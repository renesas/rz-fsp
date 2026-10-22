/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_WRAPPER_H
#define R_TSIP_WRAPPER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Primitive function names */
#define TSIP_PRV_FUNC_NAME_RANDOM_NUMBER_GENERATE                      r_tsip_p20

#define TSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_128                        r_tsip_p07
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_128                        r_tsip_p19
#define TSIP_PRV_FUNC_NAME_RFC3394_AES_128_KEY_WRAP                    NULL
#define TSIP_PRV_FUNC_NAME_RFC3394_AES_128_KEY_UNWRAP                  NULL

#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_128                 r_tsip_wrapper_p48i_ecb_enc
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_128                 r_tsip_wrapper_p48i_ecb_dec
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_128                 r_tsip_wrapper_p48i_cbc_enc
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_128                 r_tsip_wrapper_p48i_cbc_dec
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_128_WRAPPED_IV      NULL
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_128_WRAPPED_IV      NULL
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_128                     r_tsip_wrapper_p48i_ctr
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_128                       r_tsip_p48u
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_128                        r_tsip_p48f

#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_128                        r_tsip_p29i
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_128_WRAPPED_IV             NULL
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_128                  r_tsip_p29a
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_128           r_tsip_p29t
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_128                      r_tsip_p29u
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_128                       r_tsip_p29f
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_128                        r_tsip_p32i
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_128_WRAPPED_IV             NULL
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_128                  r_tsip_p32a
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_128           r_tsip_p32t
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_128                      r_tsip_p32u
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_128                       r_tsip_p32f

#define TSIP_PRV_FUNC_NAME_AES_CMAC_INIT_128                           r_tsip_p41i
#define TSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_128                         r_tsip_p41u
#define TSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_128                 r_tsip_wrapper_p41f_gen
#define TSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_128                   r_tsip_wrapper_p41f_veri

#define TSIP_PRV_FUNC_NAME_KEY_GENERATE_AES_256                        r_tsip_p08
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_AES_256                        r_tsip_p1c
#define TSIP_PRV_FUNC_NAME_RFC3394_AES_256_KEY_WRAP                    NULL
#define TSIP_PRV_FUNC_NAME_RFC3394_AES_256_KEY_UNWRAP                  NULL

#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_ENC_256                 r_tsip_wrapper_p50i_ecb_enc
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_ECB_DEC_256                 r_tsip_wrapper_p50i_ecb_dec
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_256                 r_tsip_wrapper_p50i_cbc_enc
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_256                 r_tsip_wrapper_p50i_cbc_dec
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_ENC_256_WRAPPED_IV      NULL
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CBC_DEC_256_WRAPPED_IV      NULL
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_INIT_CTR_256                     r_tsip_wrapper_p50i_ctr
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_UPDATE_256                       r_tsip_p50u
#define TSIP_PRV_FUNC_NAME_AES_CIPHER_FINAL_256                        r_tsip_p50f

#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_256                        r_tsip_p34i
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_INIT_256_WRAPPED_IV             NULL
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_AAD_256                  r_tsip_p34a
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_TRANSITION_256           r_tsip_p34t
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_UPDATE_256                      r_tsip_p34u
#define TSIP_PRV_FUNC_NAME_AES_GCM_ENC_FINAL_256                       r_tsip_p34f
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_256                        r_tsip_p36i
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_INIT_256_WRAPPED_IV             NULL
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_AAD_256                  r_tsip_p36a
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_TRANSITION_256           r_tsip_p36t
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_UPDATE_256                      r_tsip_p36u
#define TSIP_PRV_FUNC_NAME_AES_GCM_DEC_FINAL_256                       r_tsip_p36f

#define TSIP_PRV_FUNC_NAME_AES_CMAC_INIT_256                           r_tsip_p44i
#define TSIP_PRV_FUNC_NAME_AES_CMAC_UPDATE_256                         r_tsip_p44u
#define TSIP_PRV_FUNC_NAME_AES_CMAC_GENERATE_FINAL_256                 r_tsip_wrapper_p44f_gen
#define TSIP_PRV_FUNC_NAME_AES_CMAC_VERIFY_FINAL_256                   r_tsip_wrapper_p44f_veri

