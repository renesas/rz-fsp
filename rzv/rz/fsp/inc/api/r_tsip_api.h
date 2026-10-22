/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_API_H
 #define R_TSIP_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
 #include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Internal macro (calculation of key type values) */
 #define TSIP_PRV_KEY_TYPE_VAL(plain_words, alg, subtype)    (((alg) << 24) | ((subtype) << 16) | (plain_words))
 #define TSIP_PRV_KEY_TYPE_VAL_ALG(key_type_val)             ((uint8_t) \
                                                              (((uint32_t) (key_type_val) & 0xff000000U) >> 24))
 #define TSIP_PRV_KEY_TYPE_VAL_SUBTYPE(key_type_val)         ((uint8_t) \
                                                              (((uint32_t) (key_type_val) & 0x00ff0000U) >> 16))
 #define TSIP_PRV_KEY_TYPE_VAL_PLAIN_WORDS(key_type_val)     (((uint32_t) (key_type_val) & 0x0000ffffU) >> 0)

/* Internal algorithm ID */
 #define TSIP_PRV_ALG_INVALID                        (0x00)
 #define TSIP_PRV_ALG_AES                            (0x01)
 #define TSIP_PRV_ALG_XTS_AES                        (0x02)
 #define TSIP_PRV_ALG_CHACHA                         (0x03)
 #define TSIP_PRV_ALG_ECC_PUBLIC                     (0x04)
 #define TSIP_PRV_ALG_ECC_PRIVATE                    (0x05)
 #define TSIP_PRV_ALG_RSA_PUBLIC                     (0x06)
 #define TSIP_PRV_ALG_RSA_PRIVATE                    (0x07)
 #define TSIP_PRV_ALG_HMAC                           (0x08)
 #define TSIP_PRV_ALG_KDF_HMAC                       (0x09)
 #define TSIP_PRV_ALG_MISC                           (0xff)

/* Internal key subtype ID */
 #define TSIP_PRV_KEY_SUBTYPE_INVALID                (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_AES_128                (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_AES_192                (0x1)
 #define TSIP_PRV_KEY_SUBTYPE_AES_256                (0x2)
 #define TSIP_PRV_KEY_SUBTYPE_AES_NUM                (0x3)
 #define TSIP_PRV_KEY_SUBTYPE_CHACHA_CHACHA20        (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_CHACHA_NUM             (0x1)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1          (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1          (0x1)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1          (0x2)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1          (0x3)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1    (0x4)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1    (0x5)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1    (0x6)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519       (0x7)
 #define TSIP_PRV_KEY_SUBTYPE_ECC_NUM                (0x8)
 #define TSIP_PRV_KEY_SUBTYPE_RSA_1024               (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_RSA_2048               (0x1)
 #define TSIP_PRV_KEY_SUBTYPE_RSA_3072               (0x2)
 #define TSIP_PRV_KEY_SUBTYPE_RSA_4096               (0x3)
 #define TSIP_PRV_KEY_SUBTYPE_RSA_NUM                (0x4)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1              (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224            (0x1)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256            (0x2)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA384            (0x3)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512            (0x4)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512_224        (0x5)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512_256        (0x6)
 #define TSIP_PRV_KEY_SUBTYPE_HMAC_NUM               (0x7)
 #define TSIP_PRV_KEY_SUBTYPE_MISC_KUK               (0x0)
 #define TSIP_PRV_KEY_SUBTYPE_MISC_NUM               (0x1)

/* Internal DKM algorithm ID */
 #define TSIP_PRV_DKM_ALG_INVALID                    (0x0)
 #define TSIP_PRV_DKM_ALG_SHA                        (0x1)
 #define TSIP_PRV_DKM_ALG_HMAC                       (0x2)

/* Internal DKM subtype ID */
 #define TSIP_PRV_DKM_SUBTYPE_INVALID                (0x0)
 #define TSIP_PRV_DKM_SUBTYPE_SHA_256                (0x0)
 #define TSIP_PRV_DKM_SUBTYPE_SHA_384                (0x1)
 #define TSIP_PRV_DKM_SUBTYPE_SHA_NUM                (0x2)
 #define TSIP_PRV_DKM_SUBTYPE_HMAC_SHA256            (0x0)
 #define TSIP_PRV_DKM_SUBTYPE_HMAC_SHA384            (0x1)
 #define TSIP_PRV_DKM_SUBTYPE_HMAC_SHA512            (0x2)
 #define TSIP_PRV_DKM_SUBTYPE_HMAC_NUM               (0x3)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZV
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @ingroup RZV_RENESAS_SECURITY_INTERFACES
 * @defgroup RZV_TSIP_PROTECTED_API TSIP Interface
 * @brief Interface for Renesas Secure IP (TSIP) functions.
 *
 * @section RZV_TSIP_PROTECTED_API_Summary Summary
 * The TSIP interface provides TSIP functionality.
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Key types */
enum e_tsip_key_type
{
    TSIP_KEY_TYPE_INVALID =
        TSIP_PRV_KEY_TYPE_VAL(0, TSIP_PRV_ALG_INVALID, TSIP_PRV_KEY_SUBTYPE_INVALID),                  ///< Invalid key
    TSIP_KEY_TYPE_AES_128 =
        TSIP_PRV_KEY_TYPE_VAL(4, TSIP_PRV_ALG_AES, TSIP_PRV_KEY_SUBTYPE_AES_128),                      ///< AES-128
    TSIP_KEY_TYPE_AES_192 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_AES, TSIP_PRV_KEY_SUBTYPE_AES_192),                      ///< AES-192
    TSIP_KEY_TYPE_AES_256 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_AES, TSIP_PRV_KEY_SUBTYPE_AES_256),                      ///< AES-256
    TSIP_KEY_TYPE_XTS_AES_128 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_XTS_AES, TSIP_PRV_KEY_SUBTYPE_AES_128),                  ///< XTS-AES-128
    TSIP_KEY_TYPE_XTS_AES_256 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_XTS_AES, TSIP_PRV_KEY_SUBTYPE_AES_256),                 ///< XTS-AES-256
    TSIP_KEY_TYPE_CHACHA20 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_CHACHA, TSIP_PRV_KEY_SUBTYPE_CHACHA_CHACHA20),           ///< ChaCha20
    TSIP_KEY_TYPE_ECC_SECP256R1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1),        ///< secp256r1 public key (also known as NIST P-256, prime256v1)
    TSIP_KEY_TYPE_ECC_SECP384R1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(24, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1),        ///< secp384r1 public key (also known as NIST P-384)
    TSIP_KEY_TYPE_ECC_SECP521R1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(40, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1),        ///< secp521r1 public key (also known as NIST P-521)
    TSIP_KEY_TYPE_ECC_SECP256K1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1),        ///< secp256k1 public key
    TSIP_KEY_TYPE_ECC_BRAINPOOLP256R1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1),  ///< brainpoolP256r1 public key
    TSIP_KEY_TYPE_ECC_BRAINPOOLP384R1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(24, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1),  ///< brainpoolP384r1 public key
    TSIP_KEY_TYPE_ECC_BRAINPOOLP512R1_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(32, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1),  ///< brainpoolP512r1 public key
    TSIP_KEY_TYPE_ECC_EDWARDS25519_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_ECC_PUBLIC, TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519),      ///< edwards25519 public key
    TSIP_KEY_TYPE_ECC_SECP256R1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_SECP256R1),        ///< secp256r1 private key (also known as NIST P-256, prime256v1)
    TSIP_KEY_TYPE_ECC_SECP384R1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(12, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_SECP384R1),       ///< secp384r1 private key (also known as NIST P-384)
    TSIP_KEY_TYPE_ECC_SECP521R1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(20, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_SECP521R1),       ///< secp521r1 private key (also known as NIST P-521)
    TSIP_KEY_TYPE_ECC_SECP256K1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_SECP256K1),        ///< secp256k1 private key
    TSIP_KEY_TYPE_ECC_BRAINPOOLP256R1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP256R1),  ///< brainpoolP256r1 private key
    TSIP_KEY_TYPE_ECC_BRAINPOOLP384R1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(12, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP384R1), ///< brainpoolP384r1 private key
    TSIP_KEY_TYPE_ECC_BRAINPOOLP512R1_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_BRAINPOOLP512R1), ///< brainpoolP512r1 private key
    TSIP_KEY_TYPE_ECC_EDWARDS25519_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_ECC_PRIVATE, TSIP_PRV_KEY_SUBTYPE_ECC_EDWARDS25519),     ///< edwards25519 private key
    TSIP_KEY_TYPE_RSA_1024_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(36, TSIP_PRV_ALG_RSA_PUBLIC, TSIP_PRV_KEY_SUBTYPE_RSA_1024),             ///< RSA-1024 public key
    TSIP_KEY_TYPE_RSA_2048_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(68, TSIP_PRV_ALG_RSA_PUBLIC, TSIP_PRV_KEY_SUBTYPE_RSA_2048),             ///< RSA-2048 public key
    TSIP_KEY_TYPE_RSA_3072_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(100, TSIP_PRV_ALG_RSA_PUBLIC, TSIP_PRV_KEY_SUBTYPE_RSA_3072),            ///< RSA-3072 public key
    TSIP_KEY_TYPE_RSA_4096_PUBLIC =
        TSIP_PRV_KEY_TYPE_VAL(132, TSIP_PRV_ALG_RSA_PUBLIC, TSIP_PRV_KEY_SUBTYPE_RSA_4096),            ///< RSA-4096 public key
    TSIP_KEY_TYPE_RSA_1024_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(64, TSIP_PRV_ALG_RSA_PRIVATE, TSIP_PRV_KEY_SUBTYPE_RSA_1024),            ///< RSA-1024 private key
    TSIP_KEY_TYPE_RSA_2048_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(128, TSIP_PRV_ALG_RSA_PRIVATE, TSIP_PRV_KEY_SUBTYPE_RSA_2048),           ///< RSA-2048 private key
    TSIP_KEY_TYPE_RSA_3072_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(192, TSIP_PRV_ALG_RSA_PRIVATE, TSIP_PRV_KEY_SUBTYPE_RSA_3072),           ///< RSA-3072 private key
    TSIP_KEY_TYPE_RSA_4096_PRIVATE =
        TSIP_PRV_KEY_TYPE_VAL(256, TSIP_PRV_ALG_RSA_PRIVATE, TSIP_PRV_KEY_SUBTYPE_RSA_4096),           ///< RSA-4096 private key
    TSIP_KEY_TYPE_HMAC_SHA1 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA1),                   ///< HMAC-SHA1
    TSIP_KEY_TYPE_HMAC_SHA224 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA224),                 ///< HMAC-SHA224
    TSIP_KEY_TYPE_HMAC_SHA256 =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256),                 ///< HMAC-SHA256
    TSIP_KEY_TYPE_HMAC_SHA384 =
        TSIP_PRV_KEY_TYPE_VAL(12, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA384),                ///< HMAC-SHA384
    TSIP_KEY_TYPE_HMAC_SHA512 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512),                ///< HMAC-SHA512
    TSIP_KEY_TYPE_HMAC_SHA512_224 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512_224),            ///< HMAC-SHA512/224
    TSIP_KEY_TYPE_HMAC_SHA512_256 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512_256),            ///< HMAC-SHA512/256
    TSIP_KEY_TYPE_KDF_HMAC_SHA256 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_KDF_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA256),            ///< HMAC-SHA256
    TSIP_KEY_TYPE_KDF_HMAC_SHA384 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_KDF_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA384),            ///< HMAC-SHA384
    TSIP_KEY_TYPE_KDF_HMAC_SHA512 =
        TSIP_PRV_KEY_TYPE_VAL(16, TSIP_PRV_ALG_KDF_HMAC, TSIP_PRV_KEY_SUBTYPE_HMAC_SHA512),            ///< HMAC-SHA512
    TSIP_KEY_TYPE_KUK =
        TSIP_PRV_KEY_TYPE_VAL(8, TSIP_PRV_ALG_MISC, TSIP_PRV_KEY_SUBTYPE_MISC_KUK),                    ///< Key Update Key (KUK)
};

