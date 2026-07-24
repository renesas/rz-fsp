/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <string.h>
#include "r_rsip_wrapper.h"
#include "r_rsip_primitive.h"
#include "r_rsip_util.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/*
 * Maximum retry count of RSA key generation derived from FIPS186-4 B.3.3. 4.7 and 5.8 (1024, 2048, 3072)
 * Maximum retry count of RSA key generation derived from FIPS186-5 A.1.3. 4.7 and 5.8 (4096)
 */
#define RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_1024    (2 * (5 * 1024 / 2))
#define RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_2048    (2 * (5 * 2048 / 2))
#define RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_3072    (2 * (5 * 3072 / 2))
#define RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_4096    (5 * 4096 + 10 * 4096)

/* For ECC */
#define RSIP_PRV_BYTE_SIZE_ECC_521_PARAM             (66U)
#define RSIP_PRV_WORD_SIZE_ECC_521_SIGNATURE         (40U)
#define RSIP_PRV_WORD_SIZE_ECC_521_PUBLIC_KEY        (40U)
#define RSIP_PRV_BYTE_SIZE_ECC_521_PADDING           (14U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_cmd
{
    CMD_AES_KEY_WRAP_AES128 = 0,
    CMD_AES_KEY_WRAP_AES256 = 1,

    CMD_AES_MODE_ECB_ENCRYPT = 0,
    CMD_AES_MODE_ECB_DECRYPT = 1,
    CMD_AES_MODE_CBC_ENCRYPT = 2,
    CMD_AES_MODE_CBC_DECRYPT = 3,
    CMD_AES_MODE_CTR_CRYPT   = 4,

    CMD_AES_IV_TYPE_PLAIN   = 0,
    CMD_AES_IV_TYPE_WRAPPED = 1,

    CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER = 0,
    CMD_AES_CMAC_GENERATE_WITH_REMAINDER    = 1,
    CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER   = 2,
    CMD_AES_CMAC_VERIFY_WITH_REMAINDER      = 3,

    CMD_ECC_TYPE_NIST      = 0,
    CMD_ECC_TYPE_BRAINPOOL = 1,

    CMD_ECC_KEY_LENGTH_256 = 0,

    CMD_ECDH_PUBKEY_TYPE_PLAIN   = 0,
    CMD_ECDH_PUBKEY_TYPE_WRAPPED = 1,

    CMD_HMAC_HASH_TYPE_SHA1   = 0,
    CMD_HMAC_HASH_TYPE_SHA224 = 1,
    CMD_HMAC_HASH_TYPE_SHA256 = 2,

    CMD_PKI_KEY_TYPE_RSA_2048            = 0,
    CMD_PKI_KEY_TYPE_ECC_SECP256R1       = 3,
    CMD_PKI_KEY_TYPE_ECC_SECP384R1       = 4,
    CMD_PKI_KEY_TYPE_ECC_SECP521R1       = 5,
    CMD_PKI_KEY_TYPE_ECC_BRAINPOOLP256R1 = 6,
    CMD_PKI_KEY_TYPE_ECC_BRAINPOOLP384R1 = 7,
    CMD_PKI_KEY_TYPE_ECC_BRAINPOOLP512R1 = 8,

    CMD_KDF_HASH_TYPE_SHA256 = 0,
    CMD_KDF_HASH_TYPE_SHA384 = 1,
    CMD_KDF_HASH_TYPE_SHA512 = 2,

    CMD_KDF_OUTDATA_TYPE_AES128      = 0,
    CMD_KDF_OUTDATA_TYPE_AES256      = 1,
    CMD_KDF_OUTDATA_TYPE_IV_AES      = 2,
    CMD_KDF_OUTDATA_TYPE_IV_TLS12    = 3,
    CMD_KDF_OUTDATA_TYPE_IV_TLS13    = 4,
    CMD_KDF_OUTDATA_TYPE_HMAC_SHA1   = 5,
    CMD_KDF_OUTDATA_TYPE_HMAC_SHA256 = 6,
    CMD_KDF_OUTDATA_TYPE_HMAC_SHA384 = 7,
    CMD_KDF_OUTDATA_TYPE_HMAC_SHA512 = 8,

    CMD_KDF_TLS12_PRF_VERIFY_DATA_CLIENT = 0,
    CMD_KDF_TLS12_PRF_VERIFY_DATA_SERVER = 1,

    CMD_OTF_CHANNEL_0 = 0,
    CMD_OTF_CHANNEL_1 = 1,
    CMD_OTF_CHANNEL_2 = 2,

    CMD_AUTH_HASH_TYPE_JTAG_DEBUG_LEVEL1 = 0,
    CMD_AUTH_HASH_TYPE_JTAG_DEBUG_LEVEL2 = 1,
    CMD_AUTH_HASH_TYPE_SCI_USB_BOOT      = 2,
} cmd_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint32_t gs_cmd[] =
{
    BSWAP_32BIG_C(0U), BSWAP_32BIG_C(1U), BSWAP_32BIG_C(2U), BSWAP_32BIG_C(3U), BSWAP_32BIG_C(4U), BSWAP_32BIG_C(5U),
    BSWAP_32BIG_C(6U), BSWAP_32BIG_C(7U), BSWAP_32BIG_C(8U)
};

static const uint32_t gs_cmd_no_swap[4] =
{
    0, 1, 2, 3
};

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

