/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "r_typedefs.h"
#include "rsip_check_param.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

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
 * Function Name: is_aligned
 * Description  : Check alignment
 * Arguments    : [IN] data -
 *                    check data
 *                alignment -
 *                    A power of two
 * Return Value : true -
 *                    data is aligned
 *                false -
 *                    data is not aligned or invalid alignment
 *********************************************************************************************************************/
static bool is_aligned (const uintptr_t data, const uint32_t alignment)
{
    bool ret_val = false;

    if ((0U != alignment) && (0U == (alignment & (alignment - 1U))))
    {
        if (0U == (data & (alignment - 1U)))
        {
            ret_val = true;
        }
    }

    return ret_val;
}                                      /* End of function is_aligned() */

/**********************************************************************************************************************
 * Function Name: rsip_validate_addr
 * Description  : Validate address
 * Arguments    : [IN] addr -
 *                    address
 *                     alignment -
 *                    alignment
 * Return Value : CIP_DRV_RET_PASS -
 *                    valid address
 *                CIP_DRV_RET_PARAM_ERROR -
 *                    invalid address
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_addr (const uint32_t * const addr, const uint32_t alignment)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    if (!is_aligned((uintptr_t) addr, alignment))
    {
        ret_val = CIP_DRV_RET_PARAM_ERROR;
    }

    return ret_val;
}                                      /* End of function rsip_validate_addr() */

/**********************************************************************************************************************
 * Function Name: rsip_validate_size
 * Description  : Validate size
 * Arguments    : [IN] size -
 *                    size value
 * Return Value : CIP_DRV_RET_PASS -
 *                    valid size
 *                CIP_DRV_RET_PARAM_ERROR -
 *                    invalid size
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_size (const uint32_t size, const uint32_t alignment)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    if ((0U == size) || (!is_aligned(size, alignment)))
    {
        ret_val = CIP_DRV_RET_PARAM_ERROR;
    }

    return ret_val;
}                                      /* End of function rsip_validate_size() */

/**********************************************************************************************************************
 * Validate key-ID for RSIP
 * Function Name: rsip_validate_keyselect
 * Description  : Validate key_select
 * Arguments    : [IN] key_id -
 *                    key id
 * Return Value : CIP_DRV_RET_PASS -
 *                    valid key_select
 *                CIP_DRV_RET_PARAM_ERROR -
 *                    invalid key_select
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_keyselect (const uint32_t key_select)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    /* Supports external registered key only */
    if (KEY_ID_INSTALLED_EXT != (key_select & KEY_ID_INSTALLED_MASK))
    {
        ret_val = CIP_DRV_RET_PARAM_ERROR;
    }
    else
    {
        /* Support key id 0 to 4 */
        /*if ((RSIP_MIN_KEY_ID > (key_select & KEY_ID_MASK)) || (RSIP_MAX_KEY_ID < (key_select & KEY_ID_MASK)))*/
        if (RSIP_MAX_KEY_ID < (key_select & KEY_ID_MASK))
        {
            ret_val = CIP_DRV_RET_PARAM_ERROR;
        }
    }

    return ret_val;
}                                      /* End of function rsip_validate_keyselect() */

/**********************************************************************************************************************
 * Validate iV for RSIP
 * Function Name: rsip_validate_iv
 * Description  : Validate iv
 * Arguments    : [IN]  iv_select -
 *                    iv_select
 *                      iv_len -
 *                    iv length
 *
 * Return Value : CIP_DRV_RET_PASS -
 *                    valid iv length and iv_select
 *                CIP_DRV_RET_PARAM_ERROR -
 *                    invalid iv
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_iv (const uint32_t iv_select, const uint32_t iv_len)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    /* Supports specified iv length and iv_select only */
    if ((EN_IV_SIZE != iv_len) || (EN_IV_SELECT != iv_select))
    {
        ret_val = CIP_DRV_RET_PARAM_ERROR;
    }

    return ret_val;
}                                      /* End of function rsip_validate_iv() */

