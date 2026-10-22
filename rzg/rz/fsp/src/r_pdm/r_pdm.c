/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_pdm.h"
#include "r_pdm_cfg.h"
#if PDM_CFG_DMAC_ENABLE
 #include "r_dmac_b.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define PDM_PRV_PDSCR_CLEAR_MASK            (R_PDM_PDSCRCH0_SDFC_Msk | R_PDM_PDSCRCH0_SCDFC_Msk |    \
                                             R_PDM_PDSCRCH0_OVLDFC_Msk | R_PDM_PDSCRCH0_OVUDFC_Msk | \
                                             R_PDM_PDSCRCH0_BFOWDFC_Msk)
#define PDM_PRV_PDSR_ERROR_MASK             (R_PDM_PDSRCH0_SCDF_Msk | R_PDM_PDSRCH0_OVLDF_Msk | \
                                             R_PDM_PDSRCH0_OVUDF_Msk |                          \
                                             R_PDM_PDSRCH0_BFOWDF_Msk)

#define PDM_PRV_FIFO_SAMPLE_SIZE            sizeof(uint32_t)
#define PDM_PRV_FIFO_DEPTH                  32
#define PDM_PRV_FIFO_INITIAL_READ_LENGTH    (PDM_PRV_FIFO_DEPTH - 2)

/* PDM macro functions */
#define PDM_PRV_CHANNEL_OFFSET              (uintptr_t) (&(R_PDM0->PDMDSRCH1) - &(R_PDM0->PDMDSRCH0))
#define PDM_REG_CH(a, b)    *(&(a) + (PDM_PRV_CHANNEL_OFFSET * (b)))

/* "PDM" in ASCII, used to determine if driver is open. */
#define PDM_PRV_OPEN                        (0x50444DU)

#define PDM_PRV_LOOP_MAX                    (1000)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * pdm_prv_ns_callback)(pdm_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile pdm_prv_ns_callback)(pdm_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/* ISRs */
void pdm_sdet_isr(void);
void pdm_dat_isr(void);
void pdm_err_isr(void);

static void r_pdm_call_callback(pdm_instance_ctrl_t * p_ctrl, pdm_event_t event, pdm_error_t error);

/* FIFO subroutines */
static uint32_t r_pdm_fifo_read(pdm_instance_ctrl_t * p_instance_ctrl);

#if PDM_CFG_DMAC_ENABLE
static fsp_err_t r_pdm_dependent_drivers_configure(pdm_instance_ctrl_t * p_instance_ctrl);
void             pdm_rxi_dmac_isr(dmac_b_callback_args_t * args);

#endif

