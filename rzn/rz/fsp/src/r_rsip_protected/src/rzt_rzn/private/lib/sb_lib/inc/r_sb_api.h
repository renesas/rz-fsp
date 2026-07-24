/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 3630 ++ # D019 For use in upper program */

#ifndef R_SB_API_H

/* Multiple inclusion protection macro */
#define R_SB_API_H

#include <stdint.h>

/*!***********************************************************
 * \addtogroup  SBLIB           SecureBoot Library
 * \{
 * \addtogroup  SBLIBMod        SecureBoot Library Modules
 * \addtogroup  SBLIBCfg        SecureBoot Library Configurations
 * \}********************************************************/

/*!***********************************************************
 * \addtogroup  SBLIBMod          SecureBoot Library Modules
 * \{
 * \addtogroup  SBLIBCommon       SB-Lib Common module
 * \addtogroup  SBLIBSecureBoot   SB-Lib SecureBoot module
 * \addtogroup  SBLIBCRC          SB-Lib CRC module
 * \addtogroup  SBLIBManifest     SB-Lib Manifest module
 * \}********************************************************/

/*!***********************************************************
 * \addtogroup  SBLIBCfg        SecureBoot Library Configurations
 * \{
 * \addtogroup  SBLIBBC         SB-Lib BuildConfiguration
 * \}********************************************************/

/*=====================================================================================================================
 * Public macro definitions
 * =====================================================================================================================*/

/*!*********************************************************
 * \addtogroup  SBLIBCommonDefines
 * \{
 * \addtogroup  group_return_code
 * \addtogroup  group_manifest_size
 * \addtogroup  group_unused_area
 * \}******************************************************/

/** SB-Lib return value definition */
/**\addtogroup group_return_code Return code */
/*! \{*/
#define SB_RET_SUCCESS                             ((sb_ret_t) 0x55555555UL) /**< API succeeded */
#define SB_RET_SAME_IMAGE_VERSION                  ((sb_ret_t) 0x55005501UL) /**< An image of the same version as the
                                                                              *   current version is input
                                                                              *   (verification completed successfully) */
#define SB_RET_ERR_INTERNAL_FAIL                   ((sb_ret_t) 0xAAAA0000UL) /**< A internal failure */
#define SB_RET_ERR_INVALID_ARG                     ((sb_ret_t) 0xAAAA0001UL) /**< An invalid argument was entered */
#define SB_RET_ERR_UNSUPPORTED_FUNCTION            ((sb_ret_t) 0xAAAA0002UL) /**< Unsupported function executed */
#define SB_RET_ERR_INVALID_ALIGNMENT               ((sb_ret_t) 0xAAAA0003UL) /**< Data entered with incorrect alignment */
#define SB_RET_ERR_MANI_INVALID_MAGIC              ((sb_ret_t) 0xAAAA0100UL) /**< An invalid magic number is set */
#define SB_RET_ERR_MANI_UNSUPPORTED_VERSION        ((sb_ret_t) 0xAAAA0101UL) /**< Unsupported version is set */
#define SB_RET_ERR_MANI_OUT_OF_RANGE_LEN           ((sb_ret_t) 0xAAAA0102UL) /**< Out of range TLV Length is set */
#define SB_RET_ERR_MANI_TLV_FIELD_ERR              ((sb_ret_t) 0xAAAA0103UL) /**< Missing required TLV field */
#define SB_RET_ERR_MANI_TLV_INVALID_LEN            ((sb_ret_t) 0xAAAA0104UL) /**< The length exceeding the end of
                                                                              *   the manifest is specified in Length
                                                                              *   of the TLV field */
#define SB_RET_ERR_MANI_INVALID_IMAGE_LEN          ((sb_ret_t) 0xAAAA0105UL) /**< An invalid image length is set */
#define SB_RET_ERR_MANI_MISMATCH_SIGN_ALGORITHM    ((sb_ret_t) 0xAAAA0106UL) /**< There is a wrong combination of
                                                                              *   signature algorithms */
#define SB_RET_ERR_MANI_UNSUPPORTED_ALGORITHM      ((sb_ret_t) 0xAAAA0107UL) /**< An algorithm was specified that
                                                                              *   the manifest does not support */
