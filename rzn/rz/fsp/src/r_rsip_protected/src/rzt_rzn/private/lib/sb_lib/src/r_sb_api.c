/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/* PRQA S 0306 ++ # D001 Cast for address setting and checking */
/* PRQA S 2981 ++ # D010 Processing for flow verification */
/* PRQA S 5002 ++ # D018 Exception according to file nomenclature */

/*=====================================================================================================================
 * Includes <System Includes> , "Project Includes"
 * =====================================================================================================================*/
#include <stddef.h>
#include "r_sb_api.h"
#include "r_sb_build_config.h"
#include "r_sb_cmn.h"
#include "r_sb_manifest.h"
#include "r_sb_sb.h"

/*=====================================================================================================================
 * Private macro definitions
 * =====================================================================================================================*/

/* Error checking needs to be done where the settings are used, not in a configuration file. */
#if (SB_CFG_PARAM_CHECKING_ENABLE == 1U)
 #if (0U != SB_CFG_SB_MAC_VERIFICATION) && (1U != SB_CFG_SB_MAC_VERIFICATION)
  #error This is an error check from the build configuration. Cause: SB_CFG_SB_MAC_VERIFICATION
 #endif
 #if (0U != SB_CFG_SB_CERT_CHAIN_VERIFICATION) && (1U != SB_CFG_SB_CERT_CHAIN_VERIFICATION)
  #error This is an error check from the build configuration. Cause: SB_CFG_SB_CERT_CHAIN_VERIFICATION
 #endif
 #if (0U != SB_CFG_SB_CERT_CHAIN_USE_IMG_PK) && (1U != SB_CFG_SB_CERT_CHAIN_USE_IMG_PK)
  #error This is an error check from the build configuration. Cause: SB_CFG_SB_CERT_CHAIN_USE_IMG_PK
 #endif
 #if (0U != SB_CFG_IMAGE_ENC_DEC) && (1U != SB_CFG_IMAGE_ENC_DEC)
  #error This is an error check from the build configuration. Cause: SB_CFG_IMAGE_ENC_DEC
 #endif
 #if (0U != SB_CFG_CHECK_CRC) && (1U != SB_CFG_CHECK_CRC)
  #error This is an error check from the build configuration. Cause: SB_CFG_CHECK_CRC
 #endif
 #if (0U != SB_CFG_CHECK_INTEGRITY) && (1U != SB_CFG_CHECK_INTEGRITY)
  #error This is an error check from the build configuration. Cause: SB_CFG_CHECK_INTEGRITY
 #endif
#endif

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

/*=====================================================================================================================
 * Public function definitions
 * =====================================================================================================================*/

/**********************************************************************************************************************
 * Function Name : R_SB_SecureBoot
 **********************************************************************************************************************/
