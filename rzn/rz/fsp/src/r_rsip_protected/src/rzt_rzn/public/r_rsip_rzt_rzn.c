/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_public.h"
#include "r_rsip_primitive.h"
#include "r_rsip_wrapper.h"
#include "r_sb_api.h"
#include "r_rsip_otp.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define RSIP_PRV_BYTE_SIZE_ENC_ROOT_CERT_MAC                           (16U)

#if RSIP_CFG_AES_128_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_128                           r_rsip_p10
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_128                           NULL
#endif
#if RSIP_CFG_AES_192_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_192                           r_rsip_p84
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_192                           NULL
#endif
#if RSIP_CFG_AES_256_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_256                           r_rsip_p04
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_256                           NULL
#endif

#if RSIP_CFG_XTS_AES_128_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_XTS_AES_128                       r_rsip_p18
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_XTS_AES_128                       NULL
#endif
#if RSIP_CFG_XTS_AES_256_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_XTS_AES_256                       r_rsip_p1a
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_XTS_AES_256                       NULL
#endif

#if RSIP_CFG_ECC_SECP256R1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP256R1_PUBLIC              r_rsip_wrapper_pfa_secp256r1
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP256R1_PRIVATE             r_rsip_wrapper_pf3_secp256r1
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP256R1_PUBLIC              NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP256R1_PRIVATE             NULL
#endif
#if RSIP_CFG_ECC_SECP384R1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP384R1_PUBLIC              r_rsip_wrapper_pf7_secp384r1
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP384R1_PRIVATE             r_rsip_wrapper_pf8_secp384r1
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP384R1_PUBLIC              NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP384R1_PRIVATE             NULL
#endif
#if RSIP_CFG_ECC_SECP521R1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP521R1_PUBLIC              r_rsip_p3e
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP521R1_PRIVATE             r_rsip_p3f
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP521R1_PUBLIC              NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP521R1_PRIVATE             NULL
#endif
#if RSIP_CFG_ECC_BRAINPOOLP256R1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP256R1_PUBLIC        r_rsip_wrapper_pfa_brainpoolp256r1
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP256R1_PRIVATE       r_rsip_wrapper_pf3_brainpoolp256r1
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP256R1_PUBLIC        NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP256R1_PRIVATE       NULL
#endif
#if RSIP_CFG_ECC_BRAINPOOLP384R1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP384R1_PUBLIC        r_rsip_wrapper_pf7_brainpoolp384r1
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP384R1_PRIVATE       r_rsip_wrapper_pf8_brainpoolp384r1
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP384R1_PUBLIC        NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP384R1_PRIVATE       NULL
#endif
#if RSIP_CFG_ECC_BRAINPOOLP512R1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP512R1_PUBLIC        r_rsip_pfb
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP512R1_PRIVATE       r_rsip_pfc
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP512R1_PUBLIC        NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP512R1_PRIVATE       NULL
#endif
#if RSIP_CFG_ECC_EDWARDS25519_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_EDWARDS25519_PUBLIC           r_rsip_pb1
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_EDWARDS25519_PRIVATE          r_rsip_pb2
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_EDWARDS25519_PUBLIC           NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_EDWARDS25519_PRIVATE          NULL
#endif

#if RSIP_CFG_RSA_1024_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_1024_PUBLIC                   r_rsip_p59
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_1024_PRIVATE                  r_rsip_p60
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_1024         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_1024         NULL
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_1024_PUBLIC                   NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_1024_PRIVATE                  NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_1024         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_1024         NULL
#endif
#if RSIP_CFG_RSA_2048_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_2048_PUBLIC                   r_rsip_p62
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_2048_PRIVATE                  r_rsip_p63
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_2048         r_rsip_peb
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_2048         r_rsip_pec
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_2048_PUBLIC                   NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_2048_PRIVATE                  NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_2048         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_2048         NULL
#endif
#if RSIP_CFG_RSA_3072_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_3072_PUBLIC                   r_rsip_p37
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_3072_PRIVATE                  r_rsip_p42
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_3072         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_3072         NULL
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_3072_PUBLIC                   NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_3072_PRIVATE                  NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_3072         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_3072         NULL
#endif
#if RSIP_CFG_RSA_4096_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_4096_PUBLIC                   r_rsip_p43
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_4096_PRIVATE                  r_rsip_p45
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_4096         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_4096         NULL
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_4096_PUBLIC                   NULL
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_4096_PRIVATE                  NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_4096         NULL
 #define RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_4096         NULL
#endif

#if RSIP_CFG_HMAC_SHA1_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA1                         r_rsip_wrapper_p80_hmac_sha1
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA1                         NULL
#endif
#if RSIP_CFG_HMAC_SHA224_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA224                       r_rsip_wrapper_p80_hmac_sha224
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA224                       NULL
#endif
#if RSIP_CFG_HMAC_SHA256_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA256                       r_rsip_wrapper_p80_hmac_sha256
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA256                       NULL
#endif
#if RSIP_CFG_HMAC_SHA384_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA384                       r_rsip_p92
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA384                       NULL
#endif
#if RSIP_CFG_HMAC_SHA512_ENABLE
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA512                       r_rsip_p93
#else
 #define RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA512                       NULL
#endif

#if RSIP_CFG_KDF_HMAC_SHA256_ENABLE
 #define RSIP_PRV_FUNC_KDF_TLS12_PRF_VERIFY_DATA_CLIENT_SHA256         r_rsip_wrapper_pe9_sha256_client
 #define RSIP_PRV_FUNC_KDF_TLS12_PRF_VERIFY_DATA_SERVER_SHA256         r_rsip_wrapper_pe9_sha256_server
