/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_canfd.h"
#include "r_canfd_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define CANFD_OPEN                             (0x52434644U) // "RCFD" in ASCII

#define CANFD_BAUD_RATE_PRESCALER_MIN          (1U)
#define CANFD_BAUD_RATE_PRESCALER_MAX          (1024U)

#define CANFD_PRV_CTR_MODE_MASK                (R_CANFD_CFDGCTR_GSLPR_Msk + R_CANFD_CFDGCTR_GMDC_Msk)
#define CANFD_PRV_CTR_RESET_BIT                (1U)
#define CANFD_PRV_RX_BUFFER_RAM_LIMIT_BYTES    (4864U)
#define CANFD_PRV_RXMB_MAX                     (32U)
#define CANFD_PRV_TXMB_OFFSET                  (32U)
#define CANFD_PRV_TXMB_CHANNEL_OFFSET          (64U)
#define CANFD_PRV_STANDARD_ID_MAX              (0x7FFU)

#define CANFD_PRV_CFIFO_CHANNEL_OFFSET         (3U)

#define R_CANFD_CFDRM_RM_TYPE                  R_CANFD_CFDRM_Type

#define CANFD_PRV_RXMB_PTR(buffer)    (&p_reg->CFDRM[buffer])
#define CANFD_PRV_RX_FIFO_MAX                  (8U)
#define CANFD_PRV_COMMON_FIFO_MAX              (3U)
#define CANFD_PRV_CFDTMIEC_LENGTH              (2)
#define CANFD_PRV_RMID_POSITION                (R_CANFD_CFDRM_ID_RMID_Pos)
#define CANFD_PRV_RMID_MASK                    (R_CANFD_CFDRM_ID_RMID_Msk)
#define CANFD_PRV_RMRTR_POSITION               (R_CANFD_CFDRM_ID_RMRTR_Pos)
#define CANFD_PRV_RMRTR_MASK                   (R_CANFD_CFDRM_ID_RMRTR_Msk)
#define CANFD_PRV_RMIDE_POSITION               (R_CANFD_CFDRM_ID_RMIDE_Pos)
#define CANFD_PRV_RMIDE_MASK                   (R_CANFD_CFDRM_ID_RMIDE_Msk)
#define CANFD_PRV_RMDLC_POSITION               (R_CANFD_CFDRM_PTR_RMDLC_Pos)
#define CANFD_PRV_RMDLC_MASK                   (R_CANFD_CFDRM_PTR_RMDLC_Msk)

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
 #define CANFD_INTER_CH(channel)                  (0U)
#else
 #define CANFD_INTER_CH(channel)                  (channel)
#endif

#define CANFD_PRV_CFIFO_INDEX(buffer, channel)    ((buffer) + ((channel) * CANFD_PRV_CFIFO_CHANNEL_OFFSET))

/***********************************************************************************************************************
 * Const data
 **********************************************************************************************************************/

/* LUT to convert DLC values to payload size in bytes */
static const uint8_t dlc_to_bytes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

#if CANFD_CFG_PARAM_CHECKING_ENABLE

/* LUT to determine the hierarchy of can_operation_mode_t modes. */
static const uint8_t g_mode_order[] = {0, 2, 1, 0, 0, 3};
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
#if CANFD_CFG_PARAM_CHECKING_ENABLE
static bool r_canfd_bit_timing_parameter_check(can_bit_timing_cfg_t * p_bit_timing, bool is_data_phase);

#endif

static uint8_t r_canfd_bytes_to_dlc(uint8_t bytes);

static void r_candfd_global_error_handler(uint32_t instance);
static void r_canfd_rx_fifo_handler(uint32_t instance);
static void r_canfd_mb_read(R_CANFD_Type * p_reg, uint32_t buffer, can_frame_t * const frame);
static void r_canfd_call_callback(canfd_instance_ctrl_t * p_instance_ctrl, can_callback_args_t * p_args);
static void r_canfd_mode_transition(canfd_instance_ctrl_t * p_instance_ctrl, can_operation_mode_t operation_mode);
static void r_canfd_mode_ctr_set(volatile uint32_t * p_ctr_reg, can_operation_mode_t operation_mode);
void        canfd_error_isr(void);
void        canfd_rx_fifo_isr(void);
void        canfd_common_fifo_rx_isr(void);
void        canfd_channel_tx_isr(void);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* Channel control struct array */
static canfd_instance_ctrl_t * gp_instance_ctrl[BSP_FEATURE_CANFD_NUM_INSTANCES * BSP_FEATURE_CANFD_NUM_CHANNELS] =
{
    NULL
};

