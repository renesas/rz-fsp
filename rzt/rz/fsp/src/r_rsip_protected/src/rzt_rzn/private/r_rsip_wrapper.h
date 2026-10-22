/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RSIP_WRAPPER_H
#define R_RSIP_WRAPPER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Primitive function names */
#define RSIP_PRV_FUNC_NAME_RANDOM_NUMBER_GENERATE                             r_rsip_p20

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_128                               r_rsip_wrapper_p55_aes128
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_128                               r_rsip_wrapper_pad_aes128
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_128_KEY_WRAP                           r_rsip_wrapper_p8f_aes128
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_128_KEY_UNWRAP                         r_rsip_wrapper_p90_aes128

#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_128                        r_rsip_wrapper_p48i_ecb_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_128                        r_rsip_wrapper_p48i_ecb_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_128                        r_rsip_wrapper_p48i_cbc_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_128                        r_rsip_wrapper_p48i_cbc_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_128_WRAPPED_IV             r_rsip_wrapper_p48i_cbc_enc_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_128_WRAPPED_IV             r_rsip_wrapper_p48i_cbc_dec_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_128                            r_rsip_wrapper_p48i_ctr
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_128                              r_rsip_p48u
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_128                               r_rsip_p48f

#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_128                               r_rsip_wrapper_p29i_plain_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_128_WRAPPED_IV                    r_rsip_wrapper_p29i_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_128                         r_rsip_p29a
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_128                  r_rsip_p29t
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_128                             r_rsip_p29u
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_128                              r_rsip_p29f
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_128                               r_rsip_wrapper_p32i_plain_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_128_WRAPPED_IV                    r_rsip_wrapper_p32i_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_128                         r_rsip_p32a
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_128                  r_rsip_p32t
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_128                             r_rsip_p32u
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_128                              r_rsip_p32f

#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_INIT_128                               r_rsip_wrapper_p95i
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_UPDATE_128                             r_rsip_p95u
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_FINAL_128                              r_rsip_wrapper_p95f
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_INIT_128                               r_rsip_wrapper_p98i
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_UPDATE_128                             r_rsip_p98u
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_FINAL_128                              r_rsip_wrapper_p98f

#define RSIP_PRV_FUNC_NAME_AES_CMAC_INIT_128                                  r_rsip_p41i
#define RSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_128                                r_rsip_p41u
#define RSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_128                        r_rsip_wrapper_p41f_gen
#define RSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_128                          r_rsip_wrapper_p41f_veri

#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_0_AES_128                              r_rsip_wrapper_pba_ch0
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_1_AES_128                              r_rsip_wrapper_pba_ch1
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_2_AES_128                              r_rsip_wrapper_pba_ch2

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_192                               r_rsip_wrapper_p55_aes192
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_192                               r_rsip_wrapper_pad_aes192
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_192_KEY_WRAP                           NULL
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_192_KEY_UNWRAP                         NULL

#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_192                        r_rsip_wrapper_p89i_ecb_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_192                        r_rsip_wrapper_p89i_ecb_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_192                        r_rsip_wrapper_p89i_cbc_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_192                        r_rsip_wrapper_p89i_cbc_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_192_WRAPPED_IV             NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_192_WRAPPED_IV             NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_192                            r_rsip_wrapper_p89i_ctr
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_192                              r_rsip_p89u
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_192                               r_rsip_p89f

#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_192                               r_rsip_p83i
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_192_WRAPPED_IV                    NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_192                         r_rsip_p83a
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_192                  r_rsip_p83t
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_192                             r_rsip_p83u
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_192                              r_rsip_p83f
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_192                               r_rsip_p85i
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_192_WRAPPED_IV                    NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_192                         r_rsip_p85a
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_192                  r_rsip_p85t
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_192                             r_rsip_p85u
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_192                              r_rsip_p85f

#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_INIT_192                               r_rsip_wrapper_pa7i
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_UPDATE_192                             r_rsip_pa7u
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_FINAL_192                              r_rsip_pa7f
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_INIT_192                               r_rsip_wrapper_pb0i
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_UPDATE_192                             r_rsip_pb0u
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_FINAL_192                              r_rsip_pb0f

#define RSIP_PRV_FUNC_NAME_AES_CMAC_INIT_192                                  r_rsip_p87i
#define RSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_192                                r_rsip_p87u
#define RSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_192                        r_rsip_wrapper_p87f_gen
#define RSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_192                          r_rsip_wrapper_p87f_veri

#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_0_AES_192                              NULL
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_1_AES_192                              NULL
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_2_AES_192                              NULL

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_256                               r_rsip_wrapper_p55_aes256
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_256                               r_rsip_wrapper_pad_aes256
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_256_KEY_WRAP                           r_rsip_wrapper_p8f_aes256
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_256_KEY_UNWRAP                         r_rsip_wrapper_p90_aes256

#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_256                        r_rsip_wrapper_p50i_ecb_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_256                        r_rsip_wrapper_p50i_ecb_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_256                        r_rsip_wrapper_p50i_cbc_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_256                        r_rsip_wrapper_p50i_cbc_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_256_WRAPPED_IV             r_rsip_wrapper_p50i_cbc_enc_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_256_WRAPPED_IV             r_rsip_wrapper_p50i_cbc_dec_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_256                            r_rsip_wrapper_p50i_ctr
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_256                              r_rsip_p50u
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_256                               r_rsip_p50f

#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_256                               r_rsip_wrapper_p34i_plain_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_256_WRAPPED_IV                    r_rsip_wrapper_p34i_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_256                         r_rsip_p34a
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_256                  r_rsip_p34t
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_256                             r_rsip_p34u
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_256                              r_rsip_p34f
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_256                               r_rsip_wrapper_p36i_plain_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_256_WRAPPED_IV                    r_rsip_wrapper_p36i_wrapped_iv
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_256                         r_rsip_p36a
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_256                  r_rsip_p36t
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_256                             r_rsip_p36u
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_256                              r_rsip_p36f

#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_INIT_256                               r_rsip_wrapper_pa1i
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_UPDATE_256                             r_rsip_pa1u
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_FINAL_256                              r_rsip_pa1f
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_INIT_256                               r_rsip_wrapper_pa4i
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_UPDATE_256                             r_rsip_pa4u
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_FINAL_256                              r_rsip_pa4f

