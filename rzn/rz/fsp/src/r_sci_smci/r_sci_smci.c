/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_sci_smci.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "SMCI" in ASCII. Used to determine if the control block is open. */
#define SCI_SMCI_OPEN                          (0x534D4349U)

/* The bit rate register is 8-bits, so the maximum value is 255. */
#define SCI_SMCI_BRR_MAX                       (255U)

/* Number of divisors in input clock calculation. */
#define SCI_SMCI_NUM_DIVISORS                  (4U)

#define SCI_SMCI_100_PERCENT_X_1000            (100000)

#define SCI_SMCI_MAX_BAUD_RATE_ERROR_X_1000    (20000) /* 20 percent Error */

#define SCI_SMCI_S_LOOKUP_TABLE_ENTRIES        (8)
#define SCI_SMCI_CKS_MASK                      (0x03)  /* Only two bits */

#define SCI_SMCI_EVENT_CSR_ORER_POS            (19U)
#define SCI_SMCI_EVENT_CSR_PER_POS             (24U)

/***********************************************************************************************************************
 * Private constants
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct st_sci_smci_bcp_setting_const_t
{
    uint32_t bcp : 3;
    uint16_t bit_clock_conversion_number_s; /* Number of base clock cycles S in a 1-bit data transfer,
                                             * referred to as S in HW Manual. */
} sci_smci_bcp_setting_const_t;

typedef struct st_sci_smci_ffmax_lut_const_t
{
    uint16_t f_value;
    uint32_t freq_max;
} sci_smci_ffmax_lut_const_t;

typedef enum e_smci_clock_conversion_ratio_s
{
    SMCI_CLOCK_CONVERSION_RATIO_32          = 0U, ///< 32 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_64          = 1U, ///< 64 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_93          = 2U, ///< 93 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_128         = 3U, ///< 128 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_186         = 4U, ///< 186 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_256         = 5U, ///< 256 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_372         = 6U, ///< 372 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_512         = 7U, ///< 512 base clock cycles for 1-bit period
    SMCI_CLOCK_CONVERSION_RATIO_UNSUPPORTED = 8U, ///< Unsupported Clock Cycles
} smci_clock_conversion_ratio_s_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_sci_irqs_cfg(sci_smci_instance_ctrl_t * const p_instance_ctrl, smci_cfg_t const * const p_cfg);
static void r_sci_smci_config_set(sci_smci_instance_ctrl_t * const p_instance_ctrl,
                                  smci_transfer_mode_t           * p_transfer_mode_params);
static fsp_err_t r_sci_smci_brr_calculate(smci_speed_params_t const * const p_speed_params,
                                          uint32_t                          baud_rate_error_x_1000,
                                          sci_smci_clock_source_t           clock_source,
                                          sci_smci_baud_setting_t * const   p_baud_setting);
static void r_sci_smci_baud_set(R_SCI0_Type * p_sci_reg, sci_smci_baud_setting_t const * const p_baud_setting);

void sci_smci_rxi_isr(void);
void sci_smci_txi_isr(void);
void sci_smci_eri_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Base Clock Cycles for 1-bit transfer period information (Smart Card mode) */

/* This is just a lookup table for S (which is different than F) */

/* This table is the "Base clock settings in smart card interface mode" table from the
 * SCI section of the relevant hardware manual. */
static const sci_smci_bcp_setting_const_t g_bit_clock_conversion_setting_lut[SCI_SMCI_S_LOOKUP_TABLE_ENTRIES] =
{
    /* BCP, S */
    {4U, 32 },
    {5U, 64 },
    {0U, 93 },
    {1U, 128},
    {2U, 186},
    {7U, 256},
    {6U, 372},
    {3U, 512}
};

/* This is "Table 7 - Fi and f (max.) Bits" & from ISO/IEC7816-3 Third edition
 * 2006-11-01".. NOTE only the F values that can yield at last one possible supported
 * S value are listed. */
static const sci_smci_ffmax_lut_const_t g_f_value_lut[SMCI_CLOCK_CONVERSION_INTEGER_MAX] =
{
    [0]  = {372,  4000000       },
    [1]  = {372,  5000000       },
    [2]  = {0,    0             },     /* There is no value of the associated f value (558) that the SMCI hardware will support. */
    [3]  = {744,  8000000       },
    [4]  = {1116, 12000000      },
    [5]  = {1488, 16000000      },
    [6]  = {1860, 20000000      },
    [7]  = {0,    0             },
    [8]  = {0,    0             },
    [9]  = {512,  5000000       },
    [10] = {768,  7500000       },
    [11] = {1024, 10000000      },
    [12] = {1536, 15000000      },
    [13] = {2048, 20000000      },
    [14] = {0,    0             },
    [15] = {0,    0             }
};

static const uint8_t g_d_value_lut[SMCI_BAUDRATE_ADJUSTMENT_INTEGER_MAX] =
{
    [0]  = 0,
    [1]  = 1,
    [2]  = 2,
    [3]  = 4,
    [4]  = 8,
    [5]  = 16,
    [6]  = 32,
    [7]  = 64,
    [8]  = 12,
    [9]  = 20,
    [10] = 0,
    [11] = 0,
    [12] = 0,
    [13] = 0,
    [14] = 0,
    [15] = 0
};

/* This is the divisor 2^(2n+1) as defined in Table "Relationship between N setting in BRR and bit rate B" in the SCI section of the relevant hardware manual. */
static const uint8_t g_clock_div_setting[SCI_SMCI_NUM_DIVISORS] =
{
    2U,
    8U,
    32U,
    128U
};