/* CAN function pointers   */
const can_api_t g_canfd_on_canfd =
{
    .open           = R_CANFD_Open,
    .close          = R_CANFD_Close,
    .write          = R_CANFD_Write,
    .read           = R_CANFD_Read,
    .modeTransition = R_CANFD_ModeTransition,
    .infoGet        = R_CANFD_InfoGet,
    .callbackSet    = R_CANFD_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_CANFD
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***************************************************************************************************************//**
 * Open and configure the CANFD channel for operation.
 *
 * @retval FSP_SUCCESS                            Channel opened successfully.
 * @retval FSP_ERR_ALREADY_OPEN                   Driver already open.
 * @retval FSP_ERR_IN_USE                         Channel is already in use.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT         Channel does not exist on this MPU.
 * @retval FSP_ERR_ASSERTION                      A required pointer was NULL.
 * @retval FSP_ERR_CAN_INIT_FAILED                The provided nominal or data bitrate is invalid.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Open (can_ctrl_t * const p_ctrl, can_cfg_t const * const p_cfg)
{
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;

#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_extend);
    FSP_ASSERT(p_cfg->p_callback);
    FSP_ASSERT(p_cfg->p_bit_timing);

    uint32_t channel = p_cfg->channel;

    /* Check that the module is not open, the channel is present and that it is not in use */
    FSP_ERROR_RETURN(CANFD_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(channel < BSP_FEATURE_CANFD_NUM_CHANNELS * BSP_FEATURE_CANFD_NUM_INSTANCES,
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(NULL == gp_instance_ctrl[channel], FSP_ERR_IN_USE);

    /* Check that mandatory interrupts are enabled */
    FSP_ERROR_RETURN(VECTOR_NUMBER_CAN_RXF >= 0, FSP_ERR_CAN_INIT_FAILED);
    FSP_ERROR_RETURN(VECTOR_NUMBER_CAN_GLERR >= 0, FSP_ERR_CAN_INIT_FAILED);

    /* Check that the global config is present */
    canfd_extended_cfg_t * p_extend = (canfd_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(p_extend->p_global_cfg);

    /* Check nominal bit timing parameters for correctness */
    FSP_ERROR_RETURN(r_canfd_bit_timing_parameter_check(p_cfg->p_bit_timing, false), FSP_ERR_CAN_INIT_FAILED);

    /* Check that bit timing for FD bitrate switching is present and correct */
    can_bit_timing_cfg_t * p_data_timing = p_extend->p_data_timing;
    FSP_ASSERT(p_data_timing);
    FSP_ERROR_RETURN(r_canfd_bit_timing_parameter_check(p_data_timing, true), FSP_ERR_CAN_INIT_FAILED);

    can_bit_timing_cfg_t * p_bit_timing = p_cfg->p_bit_timing;

    /* Check that data rate > nominal rate */
    uint32_t data_rate_clocks = p_data_timing->baud_rate_prescaler *
                                (p_data_timing->time_segment_1 + p_data_timing->time_segment_2 + 1U);
    uint32_t nominal_rate_clocks = p_bit_timing->baud_rate_prescaler *
                                   (p_bit_timing->time_segment_1 + p_bit_timing->time_segment_2 + 1U);
    FSP_ERROR_RETURN(data_rate_clocks <= nominal_rate_clocks, FSP_ERR_CAN_INIT_FAILED);
#else
    uint32_t channel = p_cfg->channel;

    /* Get extended config */
    canfd_extended_cfg_t * p_extend = (canfd_extended_cfg_t *) p_cfg->p_extend;
#endif

    fsp_err_t err = FSP_SUCCESS;

    /* Save the base register for this channel. */
    R_CANFD_Type * p_reg = (R_CANFD_Type *) p_extend->p_reg;
    p_instance_ctrl->p_reg = p_reg;

    /* Initialize the control block */
    p_instance_ctrl->p_cfg = p_cfg;

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Get global config */
    canfd_global_cfg_t * p_global_cfg = p_extend->p_global_cfg;

    /* Start module */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_CANFD, 0);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Perform global config only if the module is in Global Sleep or Global Reset */
    if (p_reg->CFDGSTS & R_CANFD_CFDGSTS_GRSTSTS_Msk)
    {
        /* Wait for RAM initialization
         *(see RZ microprocessor Hardware Manual section "Timing of Global Mode Change") */
        FSP_HARDWARE_REGISTER_WAIT((p_reg->CFDGSTS & R_CANFD_CFDGSTS_GRAMINIT_Msk), 0);

        /* Cancel Global Sleep and wait for transition to Global Reset */
        r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_GLOBAL_RESET);

        /* Configure global TX priority, DLC check/replace functions, external/internal clock select and payload
         * overflow behavior */
        p_reg->CFDGCFG = p_global_cfg->global_config;

        /* Configure rule count for both channels */
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
        p_reg->CFDGAFLCFG0 = (CANFD_CFG_AFL_CH0_RULE_NUM << R_CANFD_CFDGAFLCFG0_RNC0_Pos);
#else
        p_reg->CFDGAFLCFG0 = (CANFD_CFG_AFL_CH0_RULE_NUM << R_CANFD_CFDGAFLCFG0_RNC0_Pos) |
                             CANFD_CFG_AFL_CH1_RULE_NUM;
#endif

        /* Set CAN FD Protocol Exception response (ISO exception state or send error frame) */
        p_reg->CFDGFDCFG = CANFD_CFG_FD_PROTOCOL_EXCEPTION;

        /* Set number and size of RX message buffers */
        p_reg->CFDRMNB = p_global_cfg->rx_mb_config;

        /* Configure RX FIFOs and interrupt */
        for (uint32_t i = 0; i < CANFD_PRV_RX_FIFO_MAX; i++)
        {
            p_reg->CFDRFCC[i] = p_global_cfg->rx_fifo_config[i];
        }

        R_BSP_IrqCfgEnable(VECTOR_NUMBER_CAN_RXF, p_global_cfg->rx_fifo_ipl, NULL);

        /* Set global error interrupts */
        p_reg->CFDGCTR = p_global_cfg->global_interrupts;

        /* Configure Common FIFOs */
        for (uint32_t i = 0; i < R_CANFD_NUM_COMMON_FIFOS; i++)
        {
            /* Configure the Common FIFOs. Mask out the enable bit because it can only be set once operating.
             * See Section "Common FIFO Configuration/Control Register n" in the RZ microprocessor Hardware Manual for more details. */
            p_reg->CFDCFCC[i] = p_global_cfg->common_fifo_config[i] & (uint32_t) ~R_CANFD_CFDCFCC_CFE_Msk;
        }
    }

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    if (CANFD_CFG_GLOBAL_ERROR_CH == channel)
#endif
    {
        /* Configure global error interrupt */
        R_BSP_IrqCfgEnable(VECTOR_NUMBER_CAN_GLERR, p_global_cfg->global_err_ipl, p_instance_ctrl);
    }

    /* Track ctrl struct */
    gp_instance_ctrl[channel] = p_instance_ctrl;

    /* Get AFL entry and limit */
    uint32_t afl_entry = 0;
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    uint32_t afl_max = CANFD_CFG_AFL_CH0_RULE_NUM;
    if (1U == channel)
    {
        afl_max = CANFD_CFG_AFL_CH1_RULE_NUM;
    }

#else
    uint32_t afl_max = CANFD_CFG_AFL_CH0_RULE_NUM;
    if (1U == channel)
    {
        afl_entry += CANFD_CFG_AFL_CH0_RULE_NUM;
        afl_max   += CANFD_CFG_AFL_CH1_RULE_NUM;
    }
#endif

    /* Unlock AFL */
    p_reg->CFDGAFLECTR = R_CANFD_CFDGAFLECTR_AFLDAE_Msk;

    /* Write all configured AFL entries */
    R_CANFD_CFDGAFL_Type * p_afl = (R_CANFD_CFDGAFL_Type *) p_extend->p_afl;
    for ( ; afl_entry < afl_max; afl_entry++)
    {
        /* AFL register access is performed through a page window comprised of 16 entries. See Section "Entering
         * Entries in the AFL" in the RZ microprocessor Hardware Manual for more details. */

        /* Set AFL page */
        p_reg->CFDGAFLECTR = (afl_entry >> 4) | R_CANFD_CFDGAFLECTR_AFLDAE_Msk;

        /* Get pointer to current AFL rule and set it to the rule pointed to by p_afl */
        volatile R_CANFD_CFDGAFL_Type * cfdgafl = &R_CANFD->CFDGAFL[afl_entry & 0xF];

        cfdgafl->ID = p_afl->ID;
        cfdgafl->M  = p_afl->M;
        cfdgafl->P0 = p_afl->P0;
        cfdgafl->P1 = p_afl->P1;
        p_afl++;

        /* Set Information Label 0 to the channel being configured */
        cfdgafl->P0_b.GAFLIFL0 = channel & 1U;
    }

    /* Lock AFL */
    p_reg->CFDGAFLECTR = 0;

    /* Cancel Channel Sleep and wait for transition to Channel Reset */
    r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_RESET);

    uint32_t interlaced_channel = CANFD_INTER_CH(channel);

    /* Configure bitrate */
    p_reg->CFDC[interlaced_channel].NCFG =
        (uint32_t) (((p_cfg->p_bit_timing->baud_rate_prescaler - 1) & R_CANFD_CFDC_NCFG_NBRP_Msk) <<
                    R_CANFD_CFDC_NCFG_NBRP_Pos) |
        ((p_cfg->p_bit_timing->time_segment_1 - 1U) << R_CANFD_CFDC_NCFG_NTSEG1_Pos) |
        ((p_cfg->p_bit_timing->time_segment_2 - 1U) << R_CANFD_CFDC_NCFG_NTSEG2_Pos) |
        ((p_cfg->p_bit_timing->synchronization_jump_width - 1U) << R_CANFD_CFDC_NCFG_NSJW_Pos);

    /* Configure data bitrate for rate switching on FD frames */
    p_reg->CFDC2[interlaced_channel].DCFG =
        (uint32_t) (((p_extend->p_data_timing->baud_rate_prescaler - 1) & R_CANFD_CFDC2_DCFG_DBRP_Msk) <<
                    R_CANFD_CFDC2_DCFG_DBRP_Pos) |
        ((p_extend->p_data_timing->time_segment_1 - 1U) << R_CANFD_CFDC2_DCFG_DTSEG1_Pos) |
        ((p_extend->p_data_timing->time_segment_2 - 1U) << R_CANFD_CFDC2_DCFG_DTSEG2_Pos) |
        ((p_extend->p_data_timing->synchronization_jump_width - 1U) << R_CANFD_CFDC2_DCFG_DSJW_Pos);

    /* Ensure transceiver delay offset is not larger than 8 bits */
    uint32_t tdco = p_extend->p_data_timing->time_segment_1;
    if (tdco > UINT8_MAX)
    {
        tdco = UINT8_MAX;
    }

    /* Configure transceiver delay compensation; allow user to set ESI bit manually
     * Leave the CLOE bit at the default setting for each device product.
     */
    uint32_t cloe = p_reg->CFDC2[interlaced_channel].FDCFG_b.CLOE;
    p_reg->CFDC2[interlaced_channel].FDCFG =
        (cloe << R_CANFD_CFDC2_FDCFG_CLOE_Pos) |
        (tdco << R_CANFD_CFDC2_FDCFG_TDCO_Pos) |
        (uint32_t) (p_extend->delay_compensation << R_CANFD_CFDC2_FDCFG_TDCE_Pos) |
        R_CANFD_CFDC2_FDCFG_ESIC_Msk | 1U;

    /* Write TX message buffer interrupt enable bits */
    memcpy((void *) &p_reg->CFDTMIEC[interlaced_channel * CANFD_PRV_CFDTMIEC_LENGTH],
           &p_extend->txmb_txi_enable,
           CANFD_PRV_CFDTMIEC_LENGTH * sizeof(uint32_t));

    /* Configure channel error interrupts */
    p_reg->CFDC[interlaced_channel].CTR = p_extend->error_interrupts | R_CANFD_CFDC_CTR_CHMDC_Msk;

    /* Enable channel interrupts */

    if (p_cfg->error_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->error_irq, p_cfg->ipl, p_instance_ctrl);
    }

    if (p_cfg->tx_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->tx_irq, p_cfg->ipl, p_instance_ctrl);
    }

    /* Use the CAN RX IRQ for Common FIFO RX. */
    if (p_cfg->rx_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->rx_irq, p_cfg->ipl, p_ctrl);
    }

    /* Set global mode to Operation and wait for transition */
    r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_GLOBAL_OPERATION);

    /* Transition to Channel Operation */
    r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_NORMAL);

    /* Set current operation modes */
    p_instance_ctrl->operation_mode = CAN_OPERATION_MODE_NORMAL;
    p_instance_ctrl->test_mode      = CAN_TEST_MODE_DISABLED;

    /* Set driver to open */
    p_instance_ctrl->open = CANFD_OPEN;

    return err;
}

