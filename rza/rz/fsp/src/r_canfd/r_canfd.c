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

#define CANFD_OPEN                         (0x52434644U) // "RCFD" in ASCII

#define CANFD_BAUD_RATE_PRESCALER_MIN      (1U)
#define CANFD_BAUD_RATE_PRESCALER_MAX      (1024U)

#if BSP_FEATURE_CANFD_HAS_RSCANFD
 #define CANFD_PRV_AFL_RX_BUFFER_MASK      (0xFF00)
 #define CANFD_PRV_AFL_MINIMUM_DLC_MASK    (0x0F)
 #define CANFD_PRV_AFL_MINIMUM_DLC_POS     (28)

 #define CANFD_PRV_CTR_MODE_MASK           (R_CANFD_RSCFDnCFDGCTR_GSLPR_Msk + R_CANFD_RSCFDnCFDGCTR_GMDC_Msk)
 #define CANFD_PRV_CTR_RESET_BIT           (1U)
 #define CANFD_PRV_RXMB_MAX                (32U)
 #define CANFD_PRV_TXMB_OFFSET             (16U)
 #define CANFD_PRV_TXMB_CHANNEL_OFFSET     (16U)
 #define CANFD_PRV_STANDARD_ID_MAX         (0x7FFU)
#endif

/** Whether or not the peripheral contains CFDCFTISTS and CFDCFRISTS registers. */
#define CANFD_PRV_CFIFO_HAS_ISTS           (!(BSP_FEATURE_CANFD_LITE && BSP_FEATURE_CANFD_NUM_CHANNELS == 1))

#if BSP_FEATURE_CANFD_LITE
 #define CANFD_PRV_CFIFO_CHANNEL_OFFSET    (1U)

 #define R_CANFD_CFDRM_RM_TYPE             R_CANFD_CFDRM_RM_Type

 #define CANFD_PRV_RXMB_PTR(buffer)    ((volatile R_CANFD_CFDRM_RM_TYPE *) &p_reg->CFDRM[buffer >> 3].RM[buffer & 7U])
 #define CANFD_PRV_RX_FIFO_MAX             (2U)
 #define CANFD_PRV_COMMON_FIFO_MAX         (1U)
 #define CANFD_PRV_CFDTMIEC_LENGTH         (1)
 #define CANFD_PRV_RMID_POSITION           (R_CANFD_CFDRM_RM_ID_RMID_Pos)
 #define CANFD_PRV_RMID_MASK               (R_CANFD_CFDRM_RM_ID_RMID_Msk)
 #define CANFD_PRV_RMRTR_POSITION          (R_CANFD_CFDRM_RM_ID_RMRTR_Pos)
 #define CANFD_PRV_RMRTR_MASK              (R_CANFD_CFDRM_RM_ID_RMRTR_Msk)
 #define CANFD_PRV_RMIDE_POSITION          (R_CANFD_CFDRM_RM_ID_RMIDE_Pos)
 #define CANFD_PRV_RMIDE_MASK              (R_CANFD_CFDRM_RM_ID_RMIDE_Msk)
 #define CANFD_PRV_RMDLC_POSITION          (R_CANFD_CFDRM_RM_PTR_RMDLC_Pos)
 #define CANFD_PRV_RMDLC_MASK              (R_CANFD_CFDRM_RM_PTR_RMDLC_Msk)
#else
 #define CANFD_PRV_CFIFO_CHANNEL_OFFSET    (3U)
 #define CANFD_PRV_RX_FIFO_MAX             (8U)
 #define CANFD_PRV_COMMON_FIFO_MAX         (3U)
 #define CANFD_PRV_CFDTMIEC_LENGTH         (2)
 #if BSP_FEATURE_CANFD_HAS_RSCANFD
  #define CANFD_PRV_RMID_POSITION          (R_CANFD_RSCFDnCFDRMID0_RMID_Pos)
  #define CANFD_PRV_RMID_MASK              (R_CANFD_RSCFDnCFDRMID0_RMID_Msk)
  #define CANFD_PRV_RMRTR_POSITION         (R_CANFD_RSCFDnCFDRMID0_RMRTR_Pos)
  #define CANFD_PRV_RMRTR_MASK             (R_CANFD_RSCFDnCFDRMID0_RMRTR_Msk)
  #define CANFD_PRV_RMIDE_POSITION         (R_CANFD_RSCFDnCFDRMID0_RMIDE_Pos)
  #define CANFD_PRV_RMIDE_MASK             (R_CANFD_RSCFDnCFDRMID0_RMIDE_Msk)
  #define CANFD_PRV_RMDLC_POSITION         (R_CANFD_RSCFDnCFDRMPTR0_RMDLC_Pos)
  #define CANFD_PRV_RMDLC_MASK             (R_CANFD_RSCFDnCFDRMPTR0_RMDLC_Msk)
  #define CANFD_PRV_CFDFESTS_RFXEMP_Msk    (0x000000FFUL)
  #define CANFD_PRV_CFDFESTS_CFXEMP_Msk    (0x00003f00UL)
  #define CANFD_PRV_CFDCFCC_CFE_Msk        (R_CANFD_RSCFDnCFDCFCC0_CFE_Msk)
 #endif
#endif

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
 * Typedef definitions
 **********************************************************************************************************************/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
typedef void (BSP_CMSE_NONSECURE_CALL * canfd_prv_ns_callback)(can_callback_args_t * p_args);
#elif defined(__GNUC__)
typedef BSP_CMSE_NONSECURE_CALL void (*volatile canfd_prv_ns_callback)(can_callback_args_t * p_args);
#endif

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
#if CANFD_CFG_PARAM_CHECKING_ENABLE
static bool r_canfd_bit_timing_parameter_check(can_bit_timing_cfg_t * p_bit_timing, bool is_data_phase);

#endif

#if BSP_FEATURE_CANFD_FD_SUPPORT
static uint8_t r_canfd_bytes_to_dlc(uint8_t bytes);

#endif