/* Subroutines */
static void r_pdm_stop_sub(pdm_instance_ctrl_t * const p_instance_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
#if PDM_CFG_DMAC_ENABLE

/* PDM DMA Activation source */
static const dmac_trigger_event_t volatile p_pdm_activation_source[] =
{
    (dmac_trigger_event_t) DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT0,
 #if BSP_FEATURE_PDM_CHANNELS_PER_UNIT > 1
    (dmac_trigger_event_t) DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT1,
  #if BSP_FEATURE_PDM_CHANNELS_PER_UNIT > 2
    (dmac_trigger_event_t) DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT2,
  #endif
 #endif

 #if BSP_FEATURE_PDM_UNITS > 1
    (dmac_trigger_event_t) DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT0,
  #if BSP_FEATURE_PDM_CHANNELS_PER_UNIT > 1
    (dmac_trigger_event_t) DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT1,
   #if BSP_FEATURE_PDM_CHANNELS_PER_UNIT > 2
    (dmac_trigger_event_t) DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT2,
   #endif
  #endif
 #endif
};
#endif

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** PDM Implementation of PDM interface.  */
const pdm_api_t g_pdm_on_pdm =
{
    .open                  = R_PDM_Open,
    .start                 = R_PDM_Start,
    .stop                  = R_PDM_Stop,
    .soundDetectionEnable  = R_PDM_SoundDetectionEnable,
    .soundDetectionDisable = R_PDM_SoundDetectionDisable,
    .read                  = R_PDM_Read,
    .statusGet             = R_PDM_StatusGet,
    .close                 = R_PDM_Close,
    .callbackSet           = R_PDM_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_PDM
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Opens the PDM. Implements @ref pdm_api_t::open.
 *
 * This function sets this clock divisor and the configurations specified in pdm_cfg_t.
 *
 * @retval FSP_SUCCESS                     Ready for PDM communication.
 * @retval FSP_ERR_ASSERTION               The pointer to p_ctrl or p_cfg is null.
 * @retval FSP_ERR_ALREADY_OPEN            The control block has already been opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Channel number is not available on this device.
 * @return                                 See @ref RZG_RENESAS_ERROR_CODES or functions called by this function for other
 *                                         possible return codes.
 **********************************************************************************************************************/
fsp_err_t R_PDM_Open (pdm_ctrl_t * const p_ctrl, pdm_cfg_t const * const p_cfg)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;
#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(BSP_FEATURE_PDM_CHANNELS_PER_UNIT > p_cfg->channel, FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(BSP_FEATURE_PDM_UNITS > p_cfg->unit, FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    pdm_extended_cfg_t * p_extend = (pdm_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(NULL != p_extend);
    FSP_ASSERT(NULL != p_extend->p_reg);

 #if PDM_CFG_DMAC_ENABLE
    if (NULL != p_cfg->p_transfer_rx)
    {
        dmac_trigger_event_t trigger =
            p_pdm_activation_source[p_cfg->unit * BSP_FEATURE_PDM_CHANNELS_PER_UNIT + p_cfg->channel];
        dmac_b_extended_cfg_t * p_dmac_rx_cfg = (dmac_b_extended_cfg_t *) p_cfg->p_transfer_rx->p_cfg->p_extend;
        FSP_ASSERT(NULL != p_dmac_rx_cfg);
        FSP_ASSERT(trigger == p_dmac_rx_cfg->activation_source);
    }
 #endif

    FSP_ERROR_RETURN(PDM_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#else
    pdm_extended_cfg_t * p_extend = (pdm_extended_cfg_t *) p_cfg->p_extend;
#endif

    /* Set the base address for specified channel. */
    R_PDM0_Type * p_reg = (R_PDM0_Type *) p_extend->p_reg;

    /* Enable PDM module */
    R_BSP_MODULE_START(FSP_IP_PDM, p_cfg->unit);

    /* Initialize PDM IP according to "PDM-IF Start Flow"
     * in the PDM-IF section of the relevant hardware manual. */

    /* Set Channel's Mode setting */
    PDM_REG_CH(p_reg->PDMDSRCH0, p_cfg->channel) =
        (uint32_t) (p_cfg->pcm_width << R_PDM_PDMDSRCH0_DBIS_Pos) |
        (uint32_t) (p_extend->moving_average_mode << R_PDM_PDMDSRCH0_SDMAMD_Pos) |
        (uint32_t) (p_extend->low_pass_filter_shift << R_PDM_PDMDSRCH0_LFIS_Pos) |
        (uint32_t) (p_extend->compensation_filter_shift << R_PDM_PDMDSRCH0_CFIS_Pos) |
        (uint32_t) (p_extend->high_pass_filter_shift << R_PDM_PDMDSRCH0_HFIS_Pos) |
        (uint32_t) (p_extend->sinc_filter_mode << R_PDM_PDMDSRCH0_SFMD_Pos) |
        (uint32_t) (p_cfg->pcm_edge << R_PDM_PDMDSRCH0_INPSEL_Pos);

    /* Set Channel's Digital Filter Configuration */
    PDM_REG_CH(p_reg->PDSFCRCH0, p_cfg->channel) =
        (uint32_t) (p_extend->sincrng << R_PDM_PDSFCRCH0_SINCRNG_Pos) |
        (uint32_t) (p_extend->sincdec << R_PDM_PDSFCRCH0_SINCDEC_Pos) |
        (uint32_t) (p_extend->clock_div << R_PDM_PDSFCRCH0_CKDIV_Pos);

    /* Set high pass filter coefficients */
    PDM_REG_CH(p_reg->PDHFCS0RCH0, p_cfg->channel) = (uint32_t) p_extend->hpf_coefficient_s0;
    PDM_REG_CH(p_reg->PDHFCK1RCH0, p_cfg->channel) = (uint32_t) p_extend->hpf_coefficient_k1;
    volatile uint32_t * p_hpf_reg  = &(p_reg->PDHFCH0RCH0);
    uintptr_t           hpf_offset = (uintptr_t) (&(p_reg->PDHFCH1RCH0) - &(p_reg->PDHFCH0RCH0));
    p_hpf_reg += p_cfg->channel * PDM_PRV_CHANNEL_OFFSET;

    for (uint32_t i = 0; i < PDM_NUM_HPF_COEFFICIENT_H; i++)
    {
        *(p_hpf_reg + hpf_offset * i) = (uint32_t) p_extend->hpf_coefficient_h[i];
    }

    /* Set compensation filter coefficients */
    volatile uint32_t * p_comp_reg  = &(p_reg->PDCFCH00RCH0);
    uintptr_t           comp_offset = (uintptr_t) (&(p_reg->PDCFCH01RCH0) - &(p_reg->PDCFCH00RCH0));
    p_comp_reg += p_cfg->channel * PDM_PRV_CHANNEL_OFFSET;

    for (uint32_t i = 0; i < PDM_NUM_COMPENSATION_FILTER_COEFFICIENT_H; i++)
    {
        *(p_comp_reg + comp_offset * i) = (uint32_t) p_extend->compensation_filter_coefficient_h[i];
    }

    /* Set low pass filter coefficients */
    PDM_REG_CH(p_reg->PDLFCH010RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h0;

    volatile uint32_t * p_lpf_reg  = &(p_reg->PDLFCH100RCH0);
    uintptr_t           lpf_offset = (uintptr_t) (&(p_reg->PDLFCH101RCH0) - &(p_reg->PDLFCH100RCH0));
    p_lpf_reg += p_cfg->channel * PDM_PRV_CHANNEL_OFFSET;

    for (uint32_t i = 0; i < PDM_NUM_LPF_FILTER_COEFFICIENT_H1; i++)
    {
        *(p_lpf_reg + lpf_offset * i) = (uint32_t) p_extend->lpf_coefficient_h1[i];
    }

    /* Set Channel's Data Buffer Control */
#if PDM_CFG_DMAC_ENABLE
    PDM_REG_CH(p_reg->PDDBCRCH0, p_cfg->channel) = PDM_INTERRUPT_THRESHOLD_1;
#else
    PDM_REG_CH(p_reg->PDDBCRCH0, p_cfg->channel) = (uint32_t) p_extend->interrupt_threshold;
#endif

    /* Set Channel's Error Detection Control */
    PDM_REG_CH(p_reg->PDSCTSRCH0, p_cfg->channel) =
        (uint32_t) (p_extend->short_circuit_count_h << R_PDM_PDSCTSRCH0_SCDH_Pos) |
        (uint32_t) (p_extend->short_circuit_count_l << R_PDM_PDSCTSRCH0_SCDL_Pos);
    PDM_REG_CH(p_reg->PDOVLTRCH0, p_cfg->channel) = p_extend->overvoltage_detection_lower_limit;
    PDM_REG_CH(p_reg->PDOVUTRCH0, p_cfg->channel) = p_extend->overvoltage_detection_upper_limit;

    /* Activate target channel's filtering */
    p_reg->PDCSTRTR |= (uint32_t) (1UL << p_cfg->channel);

    /* Wait for settling time */
#if (BSP_CFG_RTOS == 2)
    vTaskDelay(p_extend->filter_setting_time * BSP_DELAY_UNITS_MILLISECONDS);
#else
    bsp_prv_software_delay_loop(p_extend->filter_setting_time * 2);
#endif

    /* Clear Channel's Status */
    PDM_REG_CH(p_reg->PDSCRCH0, p_cfg->channel) = PDM_PRV_PDSCR_CLEAR_MASK;

    /* Set Channel's Status Detection Control (for Error Detection) */
    PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) =
        (uint32_t) (p_extend->short_circuit_detection_enable) |
        (uint32_t) (p_extend->over_voltage_lower_limit_detection_enable) |
        (uint32_t) (p_extend->over_voltage_upper_limit_detection_enable) |
        (uint32_t) (p_extend->buffer_overwrite_detection_enable);

    /* Initialize the control structure. */
    p_instance_ctrl->p_reg = p_reg;
    p_instance_ctrl->p_cfg = p_cfg;

    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Initialization complete. */
    p_instance_ctrl->open = PDM_PRV_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Starts PDM. Implements @ref pdm_api_t::start.
 *
 * This function enables reception, and enables any transfer instances used.
 *
 * The PDM will start on the next frame boundary.
 *
 * @retval FSP_SUCCESS               PDM communication stop request issued.
 * @retval FSP_ERR_ASSERTION         The pointer to p_ctrl was null.
 * @retval FSP_ERR_INVALID_SIZE      The size of buffer is not a multiple of pdm_interrupt_threshold_t.
 * @retval FSP_ERR_INVALID_ALIGNMENT The alignment of argument buffer_size is not matched with hardware specification.
 * @retval FSP_ERR_NOT_OPEN          The channel is not opened.
 * @return                       See @ref RZG_RENESAS_ERROR_CODES or lower level drivers for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t R_PDM_Start (pdm_ctrl_t * const p_ctrl,
                       void * const       p_buffer,
                       size_t const       buffer_size,
                       uint32_t const     number_of_data_to_callback)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NULL != p_buffer, FSP_ERR_ASSERTION);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(buffer_size > 0U);
    FSP_ASSERT(number_of_data_to_callback > 0U);
#endif
    pdm_extended_cfg_t * p_extend = (pdm_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_extend);
#endif

    R_PDM0_Type           * p_reg                = p_instance_ctrl->p_reg;
    pdm_cfg_t const * const p_cfg                = p_instance_ctrl->p_cfg;
    uint32_t                stages_per_interrupt = 1U << p_extend->interrupt_threshold;

    /* Verify that the buffer is aligned to 4 bytes. */
    FSP_ERROR_RETURN((0 == ((uint32_t) p_buffer & 0x03U)), FSP_ERR_INVALID_ALIGNMENT);

    /* Verify that number_of_data_to_callback is a multiple of configured interrupt threshold which determines the
     * number of stages per interrupt */
    FSP_ERROR_RETURN((0 == (number_of_data_to_callback % stages_per_interrupt)), FSP_ERR_INVALID_SIZE);

    /* Verify that buffer size is a multiple of 4 bytes */
    FSP_ERROR_RETURN((0 == buffer_size % PDM_PRV_FIFO_SAMPLE_SIZE), FSP_ERR_INVALID_SIZE);

    /* Verify that number of samples in buffer is a multiple of the number of data to callback */
    uint32_t number_of_samples_in_buffer = buffer_size / PDM_PRV_FIFO_SAMPLE_SIZE;
    FSP_ERROR_RETURN((0 == (number_of_samples_in_buffer % number_of_data_to_callback)), FSP_ERR_INVALID_SIZE);

    p_instance_ctrl->p_rx_dest        = p_buffer;
    p_instance_ctrl->p_rx_fifo        = p_buffer;
    p_instance_ctrl->rx_dest_samples  = number_of_samples_in_buffer;
    p_instance_ctrl->rx_int_count     = 0;
    p_instance_ctrl->rx_int_count_max = number_of_data_to_callback;

    /* Start communication according to "PDM-IF normal processing flow" in
     * "Normal Processing Flow" of the relevant hardware manual. */

    /* Set Channel's Data Read Enable */
    PDM_REG_CH(p_reg->PDDRCRCH0, p_cfg->channel) = R_PDM_PDDRCRCH0_DATRE_Msk;

    /* Read PDMm_PDDRRCHn x (P_FD - 2) before starting interrupts/DMA
     * P_FD: FIFO Depth
     * Note: this data discarded and not stored anywhere
     */
    for (int i = 0; i < PDM_PRV_FIFO_INITIAL_READ_LENGTH; i++)
    {
        FSP_REGISTER_READ((void *) &PDM_REG_CH(p_reg->PDDRRCH0, p_cfg->channel));
    }

#if PDM_CFG_DMAC_ENABLE

    /* Configure dependent timer and transfer drivers. */
    fsp_err_t err = r_pdm_dependent_drivers_configure(p_instance_ctrl);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);
#endif

    /* Enable error interrupt if allocated and not already enabled */
    if ((p_cfg->err_irq >= 0) && (0 == (PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) & R_PDM_PDICRCH0_IEDE_Msk)))
    {
        PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) |= R_PDM_PDICRCH0_IEDE_Msk;
        R_BSP_IrqCfgEnable(p_cfg->err_irq, p_cfg->err_ipl, p_instance_ctrl);
    }

    /* Enable data interrupt */
    PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) |= R_PDM_PDICRCH0_IDRE_Msk;

    if (p_cfg->dat_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->dat_irq, p_cfg->dat_ipl, p_instance_ctrl);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops PDM. Implements @ref pdm_api_t::stop.
 *
 * This function disables reception, and disables any transfer instances used.
 *
 * The PDM will stop on the next frame boundary.
 *
 * @retval FSP_SUCCESS           PDM communication stop request issued.
 * @retval FSP_ERR_ASSERTION     The pointer to p_ctrl was null.
 * @retval FSP_ERR_NOT_OPEN      The channel is not opened.
 * @return                       See @ref RZG_RENESAS_ERROR_CODES or lower level drivers for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t R_PDM_Stop (pdm_ctrl_t * const p_ctrl)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_pdm_stop_sub(p_instance_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures and enables sound detection. Implements @ref pdm_api_t::soundDetectionEnable.
 *
 * This function configures sound detection based on the passed in settings. It then enables sound detection.
 *
 * @retval FSP_SUCCESS           Sound detection configured and enabled.
 * @retval FSP_ERR_ASSERTION     The pointer to p_ctrl was null.
 * @retval FSP_ERR_NOT_OPEN      The channel is not opened.
 * @return                       See @ref RZG_RENESAS_ERROR_CODES or lower level drivers for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t R_PDM_SoundDetectionEnable (pdm_ctrl_t * const p_ctrl, pdm_sound_detection_setting_t sound_detection_setting)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    pdm_cfg_t const * const p_cfg = p_instance_ctrl->p_cfg;
    R_PDM0_Type           * p_reg = p_instance_ctrl->p_reg;

    /* Enable error interrupt if allocated and not already enabled */
    if ((p_cfg->err_irq >= 0) && (0 == (PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) & R_PDM_PDICRCH0_IEDE_Msk)))
    {
        PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) |= R_PDM_PDICRCH0_IEDE_Msk;
        R_BSP_IrqCfgEnable(p_cfg->err_irq, p_cfg->err_ipl, p_instance_ctrl);
    }

    /* Clear sound detection status */
    PDM_REG_CH(p_reg->PDSCRCH0, p_cfg->channel) |= R_PDM_PDSCRCH0_SDFC_Msk;

    /* Set Channel's Sound Detection Control */
    PDM_REG_CH(p_reg->PDSDLTRCH0, p_cfg->channel) = sound_detection_setting.sound_detection_lower_limit;
    PDM_REG_CH(p_reg->PDSDUTRCH0, p_cfg->channel) = sound_detection_setting.sound_detection_upper_limit;

    /* Set sound detection enable */
    PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) |= R_PDM_PDSDCRCH0_SDE_Msk;

    /* Enable sound detection interrupt if used */
    if (p_cfg->sdet_irq >= 0)
    {
        PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) |= R_PDM_PDICRCH0_ISDE_Msk;
        R_BSP_IrqCfgEnable(p_cfg->sdet_irq, p_cfg->sdet_ipl, p_instance_ctrl);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Disables sound detection. Implements @ref pdm_api_t::soundDetectionDisable.
 *
 * This function disables sound detection.
 *
 * @retval FSP_SUCCESS           Sound detection disabled.
 * @retval FSP_ERR_ASSERTION     The pointer to p_ctrl was null.
 * @retval FSP_ERR_NOT_OPEN      The channel is not opened.
 * @return                       See @ref RZG_RENESAS_ERROR_CODES or lower level drivers for other possible return codes.
 **********************************************************************************************************************/
