/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_H
 #define R_TSIP_H

/* Register definitions, common services and error codes. */
 #include "bsp_api.h"
 #include "r_tsip_api.h"
 #include "r_tsip_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZV
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_TSIP_PROTECTED
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Returns the plain key size formatted for TSIP driver of the key type. */
 #define TSIP_BYTE_SIZE_PLAIN_KEY(key_type)        (TSIP_PRV_KEY_TYPE_VAL_PLAIN_WORDS(key_type) << 2)

/** Returns the encrypted key size of the key type. */
 #define TSIP_BYTE_SIZE_ENCRYPTED_KEY(key_type)    (TSIP_PRV_BYTE_SIZE_ENCRYPTED_DATA(TSIP_PRV_KEY_TYPE_VAL_PLAIN_WORDS( \
                                                                                          key_type)))

/** RSA wrapped key additional word offset (RSA wrapped key overhead differs from TSIP_CFG_WORD_SIZE_WRAPPED_KEY_OVERHEAD). */
 #define TSIP_PRV_RSA_WRAPPED_WORD_OFFSET(key_type)                                       \
    ((((TSIP_PRV_KEY_TYPE_VAL_ALG(key_type) == TSIP_PRV_ALG_RSA_PUBLIC) ||                \
       (TSIP_PRV_KEY_TYPE_VAL_ALG(key_type) == TSIP_PRV_ALG_RSA_PRIVATE)) &&              \
      (TSIP_PRV_KEY_TYPE_VAL_SUBTYPE(key_type) == TSIP_PRV_KEY_SUBTYPE_RSA_1024)) ? 32U : \
     (((TSIP_PRV_KEY_TYPE_VAL_ALG(key_type) == TSIP_PRV_ALG_RSA_PUBLIC) ||                \
       (TSIP_PRV_KEY_TYPE_VAL_ALG(key_type) == TSIP_PRV_ALG_RSA_PRIVATE)) &&              \
      (TSIP_PRV_KEY_TYPE_VAL_SUBTYPE(key_type) == TSIP_PRV_KEY_SUBTYPE_RSA_2048)) ? 64U : 0U)

/** Returns the wrapped key size of the key type. */
 #define TSIP_BYTE_SIZE_WRAPPED_KEY(key_type)        (TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(TSIP_PRV_KEY_TYPE_VAL_PLAIN_WORDS( \
                                                                                          key_type) +                    \
                                                                                      TSIP_PRV_RSA_WRAPPED_WORD_OFFSET(  \
                                                                                          key_type)))

/* data size */
 #define TSIP_PRV_BYTE_SIZE_ENCRYPTED_DATA(words)    (((words) + TSIP_CFG_WORD_SIZE_ENCRYPTED_KEY_OVERHEAD) << 2)
 #define TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(words)      (((words) + TSIP_CFG_WORD_SIZE_WRAPPED_KEY_OVERHEAD) << 2)

/* Wrapped ECDH secret size */
 #define TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_256      TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(8)
 #define TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_384      TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(12)
 #define TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_512      TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(16)
 #define TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_521      TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(20)

/* Internal state buffer size for SHA */
 #if TSIP_CFG_SHA3_224_ENABLE || TSIP_CFG_SHA3_256_ENABLE || TSIP_CFG_SHA3_384_ENABLE || TSIP_CFG_SHA3_512_ENABLE
  #define TSIP_PRV_WORD_SIZE_SHA_INTERNAL_STATE_BUF      (52U)
 #else
  #define TSIP_PRV_WORD_SIZE_SHA_INTERNAL_STATE_BUF      (20U)
 #endif

/* Internal state buffer size for HMAC */
 #define TSIP_PRV_WORD_SIZE_HMAC_INTERNAL_STATE_BUF      (20U)

/* Buffer size for SHA */
 #if TSIP_CFG_SHA3_224_ENABLE
  #define TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF               (144U * TSIP_CFG_SHA_BUF_BLOCKS)
 #elif TSIP_CFG_SHA3_256_ENABLE
  #define TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF               (136U * TSIP_CFG_SHA_BUF_BLOCKS)
 #elif TSIP_CFG_SHA512_ENABLE || TSIP_CFG_SHA512_224_ENABLE || TSIP_CFG_SHA512_256_ENABLE || TSIP_CFG_SHA384_ENABLE
  #define TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF               (128U * TSIP_CFG_SHA_BUF_BLOCKS)
 #elif TSIP_CFG_SHA3_384_ENABLE
  #define TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF               (104U * TSIP_CFG_SHA_BUF_BLOCKS)
 #elif TSIP_CFG_SHA3_512_ENABLE
  #define TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF               (72U * TSIP_CFG_SHA_BUF_BLOCKS)
 #else
  #define TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF               (64U * TSIP_CFG_SHA_BUF_BLOCKS)
 #endif

/* Buffer size for KDF SHA */
 #if TSIP_CFG_KDF_SHA384_ENABLE
  #define TSIP_PRV_BYTE_SIZE_KDF_SHA_BLOCK_BUF           (128U)
 #else
  #define TSIP_PRV_BYTE_SIZE_KDF_SHA_BLOCK_BUF           (64U)
 #endif

/* Buffer sizes for HMAC */
 #if TSIP_CFG_HMAC_SHA512_ENABLE
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_HMAC_BUF        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA512)
  #define TSIP_PRV_BYTE_SIZE_HMAC_BLOCK_BUF              (128U * TSIP_CFG_SHA_BUF_BLOCKS)
 #elif TSIP_CFG_HMAC_SHA384_ENABLE
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_HMAC_BUF        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA384)
  #define TSIP_PRV_BYTE_SIZE_HMAC_BLOCK_BUF              (128U * TSIP_CFG_SHA_BUF_BLOCKS)
 #elif TSIP_CFG_HMAC_SHA256_ENABLE
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_HMAC_BUF        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA256)
  #define TSIP_PRV_BYTE_SIZE_HMAC_BLOCK_BUF              (64U * TSIP_CFG_HMAC_BUF_BLOCKS)
 #elif TSIP_CFG_HMAC_SHA224_ENABLE
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_HMAC_BUF        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA224)
  #define TSIP_PRV_BYTE_SIZE_HMAC_BLOCK_BUF              (64U * TSIP_CFG_HMAC_BUF_BLOCKS)
 #else
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_HMAC_BUF        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA1)
  #define TSIP_PRV_BYTE_SIZE_HMAC_BLOCK_BUF              (64U * TSIP_CFG_HMAC_BUF_BLOCKS)
 #endif