static void r_canfd_global_error_handler(uint32_t instance);
static void r_canfd_rx_fifo_handler(uint32_t instance);
static void r_canfd_mb_read(R_CANFD_Type * p_reg, uint32_t buffer, can_frame_t * const frame);
static void r_canfd_call_callback(canfd_instance_ctrl_t * p_ctrl, can_callback_args_t * p_args);
static void r_canfd_mode_transition(canfd_instance_ctrl_t * p_ctrl, can_operation_mode_t operation_mode);
static void r_canfd_mode_ctr_set(volatile uint32_t * p_ctr_reg, can_operation_mode_t operation_mode);
void        canfd_error_isr(IRQn_Type const irq);
void        canfd_rx_fifo_isr(IRQn_Type const irq);
void        canfd_common_fifo_rx_isr(IRQn_Type const irq);
void        canfd_channel_tx_isr(IRQn_Type const irq);

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
static canfd_instance_ctrl_t * gp_ctrl[BSP_FEATURE_CANFD_NUM_INSTANCES * BSP_FEATURE_CANFD_NUM_CHANNELS] = {NULL};

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
namespace RZA
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_CANFD
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***************************************************************************************************************//**
 * Open and configure the CANFD channel for operation.
 *
 * Example:
 * @snippet rza_r_canfd_example.c R_CANFD_Open
 *
 * @retval FSP_SUCCESS                            Channel opened successfully.
 * @retval FSP_ERR_ALREADY_OPEN                   Driver already open.
 * @retval FSP_ERR_IN_USE                         Channel is already in use.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT         Channel does not exist on this MPU.
 * @retval FSP_ERR_ASSERTION                      A required pointer was NULL.
 * @retval FSP_ERR_CAN_INIT_FAILED                The provided nominal or data bitrate is invalid.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Open (can_ctrl_t * const p_api_ctrl, can_cfg_t const * const p_cfg)
{
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;

#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_extend);
    FSP_ASSERT(p_cfg->p_callback);
    FSP_ASSERT(p_cfg->p_bit_timing);

    uint32_t channel = p_cfg->channel;

    /* Check that the module is not open, the channel is present and that it is not in use */
    FSP_ERROR_RETURN(CANFD_OPEN != p_ctrl->open, FSP_ERR_ALREADY_OPEN);
    FSP_ERROR_RETURN(channel < BSP_FEATURE_CANFD_NUM_CHANNELS * BSP_FEATURE_CANFD_NUM_INSTANCES,
                     FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(NULL == gp_ctrl[channel], FSP_ERR_IN_USE);

    /* Check that mandatory interrupts are enabled */
    FSP_ERROR_RETURN(CANFD_INTRCANGRECC_IRQn >= 0, FSP_ERR_CAN_INIT_FAILED);
    FSP_ERROR_RETURN(CANFD_INTRCANGERR_IRQn >= 0, FSP_ERR_CAN_INIT_FAILED);

    /* Check that the global config is present */
    canfd_extended_cfg_t * p_extend = (canfd_extended_cfg_t *) p_cfg->p_extend;
    FSP_ASSERT(p_extend->p_global_cfg);
    FSP_ASSERT(NULL != p_extend->p_reg);

    /* Check nominal bit timing parameters for correctness */
    FSP_ERROR_RETURN(r_canfd_bit_timing_parameter_check(p_cfg->p_bit_timing, false), FSP_ERR_CAN_INIT_FAILED);

 #if BSP_FEATURE_CANFD_FD_SUPPORT

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
 #endif
#else
    uint32_t channel = p_cfg->channel;

    /* Get extended config */
    canfd_extended_cfg_t * p_extend = (canfd_extended_cfg_t *) p_cfg->p_extend;
#endif

    fsp_err_t err = FSP_SUCCESS;

    /* Save the base register for this channel. */
    R_CANFD_Type * p_reg = p_extend->p_reg;
    p_ctrl->p_reg = p_reg;

    /* Initialize the control block */
    p_ctrl->p_cfg = p_cfg;

    /* Set callback and context pointers, if configured */
    p_ctrl->p_callback        = p_cfg->p_callback;
    p_ctrl->p_context         = p_cfg->p_context;
    p_ctrl->p_callback_memory = NULL;

    /* Get global config */
    canfd_global_cfg_t * p_global_cfg = p_extend->p_global_cfg;

    /* Start module */
#if BSP_FEATURE_CANFD_LITE
    R_BSP_MODULE_START(FSP_IP_CANFD, channel);
#else

    /* Start module */
    R_BSP_MODULE_START(FSP_IP_CANFD, 0);
#endif

    /* Perform global config only if the module is in Global Sleep or Global Reset */
#if BSP_FEATURE_CANFD_HAS_RSCANFD
 #if !BSP_FEATURE_CANFD_LITE
    if (p_reg->RSCFDnCFDGSTS & R_CANFD_RSCFDnCFDGSTS_GRSTSTS_Msk)
 #endif
    {
        /* Wait for RAM initialization (see section 'Initial Settings' of the hardware manual). */
        FSP_HARDWARE_REGISTER_WAIT((p_reg->RSCFDnCFDGSTS & R_CANFD_RSCFDnCFDGSTS_GRAMINIT_Msk), 0);

        /* Cancel Global Sleep and wait for transition to Global Reset */
        r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_RESET);

        /* Use CANFD Interface mode */
        p_reg->RSCFDnCFDGRMCFG_b.RCMC = 1;

        /* Cancel Channel Sleep and wait for transition to Channel Reset */
        r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_RESET);

        /* Configure global TX priority, DLC check/replace functions, external/internal clock select and payload
         * overflow behavior */
        p_reg->RSCFDnCFDGCFG = p_global_cfg->global_config;

        /* Configure rule count for both channels */
 #if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
        p_reg->RSCFDnCFDGAFLCFG0 = (CANFD_CFG_AFL_CH0_RULE_NUM << R_CANFD_RSCFDnCFDGAFLCFG0_RNC0_Pos);
 #else
        p_reg->RSCFDnCFDGAFLCFG0 = (CANFD_CFG_AFL_CH0_RULE_NUM << R_CANFD_RSCFDnCFDGAFLCFG0_RNC0_Pos) |
                                   (CANFD_CFG_AFL_CH1_RULE_NUM << R_CANFD_RSCFDnCFDGAFLCFG0_RNC1_Pos);
 #endif

        /* Set CAN FD Protocol Exception response (ISO exception state or send error frame) */
        p_reg->RSCFDnCFDGFDCFG = CANFD_CFG_FD_PROTOCOL_EXCEPTION;

        /* Set number and size of RX message buffers */
        p_reg->RSCFDnCFDRMNB = p_global_cfg->rx_mb_config;

        /* Configure RX FIFOs and interrupt */
        for (uint32_t i = 0; i < CANFD_PRV_RX_FIFO_MAX; i++)
        {
            uint32_t * rfcc_base = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFCC0 + 0x04 * i);
            *rfcc_base = p_global_cfg->rx_fifo_config[i];
        }

        R_BSP_IrqCfgEnable(CANFD_INTRCANGRECC_IRQn, p_global_cfg->rx_fifo_ipl, NULL);

        /* Set global error interrupts */
        uint32_t gctr = p_reg->RSCFDnCFDGCTR & R_CANFD_RSCFDnCFDGCTR_GMDC_Msk;
        p_reg->RSCFDnCFDGCTR = p_global_cfg->global_interrupts | gctr;

        /* Configure Common FIFOs */
        for (uint32_t i = 0; i < R_CANFD_NUM_COMMON_FIFOS; i++)
        {
            /* Configure the Common FIFOs. Mask out the enable bit because it can only be set once operating. */
            uint32_t * cfcc_base = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDCFCC0 + 0x04 * i);
            *cfcc_base = p_global_cfg->common_fifo_config[i] & (uint32_t) ~R_CANFD_RSCFDnCFDCFCC0_CFE_Msk;
        }
    }
    else
    {
        /* When other channel is already open and the global configuration is already set,
         * Only transition processing to Channel Reset is performed.
         * Cancel Channel Sleep and wait for transition to Channel Reset */
        r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_RESET);
    }
#endif

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
    if (CANFD_CFG_GLOBAL_ERROR_CH == channel)
#endif
    {
        /* Configure global error interrupt */
        R_BSP_IrqCfgEnable(CANFD_INTRCANGERR_IRQn, p_global_cfg->global_err_ipl, p_ctrl);
    }

    /* Track ctrl struct */
    gp_ctrl[channel] = p_ctrl;

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
#if BSP_FEATURE_CANFD_HAS_RSCANFD
    p_reg->RSCFDnCFDGAFLECTR = R_CANFD_RSCFDnCFDGAFLECTR_AFLDAE_Msk;
#endif

    /* Write all configured AFL entries */
    canfd_afl_entry_t const * p_afl = p_extend->p_afl;
    for ( ; afl_entry < afl_max; afl_entry++)
    {
        /* AFL register access is performed through a page window comprised of 16 entries. (see section
         * 'Data Processing Using the Receive Rule Table' of the hardware manual). for more details. */
#if BSP_FEATURE_CANFD_HAS_RSCANFD

        /* Set AFL page */
        p_reg->RSCFDnCFDGAFLECTR = (afl_entry >> 4) | R_CANFD_RSCFDnCFDGAFLECTR_AFLDAE_Msk;

        /* Get pointer to current AFL rule and set it to the rule pointed to by p_afl */
        uint32_t * gaflid_base = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDGAFLID0 + 0x10 * (afl_entry & 0xF));
        uint32_t * gaflm_base  = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDGAFLM0 + 0x10 * (afl_entry & 0xF));
        uint32_t * gaflp0_base = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDGAFLP0_0 + 0x10 * (afl_entry & 0xF));
        uint32_t * gaflp1_base = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDGAFLP1_0 + 0x10 * (afl_entry & 0xF));

        *gaflid_base = p_afl->id_u32;
        *gaflm_base  = p_afl->mask_u32;

        uint32_t afl_rxbuffer   = p_afl->destination_u32[0] & CANFD_PRV_AFL_RX_BUFFER_MASK;
        uint32_t afl_minimumdlc = p_afl->destination_u32[0] & CANFD_PRV_AFL_MINIMUM_DLC_MASK;

        *gaflp0_base = afl_rxbuffer | (afl_minimumdlc << CANFD_PRV_AFL_MINIMUM_DLC_POS);
        *gaflp1_base = p_afl->destination_u32[1];

        /* Set Information Label 0 to the channel being configured */
        *gaflp0_base &= (uint32_t) ~R_CANFD_RSCFDnCFDGAFLP0_0_GAFLPTR_Msk;
        *gaflp0_base |= (p_cfg->channel & 1U) << R_CANFD_RSCFDnCFDGAFLP0_0_GAFLPTR_Pos;

        p_afl++;
#endif
    }

    /* Lock AFL */
#if BSP_FEATURE_CANFD_HAS_RSCANFD
    p_reg->RSCFDnCFDGAFLECTR = 0;