fsp_err_t R_PDM_SoundDetectionDisable (pdm_ctrl_t * const p_ctrl)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    pdm_cfg_t const * const p_cfg = p_instance_ctrl->p_cfg;
    R_PDM0_Type           * p_reg = p_instance_ctrl->p_reg;

    /* Clear sound detection enable */
    PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) &= ~R_PDM_PDSDCRCH0_SDE_Msk;

    /* Disable sound detection interrupt if used */
    if (p_cfg->sdet_irq >= 0)
    {
        PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) &= ~R_PDM_PDICRCH0_ISDE_Msk;
    }

    /* Clear sound detection status */
    PDM_REG_CH(p_reg->PDSCRCH0, p_cfg->channel) |= R_PDM_PDSCRCH0_SDFC_Msk;

    /* Disable error interrupt if allocated and if data read isn't enabled */
    if ((p_cfg->err_irq >= 0) && (0 == PDM_REG_CH(p_reg->PDDRCRCH0, p_cfg->channel)))
    {
        PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) &= ~R_PDM_PDICRCH0_IEDE_Msk;
        R_BSP_IrqDisable(p_cfg->err_irq);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * This function is not supported. Implements @ref pdm_api_t::read.
 *
 * @retval FSP_ERR_UNSUPPORTED                 This function is not supported.
 **********************************************************************************************************************/
