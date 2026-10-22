/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RSIP_WRAPPER_H
#define R_RSIP_WARPPER_H

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
#define RSIP_PRV_FUNC_NAME_RANDOM_NUMBER_GENERATE                       r_rsip_p20

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_128                         r_rsip_p07
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_128                         r_rsip_p19
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_128_KEY_WRAP                     r_rsip_wrapper_p8f_aes128
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_128_KEY_UNWRAP                   r_rsip_wrapper_p90_aes128

#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_128                  r_rsip_wrapper_p48i_ecb_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_128                  r_rsip_wrapper_p48i_ecb_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_128                  r_rsip_wrapper_p48i_cbc_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_128                  r_rsip_wrapper_p48i_cbc_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_128_WRAPPED_IV       NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_128_WRAPPED_IV       NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_128                      r_rsip_wrapper_p48i_ctr
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_128                        r_rsip_p48u
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_128                         r_rsip_p48f

#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_128                         r_rsip_p29i
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_128_WRAPPED_IV              NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_128                   r_rsip_p29a
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_128            r_rsip_p29t
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_128                       r_rsip_p29u
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_128                        r_rsip_p29f
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_128                         r_rsip_p32i
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_128_WRAPPED_IV              NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_128                   r_rsip_p32a
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_128            r_rsip_p32t
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_128                       r_rsip_p32u
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_128                        r_rsip_p32f

#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_INIT_128                         r_rsip_wrapper_p95i
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_UPDATE_128                       r_rsip_p95u
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_FINAL_128                        r_rsip_wrapper_p95f
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_INIT_128                         r_rsip_wrapper_p98i
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_UPDATE_128                       r_rsip_p98u
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_FINAL_128                        r_rsip_wrapper_p98f

#define RSIP_PRV_FUNC_NAME_AES_CMAC_INIT_128                            r_rsip_p41i
#define RSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_128                          r_rsip_p41u
#define RSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_128                  r_rsip_wrapper_p41f_gen
#define RSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_128                    r_rsip_wrapper_p41f_veri

#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_0_AES_128                        NULL
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_1_AES_128                        NULL

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_192                         r_rsip_p86
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_192                         r_rsip_p88
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_192_KEY_WRAP                     NULL
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_192_KEY_UNWRAP                   NULL

#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_192                  r_rsip_wrapper_p89i_ecb_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_192                  r_rsip_wrapper_p89i_ecb_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_192                  r_rsip_wrapper_p89i_cbc_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_192                  r_rsip_wrapper_p89i_cbc_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_192_WRAPPED_IV       NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_192_WRAPPED_IV       NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_192                      r_rsip_wrapper_p89i_ctr
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_192                        r_rsip_p89u
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_192                         r_rsip_p89f

#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_192                         r_rsip_p83i
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_192_WRAPPED_IV              NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_192                   r_rsip_p83a
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_192            r_rsip_p83t
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_192                       r_rsip_p83u
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_192                        r_rsip_p83f
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_192                         r_rsip_p85i
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_192_WRAPPED_IV              NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_192                   r_rsip_p85a
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_192            r_rsip_p85t
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_192                       r_rsip_p85u
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_192                        r_rsip_p85f

#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_INIT_192                         r_rsip_wrapper_pa7i
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_UPDATE_192                       r_rsip_pa7u
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_FINAL_192                        r_rsip_pa7f
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_INIT_192                         r_rsip_wrapper_pb0i
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_UPDATE_192                       r_rsip_pb0u
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_FINAL_192                        r_rsip_pb0f

#define RSIP_PRV_FUNC_NAME_AES_CMAC_INIT_192                            r_rsip_p87i
#define RSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_192                          r_rsip_p87u
#define RSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_192                  r_rsip_wrapper_p87f_gen
#define RSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_192                    r_rsip_wrapper_p87f_veri

#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_0_AES_192                        NULL
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_1_AES_192                        NULL

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_256                         r_rsip_p08
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_256                         r_rsip_p1c
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_256_KEY_WRAP                     r_rsip_wrapper_p8f_aes256
#define RSIP_PRV_FUNC_NAME_RFC3394_AES_256_KEY_UNWRAP                   r_rsip_wrapper_p90_aes256

#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_256                  r_rsip_wrapper_p50i_ecb_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_256                  r_rsip_wrapper_p50i_ecb_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_256                  r_rsip_wrapper_p50i_cbc_enc
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_256                  r_rsip_wrapper_p50i_cbc_dec
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_256_WRAPPED_IV       NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_256_WRAPPED_IV       NULL
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_256                      r_rsip_wrapper_p50i_ctr
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_256                        r_rsip_p50u
#define RSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_256                         r_rsip_p50f