#endif

    uint32_t interlaced_channel = CANFD_INTER_CH(channel);

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Configure bitrate */
    volatile uint32_t * cfdcncfg_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_reg->RSCFDnCFDC0NCFG,
        &p_reg->RSCFDnCFDC1NCFG
    };

    *(cfdcncfg_base[p_cfg->channel]) =
        (uint32_t) (((p_cfg->p_bit_timing->baud_rate_prescaler - 1) & R_CANFD_RSCFDnCFDC0NCFG_NBRP_Msk) <<
                    R_CANFD_RSCFDnCFDC0NCFG_NBRP_Pos) |
        ((p_cfg->p_bit_timing->time_segment_1 - 1U) << R_CANFD_RSCFDnCFDC0NCFG_NTSEG1_Pos) |
        ((p_cfg->p_bit_timing->time_segment_2 - 1U) << R_CANFD_RSCFDnCFDC0NCFG_NTSEG2_Pos) |
        ((p_cfg->p_bit_timing->synchronization_jump_width - 1U) << R_CANFD_RSCFDnCFDC0NCFG_NSJW_Pos);

 #if BSP_FEATURE_CANFD_FD_SUPPORT

    /* Configure data bitrate for rate switching on FD frames */
    volatile uint32_t * cfdcdcfg_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_reg->RSCFDnCFDC0DCFG,
        &p_reg->RSCFDnCFDC1DCFG
    };

    *(cfdcdcfg_base[p_cfg->channel]) =
        (uint32_t) (((p_extend->p_data_timing->baud_rate_prescaler - 1) & R_CANFD_RSCFDnCFDC0DCFG_DBRP_Msk) <<
                    R_CANFD_RSCFDnCFDC0DCFG_DBRP_Pos) |
        ((p_extend->p_data_timing->time_segment_1 - 1U) << R_CANFD_RSCFDnCFDC0DCFG_DTSEG1_Pos) |
        ((p_extend->p_data_timing->time_segment_2 - 1U) << R_CANFD_RSCFDnCFDC0DCFG_DTSEG2_Pos) |
        ((p_extend->p_data_timing->synchronization_jump_width - 1U) << R_CANFD_RSCFDnCFDC0DCFG_DSJW_Pos);

    /* Ensure transceiver delay offset is not larger than 8 bits */
    uint32_t tdco = p_extend->p_data_timing->time_segment_1;
    if (tdco > UINT8_MAX)
    {
        tdco = UINT8_MAX;
    }

    /* Configure transceiver delay compensation; allow user to set ESI bit manually */
    volatile uint32_t * cfdcfdcfd_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_reg->RSCFDnCFDC0FDCFG,
        &p_reg->RSCFDnCFDC1FDCFG
    };

    *(cfdcfdcfd_base[p_cfg->channel]) =
        (uint32_t) (p_extend->txmb_merge_mode_enable << R_CANFD_RSCFDnCFDC0FDCFG_TMME_Pos) |
        (tdco << R_CANFD_RSCFDnCFDC0FDCFG_TDCO_Pos) |
        (uint32_t) (p_extend->delay_compensation << R_CANFD_RSCFDnCFDC0FDCFG_TDCE_Pos) |
        R_CANFD_RSCFDnCFDC0FDCFG_ESIC_Msk | 1U;
 #endif

    /* Write TX message buffer interrupt enable bits */
    volatile uint16_t * cfdtmiec_base[BSP_FEATURE_CANFD_NUM_CHANNELS * CANFD_PRV_CFDTMIEC_LENGTH] =
    {
        &p_reg->RSCFDnCFDTMIEC0_hword.L,
        &p_reg->RSCFDnCFDTMIEC0_hword.H
    };

    *(cfdtmiec_base[p_cfg->channel]) = (uint16_t) p_extend->txmb_txi_enable;

    /* Configure channel error interrupts */
    volatile uint32_t * cfdcctr_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_reg->RSCFDnCFDC0CTR,
        &p_reg->RSCFDnCFDC1CTR
    };
    *(cfdcctr_base[interlaced_channel]) = p_extend->error_interrupts | R_CANFD_RSCFDnCFDC0CTR_CHMDC_Msk;
#endif

    /* Enable channel interrupts */
    if (p_cfg->error_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->error_irq, p_cfg->ipl, p_ctrl);
    }

    if (p_cfg->tx_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->tx_irq, p_cfg->ipl, p_ctrl);
    }

    /* Use the CAN RX IRQ for Common FIFO RX. */
    if (p_cfg->rx_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->rx_irq, p_cfg->ipl, p_ctrl);
    }

    /* Set global mode to Operation and wait for transition */
    r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_OPERATION);

    /* Transition to Channel Operation */
    r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_NORMAL);

    /* Set current operation modes */
    p_ctrl->operation_mode = CAN_OPERATION_MODE_NORMAL;
    p_ctrl->test_mode      = CAN_TEST_MODE_DISABLED;

    /* Set driver to open */
    p_ctrl->open = CANFD_OPEN;

    return err;
}

/***************************************************************************************************************//**
 * Close the CANFD channel.
 *
 * @retval FSP_SUCCESS               Channel closed successfully.
 * @retval FSP_ERR_NOT_OPEN          Control block not open.
 * @retval FSP_ERR_ASSERTION         Null pointer presented.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Close (can_ctrl_t * const p_api_ctrl)
{
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;

#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);
#endif

    /* Set driver to closed */
    p_ctrl->open = 0U;

    /* Get config struct */
    can_cfg_t * p_cfg = (can_cfg_t *) p_ctrl->p_cfg;

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
#if !BSP_FEATURE_CANFD_LITE
    if (CANFD_CFG_GLOBAL_ERROR_CH == p_cfg->channel)
#elif BSP_FEATURE_CANFD_NUM_INSTANCES > 1

    /* Only disable the Global Error interrupt if both channels are closed. */
    if (NULL == gp_ctrl[!p_cfg->channel])
#endif
    {
        R_BSP_IrqDisable(CANFD_INTRCANGERR_IRQn);

#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

        /* Disable RX FIFO interrupt */
        R_BSP_IrqDisable(VECTOR_NUMBER_CAN_RXF);
#endif
    }

#if !BSP_FEATURE_CANFD_LITE

    /* Set channel to Sleep if other is open, otherwise reset/stop CANFD module */
    if (gp_ctrl[!p_cfg->channel])
    {
        r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_SLEEP);
    }
    else
#endif
    {
#if BSP_FEATURE_CANFD_NUM_INSTANCES == 1

        /* Disable RX FIFO interrupt */
        R_BSP_IrqDisable(CANFD_INTRCANGRECC_IRQn);
#endif

        /* Transition to Global Sleep */
        r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_RESET);
        r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_GLOBAL_SLEEP);

        /* Stop CANFD module */
#if BSP_FEATURE_CANFD_LITE
        R_BSP_MODULE_STOP(FSP_IP_CANFD, p_cfg->channel);
#else
        R_BSP_MODULE_STOP(FSP_IP_CANFD, 0);
