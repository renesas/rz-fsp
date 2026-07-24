/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0310, 3305 ++ # D002 Cast to a fixed Manifest format */
/* PRQA S 0715 ++ # D003 Develop according to C99 */
/* PRQA S 0776 ++ # D004 Exception according to function nomenclature */
/* PRQA S 0791 ++ # D005 Develop according to C99 */
/* PRQA S 1532 ++ # D007 Since files are grouped by function, they are called from different files. */
/* PRQA S 2880, 2982, 2984, 2991, 2995 ++ # D009 Processing for flow verification */
/* PRQA S 2981 ++ # D011 Not redundant depending on build configuration */
/* PRQA S 5002 ++ # D018 Exception according to file nomenclature */

/*!***********************************************************
 * \addtogroup  SBLIBSecureBoot
 * \{
 * \addtogroup  SBLIBSecureBootAPIs              SecureBoot APIs
 * \addtogroup  SBLIBSecureBootDefinesInternal   SecureBoot Internal Definitions
 * \addtogroup  SBLIBSecureBootAPIsInternal      SecureBoot Internal APIs
 * \}********************************************************/

/*=====================================================================================================================
 * Includes <System Includes> , "Project Includes"
 * =====================================================================================================================*/
#include <stddef.h>
#include "r_cip_drv_api.h"
#include "r_sb_build_config.h"
#include "r_sb_api.h"
#include "r_sb_manifest.h"
#include "r_sb_cmn.h"
#include "r_sb_cmn_drv.h"
#include "r_sb_sb.h"

/*=====================================================================================================================
 * Private macro definitions
 * =====================================================================================================================*/

/*!********************************************************************
 * \addtogroup SBLIBSecureBootDefinesInternal
 * \{
 * \addtogroup  group_tlv_search_type
 * \addtogroup  group_tlv_search_kc
 * \addtogroup  group_tlv_search_sb_cc
 * \addtogroup  group_tlv_search_ci
 * \addtogroup  group_tlv_search_sb_mac
 * \}*****************************************************************/

/** Search by certificate chain verification */
/**\addtogroup group_tlv_search_type TLV search type and mask */
/*! \{*/
/** Class & Use type of OEM root public key */
#define SB_PRV_TLV_KEY_OEM_ROOT_PK_TYPE        (SB_PRV_TLV_TYPE_CLS_KEY | SB_PRV_TLV_TYPE_CLS_KEY_UT_OEM_ROOT_PK)

/** Class & Use type of Image public key */
#define SB_PRV_TLV_KEY_IMG_PK_TYPE             (SB_PRV_TLV_TYPE_CLS_KEY | SB_PRV_TLV_TYPE_CLS_KEY_UT_IMG_PK)

/** Class mask & Use type mask of key */
#define SB_PRV_TLV_KEY_MASK                    (SB_PRV_TLV_TYPE_CLS_MASK | SB_PRV_TLV_TYPE_CLS_KEY_UT_MASK)

/** Class & Use type of Image public key hash */
#define SB_PRV_TLV_HASH_IMG_PK_TYPE            (SB_PRV_TLV_TYPE_CLS_HASH | SB_PRV_TLV_TYPE_CLS_HASH_UT_IMG_PK)

/** Class & Use type of Image hash */
#define SB_PRV_TLV_HASH_IMG_TYPE               (SB_PRV_TLV_TYPE_CLS_HASH | SB_PRV_TLV_TYPE_CLS_HASH_UT_IMG)

/** Class & Use type of Image hash */
#define SB_PRV_TLV_HASH_ENCIMG_TYPE            (SB_PRV_TLV_TYPE_CLS_HASH | SB_PRV_TLV_TYPE_CLS_HASH_UT_ENCIMG)

/** Class mask & Use type mask of Image public key hash */
#define SB_PRV_TLV_HASH_MASK                   (SB_PRV_TLV_TYPE_CLS_MASK | SB_PRV_TLV_TYPE_CLS_HASH_UT_MASK)

/** Class & Use type of Key Certificate signature */
#define SB_PRV_TLV_SIGN_CERT_TYPE              (SB_PRV_TLV_TYPE_CLS_SIGN | SB_PRV_TLV_TYPE_CLS_SIGN_UT_CERT)

/** Class & Use type of Code Certificate and image signature */
#define SB_PRV_TLV_SIGN_CERT_IMG_TYPE          (SB_PRV_TLV_TYPE_CLS_SIGN | \
                                                SB_PRV_TLV_TYPE_CLS_SIGN_UT_CODE_CERT_AND_IMG)

/** Class & Use type of Code Certificate and encryption image signature */
#define SB_PRV_TLV_SIGN_CERT_ENCIMG_TYPE       (SB_PRV_TLV_TYPE_CLS_SIGN | \
                                                SB_PRV_TLV_TYPE_CLS_SIGN_UT_CODE_CERT_AND_ENCIMG)

/** Class mask & Use type mask of signature */
#define SB_PRV_TLV_SIGN_MASK                   (SB_PRV_TLV_TYPE_CLS_MASK | SB_PRV_TLV_TYPE_CLS_SIGN_UT_MASK)

/** Class & Use type of Code Certificate + Image MAC */
#define SB_PRV_TLV_MAC_CERT_IMG_TYPE           (SB_PRV_TLV_TYPE_CLS_MAC | SB_PRV_TLV_TYPE_CLS_MAC_UT_CODE_CERT_AND_IMG)

/** Class & Use type of Code Certificate + Encrypted Image MAC */
#define SB_PRV_TLV_MAC_CERT_ENCIMG_TYPE        (SB_PRV_TLV_TYPE_CLS_MAC | \
                                                SB_PRV_TLV_TYPE_CLS_MAC_UT_CODE_CERT_AND_ENCIMG)

/** Class mask & Use type mask of MAC */
#define SB_PRV_TLV_MAC_MASK                    (SB_PRV_TLV_TYPE_CLS_MASK | SB_PRV_TLV_TYPE_CLS_MAC_UT_MASK)

/** Class & Use type of Image Cipher IV */
#define SB_PRV_TLV_IMG_CIP_IV_TYPE             (SB_PRV_TLV_TYPE_CLS_IV | SB_PRV_TLV_TYPE_CLS_IV_UT_IMG_CIPHER)

/** Class & Use type of Temp Image Decryption IV */
#define SB_PRV_TLV_CI_TMP_IMG_DEC_IV_TYPE      (SB_PRV_TLV_TYPE_CLS_IV | SB_PRV_TLV_TYPE_CLS_IV_UT_TMP_IMG_DEC)

/** Class mask & Use type mask of Temp Image Decryption IV */
#define SB_PRV_TLV_IV_MASK                     (SB_PRV_TLV_TYPE_CLS_MASK | SB_PRV_TLV_TYPE_CLS_IV_UT_MASK)

/** Class & Use type of Image Cipher Info */
#define SB_PRV_TLV_IMG_CIP_INFO_TYPE           (SB_PRV_TLV_TYPE_CLS_ICI | SB_PRV_TLV_TYPE_CLS_ICI_UT_IMG_ENC_DEC)

/** Class & Use type of Temp Image Decryption Info */
#define SB_PRV_TLV_CI_TMP_IMG_DEC_INFO_TYPE    (SB_PRV_TLV_TYPE_CLS_ICI | SB_PRV_TLV_TYPE_CLS_ICI_UT_TMP_IMG_DEC)

/** Class mask & Use type mask of Image Cipher Info */
#define SB_PRV_TLV_ICI_MASK                    (SB_PRV_TLV_TYPE_CLS_MASK | SB_PRV_TLV_TYPE_CLS_ICI_UT_MASK)

