/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "r_cip_drv_api.h"

#ifndef R_CIP_DRV_EXT_H_
 #define R_CIP_DRV_EXT_H_

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/*cstat -CERT-MSC41-C_b define values are common terms or offsets, not sensitive */

 #define RSIP_MIN_KEY_ID                      (0U) /* min key_select num */
 #define RSIP_MAX_KEY_ID                      (4U) /* max key_select num */

 #define RSIP_PARAM_BLOCK_SIZE                (512)

 #define RSIP_CBC_IV_LEN                      (4)

 #define RSIP_SHA256_HASH_LENGTH_BYTE_SIZE    (32) /* SHA256 Hash size (bytes) */

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/* return value (RSIP driver included in BootROM) */
 #define CIP_DRV_RET_CLK_SUPPLY_FAIL          ((cip_drv_ret_t) 0xAAAA0101UL) /* Failed to supply clk to RSIP */
 #define CIP_DRV_RET_JTAG_AUTH_FAIL           ((cip_drv_ret_t) 0xAAAA0102UL) /* Failed to authentication JTAG with RSIP */
 #define CIP_DRV_RET_INIT_FAIL                ((cip_drv_ret_t) 0xAAAA0103UL) /* Failed to Initialize RSIP */
 #define CIP_DRV_RET_KEY_FAIL                 ((cip_drv_ret_t) 0xAAAA0104UL) /* Wrong key data */

/*cstat +CERT-MSC41-C_b */

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

#endif                                 /* R_CIP_DRV_EXT_H_ */