/** Key types */
typedef enum e_tsip_key_type tsip_key_type_t;

/** Block cipher modes of operation for AES */
enum e_tsip_aes_cipher_mode
{
    TSIP_AES_CIPHER_MODE_ECB_ENC,            ///< Electronic Codebook (ECB) mode encryption
    TSIP_AES_CIPHER_MODE_ECB_DEC,            ///< Electronic Codebook (ECB) mode decryption
    TSIP_AES_CIPHER_MODE_CBC_ENC,            ///< Cipher Block Chaining (CBC) mode encryption
    TSIP_AES_CIPHER_MODE_CBC_DEC,            ///< Cipher Block Chaining (CBC) mode decryption
    TSIP_AES_CIPHER_MODE_CTR,                ///< Counter (CTR) mode encryption or decryption
    TSIP_AES_CIPHER_MODE_XTS_ENC,            ///< XEX-based tweaked-codebook mode with ciphertext stealing (XTS) encryption
    TSIP_AES_CIPHER_MODE_XTS_DEC,            ///< XEX-based tweaked-codebook mode with ciphertext stealing (XTS) decryption

    TSIP_AES_CIPHER_MODE_CBC_ENC_WRAPPED_IV, ///< Cipher Block Chaining (CBC) mode encryption with wrapped IV
    TSIP_AES_CIPHER_MODE_CBC_DEC_WRAPPED_IV, ///< Cipher Block Chaining (CBC) mode decryption with wrapped IV
};

/** Block cipher modes of operation for AES */
typedef enum e_tsip_aes_cipher_mode tsip_aes_cipher_mode_t;

/** AEAD modes of operation for AES */
enum e_tsip_aes_aead_mode
{
    TSIP_AES_AEAD_MODE_GCM_ENC,            ///< Galois/Counter Mode (GCM) encryption
    TSIP_AES_AEAD_MODE_GCM_DEC,            ///< Galois/Counter Mode (GCM) decryption
    TSIP_AES_AEAD_MODE_CCM_ENC,            ///< Counter with CBC-MAC (CCM) encryption
    TSIP_AES_AEAD_MODE_CCM_DEC,            ///< Counter with CBC-MAC (CCM) decryption

    TSIP_AES_AEAD_MODE_GCM_ENC_WRAPPED_IV, ///< Galois/Counter Mode (GCM) encryption with wrapped IV
    TSIP_AES_AEAD_MODE_GCM_DEC_WRAPPED_IV, ///< Galois/Counter Mode (GCM) decryption with wrapped IV
};

/** AEAD modes of operation for AES */
typedef enum e_tsip_aes_aead_mode tsip_aes_aead_mode_t;

/** ChaCha20-Poly1305 mode */
enum e_tsip_chacha_poly_mode
{
    TSIP_CHACHA20_POLY1305_MODE_ENC,   ///< ChaCha20-Poly1305 encryption
    TSIP_CHACHA20_POLY1305_MODE_DEC,   ///< ChaCha20-Poly1305 decryption
};

/** ChaCha20-Poly1305 mode */
typedef enum e_tsip_chacha_poly_mode tsip_chacha_poly_mode_t;

/** MAC modes of operation for AES */
enum e_tsip_aes_mac_mode
{
    TSIP_AES_MAC_MODE_CMAC,            ///< Cipher-based MAC (CMAC)
};

/** MAC modes of operation for AES */
typedef enum e_tsip_aes_mac_mode tsip_aes_mac_mode_t;