/* SMCI on SCI HAL API mapping for SMCI interface. */
const smci_api_t g_smci_on_sci =
{
    .open            = R_SCI_SMCI_Open,
    .close           = R_SCI_SMCI_Close,
    .write           = R_SCI_SMCI_Write,
    .read            = R_SCI_SMCI_Read,
    .transferModeSet = R_SCI_SMCI_TransferModeSet,
    .baudSet         = R_SCI_SMCI_BaudSet,
    .statusGet       = R_SCI_SMCI_StatusGet,
    .clockControl    = R_SCI_SMCI_ClockControl,
    .callbackSet     = R_SCI_SMCI_CallbackSet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_SCI_SMCI
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures the Smart Card Interface driver based on the input configurations. The interface stays in the clock-off
 * state without enabling reception at the end of this function. ISO7816-3 default communication parameters are used to
 * initialize SMCI port speed and parameters, as the ATR message is always sent in that format. Only if Inverse convention
 * is expected should the transfer mode be changed after reset. Implements @ref smci_api_t::open
 *
 * @param[in,out]  p_ctrl                  Pointer to SMCI control block that is to be opened
 * @param[in]      p_cfg                   Pointer to the config structure that shall be used to set parameters of the SMCI
 *                                         baud calculations needed to be have done and set into
 *                                         p_cfg->p_extend->p_smci_baud_setting
 *
 * @retval  FSP_SUCCESS                    Channel opened successfully.
 * @retval  FSP_ERR_ASSERTION              Pointer to SMCI control block or configuration structure is NULL.
 * @retval  FSP_ERR_IP_CHANNEL_NOT_PRESENT The requested channel does not exist on this MPU.
 * @retval  FSP_ERR_ALREADY_OPEN           Control block has already been opened or channel is being used by another
 *                                         instance. Call close() then open() to reconfigure.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_Open (smci_ctrl_t * const p_ctrl, smci_cfg_t const * const p_cfg)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;
    sci_smci_extended_cfg_t  * p_ext;
    smci_transfer_mode_t       comm_params;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cfg);

    FSP_ERROR_RETURN(SCI_SMCI_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    FSP_ASSERT(p_cfg->rxi_irq >= 0);
    FSP_ASSERT(p_cfg->txi_irq >= 0);
    FSP_ASSERT(p_cfg->eri_irq >= 0);
#endif

    p_ext = (sci_smci_extended_cfg_t *) p_cfg->p_extend;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_cfg->p_callback);
    FSP_ASSERT(p_ext);
    FSP_ASSERT(p_ext->p_smci_baud_setting);
    FSP_ASSERT(p_ext->p_reg);

    /* Make sure this channel exists. */
    FSP_ERROR_RETURN(BSP_FEATURE_SCI_CHANNELS & (1U << p_cfg->channel), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
#endif

    p_instance_ctrl->p_reg = (R_SCI0_Type *) p_ext->p_reg;

    p_instance_ctrl->p_cfg = p_cfg;

    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    comm_params.protocol   = SMCI_PROTOCOL_TYPE_T0;
    comm_params.convention = SMCI_CONVENTION_TYPE_DIRECT;
    comm_params.gsm_mode   = false;

    /* Configure the interrupts. */
    r_sci_irqs_cfg(p_instance_ctrl, p_cfg);

    /* Enable the SCI channel. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_SCI, p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Initialize registers. See section "Initialization of SCI (Smart Card Interface Mode)" in the SCI section of the relevant hardware manual. */
    r_sci_smci_config_set(p_instance_ctrl, &comm_params);

    p_instance_ctrl->p_tx_src          = NULL;
    p_instance_ctrl->tx_src_bytes      = 0U;
    p_instance_ctrl->p_rx_dest         = NULL;
    p_instance_ctrl->rx_dest_bytes     = 0U;
    p_instance_ctrl->rx_bytes_received = 0U;

    /* NOTE: Receiver and its interrupt are enabled at clock out. */
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->eri_irq);

    /* NOTE: Transmitter and its interrupt are enabled in SCI_SMCI_Write(). */
    R_BSP_IrqEnable(p_instance_ctrl->p_cfg->txi_irq);

    r_sci_smci_baud_set(p_instance_ctrl->p_reg, p_ext->p_smci_baud_setting);

    p_instance_ctrl->open       = SCI_SMCI_OPEN;
    p_instance_ctrl->smci_state = SMCI_STATE_IDLE_CLOCK_OFF;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Transmits user specified number of bytes from the source buffer pointer. Implements @ref smci_api_t::write
 *
 * @param[in,out] p_ctrl                 Pointer to SMCI control block
 * @param[in]     p_src                  Pointer to buffer that will be written out
 * @param[in]     bytes                  Number of bytes to be transferred
 *
 * @retval  FSP_SUCCESS                  Data transmission started successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to SMCI control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_IN_USE               A SMCI transmission is in progress.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_Write (smci_ctrl_t * const p_ctrl, uint8_t const * const p_src, uint32_t const bytes)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;
    uint32_t ccr0;
