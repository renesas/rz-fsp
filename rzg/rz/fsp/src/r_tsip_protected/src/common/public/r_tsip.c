/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_public.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Function pointers for initializing g_tsip_on_tsip */
typedef fsp_err_t (* tsip_api_ecdh_key_agree_t)(tsip_ctrl_t * const, tsip_wrapped_key_t const * const,
                                                tsip_wrapped_key_t const * const,
                                                tsip_wrapped_secret_abstractor_t * const);
typedef fsp_err_t (* tsip_api_ecdh_plain_key_agree_t)(tsip_ctrl_t * const, tsip_wrapped_key_t const * const,
                                                      uint8_t const * const, tsip_wrapped_secret_abstractor_t * const);
typedef fsp_err_t (* tsip_api_sha_suspend_t)(tsip_ctrl_t * const, tsip_sha_handle_abstractor_t * const);
typedef fsp_err_t (* tsip_api_sha_resume_t)(tsip_ctrl_t * const, tsip_sha_handle_abstractor_t const * const);
typedef fsp_err_t (* tsip_api_hmac_suspend_t)(tsip_ctrl_t * const, tsip_hmac_handle_abstractor_t * const);
typedef fsp_err_t (* tsip_api_hmac_resume_t)(tsip_ctrl_t * const, tsip_hmac_handle_abstractor_t const * const);
typedef fsp_err_t (* tsip_api_pki_verified_cert_info_export_t)(tsip_ctrl_t * const,
                                                               tsip_verified_cert_info_abstractor_t * const);
typedef fsp_err_t (* tsip_api_pki_verified_cert_info_import_t)(tsip_ctrl_t * const,
                                                               tsip_verified_cert_info_abstractor_t const * const);
typedef fsp_err_t (* tsip_api_kdf_sha_ecdh_secret_update_t)(tsip_ctrl_t * const,
                                                            tsip_wrapped_secret_abstractor_t const * const);
typedef fsp_err_t (* tsip_api_kdf_sha_suspend_t)(tsip_ctrl_t * const, tsip_kdf_sha_handle_abstractor_t * const);
typedef fsp_err_t (* tsip_api_kdf_sha_resume_t)(tsip_ctrl_t * const, tsip_kdf_sha_handle_abstractor_t const * const);
typedef fsp_err_t (* tsip_api_kdf_hmac_ecdh_secret_key_import_t)(tsip_ctrl_t * const,
                                                                 tsip_wrapped_secret_abstractor_t const * const,
                                                                 tsip_wrapped_key_t * const);
typedef fsp_err_t (* tsip_api_kdf_hmac_ecdh_secret_update_t)(tsip_ctrl_t * const,
                                                             tsip_wrapped_secret_abstractor_t const * const);
typedef fsp_err_t (* tsip_api_kdf_hmac_suspend_t)(tsip_ctrl_t * const, tsip_kdf_hmac_handle_abstractor_t * const);
typedef fsp_err_t (* tsip_api_kdf_hmac_resume_t)(tsip_ctrl_t * const, tsip_kdf_hmac_handle_abstractor_t const * const);

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static tsip_func_key_generate_t       select_func_key_generate(tsip_key_type_extend_t key_type_ext);
static tsip_func_key_pair_generate_t  select_func_key_pair_generate(tsip_key_type_extend_t key_type_ext);
static tsip_func_encrypted_key_wrap_t select_func_encrypted_key_wrap(tsip_key_type_extend_t key_type_ext);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint32_t gs_ecc_param1_pos[TSIP_PRV_KEY_SUBTYPE_ECC_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_384_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_521_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_384_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_512_QX,
    [TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519]    = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_EDWARDS25519_Q
};

static const uint32_t gs_ecc_param1_len[TSIP_PRV_KEY_SUBTYPE_ECC_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1]       = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1]       = TSIP_PRV_BYTE_SIZE_ECC_384_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1]       = TSIP_PRV_BYTE_SIZE_ECC_521_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1]       = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1] = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1] = TSIP_PRV_BYTE_SIZE_ECC_384_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1] = TSIP_PRV_BYTE_SIZE_ECC_512_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519]    = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM
};