/* Buffer size for ECDH */
 #if TSIP_CFG_ECC_SECP521R1_ENABLE
  #define  TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_BUF    TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_521
 #elif TSIP_CFG_ECC_BRAINPOOLP512R1_ENABLE
  #define  TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_BUF    TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_512
 #elif TSIP_CFG_ECC_SECP384R1_ENABLE || TSIP_CFG_ECC_BRAINPOOLP384R1_ENABLE
  #define  TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_BUF    TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_384
 #else
  #define  TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_BUF    TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_256
 #endif

/* Buffer size for KDF */
 #if TSIP_CFG_ECC_SECP521R1_ENABLE
  #define TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF         TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_521
 #elif TSIP_CFG_ECC_BRAINPOOLP512R1_ENABLE
  #define TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF         TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_512
 #elif TSIP_CFG_KDF_HMAC_SHA512_ENABLE
  #define TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF         TSIP_BYTE_SIZE_WRAPPED_DKM_BLOCK_SHA512
 #elif TSIP_CFG_ECC_SECP384R1_ENABLE || TSIP_CFG_ECC_BRAINPOOLP384R1_ENABLE
  #define TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF         TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_384
 #elif TSIP_CFG_KDF_HMAC_SHA384_ENABLE
  #define TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF         TSIP_BYTE_SIZE_WRAPPED_DKM_BLOCK_SHA384
 #else
  #define TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF         TSIP_BYTE_SIZE_WRAPPED_DKM_BLOCK_SHA256
 #endif

/* Buffer sizes for KDF HMAC */
 #if TSIP_CFG_KDF_HMAC_SHA512_ENABLE
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_BUF    TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA512)
  #define TSIP_PRV_BYTE_SIZE_KDF_HMAC_BLOCK_BUF          (128U)
 #elif TSIP_CFG_KDF_HMAC_SHA384_ENABLE
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_BUF    TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA384)
  #define TSIP_PRV_BYTE_SIZE_KDF_HMAC_BLOCK_BUF          (128U)
 #else
  #define TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_BUF    TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA256)
  #define TSIP_PRV_BYTE_SIZE_KDF_HMAC_BLOCK_BUF          (64U)
 #endif

/* Buffer sizes for PKI */
 #if TSIP_CFG_ECC_SECP521R1_ENABLE || TSIP_CFG_ECC_BRAINPOOLP512R1_ENABLE
  #define  TSIP_PRV_BYTE_SIZE_PKI_ENC_CERT_INFO          TSIP_BYTE_SIZE_WRAPPED_KEY(16)
 #elif TSIP_CFG_ECC_SECP384R1_ENABLE || TSIP_CFG_ECC_BRAINPOOLP384R1_ENABLE
  #define  TSIP_PRV_BYTE_SIZE_PKI_ENC_CERT_INFO          TSIP_BYTE_SIZE_WRAPPED_KEY(12)
 #else
  #define  TSIP_PRV_BYTE_SIZE_PKI_ENC_CERT_INFO          TSIP_BYTE_SIZE_WRAPPED_KEY(8)
 #endif

/* Constants */
 #define TSIP_PRV_BYTE_SIZE_AES_BLOCK                    (16U)
 #define TSIP_PRV_BYTE_SIZE_CCM_NONCE_MAX                (13U)
 #define TSIP_PRV_BYTE_SIZE_CCM_AAD_MAX                  (110U)
 #define TSIP_PRV_BYTE_SIZE_CHACHA20_BLOCK               (64U)
 #define TSIP_PRV_WORD_SIZE_CHACHA20_NONCE               (3U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/**
 * Byte size of wrapped key
 */
typedef enum e_tsip_byte_size_wrapped_key
{
    TSIP_BYTE_SIZE_WRAPPED_KEY_AES_128 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_AES_128),                     ///< AES-128
    TSIP_BYTE_SIZE_WRAPPED_KEY_AES_192 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_AES_192),                     ///< AES-192
    TSIP_BYTE_SIZE_WRAPPED_KEY_AES_256 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_AES_256),                     ///< AES-256
    TSIP_BYTE_SIZE_WRAPPED_KEY_XTS_AES_128 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_XTS_AES_128),                 ///< XTS-AES-128
    TSIP_BYTE_SIZE_WRAPPED_KEY_XTS_AES_256 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_XTS_AES_256),                 ///< XTS-AES-256
    TSIP_BYTE_SIZE_WRAPPED_KEY_CHACHA20 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_CHACHA20),                    ///< ChaCha20
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP256R1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP256R1_PUBLIC),        ///< secp256r1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP384R1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP384R1_PUBLIC),        ///< secp384r1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP521R1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP521R1_PUBLIC),        ///< secp521r1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP256K1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP256K1_PUBLIC),        ///< secp256k1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_BRAINPOOLP256R1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP256R1_PUBLIC),  ///< brainpoolP256r1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_BRAINPOOLP384R1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP384R1_PUBLIC),  ///< brainpoolP384r1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_BRAINPOOLP512R1_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP512R1_PUBLIC),  ///< brainpoolP512r1 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_EDWARDS25519_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_EDWARDS25519_PUBLIC),     ///< edwards25519 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP256R1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP256R1_PRIVATE),       ///< secp256r1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP384R1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP384R1_PRIVATE),       ///< secp384r1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP521R1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP521R1_PRIVATE),       ///< secp521r1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_SECP256K1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_SECP256K1_PRIVATE),       ///< secp256k1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_BRAINPOOLP256R1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP256R1_PRIVATE), ///< brainpoolP256r1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_BRAINPOOLP384R1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP384R1_PRIVATE), ///< brainpoolP384r1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_BRAINPOOLP512R1_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP512R1_PRIVATE), ///< brainpoolP512r1 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_ECC_EDWARDS25519_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_ECC_EDWARDS25519_PRIVATE),    ///< edwards25519 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_1024_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_1024_PUBLIC),             ///< RSA-1024 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_2048_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_2048_PUBLIC),             ///< RSA-2048 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_3072_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_3072_PUBLIC),             ///< RSA-3072 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_4096_PUBLIC =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_4096_PUBLIC),             ///< RSA-4096 public key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_1024_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_1024_PRIVATE),            ///< RSA-1024 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_2048_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_2048_PRIVATE),            ///< RSA-2048 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_3072_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_3072_PRIVATE),            ///< RSA-3072 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_RSA_4096_PRIVATE =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_RSA_4096_PRIVATE),            ///< RSA-4096 private key
    TSIP_BYTE_SIZE_WRAPPED_KEY_HMAC_SHA1 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA1),                   ///< HMAC-SHA1
    TSIP_BYTE_SIZE_WRAPPED_KEY_HMAC_SHA224 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA224),                 ///< HMAC-SHA224
    TSIP_BYTE_SIZE_WRAPPED_KEY_HMAC_SHA256 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA256),                 ///< HMAC-SHA256
    TSIP_BYTE_SIZE_WRAPPED_KEY_HMAC_SHA384 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA384),                 ///< HMAC-SHA384
    TSIP_BYTE_SIZE_WRAPPED_KEY_HMAC_SHA512 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_HMAC_SHA512),                 ///< HMAC-SHA512
    TSIP_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_SHA256 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA256),             ///< KDF HMAC-SHA256
    TSIP_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_SHA384 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA384),             ///< KDF HMAC-SHA384
    TSIP_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_SHA512 =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA512),             ///< KDF HMAC-SHA512
    TSIP_BYTE_SIZE_WRAPPED_KEY_KUK =
        TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_KUK),                         ///< Key Update Key (KUK)
} tsip_byte_size_wrapped_key_t;