#define TSIP_PRV_FUNC_NAME_GHASH_COMPUTE                               r_tsip_p21

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP256R1             r_tsip_wrapper_pf4_secp256r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256R1_PUBLIC           r_tsip_wrapper_p2c_secp256r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP256R1_PRIVATE          r_tsip_wrapper_p1e_secp256r1

#define TSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP256R1                        r_tsip_wrapper_pf0_secp256r1
#define TSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP256R1                      r_tsip_wrapper_pf1_secp256r1

#define TSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP256R1                      NULL
#define TSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP256R1                        NULL

#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP256R1             NULL
#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP256R1            NULL
#define TSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP256R1           NULL

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_SECP384R1             r_tsip_wrapper_pf9_secp384r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP384R1_PUBLIC           r_tsip_wrapper_p2e_secp384r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_SECP384R1_PRIVATE          r_tsip_wrapper_p2d_secp384r1

#define TSIP_PRV_FUNC_NAME_ECDSA_SIGN_SECP384R1                        r_tsip_wrapper_pf5_secp384r1
#define TSIP_PRV_FUNC_NAME_ECDSA_VERIFY_SECP384R1                      r_tsip_wrapper_pf6_secp384r1

#define TSIP_PRV_FUNC_NAME_ECDH_WRAPPED_SECP384R1                      NULL
#define TSIP_PRV_FUNC_NAME_ECDH_PLAIN_SECP384R1                        NULL

#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_SECP384R1             NULL
#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_SECP384R1            NULL
#define TSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_SECP384R1           NULL

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP256R1       r_tsip_wrapper_pf4_brainpoolp256r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP256R1_PUBLIC     r_tsip_wrapper_p2c_brainpoolp256r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP256R1_PRIVATE    r_tsip_wrapper_p1e_brainpoolp256r1

#define TSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP256R1                  r_tsip_wrapper_pf0_brainpoolp256r1
#define TSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP256R1                r_tsip_wrapper_pf1_brainpoolp256r1

#define TSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP256R1                NULL
#define TSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP256R1                  NULL

#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP256R1       NULL
#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP256R1      NULL
#define TSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP256R1     NULL

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP384R1       r_tsip_wrapper_pf9_brainpoolp384r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP384R1_PUBLIC     r_tsip_wrapper_p2e_brainpoolp384r1
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP384R1_PRIVATE    r_tsip_wrapper_p2d_brainpoolp384r1

#define TSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP384R1                  r_tsip_wrapper_pf5_brainpoolp384r1
#define TSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP384R1                r_tsip_wrapper_pf6_brainpoolp384r1

#define TSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP384R1                NULL
#define TSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP384R1                  NULL

#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP384R1       NULL
#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP384R1      NULL
#define TSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP384R1     NULL

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_ECC_BRAINPOOLP512R1       r_tsip_wrapper_ped
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP512R1_PUBLIC     r_tsip_pee
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_ECC_BRAINPOOLP512R1_PRIVATE    r_tsip_pef

#define TSIP_PRV_FUNC_NAME_ECDSA_SIGN_BRAINPOOLP512R1                  r_tsip_wrapper_p7d
#define TSIP_PRV_FUNC_NAME_ECDSA_VERIFY_BRAINPOOLP512R1                r_tsip_wrapper_p7e

#define TSIP_PRV_FUNC_NAME_ECDH_WRAPPED_BRAINPOOLP512R1                NULL
#define TSIP_PRV_FUNC_NAME_ECDH_PLAIN_BRAINPOOLP512R1                  NULL

#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_INIT_BRAINPOOLP512R1       NULL
#define TSIP_PRV_FUNC_NAME_PKI_ECDSA_VERIFY_FINAL_BRAINPOOLP512R1      NULL
#define TSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_ECC_BRAINPOOLP512R1     NULL

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_1024                  r_tsip_wrapper_p2a
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_1024_PUBLIC                r_tsip_p0b
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_1024_PRIVATE               r_tsip_p0c