#endif
    }

    /* Reset global control struct pointer */
    gp_ctrl[p_cfg->channel] = NULL;

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Write data to the CANFD channel.
 *
 * Example:
 * @snippet rza_r_canfd_example.c R_CANFD_Write
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_CAN_TRANSMIT_NOT_READY   Transmit in progress, cannot write data at this time.
 * @retval FSP_ERR_INVALID_ARGUMENT         Data length or buffer number invalid.
 * @retval FSP_ERR_INVALID_MODE             An FD option was set on a non-FD frame.
 * @retval FSP_ERR_ASSERTION                One or more pointer arguments is NULL.
 * @retval FSP_ERR_UNSUPPORTED              FD is not supported on this MPU.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Write (can_ctrl_t * const p_api_ctrl, uint32_t buffer, can_frame_t * const p_frame)
{
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;

    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_frame);
    FSP_ERROR_RETURN(p_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);

 #if !BSP_FEATURE_CANFD_LITE

    /* CANFD channels have 16 TX message buffers + 3 common FIFOs each (0-15, 16-18) */
    FSP_ERROR_RETURN((buffer <= 15U) ||
                     (buffer - (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0 <= 2U),
                     FSP_ERR_INVALID_ARGUMENT);
 #else

    /* CANFD Lite has 4 TX message buffers + 1 common FIFO */
    FSP_ERROR_RETURN((buffer <= 3U) ||
                     (buffer - (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0 <= 0U),
                     FSP_ERR_INVALID_ARGUMENT);
 #endif

    /* Check DLC field */
 #if BSP_FEATURE_CANFD_FD_SUPPORT
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
    FSP_ERROR_RETURN(p_frame->data_length_code <= 8, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_frame->options == 0, FSP_ERR_UNSUPPORTED);
 #endif
#else
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;
#endif

    uint32_t interlaced_channel = CANFD_INTER_CH(p_ctrl->p_cfg->channel);

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Provide variables to store common values. */
    const bool is_cfifo    = buffer >= (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0;
    uint8_t  * p_dest      = NULL;
    uint8_t  * tmc_base    = NULL;
    uint32_t * cfpctr_base = NULL;

    if (!is_cfifo)
    {
        /* Calculate global TX message buffer number */
        uint32_t buffer_idx = buffer + (interlaced_channel * CANFD_PRV_TXMB_CHANNEL_OFFSET);

        tmc_base = (uint8_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMC0) + buffer_idx);
        uint8_t * cfdtmsts_base = (uint8_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMSTS0) + buffer_idx);

        uintptr_t tmid_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMID1) -
                                     (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMID0);
        uint32_t * tmid_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMID0) + tmid_address_gap * buffer_idx);

        uintptr_t tmptr_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMPTR1) -
                                      (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMPTR0);
        uint32_t * tmptr_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMPTR0) + tmptr_address_gap * buffer_idx);

        uintptr_t tmfdctr_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMFDCTR1) -
                                        (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMFDCTR0);
        uint32_t * tmfdctr_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMFDCTR0) + tmfdctr_address_gap * buffer_idx);

        uintptr_t tmdf_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMDF0_1) -
                                     (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMDF0_0);
        uint32_t * tmdf_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDTMDF0_0) + tmdf_address_gap * buffer_idx);

        /* Ensure MB is ready */
        FSP_ERROR_RETURN(0U ==
                         (((*cfdtmsts_base) & R_CANFD_RSCFDnCFDTMSTS0_TMTRM_Msk) >> R_CANFD_RSCFDnCFDTMSTS0_TMTRM_Pos),
                         FSP_ERR_CAN_TRANSMIT_NOT_READY);

        /* Set ID */
        *tmid_base = p_frame->id | ((uint32_t) p_frame->type << R_CANFD_RSCFDnCFDTMID0_TMRTR_Pos) |
                     ((uint32_t) p_frame->id_mode << R_CANFD_RSCFDnCFDTMID0_TMIDE_Pos);

 #if BSP_FEATURE_CANFD_FD_SUPPORT

        /* Set DLC */
        *tmptr_base = (uint32_t) r_canfd_bytes_to_dlc(p_frame->data_length_code) << R_CANFD_RSCFDnCFDTMPTR0_TMDLC_Pos;

        /* Set FD bits (ESI, BRS and FDF) */
        *tmfdctr_base = p_frame->options & 7U;
 #else

        /* Set DLC */
        *tmptr_base = (uint32_t) p_frame->data_length_code << R_CANFD_RSCFDnCFDTMPTR0_TMDLC_Pos;
 #endif
        p_dest = (uint8_t *) tmdf_base;
    }
    else
    {
        /* Calculate the Common FIFO index. */
        uint32_t buffer_idx = buffer - (uint32_t) CANFD_TX_BUFFER_FIFO_COMMON_0 +
                              (interlaced_channel * CANFD_PRV_CFIFO_CHANNEL_OFFSET);

        uintptr_t cfpctr_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFPCTR1) -
                                       (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFPCTR0);
        cfpctr_base = (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFPCTR0) + cfpctr_address_gap * buffer_idx);

        uintptr_t cfid_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFID1) -
                                     (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFID0);
        uint32_t * cfid_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFID0) + cfid_address_gap * buffer_idx);

        uintptr_t cfptr_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFPTR1) -
                                      (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFPTR0);
        uint32_t * cfptr_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFPTR0) + cfptr_address_gap * buffer_idx);

        uintptr_t cffdcsts_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFFDCSTS1) -
                                         (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFFDCSTS0);
        uint32_t * cffdcsts_base = (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFFDCSTS0) +
                                                 cffdcsts_address_gap * buffer_idx);

        uintptr_t cfdf_address_gap = (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFDF0_1) -
                                     (uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFDF0_0);
        uint32_t * cfdf_base =
            (uint32_t *) ((uintptr_t) (&p_ctrl->p_reg->RSCFDnCFDCFDF0_0) + cfdf_address_gap * buffer_idx);

        /* Set ID */
        *cfid_base = p_frame->id | ((uint32_t) p_frame->type << R_CANFD_RSCFDnCFDCFID0_CFRTR_Pos) |
                     ((uint32_t) p_frame->id_mode << R_CANFD_RSCFDnCFDCFID0_CFIDE_Pos);

 #if BSP_FEATURE_CANFD_FD_SUPPORT

        /* Set DLC */
        *cfptr_base = (uint32_t) r_canfd_bytes_to_dlc(p_frame->data_length_code) << R_CANFD_RSCFDnCFDCFPTR0_CFDLC_Pos;

        /* Set FD bits (ESI, BRS and FDF) */
        *cffdcsts_base = p_frame->options & 7U;
 #else

        /* Set DLC */
        *cfptr_base = (uint32_t) p_frame->data_length_code << R_CANFD_RSCFDnCFDCFPTR0_CFDLC_Pos;
 #endif

        /* Store the data poitner. */
        p_dest = (uint8_t *) cfdf_base;
    }
