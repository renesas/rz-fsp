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

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * adc_prv_ns_callback)(adc_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile adc_prv_ns_callback)(adc_callback_args_t * p_args);
#endif

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
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_TSU_B
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

    /* If a callback is used, then make sure an interrupt is enabled */
    tsu_b_extended_cfg_t const * p_extend = (tsu_b_extended_cfg_t const *) p_cfg->p_extend;
    if (NULL != p_cfg->p_callback)
    {
        FSP_ERROR_RETURN((p_cfg->scan_end_irq >= 0) || (p_extend->compare_irq >= 0), FSP_ERR_IRQ_BSP_DISABLED);
    }

    FSP_ASSERT(NULL != p_extend->p_reg);
#else
    tsu_b_extended_cfg_t const * p_extend = (tsu_b_extended_cfg_t const *) p_cfg->p_extend;
#endif

    /* Save configurations. */
    p_instance_ctrl->p_cfg = p_cfg;
#if BSP_FEATURE_TSU_B_CALIBRAION_DATA_CHECK_ENABLE

    /* Read calibration data. */
    uint32_t calibration_data1;
    uint32_t calibration_data2;
    R_BSP_TSU_B_Read_CalibrationData(p_instance_ctrl->p_cfg->unit, &calibration_data1, &calibration_data2);
    FSP_ERROR_RETURN(
        BSP_FEATURE_TSU_B_CALIBRAION_DATA_INVALID != calibration_data1 && BSP_FEATURE_TSU_B_CALIBRAION_DATA_INVALID != calibration_data2,
        FSP_ERR_INVALID_HW_CONDITION);