/*! \}*/

/** key certificate TLV to search SecureBoot & CheckIntegrity */
/**\addtogroup group_tlv_search_kc TLV search Key Certificate */
/*! \{*/
#define SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX    (0U) /**< Index of OEM root public key */
#define SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX         (1U) /**< Index of Image public key */
#define SB_PRV_TLV_KEY_CERT_HASH_IMG_PK_IDX        (2U) /**< Index of Image public key hash */
#define SB_PRV_TLV_KEY_CERT_SIGN_CERT_IDX          (3U) /**< Index of Key Certificate signature */
#define SB_PRV_TLV_KEY_CERT_NUM                    (4U) /**< Number of Key Certificate TLVs */
/*! \}*/

/** code certificate TLV to search by SecureBoot(certificate chain verification) */
/**\addtogroup group_tlv_search_sb_cc TLV search Code Certificate for Certificate Chain verification */
/*! \{*/
#define SB_PRV_TLV_CC_CODE_CERT_KEY_IMG_PK_IDX      (0U) /**< Index of Image public key */
#define SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX        (1U) /**< Index of Image hash */
#define SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX     (2U) /**< Index of encryption image hash */
#define SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_INFO_IDX    (3U) /**< Index of Image Cipher Info */
#define SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_IV_IDX      (4U) /**< Index of Image Cipher IV */
#define SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX       (5U) /**< Index of Certificate signature */
#define SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX        (6U) /**< Index of Code Certificate and image signature */
#define SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX     (7U) /**< Index of Code Certificate and encryption image signature */
#define SB_PRV_TLV_CC_CODE_CERT_NUM                 (8U) /**< Number of Code Certificate TLVs for SecureBoot */
/*! \}*/

/** code certificate TLV to search by SecureBoot(MAC verification) */
/**\addtogroup group_tlv_search_sb_mac TLV search Code certificate for MAC verification */
/*! \{*/
#define SB_PRV_TLV_MAC_IMG_CIP_INFO_IDX    (0U) /**< Index number of Image Cipher Info */
#define SB_PRV_TLV_MAC_IMG_CIP_IV_IDX      (1U) /**< Index number of Image Cipher IV */
#if (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 1U)     /* (Use only when SB_CFG_SB_CERT_CHAIN_USE_IMG_PK is Enable) */
 #define SB_PRV_TLV_MAC_KEY_IMG_PK_IDX     (2U) /**< Index number of Image public key */
 #define SB_PRV_TLV_MAC_NUM                (3U) /**< Number of Code Certificate TLVs for MAC verify */
#else /* #if (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 1U) */
 #define SB_PRV_TLV_MAC_NUM                (2U) /**< Number of Code Certificate TLVs for MAC verify */
#endif /* #if (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 1U) */
/*! \}*/

/** code certificate TLV to search by CheckIntegrity */
/**\addtogroup group_tlv_search_ci TLV search Code Certificate for CheckIntegrity */
/*! \{*/
#define SB_PRV_TLV_CI_CODE_CERT_KEY_IMG_PK_IDX          (0U) /**< Index of Image public key */
#define SB_PRV_TLV_CI_CODE_CERT_HASH_IMG_IDX            (1U) /**< Index of Image hash */
#define SB_PRV_TLV_CI_CODE_CERT_IMG_CIP_INFO_IDX        (2U) /**< Index of Image Cipher Info */
#define SB_PRV_TLV_CI_CODE_CERT_IMG_CIP_IV_IDX          (3U) /**< Index of Image Cipher IV */
#define SB_PRV_TLV_CI_CODE_CERT_TMP_IMG_DEC_INFO_IDX    (4U) /**< Index of Temp Image Decryption Info */
#define SB_PRV_TLV_CI_CODE_CERT_TMP_IMG_DEC_IV_IDX      (5U) /**< Index of Temp Image Decryption IV */
#define SB_PRV_TLV_CI_CODE_CERT_SIGN_CERT_IDX           (6U) /**< Index of Certificate signature */
#define SB_PRV_TLV_CI_CODE_CERT_SIGN_IMG_IDX            (7U) /**< Index of Code Certificate and image signature */
#define SB_PRV_TLV_CI_CODE_CERT_NUM                     (8U) /**< Number of Code Certificate TLVs for CheckIntegrity */
/*! \}*/

/*=====================================================================================================================
 * Private type definitions
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Public global variables
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Private global variables
 * =====================================================================================================================*/

/*=====================================================================================================================
 * Private function prototypes
 * =====================================================================================================================*/
#if (SB_CFG_IMAGE_ENC_DEC == 1U)
static sb_ret_t sb_decrypt_img(const st_sb_code_cert_t * const p_code_cert_st,
                               const st_sb_tlv_t * const       p_img_cip_info,
                               const st_sb_tlv_t * const       p_img_cip_iv,
                               const uint32_t                  timing);

#endif                                 /* (SB_CFG_IMAGE_ENC_DEC == 1U) */

#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U)
static sb_ret_t sb_check_cert_chain_tlv(const st_sb_tlv_t * const p_key_cert_tlvs,
                                        const st_sb_tlv_t * const p_code_cert_tlvs);

#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) */

#if (SB_CFG_CHECK_INTEGRITY == 1U)
static sb_ret_t sb_check_check_integrity_tlv(const st_sb_tlv_t * const p_key_cert_tlvs,
                                             const st_sb_tlv_t * const p_code_cert_tlvs);

#endif                                 /* (SB_CFG_CHECK_INTEGRITY == 1U) */

#if (SB_CFG_SB_MAC_VERIFICATION == 1U)
static sb_ret_t sb_check_mac_tlv(const st_sb_tlv_t * const p_mac_tlv, const st_sb_tlv_t * const p_img_pk_tlv);

#endif                                 /* (SB_CFG_SB_MAC_VERIFICATION == 1U) */

#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) || (SB_CFG_CHECK_INTEGRITY == 1U)
static sb_ret_t sb_get_cc_tlv(const st_sb_key_cert_t * const        p_key_cert_st,
                              const st_sb_code_cert_t * const       p_code_cert_st,
                              const st_sb_search_tlv_type_t * const p_search_tlv_key_cert,
                              const uint32_t                        search_tlv_key_cert_num,
                              const st_sb_search_tlv_type_t * const p_search_tlv_code_cert,
                              const uint32_t                        search_tlv_code_cert_num,
                              st_sb_tlv_t * const                   p_key_cert_tlvs,
                              st_sb_tlv_t * const                   p_code_cert_tlvs);

#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) || (SB_CFG_CHECK_INTEGRITY == 1U) */

/*=====================================================================================================================
 * Public function definitions
 * =====================================================================================================================*/