#define TSIP_PRV_FUNC_NAME_RSA_ENCRYPT_1024                            r_tsip_p53
#define TSIP_PRV_FUNC_NAME_RSA_DECRYPT_1024                            r_tsip_p54

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_2048                  r_tsip_wrapper_p2b
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_2048_PUBLIC                r_tsip_p0d
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_2048_PRIVATE               r_tsip_p0e

#define TSIP_PRV_FUNC_NAME_RSA_ENCRYPT_2048                            r_tsip_p56
#define TSIP_PRV_FUNC_NAME_RSA_DECRYPT_2048                            r_tsip_p57

#define TSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_INIT_2048                    NULL
#define TSIP_PRV_FUNC_NAME_PKI_RSA_VERIFY_FINAL_2048                   NULL
#define TSIP_PRV_FUNC_NAME_PKI_CERT_KEY_IMPORT_RSA_2048                NULL

#define TSIP_PRV_FUNC_NAME_KEY_PAIR_GENERATE_RSA_4096                  NULL
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_4096_PUBLIC                r_tsip_p9e
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_RSA_4096_PRIVATE               NULL

#define TSIP_PRV_FUNC_NAME_RSA_ENCRYPT_4096                            r_tsip_p7c
#define TSIP_PRV_FUNC_NAME_RSA_DECRYPT_4096                            NULL

#define TSIP_PRV_FUNC_NAME_SHA1                                        r_tsip_p71
#define TSIP_PRV_FUNC_NAME_SHA2                                        r_tsip_p72

#define TSIP_PRV_FUNC_NAME_HMAC_SHA1_INIT                              r_tsip_p73i
#define TSIP_PRV_FUNC_NAME_HMAC_SHA1_RESUME                            r_tsip_p73r
#define TSIP_PRV_FUNC_NAME_HMAC_SHA1_UPDATE                            r_tsip_p73u
#define TSIP_PRV_FUNC_NAME_HMAC_SHA1_SUSPEND                           r_tsip_p73s
#define TSIP_PRV_FUNC_NAME_HMAC_SHA1_FINAL                             r_tsip_p73f

#define TSIP_PRV_FUNC_NAME_HMAC_SHA224_INIT                            r_tsip_pdci
#define TSIP_PRV_FUNC_NAME_HMAC_SHA224_RESUME                          r_tsip_pdcr
#define TSIP_PRV_FUNC_NAME_HMAC_SHA224_UPDATE                          r_tsip_pdcu
#define TSIP_PRV_FUNC_NAME_HMAC_SHA224_SUSPEND                         r_tsip_pdcs
#define TSIP_PRV_FUNC_NAME_HMAC_SHA224_FINAL                           r_tsip_pdcf

#define TSIP_PRV_FUNC_NAME_HMAC_SHA256_INIT                            r_tsip_p76i
#define TSIP_PRV_FUNC_NAME_HMAC_SHA256_RESUME                          r_tsip_p76r
#define TSIP_PRV_FUNC_NAME_HMAC_SHA256_UPDATE                          r_tsip_p76u
#define TSIP_PRV_FUNC_NAME_HMAC_SHA256_SUSPEND                         r_tsip_p76s
#define TSIP_PRV_FUNC_NAME_HMAC_SHA256_FINAL                           r_tsip_p76f

#define TSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA1                      r_tsip_p6d
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA1                      r_tsip_wrapper_p0f_sha1

#define TSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA224                    r_tsip_p6e
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA224                    r_tsip_wrapper_p0f_sha224

#define TSIP_PRV_FUNC_NAME_KEY_GENERATE_HMAC_SHA256                    r_tsip_p6f
#define TSIP_PRV_FUNC_NAME_ENC_KEY_WRAP_HMAC_SHA256                    r_tsip_wrapper_p0f_sha256