#else
 #define RSIP_PRV_FUNC_KDF_TLS12_PRF_VERIFY_DATA_CLIENT_SHA256         NULL
 #define RSIP_PRV_FUNC_KDF_TLS12_PRF_VERIFY_DATA_SERVER_SHA256         NULL
#endif

#if BSP_FEATURE_RSIP_JTAG_DEBUG_AUTH_LEVEL1
 #define RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_JTAG_DEBUG_LEVEL1    r_rsip_wrapper_p15_jtag_level1
#else
 #define RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_JTAG_DEBUG_LEVEL1    NULL
#endif

#if BSP_FEATURE_RSIP_JTAG_DEBUG_AUTH_LEVEL2
 #define RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_JTAG_DEBUG_LEVEL2    r_rsip_wrapper_p15_jtag_level2
#else
 #define RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_JTAG_DEBUG_LEVEL2    NULL
#endif

#if BSP_FEATURE_RSIP_SCI_USB_BOOT_AUTH
 #define RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_SCI_USB_BOOT         r_rsip_wrapper_p15_sci_usb
#else
 #define RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_SCI_USB_BOOT         NULL
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Initial key wrap */
typedef rsip_ret_t (* rsip_func_initial_key_wrap_t)(const uint32_t InData_SharedKeyNum[],
                                                    const uint32_t InData_SharedKeyIndex[],
                                                    const uint32_t InData_SessionKey[], const uint32_t InData_IV[],
                                                    const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[]);

/* Root certificate key import */
typedef rsip_ret_t (* rsip_func_root_cert_key_import_t)(const uint32_t InData_RootCertificate[],
                                                        const uint32_t InData_RootCertificateInfo[],
                                                        const uint32_t InData_RootCertificatePubKey[],
                                                        uint32_t       OutData_KeyIndex[]);

/* TLS1.2 PRF verify_data compute */
typedef rsip_ret_t (* rsip_func_kdf_tls12_prf_verify_data_compute_t)(const uint32_t InData_Hash[],
                                                                     const uint32_t InData_KeyIndex[],
                                                                     uint32_t       OutData_Verify_data[]);

/* TLS1.2 RSA premaster secret */
typedef rsip_ret_t (* rsip_func_tls12_rsa_premaster_secret_encrypt_t)(const uint32_t InData_KeyIndex[],
                                                                      const uint32_t InData_EncPreMasterSecret[],
                                                                      uint32_t       OutData_EncPremasterSecret[]);
typedef rsip_ret_t (* rsip_func_tls12_rsa_premaster_secret_decrypt_t)(const uint32_t InData_KeyIndex[],
                                                                      const uint32_t InData_EncPreMasterSecret[],
                                                                      uint32_t       OutData_KeyIndex[]);

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static rsip_func_initial_key_wrap_t     select_func_initial_key_wrap(rsip_key_type_extend_t key_type_ext);
static rsip_func_root_cert_key_import_t select_func_root_cert_key_import(rsip_key_type_extend_t key_type_ext);
RSIP_PRV_STATIC_INLINE uint32_t         r_rsip_ceil(const uint32_t num, const uint32_t significance);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_aes[RSIP_PRV_KEY_SUBTYPE_AES_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_AES_128] = RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_128,
    [RSIP_PRV_KEY_SUBTYPE_AES_192] = RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_192,
    [RSIP_PRV_KEY_SUBTYPE_AES_256] = RSIP_PRV_FUNC_INIT_KEY_WRAP_AES_256
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_xts_aes[RSIP_PRV_KEY_SUBTYPE_AES_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_AES_128] = RSIP_PRV_FUNC_INIT_KEY_WRAP_XTS_AES_128,
    [RSIP_PRV_KEY_SUBTYPE_AES_256] = RSIP_PRV_FUNC_INIT_KEY_WRAP_XTS_AES_256
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_chacha[RSIP_PRV_KEY_SUBTYPE_CHACHA_NUM] =
{
    NULL
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_ecc_pub[RSIP_PRV_KEY_SUBTYPE_ECC_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1]       = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP256R1_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1]       = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP384R1_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1]       = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP521R1_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1] = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP256R1_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1] = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP384R1_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1] = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP512R1_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519]    = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_EDWARDS25519_PUBLIC
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_ecc_priv[RSIP_PRV_KEY_SUBTYPE_ECC_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1]       = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP256R1_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1]       = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP384R1_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1]       = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_SECP521R1_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1] = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP256R1_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1] = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP384R1_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1] = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_BRAINPOOLP512R1_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519]    = RSIP_PRV_FUNC_INIT_KEY_WRAP_ECC_EDWARDS25519_PRIVATE
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_rsa_pub[RSIP_PRV_KEY_SUBTYPE_RSA_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_RSA_1024] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_1024_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_RSA_2048] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_2048_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_RSA_3072] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_3072_PUBLIC,
    [RSIP_PRV_KEY_SUBTYPE_RSA_4096] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_4096_PUBLIC
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_rsa_priv[RSIP_PRV_KEY_SUBTYPE_RSA_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_RSA_1024] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_1024_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_RSA_2048] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_2048_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_RSA_3072] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_3072_PRIVATE,
    [RSIP_PRV_KEY_SUBTYPE_RSA_4096] = RSIP_PRV_FUNC_INIT_KEY_WRAP_RSA_4096_PRIVATE
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_hmac[RSIP_PRV_KEY_SUBTYPE_HMAC_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA1]   = RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA1,
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA224] = RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA224,
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA256] = RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA256,
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA384] = RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA384,
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA512] = RSIP_PRV_FUNC_INIT_KEY_WRAP_HMAC_SHA512
};