#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_256                         r_rsip_p34i
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_256_WRAPPED_IV              NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_256                   r_rsip_p34a
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_256            r_rsip_p34t
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_256                       r_rsip_p34u
#define RSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_256                        r_rsip_p34f
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_256                         r_rsip_p36i
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_256_WRAPPED_IV              NULL
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_256                   r_rsip_p36a
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_256            r_rsip_p36t
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_256                       r_rsip_p36u
#define RSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_256                        r_rsip_p36f

#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_INIT_256                         r_rsip_wrapper_pa1i
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_UPDATE_256                       r_rsip_pa1u
#define RSIP_PRV_FUNC_NAME_AES_CCM_ENC_FINAL_256                        r_rsip_pa1f
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_INIT_256                         r_rsip_wrapper_pa4i
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_UPDATE_256                       r_rsip_pa4u
#define RSIP_PRV_FUNC_NAME_AES_CCM_DEC_FINAL_256                        r_rsip_pa4f

#define RSIP_PRV_FUNC_NAME_AES_CMAC_INIT_256                            r_rsip_p44i
#define RSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_256                          r_rsip_p44u
#define RSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_256                  r_rsip_wrapper_p44f_gen
#define RSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_256                    r_rsip_wrapper_p44f_veri

#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_0_AES_256                        NULL
#define RSIP_PRV_FUNC_NAME_OTF_CHANNEL_1_AES_256                        NULL

#define RSIP_PRV_FUNC_NAME_GHASH_COMPUTE                                r_rsip_p21

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_XTS_AES_128                     r_rsip_p16
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_XTS_AES_128                     r_rsip_p1b

#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_INIT_128                         r_rsip_pb3i
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_UPDATE_128                       r_rsip_pb3u
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_FINAL_128                        r_rsip_pb3f
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_INIT_128                         r_rsip_pb6i
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_UPDATE_128                       r_rsip_pb6u
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_FINAL_128                        r_rsip_pb6f

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_XTS_AES_256                     r_rsip_p17
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_XTS_AES_256                     r_rsip_p1d

#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_INIT_256                         r_rsip_pb9i
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_UPDATE_256                       r_rsip_pb9u
#define RSIP_PRV_FUNC_NAME_XTS_AES_ENC_FINAL_256                        r_rsip_pb9f
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_INIT_256                         r_rsip_pc2i
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_UPDATE_256                       r_rsip_pc2u
#define RSIP_PRV_FUNC_NAME_XTS_AES_DEC_FINAL_256                        r_rsip_pc2f

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP256R1              r_rsip_wrapper_pf4_secp256r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256R1_PUBLIC            r_rsip_wrapper_p2c_secp256r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256R1_PRIVATE           r_rsip_wrapper_p1e_secp256r1

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP256R1                         r_rsip_wrapper_pf0_secp256r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP256R1                       r_rsip_wrapper_pf1_secp256r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP256R1                       NULL
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP256R1                         NULL

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP256R1              NULL
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP256R1             NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP256R1            NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP384R1              r_rsip_wrapper_pf9_secp384r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP384R1_PUBLIC            r_rsip_wrapper_p2d_secp384r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP384R1_PRIVATE           r_rsip_wrapper_p2e_secp384r1

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP384R1                         r_rsip_wrapper_pf5_secp384r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP384R1                       r_rsip_wrapper_pf6_secp384r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP384R1                       NULL
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP384R1                         NULL

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP384R1              NULL
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP384R1             NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP384R1            NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP521R1              r_rsip_wrapper_p13
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP521R1_PUBLIC            r_rsip_p8c
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP521R1_PRIVATE           r_rsip_p8d

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP521R1                         r_rsip_wrapper_p11
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP521R1                       r_rsip_wrapper_p12

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP521R1                       NULL
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP521R1                         NULL

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP521R1              NULL
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP521R1             NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP521R1            NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP256R1        r_rsip_wrapper_pf4_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP256R1_PUBLIC      r_rsip_wrapper_p2c_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP256R1_PRIVATE     r_rsip_wrapper_p1e_brainpoolp256r1

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP256R1                   r_rsip_wrapper_pf0_brainpoolp256r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP256R1                 r_rsip_wrapper_pf1_brainpoolp256r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP256R1                 NULL
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP256R1                   NULL

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP256R1        NULL
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP256R1       NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP256R1      NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP384R1        r_rsip_wrapper_pf9_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP384R1_PUBLIC      r_rsip_wrapper_p2d_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP384R1_PRIVATE     r_rsip_wrapper_p2e_brainpoolp384r1

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP384R1                   r_rsip_wrapper_pf5_brainpoolp384r1
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP384R1                 r_rsip_wrapper_pf6_brainpoolp384r1

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP384R1                 NULL
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP384R1                   NULL

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP384R1        NULL
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP384R1       NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP384R1      NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP512R1        r_rsip_wrapper_p7f
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP512R1_PUBLIC      r_rsip_p8a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP512R1_PRIVATE     r_rsip_p8b