/**********************************************************************************************************************
 * Function Name : r_sb_sb_verify_cert_chain
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIsInternal
 * \brief       Validate manifest and image certificate chains
 * \param       [in]   p_key_cert_st           Start address of Key Certificate Structure
 * \param       [in]   p_code_cert_st          Start address of Code Certificate Structure
 * \return
 *  - #SB_RET_SUCCESS:                             Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                   Internal processing failed
 *  - #SB_RET_ERR_UNSUPPORTED_FUNCTION:             Unsupported function executed
 *  - #SB_RET_ERR_INVALID_ALIGNMENT:               Data entered with incorrect alignment
 *  - #SB_RET_ERR_MANI_TLV_FIELD_ERR:              Missing required TLV field
 *  - #SB_RET_ERR_MANI_TLV_INVALID_LEN:            The length of the TLV field has a size that exceeds the end of
 *                                                 the manifest.
 *  - #SB_RET_ERR_MANI_MISMATCH_SIGN_ALGORITHM:    There is a wrong combination of signature algorithms
 *  - #SB_RET_ERR_MANI_UNSUPPORTED_ALGORITHM:      There is a wrong combination of signature algorithms
 *  - #SB_RET_ERR_CRYPTO_FAIL:                     Encryption failed
 *  - #SB_RET_ERR_CRYPTO_AUTH_FAIL:                Verification failed
 *  - #SB_RET_ERR_CRYPTO_UNSUPPORTED_ALGORITHM:    Unsupported algorithm
 *  - #SB_RET_ERR_CRYPTO_PARAM_ERR:                Parameter error
 *  - #SB_RET_ERR_LOWER_IMAGE_VERSION:             Image version lower than the current image version is installed
 * \par Global Variables
 *  - None
 * \par Call SB-Driver API
 *  - R_CIP_DRV_CheckImageVersion
 *  - R_CIP_DRV_PrcVerifyCertChain
 * \par Precondition
 *  - None
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Check the value by parsing the TLV from the manifest
 *      - If the Image Cipher flag is set in Flags of the code certificate header, decrypt the image
 *      - If the signature target of the Code Certificate is a plaintext image, decrypt the image before verification,
 *        and if the signature target is an encrypted image, decrypt the image after verification.
 *      - If build configuration #SB_CFG_IMAGE_ENC_DEC is enabled, supports image decryption
 *      - Implement the following as a glitch countermeasure :
 *        - Add a flow counter before and after calling R_CIP_DRV_PrcVerifyCertChain
 *
 * Pseudo-code for the function can be found below.
 * -# Set dest_addr of Code Certificate header to img_addr
 * -# Set TLV search condition of Key Certificate to search_tlv_key_cert
 * -# Set TLV search condition of Code Certificate to search_tlv_code_cert
 * -# If (NULL != p_key_cert_st) && (NULL != p_code_cert_st) && (NULL != p_code_cert_st->p_header)
 *   -# Get TLV for key certificate and code certificate with #sb_get_cc_tlv
 *   -# Set function result to ret
 *   -# If #SB_RET_SUCCESS == ret
 *     -# Check certificate chain verification tlv with #sb_check_cert_chain_tlv
 *     -# If #SB_RET_SUCCESS == ret
 *       -# If the OEM_ROOT_PK value of the key certificate is NULL,
 *          set the start address of the Image public key TLV to p_key_cert_signer_pk_tlv.
 *          If the OEM_ROOT_PK value of the key certificate is not NULL,
 *          set the start address of the OEM_ROOT_PK TLV to p_key_cert_signer_pk_tlv.
 *       -# If the certificate signature value of the code certificate is not NULL
 *         -# Set the start address of the certificate signature TLV to p_code_cert_sign_tlv.
 *         -# If the Image hash value of the code certificate is NULL
 *            set the start address of the Encrypted Image hash TLV to p_img_hash_tlv.
 *            Else set the start address of the Image hash TLV to p_img_hash_tlv.
 *       -# Else if the Image Signature value of the code certificate is not NULL
 *         -# Set the start address of the Image Signature TLV to p_code_cert_sign_tlv.
 *         -# Set null to p_img_hash_tlv
 *       -# Else
 *         -# Set the start address of the Encrypted Image Signature TLV to p_code_cert_sign_tlv.
 *         -# Set null to p_img_hash_tlv
 *       -# If (p_code_cert_st->p_header->flags & #SB_PRV_CODE_CERT_HEADER_FLAGS_IMG_CIPHER_ENC) != 0UL &&
 *           (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX]) == p_code_cert_sign_tlv) ||
 *           (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX]) == p_code_cert_sign_tlv) &&
 *            ((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX]) == p_img_hash_tlv)))
 *         -# <B>--- If #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *         -# Decrypt the image with #sb_decrypt_img
 *         -# Set function result to ret
 *         -# Set CIP_DRV_CIPHER_TIMING_BEFORE_VERIFY to dec_img_param.timing
 *         -# Set dec_img_param address to p_dec_img_param
 *         -# If it contains image cipher info TLV
 *           -# Set dest_addr of image cipher info to img_addr
 *         -# Else
 *           -# Do nothing
 *         -# <B>--- Else #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *         -# Set #SB_RET_ERR_UNSUPPORTED_FUNCTION to ret
 *         -# <B>--- Endif #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *       -# Else
 *         -# Do nothing
 *       -# If #SB_RET_SUCCESS == ret
 *         -# Set key certificate driver parameters with #r_sb_cmn_drv_set_cc_key_cert_param
 *         -# Set function result to ret
 *         -# If #SB_RET_SUCCESS == ret
 *           -# Set code certificate driver parameters with #r_sb_cmn_drv_set_cc_code_cert_param
 *           -# Set function result to ret
 *           -# If #SB_RET_SUCCESS == ret
 *             -# To clear ret, set #SB_RET_ERR_INTERNAL_FAIL to ret and set CIP_DRV_RET_FAIL to cip_ret
 *             -# Add #SB_PRV_CMN_FC_SECUREBOOT_CNT to flow counter with #r_sb_cmn_fc_add_counter
 *             -# <B>--- If #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *             -# If (p_code_cert_st->p_header->flags & #SB_PRV_CODE_CERT_HEADER_FLAGS_IMG_CIPHER_ENC) != 0UL &&
 *                 (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX]) == p_code_cert_sign_tlv) ||
 *                 (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX]) == p_code_cert_sign_tlv) &&
 *                  ((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX]) == p_img_hash_tlv)))
 *               -# Set CIP_DRV_CIPHER_TIMING_AFTER_VERIFY to dec_img_param.timing
 *               -# Set dec_img_param address to p_dec_img_param
 *             -# else
 *               -# Add #SB_PRV_CMN_FC_SECUREBOOT_CNT to flow counter with #r_sb_cmn_fc_add_counter
 *             -# <B>--- Else #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *             -# Add #SB_PRV_CMN_FC_SECUREBOOT_CNT to flow counter with #r_sb_cmn_fc_add_counter
 *             -# <B>--- Endifse #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *             -# Call SB-Driver API R_CIP_DRV_PrcVerifyCertChain
 *             -# Set SB-Driver API result to cip_ret
 *             -# Get the return code from the value of cpi_ret with #r_sb_cmn_drv_get_sb_ret_from_cip_ret
 *             -# Set function result to ret
 *             -# Add #SB_PRV_CMN_FC_SECUREBOOT_CNT to flow counter with #r_sb_cmn_fc_add_counter
 *             -# If #SB_RET_SUCCESS == ret
 *               -# To clear ret, set #SB_RET_ERR_INTERNAL_FAIL to ret and set CIP_DRV_RET_FAIL to cip_ret
 *               -# Call SB-Driver API R_CIP_DRV_CheckImageVersion
 *               -# Set SB-Driver API result to cip_ret
 *               -# Get the return code from the value of cpi_ret with #r_sb_cmn_drv_get_sb_ret_from_cip_ret
 *               -# Set function result to ret
 *               -# Add #SB_PRV_CMN_FC_SECUREBOOT_CNT to flow counter with #r_sb_cmn_fc_add_counter
 *               -# If (#SB_RET_SUCCESS == ret) || (#SB_RET_SAME_IMAGE_VERSION == ret)
 *                 -# Set #SB_RET_SUCCESS to ret
 *                 -# If (p_code_cert_st->p_header->flags & #SB_PRV_CODE_CERT_HEADER_FLAGS_IMG_CIPHER_ENC) != 0UL &&
 *                      (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX]) == p_code_cert_sign_tlv) ||
 *                     ((((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX]) == p_code_cert_sign_tlv) &&
 *                       ((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX]) == p_img_hash_tlv)))
 *                   -# <B>--- If #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *                   -# Decrypt the image with #sb_decrypt_img
 *                   -# Add #SB_PRV_CMN_FC_SECUREBOOT_CNT to flow counter with #r_sb_cmn_fc_add_counter
 *                   -# Set function result to ret
 *                   -# <B>--- Else #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *                   -# Set #SB_RET_ERR_UNSUPPORTED_FUNCTION to ret
 *                   -# <B>--- Endif #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *                 -# Else
 *                   -# Do nothing
 *               -# Else
 *                 -# Do nothing
 *             -# Else
 *               -# Do nothing
 *           -# Else
 *             -# Do nothing
 *         -# Else
 *           -# Do nothing
 *       -# Else
 *         -# Do nothing
 *     -# Else
 *       -# Do nothing
 *   -# Else
 *     -# Do nothing
 * -# Else
 *   -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Return ret
 *
 * \callgraph
 *********************************************************************************************************************/