/**
 * Byte size of encrypted key
 */
typedef enum e_tsip_byte_size_encrypted_key
{
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_AES_128 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_AES_128),                     ///< AES-128
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_AES_192 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_AES_192),                     ///< AES-192
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_AES_256 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_AES_256),                     ///< AES-256
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_XTS_AES_128 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_XTS_AES_128),                 ///< XTS-AES-128
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_XTS_AES_256 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_XTS_AES_256),                 ///< XTS-AES-256
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_CHACHA20 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_CHACHA20),                    ///< ChaCha20
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP256R1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP256R1_PUBLIC),        ///< secp256r1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP384R1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP384R1_PUBLIC),        ///< secp384r1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP521R1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP521R1_PUBLIC),        ///< secp521r1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP256K1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP256K1_PUBLIC),        ///< secp256k1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_BRAINPOOLP256R1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP256R1_PUBLIC),  ///< brainpoolP256r1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_BRAINPOOLP384R1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP384R1_PUBLIC),  ///< brainpoolP384r1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_BRAINPOOLP512R1_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP512R1_PUBLIC),  ///< brainpoolP512r1 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_EDWARDS25519_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_EDWARDS25519_PUBLIC),     ///< edwards25519 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP256R1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP256R1_PRIVATE),       ///< secp256r1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP384R1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP384R1_PRIVATE),       ///< secp384r1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP521R1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP521R1_PRIVATE),       ///< secp521r1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_SECP256K1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_SECP256K1_PRIVATE),       ///< secp256k1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_BRAINPOOLP256R1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP256R1_PRIVATE), ///< brainpoolP256r1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_BRAINPOOLP384R1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP384R1_PRIVATE), ///< brainpoolP384r1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_BRAINPOOLP512R1_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_BRAINPOOLP512R1_PRIVATE), ///< brainpoolP512r1 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_ECC_EDWARDS25519_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_ECC_EDWARDS25519_PRIVATE),    ///< edwards25519 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_1024_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_1024_PUBLIC),             ///< RSA-1024 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_2048_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_2048_PUBLIC),             ///< RSA-2048 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_3072_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_3072_PUBLIC),             ///< RSA-3072 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_4096_PUBLIC =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_4096_PUBLIC),             ///< RSA-4096 public key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_1024_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_1024_PRIVATE),            ///< RSA-1024 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_2048_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_2048_PRIVATE),            ///< RSA-2048 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_3072_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_3072_PRIVATE),            ///< RSA-3072 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_RSA_4096_PRIVATE =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_RSA_4096_PRIVATE),            ///< RSA-4096 private key
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_HMAC_SHA1 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_HMAC_SHA1),                   ///< HMAC-SHA1
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_HMAC_SHA224 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_HMAC_SHA224),                 ///< HMAC-SHA224
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_HMAC_SHA256 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_HMAC_SHA256),                 ///< HMAC-SHA256
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_HMAC_SHA384 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_HMAC_SHA384),                 ///< HMAC-SHA384
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_HMAC_SHA512 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_HMAC_SHA512),                 ///< HMAC-SHA512
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_KDF_HMAC_SHA256 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA256),             ///< KDF HMAC-SHA256
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_KDF_HMAC_SHA384 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA384),             ///< KDF HMAC-SHA384
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_KDF_HMAC_SHA512 =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_KDF_HMAC_SHA512),             ///< KDF HMAC-SHA512
    TSIP_BYTE_SIZE_ENCRYPTED_KEY_KUK =
        TSIP_BYTE_SIZE_ENCRYPTED_KEY(TSIP_KEY_TYPE_KUK),                         ///< Key Update Key (KUK)
} tsip_byte_size_encrypted_key_t;

/** Byte size of wrapped key */
typedef enum e_tsip_byte_size_wrapped_dkm
{
    TSIP_BYTE_SIZE_WRAPPED_DKM_HEADER       = 12,                                  ///< Header
    TSIP_BYTE_SIZE_WRAPPED_DKM_BLOCK_SHA256 = TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(8),  ///< A block of SHA-256
    TSIP_BYTE_SIZE_WRAPPED_DKM_BLOCK_SHA384 = TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(12), ///< A block of SHA-384
    TSIP_BYTE_SIZE_WRAPPED_DKM_BLOCK_SHA512 = TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(16), ///< A block of SHA-384
} tsip_byte_size_wrapped_dkm_t;

/** Byte size of wrapped IV or nonce */
typedef enum e_tsip_byte_size_wrapped_iv
{
    TSIP_BYTE_SIZE_WRAPPED_IV = TSIP_PRV_BYTE_SIZE_WRAPPED_DATA(4), ///< Wrapped IV size for all algorithms
} tsip_byte_size_wrapped_iv_t;

/* Working area for AES block cipher */
typedef struct st_tsip_aes_cihper_handle
{
    const void * p_func;               // Pointer to primitive functions
} tsip_aes_cipher_handle_t;

/* Working area for AES-GCM */
typedef struct st_tsip_aes_gcm_handle
{
    const void * p_func;                               // Pointer to primitive functions
    uint8_t      buffer[TSIP_PRV_BYTE_SIZE_AES_BLOCK]; // Buffer for AAD and plaintext/ciphertext
    uint32_t     buffered_length;                      // Buffered AAD and plaintext/ciphertext length
    uint32_t     total_length;                         // Total plaintext/ciphertext length
    uint32_t     total_aad_length;                     // Total AAD length
} tsip_aes_gcm_handle_t;