#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_src);
    FSP_ASSERT(0U != bytes);
    FSP_ERROR_RETURN(0U == p_instance_ctrl->tx_src_bytes, FSP_ERR_IN_USE);
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    ccr0 = p_instance_ctrl->p_reg->CCR0;

    /* Disable the receiver, and enable transmitter. */
    ccr0 &= (uint32_t) ~(R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_RIE_Msk);
    ccr0 |= R_SCI0_CCR0_TE_Msk;

    p_instance_ctrl->p_reg->CCR0 = ccr0;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0U);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 1U);

    /* The FIFO is not used, so the first write will be done from this function. Subsequent writes will be done
     * from txi_isr. */
    p_instance_ctrl->tx_src_bytes = bytes - 1;
    p_instance_ctrl->p_tx_src     = p_src + 1;

    p_instance_ctrl->smci_state = SMCI_STATE_TX_PROGRESSING;

    /* Enable the TX interrupt before putting data in TDR.. also enable RIE as it enables the error interrupts
     * that may occur. */
    p_instance_ctrl->p_reg->CCR0 |= (R_SCI0_CCR0_TIE_Msk | R_SCI0_CCR0_RIE_Msk);

    p_instance_ctrl->p_reg->TDR_b.TDAT = *(p_src);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Receives user specified number of bytes into destination buffer pointer. Receiving is done at the ISR level as
 * there is no FIFO. If 0 is passed in as the length, reception will always invoke the user callback.
 * Implements @ref smci_api_t::read
 *
 * @param[in,out] p_ctrl                 Pointer to SMCI control block
 * @param[in,out] p_dest                 Pointer to the buffer top be read into
 * @param[in]     bytes                  Number of bytes to copy from the SMCI receive register
 *
 * @retval  FSP_SUCCESS                  Data reception started successfully.
 * @retval  FSP_ERR_ASSERTION            Pointer to SMCI control block or read buffer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_IN_USE               A previous read operation is still in progress.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_Read (smci_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;
#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT((p_dest) || (0U == bytes));
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((0U == bytes) || (0U == p_instance_ctrl->rx_dest_bytes - p_instance_ctrl->rx_bytes_received),
                     FSP_ERR_IN_USE);
#endif
    if (0 == bytes)                    /* 0 bytes indicate a reset of the read states. */
    {
        p_instance_ctrl->smci_state = SMCI_STATE_TX_RX_IDLE;
    }

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ERROR_RETURN(SMCI_STATE_TX_RX_IDLE == p_instance_ctrl->smci_state, FSP_ERR_IN_USE);
#endif

    /* Transmit and receive interrupts must be disabled to start with. */
    /* Disable transmit. */
    p_instance_ctrl->p_reg->CCR0 &= (uint32_t) ~(R_SCI0_CCR0_TIE_Msk | R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RIE_Msk);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);

    /* Save the destination address and size for use in rxi_isr. */
    p_instance_ctrl->p_rx_dest         = p_dest;
    p_instance_ctrl->rx_dest_bytes     = bytes;
    p_instance_ctrl->rx_bytes_received = 0U;

    /* Enable receiver and its interrupt. */
    p_instance_ctrl->p_reg->CCR0 |= (R_SCI0_CCR0_RIE_Msk | R_SCI0_CCR0_RE_Msk);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1U);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the settings of block transfer mode and data transfer convention. The CCR1 and CCR3 registers
 * will be set according to the input arguments of protocol type, data convention type, and mode.
 * Implements @ref smci_api_t::transferModeSet
 *
 * @param[in,out] p_ctrl                 Pointer to SMCI control block that is to be modified
 * @param[in]     p_transfer_mode_params Pointer to SMCI settings like protocol, convention, and gsm_mode
 *
 * @warning This terminates any in-progress transmission and reception.
 *
 * @retval  FSP_SUCCESS                  Transfer mode and data transfer direction was successfully changed.
 * @retval  FSP_ERR_IN_USE               Unable to change transfer mode as device has clock off or is actively RX or TX.
 * @retval  FSP_ERR_ASSERTION            Null pointer was passed as a parameter.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_TransferModeSet (smci_ctrl_t * const                p_ctrl,
                                      smci_transfer_mode_t const * const p_transfer_mode_params)

{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_transfer_mode_params);

    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    FSP_ERROR_RETURN((SMCI_STATE_IDLE_CLOCK_OFF == p_instance_ctrl->smci_state) ||
                     (SMCI_STATE_TX_RX_IDLE == p_instance_ctrl->smci_state),
                     FSP_ERR_IN_USE);