static const uint32_t gs_ecc_param2_pos[TSIP_PRV_KEY_SUBTYPE_ECC_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_384_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_521_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1]       = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_384_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_512_QY,
    [TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519]    = 0
};

static const uint32_t gs_ecc_param2_len[TSIP_PRV_KEY_SUBTYPE_ECC_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1]       = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1]       = TSIP_PRV_BYTE_SIZE_ECC_384_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1]       = TSIP_PRV_BYTE_SIZE_ECC_521_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1]       = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1] = TSIP_PRV_BYTE_SIZE_ECC_256_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1] = TSIP_PRV_BYTE_SIZE_ECC_384_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1] = TSIP_PRV_BYTE_SIZE_ECC_512_PARAM,
    [TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519]    = 0
};

static const uint32_t gs_rsa_n_pos = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_N;

static const uint32_t gs_rsa_n_len[TSIP_PRV_KEY_SUBTYPE_RSA_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_RSA_1024] = TSIP_PRV_BYTE_SIZE_RSA_1024_N,
    [TSIP_PRV_KEY_SUBTYPE_RSA_2048] = TSIP_PRV_BYTE_SIZE_RSA_2048_N,
    [TSIP_PRV_KEY_SUBTYPE_RSA_3072] = TSIP_PRV_BYTE_SIZE_RSA_3072_N,
    [TSIP_PRV_KEY_SUBTYPE_RSA_4096] = TSIP_PRV_BYTE_SIZE_RSA_4096_N
};

static const uint32_t gs_rsa_e_pos[TSIP_PRV_KEY_SUBTYPE_RSA_NUM] =
{
    [TSIP_PRV_KEY_SUBTYPE_RSA_1024] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_1024_E,
    [TSIP_PRV_KEY_SUBTYPE_RSA_2048] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_2048_E,
    [TSIP_PRV_KEY_SUBTYPE_RSA_3072] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_3072_E,
    [TSIP_PRV_KEY_SUBTYPE_RSA_4096] = TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_4096_E
};

static const uint32_t gs_rsa_e_len = TSIP_PRV_BYTE_SIZE_RSA_E;

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