/**********************************************************************************************************************
 * Validate cipher mode for RSIP
 * Function Name: rsip_validate_cipher
 * Description  : Validate cipher mode
 * Arguments    : [IN]  cipher_algo -
 *                    cipher algorithm
 *                      cipher_mode -
 *                    cipher mode
 * Return Value : CIP_DRV_RET_PASS -
 *                    supported algorithm and mode
 *                CIP_DRV_RET_UNSUPPORTED_ALGORITHM -
 *                    not supported algorithm
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_cipher (const uint32_t cipher_algo, const uint32_t cipher_mode)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    /* Supports AES128-CBC mode only */
    if ((CIP_DRV_CIPHER_ALGO_AES128 != cipher_algo) || (CIP_DRV_CIPHER_MODE_CBC != cipher_mode))
    {
        ret_val = CIP_DRV_RET_UNSUPPORTED_ALGORITHM;
    }

    return ret_val;
}                                      /* End of function rsip_validate_cipher() */

/**********************************************************************************************************************
 * Validate verify mode for RSIP
 * Function Name: rsip_validate_verify_keycert
 * Description  : Validate algorithm of verification for key ceritification
 * Arguments    : [IN]  img_pk_hash_algo -
 *                    Image PK hash algorithm
 *                      sign_algo -
 *                    Sign algorithm
 *                      sign_hash_algo -
 *                    Sign hash algorithm
 *                      sign_scheme -
 *                    Sign scheme
 * Return Value : CIP_DRV_RET_PASS -
 *                    supported algorithm
 *                CIP_DRV_RET_UNSUPPORTED_ALGORITHM -
 *                    not supported algorithm
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_verify_keycert (const uint32_t img_pk_hash_algo,
                                                   const uint32_t sign_algo,
                                                   const uint32_t sign_hash_algo,
                                                   const uint32_t sign_scheme)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    /* Supports specified algorithm only */
    if ((CIP_DRV_HASH_ALGO_SHA2_256 != img_pk_hash_algo) || (CIP_DRV_SIGN_ALGO_ECDSA_P256 != sign_algo) ||
        (CIP_DRV_HASH_ALGO_SHA2_256 != sign_hash_algo) || (CIP_DRV_SCHEME_NONE != sign_scheme))
    {
        ret_val = CIP_DRV_RET_UNSUPPORTED_ALGORITHM;
    }

    return ret_val;
}                                      /* End of function rsip_validate_verify_keycert() */

/**********************************************************************************************************************
 * Validate verify mode for RSIP
 * Function Name: rsip_validate_verify_codecert
 * Description  : Validate algorithm of verification for code ceritification
 * Arguments    : [IN]  img_hash_algo -
 *                    Image hash algorithm
 *                      sign_algo -
 *                    Sign algorithm
 *                      sign_hash_algo -
 *                    Sign hash algorithm
 *                      sign_scheme -
 *                    Sigh scheme
 * Return Value : CIP_DRV_RET_PASS -
 *                    supported algorithm
 *                CIP_DRV_RET_UNSUPPORTED_ALGORITHM
 *                    not supported algorithm
 *********************************************************************************************************************/
static cip_drv_ret_t rsip_validate_verify_codecert (const uint32_t img_hash_algo,
                                                    const uint32_t sign_algo,
                                                    const uint32_t sign_hash_algo,
                                                    const uint32_t sign_scheme)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    /* Supports specified algorithm only */
    if (((CIP_DRV_HASH_ALGO_SHA2_256 != img_hash_algo) && (CIP_DRV_HASH_ALGO_NONE != img_hash_algo)) ||
        (CIP_DRV_SIGN_ALGO_ECDSA_P256 != sign_algo) ||
        (CIP_DRV_HASH_ALGO_SHA2_256 != sign_hash_algo) ||
        (CIP_DRV_SCHEME_NONE != sign_scheme))
    {
        ret_val = CIP_DRV_RET_UNSUPPORTED_ALGORITHM;
    }

    return ret_val;
}                                      /* End of function rsip_validate_verify_codecert() */

/**********************************************************************************************************************
 * Check decryption parameter for RSIP
 * Function Name: rsip_check_dec_param
 * Description  : Check parameter for decryption
 * Arguments    : [IN] dec_param -
 *                    decryption parameter
 * Return Value : CIP_DRV_RET_PASS -
 *                    valid parameter
 *                CIP_DRV_RET_PARAM_ERROR -
 *                    invalid parameter
 *                CIP_DRV_RET_UNSUPPORTED_ALGORITHM -
 *                    not supported algorithm
 *********************************************************************************************************************/