static const rsip_func_initial_key_wrap_t gsp_func_initial_key_wrap_misc[RSIP_PRV_KEY_SUBTYPE_MISC_NUM] =
{
    [RSIP_PRV_KEY_SUBTYPE_MISC_KUK] = r_rsip_p1f
};

static const rsip_func_initial_key_wrap_t gsp_func_auth_password_hash_compute[3] =
{
    [RSIP_AUTH_TYPE_JTAG_DEBUG_LEVEL1] = RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_JTAG_DEBUG_LEVEL1,
    [RSIP_AUTH_TYPE_JTAG_DEBUG_LEVEL2] = RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_JTAG_DEBUG_LEVEL2,
    [RSIP_AUTH_TYPE_SCI_USB_BOOT]      = RSIP_PRV_FUNC_AUTH_PASSWORD_HASH_COMPUTE_SCI_USB_BOOT
};

static const rsip_func_kdf_tls12_prf_verify_data_compute_t gsp_func_kdf_tls12_prf_verify_data_compute
[RSIP_PRV_KEY_SUBTYPE_HMAC_NUM][2] =
{
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA256][RSIP_TLS12_PRF_LABEL_CLIENT_FINISHED] =
        RSIP_PRV_FUNC_KDF_TLS12_PRF_VERIFY_DATA_CLIENT_SHA256,
    [RSIP_PRV_KEY_SUBTYPE_HMAC_SHA256][RSIP_TLS12_PRF_LABEL_SERVER_FINISHED] =
        RSIP_PRV_FUNC_KDF_TLS12_PRF_VERIFY_DATA_SERVER_SHA256
};

static const rsip_func_tls12_rsa_premaster_secret_encrypt_t gsp_func_tls12_rsa_premaster_secret_encrypt[
    RSIP_PRV_KEY_SUBTYPE_RSA_NUM
] =
{
    [RSIP_PRV_KEY_SUBTYPE_RSA_1024] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_1024,
    [RSIP_PRV_KEY_SUBTYPE_RSA_2048] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_2048,
    [RSIP_PRV_KEY_SUBTYPE_RSA_3072] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_3072,
    [RSIP_PRV_KEY_SUBTYPE_RSA_4096] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_ENCRYPT_4096
};

static const rsip_func_tls12_rsa_premaster_secret_decrypt_t gsp_func_tls12_rsa_premaster_secret_decrypt[
    RSIP_PRV_KEY_SUBTYPE_RSA_NUM
] =
{
    [RSIP_PRV_KEY_SUBTYPE_RSA_1024] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_1024,
    [RSIP_PRV_KEY_SUBTYPE_RSA_2048] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_2048,
    [RSIP_PRV_KEY_SUBTYPE_RSA_3072] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_3072,
    [RSIP_PRV_KEY_SUBTYPE_RSA_4096] = RSIP_PRV_FUNC_TLS12_RSA_PREMASTER_SECRET_DECRYPT_4096
};

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_RSIP_PROTECTED
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Decrypts an encrypted user key with User Factory Programming Key (UFPK) and wrap it with the Hardware Unique Key (HUK).
 *
 * @par Conditions
 * Argument @ref rsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZN_r-rsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                                 Pointer to control block.
 * @param[in]     p_wrapped_user_factory_programming_key Wrapped User Factory Programming Key (W-UFPK).
 *                                                       The length is 32 bytes.
 * @param[in]     p_initial_vector                       Initialization vector when generating encrypted_key.
 *                                                       The length is 16 bytes.
 * @param[in]     p_encrypted_key                        Encrypted user key. The length depends on the key type.
 * @param[in,out] p_wrapped_key                          Pointer to destination of wrapped key.
 *                                                       The length depends on the key type.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 *
 * @note See also Section @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms".
 **********************************************************************************************************************/
fsp_err_t R_RSIP_InitialKeyWrap (rsip_ctrl_t * const        p_ctrl,
                                 void const * const         p_wrapped_user_factory_programming_key,
                                 void const * const         p_initial_vector,
                                 void const * const         p_encrypted_key,
                                 rsip_wrapped_key_t * const p_wrapped_key)