const tsip_api_t g_tsip_on_tsip =
{
    .open                       = R_TSIP_Open,
    .close                      = R_TSIP_Close,
    .randomNumberGenerate       = R_TSIP_RandomNumberGenerate,
    .keyGenerate                = R_TSIP_KeyGenerate,
    .keyPairGenerate            = R_TSIP_KeyPairGenerate,
    .encryptedKeyWrap           = R_TSIP_EncryptedKeyWrap,
    .rfc3394_KeyWrap            = R_TSIP_RFC3394_KeyWrap,
    .rfc3394_KeyUnwrap          = R_TSIP_RFC3394_KeyUnwrap,
    .publicKeyExport            = R_TSIP_PublicKeyExport,
    .aesCipherInit              = R_TSIP_AES_Cipher_Init,
    .aesCipherUpdate            = R_TSIP_AES_Cipher_Update,
    .aesCipherFinish            = R_TSIP_AES_Cipher_Finish,
    .aesAeadInit                = R_TSIP_AES_AEAD_Init,
    .aesAeadLengthsSet          = R_TSIP_AES_AEAD_LengthsSet,
    .aesAeadAadUpdate           = R_TSIP_AES_AEAD_AADUpdate,
    .aesAeadUpdate              = R_TSIP_AES_AEAD_Update,
    .aesAeadFinish              = R_TSIP_AES_AEAD_Finish,
    .aesAeadVerify              = R_TSIP_AES_AEAD_Verify,
    .aesMacInit                 = R_TSIP_AES_MAC_Init,
    .aesMacUpdate               = R_TSIP_AES_MAC_Update,
    .aesMacSignFinish           = R_TSIP_AES_MAC_SignFinish,
    .aesMacVerifyFinish         = R_TSIP_AES_MAC_VerifyFinish,
    .chacha20Init               = R_TSIP_ChaCha20_Init,
    .chacha20Update             = R_TSIP_ChaCha20_Update,
    .chacha20Finish             = R_TSIP_ChaCha20_Finish,
    .chacha20Poly1305Init       = R_TSIP_ChaCha20_Poly1305_Init,
    .chacha20Poly1305AadUpdate  = R_TSIP_ChaCha20_Poly1305_AADUpdate,
    .chacha20Poly1305Update     = R_TSIP_ChaCha20_Poly1305_Update,
    .chacha20Poly1305Finish     = R_TSIP_ChaCha20_Poly1305_Finish,
    .chacha20Poly1305Verify     = R_TSIP_ChaCha20_Poly1305_Verify,
    .ecdsaSign                  = R_TSIP_ECDSA_Sign,
    .ecdsaVerify                = R_TSIP_ECDSA_Verify,
    .eddsaSign                  = R_TSIP_PureEdDSA_Sign,
    .eddsaVerify                = R_TSIP_PureEdDSA_Verify,
    .ecdhKeyAgree               = (tsip_api_ecdh_key_agree_t) R_TSIP_ECDH_KeyAgree,
    .ecdhPlainKeyAgree          = (tsip_api_ecdh_plain_key_agree_t) R_TSIP_ECDH_PlainKeyAgree,
    .rsaEncrypt                 = R_TSIP_RSA_Encrypt,
    .rsaDecrypt                 = R_TSIP_RSA_Decrypt,
    .rsaesPkcs1V15Encrypt       = R_TSIP_RSAES_PKCS1_V1_5_Encrypt,
    .rsaesPkcs1V15Decrypt       = R_TSIP_RSAES_PKCS1_V1_5_Decrypt,
    .rsaesOaepEncrypt           = R_TSIP_RSAES_OAEP_Encrypt,
    .rsaesOaepDecrypt           = R_TSIP_RSAES_OAEP_Decrypt,
    .rsassaPkcs1V15Sign         = R_TSIP_RSASSA_PKCS1_V1_5_Sign,
    .rsassaPkcs1V15Verify       = R_TSIP_RSASSA_PKCS1_V1_5_Verify,
    .rsassaPssSign              = R_TSIP_RSASSA_PSS_Sign,
    .rsassaPssVerify            = R_TSIP_RSASSA_PSS_Verify,
    .shaCompute                 = R_TSIP_SHA_Compute,
    .shaInit                    = R_TSIP_SHA_Init,
    .shaUpdate                  = R_TSIP_SHA_Update,
    .shaFinish                  = R_TSIP_SHA_Finish,
    .shaSuspend                 = (tsip_api_sha_suspend_t) R_TSIP_SHA_Suspend,
    .shaResume                  = (tsip_api_sha_resume_t) R_TSIP_SHA_Resume,
    .hmacCompute                = R_TSIP_HMAC_Compute,
    .hmacVerify                 = R_TSIP_HMAC_Verify,
    .hmacInit                   = R_TSIP_HMAC_Init,
    .hmacUpdate                 = R_TSIP_HMAC_Update,
    .hmacSignFinish             = R_TSIP_HMAC_SignFinish,
    .hmacVerifyFinish           = R_TSIP_HMAC_VerifyFinish,
    .hmacSuspend                = (tsip_api_hmac_suspend_t) R_TSIP_HMAC_Suspend,
    .hmacResume                 = (tsip_api_hmac_resume_t) R_TSIP_HMAC_Resume,
    .pkiEcdsaCertVerify         = R_TSIP_PKI_ECDSA_CertVerify,
    .pkiVerifiedCertInfoExport  = (tsip_api_pki_verified_cert_info_export_t) R_TSIP_PKI_VerifiedCertInfoExport,
    .pkiVerifiedCertInfoImport  = (tsip_api_pki_verified_cert_info_import_t) R_TSIP_PKI_VerifiedCertInfoImport,
    .pkiCertKeyImport           = R_TSIP_PKI_CertKeyImport,
    .kdfShaInit                 = R_TSIP_KDF_SHA_Init,
    .kdfShaEcdhSecretUpdate     = (tsip_api_kdf_sha_ecdh_secret_update_t) R_TSIP_KDF_SHA_ECDHSecretUpdate,
    .kdfShaUpdate               = R_TSIP_KDF_SHA_Update,
    .kdfShaFinish               = R_TSIP_KDF_SHA_Finish,
    .kdfShaSuspend              = (tsip_api_kdf_sha_suspend_t) R_TSIP_KDF_SHA_Suspend,
    .kdfShaResume               = (tsip_api_kdf_sha_resume_t) R_TSIP_KDF_SHA_Resume,
    .kdfHmacDkmKeyImport        = R_TSIP_KDF_HMAC_DKMKeyImport,
    .kdfHmacEcdhSecretKeyImport = (tsip_api_kdf_hmac_ecdh_secret_key_import_t) R_TSIP_KDF_HMAC_ECDHSecretKeyImport,
    .kdfHmacInit                = R_TSIP_KDF_HMAC_Init,
    .kdfHmacDkmUpdate           = R_TSIP_KDF_HMAC_DKMUpdate,
    .kdfHmacEcdhSecretUpdate    = (tsip_api_kdf_hmac_ecdh_secret_update_t) R_TSIP_KDF_HMAC_ECDHSecretUpdate,
    .kdfHmacUpdate              = R_TSIP_KDF_HMAC_Update,
    .kdfHmacSignFinish          = R_TSIP_KDF_HMAC_SignFinish,
    .kdfHmacSuspend             = (tsip_api_kdf_hmac_suspend_t) R_TSIP_KDF_HMAC_Suspend,
    .kdfHmacResume              = (tsip_api_kdf_hmac_resume_t) R_TSIP_KDF_HMAC_Resume,
    .kdfDkmConcatenate          = R_TSIP_KDF_DKMConcatenate,
    .kdfDerivedKeyImport        = R_TSIP_KDF_DerivedKeyImport,
    .kdfDerivedIvWrap           = R_TSIP_KDF_DerivedIVWrap,
    .otfInit                    = R_TSIP_OTF_Init,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_TSIP_PROTECTED
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enables use of Renesas Secure IP functionality.
 *
 * Implements @ref tsip_api_t::open.
 *
 * @par State transition
 * @parblock
 * This API can only be executed in **STATE_INITIAL**, and causes state transition.
 *
 * |Return value|Next state|
 * |------------|----------|
 * |FSP_SUCCESS |STATE_MAIN|
 * |Others      |No change |
 * @endparblock
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_ALREADY_OPEN                  Module is already open.
 * @retval FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL      Internal key value is illegal.
 * @retval FSP_ERR_CRYPTO_TSIP_FAIL              Hardware initialization is failed.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption or hardware fault is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_Open (tsip_ctrl_t * const p_ctrl, tsip_cfg_t const * const p_cfg)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ERROR_RETURN(TSIP_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    /* Set configuration */
    p_instance_ctrl->p_cfg = p_cfg;

    /* Device-specific sequence */
    tsip_ret_t tsip_ret = r_tsip_open();

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            /* Reset handle */
            r_tsip_handle_reset(&p_instance_ctrl->handle);

            /* State transition */
            p_instance_ctrl->state = TSIP_STATE_MAIN;

            /* Set driver status to open */
            p_instance_ctrl->open = TSIP_OPEN;

            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        /* Treat PASS_1 as FAIL */
        case TSIP_RET_FAIL:
        case TSIP_RET_PASS_1:
        {
            err = FSP_ERR_CRYPTO_TSIP_FAIL;
            break;
        }

        case TSIP_RET_KEY_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL;
            break;
        }

        /* Treat RETRY as FATAL */
        case TSIP_RET_RETRY:
        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Disables use of Renesas Secure IP functionality.
 *
 * Implements @ref tsip_api_t::close.
 *
 * @par State transition
 * @parblock
 * This API can be executed in **except STATE_INITIAL**, and causes state transition.
 *
 * |Return value|Next state   |
 * |------------|-------------|
 * |FSP_SUCCESS |STATE_INITIAL|
 * |Others      |No change    |
 * @endparblock
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 *
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_Close (tsip_ctrl_t * const p_ctrl)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Device-specific sequence */
    tsip_ret_t tsip_ret = r_tsip_close();

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            /* Set driver status to close */
            p_instance_ctrl->open = 0U;

            err = FSP_SUCCESS;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Generates a 128-bit random number.
 *
 * Implements @ref tsip_api_t::randomNumberGenerate.
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_RandomNumberGenerate (tsip_ctrl_t * const p_ctrl, uint8_t * const p_random)
{
#if TSIP_CFG_PARAM_CHECKING_ENABLE
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_random);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    return r_tsip_random_number_generate(p_ctrl, p_random);
}