/** Hash type */
enum e_tsip_hash_type
{
    TSIP_HASH_TYPE_SHA1,               ///< SHA-1
    TSIP_HASH_TYPE_SHA224,             ///< SHA-224
    TSIP_HASH_TYPE_SHA256,             ///< SHA-256
    TSIP_HASH_TYPE_SHA384,             ///< SHA-384
    TSIP_HASH_TYPE_SHA512,             ///< SHA-512
    TSIP_HASH_TYPE_SHA512_224,         ///< SHA-512/224
    TSIP_HASH_TYPE_SHA512_256,         ///< SHA-512/256
    TSIP_HASH_TYPE_SHA3_224,           ///< SHA3-224
    TSIP_HASH_TYPE_SHA3_256,           ///< SHA3-256
    TSIP_HASH_TYPE_SHA3_384,           ///< SHA3-384
    TSIP_HASH_TYPE_SHA3_512,           ///< SHA3-512

    TSIP_HASH_TYPE_NUM                 // Number of hash types
};

/** Hash type */
typedef enum e_tsip_hash_type tsip_hash_type_t;

/** MGF type */
enum e_tsip_mgf_type
{
    TSIP_MGF_TYPE_MGF1_SHA1       = TSIP_HASH_TYPE_SHA1,       ///< MGF1 with SHA-1
    TSIP_MGF_TYPE_MGF1_SHA224     = TSIP_HASH_TYPE_SHA224,     ///< MGF1 with SHA-224
    TSIP_MGF_TYPE_MGF1_SHA256     = TSIP_HASH_TYPE_SHA256,     ///< MGF1 with SHA-256
    TSIP_MGF_TYPE_MGF1_SHA384     = TSIP_HASH_TYPE_SHA384,     ///< MGF1 with SHA-384
    TSIP_MGF_TYPE_MGF1_SHA512     = TSIP_HASH_TYPE_SHA512,     ///< MGF1 with SHA-512
    TSIP_MGF_TYPE_MGF1_SHA512_224 = TSIP_HASH_TYPE_SHA512_224, ///< MGF1 with SHA-512/224
    TSIP_MGF_TYPE_MGF1_SHA512_256 = TSIP_HASH_TYPE_SHA512_256  ///< MGF1 with SHA-512/256
};

/** MGF type */
typedef enum e_tsip_mgf_type tsip_mgf_type_t;

/** RSA salt length */
enum e_tsip_rsa_salt_length
{
    TSIP_RSA_SALT_LENGTH_AUTO = 0xFFFFFFFFU, ///< When signing, the salt length is set to @ref TSIP_RSA_SALT_LENGTH_MAX or @ref TSIP_RSA_SALT_LENGTH_HASH, whichever is shorter. When verifying, the salt length is detected automatically.
    TSIP_RSA_SALT_LENGTH_HASH = 0xFFFFFFFEU, ///< The salt length is set to the hash length.
    TSIP_RSA_SALT_LENGTH_MAX  = 0xFFFFFFFDU, ///< The salt length is set to emLen - hLen - 2, where emLen is the same as the key length and hLen is the hash length.
};

/** RSA salt length */
typedef enum e_tsip_rsa_salt_length tsip_rsa_salt_length_t;

/* State that specifies functions that can be called next. This enum is private. */
enum e_tsip_user_handle_state
{
    TSIP_USER_HANDLE_STATE_INIT,       // Init function can be called.
    TSIP_USER_HANDLE_STATE_RESUME,     // Resume
    TSIP_USER_HANDLE_STATE_UPDATE      // Update
};

/* State that specifies functions that can be called next. This enum is private. */
typedef enum e_tsip_user_handle_state tsip_user_handle_state_t;

/** IV data types */
enum e_tsip_initial_vector_type
{
    TSIP_INITIAL_VECTOR_TYPE_AES_16_BYTE,    ///< Wrapped AES initial vector (unprocessed)
    TSIP_INITIAL_VECTOR_TYPE_AES_TLS12_AEAD, ///< Wrapped AES nonce (TLS1.2 AES AEAD)
    TSIP_INITIAL_VECTOR_TYPE_AES_TLS13_AEAD, ///< Wrapped AES nonce (TLS1.3 AES AEAD)
};

/** IV data types */
typedef enum e_tsip_initial_vector_type tsip_initial_vector_type_t;

/** Channel number of on-the-fly decryption/encryption module. */
enum e_tsip_otf_channel
{
    TSIP_OTF_CHANNEL_0,                ///< Channel 0
    TSIP_OTF_CHANNEL_1,                ///< Channel 1
    TSIP_OTF_CHANNEL_2,                ///< Channel 2
    TSIP_OTF_CHANNEL_NUM               // Number of channels
};

/** Channel number of on-the-fly decryption/encryption module. */
typedef enum e_tsip_otf_channel tsip_otf_channel_t;

/** Wrapped key structure for all supported algorithms. */
struct st_tsip_wrapped_key
{
    tsip_key_type_t type;              ///< Key type
    void          * p_value;           ///< Key value
};

/** Wrapped key structure for all supported algorithms. */
typedef struct st_tsip_wrapped_key tsip_wrapped_key_t;

/** Wrapped Derived Keying Material (DKM) structure for KDF APIs. */
struct st_tsip_wrapped_dkm
{
    uint8_t  alg;                      // Internal algorithm ID
    uint8_t  subtype;                  // Internal key type ID
    uint8_t  info[2];                  // Reserved area
    uint32_t block_length;             // DKM block length
    uint32_t blocks;                   // Number of DKM blocks

    uint8_t value[];                   // Variable length array to store the data value
};

/** Wrapped Derived Keying Material (DKM) structure for KDF APIs. */
typedef struct st_tsip_wrapped_dkm tsip_wrapped_dkm_t;

/** Allocate an instance specific handle to pass into the API calls. */
typedef void tsip_sha_handle_abstractor_t;

/** Allocate an instance specific handle to pass into the API calls. */
typedef void tsip_hmac_handle_abstractor_t;

/** Allocate an instance specific handle to pass into the API calls. */
typedef void tsip_kdf_sha_handle_abstractor_t;

/** Allocate an instance specific handle to pass into the API calls. */
typedef void tsip_kdf_hmac_handle_abstractor_t;

/** Allocate an instance specific handle to pass into the API calls. */
typedef void tsip_wrapped_secret_abstractor_t;

/** Allocate an instance specific handle to pass into the API calls. */
typedef void tsip_verified_cert_info_abstractor_t;

/** TSIP Control block. Allocate an instance specific control block to pass into the API calls. */
typedef void tsip_ctrl_t;

/** User configuration structure, used in open function */
struct st_tsip_cfg
{
    void const * p_extend;             ///< Hardware-dependent configuration
};

/** User configuration structure, used in open function */
typedef struct st_tsip_cfg tsip_cfg_t;

/** TSIP driver structure.  General TSIP functions implemented at the HAL layer follow this API. */
struct st_tsip_api
{
    /**
     * Enables use of Renesas Secure IP functionality.
     *
     * @param[in,out] p_ctrl Pointer to control block.
     * @param[in]     p_cfg  Pointer to configuration structure.
     */
    fsp_err_t (* open)(tsip_ctrl_t * const p_ctrl, tsip_cfg_t const * const p_cfg);

    /**
     * Disables use of Renesas Secure IP functionality.
     *
     * @param[in,out]   p_ctrl     Pointer to control block.
     */
    fsp_err_t (* close)(tsip_ctrl_t * const p_ctrl);