{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_user_factory_programming_key);
    FSP_ASSERT(p_initial_vector);
    FSP_ASSERT(p_encrypted_key);
    FSP_ASSERT(p_wrapped_key);
    FSP_ASSERT(p_wrapped_key->p_value);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rsip_key_type_extend_t       key_type_ext = r_rsip_key_type_parse(p_wrapped_key->type); // Parse key type
    rsip_func_initial_key_wrap_t p_func       = select_func_initial_key_wrap(key_type_ext); // Set function

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                          // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Read W-HRK from OTP */
    uint32_t   whrk_num[RSIP_PRV_WORD_SIZE_WHRK_NUM];
    uint32_t   whrk[RSIP_PRV_WORD_SIZE_WHRK];
    rsip_ret_t rsip_ret = r_rsip_whrk_read(whrk_num, whrk);

    if (RSIP_RET_PASS == rsip_ret)
    {
        /* Call function (cast to match the argument type with the primitive function) */
        rsip_ret = p_func((uint32_t const *) whrk_num,
                          (uint32_t const *) whrk,
                          (uint32_t const *) p_wrapped_user_factory_programming_key,
                          (uint32_t const *) p_initial_vector,
                          (uint32_t const *) p_encrypted_key,
                          (uint32_t *) p_wrapped_key->p_value);
    }

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Decrypts a common key for secure boot with User Factory Programming Key (UFPK) and wrap it with the Hardware Unique Key (HUK).
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                                 Pointer to control block.
 * @param[in]     p_wrapped_user_factory_programming_key Wrapped User Factory Programming Key (W-UFPK).
 *                                                       The length is 32 bytes.
 * @param[in]     p_initial_vector                       Initialization vector when generating encrypted_key.
 *                                                       The length is 16 bytes.
 * @param[in]     p_encrypted_key                        Encrypted key.
 * @param[out]    p_injected_key                         Pointer to destination of injected key.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_SB_InitialCommonKeyWrap (rsip_ctrl_t * const          p_ctrl,
                                          void const * const           p_wrapped_user_factory_programming_key,
                                          void const * const           p_initial_vector,
                                          void const * const           p_encrypted_key,
                                          rsip_sb_common_key_t * const p_injected_key)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_user_factory_programming_key);
    FSP_ASSERT(p_initial_vector);
    FSP_ASSERT(p_encrypted_key);
    FSP_ASSERT(p_injected_key);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Read W-HRK from OTP */
    uint32_t   whrk_num[RSIP_PRV_WORD_SIZE_WHRK_NUM];
    uint32_t   whrk[RSIP_PRV_WORD_SIZE_WHRK];
    rsip_ret_t rsip_ret = r_rsip_whrk_read(whrk_num, whrk);

    if (RSIP_RET_PASS == rsip_ret)
    {
        /* Call primitive (cast to match the argument type with the primitive function) */
        rsip_ret = r_rsip_p03((uint32_t const *) whrk_num,
                              (uint32_t const *) whrk,
                              (uint32_t const *) p_wrapped_user_factory_programming_key,
                              (uint32_t const *) p_initial_vector,
                              (uint32_t const *) p_encrypted_key,
                              (uint32_t *) p_injected_key);
    }

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Decrypts user password for boot/debug authentication with User Factory Programming Key (UFPK)
 * and generates the password hash.
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                                 Pointer to control block.
 * @param[in]     p_wrapped_user_factory_programming_key Pointer to wrapped User Factory Programming Key (W-UFPK).
 *                                                       The length is 32 bytes.
 * @param[in]     p_initial_vector                       Pointer to initialization vector when generating encrypted_key.
 *                                                       The length is 16 bytes.
 * @param[in]     authentication_type                    Authentication type.
 * @param[in]     p_encrypted_password                   Pointer to encrypted user password. The length is 32 bytes.
 * @param[out]    p_hashed_password                      Pointer to destination of password The length is 32 bytes.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Selected authentication_type is not supported on this device.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_AuthPasswordHashCompute (rsip_ctrl_t * const                 p_ctrl,
                                          void const * const                  p_wrapped_user_factory_programming_key,
                                          void const * const                  p_initial_vector,
                                          rsip_auth_type_t const              authentication_type,
                                          void const * const                  p_encrypted_password,
                                          rsip_hashed_auth_password_t * const p_hashed_password)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

    /* Set function */
    rsip_func_initial_key_wrap_t p_func = gsp_func_auth_password_hash_compute[authentication_type];

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_user_factory_programming_key);
    FSP_ASSERT(p_initial_vector);
    FSP_ASSERT(p_encrypted_password);
    FSP_ASSERT(p_hashed_password);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Check function */
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Read W-HRK from OTP */
    uint32_t   whrk_num[RSIP_PRV_WORD_SIZE_WHRK_NUM];
    uint32_t   whrk[RSIP_PRV_WORD_SIZE_WHRK];
    rsip_ret_t rsip_ret = r_rsip_whrk_read(whrk_num, whrk);

    if (RSIP_RET_PASS == rsip_ret)
    {
        /* Call primitive (cast to match the argument type with the primitive function) */
        rsip_ret = p_func((uint32_t const *) whrk_num,
                          (uint32_t const *) whrk,
                          (uint32_t const *) p_wrapped_user_factory_programming_key,
                          (uint32_t const *) p_initial_vector,
                          (uint32_t const *) p_encrypted_password,
                          (uint32_t *) p_hashed_password);
    }

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Inputs encrypted certificate with User Factory Programming Key (UFPK) and wraps it.
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                                 Pointer to control block.
 * @param[in]     p_wrapped_user_factory_programming_key Wrapped User Factory Programming Key (W-UFPK).
 *                                                       The length is 32 bytes.
 * @param[in]     p_initial_vector                       Initialization vector when generating encrypted_key.
 *                                                       The length is 16 bytes.
 * @param[in]     p_encrypted_cert                       Encrypted certificate.
 * @param[in]     cert_length                            Raw certificate length.
 * @param[out]    p_cert                                 Pointer to destination of raw certificate.
 * @param[out]    p_cert_mac                             Pointer to destination of certificate MAC.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 *
 * @note p_cert is output with 16-byte padding. The certificate with padding is input to R_RSIP_PKI_RootCertKeyImport().
 **********************************************************************************************************************/