/* Working area for AES-CCM */
typedef struct st_tsip_aes_ccm_handle
{
    const void       * p_func;                                                               // Pointer to primitive functions
    tsip_wrapped_key_t wrapped_key;                                                          // Wrapped key
    uint8_t            wrapped_key_value[TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_AES_256)]; // Wrapped key value
    uint8_t            nonce_buffer[TSIP_PRV_BYTE_SIZE_CCM_NONCE_MAX];                       // Buffer for nonce
    uint32_t           nonce_length;                                                         // Nonce length
    uint8_t            buffer[TSIP_PRV_BYTE_SIZE_CCM_AAD_MAX];                               // Buffer for AAD and plaintext/ciphertext
    uint32_t           buffered_length;                                                      // Buffered AAD and plaintext/ciphertext length
    uint32_t           input_aad_length;                                                     // Input AAD length
    uint32_t           total_aad_length;                                                     // Total AAD length
    uint32_t           input_length;                                                         // Input plaintext/ciphertext length
    uint32_t           total_length;                                                         // Total plaintext/ciphertext length
    uint32_t           tag_length;                                                           // Tag length
} tsip_aes_ccm_handle_t;

/* Working area for AES-CMAC */
typedef struct st_tsip_aes_cmac_handle
{
    const void * p_func;                               // Pointer to primitive functions
    uint8_t      buffer[TSIP_PRV_BYTE_SIZE_AES_BLOCK]; // Buffer for message
    uint32_t     buffered_length;                      // Buffered message length
    uint32_t     total_length;                         // Total message length
} tsip_aes_cmac_handle_t;

/* Working area for ChaCha20 */
typedef struct st_tsip_chacha20_handle
{
    const void       * p_func;                                                                // Pointer to primitive functions
    tsip_wrapped_key_t wrapped_key;                                                           // Wrapped key
    uint8_t            wrapped_key_value[TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_CHACHA20)]; // Wrapped key value
    uint32_t           nonce_buffer[TSIP_PRV_WORD_SIZE_CHACHA20_NONCE];                       // Buffer for nonce
    uint8_t            buffer[TSIP_PRV_BYTE_SIZE_CHACHA20_BLOCK];                             // Buffer for plaintext/ciphertext
    uint32_t           buffered_length;                                                       // Buffered plaintext/ciphertext length
    uint32_t           total_length;                                                          // Total plaintext/ciphertext length
} tsip_chacha20_handle_t;

/* Working area for ChaCha20-Poly1305 */
typedef struct st_tsip_chacha20_poly1305_handle
{
    const void       * p_func;                                                                // Pointer to primitive functions
    tsip_wrapped_key_t wrapped_key;                                                           // Wrapped key
    uint8_t            wrapped_key_value[TSIP_BYTE_SIZE_WRAPPED_KEY(TSIP_KEY_TYPE_CHACHA20)]; // Wrapped key value
    uint32_t           nonce_buffer[TSIP_PRV_WORD_SIZE_CHACHA20_NONCE];                       // Buffer for nonce
    uint8_t            buffer[TSIP_PRV_BYTE_SIZE_CHACHA20_BLOCK];                             // Buffer for plaintext/ciphertext
    uint32_t           buffered_length;                                                       // Buffered plaintext/ciphertext length
    uint32_t           total_length;                                                          // Total plaintext/ciphertext length
    uint32_t           total_aad_length;                                                      // Total AAD length
} tsip_chacha20_poly1305_handle_t;

/** Working area for SHA functions. DO NOT MODIFY. */
typedef struct st_tsip_sha_handle
{
    tsip_hash_type_t         type;                                                      // Hash type
    uint8_t                  buffer[TSIP_PRV_BYTE_SIZE_SHA_BLOCK_BUF];                  // Stored message
    uint32_t                 buffered_length;                                           // Buffered message length
    uint32_t                 total_length;                                              // Total message length input to primitive
    uint32_t                 block_size;                                                // Block size
    uint32_t                 internal_state[TSIP_PRV_WORD_SIZE_SHA_INTERNAL_STATE_BUF]; // Internal state
    tsip_user_handle_state_t handle_state;                                              // Handle state
} tsip_sha_handle_t;

/** Working area for HMAC functions. DO NOT MODIFY. */
typedef struct st_tsip_hmac_handle
{
    tsip_wrapped_key_t       wrapped_key;                                                // Wrapped key
    uint8_t                  wrapped_key_value[TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_HMAC_BUF]; // Wrapped key value
    uint8_t                  buffer[TSIP_PRV_BYTE_SIZE_HMAC_BLOCK_BUF];                  // Stored message
    uint32_t                 buffered_length;                                            // Buffered message length
    uint32_t                 total_length;                                               // Total message length input to primitive
    uint32_t                 block_size;                                                 // Block size
    uint32_t                 internal_state[TSIP_PRV_WORD_SIZE_HMAC_INTERNAL_STATE_BUF]; // Internal state
    tsip_user_handle_state_t handle_state;                                               // Handle state
} tsip_hmac_handle_t;

/** Working area for KDF SHA functions. DO NOT MODIFY. */
typedef struct st_tsip_kdf_sha_handle
{
    tsip_hash_type_t         type;                                                      // Hash type
    uint8_t                  buffer1[4];                                                // Stored message1
    uint32_t                 buffered_length1;                                          // Buffered message length1
    uint8_t                  buffer2[TSIP_PRV_BYTE_SIZE_KDF_SHA_BLOCK_BUF];             // Stored message2
    uint32_t                 buffered_length2;                                          // Buffered message length2
    uint32_t                 total_length;                                              // Total message length input to primitive
    uint32_t                 block_size;                                                // Block size
    uint32_t                 internal_state[TSIP_PRV_WORD_SIZE_SHA_INTERNAL_STATE_BUF]; // Internal state
    tsip_user_handle_state_t handle_state;                                              // Handle state

    uint8_t  wrapped_msg[TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF];                       // Wrapped message
    uint32_t wrapped_msg_length;                                                        // Wrapped message length
    uint32_t actual_wrapped_msg_length;                                                 // Actual wrapped message length
} tsip_kdf_sha_handle_t;

/** Working area for KDF HMAC functions. DO NOT MODIFY. */
typedef struct st_tsip_kdf_hmac_handle
{
    tsip_wrapped_key_t       wrapped_key;                                                    // Wrapped key
    uint8_t                  wrapped_key_value[TSIP_PRV_BYTE_SIZE_WRAPPED_KEY_KDF_HMAC_BUF]; // Wrapped key value
    uint8_t                  buffer[TSIP_PRV_BYTE_SIZE_KDF_HMAC_BLOCK_BUF];                  // Stored message
    uint32_t                 buffered_length;                                                // Buffered message length
    uint32_t                 total_length;                                                   // Total message length input to primitive
    uint32_t                 block_size;                                                     // Block size
    uint32_t                 internal_state[TSIP_PRV_WORD_SIZE_HMAC_INTERNAL_STATE_BUF];     // Internal state
    tsip_user_handle_state_t handle_state;                                                   // Handle state

    uint8_t  wrapped_msg[TSIP_PRV_BYTE_SIZE_KDF_WRAPPED_MSG_BUF];                            // Wrapped message
    uint32_t wrapped_msg_length;                                                             // Wrapped message length
    uint32_t actual_wrapped_msg_length;                                                      // Actual wrapped message length
} tsip_kdf_hmac_handle_t;