#endif

    /* Save CCR0 configurations except transmit interrupts. Resuming transmission after reconfiguring transfer mode is
     * not supported. */
    uint32_t preserved_ccr0 = p_instance_ctrl->p_reg->CCR0 &
                              (uint32_t) ~(R_SCI0_CCR0_TIE_Msk | R_SCI0_CCR0_TE_Msk);

    /* If TX and RX arent disable writing to speed and mode registers wont occur according to datasheet. */
    p_instance_ctrl->p_reg->CCR0 = preserved_ccr0 & (uint32_t) ~(R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RE_Msk);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0U);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);
    p_instance_ctrl->p_tx_src = NULL;

    uint32_t ccr1 = p_instance_ctrl->p_reg->CCR1;
    uint32_t ccr3 = p_instance_ctrl->p_reg->CCR3;

    /* Enable parity for SMCI mode. */
    ccr1 |= R_SCI0_CCR1_PE_Msk;

    if (SMCI_PROTOCOL_TYPE_T1 == p_transfer_mode_params->protocol)
    {
        ccr3 |= R_SCI0_CCR3_BLK_Msk;
    }
    else
    {
        ccr3 &= (uint32_t) ~R_SCI0_CCR3_BLK_Msk;
    }

    if (SMCI_CONVENTION_TYPE_DIRECT == p_transfer_mode_params->convention)
    {
        ccr1 &= (uint32_t) ~R_SCI0_CCR1_PM_Msk;
        ccr3 &= (uint32_t) ~R_SCI0_CCR3_SINV_Msk;
        ccr3 |= R_SCI0_CCR3_LSBF_Msk;
    }
    else
    {
        ccr1 |= R_SCI0_CCR1_PM_Msk;    /* Because the SINV bit only inverts data bits D7 to D0, */
                                       /* write 1 to the PM bit in CCR1 to invert the parity bit for */
                                       /* both transmission and reception. */
        ccr3 |= R_SCI0_CCR3_SINV_Msk;
        ccr3 &= (uint32_t) ~R_SCI0_CCR3_LSBF_Msk;
    }

    /* Set the GSM mode. */
    if (true == p_transfer_mode_params->gsm_mode)
    {
        ccr3 |= R_SCI0_CCR3_GM_Msk;
    }
    else
    {
        ccr3 &= (uint32_t) ~R_SCI0_CCR3_GM_Msk;
    }

    p_instance_ctrl->p_reg->CCR3 = ccr3;
    p_instance_ctrl->p_reg->CCR1 = ccr1;

    /* Restore all settings except transmit enable interrupts. */
    /* Keep the receiver on, thats the normal idle state. */
    p_instance_ctrl->p_reg->CCR0 = preserved_ccr0 | R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_RIE_Msk;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1U);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the baud rate and clock output. p_baud_setting is a pointer to a sci_smci_baud_setting_t structure that needs
 * to have already been filled by R_SCI_SMCI_BaudCalculate.
 * Implements @ref smci_api_t::baudSet
 *
 * @warning This terminates any in-progress transmission.
 *
 * @param[in,out] p_ctrl                 Pointer to SMCI control block that is to be modified
 * @param[in]     p_baud_setting         Pointer to baud setting information to be written to the SMCI hardware registers
 *
 * @retval  FSP_SUCCESS                  Baud rate was successfully changed.
 * @retval  FSP_ERR_ASSERTION            Pointer to SMCI control block or p_baud_setting is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_INVALID_ARGUMENT     The p_baud_setting does not seem to be set correctly.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_BaudSet (smci_ctrl_t * const p_ctrl, void const * const p_baud_setting)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_baud_setting);
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(((sci_smci_baud_setting_t *) p_baud_setting)->computed_baud_rate != 0U, FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Save CCR0 configurations except transmit interrupts. Resuming transmission after reconfiguring baud settings is
     * not supported. */
    uint32_t preserved_ccr0 = p_instance_ctrl->p_reg->CCR0 & (uint32_t) ~R_SCI0_CCR0_TIE_Msk;

    /* If TX and RX arent disable writing to speed and mode registers wont occur according to datasheet. */
    p_instance_ctrl->p_reg->CCR0 = preserved_ccr0 & (uint32_t) ~(R_SCI0_CCR0_TE_Msk | R_SCI0_CCR0_RE_Msk);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0U);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);

    p_instance_ctrl->p_tx_src = NULL;

    /* Apply new baud rate register settings. */
    r_sci_smci_baud_set(p_instance_ctrl->p_reg, p_baud_setting);

    /* Restore all settings except transmit enable interrupts. */
    /* Keep the receiver on, thats the normal idle state. */
    p_instance_ctrl->p_reg->CCR0 = preserved_ccr0 | R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_RIE_Msk;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1U);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Provides the state of the driver and the # of bytes received since read was called.
 * Implements @ref smci_api_t::statusGet
 *
 * @param[in]  p_ctrl         Pointer to SMCI control block of this SMCI instance
 * @param[out] p_status       Pointer structure that will be filled in with status info
 *
 * @retval  FSP_SUCCESS                  Information stored in provided p_status.
 * @retval  FSP_ERR_ASSERTION            Pointer to SMCI control block, or status structure is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_StatusGet (smci_ctrl_t * const p_ctrl, smci_status_t * const p_status)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_status);
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_status->smci_state = p_instance_ctrl->smci_state;

    /* The number of bytes received. */
    p_status->bytes_recvd = p_instance_ctrl->rx_bytes_received;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable or disable the clock signal that is provided by interface the baud rate. When the clock is enabled, reception
 * is enabled at the end of this function. See section "Clock Output Control" in Smart Card Interface Mode
 * in the SCI section of the relevant hardware manual.
 * Implements @ref smci_api_t::clockControl
 *
 * @warning This terminates any in-progress transmission and reception.
 *
 * @param[in,out]  p_ctrl                Pointer to SMCI control block
 * @param[in]      clock_enable          true=Enable or false=disable the Smart Card Interface clock
 *
 * @retval  FSP_SUCCESS                  Clock output setting was successfully changed.
 * @retval  FSP_ERR_ASSERTION            Pointer to SMCI control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 * @retval  FSP_ERR_INVALID_MODE         Clock cannot be disabled if GSM mode isnt active.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_ClockControl (smci_ctrl_t * const p_ctrl, bool clock_enable)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;
    uint32_t ccr0;
#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters. */
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    /* Only allow clock off in GSM Mode. */
    if (false == clock_enable)
    {
        FSP_ERROR_RETURN(1U == p_instance_ctrl->p_reg->CCR3_b.GM, FSP_ERR_INVALID_MODE);
    }