fsp_err_t R_RSIP_PKI_InitialRootCertWrap (rsip_ctrl_t * const          p_ctrl,
                                          void const * const           p_wrapped_user_factory_programming_key,
                                          void const * const           p_initial_vector,
                                          void const * const           p_encrypted_cert,
                                          uint32_t const               cert_length,
                                          uint8_t * const              p_cert,
                                          rsip_root_cert_mac_t * const p_cert_mac)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_user_factory_programming_key);
    FSP_ASSERT(p_initial_vector);
    FSP_ASSERT(p_encrypted_cert);
    FSP_ASSERT(p_cert);
    FSP_ASSERT(p_cert_mac);

    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Read W-HRK from OTP */
    uint32_t   whrk_num[RSIP_PRV_WORD_SIZE_WHRK_NUM];
    uint32_t   whrk[RSIP_PRV_WORD_SIZE_WHRK];
    rsip_ret_t rsip_ret = r_rsip_whrk_read(whrk_num, whrk);

    uint32_t root_certificate_length[1] =
    {
        bswap_32big(cert_length)
    };

    if (RSIP_RET_PASS == rsip_ret)
    {
        /* Call primitive (cast to match the argument type with the primitive function) */
        rsip_ret = r_rsip_pe8((uint32_t const *) whrk_num,
                              (uint32_t const *) whrk,
                              (uint32_t const *) p_wrapped_user_factory_programming_key,
                              (uint32_t const *) p_initial_vector,
                              (uint32_t const *) p_encrypted_cert,
                              root_certificate_length,
                              (uint32_t *) p_cert,
                              (uint32_t *) p_cert_mac->value,
                              r_rsip_byte_to_word_convert(r_rsip_ceil(cert_length, RSIP_PRV_BYTE_SIZE_AES_BLOCK) +
                                                          RSIP_PRV_BYTE_SIZE_ENC_ROOT_CERT_MAC));
    }

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Verifies wrapped root certificate and wraps public key included in it.
 *
 * @par Conditions
 * Argument @ref rsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZN_r-rsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl               Pointer to control block.
 * @param[in]     p_cert               Raw certificate.
 * @param[in]     p_cert_mac           Pointer to certificate MAC.
 * @param[in]     p_key_param1         Pointer to start address of the public key parameter in certificate.
 *                                     - [ECC] Qx
 *                                     - [RSA] n
 * @param[in]     key_param1_length    Length of key_param1 stored in the certificate.
 * @param[in]     p_key_param2         Pointer to start address of the public key parameter in certificate.
 *                                     - [ECC] Qy
 *                                     - [RSA] e
 * @param[in]     key_param2_length    Length of key_param2 stored in the certificate.
 * @param[in,out] p_wrapped_public_key Pointer to destination of wrapped public key. The length depends on key type.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 *
 * @note
 * - Enter argument p_cert of R_RSIP_PKI_InitialRootCertWrap() into this function without removing the padding.
 * - For arguments p_key_param1 and p_key_param2, specify an address inside the certificate.
 *   Addresses outside the certificate are invalid.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_PKI_RootCertKeyImport (rsip_ctrl_t * const                p_ctrl,
                                        uint8_t const * const              p_cert,
                                        rsip_root_cert_mac_t const * const p_cert_mac,
                                        uint8_t const * const              p_key_param1,
                                        uint32_t const                     key_param1_length,
                                        uint8_t const * const              p_key_param2,
                                        uint32_t const                     key_param2_length,
                                        rsip_wrapped_key_t * const         p_wrapped_public_key)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cert);
    FSP_ASSERT(p_cert_mac);
    FSP_ASSERT(p_key_param1);
    FSP_ASSERT(p_key_param2);
    FSP_ASSERT(p_wrapped_public_key);
    FSP_ASSERT(p_wrapped_public_key->p_value);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rsip_key_type_extend_t           key_type_ext = r_rsip_key_type_parse(p_wrapped_public_key->type); // Parse key type
    rsip_func_root_cert_key_import_t p_func       = select_func_root_cert_key_import(key_type_ext);    // Set function

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                     // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    uint32_t root_certificate_pubkey[4] =
    {
        bswap_32big((uint32_t) ((uintptr_t) p_key_param1 - (uintptr_t) p_cert)),                         // Start position of param1
        bswap_32big((uint32_t) ((uintptr_t) p_key_param1 - (uintptr_t) p_cert + key_param1_length - 1)), // End position of param1
        bswap_32big((uint32_t) ((uintptr_t) p_key_param2 - (uintptr_t) p_cert)),                         // Start position of param2
        bswap_32big((uint32_t) ((uintptr_t) p_key_param2 - (uintptr_t) p_cert + key_param2_length - 1)), // End position of param2
    };

    /* Call primitive (cast to match the argument type with the primitive function) */
    rsip_ret_t rsip_ret = p_func((uint32_t const *) p_cert,
                                 (uint32_t const *) p_cert_mac->value,
                                 (uint32_t const *) root_certificate_pubkey,
                                 (uint32_t *) p_wrapped_public_key->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Computes plain verify_data of TLS1.2 from KDF output (TLS1.2 master secret).
 *
 * @par Conditions
 * Argument @ref rsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZN_r-rsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl        Pointer to control block.
 * @param[in]     p_wrapped_key Pointer to wrapped key derived by Derived Keying Material (DKM).
 * @param[in]     label         Label string. [Client] "client finished". [Server] "server finished".
 * @param[in]     p_hash        Hashed handshake message.
 * @param[out]    p_verify_data Pointer to destination of plain verify_data.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 * @retval FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL      Input key value is illegal.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_KDF_TLS12PRFVerifyDataCompute (rsip_ctrl_t * const              p_ctrl,
                                                rsip_wrapped_key_t const * const p_wrapped_key,
                                                rsip_tls12_prf_label_t const     label,
                                                uint8_t const * const            p_hash,
                                                uint8_t * const                  p_verify_data)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_key);
    FSP_ASSERT(p_wrapped_key->p_value);
    FSP_ASSERT(p_hash);
    FSP_ASSERT(p_verify_data);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rsip_key_type_extend_t key_type_ext = r_rsip_key_type_parse(p_wrapped_key->type);              // Parse key type
    rsip_func_kdf_tls12_prf_verify_data_compute_t p_func =
        gsp_func_kdf_tls12_prf_verify_data_compute[key_type_ext.subtype][label];                   // Set function

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(RSIP_PRV_ALG_KDF_HMAC == key_type_ext.alg, FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL); // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                 // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call function (cast to match the argument type with the primitive function) */
    rsip_ret_t rsip_ret = p_func((const uint32_t *) p_hash,
                                 (const uint32_t *) p_wrapped_key->p_value,
                                 (uint32_t *) p_verify_data);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_KEY_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Generates TLS1.2 premaster secret for RSA key exchange.
 *
 * @par Conditions
 * Argument @ref rsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZN_r-rsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                     Pointer to control block.
 * @param[out]    p_wrapped_premaster_secret Pointer to wrapped key of premaster secret.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 *
 * @note This function is used only on client side.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_TLS12_RSAPremasterSecretGenerate (rsip_ctrl_t * const        p_ctrl,
                                                   rsip_wrapped_key_t * const p_wrapped_premaster_secret)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_premaster_secret);

    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call primitive (cast to match the argument type with the primitive function) */
    rsip_ret_t rsip_ret = r_rsip_pea((uint32_t *) p_wrapped_premaster_secret->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            p_wrapped_premaster_secret->type = RSIP_KEY_TYPE_KDF_HMAC_SHA256;

            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Encrypts TLS1.2 premaster secret for RSA key exchange with RSAES-PKCS1-v1_5.
 *
 * @par Conditions
 * Argument @ref rsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZN_r-rsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                       Pointer to control block.
 * @param[in]     p_wrapped_public_key         Pointer to wrapped public key imported by R_RSIP_PKI_CertKeyImport().
 * @param[in]     p_wrapped_premaster_secret   Pointer to wrapped key of premaster secret.
 * @param[out]    p_encrypted_premaster_secret Pointer to encrypted premaster secret.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL      Input key value is illegal.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 *
 * @note This function used only on only client side.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_TLS12_RSAPremasterSecretEncrypt (rsip_ctrl_t * const              p_ctrl,
                                                  rsip_wrapped_key_t const * const p_wrapped_public_key,
                                                  rsip_wrapped_key_t const * const p_wrapped_premaster_secret,
                                                  uint8_t * const                  p_encrypted_premaster_secret)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_public_key);
    FSP_ASSERT(p_wrapped_premaster_secret);
    FSP_ASSERT(p_encrypted_premaster_secret);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rsip_key_type_extend_t key_type_ext = r_rsip_key_type_parse(p_wrapped_public_key->type);         // Parse key type
    rsip_func_tls12_rsa_premaster_secret_encrypt_t p_func =
        gsp_func_tls12_rsa_premaster_secret_encrypt[key_type_ext.subtype];                           // Set function

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(RSIP_PRV_ALG_RSA_PUBLIC == key_type_ext.alg, FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL); // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                   // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call primitive (cast to match the argument type with the primitive function) */
    rsip_ret_t rsip_ret = p_func((uint32_t const *) p_wrapped_public_key->p_value,
                                 (uint32_t const *) p_wrapped_premaster_secret->p_value,
                                 (uint32_t *) p_encrypted_premaster_secret);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_KEY_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Decrypts TLS1.2 premaster secret for RSA key exchange with RSAES-PKCS1-v1_5.
 *
 * @par Conditions
 * Argument @ref rsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZN_r-rsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZN_r-rsip-protected-configuration "Configuration".
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @param[in,out] p_ctrl                       Pointer to control block.
 * @param[in]     p_wrapped_private_key        Pointer to wrapped private key.
 * @param[in]     p_encrypted_premaster_secret Pointer to encrypted premaster secret.
 * @param[out]    p_wrapped_premaster_secret   Pointer to wrapped key of premaster secret.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL      Input key value is illegal.
 * @retval FSP_ERR_CRYPTO_RSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_RSIP_FATAL             Software corruption is detected.
 *
 * @note This function is used only on server side.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_TLS12_RSAPremasterSecretDecrypt (rsip_ctrl_t * const              p_ctrl,
                                                  rsip_wrapped_key_t const * const p_wrapped_private_key,
                                                  uint8_t const * const            p_encrypted_premaster_secret,
                                                  rsip_wrapped_key_t * const       p_wrapped_premaster_secret)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_wrapped_private_key);
    FSP_ASSERT(p_encrypted_premaster_secret);
    FSP_ASSERT(p_wrapped_premaster_secret);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    rsip_key_type_extend_t key_type_ext = r_rsip_key_type_parse(p_wrapped_private_key->type);         // Parse key type
    rsip_func_tls12_rsa_premaster_secret_decrypt_t p_func =
        gsp_func_tls12_rsa_premaster_secret_decrypt[key_type_ext.subtype];                            // Set function