cip_drv_ret_t rsip_check_dec_param (const st_cip_drv_cipher_img_param_t * const dec_param)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;

    if (NULL == dec_param)
    {
        ret_val = CIP_DRV_RET_PARAM_ERROR;
    }
    else
    {
        if (CIP_DRV_RET_PASS == ret_val)
        {
            /* key_select data included in dec parameter is stored as big endian data */
            ret_val = rsip_validate_keyselect(dec_param->key_select);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(dec_param->p_img_src, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(dec_param->p_img_dst, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(dec_param->p_iv, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_size(dec_param->img_len, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_cipher(dec_param->cipher_algo, dec_param->cipher_mode);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            /* iv_select data included in dec parameter is stored as big endian data */
            ret_val = rsip_validate_iv(dec_param->iv_select, dec_param->iv_len);
        }
    }

    return ret_val;
}                                      /* End of function rsip_check_dec_param() */

/**********************************************************************************************************************
 * Check verification parameter for RSIP
 * Function Name: rsip_check_verify_param
 * Description  : Check parameter for verification
 * Arguments    : [IN] dec_param -
 *                    verification parameter
 * Return Value : CIP_DRV_RET_PASS -
 *                    valid parameter
 *                CIP_DRV_RET_PARAM_ERROR -
 *                    invalid parameter
 *                CIP_DRV_RET_UNSUPPORTED_ALGORITHM -
 *                    not supported algorithm
 *********************************************************************************************************************/
cip_drv_ret_t rsip_check_verify_param (const st_cip_drv_cc_key_cert_param_t * const  p_cc_key_cert_param,
                                       const st_cip_drv_cc_code_cert_param_t * const p_cc_code_cert_param,
                                       const st_cip_drv_cipher_img_param_t * const   p_dec_img_param)
{
    cip_drv_ret_t ret_val = CIP_DRV_RET_PASS;
    (void) p_dec_img_param;

    if ((NULL == p_cc_key_cert_param) || (NULL == p_cc_code_cert_param))
    {
        ret_val = CIP_DRV_RET_PARAM_ERROR;
    }
    else
    {
        /* key cert check */

        if (CIP_DRV_RET_PASS == ret_val)
        {
            /* Support CIP_DRV_KEY_CERT_PK_CMP_SRC_ROT only */
            if (CIP_DRV_KEY_CERT_PK_CMP_SRC_ROT != p_cc_key_cert_param->key_cert_pk_cmp_src)
            {
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }
        }

        /* Check algo */
        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_verify_keycert(p_cc_key_cert_param->img_pk_hash_algo,
                                                   p_cc_key_cert_param->sign_algo,
                                                   p_cc_key_cert_param->sign_hash_algo,
                                                   p_cc_key_cert_param->sign_scheme);
        }

        /* Check alignment */
        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(p_cc_key_cert_param->p_img_pk_hash, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(p_cc_key_cert_param->p_sign_pk, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(p_cc_key_cert_param->p_sign, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_addr(p_cc_key_cert_param->p_key_cert, 4);
        }

        /* Check size */
        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_size(p_cc_key_cert_param->img_pk_hash_len, 4);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            if (ECDSA_P256_KEY_SIZE_TOTAL != p_cc_key_cert_param->sign_pk_len)
            {
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }

            if (ECDSA_P256_SIGN_SIZE != p_cc_key_cert_param->sign_len)
            {
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }
        }

        /* code cert check */

        /* Check Algo */
        if (CIP_DRV_RET_PASS == ret_val)
        {
            ret_val = rsip_validate_verify_codecert(p_cc_code_cert_param->img_hash_algo,
                                                    p_cc_code_cert_param->sign_algo,
                                                    p_cc_code_cert_param->sign_hash_algo,
                                                    p_cc_code_cert_param->sign_scheme);
        }

        if (CIP_DRV_RET_PASS == ret_val)
        {
            /* Support no save img pk only */
            if (0U != p_cc_code_cert_param->is_save_img_pk)
            {
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }

            /* check size */
            if (ECDSA_P256_KEY_SIZE_TOTAL != p_cc_code_cert_param->sign_pk_len)
            {
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }

            if (ECDSA_P256_SIGN_SIZE != p_cc_code_cert_param->sign_len)
            {
                ret_val = CIP_DRV_RET_PARAM_ERROR;
            }
        }
    }

    return ret_val;
}                                      /* End of function rsip_check_verify_param() */

/* End of File */
