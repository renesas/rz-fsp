/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_private.h"
#include "r_tsip_primitive.h"
#include "r_tsip_wrapper.h"
#include "r_tsip_reg.h"
#include "r_tsip_addr.h"
#include "r_tsip_util.h"
#include "r_tsip_public.h"
#include "r_tsip_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* For AES-CMAC. These commands do not require byte swapping */
#define TSIP_PRV_CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER    (0U)
#define TSIP_PRV_CMD_AES_CMAC_GENERATE_WITH_REMAINDER       (1U)
#define TSIP_PRV_CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER      (2U)
#define TSIP_PRV_CMD_AES_CMAC_VERIFY_WITH_REMAINDER         (3U)

/* For RSA */

/*
 * Maximum retry count of RSA key generation derived from FIPS186-4 B.3.3. 4.7 and 5.8 (1024, 2048, 3072)
 * Maximum retry count of RSA key generation derived from FIPS186-5 A.1.3. 4.7 and 5.8 (4096)
 */
#define TSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_1024           (2 * (5 * 1024 / 2))
#define TSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_2048           (2 * (5 * 2048 / 2))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_cmd
{
    CMD_AES_MODE_ECB_ENCRYPT = 0,
    CMD_AES_MODE_ECB_DECRYPT = 1,
    CMD_AES_MODE_CBC_ENCRYPT = 2,
    CMD_AES_MODE_CBC_DECRYPT = 3,
    CMD_AES_MODE_CTR_CRYPT   = 4,

    CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER = 0,
    CMD_AES_CMAC_GENERATE_WITH_REMAINDER    = 1,
    CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER   = 2,
    CMD_AES_CMAC_VERIFY_WITH_REMAINDER      = 3,

    CMD_ECC_TYPE_NIST      = 0,
    CMD_ECC_TYPE_BRAINPOOL = 1,
    CMD_ECC_TYPE_KOBLITZ   = 2,

    CMD_ECC_KEY_LENGTH_256 = 0,

    CMD_HMAC_HASH_TYPE_SHA1   = 0,
    CMD_HMAC_HASH_TYPE_SHA224 = 1,
    CMD_HMAC_HASH_TYPE_SHA256 = 2,
} cmd_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint32_t gs_cmd[7] =
{
    BSWAP_32BIG_C(0U), BSWAP_32BIG_C(1U), BSWAP_32BIG_C(2U), BSWAP_32BIG_C(3U), BSWAP_32BIG_C(4U), BSWAP_32BIG_C(5U),
    BSWAP_32BIG_C(6U)
};

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/
tsip_ret_t r_tsip_wrapper_pf0_secp256r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         uint32_t       OutData_Signature[])
{
    return r_tsip_pf0(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      OutData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf1_secp256r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[])
{
    return r_tsip_pf1(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      InData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf4_secp256r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_pf4(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      OutData_PubKeyIndex,
                      OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2c_secp256r1 (const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p2c(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p1e_secp256r1 (const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p1e(&gs_cmd[CMD_ECC_TYPE_NIST],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_pf0_brainpoolp256r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               uint32_t       OutData_Signature[])
{
    return r_tsip_pf0(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      OutData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf1_brainpoolp256r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[])
{
    return r_tsip_pf1(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_KeyIndex,
                      InData_MsgDgst,
                      InData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf4_brainpoolp256r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_pf4(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      OutData_PubKeyIndex,
                      OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2c_brainpoolp256r1 (const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p2c(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p1e_brainpoolp256r1 (const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p1e(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL],
                      &gs_cmd[CMD_ECC_KEY_LENGTH_256],
                      InData_IV,
                      InData_InstData,
                      OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_pf5_secp384r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         uint32_t       OutData_Signature[])
{
    return r_tsip_pf5(&gs_cmd[CMD_ECC_TYPE_NIST], InData_KeyIndex, InData_MsgDgst, OutData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf6_secp384r1 (const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[])
{
    return r_tsip_pf6(&gs_cmd[CMD_ECC_TYPE_NIST], InData_KeyIndex, InData_MsgDgst, InData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf9_secp384r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_pf9(&gs_cmd[CMD_ECC_TYPE_NIST], OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2e_secp384r1 (const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p2e(&gs_cmd[CMD_ECC_TYPE_NIST], InData_IV, InData_InstData, OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2d_secp384r1 (const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p2d(&gs_cmd[CMD_ECC_TYPE_NIST], InData_IV, InData_InstData, OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_pf5_brainpoolp384r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               uint32_t       OutData_Signature[])
{
    return r_tsip_pf5(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], InData_KeyIndex, InData_MsgDgst, OutData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf6_brainpoolp384r1 (const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[])
{
    return r_tsip_pf6(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], InData_KeyIndex, InData_MsgDgst, InData_Signature);
}

tsip_ret_t r_tsip_wrapper_pf9_brainpoolp384r1 (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_pf9(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2e_brainpoolp384r1 (const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p2e(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], InData_IV, InData_InstData, OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2d_brainpoolp384r1 (const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p2d(&gs_cmd[CMD_ECC_TYPE_BRAINPOOL], InData_IV, InData_InstData, OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p7d (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_MsgDgst[],
                               uint32_t       OutData_Signature[])
{
    return r_tsip_p7d(InData_KeyIndex, InData_MsgDgst, OutData_Signature);
}

tsip_ret_t r_tsip_wrapper_p7e (const uint32_t InData_KeyIndex[],
                               const uint32_t InData_MsgDgst[],
                               const uint32_t InData_Signature[])
{
    return r_tsip_p7e(InData_KeyIndex, InData_MsgDgst, InData_Signature);
}

tsip_ret_t r_tsip_wrapper_ped (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_ped(OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2a (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_p2a(TSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_1024, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p2b (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    return r_tsip_p2b(TSIP_PRV_MAX_RETRY_COUNT_KEY_GEN_RSA_2048, OutData_PubKeyIndex, OutData_PrivKeyIndex);
}

tsip_ret_t r_tsip_wrapper_p48i_ecb_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p48i(&gs_cmd[CMD_AES_MODE_ECB_ENCRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p48i_ecb_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p48i(&gs_cmd[CMD_AES_MODE_ECB_DECRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p48i_cbc_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p48i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p48i_cbc_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p48i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p48i_ctr (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p48i(&gs_cmd[CMD_AES_MODE_CTR_CRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p50i_ecb_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p50i(&gs_cmd[CMD_AES_MODE_ECB_ENCRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p50i_ecb_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p50i(&gs_cmd[CMD_AES_MODE_ECB_DECRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p50i_cbc_enc (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p50i(&gs_cmd[CMD_AES_MODE_CBC_ENCRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p50i_cbc_dec (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p50i(&gs_cmd[CMD_AES_MODE_CBC_DECRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p50i_ctr (const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    return r_tsip_p50i(&gs_cmd[CMD_AES_MODE_CTR_CRYPT], InData_KeyIndex, InData_IV);
}

tsip_ret_t r_tsip_wrapper_p41f_gen (const uint32_t * InData_Text, uint32_t * OutData_DataT, const uint32_t all_msg_len)
{
    uint32_t InData_Cmd[1] =
    {
        ((0 == (all_msg_len % 16)) &&
         (0 !=
          all_msg_len)) ? TSIP_PRV_CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER :
        TSIP_PRV_CMD_AES_CMAC_GENERATE_WITH_REMAINDER
    };
    uint32_t InData_DataT = 0;

    return r_tsip_p41f(InData_Cmd, InData_Text, &InData_DataT, (uint32_t *) &all_msg_len, OutData_DataT);
}

tsip_ret_t r_tsip_wrapper_p41f_veri (const uint32_t * InData_Text,
                                     const uint32_t * InData_DataT,
                                     const uint32_t * InData_DataTLen,
                                     const uint32_t   all_msg_len)
{
    uint32_t InData_Cmd[1] =
    {
        ((0 == (all_msg_len % 16)) &&
         (0 !=
          all_msg_len)) ? TSIP_PRV_CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER :
        TSIP_PRV_CMD_AES_CMAC_VERIFY_WITH_REMAINDER
    };
    uint32_t OutData_DataT[4] = {0};
    (void) all_msg_len;

    return r_tsip_p41f(InData_Cmd, InData_Text, InData_DataT, InData_DataTLen, OutData_DataT);
}

tsip_ret_t r_tsip_wrapper_p44f_gen (const uint32_t * InData_Text, uint32_t * OutData_DataT, const uint32_t all_msg_len)
{
    uint32_t InData_Cmd[1] =
    {
        ((0 == (all_msg_len % 16)) &&
         (0 !=
          all_msg_len)) ? TSIP_PRV_CMD_AES_CMAC_GENERATE_WITHOUT_REMAINDER :
        TSIP_PRV_CMD_AES_CMAC_GENERATE_WITH_REMAINDER
    };
    uint32_t InData_DataT = 0;

    return r_tsip_p44f(InData_Cmd, InData_Text, &InData_DataT, (uint32_t *) &all_msg_len, OutData_DataT);
}

tsip_ret_t r_tsip_wrapper_p44f_veri (const uint32_t * InData_Text,
                                     const uint32_t * InData_DataT,
                                     const uint32_t * InData_DataTLen,
                                     const uint32_t   all_msg_len)
{
    uint32_t InData_Cmd[1] =
    {
        ((0 == (all_msg_len % 16)) &&
         (0 !=
          all_msg_len)) ? TSIP_PRV_CMD_AES_CMAC_VERIFY_WITHOUT_REMAINDER :
        TSIP_PRV_CMD_AES_CMAC_VERIFY_WITH_REMAINDER
    };
    uint32_t OutData_DataT[4] = {0};
    (void) all_msg_len;

    return r_tsip_p44f(InData_Cmd, InData_Text, InData_DataT, InData_DataTLen, OutData_DataT);
}

tsip_ret_t r_tsip_wrapper_p0f_sha1 (const uint32_t InData_IV[],
                                    const uint32_t InData_InstData[],
                                    uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p0f(&gs_cmd[CMD_HMAC_HASH_TYPE_SHA1], InData_IV, InData_InstData, OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p0f_sha224 (const uint32_t InData_IV[],
                                      const uint32_t InData_InstData[],
                                      uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p0f(&gs_cmd[CMD_HMAC_HASH_TYPE_SHA224], InData_IV, InData_InstData, OutData_KeyIndex);
}

tsip_ret_t r_tsip_wrapper_p0f_sha256 (const uint32_t InData_IV[],
                                      const uint32_t InData_InstData[],
                                      uint32_t       OutData_KeyIndex[])
{
    return r_tsip_p0f(&gs_cmd[CMD_HMAC_HASH_TYPE_SHA256], InData_IV, InData_InstData, OutData_KeyIndex);
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