#endif

    /* Copy data to register buffer */
    uint32_t  len   = p_frame->data_length_code;
    uint8_t * p_src = p_frame->data;
    while (len--)
    {
        *p_dest++ = *p_src++;
    }

    if (!is_cfifo)
    {
        /* Request transmission */
        *tmc_base = 1;
    }
    else
    {
        /* Increment the Common FIFO pointer by writing 0xFF to CFPCTR. */
        *cfpctr_base = UINT8_MAX;
    }

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Read data from a CANFD Message Buffer or FIFO.
 *
 * Example:
 * snippet rza_r_canfd_example.c R_CANFD_Read
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_INVALID_ARGUMENT         Buffer number invalid.
 * @retval FSP_ERR_ASSERTION                p_api_ctrl or p_frame is NULL.
 * @retval FSP_ERR_BUFFER_EMPTY             Buffer or FIFO is empty.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_Read (can_ctrl_t * const p_api_ctrl, uint32_t buffer, can_frame_t * const p_frame)
{
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_frame);
    FSP_ERROR_RETURN(p_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((buffer < CANFD_PRV_RXMB_MAX + CANFD_PRV_RX_FIFO_MAX) ||
                     ((buffer >= CANFD_RX_BUFFER_FIFO_COMMON_0) &&
                      (buffer < CANFD_RX_BUFFER_FIFO_COMMON_0 + CANFD_PRV_COMMON_FIFO_MAX)),
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    uint32_t not_empty;

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Return an error if the buffer or FIFO is empty */
    if (buffer < CANFD_PRV_RXMB_MAX)
    {
        not_empty = p_ctrl->p_reg->RSCFDnCFDRMND0 & (1U << buffer);
    }
    else if (buffer < (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0)
    {
        not_empty = !(p_ctrl->p_reg->RSCFDnCFDFESTS & (1U << (buffer - CANFD_PRV_RXMB_MAX)));
    }
    else
    {
        /* Common FIFO status are grouped together and not channelized, so calculate the index based on the channel. */
        const uint32_t cfifo_idx = CANFD_PRV_CFIFO_INDEX(buffer - (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0,
                                                         CANFD_INTER_CH(p_ctrl->p_cfg->channel));

        /* Update the buffer to be effectively the cfifo index calculated above. */
        /* This is needed since r_canfd_mb_read(...) doesn't take a channel number. */
        buffer = cfifo_idx + (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0;

        not_empty = (~p_ctrl->p_reg->RSCFDnCFDFESTS & (1U << (R_CANFD_RSCFDnCFDFESTS_CF0EMP_Pos + cfifo_idx))) != 0;
    }
#endif

    FSP_ERROR_RETURN(not_empty, FSP_ERR_BUFFER_EMPTY);

    /* Retrieve message from buffer */
    r_canfd_mb_read(p_ctrl->p_reg, buffer, p_frame);

    return FSP_SUCCESS;
}

/***************************************************************************************************************//**
 * Switch to a different channel, global or test mode.
 *
 * Example:
 * @snippet rza_r_canfd_example.c R_CANFD_ModeTransition
 *
 * @retval FSP_SUCCESS                      Operation succeeded.
 * @retval FSP_ERR_NOT_OPEN                 Control block not open.
 * @retval FSP_ERR_ASSERTION                Null pointer presented
 * @retval FSP_ERR_INVALID_MODE             Cannot change to the requested mode from the current global mode.
 *****************************************************************************************************************/
fsp_err_t R_CANFD_ModeTransition (can_ctrl_t * const   p_api_ctrl,
                                  can_operation_mode_t operation_mode,
                                  can_test_mode_t      test_mode)
{
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t               err    = FSP_SUCCESS;
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);

    /* Get Global Status */
 #if BSP_FEATURE_CANFD_HAS_RSCANFD
    uint32_t cfdgsts = p_ctrl->p_reg->RSCFDnCFDGSTS;
 #endif

 #if !BSP_FEATURE_CANFD_LITE

    /* Check to ensure the current mode is Global Halt when transitioning into or out of Internal Bus mode */
  #if BSP_FEATURE_CANFD_HAS_RSCANFD
    FSP_ERROR_RETURN((cfdgsts & R_CANFD_RSCFDnCFDGSTS_GHLTSTS_Msk) || !((p_ctrl->test_mode != test_mode) &&
                                                                        ((CAN_TEST_MODE_INTERNAL_BUS ==
                                                                          p_ctrl->test_mode) ||
                                                                         (CAN_TEST_MODE_INTERNAL_BUS == test_mode))),
                     FSP_ERR_INVALID_MODE);
  #endif
 #else

    /* Internal Bus mode is not supported on this MPU */
    FSP_ERROR_RETURN(CAN_TEST_MODE_INTERNAL_BUS != test_mode, FSP_ERR_INVALID_MODE);
 #endif

    /* Check to ensure the current mode is Global Reset when transitioning into or out of Global Sleep (see Section
     * "Global Modes" in the Hardware Manual for details) */
 #if BSP_FEATURE_CANFD_HAS_RSCANFD
    FSP_ERROR_RETURN(((cfdgsts & R_CANFD_RSCFDnCFDGSTS_GRSTSTS_Msk) && (CAN_OPERATION_MODE_RESET & operation_mode)) ||
                     (!(cfdgsts & R_CANFD_RSCFDnCFDGSTS_GSLPSTS_Msk) &&
                      (CAN_OPERATION_MODE_GLOBAL_SLEEP != operation_mode)),
                     FSP_ERR_INVALID_MODE);
 #endif

    /* Check to ensure the current Global mode supports the requested Channel mode, if applicable. The requested mode
     * and the current global mode are converted into a number 0-3 corresponding to Operation, Halt, Reset and Sleep
     * respectively. The channel mode cannot be switched to a mode with an index lower than the current global mode. */
    if (operation_mode < CAN_OPERATION_MODE_GLOBAL_OPERATION)
    {
        FSP_ERROR_RETURN(g_mode_order[operation_mode] >= g_mode_order[cfdgsts & CANFD_PRV_CTR_MODE_MASK],
                         FSP_ERR_INVALID_MODE);
    }
#endif

    uint32_t interlaced_channel = CANFD_INTER_CH(p_ctrl->p_cfg->channel);

#if BSP_FEATURE_CANFD_HAS_RSCANFD
    volatile uint32_t * cfdcctr_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_ctrl->p_reg->RSCFDnCFDC0CTR,
        &p_ctrl->p_reg->RSCFDnCFDC1CTR
    };

    if (p_ctrl->test_mode != test_mode)
    {
 #if !BSP_FEATURE_CANFD_LITE

        /* Follow the procedure for switching to Internal Bus mode given in Section "Inter-Channel
         * Communication Test Setting Procedure" of the Hardware Manual */
        if (CAN_TEST_MODE_INTERNAL_BUS == test_mode)
        {
            /* Disable channel test mode */
            *(cfdcctr_base[interlaced_channel]) &= (uint32_t) ~R_CANFD_RSCFDnCFDC0CTR_CTME_Msk;

            /* Link channel to internal bus */
            p_ctrl->p_reg->RSCFDnCFDGTSTCFG |= 1U << interlaced_channel;

            /* Enable internal bus test mode */
            p_ctrl->p_reg->RSCFDnCFDGTSTCTR = 1;
        }
        else
 #endif
        {
 #if !BSP_FEATURE_CANFD_LITE
            if (p_ctrl->test_mode == CAN_TEST_MODE_INTERNAL_BUS)
            {
                /* Unlink channel from internal bus */
                p_ctrl->p_reg->RSCFDnCFDGTSTCFG &= ~(1U << interlaced_channel);

                /* Disable global test mode if no channels are linked */
                if (!p_ctrl->p_reg->RSCFDnCFDGTSTCFG)
                {
                    p_ctrl->p_reg->RSCFDnCFDGTSTCTR = 0;
                }
            }
 #endif

            /* Transition to Channel Halt when changing test modes */
            r_canfd_mode_transition(p_ctrl, CAN_OPERATION_MODE_HALT);

            /* Set channel test mode */
            uint32_t cfdcnctr = *(cfdcctr_base[interlaced_channel]);
            cfdcnctr &= (uint32_t) ~(R_CANFD_RSCFDnCFDC0CTR_CTME_Msk | R_CANFD_RSCFDnCFDC0CTR_CTMS_Msk);
            *(cfdcctr_base[interlaced_channel]) = cfdcnctr | ((uint32_t) test_mode << R_CANFD_RSCFDnCFDC0CTR_CTME_Pos);
        }

        p_ctrl->test_mode = test_mode;
    }
#endif

    if (p_ctrl->operation_mode != operation_mode)
    {
        r_canfd_mode_transition(p_ctrl, operation_mode);
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
fsp_err_t R_CANFD_InfoGet (can_ctrl_t * const p_api_ctrl, can_info_t * const p_info)
{
#if CANFD_CFG_PARAM_CHECKING_ENABLE
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;

    /* Check pointers for NULL values */
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_info);

    /* If channel is not open, return an error */
    FSP_ERROR_RETURN(p_ctrl->open == CANFD_OPEN, FSP_ERR_NOT_OPEN);
#else
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;
#endif

    uint32_t interlaced_channel = CANFD_INTER_CH(p_ctrl->p_cfg->channel);

#if BSP_FEATURE_CANFD_HAS_RSCANFD
    volatile uint32_t * cfdcsts_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_ctrl->p_reg->RSCFDnCFDC0STS,
        &p_ctrl->p_reg->RSCFDnCFDC1STS
    };
    volatile uint32_t * cfdcerfl_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_ctrl->p_reg->RSCFDnCFDC0ERFL,
        &p_ctrl->p_reg->RSCFDnCFDC1ERFL
    };

    uint32_t cfdcnsts = *(cfdcsts_base[interlaced_channel]);

    p_info->status              = cfdcnsts & UINT16_MAX;
    p_info->error_count_receive =
        (uint8_t) ((cfdcnsts & R_CANFD_RSCFDnCFDC0STS_RECSTS_Msk) >> R_CANFD_RSCFDnCFDC0STS_RECSTS_Pos);
    p_info->error_count_transmit =
        (uint8_t) ((cfdcnsts & R_CANFD_RSCFDnCFDC0STS_TEC_Msk) >> R_CANFD_RSCFDnCFDC0STS_TEC_Pos);
    p_info->error_code     = *(cfdcerfl_base[interlaced_channel]) & UINT16_MAX;
    p_info->rx_mb_status   = p_ctrl->p_reg->RSCFDnCFDRMND0;
    p_info->rx_fifo_status = (~p_ctrl->p_reg->RSCFDnCFDFESTS) &
                             (CANFD_PRV_CFDFESTS_RFXEMP_Msk | CANFD_PRV_CFDFESTS_CFXEMP_Msk);
#endif

    /* Clear error flags if the error IRQ is not enabled. */
    if (p_ctrl->p_cfg->error_irq < 0)
    {
        *(cfdcerfl_base[interlaced_channel]) = 0;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref can_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_NO_CALLBACK_MEMORY   p_callback is non-secure and p_callback_memory is either secure or NULL.
 **********************************************************************************************************************/
fsp_err_t R_CANFD_CallbackSet (can_ctrl_t * const          p_api_ctrl,
                               void (                    * p_callback)(can_callback_args_t *),
                               void * const                p_context,
                               can_callback_args_t * const p_callback_memory)
{
    canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) p_api_ctrl;

#if CANFD_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(CANFD_OPEN == p_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

#if BSP_TZ_SECURE_BUILD

    /* Get security state of p_callback */
    bool callback_is_secure =
        (NULL == cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE));

 #if CANFD_CFG_PARAM_CHECKING_ENABLE

    /* In secure projects, p_callback_memory must be provided in non-secure space if p_callback is non-secure */
    can_callback_args_t * const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory,
                                                                                      CMSE_AU_NONSECURE);
    FSP_ERROR_RETURN(callback_is_secure || (NULL != p_callback_memory_checked), FSP_ERR_NO_CALLBACK_MEMORY);
 #endif
#endif

    /* Store callback and context */
#if BSP_TZ_SECURE_BUILD
    p_ctrl->p_callback = callback_is_secure ? p_callback :
                         (void (*)(can_callback_args_t *))cmse_nsfptr_create(p_callback);
#else
    p_ctrl->p_callback = p_callback;
#endif
    p_ctrl->p_context         = p_context;
    p_ctrl->p_callback_memory = p_callback_memory;

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

    /* Check that TSEG1 > TSEG2 >= SJW for nominal bitrate
     * (see section "Bit Timing Setting" in the Hardware Manual.) */

 #if BSP_FEATURE_CANFD_FD_SUPPORT
    if (is_data_phase)
    {
        /* Check Time Segment 1 is greater than or equal to Time Segment 2 */
        FSP_ERROR_RETURN((uint32_t) p_bit_timing->time_segment_1 >= (uint32_t) p_bit_timing->time_segment_2, false);
    }
    else
 #else

    /* Data phase is only avaiable for FD mode. */
    FSP_PARAMETER_NOT_USED(is_data_phase);
 #endif
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
    bool       is_mb    = buffer < CANFD_PRV_RXMB_MAX;
    const bool is_cfifo = buffer >= (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0;

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Get pointer to message buffer (FIFOs use the same buffer structure) */
    uintptr_t rmid_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRMID1) - (uintptr_t) (&p_reg->RSCFDnCFDRMID0);
    uintptr_t rfid_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRFID1) - (uintptr_t) (&p_reg->RSCFDnCFDRFID0);
    uintptr_t cfid_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDCFID1) - (uintptr_t) (&p_reg->RSCFDnCFDCFID0);

    uint32_t * id_base = (is_mb) ?
                         (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRMID0 + rmid_address_gap * buffer) :
                         (is_cfifo) ?
                         (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDCFID0 + cfid_address_gap *
                                       (buffer - CANFD_RX_BUFFER_FIFO_COMMON_0)) :
                         (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFID0 + rfid_address_gap *
                                       (buffer - CANFD_PRV_RXMB_MAX));

    uintptr_t rmfdsts_address_gap  = (uintptr_t) (&p_reg->RSCFDnCFDRMFDSTS1) - (uintptr_t) (&p_reg->RSCFDnCFDRMFDSTS0);
    uintptr_t rffdsts_address_gap  = (uintptr_t) (&p_reg->RSCFDnCFDRFFDSTS1) - (uintptr_t) (&p_reg->RSCFDnCFDRFFDSTS0);
    uintptr_t cffdcsts_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDCFFDCSTS1) -
                                     (uintptr_t) (&p_reg->RSCFDnCFDCFFDCSTS0);

    uint32_t * fdsts_base = (is_mb) ?
                            (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRMFDSTS0 + rmfdsts_address_gap * buffer) :
                            (is_cfifo) ?
                            (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDCFFDCSTS0 + cffdcsts_address_gap *
                                          (buffer - CANFD_RX_BUFFER_FIFO_COMMON_0)) :
                            (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFFDSTS0 + rffdsts_address_gap *
                                          (buffer - CANFD_PRV_RXMB_MAX));

    uintptr_t rmptr_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRMPTR1) - (uintptr_t) (&p_reg->RSCFDnCFDRMPTR0);
    uintptr_t rfptr_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRFPTR1) - (uintptr_t) (&p_reg->RSCFDnCFDRFPTR0);
    uintptr_t cfptr_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDCFPTR1) - (uintptr_t) (&p_reg->RSCFDnCFDCFPTR0);

    uint32_t * ptr_base = (is_mb) ?
                          (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRMPTR0 + rmptr_address_gap * buffer) :
                          (is_cfifo) ?
                          (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDCFPTR0 + cfptr_address_gap *
                                        (buffer - CANFD_RX_BUFFER_FIFO_COMMON_0)) :
                          (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFPTR0 + rfptr_address_gap *
                                        (buffer - CANFD_PRV_RXMB_MAX));

    uintptr_t rmdf_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRMDF0_1) - (uintptr_t) (&p_reg->RSCFDnCFDRMDF0_0);
    uintptr_t rfdf_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRFDF0_1) - (uintptr_t) (&p_reg->RSCFDnCFDRFDF0_0);
    uintptr_t cfdf_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDCFDF0_1) - (uintptr_t) (&p_reg->RSCFDnCFDCFDF0_0);

    uint32_t * df_base = (is_mb) ?
                         (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRMDF0_0 + rmdf_address_gap * buffer) :
                         (is_cfifo) ?
                         (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDCFDF0_0 + cfdf_address_gap *
                                       (buffer - CANFD_RX_BUFFER_FIFO_COMMON_0)) :
                         (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFDF0_0 + rfdf_address_gap *
                                       (buffer - CANFD_PRV_RXMB_MAX));

    /* Get frame data. */
    uint32_t id = *id_base;

    /* Get the frame type */
    frame->type = (can_frame_type_t) ((id & R_CANFD_RSCFDnCFDRMID0_RMRTR_Msk) >> R_CANFD_RSCFDnCFDRMID0_RMRTR_Pos);

 #if BSP_FEATURE_CANFD_FD_SUPPORT

    /* Get FD status bits (ESI, BRS and FDF) */
    frame->options = (*fdsts_base) & 7U;
 #else
    frame->options = 0U;
 #endif

    /* Get the frame ID */
    frame->id = id & CANFD_PRV_RMID_MASK;

    /* Get the frame ID mode (IDE bit) */
    frame->id_mode = (can_id_mode_t) (id >> CANFD_PRV_RMIDE_POSITION);

    /* Get the frame data length code */
    frame->data_length_code = dlc_to_bytes[(*ptr_base) >> R_CANFD_RSCFDnCFDRMPTR0_RMDLC_Pos];

    /* Copy data to frame */
    uint32_t  len    = frame->data_length_code;
    uint8_t * p_dest = frame->data;
    uint8_t * p_src  = (uint8_t *) df_base;
    while (len--)
    {
        *p_dest++ = *p_src++;
    }

    if (is_mb)
    {
        /* Clear RXMB New Data bit */
        p_reg->RSCFDnCFDRMND0 &= ~(1U << buffer);
    }
    else if (is_cfifo)
    {
        /* Increment the Common FIFO pointer. */
        uint32_t * cfpctr_base =
            (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDCFPCTR0 + 0x04 * (buffer - CANFD_RX_BUFFER_FIFO_COMMON_0));
        *cfpctr_base = UINT8_MAX;
    }
    else
    {
        /* Increment RX FIFO pointer */
        uint32_t * rfpctr_base =
            (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFPCTR0 + 0x04 * (buffer - CANFD_PRV_RXMB_MAX));
        *rfpctr_base = UINT8_MAX;
    }
