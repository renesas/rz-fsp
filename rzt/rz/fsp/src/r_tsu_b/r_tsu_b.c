/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#include "r_tsu_b.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "TSUB" in ASCII, used to determine if channel is open. */
#define TSU_B_OPEN    (0x54535542U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

static void     r_tsu_b_open_sub(tsu_b_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg);
void            tsu_b_scan_end_isr(void);
void            tsu_b_compare_isr(void);
static void     r_tsu_b_irq_enable(IRQn_Type irq, uint8_t ipl, void * p_context);
static void     r_tsu_b_irq_disable(IRQn_Type irq);
static void     r_tsu_b_call_callback(tsu_b_instance_ctrl_t * p_ctrl, adc_callback_args_t * p_args);
static uint32_t r_tsu_b_calculate_comparison_value(tsu_b_instance_ctrl_t * const p_instance_ctrl,
                                                   int                           setting_temperature);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** TSU_B Implementation of ADC. */
const adc_api_t g_adc_on_tsu_b =
{
    .open           = R_TSU_B_Open,
    .scanCfg        = R_TSU_B_ScanCfg,
    .infoGet        = R_TSU_B_InfoGet,
    .scanStart      = R_TSU_B_ScanStart,
    .scanGroupStart = R_TSU_B_ScanGroupStart,
    .scanStop       = R_TSU_B_ScanStop,
    .scanStatusGet  = R_TSU_B_StatusGet,
    .read           = R_TSU_B_Read,
    .read32         = R_TSU_B_Read32,
    .close          = R_TSU_B_Close,
    .calibrate      = R_TSU_B_Calibrate,
    .offsetSet      = R_TSU_B_OffsetSet,
    .callbackSet    = R_TSU_B_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_TSU_B
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes the TSU_B module and applies configurations.
 *
 * @retval FSP_SUCCESS                     Module is ready for use.
 * @retval FSP_ERR_ASSERTION               An input argument is invalid.
 * @retval FSP_ERR_ALREADY_OPEN            The instance control structure has already been opened.
 * @retval FSP_ERR_IRQ_BSP_DISABLED        A callback is provided, but the interrupt is not enabled.
 * @retval FSP_ERR_INVALID_HW_CONDITION    Calibration data is invalid value, so TSU_B is in invalid condition.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_Open (adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg)
{
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking */
#if TSU_B_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);

    /* Verify the configuration parameters are valid   */
    FSP_ASSERT(NULL != p_cfg);

    /* Verify this unit has not already been initialized   */
    FSP_ERROR_RETURN(TSU_B_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    tsu_b_extended_cfg_t const * p_extend = (tsu_b_extended_cfg_t const *) p_cfg->p_extend;

    /* Verify the extended configuration parameters are valid */
    FSP_ASSERT(NULL != p_extend);
    FSP_ASSERT(NULL != p_extend->p_reg);

    /* If a callback is used, then make sure an interrupt is enabled */
    if (NULL != p_cfg->p_callback)
    {
        FSP_ERROR_RETURN((p_cfg->scan_end_irq >= 0) || (p_extend->compare_irq >= 0), FSP_ERR_IRQ_BSP_DISABLED);
    }

#else
    tsu_b_extended_cfg_t const * p_extend = (tsu_b_extended_cfg_t const *) p_cfg->p_extend;
#endif

    /* Save configurations. */
    p_instance_ctrl->p_cfg = p_cfg;
#if BSP_FEATURE_TSU_B_CALIBRAION_DATA_CHECK_ENABLE
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* OTP power on setting. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 1);

    /* Set the low temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_LOW_TEMPERATURE_REGISTER;

    /* Read low temperature calibration data. */
    volatile uint32_t calibration_data1 = R_OTP->OTPDATARD;

    /* Set the high temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_HIGH_TEMPERATURE_REGISTER;

    /* Read high temperature calibration data. */
    volatile uint32_t calibration_data2 = R_OTP->OTPDATARD;

    /* OTP power off setting. */
    R_OTP->OTPPWR &= (uint32_t) ~(R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk);
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 0);

    FSP_CRITICAL_SECTION_EXIT;

    FSP_ERROR_RETURN(
        BSP_FEATURE_TSU_B_CALIBRAION_DATA_INVALID != calibration_data1 && BSP_FEATURE_TSU_B_CALIBRAION_DATA_INVALID != calibration_data2,
        FSP_ERR_INVALID_HW_CONDITION);
#endif
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Calculate the register base address. */
    p_instance_ctrl->p_reg = (R_TSU_B0_Type *) p_extend->p_reg;

    /* Initialize the hardware based on the configuration. */
    r_tsu_b_open_sub(p_instance_ctrl, p_cfg);

    /* Enable interrupts */
    r_tsu_b_irq_enable(p_cfg->scan_end_irq, p_cfg->scan_end_ipl, p_instance_ctrl);
    r_tsu_b_irq_enable(p_extend->compare_irq, p_extend->compare_ipl, p_instance_ctrl);

    /* Mark driver as opened by initializing it to "TSUB" in its ASCII equivalent for this unit. */
    p_instance_ctrl->open = TSU_B_OPEN;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements adc_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_CallbackSet (adc_ctrl_t * const          p_api_ctrl,
                               void (                    * p_callback)(adc_callback_args_t *),
                               void * const                p_context,
                               adc_callback_args_t * const p_callback_memory)
{
    tsu_b_instance_ctrl_t * p_ctrl = (tsu_b_instance_ctrl_t *) p_api_ctrl;

#if (TSU_B_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */

    p_ctrl->p_callback = p_callback;

    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts a software scan or enables the hardware trigger for a scan depending on how the triggers were configured in
 * the R_TSU_B_Open call. If the unit was configured for ELC or external hardware triggering, then this function allows
 * the trigger signal to get to the TSU_B unit. The function is not able to control the generation of the trigger itself.
 * If the unit was configured for software triggering, then this function starts the software triggered scan.
 *
 * @retval FSP_SUCCESS                 Scan started (software trigger) or hardware triggers enabled.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            TSU_B is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     TSU_B is not initialized.
 * @retval FSP_ERR_IN_USE              Another scan is still in progress (software trigger).
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_ScanStart (adc_ctrl_t * p_ctrl)
{
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking  */
#if TSU_B_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
    FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->SSR, FSP_ERR_IN_USE);
#endif

    /* Start conversion. */
    if (ADC_TRIGGER_SOFTWARE == p_instance_ctrl->p_cfg->trigger)
    {
        p_instance_ctrl->p_reg->STRGR_b.ADST = 1U;
    }

#if BSP_FEATURE_TSU_B_ELC_TRIGGER_SUPPORTED
    else
    {
        p_instance_ctrl->p_reg->SOSR1_b.TRGE = 1U;
    }
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get current TSU_B status and store it in provided pointer p_status.
 * Provides the status of any scan process that was started, including scans started by ELC or external triggers.
 *
 * @retval FSP_SUCCESS                 Module status stored in the provided pointer p_status
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_StatusGet (adc_ctrl_t * p_ctrl, adc_status_t * p_status)
{
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

#if TSU_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Read the status of the SSR bit. SSR is set when a scan is in progress. */
    p_status->state = (adc_state_t) p_instance_ctrl->p_reg->SSR_b.CONV;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads conversion results from a sensor.
 *
 * @retval FSP_SUCCESS                 Data read into provided p_data.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            TSU_B is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     TSU_B is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_Read (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint16_t * const p_data)
{
    FSP_PARAMETER_NOT_USED(reg_id);
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking. */
#if TSU_B_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
#endif

    /* Read the data from the requested TSU_B conversion register and return it */
    *p_data = (uint16_t) p_instance_ctrl->p_reg->SCRR;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the calibration data for the sensor.
 *
 * @retval FSP_SUCCESS                 Information stored in p_adc_info.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            TSU_B is not open.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_InfoGet (adc_ctrl_t * p_ctrl, adc_info_t * p_adc_info)
{
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;

#if TSU_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_adc_info);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_adc_info->length        = 1U;
    p_adc_info->p_address     = &p_instance_ctrl->p_reg->SCRR;
    p_adc_info->transfer_size = TRANSFER_SIZE_2_BYTE;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* OTP power on setting. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 1);

    /* Set the low temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_LOW_TEMPERATURE_REGISTER;

    /* Set low temperature calibration data. */
    p_adc_info->calibration_data1 = R_OTP->OTPDATARD;

    /* Set the high temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_HIGH_TEMPERATURE_REGISTER;

    /* Set high temperature calibration data. */
    p_adc_info->calibration_data2 = R_OTP->OTPDATARD;

    /* OTP power off setting. */
    R_OTP->OTPPWR &= (uint32_t) ~(R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk);
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 0);

    FSP_CRITICAL_SECTION_EXIT;

    return err;
}

/*******************************************************************************************************************//**
 * Disables the unit from being triggered by the hardware trigger (ELC or external) based on
 * what type of trigger the unit was configured for in the R_TSU_B_Open function. Stopping a hardware triggered scan via
 * this function does not abort an ongoing scan, but prevents the next scan from occurring.
 *
 * @retval FSP_SUCCESS                 Hardware triggers disabled.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            TSU_B is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     TSU_B is not initialized.
 * @retval FSP_ERR_INVALID_MODE        Not valid for software triggers.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_ScanStop (adc_ctrl_t * p_ctrl)
{
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

    /*  Perform parameter checking */
#if TSU_B_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
 #if !BSP_FEATURE_TSU_B_CONTINUOUS_MODE_SUPPORTED
    FSP_ERROR_RETURN(ADC_TRIGGER_SOFTWARE != p_instance_ctrl->p_cfg->trigger, FSP_ERR_INVALID_MODE);
 #endif
#endif

    /* Disable hardware trigger. */
    if (ADC_TRIGGER_SYNC_ELC == p_instance_ctrl->p_cfg->trigger)
    {
#if BSP_FEATURE_TSU_B_ELC_TRIGGER_SUPPORTED
        p_instance_ctrl->p_reg->SOSR1_b.TRGE = 0U;
#endif
    }
    else
    {
#if BSP_FEATURE_TSU_B_CONTINUOUS_MODE_SUPPORTED
        p_instance_ctrl->p_reg->STRGR_b.ADEND = 1U;
#endif
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The value returned from the sensor can be converted into degrees Celsius.
 *
 * @retval FSP_SUCCESS                 Data calculate into provided p_temp.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            TSU_B is not open.
 * @retval FSP_ERR_NOT_INITIALIZED     TSU_B is not initialized.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_CalculateTemperature (adc_ctrl_t * p_ctrl, uint16_t temperature_code, float * const p_temperature)
{
    /*  Perform parameter checking */
#if TSU_B_CFG_PARAM_CHECKING_ENABLE
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
#endif

    FSP_PARAMETER_NOT_USED(p_ctrl);

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* OTP power on setting. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 1);

    /* Set the low temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_LOW_TEMPERATURE_REGISTER;

    /* Read low temperature calibration data. */
    volatile uint32_t calibration_data1 = R_OTP->OTPDATARD;

    /* Set the high temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_HIGH_TEMPERATURE_REGISTER;

    /* Read high temperature calibration data. */
    volatile uint32_t calibration_data2 = R_OTP->OTPDATARD;

    /* OTP power off setting. */
    R_OTP->OTPPWR &= (uint32_t) ~(R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk);
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 0);

    FSP_CRITICAL_SECTION_EXIT;

    /* Calculate the temperature. Reference section "Temperature Compensation Calculation" in the hardware manual.
     * The correspondence of constants is shown below.
     * temperature_code                                             : a
     * calibration_data1(the value at low temperature)              : b
     * calibration_data2(the value at high temperature)             : c
     * BSP_FEATURE_TSU_B_LOW_TEMPERATURE(low temperature)           : d
     * BSP_FEATURE_TSU_B_HIGH_TEMPERATURE(high temperature)         : e */
    float term1;
    float term2;
    float calibration_data1f = (float) calibration_data1;
    float calibration_data2f = (float) calibration_data2;

    /* Calculate the term1. Reference section "Temperature Compensation Calculation" in the hardware manual.*/
    term1 = (BSP_FEATURE_TSU_B_HIGH_TEMPERATURE - BSP_FEATURE_TSU_B_LOW_TEMPERATURE) /
            (calibration_data2f - calibration_data1f);

    /* Calculate the term2. Reference section "Temperature Compensation Calculation" in the hardware manual.*/
    term2 = (float) temperature_code - (float) calibration_data1;

    *p_temperature = (term1 * term2) + BSP_FEATURE_TSU_B_LOW_TEMPERATURE;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * This function ends any scan in progress, disables interrupts, and removes power to the A/D peripheral.
 *
 * @retval FSP_SUCCESS                 Module closed.
 * @retval FSP_ERR_ASSERTION           An input argument is invalid.
 * @retval FSP_ERR_NOT_OPEN            Unit is not open.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_Close (adc_ctrl_t * p_ctrl)
{
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;

#if TSU_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    tsu_b_extended_cfg_t * p_extend = (tsu_b_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Mark driver as closed   */
    p_instance_ctrl->open        = 0U;
    p_instance_ctrl->initialized = 0U;

    /* Disable interrupts. */
    r_tsu_b_irq_disable(p_instance_ctrl->p_cfg->scan_end_irq);
    r_tsu_b_irq_disable(p_extend->compare_irq);

    /* Clear the interrupt status flag.  */
    p_instance_ctrl->p_reg->SICR = R_TSU_B0_SICR_ADCLR_Msk | R_TSU_B0_SICR_CMPCLR_Msk;
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->SICR);

    /* Confirm TSU_SISR = 0. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->SISR, 0U);

    /* Stop the TSU_B. */
    p_instance_ctrl->p_reg->SSUSR = R_TSU_B0_SSUSR_ADC_PD_Msk;

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_TSU, p_instance_ctrl->p_cfg->unit);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::scanCfg is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_ScanCfg (adc_ctrl_t * p_ctrl, void const * const p_channel_cfg)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_channel_cfg);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::scanGroupStart is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_ScanGroupStart (adc_ctrl_t * p_ctrl, adc_group_mask_t group_id)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(group_id);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::read32 is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_Read32 (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
    FSP_PARAMETER_NOT_USED(p_data);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::calibrate is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_Calibrate (adc_ctrl_t * const p_ctrl, void const * p_extend)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_extend);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @ref adc_api_t::offsetSet is not supported.
 *
 * @retval FSP_ERR_UNSUPPORTED         Function not supported in this implementation.
 **********************************************************************************************************************/