#endif
    ccr0 = p_instance_ctrl->p_reg->CCR0;

    /* Clock Enable control bit can be written only when TE=0 and RE=0.
     * The setting of RIE and TIE are reset because resuming reception or transmission after clock state change is not supported. */
    p_instance_ctrl->p_reg->CCR0 = ccr0 & (uint32_t) ~(R_SCI0_CCR0_RE_Msk | R_SCI0_CCR0_TE_Msk |
                                                       R_SCI0_CCR0_RIE_Msk | R_SCI0_CCR0_TIE_Msk);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0U);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);

    if (clock_enable)
    {
        /* Output clock. */
        p_instance_ctrl->p_reg->CCR3_b.CKE = 1U;

        /* Enable received transfer as default. */
        p_instance_ctrl->p_reg->CCR0 |= (R_SCI0_CCR0_RIE_Msk | R_SCI0_CCR0_RE_Msk);
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 1U);
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);

        /* Indicate we are ready to transmit. */
        p_instance_ctrl->smci_state = SMCI_STATE_TX_RX_IDLE;
    }
    else
    {
        /* Stop clock. */
        p_instance_ctrl->p_reg->CCR3_b.CKE = 0U;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback and has option of providing memory for callback structure.
 * Implements smci_api_t::callbackSet
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_CallbackSet (smci_ctrl_t * const          p_ctrl,
                                  void (                     * p_callback)(smci_callback_args_t *),
                                  void * const                 p_context,
                                  smci_callback_args_t * const p_callback_memory)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context. */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Aborts any in progress transfers. Disables interrupts, receiver, and transmitter.
 * Implements @ref smci_api_t::close
 *
 * @param[in]  p_ctrl                Pointer to SMCI control block that is requested to close
 *
 * @retval  FSP_SUCCESS              Channel successfully closed.
 * @retval  FSP_ERR_ASSERTION        Pointer to SMCI control block is NULL.
 * @retval  FSP_ERR_NOT_OPEN         The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_Close (smci_ctrl_t * const p_ctrl)
{
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) p_ctrl;
#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_instance_ctrl);
    FSP_ERROR_RETURN(SCI_SMCI_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Mark the channel not open so other APIs cannot use it. */
    p_instance_ctrl->open = 0U;

    /* Disable interrupts, receiver, and transmitter. Disable baud clock output. */
    p_instance_ctrl->p_reg->CCR0 = 0U;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0U);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);
    p_instance_ctrl->p_reg->CCR3_b.CKE = 0U;

    /* Disable reception IRQs. */
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->rxi_irq);
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->eri_irq);

    /* Disable transmission IRQs. */
    R_BSP_IrqDisable(p_instance_ctrl->p_cfg->txi_irq);

    /* Enter module stop mode. */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_SCI, p_instance_ctrl->p_cfg->channel);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Calculates baud rate register settings. Evaluates and determines the best possible settings set to the baud rate
 * related registers. And then updates the SCI registers.
 *
 * @param[in]  p_speed_params            Structure including speed defining params, baud, F, and D.
 * @param[in]  baud_rate_error_x_1000    &lt;baud_rate_percent_error&gt; x 1000 required for module to function.
 *                                       Absolute max baud_rate_error is 20000 (20%) according to the ISO spec.
 * @param[in]  clock_source              Clock source (PCLKM or SCInASYNCCLK) used for bit rate calculation.
 * @param[out] p_baud_setting            Baud setting information stored here if successful.
 *
 * @retval     FSP_SUCCESS               Baud rate setting calculation successful.
 * @retval     FSP_ERR_ASSERTION         p_speed_params or p_baud is a null pointer.
 * @retval     FSP_ERR_INVALID_ARGUMENT  Baud rate is '0', freq is '0', or error in
 *                                       calculated baud rate is larger than 20%.
 **********************************************************************************************************************/