#define RSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP512R1                   r_rsip_wrapper_p7d
#define RSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP512R1                 r_rsip_wrapper_p7e

#define RSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP512R1                 NULL
#define RSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP512R1                   NULL

#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP512R1        NULL
#define RSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP512R1       NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP512R1      NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_EDWARDS25519           r_rsip_wrapper_p4a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_EDWARDS25519_PUBLIC         r_rsip_paa
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_EDWARDS25519_PRIVATE        r_rsip_pab

#define RSIP_PRV_FUNC_NAME_EDDSA_SIGN_EDWARDS25519                      r_rsip_wrapper_p4c
#define RSIP_PRV_FUNC_NAME_EDDSA_VERIFY_EDWARDS25519                    r_rsip_wrapper_p4d

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_1024                   r_rsip_wrapper_p2a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_1024_PUBLIC                 r_rsip_p0b
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_1024_PRIVATE                r_rsip_p0c

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_1024                             r_rsip_p53
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_1024                             r_rsip_p54

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_2048                   r_rsip_wrapper_p2b
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_2048_PUBLIC                 r_rsip_p0d
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_2048_PRIVATE                r_rsip_p0e

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_2048                             r_rsip_p56
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_2048                             r_rsip_p57

#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_INIT_2048                     NULL
#define RSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_FINAL_2048                    NULL
#define RSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_RSA_2048                 NULL

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_3072                   r_rsip_wrapper_p3a
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_3072_PUBLIC                 r_rsip_p38
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_3072_PRIVATE                r_rsip_p9d

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_3072                             r_rsip_p79
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_3072                             r_rsip_p7a

#define RSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_4096                   r_rsip_wrapper_p3b
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_4096_PUBLIC                 r_rsip_p9e
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_4096_PRIVATE                r_rsip_p9f

#define RSIP_PRV_FUNC_NAME_RSA_ENCRYPT_4096                             r_rsip_p7b
#define RSIP_PRV_FUNC_NAME_RSA_DECRYPT_4096                             r_rsip_p7c

#define RSIP_PRV_FUNC_NAME_SHA1SHA2_INIT                                r_rsip_p70i
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_RESUME                              r_rsip_p70r
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_UPDATE                              r_rsip_p70u
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_SUSPEND                             r_rsip_p70s
#define RSIP_PRV_FUNC_NAME_SHA1SHA2_FINAL                               r_rsip_p70f

#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_INIT                           r_rsip_p75i
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_RESUME                         r_rsip_p75r
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_UPDATE                         r_rsip_p75u
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_SUSPEND                        r_rsip_p75s
#define RSIP_PRV_FUNC_NAME_HMAC_SHA1SHA2_FINAL                          r_rsip_p75f

#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_INIT                       NULL
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_RESUME                     NULL
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_ENC_UPDATE                 NULL
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_UPDATE                     NULL
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_SUSPEND                    NULL
#define RSIP_PRV_FUNC_NAME_KDF_HMAC_SHA1SHA2_FINAL                      NULL

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA1                       r_rsip_p6d
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA1                       r_rsip_wrapper_p0f_hmac_sha1

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA224                     r_rsip_p6e
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA224                     r_rsip_wrapper_p0f_hmac_sha224

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA256                     r_rsip_p6f
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA256                     r_rsip_wrapper_p0f_hmac_sha256

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA384                     r_rsip_p3c
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA384                     r_rsip_pa8

#define RSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA512                     r_rsip_p3d
#define RSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA512                     r_rsip_pa9

#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_KEY_IMPORT_SHA256            NULL
#define RSIP_PRV_FUNC_NAME_KDF_ECDH_SECRET_MSG_WRAP_SHA256              NULL
#define RSIP_PRV_FUNC_NAME_KDF_MAC_KEY_IMPORT_SHA256                    NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_AES_128        NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_AES_256        NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA1      NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA256    NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA384    NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_KEY_IMPORT_SHA256_HMAC_SHA512    NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA256_AES               NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA256_TLS12             NULL
#define RSIP_PRV_FUNC_NAME_KDF_DERIVED_IV_WRAP_SHA256_TLS13             NULL