#if RSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(RSIP_PRV_ALG_RSA_PRIVATE == key_type_ext.alg, FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL); // Check key type
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                    // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call primitive (cast to match the argument type with the primitive function) */
    rsip_ret_t rsip_ret = p_func((uint32_t const *) p_wrapped_private_key->p_value,
                                 (uint32_t const *) p_encrypted_premaster_secret,
                                 (uint32_t *) p_wrapped_premaster_secret->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_RSIP_FATAL;
    switch (rsip_ret)
    {
        case RSIP_RET_PASS:
        {
            p_wrapped_premaster_secret->type = RSIP_KEY_TYPE_KDF_HMAC_SHA256;

            err = FSP_SUCCESS;
            break;
        }

        case RSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_CRYPTO_RSIP_RESOURCE_CONFLICT;
            break;
        }

        case RSIP_RET_KEY_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_KEY_SET_FAIL;
            break;
        }

        case RSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_RSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_RSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Verifies a Manifest signature and decrypts program in the Manifest for secure boot.
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @note If this API returns FSP_ERR_SB_CRYPTO_AUTH_FAIL or FSP_ERR_SB_CRYPTO_PARAM_ERR, RSIP stops working.
 *
 * @param[in,out] p_ctrl               Pointer to control block.
 * @param[in]     p_key_cert           Pointer to key certificate.
 * @param[in]     key_cert_max_length  Maximum length of key certificate.
 * @param[in]     p_code_cert          Pointer to key code certificate.
 * @param[in]     code_cert_max_length Maximum length of code certificate.
 *
 * @retval FSP_SUCCESS                             Normal termination.
 * @retval FSP_ERR_ASSERTION                       A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                        Module is not open.
 * @retval FSP_ERR_INVALID_STATE                   Internal state is illegal.
 *
 * @retval FSP_ERR_SB_INTERNAL_FAIL                An internal failure.
 * @retval FSP_ERR_SB_INVALID_ARG                  An invalid argument was entered.
 * @retval FSP_ERR_SB_UNSUPPORTED_FUNCTION         Unsupported function executed.
 * @retval FSP_ERR_SB_INVALID_ALIGNMENT            Data entered with incorrect alignment.
 * @retval FSP_ERR_SB_MANI_INVALID_MAGIC           An invalid magic number is set.
 * @retval FSP_ERR_SB_MANI_UNSUPPORTED_VERSION     Unsupported version is set.
 * @retval FSP_ERR_SB_MANI_OUT_OF_RANGE_LEN        Out of range TLV Length is set.
 * @retval FSP_ERR_SB_MANI_TLV_FIELD_ERR           Missing required TLV field.
 * @retval FSP_ERR_SB_MANI_TLV_INVALID_LEN         The length exceeding the end of the manifest is specified
 *                                                 in length of the TLV field.
 * @retval FSP_ERR_SB_MANI_INVALID_IMAGE_LEN       An invalid image length is set.
 * @retval FSP_ERR_SB_MANI_MISMATCH_SIGN_ALGORITHM There is a wrong combination of signature algorithms.
 * @retval FSP_ERR_SB_MANI_UNSUPPORTED_ALGORITHM   An algorithm was specified that the manifest does not support.
 * @retval FSP_ERR_SB_CRYPTO_FAIL                  Cryptographic processing failure.
 * @retval FSP_ERR_SB_CRYPTO_AUTH_FAIL             Verification failed.
 * @retval FSP_ERR_SB_CRYPTO_UNSUPPORTED_ALGORITHM Unsupported algorithm.
 * @retval FSP_ERR_SB_CRYPTO_RESOURCE_CONFLICT     CryptoIP is in use.
 * @retval FSP_ERR_SB_CRYPTO_PARAM_ERR             Parameter error.
 **********************************************************************************************************************/