fsp_err_t R_TSU_B_OffsetSet (adc_ctrl_t * const p_ctrl, adc_channel_t const reg_id, int32_t offset)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(reg_id);
    FSP_PARAMETER_NOT_USED(offset);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup TSU_B)
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
 * The Open function applies power to the TSU_B peripheral, sets the value for SOSR1, CMSR, SIER, LLSR, ULSR.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  p_cfg                   Pointer to configuration structure
 **********************************************************************************************************************/
static void r_tsu_b_open_sub (tsu_b_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg)
{
    tsu_b_extended_cfg_t const * p_cfg_extend = (tsu_b_extended_cfg_t const *) p_cfg->p_extend;

    /* Determine the value for SSUSR, SOSR1, CMSR, LLSR, ULSR, SIER.*/
    /* Release the TSU_B from the power-down state. */
    uint32_t ssusr = (uint32_t) (0U << R_TSU_B0_SSUSR_ADC_PD_Pos);
    ssusr |= (uint32_t) (R_TSU_B0_SSUSR_EN_TS_Msk | R_TSU_B0_SSUSR_SOC_TS_EN_Msk);

    /* Sets the average counts. */
    uint32_t sosr1 = (uint32_t) (R_TSU_B0_SOSR1_OUTSEL_Msk);
    sosr1 |= (uint32_t) (p_cfg_extend->average_count << R_TSU_B0_SOSR1_ADCT_Pos);

#if BSP_FEATURE_TSU_B_ELC_TRIGGER_SUPPORTED

    /* Sets the trigger. */
    sosr1 |= (uint32_t) (0U << R_TSU_SOSR1_TRGE_Pos);
#endif

    /* Repeat mode corresponds to ADC_MODE_CONTINUOUS_SCAN of API,
     * but since the API value (=2) and repeat mode register setting value (=1) are different,
     * it is necessary to convert them.
     * Sets the conversion mode. */
    sosr1 |= (uint32_t) ((p_cfg->mode >> 1U) << R_TSU_B0_SOSR1_ADCS_Pos);

    uint32_t cmsr;
    uint32_t sier;
    uint32_t llsr              = 0U;
    uint32_t ulsr              = 0U;
    int32_t  setting_temp_low  = p_cfg_extend->compare_ref_low;
    int32_t  setting_temp_high = p_cfg_extend->compare_ref_high;

    /* When using Comparison Function, set the compare mode and lower limit value, upper limit value. */
    if (TSU_B_COMPARE_CFG_DISABLE != p_cfg_extend->comparison_mode)
    {
        cmsr = (uint32_t) (p_cfg_extend->comparison_mode << R_TSU_B0_CMSR_CMPEN_Pos);
        llsr = r_tsu_b_calculate_comparison_value(p_instance_ctrl, setting_temp_low);
        ulsr = r_tsu_b_calculate_comparison_value(p_instance_ctrl, setting_temp_high);
    }
    else
    {
        cmsr = (uint32_t) (0U << R_TSU_B0_CMSR_CMPEN_Pos);
    }

    sier = (uint32_t) (R_TSU_B0_SIER_ADIE_Msk | R_TSU_B0_SIER_CMPIE_Msk);

    /* Apply clock to peripheral. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_TSU, p_instance_ctrl->p_cfg->unit);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Set the predetermined values for SSUSR, SOSR1, CMSR, LLSR, ULSR, SIER.*/
    p_instance_ctrl->p_reg->SSUSR = ssusr;
    p_instance_ctrl->p_reg->SOSR1 = sosr1;
    p_instance_ctrl->p_reg->CMSR  = cmsr;
    p_instance_ctrl->p_reg->LLSR  = llsr;
    p_instance_ctrl->p_reg->ULSR  = ulsr;
    p_instance_ctrl->p_reg->SIER  = sier;

    R_BSP_SoftwareDelay(5U, BSP_DELAY_UNITS_MICROSECONDS);

    p_instance_ctrl->initialized = TSU_B_OPEN;
}

