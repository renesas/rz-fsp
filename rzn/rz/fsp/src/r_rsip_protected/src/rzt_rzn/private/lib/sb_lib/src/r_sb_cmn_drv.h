/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0776 ++ # D004 Exception according to function nomenclature */

#ifndef R_SB_CMN_DRV_H

/* Multiple inclusion protection macro */
#define R_SB_CMN_DRV_H

/*=====================================================================================================================
 * Public macro definitions
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Public type definitions
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Public global variables
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Public global functions
 * =====================================================================================================================*/
extern sb_ret_t r_sb_cmn_drv_set_cc_key_cert_param(const st_sb_key_cert_t * const         p_key_cert_st,
                                                   const st_sb_tlv_t * const              p_img_pk_hash_tlv,
                                                   const st_sb_tlv_t * const              p_sign_pk_tlv,
                                                   const st_sb_tlv_t * const              p_sign_tlv,
                                                   st_cip_drv_cc_key_cert_param_t * const p_cc_key_cert_param);
extern sb_ret_t r_sb_cmn_drv_set_cc_code_cert_param(const st_sb_code_cert_t * const         p_code_cert_st,
                                                    const uint32_t                          img_addr,
                                                    const st_sb_tlv_t * const               p_sign_pk_tlv,
                                                    const st_sb_tlv_t * const               p_sign_tlv,
                                                    const st_sb_tlv_t * const               p_img_hash_tlv,
                                                    st_cip_drv_cc_code_cert_param_t * const p_cc_code_cert_param);
extern sb_ret_t r_sb_cmn_drv_set_cipher_img_param(const st_sb_code_cert_t * const       p_code_cert_st,
                                                  const st_sb_tlv_t * const             p_img_cip_info,
                                                  const st_sb_tlv_t * const             p_img_cip_iv,
                                                  const sb_bool_t                       is_overwrite_image,
                                                  const uint32_t                        timing,
                                                  st_cip_drv_cipher_img_param_t * const p_cipher_img_param);
extern sb_ret_t r_sb_cmn_drv_get_sb_ret_from_cip_ret(const cip_drv_ret_t cip_ret);

#endif                                 /* R_SB_CMN_DRV_H */

/*=====================================================================================================================
 * End of File
 * =====================================================================================================================*/
