/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "r_typedefs.h"
#include "r_cip_drv_api_ext.h"

#ifndef RSIP_CHECK_PARAM_H_
 #define RSIP_CHECK_PARAM_H_

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/*cstat -CERT-MSC41-C_b define values are common terms or offsets, not sensitive*/
 #define EN_IV_SELECT                 (0x00030000uL) /* supported IV select value */
 #define EN_IV_SIZE                   (16U)          /* supported IV size */

 #define ECDSA_P256_KEY_SIZE_TOTAL    (64U)          /* ECDSA P256 Key Size Qx + Qy */
 #define ECDSA_P256_KEY_SIZE_QXQY     (32U)          /* ECDSA P256 Key Size Qx, Qy */
 #define ECDSA_P256_SIGN_SIZE         (64U)          /* ECDSA P256 Sign Size */

 #define KEY_ID_INSTALLED_EXT         (0x00020000uL) /* for key_select check */
 #define KEY_ID_INSTALLED_MASK        (0xFFFFFF00uL) /* for key_select check */
 #define KEY_ID_MASK                  (0x000000FFuL) /* for key_select check */
/*cstat +CERT-MSC41-C_b*/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/******************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/
extern cip_drv_ret_t rsip_check_dec_param(const st_cip_drv_cipher_img_param_t * const dec_param);
extern cip_drv_ret_t rsip_check_verify_param(const st_cip_drv_cc_key_cert_param_t * const  p_cc_key_cert_param,
                                             const st_cip_drv_cc_code_cert_param_t * const p_cc_code_cert_param,
                                             const st_cip_drv_cipher_img_param_t * const   p_dec_img_param);

#endif                                 /* RSIP_CHECK_PARAM_H_ */