#define RSIP_PRV_PKI_HASH_TYPE_SHA1                                     (0U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA224                                   (0U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA256                                   (1U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA384                                   (4U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA512                                   (5U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA512_224                               (2U)
#define RSIP_PRV_PKI_HASH_TYPE_SHA512_256                               (3U)

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* Key pair generation */
rsip_ret_t r_rsip_wrapper_pf4_secp256r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
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
rsip_ret_t r_rsip_wrapper_p2c_secp256r1(uint32_t const InData_IV[],
                                        uint32_t const InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p1e_secp256r1(uint32_t const InData_IV[],
                                        uint32_t const InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p2c_brainpoolp256r1(uint32_t const InData_IV[],
                                              uint32_t const InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p1e_brainpoolp256r1(uint32_t const InData_IV[],
                                              uint32_t const InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p2d_secp384r1(uint32_t const InData_IV[],
                                        uint32_t const InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p2e_secp384r1(uint32_t const InData_IV[],
                                        uint32_t const InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p2d_brainpoolp384r1(uint32_t const InData_IV[],
                                              uint32_t const InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p2e_brainpoolp384r1(uint32_t const InData_IV[],
                                              uint32_t const InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p0f_hmac_sha1(const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p0f_hmac_sha224(const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p0f_hmac_sha256(const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
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
rsip_ret_t r_rsip_wrapper_p50i_ctr(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);

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
rsip_ret_t r_rsip_wrapper_p4c(const uint32_t InData_PrivKeyIndex[],
                              const uint32_t InData_PubKeyIndex[],
                              const uint32_t InData_Msg[],
                              const uint64_t InData_MsgLen,
                              uint32_t       OutData_Signature[]);
rsip_ret_t r_rsip_wrapper_p4d(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_Msg[],
                              const uint64_t InData_MsgLen,
                              const uint32_t InData_Signature[]);

/* Key injection */
rsip_ret_t r_rsip_wrapper_pfa_secp256r1(const uint32_t InData_SharedKeyNum[],
                                        const uint32_t InData_SharedKeyIndex[],
                                        const uint32_t InData_SessionKey[],
                                        const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf3_secp256r1(const uint32_t InData_SharedKeyNum[],
                                        const uint32_t InData_SharedKeyIndex[],
                                        const uint32_t InData_SessionKey[],
                                        const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pfa_brainpoolp256r1(const uint32_t InData_SharedKeyNum[],
                                              const uint32_t InData_SharedKeyIndex[],
                                              const uint32_t InData_SessionKey[],
                                              const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf3_brainpoolp256r1(const uint32_t InData_SharedKeyNum[],
                                              const uint32_t InData_SharedKeyIndex[],
                                              const uint32_t InData_SessionKey[],
                                              const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf7_secp384r1(const uint32_t InData_SharedKeyNum[],
                                        const uint32_t InData_SharedKeyIndex[],
                                        const uint32_t InData_SessionKey[],
                                        const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf8_secp384r1(const uint32_t InData_SharedKeyNum[],
                                        const uint32_t InData_SharedKeyIndex[],
                                        const uint32_t InData_SessionKey[],
                                        const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf7_brainpoolp384r1(const uint32_t InData_SharedKeyNum[],
                                              const uint32_t InData_SharedKeyIndex[],
                                              const uint32_t InData_SessionKey[],
                                              const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_pf8_brainpoolp384r1(const uint32_t InData_SharedKeyNum[],
                                              const uint32_t InData_SharedKeyIndex[],
                                              const uint32_t InData_SessionKey[],
                                              const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p80_hmac_sha1(const uint32_t InData_SharedKeyNum[],
                                        const uint32_t InData_SharedKeyIndex[],
                                        const uint32_t InData_SessionKey[],
                                        const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p80_hmac_sha224(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);
rsip_ret_t r_rsip_wrapper_p80_hmac_sha256(const uint32_t InData_SharedKeyNum[],
                                          const uint32_t InData_SharedKeyIndex[],
                                          const uint32_t InData_SessionKey[],
                                          const uint32_t InData_IV[],
                                          const uint32_t InData_InstData[],
                                          uint32_t       OutData_KeyIndex[]);

#endif                                 /* R_RSIP_WRAPPER_H */
