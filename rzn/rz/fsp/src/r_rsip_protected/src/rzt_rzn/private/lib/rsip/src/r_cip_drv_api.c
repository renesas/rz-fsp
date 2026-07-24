/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "bsp_api.h"
#include "iodefine.h"
#include "r_typedefs.h"
#include "r_error_codes.h"
#include "r_cip_drv_api.h"
#include "rsip_check_param.h"
#include "r_rsip_primitive.h"
#include "r_rsip_util.h"
#include "r_otp_drv.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/*cstat -CERT-MSC41-C_b define values are common terms or offsets, not sensitive*/
#define ROTPKHASH_WORDSIZE           (OTP_IP_ROOT_PUBLIC_KEY_HASH_SIZE / 2U)
#define IMG_PK_HASH_SIZE             (32U)
#define IMAGE_DECRYPTKEY_WORDSIZE    (12U)
#define IMAGE_DECRYPTKEY_BYTESIZE    (IMAGE_DECRYPTKEY_WORDSIZE * 4U)

/*cstat +CERT-MSC41-C_b*/

#define RSIP_CBC_DEC                 (0x00000003uL)

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Private global variables and functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: R_CIP_DRV_PrcDecryptImage
 * Description  : Secure boot
 * Arguments    : [IN] dec_param -
 *                    Decryption Parameter for Secure Boot.
 * Return Value : CIP_DRV_RET_PASS -
 *                    normal end
 *                CIP_DRV_RET_FAIL -
 *                    failed to decrypt.
 *                CIP_DRV_RET_UNSUPPORTER_ALGORITHM -
 *                    unsupported algorithm.
 *                CIP_DRV_RET_RESOURCE_CONFLICT -
 *                    resource conflict.
 *********************************************************************************************************************/
cip_drv_ret_t R_CIP_DRV_PrcDecryptImage (const st_cip_drv_cipher_img_param_t * const p_dec_img_param)
{
    rsip_ret_t    err_val = RSIP_RET_PASS;
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    ret_val = rsip_check_dec_param(p_dec_img_param);

    if (CIP_DRV_RET_PASS == ret_val)
    {
        uint32_t key_data[IMAGE_DECRYPTKEY_WORDSIZE];

        /* key_select data included in dec parameter is stored as big endian data */
        uint32_t key_id = ((p_dec_img_param->key_select) & KEY_ID_MASK);

        /* get key */
        /* if key_id = 4, key is included in image */
        if (RSIP_MAX_KEY_ID == key_id)
        {
            uintptr_t key_pos;
            key_pos = (uintptr_t) p_dec_img_param->p_img_src + p_dec_img_param->img_len;

            /* get key from end of IMG */
            memcpy(key_data, (void *) key_pos, IMAGE_DECRYPTKEY_BYTESIZE);
        }
        else if (key_id < RSIP_MAX_KEY_ID)
        {
            /* get key from OTP */
            /* TODO: check whether these are the right OTP keys to use here */
            const e_otp_content_t otp_cont[4] =
            {
                OTP_CONTENT_ADDITIONAL_KEY1,
                OTP_CONTENT_ADDITIONAL_KEY2,
                OTP_CONTENT_ADDITIONAL_KEY3,
                OTP_CONTENT_ADDITIONAL_KEY4
            };

            if (D_BOOT_OK !=
                R_OTP_GetContent(otp_cont[key_id], (uint8_t *) key_data, sizeof(key_data)))
            {
                /* otp error */
                ret_val = CIP_DRV_RET_FAIL;
            }
        }
        else
        {
            /* Invalid key id */
            ret_val = CIP_DRV_RET_PARAM_ERROR;
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            /* get iv from code certificate */
            if (NULL == p_dec_img_param->p_iv)
            {
                /* We do not support code cert without iv */
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }
            else
            {
                /* read iv from code cert */
                if (16U != p_dec_img_param->iv_len)
                {
                    ret_val = CIP_DRV_RET_PARAM_ERROR;
                }
            }
        }

        /* execute RSIP procedure */
        if (CIP_DRV_RET_PASS == ret_val)
        {
            uint32_t mode = bswap_32big(RSIP_CBC_DEC); /* not support except for AES-128/CBC */

            /* RSIP procedure 47i */
            /* cast arg according to RSIP procedure */
            /*cstat !CERT-EXP39-C_d Valid verified cast from 32 bit values to 32 bit tool error*/
            err_val = r_rsip_p47i(&mode, key_data, (uint32_t *) p_dec_img_param->p_iv);
            if (RSIP_RET_KEY_FAIL == err_val)
            {
                ret_val = CIP_DRV_RET_KEY_FAIL;
            }
            else if (RSIP_RET_RESOURCE_CONFLICT == err_val)
            {
                ret_val = CIP_DRV_RET_RESOURCE_CONFLICT;
            }
            else
            {
                ;                      /* SUCCESS, DO NOTHING */
            }
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            /* RSIP procedure 47u */
            /* cast arg according to RSIP procedure */
            /* RSIP procedure requires 4bytes * [MAX_CNT] */
            /*cstat !CERT-EXP39-C_d Valid verified cast from 32 bit values to 32 bit tool error*/
            r_rsip_p47u((uint32_t *) p_dec_img_param->p_img_src,
                        p_dec_img_param->p_img_dst,
                        (p_dec_img_param->img_len) >> 2);

            /* RSIP procedure 47f */
            if (RSIP_RET_PASS != r_rsip_p47f())
            {
                ret_val = CIP_DRV_RET_FAIL;
            }
        }
    }

    return ret_val;
}                                      /* End of function R_CIP_DRV_PrcDecryptImage() */