#endif
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_ctrl     Pointer to CAN instance control block
 * @param[in]     p_args     Pointer to arguments on stack
 **********************************************************************************************************************/
static void r_canfd_call_callback (canfd_instance_ctrl_t * p_ctrl, can_callback_args_t * p_args)
{
    can_callback_args_t args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    can_callback_args_t * p_args_memory = p_ctrl->p_callback_memory;
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
        canfd_prv_ns_callback p_callback = (canfd_prv_ns_callback) (p_ctrl->p_callback);
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
 * Global Error Handler.
 *
 * Handles the Global Error IRQ for a given instance of CANFD.
 **********************************************************************************************************************/
static void r_canfd_global_error_handler (uint32_t instance)
{
    canfd_instance_ctrl_t * p_ctrl = gp_ctrl[instance];

    can_callback_args_t args = {0U};

    args.event = CAN_EVENT_ERR_GLOBAL;

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Read global error flags. */
    uint32_t cfdgerfl = p_ctrl->p_reg->RSCFDnCFDGERFL;

    /* Global errors are in the top halfword of canfd_error_t; move and preserve ECC error flags. */
    args.error = ((cfdgerfl & UINT16_MAX) << 16) + ((cfdgerfl >> 16) << 28);

    /* Clear global error flags. */
    p_ctrl->p_reg->RSCFDnCFDGERFL = 0;

    if (args.error & CANFD_ERROR_GLOBAL_MESSAGE_LOST)
    {
        /* Get lowest RX FIFO with Message Lost condition and clear the flag */
        uint32_t buffer_mask_result = 0;
        uint32_t shift_count        = CANFD_PRV_RX_FIFO_MAX;
        while (0U == buffer_mask_result)
        {
            /* Decrement shift count until a flag is found in the mask. */
            shift_count--;
            buffer_mask_result = (uint32_t) (p_ctrl->p_reg->RSCFDnCFDFMSTS & (1U << shift_count));
        }

        ;

        args.buffer = shift_count;

        uint32_t * rfsts_base = (uint32_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDRFSTS0 + 0x04 * args.buffer);
        *rfsts_base &= (uint32_t) ~R_CANFD_RSCFDnCFDRFSTS0_RFMLT_Msk;
    }
#endif

    /* Set channel and context based on selected global error handler channel. */
    args.channel   = CANFD_CFG_GLOBAL_ERROR_CH;
    args.p_context = p_ctrl->p_context;

    /* Set remaining arguments and call callback */
    r_canfd_call_callback(p_ctrl, &args);
}

/*******************************************************************************************************************//**
 * Error ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common error function, and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_error_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    /* Get IRQ and context */

    if (CANFD_INTRCANGERR_IRQn == irq)
    {
#if BSP_FEATURE_CANFD_NUM_INSTANCES > 1

        /* If there are seperate instances of CANFD, then loop over each instance to handle the source of the global
         * error IRQ. */
        for (uint32_t i = 0; i < BSP_FEATURE_CANFD_NUM_INSTANCES; i++)
        {
            if (NULL != gp_ctrl[i])
            {
                r_canfd_global_error_handler(i);
            }
        }

#else
        r_canfd_global_error_handler(CANFD_CFG_GLOBAL_ERROR_CH);
#endif
    }
    else
    {
        canfd_instance_ctrl_t * p_ctrl = (canfd_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

        can_callback_args_t     args = {0U};
        canfd_instance_ctrl_t * p_callback_ctrl;

#if BSP_FEATURE_CANFD_HAS_RSCANFD
        volatile uint32_t * cfdcerfl_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
        {
            &p_ctrl->p_reg->RSCFDnCFDC0ERFL,
            &p_ctrl->p_reg->RSCFDnCFDC1ERFL
        };
#endif

        args.event = CAN_EVENT_ERR_CHANNEL;

        /* Read and clear channel error flags. */
        uint32_t interlaced_channel = CANFD_INTER_CH(p_ctrl->p_cfg->channel);
        args.error = *(cfdcerfl_base[p_ctrl->p_cfg->channel]) & UINT16_MAX;
        *(cfdcerfl_base[p_ctrl->p_cfg->channel]) = 0;

        /* Choose the channel provided by the interrupt context. */
        p_callback_ctrl = p_ctrl;

        args.channel   = interlaced_channel;
        args.p_context = p_ctrl->p_context;
        args.buffer    = 0U;

        /* Set remaining arguments and call callback */
        r_canfd_call_callback(p_callback_ctrl, &args);
    }

    /* Clear IRQ */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
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

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Get lowest FIFO requesting interrupt */
    uint32_t shift_count      = CANFD_PRV_RX_FIFO_MAX;
    uint32_t fifo_mask_result = 0;
    while (0U == fifo_mask_result)
    {
        /* Decrement shift count until a flag is found in the mask. */
        shift_count--;
        fifo_mask_result = (uint32_t) (p_reg->RSCFDnCFDRFISTS & (1U << shift_count));
    }

    uint32_t fifo = shift_count;

    /* Only perform ISR duties if a FIFO has requested it */
    if (fifo < CANFD_PRV_RX_FIFO_MAX)
    {
        /* Set static arguments */
        args.event  = CAN_EVENT_RX_COMPLETE;
        args.buffer = fifo + CANFD_PRV_RXMB_MAX;

        /* Read from the FIFO until it is empty */
        while (!(p_reg->RSCFDnCFDFESTS & (1U << fifo)))
        {
            /* Get channel associated with the AFL entry */
 #if BSP_FEATURE_CANFD_NUM_INSTANCES > 1
            args.channel = instance;
 #else
            uintptr_t rffdsts_address_gap = (uintptr_t) (&p_reg->RSCFDnCFDRFPTR1) -
                                            (uintptr_t) (&p_reg->RSCFDnCFDRFPTR0);
            uint32_t * rffdsts_base =
                (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFPTR0 + rffdsts_address_gap * fifo);
            args.channel = ((*rffdsts_base) & R_CANFD_RSCFDnCFDRFPTR0_RFPTR_Msk) >> R_CANFD_RSCFDnCFDRFPTR0_RFPTR_Pos;
 #endif

            /* Read and index FIFO */
            r_canfd_mb_read(p_reg, fifo + CANFD_PRV_RXMB_MAX, &args.frame);

            /* Set the remaining callback arguments */
            args.p_context = gp_ctrl[args.channel]->p_context;
            r_canfd_call_callback(gp_ctrl[args.channel], &args);
        }

        /* Clear RX FIFO Interrupt Flag */
        uint32_t * rfsts_base = (uint32_t *) ((uintptr_t) &p_reg->RSCFDnCFDRFSTS0 + 0x04 * fifo);
        *rfsts_base &= (uint32_t) ~R_CANFD_RSCFDnCFDRFSTS0_RFIF_Msk;
    }
#endif

#if BSP_FEATURE_CANFD_HAS_RSCANFD
    if (!p_reg->RSCFDnCFDRFISTS)
    {
        /* Clear interrupt in NVIC if there are no pending RX FIFO IRQs */
        R_BSP_IrqStatusClear(CANFD_INTRCANGRECC_IRQn);
    }
#endif
}

/*******************************************************************************************************************//**
 * Receive ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common receive function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_rx_fifo_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE FSP_PARAMETER_NOT_USED(irq);

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
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Transmit ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common transmit function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_channel_tx_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    canfd_instance_ctrl_t * p_ctrl   = (canfd_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    canfd_extended_cfg_t  * p_extend = (canfd_extended_cfg_t *) p_ctrl->p_cfg->p_extend;
    uint32_t                channel  = p_ctrl->p_cfg->channel;

    /* Set static arguments */
    can_callback_args_t args;
    args.channel   = channel;
    args.p_context = p_ctrl->p_context;

    uint32_t interlaced_channel = CANFD_INTER_CH(channel);

#if BSP_FEATURE_CANFD_HAS_RSCANFD

    /* Check the byte of CFDGTINTSTS0 that corresponds to the interrupting channel */
    volatile uint8_t * p_cfdgtintsts = (((volatile uint8_t *) &p_ctrl->p_reg->RSCFDnCFDGTINTSTS0) + interlaced_channel);
    while (*p_cfdgtintsts)
    {
        bool                is_cfifo = false;
        uint32_t            txmb;
        volatile uint32_t * p_cfdtm_sts;
        const uint32_t      cfdgtintsts = *p_cfdgtintsts;

        /* Get relevant TX status register bank */
        if (cfdgtintsts & R_CANFD_RSCFDnCFDGTINTSTS0_TSIF0_Msk)
        {
            p_cfdtm_sts = (volatile uint32_t *) &p_ctrl->p_reg->RSCFDnCFDTMTCSTS0;
            args.event  = CAN_EVENT_TX_COMPLETE;
        }
        else if (cfdgtintsts & R_CANFD_RSCFDnCFDGTINTSTS0_CFTIF0_Msk)
        {
            is_cfifo = true;
            uint32_t common_fifo_index;
 #if CANFD_PRV_CFIFO_HAS_ISTS
            p_cfdtm_sts = (volatile uint32_t *) &p_ctrl->p_reg->RSCFDnCFDCFTISTS;

            /* Determine TX Common FIFO buffer with the specified event */
            uint32_t common_fifo_mask_result = 0;
            common_fifo_index = CANFD_PRV_CFIFO_CHANNEL_OFFSET * 2;
            while (0U == common_fifo_mask_result)
            {
                /* Decrement common_fifo_index until a flag is found in the mask. */
                common_fifo_index--;
                common_fifo_mask_result = (uint32_t) (*p_cfdtm_sts & (1U << common_fifo_index));
            }

 #else
            common_fifo_index = 0;
 #endif
            args.event =
                (p_extend->p_global_cfg->common_fifo_config[common_fifo_index] & R_CANFD_RSCFDnCFDCFCC0_CFIM_Msk) ?
                CAN_EVENT_TX_COMPLETE : CAN_EVENT_TX_FIFO_EMPTY;
        }
        else
        {
            p_cfdtm_sts = (volatile uint32_t *) &p_ctrl->p_reg->RSCFDnCFDTMTASTS0;
            args.event  = CAN_EVENT_TX_ABORTED;
        }

        /* Calculate lowest TXMB with the specified event */
        if (!is_cfifo)
        {
            uint32_t txmb_mask_result = 0;
            uint32_t shift_count      = CANFD_PRV_TXMB_CHANNEL_OFFSET * 2;
            while (0U == txmb_mask_result)
            {
                /* Decrement shift count until a flag is found in the mask. */
                shift_count--;
                txmb_mask_result = (uint32_t) (*p_cfdtm_sts & (1U << shift_count));
            }

            txmb = shift_count;

            /* Clear TX complete/abort flags */
            uint8_t * tmsts_base = (uint8_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDTMSTS0 + txmb);
            *tmsts_base &= (uint8_t) (~R_CANFD_RSCFDnCFDTMSTS0_TMTRF_Msk);
        }
        else
        {
 #if CANFD_PRV_CFIFO_HAS_ISTS
            uint32_t txmb_mask_result = 0;
            uint32_t shift_count      = CANFD_PRV_CFIFO_CHANNEL_OFFSET * 2;
            while (0U == txmb_mask_result)
            {
                /* Decrement shift count until a flag is found in the mask. */
                shift_count--;
                txmb_mask_result = (uint32_t) (*p_cfdtm_sts & (1U << shift_count));
            }

 #else
            txmb = 0;
 #endif
            txmb = shift_count;

            /* Clear the interrupt flag for Common FIFO TX. */
            uint8_t * cfsts_base = (uint8_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDCFSTS0 + 0x04 * txmb);
            *cfsts_base &= (uint8_t) (~R_CANFD_RSCFDnCFDCFSTS0_CFTXIF_Msk);

            /* Add the Common FIFO offset so the correct type of buffer will be available in the callback. */
            txmb += CANFD_TX_BUFFER_FIFO_COMMON_0;
        }

        /* Set the callback arguments */
        args.buffer = txmb;

        r_canfd_call_callback(p_ctrl, &args);
    }
#endif

    /* Clear interrupt */
    R_BSP_IrqStatusClear(irq);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * Common FIFO Receive ISR.
 *
 * Saves context if RTOS is used, clears interrupts, calls common receive function
 * and restores context if RTOS is used.
 **********************************************************************************************************************/
void canfd_common_fifo_rx_isr (IRQn_Type const irq)
{
    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE

    canfd_instance_ctrl_t * p_ctrl  = (canfd_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    uint32_t                channel = p_ctrl->p_cfg->channel;

    /* Set static arguments */
    can_callback_args_t args;

#if CANFD_PRV_CFIFO_HAS_ISTS

    /* Get lowest FIFO requesting interrupt */
    uint32_t shift_count      = CANFD_PRV_CFIFO_CHANNEL_OFFSET * 2;
    uint32_t fifo_mask_result = 0;
    while (0U == fifo_mask_result)
    {
        /* Decrement shift count until a flag is found in the mask. */
        shift_count--;
        fifo_mask_result = (uint32_t) (p_ctrl->p_reg->RSCFDnCFDCFRISTS & (1U << shift_count));
    }

    uint32_t fifo = shift_count;
#else
    uint32_t fifo = 0;
#endif

    /* Set static arguments */
    args.event   = CAN_EVENT_RX_COMPLETE;
    args.channel = channel;

#if BSP_FEATURE_CANFD_NUM_CHANNELS > 1

    /* Get the channel based fifo index to get the currect buffer value. */
    if (fifo < CANFD_PRV_CFIFO_CHANNEL_OFFSET)
    {
        args.buffer = fifo;
    }
    else
    {
        args.buffer = fifo % CANFD_PRV_CFIFO_CHANNEL_OFFSET;
    }

#else
    args.buffer = fifo;
#endif

    /* Move buffer up to the correct range. */
    args.buffer += (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0;

    /* Read from the FIFO until it is empty */
    while (!(p_ctrl->p_reg->RSCFDnCFDFESTS & (1U << (R_CANFD_RSCFDnCFDFESTS_CF0EMP_Pos + fifo))))
    {
        /* Read and index FIFO */
        /* buffer is slightly different in this function since it operates globally. */
        r_canfd_mb_read(p_ctrl->p_reg, fifo + (uint32_t) CANFD_RX_BUFFER_FIFO_COMMON_0, &args.frame);

        /* Set the remaining callback arguments */
        args.p_context = gp_ctrl[args.channel]->p_context;
        r_canfd_call_callback(gp_ctrl[args.channel], &args);
    }

    /* Clear Common FIFO RX Interrupt Flag */
    uint32_t * cfsts_base = (uint32_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDCFSTS0 + 0x04 * fifo);
    *cfsts_base &= (uint32_t) ~R_CANFD_RSCFDnCFDCFSTS0_CFRXIF_Msk;

#if CANFD_PRV_CFIFO_HAS_ISTS
    if (!p_ctrl->p_reg->RSCFDnCFDCFRISTS)
#else

    /* This device is single channel and single Common FIFO. */
    if (!(p_ctrl->p_reg->RSCFDnCFDCFSTS0 & R_CANFD_RSCFDnCFDCFSTS0_CFRXIF_Msk))
#endif
    {
        /* Clear interrupt in NVIC if there are no pending RX FIFO IRQs */
        R_BSP_IrqStatusClear(irq);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

/*******************************************************************************************************************//**
 * This function is used to switch the CANFD peripheral operation mode.
 * @param[in]  p_ctrl            - pointer to control structure
 * @param[in]  operation_mode    - destination operation mode
 **********************************************************************************************************************/
static void r_canfd_mode_transition (canfd_instance_ctrl_t * p_ctrl, can_operation_mode_t operation_mode)
{
    uint32_t interlaced_channel = CANFD_INTER_CH(p_ctrl->p_cfg->channel);

#if BSP_FEATURE_CANFD_HAS_RSCANFD
    volatile uint32_t * cfdcctr_base[BSP_FEATURE_CANFD_NUM_CHANNELS] =
    {
        &p_ctrl->p_reg->RSCFDnCFDC0CTR,
        &p_ctrl->p_reg->RSCFDnCFDC1CTR
    };

    /* Get bit 7 from operation_mode to determine if this is a global mode change request */
    bool global_mode = (bool) (operation_mode >> 7);
    operation_mode &= 0xF;

    volatile uint32_t * rfcc_base = NULL;
    volatile uint32_t * cfcc_base = NULL;

    if (global_mode)
    {
        uint32_t cfdgctr = p_ctrl->p_reg->RSCFDnCFDGCTR;

        /* If CANFD is transitioning to Global Reset, make sure the FIFOs are disabled. */
        if (!(cfdgctr & R_CANFD_RSCFDnCFDGSTS_GRSTSTS_Msk) && (operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Disable RX FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_RX_FIFO_MAX; i++)
            {
                rfcc_base   = (uint32_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDRFCC0 + 0x04 * i);
                *rfcc_base &= (uint32_t) ~R_CANFD_RSCFDnCFDRFCC0_RFE_Msk;
            }

            /* Disable Common FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_COMMON_FIFO_MAX * BSP_FEATURE_CANFD_NUM_CHANNELS; i++)
            {
                cfcc_base   = (uint32_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDCFCC0 + 0x04 * i);
                *cfcc_base &= (uint32_t) ~R_CANFD_RSCFDnCFDCFCC0_CFE_Msk;
            }
        }

        r_canfd_mode_ctr_set(&p_ctrl->p_reg->RSCFDnCFDGCTR, operation_mode);

        /* If CANFD is transitioning out of Reset the FIFOs need to be enabled. */
        if ((cfdgctr & R_CANFD_RSCFDnCFDGSTS_GRSTSTS_Msk) && !(operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Get global config */
            canfd_global_cfg_t * p_global_cfg =
                ((canfd_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->p_global_cfg;

            /* Enable RX FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_RX_FIFO_MAX; i++)
            {
                rfcc_base   = (uint32_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDRFCC0 + 0x04 * i);
                *rfcc_base &= (uint32_t) ~R_CANFD_RSCFDnCFDRFCC0_RFE_Msk;
                *rfcc_base |= p_global_cfg->rx_fifo_config[i] & 1U;
            }
        }
    }
    else
    {
        uint32_t cfdcnctr = *(cfdcctr_base[interlaced_channel]);

        if (((cfdcnctr & R_CANFD_RSCFDnCFDC0CTR_CSLPR_Msk) && (!(CAN_OPERATION_MODE_RESET & operation_mode))) ||
            ((!(cfdcnctr & CANFD_PRV_CTR_RESET_BIT)) && (CAN_OPERATION_MODE_SLEEP == operation_mode)))
        {
            /* Transition channel to Reset if a transition to/from Sleep is requested (see Section "Channel
             * Modes" in the Hardware Manual for details) */
            r_canfd_mode_ctr_set(cfdcctr_base[interlaced_channel], CAN_OPERATION_MODE_RESET);
        }

        /* Request transition to selected mode */
        r_canfd_mode_ctr_set(cfdcctr_base[interlaced_channel], operation_mode);

        /* If CANFD is transitioning from Reset, make sure the Common FIFOs are enabled.
         * The FIFOs will be disabled automatically if configured for TX and the channel is transitioned to reset. */
        if ((cfdcnctr & R_CANFD_RSCFDnCFDC0CTR_CHMDC_Msk) && !(operation_mode & CAN_OPERATION_MODE_RESET))
        {
            /* Get global config */
            canfd_global_cfg_t * p_global_cfg =
                ((canfd_extended_cfg_t *) p_ctrl->p_cfg->p_extend)->p_global_cfg;

            const uint32_t ch_offset = interlaced_channel * CANFD_PRV_COMMON_FIFO_MAX;

            /* Enable Common FIFOs */
            for (uint32_t i = 0; i < CANFD_PRV_COMMON_FIFO_MAX; i++)
            {
                cfcc_base   = (uint32_t *) ((uintptr_t) &p_ctrl->p_reg->RSCFDnCFDCFCC0 + 0x04 * (ch_offset + i));
                *cfcc_base &= (uint32_t) ~R_CANFD_RSCFDnCFDCFCC0_CFE_Msk;
                *cfcc_base |= p_global_cfg->common_fifo_config[ch_offset + i] & 1U;
            }
        }
    }
#endif

    p_ctrl->operation_mode = (can_operation_mode_t) (*(cfdcctr_base[interlaced_channel]) & CANFD_PRV_CTR_MODE_MASK);
}

/*******************************************************************************************************************//**
 * Sets the provided CTR register to the requested mode and waits for the associated STS register to reflect the change
 * @param[in]  p_ctr_reg            - pointer to control register
 * @param[in]  operation_mode       - requested mode (not including global bits)
 **********************************************************************************************************************/
static void r_canfd_mode_ctr_set (volatile uint32_t * p_ctr_reg, can_operation_mode_t operation_mode)
{
    volatile uint32_t * p_sts_reg = p_ctr_reg + 1;

    /* See definitions for CFDCnCTR, CFDCnSTS, CFDGCTR and CFDGSTS in the Hardware Manual. */
    *p_ctr_reg = (*p_ctr_reg & (uint32_t) ~CANFD_PRV_CTR_MODE_MASK) | operation_mode;
    FSP_HARDWARE_REGISTER_WAIT((*p_sts_reg & CANFD_PRV_CTR_MODE_MASK), operation_mode);
}

#if BSP_FEATURE_CANFD_FD_SUPPORT

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

#endif