/** Verified certificate information */
typedef struct st_tsip_verified_cert_info
{
    uint8_t value[TSIP_PRV_BYTE_SIZE_PKI_ENC_CERT_INFO];
} tsip_verified_cert_info_t;

/** Wrapped ECDH secret structure for ECDH and KDF APIs. */
typedef struct st_tsip_wrapped_secret
{
    uint8_t type;                                              // Internal key type ID
    uint8_t info[3];                                           // Reserved area
    uint8_t value[TSIP_PRV_BYTE_SIZE_ECDH_WRAPPED_SECRET_BUF]; // Wrapped secret
} tsip_wrapped_secret_t;

/* Working area for TSIP cryptographic algorithms. This union is included in private control block. */
typedef union u_tsip_handle
{
    tsip_aes_cipher_handle_t        aes_cipher;        // AES block cipher
    tsip_aes_gcm_handle_t           aes_gcm;           // AES-GCM
    tsip_aes_ccm_handle_t           aes_ccm;           // AES-CCM
    tsip_aes_cmac_handle_t          aes_cmac;          // AES-CMAC
    tsip_chacha20_handle_t          chacha20;          // ChaCha20
    tsip_chacha20_poly1305_handle_t chacha20_poly1305; // ChaCha20-Poly1305
    tsip_sha_handle_t               sha;               // SHA
    tsip_hmac_handle_t              hmac;              // HMAC
    tsip_kdf_sha_handle_t           kdf_sha;           // KDF SHA
    tsip_kdf_hmac_handle_t          kdf_hmac;          // KDF HMAC
} tsip_handle_t;

/* State that specifies functions that can be called next */
typedef enum e_tsip_state
{
    TSIP_STATE_MAIN,                        // Main
    TSIP_STATE_AES_CIPHER,                  // AES-ECB, AES-CBC, AES-CTR
    TSIP_STATE_AES_XTS_UPDATE,              // XTS-AES update
    TSIP_STATE_AES_XTS_FINISH,              // XTS-AES finalization
    TSIP_STATE_AES_GCM_ENC_UPDATE_AAD,      // AES-GCM encryption, AAD input
    TSIP_STATE_AES_GCM_ENC_UPDATE_TEXT,     // AES-GCM encryption, plaintext/ciphertext input
    TSIP_STATE_AES_GCM_DEC_UPDATE_AAD,      // AES-GCM decryption, AAD input
    TSIP_STATE_AES_GCM_DEC_UPDATE_TEXT,     // AES-GCM decryption, plaintext/ciphertext input
    TSIP_STATE_AES_CCM_ENC_SET_LENGTH,      // AES-CCM encryption, length setting
    TSIP_STATE_AES_CCM_ENC_UPDATE_AAD,      // AES-CCM encryption, AAD input
    TSIP_STATE_AES_CCM_ENC_UPDATE_TEXT,     // AES-CCM encryption, plaintext/ciphertext input
    TSIP_STATE_AES_CCM_ENC_FINISH,          // AES-CCM encryption, finish
    TSIP_STATE_AES_CCM_DEC_SET_LENGTH,      // AES-CCM decryption, length setting
    TSIP_STATE_AES_CCM_DEC_UPDATE_AAD,      // AES-CCM decryption, AAD input
    TSIP_STATE_AES_CCM_DEC_UPDATE_TEXT,     // AES-CCM decryption, plaintext/ciphertext input
    TSIP_STATE_AES_CCM_DEC_VERI,            // AES-CCM encryption, verification
    TSIP_STATE_AES_CMAC,                    // AES-CMAC
    TSIP_STATE_CHACHA,                      // ChaCha20
    TSIP_STATE_CHACHA_POLY_ENC_UPDATE_AAD,  // ChaCha20-Poly1305 encryption, AAD input
    TSIP_STATE_CHACHA_POLY_ENC_UPDATE_TEXT, // ChaCha20-Poly1305 encryption, plaintext/ciphertext input
    TSIP_STATE_CHACHA_POLY_DEC_UPDATE_AAD,  // ChaCha20-Poly1305 decryption, AAD input
    TSIP_STATE_CHACHA_POLY_DEC_UPDATE_TEXT, // ChaCha20-Poly1305 decryption, plaintext/ciphertext input
    TSIP_STATE_SHA,                         // SHA
    TSIP_STATE_HMAC,                        // HMAC
    TSIP_STATE_KDF_SHA,                     // KDF SHA
    TSIP_STATE_KDF_HMAC,                    // KDF HMAC
} tsip_state_t;

/** TSIP private control block. DO NOT MODIFY. Initialization occurs when R_TSIP_Open() is called. */
typedef struct st_tsip_instance_ctrl
{
    uint32_t           open;                          // Indicates whether the open() API has been successfully
    tsip_cfg_t const * p_cfg;                         // Pointer to the configuration block
    tsip_handle_t      handle;                        // Handle of algorithms that cannot be suspended
    tsip_state_t       state;                         // Flags to limit the next API to call

    tsip_verified_cert_info_t pki_verified_cert_info; // Verified certificate info
} tsip_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const tsip_api_t g_tsip_on_tsip;

/** @endcond */

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

/* r_tsip.c */
fsp_err_t R_TSIP_Open(tsip_ctrl_t * const p_ctrl, tsip_cfg_t const * const p_cfg);
fsp_err_t R_TSIP_Close(tsip_ctrl_t * const p_ctrl);
fsp_err_t R_TSIP_RandomNumberGenerate(tsip_ctrl_t * const p_ctrl, uint8_t * const p_random);
fsp_err_t R_TSIP_KeyGenerate(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t * const p_wrapped_key);
fsp_err_t R_TSIP_KeyPairGenerate(tsip_ctrl_t * const        p_ctrl,
                                 tsip_wrapped_key_t * const p_wrapped_public_key,
                                 tsip_wrapped_key_t * const p_wrapped_private_key);
fsp_err_t R_TSIP_EncryptedKeyWrap(tsip_ctrl_t * const              p_ctrl,
                                  tsip_wrapped_key_t const * const p_key_update_key,
                                  void const * const               p_initial_vector,
                                  void const * const               p_encrypted_key,
                                  tsip_wrapped_key_t * const       p_wrapped_key);
fsp_err_t R_TSIP_RFC3394_KeyWrap(tsip_ctrl_t * const              p_ctrl,
                                 tsip_wrapped_key_t const * const p_wrapped_kek,
                                 tsip_wrapped_key_t const * const p_wrapped_target_key,
                                 uint8_t * const                  p_rfc3394_wrapped_target_key);