/*******************************************************************************************************************//**
 * Calculate comparison setting values.
 *
 * @param[in]  p_instance_ctrl         Pointer to instance control block
 * @param[in]  setting_temperature     The temperature T (degrees Celsius) you want to set.
 *
 * @retval  calculate_value  The comparison setting values
 **********************************************************************************************************************/
static uint32_t r_tsu_b_calculate_comparison_value (tsu_b_instance_ctrl_t * const p_instance_ctrl,
                                                    int                           setting_temperature)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* OTP power on setting. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 1);

    /* Set the low temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_LOW_TEMPERATURE_REGISTER;

    /* Read low temperature calibration data. */
    volatile uint32_t calibration_data1 = R_OTP->OTPDATARD;

    /* Set the high temperature calibration data address to the OTPADRRD register. */
    R_OTP->OTPADRRD = BSP_FEATURE_TSU_B_UNIT_0_HIGH_TEMPERATURE_REGISTER;

    /* Read high temperature calibration data. */
    volatile uint32_t calibration_data2 = R_OTP->OTPDATARD;

    /* OTP power off setting. */
    R_OTP->OTPPWR &= (uint32_t) ~(R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk);
    FSP_HARDWARE_REGISTER_WAIT(R_OTP->OTPSTR_b.CMD_RDY, 0);

    FSP_CRITICAL_SECTION_EXIT;

    /* Calculate the comparison setting values. Reference section "Temperature Compensation Calculation" in the hardware manual.
     * The correspondence of constants is shown below.
     * setting_temperature                                          : T
     * calibration_data1(the value at low temperature)              : b
     * calibration_data2(the value at high temperature)             : c
     * BSP_FEATURE_TSU_B_LOW_TEMPERATURE(low temperature)           : d
     * BSP_FEATURE_TSU_B_HIGH_TEMPERATURE(high temperature)         : e */
    uint32_t calculate_value;
    float    term1;
    float    term2;
    float    term3;
    float    term4;

    /* Calculate the term1. Reference section "Comparison Setting Value Calculation" in the hardware manual.*/
    term1 = (float) setting_temperature - BSP_FEATURE_TSU_B_LOW_TEMPERATURE;

    /* Calculate the term2. Reference section "Comparison Setting Value Calculation" in the hardware manual.*/
    float calibration_data1f = (float) calibration_data1;
    float calibration_data2f = (float) calibration_data2;
    term2 = calibration_data2f - calibration_data1f;

    /* Calculate the term3. Reference section "Comparison Setting Value Calculation" in the hardware manual.*/
    term3 = BSP_FEATURE_TSU_B_HIGH_TEMPERATURE - BSP_FEATURE_TSU_B_LOW_TEMPERATURE;

    /* Calculate the term4. Reference section "Comparison Setting Value Calculation" in the hardware manual.*/
    term4 = (term1 * term2) / term3;

    /* Calculate the setting value. Reference section "Comparison Setting Value Calculation" in the hardware manual.*/
    calculate_value = (uint32_t) (term4 + (float) calibration_data1);

    return calculate_value;
}