#define RSIP_PRV_FUNC_NAME_AES_CMAC_INIT_256                                  r_rsip_p44i
#define RSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_256                                r_rsip_p44u
#define RSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_256                        r_rsip_wrapper_p44f_gen
#define RSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_256                          r_rsip_wrapper_p44f_veri

#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_0_AES_256                              r_rsip_wrapper_pbc_ch0
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_1_AES_256                              r_rsip_wrapper_pbc_ch1
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_2_AES_256                              r_rsip_wrapper_pbc_ch2

#define RSIP_PRV_FUNC_NAME_GHASH_COMPUTE                                      r_rsip_p21

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_XTS_AES_128                           r_rsip_p16
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_XTS_AES_128                           r_rsip_wrapper_pad_xts_aes128

#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_INIT_128                               r_rsip_pb3i
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_UPDATE_128                             r_rsip_pb3u
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_FINAL_128                              r_rsip_pb3f
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_INIT_128                               r_rsip_pb6i
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_UPDATE_128                             r_rsip_pb6u
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_FINAL_128                              r_rsip_pb6f

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_XTS_AES_256                           r_rsip_p17
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_XTS_AES_256                           r_rsip_wrapper_pad_xts_aes256

#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_INIT_256                               r_rsip_pb9i
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_UPDATE_256                             r_rsip_pb9u
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_FINAL_256                              r_rsip_pb9f
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_INIT_256                               r_rsip_pc2i
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_UPDATE_256                             r_rsip_pc2u
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_FINAL_256                              r_rsip_pc2f

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_CHACHA20                              r_rsip_wrapper_p55_chacha20
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_CHACHA20                              r_rsip_wrapper_pad_chacha20

#define RSIP_PRV_FUNC_NAME_CHACHA20_INIT                                      r_rsip_p96i
#define RSIP_PRV_FUNC_NAME_CHACHA20_UPDATE                                    r_rsip_p96u
#define RSIP_PRV_FUNC_NAME_CHACHA20_FINAL                                     r_rsip_p96f
#define RSIP_PRV_FUNC_NAME_CHACHA20_SUSPEND                                   r_rsip_p96s
#define RSIP_PRV_FUNC_NAME_CHACHA20_RESUME                                    r_rsip_p96r

#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_ENC_INIT                         r_rsip_wrapper_p97i_enc
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_DEC_INIT                         r_rsip_wrapper_p97i_dec
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_UPDATE_AAD                       r_rsip_p97a
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_UPDATE_TRANSITION                r_rsip_p97t
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_UPDATE                           r_rsip_p97u
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_FINAL                            r_rsip_p97f
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_SUSPEND                          r_rsip_p97s
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_ENC_RESUME                       r_rsip_wrapper_p97r_enc
#define RSIP_PRV_FUNC_NAME_CHACHA20_POLY1305_DEC_RESUME                       r_rsip_wrapper_p97r_dec

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP256R1                    r_rsip_wrapper_pf4_secp256r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256R1_PUBLIC                  r_rsip_wrapper_pad_secp256r1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256R1_PRIVATE                 r_rsip_wrapper_pad_secp256r1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP256R1                               r_rsip_wrapper_pf0_secp256r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP256R1                             r_rsip_wrapper_pf1_secp256r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP256R1                             r_rsip_wrapper_pe2_wrapped_secp256r1
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP256R1                               r_rsip_wrapper_pe2_plain_secp256r1

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP256R1                    r_rsip_wrapper_peei_secp256r1
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP256R1                   r_rsip_peef
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP256R1                  r_rsip_wrapper_pe1_secp256r1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP384R1                    r_rsip_wrapper_pf9_secp384r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP384R1_PUBLIC                  r_rsip_wrapper_pad_secp384r1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP384R1_PRIVATE                 r_rsip_wrapper_pad_secp384r1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP384R1                               r_rsip_wrapper_pf5_secp384r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP384R1                             r_rsip_wrapper_pf6_secp384r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP384R1                             r_rsip_wrapper_p4e_wrapped_secp384r1
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP384R1                               r_rsip_wrapper_p4e_plain_secp384r1

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP384R1                    r_rsip_wrapper_p51i_secp384r1
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP384R1                   r_rsip_p51f
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP384R1                  r_rsip_wrapper_pe1_secp384r1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP521R1                    r_rsip_wrapper_p13
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP521R1_PUBLIC                  r_rsip_wrapper_pad_secp521r1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP521R1_PRIVATE                 r_rsip_wrapper_pad_secp521r1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP521R1                               r_rsip_wrapper_p11
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP521R1                             r_rsip_wrapper_p12

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP521R1                             r_rsip_wrapper_p4f_wrapped_secp521r1
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP521R1                               r_rsip_wrapper_p4f_plain_secp521r1

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP521R1                    r_rsip_wrapper_p52i_secp521r1
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP521R1                   r_rsip_p52f
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP521R1                  r_rsip_wrapper_pe1_secp521r1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP256K1                    r_rsip_wrapper_pf4_secp256k1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256K1_PUBLIC                  r_rsip_wrapper_pad_secp256k1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256K1_PRIVATE                 r_rsip_wrapper_pad_secp256k1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP256K1                               r_rsip_wrapper_pf0_secp256k1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP256K1                             r_rsip_wrapper_pf1_secp256k1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP256R1              r_rsip_wrapper_pf4_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP256R1_PUBLIC            r_rsip_wrapper_pad_brainpoolp256r1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP256R1_PRIVATE           r_rsip_wrapper_pad_brainpoolp256r1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP256R1                         r_rsip_wrapper_pf0_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP256R1                       r_rsip_wrapper_pf1_brainpoolp256r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP256R1                       r_rsip_wrapper_pe2_wrapped_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP256R1                         r_rsip_wrapper_pe2_plain_brainpoolp256r1

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP256R1              r_rsip_wrapper_peei_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP256R1             r_rsip_peef
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP256R1            r_rsip_wrapper_pe1_brainpoolp256r1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP384R1              r_rsip_wrapper_pf9_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP384R1_PUBLIC            r_rsip_wrapper_pad_brainpoolp384r1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP384R1_PRIVATE           r_rsip_wrapper_pad_brainpoolp384r1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP384R1                         r_rsip_wrapper_pf5_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP384R1                       r_rsip_wrapper_pf6_brainpoolp384r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP384R1                       r_rsip_wrapper_p4e_wrapped_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP384R1                         r_rsip_wrapper_p4e_plain_brainpoolp384r1

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP384R1              r_rsip_wrapper_p51i_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP384R1             r_rsip_p51f
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP384R1            r_rsip_wrapper_pe1_brainpoolp384r1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP512R1              r_rsip_wrapper_p7f
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP512R1_PUBLIC            r_rsip_wrapper_pad_brainpoolp512r1_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP512R1_PRIVATE           r_rsip_wrapper_pad_brainpoolp512r1_priv

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP512R1                         r_rsip_wrapper_p7d
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP512R1                       r_rsip_wrapper_p7e

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP512R1                       r_rsip_wrapper_p5e_wrapped_brainpoolp512r1
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP512R1                         r_rsip_wrapper_p5e_plain_brainpoolp512r1

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP512R1              r_rsip_wrapper_p5fi_brainpoolp512r1
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP512R1             r_rsip_p5ff
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP512R1            r_rsip_wrapper_pe1_brainpoolp512r1

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_EDWARDS25519                 r_rsip_wrapper_p4a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_EDWARDS25519_PUBLIC               r_rsip_wrapper_pad_edwards25519_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_EDWARDS25519_PRIVATE              r_rsip_wrapper_pad_edwards25519_priv