#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U)
sb_ret_t r_sb_sb_verify_cert_chain (const st_sb_key_cert_t * const  p_key_cert_st,
                                    const st_sb_code_cert_t * const p_code_cert_st)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t      ret;
    cip_drv_ret_t cip_ret;
    st_sb_tlv_t   key_cert_tlvs[SB_PRV_TLV_KEY_CERT_NUM];
    st_sb_tlv_t   code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_NUM];
    st_cip_drv_cc_key_cert_param_t  key_cert_param;
    st_cip_drv_cc_code_cert_param_t code_cert_param;
 #if (SB_CFG_IMAGE_ENC_DEC == 1U)
    st_cip_drv_cipher_img_param_t dec_img_param;
 #endif                                /* (SB_CFG_IMAGE_ENC_DEC == 1U) */
    const st_cip_drv_cipher_img_param_t * p_dec_img_param = NULL;
    const st_sb_tlv_t * p_key_cert_signer_pk_tlv;
    const st_sb_tlv_t * p_code_cert_sign_tlv;
    const st_sb_tlv_t * p_img_hash_tlv;
    uint32_t            img_addr;

    const st_sb_search_tlv_type_t search_tlv_key_cert[SB_PRV_TLV_KEY_CERT_NUM] =
    {
        {SB_PRV_TLV_KEY_OEM_ROOT_PK_TYPE, SB_PRV_TLV_KEY_MASK                   }, /* KEY_CERT_KEY_OEM_ROOT_PK_IDX */
        {SB_PRV_TLV_KEY_IMG_PK_TYPE,      SB_PRV_TLV_KEY_MASK                   }, /* KEY_CERT_KEY_IMG_PK_IDX */
        {SB_PRV_TLV_HASH_IMG_PK_TYPE,     SB_PRV_TLV_HASH_MASK                  }, /* KEY_CERT_HASH_IMG_PK_IDX */
        {SB_PRV_TLV_SIGN_CERT_TYPE,       SB_PRV_TLV_SIGN_MASK                  }, /* KEY_CERT_SIGN_CERT_IDX */
    };

    const st_sb_search_tlv_type_t search_tlv_code_cert[SB_PRV_TLV_CC_CODE_CERT_NUM] =
    {
        {SB_PRV_TLV_KEY_IMG_PK_TYPE,       SB_PRV_TLV_KEY_MASK                         }, /* SB_CODE_CERT_KEY_IMG_PK_IDX */
        {SB_PRV_TLV_HASH_IMG_TYPE,         SB_PRV_TLV_HASH_MASK                        }, /* SB_CODE_CERT_HASH_IMG_IDX */
        {SB_PRV_TLV_HASH_ENCIMG_TYPE,      SB_PRV_TLV_HASH_MASK                        }, /* SB_CODE_CERT_HASH_ENCIMG_IDX */
        {SB_PRV_TLV_IMG_CIP_INFO_TYPE,     SB_PRV_TLV_ICI_MASK                         }, /* SB_CODE_CERT_IMG_CIP_INFO_IDX */
        {SB_PRV_TLV_IMG_CIP_IV_TYPE,       SB_PRV_TLV_IV_MASK                          }, /* SB_CODE_CERT_IMG_CIP_IV_IDX */
        {SB_PRV_TLV_SIGN_CERT_TYPE,        SB_PRV_TLV_SIGN_MASK                        }, /* SB_CODE_CERT_SIGN_CERT_IDX */
        {SB_PRV_TLV_SIGN_CERT_IMG_TYPE,    SB_PRV_TLV_SIGN_MASK                        }, /* SB_CODE_CERT_SIGN_IMG_IDX */
        {SB_PRV_TLV_SIGN_CERT_ENCIMG_TYPE, SB_PRV_TLV_SIGN_MASK                        }, /* SB_CODE_CERT_SIGN_ENCIMG_IDX */
    };

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/
    if ((NULL != p_key_cert_st) && (NULL != p_code_cert_st) && (NULL != p_code_cert_st->p_header))
    {
        /* Image address use destination address of code certificate header */
        img_addr = p_code_cert_st->p_header->dest_addr;

        /* Get TLVs */
        ret = sb_get_cc_tlv(p_key_cert_st,
                            p_code_cert_st,
                            search_tlv_key_cert,
                            SB_PRV_TLV_KEY_CERT_NUM,
                            search_tlv_code_cert,
                            SB_PRV_TLV_CC_CODE_CERT_NUM,
                            key_cert_tlvs,
                            code_cert_tlvs);
        if (SB_RET_SUCCESS == ret)
        {
            /* Check cert chain tlv */
            ret = sb_check_cert_chain_tlv(key_cert_tlvs, code_cert_tlvs);
            if (SB_RET_SUCCESS == ret)
            {
                /* Select kye cert signer public key TLV */
                p_key_cert_signer_pk_tlv = (NULL == key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX].p_val) ?
                                           (&key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX]) :
                                           (&key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX]);

                /* Select code cert sign TVL and image hash TLV */
                if (NULL != code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX].p_val)
                {
                    p_code_cert_sign_tlv = &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX];
                    p_img_hash_tlv       = (NULL == code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX].p_val) ?
                                           (&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX]) :
                                           (&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX]);
                }
                else if (NULL != code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX].p_val)
                {
                    p_code_cert_sign_tlv = &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX];
                    p_img_hash_tlv       = NULL; /* Does not use image hash TLV */
                }
                else                             /* NULL != code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX].p_val */
                {
                    p_code_cert_sign_tlv = &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX];
                    p_img_hash_tlv       = NULL; /* Does not use image hash TLV */
                }

                /* Decrypt before signature */
                if (((p_code_cert_st->p_header->flags & SB_PRV_CODE_CERT_HEADER_FLAGS_IMG_CIPHER_ENC) != 0UL) &&
                    (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX]) == p_code_cert_sign_tlv) ||
                     (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX]) == p_code_cert_sign_tlv) &&
                      ((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX]) == p_img_hash_tlv))))
                {
 #if (SB_CFG_IMAGE_ENC_DEC == 1U)

                    /* Image cipher flag ON and code certificate signing target is not a cryptographic image */
                    ret = sb_decrypt_img(p_code_cert_st,
                                         &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_INFO_IDX],
                                         &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_IV_IDX],
                                         CIP_DRV_CIPHER_TIMING_BEFORE_VERIFY);

                    /* Set decyrpted timing in dec_img_param */
                    dec_img_param.timing = CIP_DRV_CIPHER_TIMING_BEFORE_VERIFY;
                    p_dec_img_param      = &dec_img_param;

                    if (NULL != code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_INFO_IDX].p_val)
                    {
                        /* Image address use destination address of image ciphre info */
                        img_addr = ((const st_sb_img_cip_info_val_t *)
                                    code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_INFO_IDX].p_val)->dest_addr;
                    }
                    else
                    {
                        /* Do nothing */
                    }

 #else                                 /* !(SB_CFG_IMAGE_ENC_DEC == 1U) */
                    /* Code decryption not supported */
                    ret = SB_RET_ERR_UNSUPPORTED_FUNCTION;
 #endif /* (SB_CFG_IMAGE_ENC_DEC == 1U) */
                }
                else
                {
                    /* Do nothing */
                }

                if (SB_RET_SUCCESS == ret)
                {
                    /* Set key certificate driver parameters */
                    ret =
                        r_sb_cmn_drv_set_cc_key_cert_param(p_key_cert_st,
                                                           &key_cert_tlvs[SB_PRV_TLV_KEY_CERT_HASH_IMG_PK_IDX],
                                                           p_key_cert_signer_pk_tlv,
                                                           &key_cert_tlvs[SB_PRV_TLV_KEY_CERT_SIGN_CERT_IDX],
                                                           &key_cert_param);
                    if (SB_RET_SUCCESS == ret)
                    {
                        /* Set code certificate driver parameters */
                        ret =
                            r_sb_cmn_drv_set_cc_code_cert_param(p_code_cert_st,
                                                                img_addr,
                                                                &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_KEY_IMG_PK_IDX],
                                                                p_code_cert_sign_tlv,
                                                                p_img_hash_tlv,
                                                                &code_cert_param);

                        /* Verification with certificate chain */
                        if (SB_RET_SUCCESS == ret)
                        {
                            /* Clear ret */
                            cip_ret = CIP_DRV_RET_FAIL;
                            ret     = SB_RET_ERR_INTERNAL_FAIL;

                            /* Add verify count to flow counter */
                            r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);

                            /* If the image is not decrypted, add the counter value
                             * When decrypt, add flow counter after decrypting
                             * This process is glitch countermeasure
                             * This must be done before verification */
 #if (SB_CFG_IMAGE_ENC_DEC == 1U)
                            if (((p_code_cert_st->p_header->flags & SB_PRV_CODE_CERT_HEADER_FLAGS_IMG_CIPHER_ENC) !=
                                 0UL) &&
                                (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX]) == p_code_cert_sign_tlv) ||
                                 (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX]) == p_code_cert_sign_tlv) &&
                                  ((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX]) == p_img_hash_tlv))))
                            {
                                /* Not added here, since it is added after decrypting */

                                /* Set decyrpted timing in dec_img_param */
                                dec_img_param.timing = CIP_DRV_CIPHER_TIMING_AFTER_VERIFY;
                                p_dec_img_param      = &dec_img_param;
                            }
                            else
                            {
                                r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);
                            }

 #else                                 /* (SB_CFG_IMAGE_ENC_DEC == 1U) */
                            r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);
 #endif /* (SB_CFG_IMAGE_ENC_DEC == 1U) */
                            /* Call SB-Driver API */
                            cip_ret = R_CIP_DRV_PrcVerifyCertChain(&key_cert_param, &code_cert_param, p_dec_img_param);
                            ret     = r_sb_cmn_drv_get_sb_ret_from_cip_ret(cip_ret);
                            r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);
                            if (SB_RET_SUCCESS == ret)
                            {
                                /* Clear ret */
                                cip_ret = CIP_DRV_RET_FAIL;
                                ret     = SB_RET_ERR_INTERNAL_FAIL;

                                /* Add verify count to flow counter */
                                r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);

                                /* Check image version */
                                cip_ret = R_CIP_DRV_CheckImageVersion(p_code_cert_st->p_header->img_version,
                                                                      p_code_cert_st->p_header->build_num);
                                ret = r_sb_cmn_drv_get_sb_ret_from_cip_ret(cip_ret);
                                r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);
                                if ((SB_RET_SUCCESS == ret) || (SB_RET_SAME_IMAGE_VERSION == ret))
                                {
                                    /* In the case of secure boot, it is only necessary to use the same version
                                     *  or higher, so set SUCCESS to ret */
                                    ret = SB_RET_SUCCESS;

                                    /* Decrypt after signature */
                                    if (((p_code_cert_st->p_header->flags &
                                          SB_PRV_CODE_CERT_HEADER_FLAGS_IMG_CIPHER_ENC) !=
                                         0UL) &&
                                        (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX]) ==
                                          p_code_cert_sign_tlv) ||
                                         (((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX]) ==
                                           p_code_cert_sign_tlv) &&
                                          ((&code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX]) ==
                                           p_img_hash_tlv))))
                                    {
 #if (SB_CFG_IMAGE_ENC_DEC == 1U)

                                        /* Image cipher flag ON and code certificate signing target
                                         *  is a cryptographic image */
                                        ret =
                                            sb_decrypt_img(p_code_cert_st,
                                                           &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_INFO_IDX],
                                                           &code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_IMG_CIP_IV_IDX],
                                                           CIP_DRV_CIPHER_TIMING_AFTER_VERIFY);
                                        r_sb_cmn_fc_add_counter(SB_PRV_CMN_FC_SECUREBOOT_CNT);
 #else                                 /* !(SB_CFG_IMAGE_ENC_DEC == 1U) */
                                        /* Code decryption not supported */
                                        ret = SB_RET_ERR_UNSUPPORTED_FUNCTION;
 #endif /* (SB_CFG_IMAGE_ENC_DEC == 1U) */
                                    }
                                    else
                                    {
                                        /* Do nothing */
                                    }
                                }
                                else
                                {
                                    /* Do nothing */
                                }
                            }
                            else
                            {
                                /* Do nothing */
                            }
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        ret = SB_RET_ERR_INTERNAL_FAIL;
    }

    return ret;
}