/***************************************************************************************************************//**
 * Close the CANFD channel.
 *
 * @retval FSP_SUCCESS               Channel closed successfully.
 * @retval FSP_ERR_NOT_OPEN          Control block not open.
 * @retval FSP_ERR_ASSERTION         Null pointer presented.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Close (can_ctrl_t * const p_ctrl)
{
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;

#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);
#endif

    /* Get config struct */
    can_cfg_t * p_cfg = (can_cfg_t *) p_instance_ctrl->p_cfg;

    /* Disable channel interrupts */

    if (p_cfg->error_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->error_irq);
    }

    if (p_cfg->tx_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->tx_irq);
    }

    if (p_cfg->rx_irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->rx_irq);
    }

    /* Disable Global Error interrupt if the handler channel is being closed */
    if (CANFD_CFG_GLOBAL_ERROR_CH == p_cfg->channel)
    {
        R_BSP_IrqDisable(VECTOR_NUMBER_CAN_GLERR);

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

        /* Disable RX FIFO interrupt */
        R_BSP_IrqDisable(VECTOR_NUMBER_CAN_RXF);
#endif
    }

    /* Set channel to Sleep if other is open, otherwise reset/stop CANFD module */
    if (gp_instance_ctrl[!p_cfg->channel])
    {
        r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_SLEEP);
    }
    else
    {
#if BSP_FEATURE_CANFD_NUM_INSTANCES == 1

        /* Disable RX FIFO interrupt */
        R_BSP_IrqDisable(VECTOR_NUMBER_CAN_RXF);
#endif

        /* Transition to Global Sleep */
        r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_GLOBAL_RESET);
        r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_GLOBAL_SLEEP);

        /* Stop CANFD module */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
        R_BSP_MODULE_STOP(FSP_IP_CANFD, 0);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    }

    /* Reset global control struct pointer */
    gp_instance_ctrl[p_cfg->channel] = NULL;

    /* Set driver to closed */
    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Write data to the CANFD channel.
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_CAN_TRANSMIT_NOT_READY   Transmit in progress, cannot write data at this time.
 * @retval FSP_ERR_INVALID_ARGUMENT         Data length or buffer number invalid.
 * @retval FSP_ERR_INVALID_MODE             An FD option was set on a non-FD frame.
 * @retval FSP_ERR_ASSERTION                Null pointer presented
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Write (can_ctrl_t * const p_ctrl, uint32_t buffer, can_frame_t * const p_frame)
{
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;

    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_frame);
    FSP_ERROR_RETURN(p_instance_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);

    /* CANFD channels have 32 TX message buffers + 3 common FIFOs each (0-15, 32-47, 64-66) */
    FSP_ERROR_RETURN((buffer <= 15U) ||
                     (buffer - 32U <= 15U) ||
                     (buffer - (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0 <= 2U),
                     FSP_ERR_INVALID_ARGUMENT);

    /* Check DLC field */
    if (!(p_frame->options & CANFD_FRAME_OPTION_FD))
    {
        FSP_ERROR_RETURN(p_frame->data_length_code <= 8, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(p_frame->options == 0, FSP_ERR_INVALID_MODE);
    }
    else if (p_frame->data_length_code > 0)
    {
        /* Make sure the supplied data size corresponds to a valid DLC value */
        FSP_ERROR_RETURN(0U != r_canfd_bytes_to_dlc(p_frame->data_length_code), FSP_ERR_INVALID_ARGUMENT);
    }
    else
    {
        /* Do nothing. */
    }

#else
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;
#endif

    /* Provide variables to store common values. */
    const bool     is_cfifo           = buffer >= (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0;
    const uint32_t interlaced_channel = CANFD_INTER_CH(p_instance_ctrl->p_cfg->channel);

    const uint32_t id = p_frame->id | ((uint32_t) p_frame->type << R_CANFD_CFDTM_ID_TMRTR_Pos) |
                        ((uint32_t) p_frame->id_mode << R_CANFD_CFDTM_ID_TMIDE_Pos);

    uint32_t           buffer_idx = 0;
    volatile uint8_t * p_dest     = NULL;

    if (!is_cfifo)
    {
        /* Calculate global TX message buffer number */
        buffer_idx = buffer + (interlaced_channel * CANFD_PRV_TXMB_CHANNEL_OFFSET);

        /* Ensure MB is ready */
        FSP_ERROR_RETURN(0U == p_instance_ctrl->p_reg->CFDTMSTS_b[buffer_idx].TMTSTS, FSP_ERR_CAN_TRANSMIT_NOT_READY);

        /* Set ID */
        p_instance_ctrl->p_reg->CFDTM[buffer_idx].ID = id;

        /* Set DLC */
        p_instance_ctrl->p_reg->CFDTM[buffer_idx].PTR = (uint32_t) r_canfd_bytes_to_dlc(p_frame->data_length_code) <<
                                                        R_CANFD_CFDTM_PTR_TMDLC_Pos;

        /* Set FD bits (ESI, BRS and FDF) */
        p_instance_ctrl->p_reg->CFDTM[buffer_idx].FDCTR = p_frame->options & 7U;

        /* Store the data pointer. */
        p_dest = (uint8_t *) p_instance_ctrl->p_reg->CFDTM[buffer_idx].DF;
    }
    else
    {
        /* Calculate the Common FIFO index. */
        buffer_idx = buffer - (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0 +
                     (interlaced_channel * CANFD_PRV_CFIFO_CHANNEL_OFFSET);

        /* Set ID. */
        p_instance_ctrl->p_reg->CFDCF[buffer_idx].ID = id;

        /* Set DLC. */
        p_instance_ctrl->p_reg->CFDCF[buffer_idx].PTR = (uint32_t) r_canfd_bytes_to_dlc(p_frame->data_length_code) <<
                                                        R_CANFD_CFDCF_PTR_CFDLC_Pos;

        /* Set the FD bits (ESI, BRS and FDF). */
        p_instance_ctrl->p_reg->CFDCF[buffer_idx].FDCSTS = p_frame->options & 7U;

        /* Store the data poitner. */
        p_dest = (uint8_t *) p_instance_ctrl->p_reg->CFDCF[buffer_idx].DF;
    }

    /* Copy data to register buffer */
    uint32_t           len   = p_frame->data_length_code;
    volatile uint8_t * p_src = p_frame->data;
    while (len--)
    {
        *p_dest++ = *p_src++;
    }

    if (!is_cfifo)
    {
        /* Request transmission */
        p_instance_ctrl->p_reg->CFDTMC[buffer_idx] = 1;
    }
    else
    {
        /* Increment the FIFO pointer by writing 0xFF to CFPC. */
        p_instance_ctrl->p_reg->CFDCFPCTR[buffer_idx] = R_CANFD_CFDCFPCTR_CFPC_Msk;
    }

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Read data from a CANFD Message Buffer or FIFO.
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_INVALID_ARGUMENT         Buffer number invalid.
 * @retval FSP_ERR_ASSERTION                p_ctrl or p_frame is NULL.
 * @retval FSP_ERR_BUFFER_EMPTY             Buffer or FIFO is empty.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Read (can_ctrl_t * const p_ctrl, uint32_t buffer, can_frame_t * const p_frame)
{
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_frame);
    FSP_ERROR_RETURN(p_instance_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((buffer < CANFD_PRV_RXMB_MAX + CANFD_PRV_RX_FIFO_MAX) ||
                     ((buffer >= CANFD_RX_BUFFER_FIFO_COMMON_0) &&
                      (buffer < CANFD_RX_BUFFER_FIFO_COMMON_0 + CANFD_PRV_COMMON_FIFO_MAX)),
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    uint32_t not_empty;

    /* Return an error if the buffer or FIFO is empty */
    if (buffer < CANFD_PRV_RXMB_MAX)
    {
        not_empty = p_instance_ctrl->p_reg->CFDRMND0 & (1U << buffer);
    }
    else if (buffer < (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0)
    {
        not_empty = !(p_instance_ctrl->p_reg->CFDFESTS & (1U << (buffer - CANFD_PRV_RXMB_MAX)));
    }
    else
    {
        /* Common FIFO status are grouped together and not channelized, so calculate the index based on the channel. */
        const uint32_t cfifo_idx = CANFD_PRV_CFIFO_INDEX(buffer - (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0,
                                                         CANFD_INTER_CH(p_instance_ctrl->p_cfg->channel));

        /* Update the buffer to be effectively the cfifo index calculated above. */
        /* This is needed since r_canfd_mb_read(...) doesn't take a channel number. */
        buffer = cfifo_idx + (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0;

        not_empty = (~p_instance_ctrl->p_reg->CFDFESTS & (1U << (R_CANFD_CFDFESTS_CFXEMP_Pos + cfifo_idx))) != 0;
    }

    FSP_ERROR_RETURN(not_empty, FSP_ERR_BUFFER_EMPTY);

    /* Retrieve message from buffer */
    r_canfd_mb_read(p_instance_ctrl->p_reg, buffer, p_frame);

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Switch to a different channel, global or test mode.
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_ASSERTION                Null pointer presented
 * @retval FSP_ERR_INVALID_MODE             Cannot change to the requested mode from the current global mode.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_ModeTransition (can_ctrl_t * const   p_ctrl,
                                  can_operation_mode_t operation_mode,
                                  can_test_mode_t      test_mode)
{
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(p_instance_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);

    /* Get Global Status */
    uint32_t cfdgsts = p_instance_ctrl->p_reg->CFDGSTS;

    /* Check to ensure the current mode is Global Halt when transitioning into or out of Internal Bus mode */
    FSP_ERROR_RETURN((cfdgsts & R_CANFD_CFDGSTS_GHLTSTS_Msk) || !((p_instance_ctrl->test_mode != test_mode) &&
                                                                  ((CAN_TEST_MODE_INTERNAL_BUS ==
                                                                    p_instance_ctrl->test_mode) ||
                                                                   (CAN_TEST_MODE_INTERNAL_BUS == test_mode))),
                     FSP_ERR_INVALID_MODE);

    /* Check to ensure the current mode is Global Reset when transitioning into or out of Global Sleep (see Section
     * "Global Modes" in the RZ microprocessor Hardware Manual for details) */
    FSP_ERROR_RETURN(((cfdgsts & R_CANFD_CFDGSTS_GRSTSTS_Msk) && (CAN_OPERATION_MODE_RESET & operation_mode)) ||
                     (!(cfdgsts & R_CANFD_CFDGSTS_GSLPSTS_Msk) && (CAN_OPERATION_MODE_GLOBAL_SLEEP != operation_mode)),
                     FSP_ERR_INVALID_MODE);

    /* Check to ensure the current Global mode supports the requested Channel mode, if applicable. The requested mode
     * and the current global mode are converted into a number 0-3 corresponding to Operation, Halt, Reset and Sleep
     * respectively. The channel mode cannot be switched to a mode with an index lower than the current global mode. */
    if (operation_mode < CAN_OPERATION_MODE_GLOBAL_OPERATION)
    {
        FSP_ERROR_RETURN(g_mode_order[operation_mode] >= g_mode_order[cfdgsts & CANFD_PRV_CTR_MODE_MASK],
                         FSP_ERR_INVALID_MODE);
    }
#endif

    uint32_t interlaced_channel = CANFD_INTER_CH(p_instance_ctrl->p_cfg->channel);

    if (p_instance_ctrl->test_mode != test_mode)
    {
        /* Follow the procedure for switching to Internal Bus mode given in Section "Internal CAN Bus
         * Communication Test Mode" of the RZ microprocessor Hardware Manual */
        if (CAN_TEST_MODE_INTERNAL_BUS == test_mode)
        {
            /* Disable channel test mode */
            p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR_b.CTME = 0;

            /* Link channel to internal bus */
            p_instance_ctrl->p_reg->CFDGTSTCFG |= 1U << interlaced_channel;

            /* Enable internal bus test mode */
            p_instance_ctrl->p_reg->CFDGTSTCTR = 1;
        }
        else
        {
            if (p_instance_ctrl->test_mode == CAN_TEST_MODE_INTERNAL_BUS)
            {
                /* Unlink channel from internal bus */
                p_instance_ctrl->p_reg->CFDGTSTCFG &= ~(1U << interlaced_channel);

                /* Disable global test mode if no channels are linked */
                if (!p_instance_ctrl->p_reg->CFDGTSTCFG)
                {
                    p_instance_ctrl->p_reg->CFDGTSTCTR = 0;
                }
            }

            /* Transition to Channel Halt when changing test modes */
            r_canfd_mode_transition(p_instance_ctrl, CAN_OPERATION_MODE_HALT);

            /* Set channel test mode */
            uint32_t cfdcnctr = p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR;
            cfdcnctr &= (uint32_t) ~(R_CANFD_CFDC_CTR_CTME_Msk | R_CANFD_CFDC_CTR_CTMS_Msk);
            p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR = cfdcnctr |
                                                                   ((uint32_t) test_mode << R_CANFD_CFDC_CTR_CTME_Pos);
        }

        p_instance_ctrl->test_mode = test_mode;
    }

    if (p_instance_ctrl->operation_mode != operation_mode)
    {
        r_canfd_mode_transition(p_instance_ctrl, operation_mode);
    }

    return err;
}

/***************************************************************************************************************//**
 * Get CANFD state and status information for the channel.
 *
 * @retval  FSP_SUCCESS                     Operation succeeded.
 * @retval  FSP_ERR_NOT_OPEN                Control block not open.
 * @retval  FSP_ERR_ASSERTION               Null pointer presented
 *****************************************************************************************************************/
fsp_err_t R_CANFD_InfoGet (can_ctrl_t * const p_ctrl, can_info_t * const p_info)
{
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;

    /* Check pointers for NULL values */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_info);

    /* If channel is not open, return an error */
    FSP_ERROR_RETURN(p_instance_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);
#else
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;
#endif

    uint32_t interlaced_channel = CANFD_INTER_CH(p_instance_ctrl->p_cfg->channel);

    uint32_t cfdcnsts = p_instance_ctrl->p_reg->CFDC[interlaced_channel].STS;
    p_info->status               = cfdcnsts & UINT16_MAX;
    p_info->error_count_receive  = (uint8_t) ((cfdcnsts & R_CANFD_CFDC_STS_REC_Msk) >> R_CANFD_CFDC_STS_REC_Pos);
    p_info->error_count_transmit = (uint8_t) ((cfdcnsts & R_CANFD_CFDC_STS_TEC_Msk) >> R_CANFD_CFDC_STS_TEC_Pos);
    p_info->error_code           = p_instance_ctrl->p_reg->CFDC[interlaced_channel].ERFL & UINT16_MAX;
    p_info->rx_mb_status         = p_instance_ctrl->p_reg->CFDRMND0;
    p_info->rx_fifo_status       = (~p_instance_ctrl->p_reg->CFDFESTS) &
                                   (R_CANFD_CFDFESTS_RFXEMP_Msk | R_CANFD_CFDFESTS_CFXEMP_Msk);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref can_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_CANFD_CallbackSet (can_ctrl_t * const          p_ctrl,
                               void (                    * p_callback)(can_callback_args_t *),
                               void * const                p_context,
                               can_callback_args_t * const p_callback_memory)
{
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) p_ctrl;

#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(CANFD_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup CAN)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
#if CANFD_CFG_PARAM_CHECKING_ENABLE
static bool r_canfd_bit_timing_parameter_check (can_bit_timing_cfg_t * const p_bit_timing, bool is_data_phase)
{
    /* Check that prescaler is in range */
    FSP_ERROR_RETURN((p_bit_timing->baud_rate_prescaler <= CANFD_BAUD_RATE_PRESCALER_MAX) &&
                     (p_bit_timing->baud_rate_prescaler >= CANFD_BAUD_RATE_PRESCALER_MIN),
                     false);

    /* Check that TSEG1 > TSEG2 >= SJW for nominal bitrate per section "Bit Timing Conditions" in the
     * RZ microprocessor Hardware Manual. */

    if (is_data_phase)
    {
        /* Check Time Segment 1 is greater than or equal to Time Segment 2 */
        FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_1 >= (uint32_t) p_bit_timing->time_segment_2, false);
    }
    else
    {
        /* Check Time Segment 1 is greater than Time Segment 2 */
        FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_1 > (uint32_t) p_bit_timing->time_segment_2, false);
    }

    /* Check Time Segment 2 is greater than or equal to the synchronization jump width */
    FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_2 >= (uint32_t) p_bit_timing->synchronization_jump_width,
                     false);

    return true;
}

#endif

/*******************************************************************************************************************//**
 * Read from a Message Buffer or FIFO.
 *
 * NOTE: Does not index FIFOs.
 *
 * @param[in]     p_reg      Pointer to the CANFD registers
 * @param[in]     buffer     Index of buffer to read from (MBs 0-31, FIFOs 32+)
 * @param[in]     frame      Pointer to CAN frame to write to
 **********************************************************************************************************************/
static void r_canfd_mb_read (R_CANFD_Type * p_reg, uint32_t buffer, can_frame_t * const frame)
{
    const bool is_mb    = buffer < CANFD_PRV_RXMB_MAX;
    const bool is_cfifo = buffer >= (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0;

    /* Get pointer to message buffer (FIFOs use the same buffer structure) */
    volatile R_CANFD_CFDRM_RM_TYPE * mb_regs;
    if (is_mb)
    {
        mb_regs = CANFD_PRV_RXMB_PTR(buffer);
    }
    else if (is_cfifo)
    {
        mb_regs = (volatile R_CANFD_CFDRM_RM_TYPE *) &(p_reg->CFDCF[buffer - (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0]);
    }
    else
    {
        mb_regs = (volatile R_CANFD_CFDRM_RM_TYPE *) &(p_reg->CFDRF[buffer - CANFD_PRV_RXMB_MAX]);
    }

    /* Get frame data. */
    uint32_t id = mb_regs->ID;

    /* Get the frame type */
    frame->type = (can_frame_type_t) ((id & CANFD_PRV_RMRTR_MASK) >> CANFD_PRV_RMRTR_POSITION);

    /* Get FD status bits (ESI, BRS and FDF) */
    frame->options = mb_regs->FDSTS & 7U;

    /* Get the frame ID */
    frame->id = id & CANFD_PRV_RMID_MASK;

    /* Get the frame ID mode (IDE bit) */
    frame->id_mode = (can_id_mode_t) (id >> CANFD_PRV_RMIDE_POSITION);

    /* Get the frame data length code */
    frame->data_length_code = dlc_to_bytes[mb_regs->PTR >> CANFD_PRV_RMDLC_POSITION];

    /* Copy data to frame */
    uint32_t           len    = frame->data_length_code;
    volatile uint8_t * p_dest = frame->data;
    volatile uint8_t * p_src  = (uint8_t *) mb_regs->DF;
    while (len--)
    {
        *p_dest++ = *p_src++;
    }

    if (is_mb)
    {
        /* Clear RXMB New Data bit */
        p_reg->CFDRMND0 &= ~(1U << buffer);
    }
    else if (is_cfifo)
    {
        /* Increment the Common FIFO pointer. */
        p_reg->CFDCFPCTR[buffer - (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0] = R_CANFD_CFDCFPCTR_CFPC_Msk;
    }
    else
    {
        /* Increment RX FIFO pointer */
        p_reg->CFDRFPCTR[buffer - CANFD_PRV_RXMB_MAX] = UINT8_MAX;
    }
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl     Pointer to CAN instance control block
 * @param[in]     p_args              Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_canfd_call_callback (canfd_instance_ctrl_t * p_instance_ctrl, can_callback_args_t * p_args)
{
    can_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    can_callback_args_t * p_args_memory = p_instance_ctrl->p_callback_memory;
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

    p_instance_ctrl->p_callback(p_args_memory);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Global Error Handler.
 *
 * Handles the Global Error IRQ for a given instance of CANFD.
 **********************************************************************************************************************/
static void r_candfd_global_error_handler (uint32_t instance)
{
    canfd_instance_ctrl_t * p_instance_ctrl = gp_instance_ctrl[instance];

    can_callback_args_t args = {0U};

    args.event = CAN_EVENT_ERR_GLOBAL;

    /* Read global error flags. */
    uint32_t cfdgerfl = p_instance_ctrl->p_reg->CFDGERFL;

    /* Global errors are in the top halfword of canfd_error_t; move and preserve ECC error flags. */
    args.error = ((cfdgerfl & UINT16_MAX) << 16) + ((cfdgerfl >> 16) << 28);

    /* Clear global error flags. */
    p_instance_ctrl->p_reg->CFDGERFL = 0;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->CFDGERFL);

    if (args.error & CANFD_ERROR_GLOBAL_MESSAGE_LOST)
    {
        /* Get lowest RX FIFO with Message Lost condition and clear the flag */
        args.buffer = __CLZ(__RBIT(p_instance_ctrl->p_reg->CFDFMSTS));
        p_instance_ctrl->p_reg->CFDRFSTS[args.buffer] &= (uint32_t) ~R_CANFD_CFDRFSTS_RFMLT_Msk;

        /* Dummy read to ensure that interrupt event is cleared. */
        FSP_REGISTER_READ(p_instance_ctrl->p_reg->CFDRFSTS[args.buffer]);
    }

    /* Set channel and context based on selected global error handler channel. */
    args.channel   = CANFD_CFG_GLOBAL_ERROR_CH;
    args.p_context = p_instance_ctrl->p_context;

    /* Set remaining arguments and call callback */
    r_canfd_call_callback(p_instance_ctrl, &args);
}

/*******************************************************************************************************************//**
 * Error ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common error function, and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_error_isr (void)
{
    CANFD_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Get IRQ and context */
    IRQn_Type irq = R_FSP_CurrentIrqGet();

    if (VECTOR_NUMBER_CAN_GLERR == irq)
    {
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

        /* If there are seperate instances of CANFD, then loop over each instance to handle the source of the global
         * error IRQ. */
        for (uint32_t i = 0; i < BSP_FEATURE_CANFD_NUM_INSTANCES; i++)
        {
            if (NULL != gp_ctrl[i])
            {
                r_candfd_global_error_handler(i);
            }
        }

#else
        r_candfd_global_error_handler(CANFD_CFG_GLOBAL_ERROR_CH);
#endif
    }
    else
    {
        canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

        can_callback_args_t     args = {0U};
        canfd_instance_ctrl_t * p_callback_ctrl;

        args.event = CAN_EVENT_ERR_CHANNEL;

        /* Read and clear channel error flags. */
        uint32_t interlaced_channel = CANFD_INTER_CH(p_instance_ctrl->p_cfg->channel);
        args.error = p_instance_ctrl->p_reg->CFDC[interlaced_channel].ERFL & UINT16_MAX; // Upper halfword contains latest CRC
        p_instance_ctrl->p_reg->CFDC[interlaced_channel].ERFL = 0;

        /* Dummy read to ensure that interrupt event is cleared. */
        FSP_REGISTER_READ(p_instance_ctrl->p_reg->CFDC[interlaced_channel].ERFL);

        /* Choose the channel provided by the interrupt context. */
        p_callback_ctrl = p_instance_ctrl;

        args.channel   = interlaced_channel;
        args.p_context = p_instance_ctrl->p_context;
        args.buffer    = 0U;

        /* Set remaining arguments and call callback */
        r_canfd_call_callback(p_callback_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    CANFD_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Receive FIFO handler.
 *
 * Handles the Receive IRQ for a given instance of CANFD.
 **********************************************************************************************************************/
static void r_canfd_rx_fifo_handler (uint32_t instance)
{
    can_callback_args_t args;
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    R_CANFD_Type * p_reg =
        (R_CANFD_Type *) ((uint32_t) R_CANFD0 + (instance * ((uint32_t) R_CANFD1 - (uint32_t) R_CANFD0)));
#else
    FSP_PARAMETER_NOT_USED(instance);
    R_CANFD_Type * p_reg = R_CANFD;
#endif

    /* Get lowest FIFO requesting interrupt */
    uint32_t fifo = __CLZ(__RBIT(p_reg->CFDRFISTS));

    /* Only perform ISR duties if a FIFO has requested it */
    if (fifo < CANFD_PRV_RX_FIFO_MAX)
    {
        /* Set static arguments */
        args.event  = CAN_EVENT_RX_COMPLETE;
        args.buffer = fifo + CANFD_PRV_RXMB_MAX;

        /* Read from the FIFO until it is empty */
        while (!(p_reg->CFDFESTS & (1U << fifo)))
        {
            /* Get channel associated with the AFL entry */
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
            args.channel = instance;
#else
            args.channel = p_reg->CFDRF[fifo].FDSTS_b.RFIFL;
#endif

            /* Read and index FIFO */
            r_canfd_mb_read(p_reg, fifo + CANFD_PRV_RXMB_MAX, &args.frame);

            /* Set the remaining callback arguments */
            args.p_context = gp_instance_ctrl[args.channel]->p_context;
            r_canfd_call_callback(gp_instance_ctrl[args.channel], &args);
        }

        /* Clear RX FIFO Interrupt Flag */
        p_reg->CFDRFSTS[fifo] &= (uint32_t) ~R_CANFD_CFDRFSTS_RFIF_Msk;

        /* Dummy read to ensure that interrupt event is cleared. */
        FSP_REGISTER_READ(p_reg->CFDRFSTS[fifo]);
    }
}

/*******************************************************************************************************************//**
 * Receive ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common receive function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_rx_fifo_isr (void)
{
    CANFD_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

    /* If there are seperate instances of CANFD, then loop over each instance to handle the source of the global
     * receive IRQ. */
    for (uint32_t i = 0; i < BSP_FEATURE_CANFD_NUM_INSTANCES; i++)
    {
        if (NULL != gp_ctrl[i])
        {
            r_canfd_rx_fifo_handler(i);
        }
    }

#else
    r_canfd_rx_fifo_handler(0U);
#endif

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    CANFD_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Transmit ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common transmit function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_channel_tx_isr (void)
{
    CANFD_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    canfd_extended_cfg_t  * p_extend        = (canfd_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    uint32_t                channel         = p_instance_ctrl->p_cfg->channel;

    /* Set static arguments */
    can_callback_args_t args;
    args.channel   = channel;
    args.p_context = p_instance_ctrl->p_context;

    uint32_t interlaced_channel = CANFD_INTER_CH(channel);

    /* Check the byte of CFDGTINTSTS0 that corresponds to the interrupting channel */
    volatile uint8_t * p_cfdgtintsts =
        (((volatile uint8_t *) &p_instance_ctrl->p_reg->CFDGTINTSTS0) + interlaced_channel);
    while (*p_cfdgtintsts)
    {
        bool                is_cfifo = false;
        uint32_t            txmb;
        volatile uint32_t * p_cfdtm_sts;
        const uint32_t      cfdgtintsts = *p_cfdgtintsts;

        interlaced_channel <<= 1;

        /* Get relevant TX status register bank */
        if (cfdgtintsts & R_CANFD_CFDGTINTSTS0_TSIF0_Msk)
        {
            p_cfdtm_sts = (volatile uint32_t *) &p_instance_ctrl->p_reg->CFDTMTCSTS[interlaced_channel];
            args.event  = CAN_EVENT_TX_COMPLETE;
        }
        else if (cfdgtintsts & R_CANFD_CFDGTINTSTS0_CFTIF0_Msk)
        {
            is_cfifo    = true;
            p_cfdtm_sts = (volatile uint32_t *) &p_instance_ctrl->p_reg->CFDCFTISTS;
            args.event  = (p_extend->p_global_cfg->common_fifo_config[interlaced_channel] & R_CANFD_CFDCFCC_CFIM_Msk) ?
                          CAN_EVENT_TX_COMPLETE : CAN_EVENT_TX_FIFO_EMPTY;
        }
        else
        {
            p_cfdtm_sts = (volatile uint32_t *) &p_instance_ctrl->p_reg->CFDTMTASTS[interlaced_channel];
            args.event  = CAN_EVENT_TX_ABORTED;
        }

        interlaced_channel >>= 1;

        /* Calculate lowest TXMB with the specified event */
        if (!is_cfifo)
        {
            txmb = __CLZ(__RBIT(*p_cfdtm_sts));
            txmb = (txmb < 16) ? txmb : __CLZ(__RBIT(*(p_cfdtm_sts + 1))) + CANFD_PRV_TXMB_OFFSET;

            /* Clear TX complete/abort flags */
            p_instance_ctrl->p_reg->CFDTMSTS_b[txmb + (CANFD_PRV_TXMB_CHANNEL_OFFSET * interlaced_channel)].TMTRF = 0;

            /* Dummy read to ensure that interrupt event is cleared. */
            FSP_REGISTER_READ(p_instance_ctrl->p_reg->CFDTMSTS[txmb +
                                                               (CANFD_PRV_TXMB_CHANNEL_OFFSET * interlaced_channel)]);
        }
        else
        {
            /* Adjust txmb with the lowest indexed Common FIFO that could have triggered this event.
             * Mask out only the Common FIFOs associated with this channel. */
            uint32_t cfdtm_mask = ((1U << CANFD_PRV_COMMON_FIFO_MAX) - 1U) <<
                                  (interlaced_channel * CANFD_PRV_COMMON_FIFO_MAX);
            txmb = __CLZ(__RBIT(*p_cfdtm_sts & cfdtm_mask));

            /* Clear the interrupt flag for Common FIFO TX. */
            p_instance_ctrl->p_reg->CFDCFSTS[txmb] &= (uint32_t) ~R_CANFD_CFDCFSTS_CFTXIF_Msk;

            /* Dummy read to ensure that interrupt event is cleared. */
            FSP_REGISTER_READ(p_instance_ctrl->p_reg->CFDCFSTS[txmb]);

            /* Add the Common FIFO offset so the correct type of buffer will be available in the callback. */
            txmb += CANFD_TX_BUFFER_FIFO_COMMON_0;
        }

        /* Set the callback arguments */
        args.buffer = txmb;
        r_canfd_call_callback(p_instance_ctrl, &args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    CANFD_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Common FIFO Receive ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common receive function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_common_fifo_rx_isr (void)
{
    CANFD_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    canfd_instance_ctrl_t * p_instance_ctrl = (canfd_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    uint32_t                channel         = p_instance_ctrl->p_cfg->channel;
    can_callback_args_t     args;

    /* Get lowest FIFO requesting interrupt */

    /* To satisfy clang-tidy mask out the index. A value of 32 only happens if no flag is set which shouldn't happen in
     * this ISR. If it does for some reason, the while loop below will be bypassed since the associated flag being
     * checked will be ignored. */
    uint32_t fifo = __CLZ(__RBIT(p_instance_ctrl->p_reg->CFDCFRISTS & R_CANFD_CFDCFRISTS_CFXRXIF_Msk)) & 0x1FU;

    /* Set static arguments */
    args.event   = CAN_EVENT_RX_COMPLETE;
    args.channel = channel;

#if BSP_FEATURE_CANFD_NUM_CHANNELS > 1

    /* Get the channel based fifo index to get the currect buffer value. */
    if (fifo > CANFD_PRV_CFIFO_CHANNEL_OFFSET)
    {
        args.buffer = fifo % (CANFD_PRV_CFIFO_CHANNEL_OFFSET + 1);
    }
    else
    {
        args.buffer = fifo;
    }

#else
    args.buffer = fifo;
#endif

    /* Move buffer up to the correct range. */
    args.buffer += (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0;

    /* Read from the FIFO until it is empty */
    while (!(p_instance_ctrl->p_reg->CFDFESTS & (1U << (R_CANFD_CFDFESTS_CFXEMP_Pos + fifo))))
    {
        /* Read and index FIFO */
        /* buffer is slightly different in this function since it operates globally. */
        r_canfd_mb_read(p_instance_ctrl->p_reg, fifo + (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0, &args.frame);

        /* Set the remaining callback arguments */
        args.p_context = gp_instance_ctrl[args.channel]->p_context;
        r_canfd_call_callback(gp_instance_ctrl[args.channel], &args);
    }

    /* Clear Common FIFO RX Interrupt Flag */
    p_instance_ctrl->p_reg->CFDCFSTS[fifo] &= (uint32_t) ~R_CANFD_CFDCFSTS_CFRXIF_Msk;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->CFDCFSTS[fifo]);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    CANFD_CFG_MULTIPLEX_INTERRUPT_ENABLE;
}

/*******************************************************************************************************************//**
 * This function is used to switch the CANFD peripheral operation mode.
 * @param[in]  p_instance_ctrl            - pointer to control structure
 * @param[in]  operation_mode    - destination operation mode
 **********************************************************************************************************************/
static void r_canfd_mode_transition (canfd_instance_ctrl_t * p_instance_ctrl, can_operation_mode_t operation_mode)
{
    uint32_t interlaced_channel = CANFD_INTER_CH(p_instance_ctrl->p_cfg->channel);

    /* Get bit 7 from operation_mode to determine if this is a global mode change request */
    bool global_mode = (bool) (operation_mode >> 7);
    operation_mode &= 0xF;

    if (global_mode)
    {
        uint32_t cfdgctr = p_instance_ctrl->p_reg->CFDGCTR;

        /* If CANFD is transitioning to Global Reset, make sure the FIFOs are disabled. */
        if (!(cfdgctr & R_CANFD_CFDGSTS_GRSTSTS_Msk) && (operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Disable RX FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_RX_FIFO_MAX; i++)
            {
                p_instance_ctrl->p_reg->CFDRFCC[i] &= (uint32_t) ~R_CANFD_CFDRFCC_RFE_Msk;
            }

            /* Disable Common FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_COMMON_FIFO_MAX * BSP_FEATURE_CANFD_NUM_CHANNELS; i++)
            {
                p_instance_ctrl->p_reg->CFDCFCC[i] &= (uint32_t) ~R_CANFD_CFDCFCC_CFE_Msk;
            }
        }

        r_canfd_mode_ctr_set(&p_instance_ctrl->p_reg->CFDGCTR, operation_mode);

        /* If CANFD is transitioning out of Reset the FIFOs need to be enabled. */
        if ((cfdgctr & R_CANFD_CFDGSTS_GRSTSTS_Msk) && !(operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Get global config */
            canfd_global_cfg_t * p_global_cfg =
                ((canfd_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->p_global_cfg;

            /* Enable RX FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_RX_FIFO_MAX; i++)
            {
                p_instance_ctrl->p_reg->CFDRFCC[i] = p_global_cfg->rx_fifo_config[i];
            }
        }
    }
    else
    {
        uint32_t cfdcnctr = p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR;

        if (((cfdcnctr & R_CANFD_CFDC_CTR_CSLPR_Msk) && (!(CAN_OPERATION_MODE_RESET & operation_mode))) ||
            ((!(cfdcnctr & CANFD_PRV_CTR_RESET_BIT)) && (CAN_OPERATION_MODE_SLEEP == operation_mode)))
        {
            /* Transition channel to Reset if a transition to/from Sleep is requested (see Section "Channel
             * Modes" in the RZ microprocessor Hardware Manual for details) */
            r_canfd_mode_ctr_set(&p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR, CAN_OPERATION_MODE_RESET);
        }

        /* Request transition to selected mode */
        r_canfd_mode_ctr_set(&p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR, operation_mode);

        /* If CANFD is transitioning from Reset, make sure the Common FIFOs are enabled.
         * The FIFOs will be disabled automatically if configured for TX and the channel is transitioned to reset. */
        if ((cfdcnctr & R_CANFD_CFDC_CTR_CHMDC_Msk) && !(operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Get global config */
            canfd_global_cfg_t * p_global_cfg =
                ((canfd_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->p_global_cfg;

            const uint32_t ch_offset = interlaced_channel * CANFD_PRV_COMMON_FIFO_MAX;

            /* Enable Common FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_COMMON_FIFO_MAX; i++)
            {
                p_instance_ctrl->p_reg->CFDCFCC[ch_offset + i] |=
                    (p_global_cfg->common_fifo_config[ch_offset + i] & (uint32_t) R_CANFD_CFDCFCC_CFE_Msk);
            }
        }
    }

    p_instance_ctrl->operation_mode =
        (can_operation_mode_t) (p_instance_ctrl->p_reg->CFDC[interlaced_channel].CTR & CANFD_PRV_CTR_MODE_MASK);
}

/*******************************************************************************************************************//**
 * Sets the provided CTR register to the requested mode and waits for the associated STS register to reflect the change
 * @param[in]  p_ctr_reg            - pointer to control register
 * @param[in]  operation_mode       - requested mode (not including global bits)
 **********************************************************************************************************************/
static void r_canfd_mode_ctr_set (volatile uint32_t * p_ctr_reg, can_operation_mode_t operation_mode)
{
    volatile uint32_t * p_sts_reg = p_ctr_reg + 1;

    /* See definitions for CFDCnCTR, CFDCnSTS, CFDGCTR and CFDGSTS in the RZ microprocessor Hardware Manual */
    *p_ctr_reg = (*p_ctr_reg & (uint32_t) ~CANFD_PRV_CTR_MODE_MASK) | operation_mode;
    FSP_HARDWARE_REGISTER_WAIT((*p_sts_reg & CANFD_PRV_CTR_MODE_MASK), operation_mode);
}

/*******************************************************************************************************************//**
 * Converts bytes into a DLC value
 * @param[in]  bytes       Number of payload bytes
 **********************************************************************************************************************/
static uint8_t r_canfd_bytes_to_dlc (uint8_t bytes)
{
    if (bytes <= 8)
    {
        return bytes;
    }

    if (bytes <= 24)
    {
        return (uint8_t) (8U + ((bytes - 8U) / 4U));
    }

    return (uint8_t) (0xDU + ((bytes / 16U) - 2U));
}