#define TSIP_PRV_PKI_HASH_TYPE_SHA1                                    (0U)
#define TSIP_PRV_PKI_HASH_TYPE_SHA224                                  (0U)
#define TSIP_PRV_PKI_HASH_TYPE_SHA256                                  (1U)
#define TSIP_PRV_PKI_HASH_TYPE_SHA384                                  (4U)
#define TSIP_PRV_PKI_HASH_TYPE_SHA512                                  (5U)
#define TSIP_PRV_PKI_HASH_TYPE_SHA512_224                              (2U)
#define TSIP_PRV_PKI_HASH_TYPE_SHA512_256                              (3U)

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/* ECC */
tsip_ret_t r_tsip_wrapper_pf0_secp256r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf1_secp256r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf4_secp256r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2c_secp256r1(const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p1e_secp256r1(const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_pf0_brainpoolp256r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf1_brainpoolp256r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf4_brainpoolp256r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2c_brainpoolp256r1(const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p1e_brainpoolp256r1(const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_pf5_secp384r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf6_secp384r1(const uint32_t InData_KeyIndex[],
                                        const uint32_t InData_MsgDgst[],
                                        const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf9_secp384r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2e_secp384r1(const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2d_secp384r1(const uint32_t InData_IV[],
                                        const uint32_t InData_InstData[],
                                        uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_pf5_brainpoolp384r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf6_brainpoolp384r1(const uint32_t InData_KeyIndex[],
                                              const uint32_t InData_MsgDgst[],
                                              const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_wrapper_pf9_brainpoolp384r1(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2e_brainpoolp384r1(const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2d_brainpoolp384r1(const uint32_t InData_IV[],
                                              const uint32_t InData_InstData[],
                                              uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p7d(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_MsgDgst[],
                              uint32_t       OutData_Signature[]);
tsip_ret_t r_tsip_wrapper_p7e(const uint32_t InData_KeyIndex[],
                              const uint32_t InData_MsgDgst[],
                              const uint32_t InData_Signature[]);
tsip_ret_t r_tsip_wrapper_ped(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);

/* RSA */
tsip_ret_t r_tsip_wrapper_p2a(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);
tsip_ret_t r_tsip_wrapper_p2b(uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[]);

/* AES-ECB/CBC/CTR */
tsip_ret_t r_tsip_wrapper_p48i_ecb_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p48i_ecb_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p48i_cbc_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p48i_cbc_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p48i_ctr(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p50i_ecb_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p50i_ecb_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p50i_cbc_enc(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p50i_cbc_dec(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);
tsip_ret_t r_tsip_wrapper_p50i_ctr(const uint32_t InData_KeyIndex[], const uint32_t InData_IV[]);

/* AES-MAC */
tsip_ret_t r_tsip_wrapper_p41f_gen(const uint32_t * InData_Text, uint32_t * OutData_DataT, const uint32_t all_msg_len);
tsip_ret_t r_tsip_wrapper_p41f_veri(const uint32_t * InData_Text,
                                    const uint32_t * InData_DataT,
                                    const uint32_t * InData_DataTLen,
                                    const uint32_t   all_msg_len);
tsip_ret_t r_tsip_wrapper_p44f_gen(const uint32_t * InData_Text, uint32_t * OutData_DataT, const uint32_t all_msg_len);
tsip_ret_t r_tsip_wrapper_p44f_veri(const uint32_t * InData_Text,
                                    const uint32_t * InData_DataT,
                                    const uint32_t * InData_DataTLen,
                                    const uint32_t   all_msg_len);

/* HMAC */
tsip_ret_t r_tsip_wrapper_p0f_sha1(const uint32_t InData_IV[],
                                   const uint32_t InData_InstData[],
                                   uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p0f_sha224(const uint32_t InData_IV[],
                                     const uint32_t InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);
tsip_ret_t r_tsip_wrapper_p0f_sha256(const uint32_t InData_IV[],
                                     const uint32_t InData_InstData[],
                                     uint32_t       OutData_KeyIndex[]);

#endif                                 /* R_TSIP_WRAPPER_H */