#define SB_RET_ERR_CRYPTO_FAIL                     ((sb_ret_t) 0xAAAA0200UL) /**< Cryptographic processing failure */
#define SB_RET_ERR_CRYPTO_AUTH_FAIL                ((sb_ret_t) 0xAAAA0201UL) /**< Verification failed */
#define SB_RET_ERR_CRYPTO_UNSUPPORTED_ALGORITHM    ((sb_ret_t) 0xAAAA0202UL) /**< Unsupported algorithm */
#define SB_RET_ERR_CRYPTO_RESOURCE_CONFLICT        ((sb_ret_t) 0xAAAA0203UL) /**< Other resorece is using CryptoIP. */
#define SB_RET_ERR_CRYPTO_PARAM_ERR                ((sb_ret_t) 0xAAAA0204UL) /**< Parameter error */
#define SB_RET_ERR_CRC_MISMATCH                    ((sb_ret_t) 0xAAAA0300UL) /**< CRC mismatch */
#define SB_RET_ERR_CRC_UNSUPPORTED_POLYNOMIAL      ((sb_ret_t) 0xAAAA0301UL) /**< Unsupported polynominal */
#define SB_RET_ERR_LOWER_IMAGE_VERSION             ((sb_ret_t) 0xAAAA0400UL) /**< Image version lower than the current
                                                                              *   image version is installed */

/*! \}*/

/** Manifest size definition */
/**\addtogroup group_manifest_size Manifest size */
/*! \{*/
#define SB_MANIFEST_LEN_MIN    (36UL)    /**< Minimum manifest length */
#define SB_MANIFEST_LEN_MAX    (10240UL) /**< Maximum manifest length */
/*! \}*/

/** Reserved WORD size definition */
/**\addtogroup group_unused_area Reserved WORD size */
/*! \{*/
#define SB_KEY_CERT_RESERVED_WORD_SIZE    (5U) /**< Key Certificate header reserved WORD size */
/*! \}*/

/*=====================================================================================================================
 * Public type definitions
 * =====================================================================================================================*/

/*!*********************************************************
 * \addtogroup  SBLIBCommonTypes
 * \{*******************************************************/
typedef uint32_t sb_ret_t;             /**< SB-Lib return type */

/** MAC type value enumeration */
typedef enum
{
    SB_MAC_TYPE_NONE = 0,              /**< Type not used */
    SB_MAC_TYPE_HMAC_SHA2_224,         /**< HMAC SHA2-224 */
    SB_MAC_TYPE_HMAC_SHA2_256,         /**< HMAC SHA2-256 */
    SB_MAC_TYPE_HMAC_SHA2_384,         /**< HMAC SHA2-384 */
    SB_MAC_TYPE_HMAC_SHA2_512,         /**< HMAC SHA2-512 */
    SB_MAC_TYPE_HMAC_SHA3_224,         /**< HMAC SHA3-224 */
    SB_MAC_TYPE_HMAC_SHA3_256,         /**< HMAC SHA3-256 */
    SB_MAC_TYPE_HMAC_SHA3_384,         /**< HMAC SHA3-384 */
    SB_MAC_TYPE_HMAC_SHA3_512,         /**< HMAC SHA3-512 */
    SB_MAC_TYPE_CMAC_AES_128,          /**< CMAC AES-128 */
    SB_MAC_TYPE_CMAC_AES_192,          /**< CMAC AES-192 */
    SB_MAC_TYPE_CMAC_AES_256           /**< CMAC AES-256 */
} e_sb_mac_type_t;

/*! \}*/

/*!*********************************************************
 * \addtogroup  SBLIBManifestTypes
 * \{*******************************************************/

/** Key Certificate header structure */
typedef struct
{
    uint32_t magic;                                    /**< Magic number unique to KeyCertificate */
    uint32_t manifest_version;                         /**< Manifest version */
    uint32_t flags;                                    /**< KeyCertificate flag (Unused in V.1.00) */
    uint32_t reserved[SB_KEY_CERT_RESERVED_WORD_SIZE]; /**< Unused area */
} st_sb_key_cert_header_t;

/** Code Certificate header structure */
typedef struct
{
    uint32_t magic;                    /**< Magic number unique to CodeCertificate */
    uint32_t manifest_version;         /**< Manifest version */
    uint32_t flags;                    /**< CodeCertificate flag */
    uint32_t load_addr;                /**< Image storage address */
    uint32_t dest_addr;                /**< Image expansion destination address */
    uint32_t img_len;                  /**< Image byte size */
    uint32_t img_version;              /**< Image version */
    uint32_t build_num;                /**< Image build number */
} st_sb_code_cert_header_t;

