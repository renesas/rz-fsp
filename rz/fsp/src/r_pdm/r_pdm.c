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

/* PCM width */
#define PDM_PRV_PCM_WIDTH_20_BITS_0_18    (0x0)
#define PDM_PRV_PCM_WIDTH_20_BITS_1_18    (0x1)
#define PDM_PRV_PCM_WIDTH_20_BITS_2_18    (0x2)
#define PDM_PRV_PCM_WIDTH_20_BITS_3_18    (0x3)
#define PDM_PRV_PCM_WIDTH_16_BITS_4_18    (0x8)
#define PDM_PRV_PCM_WIDTH_16_BITS_3_17    (0x9)
#define PDM_PRV_PCM_WIDTH_16_BITS_2_16    (0xa)
#define PDM_PRV_PCM_WIDTH_16_BITS_1_15    (0xb)
#define PDM_PRV_PCM_WIDTH_16_BITS_0_14    (0xc)

/* SINC Filter Mode */
#define PDM_PRV_SINC_FILTER_MODE_4        (0U)
#define PDM_PRV_SINC_FILTER_MODE_1        (1U)
#define PDM_PRV_SINC_FILTER_MODE_2        (2U)
#define PDM_PRV_SINC_FILTER_MODE_3        (3U)

/* PCM bits */
#define PDM_PRV_PCM_WIDTH_MASK            (0xF0U)
#define PDM_PRV_PCM_WIDTH_20_BITS         (0x00U)
#define PDM_PRV_PCM_WIDTH_16_BITS         (0x10U)

/* PDM macro functions */
#define PDM_PRV_CHANNEL_OFFSET            (uintptr_t) (&(R_PDM0->PDMDSRCH1) - &(R_PDM0->PDMDSRCH0))
#define PDM_REG_CH(a, b)    *(&(a) + (PDM_PRV_CHANNEL_OFFSET * (b)))

/* "PDM" in ASCII, used to determine if driver is open. */
#define PDM_PRV_OPEN                      (0x50444DU)

#define PDM_PRV_LOOP_MAX                  (1000)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * pdm_prv_ns_callback)(pdm_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile pdm_prv_ns_callback)(pdm_callback_args_t * p_args);
#endif

/* PDM communication direction */
typedef enum e_pdm_dir
{
    PDM_DIR_RX    = 1U,                ///< Receive direction only
    PDM_DIR_TX    = 2U,                ///< Transmit direction only
    PDM_DIR_TX_RX = 3U,                ///< Transmit and receive direction
} pdm_dir_t;

/* Arguments are stored in a structure for transfer reset subroutine to avoid having more than 4 arguments. */
typedef struct e_pdm_prv_transfer_reset
{
    void const * p_data;
    uint32_t     bytes;
    void const * p_src;
    void       * p_dest;
} pdm_prv_transfer_reset_t;

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

/* Open subroutines */

static void r_pdm_interrupts_configure(pdm_instance_ctrl_t * const p_instance, pdm_cfg_t const * const p_cfg);

#if PDM_CFG_DMAC_ENABLE
static fsp_err_t r_pdm_dependent_drivers_configure(pdm_instance_ctrl_t * p_instance_ctrl);
void             pdm_rxi_dmac_isr(dmac_b_callback_args_t * args);

#endif