fsp_err_t R_TSIP_RFC3394_KeyUnwrap(tsip_ctrl_t * const              p_ctrl,
                                   tsip_wrapped_key_t const * const p_wrapped_kek,
                                   uint8_t const * const            p_rfc3394_wrapped_target_key,
                                   tsip_wrapped_key_t * const       p_wrapped_target_key);
fsp_err_t R_TSIP_PublicKeyExport(tsip_wrapped_key_t const * const p_wrapped_public_key,
                                 uint8_t * const                  p_raw_public_key);

/* r_tsip_aes.c */
fsp_err_t R_TSIP_AES_Cipher_Init(tsip_ctrl_t * const              p_ctrl,
                                 tsip_aes_cipher_mode_t const     mode,
                                 tsip_wrapped_key_t const * const p_wrapped_key,
                                 uint8_t const * const            p_initial_vector);
fsp_err_t R_TSIP_AES_Cipher_Update(tsip_ctrl_t * const   p_ctrl,
                                   uint8_t const * const p_input,
                                   uint8_t * const       p_output,
                                   uint32_t const        length);
fsp_err_t R_TSIP_AES_Cipher_Finish(tsip_ctrl_t * const p_ctrl);
fsp_err_t R_TSIP_AES_AEAD_Init(tsip_ctrl_t * const              p_ctrl,
                               tsip_aes_aead_mode_t const       mode,
                               tsip_wrapped_key_t const * const p_wrapped_key,
                               uint8_t const * const            p_nonce,
                               uint32_t const                   nonce_length);
fsp_err_t R_TSIP_AES_AEAD_LengthsSet(tsip_ctrl_t * const p_ctrl,
                                     uint32_t const      total_aad_length,
                                     uint32_t const      total_text_length,
                                     uint32_t const      tag_length);
fsp_err_t R_TSIP_AES_AEAD_AADUpdate(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_aad, uint32_t const aad_length);
fsp_err_t R_TSIP_AES_AEAD_Update(tsip_ctrl_t * const   p_ctrl,
                                 uint8_t const * const p_input,
                                 uint32_t const        input_length,
                                 uint8_t * const       p_output,
                                 uint32_t * const      p_output_length);
fsp_err_t R_TSIP_AES_AEAD_Finish(tsip_ctrl_t * const p_ctrl,
                                 uint8_t * const     p_output,
                                 uint32_t * const    p_output_length,
                                 uint8_t * const     p_tag);
fsp_err_t R_TSIP_AES_AEAD_Verify(tsip_ctrl_t * const   p_ctrl,
                                 uint8_t * const       p_output,
                                 uint32_t * const      p_output_length,
                                 uint8_t const * const p_tag,
                                 uint32_t const        tag_length);

fsp_err_t R_TSIP_AES_MAC_Init(tsip_ctrl_t * const              p_ctrl,
                              tsip_aes_mac_mode_t const        mode,
                              tsip_wrapped_key_t const * const p_wrapped_key);
fsp_err_t R_TSIP_AES_MAC_Update(tsip_ctrl_t * const   p_ctrl,
                                uint8_t const * const p_message,
                                uint32_t const        message_length);
fsp_err_t R_TSIP_AES_MAC_SignFinish(tsip_ctrl_t * const p_ctrl, uint8_t * const p_mac);
fsp_err_t R_TSIP_AES_MAC_VerifyFinish(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_mac,
                                      uint32_t const mac_length);

/* r_tsip_chacha.c */
fsp_err_t R_TSIP_ChaCha20_Init(tsip_ctrl_t * const              p_ctrl,
                               tsip_wrapped_key_t const * const p_wrapped_key,
                               uint8_t const * const            p_nonce,
                               uint32_t const                   counter);
fsp_err_t R_TSIP_ChaCha20_Update(tsip_ctrl_t * const   p_ctrl,
                                 uint8_t const * const p_input,
                                 uint32_t const        input_length,
                                 uint8_t * const       p_output,
                                 uint32_t * const      p_output_length);
fsp_err_t R_TSIP_ChaCha20_Finish(tsip_ctrl_t * const p_ctrl, uint8_t * const p_output,
                                 uint32_t * const p_output_length);
fsp_err_t R_TSIP_ChaCha20_Poly1305_Init(tsip_ctrl_t * const              p_ctrl,
                                        tsip_chacha_poly_mode_t const    mode,
                                        tsip_wrapped_key_t const * const p_wrapped_key,
                                        uint8_t const * const            p_nonce,
                                        uint32_t const                   nonce_length);
fsp_err_t R_TSIP_ChaCha20_Poly1305_AADUpdate(tsip_ctrl_t * const   p_ctrl,
                                             uint8_t const * const p_aad,
                                             uint32_t const        aad_length);
fsp_err_t R_TSIP_ChaCha20_Poly1305_Update(tsip_ctrl_t * const   p_ctrl,
                                          uint8_t const * const p_input,
                                          uint32_t const        input_length,
                                          uint8_t * const       p_output,
                                          uint32_t * const      p_output_length);
fsp_err_t R_TSIP_ChaCha20_Poly1305_Finish(tsip_ctrl_t * const p_ctrl,
                                          uint8_t * const     p_output,
                                          uint32_t * const    p_output_length,
                                          uint8_t * const     p_tag);
fsp_err_t R_TSIP_ChaCha20_Poly1305_Verify(tsip_ctrl_t * const   p_ctrl,
                                          uint8_t * const       p_output,
                                          uint32_t * const      p_output_length,
                                          uint8_t const * const p_tag,
                                          uint32_t const        tag_length);

/* r_tsip_ecc.c */
fsp_err_t R_TSIP_ECDSA_Sign(tsip_ctrl_t * const              p_ctrl,
                            tsip_wrapped_key_t const * const p_wrapped_private_key,
                            uint8_t const * const            p_hash,
                            uint8_t * const                  p_signature);
fsp_err_t R_TSIP_ECDSA_Verify(tsip_ctrl_t * const              p_ctrl,
                              tsip_wrapped_key_t const * const p_wrapped_public_key,
                              uint8_t const * const            p_hash,
                              uint8_t const * const            p_signature);
fsp_err_t R_TSIP_PureEdDSA_Sign(tsip_ctrl_t * const              p_ctrl,
                                tsip_wrapped_key_t const * const p_wrapped_private_key,
                                tsip_wrapped_key_t const * const p_wrapped_public_key,
                                uint8_t const * const            p_message,
                                uint64_t const                   message_length,
                                uint8_t * const                  p_signature);
fsp_err_t R_TSIP_PureEdDSA_Verify(tsip_ctrl_t * const              p_ctrl,
                                  tsip_wrapped_key_t const * const p_wrapped_public_key,
                                  uint8_t const * const            p_message,
                                  uint64_t const                   message_length,
                                  uint8_t const * const            p_signature);