sb_ret_t R_SB_SecureBoot (const uint8_t * const p_key_cert,
                          const uint32_t        key_cert_len_max,
                          const uint8_t * const p_code_cert,
                          const uint32_t        code_cert_len_max,
                          const uint8_t * const p_mac_tlv)
{
    /*-----------------------------------------------------------------------------------------------------------------
     * Local variables
     * -----------------------------------------------------------------------------------------------------------------*/
    sb_ret_t  ret;
    sb_bool_t flow_correct_ret = SB_PRV_FALSE;
#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U)
    st_sb_key_cert_t key_cert_st;
#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) */
#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) || (SB_CFG_SB_MAC_VERIFICATION == 1U)
    st_sb_code_cert_t code_cert_st;
#endif                                 /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) || (SB_CFG_SB_MAC_VERIFICATION == 1U) */
#if (SB_CFG_SB_MAC_VERIFICATION == 1U)
    st_sb_tlv_t mac_tlv_st;
#endif                                 /* (SB_CFG_SB_MAC_VERIFICATION == 1U) */

    /*-----------------------------------------------------------------------------------------------------------------
     * Function body
     * -----------------------------------------------------------------------------------------------------------------*/

    /* Initialize flow counter */
    r_sb_cmn_fc_sb_init();

    /* Select veritication mode */
    if (NULL == p_mac_tlv)
    {
#if (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U)

        /* Check NULL argument excepted key_cert (may be placed at 0x0) and mac_tlv (optional) */
        if (NULL != p_code_cert)
        {
            /* Check alignment */
            /* No problem with casting to pointer size */
            if ((((uintptr_t) p_key_cert & (uintptr_t) SB_PRV_REMAINDER_DIV4) == (uintptr_t) 0UL) &&
                (((uintptr_t) p_code_cert & (uintptr_t) SB_PRV_REMAINDER_DIV4) == (uintptr_t) 0UL)) /*Same cast as above*/
            {
                /* Set Key cert structure */
                ret = r_sb_mani_set_key_cert_st(p_key_cert, &key_cert_st);
                if (SB_RET_SUCCESS == ret)
                {
                    /* Check key cert */
                    ret = r_sb_mani_chk_key_cert(&key_cert_st, key_cert_len_max);
                    if (SB_RET_SUCCESS == ret)
                    {
                        /* Set Code cert structure */
                        ret = r_sb_mani_set_code_cert_st(p_code_cert, &code_cert_st);
                        if (SB_RET_SUCCESS == ret)
                        {
                            /* Check code cert */
                            ret = r_sb_mani_chk_code_cert(&code_cert_st, code_cert_len_max);
                            if (SB_RET_SUCCESS == ret)
                            {
                                /* Verify certificate chain */
                                ret = r_sb_sb_verify_cert_chain(&key_cert_st, &code_cert_st);
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
                    /* Do nothing. */
                }
            }
            else
            {
                /* Invalid alignment */
                ret = SB_RET_ERR_INVALID_ALIGNMENT;
            }
        }
        else
        {
            /* Invalid argument */
            ret = SB_RET_ERR_INVALID_ARG;
        }

#else                                  /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) */
        ret = SB_RET_ERR_UNSUPPORTED_FUNCTION;
#endif /* (SB_CFG_SB_CERT_CHAIN_VERIFICATION == 1U) */
    }
    else
    {
#if (SB_CFG_SB_MAC_VERIFICATION == 1U)

        /* Check NULL argument excepted mac_tlv */
        if (NULL != p_code_cert)
        {
            /* Check alignment */
            /* No problem with casting to pointer size */
            if ((((uintptr_t) p_code_cert & (uintptr_t) SB_PRV_REMAINDER_DIV4) == (uintptr_t) 0UL) &&
                (((uintptr_t) p_mac_tlv & (uintptr_t) SB_PRV_REMAINDER_DIV4) == (uintptr_t) 0UL)) /* Same cast as above */
            {
                /* Set Code cert structure */
                ret = r_sb_mani_set_code_cert_st(p_code_cert, &code_cert_st);
                if (SB_RET_SUCCESS == ret)
                {
                    /* Check code cert */
                    ret = r_sb_mani_chk_code_cert(&code_cert_st, code_cert_len_max);
                    if (SB_RET_SUCCESS == ret)
                    {
                        /* Set MAC TLV structure */
                        ret = r_sb_mani_set_mac_tlv_st(p_mac_tlv, &mac_tlv_st);
                        if (SB_RET_SUCCESS == ret)
                        {
                            /* Verify MAC */
                            ret = r_sb_sb_verify_mac(&code_cert_st, &mac_tlv_st);
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing. */
                    }
                }
                else
                {
                    /* Do nothing. */
                }
            }
            else
            {
                /* Invalid alignment */
                ret = SB_RET_ERR_INVALID_ALIGNMENT;
            }
        }
        else
        {
            /* Invalid argument */
            ret = SB_RET_ERR_INVALID_ARG;
        }

#else                                  /* (SB_CFG_SB_MAC_VERIFICATION == 1U) */
        ret = SB_RET_ERR_UNSUPPORTED_FUNCTION;
#endif  /* (SB_CFG_SB_MAC_VERIFICATION == 1U) */
    }

    /* Verify flow counter */
    flow_correct_ret = r_sb_cmn_fc_is_sb_flow_correct();
    if (SB_RET_SUCCESS == ret)
    {
        if (SB_PRV_TRUE == flow_correct_ret)
        {
            /* Do nothing */
        }
        else
        {
            /* Flow counter mismatch  */
            ret = SB_RET_ERR_INTERNAL_FAIL;
        }
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/**********************************************************************************************************************
 * End of function R_SB_SecureBoot()
 **********************************************************************************************************************/

/*=====================================================================================================================
 * Private function definitions
 * =====================================================================================================================*/

/*=====================================================================================================================
 * End of file
 * =====================================================================================================================*/