/*! \}*/

/*=====================================================================================================================
 * Public global variables
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Public global functions
 * =====================================================================================================================*/

/**********************************************************************************************************************
 * Function Name : R_SB_SecureBoot
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIs
 * \brief       Perform a secure boot
 * \param       [in]   p_key_cert           Start address of Key Certificate \n
 *                                          Data must be aligned on 4-byte boundaries \n
 *                                          Don't care when using secure boot with MAC.
 * \param       [in]   key_cert_len_max     Maximum byte length that Key Certificate can take \n
 *                                          Don't care when using secure boot with MAC. \n
 *                                          [range] #SB_MANIFEST_LEN_MIN - #SB_MANIFEST_LEN_MAX
 * \param       [in]   p_code_cert          Start address of Code Certificate \n
 *                                          Data must be aligned on 4-byte boundaries
 * \param       [in]   code_cert_len_max    Maximum byte length that Code Certificate can take \n
 *                                          [range] #SB_MANIFEST_LEN_MIN - #SB_MANIFEST_LEN_MAX
 * \param       [in]   p_mac_tlv            Start address of Code Certificate verification data (TLV format) \n
 *                                          Data must be aligned on 4-byte boundaries \n
 *                                          Specify NULL when verifying with a certificate chain
 * \return
 *  - #SB_RET_SUCCESS:                          Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                Internal processing failed
 *  - #SB_RET_ERR_INVALID_ARG:                  Invalid argument entered
 *  - #SB_RET_ERR_UNSUPPORTED_FUNCTION:         Unsupported function executed
 *  - #SB_RET_ERR_INVALID_ALIGNMENT:            Data entered with incorrect alignment
 *  - #SB_RET_ERR_MANI_INVALID_MAGIC:           Incorrect magic number is set
 *  - #SB_RET_ERR_MANI_UNSUPPORTED_VERSION:     Unsupported version is set
 *  - #SB_RET_ERR_MANI_OUT_OF_RANGE_LEN:        TLV Length out of range is set
 *  - #SB_RET_ERR_MANI_TLV_FIELD_ERR:           Missing required TLV fields
 *  - #SB_RET_ERR_MANI_TLV_INVALID_LEN:         The length of the TLV field has a size that exceeds the end of
 *                                              the manifest.
 *  - #SB_RET_ERR_MANI_INVALID_IMAGE_LEN:       An invalid image length is set
 *  - #SB_RET_ERR_MANI_MISMATCH_SIGN_ALGORITHM: There is a wrong combination of signature algorithms
 *  - #SB_RET_ERR_MANI_UNSUPPORTED_ALGORITHM:   An algorithm was specified that the manifest does not support
 *  - #SB_RET_ERR_CRYPTO_FAIL:                  Encryption failed
 *  - #SB_RET_ERR_CRYPTO_AUTH_FAIL:             Verification failed
 *  - #SB_RET_ERR_CRYPTO_UNSUPPORTED_ALGORITHM: Unsupported algorithm
 *  - #SB_RET_ERR_CRYPTO_PARAM_ERR:             Parameter error
 *  - #SB_RET_ERR_LOWER_IMAGE_VERSION:          Image version lower than the current image version is installed
 * \par Global Variables
 *  - Image data    [in]    Binary data of the image to be verified \n
 *                          Data must be aligned on 4-byte boundaries
 * \par Call SB-Driver API
 *  - R_CIP_DRV_PrcDeriveMacKeyFromHuk
 *  - R_CIP_DRV_PrcVerifyMac
 *  - R_CIP_DRV_PrcVerifyCertChain
 *  - R_CIP_DRV_PrcDecryptImage
 *  - R_CIP_DRV_CheckImageVersion
 * \par Precondition
 *  - Cryptographic IP initialization is complete.
 *  - The target boot loader program has been copied to the Dest Addr field of the Code Certificate Header.
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Verification type is determined by the combination of set arguments.
 *| p_key_cert| p_code_cert| p_mac_tlv| verification type            |
 *|:----------|:-----------|:---------|:-----------------------------|
 *|Set        |Set         |Set       |MAC verification (do not use p_key_cert)|
 *|NULL       |Set         |Set       |MAC verification              |
 *|Set        |Set         |NULL      |Certificate chain verification|
 * *Other combinations are errors.
 * \par
 *      - The TLV fields of Key Certificate, Code Certificate,
 *        and MAC referenced by each verification type are described below. \n
 *        < MAC verification >
 *| Type           | Required/Choose/\n Optional| TLV Type(Class) | TLV Type(Use Type)| Description                             |
 *|:---------------|:---------------------------|:----------------|:------------------|:----------------------------------------|
 *|Code Certificate|Required(*)                 |Key              |Image public key|Public key for signature verification of Code Certificate \n (*Only certificate chain verification using the IMG PK of the previous stage configlation enable)|
 *|^               |Optional                    |Image Cipher info|Image Encryption/Decryption Information|Image decryption information \n (Required when using Image Cipher and using a non-default value for the key or output destination address)|
 *|^               |Optional                    |IV               |Image Cipher IV    |IV used in decoding the image \n (Required when Image Cipher info IV select is "IV stored in Code Certificate")|
 *|MAC             |Choose (Use Type)           |MAC              |Code Certificate + \n Image MAC|MAC calculated for Code Certificate and image \n Select Uset type depending on whether the image for MAC is encrypted|
 *|^               |^                           |^                |Code Certificate + \n Encrypted Image MAC|^                  |
 * \n
 *        < Certificate chain verification >
 *| Type           | Required/Choose/\n Optional| TLV Type(Class) | TLV Type(Use Type)| Description                             |
 *|:---------------|:---------------------------|:----------------|:------------------|:----------------------------------------|
 *|Key Certificate |Choose (Use Type)           |Key              |OEM root public key|Public key for signature verification of Key Certificate \n \<When verifying using RoT\> \n Set "OEM root public key" to Use type \n \<When verifying using the previous IMG PK\> \n Set Use type to "Image public key"|
 *|^               |^                           |^                |Image public key   |^                                        |
 *|^               |Required                    |Hash             |Image public key Hash|Hash value of public key for signature verification of Code Certificate|
 *|^               |Required                    |Signature        |Key Certificate signature|Signature value calculated for Key Certificate|
 *|Code Certificate|Required                    |Key              |Image public key   |Public key for signature verification of Code Certificate|
 *|^               |Choose (Use Type)           |Signature        |Code Certificate + \n Image Signature|Code Certificate and signature value calculated by image \n Select Uset type depending on whether the image to be signed is encrypted|
 *|^               |^                           |^                |Code Certificate + \n Encrypted Image Signature|^            |
 *|^               |Optional                    |Image Cipher info|Image Encryption/Decryption Information|Image decryption information \n (Required when using Image Cipher and using a non-default value for the key or output destination address)|
 *|^               |Optional                    |IV               |Image Cipher IV    |IV used in decoding the image            |
 * \par
 *      - Returns an error if the set TLV is in the following cases
 *        - "Required" TLV is not set
 *        - "Choose" TLV is not set
 *        - Two or more "Choose" TLVs are set
 *      - When multiple TLVs with the same Class and Use type are set,
 *        use the TLV found earlier when parsing from the beginning of the TLV field.
 *      - In the MAC calculation in MAC verification, input data in the following order
 *        -# Code Certificate
 *        -# Image
 *      - In hash calculation for signature verification of Code Certificate in certificate chain verification,
 *        input data in the following order
 *        -# Code Certificate (excluding signature value TLV)
 *        -# Image
 *      - Use a key derived from HUK for MAC verification \n This key is generated by Crypto IP
 *      - If Image Cipher in the Code Certificate \> Header \> Flags field is present,
 *        decrypt the image at the time of verification \n Decryption is performed at the following timing
 *        - MAC verification: decrypt after verification
 *        - Certificate chain verification: \n
 *          If the signature target is a plain text image, decrypt it before verification \n
 *          If the signature target is an encrypted image, decrypt it after verification
 *      - Certificate chain verification processing is only compiled if the
 *        build configuration #SB_CFG_SB_CERT_CHAIN_VERIFICATION is enabled
 *      - MAC verification process is only compiled if build configuration #SB_CFG_SB_MAC_VERIFICATION is enabled
 *      - Compare image versions \n
 *        If the image version stored in the anti-rollback counter is lower than the Image version set
 *        in the Code Certificate Header, return #SB_RET_ERR_LOWER_IMAGE_VERSION
 *
 * Pseudo-code for the function can be found below.
 * -# Set #SB_PRV_FALSE to flow_correct_ret
 * -# Set the initial value for the flow counter with #r_sb_cmn_fc_sb_init
 * -# If NULL == p_mac_tlv
 *   -# <B>--- If #SB_CFG_SB_CERT_CHAIN_VERIFICATION is enabled ---</B>
 *   -# If NULL != p_code_cert
 *     -# If (((uintptr_t)p_key_cert & #SB_PRV_REMAINDER_DIV4) == 0UL) &&
 *           (((uintptr_t)p_code_cert & #SB_PRV_REMAINDER_DIV4) == 0UL)
 *       -# Set Key cert structure with #r_sb_mani_set_key_cert_st
 *       -# If #SB_RET_SUCCESS == ret
 *         -# Check Key cert with #r_sb_mani_chk_key_cert
 *         -# If #SB_RET_SUCCESS == ret
 *           -# Set code cert structure with #r_sb_mani_set_code_cert_st
 *           -# If #SB_RET_SUCCESS == ret
 *             -# Check code cert with #r_sb_mani_chk_code_cert
 *             -# If #SB_RET_SUCCESS == ret
 *               -# Verify certificate chain with #r_sb_sb_verify_cert_chain
 *             -# Else
 *               -# Do nothing
 *           -# Else
 *             -# Do nothing
 *         -# Else
 *           -# Do nothing
 *       -# Else
 *         -# Do nothing
 *     -# Else
 *       -# Set #SB_RET_ERR_INVALID_ALIGNMENT to ret
 *   -# Else
 *     -# Set #SB_RET_ERR_INVALID_ARG to ret
 *   -# <B>--- Else #SB_CFG_SB_CERT_CHAIN_VERIFICATION is enabled ---</B>
 *   -# Set #SB_RET_ERR_UNSUPPORTED_FUNCTION to ret
 *   -# <B>--- Endif #SB_CFG_SB_CERT_CHAIN_VERIFICATION is enabled ---</B>
 * -# Else
 *   -# <B>--- If #SB_CFG_SB_MAC_VERIFICATION is enabled ---</B>
 *   -# If NULL != p_code_cert
 *     -# If (((uintptr_t)p_code_cert & #SB_PRV_REMAINDER_DIV4) == 0UL) &&
 *           (((uintptr_t)p_mac_tlv & #SB_PRV_REMAINDER_DIV4) == 0UL)
 *       -# Set code cert structure with #r_sb_mani_set_code_cert_st
 *       -# If #SB_RET_SUCCESS == ret
 *         -# Check code cert with #r_sb_mani_chk_code_cert
 *         -# If #SB_RET_SUCCESS == ret
 *           -# Set MAC TLV structure with #r_sb_mani_set_mac_tlv_st
 *           -# If #SB_RET_SUCCESS == ret
 *             -# Perform MAC verification with r_sb_sb_verify_mac
 *           -# Else
 *             -# Do nothing
 *         -# Else
 *           -# Do nothing
 *       -# Else
 *         -# Do nothing
 *     -# Else
 *       -# Set #SB_RET_ERR_INVALID_ALIGNMENT to ret
 *   -# Else
 *     -# Set #SB_RET_ERR_INVALID_ARG to ret
 *   -# <B>--- Else #SB_CFG_SB_MAC_VERIFICATION is enabled ---</B>
 *   -# Set #SB_RET_ERR_UNSUPPORTED_FUNCTION to ret
 *   -# <B>--- Endif #SB_CFG_SB_MAC_VERIFICATION is enabled ---</B>
 * -# Check if the SecureBoot flow is correct using #r_sb_cmn_fc_is_sb_flow_correct
 * -# Set function result to flow_correct_ret
 * -# If #SB_RET_SUCCESS == ret
 *   -# If #SB_PRV_TRUE == flow_correct_ret
 *     -# Do nothing
 *   -# Else
 *     -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Else
 *   -# Do nothing
 * -# Return ret
 *
 * \callgraph
 *********************************************************************************************************************/
extern sb_ret_t R_SB_SecureBoot(const uint8_t * const p_key_cert,
                                const uint32_t        key_cert_len_max,
                                const uint8_t * const p_code_cert,
                                const uint32_t        code_cert_len_max,
                                const uint8_t * const p_mac_tlv);

#endif                                 /* R_SB_API_H */

/*=====================================================================================================================
 * End of File
 * =====================================================================================================================*/