#define RSIP_PRV_FUNC_NAME_EDDSA_SIGN_EDWARDS25519                            r_rsip_wrapper_p4c
#define RSIP_PRV_FUNC_NAME_EDDSA_VERIFY_EDWARDS25519                          r_rsip_wrapper_p4d

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_1024                         r_rsip_wrapper_p2a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_1024_PUBLIC                       r_rsip_wrapper_pad_rsa1024_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_1024_PRIVATE                      r_rsip_wrapper_pad_rsa1024_priv

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_1024                                   r_rsip_p53
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_1024                                   r_rsip_p54

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_2048                         r_rsip_wrapper_p2b
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_2048_PUBLIC                       r_rsip_wrapper_pad_rsa2048_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_2048_PRIVATE                      r_rsip_wrapper_pad_rsa2048_priv

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_2048                                   r_rsip_p56
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_2048                                   r_rsip_p57

#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_INIT_2048                           r_rsip_pedi
#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_FINAL_2048                          r_rsip_pedf
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_RSA_2048                       r_rsip_wrapper_pe1_rsa2048

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_3072                         r_rsip_wrapper_p3a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_3072_PUBLIC                       r_rsip_wrapper_pad_rsa3072_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_3072_PRIVATE                      r_rsip_wrapper_pad_rsa3072_priv

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_3072                                   r_rsip_p79
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_3072                                   r_rsip_p7a

#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_INIT_3072                           NULL
#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_FINAL_3072                          NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_RSA_3072                       NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_4096                         r_rsip_wrapper_p3b
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_4096_PUBLIC                       r_rsip_wrapper_pad_rsa4096_pub
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_4096_PRIVATE                      r_rsip_wrapper_pad_rsa4096_priv

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_4096                                   r_rsip_p7b
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_4096                                   r_rsip_p7c

#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_INIT_4096                           NULL
#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_FINAL_4096                          NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_RSA_4096                       NULL

#define RSIP_PRV_FUNC_NAME_SHA1SHA2_INIT                                      r_rsip_p70i
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_RESUME                                    r_rsip_p70r
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_UPDATE                                    r_rsip_p70u
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_SUSPEND                                   r_rsip_p70s
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_FINAL                                     r_rsip_p70f

#define RSIP_PRV_FUNC_NAME_SHA3_INIT                                          r_rsip_p78i
#define RSIP_PRV_FUNC_NAME_SHA3_RESUME                                        r_rsip_p78r
#define RSIP_PRV_FUNC_NAME_SHA3_UPDATE                                        r_rsip_p78u
#define RSIP_PRV_FUNC_NAME_SHA3_SUSPEND                                       r_rsip_p78s
#define RSIP_PRV_FUNC_NAME_SHA3_FINAL                                         r_rsip_p78f

#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_INIT                                 r_rsip_p75i
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_RESUME                               r_rsip_p75r
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_UPDATE                               r_rsip_p75u
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_SUSPEND                              r_rsip_p75s
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_FINAL                                r_rsip_p75f

#define RSIP_PRV_FUNC_NAME_HMAC_SHA3_INIT                                     r_rsip_p58i
#define RSIP_PRV_FUNC_NAME_HMAC_SHA3_RESUME                                   r_rsip_p58r
#define RSIP_PRV_FUNC_NAME_HMAC_SHA3_UPDATE                                   r_rsip_p58u
#define RSIP_PRV_FUNC_NAME_HMAC_SHA3_SUSPEND                                  r_rsip_p58s
#define RSIP_PRV_FUNC_NAME_HMAC_SHA3_FINAL                                    r_rsip_p58f

#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_INIT                             r_rsip_pe5i
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_RESUME                           r_rsip_pe5r
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_ENC_UPDATE                       r_rsip_pe5e
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_UPDATE                           r_rsip_pe5u
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_SUSPEND                          r_rsip_pe5s
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_FINAL                            r_rsip_pe5f

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA1                             r_rsip_wrapper_p55_hmac_sha1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA1                             r_rsip_wrapper_pad_hmac_sha1

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA224                           r_rsip_wrapper_p55_hmac_sha224
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA224                           r_rsip_wrapper_pad_hmac_sha224

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA256                           r_rsip_wrapper_p55_hmac_sha256
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA256                           r_rsip_wrapper_pad_hmac_sha256

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA384                           r_rsip_wrapper_p55_hmac_sha384
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA384                           r_rsip_wrapper_pad_hmac_sha384

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA512                           r_rsip_wrapper_p55_hmac_sha512
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA512                           r_rsip_wrapper_pad_hmac_sha512

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA3_224                         r_rsip_wrapper_p55_hmac_sha3_224
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA3_224                         r_rsip_wrapper_pad_hmac_sha3_224

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA3_256                         r_rsip_wrapper_p55_hmac_sha3_256
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA3_256                         r_rsip_wrapper_pad_hmac_sha3_256

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA3_384                         r_rsip_wrapper_p55_hmac_sha3_384
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA3_384                         r_rsip_wrapper_pad_hmac_sha3_384

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA3_512                         r_rsip_wrapper_p55_hmac_sha3_512
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA3_512                         r_rsip_wrapper_pad_hmac_sha3_512