fsp_err_t R_TSIP_ECDH_KeyAgree(tsip_ctrl_t * const              p_ctrl,
                               tsip_wrapped_key_t const * const p_wrapped_private_key,
                               tsip_wrapped_key_t const * const p_wrapped_public_key,
                               tsip_wrapped_secret_t * const    p_wrapped_secret);
fsp_err_t R_TSIP_ECDH_PlainKeyAgree(tsip_ctrl_t * const              p_ctrl,
                                    tsip_wrapped_key_t const * const p_wrapped_private_key,
                                    uint8_t const * const            p_plain_public_key,
                                    tsip_wrapped_secret_t * const    p_wrapped_secret);

/* r_tsip_rsa.c */
fsp_err_t R_TSIP_RSA_Encrypt(tsip_ctrl_t * const              p_ctrl,
                             tsip_wrapped_key_t const * const p_wrapped_public_key,
                             uint8_t const * const            p_plain,
                             uint8_t * const                  p_cipher);
fsp_err_t R_TSIP_RSA_Decrypt(tsip_ctrl_t * const              p_ctrl,
                             tsip_wrapped_key_t const * const p_wrapped_private_key,
                             uint8_t const * const            p_cipher,
                             uint8_t * const                  p_plain);
fsp_err_t R_TSIP_RSAES_PKCS1_V1_5_Encrypt(tsip_ctrl_t * const              p_ctrl,
                                          tsip_wrapped_key_t const * const p_wrapped_public_key,
                                          uint8_t const * const            p_plain,
                                          uint32_t const                   plain_length,
                                          uint8_t * const                  p_cipher);
fsp_err_t R_TSIP_RSAES_PKCS1_V1_5_Decrypt(tsip_ctrl_t * const              p_ctrl,
                                          tsip_wrapped_key_t const * const p_wrapped_private_key,
                                          uint8_t const * const            p_cipher,
                                          uint8_t * const                  p_plain,
                                          uint32_t * const                 p_plain_length,
                                          uint32_t const                   plain_buffer_length);
fsp_err_t R_TSIP_RSAES_OAEP_Encrypt(tsip_ctrl_t * const              p_ctrl,
                                    tsip_wrapped_key_t const * const p_wrapped_public_key,
                                    tsip_hash_type_t const           hash_function,
                                    tsip_mgf_type_t const            mask_generation_function,
                                    uint8_t const * const            p_label,
                                    uint32_t const                   label_length,
                                    uint8_t const * const            p_plain,
                                    uint32_t const                   plain_length,
                                    uint8_t * const                  p_cipher);
fsp_err_t R_TSIP_RSAES_OAEP_Decrypt(tsip_ctrl_t * const              p_ctrl,
                                    tsip_wrapped_key_t const * const p_wrapped_private_key,
                                    tsip_hash_type_t const           hash_function,
                                    tsip_mgf_type_t const            mask_generation_function,
                                    uint8_t const * const            p_label,
                                    uint32_t const                   label_length,
                                    uint8_t const * const            p_cipher,
                                    uint8_t * const                  p_plain,
                                    uint32_t * const                 p_plain_length,
                                    uint32_t const                   plain_buffer_length);
fsp_err_t R_TSIP_RSASSA_PKCS1_V1_5_Sign(tsip_ctrl_t * const              p_ctrl,
                                        tsip_wrapped_key_t const * const p_wrapped_private_key,
                                        tsip_hash_type_t const           hash_function,
                                        uint8_t const * const            p_hash,
                                        uint8_t * const                  p_signature);
fsp_err_t R_TSIP_RSASSA_PKCS1_V1_5_Verify(tsip_ctrl_t * const              p_ctrl,
                                          tsip_wrapped_key_t const * const p_wrapped_public_key,
                                          tsip_hash_type_t const           hash_function,
                                          uint8_t const * const            p_hash,
                                          uint8_t const * const            p_signature);
fsp_err_t R_TSIP_RSASSA_PSS_Sign(tsip_ctrl_t * const              p_ctrl,
                                 tsip_wrapped_key_t const * const p_wrapped_private_key,
                                 tsip_hash_type_t const           hash_function,
                                 tsip_mgf_type_t const            mask_generation_function,
                                 uint32_t const                   salt_length,
                                 uint8_t const * const            p_hash,
                                 uint8_t * const                  p_signature);
fsp_err_t R_TSIP_RSASSA_PSS_Verify(tsip_ctrl_t * const              p_ctrl,
                                   tsip_wrapped_key_t const * const p_wrapped_public_key,
                                   tsip_hash_type_t const           hash_function,
                                   tsip_mgf_type_t const            mask_generation_function,
                                   uint32_t const                   salt_length,
                                   uint8_t const * const            p_hash,
                                   uint8_t const * const            p_signature);

/* r_tsip_sha.c */
fsp_err_t R_TSIP_SHA_Compute(tsip_ctrl_t * const    p_ctrl,
                             tsip_hash_type_t const hash_type,
                             uint8_t const * const  p_message,
                             uint32_t const         message_length,
                             uint8_t * const        p_digest);
fsp_err_t R_TSIP_SHA_Init(tsip_ctrl_t * const p_ctrl, tsip_hash_type_t const hash_type);
fsp_err_t R_TSIP_SHA_Update(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message, uint32_t const message_length);
fsp_err_t R_TSIP_SHA_Finish(tsip_ctrl_t * const p_ctrl, uint8_t * const p_digest);
fsp_err_t R_TSIP_SHA_Suspend(tsip_ctrl_t * const p_ctrl, tsip_sha_handle_t * const p_handle);
fsp_err_t R_TSIP_SHA_Resume(tsip_ctrl_t * const p_ctrl, tsip_sha_handle_t const * const p_handle);
fsp_err_t R_TSIP_HMAC_Compute(tsip_ctrl_t * const        p_ctrl,
                              const tsip_wrapped_key_t * p_wrapped_key,
                              uint8_t const * const      p_message,
                              uint32_t const             message_length,
                              uint8_t * const            p_mac);
fsp_err_t R_TSIP_HMAC_Verify(tsip_ctrl_t * const        p_ctrl,
                             const tsip_wrapped_key_t * p_wrapped_key,
                             uint8_t const * const      p_message,
                             uint32_t const             message_length,
                             uint8_t const * const      p_mac,
                             uint32_t const             mac_length);
fsp_err_t R_TSIP_HMAC_Init(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_key);
fsp_err_t R_TSIP_HMAC_Update(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message,
                             uint32_t const message_length);