/* Stop subroutines */
static void r_pdm_stop_sub(pdm_instance_ctrl_t * const p_instance_ctrl);
static void r_pdm_start_sub(pdm_instance_ctrl_t * const p_instance_ctrl);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** PDM Implementation of PDM interface.  */
const pdm_api_t g_pdm_on_pdm =
{
    .open        = R_PDM_Open,
    .start       = R_PDM_Start,
    .stop        = R_PDM_Stop,
    .read        = R_PDM_Read,
    .statusGet   = R_PDM_StatusGet,
    .close       = R_PDM_Close,
    .callbackSet = R_PDM_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZV
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_PDM
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Opens the PDM. Implements @ref pdm_api_t::open.
 *
 * This function sets this clock divisor and the configurations specified in pdm_cfg_t.  It also opens the timer and
 * transfer instances if they are provided.
 *
 * @retval FSP_SUCCESS                     Ready for PDM communication.
 * @retval FSP_ERR_ASSERTION               The pointer to p_ctrl or p_cfg is null.
 * @retval FSP_ERR_ALREADY_OPEN            The control block has already been opened.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT  Channel number is not available on this device.
 * @return                                 See @ref RZV_RENESAS_ERROR_CODES or functions called by this function for other
 *                                         popdmble return codes. This function calls:
 *                                             * @ref transfer_api_t::open
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
        dmac_trigger_event_t trigger = DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT0;
        if (1 == p_cfg->unit)
        {
            trigger = DMAC_TRIGGER_EVENT_PDM1_INT_PDM_DAT0;
        }

        trigger += p_cfg->channel;
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
    R_PDM0_Type * p_reg    = (R_PDM0_Type *) p_extend->p_reg;
    

    /************************************
     *   MODULE_ON
     ************************************/
    R_BSP_MODULE_START(FSP_IP_PDM, p_cfg->unit);

    /************************************
     *   PDM-IF initializing
     ************************************/

    /* Set Channel's Mode setting */
    uint32_t pcm_width;
    uint32_t sfmd;
    switch (p_cfg->pcm_width)
    {
        default:
        case PDM_PCM_WIDTH_20_BITS_0_18:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_20_BITS_0_18;
            break;
        }

        case PDM_PCM_WIDTH_20_BITS_1_18:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_20_BITS_1_18;
            break;
        }

        case PDM_PCM_WIDTH_20_BITS_2_18:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_20_BITS_2_18;
            break;
        }

        case PDM_PCM_WIDTH_20_BITS_3_18:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_20_BITS_3_18;
            break;
        }

        case PDM_PCM_WIDTH_16_BITS_4_18:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_16_BITS_4_18;
            break;
        }

        case PDM_PCM_WIDTH_16_BITS_3_17:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_16_BITS_3_17;
            break;
        }

        case PDM_PCM_WIDTH_16_BITS_2_16:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_16_BITS_2_16;
            break;
        }

        case PDM_PCM_WIDTH_16_BITS_1_15:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_16_BITS_1_15;
            break;
        }

        case PDM_PCM_WIDTH_16_BITS_0_14:
        {
            pcm_width = PDM_PRV_PCM_WIDTH_16_BITS_0_14;
            break;
        }
    }

    switch (p_extend->sinc_filter_mode)
    {
        default:
        case PDM_SINC_FILTER_MODE_4:
        {
            sfmd = PDM_PRV_SINC_FILTER_MODE_4;
            break;
        }

        case PDM_SINC_FILTER_MODE_1:
        {
            sfmd = PDM_PRV_SINC_FILTER_MODE_1;
            break;
        }

        case PDM_SINC_FILTER_MODE_2:
        {
            sfmd = PDM_PRV_SINC_FILTER_MODE_2;
            break;
        }

        case PDM_SINC_FILTER_MODE_3:
        {
            sfmd = PDM_PRV_SINC_FILTER_MODE_3;
            break;
        }
    }

    PDM_REG_CH(p_reg->PDMDSRCH0, p_cfg->channel) =
        (pcm_width << R_PDM_PDMDSRCH0_DBIS_Pos) |
        (uint32_t) (p_extend->moving_average_mode << R_PDM_PDMDSRCH0_SDMAMD_Pos) |
        (uint32_t) (p_extend->low_pass_filter_shift << R_PDM_PDMDSRCH0_LFIS_Pos) |
        (uint32_t) (p_extend->compensation_filter_shift << R_PDM_PDMDSRCH0_CFIS_Pos) |
        (uint32_t) (p_extend->high_pass_filter_shift << R_PDM_PDMDSRCH0_HFIS_Pos) |
        (sfmd << R_PDM_PDMDSRCH0_SFMD_Pos) |
        (uint32_t) (p_cfg->pcm_edge << R_PDM_PDMDSRCH0_INPSEL_Pos);

    /* Set Channel's Digital Filter Configuration */
    PDM_REG_CH(p_reg->PDSFCRCH0, p_cfg->channel) =
        (uint32_t) (p_extend->sincrng << R_PDM_PDSFCRCH0_SINCRNG_Pos) |
        (uint32_t) (p_extend->sincdec << R_PDM_PDSFCRCH0_SINCDEC_Pos) |
        (uint32_t) (p_extend->clock_div << R_PDM_PDSFCRCH0_CKDIV_Pos);
    PDM_REG_CH(p_reg->PDHFCS0RCH0, p_cfg->channel)  = (uint32_t) p_extend->hpf_coefficient_s0;
    PDM_REG_CH(p_reg->PDHFCK1RCH0, p_cfg->channel)  = (uint32_t) p_extend->hpf_coefficient_k1;
    PDM_REG_CH(p_reg->PDHFCH0RCH0, p_cfg->channel)  = (uint32_t) p_extend->hpf_coefficient_h[0];
    PDM_REG_CH(p_reg->PDHFCH1RCH0, p_cfg->channel)  = (uint32_t) p_extend->hpf_coefficient_h[1];
    PDM_REG_CH(p_reg->PDCFCH00RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[0];
    PDM_REG_CH(p_reg->PDCFCH01RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[1];
    PDM_REG_CH(p_reg->PDCFCH02RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[2];
    PDM_REG_CH(p_reg->PDCFCH03RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[3];
    PDM_REG_CH(p_reg->PDCFCH04RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[4];
    PDM_REG_CH(p_reg->PDCFCH05RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[5];
    PDM_REG_CH(p_reg->PDCFCH06RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[6];
    PDM_REG_CH(p_reg->PDCFCH07RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[7];
    PDM_REG_CH(p_reg->PDCFCH08RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[8];
    PDM_REG_CH(p_reg->PDCFCH09RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[9];
    PDM_REG_CH(p_reg->PDCFCH10RCH0, p_cfg->channel) = (uint32_t) p_extend->compensation_filter_coefficient_h[10];

    PDM_REG_CH(p_reg->PDLFCH010RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h0;
    PDM_REG_CH(p_reg->PDLFCH100RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[0];
    PDM_REG_CH(p_reg->PDLFCH101RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[1];
    PDM_REG_CH(p_reg->PDLFCH102RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[2];
    PDM_REG_CH(p_reg->PDLFCH103RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[3];
    PDM_REG_CH(p_reg->PDLFCH104RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[4];
    PDM_REG_CH(p_reg->PDLFCH105RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[5];
    PDM_REG_CH(p_reg->PDLFCH106RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[6];
    PDM_REG_CH(p_reg->PDLFCH107RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[7];
    PDM_REG_CH(p_reg->PDLFCH108RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[8];
    PDM_REG_CH(p_reg->PDLFCH109RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[9];
    PDM_REG_CH(p_reg->PDLFCH110RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[10];
    PDM_REG_CH(p_reg->PDLFCH111RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[11];
    PDM_REG_CH(p_reg->PDLFCH112RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[12];
    PDM_REG_CH(p_reg->PDLFCH113RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[13];
    PDM_REG_CH(p_reg->PDLFCH114RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[14];
    PDM_REG_CH(p_reg->PDLFCH115RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[15];
    PDM_REG_CH(p_reg->PDLFCH116RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[16];
    PDM_REG_CH(p_reg->PDLFCH117RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[17];
    PDM_REG_CH(p_reg->PDLFCH118RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[18];
    PDM_REG_CH(p_reg->PDLFCH119RCH0, p_cfg->channel) = (uint32_t) p_extend->lpf_coefficient_h1[19];

    /* Set Channel's Sound Detection Control */
    PDM_REG_CH(p_reg->PDSDLTRCH0, p_cfg->channel) = p_extend->sound_detection_lower_limit;
    PDM_REG_CH(p_reg->PDSDUTRCH0, p_cfg->channel) = p_extend->sound_detection_upper_limit;

    /* Set Channel's Data Buffer Control */
#if PDM_CFG_DMAC_ENABLE
    PDM_REG_CH(p_reg->PDDBCRCH0, p_cfg->channel) = PDM_INTERRUPT_THRESHOLD_1;
#else
    PDM_REG_CH(p_reg->PDDBCRCH0, p_cfg->channel) = (uint32_t) p_extend->interupt_threshold;
#endif

    /* Set Channel's Error Detection Control */
    PDM_REG_CH(p_reg->PDSCTSRCH0, p_cfg->channel) =
        (uint32_t) (p_extend->short_circuit_count_h << R_PDM_PDSCTSRCH0_SCDH_Pos) |
        (uint32_t) (p_extend->short_circuit_count_l << R_PDM_PDSCTSRCH0_SCDL_Pos);
    PDM_REG_CH(p_reg->PDOVLTRCH0, p_cfg->channel) = p_extend->overvoltage_detection_lower_limit;
    PDM_REG_CH(p_reg->PDOVUTRCH0, p_cfg->channel) = p_extend->overvoltage_detection_upper_limit;

    /* Initialize the control structure. */
    p_instance_ctrl->p_reg = p_reg;
    p_instance_ctrl->p_cfg = p_cfg;

    /* Configure interrupts. */
    r_pdm_interrupts_configure(p_instance_ctrl, p_cfg);

    /* Initialize the PDM following the procedure in "Procedure to start communication (CPU operation
     * procedure)" of the User's Manual. This function follows this procedure except for enabling
     * interrupts and enabling communication, which are done before communication begins. */

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
 * @retval FSP_ERR_INVALID_SIZE      The size of buffer is not the multiple of pdm_interrupt_threshold_t.
 * @retval FSP_ERR_INVALID_ALIGNMENT The alignment of argument buffer_size is not matched with hardware specification.
 * @retval FSP_ERR_NOT_OPEN          The channel is not opened.
 * @return                       See @ref RZV_RENESAS_ERROR_CODES or lower level drivers for other popdmble return codes.
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
    uint32_t stages_per_interrupt = 1U << p_extend->interupt_threshold;
    uint32_t datum_bytes;
    datum_bytes = sizeof(uint32_t);

    FSP_ERROR_RETURN((0 == ((uint32_t) p_buffer & 3)), FSP_ERR_INVALID_ALIGNMENT);

    uint32_t number_of_interrupt_in_buffer;
    uint32_t tmp = number_of_data_to_callback / stages_per_interrupt;
    FSP_ERROR_RETURN((number_of_data_to_callback == stages_per_interrupt * tmp), FSP_ERR_INVALID_SIZE);
    number_of_interrupt_in_buffer = buffer_size / datum_bytes / (number_of_data_to_callback / stages_per_interrupt);
    FSP_ERROR_RETURN((buffer_size ==
                      number_of_interrupt_in_buffer * datum_bytes * (number_of_data_to_callback / stages_per_interrupt)),
                     FSP_ERR_INVALID_SIZE);
    p_instance_ctrl->p_rx_dest        = p_buffer;
    p_instance_ctrl->p_rx_fifo        = p_buffer;
    p_instance_ctrl->rx_dest_samples  = buffer_size / datum_bytes;
    p_instance_ctrl->rx_int_count     = 0;
    p_instance_ctrl->rx_int_count_max = number_of_data_to_callback;

#if PDM_CFG_DMAC_ENABLE

    /* Configure dependent timer and transfer drivers. */
    fsp_err_t err = r_pdm_dependent_drivers_configure(p_instance_ctrl);
    FSP_ERROR_RETURN((FSP_SUCCESS == err), err);
#endif

    r_pdm_start_sub(p_instance_ctrl);

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
 * @return                       See @ref RZV_RENESAS_ERROR_CODES or lower level drivers for other popdmble return codes.
 **********************************************************************************************************************/
fsp_err_t R_PDM_Stop (pdm_ctrl_t * const p_ctrl)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Stop is complete after an PDM_EVENT_IDLE interrupt. */
    r_pdm_stop_sub(p_instance_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads data into provided buffer. Implements @ref pdm_api_t::read.
 *
 * This function resets the transfer if the transfer interface is used, or reads the length of data available in the
 * FIFO then stores the remaining read buffer in the control block to be filled in the ISR.
 *
 * Read() cannot be called if another Start() operation is in progress.  Read can be called
 * when the PDM is idle.
 *
 * @retval FSP_SUCCESS                 Read initiated successfully.
 * @retval FSP_ERR_IN_USE              Peripheral is in the wrong mode or not idle.
 * @retval FSP_ERR_ASSERTION           The pointer to p_ctrl or p_dest was null, or bytes requested was 0.
 * @retval FSP_ERR_NOT_OPEN            The channel is not opened.
 * @return                             See @ref RZV_RENESAS_ERROR_CODES or functions called by this function for other
 *                                     popdmble return codes. This function calls:
 *                                         * @ref transfer_api_t::reset
 **********************************************************************************************************************/
fsp_err_t R_PDM_Read (pdm_ctrl_t * const p_ctrl, void * const p_dest, uint32_t const bytes)
{
    pdm_instance_ctrl_t * p_instance_ctrl = (pdm_instance_ctrl_t *) p_ctrl;

#if PDM_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(PDM_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_dest);

    /* bytes must be a non-zero multiple of the FIFO access size multiplied by 2 (for the left and right channel). */
    FSP_ASSERT(bytes > 0U);
#endif

    FSP_ERROR_RETURN((0 ==
                      (p_instance_ctrl->p_reg->PDCSR & (1 << (R_PDM_PDCSR_STATE_Pos + p_instance_ctrl->p_cfg->channel)))),
                     FSP_ERR_IN_USE)

    uint32_t count = 0;
    uint32_t   max_count = PDM_REG_CH(p_instance_ctrl->p_reg->PDDSRCH0, p_instance_ctrl->p_cfg->channel);
    uint32_t * p_data    = p_dest;

    if (max_count > bytes / sizeof(uint32_t))
    {
        max_count = bytes / sizeof(uint32_t);
    }

    for (count = 0; count < max_count; count++)
    {
        *p_data++ = PDM_REG_CH(p_instance_ctrl->p_reg->PDDRRCH0, p_instance_ctrl->p_cfg->channel);
    }

    return FSP_SUCCESS;
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

    p_status->state =
        (0 ==
         (p_instance_ctrl->p_reg->PDCSR & (1 << (R_PDM_PDCSR_STATE_Pos + p_instance_ctrl->p_cfg->channel)))) ?
        PDM_STATE_STOPPED :
        PDM_STATE_IN_USE;

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

    r_pdm_stop_sub(p_instance_ctrl);

    p_instance_ctrl->open = 0U;

    /* Disable interrupts. */
    if (p_instance_ctrl->p_cfg->dat_irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->p_cfg->dat_irq);
    }

    if (p_instance_ctrl->p_cfg->sdet_irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->p_cfg->sdet_irq);
    }

    if (p_instance_ctrl->p_cfg->err_irq >= 0)
    {
        R_BSP_IrqDisable(p_instance_ctrl->p_cfg->err_irq);
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

/*******************************************************************************************************************//**
 * For each interrupt, if it is enabled, sets the interrupt priority based on user configuration and stores the control
 * block so it can be accessed in the ISR.
 *
 * @param[in] p_instance               Pointer to the p_instance structure.
 * @param[in] p_cfg                    Pointer to the configuration structure.
 **********************************************************************************************************************/
static void r_pdm_interrupts_configure (pdm_instance_ctrl_t * const p_instance, pdm_cfg_t const * const p_cfg)
{
    if (p_cfg->dat_irq >= 0)
    {
        R_BSP_IrqEnable(p_cfg->dat_irq);
        R_FSP_IsrContextSet(p_cfg->dat_irq, p_instance);
    }

    if (p_cfg->sdet_irq >= 0)
    {
        R_BSP_IrqEnable(p_cfg->sdet_irq);
        R_FSP_IsrContextSet(p_cfg->sdet_irq, p_instance);
    }

    if (p_cfg->err_irq >= 0)
    {
        R_BSP_IrqEnable(p_cfg->err_irq);
        R_FSP_IsrContextSet(p_cfg->err_irq, p_instance);
    }
}

#if PDM_CFG_DMAC_ENABLE

/*******************************************************************************************************************//**
 * Configures any dependent drivers selected by the user, including transfer and timer drivers.
 *
 * @param[in] p_reg                    Pointer to PDM base register address for this channel.
 * @param[in] p_cfg                    Pointer to the configuration structure.
 *
 * @retval FSP_SUCCESS                 Dependent drivers configured successfully.
 * @return                             See @ref RZV_RENESAS_ERROR_CODES or functions called by this function for other
 *                                     popdmble return codes. This function calls:
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
 * Enables PDM transmipdmon and reception.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 **********************************************************************************************************************/
static void r_pdm_start_sub (pdm_instance_ctrl_t * const p_instance_ctrl)
{
    const pdm_cfg_t    * p_cfg    = p_instance_ctrl->p_cfg;
    R_PDM0_Type        * p_reg    = p_instance_ctrl->p_reg;
    pdm_extended_cfg_t * p_extend = (pdm_extended_cfg_t *) p_cfg->p_extend;

    /* Activate target channel's filtering */
    p_reg->PDCSTRTR |= (uint32_t) (1UL << p_cfg->channel);

    /* Wait for settling time (maximum 90.5ms) */
#if (BSP_CFG_RTOS == 2)
    vTaskDelay(p_extend->filter_setting_time);
#else
    bsp_prv_software_delay_loop(p_extend->filter_setting_time * BSP_DELAY_UNITS_MILLISECONDS);
#endif

    /* Clear Channel's Status */
    PDM_REG_CH(p_reg->PDSCRCH0, p_cfg->channel) =
        R_PDM_PDSCRCH0_SDFC_Msk |
        R_PDM_PDSCRCH0_SCDFC_Msk |
        R_PDM_PDSCRCH0_OVLDFC_Msk |
        R_PDM_PDSCRCH0_OVUDFC_Msk |
        R_PDM_PDSCRCH0_BFOWDFC_Msk;

    /* Set Channel's Status Detection Control (for Error Detection) */
    PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) =
        (R_PDM_PDSDCRCH0_SDE_Msk * p_extend->sound_detection_enable) |
        (R_PDM_PDSDCRCH0_SCDE_Msk * p_extend->short_circuit_detection_enable) |
        (R_PDM_PDSDCRCH0_OVLDE_Msk * p_extend->over_voltage_lower_limit_detection_enable) |
        (R_PDM_PDSDCRCH0_OVUDE_Msk * p_extend->over_voltage_upper_limit_detection_enable) |
        (R_PDM_PDSDCRCH0_BFOWDE_Msk * p_extend->buffer_overwrite_detection_enable);

    /* Set Channel's Interrupt Control (for Error Detection) */
    p_reg->PDCICR |=
        (((1U << R_PDM_PDCICR_ISDE_Pos) * ((p_cfg->sdet_irq >= 0) ? 1 : 0)) |
         ((1U << R_PDM_PDCICR_IDRE_Pos) * ((p_cfg->dat_irq >= 0) ? 1 : 0)) |
         ((1U << R_PDM_PDCICR_IEDE_Pos) * ((p_cfg->err_irq >= 0) ? 1 : 0))) << p_cfg->channel;

    /* Set Channel's Data Read Enable */
    p_reg->PDCDRCR |= 1 << (R_PDM_PDCDRCR_DATRE_Pos + p_cfg->channel);
}

/*******************************************************************************************************************//**
 * Disables PDM transmipdmon and reception.
 *
 * @param[in] p_instance_ctrl          Pointer to the control block.
 **********************************************************************************************************************/
static void r_pdm_stop_sub (pdm_instance_ctrl_t * const p_instance_ctrl)
{
    /* Stop communication following the procedure from "Procedure to halt communication (CPU operation
     * procedure)" in the User's Manual. */

    const pdm_cfg_t * p_cfg = p_instance_ctrl->p_cfg;
    R_PDM0_Type     * p_reg = p_instance_ctrl->p_reg;
    uint32_t          loop;
    pdm_status_t      status = {.state = PDM_STATE_STOPPED};
    fsp_err_t         err    = R_PDM_StatusGet(p_instance_ctrl, &status);

    if ((FSP_SUCCESS == err) && (PDM_STATE_STOPPED != status.state))
    {
        /* Disable Channel's Data Read */
        p_reg->PDCDRCR &= ~(uint32_t) (1U << (R_PDM_PDCDRCR_DATRE_Pos + p_cfg->channel));

#if PDM_CFG_DMAC_ENABLE

        /* If transfer is used, close transfer when stop is requested. */
        if (NULL != p_instance_ctrl->p_cfg->p_transfer_rx)
        {
            (void) p_instance_ctrl->p_cfg->p_transfer_rx->p_api->close(p_instance_ctrl->p_cfg->p_transfer_rx->p_ctrl);
        }
#endif

        /* Stop target channel's filtering */
        p_reg->PDCSTPTR |= 1 << (R_PDM_PDCSTPTR_STPTRG_Pos + p_cfg->channel);

        /* Target channel is stopped? */

        for (loop = 0; loop < PDM_PRV_LOOP_MAX; loop++)
        {
            if (0 == (p_reg->PDCSR & (1 << (R_PDM_PDCSR_STATE_Pos + p_cfg->channel))))
            {
                break;
            }
        }

        /* Disable Channel's Interrupt */
        p_reg->PDCICR &=
            ~(((uint32_t) (1U << R_PDM_PDCICR_ISDE_Pos) |
               (uint32_t) (1U << R_PDM_PDCICR_IDRE_Pos) |
               (uint32_t) (1U << R_PDM_PDCICR_IEDE_Pos)) << p_cfg->channel);

        /* Disable Channel's Status Detection */
        PDM_REG_CH(p_reg->PDSDCRCH0, p_cfg->channel) = 0;
        p_reg->PDCSDCR &= ~(uint32_t) (1U << (R_PDM_PDCSDCR_SDE_Pos + p_cfg->channel));

        /* Clear Channel's Status */
        PDM_REG_CH(p_reg->PDSCRCH0, p_cfg->channel) =
            R_PDM_PDSCRCH0_SDFC_Msk |
            R_PDM_PDSCRCH0_SCDFC_Msk |
            R_PDM_PDSCRCH0_OVLDFC_Msk |
            R_PDM_PDSCRCH0_OVUDFC_Msk |
            R_PDM_PDSCRCH0_BFOWDFC_Msk;
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

    /* disable Sound detection */
    PDM_REG_CH(p_instance_ctrl->p_reg->PDSDCRCH0, p_instance_ctrl->p_cfg->channel) &= ~R_PDM_PDSDCRCH0_SDE_Msk;

    /* clear Sound detection flag */
    PDM_REG_CH(p_instance_ctrl->p_reg->PDSCRCH0, p_instance_ctrl->p_cfg->channel) = R_PDM_PDSCRCH0_SDFC_Msk;

    /* Clear the IR flag in the ICU */
    R_BSP_IrqStatusClear(irq);

    /* If there are more samples to write to the FIFO or the FIFO is above the watermark, don't call the callback. */
    if (p_instance_ctrl->p_callback)
    {
        r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_SOUND_DETECTION, 0);
    }

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
                r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_DATA, 0);
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

    if (p_instance_ctrl->p_callback)
    {
        pdm_error_t error    = 0;
        uint32_t    pdsdcrch = 0;

        /* Get Status. */
        pdsdcrch = PDM_REG_CH(p_instance_ctrl->p_reg->PDSRCH0, p_instance_ctrl->p_cfg->channel);
        if (pdsdcrch & R_PDM_PDSRCH0_SCDF_Msk)
        {
            error |= PDM_ERROR_SHORT_CIRCUIT;
        }

        if (pdsdcrch & R_PDM_PDSRCH0_OVLDF_Msk)
        {
            error |= PDM_ERROR_OVERVOLTAGE_LOWER;
        }

        if (pdsdcrch & R_PDM_PDSRCH0_OVUDF_Msk)
        {
            error |= PDM_ERROR_OVERVOLTAGE_UPPER;
        }

        if (pdsdcrch & R_PDM_PDSRCH0_BFOWDF_Msk)
        {
            error |= PDM_ERROR_BUFFER_OVERWRITE;
        }

        /* If peripheral is idle, call idle callback. */
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
            r_pdm_call_callback(p_instance_ctrl, PDM_EVENT_DATA, 0);
        }
    }
}

#endif
