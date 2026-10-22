/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_COMMON_H
#define R_TSIP_COMMON_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip.h"
#include "r_tsip_private.h"
#include "r_tsip_util.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "TSIP" in ASCII, used to determine if channel is open. */
#define TSIP_OPEN    (0x52534950U)

/* Various lengths */

/* TSIP_PRV_BYTE_SIZE_AES_BLOCK is defined in r_tsip.h */

/* ECC */
#define TSIP_PRV_BYTE_SIZE_ECC_256_PARAM                           (32U)
#define TSIP_PRV_BYTE_SIZE_ECC_384_PARAM                           (48U)
#define TSIP_PRV_BYTE_SIZE_ECC_512_PARAM                           (64U)
#define TSIP_PRV_BYTE_SIZE_ECC_521_PARAM                           (66U)

#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QX            (0U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_256_QY            (32U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_384_QX            (0U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_384_QY            (48U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_512_QX            (0U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_512_QY            (64U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_521_QX            (14U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_521_QY            (94U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_ECC_EDWARDS25519_Q    (0U)

/* RSA */
#define TSIP_PRV_BYTE_SIZE_RSA_1024_N                              (128U)
#define TSIP_PRV_BYTE_SIZE_RSA_2048_N                              (256U)
#define TSIP_PRV_BYTE_SIZE_RSA_3072_N                              (384U)
#define TSIP_PRV_BYTE_SIZE_RSA_4096_N                              (512U)
#define TSIP_PRV_BYTE_SIZE_RSA_E                                   (4U)

#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_N                 (0U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_1024_E            (128U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_2048_E            (256U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_3072_E            (384U)
#define TSIP_PRV_BYTE_POS_WRAPPED_PUBLIC_KEY_RSA_4096_E            (512U)

/* SHA */
#define TSIP_PRV_BYTE_SIZE_HASH_BLOCK_SHA1_SHA224_SHA256           (64U)
#define TSIP_PRV_BYTE_SIZE_HASH_BLOCK_SHA384_SHA512                (128U)
#define TSIP_PRV_BYTE_SIZE_HASH_BLOCK_SHA3_224                     (144U)
#define TSIP_PRV_BYTE_SIZE_HASH_BLOCK_SHA3_256                     (136U)
#define TSIP_PRV_BYTE_SIZE_HASH_BLOCK_SHA3_384                     (104U)
#define TSIP_PRV_BYTE_SIZE_HASH_BLOCK_SHA3_512                     (72U)

/* RNG */
#define TSIP_PRV_BYTE_SIZE_RNG                                     (16U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* r_tsip.c */
fsp_err_t r_tsip_random_number_generate(tsip_ctrl_t * const p_ctrl, uint8_t * const p_random);

/* r_tsip_sha.c */
fsp_err_t r_tsip_sha_init(tsip_ctrl_t * const p_ctrl, tsip_hash_type_t const hash_type);
fsp_err_t r_tsip_sha_update(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message, uint32_t const message_length);
fsp_err_t r_tsip_sha_finish(tsip_ctrl_t * const p_ctrl, uint8_t * const p_digest);

/*******************************************************************************************************************//**
 * Resets handle.
 *
 * @param[in] handle Pointer to handle.
 ***********************************************************************************************************************/
TSIP_PRV_STATIC_INLINE void r_tsip_handle_reset (tsip_handle_t * handle)
{
    memset(handle, 0, sizeof(tsip_handle_t));
}

#endif                                 /* R_TSIP_COMMON_H */
