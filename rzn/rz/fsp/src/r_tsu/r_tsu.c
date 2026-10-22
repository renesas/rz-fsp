/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "r_tsu.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "RTSU" in ASCII, used to determine if channel is open. */
#define TSU_OPEN                           (0x52545355U)

/* Stabilization time to start TSU. */
#define TSU_START_STABILIZATION_TIME_US    (60U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** TSU Implementation of ADC. */
const adc_api_t g_adc_on_tsu =
{
    .open           = R_TSU_Open,
    .scanCfg        = R_TSU_ScanCfg,
    .scanStart      = R_TSU_ScanStart,
    .scanGroupStart = R_TSU_ScanGroupStart,
    .scanStop       = R_TSU_ScanStop,
    .scanStatusGet  = R_TSU_StatusGet,
    .read           = R_TSU_Read,
    .read32         = R_TSU_Read32,
    .calibrate      = R_TSU_Calibrate,
    .offsetSet      = R_TSU_OffsetSet,
    .callbackSet    = R_TSU_CallbackSet,
    .close          = R_TSU_Close,
    .infoGet        = R_TSU_InfoGet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_TSU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Start the TSU module.
 *
 * @retval FSP_SUCCESS                     Module is ready for use.
 * @retval FSP_ERR_ASSERTION               An input argument is invalid.
 * @retval FSP_ERR_ALREADY_OPEN            The instance control structure has already been opened.
 **********************************************************************************************************************/
fsp_err_t R_TSU_Open (adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg)
{
    tsu_instance_ctrl_t * p_instance_ctrl = (tsu_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking. */
#if TSU_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);

    /* Verify this unit has not already been initialized. */
    FSP_ERROR_RETURN(TSU_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_cfg);
#endif

    /* Start the TSU module. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_TSU, 0);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Set the divider value for PCLKL. */
    R_TSU->TSUSCS = (uint32_t) (R_SYSC_S->SCKCR2_b.DIVSELSUB << R_TSU_TSUSCS_CKDIV_Pos) | 1U;

    /* Mark driver as open by initializing it to "RTSU" in its ASCII equivalent for this unit. */
    p_instance_ctrl->open = TSU_OPEN;

    /* Return the error code. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable the temperature sensor and ADC. Start A/D conversion.
 *
 * @note Even if the A/D conversion starts, it takes time for the results to be stored. So wait until the result is
 * stored and then read.
 *
 * @retval FSP_SUCCESS                 Scan started.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_IN_USE              Another scan is still in progress.
 **********************************************************************************************************************/
fsp_err_t R_TSU_ScanStart (adc_ctrl_t * p_ctrl)
{
    tsu_instance_ctrl_t * p_instance_ctrl = (tsu_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking. */
#if TSU_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Verify Another scan is not in progress. */
    FSP_ERROR_RETURN(0U == R_TSU->TSUSS, FSP_ERR_IN_USE);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Enable the temperature sensor and ADC. */
    R_TSU->TSUSM = R_TSU_TSUSM_TSEN_Msk | R_TSU_TSUSM_ADCEN_Msk;

    /* Wait 60us. See "Operation" in the TSU section of the relevant hardware manual. */
    R_BSP_SoftwareDelay(TSU_START_STABILIZATION_TIME_US, BSP_DELAY_UNITS_MICROSECONDS);

    /* Start A/D conversion. */
    R_TSU->TSUST = R_TSU_TSUST_START_Msk;

    /* Do a dummy read to set the START bit to 1. */
    FSP_REGISTER_READ(R_TSU->TSUST);

    /* Return the error code. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop A/D conversion. Disable the temperature sensor and ADC.
 *
 * @retval FSP_SUCCESS                 Scan stopped.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_TSU_ScanStop (adc_ctrl_t * p_ctrl)
{
    tsu_instance_ctrl_t * p_instance_ctrl = (tsu_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking. */
#if TSU_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Read TSUSAD before setting START bit to 0.
     * See "Register Descriptions" in the TSU section of the relevant hardware manual. */
    FSP_REGISTER_READ(R_TSU->TSUSAD);

    /* Stop A/D conversion. */
    R_TSU->TSUST = 0U;

    /* Confirm TSUSS.CONV = 0. See "Operation" in the TSU section of the relevant hardware manual. */
    FSP_HARDWARE_REGISTER_WAIT(R_TSU->TSUSS, 0U);

    /* Disable the temperature sensor and ADC. */
    R_TSU->TSUSM = 0U;

    /* Return the error code. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provide the A/D conversion status.
 *
 * @retval FSP_SUCCESS                 Module status stored in the provided pointer p_status.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_TSU_StatusGet (adc_ctrl_t * p_ctrl, adc_status_t * p_status)
{
    tsu_instance_ctrl_t * p_instance_ctrl = (tsu_instance_ctrl_t *) p_ctrl;

#if TSU_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(TSU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Read the status of the TSUSS.CONV bit. CONV is set when a scan is in progress. */
    p_status->state = (adc_state_t) R_TSU->TSUSS;

    /* Return the error code. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads conversion results from a sensor.
 *
 * @note Specify ADC_CHANNEL_TEMPERATURE for reg_id.
 *
 * @retval FSP_SUCCESS                 Data read into provided p_data.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 * @retval FSP_ERR_INVALID_STATE       Read command not valid in the current state.
 **********************************************************************************************************************/
fsp_err_t R_TSU_Read (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data)
{
    tsu_instance_ctrl_t * p_instance_ctrl = (tsu_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking. */
#if TSU_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(TSU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Verify the reg_id is valid. */
    FSP_ASSERT(ADC_CHANNEL_TEMPERATURE == reg_id);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
#endif

    /* Verify TSUST.START bit is 1 before reading the sensor data.
     * See "Operation" in the TSU section of the relevant hardware manual. */
    FSP_ERROR_RETURN(1U == R_TSU->TSUST, FSP_ERR_INVALID_STATE);

    /* Read the sensor data from the register and return it. */
    *p_data = (uint16_t) R_TSU->TSUSAD;

    /* Return the error code. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stop the TSU module.
 *
 * @retval FSP_SUCCESS                 Module closed.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_TSU_Close (adc_ctrl_t * p_ctrl)
{
    tsu_instance_ctrl_t * p_instance_ctrl = (tsu_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking. */
#if TSU_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Mark driver as closed. */
    p_instance_ctrl->open = 0U;

    /* Stop the TSU module. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_TSU, 0);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Return the error code. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::scanCfg is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_ScanCfg (adc_ctrl_t * p_ctrl, void const * const p_extend)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_extend);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::scanGroupStart is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_ScanGroupStart (adc_ctrl_t * p_ctrl, adc_group_mask_t group_mask)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(group_mask);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::read32 is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_Read32 (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
    FSP_PARAMETER_NOT_USED(p_data);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::calibrate is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_Calibrate (adc_ctrl_t * const p_ctrl, void const * p_extend)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_extend);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::offsetSet is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_OffsetSet (adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
    FSP_PARAMETER_NOT_USED(offset);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::callbackSet is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_CallbackSet (adc_ctrl_t * const          p_ctrl,
                             void (                    * p_callback)(adc_callback_args_t *),
                             void * const                p_context,
                             adc_callback_args_t * const p_callback_memory)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_callback);
    FSP_PARAMETER_NOT_USED(p_context);
    FSP_PARAMETER_NOT_USED(p_callback_memory);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::infoGet is not supported on the TSU.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_InfoGet (adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_adc_info);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup TSU)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