fsp_err_t R_TSIP_HMAC_SignFinish(tsip_ctrl_t * const p_ctrl, uint8_t * const p_mac);
fsp_err_t R_TSIP_HMAC_VerifyFinish(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_mac, uint32_t const mac_length);
fsp_err_t R_TSIP_HMAC_Suspend(tsip_ctrl_t * const p_ctrl, tsip_hmac_handle_t * const p_handle);
fsp_err_t R_TSIP_HMAC_Resume(tsip_ctrl_t * const p_ctrl, tsip_hmac_handle_t const * const p_handle);

/* r_tsip_pki.c */
fsp_err_t R_TSIP_PKI_ECDSA_CertVerify(tsip_ctrl_t * const              p_ctrl,
                                      tsip_wrapped_key_t const * const p_wrapped_public_key,
                                      uint8_t const * const            p_hash,
                                      uint8_t const * const            p_signature);
fsp_err_t R_TSIP_PKI_RSASSA_PKCS1_V1_5_CertVerify(tsip_ctrl_t * const              p_ctrl,
                                                  tsip_wrapped_key_t const * const p_wrapped_public_key,
                                                  tsip_hash_type_t const           hash_function,
                                                  uint8_t const * const            p_hash,
                                                  uint8_t const * const            p_signature);
fsp_err_t R_TSIP_PKI_RSASSA_PSS_CertVerify(tsip_ctrl_t * const              p_ctrl,
                                           tsip_wrapped_key_t const * const p_wrapped_public_key,
                                           tsip_hash_type_t const           hash_function,
                                           tsip_mgf_type_t const            mask_generation_function,
                                           uint32_t const                   salt_length,
                                           uint8_t const * const            p_hash,
                                           uint8_t const * const            p_signature);
fsp_err_t R_TSIP_PKI_VerifiedCertInfoExport(tsip_ctrl_t * const               p_ctrl,
                                            tsip_verified_cert_info_t * const p_verified_cert_info);
fsp_err_t R_TSIP_PKI_VerifiedCertInfoImport(tsip_ctrl_t * const                     p_ctrl,
                                            tsip_verified_cert_info_t const * const p_verified_cert_info);
fsp_err_t R_TSIP_PKI_CertKeyImport(tsip_ctrl_t * const        p_ctrl,
                                   uint8_t const * const      p_cert,
                                   uint32_t const             cert_length,
                                   uint8_t const * const      p_key_param1,
                                   uint32_t const             key_param1_length,
                                   uint8_t const * const      p_key_param2,
                                   uint32_t const             key_param2_length,
                                   tsip_hash_type_t const     hash_function,
                                   tsip_wrapped_key_t * const p_wrapped_public_key);

/* r_tsip_kdf.c */
fsp_err_t R_TSIP_KDF_SHA_Init(tsip_ctrl_t * const p_ctrl, tsip_hash_type_t const hash_type);
fsp_err_t R_TSIP_KDF_SHA_ECDHSecretUpdate(tsip_ctrl_t * const                 p_ctrl,
                                          tsip_wrapped_secret_t const * const p_wrapped_secret);
fsp_err_t R_TSIP_KDF_SHA_Update(tsip_ctrl_t * const   p_ctrl,
                                uint8_t const * const p_message,
                                uint32_t const        message_length);
fsp_err_t R_TSIP_KDF_SHA_Finish(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t * const p_wrapped_dkm);
fsp_err_t R_TSIP_KDF_SHA_Suspend(tsip_ctrl_t * const p_ctrl, tsip_kdf_sha_handle_t * const p_handle);
fsp_err_t R_TSIP_KDF_SHA_Resume(tsip_ctrl_t * const p_ctrl, tsip_kdf_sha_handle_t const * const p_handle);
fsp_err_t R_TSIP_KDF_HMAC_DKMKeyImport(tsip_ctrl_t * const              p_ctrl,
                                       tsip_wrapped_dkm_t const * const p_wrapped_dkm,
                                       uint32_t const                   key_length,
                                       tsip_wrapped_key_t * const       p_wrapped_key);
fsp_err_t R_TSIP_KDF_HMAC_ECDHSecretKeyImport(tsip_ctrl_t * const                 p_ctrl,
                                              tsip_wrapped_secret_t const * const p_wrapped_secret,
                                              tsip_wrapped_key_t * const          p_wrapped_key);
fsp_err_t R_TSIP_KDF_HMAC_Init(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_key);
fsp_err_t R_TSIP_KDF_HMAC_DKMUpdate(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t const * const p_wrapped_dkm);
fsp_err_t R_TSIP_KDF_HMAC_ECDHSecretUpdate(tsip_ctrl_t * const                 p_ctrl,
                                           tsip_wrapped_secret_t const * const p_wrapped_secret);
fsp_err_t R_TSIP_KDF_HMAC_Update(tsip_ctrl_t * const   p_ctrl,
                                 uint8_t const * const p_message,
                                 uint32_t const        message_length);
fsp_err_t R_TSIP_KDF_HMAC_SignFinish(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t * const p_wrapped_dkm);
fsp_err_t R_TSIP_KDF_HMAC_Suspend(tsip_ctrl_t * const p_ctrl, tsip_kdf_hmac_handle_t * const p_handle);
fsp_err_t R_TSIP_KDF_HMAC_Resume(tsip_ctrl_t * const p_ctrl, tsip_kdf_hmac_handle_t const * const p_handle);
fsp_err_t R_TSIP_KDF_DKMConcatenate(tsip_wrapped_dkm_t * const       p_wrapped_dkm1,
                                    tsip_wrapped_dkm_t const * const p_wrapped_dkm2,
                                    uint32_t const                   wrapped_dkm1_buffer_length);
fsp_err_t R_TSIP_KDF_DerivedKeyImport(tsip_ctrl_t * const              p_ctrl,
                                      tsip_wrapped_dkm_t const * const p_wrapped_dkm,
                                      uint32_t const                   position,
                                      tsip_wrapped_key_t * const       p_wrapped_key);
fsp_err_t R_TSIP_KDF_DerivedIVWrap(tsip_ctrl_t * const              p_ctrl,
                                   tsip_wrapped_dkm_t const * const p_wrapped_dkm,
                                   tsip_initial_vector_type_t const initial_vector_type,
                                   uint32_t const                   position,
                                   uint8_t const * const            p_tls_sequence_num,
                                   uint8_t * const                  p_wrapped_initial_vector);

/* r_tsip_otf.c */
fsp_err_t R_TSIP_OTF_Init(tsip_ctrl_t * const        p_ctrl,
                          tsip_otf_channel_t const   channel,
                          tsip_wrapped_key_t * const p_wrapped_key,
                          uint8_t const * const      p_seed);

/*******************************************************************************************************************//**
 * @} (end addtogroup TSIP_PROTECTED)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_TSIP_H */