#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) */

/**********************************************************************************************************************
 * End of function r_sb_sb_verify_cert_chain()
 **********************************************************************************************************************/

/*=====================================================================================================================
 * Private function definitions
 * =====================================================================================================================*/

/**********************************************************************************************************************
 * Function Name : sb_decrypt_img
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIsInternal
 * \brief       Obtain the Image Cipher Info from the code certificate and decrypt the Image Cipher Info
 * \param       [in]   p_code_cert_st          Start address of Code Certificate Structure
 * \param       [in]   p_img_cip_info          Start address of Image Cipher Info
 * \param       [in]   p_img_cip_iv            Start address of Image Cipher IV
 * \param       [in]   timing                  Decyption timing viewed from signature verification
 * \return
 *  - #SB_RET_SUCCESS:                             Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                   Internal processing failed
 *  - #SB_RET_ERR_INVALID_ALIGNMENT:               Data entered with incorrect alignment
 *  - #SB_RET_ERR_MANI_TLV_INVALID_LEN:            The length of the TLV field has a size that exceeds the end of
 *                                                 the manifest.
 *  - #SB_RET_ERR_MANI_UNSUPPORTED_ALGORITHM:      There is a wrong combination of signature algorithms
 *  - #SB_RET_ERR_CRYPTO_FAIL:                     Encryption failed
 *  - #SB_RET_ERR_CRYPTO_UNSUPPORTED_ALGORITHM:    Unsupported algorithm
 *  - #SB_RET_ERR_CRYPTO_PARAM_ERR:                Parameter error
 * \par Global Variables
 *  - None
 * \par Call SB-Driver API
 *  - R_CIP_DRV_PrcDecryptImage
 * \par Precondition
 *  - None
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Perform image decryption
 *      - If the Code Certificate has an Image Cipher Info TLV, decrypt based on that information
 *        If not, decrypt with the default value of CIP-Driver
 *      - If build configuration #SB_CFG_IMAGE_ENC_DEC is enabled, this function is targeted for compilation
 *
 * Pseudo-code for the function can be found below.
 * -# <B>--- If #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 * -# Set #SB_RET_SUCCESS to ret
 * -# If (NULL != p_code_cert_st) && (NULL != p_img_cip_info) && (NULL != p_img_cip_iv)
 *   -# Set (const st_sb_img_cip_info_val_t*)(p_img_cip_info->p_val) to p_img_cip_info_val
 *   -# If NULL != p_img_cip_info_val
 *     -# If (p_img_cip_info_val->dest_addr & SB_PRV_REMAINDER_DIV4) != 0UL
 *       -# Set #SB_RET_ERR_INVALID_ALIGNMENT to ret
 *     -# Else
 *       -# Do nothing
 *   -# Else
 *     -# Do nothing
 *   -# If #SB_RET_SUCCESS == ret
 *     -# Set Image Cipher Info parameters with #r_sb_cmn_drv_set_cipher_img_param
 *     -# Set function result to ret
 *     -# If #SB_RET_SUCCESS == ret
 *       -# Call SB-Driver API R_CIP_DRV_PrcDecryptImage
 *       -# Set SB-Driver API result to cip_ret
 *       -# Get the return code from the value of cpi_ret with #r_sb_cmn_drv_get_sb_ret_from_cip_ret
 *       -# Set function result to ret
 *     -# Else
 *       -# Do nothing
 *   -# Else
 *     -# Do nothing
 * -# Else
 *   -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Return ret
 * -# <B>--- Endif #SB_CFG_IMAGE_ENC_DEC is enabled ---</B>
 *
 * \callgraph
 *********************************************************************************************************************/