fsp_err_t R_PDM_Read (pdm_ctrl_t * const p_ctrl, void * const p_dest, uint32_t const bytes)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(bytes);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Gets PDM status and stores it in provided pointer p_status. Implements @ref pdm_api_t::statusGet.
 *
 * @retval FSP_SUCCESS           Information stored successfully.
 * @retval FSP_ERR_ASSERTION     The p_ctrl or p_status parameter was null.
 * @retval FSP_ERR_NOT_OPEN      The channel is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PDM_StatusGet (pdm_ctrl_t * const p_ctrl, pdm_status_t * const p_status)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE

    /* Make sure parameters are valid. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    R_PDM0_Type           * p_reg = p_instance_ctrl->p_reg;
    pdm_cfg_t const * const p_cfg = p_instance_ctrl->p_cfg;

    /* Set state based on if data read is enabled */
    p_status->state = PDM_REG_CH(p_reg->PDDRCRCH0, p_cfg->channel) ? PDM_STATE_IN_USE : PDM_STATE_STOPPED;

    /* Set sound detection state */
    p_status->sound_detection_enabled = (0 != (PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) & R_PDM_PDICRCH0_ISDE_Msk));

    /* Get status, mask out non-error statuses */
    uint32_t pdsr = PDM_REG_CH(p_reg->PDSRCH0, p_cfg->channel) & PDM_PRV_PDSR_ERROR_MASK;

    /* Set errors, shift so that error statuses match the error enum*/
    p_status->error = (pdm_error_t) (pdsr >> R_PDM_PDSCRCH0_SCDFC_Pos);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Closes PDM. Implements @ref pdm_api_t::close.
 *
 * This function powers down the PDM and closes the lower level timer and transfer drivers if they are used.
 *
 * @retval FSP_SUCCESS           Device closed successfully.
 * @retval FSP_ERR_ASSERTION     The pointer to p_ctrl was null.
 * @retval FSP_ERR_NOT_OPEN      The channel is not opened.
 **********************************************************************************************************************/