/*******************************************************************************************************************//**
 * Generates a wrapped symmetric key from a random number.
 * In this API, user key input is unnecessary.
 * By encrypting data using the wrapped key is output by this API, dead copying of data can be prevented.
 *
 * Implements @ref tsip_api_t::keyGenerate.
 *
 * @par Conditions
 * Argument @ref RZG::tsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZG_r-tsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZG_r-tsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_KeyGenerate (tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t * const p_wrapped_key)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_key);
    FSP_ASSERT(p_wrapped_key->p_value);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsip_key_type_extend_t   key_type_ext = r_tsip_key_type_parse(p_wrapped_key->type); // Parse key type
    tsip_func_key_generate_t p_func       = select_func_key_generate(key_type_ext);     // Set function

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                      // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func((uint32_t *) p_wrapped_key->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Generates a wrapped asymmetric key pair from a random number. In this API, user key input is unnecessary.
 * By encrypting data using the wrapped key is output by this API, dead copying of data can be prevented.
 *
 * Implements @ref tsip_api_t::keyPairGenerate.
 *
 * @par Conditions
 * @parblock
 * Argument @ref RZG::tsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZG_r-tsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZG_r-tsip-protected-configuration "Configuration".
 *
 * Here, p_wrapped_public_key->type and p_wrapped_private_key->type must match.
 * For example, if p_wrapped_public_key->type is @ref TSIP_KEY_TYPE_ECC_SECP256R1_PUBLIC,
 * then p_wrapped_public_key->type must be @ref TSIP_KEY_TYPE_ECC_SECP256R1_PRIVATE.
 * @endparblock
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_KeyPairGenerate (tsip_ctrl_t * const        p_ctrl,
                                  tsip_wrapped_key_t * const p_wrapped_public_key,
                                  tsip_wrapped_key_t * const p_wrapped_private_key)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_public_key);
    FSP_ASSERT(p_wrapped_public_key->p_value);
    FSP_ASSERT(p_wrapped_private_key);
    FSP_ASSERT(p_wrapped_private_key->p_value);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsip_key_type_extend_t        public_key_type_ext = r_tsip_key_type_parse(p_wrapped_public_key->type);  // Parse key type
    tsip_func_key_pair_generate_t p_func              = select_func_key_pair_generate(public_key_type_ext); // Set function

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    tsip_key_type_extend_t private_key_type_ext = r_tsip_key_type_parse(p_wrapped_private_key->type);       // Parse key type
    FSP_ERROR_RETURN(((TSIP_PRV_ALG_ECC_PUBLIC == public_key_type_ext.alg) &&
                      (TSIP_PRV_ALG_ECC_PRIVATE == private_key_type_ext.alg)) ||
                     ((TSIP_PRV_ALG_RSA_PUBLIC == public_key_type_ext.alg) &&
                      (TSIP_PRV_ALG_RSA_PRIVATE == private_key_type_ext.alg))
                     ,
                     FSP_ERR_NOT_ENABLED);                                                              // Check key type
    FSP_ERROR_RETURN(private_key_type_ext.subtype == public_key_type_ext.subtype, FSP_ERR_NOT_ENABLED); // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                      // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func((uint32_t *) p_wrapped_public_key->p_value, (uint32_t *) p_wrapped_private_key->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Decrypts an encrypted user key with Key Update Key (KUK) and wrap it with the Hardware Unique Key (HUK).
 *
 * Implements @ref tsip_api_t::encryptedKeyWrap.
 *
 * @par Conditions
 * Argument @ref RZG::tsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZG_r-tsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZG_r-tsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_TSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL      Input KUK is illegal.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_EncryptedKeyWrap (tsip_ctrl_t * const              p_ctrl,
                                   tsip_wrapped_key_t const * const p_key_update_key,
                                   void const * const               p_initial_vector,
                                   void const * const               p_encrypted_key,
                                   tsip_wrapped_key_t * const       p_wrapped_key)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_key_update_key);
    FSP_ASSERT(p_key_update_key->p_value);
    FSP_ASSERT(p_initial_vector);
    FSP_ASSERT(p_encrypted_key);
    FSP_ASSERT(p_wrapped_key);
    FSP_ASSERT(p_wrapped_key->p_value);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsip_key_type_extend_t         key_type_ext = r_tsip_key_type_parse(p_wrapped_key->type);        // Parse key type
    tsip_func_encrypted_key_wrap_t p_func       = select_func_encrypted_key_wrap(key_type_ext);      // Set function

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(TSIP_KEY_TYPE_KUK == p_key_update_key->type, FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL); // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                   // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Set KUK */
    r_tsip_kuk_set(p_key_update_key->p_value);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret =
        p_func((uint32_t const *) p_initial_vector,
               (uint32_t const *) p_encrypted_key,
               (uint32_t *) p_wrapped_key->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        case TSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * This function provides Key Wrap algorithm compliant with RFC3394.
 * Using p_wrapped_kek to wrap p_wrapped_target_key, and output the result to p_rfc3394_wrapped_target_key.
 *
 * Implements @ref tsip_api_t::rfc3394_KeyWrap.
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @par Conditions
 * Argument @ref RZG::tsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZG_r-tsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZG_r-tsip-protected-configuration "Configuration".
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_INVALID_ARGUMENT              Input key type or mode is illegal.
 * @retval FSP_ERR_CRYPTO_TSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL      Input key value is illegal.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_RFC3394_KeyWrap (tsip_ctrl_t * const              p_ctrl,
                                  tsip_wrapped_key_t const * const p_wrapped_kek,
                                  tsip_wrapped_key_t const * const p_wrapped_target_key,
                                  uint8_t * const                  p_rfc3394_wrapped_target_key)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_kek);
    FSP_ASSERT(p_wrapped_kek->p_value);
    FSP_ASSERT(p_wrapped_target_key);
    FSP_ASSERT(p_wrapped_target_key->p_value);
    FSP_ASSERT(p_rfc3394_wrapped_target_key);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsip_key_type_extend_t       key_type_ext = r_tsip_key_type_parse(p_wrapped_kek->type);     // Parse key type
    tsip_func_rfc3394_key_wrap_t p_func       = gp_func_rfc3394_key_wrap[key_type_ext.subtype]; // Set function

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(TSIP_PRV_ALG_AES == key_type_ext.alg, FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL);   // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                              // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Check key type and get parameters */
    uint32_t wrapped_key_type[1] = {0};
    uint32_t key_index_size      = r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_target_key->type));
    uint32_t wrapped_key_size    =
        r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_PLAIN_KEY(p_wrapped_target_key->type) + 8);

    FSP_ERROR_RETURN(FSP_SUCCESS == r_tsip_get_rfc3394_key_wrap_param(p_wrapped_target_key->type, wrapped_key_type),
                     FSP_ERR_INVALID_ARGUMENT);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func((const uint32_t *) p_wrapped_kek->p_value,
                                 wrapped_key_type,
                                 (const uint32_t *) p_wrapped_target_key->p_value,
                                 (uint32_t *) p_rfc3394_wrapped_target_key,
                                 key_index_size,
                                 wrapped_key_size);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_FAIL;
            break;
        }

        case TSIP_RET_KEY_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * This function provides Key Unwrap algorithm compliant with RFC3394.
 * Using p_wrapped_kek to unwrap p_rfc3394_wrapped_target_key, and output the result to p_wrapped_target_key.
 *
 * Implements @ref tsip_api_t::rfc3394_KeyUnwrap.
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @par Conditions
 * Argument @ref RZG::tsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZG_r-tsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZG_r-tsip-protected-configuration "Configuration".
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_INVALID_ARGUMENT              Input key type or mode is illegal.
 * @retval FSP_ERR_CRYPTO_TSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL      Input key value is illegal.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_RFC3394_KeyUnwrap (tsip_ctrl_t * const              p_ctrl,
                                    tsip_wrapped_key_t const * const p_wrapped_kek,
                                    uint8_t const * const            p_rfc3394_wrapped_target_key,
                                    tsip_wrapped_key_t * const       p_wrapped_target_key)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_kek);
    FSP_ASSERT(p_wrapped_kek->p_value);
    FSP_ASSERT(p_rfc3394_wrapped_target_key);
    FSP_ASSERT(p_wrapped_target_key);
    FSP_ASSERT(p_wrapped_target_key->p_value);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsip_key_type_extend_t         key_type_ext = r_tsip_key_type_parse(p_wrapped_kek->type);       // Parse key type
    tsip_func_rfc3394_key_unwrap_t p_func       = gp_func_rfc3394_key_unwrap[key_type_ext.subtype]; // Set function

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(TSIP_PRV_ALG_AES == key_type_ext.alg, FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL);       // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                  // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Check key type and get parameters */
    uint32_t wrapped_key_type[1] = {0};
    uint32_t key_index_size      = r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_WRAPPED_KEY(p_wrapped_target_key->type));
    uint32_t wrapped_key_size    =
        r_tsip_byte_to_word_convert(TSIP_BYTE_SIZE_PLAIN_KEY(p_wrapped_target_key->type) + 8);

    FSP_ERROR_RETURN(FSP_SUCCESS ==
                     r_tsip_get_rfc3394_key_wrap_param(p_wrapped_target_key->type, wrapped_key_type),
                     FSP_ERR_INVALID_ARGUMENT);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func((const uint32_t *) p_wrapped_kek->p_value,
                                 wrapped_key_type,
                                 (const uint32_t *) p_rfc3394_wrapped_target_key,
                                 (uint32_t *) p_wrapped_target_key->p_value,
                                 wrapped_key_size,
                                 key_index_size);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_FAIL;
            break;
        }

        case TSIP_RET_KEY_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Exports public key parameters from a wrapped key.
 *
 * Implements @ref tsip_api_t::publicKeyExport.
 *
 * Relative position of each elements in p_raw_public_key is shown in below:
 * - ECC (TSIP_KEY_TYPE_ECC_*) :
 *   Qx placed first and Qy placed after that.
 *   |bit length|Qx|Qy|
 *   |----------|--|--|
 *   |256       |0 |32|
 *   |384       |0 |48|
 *   |512       |0 |64|
 *   |521       |0 |66|
 *
 * - RSA (TSIP_KEY_TYPE_RSA_*) : n placed first and e placed after that.
 *   |modulus|n|e  |
 *   |-------|-|---|
 *   |1024   |0|128|
 *   |2048   |0|256|
 *   |3072   |0|384|
 *   |4096   |0|512|
 *
 * @par State transition
 * This API can be executed in **any state** including STATE_INITIAL, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL      Input key value is illegal.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_PublicKeyExport (tsip_wrapped_key_t const * const p_wrapped_public_key,
                                  uint8_t * const                  p_raw_public_key)
{
#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_wrapped_public_key);
    FSP_ASSERT(p_wrapped_public_key->p_value);
    FSP_ASSERT(p_raw_public_key);
#endif

    tsip_key_type_extend_t key_type_ext = r_tsip_key_type_parse(p_wrapped_public_key->type); // Parse key type

    fsp_err_t err  = FSP_ERR_CRYPTO_TSIP_KEY_SET_FAIL;
    uint8_t * base = (uint8_t *) p_wrapped_public_key->p_value + r_tsip_word_to_byte_convert(
        TSIP_CFG_WORD_SIZE_WRAPPED_PUBLIC_KEY_PREFIX);
    uint32_t param1_pos;
    uint32_t param1_len;
    uint32_t param2_pos;
    uint32_t param2_len;

    switch (key_type_ext.alg)
    {
        case TSIP_PRV_ALG_ECC_PUBLIC:
        {
            param1_pos = gs_ecc_param1_pos[key_type_ext.subtype];
            param1_len = gs_ecc_param1_len[key_type_ext.subtype];
            param2_pos = gs_ecc_param2_pos[key_type_ext.subtype];
            param2_len = gs_ecc_param2_len[key_type_ext.subtype];
            err        = FSP_SUCCESS;
            break;
        }

        case TSIP_PRV_ALG_RSA_PUBLIC:
        {
            param1_pos = gs_rsa_n_pos;
            param1_len = gs_rsa_n_len[key_type_ext.subtype];
            param2_pos = gs_rsa_e_pos[key_type_ext.subtype];
            param2_len = gs_rsa_e_len;
            err        = FSP_SUCCESS;
            break;
        }

        default:
        {
            /* Do nothing */
        }
    }

    if (FSP_SUCCESS == err)
    {
        memcpy(p_raw_public_key, base + param1_pos, param1_len);
        memcpy(p_raw_public_key + param1_len, base + param2_pos, param2_len);
    }

    return err;
}

