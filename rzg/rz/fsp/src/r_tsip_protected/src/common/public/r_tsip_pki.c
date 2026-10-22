/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_public.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static tsip_func_pki_cert_key_import_t select_func_cert_key_import(tsip_key_type_t key_type);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_TSIP_PROTECTED
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Exports verified certificate information stored in this driver.
 *
 * The certificate is last called function R_TSIP_PKI_ECDSA_CertVerify(), R_TSIP_PKI_RSASSA_PKCS1_V1_5_CertVerify(),
 * R_TSIP_PKI_RSASSA_PSS_CertVerify(), or R_TSIP_PKI_VerifiedCertInfoImport().
 *
 * Implements @ref tsip_api_t::pkiVerifiedCertInfoExport.
 *
 * @par State transition
 * This API can be executed in **any state** including STATE_INITIAL, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS       Normal termination.
 * @retval FSP_ERR_ASSERTION A required parameter is NULL.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_PKI_VerifiedCertInfoExport (tsip_ctrl_t * const               p_ctrl,
                                             tsip_verified_cert_info_t * const p_verified_cert_info)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_verified_cert_info);
#endif

    memcpy(p_verified_cert_info, &p_instance_ctrl->pki_verified_cert_info, sizeof(tsip_verified_cert_info_t));

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Imports verified certificate information.
 *
 * Implements @ref tsip_api_t::pkiVerifiedCertInfoImport.
 *
 * @par State transition
 * This API can be executed in **any state** including STATE_INITIAL, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS       Normal termination.
 * @retval FSP_ERR_ASSERTION A required parameter is NULL.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_PKI_VerifiedCertInfoImport (tsip_ctrl_t * const                     p_ctrl,
                                             tsip_verified_cert_info_t const * const p_verified_cert_info)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_verified_cert_info);
#endif

    memcpy(&p_instance_ctrl->pki_verified_cert_info, p_verified_cert_info, sizeof(tsip_verified_cert_info_t));

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Wraps the public key in the verified public key certificate.
 *
 * Implements @ref tsip_api_t::pkiCertKeyImport.
 *
 * @par Conditions
 * @parblock
 * Argument @ref RZG::tsip_wrapped_key_t::type must be supported by both the function and the device,
 * and must also be enabled in the configuration. For more details, please refer to
 * @ref RZG_r-tsip-protected-supported-algorithms "Supported Algorithms" and
 * @ref RZG_r-tsip-protected-configuration "Configuration".
 * @endparblock
 *
 * @par State transition
 * This API can only be executed in **STATE_MAIN**, and does not cause any state transitions.
 *
 * @retval FSP_SUCCESS                           Normal termination.
 * @retval FSP_ERR_ASSERTION                     A required parameter is NULL.
 * @retval FSP_ERR_NOT_OPEN                      Module is not open.
 * @retval FSP_ERR_INVALID_STATE                 Internal state is illegal.
 * @retval FSP_ERR_NOT_ENABLED                   Input key type is disabled in this function by configuration.
 * @retval FSP_ERR_CRYPTO_TSIP_FAIL              Input parameter is invalid.
 *
 * @retval FSP_ERR_IN_USE A resource conflict occurred because a hardware resource required
 *                                               by the processing is in use by other processing.
 * @retval FSP_ERR_CRYPTO_TSIP_FATAL             Software corruption is detected.
 *
 * @note
 * - Argument p_cert must correspond to the signature of the last called function R_TSIP_PKI_ECDSA_CertVerify(),
 *   R_TSIP_PKI_RSASSA_PKCS1_V1_5_CertVerify(), or R_TSIP_PKI_RSASSA_PSS_CertVerify().
 * - For arguments p_key_param1 and p_key_param2, specify an address inside the certificate.
 *   Addresses outside the certificate are invalid.
 **********************************************************************************************************************/