fsp_err_t R_PDM_Close (pdm_ctrl_t * const p_ctrl)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    pdm_cfg_t const * const p_cfg = p_instance_ctrl->p_cfg;
    R_PDM0_Type           * p_reg = p_instance_ctrl->p_reg;

    r_pdm_stop_sub(p_instance_ctrl);

    /* Stop PDM according to "PDM-IF Stop Flow" in
     * "Stop Flow" of the relevant hardware manual. */

    /* Stop target channel's filtering */
    PDM_REG_CH(p_reg->PDSTPTRCH0, p_cfg->channel) = R_PDM_PDSTPTRCH0_STPTRG_Msk;

    /* Target channel is stopped? */
    for (uint32_t loop = 0; loop < PDM_PRV_LOOP_MAX; loop++)
    {
        if (!(PDM_REG_CH(p_reg->PDSRCH0, p_cfg->channel) & R_PDM_PDSRCH0_STATE_Msk))
        {
            break;
        }
    }

    /* Disable Channel's Interrupt */
    PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) &= ~(R_PDM_PDICRCH0_ISDE_Msk | R_PDM_PDICRCH0_IEDE_Msk);

    /* Disable Channel's Status Detection */
    PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) = 0;

    /* Clear Channel's Status */
    PDM_REG_CH(p_reg->PDSCRCH0, p_cfg->channel) = PDM_PRV_PDSCR_CLEAR_MASK;

    p_instance_ctrl->open = 0U;

    /* Disable interrupts. */
    if (p_cfg->dat_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->dat_irq);
    }

    if (p_cfg->sdet_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->sdet_irq);
    }

    if (p_cfg->err_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->err_irq);
    }