/*******************************************************************************************************************//**
 * @}
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Generates a 128-bit random number.
 *
 * @param[in,out] p_ctrl   Pointer to control block.
 * @param[out]    p_random Pointer to destination of random number. The length is 16 bytes.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t r_tsip_random_number_generate (tsip_ctrl_t * const p_ctrl, uint8_t * const p_random)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = gp_func_rng((uint32_t *) p_random);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Select primitive function of key generation from key type.
 *
 * @param[in] key_type_ext Extended key type.
 *
 * @return Pointer to function.
 ***********************************************************************************************************************/
static tsip_func_key_generate_t select_func_key_generate (tsip_key_type_extend_t key_type_ext)
{
    tsip_func_key_generate_t ret = NULL;

    switch (key_type_ext.alg)
    {
        case TSIP_PRV_ALG_AES:
        {
            ret = gp_func_key_generate_aes[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_XTS_AES:
        {
            ret = gp_func_key_generate_xts_aes[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_CHACHA:
        {
            ret = gp_func_key_generate_chacha[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_HMAC:
        {
            ret = gp_func_key_generate_hmac[key_type_ext.subtype];
            break;
        }

        default:
        {
            /* Do nothing */
        }
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Select primitive function of key pair generation from public key type.
 *
 * @param[in] key_type_ext Extended key type.
 *
 * @return Pointer to function.
 ***********************************************************************************************************************/
static tsip_func_key_pair_generate_t select_func_key_pair_generate (tsip_key_type_extend_t key_type_ext)
{
    tsip_func_key_pair_generate_t ret = NULL;

    switch (key_type_ext.alg)
    {
        case TSIP_PRV_ALG_ECC_PUBLIC:
        {
            ret = gp_func_key_pair_generate_ecc[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_RSA_PUBLIC:
        {
            ret = gp_func_key_pair_generate_rsa[key_type_ext.subtype];
            break;
        }

        default:
        {
            /* Do nothing */
        }
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Select primitive function of encrypted key wrapping from key type.
 *
 * @param[in] key_type_ext Extended key type.
 *
 * @return Pointer to function.
 ***********************************************************************************************************************/
static tsip_func_encrypted_key_wrap_t select_func_encrypted_key_wrap (tsip_key_type_extend_t key_type_ext)
{
    tsip_func_encrypted_key_wrap_t ret = NULL;

    switch (key_type_ext.alg)
    {
        case TSIP_PRV_ALG_AES:
        {
            ret = gp_func_encrypted_key_wrap_aes[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_XTS_AES:
        {
            ret = gp_func_encrypted_key_wrap_xts_aes[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_CHACHA:
        {
            ret = gp_func_encrypted_key_wrap_chacha[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_ECC_PUBLIC:
        {
            ret = gp_func_encrypted_key_wrap_ecc_pub[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_ECC_PRIVATE:
        {
            ret = gp_func_encrypted_key_wrap_ecc_priv[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_RSA_PUBLIC:
        {
            ret = gp_func_encrypted_key_wrap_rsa_pub[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_RSA_PRIVATE:
        {
            ret = gp_func_encrypted_key_wrap_rsa_priv[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_HMAC:
        {
            ret = gp_func_encrypted_key_wrap_hmac[key_type_ext.subtype];
            break;
        }

        default:
        {
            /* Do nothing */
        }
    }

    return ret;
}