#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_KEY_IMPORT_SHA256                  r_rsip_wrapper_pe4_sha256
#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_MSG_WRAP_SHA256                    r_rsip_wrapper_pe3_sha256
#define RSIP_PRV_FUNC_NAME_KDF_MAC_KEY_IMPORT_SHA256                          r_rsip_wrapper_pe6_sha256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_AES_128              r_rsip_wrapper_pe7_sha256_aes128
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_AES_256              r_rsip_wrapper_pe7_sha256_aes256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA1            r_rsip_wrapper_pe7_sha256_hmac_sha1
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA256          r_rsip_wrapper_pe7_sha256_hmac_sha256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA384          r_rsip_wrapper_pe7_sha256_hmac_sha384
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA512          r_rsip_wrapper_pe7_sha256_hmac_sha512
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA256_AES                     r_rsip_wrapper_pe7_sha256_iv_aes
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA256_TLS12                   r_rsip_wrapper_pe7_sha256_iv_tls12
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA256_TLS13                   r_rsip_wrapper_pe7_sha256_iv_tls13

#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_KEY_IMPORT_SHA384                  r_rsip_wrapper_pe4_sha384
#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_MSG_WRAP_SHA384                    r_rsip_wrapper_pe3_sha384
#define RSIP_PRV_FUNC_NAME_KDF_MAC_KEY_IMPORT_SHA384                          r_rsip_wrapper_pe6_sha384
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA384_AES_128              r_rsip_wrapper_pe7_sha384_aes128
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA384_AES_256              r_rsip_wrapper_pe7_sha384_aes256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA384_HMAC_SHA1            r_rsip_wrapper_pe7_sha384_hmac_sha1
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA384_HMAC_SHA256          r_rsip_wrapper_pe7_sha384_hmac_sha256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA384_HMAC_SHA384          r_rsip_wrapper_pe7_sha384_hmac_sha384
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA384_HMAC_SHA512          r_rsip_wrapper_pe7_sha384_hmac_sha512
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA384_AES                     r_rsip_wrapper_pe7_sha384_iv_aes
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA384_TLS12                   r_rsip_wrapper_pe7_sha384_iv_tls12
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA384_TLS13                   r_rsip_wrapper_pe7_sha384_iv_tls13

#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_KEY_IMPORT_SHA512_SECP521R1        r_rsip_wrapper_pe4_sha512_secp521r1
#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_KEY_IMPORT_SHA512_BRAINPOOLP512R1 \
    r_rsip_wrapper_pe4_sha512_brainpoolp512r1
#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_MSG_WRAP_SHA512_SECP521R1          r_rsip_wrapper_pe3_sha512_secp521r1
#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_MSG_WRAP_SHA512_BRAINPOOLP512R1    r_rsip_wrapper_pe3_sha512_brainpoolp512r1
#define RSIP_PRV_FUNC_NAME_KDF_MAC_KEY_IMPORT_SHA512                          r_rsip_wrapper_pe6_sha512
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA512_AES_128              r_rsip_wrapper_pe7_sha512_aes128
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA512_AES_256              r_rsip_wrapper_pe7_sha512_aes256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA512_HMAC_SHA1            r_rsip_wrapper_pe7_sha512_hmac_sha1
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA512_HMAC_SHA256          r_rsip_wrapper_pe7_sha512_hmac_sha256
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA512_HMAC_SHA384          r_rsip_wrapper_pe7_sha512_hmac_sha384
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA512_HMAC_SHA512          r_rsip_wrapper_pe7_sha512_hmac_sha512
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA512_AES                     r_rsip_wrapper_pe7_sha512_iv_aes
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA512_TLS12                   r_rsip_wrapper_pe7_sha512_iv_tls12
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA512_TLS13                   r_rsip_wrapper_pe7_sha512_iv_tls13