/**********************************************************************************************************************
 * Function Name: R_CIP_DRV_PrcVerifyCertChain
 * Description  : Verify Key cert and Code cert for Secure boot
 * Arguments    : [IN] p_cc_key_cert_param -
 *                    pointer to Key Certification.
 *                     p_cc_code_cert_param -
 *                    pointer to Code Certification.
 *                     p_dec_img_param -
 *                    Timing specification for decryption and verification. Not Use.
 * Return Value : CIP_DRV_RET_PASS -
 *                    normal end
 *                CIP_DRV_RET_FAIL -
 *                    failed (includes Parameter error)
 *                CIP_DRV_RET_UNSUPPORTED_ALGORITHM
 *                    not supported algorithm
 *                CIP_DRV_RET_RESOURCE_CONFLICT
 *                    resource conflict
 *                CIP_DRV_RET_AUTH_FAIL -
 *                    failed to authentication
 *********************************************************************************************************************/
cip_drv_ret_t R_CIP_DRV_PrcVerifyCertChain (const st_cip_drv_cc_key_cert_param_t * const  p_cc_key_cert_param,
                                            const st_cip_drv_cc_code_cert_param_t * const p_cc_code_cert_param,
                                            const st_cip_drv_cipher_img_param_t * const   p_dec_img_param)
{
    rsip_ret_t    err_val = RSIP_RET_PASS;
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;
    uint32_t      r_otpk_hash[ROTPKHASH_WORDSIZE];

    uintptr_t img_hash_pos     = 0;
    uintptr_t key_sign_pk_pos  = 0;
    uintptr_t img_pk_hash_pos  = 0;
    uintptr_t code_sign_pk_pos = 0;

    ret_val = rsip_check_verify_param(p_cc_key_cert_param, p_cc_code_cert_param, p_dec_img_param);

    /* get hash of root key from OTP */
    if (CIP_DRV_RET_PASS == ret_val)
    {
        /* get hash value of ROT PK in OTP memory */
        if (D_BOOT_OK !=
            R_OTP_GetContent(OTP_CONTENT_ROOT_PUBLIC_KEY_HASH, (uint8_t *) r_otpk_hash, sizeof(r_otpk_hash)))
        {
            ret_val = CIP_DRV_RET_FAIL;
        }
    }

    /* calculate and check offset position */
    if (CIP_DRV_RET_PASS == ret_val)
    {
        /* each offset value is small enough, so we can cast to uint32_t */
        if (NULL == p_cc_code_cert_param->p_img_hash)
        {
            img_hash_pos = 0;
        }
        else
        {
            if ((uintptr_t) (p_cc_code_cert_param->p_img_hash) > (uintptr_t) (p_cc_code_cert_param->p_code_cert))
            {
                img_hash_pos = (uintptr_t) p_cc_code_cert_param->p_img_hash -
                               (uintptr_t) p_cc_code_cert_param->p_code_cert;
            }
            else
            {
                img_hash_pos = 0;
                ret_val      = CIP_DRV_RET_PARAM_ERROR;
            }
        }

        if ((uintptr_t) p_cc_key_cert_param->p_sign_pk > (uintptr_t) p_cc_key_cert_param->p_key_cert)
        {
            key_sign_pk_pos = (uintptr_t) p_cc_key_cert_param->p_sign_pk -
                              (uintptr_t) p_cc_key_cert_param->p_key_cert;
        }
        else
        {
            key_sign_pk_pos = 0;
            ret_val         = CIP_DRV_RET_PARAM_ERROR;
        }

        if ((uintptr_t) p_cc_key_cert_param->p_img_pk_hash > (uintptr_t) p_cc_key_cert_param->p_key_cert)
        {
            img_pk_hash_pos = (uintptr_t) p_cc_key_cert_param->p_img_pk_hash -
                              (uintptr_t) p_cc_key_cert_param->p_key_cert;
        }
        else
        {
            img_pk_hash_pos = 0;
            ret_val         = CIP_DRV_RET_PARAM_ERROR;
        }

        if ((uintptr_t) p_cc_code_cert_param->p_sign_pk > (uintptr_t) p_cc_code_cert_param->p_code_cert)
        {
            code_sign_pk_pos = (uintptr_t) p_cc_code_cert_param->p_sign_pk -
                               (uintptr_t) p_cc_code_cert_param->p_code_cert;
        }
        else
        {
            code_sign_pk_pos = 0;
            ret_val          = CIP_DRV_RET_PARAM_ERROR;
        }
    }

    if (CIP_DRV_RET_PASS == ret_val)
    {
        uint32_t cmd;
        uint32_t key_cert_pubkey_offset[4];  /* Qx start-end, Qy start-end */
        uint32_t image_pk_hash_offset[2];    /* Start-End */
        uint32_t code_cert_pubkey_offset[4]; /* Qx start-end, Qy start-end */
        uint32_t image_hash_offset[2];       /* start-end */

        uint32_t key_cert_sign_len;
        uint32_t code_cert_sign_len;
        uint32_t image_len;

        /* Start verification */
        /* Set argument for RSIP procedure 24 */
        if (NULL == p_cc_code_cert_param->p_img_hash)
        {
            /* Target of signature = Code Certificate + image */
            cmd = 0x00000000uL;
            image_hash_offset[0] = 0;
            image_hash_offset[1] = 0;
        }
        else
        {
            /* Target of signature = Code Certificate only */
            cmd = 0x00000001uL;
            image_hash_offset[0] = (uint32_t) img_hash_pos;
            if (0U == p_cc_code_cert_param->img_hash_len)
            {
                image_hash_offset[1] = image_hash_offset[0]; /* start pos = end pos */
            }
            else
            {
                image_hash_offset[1] = (image_hash_offset[0] + p_cc_code_cert_param->img_hash_len) - 1U;
            }
        }

        key_cert_pubkey_offset[0] = (uint32_t) key_sign_pk_pos;                                           /* Qx start */
        key_cert_pubkey_offset[1] = key_cert_pubkey_offset[0] + (ECDSA_P256_KEY_SIZE_QXQY - 1U);          /* Qx end */
        key_cert_pubkey_offset[2] = key_cert_pubkey_offset[0] + ECDSA_P256_KEY_SIZE_QXQY;                 /* Qy start */
        key_cert_pubkey_offset[3] = key_cert_pubkey_offset[0] + ((ECDSA_P256_KEY_SIZE_QXQY * 2U) - 1U);   /* Qy end */

        /* for ImgPkHash, offset value from top of key certification must be specified */
        image_pk_hash_offset[0] = (uint32_t) img_pk_hash_pos;                                             /* IMG PK Hash Value start */
        image_pk_hash_offset[1] = image_pk_hash_offset[0] + (IMG_PK_HASH_SIZE - 1U);                      /* IMG PK Hash end */

        code_cert_pubkey_offset[0] = (uint32_t) code_sign_pk_pos;                                         /* Qx start */
        code_cert_pubkey_offset[1] = code_cert_pubkey_offset[0] + (ECDSA_P256_KEY_SIZE_QXQY - 1U);        /* Qx end */
        code_cert_pubkey_offset[2] = code_cert_pubkey_offset[0] + ECDSA_P256_KEY_SIZE_QXQY;               /* Qy start */
        code_cert_pubkey_offset[3] = code_cert_pubkey_offset[0] + ((ECDSA_P256_KEY_SIZE_QXQY * 2U) - 1U); /* Qy end */

        /* change endian for RSIP */
        cmd = bswap_32big(cmd);

        key_cert_sign_len = bswap_32big(p_cc_key_cert_param->key_cert_sign_len);

        key_cert_pubkey_offset[0] = bswap_32big(key_cert_pubkey_offset[0]);
        key_cert_pubkey_offset[1] = bswap_32big(key_cert_pubkey_offset[1]);
        key_cert_pubkey_offset[2] = bswap_32big(key_cert_pubkey_offset[2]);
        key_cert_pubkey_offset[3] = bswap_32big(key_cert_pubkey_offset[3]);

        image_pk_hash_offset[0] = bswap_32big(image_pk_hash_offset[0]);
        image_pk_hash_offset[1] = bswap_32big(image_pk_hash_offset[1]);

        code_cert_sign_len = bswap_32big(p_cc_code_cert_param->code_cert_sign_len);

        code_cert_pubkey_offset[0] = bswap_32big(code_cert_pubkey_offset[0]);
        code_cert_pubkey_offset[1] = bswap_32big(code_cert_pubkey_offset[1]);
        code_cert_pubkey_offset[2] = bswap_32big(code_cert_pubkey_offset[2]);
        code_cert_pubkey_offset[3] = bswap_32big(code_cert_pubkey_offset[3]);

        image_hash_offset[0] = bswap_32big(image_hash_offset[0]);
        image_hash_offset[1] = bswap_32big(image_hash_offset[1]);

        /* RSIP procedure requires 4byte * [MAX_SIZE] */
        image_len = bswap_32big((p_cc_code_cert_param->img_len) >> 2U);

        /* Verify manifest */
        /* cast each arg according to RSIP procedure */
        /*cstat -CERT-EXP39-C_d Valid verified cast from 32 bit *values to 32 bit * values tool error*/
        err_val =
            r_rsip_p24(&cmd,
                       (uint32_t *) (p_cc_key_cert_param->p_key_cert),
                       (uint32_t *) (&key_cert_sign_len),
                       (uint32_t *) (p_cc_key_cert_param->p_sign),
                       key_cert_pubkey_offset,
                       image_pk_hash_offset,
                       r_otpk_hash,
                       (uint32_t *) (p_cc_code_cert_param->p_code_cert),
                       (uint32_t *) (&code_cert_sign_len),
                       (uint32_t *) (p_cc_code_cert_param->p_sign),
                       code_cert_pubkey_offset,
                       image_hash_offset,
                       (uint32_t *) (p_cc_code_cert_param->p_img),
                       image_len);

        /*cstat +CERT-EXP39-C_d Valid verified cast from 32 bit values to 32 bit tool error*/

        if (RSIP_RET_PARAM_FAIL == err_val)
        {
            ret_val = CIP_DRV_RET_FAIL; /* if RSIP returns PARAM_FAIL, maybe it can not be retried */
        }
        else if (RSIP_RET_RESOURCE_CONFLICT == err_val)
        {
            ret_val = CIP_DRV_RET_RESOURCE_CONFLICT;
        }
        else if (RSIP_RET_VERIFICATION_FAIL == err_val)
        {
            ret_val = CIP_DRV_RET_AUTH_FAIL;
        }
        else if (RSIP_RET_PASS == err_val)
        {
            ret_val = CIP_DRV_RET_PASS;
        }
        else                           /* other error */
        {
            ret_val = CIP_DRV_RET_FAIL;
        }
    }

    return ret_val;
}                                      /* End of function R_CIP_DRV_PrcVerifyCertChain() */

/**********************************************************************************************************************
 * Function Name: R_CIP_DRV_CheckImageVersion
 * Description  : Image version check - not supported on RZ/T2
 * Arguments    : [IN] image_version -
 *
 *                     build_num -
 *
 * Return Value : CIP_DRV_RET_SAME_IMAGE_VERSION -
 *                    input version is same as stored in hardware resource.
 *********************************************************************************************************************/
cip_drv_ret_t R_CIP_DRV_CheckImageVersion (const uint32_t image_version, const uint32_t build_num)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_SAME_IMAGE_VERSION;
    (void) image_version;
    (void) build_num;

    /* This is a dummy function as image version is not supported on RZ/T2 */

    return ret_val;
}                                      /* End of function R_CIP_DRV_CheckImageVersion() */

/* End of File */