rsip_ret_t r_rsip_wrapper_pf4_secp256r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_pf4(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      DomainParam_NIST_P256,
                      OutData_PubKeyIndex,
                      OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf4_brainpoolp256r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_pf4(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      DomainParam_Brainpool_256r1,
                      OutData_PubKeyIndex,
                      OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf9_secp384r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_pf9(&gs_cmd[CMD_ECC_TYPE_NIST], DomainParam_NIST_P384, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf9_brainpoolp384r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_pf9(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      DomainParam_Brainpool_384r1,
                      OutData_PubKeyIndex,
                      OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p13 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p13(DomainParam_NIST_P521, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p7f (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p7f(DomainParam_Brainpool_512r1, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p4a (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p4a(DomainParam_Ed25519, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2a (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p2a(RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_1024, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2b (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p2b(RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_2048, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p3a (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p3a(RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_3072, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p3b (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_rsip_p3b(RSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_4096, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2c_secp256r1 (uint32_t const InData_IV[],
                                         uint32_t const InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p2c(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p1e_secp256r1 (uint32_t const InData_IV[],
                                         uint32_t const InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p1e(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2c_brainpoolp256r1 (uint32_t const InData_IV[],
                                               uint32_t const InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p2c(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p1e_brainpoolp256r1 (uint32_t const InData_IV[],
                                               uint32_t const InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p1e(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2d_secp384r1 (uint32_t const InData_IV[],
                                         uint32_t const InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p2d(&gs_cmd[CMD_ECC_TYPE_NIST], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2e_secp384r1 (uint32_t const InData_IV[],
                                         uint32_t const InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p2e(&gs_cmd[CMD_ECC_TYPE_NIST], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2d_brainpoolp384r1 (uint32_t const InData_IV[],
                                               uint32_t const InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p2d(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p2e_brainpoolp384r1 (uint32_t const InData_IV[],
                                               uint32_t const InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p2e(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p0f_hmac_sha1 (const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p0f(&gs_cmd[CMD_HMAC_HASH_TYPE_SHA1], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p0f_hmac_sha224 (const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p0f(&gs_cmd[CMD_HMAC_HASH_TYPE_SHA224], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p0f_hmac_sha256 (const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p0f(&gs_cmd[CMD_HMAC_HASH_TYPE_SHA256], InData_IV, InData_InstData, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p8f_aes128 (const uint32_t InData_KeyIndex[],
                                      const uint32_t InData_WrappedKeyType[],
                                      const uint32_t InData_WrappedKeyIndex[],
                                      uint32_t       OutData_Text[],
                                      uint32_t       KEY_INDEX_SIZE,
                                      uint32_t       WRAPPED_KEY_SIZE)
{
    return r_rsip_p8f(&gs_cmd[CMD_AES_KEY_WRAP_AES128],
                      InData_KeyIndex,
                      InData_WrappedKeyType,
                      InData_WrappedKeyIndex,
                      OutData_Text,
                      KEY_INDEX_SIZE,
                      WRAPPED_KEY_SIZE);
}

rsip_ret_t r_rsip_wrapper_p8f_aes256 (const uint32_t InData_KeyIndex[],
                                      const uint32_t InData_WrappedKeyType[],
                                      const uint32_t InData_WrappedKeyIndex[],
                                      uint32_t       OutData_Text[],
                                      uint32_t       KEY_INDEX_SIZE,
                                      uint32_t       WRAPPED_KEY_SIZE)
{
    return r_rsip_p8f(&gs_cmd[CMD_AES_KEY_WRAP_AES256],
                      InData_KeyIndex,
                      InData_WrappedKeyType,
                      InData_WrappedKeyIndex,
                      OutData_Text,
                      KEY_INDEX_SIZE,
                      WRAPPED_KEY_SIZE);
}

rsip_ret_t r_rsip_wrapper_p90_aes128 (const uint32_t InData_KeyIndex[],
                                      const uint32_t InData_WrappedKeyType[],
                                      const uint32_t InData_Text[],
                                      uint32_t       OutData_KeyIndex[],
                                      uint32_t       WRAPPED_KEY_SIZE,
                                      uint32_t       KEY_INDEX_SIZE)
{
    return r_rsip_p90(&gs_cmd[CMD_AES_KEY_WRAP_AES128],
                      InData_KeyIndex,
                      InData_WrappedKeyType,
                      InData_Text,
                      OutData_KeyIndex,
                      WRAPPED_KEY_SIZE,
                      KEY_INDEX_SIZE);
}

rsip_ret_t r_rsip_wrapper_p90_aes256 (const uint32_t InData_KeyIndex[],
                                      const uint32_t InData_WrappedKeyType[],
                                      const uint32_t InData_Text[],
                                      uint32_t       OutData_KeyIndex[],
                                      uint32_t       WRAPPED_KEY_SIZE,
                                      uint32_t       KEY_INDEX_SIZE)
{
    return r_rsip_p90(&gs_cmd[CMD_AES_KEY_WRAP_AES256],
                      InData_KeyIndex,
                      InData_WrappedKeyType,
                      InData_Text,
                      OutData_KeyIndex,
                      WRAPPED_KEY_SIZE,
                      KEY_INDEX_SIZE);
}

rsip_ret_t r_rsip_wrapper_p48i_ecb_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_ECB_ENCRYPT], InData_KeyIndex, NULL, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p48i_ecb_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_ECB_DECRYPT], InData_KeyIndex, NULL, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p48i_cbc_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p48i_cbc_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p48i_cbc_enc_wrapped_iv (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p48i_cbc_dec_wrapped_iv (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p48i_ctr (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p48i(&gs_cmd[CMD_AES_MODE_CTR_CRYPT], InData_KeyIndex, NULL, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p89i_ecb_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p89i(&gs_cmd[CMD_AES_MODE_ECB_ENCRYPT], InData_KeyIndex, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p89i_ecb_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p89i(&gs_cmd[CMD_AES_MODE_ECB_DECRYPT], InData_KeyIndex, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p89i_cbc_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p89i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p89i_cbc_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p89i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p89i_ctr (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p89i(&gs_cmd[CMD_AES_MODE_CTR_CRYPT], InData_KeyIndex, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_ecb_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_ECB_ENCRYPT], InData_KeyIndex, NULL, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_ecb_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_ECB_DECRYPT], InData_KeyIndex, NULL, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_cbc_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_cbc_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_cbc_enc_wrapped_iv (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_cbc_dec_wrapped_iv (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p50i_ctr (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_rsip_p50i(&gs_cmd[CMD_AES_MODE_CTR_CRYPT], InData_KeyIndex, NULL, InData_IV);
}

rsip_ret_t r_rsip_wrapper_p29i_plain_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p29i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p29i_wrapped_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p29i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p32i_plain_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p32i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p32i_wrapped_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p32i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p34i_plain_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p34i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p34i_wrapped_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p34i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p36i_plain_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p36i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_PLAIN], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p36i_wrapped_iv (const uint32_t * InData_KeyIndex, const uint32_t * InData_IV)
{
    return r_rsip_p36i(InData_KeyIndex, &gs_cmd[CMD_AES_IV_TYPE_WRAPPED], InData_IV);
}

rsip_ret_t r_rsip_wrapper_p95i (const uint32_t * InData_KeyIndex,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_IV,
                                const uint32_t * InData_Header,
                                uint32_t         Header_Len)
{
    (void) InData_TextLen;

    return r_rsip_p95i(InData_KeyIndex, InData_IV, InData_Header, Header_Len);
}

rsip_ret_t r_rsip_wrapper_p98i (const uint32_t * InData_KeyIndex,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_MACLength,
                                const uint32_t * InData_IV,
                                const uint32_t * InData_Header,
                                uint32_t         Header_Len)
{
    (void) InData_TextLen;
    (void) InData_MACLength;

    return r_rsip_p98i(InData_KeyIndex, InData_IV, InData_Header, Header_Len);
}

rsip_ret_t r_rsip_wrapper_p95f (const uint32_t * InData_Text,
                                const uint32_t * InData_TextLen,
                                uint32_t       * OutData_Text,
                                uint32_t       * OutData_MAC)
{
    return r_rsip_p95f(InData_Text, InData_TextLen, OutData_Text, OutData_MAC);
}

rsip_ret_t r_rsip_wrapper_p98f (const uint32_t * InData_Text,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_MAC,
                                const uint32_t * InData_MACLength,
                                uint32_t       * OutData_Text)
{
    return r_rsip_p98f(InData_Text, InData_TextLen, InData_MAC, InData_MACLength, OutData_Text);
}

rsip_ret_t r_rsip_wrapper_pa7i (const uint32_t * InData_KeyIndex,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_IV,
                                const uint32_t * InData_Header,
                                uint32_t         Header_Len)
{
    (void) InData_TextLen;

    return r_rsip_pa7i(InData_KeyIndex, InData_IV, InData_Header, Header_Len);
}

rsip_ret_t r_rsip_wrapper_pb0i (const uint32_t * InData_KeyIndex,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_MACLength,
                                const uint32_t * InData_IV,
                                const uint32_t * InData_Header,
                                uint32_t         Header_Len)
{
    (void) InData_TextLen;
    (void) InData_MACLength;

    return r_rsip_pb0i(InData_KeyIndex, InData_IV, InData_Header, Header_Len);
}

rsip_ret_t r_rsip_wrapper_pa1i (const uint32_t * InData_KeyIndex,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_IV,
                                const uint32_t * InData_Header,
                                uint32_t         Header_Len)
{
    (void) InData_TextLen;

    return r_rsip_pa1i(InData_KeyIndex, InData_IV, InData_Header, Header_Len);
}

rsip_ret_t r_rsip_wrapper_pa4i (const uint32_t * InData_KeyIndex,
                                const uint32_t * InData_TextLen,
                                const uint32_t * InData_MACLength,
                                const uint32_t * InData_IV,
                                const uint32_t * InData_Header,
                                uint32_t         Header_Len)
{
    (void) InData_TextLen;
    (void) InData_MACLength;

    return r_rsip_pa4i(InData_KeyIndex, InData_IV, InData_Header, Header_Len);
}

rsip_ret_t r_rsip_wrapper_p41f_gen (const uint32_t InData_Text[], uint32_t OutData_DataT[], const uint32_t all_msg_len)
{
    cmd_t cmd = ((0 == (all_msg_len % 16)) && (0 != all_msg_len)) ?
                CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER : CMD_AES_CMAC_GENERATE_WITH_REMAINDER;

    return r_rsip_p41f(&gs_cmd_no_swap[cmd], InData_Text, NULL, NULL, OutData_DataT);
}

rsip_ret_t r_rsip_wrapper_p87f_gen (const uint32_t InData_Text[], uint32_t OutData_DataT[], const uint32_t all_msg_len)
{
    cmd_t cmd = ((0 == (all_msg_len % 16)) && (0 != all_msg_len)) ?
                CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER : CMD_AES_CMAC_GENERATE_WITH_REMAINDER;

    return r_rsip_p87f(&gs_cmd_no_swap[cmd], InData_Text, NULL, NULL, OutData_DataT);
}

rsip_ret_t r_rsip_wrapper_p44f_gen (const uint32_t InData_Text[], uint32_t OutData_DataT[], const uint32_t all_msg_len)
{
    cmd_t cmd = ((0 == (all_msg_len % 16)) && (0 != all_msg_len)) ?
                CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER : CMD_AES_CMAC_GENERATE_WITH_REMAINDER;

    return r_rsip_p44f(&gs_cmd_no_swap[cmd], InData_Text, NULL, NULL, OutData_DataT);
}

rsip_ret_t r_rsip_wrapper_p41f_veri (const uint32_t InData_Text[],
                                     const uint32_t InData_DataT[],
                                     const uint32_t InData_DataTLen[],
                                     const uint32_t all_msg_len)
{
    cmd_t cmd = ((0 == (all_msg_len % 16)) && (0 != all_msg_len)) ?
                CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER : CMD_AES_CMAC_VERIFY_WITH_REMAINDER;

    return r_rsip_p41f(&gs_cmd_no_swap[cmd], InData_Text, InData_DataT, InData_DataTLen, NULL);
}

rsip_ret_t r_rsip_wrapper_p87f_veri (const uint32_t InData_Text[],
                                     const uint32_t InData_DataT[],
                                     const uint32_t InData_DataTLen[],
                                     const uint32_t all_msg_len)
{
    cmd_t cmd = ((0 == (all_msg_len % 16)) && (0 != all_msg_len)) ?
                CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER : CMD_AES_CMAC_VERIFY_WITH_REMAINDER;

    return r_rsip_p87f(&gs_cmd_no_swap[cmd], InData_Text, InData_DataT, InData_DataTLen, NULL);
}

rsip_ret_t r_rsip_wrapper_p44f_veri (const uint32_t InData_Text[],
                                     const uint32_t InData_DataT[],
                                     const uint32_t InData_DataTLen[],
                                     const uint32_t all_msg_len)
{
    cmd_t cmd = ((0 == (all_msg_len % 16)) && (0 != all_msg_len)) ?
                CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER : CMD_AES_CMAC_VERIFY_WITH_REMAINDER;

    return r_rsip_p44f(&gs_cmd_no_swap[cmd], InData_Text, InData_DataT, InData_DataTLen, NULL);
}

rsip_ret_t r_rsip_wrapper_pf0_secp256r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         uint32_t       OutData_Signature[])
{
    return r_rsip_pf0(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      DomainParam_NIST_P256,
                      OutData_Signature);
}

rsip_ret_t r_rsip_wrapper_pf1_secp256r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[])
{
    return r_rsip_pf1(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      InData_Signature,
                      DomainParam_NIST_P256);
}

rsip_ret_t r_rsip_wrapper_pf0_brainpoolp256r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               uint32_t       OutData_Signature[])
{
    return r_rsip_pf0(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      DomainParam_Brainpool_256r1,
                      OutData_Signature);
}

rsip_ret_t r_rsip_wrapper_pf1_brainpoolp256r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[])
{
    return r_rsip_pf1(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      InData_Signature,
                      DomainParam_Brainpool_256r1);
}

rsip_ret_t r_rsip_wrapper_pf5_secp384r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         uint32_t       OutData_Signature[])
{
    return r_rsip_pf5(&gs_cmd[CMD_ECC_TYPE_NIST],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      DomainParam_NIST_P384,
                      OutData_Signature);
}

rsip_ret_t r_rsip_wrapper_pf6_secp384r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[])
{
    return r_rsip_pf6(&gs_cmd[CMD_ECC_TYPE_NIST],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      InData_Signature,
                      DomainParam_NIST_P384);
}

rsip_ret_t r_rsip_wrapper_pf5_brainpoolp384r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               uint32_t       OutData_Signature[])
{
    return r_rsip_pf5(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      DomainParam_Brainpool_384r1,
                      OutData_Signature);
}

rsip_ret_t r_rsip_wrapper_pf6_brainpoolp384r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[])
{
    return r_rsip_pf6(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      InData_Signature,
                      DomainParam_Brainpool_384r1);
}

rsip_ret_t r_rsip_wrapper_p11 (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_MsgDgst[],
                               uint32_t       OutData_Signature[])
{
    rsip_ret_t     rsip_ret;
    uint32_t       Signature[RSIP_PRV_WORD_SIZE_ECC_521_SIGNATURE] = {0};
    const uint32_t signature_r_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;
    const uint32_t signature_s_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING +
                                          RSIP_PRV_BYTE_SIZE_ECC_521_PARAM +
                                          RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;

    rsip_ret = r_rsip_p11(InData_KeyIndex, InData_MsgDgst, DomainParam_NIST_P521, Signature);
    if (RSIP_RET_PASS == rsip_ret)
    {
        memcpy((uint8_t *) OutData_Signature,
               (uint8_t *) Signature + signature_r_pad_byte,
               RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);
        memcpy((uint8_t *) OutData_Signature + RSIP_PRV_BYTE_SIZE_ECC_521_PARAM,
               (uint8_t *) Signature + signature_s_pad_byte,
               RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);
    }

    return rsip_ret;
}

rsip_ret_t r_rsip_wrapper_p12 (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_MsgDgst[],
                               const uint32_t InData_Signature[])
{
    uint32_t       Signature[RSIP_PRV_WORD_SIZE_ECC_521_SIGNATURE] = {0};
    const uint32_t signature_r_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;
    const uint32_t signature_s_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING +
                                          RSIP_PRV_BYTE_SIZE_ECC_521_PARAM +
                                          RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;

    memcpy((uint8_t *) Signature + signature_r_pad_byte, (uint8_t *) InData_Signature,
           RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);
    memcpy((uint8_t *) Signature + signature_s_pad_byte,
           (uint8_t *) InData_Signature + RSIP_PRV_BYTE_SIZE_ECC_521_PARAM,
           RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);

    return r_rsip_p12(InData_KeyIndex, InData_MsgDgst, Signature, DomainParam_NIST_P521);
}

rsip_ret_t r_rsip_wrapper_p7d (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_MsgDgst[],
                               uint32_t       OutData_Signature[])
{
    return r_rsip_p7d(InData_KeyIndex, InData_MsgDgst, DomainParam_Brainpool_512r1, OutData_Signature);
}

rsip_ret_t r_rsip_wrapper_p7e (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_MsgDgst[],
                               const uint32_t InData_Signature[])
{
    return r_rsip_p7e(InData_KeyIndex, InData_MsgDgst, InData_Signature, DomainParam_Brainpool_512r1);
}

rsip_ret_t r_rsip_wrapper_p4c (const uint32_t InData_PrivKeyIndex[],
                               const uint32_t InData_PubKeyIndex[],
                               const uint32_t InData_Msg[],
                               const uint64_t InData_MsgLen,
                               uint32_t       OutData_Signature[])
{
    uint32_t msg_len[2] =
    {
        r_rsip_byte_to_bit_convert_upper(InData_MsgLen),
        r_rsip_byte_to_bit_convert_lower(InData_MsgLen)
    };

    msg_len[0] = bswap_32big(msg_len[0]);
    msg_len[1] = bswap_32big(msg_len[1]);

    uint64_t max_cnt = ((InData_MsgLen + 3) >> 2);

    return r_rsip_p4c(InData_PrivKeyIndex,
                      InData_PubKeyIndex,
                      InData_Msg,
                      msg_len,
                      DomainParam_Ed25519,
                      OutData_Signature,
                      max_cnt);
}

rsip_ret_t r_rsip_wrapper_p4d (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_Msg[],
                               const uint64_t InData_MsgLen,
                               const uint32_t InData_Signature[])
{
    uint32_t msg_len[2] =
    {
        r_rsip_byte_to_bit_convert_upper(InData_MsgLen),
        r_rsip_byte_to_bit_convert_lower(InData_MsgLen)
    };

    msg_len[0] = bswap_32big(msg_len[0]);
    msg_len[1] = bswap_32big(msg_len[1]);

    uint64_t max_cnt = ((InData_MsgLen + 3) >> 2);

    return r_rsip_p4d(InData_KeyIndex, InData_Msg, msg_len, InData_Signature, DomainParam_Ed25519, max_cnt);
}

rsip_ret_t r_rsip_wrapper_pfa_secp256r1 (const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pfa(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf3_secp256r1 (const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pf3(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pfa_brainpoolp256r1 (const uint32_t InData_SharedKeyNum[],
                                               const uint32_t InData_SharedKeyIndex[],
                                               const uint32_t InData_SessionKey[],
                                               const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pfa(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf3_brainpoolp256r1 (const uint32_t InData_SharedKeyNum[],
                                               const uint32_t InData_SharedKeyIndex[],
                                               const uint32_t InData_SessionKey[],
                                               const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pf3(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf7_secp384r1 (const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pf7(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_NIST],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf8_secp384r1 (const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pf8(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_NIST],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf7_brainpoolp384r1 (const uint32_t InData_SharedKeyNum[],
                                               const uint32_t InData_SharedKeyIndex[],
                                               const uint32_t InData_SessionKey[],
                                               const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pf7(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pf8_brainpoolp384r1 (const uint32_t InData_SharedKeyNum[],
                                               const uint32_t InData_SharedKeyIndex[],
                                               const uint32_t InData_SessionKey[],
                                               const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pf8(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p80_hmac_sha1 (const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p80(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_HMAC_HASH_TYPE_SHA1],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p80_hmac_sha224 (const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p80(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_HMAC_HASH_TYPE_SHA224],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_p80_hmac_sha256 (const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[])
{
    return r_rsip_p80(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      &gs_cmd[CMD_HMAC_HASH_TYPE_SHA256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe2_wrapped_secp256r1 (const uint32_t InData_PubKey[],
                                                 const uint32_t InData_KeyIndex[],
                                                 uint32_t       OutData_EncSecret[])
{
    return r_rsip_pe2(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_WRAPPED],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_NIST_P256,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_pe2_plain_secp256r1 (const uint32_t InData_PubKey[],
                                               const uint32_t InData_KeyIndex[],
                                               uint32_t       OutData_EncSecret[])
{
    return r_rsip_pe2(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_PLAIN],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_NIST_P256,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_pe2_wrapped_brainpoolp256r1 (const uint32_t InData_PubKey[],
                                                       const uint32_t InData_KeyIndex[],
                                                       uint32_t       OutData_EncSecret[])
{
    return r_rsip_pe2(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_WRAPPED],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_Brainpool_256r1,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_pe2_plain_brainpoolp256r1 (const uint32_t InData_PubKey[],
                                                     const uint32_t InData_KeyIndex[],
                                                     uint32_t       OutData_EncSecret[])
{
    return r_rsip_pe2(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_PLAIN],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_Brainpool_256r1,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p4e_wrapped_secp384r1 (const uint32_t InData_PubKey[],
                                                 const uint32_t InData_KeyIndex[],
                                                 uint32_t       OutData_EncSecret[])
{
    return r_rsip_p4e(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_WRAPPED],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_NIST_P384,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p4e_plain_secp384r1 (const uint32_t InData_PubKey[],
                                               const uint32_t InData_KeyIndex[],
                                               uint32_t       OutData_EncSecret[])
{
    return r_rsip_p4e(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_PLAIN],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_NIST_P384,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p4e_wrapped_brainpoolp384r1 (const uint32_t InData_PubKey[],
                                                       const uint32_t InData_KeyIndex[],
                                                       uint32_t       OutData_EncSecret[])
{
    return r_rsip_p4e(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_WRAPPED],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_Brainpool_384r1,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p4e_plain_brainpoolp384r1 (const uint32_t InData_PubKey[],
                                                     const uint32_t InData_KeyIndex[],
                                                     uint32_t       OutData_EncSecret[])
{
    return r_rsip_p4e(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECDH_PUBKEY_TYPE_PLAIN],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_Brainpool_384r1,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p4f_wrapped_secp521r1 (const uint32_t InData_PubKey[],
                                                 const uint32_t InData_KeyIndex[],
                                                 uint32_t       OutData_EncSecret[])
{
    return r_rsip_p4f(&gs_cmd[CMD_ECDH_PUBKEY_TYPE_WRAPPED],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_NIST_P521,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p4f_plain_secp521r1 (const uint32_t InData_PubKey[],
                                               const uint32_t InData_KeyIndex[],
                                               uint32_t       OutData_EncSecret[])
{
    uint32_t       PubKey[RSIP_PRV_WORD_SIZE_ECC_521_PUBLIC_KEY] = {0};
    const uint32_t public_key_qx_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;
    const uint32_t public_key_qy_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING +
                                            RSIP_PRV_BYTE_SIZE_ECC_521_PARAM +
                                            RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;

    memcpy((uint8_t *) PubKey + public_key_qx_pad_byte, (uint8_t *) InData_PubKey, RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);
    memcpy((uint8_t *) PubKey + public_key_qy_pad_byte,
           (uint8_t *) InData_PubKey + RSIP_PRV_BYTE_SIZE_ECC_521_PARAM,
           RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);

    return r_rsip_p4f(&gs_cmd[CMD_ECDH_PUBKEY_TYPE_PLAIN],
                      PubKey,
                      InData_KeyIndex,
                      DomainParam_NIST_P521,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p5e_wrapped_brainpoolp512r1 (const uint32_t InData_PubKey[],
                                                       const uint32_t InData_KeyIndex[],
                                                       uint32_t       OutData_EncSecret[])
{
    return r_rsip_p5e(&gs_cmd[CMD_ECDH_PUBKEY_TYPE_WRAPPED],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_Brainpool_512r1,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_p5e_plain_brainpoolp512r1 (const uint32_t InData_PubKey[],
                                                     const uint32_t InData_KeyIndex[],
                                                     uint32_t       OutData_EncSecret[])
{
    return r_rsip_p5e(&gs_cmd[CMD_ECDH_PUBKEY_TYPE_PLAIN],
                      InData_PubKey,
                      InData_KeyIndex,
                      DomainParam_Brainpool_512r1,
                      OutData_EncSecret);
}

rsip_ret_t r_rsip_wrapper_pe0_secp256r1 (const uint32_t InData_RootCertificate[],
                                         const uint32_t InData_RootCertificateInfo[],
                                         const uint32_t InData_RootCertificatePubKey[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe0(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_SECP256R1],
                      InData_RootCertificate,
                      InData_RootCertificateInfo,
                      InData_RootCertificatePubKey,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe0_rsa2048 (const uint32_t InData_RootCertificate[],
                                       const uint32_t InData_RootCertificateInfo[],
                                       const uint32_t InData_RootCertificatePubKey[],
                                       uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe0(&gs_cmd[CMD_PKI_KEY_TYPE_RSA_2048],
                      InData_RootCertificate,
                      InData_RootCertificateInfo,
                      InData_RootCertificatePubKey,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_secp256r1 (const uint32_t InData_HashType[],
                                         const uint32_t InData_Certificate[],
                                         const uint32_t InData_CertificateLength[],
                                         const uint32_t InData_CertificatePubKey[],
                                         const uint32_t InData_EncCertificateInfo[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_SECP256R1],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_secp384r1 (const uint32_t InData_HashType[],
                                         const uint32_t InData_Certificate[],
                                         const uint32_t InData_CertificateLength[],
                                         const uint32_t InData_CertificatePubKey[],
                                         const uint32_t InData_EncCertificateInfo[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_SECP384R1],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_secp521r1 (const uint32_t InData_HashType[],
                                         const uint32_t InData_Certificate[],
                                         const uint32_t InData_CertificateLength[],
                                         const uint32_t InData_CertificatePubKey[],
                                         const uint32_t InData_EncCertificateInfo[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_SECP521R1],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_brainpoolp256r1 (const uint32_t InData_HashType[],
                                               const uint32_t InData_Certificate[],
                                               const uint32_t InData_CertificateLength[],
                                               const uint32_t InData_CertificatePubKey[],
                                               const uint32_t InData_EncCertificateInfo[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_BRAINPOOLP256R1],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_brainpoolp384r1 (const uint32_t InData_HashType[],
                                               const uint32_t InData_Certificate[],
                                               const uint32_t InData_CertificateLength[],
                                               const uint32_t InData_CertificatePubKey[],
                                               const uint32_t InData_EncCertificateInfo[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_BRAINPOOLP384R1],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_brainpoolp512r1 (const uint32_t InData_HashType[],
                                               const uint32_t InData_Certificate[],
                                               const uint32_t InData_CertificateLength[],
                                               const uint32_t InData_CertificatePubKey[],
                                               const uint32_t InData_EncCertificateInfo[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_ECC_BRAINPOOLP512R1],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe1_rsa2048 (const uint32_t InData_HashType[],
                                       const uint32_t InData_Certificate[],
                                       const uint32_t InData_CertificateLength[],
                                       const uint32_t InData_CertificatePubKey[],
                                       const uint32_t InData_EncCertificateInfo[],
                                       uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe1(&gs_cmd[CMD_PKI_KEY_TYPE_RSA_2048],
                      InData_HashType,
                      InData_Certificate,
                      InData_CertificateLength,
                      InData_CertificatePubKey,
                      InData_EncCertificateInfo,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_peei_secp256r1 (const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_MsgDgst[],
                                          const uint32_t InData_Signature[])
{
    return r_rsip_peei(&gs_cmd[CMD_ECC_TYPE_NIST],
                       InData_KeyIndex,
                       InData_MsgDgst,
                       InData_Signature,
                       DomainParam_NIST_P256);
}

rsip_ret_t r_rsip_wrapper_peei_brainpoolp256r1 (const uint32_t InData_KeyIndex[],
                                                const uint32_t InData_MsgDgst[],
                                                const uint32_t InData_Signature[])
{
    return r_rsip_peei(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                       InData_KeyIndex,
                       InData_MsgDgst,
                       InData_Signature,
                       DomainParam_Brainpool_256r1);
}

rsip_ret_t r_rsip_wrapper_p51i_secp384r1 (const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_MsgDgst[],
                                          const uint32_t InData_Signature[])
{
    return r_rsip_p51i(&gs_cmd[CMD_ECC_TYPE_NIST],
                       InData_KeyIndex,
                       InData_MsgDgst,
                       InData_Signature,
                       DomainParam_NIST_P384);
}

rsip_ret_t r_rsip_wrapper_p51i_brainpoolp384r1 (const uint32_t InData_KeyIndex[],
                                                const uint32_t InData_MsgDgst[],
                                                const uint32_t InData_Signature[])
{
    return r_rsip_p51i(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                       InData_KeyIndex,
                       InData_MsgDgst,
                       InData_Signature,
                       DomainParam_Brainpool_384r1);
}

rsip_ret_t r_rsip_wrapper_p5fi_brainpoolp512r1 (const uint32_t InData_KeyIndex[],
                                                const uint32_t InData_MsgDgst[],
                                                const uint32_t InData_Signature[])
{
    return r_rsip_p5fi(InData_KeyIndex, InData_MsgDgst, InData_Signature, DomainParam_Brainpool_512r1);
}

rsip_ret_t r_rsip_wrapper_p52i_secp521r1 (const uint32_t InData_KeyIndex[],
                                          const uint32_t InData_MsgDgst[],
                                          const uint32_t InData_Signature[])
{
    uint32_t       Signature[RSIP_PRV_WORD_SIZE_ECC_521_SIGNATURE] = {0};
    const uint32_t signature_r_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;
    const uint32_t signature_s_pad_byte = RSIP_PRV_BYTE_SIZE_ECC_521_PADDING +
                                          RSIP_PRV_BYTE_SIZE_ECC_521_PARAM +
                                          RSIP_PRV_BYTE_SIZE_ECC_521_PADDING;

    memcpy((uint8_t *) Signature + signature_r_pad_byte, (uint8_t *) InData_Signature,
           RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);
    memcpy((uint8_t *) Signature + signature_s_pad_byte,
           (uint8_t *) InData_Signature + RSIP_PRV_BYTE_SIZE_ECC_521_PARAM,
           RSIP_PRV_BYTE_SIZE_ECC_521_PARAM);

    return r_rsip_p52i(InData_KeyIndex, InData_MsgDgst, Signature, DomainParam_NIST_P521);
}

rsip_ret_t r_rsip_wrapper_pe3_sha256 (const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[])
{
    return r_rsip_pe3(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256], NULL, InData_EncSecret, OutData_EncMsg);
}

rsip_ret_t r_rsip_wrapper_pe3_sha384 (const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[])
{
    return r_rsip_pe3(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384], NULL, InData_EncSecret, OutData_EncMsg);
}

rsip_ret_t r_rsip_wrapper_pe3_sha512_secp521r1 (const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[])
{
    return r_rsip_pe3(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512], &gs_cmd[CMD_ECC_TYPE_NIST], InData_EncSecret, OutData_EncMsg);
}

rsip_ret_t r_rsip_wrapper_pe3_sha512_brainpoolp512r1 (const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[])
{
    return r_rsip_pe3(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      &gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      InData_EncSecret,
                      OutData_EncMsg);
}

rsip_ret_t r_rsip_wrapper_pe4_sha256 (const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[])
{
    return r_rsip_pe4(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256], NULL, InData_EncSecret, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe4_sha384 (const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[])
{
    return r_rsip_pe4(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384], NULL, InData_EncSecret, OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe4_sha512_secp521r1 (const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[])
{
    return r_rsip_pe4(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512], &gs_cmd[CMD_ECC_TYPE_NIST], InData_EncSecret,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe4_sha512_brainpoolp512r1 (const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[])
{
    return r_rsip_pe4(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      &gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      InData_EncSecret,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe6_sha256 (const uint32_t InData_KDFInfo[],
                                      const uint32_t InData_KDFInfo_Count[],
                                      const uint32_t InData_OutDataLength[],
                                      uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe6(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      InData_OutDataLength,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe6_sha384 (const uint32_t InData_KDFInfo[],
                                      const uint32_t InData_KDFInfo_Count[],
                                      const uint32_t InData_OutDataLength[],
                                      uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe6(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      InData_OutDataLength,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe6_sha512 (const uint32_t InData_KDFInfo[],
                                      const uint32_t InData_KDFInfo_Count[],
                                      const uint32_t InData_OutDataLength[],
                                      uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe6(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      InData_OutDataLength,
                      OutData_KeyIndex);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_aes128 (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256], InData_KDFInfo, InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_AES128], InData_OutDataLocation, NULL, NULL, OutData_KeyIndex, NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_aes256 (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256], InData_KDFInfo, InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_AES256], InData_OutDataLocation, NULL, NULL, OutData_KeyIndex, NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha1 (const uint32_t InData_KDFInfo[],
                                                const uint32_t InData_KDFInfo_Count[],
                                                const uint32_t InData_OutDataLocation[],
                                                uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA1],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha256 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA256],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha384 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA384],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha512 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA512],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_iv_aes (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             const uint32_t InData_SeqNum[],
                                             uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_AES],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_iv_tls12 (const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               const uint32_t InData_SeqNum[],
                                               uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_TLS12],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha256_iv_tls13 (const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               const uint32_t InData_SeqNum[],
                                               uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_TLS13],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_aes128 (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384], InData_KDFInfo, InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_AES128], InData_OutDataLocation, NULL, NULL, OutData_KeyIndex, NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_aes256 (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384], InData_KDFInfo, InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_AES256], InData_OutDataLocation, NULL, NULL, OutData_KeyIndex, NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha1 (const uint32_t InData_KDFInfo[],
                                                const uint32_t InData_KDFInfo_Count[],
                                                const uint32_t InData_OutDataLocation[],
                                                uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA1],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha256 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA256],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha384 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA384],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha512 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA512],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_iv_aes (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             const uint32_t InData_SeqNum[],
                                             uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_AES],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_iv_tls12 (const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               const uint32_t InData_SeqNum[],
                                               uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_TLS12],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha384_iv_tls13 (const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               const uint32_t InData_SeqNum[],
                                               uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA384],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_TLS13],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_aes128 (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512], InData_KDFInfo, InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_AES128], InData_OutDataLocation, NULL, NULL, OutData_KeyIndex, NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_aes256 (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             uint32_t       OutData_KeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512], InData_KDFInfo, InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_AES256], InData_OutDataLocation, NULL, NULL, OutData_KeyIndex, NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha1 (const uint32_t InData_KDFInfo[],
                                                const uint32_t InData_KDFInfo_Count[],
                                                const uint32_t InData_OutDataLocation[],
                                                uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA1],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha256 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA256],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha384 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA384],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha512 (const uint32_t InData_KDFInfo[],
                                                  const uint32_t InData_KDFInfo_Count[],
                                                  const uint32_t InData_OutDataLocation[],
                                                  uint32_t       OutData_HMACKeyIndex[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_HMAC_SHA512],
                      InData_OutDataLocation,
                      NULL,
                      OutData_HMACKeyIndex,
                      NULL,
                      NULL);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_iv_aes (const uint32_t InData_KDFInfo[],
                                             const uint32_t InData_KDFInfo_Count[],
                                             const uint32_t InData_OutDataLocation[],
                                             const uint32_t InData_SeqNum[],
                                             uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_AES],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_iv_tls12 (const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               const uint32_t InData_SeqNum[],
                                               uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_TLS12],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe7_sha512_iv_tls13 (const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               const uint32_t InData_SeqNum[],
                                               uint32_t       OutData_EncIV[])
{
    return r_rsip_pe7(&gs_cmd[CMD_KDF_HASH_TYPE_SHA512],
                      InData_KDFInfo,
                      InData_KDFInfo_Count,
                      &gs_cmd[CMD_KDF_OUTDATA_TYPE_IV_TLS13],
                      InData_OutDataLocation,
                      InData_SeqNum,
                      NULL,
                      NULL,
                      OutData_EncIV);
}

rsip_ret_t r_rsip_wrapper_pe9_sha256_client (const uint32_t InData_Hash[],
                                             const uint32_t InData_KeyIndex[],
                                             uint32_t       OutData_Verify_data[])
{
    return r_rsip_pe9(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256], InData_Hash, InData_KeyIndex,
                      &gs_cmd[CMD_KDF_TLS12_PRF_VERIFY_DATA_CLIENT], OutData_Verify_data);
};

rsip_ret_t r_rsip_wrapper_pe9_sha256_server (const uint32_t InData_Hash[],
                                             const uint32_t InData_KeyIndex[],
                                             uint32_t       OutData_Verify_data[])
{
    return r_rsip_pe9(&gs_cmd[CMD_KDF_HASH_TYPE_SHA256], InData_Hash, InData_KeyIndex,
                      &gs_cmd[CMD_KDF_TLS12_PRF_VERIFY_DATA_SERVER], OutData_Verify_data);
};

rsip_ret_t r_rsip_wrapper_p15_jtag_level1 (const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_EncAuthData[],
                                           uint32_t       OutData_Hash[])
{
    return r_rsip_p15(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      InData_IV,
                      InData_EncAuthData,
                      &gs_cmd[CMD_AUTH_HASH_TYPE_JTAG_DEBUG_LEVEL1],
                      OutData_Hash);
}

rsip_ret_t r_rsip_wrapper_p15_jtag_level2 (const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_EncAuthData[],
                                           uint32_t       OutData_Hash[])
{
    return r_rsip_p15(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      InData_IV,
                      InData_EncAuthData,
                      &gs_cmd[CMD_AUTH_HASH_TYPE_JTAG_DEBUG_LEVEL2],
                      OutData_Hash);
}

rsip_ret_t r_rsip_wrapper_p15_sci_usb (const uint32_t InData_SharedKeyNum[],
                                       const uint32_t InData_SharedKeyIndex[],
                                       const uint32_t InData_SessionKey[],
                                       const uint32_t InData_IV[],
                                       const uint32_t InData_EncAuthData[],
                                       uint32_t       OutData_Hash[])
{
    return r_rsip_p15(InData_SharedKeyNum,
                      InData_SharedKeyIndex,
                      InData_SessionKey,
                      InData_IV,
                      InData_EncAuthData,
                      &gs_cmd[CMD_AUTH_HASH_TYPE_SCI_USB_BOOT],
                      OutData_Hash);
}

rsip_ret_t r_rsip_wrapper_pba_ch0 (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    return r_rsip_pba(&gs_cmd[CMD_OTF_CHANNEL_0], InData_KeyIndex, InData_DOTFSEED);
};

rsip_ret_t r_rsip_wrapper_pba_ch1 (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    return r_rsip_pba(&gs_cmd[CMD_OTF_CHANNEL_1], InData_KeyIndex, InData_DOTFSEED);
};

rsip_ret_t r_rsip_wrapper_pba_ch2 (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    return r_rsip_pba(&gs_cmd[CMD_OTF_CHANNEL_2], InData_KeyIndex, InData_DOTFSEED);
};

rsip_ret_t r_rsip_wrapper_pbc_ch0 (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    return r_rsip_pbc(&gs_cmd[CMD_OTF_CHANNEL_0], InData_KeyIndex, InData_DOTFSEED);
};

rsip_ret_t r_rsip_wrapper_pbc_ch1 (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    return r_rsip_pbc(&gs_cmd[CMD_OTF_CHANNEL_1], InData_KeyIndex, InData_DOTFSEED);
};

rsip_ret_t r_rsip_wrapper_pbc_ch2 (const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
{
    return r_rsip_pbc(&gs_cmd[CMD_OTF_CHANNEL_2], InData_KeyIndex, InData_DOTFSEED);
};

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