#if PDM_CFG_DMAC_ENABLE

    /* If transfer is used, disable transfer when stop is requested. */
    if (NULL != p_instance_ctrl->p_cfg->p_transfer_rx)
    {
        (void) p_instance_ctrl->p_cfg->p_transfer_rx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl);
    }
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements pdm_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_PDM_CallbackSet (pdm_ctrl_t * const          p_ctrl,
                             void (                    * p_callback)(pdm_callback_args_t *),
                             void * const                p_context,
                             pdm_callback_args_t * const p_callback_memory)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if (PDM_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if PDM_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    pdm_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                      CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD
    p_instance_ctrl->p_callback = callback_is_secure ? p_callback :
                                  (void (*)(pdm_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_instance_ctrl->p_callback = p_callback;
#endif
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup R_PDM)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

#if PDM_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Configures any dependent drivers selected by the user, including transfer and timer drivers.
 *
 * @param[in] p_instance_ctrl               Pointer to the p_instance_ctrl structure.
 *
 * @retval FSP_SUCCESS                 Dependent drivers configured successfully.
 * @return                             See @ref RZG_RENESAS_ERROR_CODES or functions called by this function for other
 *                                     possible return codes. This function calls:
 *                                         * @ref transfer_api_t::open
 **********************************************************************************************************************/
static fsp_err_t r_pdm_dependent_drivers_configure (pdm_instance_ctrl_t * p_instance_ctrl)
{
    /* Prepare transfer configuration. */
    fsp_err_t               err_transfer_rx = FSP_SUCCESS;
    pdm_cfg_t const * const p_cfg           = p_instance_ctrl->p_cfg;
    R_PDM0_Type           * p_reg           = p_instance_ctrl->p_reg;
    dmac_b_extended_cfg_t * p_dmac_extend   = (dmac_b_extended_cfg_t *) p_cfg->p_transfer_rx->p_cfg->p_extend;

    /* If a transfer instance is provided for read, open the transfer instance. */
    if (NULL != p_cfg->p_transfer_rx)
    {
        uint32_t * p_data_end = p_instance_ctrl->p_rx_dest;
        p_data_end += p_instance_ctrl->rx_dest_samples;

        p_cfg->p_transfer_rx->p_cfg->p_info->p_src     = (void *) &PDM_REG_CH(p_reg->PDDRRCH0, p_cfg->channel);
        p_cfg->p_transfer_rx->p_cfg->p_info->p_dest    = p_instance_ctrl->p_rx_dest;
        p_cfg->p_transfer_rx->p_cfg->p_info->src_size  = TRANSFER_SIZE_4_BYTE;
        p_cfg->p_transfer_rx->p_cfg->p_info->dest_size = TRANSFER_SIZE_4_BYTE;
        p_cfg->p_transfer_rx->p_cfg->p_info->length    = p_instance_ctrl->rx_int_count_max * sizeof(uint32_t);
        p_instance_ctrl->p_rx_fifo =
            (void *) ((uint32_t *) p_instance_ctrl->p_rx_fifo + p_instance_ctrl->rx_int_count_max);

        if (p_instance_ctrl->p_rx_fifo >= (void *) p_data_end)
        {
            p_instance_ctrl->p_rx_fifo = p_instance_ctrl->p_rx_dest;
        }

        p_cfg->p_transfer_rx->p_cfg->p_info->p_next1_src  = (void *) &PDM_REG_CH(p_reg->PDDRRCH0, p_cfg->channel);
        p_cfg->p_transfer_rx->p_cfg->p_info->p_next1_dest = p_instance_ctrl->p_rx_fifo;
        p_cfg->p_transfer_rx->p_cfg->p_info->next1_length = p_instance_ctrl->rx_int_count_max * sizeof(uint32_t);
        p_instance_ctrl->p_rx_fifo =
            (void *) ((uint32_t *) p_instance_ctrl->p_rx_fifo + p_instance_ctrl->rx_int_count_max);

        if (p_instance_ctrl->p_rx_fifo >= (void *) p_data_end)
        {
            p_instance_ctrl->p_rx_fifo = p_instance_ctrl->p_rx_dest;
        }

        p_dmac_extend->ack_mode = DMAC_B_ACK_MODE_BUS_CYCLE_MODE;
        p_dmac_extend->activation_request_source_select = DMAC_B_REQUEST_DIRECTION_SOURCE_MODULE;

        err_transfer_rx = p_cfg->p_transfer_rx->p_api->open(p_cfg->p_transfer_rx->p_ctrl, p_cfg->p_transfer_rx->p_cfg);
 #if  PDM_CFG_PARAM_CHECKING_ENABLE
        FSP_ERROR_RETURN((FSP_SUCCESS == err_transfer_rx), err_transfer_rx);
 #else
        FSP_PARAMETER_NOT_USED(err_transfer_rx);
 #endif
        err_transfer_rx = p_cfg->p_transfer_rx->p_api->enable(p_cfg->p_transfer_rx->p_ctrl);
 #if  PDM_CFG_PARAM_CHECKING_ENABLE
        FSP_ERROR_RETURN((FSP_SUCCESS == err_transfer_rx), err_transfer_rx);
 #else
        FSP_PARAMETER_NOT_USED(err_transfer_rx);
 #endif
    }

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Disables PDM reception.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 **********************************************************************************************************************/
static void r_pdm_stop_sub (pdm_instance_ctrl_t * const p_instance_ctrl)
{
    /* Stop communication according to "PDM-IF normal processing flow" in
     * "Normal Processing Flow" of the relevant hardware manual. */
    R_PDM0_Type           * p_reg = p_instance_ctrl->p_reg;
    pdm_cfg_t const * const p_cfg = p_instance_ctrl->p_cfg;

    /* Only stop if data read is currently enabled */
    if (PDM_REG_CH(p_reg->PDDRCRCH0, p_cfg->channel))
    {
        /* Disable channel data interrupt. */
        PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) &= ~R_PDM_PDICRCH0_IDRE_Msk;

        /* Disable Channel's Data Read. */
        PDM_REG_CH(p_reg->PDDRCRCH0, p_cfg->channel) = 0;

#if PDM_CFG_DMAC_ENABLE

        /* If transfer is used, close transfer when stop is requested. */
        if (NULL != p_instance_ctrl->p_cfg->p_transfer_rx)
        {
            (void) p_instance_ctrl->p_cfg->p_transfer_rx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        }
#endif

        /* Disable error interrupt if allocated and if sound detection isn't enabled */
        if ((p_cfg->err_irq >= 0) && (0 == (PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) & R_PDM_PDSDCRCH0_SDE_Msk)))
        {
            PDM_REG_CH(p_reg->PDICRCH0, p_cfg->channel) &= ~R_PDM_PDICRCH0_IEDE_Msk;
            R_BSP_IrqDisable(p_cfg->err_irq);
        }
    }
}

/*******************************************************************************************************************//**
 *  Reads data from FIFO.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 * @return                             The number of received data.
 **********************************************************************************************************************/
static uint32_t r_pdm_fifo_read (pdm_instance_ctrl_t * p_instance_ctrl)
{
    /* Calculate the number of available bytes of data in receive FIFO. */
    uint32_t count;

    uint32_t * p_data_end = p_instance_ctrl->p_rx_dest;
    p_data_end += p_instance_ctrl->rx_dest_samples;
    uint32_t * p_data      = p_instance_ctrl->p_rx_fifo;
    uint32_t   fifo_number = PDM_REG_CH(p_instance_ctrl->p_reg->PDDSRCH0, p_instance_ctrl->p_cfg->channel);
    for (count = 0; count < fifo_number; count++)
    {
        *p_data++ = PDM_REG_CH(p_instance_ctrl->p_reg->PDDRRCH0, p_instance_ctrl->p_cfg->channel);
        if (p_data >= p_data_end)
        {
            p_data = p_instance_ctrl->p_rx_dest;
            count++;
            break;
        }
    }

    p_instance_ctrl->p_rx_fifo = p_data;

    return count;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to PDM instance control block
 * @param[in]     event      Event code
 * @param[in]     error      Error code
 **********************************************************************************************************************/
static void r_pdm_call_callback (pdm_instance_ctrl_t * p_ctrl, pdm_event_t event, pdm_error_t error)
{
    pdm_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    pdm_callback_args_t * p_args = p_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->event     = event;
    p_args->p_context = p_ctrl->p_context;
    p_args->error     = error;

#if BSP_TZ_SECURE_BUILD

    /* p_callback can point to a secure function or a non-secure function. */
    if (!cmse_is_nsfptr(p_ctrl->p_callback))
    {
        /* If p_callback is secure, then the project does not need to change security state. */
        p_ctrl->p_callback(p_args);
    }
    else
    {
        /* If p_callback is Non-secure, then the project must change to Non-secure state in order to call the callback. */
        pdm_prv_ns_callback p_callback = (pdm_prv_ns_callback) (p_ctrl->p_callback);
        p_callback(p_args);
    }

#else

    /* If the project is not Trustzone Secure, then it will never need to change security state in order to call the callback. */
    p_ctrl->p_callback(p_args);
#endif
    if (NULL != p_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Sound detection ISR. Calls callback and disables Sound detection interrupt.
 **********************************************************************************************************************/
void pdm_sdet_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type             irq             = R_FSP_CurrentIrqGet();
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Disable Sound detection */
    PDM_REG_CH(p_instance_ctrl->p_reg->PDSDCRCH0, p_instance_ctrl->p_cfg->channel) &= ~R_PDM_PDSDCRCH0_SDE_Msk;

    /* Clear Sound detection flag */
    PDM_REG_CH(p_instance_ctrl->p_reg->PDSCRCH0, p_instance_ctrl->p_cfg->channel) = R_PDM_PDSCRCH0_SDFC_Msk;

    /* Call callback if provided with sound detection event */
    if (p_instance_ctrl->p_callback)
    {
        r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_SOUND_DETECTION, PDM_ERROR_NONE);
    }

    /* Clear the IR flag in the ICU */
    R_BSP_IrqStatusClear(irq);

    /* Enable Sound detection */
    PDM_REG_CH(p_instance_ctrl->p_reg->PDSDCRCH0, p_instance_ctrl->p_cfg->channel) |= R_PDM_PDSDCRCH0_SDE_Msk;

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Receive ISR.  Calls callback when reception is complete.  Empties FIFO if transfer interface is not used.
 **********************************************************************************************************************/
void pdm_dat_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type             irq             = R_FSP_CurrentIrqGet();
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    /* Clear the IR flag in the ICU */
    R_BSP_IrqStatusClear(irq);

    if (NULL != p_instance_ctrl->p_rx_dest)
    {
        uint32_t received;

        /* If transfer is not used, read data into the destination buffer. */
        received = r_pdm_fifo_read(p_instance_ctrl);
        p_instance_ctrl->rx_int_count += received;
        while (p_instance_ctrl->rx_int_count >= p_instance_ctrl->rx_int_count_max)
        {
            p_instance_ctrl->rx_int_count -= p_instance_ctrl->rx_int_count_max;
            if (p_instance_ctrl->p_callback)
            {
                r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_DATA, PDM_ERROR_NONE);
            }
        }
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Error ISR.
 *
 * Handles errors and calls callback.
 **********************************************************************************************************************/
void pdm_err_isr (void)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    IRQn_Type             irq             = R_FSP_CurrentIrqGet();
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    pdm_error_t error = PDM_ERROR_NONE;

    /* Get status, mask out non-error statuses */
    uint32_t pdsr =
        PDM_REG_CH(p_instance_ctrl->p_reg->PDSRCH0, p_instance_ctrl->p_cfg->channel) & PDM_PRV_PDSR_ERROR_MASK;

    /* Set error for callback, shift so that error statuses match the error enum*/
    error = (pdm_error_t) (pdsr >> R_PDM_PDSCRCH0_SCDFC_Pos);

    if (p_instance_ctrl->p_callback)
    {
        /* Call callback if provided. */
        r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_ERROR, error);
    }

    /* PDM must If any of these error occur, stop PDM-IF following Stop Flow and change the settings. */
    r_pdm_stop_sub(p_instance_ctrl);

    /* Clear the IR flag in the ICU */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

#if PDM_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Dedicated function for DMAC linkage at the time of reception.
 **********************************************************************************************************************/
void pdm_rxi_dmac_isr (dmac_b_callback_args_t * args)
{
    if (NULL != args)
    {
        pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) args->p_context;

        if ((NULL != p_instance_ctrl) && (p_instance_ctrl->p_callback))
        {
            uint32_t count = p_instance_ctrl->rx_int_count_max;
            count *= sizeof(uint32_t);

            /* Reload the next buffer */
            p_instance_ctrl->p_cfg->p_transfer_rx->p_api->reload(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl,
                                                                 (void *) &PDM_REG_CH(p_instance_ctrl->p_reg->PDDRRCH0,
                                                                                      p_instance_ctrl->p_cfg->channel),
                                                                 p_instance_ctrl->p_rx_fifo,
                                                                 count);

            /* Calculate the next-next buffer */
            p_instance_ctrl->p_rx_fifo =
                (void *) ((uint32_t *) p_instance_ctrl->p_rx_fifo + p_instance_ctrl->rx_int_count_max);

            uint32_t * p_data_end = p_instance_ctrl->p_rx_dest;
            p_data_end += p_instance_ctrl->rx_dest_samples;

            if (p_instance_ctrl->p_rx_fifo >= (void *) p_data_end)
            {
                p_instance_ctrl->p_rx_fifo = p_instance_ctrl->p_rx_dest;
            }

            /* Call callback function */
            r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_DATA, PDM_ERROR_NONE);
        }
    }
}

#endif