fsp_err_t R_SCI_SMCI_BaudCalculate (smci_speed_params_t const * const p_speed_params,
                                    uint32_t                          baud_rate_error_x_1000,
                                    sci_smci_clock_source_t           clock_source,
                                    void * const                      p_baud_setting)
{
    sci_smci_baud_setting_t * p_baud = (sci_smci_baud_setting_t *) p_baud_setting;

#if (SCI_SMCI_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_speed_params);
    FSP_ERROR_RETURN(0U != p_speed_params->baudrate, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(0U != g_f_value_lut[p_speed_params->fi].freq_max, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(SCI_SMCI_MAX_BAUD_RATE_ERROR_X_1000 >= baud_rate_error_x_1000, FSP_ERR_INVALID_ARGUMENT);
    FSP_ASSERT(p_baud);
#endif

    fsp_err_t err;

    /* Calculate the SCI baudrate registers configuration. */
    err = r_sci_smci_brr_calculate(p_speed_params, baud_rate_error_x_1000, clock_source, p_baud);

    if (FSP_SUCCESS != err)
    {
        p_baud->computed_baud_rate = 0U;
    }

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup SCI_SMCI)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Sets interrupt priority and initializes vector info for all interrupts.
 *
 * @param[in]  p_instance_ctrl           Pointer to SMCI control block
 * @param[in]  p_cfg                     Pointer to SMCI specific configuration structure
 **********************************************************************************************************************/
static void r_sci_irqs_cfg (sci_smci_instance_ctrl_t * const p_instance_ctrl, smci_cfg_t const * const p_cfg)
{
    R_BSP_IrqCfg(p_cfg->eri_irq, p_cfg->eri_ipl, p_instance_ctrl);
    R_BSP_IrqCfg(p_cfg->rxi_irq, p_cfg->rxi_ipl, p_instance_ctrl);
    R_BSP_IrqCfg(p_cfg->txi_irq, p_cfg->txi_ipl, p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * Computes the BRR register value required for the given input params.
 * @param[in]  p_speed_params              Pointer to structure containing etu definition params
 * @param[in]  baud_rate_error_x_1000      Allowable baud rate error
 * @param[in]  clock_source                Clock source (PCLKM or SCInASYNCCLK) used for bit rate calculation
 * @param[out] p_baud_setting              Pointer to structure containing computed values to achieve baud/error rate
 *
 * @retval  FSP_SUCCESS                  Register settings updated in provided p_baud_setting
 * @retval  FSP_ERR_INVALID_ARGUMENT     Cant achieve output etu/freq with given params
 **********************************************************************************************************************/
static fsp_err_t r_sci_smci_brr_calculate (smci_speed_params_t const * const p_speed_params,
                                           uint32_t                          baud_rate_error_x_1000,
                                           sci_smci_clock_source_t           clock_source,
                                           sci_smci_baud_setting_t * const   p_baud_setting)
{
    uint32_t        max_baudrate    = 0U;
    static uint32_t actual_baudrate = 0U;
    int32_t         hit_bit_err     = SCI_SMCI_100_PERCENT_X_1000;
    static uint32_t divisor         = 0U;
    uint32_t        f_value         = 0U;
    uint32_t        freq_hz         = 0U;
    if (SCI_SMCI_CLOCK_SOURCE_PCLKM == clock_source)
    {
        freq_hz = R_FSP_SystemClockHzGet(FSP_PRIV_CLOCK_PCLKM);
    }
    else
    {
        freq_hz =
            R_FSP_SystemClockHzGet((fsp_priv_clock_t) ((uint8_t) FSP_PRIV_CLOCK_PCLKSCI0 + (uint8_t) clock_source));
    }

    int32_t  err_divisor     = 0;
    int32_t  bit_err         = 0;
    uint32_t temp_brr        = 0U;
    uint32_t s_value         = 0U;
    uint8_t  s_index         = 0U;
    uint32_t target_baudrate = 0U;

    target_baudrate = p_speed_params->baudrate;

    /* Find the best BRR (bit rate register) value in Smart Card mode. */

    /* First determine if we can get to the spec'd baudrate withe params given. */
    f_value = (uint32_t) g_f_value_lut[p_speed_params->fi].f_value;

    max_baudrate = (g_d_value_lut[p_speed_params->di] * g_f_value_lut[p_speed_params->fi].freq_max) / f_value;

    s_value = f_value / g_d_value_lut[p_speed_params->di];
    if (target_baudrate > max_baudrate)
    {
        /* Error out if the parameters supplied will not allow the baud rate generated to be within error range. */
        FSP_ERROR_RETURN(((((target_baudrate - max_baudrate) * 100000) / max_baudrate) <= baud_rate_error_x_1000),
                         FSP_ERR_INVALID_ARGUMENT);
        target_baudrate = max_baudrate;
    }

    /* Validate that a S value for the given F and D exists on the SMCI hardware. */
    /* Find the S value that corresponds, from our look up table. */
    while ((s_index < SCI_SMCI_S_LOOKUP_TABLE_ENTRIES) &&
           (s_value != g_bit_clock_conversion_setting_lut[s_index].bit_clock_conversion_number_s))
    {
        s_index++;
    }

    FSP_ERROR_RETURN((s_index != SCI_SMCI_S_LOOKUP_TABLE_ENTRIES), FSP_ERR_INVALID_ARGUMENT);

    for (uint8_t cks_value = 0U;
         cks_value < (SCI_SMCI_NUM_DIVISORS) && (hit_bit_err > ((int32_t) baud_rate_error_x_1000));
         cks_value++)
    {
        /* This is the based on SMCI BRR setting as defined in Table "Relationship between N setting in BRR and bit rate B"
         * in the SCI section of the relevant hardware manual. */
        divisor = (uint32_t) g_clock_div_setting[cks_value] * target_baudrate *
                  s_value;
        temp_brr = freq_hz / divisor;

        if (temp_brr <= (SCI_SMCI_BRR_MAX + 1U))
        {
            if (temp_brr > 0U)
            {
                temp_brr -= 1U;

                /* Calculate the bit rate error. The formula is as follows:
                 *  bit rate error[%] = {(PCLK / (baud * div_coefficient * (BRR + 1)) - 1} x 100
                 *  calculates bit rate error[%] to three decimal places
                 */
                err_divisor = (int32_t) (divisor * (temp_brr + 1U));

                /* Promoting to 64 bits for calculation, but the final value can never be more than 32 bits, as
                 * described below, so this cast is safe.
                 *    1. (temp_brr + 1) can be off by an upper limit of 1 due to rounding from the calculation:
                 *       freq_hz / divisor, or:
                 *       freq_hz / divisor <= (temp_brr + 1) < (freq_hz / divisor) + 1
                 *    2. Solving for err_divisor:
                 *       freq_hz <= err_divisor < freq_hz + divisor
                 *    3. Solving for bit_err:
                 *       0 >= bit_err >= (freq_hz * 100000 / (freq_hz + divisor)) - 100000
                 *    4. freq_hz >= divisor (or temp_brr would be -1 and we would never enter this while loop), so:
                 *       0 >= bit_err >= 100000 / freq_hz - 100000
                 *    5. Larger frequencies yield larger bit errors (absolute value).  As the frequency grows,
                 *       the bit_err approaches -100000, so:
                 *       0 >= bit_err >= -100000
                 *    6. bit_err is between -100000 and 0.  This entire range fits in an int32_t type, so the cast
                 *       to (int32_t) is safe.
                 */
                bit_err = (int32_t) (((((int64_t) freq_hz) * SCI_SMCI_100_PERCENT_X_1000) /
                                      err_divisor) - SCI_SMCI_100_PERCENT_X_1000);

                /* Bit error will always be > 0 because we are effectively rouding down BRR, so we dont need to
                 * do absolute value. */

                actual_baudrate =
                    (uint32_t) (freq_hz /
                                (g_clock_div_setting[cks_value] * s_value *
                                 (temp_brr + 1U)));

                /* If the absolute value of the bit rate error is less than the previous lowest absolute value of
                 * bit rate error, then store these settings as the best value.
                 */
                if (bit_err < hit_bit_err)
                {
                    /* Look up the settings based on the s_index we found above. */
                    p_baud_setting->ccr2_clock_bits_b.cks = (uint8_t) (cks_value & SCI_SMCI_CKS_MASK);
                    p_baud_setting->ccr2_clock_bits_b.bcp = g_bit_clock_conversion_setting_lut[s_index].bcp;
                    p_baud_setting->ccr2_clock_bits_b.brr = (uint8_t) temp_brr;
                    hit_bit_err = bit_err;
                }
            }
        }
    }

    p_baud_setting->computed_baud_rate = actual_baudrate;

    /* Return an error if the percent error is larger than the maximum percent error allowed for this instance. */
    FSP_ERROR_RETURN(hit_bit_err <= (int32_t) baud_rate_error_x_1000, FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Changes baud rate based on predetermined register settings.
 *
 * @param[in]  p_sci_reg       Base pointer for SCI registers
 * @param[in]  p_baud_setting  Pointer to other divisor related settings
 *
 * @note       The transmitter and receiver (TE and RE bits in CCR3) must be disabled prior to calling this function.
 **********************************************************************************************************************/
static void r_sci_smci_baud_set (R_SCI0_Type * p_sci_reg, sci_smci_baud_setting_t const * const p_baud_setting)
{
    uint32_t ccr2 = (p_sci_reg->CCR2) & (uint32_t) ~(R_SCI0_CCR2_CKS_Msk | R_SCI0_CCR2_BRR_Msk | R_SCI0_CCR2_BCP_Msk);

    /* Set Base Clock Pulse, BRR, and Clock Select. */
    ccr2 |= p_baud_setting->ccr2_clock_bits &
            (uint32_t) (R_SCI0_CCR2_CKS_Msk | R_SCI0_CCR2_BRR_Msk | R_SCI0_CCR2_BCP_Msk);
    p_sci_reg->CCR2 = ccr2;
}

/*******************************************************************************************************************//**
 * Configures SCI related registers for Smart Card mode.
 *
 * @param[in]     p_instance_ctrl          Pointer to SMCI control structure
 * @param[in]     p_transfer_mode_params   Pointer to SMCI specific comm parameters
 **********************************************************************************************************************/
static void r_sci_smci_config_set (sci_smci_instance_ctrl_t * const p_instance_ctrl,
                                   smci_transfer_mode_t           * p_transfer_mode_params)
{
    smci_cfg_t const        * p_cfg    = p_instance_ctrl->p_cfg;
    sci_smci_extended_cfg_t * p_extend = (sci_smci_extended_cfg_t *) p_cfg->p_extend;

    /* Stop communication - Set TEIE, TIE, RIE, TE, and RE to 0. */
    p_instance_ctrl->p_reg->CCR0 = 0U;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.RE, 0U);
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CCR0_b.TE, 0U);

    /* Initialize registers. */
    uint32_t ccr1 = R_SCI0_CCR1_SPB2DT_Msk;
    uint32_t ccr2 = (4U << R_SCI0_CCR2_BCP_Pos) | R_SCI0_CCR2_BRR_Msk | R_SCI0_CCR2_MDDR_Msk;
    uint32_t ccr3 = R_SCI0_CCR3_CPHA_Msk | R_SCI0_CCR3_CPOL_Msk;

    /* Write settings to CCR3:
     * - Set to Smart card interface mode.
     * - Set Transfer mode.
     * - Set Character Length to 8-Bit.
     * - Set Bypass Synchronizer circuit between bus clock and operation clock.
     *
     * Set to Smart card interface mode. */
    ccr3 |= 1U << R_SCI0_CCR3_MOD_Pos;

    /* Set Transfer mode. */
    if (true == p_transfer_mode_params->gsm_mode)
    {
        ccr3 |= R_SCI0_CCR3_GM_Msk;
    }

    if (SMCI_PROTOCOL_TYPE_T1 == p_transfer_mode_params->protocol)
    {
        ccr3 |= R_SCI0_CCR3_BLK_Msk;
    }

    if (SMCI_CONVENTION_TYPE_DIRECT == p_transfer_mode_params->convention)
    {
        ccr3 |= R_SCI0_CCR3_LSBF_Msk;
    }
    else
    {
        ccr3 |= R_SCI0_CCR3_SINV_Msk;
        ccr1 |= R_SCI0_CCR1_PM_Msk;    /* Need to invert parity as well. */
    }

    /* Set Character Length to 8-Bit. */
    ccr3 |= 2U << R_SCI0_CCR3_CHR_Pos;

    /* Apply the synchronization bypass settings. */
    if (SCI_SMCI_CLOCK_SOURCE_PCLKM == p_extend->clock_source)
    {
        ccr3 |= R_SCI0_CCR3_BPEN_Msk;
    }

    p_instance_ctrl->p_reg->CCR3 = ccr3;

    /* Write settings to CCR2:
     * - Set BRME to 0.
     */
    p_instance_ctrl->p_reg->CCR2 = ccr2;

    /* Write settings to CCR1:
     * - Enable parity.
     */
    ccr1 |= R_SCI0_CCR1_PE_Msk;
    p_instance_ctrl->p_reg->CCR1 = ccr1;

    /* Clear status flags. */
    p_instance_ctrl->p_reg->CFCLR = R_SCI0_CFCLR_RDRFC_Msk | R_SCI0_CFCLR_FERC_Msk | R_SCI0_CFCLR_PERC_Msk |
                                    R_SCI0_CFCLR_MFFC_Msk | R_SCI0_CFCLR_ORERC_Msk | R_SCI0_CFCLR_DFERC_Msk |
                                    R_SCI0_CFCLR_DPERC_Msk | R_SCI0_CFCLR_DCMFC_Msk | R_SCI0_CFCLR_ERSC_Msk;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl     Pointer to SMCI instance control block
 * @param[in]     data                See smci_callback_args_t in r_smci_api.h
 * @param[in]     event               Event code
 **********************************************************************************************************************/
static void r_sci_smci_call_callback (sci_smci_instance_ctrl_t * p_instance_ctrl, uint8_t data, smci_event_t event)
{
    smci_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    smci_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack. */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    p_args->channel   = p_instance_ctrl->p_cfg->channel;
    p_args->data      = data;
    p_args->event     = event;
    p_args->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * Receiver ISR receives data into the receive buffer or initiates user callback.
 *
 **********************************************************************************************************************/
void sci_smci_rxi_isr (void)
{
    SCI_SMCI_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    uint8_t data;

    data = (uint8_t) p_instance_ctrl->p_reg->RDR_b.RDAT;

    if (0U == (p_instance_ctrl->rx_dest_bytes - p_instance_ctrl->rx_bytes_received))
    {
        /* Call user callback with the data. */
        r_sci_smci_call_callback(p_instance_ctrl, data, SMCI_EVENT_RX_CHAR);
    }
    else
    {
        *p_instance_ctrl->p_rx_dest         = data;
        p_instance_ctrl->p_rx_dest         += 1;
        p_instance_ctrl->rx_bytes_received += 1;
        p_instance_ctrl->smci_state         = SMCI_STATE_RX_PROGRESSING;
        if (0 == p_instance_ctrl->rx_dest_bytes - p_instance_ctrl->rx_bytes_received)
        {
            p_instance_ctrl->smci_state = SMCI_STATE_TX_RX_IDLE;
            r_sci_smci_call_callback(p_instance_ctrl, 0U, SMCI_EVENT_RX_COMPLETE);
        }
    }

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    SCI_SMCI_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Transmit ISR, loads the transmit register from the transmit buffer, until all data is sent
 * after which callback is initiated.
 *
 **********************************************************************************************************************/
void sci_smci_txi_isr (void)
{
    SCI_SMCI_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    if (0U != p_instance_ctrl->tx_src_bytes)
    {
        /* Write 1byte (uint8_t) data to (uint8_t) data register. */
        p_instance_ctrl->p_reg->TDR_b.TDAT = *(p_instance_ctrl->p_tx_src);

        /* Update pointer to the next data and number of remaining bytes in the control block. */
        p_instance_ctrl->tx_src_bytes -= 1;
        p_instance_ctrl->p_tx_src     += 1;
    }
    else
    {
        p_instance_ctrl->p_tx_src   = NULL;
        p_instance_ctrl->smci_state = SMCI_STATE_TX_RX_IDLE;

        uint32_t ccr0_temp = p_instance_ctrl->p_reg->CCR0;
        ccr0_temp &= (uint32_t) ~(R_SCI0_CCR0_TIE_Msk | R_SCI0_CCR0_TE_Msk);
        ccr0_temp |= R_SCI0_CCR0_RE_Msk;
        p_instance_ctrl->p_reg->CCR0 = ccr0_temp;

        r_sci_smci_call_callback(p_instance_ctrl, 0U, SMCI_EVENT_TX_COMPLETE);
    }

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    SCI_SMCI_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

/*******************************************************************************************************************//**
 * Error ISR, clears all three error Error Signal Status, Parity Error Flag, and Overrun Error Flag, then initiates
 * the callback with an event code.
 **********************************************************************************************************************/
void sci_smci_eri_isr (void)
{
    SCI_SMCI_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used. */
    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open. */
    sci_smci_instance_ctrl_t * p_instance_ctrl = (sci_smci_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    uint8_t      data = 0U;
    smci_event_t event;

    /* Read data. */
    data = (uint8_t) p_instance_ctrl->p_reg->RDR_b.RDAT;

    uint32_t csr = p_instance_ctrl->p_reg->CSR;
    event = (smci_event_t) ((csr & R_SCI0_CSR_ORER_Msk) >> SCI_SMCI_EVENT_CSR_ORER_POS |
                            (csr & R_SCI0_CSR_ERS_Msk) |
                            (csr & R_SCI0_CSR_PER_Msk) >> SCI_SMCI_EVENT_CSR_PER_POS);

    p_instance_ctrl->p_reg->CFCLR = R_SCI0_CFCLR_ORERC_Msk | R_SCI0_CFCLR_ERSC_Msk | R_SCI0_CFCLR_PERC_Msk;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->CSR);

    /* Call callback. */
    r_sci_smci_call_callback(p_instance_ctrl, data, event);

    /* Restore context if RTOS is used. */
    FSP_CONTEXT_RESTORE;

    SCI_SMCI_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