    /**
     * Generates a 128-bit random number.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_random 128bit random numbers.
     */
    fsp_err_t (* randomNumberGenerate)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_random);

    /**
     * Generate a wrapped symmetric key from a random number.
     * In this API, user key input is unnecessary.
     * By encrypting data using the wrapped key is output by this API, dead copying of data can be prevented.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in,out] p_wrapped_key Pointer to destination of wrapped key. The length depends on key type. Refer "Key Size Table".
     */
    fsp_err_t (* keyGenerate)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t * const p_wrapped_key);

    /**
     * Generate a wrapped asymmetric key pair from a random number. In this API, user key input is unnecessary.
     * By encrypting data using the wrapped key is output by this API, dead copying of data can be prevented.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in,out] p_wrapped_public_key  Key index for Public Key. The length depends on the key type. Refer "Key Size Table".
     * @param[in,out] p_wrapped_private_key Key index for Private Key. The length depends on the key type. Refer "Key Size Table".
     */
    fsp_err_t (* keyPairGenerate)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t * const p_wrapped_public_key,
                                  tsip_wrapped_key_t * const p_wrapped_private_key);

    /**
     * Decrypt the encrypted user key with Key Update Key (KUK) and wrap it with the Hardware Unique Key (HUK).
     *
     * @param[in,out] p_ctrl           Pointer to control block.
     * @param[in]     p_key_update_key Pointer to Key Update Key.
     * @param[in]     p_initial_vector Initialization vector when generating encrypted_key.
     *                                 The length is 16 bytes.
     * @param[in]     p_encrypted_key  Encrypted user key. The length depends on the key type. Refer "Key Size Table".
     * @param[in,out] p_wrapped_key    Pointer to destination of wrapped key. The length depends on key type. Refer "Key Size Table".
     */
    fsp_err_t (* encryptedKeyWrap)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_key_update_key,
                                   void const * const p_initial_vector, void const * const p_encrypted_key,
                                   tsip_wrapped_key_t * const p_wrapped_key);

    /**
     * This function provides Key Wrap algorithm compliant with RFC3394.
     * Using p_wrapped_kek to wrap p_wrapped_target_key, and output the result to p_rfc3394_wrapped_target_key.
     *
     * @param[in,out] p_ctrl                       Pointer to control block.
     * @param[in]     p_wrapped_kek                Pointer to wrapped key-encryption-key used to RFC3394-wrap the target key.
     * @param[in]     p_wrapped_target_key         Pointer to wrapped target key to be RFC3394-wrapped.
     * @param[out]    p_rfc3394_wrapped_target_key Pointer to destination of RFC3394-wrapped target key.
     */
    fsp_err_t (* rfc3394_KeyWrap)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_kek,
                                  tsip_wrapped_key_t const * const p_wrapped_target_key,
                                  uint8_t * const p_rfc3394_wrapped_target_key);

    /**
     * This function provides Key Unwrap algorithm compliant with RFC3394.
     * Using p_wrapped_kek to unwrap p_rfc3394_wrapped_target_key, and output the result to p_wrapped_target_key.
     *
     * @param[in,out] p_ctrl                       Pointer to control block.
     * @param[in]     p_wrapped_kek                Pointer to wrapped key-encryption-key used to RFC3394-unwrap the target key.
     * @param[in]     p_rfc3394_wrapped_target_key Pointer to AES-wrapped target key to be RFC3394-unwrapped.
     * @param[in,out] p_wrapped_target_key         Pointer to destination of RFC3394-unwrapped target key.
     */
    fsp_err_t (* rfc3394_KeyUnwrap)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_kek,
                                    uint8_t const * const p_rfc3394_wrapped_target_key,
                                    tsip_wrapped_key_t * const p_wrapped_target_key);

    /**
     * Exports public key parameters from a wrapped key.
     *
     * @param[in]  p_wrapped_public_key Key index for Public Key. The length depends on the key type. Refer "Key Size Table".
     * @param[out] p_raw_public_key     Pointer to destination of raw public key. The length depends on the key length.
     */
    fsp_err_t (* publicKeyExport)(tsip_wrapped_key_t const * const p_wrapped_public_key,
                                  uint8_t * const                  p_raw_public_key);

    /**
     * Set parameters of AES cipher.
     *
     * @param[in,out] p_ctrl           Pointer to control block.
     * @param[in]     mode             Block cipher modes of operation for AES.
     * @param[in]     p_wrapped_key    Pointer to wrapped key of AES or XTS-AES key.
     * @param[in]     p_initial_vector Pointer to initialization vector (IV) or nonce. The length is 16 bytes.
     *                                 @arg [ECB] Not required
     *                                 @arg [CBC][XTS] IV
     *                                 @arg [CTR] Nonce
     */
    fsp_err_t (* aesCipherInit)(tsip_ctrl_t * const p_ctrl, tsip_aes_cipher_mode_t const mode,
                                tsip_wrapped_key_t const * const p_wrapped_key, uint8_t const * const p_initial_vector);

    /**
     * Encrypt plaintext.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[in]     p_input  Pointer to input text. The length is given as the argument.
     * @param[out]    p_output Pointer to destination of output text. The length is given as the argument.
     * @param[in]     length   Byte length of input and output.
     *                         @arg [ECB][CBC][CTR] Must be 0 or a multiple of 16.
     *                         @arg [XTS] Must be 0 or greater than or equal to 16.
     *                         After an integer not divisible by 16 is input, update can no longer be executed.
     */
    fsp_err_t (* aesCipherUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_input, uint8_t * const p_output,
                                  uint32_t const length);

    /**
     * Finalize AES operation.
     *
     * @param[in,out] p_ctrl Pointer to control block.
     */
    fsp_err_t (* aesCipherFinish)(tsip_ctrl_t * const p_ctrl);

    /**
     * Prepares an AES-AEAD function.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     mode          AEAD mode of operation.
     * @param[in]     p_wrapped_key Pointer to wrapped key of AES key.
     * @param[in]     p_nonce       Pointer to nonce. The length is nonce_length.
     * @param[in]     nonce_length  Byte length of nonce. Input 1 or more.
     */
    fsp_err_t (* aesAeadInit)(tsip_ctrl_t * const p_ctrl, tsip_aes_aead_mode_t const mode,
                              tsip_wrapped_key_t const * const p_wrapped_key, uint8_t const * const p_nonce,
                              uint32_t const nonce_length);

    /**
     * Set text and tag lengths for specific mode.
     *
     * @param[in,out] p_ctrl            Pointer to control block.
     * @param[in]     total_aad_length  Total AAD length.
     * @param[in]     total_text_length Total input and output text length.
     * @param[in]     tag_length        Input or output tag length.
     */
    fsp_err_t (* aesAeadLengthsSet)(tsip_ctrl_t * const p_ctrl, uint32_t const total_aad_length,
                                    uint32_t const total_text_length, uint32_t const tag_length);

    /**
     * Inputs additional authentication data.
     *
     * @param[in,out] p_ctrl     Pointer to control block.
     * @param[in]     p_aad      Additional authentication data. The length depends on aad_length.
     * @param[in]     aad_length Byte length of additional authentication data (0 or more bytes).
     *                           After starting input of plaintext, this value must always be 0.
     */
    fsp_err_t (* aesAeadAadUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_aad, uint32_t const aad_length);

    /**
     * Inputs test and executes encryption and decryption.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[in]     p_input         Pointer to input text. The length is input_length.
     * @param[in]     input_length    Byte length of input text (0 or more bytes).
     * @param[out]    p_output        Pointer to destination of output text. The length is p_output_length.
     * @param[out]    p_output_length Pointer to destination of output text length.
     */
    fsp_err_t (* aesAeadUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_input, uint32_t const input_length,
                                uint8_t * const p_output, uint32_t * const p_output_length);

    /**
     * Finalizes an AES-GCM encryption.
     *
     * If there is 16-byte fractional data indicated by the total data length of the value of p_plain that was input by
     * R_TSIP_AES_GCM_EncryptUpdate(), this API will output the result of encrypting that fractional data to p_cipher.
     * Here, the portion that does not reach 16 bytes will be padded with zeros.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[out]    p_output        Pointer to destination of output text. The fractional block is output.
     * @param[out]    p_output_length Pointer to destination of output text length.
     * @param[out]    p_tag           Pointer to destination of tag for authentication.
     *                                GCM : The length is 16 bytes.
     *                                      *If a different tag length is required, truncate the 16-byte tag
     *                                        to the required tag length (NIST SP800-38D 7.1).
     *                                CCM : The length is the value set by the API R_TSIP_AES_AEAD_LengthsSet().
     */
    fsp_err_t (* aesAeadFinish)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_output, uint32_t * const p_output_length,
                                uint8_t * const p_tag);

    /**
     * Finalizes an AES-GCM decryption.
     *
     * If there is 16-byte fractional data indicated by the total data length of the value of p_cipher that was input by
     * R_TSIP_AES_GCM_DecryptUpdate(), this API will output the result of decrypting that fractional data to p_cipher.
     * Here, the portion that does not reach 16 bytes will be padded with zeros.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[out]    p_output        Pointer to destination of decrypted data.
     * @param[out]    p_output_length Pointer to destination of decrypted data length.
     * @param[in]     p_tag           Pointer to destination of tag for authentication. The length depends on tag_length.
     * @param[in]     tag_length      Byte length of tag. Must be 1 to 16.
     */
    fsp_err_t (* aesAeadVerify)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_output, uint32_t * const p_output_length,
                                uint8_t const * const p_tag, uint32_t const tag_length);

    /**
     * Prepares an AES-MAC generation and verification.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     mode          MAC mode of operation
     * @param[in]     p_wrapped_key Pointer to wrapped key of AES key.
     */
    fsp_err_t (* aesMacInit)(tsip_ctrl_t * const p_ctrl, tsip_aes_mac_mode_t const mode,
                             tsip_wrapped_key_t const * const p_wrapped_key);

    /**
     * Input message.
     * Inside this function, the data that is input by the user is buffered until the input value of p_message exceeds 16 bytes.
     * If the input value, p_message, is not a multiple of 16 bytes, it will be padded within the function.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     */
    fsp_err_t (* aesMacUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message,
                               uint32_t const message_length);

    /**
     * Finalizes an AES-CMAC generation.
     *
     * @param[in,out] p_ctrl Pointer to control block.
     * @param[out]    p_mac  Pointer to destination of MAC. The length is 16 bytes.
     */
    fsp_err_t (* aesMacSignFinish)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_mac);

    /** Finalizes an AES-CMAC verification.
     *
     * @param[in,out] p_ctrl     Pointer to control block.
     * @param[in]     p_mac      Pointer to MAC. The length depends on mac_length.
     * @param[in]     mac_length Byte length of MAC. Must be 2 to 16.
     */
    fsp_err_t (* aesMacVerifyFinish)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_mac,
                                     uint32_t const mac_length);

    /**
     * Prepares a ChaCha20 function.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     p_wrapped_key Pointer to wrapped key of ChaCha20 key.
     * @param[in]     p_nonce       Pointer to nonce. The length is 12 bytes.
     * @param[in]     counter       32-bit initial counter. This is usually zero.
     */
    fsp_err_t (* chacha20Init)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_key,
                               uint8_t const * const p_nonce, uint32_t const counter);

    /**
     * Encrypts plaintext or decrypts ciphertext.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[in]     p_input         Pointer to input text. The length is input_length.
     * @param[in]     input_length    Byte length of input text (0 or more bytes).
     * @param[out]    p_output        Pointer to destination of output text. The length is p_output_length.
     * @param[out]    p_output_length Pointer to destination of output text length.
     */
    fsp_err_t (* chacha20Update)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_input, uint32_t const input_length,
                                 uint8_t * const p_output, uint32_t * const p_output_length);

    /**
     * Finalize ChaCha20 operation.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[out]    p_output        Pointer to destination of output text. The fractional block is output.
     * @param[out]    p_output_length Pointer to destination of output text length.
     */
    fsp_err_t (* chacha20Finish)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_output,
                                 uint32_t * const p_output_length);

    /**
     * Prepares a ChaCha20-Poly1305 function.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     mode          AEAD mode of operation.
     * @param[in]     p_wrapped_key Pointer to wrapped key of AES key.
     * @param[in]     p_nonce       Pointer to nonce. The length is nonce_length.
     * @param[in]     nonce_length  Byte length of nonce. Input 1 or more.
     */
    fsp_err_t (* chacha20Poly1305Init)(tsip_ctrl_t * const p_ctrl, tsip_chacha_poly_mode_t const mode,
                                       tsip_wrapped_key_t const * const p_wrapped_key, uint8_t const * const p_nonce,
                                       uint32_t const nonce_length);

    /**
     * Inputs Additional Authentication Data (AAD).
     *
     * @param[in,out] p_ctrl     Pointer to control block.
     * @param[in]     p_aad      Additional authentication data. The length depends on aad_length.
     * @param[in]     aad_length Byte length of additional authentication data (0 or more bytes).
     *                           After starting input of plaintext, this value must always be 0.
     */
    fsp_err_t (* chacha20Poly1305AadUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_aad,
                                            uint32_t const aad_length);

    /**
     * Encrypts plaintext or decrypts ciphertext.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[in]     p_input         Pointer to input text. The length is input_length.
     * @param[in]     input_length    Byte length of input text (0 or more bytes).
     * @param[out]    p_output        Pointer to destination of output text. The length is p_output_length.
     * @param[out]    p_output_length Pointer to destination of output text length.
     */
    fsp_err_t (* chacha20Poly1305Update)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_input,
                                         uint32_t const input_length, uint8_t * const p_output,
                                         uint32_t * const p_output_length);

    /**
     * Finalizes a ChaCha20-Poly1305 encryption.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[out]    p_output        Pointer to destination of output text. The fractional block is output.
     * @param[out]    p_output_length Pointer to destination of output text length.
     * @param[out]    p_tag           Pointer to destination of tag for authentication. The length is 16 bytes.
     */
    fsp_err_t (* chacha20Poly1305Finish)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_output,
                                         uint32_t * const p_output_length, uint8_t * const p_tag);

    /**
     * Finalizes a ChaCha20-Poly1305 decryption.
     *
     * @param[in,out] p_ctrl          Pointer to control block.
     * @param[out]    p_output        Pointer to destination of decrypted data.
     * @param[out]    p_output_length Pointer to destination of decrypted data length.
     * @param[in]     p_tag           Pointer to destination of tag for authentication. The length depends on tag_length.
     * @param[in]     tag_length      Byte length of tag. Must be 16.
     */
    fsp_err_t (* chacha20Poly1305Verify)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_output,
                                         uint32_t * const p_output_length, uint8_t const * const p_tag,
                                         uint32_t const tag_length);

    /**
     * Signs a hashed message. The message hash should be generated in advance.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in]     p_wrapped_private_key Pointer to wrapped key of ECC private key.
     * @param[in]     p_hash                Pointer to hash value. The length is as same as the key length.
     * @param[out]    p_signature           Pointer to destination of signature (r, s).
     *                                      The length is twice as long as the key length.
     */
    fsp_err_t (* ecdsaSign)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                            uint8_t const * const p_hash, uint8_t * const p_signature);

    /**
     * Verifies a hashed message. The message hash should be generated in advance.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_wrapped_public_key Pointer to wrapped key of ECC public key.
     * @param[in]     p_hash               Pointer to hash value. The length is as same as the key length.
     * @param[in]     p_signature          Pointer to signature (r, s). The length is twice as long as the key length.
     */
    fsp_err_t (* ecdsaVerify)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_public_key,
                              uint8_t const * const p_hash, uint8_t const * const p_signature);

    /**
     * Sign the message using EdDSA.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in]     p_wrapped_private_key Pointer to wrapped key of ECC private key.
     * @param[in]     p_wrapped_public_key  Pointer to wrapped key of ECC public key.
     * @param[in]     p_message             Pointer to message. The length is message_length.
     * @param[in]     message_length        Byte length of message.
     * @param[out]    p_signature           Pointer to destination of signature (r, s).
     *                                      The length is twice as long as the key length.
     */
    fsp_err_t (* eddsaSign)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                            tsip_wrapped_key_t const * const p_wrapped_public_key, uint8_t const * const p_message,
                            uint64_t const message_length, uint8_t * const p_signature);

    /**
     * Verifies the message using EdDSA.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_wrapped_public_key Pointer to wrapped key of ECC public key.
     * @param[in]     p_message            Pointer to message. The length is message_length.
     * @param[in]     message_length       Byte length of message.
     * @param[in]     p_signature          Pointer to signature (r, s). The length is twice as long as the key length.
     */
    fsp_err_t (* eddsaVerify)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_public_key,
                              uint8_t const * const p_message, uint64_t const message_length,
                              uint8_t const * const p_signature);

    /**
     * Computes ECDH secret with wrapped private key and wrapped public key.
     *
     * @param[in,out] p_ctrl                 Pointer to control block.
     * @param[in]     p_wrapped_private_key  Wrapped secp256r1 private key.
     * @param[in]     p_wrapped_public_key   Wrapped secp256r1 public key.
     * @param[out]    p_wrapped_secret       Pointer to destination of wrapped secret
     */
    fsp_err_t (* ecdhKeyAgree)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                               tsip_wrapped_key_t const * const p_wrapped_public_key,
                               tsip_wrapped_secret_abstractor_t * const p_wrapped_secret);

    /**
     * Computes ECDH secret with wrapped private key and plain public key.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in]     p_wrapped_private_key Wrapped secp256r1 private key.
     * @param[in]     p_plain_public_key    Plain secp256r1 public key.
     * @param[out]    p_wrapped_secret      Pointer to destination of wrapped secret.
     */
    fsp_err_t (* ecdhPlainKeyAgree)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                                    uint8_t const * const p_plain_public_key,
                                    tsip_wrapped_secret_abstractor_t * const p_wrapped_secret);

    /**
     * Encrypts plaintext with raw RSA.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_wrapped_public_key Pointer to wrapped key of RSA public key.
     * @param[in]     p_plain              Pointer to plaintext. The length is as same as the key length.
     * @param[out]    p_cipher             Pointer to destination of ciphertext. The length is as same as the key length.
     */
    fsp_err_t (* rsaEncrypt)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_public_key,
                             uint8_t const * const p_plain, uint8_t * const p_cipher);

    /**
     * Decrypts ciphertext with raw RSA.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in]     p_wrapped_private_key Pointer to wrapped key of RSA private key.
     * @param[in]     p_cipher              Pointer to ciphertext. The length is as same as the key length.
     * @param[out]    p_plain               Pointer to destination of plaintext. The length is as same as the key length.
     */
    fsp_err_t (* rsaDecrypt)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                             uint8_t const * const p_cipher, uint8_t * const p_plain);

    /**
     * Encrypts plaintext with RSAES-PKCS1-v1_5.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_wrapped_public_key Pointer to wrapped key of RSA public key.
     * @param[in]     p_plain              Pointer to plaintext.
     * @param[in]     plain_length         Length of plaintext.
     * @param[out]    p_cipher             Pointer to destination of ciphertext. The length is as same as the key length.
     */
    fsp_err_t (* rsaesPkcs1V15Encrypt)(tsip_ctrl_t * const p_ctrl,
                                       tsip_wrapped_key_t const * const p_wrapped_public_key,
                                       uint8_t const * const p_plain, uint32_t const plain_length,
                                       uint8_t * const p_cipher);

    /**
     * Decrypts with RSAES-PKCS1-v1_5.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in]     p_wrapped_private_key Pointer to wrapped key of RSA private key.
     * @param[in]     p_cipher              Pointer to ciphertext. The length is as same as the key length.
     * @param[out]    p_plain               Pointer to destination of plaintext.
     * @param[out]    p_plain_length        Pointer to destination of actual plaintext length.
     * @param[in]     plain_buffer_length   Length of plaintext destination. It must be equal to or greater than *p_plain_length.
     */
    fsp_err_t (* rsaesPkcs1V15Decrypt)(tsip_ctrl_t * const p_ctrl,
                                       tsip_wrapped_key_t const * const p_wrapped_private_key,
                                       uint8_t const * const p_cipher, uint8_t * const p_plain,
                                       uint32_t * const p_plain_length, uint32_t const plain_buffer_length);

    /**
     * Encrypts plaintext with RSAES-OAEP.
     *
     * @param[in,out] p_ctrl                   Pointer to control block.
     * @param[in]     p_wrapped_public_key     Pointer to wrapped key of RSA public key.
     * @param[in]     hash_function            Hash function for label.
     * @param[in]     mask_generation_function Mask generation function in EME-OAEP encoding.
     * @param[in]     p_label                  Pointer to label. If label_length != 0, p_label must not be NULL.
     * @param[in]     label_length             Length of label. Please set 0 or more.
     * @param[in]     p_plain                  Pointer to plaintext.
     * @param[in]     plain_length             Length of plaintext.
     * @param[out]    p_cipher                 Pointer to destination of ciphertext. The length is as same as the key length.
     */
    fsp_err_t (* rsaesOaepEncrypt)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_public_key,
                                   tsip_hash_type_t const hash_function, tsip_mgf_type_t const mask_generation_function,
                                   uint8_t const * const p_label,
                                   uint32_t const label_length, uint8_t const * const p_plain,
                                   uint32_t const plain_length, uint8_t * const p_cipher);

    /**
     * Decrypts ciphertext with RSAES-OAEP.
     *
     * @param[in,out] p_ctrl                   Pointer to control block.
     * @param[in]     p_wrapped_private_key    Pointer to wrapped key of RSA private key.
     * @param[in]     hash_function            Hash function for label.
     * @param[in]     mask_generation_function Mask generation function in EME-OAEP encoding.
     * @param[in]     p_label                  Pointer to label. If label_length != 0, p_label must not be NULL.
     * @param[in]     label_length             Length of label. Please set 0 or more.
     * @param[in]     p_cipher                 Pointer to ciphertext. The length is as same as the key length.
     * @param[out]    p_plain                  Pointer to destination of plaintext.
     * @param[out]    p_plain_length           Pointer to destination of actual plaintext length.
     * @param[in]     plain_buffer_length      Length of plaintext destination. It must be equal to or greater than
     *                                         *p_plain_length.
     */
    fsp_err_t (* rsaesOaepDecrypt)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                                   tsip_hash_type_t const hash_function, tsip_mgf_type_t const mask_generation_function,
                                   uint8_t const * const p_label,
                                   uint32_t const label_length, uint8_t const * const p_cipher, uint8_t * const p_plain,
                                   uint32_t * const p_plain_length, uint32_t const plain_buffer_length);

    /**
     * Signs message with RSASSA-PKCS1-v1_5.
     *
     * @param[in,out] p_ctrl                Pointer to control block.
     * @param[in]     p_wrapped_private_key Pointer to wrapped key of RSA private key.
     * @param[in]     hash_function         Hash function in EMSA-PKCS1-v1_5.
     * @param[in]     p_hash                Pointer to input hash.
     * @param[out]    p_signature           Pointer to destination of signature.
     */
    fsp_err_t (* rsassaPkcs1V15Sign)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                                     tsip_hash_type_t const hash_function, uint8_t const * const p_hash,
                                     uint8_t * const p_signature);

    /**
     * Verifies signature with RSASSA-PKCS1-v1_5.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_wrapped_public_key Pointer to wrapped key of RSA public key.
     * @param[in]     hash_function        Hash function in EMSA-PKCS1-v1_5.
     * @param[in]     p_hash               Pointer to input hash.
     * @param[in]     p_signature          Pointer to input signature.
     */
    fsp_err_t (* rsassaPkcs1V15Verify)(tsip_ctrl_t * const p_ctrl,
                                       tsip_wrapped_key_t const * const p_wrapped_public_key,
                                       tsip_hash_type_t const hash_function,
                                       uint8_t const * const p_hash, uint8_t const * const p_signature);

    /**
     * Signs message with RSASSA-PSS.
     *
     * @param[in,out] p_ctrl                   Pointer to control block.
     * @param[in]     p_wrapped_private_key    Pointer to wrapped key of RSA private key.
     * @param[in]     hash_function            Hash function in EMSA-PSS-ENCODE.
     * @param[in]     mask_generation_function Mask generation function in EMSA-PSS-ENCODE.
     * @param[in]     salt_length              Salt length.
     * @param[in]     p_hash                   Pointer to input hash.
     * @param[out]    p_signature              Pointer to destination of signature.
     */
    fsp_err_t (* rsassaPssSign)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_private_key,
                                tsip_hash_type_t const hash_function, tsip_mgf_type_t const mask_generation_function,
                                uint32_t const salt_length,
                                uint8_t const * const p_hash, uint8_t * const p_signature);

    /**
     * Verifies signature with RSASSA-PSS.
     *
     * @param[in,out] p_ctrl                   Pointer to control block.
     * @param[in]     p_wrapped_public_key     Pointer to wrapped key of RSA public key.
     * @param[in]     hash_function            Hash function in EMSA-PSS-VERIFY.
     * @param[in]     mask_generation_function Mask generation function in EMSA-PSS-VERIFY.
     * @param[in]     salt_length              Salt length.
     * @param[in]     p_hash                   Pointer to input hash.
     * @param[in]     p_signature              Pointer to input signature.
     */
    fsp_err_t (* rsassaPssVerify)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_public_key,
                                  tsip_hash_type_t const hash_function, tsip_mgf_type_t const mask_generation_function,
                                  uint32_t const salt_length,
                                  uint8_t const * const p_hash, uint8_t const * const p_signature);

    /**
     * Generates SHA message digest.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     hash_type      Generating hash type.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     * @param[out]    p_digest       Pointer to destination of message digest. The length depends on hash type.
     */
    fsp_err_t (* shaCompute)(tsip_ctrl_t * const p_ctrl, tsip_hash_type_t const hash_type,
                             uint8_t const * const p_message, uint32_t const message_length, uint8_t * const p_digest);

    /**
     * Prepares a SHA generation.
     *
     * @param[in,out] p_ctrl    Pointer to control block.
     * @param[in]     hash_type Generating hash type.
     */
    fsp_err_t (* shaInit)(tsip_ctrl_t * const p_ctrl, tsip_hash_type_t const hash_type);

    /**
     * Inputs message.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     */
    fsp_err_t (* shaUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message, uint32_t const message_length);

    /**
     * Finalizes a SHA generation.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_digest Pointer to destination of message digest. The length depends on hash type.
     */
    fsp_err_t (* shaFinish)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_digest);

    /**
     * Suspend SHA generation.
     * This API allows you to suspend processing, for example, if you are in the middle of computing digest value for successive chunks of the message and need to perform another process.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_handle Pointer to destination of SHA control block.
     */
    fsp_err_t (* shaSuspend)(tsip_ctrl_t * const p_ctrl, tsip_sha_handle_abstractor_t * const p_handle);

    /**
     * Resume SHA generation.
     * This API allows you to resume a process that has been suspended by R_TSIP_SHA_Suspend() API.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[in]     p_handle Pointer to SHA control block.
     */
    fsp_err_t (* shaResume)(tsip_ctrl_t * const p_ctrl, tsip_sha_handle_abstractor_t const * const p_handle);

    /**
     * Generates HMAC.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_wrapped_key  Pointer to wrapped key of HMAC key.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     * @param[out]    p_mac          Pointer to destination of message digest. The length depends on MAC type.
     */
    fsp_err_t (* hmacCompute)(tsip_ctrl_t * const p_ctrl, const tsip_wrapped_key_t * p_wrapped_key,
                              uint8_t const * const p_message, uint32_t const message_length, uint8_t * const p_mac);

    /**
     * Verifies HMAC.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_wrapped_key  Pointer to wrapped key of HMAC key.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     * @param[in]     p_mac          Pointer to MAC. The length depends on mac_length.
     * @param[in]     mac_length     Byte length of MAC.
     */
    fsp_err_t (* hmacVerify)(tsip_ctrl_t * const p_ctrl, const tsip_wrapped_key_t * p_wrapped_key,
                             uint8_t const * const p_message, uint32_t const message_length,
                             uint8_t const * const p_mac,
                             uint32_t const mac_length);

    /**
     * Prepares a HMAC generation.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     p_wrapped_key Pointer to wrapped key of HMAC key.
     */
    fsp_err_t (* hmacInit)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_key);

    /**
     * Inputs message.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     */
    fsp_err_t (* hmacUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message,
                             uint32_t const message_length);

    /**
     * Finalizes a HMAC generation.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_mac    Pointer to destination of message digest. The length depends on MAC type.
     */
    fsp_err_t (* hmacSignFinish)(tsip_ctrl_t * const p_ctrl, uint8_t * const p_mac);

    /**
     * Finalizes a HMAC verification.
     *
     * @param[in,out] p_ctrl     Pointer to control block.
     * @param[in]     p_mac      Pointer to MAC. The length depends on mac_length.
     * @param[in]     mac_length Byte length of MAC.
     */
    fsp_err_t (* hmacVerifyFinish)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_mac, uint32_t const mac_length);

    /**
     * Suspend HMAC generation.
     * This API allows you to suspend processing, for example, if you are in the middle of computing HMAC for successive chunks of the message and need to perform another process.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_handle Pointer to destination of HMAC control block.
     */
    fsp_err_t (* hmacSuspend)(tsip_ctrl_t * const p_ctrl, tsip_hmac_handle_abstractor_t * const p_handle);

    /**
     * Resume HMAC generation.
     * This API allows you to resume a process that has been suspended by R_TSIP_HMAC_Suspend() API.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[in]     p_handle Pointer to HMAC control block.
     */
    fsp_err_t (* hmacResume)(tsip_ctrl_t * const p_ctrl, tsip_hmac_handle_abstractor_t const * const p_handle);

    /**
     * Verifies a public key certificate with ECDSA.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_wrapped_public_key Pointer to wrapped key of ECC public key.
     * @param[in]     p_hash               Pointer to hash value. The length is as same as the key length.
     * @param[in]     p_signature          Pointer to signature (r, s). The length is twice as long as the key length.
     */
    fsp_err_t (* pkiEcdsaCertVerify)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_public_key,
                                     uint8_t const * const p_hash, uint8_t const * const p_signature);

    /**
     * Exports verified certificate information stored in this driver.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[out]    p_verified_cert_info Pointer to certificate to be signed
     */
    fsp_err_t (* pkiVerifiedCertInfoExport)(tsip_ctrl_t * const                          p_ctrl,
                                            tsip_verified_cert_info_abstractor_t * const p_verified_cert_info);

    /**
     * Imports verified certificate information.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_verified_cert_info Pointer to certificate to be signed
     */
    fsp_err_t (* pkiVerifiedCertInfoImport)(tsip_ctrl_t * const                                p_ctrl,
                                            tsip_verified_cert_info_abstractor_t const * const p_verified_cert_info);

    /**
     * Wraps the public key in the verified public key certificate.
     *
     * @param[in,out] p_ctrl               Pointer to control block.
     * @param[in]     p_cert               Pointer to certificate.
     * @param[in]     cert_length          Certificate length.
     * @param[in]     p_key_param1         Pointer to start address of the public key parameter in certificate.
     *                                     - [ECC] Qx
     * @param[in]     key_param1_length    Length of key_param1 stored in the certificate.
     * @param[in]     p_key_param2         Pointer to start address of the public key parameter in certificate.
     *                                     - [ECC] Qy
     * @param[in]     key_param2_length    Length of key_param2 stored in the certificate.
     * @param[in]     hash_function        The hash function used when verifying certificate signature.
     * @param[in,out] p_wrapped_public_key Pointer to wrapped key of public key in the certificate.
     */
    fsp_err_t (* pkiCertKeyImport)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_cert, uint32_t const cert_length,
                                   uint8_t const * const p_key_param1, uint32_t const key_param1_length,
                                   uint8_t const * const p_key_param2,
                                   uint32_t const key_param2_length, tsip_hash_type_t const hash_function,
                                   tsip_wrapped_key_t * const p_wrapped_public_key);

    /**
     * Prepares a SHA generation.
     *
     * @param[in,out] p_ctrl    Pointer to control block.
     * @param[in]     hash_type Generating hash type.
     */
    fsp_err_t (* kdfShaInit)(tsip_ctrl_t * const p_ctrl, tsip_hash_type_t const hash_type);

    /**
     * Inputs wrapped ECDH secret as a message.
     *
     * @param[in,out] p_ctrl           Pointer to control block.
     * @param[in]     p_wrapped_secret Pointer to wrapped secret.
     */
    fsp_err_t (* kdfShaEcdhSecretUpdate)(tsip_ctrl_t * const                            p_ctrl,
                                         tsip_wrapped_secret_abstractor_t const * const p_wrapped_secret);

    /**
     * Inputs message.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     */
    fsp_err_t (* kdfShaUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message,
                               uint32_t const message_length);

    /**
     * Finalizes a SHA operation and generate DKM (Derived Keying Material).
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[out]    p_wrapped_dkm Pointer to destination of wrapped DKM.
     */
    fsp_err_t (* kdfShaFinish)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t * const p_wrapped_dkm);

    /**
     * Suspend SHA generation.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_handle Pointer to destination of KDF SHA control block.
     */
    fsp_err_t (* kdfShaSuspend)(tsip_ctrl_t * const p_ctrl, tsip_kdf_sha_handle_abstractor_t * const p_handle);

    /**
     * Resume SHA generation.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[in]     p_handle Pointer to KDF SHA control block.
     */
    fsp_err_t (* kdfShaResume)(tsip_ctrl_t * const p_ctrl, tsip_kdf_sha_handle_abstractor_t const * const p_handle);

    /**
     * Converts wrapped Derived Keying Material (DKM) to HMAC key for KDF.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     p_wrapped_dkm Pointer to wrapped DKM.
     * @param[in]     key_length    Length of HMAC key to be extracted from DKM.
     * @param[in,out] p_wrapped_key Pointer to destination wrapped HMAC key for KDF.
     */
    fsp_err_t (* kdfHmacDkmKeyImport)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t const * const p_wrapped_dkm,
                                      uint32_t const key_length, tsip_wrapped_key_t * const p_wrapped_key);

    /**
     * Converts wrapped ECDH secret to wrapped HMAC key for KDF.
     *
     * @param[in,out] p_ctrl           Pointer to control block.
     * @param[in]     p_wrapped_secret Pointer to wrapped secret.
     * @param[in,out] p_wrapped_key    Pointer to destination wrapped HMAC key for KDF.
     */
    fsp_err_t (* kdfHmacEcdhSecretKeyImport)(tsip_ctrl_t * const                            p_ctrl,
                                             tsip_wrapped_secret_abstractor_t const * const p_wrapped_secret,
                                             tsip_wrapped_key_t * const                     p_wrapped_key);

    /**
     * Prepares a HMAC generation.
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     p_wrapped_key Pointer to wrapped key of HMAC key.
     */
    fsp_err_t (* kdfHmacInit)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_key_t const * const p_wrapped_key);

    /**
     * Inputs wrapped Derived Keying Material (DKM) as a message.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_wrapped_dkm  Pointer to wrapped DKM.
     */
    fsp_err_t (* kdfHmacDkmUpdate)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t const * const p_wrapped_dkm);

    /**
     * Inputs wrapped ECDH secret as a message.
     *
     * @param[in,out] p_ctrl           Pointer to control block.
     * @param[in]     p_wrapped_secret Pointer to wrapped secret.
     */
    fsp_err_t (* kdfHmacEcdhSecretUpdate)(tsip_ctrl_t * const                            p_ctrl,
                                          tsip_wrapped_secret_abstractor_t const * const p_wrapped_secret);

    /**
     * Inputs message.
     *
     * @param[in,out] p_ctrl         Pointer to control block.
     * @param[in]     p_message      Pointer to message. The length is message_length.
     * @param[in]     message_length Byte length of message (0 or more bytes).
     */
    fsp_err_t (* kdfHmacUpdate)(tsip_ctrl_t * const p_ctrl, uint8_t const * const p_message,
                                uint32_t const message_length);

    /**
     * Finalizes a HMAC generation.
     *
     * @param[in,out] p_ctrl Pointer to control block.
     * @param[out]    p_wrapped_dkm  Pointer to destination of wrapped Derived Keying Material (DKM).
     */
    fsp_err_t (* kdfHmacSignFinish)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t * const p_wrapped_dkm);

    /**
     * Suspends HMAC operation.
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[out]    p_handle Pointer to destination of KDF HMAC control block.
     */
    fsp_err_t (* kdfHmacSuspend)(tsip_ctrl_t * const p_ctrl, tsip_kdf_hmac_handle_abstractor_t * const p_handle);

    /**
     * Resumes HMAC operation suspended by R_TSIP_KDF_HMAC_Suspend().
     *
     * @param[in,out] p_ctrl   Pointer to control block.
     * @param[in]     p_handle Pointer to KDF HMAC control block.
     */
    fsp_err_t (* kdfHmacResume)(tsip_ctrl_t * const p_ctrl, tsip_kdf_hmac_handle_abstractor_t const * const p_handle);

    /**
     * Concatenates two wrapped derived keying materials (DKMs).
     *
     * @param[in,out] p_wrapped_dkm1             Pointer to first DKM (DKM1).
     * @param[in]     p_wrapped_dkm2             Pointer to second DKM (DKM2).
     * @param[in]     wrapped_dkm1_buffer_length Length of wrapped_dkm1 buffer.
     *                                           It must be equal to or greater than DKM1 || DKM2.
     */
    fsp_err_t (* kdfDkmConcatenate)(tsip_wrapped_dkm_t * const       p_wrapped_dkm1,
                                    tsip_wrapped_dkm_t const * const p_wrapped_dkm2,
                                    uint32_t const                   wrapped_dkm1_buffer_length);

    /**
     * Outputs a wrapped key from Derived Keying Material (DKM).
     *
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     p_wrapped_dkm Pointer to wrapped DKM.
     * @param[in]     position      Start position of output key value in the DKM.
     * @param[in,out] p_wrapped_key Pointer to destination of wrapped key.
     */
    fsp_err_t (* kdfDerivedKeyImport)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t const * const p_wrapped_dkm,
                                      uint32_t const position, tsip_wrapped_key_t * const p_wrapped_key);

    /**
     * Outputs a initial vector from Derived Keying Material (DKM).
     *
     * @param[in,out] p_ctrl                   Pointer to control block.
     * @param[in]     p_wrapped_dkm            Pointer to wrapped DKM.
     * @param[in]     initial_vector_type      Initial vector type.
     * @param[in]     position                 Start position of output data value in the DKM.
     * @param[in]     p_tls_sequence_num       TLS sequence number. This argument is valid only for TLS-related data type.
     * @param[out]    p_wrapped_initial_vector Pointer to destination of wrapped initial vector.
     */
    fsp_err_t (* kdfDerivedIvWrap)(tsip_ctrl_t * const p_ctrl, tsip_wrapped_dkm_t const * const p_wrapped_dkm,
                                   tsip_initial_vector_type_t const initial_vector_type, uint32_t const position,
                                   uint8_t const * const p_tls_sequence_num, uint8_t * const p_wrapped_initial_vector);

    /**
     * Initialize on-the-fly decryption on TSIP.
     * @param[in,out] p_ctrl        Pointer to control block.
     * @param[in]     channel       Channel number.
     * @param[in]     p_wrapped_key Pointer to wrapped AES key.
     * @param[in]     p_seed        Pointer to seed.
     */
    fsp_err_t (* otfInit)(tsip_ctrl_t * const p_ctrl, tsip_otf_channel_t const channel,
                          tsip_wrapped_key_t * const p_wrapped_key, uint8_t const * const p_seed);
};

/** TSIP driver structure.  General TSIP functions implemented at the HAL layer follow this API. */
typedef struct st_tsip_api tsip_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
struct st_tsip_instance
{
    tsip_ctrl_t      * p_ctrl;         ///< Pointer to the control structure for this instance
    tsip_cfg_t const * p_cfg;          ///< Pointer to the configuration structure for this instance
    tsip_api_t const * p_api;          ///< Pointer to the API structure for this instance
};

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_tsip_instance tsip_instance_t;

/*******************************************************************************************************************//**
 * @} (end addtogroup TSIP_PROTECTED_API)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* R_TSIP_API_H */