#endif
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Save register base address. */
    p_instance_ctrl->p_reg = p_extend->p_reg;

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
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
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

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if TSU_B_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    adc_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                      CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif

    p_ctrl->p_callback = callback_is_secure ? p_callback :
                         (void (*)(adc_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif

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
    FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->TSU_SSR, FSP_ERR_IN_USE);
#endif

    /* Start conversion. */
    if (ADC_TRIGGER_SOFTWARE == p_instance_ctrl->p_cfg->trigger)
    {
        p_instance_ctrl->p_reg->TSU_STRGR_b.ADST = 1U;
    }

#if BSP_FEATURE_TSU_B_ELC_TRIGGER_SUPPORTED
    else
    {
        p_instance_ctrl->p_reg->TSU_SOSR1_b.TRGE = 1U;
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
    p_status->state = (adc_state_t) p_instance_ctrl->p_reg->TSU_SSR_b.CONV;

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
    *p_data = (uint16_t) p_instance_ctrl->p_reg->TSU_SCRR;

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

    uint32_t calibration_data1;
    uint32_t calibration_data2;

#if TSU_B_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_adc_info);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_adc_info->length        = 1U;
    p_adc_info->p_address     = &p_instance_ctrl->p_reg->TSU_SCRR;
    p_adc_info->transfer_size = TRANSFER_SIZE_2_BYTE;

    /* Set calibration data. */
    R_BSP_TSU_B_Read_CalibrationData(p_instance_ctrl->p_cfg->unit, &calibration_data1, &calibration_data2);
    p_adc_info->calibration_data1 = calibration_data1;
    p_adc_info->calibration_data2 = calibration_data2;

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
        p_instance_ctrl->p_reg->TSU_SOSR1_b.TRGE = 0U;
#endif
    }
    else
    {
#if BSP_FEATURE_TSU_B_CONTINUOUS_MODE_SUPPORTED
        p_instance_ctrl->p_reg->TSU_STRGR_b.ADEND = 1U;
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
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) p_ctrl;
    uint32_t                calibration_data1;
    uint32_t                calibration_data2;

    /*  Perform parameter checking */
#if TSU_B_CFG_PARAM_CHECKING_ENABLE

    /* Verify the pointers are valid */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(TSU_B_OPEN == p_instance_ctrl->initialized, FSP_ERR_NOT_INITIALIZED);
#endif

    /* Read calibration data. */
    R_BSP_TSU_B_Read_CalibrationData(p_instance_ctrl->p_cfg->unit, &calibration_data1, &calibration_data2);

    /* Calculate the temperature. Reference section "Temperature Compensation Calculation" in the user's manual.
     * The calculation formula is as follows:
     * T(degrees Celsius) = ((e - d) / (c - b)) * (a - b) + d
     * The correspondence between the formula and the constants in the code is as follows:
     * a :temperature_code
     * b :calibration_data1(the value at low temperature)
     * c :calibration_data2(the value at high temperature)
     * d :BSP_FEATURE_TSU_B_LOW_TEMPERATURE(low temperature)
     * e :BSP_FEATURE_TSU_B_HIGH_TEMPERATURE(high temperature) */
    float term1;
    float term2;

    /* Calculate the term1. Reference section "Temperature Compensation Calculation" in the user's manual.*/
    term1 = (BSP_FEATURE_TSU_B_HIGH_TEMPERATURE - BSP_FEATURE_TSU_B_LOW_TEMPERATURE) /
            ((float) calibration_data2 - (float) calibration_data1);

    /* Calculate the term2. Reference section "Temperature Compensation Calculation" in the user's manual.*/
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
    p_instance_ctrl->p_reg->TSU_SICR = R_TSU_B0_SICR_ADCLR_Msk | R_TSU_B0_SICR_CMPCLR_Msk;
    volatile uint32_t dummy = p_instance_ctrl->p_reg->TSU_SICR;
    FSP_PARAMETER_NOT_USED(dummy);

    /* Confirm TSU_SISR = 0. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->TSU_SISR, 0U);

    /* Stop the TSU_B. */
    p_instance_ctrl->p_reg->TSU_SSUSR = R_TSU_B0_SSUSR_ADC_PD_TS_Msk;

    R_BSP_MODULE_STOP(FSP_IP_TSU, p_instance_ctrl->p_cfg->unit);

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
    uint32_t ssusr = (uint32_t) (0U << R_TSU_B0_SSUSR_ADC_PD_TS_Pos);
    ssusr |= (uint32_t) (R_TSU_B0_SSUSR_EN_TS_Msk | R_TSU_B0_SSUSR_SOC_TS_EN_Msk);

    /* Sets the average counts. */
    uint32_t sosr1 = (uint32_t) (R_TSU_B0_SOSR1_OUTSEL_Msk);
    sosr1 |= (uint32_t) (p_cfg_extend->average_count << R_TSU_B0_SOSR1_ADCT_Pos);

#if BSP_FEATURE_TSU_B_ELC_TRIGGER_SUPPORTED

    /* Sets the trigger. */
    sosr1 |= (uint32_t) (0U << R_TSU_B0_SOSR1_TRGE_Pos);
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
    R_BSP_MODULE_START(FSP_IP_TSU, p_instance_ctrl->p_cfg->unit);

    /* Set the predetermined values for SSUSR, SOSR1, CMSR, LLSR, ULSR, SIER.*/
    p_instance_ctrl->p_reg->TSU_SSUSR = ssusr;
    p_instance_ctrl->p_reg->TSU_SOSR1 = sosr1;
    p_instance_ctrl->p_reg->TSU_CMSR  = cmsr;
    p_instance_ctrl->p_reg->TSU_LLSR  = llsr;
    p_instance_ctrl->p_reg->TSU_ULSR  = ulsr;
    p_instance_ctrl->p_reg->TSU_SIER  = sier;

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
    uint32_t calibration_data1;
    uint32_t calibration_data2;

    /* Set calibration data. */
    R_BSP_TSU_B_Read_CalibrationData(p_instance_ctrl->p_cfg->unit, &calibration_data1, &calibration_data2);

    /* Calculate the comparison setting values. Reference section "Temperature Compensation Calculation" in the user's manual.
     * The calculation formula is as follows:
     * a = ((T - d) * (c - b)) / (e - d) + b
     * The correspondence between the formula and the constants in the code is as follows:
     * T : setting_temperature
     * b : calibration_data1(the value at low temperature)
     * c : calibration_data2(the value at high temperature)
     * d : BSP_FEATURE_TSU_B_LOW_TEMPERATURE(low temperature)
     * e : BSP_FEATURE_TSU_B_HIGH_TEMPERATURE(high temperature) */
    uint32_t calculate_value;
    float    term1;
    float    term2;
    float    term3;
    float    term4;

    /* Calculate the term1. Reference section "Comparison Setting Value Calculation" in the user's manual.*/
    term1 = (float) setting_temperature - BSP_FEATURE_TSU_B_LOW_TEMPERATURE;

    /* Calculate the term2. Reference section "Comparison Setting Value Calculation" in the user's manual.*/
    term2 = (float) calibration_data2 - (float) calibration_data1;

    /* Calculate the term3. Reference section "Comparison Setting Value Calculation" in the user's manual.*/
    term3 = BSP_FEATURE_TSU_B_HIGH_TEMPERATURE - BSP_FEATURE_TSU_B_LOW_TEMPERATURE;

    /* Calculate the term4. Reference section "Comparison Setting Value Calculation" in the user's manual.*/
    term4 = (term1 * term2) / term3;

    /* Calculate the setting value. Reference section "Comparison Setting Value Calculation" in the user's manual.*/
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

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args_memory);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        adc_prv_ns_callback p_callback = (adc_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args_memory);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_ctrl->p_callback(p_args_memory);
#endif

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
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear the BSP IRQ Flag     */
    R_BSP_IrqStatusClear(irq);

    adc_callback_args_t args;
    args.event = ADC_EVENT_SCAN_COMPLETE;

    /* Clear the interrupt cause flag.  */
    p_instance_ctrl->p_reg->TSU_SICR = R_TSU_B0_SICR_ADCLR_Msk;

    /* Dummy read the SICR bit. */
    volatile uint32_t dummy = p_instance_ctrl->p_reg->TSU_SICR;
    FSP_PARAMETER_NOT_USED(dummy);

    /* Check that the conversion complete status flag was completed. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->TSU_SISR, 0x00);

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
}

/*******************************************************************************************************************//**
 * This function implements interrupt handler for scan complete.
 **********************************************************************************************************************/
void tsu_b_compare_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    tsu_b_instance_ctrl_t * p_instance_ctrl = (tsu_b_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear the BSP IRQ Flag     */
    R_BSP_IrqStatusClear(irq);

    adc_callback_args_t args;
    args.event = ADC_EVENT_WINDOW_COMPARE_A;

    /* Clear the interrupt cause flag.  */
    p_instance_ctrl->p_reg->TSU_SICR = R_TSU_B0_SICR_ADCLR_Msk | R_TSU_B0_SICR_CMPCLR_Msk;

    /* Dummy read the SICR bit. */
    volatile uint32_t dummy = p_instance_ctrl->p_reg->TSU_SICR;
    FSP_PARAMETER_NOT_USED(dummy);

    /* Check that the conversion complete status flag was completed. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->TSU_SISR, 0x00);

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
}