#if (SB_CFG_IMAGE_ENC_DEC == 1U)
static sb_ret_t sb_decrypt_img (const st_sb_code_cert_t * const p_code_cert_st,
                                const st_sb_tlv_t * const       p_img_cip_info,
                                const st_sb_tlv_t * const       p_img_cip_iv,
                                const uint32_t                  timing)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t                         ret = SB_RET_SUCCESS;
    cip_drv_ret_t                    cip_ret;
    st_cip_drv_cipher_img_param_t    img_param;
    const st_sb_img_cip_info_val_t * p_img_cip_info_val;

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/
    if ((NULL != p_code_cert_st) && (NULL != p_img_cip_info) && (NULL != p_img_cip_iv))
    {
        p_img_cip_info_val = (const st_sb_img_cip_info_val_t *) (p_img_cip_info->p_val); /* Casting from pointer
                                                                                          * to pointer is no problem */
        if (NULL != p_img_cip_info_val)
        {
            /* Check image alignment */
            if ((p_img_cip_info_val->dest_addr & SB_PRV_REMAINDER_DIV4) != 0UL)
            {
                /* Invalid image alignment */
                ret = SB_RET_ERR_INVALID_ALIGNMENT;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }

        if (SB_RET_SUCCESS == ret)
        {
            ret = r_sb_cmn_drv_set_cipher_img_param(p_code_cert_st,
                                                    p_img_cip_info,
                                                    p_img_cip_iv,
                                                    SB_PRV_FALSE,
                                                    timing,
                                                    &img_param);
            if (SB_RET_SUCCESS == ret)
            {
                cip_ret = R_CIP_DRV_PrcDecryptImage(&img_param);
                ret     = r_sb_cmn_drv_get_sb_ret_from_cip_ret(cip_ret);
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        ret = SB_RET_ERR_INTERNAL_FAIL;
    }

    return ret;
}

#endif                                 /* (SB_CFG_IMAGE_ENC_DEC == 1U) */

/**********************************************************************************************************************
 * End of function sb_decrypt_img()
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name : sb_check_cert_chain_tlv
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIsInternal
 * \brief       Check the obtained TLV of Certificate Chain
 * \param       [in]   p_key_cert_tlvs         Start address of Key Certificate TLVs
 * \param       [in]   p_code_cert_tlvs        Start address of Code Certificate TLVs
 * \return
 *  - #SB_RET_SUCCESS:                          Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                Internal processing failed
 *  - #SB_RET_ERR_UNSUPPORTED_FUNCTION:         Unsupported function executed
 *  - #SB_RET_ERR_MANI_TLV_FIELD_ERR:           Missing required TLV fields
 * \par Global Variables
 *  - None
 * \par Call SB-Driver API
 *  - None
 * \par Precondition
 *  - None
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Check that the TLV of the key certificate has Image public key Hash and Key Certificate signature
 *      - Confirm that the OEM root public key or Image public key is specified in the key class TLV of the
 *        key certificate. (NG if both are specified)
 *      - Confirm that Code Certificate TLV has signature verification public key
 *      - Confirm that Code Certificate TLV has signature
 *      - Confirm that Code Certificate TLV has image hash (When only the certificate is to be signed)
 *
 * Pseudo-code for the function can be found below.
 * -# Set #SB_RET_SUCCESS to ret
 * -# If (NULL != p_key_cert_tlvs) && (NULL != p_code_cert_tlvs)
 *   -# If the value of Image public key hash TLV of the key certificate is not NULL and
 *      the value of Key Certificate signature TLV is not NULL
 *     -# If the value of the OEM_ROOT_PK TLV of the key certificate is not NULL and
 *        the value of the Image public key TLV is NULL, or \n
 *        if the value of the OEM_ROOT_PK TLV of the key certificate is NULL and
 *        the value of the Image public key TLV is not NULL
 *       -# If the value of Image public key TLV of the code certificate is not NULL
 *         -# If only one of the following is non-NULL \n
 *            Certificate Signature TLV \n
 *            Certificate and Image Signature TLV \n
 *            Certificate and Encrypted Image Signature TLV \n
 *           -# If Signature TLV is Certificate only
 *             -# If only one of the following is non-NULL \n
 *                Image Hash TLV \n
 *                Encrypted Image Hash TLV \n
 *               -# TLV field OK. Do nothing
 *             -# Else
 *               -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *           -# Else
 *             -# TLV field OK. Do nothing
 *         -# Else
 *           -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *         -# Else
 *           -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *       -# Else
 *         -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *     -# Else
 *       -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *   -# Else
 *     -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *   -# <B>--- If #SB_CFG_SB_CERT_CHAIN_USE_IMG_PK is disabled ---</B>
 *   -# If (SB_RET_SUCCESS == ret) &&
 *          (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val)
 *     -# Set #SB_RET_ERR_UNSUPPORTED_FUNCTION to ret
 *   -# Else
 *     -# Do nothing
 *   -# <B>--- Endif #SB_CFG_SB_CERT_CHAIN_USE_IMG_PK is disabled ---</B>
 * -# Else
 *   -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Return ret
 *
 * \callgraph
 *********************************************************************************************************************/
#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U)
static sb_ret_t sb_check_cert_chain_tlv (const st_sb_tlv_t * const p_key_cert_tlvs,
                                         const st_sb_tlv_t * const p_code_cert_tlvs)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t ret = SB_RET_SUCCESS;

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/
    if ((NULL != p_key_cert_tlvs) && (NULL != p_code_cert_tlvs))
    {
        /*  Check requeste TLV in key cert */
        if ((NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_HASH_IMG_PK_IDX].p_val) &&
            (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_SIGN_CERT_IDX].p_val))
        {
            /*  Check select TLV in key cert */
            if (((NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX].p_val) &&
                 (NULL == p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val)) ||
                ((NULL == p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX].p_val) &&
                 (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val)))
            {
                /*  Check requeste TLV in code cert */
                if (NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_KEY_IMG_PK_IDX].p_val)
                {
                    /*  Check select TLV in code cert */
                    if (((NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX].p_val) &&
                         (NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX].p_val) &&
                         (NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX].p_val)) ||
                        ((NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX].p_val) &&
                         (NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX].p_val) &&
                         (NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX].p_val)) ||
                        ((NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX].p_val) &&
                         (NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_IMG_IDX].p_val) &&
                         (NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_ENCIMG_IDX].p_val)))
                    {
                        if (NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_SIGN_CERT_IDX].p_val)
                        {
                            if (((NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX].p_val) &&
                                 (NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX].p_val)) ||
                                ((NULL == p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_IMG_IDX].p_val) &&
                                 (NULL != p_code_cert_tlvs[SB_PRV_TLV_CC_CODE_CERT_HASH_ENCIMG_IDX].p_val)))
                            {
                                /* TLV field OK. Do nothing */
                            }
                            else
                            {
                                ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                            }
                        }
                        else
                        {
                            /* TLV field OK. Do nothing */
                        }
                    }
                    else
                    {
                        ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                    }
                }
                else
                {
                    ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                }
            }
            else
            {
                ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
            }
        }
        else
        {
            ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
        }

 #if (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 0U)
        if ((SB_RET_SUCCESS == ret) &&
            (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val))
        {
            ret = SB_RET_ERR_UNSUPPORTED_FUNCTION;
        }
        else
        {
            /* Do nothing */
        }
 #endif                                /* (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 0U) */
    }
    else
    {
        /* Since this function is only called from within the library, this route is not usually taken */
        ret = SB_RET_ERR_INTERNAL_FAIL;
    }

    return ret;
}