fsp_err_t R_RSIP_SB_ManifestVerify (rsip_ctrl_t * const   p_ctrl,
                                    uint8_t const * const p_key_cert,
                                    uint32_t const        key_cert_max_length,
                                    uint8_t const * const p_code_cert,
                                    uint32_t const        code_cert_max_length)
{
    rsip_instance_ctrl_t * p_instance_ctrl = (rsip_instance_ctrl_t *) p_ctrl;
    fsp_err_t              err             = (fsp_err_t) FSP_ERR_SB_INTERNAL_FAIL;

#if RSIP_CFG_PARAM_CHECKING_ENABLE

    /* p_key_cert may be 0x0 */
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_code_cert);
    FSP_ERROR_RETURN(RSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Check state */
    FSP_ERROR_RETURN(RSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    /* Call SB-Lib function */
    sb_ret_t sb_ret = R_SB_SecureBoot(p_key_cert, key_cert_max_length, p_code_cert, code_cert_max_length, NULL);

    /* Check error */
    switch (sb_ret)
    {
        case SB_RET_SUCCESS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case SB_RET_ERR_INTERNAL_FAIL:
        {
            err = (fsp_err_t) FSP_ERR_SB_INTERNAL_FAIL;
            break;
        }

        case SB_RET_ERR_INVALID_ARG:
        {
            err = (fsp_err_t) FSP_ERR_SB_INVALID_ARG;
            break;
        }

        case SB_RET_ERR_UNSUPPORTED_FUNCTION:
        {
            err = (fsp_err_t) FSP_ERR_SB_UNSUPPORTED_FUNCTION;
            break;
        }

        case SB_RET_ERR_INVALID_ALIGNMENT:
        {
            err = (fsp_err_t) FSP_ERR_SB_INVALID_ALIGNMENT;
            break;
        }

        case SB_RET_ERR_MANI_INVALID_MAGIC:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_INVALID_MAGIC;
            break;
        }

        case SB_RET_ERR_MANI_UNSUPPORTED_VERSION:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_UNSUPPORTED_VERSION;
            break;
        }

        case SB_RET_ERR_MANI_OUT_OF_RANGE_LEN:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_OUT_OF_RANGE_LEN;
            break;
        }

        case SB_RET_ERR_MANI_TLV_FIELD_ERR:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_TLV_FIELD_ERR;
            break;
        }

        case SB_RET_ERR_MANI_TLV_INVALID_LEN:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_TLV_INVALID_LEN;
            break;
        }

        case SB_RET_ERR_MANI_INVALID_IMAGE_LEN:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_INVALID_IMAGE_LEN;
            break;
        }

        case SB_RET_ERR_MANI_MISMATCH_SIGN_ALGORITHM:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_MISMATCH_SIGN_ALGORITHM;
            break;
        }

        case SB_RET_ERR_MANI_UNSUPPORTED_ALGORITHM:
        {
            err = (fsp_err_t) FSP_ERR_SB_MANI_UNSUPPORTED_ALGORITHM;
            break;
        }

        case SB_RET_ERR_CRYPTO_FAIL:
        {
            err = (fsp_err_t) FSP_ERR_SB_CRYPTO_FAIL;
            break;
        }

        case SB_RET_ERR_CRYPTO_AUTH_FAIL:
        {
            err = (fsp_err_t) FSP_ERR_SB_CRYPTO_AUTH_FAIL;
            break;
        }

        case SB_RET_ERR_CRYPTO_UNSUPPORTED_ALGORITHM:
        {
            err = (fsp_err_t) FSP_ERR_SB_CRYPTO_UNSUPPORTED_ALGORITHM;
            break;
        }

        case SB_RET_ERR_CRYPTO_RESOURCE_CONFLICT:
        {
            err = (fsp_err_t) FSP_ERR_SB_CRYPTO_RESOURCE_CONFLICT;
            break;
        }

        case SB_RET_ERR_CRYPTO_PARAM_ERR:
        {
            err = (fsp_err_t) FSP_ERR_SB_CRYPTO_PARAM_ERR;
            break;
        }

        default:
        {
            err = (fsp_err_t) FSP_ERR_SB_INTERNAL_FAIL;
        }
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

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Select primitive function of initial key wrapping from key type.
 *
 * @param[in] key_type_ext Extended key type.
 *
 * @return Pointer to function.
 ***********************************************************************************************************************/