/*******************************************************************************************************************//**
 * Enables requested IRQ.
 *
 * @param[in]  irq        IRQ to enable
 * @param[in]  ipl        Interrupt priority
 * @param[in]  p_context  Pointer to interrupt context
 **********************************************************************************************************************/
static void r_tsu_b_irq_enable (IRQn_Type irq, uint8_t ipl, void * p_context)
{
    if (irq >= 0)
    {
        R_BSP_IrqCfgEnable(irq, ipl, p_context);
    }
}

/*******************************************************************************************************************//**
 * Disables and clears context for the requested IRQ.
 *
 * @param[in]  irq  IRQ to disable
 **********************************************************************************************************************/
static void r_tsu_b_irq_disable (IRQn_Type irq)
{
    if (irq >= 0)
    {
        R_BSP_IrqDisable(irq);
        R_FSP_IsrContextSet(irq, NULL);
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to ADC instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_tsu_b_call_callback (tsu_b_instance_ctrl_t * p_ctrl, adc_callback_args_t * p_args)
{
    adc_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    adc_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;
    if (NULL == p_args_memory)
    {
        /* Use provided args struct on stack */
        p_args_memory = p_args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args_memory;

        /* Copy the stacked args to callback memory */
        *p_args_memory = *p_args;
    }

    p_ctrl->p_callback(p_args_memory);

    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * This function implements interrupt handler for scan complete.
 **********************************************************************************************************************/
void tsu_b_scan_end_isr (void)
{
    TSU_B_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    adc_callback_args_t args;
    args.event = ADC_EVENT_SCAN_COMPLETE;

    /* Clear the interrupt cause flag.  */
    p_instance_ctrl->p_reg->SICR = R_TSU_B0_SICR_ADCLR_Msk;

    /* Dummy read the SICR bit. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->SICR);

    /* Check that the conversion complete status flag was completed. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->SISR, 0x00);

    /* Store the unit number into the callback argument */
    args.unit = p_instance_ctrl->p_cfg->unit;

    /* Populate the context field. */
    args.p_context = p_instance_ctrl->p_context;

    /* Initialize the channel to 0.  It is not used in this implementation. */
    args.channel = ADC_CHANNEL_0;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_tsu_b_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    TSU_B_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * This function implements interrupt handler for scan complete.
 **********************************************************************************************************************/
void tsu_b_compare_isr (void)
{
    TSU_B_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    adc_callback_args_t args;
    args.event = ADC_EVENT_WINDOW_COMPARE_A;

    /* Clear the interrupt cause flag.  */
    p_instance_ctrl->p_reg->SICR = R_TSU_B0_SICR_ADCLR_Msk | R_TSU_B0_SICR_CMPCLR_Msk;

    /* Dummy read the SICR bit. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->SICR);

    /* Check that the conversion complete status flag was completed. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->SISR, 0x00);

    /* Store the unit number into the callback argument */
    args.unit = p_instance_ctrl->p_cfg->unit;

    /* Populate the context field. */
    args.p_context = p_instance_ctrl->p_context;

    /* Initialize the channel to 0.  It is not used in this implementation. */
    args.channel = ADC_CHANNEL_0;

    /* If a callback was provided, call it with the argument */
    if (NULL != p_instance_ctrl->p_callback)
    {
        r_tsu_b_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    TSU_B_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