#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) */

/**********************************************************************************************************************
 * End of function sb_check_cert_chain_tlv()
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name : sb_check_check_integrity_tlv
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIsInternal
 * \brief       Check the obtained TLV of Check Integrity
 * \param       [in]   p_key_cert_tlvs         Start address of Key Certificate TLVs
 * \param       [in]   p_code_cert_tlvs        Start address of Code Certificate TLVs
 * \return
 *  - #SB_RET_SUCCESS:                          Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                Internal processing failed
 *  - #SB_RET_ERR_UNSUPPORTED_FUNCTION:         Unsupported function executed
 *  - #SB_RET_ERR_MANI_TLV_FIELD_ERR:           Missing required TLV fields
 * \par Global Variables
 *  - None
 * \par Call SB-Driver API
 *  - None
 * \par Precondition
 *  - None
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Check that the TLV of the key certificate has Image public key Hash and Key Certificate signature
 *      - Confirm that the OEM root public key or Image public key is specified in the key class TLV of the
 *        key certificate. (NG if both are specified)
 *      - Confirm that Code Certificate TLV has signature verification public key
 *      - Confirm that Code Certificate TLV has signature
 *      - Confirm that Code Certificate TLV has image hash (When only the certificate is to be signed)
 *
 * Pseudo-code for the function can be found below.
 * -# Set #SB_RET_SUCCESS to ret
 * -# If (NULL != p_key_cert_tlvs) && (NULL != p_code_cert_tlvs)
 *   -# If the value of Image public key hash TLV of the key certificate is not NULL and
 *      the value of Key Certificate signature TLV is not NULL
 *     -# If the value of the OEM_ROOT_PK TLV of the key certificate is not NULL and
 *        the value of the Image public key TLV is NULL, or \n
 *        if the value of the OEM_ROOT_PK TLV of the key certificate is NULL and
 *        the value of the Image public key TLV is not NULL
 *       -# If the value of Image public key TLV of the code certificate is not NULL
 *         -# If only one of the following is non-NULL \n
 *            Certificate Signature TLV \n
 *            Certificate and Image Signature TLV \n
 *           -# If Signature TLV is Certificate only
 *             -# If only one of the following is non-NULL \n
 *                Image Hash TLV \n
 *               -# TLV field OK. Do nothing
 *             -# Else
 *               -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *           -# Else
 *             -# TLV field OK. Do nothing
 *         -# Else
 *           -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *         -# Else
 *           -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *       -# Else
 *         -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *     -# Else
 *       -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *   -# Else
 *     -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *   -# <B>--- If #SB_CFG_SB_CERT_CHAIN_USE_IMG_PK is disabled ---</B>
 *   -# If (SB_RET_SUCCESS == ret) &&
 *          (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val)
 *     -# Set #SB_RET_ERR_UNSUPPORTED_FUNCTION to ret
 *   -# Else
 *     -# Do nothing
 *   -# <B>--- Endif #SB_CFG_SB_CERT_CHAIN_USE_IMG_PK is disabled ---</B>
 * -# Else
 *   -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Return ret
 *
 * \callgraph
 *********************************************************************************************************************/
#if (SB_CFG_CHECK_INTEGRITY == 1U)
static sb_ret_t sb_check_check_integrity_tlv (const st_sb_tlv_t * const p_key_cert_tlvs,
                                              const st_sb_tlv_t * const p_code_cert_tlvs)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t ret = SB_RET_SUCCESS;

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/
    if ((NULL != p_key_cert_tlvs) && (NULL != p_code_cert_tlvs))
    {
        /*  Check requeste TLV in key cert */
        if ((NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_HASH_IMG_PK_IDX].p_val) &&
            (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_SIGN_CERT_IDX].p_val))
        {
            /*  Check select TLV in key cert */
            if (((NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX].p_val) &&
                 (NULL == p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val)) ||
                ((NULL == p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_OEM_ROOT_PK_IDX].p_val) &&
                 (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val)))
            {
                /*  Check requeste TLV in code cert */
                if (NULL != p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_KEY_IMG_PK_IDX].p_val)
                {
                    /*  Check select TLV in code cert */
                    if (((NULL != p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_SIGN_CERT_IDX].p_val) &&
                         (NULL == p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_SIGN_IMG_IDX].p_val)) ||
                        ((NULL == p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_SIGN_CERT_IDX].p_val) &&
                         (NULL != p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_SIGN_IMG_IDX].p_val)))
                    {
                        if (NULL != p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_SIGN_CERT_IDX].p_val)
                        {
                            if (NULL != p_code_cert_tlvs[SB_PRV_TLV_CI_CODE_CERT_HASH_IMG_IDX].p_val)
                            {
                                /* TLV field OK. Do nothing */
                            }
                            else
                            {
                                ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                            }
                        }
                        else
                        {
                            /* TLV field OK. Do nothing */
                        }
                    }
                    else
                    {
                        ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                    }
                }
                else
                {
                    ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                }
            }
            else
            {
                ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
            }
        }
        else
        {
            ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
        }

 #if (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 0U)
        if ((SB_RET_SUCCESS == ret) &&
            (NULL != p_key_cert_tlvs[SB_PRV_TLV_KEY_CERT_KEY_IMG_PK_IDX].p_val))
        {
            ret = SB_RET_ERR_UNSUPPORTED_FUNCTION;
        }
        else
        {
            /* Do nothing */
        }
 #endif                                /* (SB_CFG_SB_CERT_CHAIN_USE_IMG_PK == 0U) */
    }
    else
    {
        /* Since this function is only called from within the library, this route is not usually taken */
        ret = SB_RET_ERR_INTERNAL_FAIL;
    }

    return ret;
}

#endif                                 /* (SB_CFG_CHECK_INTEGRITY == 1U) */