static rsip_func_initial_key_wrap_t select_func_initial_key_wrap (rsip_key_type_extend_t key_type_ext)
{
    rsip_func_initial_key_wrap_t ret = NULL;

    switch (key_type_ext.alg)
    {
        case RSIP_PRV_ALG_AES:
        {
            ret = gsp_func_initial_key_wrap_aes[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_XTS_AES:
        {
            ret = gsp_func_initial_key_wrap_xts_aes[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_CHACHA:
        {
            ret = gsp_func_initial_key_wrap_chacha[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_ECC_PUBLIC:
        {
            ret = gsp_func_initial_key_wrap_ecc_pub[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_ECC_PRIVATE:
        {
            ret = gsp_func_initial_key_wrap_ecc_priv[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_RSA_PUBLIC:
        {
            ret = gsp_func_initial_key_wrap_rsa_pub[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_RSA_PRIVATE:
        {
            ret = gsp_func_initial_key_wrap_rsa_priv[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_HMAC:
        {
            ret = gsp_func_initial_key_wrap_hmac[key_type_ext.subtype];
            break;
        }

        case RSIP_PRV_ALG_MISC:
        {
            ret = gsp_func_initial_key_wrap_misc[key_type_ext.subtype];
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
 * Select primitive function of root certificate key import from key type.
 *
 * @param[in] key_type_ext Extended Key type.
 *
 * @return Pointer to function.
 ***********************************************************************************************************************/
static rsip_func_root_cert_key_import_t select_func_root_cert_key_import (rsip_key_type_extend_t key_type_ext)
{
    rsip_func_kdf_derived_key_import_t ret = NULL;

    switch (key_type_ext.alg)
    {
        case RSIP_PRV_ALG_ECC_PUBLIC:
        {
            if (RSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1 == key_type_ext.subtype)
            {
                ret = r_rsip_wrapper_pe0_secp256r1;
            }

            break;
        }

        case RSIP_PRV_ALG_RSA_PUBLIC:
        {
            if (RSIP_PRV_KEY_SUBTYPE_RSA_2048 == key_type_ext.subtype)
            {
                ret = r_rsip_wrapper_pe0_rsa2048;
            }

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
 * Calculate ceiling function.
 *
 * @param[in] num          Integer
 * @param[in] significance Significance
 *
 * @return Word length
 ***********************************************************************************************************************/
RSIP_PRV_STATIC_INLINE uint32_t r_rsip_ceil (const uint32_t num, const uint32_t significance)
{
    return ((num + significance - 1) / significance) * significance;
}