#define RSIP_PRV_PKI_HASH_TYPE_SHA1                                           (0U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA224                                         (0U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA256                                         (1U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA384                                         (4U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA512                                         (5U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA512_224                                     (2U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA512_256                                     (3U)

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* Key generation */
rsip_ret_t r_rsip_wrapper_p55_aes128(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_aes192(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_aes256(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_xts_aes128(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_xts_aes256(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_chacha20(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha1(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha224(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha256(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha384(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha512(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha3_224(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha3_256(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha3_384(uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p55_hmac_sha3_512(uint32_t OutData_KeyIndex[]);

/* Key pair generation */
rsip_ret_t r_rsip_wrapper_pf4_secp256r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf4_secp256k1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf4_brainpoolp256r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf9_secp384r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf9_brainpoolp384r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_p13(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_p7f(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_p4a(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);

rsip_ret_t r_rsip_wrapper_p2a(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_p2b(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_p3a(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
rsip_ret_t r_rsip_wrapper_p3b(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);

/* Key update */
rsip_ret_t r_rsip_wrapper_pad_aes128(uint32_t const InData_IV[],
                                     uint32_t const InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_aes192(uint32_t const InData_IV[],
                                     uint32_t const InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_aes256(uint32_t const InData_IV[],
                                     uint32_t const InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_xts_aes128(uint32_t const InData_IV[],
                                         uint32_t const InData_InstData[],
                                         uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_xts_aes256(uint32_t const InData_IV[],
                                         uint32_t const InData_InstData[],
                                         uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_chacha20(uint32_t const InData_IV[],
                                       uint32_t const InData_InstData[],
                                       uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp256r1_pub(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp256r1_priv(uint32_t const InData_IV[],
                                             uint32_t const InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp384r1_pub(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp384r1_priv(uint32_t const InData_IV[],
                                             uint32_t const InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp521r1_pub(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp521r1_priv(uint32_t const InData_IV[],
                                             uint32_t const InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_brainpoolp256r1_pub(uint32_t const InData_IV[],
                                                  uint32_t const InData_InstData[],
                                                  uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_brainpoolp256r1_priv(uint32_t const InData_IV[],
                                                   uint32_t const InData_InstData[],
                                                   uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_brainpoolp384r1_pub(uint32_t const InData_IV[],
                                                  uint32_t const InData_InstData[],
                                                  uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_brainpoolp384r1_priv(uint32_t const InData_IV[],
                                                   uint32_t const InData_InstData[],
                                                   uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_brainpoolp512r1_pub(uint32_t const InData_IV[],
                                                  uint32_t const InData_InstData[],
                                                  uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_brainpoolp512r1_priv(uint32_t const InData_IV[],
                                                   uint32_t const InData_InstData[],
                                                   uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp256k1_pub(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_secp256k1_priv(uint32_t const InData_IV[],
                                             uint32_t const InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_edwards25519_pub(uint32_t const InData_IV[],
                                               uint32_t const InData_InstData[],
                                               uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_edwards25519_priv(uint32_t const InData_IV[],
                                                uint32_t const InData_InstData[],
                                                uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa1024_pub(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa1024_priv(uint32_t const InData_IV[],
                                           uint32_t const InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa2048_pub(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa2048_priv(uint32_t const InData_IV[],
                                           uint32_t const InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa3072_pub(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa3072_priv(uint32_t const InData_IV[],
                                           uint32_t const InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa4096_pub(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_rsa4096_priv(uint32_t const InData_IV[],
                                           uint32_t const InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha1(uint32_t const InData_IV[],
                                        uint32_t const InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha224(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha256(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha384(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha512(uint32_t const InData_IV[],
                                          uint32_t const InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha3_224(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha3_256(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha3_384(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pad_hmac_sha3_512(uint32_t const InData_IV[],
                                            uint32_t const InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);

/* RFC3394 AES key wrap */
rsip_ret_t r_rsip_wrapper_p8f_aes128(const uint32_t InData_KeyIndex[],
                                     const uint32_t InData_WrappedKeyType[],
                                     const uint32_t InData_WrappedKeyIndex[],
                                     uint32_t       OutData_Text[],
                                     uint32_t       KEY_INDEX_SIZE,
                                     uint32_t       WRAPPED_KEY_SIZE);

rsip_ret_t r_rsip_wrapper_p8f_aes256(const uint32_t InData_KeyIndex[],
                                     const uint32_t InData_WrappedKeyType[],
                                     const uint32_t InData_WrappedKeyIndex[],
                                     uint32_t       OutData_Text[],
                                     uint32_t       KEY_INDEX_SIZE,
                                     uint32_t       WRAPPED_KEY_SIZE);

rsip_ret_t r_rsip_wrapper_p90_aes128(const uint32_t InData_KeyIndex[],
                                     const uint32_t InData_WrappedKeyType[],
                                     const uint32_t InData_Text[],
                                     uint32_t       OutData_KeyIndex[],
                                     uint32_t       WRAPPED_KEY_SIZE,
                                     uint32_t       KEY_INDEX_SIZE);

rsip_ret_t r_rsip_wrapper_p90_aes256(const uint32_t InData_KeyIndex[],
                                     const uint32_t InData_WrappedKeyType[],
                                     const uint32_t InData_Text[],
                                     uint32_t       OutData_KeyIndex[],
                                     uint32_t       WRAPPED_KEY_SIZE,
                                     uint32_t       KEY_INDEX_SIZE);

/* AES-ECB/CBC/CTR */
rsip_ret_t r_rsip_wrapper_p48i_ecb_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p48i_ecb_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p48i_cbc_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p48i_cbc_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p48i_cbc_enc_wrapped_iv(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p48i_cbc_dec_wrapped_iv(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p48i_ctr(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p89i_ecb_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p89i_ecb_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p89i_cbc_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p89i_cbc_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p89i_ctr(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_ecb_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_ecb_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_cbc_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_cbc_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_cbc_enc_wrapped_iv(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_cbc_dec_wrapped_iv(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
rsip_ret_t r_rsip_wrapper_p50i_ctr(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);

/* AES-GCM */
rsip_ret_t r_rsip_wrapper_p29i_plain_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p29i_wrapped_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p32i_plain_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p32i_wrapped_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p34i_plain_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p34i_wrapped_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p36i_plain_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);
rsip_ret_t r_rsip_wrapper_p36i_wrapped_iv(const uint32_t * InData_KeyIndex, const uint32_t * InData_IV);

/* AES-CCM */
rsip_ret_t r_rsip_wrapper_p95i(const uint32_t * InData_KeyIndex,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_IV,
                               const uint32_t * InData_Header,
                               uint32_t         Header_Len);
rsip_ret_t r_rsip_wrapper_p98i(const uint32_t * InData_KeyIndex,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_MACLength,
                               const uint32_t * InData_IV,
                               const uint32_t * InData_Header,
                               uint32_t         Header_Len);
rsip_ret_t r_rsip_wrapper_p95f(const uint32_t * InData_Text,
                               const uint32_t * InData_TextLen,
                               uint32_t       * OutData_Text,
                               uint32_t       * OutData_MAC);
rsip_ret_t r_rsip_wrapper_p98f(const uint32_t * InData_Text,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_MAC,
                               const uint32_t * InData_MACLength,
                               uint32_t       * OutData_Text);
rsip_ret_t r_rsip_wrapper_pa7i(const uint32_t * InData_KeyIndex,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_IV,
                               const uint32_t * InData_Header,
                               uint32_t         Header_Len);
rsip_ret_t r_rsip_wrapper_pb0i(const uint32_t * InData_KeyIndex,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_MACLength,
                               const uint32_t * InData_IV,
                               const uint32_t * InData_Header,
                               uint32_t         Header_Len);
rsip_ret_t r_rsip_wrapper_pa1i(const uint32_t * InData_KeyIndex,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_IV,
                               const uint32_t * InData_Header,
                               uint32_t         Header_Len);
rsip_ret_t r_rsip_wrapper_pa4i(const uint32_t * InData_KeyIndex,
                               const uint32_t * InData_TextLen,
                               const uint32_t * InData_MACLength,
                               const uint32_t * InData_IV,
                               const uint32_t * InData_Header,
                               uint32_t         Header_Len);

/* AES-CMAC */
rsip_ret_t r_rsip_wrapper_p41f_gen(const uint32_t InData_Text[], uint32_t OutData_DataT[], const uint32_t all_msg_len);
rsip_ret_t r_rsip_wrapper_p87f_gen(const uint32_t InData_Text[], uint32_t OutData_DataT[], const uint32_t all_msg_len);
rsip_ret_t r_rsip_wrapper_p44f_gen(const uint32_t InData_Text[], uint32_t OutData_DataT[], const uint32_t all_msg_len);
rsip_ret_t r_rsip_wrapper_p41f_veri(const uint32_t InData_Text[],
                                    const uint32_t InData_DataT[],
                                    const uint32_t InData_DataTLen[],
                                    const uint32_t all_msg_len);
rsip_ret_t r_rsip_wrapper_p87f_veri(const uint32_t InData_Text[],
                                    const uint32_t InData_DataT[],
                                    const uint32_t InData_DataTLen[],
                                    const uint32_t all_msg_len);
rsip_ret_t r_rsip_wrapper_p44f_veri(const uint32_t InData_Text[],
                                    const uint32_t InData_DataT[],
                                    const uint32_t InData_DataTLen[],
                                    const uint32_t all_msg_len);

/* ChaCha20-Poly1305 */
rsip_ret_t r_rsip_wrapper_p97i_enc(const uint32_t * InData_KeyIndex,
                                   const uint32_t * InData_Nonce,
                                   const uint32_t * InData_TextLen,
                                   const uint32_t * InData_DataALen);
rsip_ret_t r_rsip_wrapper_p97i_dec(const uint32_t * InData_KeyIndex,
                                   const uint32_t * InData_Nonce,
                                   const uint32_t * InData_TextLen,
                                   const uint32_t * InData_DataALen);
rsip_ret_t r_rsip_wrapper_p97r_enc(const uint32_t * InData_KeyIndex,
                                   const uint32_t * InData_Nonce,
                                   const uint32_t * InData_State);
rsip_ret_t r_rsip_wrapper_p97r_dec(const uint32_t * InData_KeyIndex,
                                   const uint32_t * InData_Nonce,
                                   const uint32_t * InData_State);

/* ECDSA */
rsip_ret_t r_rsip_wrapper_pf0_secp256r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf1_secp256r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        const uint32_t InData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf0_brainpoolp256r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf1_brainpoolp256r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              const uint32_t InData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf0_secp256k1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf1_secp256k1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        const uint32_t InData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf5_secp384r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf6_secp384r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        const uint32_t InData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf5_brainpoolp384r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_pf6_brainpoolp384r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              const uint32_t InData_Signature[]);
rsip_ret_t r_rsip_wrapper_p11(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_MsgDgst[],
                              uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_p12(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_MsgDgst[],
                              const uint32_t InData_Signature[]);
rsip_ret_t r_rsip_wrapper_p7d(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_MsgDgst[],
                              uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_p7e(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_MsgDgst[],
                              const uint32_t InData_Signature[]);

/* EdDSA */
rsip_ret_t r_rsip_wrapper_p4c(const uint32_t InData_PrivKeyIndex[],
                              const uint32_t InData_PubKeyIndex[],
                              const uint32_t InData_Msg[],
                              const uint64_t InData_MsgLen,
                              uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_p4d(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_Msg[],
                              const uint64_t InData_MsgLen,
                              const uint32_t InData_Signature[]);

/* ECDH */
rsip_ret_t r_rsip_wrapper_pe2_wrapped_secp256r1(const uint32_t InData_PubKey[],
                                                const uint32_t InData_KeyIndex[],
                                                uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_pe2_plain_secp256r1(const uint32_t InData_PubKey[],
                                              const uint32_t InData_KeyIndex[],
                                              uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_pe2_wrapped_brainpoolp256r1(const uint32_t InData_PubKey[],
                                                      const uint32_t InData_KeyIndex[],
                                                      uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_pe2_plain_brainpoolp256r1(const uint32_t InData_PubKey[],
                                                    const uint32_t InData_KeyIndex[],
                                                    uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p4e_wrapped_secp384r1(const uint32_t InData_PubKey[],
                                                const uint32_t InData_KeyIndex[],
                                                uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p4e_plain_secp384r1(const uint32_t InData_PubKey[],
                                              const uint32_t InData_KeyIndex[],
                                              uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p4e_wrapped_brainpoolp384r1(const uint32_t InData_PubKey[],
                                                      const uint32_t InData_KeyIndex[],
                                                      uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p4e_plain_brainpoolp384r1(const uint32_t InData_PubKey[],
                                                    const uint32_t InData_KeyIndex[],
                                                    uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p4f_wrapped_secp521r1(const uint32_t InData_PubKey[],
                                                const uint32_t InData_KeyIndex[],
                                                uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p4f_plain_secp521r1(const uint32_t InData_PubKey[],
                                              const uint32_t InData_KeyIndex[],
                                              uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p5e_wrapped_brainpoolp512r1(const uint32_t InData_PubKey[],
                                                      const uint32_t InData_KeyIndex[],
                                                      uint32_t       OutData_EncSecret[]);
rsip_ret_t r_rsip_wrapper_p5e_plain_brainpoolp512r1(const uint32_t InData_PubKey[],
                                                    const uint32_t InData_KeyIndex[],
                                                    uint32_t       OutData_EncSecret[]);

/* Key injection */
rsip_ret_t r_rsip_wrapper_pac_aes128(const uint32_t InData_SharedKeyNum[],
                                     const uint32_t InData_SharedKeyIndex[],
                                     const uint32_t InData_SessionKey[],
                                     const uint32_t InData_IV[],
                                     const uint32_t InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_aes192(const uint32_t InData_SharedKeyNum[],
                                     const uint32_t InData_SharedKeyIndex[],
                                     const uint32_t InData_SessionKey[],
                                     const uint32_t InData_IV[],
                                     const uint32_t InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_aes256(const uint32_t InData_SharedKeyNum[],
                                     const uint32_t InData_SharedKeyIndex[],
                                     const uint32_t InData_SessionKey[],
                                     const uint32_t InData_IV[],
                                     const uint32_t InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_xts_aes128(const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_xts_aes256(const uint32_t InData_SharedKeyNum[],
                                         const uint32_t InData_SharedKeyIndex[],
                                         const uint32_t InData_SessionKey[],
                                         const uint32_t InData_IV[],
                                         const uint32_t InData_InstData[],
                                         uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_chacha20(const uint32_t InData_SharedKeyNum[],
                                       const uint32_t InData_SharedKeyIndex[],
                                       const uint32_t InData_SessionKey[],
                                       const uint32_t InData_IV[],
                                       const uint32_t InData_InstData[],
                                       uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp256r1_pub(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp256r1_priv(const uint32_t InData_SharedKeyNum[],
                                             const uint32_t InData_SharedKeyIndex[],
                                             const uint32_t InData_SessionKey[],
                                             const uint32_t InData_IV[],
                                             const uint32_t InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp384r1_pub(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp384r1_priv(const uint32_t InData_SharedKeyNum[],
                                             const uint32_t InData_SharedKeyIndex[],
                                             const uint32_t InData_SessionKey[],
                                             const uint32_t InData_IV[],
                                             const uint32_t InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp521r1_pub(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp521r1_priv(const uint32_t InData_SharedKeyNum[],
                                             const uint32_t InData_SharedKeyIndex[],
                                             const uint32_t InData_SessionKey[],
                                             const uint32_t InData_IV[],
                                             const uint32_t InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp256k1_pub(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_secp256k1_priv(const uint32_t InData_SharedKeyNum[],
                                             const uint32_t InData_SharedKeyIndex[],
                                             const uint32_t InData_SessionKey[],
                                             const uint32_t InData_IV[],
                                             const uint32_t InData_InstData[],
                                             uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_brainpoolp256r1_pub(const uint32_t InData_SharedKeyNum[],
                                                  const uint32_t InData_SharedKeyIndex[],
                                                  const uint32_t InData_SessionKey[],
                                                  const uint32_t InData_IV[],
                                                  const uint32_t InData_InstData[],
                                                  uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_brainpoolp256r1_priv(const uint32_t InData_SharedKeyNum[],
                                                   const uint32_t InData_SharedKeyIndex[],
                                                   const uint32_t InData_SessionKey[],
                                                   const uint32_t InData_IV[],
                                                   const uint32_t InData_InstData[],
                                                   uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_brainpoolp384r1_pub(const uint32_t InData_SharedKeyNum[],
                                                  const uint32_t InData_SharedKeyIndex[],
                                                  const uint32_t InData_SessionKey[],
                                                  const uint32_t InData_IV[],
                                                  const uint32_t InData_InstData[],
                                                  uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_brainpoolp384r1_priv(const uint32_t InData_SharedKeyNum[],
                                                   const uint32_t InData_SharedKeyIndex[],
                                                   const uint32_t InData_SessionKey[],
                                                   const uint32_t InData_IV[],
                                                   const uint32_t InData_InstData[],
                                                   uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_brainpoolp512r1_pub(const uint32_t InData_SharedKeyNum[],
                                                  const uint32_t InData_SharedKeyIndex[],
                                                  const uint32_t InData_SessionKey[],
                                                  const uint32_t InData_IV[],
                                                  const uint32_t InData_InstData[],
                                                  uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_brainpoolp512r1_priv(const uint32_t InData_SharedKeyNum[],
                                                   const uint32_t InData_SharedKeyIndex[],
                                                   const uint32_t InData_SessionKey[],
                                                   const uint32_t InData_IV[],
                                                   const uint32_t InData_InstData[],
                                                   uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_edwards25519_pub(const uint32_t InData_SharedKeyNum[],
                                               const uint32_t InData_SharedKeyIndex[],
                                               const uint32_t InData_SessionKey[],
                                               const uint32_t InData_IV[],
                                               const uint32_t InData_InstData[],
                                               uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_edwards25519_priv(const uint32_t InData_SharedKeyNum[],
                                                const uint32_t InData_SharedKeyIndex[],
                                                const uint32_t InData_SessionKey[],
                                                const uint32_t InData_IV[],
                                                const uint32_t InData_InstData[],
                                                uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa1024_pub(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa1024_priv(const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa2048_pub(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa2048_priv(const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa3072_pub(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa3072_priv(const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa4096_pub(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_rsa4096_priv(const uint32_t InData_SharedKeyNum[],
                                           const uint32_t InData_SharedKeyIndex[],
                                           const uint32_t InData_SessionKey[],
                                           const uint32_t InData_IV[],
                                           const uint32_t InData_InstData[],
                                           uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha1(const uint32_t InData_SharedKeyNum[],
                                        const uint32_t InData_SharedKeyIndex[],
                                        const uint32_t InData_SessionKey[],
                                        const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha224(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha256(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha384(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha512(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha3_224(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha3_256(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha3_384(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_hmac_sha3_512(const uint32_t InData_SharedKeyNum[],
                                            const uint32_t InData_SharedKeyIndex[],
                                            const uint32_t InData_SessionKey[],
                                            const uint32_t InData_IV[],
                                            const uint32_t InData_InstData[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pac_misc_kuk(const uint32_t InData_SharedKeyNum[],
                                       const uint32_t InData_SharedKeyIndex[],
                                       const uint32_t InData_SessionKey[],
                                       const uint32_t InData_IV[],
                                       const uint32_t InData_InstData[],
                                       uint32_t       OutData_KeyIndex[]);

/* Root certificate key import */
rsip_ret_t r_rsip_wrapper_pe0_secp256r1(const uint32_t InData_RootCertificate[],
                                        const uint32_t InData_RootCertificateInfo[],
                                        const uint32_t InData_RootCertificatePubKey[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe0_rsa2048(const uint32_t InData_RootCertificate[],
                                      const uint32_t InData_RootCertificateInfo[],
                                      const uint32_t InData_RootCertificatePubKey[],
                                      uint32_t       OutData_KeyIndex[]);

/* PKI */
rsip_ret_t r_rsip_wrapper_pe1_secp256r1(const uint32_t InData_HashType[],
                                        const uint32_t InData_Certificate[],
                                        const uint32_t InData_CertificateLength[],
                                        const uint32_t InData_CertificatePubKey[],
                                        const uint32_t InData_EncCertificateInfo[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe1_secp384r1(const uint32_t InData_HashType[],
                                        const uint32_t InData_Certificate[],
                                        const uint32_t InData_CertificateLength[],
                                        const uint32_t InData_CertificatePubKey[],
                                        const uint32_t InData_EncCertificateInfo[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe1_secp521r1(const uint32_t InData_HashType[],
                                        const uint32_t InData_Certificate[],
                                        const uint32_t InData_CertificateLength[],
                                        const uint32_t InData_CertificatePubKey[],
                                        const uint32_t InData_EncCertificateInfo[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe1_brainpoolp256r1(const uint32_t InData_HashType[],
                                              const uint32_t InData_Certificate[],
                                              const uint32_t InData_CertificateLength[],
                                              const uint32_t InData_CertificatePubKey[],
                                              const uint32_t InData_EncCertificateInfo[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe1_brainpoolp384r1(const uint32_t InData_HashType[],
                                              const uint32_t InData_Certificate[],
                                              const uint32_t InData_CertificateLength[],
                                              const uint32_t InData_CertificatePubKey[],
                                              const uint32_t InData_EncCertificateInfo[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe1_brainpoolp512r1(const uint32_t InData_HashType[],
                                              const uint32_t InData_Certificate[],
                                              const uint32_t InData_CertificateLength[],
                                              const uint32_t InData_CertificatePubKey[],
                                              const uint32_t InData_EncCertificateInfo[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe1_rsa2048(const uint32_t InData_HashType[],
                                      const uint32_t InData_Certificate[],
                                      const uint32_t InData_CertificateLength[],
                                      const uint32_t InData_CertificatePubKey[],
                                      const uint32_t InData_EncCertificateInfo[],
                                      uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_peei_secp256r1(const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[]);

rsip_ret_t r_rsip_wrapper_peei_brainpoolp256r1(const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[]);

rsip_ret_t r_rsip_wrapper_p51i_secp384r1(const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[]);

rsip_ret_t r_rsip_wrapper_p51i_brainpoolp384r1(const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[]);

rsip_ret_t r_rsip_wrapper_p52i_secp521r1(const uint32_t InData_KeyIndex[],
                                         const uint32_t InData_MsgDgst[],
                                         const uint32_t InData_Signature[]);

rsip_ret_t r_rsip_wrapper_p5fi_brainpoolp512r1(const uint32_t InData_KeyIndex[],
                                               const uint32_t InData_MsgDgst[],
                                               const uint32_t InData_Signature[]);

/* KDF */
rsip_ret_t r_rsip_wrapper_pe3_sha256(const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[]);
rsip_ret_t r_rsip_wrapper_pe3_sha384(const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[]);
rsip_ret_t r_rsip_wrapper_pe3_sha512_secp521r1(const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[]);
rsip_ret_t r_rsip_wrapper_pe3_sha512_brainpoolp512r1(const uint32_t InData_EncSecret[], uint32_t OutData_EncMsg[]);
rsip_ret_t r_rsip_wrapper_pe4_sha256(const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe4_sha384(const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe4_sha512_secp521r1(const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe4_sha512_brainpoolp512r1(const uint32_t InData_EncSecret[], uint32_t OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe6_sha256(const uint32_t InData_KDFInfo[],
                                     const uint32_t InData_KDFInfo_Count[],
                                     const uint32_t InData_OutDataLength[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe6_sha384(const uint32_t InData_KDFInfo[],
                                     const uint32_t InData_KDFInfo_Count[],
                                     const uint32_t InData_OutDataLength[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe6_sha512(const uint32_t InData_KDFInfo[],
                                     const uint32_t InData_KDFInfo_Count[],
                                     const uint32_t InData_OutDataLength[],
                                     uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_aes128(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_aes256(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha1(const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha256(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha384(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_hmac_sha512(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_iv_aes(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            const uint32_t InData_SeqNum[],
                                            uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_iv_tls12(const uint32_t InData_KDFInfo[],
                                              const uint32_t InData_KDFInfo_Count[],
                                              const uint32_t InData_OutDataLocation[],
                                              const uint32_t InData_SeqNum[],
                                              uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha256_iv_tls13(const uint32_t InData_KDFInfo[],
                                              const uint32_t InData_KDFInfo_Count[],
                                              const uint32_t InData_OutDataLocation[],
                                              const uint32_t InData_SeqNum[],
                                              uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_aes128(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_aes256(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha1(const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha256(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha384(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_hmac_sha512(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_iv_aes(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            const uint32_t InData_SeqNum[],
                                            uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_iv_tls12(const uint32_t InData_KDFInfo[],
                                              const uint32_t InData_KDFInfo_Count[],
                                              const uint32_t InData_OutDataLocation[],
                                              const uint32_t InData_SeqNum[],
                                              uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha384_iv_tls13(const uint32_t InData_KDFInfo[],
                                              const uint32_t InData_KDFInfo_Count[],
                                              const uint32_t InData_OutDataLocation[],
                                              const uint32_t InData_SeqNum[],
                                              uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_aes128(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_aes256(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha1(const uint32_t InData_KDFInfo[],
                                               const uint32_t InData_KDFInfo_Count[],
                                               const uint32_t InData_OutDataLocation[],
                                               uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha256(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha384(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_hmac_sha512(const uint32_t InData_KDFInfo[],
                                                 const uint32_t InData_KDFInfo_Count[],
                                                 const uint32_t InData_OutDataLocation[],
                                                 uint32_t       OutData_HMACKeyIndex[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_iv_aes(const uint32_t InData_KDFInfo[],
                                            const uint32_t InData_KDFInfo_Count[],
                                            const uint32_t InData_OutDataLocation[],
                                            const uint32_t InData_SeqNum[],
                                            uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_iv_tls12(const uint32_t InData_KDFInfo[],
                                              const uint32_t InData_KDFInfo_Count[],
                                              const uint32_t InData_OutDataLocation[],
                                              const uint32_t InData_SeqNum[],
                                              uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe7_sha512_iv_tls13(const uint32_t InData_KDFInfo[],
                                              const uint32_t InData_KDFInfo_Count[],
                                              const uint32_t InData_OutDataLocation[],
                                              const uint32_t InData_SeqNum[],
                                              uint32_t       OutData_EncIV[]);
rsip_ret_t r_rsip_wrapper_pe9_sha256_client(const uint32_t InData_Hash[],
                                            const uint32_t InData_KeyIndex[],
                                            uint32_t       OutData_Verify_data[]);
rsip_ret_t r_rsip_wrapper_pe9_sha256_server(const uint32_t InData_Hash[],
                                            const uint32_t InData_KeyIndex[],
                                            uint32_t       OutData_Verify_data[]);

/* Password hash generation */
rsip_ret_t r_rsip_wrapper_p15_jtag_level1(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_EncAuthData[],
                                          uint32_t       OutData_Hash[]);
rsip_ret_t r_rsip_wrapper_p15_jtag_level2(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_EncAuthData[],
                                          uint32_t       OutData_Hash[]);
rsip_ret_t r_rsip_wrapper_p15_sci_usb(const uint32_t InData_SharedKeyNum[],
                                      const uint32_t InData_SharedKeyIndex[],
                                      const uint32_t InData_SessionKey[],
                                      const uint32_t InData_IV[],
                                      const uint32_t InData_EncAuthData[],
                                      uint32_t       OutData_Hash[]);

/* OTF */
rsip_ret_t r_rsip_wrapper_pba_ch0(const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);
rsip_ret_t r_rsip_wrapper_pba_ch1(const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);
rsip_ret_t r_rsip_wrapper_pba_ch2(const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);
rsip_ret_t r_rsip_wrapper_pbc_ch0(const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);
rsip_ret_t r_rsip_wrapper_pbc_ch1(const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);
rsip_ret_t r_rsip_wrapper_pbc_ch2(const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[]);

#endif                                 /* R_RSIP_WRAPPER_H */