/**********************************************************************************************************************
 * End of function sb_check_check_integrity_tlv()
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name : sb_check_mac_tlv
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIsInternal
 * \brief       Check the obtained TLV of MAC verify
 * \param       [in]   p_mac_tlv               Start address of MAC TLVs
 * \param       [in]   p_img_pk_tlv            Start address of Image public key TLVs
 * \return
 *  - #SB_RET_SUCCESS:                          Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                Internal processing failed
 *  - #SB_RET_ERR_MANI_TLV_FIELD_ERR:           Missing required TLV fields
 * \par Global Variables
 *  - None
 * \par Call SB-Driver API
 *  - None
 * \par Precondition
 *  - None
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Check that the Use Type of the MAC Type class is
 *        "Code Certificate + Image MAC" or "Code Certificate + Encrypted Image MAC"
 *
 * Pseudo-code for the function can be found below.
 * -# Set #SB_RET_SUCCESS to ret
 * -# If NULL != p_mac_tlv
 *   -# If MAC type is #SB_PRV_TLV_MAC_CERT_IMG_TYPE or
 *      if MAC type is #SB_PRV_TLV_MAC_CERT_ENCIMG_TYPE
 *     -# If NULL != p_img_pk_tlv
 *       -# If p_img_pk_tlv->val != NULL
 *         -# Do nothing
 *       -# Else
 *         -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 *     -# Else
 *       -# Do nothing
 *   -# Else
 *     -# Set #SB_RET_ERR_MANI_TLV_FIELD_ERR to ret
 * -# Else
 *   -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Return ret
 *
 * \callgraph
 *********************************************************************************************************************/
#if (SB_CFG_SB_MAC_VERIFICATION == 1U)
static sb_ret_t sb_check_mac_tlv (const st_sb_tlv_t * const p_mac_tlv, const st_sb_tlv_t * const p_img_pk_tlv)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t ret = SB_RET_SUCCESS;

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/

    /* Check NULL argument excepted p_img_pk_tlv */
    if (NULL != p_mac_tlv)
    {
        /*  Check MAC Type class and Use Type(Because MAC is an input from outside the library) */
        if (((p_mac_tlv->type & SB_PRV_TLV_MAC_MASK) == SB_PRV_TLV_MAC_CERT_IMG_TYPE) ||
            ((p_mac_tlv->type & SB_PRV_TLV_MAC_MASK) == SB_PRV_TLV_MAC_CERT_ENCIMG_TYPE))
        {
            if (NULL != p_img_pk_tlv)
            {
                if (NULL != p_img_pk_tlv->p_val)
                {
                    /* TLV field OK. Do nothing */
                }
                else
                {
                    ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
                }
            }
            else
            {
                /* TLV field OK. Do nothing */
            }
        }
        else
        {
            ret = SB_RET_ERR_MANI_TLV_FIELD_ERR;
        }
    }
    else
    {
        /* Since this function is only called from within the library, this route is not usually taken */
        ret = SB_RET_ERR_INTERNAL_FAIL;
    }

    return ret;
}

#endif                                 /* (SB_CFG_SB_MAC_VERIFICATION == 1U) */

/**********************************************************************************************************************
 * End of function sb_check_mac_tlv()
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name : sb_get_cc_tlv
 **********************************************************************************************************************/

/*!****************************************************************************************************************//**
 * \ingroup     SBLIBSecureBootAPIsInternal
 * \brief       Search key certificate and code certificate TLVs and confirm the obtained TLVs
 * \param       [in]   p_key_cert_st               Start address of Key Certificate Structure
 * \param       [in]   p_code_cert_st              Start address of Code Certificate Structure
 * \param       [in]   p_search_tlv_key_cert       Start address of Key certificate TLVs search information
 * \param       [in]   search_tlv_key_cert_num     Number of Key certificates TLV to search
 * \param       [in]   p_search_tlv_code_cert      Start address of Code certificate TLVs search information
 * \param       [in]   search_tlv_code_cert_num    Number of Code certificates TLV to search
 * \param       [out]  p_key_cert_tlvs             Output address of Key certificate TLVs
 * \param       [out]  p_code_cert_tlvs            Output address of Code certificate TLVs
 * \return
 *  - #SB_RET_SUCCESS:                          Successful completion
 *  - #SB_RET_ERR_INTERNAL_FAIL:                Internal processing failed
 *  - #SB_RET_ERR_MANI_TLV_FIELD_ERR:           Missing required TLV fields
 *  - #SB_RET_ERR_MANI_TLV_INVALID_LEN:         The length of the TLV field has a size that exceeds the end of
 *                                              the manifest.
 * \par Global Variables
 *  - None
 * \par Call SB-Driver API
 *  - None
 * \par Precondition
 *  - None
 * \par Security components
 *  - yes
 * \par Detailed description
 *      - Parse the Key certificate TLV based on the search conditions passed in the arguments
 *      - Parse the Code certificate TLV based on the search conditions passed in the arguments
 *      - Check if the parsed TLV information is correct
 *
 * Pseudo-code for the function can be found below.
 * -# If (NULL != p_key_cert_st) && (NULL != p_code_cert_st) && (NULL != p_search_tlv_key_cert) &&
 *       (NULL != p_search_tlv_code_cert) && (NULL != p_key_cert_tlvs) && (NULL != p_code_cert_tlvs)
 *   -# Parse the key certificate TLV with #r_sb_mani_parse_tlvs
 *   -# Set function result to ret
 *   -# If #SB_RET_SUCCESS == ret
 *     -# Parse the code certificate TLV with #r_sb_mani_parse_tlvs
 *     -# Set function result to ret
 *   -# Else
 *     -# Do nothing
 * -# Else
 *   -# Set #SB_RET_ERR_INTERNAL_FAIL to ret
 * -# Return ret
 *
 * \callgraph
 *********************************************************************************************************************/
#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) || (SB_CFG_CHECK_INTEGRITY == 1U)
static sb_ret_t sb_get_cc_tlv (const st_sb_key_cert_t * const        p_key_cert_st,
                               const st_sb_code_cert_t * const       p_code_cert_st,
                               const st_sb_search_tlv_type_t * const p_search_tlv_key_cert,
                               const uint32_t                        search_tlv_key_cert_num,
                               const st_sb_search_tlv_type_t * const p_search_tlv_code_cert,
                               const uint32_t                        search_tlv_code_cert_num,
                               st_sb_tlv_t * const                   p_key_cert_tlvs,
                               st_sb_tlv_t * const                   p_code_cert_tlvs)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t ret;

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/

    /* Check NULL argument */
    if ((NULL != p_key_cert_st) && (NULL != p_code_cert_st) && (NULL != p_search_tlv_key_cert) &&
        (NULL != p_search_tlv_code_cert) && (NULL != p_key_cert_tlvs) && (NULL != p_code_cert_tlvs))
    {
        /* Get Key cert TLVs */
        ret = r_sb_mani_parse_tlvs(p_key_cert_st->p_tlv_top,
                                   p_key_cert_st->tlv_len,
                                   search_tlv_key_cert_num,
                                   p_search_tlv_key_cert,
                                   p_key_cert_tlvs);
        if (SB_RET_SUCCESS == ret)
        {
            ret = r_sb_mani_parse_tlvs(p_code_cert_st->p_tlv_top,
                                       p_code_cert_st->tlv_len,
                                       search_tlv_code_cert_num,
                                       p_search_tlv_code_cert,
                                       p_code_cert_tlvs);
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Since this function is only called from within the library, this route is not usually taken */
        ret = SB_RET_ERR_INTERNAL_FAIL;
    }

    return ret;
}

#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) || (SB_CFG_CHECK_INTEGRITY == 1U) */

/**********************************************************************************************************************
 * End of function sb_get_cc_tlv()
 **********************************************************************************************************************/

/*=====================================================================================================================
 * End of file
 * =====================================================================================================================*/