fsp_err_t R_TSIP_PKI_CertKeyImport (tsip_ctrl_t * const        p_ctrl,
                                    uint8_t const * const      p_cert,
                                    uint32_t const             cert_length,
                                    uint8_t const * const      p_key_param1,
                                    uint32_t const             key_param1_length,
                                    uint8_t const * const      p_key_param2,
                                    uint32_t const             key_param2_length,
                                    tsip_hash_type_t const     hash_function,
                                    tsip_wrapped_key_t * const p_wrapped_public_key)
{
    tsip_instance_ctrl_t * p_instance_ctrl = (tsip_instance_ctrl_t *) p_ctrl;

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cert);
    FSP_ASSERT(p_key_param1);
    FSP_ASSERT(p_key_param2);
    FSP_ASSERT(p_wrapped_public_key);
    FSP_ASSERT(p_wrapped_public_key->p_value);
    FSP_ERROR_RETURN(TSIP_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsip_func_pki_cert_key_import_t p_func = select_func_cert_key_import(p_wrapped_public_key->type); // Set function

#if TSIP_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_func, FSP_ERR_NOT_ENABLED);                                                    // Check configuration
#endif

    /* Check state */
    FSP_ERROR_RETURN(TSIP_STATE_MAIN == p_instance_ctrl->state, FSP_ERR_INVALID_STATE);

    uint32_t certificate_length[1] =
    {
        bswap_32big(cert_length)
    };

    uint32_t certificate_pubkey[4] =
    {
        bswap_32big((uint32_t) ((uintptr_t) p_key_param1 - (uintptr_t) p_cert)),                         // Start position of param1
        bswap_32big((uint32_t) ((uintptr_t) p_key_param1 - (uintptr_t) p_cert + key_param1_length - 1)), // End position of param1
        bswap_32big((uint32_t) ((uintptr_t) p_key_param2 - (uintptr_t) p_cert)),                         // Start position of param2
        bswap_32big((uint32_t) ((uintptr_t) p_key_param2 - (uintptr_t) p_cert + key_param2_length - 1)), // End position of param2
    };

    uint32_t hash_type[1] =
    {
        bswap_32big(g_pki_hash_type[hash_function])
    };

    /* Call function (cast to match the argument type with the primitive function) */
    tsip_ret_t tsip_ret = p_func(hash_type,
                                 (uint32_t const *) p_cert,
                                 certificate_length,
                                 (uint32_t const *) certificate_pubkey,
                                 (uint32_t *) &p_instance_ctrl->pki_verified_cert_info,
                                 (uint32_t *) p_wrapped_public_key->p_value);

    /* Check error */
    fsp_err_t err = FSP_ERR_CRYPTO_TSIP_FATAL;
    switch (tsip_ret)
    {
        case TSIP_RET_PASS:
        {
            err = FSP_SUCCESS;
            break;
        }

        case TSIP_RET_RESOURCE_CONFLICT:
        {
            err = FSP_ERR_IN_USE;
            break;
        }

        case TSIP_RET_FAIL:
        {
            err = FSP_ERR_CRYPTO_TSIP_FAIL;
            break;
        }

        default:
        {
            err = FSP_ERR_CRYPTO_TSIP_FATAL;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * @}
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Get parameter length from key type.
 *
 * @param[in]  key_type      Key type.
 ***********************************************************************************************************************/
static tsip_func_pki_cert_key_import_t select_func_cert_key_import (tsip_key_type_t key_type)
{
    tsip_func_pki_cert_key_import_t ret          = NULL;
    tsip_key_type_extend_t          key_type_ext = r_tsip_key_type_parse(key_type);

    switch (key_type_ext.alg)
    {
        case TSIP_PRV_ALG_ECC_PUBLIC:
        {
            ret = gp_func_pki_cert_key_import_ecc[key_type_ext.subtype];
            break;
        }

        case TSIP_PRV_ALG_RSA_PUBLIC:
        {
            ret = gp_func_pki_cert_key_import_rsa[key_type_ext.subtype];
            break;
        }

        default:
        {
            /* Do nothing */
        }
    }

    return ret;
}
