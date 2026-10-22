/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_xspi_ospi.h"

#if XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE
 #include "r_transfer_api.h"
 #include "r_dmac.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define XSPI_OSPI_PRV_OPEN                                  (0x4F535049)

#define XSPI_OSPI_PRV_WRAPCFG_DSSFTCS0_VALUE_MASK           (0x1FU)
#define XSPI_OSPI_PRV_WRAPCFG_DSSFTCS1_VALUE_MASK           (0x1FU)

#define XSPI_OSPI_PRV_LIOCFGCS_PRTMD_OFFSET                 (0U)
#define XSPI_OSPI_PRV_LIOCFGCS_PRTMD_VALUE_MASK             (0x3FFU)
#define XSPI_OSPI_PRV_LIOCFGCS_PRTMD_MASK                   (0x3FFU << XSPI_OSPI_PRV_LIOCFGCS_PRTMD_OFFSET)
#define XSPI_OSPI_PRV_LIOCFGCS_CSMIN_OFFSET                 (16U)
#define XSPI_OSPI_PRV_LIOCFGCS_CSMIN_VALUE_MASK             (0x0FU)
#define XSPI_OSPI_PRV_LIOCFGCS_CSASTEX_OFFSET               (20U)
#define XSPI_OSPI_PRV_LIOCFGCS_CSASTEX_VALUE_MASK           (0x01U)
#define XSPI_OSPI_PRV_LIOCFGCS_CSENGEX_OFFSET               (21U)
#define XSPI_OSPI_PRV_LIOCFGCS_CSENGEX_VALUE_MASK           (0x01U)

#define XSPI_OSPI_PRV_CMCFG0_FFMT_OFFSET                    (0U)
#define XSPI_OSPI_PRV_CMCFG0_ADDSIZE_OFFSET                 (2U)
#define XSPI_OSPI_PRV_CMCFG0_ADDSIZE_VALUE_MASK             (0x03U)
#define XSPI_OSPI_PRV_CMCFG0_WPBSTMD_OFFSET                 (4U)
#define XSPI_OSPI_PRV_CMCFG0_WPBSTMD_VALUE_MASK             (0x01U)
#define XSPI_OSPI_PRV_CMCFG0_ADDRPEN_OFFSET                 (16U)
#define XSPI_OSPI_PRV_CMCFG0_ADDRPEN_VALUE_MASK             (0xFFU)
#define XSPI_OSPI_PRV_CMCFG1_RDCMD_OFFSET                   (0U)
#define XSPI_OSPI_PRV_CMCFG1_RDCMD_UPPER_OFFSET             (8U)
#define XSPI_OSPI_PRV_CMCFG1_RDCMD_1B_VALUE_MASK            (0xFFU)
#define XSPI_OSPI_PRV_CMCFG1_RDCMD_2B_VALUE_MASK            (0xFFFFU)
#define XSPI_OSPI_PRV_CMCFG1_RDLATE_OFFSET                  (16U)
#define XSPI_OSPI_PRV_CMCFG1_RDLATE_VALUE_MASK              (0x1FU)

#define XSPI_OSPI_PRV_CMCFG2_WRCMD_OFFSET                   (0U)
#define XSPI_OSPI_PRV_CMCFG2_WRCMD_UPPER_OFFSET             (8U)
#define XSPI_OSPI_PRV_CMCFG2_WRCMD_1B_VALUE_MASK            (0xFFU)
#define XSPI_OSPI_PRV_CMCFG2_WRCMD_2B_VALUE_MASK            (0xFFFFU)
#define XSPI_OSPI_PRV_CMCFG2_WRLATE_OFFSET                  (16U)

#define XSPI_OSPI_PRV_BMCFG_WRMD_OFFSET                     (0U)
#define XSPI_OSPI_PRV_BMCFG_MWRCOMB_OFFSET                  (7U)
#define XSPI_OSPI_PRV_BMCFG_MWRSIZE_OFFSET                  (8U)
#define XSPI_OSPI_PRV_BMCFG_PREEN_OFFSET                    (16U)
#define XSPI_OSPI_PRV_BMCFG_PREEN_VALUE_MASK                (0x01U)

#define XSPI_OSPI_PRV_BMCTL_DEFAULT_VALUE                   (0xFF)

#define XSPI_OSPI_PRV_CDTBUF_CMDSIZE_OFFSET                 (0U)
#define XSPI_OSPI_PRV_CDTBUF_CMDSIZE_VALUE_MASK             (0x03U)
#define XSPI_OSPI_PRV_CDTBUF_ADDSIZE_OFFSET                 (2U)
#define XSPI_OSPI_PRV_CDTBUF_ADDSIZE_VALUE_MASK             (0x07U)
#define XSPI_OSPI_PRV_CDTBUF_DATASIZE_OFFSET                (5U)
#define XSPI_OSPI_PRV_CDTBUF_DATASIZE_VALUE_MASK            (0x0FU)
#define XSPI_OSPI_PRV_CDTBUF_LATE_OFFSET                    (9U)
#define XSPI_OSPI_PRV_CDTBUF_LATE_VALUE_MASK                (0x1FU)
#define XSPI_OSPI_PRV_CDTBUF_TRTYPE_OFFSET                  (15U)
#define XSPI_OSPI_PRV_CDTBUF_TRTYPE_VALUE_MASK              (0x01U)
#define XSPI_OSPI_PRV_CDTBUF_CMD_OFFSET                     (16U)
#define XSPI_OSPI_PRV_CDTBUF_CMD_UPPER_OFFSET               (24U)
#define XSPI_OSPI_PRV_CDTBUF_CMD_1B_VALUE_MASK              (0xFFU)
#define XSPI_OSPI_PRV_CDTBUF_CMD_2B_VALUE_MASK              (0xFFFFU)

#define XSPI_OSPI_PRV_CCCTL0_CANOWR_OFFSET                  (1U)
#define XSPI_OSPI_PRV_CCCTL0_CAITV_OFFSET                   (8U)
#define XSPI_OSPI_PRV_CCCTL0_CASFTSTA_OFFSET                (16U)
#define XSPI_OSPI_PRV_CCCTL0_CASFTEND_OFFSET                (24U)

#define XSPI_OSPI_PRV_CCCTL1_CACMDSIZE_OFFSET               (0U)
#define XSPI_OSPI_PRV_CCCTL1_CACMDSIZE_VALUE_MASK           (0x3U)
#define XSPI_OSPI_PRV_CCCTL1_CAADDSIZE_OFFSET               (2U)
#define XSPI_OSPI_PRV_CCCTL1_CAADDSIZE_VALUE_MASK           (0xFU)
#define XSPI_OSPI_PRV_CCCTL1_CADATASIZE_OFFSET              (5U)
#define XSPI_OSPI_PRV_CCCTL1_CAWRLATE_OFFSET                (16U)
#define XSPI_OSPI_PRV_CCCTL1_CARDLATE_OFFSET                (24U)
#define XSPI_OSPI_PRV_CCCTL1_CARDLATE_VALUE_MASK            (0x1FU)

#define XSPI_OSPI_PRV_CCCTL2_CARDCMD_OFFSET                 (16U)
#define XSPI_OSPI_PRV_CCCTL2_CARDCMD_VALUE_MASK             (0xFFFFU)

#define XSPI_OSPI_PRV_COMSTT_MEMACC_OFFSET                  (0U)
#define XSPI_OSPI_PRV_COMSTT_MEMACC_VALUE_MASK              (0x01U)
#define XSPI_OSPI_PRV_COMSTT_WRBUFNE_OFFSET                 (6U)
#define XSPI_OSPI_PRV_COMSTT_WRBUFNE_VALUE_MASK             (0x01U)

#define XSPI_OSPI_PRV_INTC_CMDCMPC_OFFSET                   (0U)

#define XSPI_OSPI_PRV_MAX_COMBINE_SIZE                      (64U)

#define XSPI_OSPI_PRV_ADDRESS_REPLACE_VALUE                 (0xF0)
#define XSPI_OSPI_PRV_ADDRESS_REPLACE_ENABLE_BITS           (XSPI_OSPI_PRV_ADDRESS_REPLACE_VALUE << \
                                                             XSPI_OSPI_PRV_CMCFG0_ADDRPEN_OFFSET)
#define XSPI_OSPI_PRV_ADDRESS_REPLACE_MASK                  (~(XSPI_OSPI_PRV_ADDRESS_REPLACE_VALUE << 24))

#define XSPI_OSPI_PRV_WORD_ACCESS_SIZE                      (4U)
#define XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE                 (2U)

#define XSPI_OSPI_PRV_DIRECT_ADDR_AND_DATA_MASK             (7U)
#define XSPI_OSPI_PRV_PAGE_SIZE_BYTES                       (256U)

#define XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_0    (0xFFFF0000)
#define XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_1    (0x000800FF)
#define XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_2    (0x00FFF700)
#define XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_3    (0xF700F708)
#define XSPI_OSPI_PRV_AUTOCALIBRATION_TIMEOUT_US            (500U)

#define XSPI_OSPI_PRV_1MB_MEMORY_SIZE                       (0x100000)
#define XSPI_OSPI_PRV_2MB_MEMORY_SIZE                       (0x200000)
#define XSPI_OSPI_PRV_4MB_MEMORY_SIZE                       (0x400000)
#define XSPI_OSPI_PRV_8MB_MEMORY_SIZE                       (0x800000)
#define XSPI_OSPI_PRV_16MB_MEMORY_SIZE                      (0x1000000)
#define XSPI_OSPI_PRV_32MB_MEMORY_SIZE                      (0x2000000)
#define XSPI_OSPI_PRV_64MB_MEMORY_SIZE                      (0x4000000)

#define XSPI_OSPI_PRV_UINT32_BITS                           (32U)
#define XSPI_OSPI_PRV_DIRECT_TRANSFER_MAX_BYTES             (8U)
#define XSPI_OSPI_PRV_BYTE_SIZE_SHIFT                       (8U)
#define XSPI_OSPI_UNIT_FLAG_MASK                            (3U)

#define XSPI_OSPI_BUFFER_WRITE_WAIT_CYCLE                   (5U)

#ifndef XSPI_OSPI_MAX_WRITE_ENABLE_LOOPS
 #define XSPI_OSPI_MAX_WRITE_ENABLE_LOOPS                   (5U)
#endif

#if BSP_FEATURE_XSPI_HAS_XSPI_MISC2
 #define XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET                (16U)
 #define XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_MASK              (0x01U)
 #define XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK          (0x02U)
 #define XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK           (0x10U)
 #define XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK       (0x20U)
#endif

#define XSPI_OSPI_PRV_REV16_BYTES_SHIFT                     (8U)
#define XSPI_OSPI_PRV_REV16_INCREMENT_BYTES_MASK            (0x00FF00FFU)
#define XSPI_OSPI_PRV_REV16_DECREMENT_BYTES_MASK            (0xFF00FF00U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static fsp_err_t r_xspi_ospi_automatic_calibration_seq(xspi_ospi_instance_ctrl_t * p_instance_ctrl);
static bool      r_xspi_ospi_status_sub(xspi_ospi_instance_ctrl_t * p_instance_ctrl, uint8_t bit_pos);
static fsp_err_t r_xspi_ospi_spi_protocol_specific_settings(xspi_ospi_instance_ctrl_t * p_instance_ctrl,
                                                            spi_flash_protocol_t        spi_protocol);
static fsp_err_t r_xspi_ospi_write_enable(xspi_ospi_instance_ctrl_t * p_instance_ctrl);
static void      r_xspi_ospi_direct_transfer(xspi_ospi_instance_ctrl_t         * p_instance_ctrl,
                                             spi_flash_direct_transfer_t * const p_transfer,
                                             spi_flash_direct_transfer_dir_t     direction);
static uint32_t byte_order_rev(uint32_t value);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Bit-flags specifying which channels are open so the module can be stopped when all are closed. */
static uint32_t g_xspi_ospi_channels_open_flags = 0;

#if XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE
static uint8_t src_data[XSPI_OSPI_PRV_MAX_COMBINE_SIZE] BSP_PLACE_IN_SECTION(".noncache_buffer.ospi");
#endif

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_XSPI_OSPI
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

const spi_flash_api_t g_spi_flash_on_xspi_ospi =
{
    .open           = R_XSPI_OSPI_Open,
    .directWrite    = R_XSPI_OSPI_DirectWrite,
    .directRead     = R_XSPI_OSPI_DirectRead,
    .directTransfer = R_XSPI_OSPI_DirectTransfer,
    .spiProtocolSet = R_XSPI_OSPI_SpiProtocolSet,
    .write          = R_XSPI_OSPI_Write,
    .erase          = R_XSPI_OSPI_Erase,
    .statusGet      = R_XSPI_OSPI_StatusGet,
    .xipEnter       = R_XSPI_OSPI_XipEnter,
    .xipExit        = R_XSPI_OSPI_XipExit,
    .bankSet        = R_XSPI_OSPI_BankSet,
    .autoCalibrate  = R_XSPI_OSPI_AutoCalibrate,
    .close          = R_XSPI_OSPI_Close,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Open the OSPI driver module. After the driver is open, the OSPI can be accessed like internal flash memory.
 *
 * Implements @ref spi_flash_api_t::open.
 *
 * @retval FSP_SUCCESS              Configuration was successful.
 * @retval FSP_ERR_ASSERTION        The parameter p_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_ALREADY_OPEN     Driver has already been opened with the same p_ctrl.
 * @retval FSP_ERR_CALIBRATE_FAILED Failed to perform auto-calibrate.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_Open (spi_flash_ctrl_t * const p_ctrl, spi_flash_cfg_t const * const p_cfg)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    xspi_ospi_extended_cfg_t * p_cfg_extend = (xspi_ospi_extended_cfg_t *) p_cfg->p_extend;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_cfg_extend);
    FSP_ASSERT(p_cfg_extend->p_reg);
    FSP_ERROR_RETURN(
        (g_xspi_ospi_channels_open_flags & (1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select))) == 0,
        FSP_ERR_ALREADY_OPEN);
#endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

    /* Enable clock to the OSPI block */
    R_BSP_MODULE_START(FSP_IP_XSPI, p_cfg_extend->unit);

    /* Release from reset */
    if (0U == p_cfg_extend->unit)
    {
        R_BSP_ModuleResetDisable(BSP_MODULE_RESET_XSPI0);
    }
    else
    {
        R_BSP_ModuleResetDisable(BSP_MODULE_RESET_XSPI1);
    }

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

#if BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED

    /* Release from slave stop. */
    if (0U == p_cfg_extend->unit)
    {
        R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_XSPI0);
    }
    else
    {
        R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_XSPI1);
    }
#endif

#if BSP_FEATURE_XSPI_HAS_XSPI_MISC2

    /* Bus release request */
    R_XSPI_MISC2->MSTP_CTRL_XSPI &=
        ~(XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_MASK << (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit));
    FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                 (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK),
                               0U);

    /* Module release request */
    R_XSPI_MISC2->MSTP_CTRL_XSPI &=
        ~(XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK << (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit));
    FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                 (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK),
                               0U);
#endif

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

#if XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE
    transfer_instance_t const * p_transfer = p_cfg_extend->p_lower_lvl_transfer;
 #if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_transfer);
 #endif

    /* Initialize transfer instance */
    p_transfer->p_api->open(p_transfer->p_ctrl, p_transfer->p_cfg);
#endif

    /* Set base address. */
    p_instance_ctrl->p_reg = (R_XSPI0_Type *) p_cfg_extend->p_reg;

    /* Initialize control block. */
    p_instance_ctrl->p_cfg        = p_cfg;
    p_instance_ctrl->spi_protocol = p_cfg->spi_protocol;
    p_instance_ctrl->chip_select  = p_cfg_extend->chip_select;

    /* xSPI configuration (see RZ microprocessor Hardware Manual section "Flow of Configuration"). */

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

    /* Set xSPI IO voltage */
#if BSP_FEATURE_XSPI_VOLTAGE_SETTING_SUPPORTED
    if (0 == p_cfg_extend->unit)
    {
        R_XSPI0_MISC->IOVOLCTL = p_cfg_extend->io_voltage;
    }
    else
    {
        R_XSPI1_MISC->IOVOLCTL = p_cfg_extend->io_voltage;
    }
#endif

    /* Set xSPI CSn address space. */
#if 1 == BSP_FEATURE_XSPI_CS_ADDRESS_SPACE_SETTING_TYPE
    xspi_ospi_memory_size_t memory_size_reg = XSPI_OSPI_MEMORY_SIZE_1MB;

    switch (p_cfg_extend->memory_size)
    {
        case XSPI_OSPI_PRV_1MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_1MB;
            break;
        }

        case XSPI_OSPI_PRV_2MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_2MB;
            break;
        }

        case XSPI_OSPI_PRV_4MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_4MB;
            break;
        }

        case XSPI_OSPI_PRV_8MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_8MB;
            break;
        }

        case XSPI_OSPI_PRV_16MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_16MB;
            break;
        }

        case XSPI_OSPI_PRV_32MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_32MB;
            break;
        }

        case XSPI_OSPI_PRV_64MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_OSPI_MEMORY_SIZE_64MB;
            break;
        }

        default:
        {
            break;
        }
    }

    if (XSPI_OSPI_CHIP_SELECT_0 == p_cfg_extend->chip_select)
    {
        p_instance_ctrl->p_reg->CSSCTL_b.CS0SIZE = memory_size_reg;
    }
    else
    {
        p_instance_ctrl->p_reg->CSSCTL_b.CS1SIZE = memory_size_reg;
    }

#else
    uint32_t mirror_address_delta;
 #if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
    mirror_address_delta = 0;
 #else
    mirror_address_delta = BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS;
 #endif
    R_XSPI0_MISC->CS0ENDAD = p_cfg_extend->p_address_space->unit0_cs0_end_address - mirror_address_delta;
    R_XSPI0_MISC->CS1STRAD = p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta;
    R_XSPI0_MISC->CS1ENDAD = p_cfg_extend->p_address_space->unit0_cs1_end_address - mirror_address_delta;
    R_XSPI1_MISC->CS0ENDAD = p_cfg_extend->p_address_space->unit1_cs0_end_address - mirror_address_delta;
    R_XSPI1_MISC->CS1STRAD = p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta;
    R_XSPI1_MISC->CS1ENDAD = p_cfg_extend->p_address_space->unit1_cs1_end_address - mirror_address_delta;
#endif
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

    /* Set xSPI protocol mode. */
    p_instance_ctrl->p_reg->LIOCFGCS[p_cfg_extend->chip_select] = (p_cfg->spi_protocol) <<
                                                                  XSPI_OSPI_PRV_LIOCFGCS_PRTMD_OFFSET;

    /* Set xSPI drive/sampling timing. */
    if (XSPI_OSPI_CHIP_SELECT_0 == p_instance_ctrl->chip_select)
    {
        p_instance_ctrl->p_reg->WRAPCFG_b.DSSFTCS0 =
            p_cfg_extend->data_latch_delay_clocks & XSPI_OSPI_PRV_WRAPCFG_DSSFTCS0_VALUE_MASK;
    }
    else
    {
        p_instance_ctrl->p_reg->WRAPCFG_b.DSSFTCS1 =
            p_cfg_extend->data_latch_delay_clocks & XSPI_OSPI_PRV_WRAPCFG_DSSFTCS1_VALUE_MASK;
    }

    /* Set xSPI CSn signal timings. */
    p_instance_ctrl->p_reg->LIOCFGCS[p_instance_ctrl->chip_select] =
        ((p_cfg->spi_protocol & XSPI_OSPI_PRV_LIOCFGCS_PRTMD_VALUE_MASK) << XSPI_OSPI_PRV_LIOCFGCS_PRTMD_OFFSET) |
        ((p_cfg_extend->p_timing_settings->command_to_command_interval &
          XSPI_OSPI_PRV_LIOCFGCS_CSMIN_VALUE_MASK) << XSPI_OSPI_PRV_LIOCFGCS_CSMIN_OFFSET) |
        ((p_cfg_extend->p_timing_settings->cs_pulldown_lead & XSPI_OSPI_PRV_LIOCFGCS_CSASTEX_VALUE_MASK) <<
            XSPI_OSPI_PRV_LIOCFGCS_CSASTEX_OFFSET) |
        ((p_cfg_extend->p_timing_settings->cs_pullup_lag & XSPI_OSPI_PRV_LIOCFGCS_CSENGEX_VALUE_MASK) <<
            XSPI_OSPI_PRV_LIOCFGCS_CSENGEX_OFFSET);

    /* Set xSPI memory-mapping operation. */
    fsp_err_t ret = r_xspi_ospi_spi_protocol_specific_settings(p_instance_ctrl, p_instance_ctrl->spi_protocol);

    /* Set the access from AHB channel. */
    p_instance_ctrl->p_reg->BMCTL0 = XSPI_OSPI_PRV_BMCTL_DEFAULT_VALUE;

    /* Return response after issuing write transaction to xSPI bus, Enable prefetch function. */
    p_instance_ctrl->p_reg->BMCFG = (0 << XSPI_OSPI_PRV_BMCFG_WRMD_OFFSET) |
                                    (1 << XSPI_OSPI_PRV_BMCFG_MWRCOMB_OFFSET) |
                                    (0x0F << XSPI_OSPI_PRV_BMCFG_MWRSIZE_OFFSET) |
                                    ((p_cfg_extend->prefetch_en & XSPI_OSPI_PRV_BMCFG_PREEN_VALUE_MASK) <<
                                     XSPI_OSPI_PRV_BMCFG_PREEN_OFFSET);

    if (FSP_SUCCESS == ret)
    {
        p_instance_ctrl->open            = XSPI_OSPI_PRV_OPEN;
        g_xspi_ospi_channels_open_flags |= (1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select));
    }
    else if ((g_xspi_ospi_channels_open_flags & (XSPI_OSPI_UNIT_FLAG_MASK << (p_cfg_extend->unit << 1U))) == 0)
    {
        /* If the open fails and no other channels are open, stop the module. */
        R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Writes raw data directly to the OctaFlash. API not supported. Use R_XSPI_OSPI_DirectTransfer
 *
 * Implements @ref spi_flash_api_t::directWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by OSPI.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_DirectWrite (spi_flash_ctrl_t * const p_ctrl,
                                   uint8_t const * const    p_src,
                                   uint32_t const           bytes,
                                   bool const               read_after_write)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_src);
    FSP_PARAMETER_NOT_USED(bytes);
    FSP_PARAMETER_NOT_USED(read_after_write);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Reads raw data directly from the OctaFlash. API not supported. Use R_XSPI_OSPI_DirectTransfer.
 *
 * Implements @ref spi_flash_api_t::directRead.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by OSPI.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_DirectRead (spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(p_dest);
    FSP_PARAMETER_NOT_USED(bytes);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Read/Write raw data directly with the OctaFlash.
 *
 * Implements @ref spi_flash_api_t::directTransfer.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_DirectTransfer (spi_flash_ctrl_t * const            p_ctrl,
                                      spi_flash_direct_transfer_t * const p_transfer,
                                      spi_flash_direct_transfer_dir_t     direction)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;
#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ASSERT(0 != p_transfer->command_length);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    r_xspi_ospi_direct_transfer(p_instance_ctrl, p_transfer, direction);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enters XIP (execute in place) mode.
 *
 * Implements @ref spi_flash_api_t::xipEnter.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by OSPI.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_XipEnter (spi_flash_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Exits XIP (execute in place) mode.
 *
 * Implements @ref spi_flash_api_t::xipExit.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by OSPI.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_XipExit (spi_flash_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Program a page of data to the flash.
 *
 * Implements @ref spi_flash_api_t::write.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl, p_dest or p_src is NULL, or byte_count crosses a page boundary.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         Another Write/Erase transaction is in progress.
 * @retval FSP_ERR_WRITE_FAILED        Write operation failed.
 * @retval FSP_ERR_INVALID_SIZE        Insufficient space remaining in page.
 *
 * @note In this API, data can be written up to 64 bytes at a time if DMAC support is enabled.
 * Otherwise, the number of bytes that can be written at one time depends on the MPU :
 * 64 bytes for RZ/T2M and RZ/T2L, 8 bytes for RZ/T2ME, RZ/T2H, and RZ/T2N.
 * @note This API performs page program operations to the device. Writing across pages is not supported.
 * Please set the write address and write size according to the page size of your device.
 * @note In 8D-8D-8D(OPI) mode, written data must be even bytes in size.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_Write (spi_flash_ctrl_t * const p_ctrl,
                             uint8_t const * const    p_src,
                             uint8_t * const          p_dest,
                             uint32_t                 byte_count)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;
#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
 #if !XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE && BSP_FEATURE_XSPI_HAS_AXI_BRIDGE
    FSP_ASSERT(XSPI_OSPI_PRV_DIRECT_TRANSFER_MAX_BYTES >= byte_count);
 #else
    FSP_ASSERT(XSPI_OSPI_PRV_MAX_COMBINE_SIZE >= byte_count);
 #endif
    FSP_ASSERT(0 != byte_count);
    FSP_ASSERT((0 == byte_count % XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE) ||
               (XSPI_OSPI_BYTE_ORDER_1032 != ((xspi_ospi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend)->byte_order) ||
               (SPI_FLASH_PROTOCOL_8D_8D_8D != p_instance_ctrl->spi_protocol));
#endif
    xspi_ospi_extended_cfg_t * p_cfg_extend = (xspi_ospi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE || (!XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE && BSP_FEATURE_XSPI_HAS_AXI_BRIDGE)
    uint32_t chip_address;
    uint32_t chip_select = p_cfg_extend->chip_select;
    uint32_t unit        = p_cfg_extend->unit;
    uint32_t mirror_address_delta;

 #ifdef BSP_CFG_CORE_CA55
    uintptr_t dest_va = (uintptr_t) p_dest;
    uintptr_t dest_pa = 0U;

    fsp_err_t mmu_err;
    mmu_err = R_BSP_MmuVatoPa(dest_va, &dest_pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == mmu_err, mmu_err);
 #else
    uintptr_t dest_pa = (uintptr_t) p_dest;
 #endif

    /* Get device start address. */
 #if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
    mirror_address_delta = 0U;
 #else
    mirror_address_delta = (dest_pa < BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS) ?
                           BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS -
                           BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS : 0U;
 #endif

    chip_address = (0 == chip_select) ?
                   (0 == unit) ?
                   (uint32_t) dest_pa - (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - mirror_address_delta) : // unit0 cs0
                   (uint32_t) dest_pa - (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS - mirror_address_delta) : // unit1 cs0
                   (0 == unit)
 #if 2 == BSP_FEATURE_XSPI_CS_ADDRESS_SPACE_SETTING_TYPE
                   ? (uint32_t) dest_pa -
                   (p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta) :       // unit0 cs1
                   (uint32_t) dest_pa -
                   (p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta);        // unit1 cs1
 #else
                   ? (uint32_t) dest_pa -
                   (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                    mirror_address_delta) :                                                                // unit0 cs1
                   (uint32_t) dest_pa -
                   (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                    mirror_address_delta);                                                                 // unit1 cs1
 #endif
#endif

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    uintptr_t page_size = p_instance_ctrl->p_cfg->page_size_bytes;

    uintptr_t page_offset = chip_address % page_size;

    FSP_ERROR_RETURN((page_size - page_offset) >= byte_count, FSP_ERR_INVALID_SIZE);
#endif

    FSP_ERROR_RETURN(false == r_xspi_ospi_status_sub(p_instance_ctrl, p_instance_ctrl->p_cfg->write_status_bit),
                     FSP_ERR_DEVICE_BUSY);

    r_xspi_ospi_write_enable(p_instance_ctrl);

#if XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE
    uint32_t byte = 0;

    if ((XSPI_OSPI_BYTE_ORDER_1032 == p_cfg_extend->byte_order) &&
        (SPI_FLASH_PROTOCOL_8D_8D_8D == p_instance_ctrl->spi_protocol))
    {
        do
        {
            if (byte_count - byte >= XSPI_OSPI_PRV_WORD_ACCESS_SIZE)
            {
                *(uint32_t *) (src_data + byte) = byte_order_rev(*(uint32_t *) (p_src + byte));
                byte += XSPI_OSPI_PRV_WORD_ACCESS_SIZE;
            }
            else if (byte_count - byte >= XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE)
            {
                *(uint16_t *) (src_data + byte) = (uint16_t) byte_order_rev(*(uint16_t *) (p_src + byte));
                byte += XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE;
            }
            else
            {
                *(src_data + byte) = *(uint8_t *) (p_src + byte);
                byte++;
            }
        } while (byte < byte_count);
    }
    else
    {
        do
        {
            *(src_data + byte) = *(uint8_t *) (p_src + byte);
            byte++;
        } while (byte < byte_count);
    }

    /* Setup and start DMAC transfer. */
    transfer_instance_t const * p_transfer = p_cfg_extend->p_lower_lvl_transfer;

    p_transfer->p_cfg->p_info->src_size       = TRANSFER_SIZE_1_BYTE;
    p_transfer->p_cfg->p_info->dest_size      = TRANSFER_SIZE_1_BYTE;
    p_transfer->p_cfg->p_info->src_addr_mode  = TRANSFER_ADDR_MODE_INCREMENTED;
    p_transfer->p_cfg->p_info->dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED;
    p_transfer->p_cfg->p_info->p_src          = &src_data;
    p_transfer->p_cfg->p_info->p_dest         = p_dest;
    p_transfer->p_cfg->p_info->length         = byte_count;
    fsp_err_t err = p_transfer->p_api->reconfigure(p_transfer->p_ctrl, p_transfer->p_cfg->p_info);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Start DMA */
    err = p_transfer->p_api->softwareStart(p_transfer->p_ctrl, TRANSFER_START_MODE_SINGLE);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Wait for DMAC to complete to maintain deterministic processing and backward compatability */
    volatile transfer_properties_t transfer_properties = {0U};
    err = p_transfer->p_api->infoGet(p_transfer->p_ctrl, (transfer_properties_t *) &transfer_properties);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    while (FSP_SUCCESS == err && transfer_properties.transfer_length_remaining > 0)
    {
        err = p_transfer->p_api->infoGet(p_transfer->p_ctrl, (transfer_properties_t *) &transfer_properties);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }

    /* Request to push the pending data */
    if (XSPI_OSPI_PRV_MAX_COMBINE_SIZE > byte_count)
    {
        /* Push the pending data. */
        p_instance_ctrl->p_reg->BMCTL1_b.MWRPUSH = 1;
    }

#elif BSP_FEATURE_XSPI_HAS_AXI_BRIDGE
    spi_flash_direct_transfer_t write_transfer;

    write_transfer.data_u64 = 0;
    for (uint32_t bytes = 0; bytes < byte_count; bytes++)
    {
        write_transfer.data_u64 |= ((uint64_t) *(uint8_t *) (p_src + bytes)) << (bytes * XSPI_OSPI_PRV_BYTE_SIZE_SHIFT);
    }

    write_transfer.data_length    = (uint8_t) byte_count;
    write_transfer.address        = chip_address;
    write_transfer.address_length = (p_instance_ctrl->p_cfg->address_bytes == SPI_FLASH_ADDRESS_BYTES_4) ? 4U : 3U;
    write_transfer.dummy_cycles   = 0;

    if (SPI_FLASH_PROTOCOL_1S_1S_1S == p_instance_ctrl->spi_protocol)
    {
        write_transfer.command        = p_instance_ctrl->p_cfg->page_program_command;
        write_transfer.command_length = 1U;
    }
    else
    {
        write_transfer.command        = p_cfg_extend->p_opi_commands->page_program_command;
        write_transfer.command_length = 2U;
    }

    r_xspi_ospi_direct_transfer(p_instance_ctrl, &write_transfer, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);

    /* If prefetch is enabled, make sure the banks aren't being used and flush the prefetch caches after an erase. */
    if (p_cfg_extend->prefetch_en == XSPI_OSPI_PREFETCH_FUNCTION_ENABLE)
    {
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->COMSTT_b.MEMACC, 0);
        p_instance_ctrl->p_reg->BMCTL1_b.PBUFCLR = 1;
    }

#else
    uint32_t i = 0;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Word access */
    if (0 == byte_count % XSPI_OSPI_PRV_WORD_ACCESS_SIZE)
    {
        uint32_t * p_word_aligned_dest = (uint32_t *) p_dest;
        uint32_t * p_word_aligned_src  = (uint32_t *) p_src;
        if ((XSPI_OSPI_BYTE_ORDER_1032 == p_cfg_extend->byte_order) &&
            (SPI_FLASH_PROTOCOL_8D_8D_8D == p_instance_ctrl->spi_protocol))
        {
            for (i = 0; i < byte_count / XSPI_OSPI_PRV_WORD_ACCESS_SIZE; i++)
            {
                /* Apply byte_order_rev to convert the data to match the OctaFlash byte order. */
                *p_word_aligned_dest = byte_order_rev(*p_word_aligned_src);
                p_word_aligned_dest++;
                p_word_aligned_src++;
            }
        }
        else
        {
            for (i = 0; i < byte_count / XSPI_OSPI_PRV_WORD_ACCESS_SIZE; i++)
            {
                *p_word_aligned_dest = *p_word_aligned_src;
                p_word_aligned_dest++;
                p_word_aligned_src++;
            }
        }
    }
    /* Half Word access */
    else if (0 == byte_count % XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE)
    {
        uint16_t * p_half_word_aligned_dest = (uint16_t *) p_dest;
        uint16_t * p_half_word_aligned_src  = (uint16_t *) p_src;
        if ((XSPI_OSPI_BYTE_ORDER_1032 == p_cfg_extend->byte_order) &&
            (SPI_FLASH_PROTOCOL_8D_8D_8D == p_instance_ctrl->spi_protocol))
        {
            for (i = 0; i < byte_count / XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE; i++)
            {
                /* Apply byte_order_rev to convert the data to match the OctaFlash byte order. */
                *p_half_word_aligned_dest =
                    (uint16_t) byte_order_rev((uint32_t) (*p_half_word_aligned_src & UINT16_MAX));
                p_half_word_aligned_dest++;
                p_half_word_aligned_src++;
            }
        }
        else
        {
            for (i = 0; i < byte_count / XSPI_OSPI_PRV_HALF_WORD_ACCESS_SIZE; i++)
            {
                *p_half_word_aligned_dest = *p_half_word_aligned_src;
                p_half_word_aligned_dest++;
                p_half_word_aligned_src++;
            }
        }
    }
    /* Byte access */
    else
    {
        for (i = 0; i < byte_count; i++)
        {
            p_dest[i] = p_src[i];
        }
    }

    /* Protect the order between access to the xSPI external memory space and the xSPI peripheral space. */
    __DSB();

    /* Request to push the pending data */
    if (XSPI_OSPI_PRV_MAX_COMBINE_SIZE > byte_count)
    {
        /* Do dummy read for wait.
         * To ensure that all write data is stored in the xSPI internal write buffer before issuing a push request,
         * it is necessary to wait a few cycles. */
        for (uint32_t wait_cycle = 0; wait_cycle < XSPI_OSPI_BUFFER_WRITE_WAIT_CYCLE; wait_cycle++)
        {
            FSP_REGISTER_READ(p_instance_ctrl->p_reg->COMCFG);
        }

        /* Push the pending data. */
        p_instance_ctrl->p_reg->BMCTL1_b.MWRPUSH = 1;
    }

    /* Wait until memory access starts in write API. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->COMSTT_b.MEMACC, 1);

    FSP_CRITICAL_SECTION_EXIT;
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Erase a block or sector of flash.  The byte_count must exactly match one of the erase sizes defined in spi_flash_cfg_t.
 * For chip erase, byte_count must be SPI_FLASH_ERASE_SIZE_CHIP_ERASE.
 *
 * Implements @ref spi_flash_api_t::erase.
 *
 * @retval FSP_SUCCESS                 The command to erase the flash was executed successfully.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl or p_device_address is NULL, byte_count doesn't match an erase
 *                                     size defined in spi_flash_cfg_t, or byte_count is set to 0.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 * @retval FSP_ERR_WRITE_FAILED        Write operation failed.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_Erase (spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_device_address, uint32_t byte_count)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_device_address);
    FSP_ASSERT(0 != byte_count);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    spi_flash_cfg_t const    * p_cfg        = p_instance_ctrl->p_cfg;
    xspi_ospi_extended_cfg_t * p_cfg_extend = (xspi_ospi_extended_cfg_t *) p_cfg->p_extend;

    uint8_t unit        = p_cfg_extend->unit;
    uint8_t chip_select = p_cfg_extend->chip_select;

    uint16_t  erase_command = 0;
    uintptr_t chip_address  = 0;
    bool      send_address  = true;

    if (SPI_FLASH_ERASE_SIZE_CHIP_ERASE != byte_count)
    {
        uint32_t mirror_address_delta;

#ifdef BSP_CFG_CORE_CA55
        uintptr_t device_address_va = (uintptr_t) p_device_address;
        uintptr_t device_address_pa = 0U;

        fsp_err_t mmu_err;
        mmu_err = R_BSP_MmuVatoPa(device_address_va, &device_address_pa);
        FSP_ERROR_RETURN(FSP_SUCCESS == mmu_err, mmu_err);
#else
        uintptr_t device_address_pa = (uintptr_t) p_device_address;
#endif

        /* Get device start address. */
#if 0 == BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS
        mirror_address_delta = 0U;
#else
        mirror_address_delta = (device_address_pa < BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS) ?
                               BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS -
                               BSP_FEATURE_XSPI_DEVICE_0_MIRROR_START_ADDRESS :
                               0U;
#endif

        chip_address = (0 == chip_select) ?
                       (0 == unit) ?
                       device_address_pa - (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS - mirror_address_delta) : // unit0 cs0
                       device_address_pa - (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS - mirror_address_delta) : // unit1 cs0
                       (0 == unit)
#if 2 == BSP_FEATURE_XSPI_CS_ADDRESS_SPACE_SETTING_TYPE
                       ? device_address_pa -
                       (p_cfg_extend->p_address_space->unit0_cs1_start_address - mirror_address_delta) :      // unit0 cs1
                       device_address_pa -
                       (p_cfg_extend->p_address_space->unit1_cs1_start_address - mirror_address_delta);       // unit1 cs1
#else
                       ? device_address_pa -
                       (BSP_FEATURE_XSPI_DEVICE_0_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                        mirror_address_delta) :                                                               // unit0 cs1
                       device_address_pa -
                       (BSP_FEATURE_XSPI_DEVICE_1_START_ADDRESS + BSP_FEATURE_XSPI_DEVICE_ADDRESS_SPACE_SIZE / 2 -
                        mirror_address_delta);                                                                // unit1 cs1
#endif
    }

    FSP_ERROR_RETURN(false == r_xspi_ospi_status_sub(p_instance_ctrl, p_cfg->write_status_bit), FSP_ERR_DEVICE_BUSY);

    for (uint32_t index = 0; index < p_cfg->erase_command_list_length; index++)
    {
        /* If requested byte_count is supported by underlying flash, store the command. */
        if (byte_count == p_cfg->p_erase_command_list[index].size)
        {
            if (SPI_FLASH_ERASE_SIZE_CHIP_ERASE == byte_count)
            {
                /* Don't send address for chip erase. */
                send_address = false;
            }

            erase_command = p_cfg->p_erase_command_list[index].command;
            break;
        }
    }

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(0U != erase_command);
#endif

    r_xspi_ospi_write_enable(p_instance_ctrl);

    spi_flash_direct_transfer_t direct_command = {0};
    direct_command.command        = erase_command;
    direct_command.address        = (uint32_t) chip_address;
    direct_command.address_length = (true == send_address) ?
                                    (XSPI_OSPI_PRV_DIRECT_ADDR_AND_DATA_MASK &
                                     (p_instance_ctrl->p_cfg->address_bytes + 1U)) : 0U;
    direct_command.command_length = (SPI_FLASH_PROTOCOL_1S_1S_1S == p_instance_ctrl->spi_protocol) ?
                                    1U : (p_cfg_extend->p_opi_commands->command_bytes);

    r_xspi_ospi_direct_transfer(p_instance_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);

    /* If prefetch is enabled, make sure the banks aren't being used and flush the prefetch caches after an erase. */
    if (p_cfg_extend->prefetch_en == XSPI_OSPI_PREFETCH_FUNCTION_ENABLE)
    {
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->COMSTT_b.MEMACC, 0);
        p_instance_ctrl->p_reg->BMCTL1_b.PBUFCLR = 1;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the write or erase status of the flash.
 *
 * Implements @ref spi_flash_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 The write status is in p_status.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl or p_status is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_StatusGet (spi_flash_ctrl_t * const p_ctrl, spi_flash_status_t * const p_status)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t comstt  = p_instance_ctrl->p_reg->COMSTT;
    bool     memacc  = (bool) ((comstt >> XSPI_OSPI_PRV_COMSTT_MEMACC_OFFSET) & XSPI_OSPI_PRV_COMSTT_MEMACC_VALUE_MASK);
    bool     wrbufne =
        (bool) ((comstt >> XSPI_OSPI_PRV_COMSTT_WRBUFNE_OFFSET) & XSPI_OSPI_PRV_COMSTT_WRBUFNE_VALUE_MASK);

    if ((true == memacc) || (true == wrbufne))
    {
        /* If the xSPI is accessing memory or data is in the write buffer,
         * it is judged a "write in progress" without access to device. */
        p_status->write_in_progress = (bool) (wrbufne | memacc);
    }
    else
    {
        /* Read device status. */
        p_status->write_in_progress = r_xspi_ospi_status_sub(p_instance_ctrl, p_instance_ctrl->p_cfg->write_status_bit);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Selects the bank to access.
 *
 * Implements @ref spi_flash_api_t::bankSet.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by OSPI.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_BankSet (spi_flash_ctrl_t * const p_ctrl, uint32_t bank)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(bank);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Sets the SPI protocol.
 *
 * Implements @ref spi_flash_api_t::spiProtocolSet.
 *
 * @retval FSP_SUCCESS                SPI protocol updated on MPU peripheral.
 * @retval FSP_ERR_ASSERTION          A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN           Driver is not opened.
 * @retval FSP_ERR_CALIBRATE_FAILED   Failed to perform auto-calibrate.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_SpiProtocolSet (spi_flash_ctrl_t * const p_ctrl, spi_flash_protocol_t spi_protocol)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    p_instance_ctrl->spi_protocol = spi_protocol;

    /* Update the SPI protocol and its associated registers. */
    return r_xspi_ospi_spi_protocol_specific_settings(p_instance_ctrl, spi_protocol);
}

/*******************************************************************************************************************//**
 * Auto-calibrate the OctaRAM device using the preamble pattern. Unsupported by XSPI_OSPI.
 *
 * Implements @ref spi_flash_api_t::autoCalibrate.
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported by XSPI_OSPI
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_AutoCalibrate (spi_flash_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Close the OSPI driver module.
 *
 * Implements @ref spi_flash_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 *
 *
 * @note If another chip select of the same unit is used by other drivers,
 * the other chip select operation will also stop when this function is executed.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_OSPI_Close (spi_flash_ctrl_t * const p_ctrl)
{
    xspi_ospi_instance_ctrl_t * p_instance_ctrl = (xspi_ospi_instance_ctrl_t *) p_ctrl;

#if XSPI_OSPI_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_OSPI_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    spi_flash_cfg_t          * p_cfg        = (spi_flash_cfg_t *) p_instance_ctrl->p_cfg;
    xspi_ospi_extended_cfg_t * p_cfg_extend = (xspi_ospi_extended_cfg_t *) p_cfg->p_extend;

    g_xspi_ospi_channels_open_flags &= ~(1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select));

    if ((g_xspi_ospi_channels_open_flags & (XSPI_OSPI_UNIT_FLAG_MASK << (p_cfg_extend->unit << 1U))) == 0)
    {
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

#if BSP_FEATURE_XSPI_HAS_XSPI_MISC2

        /* Module stop request */
        R_XSPI_MISC2->MSTP_CTRL_XSPI |= XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_MASK <<
                                        (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit);
        FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                     (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                    XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK),
                                   XSPI_OSPI_PRV_MSTP_CTRL_MODULE_STOP_ACK_MASK);

        /* Bus stop request */
        R_XSPI_MISC2->MSTP_CTRL_XSPI |= XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_MASK <<
                                        (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit);
        FSP_HARDWARE_REGISTER_WAIT(((R_XSPI_MISC2->MSTP_CTRL_XSPI >>
                                     (XSPI_OSPI_PRV_MSTP_CTRL_UNIT_OFFSET * p_cfg_extend->unit)) &
                                    XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK),
                                   XSPI_OSPI_PRV_MSTP_CTRL_BUS_STOP_ACK_MASK);
#endif

#if BSP_FEATURE_BSP_SLAVE_STOP_SUPPORTED

        /* Slave stop request */
        if (0U == p_cfg_extend->unit)
        {
            R_BSP_SlaveStop(BSP_BUS_SLAVE_XSPI0);
        }
        else
        {
            R_BSP_SlaveStop(BSP_BUS_SLAVE_XSPI1);
        }
#endif
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

        /* Enable reset */
        if (0U == p_cfg_extend->unit)
        {
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_XSPI0);
        }
        else
        {
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_XSPI1);
        }

        /* Disable clock to the OSPI block */
        R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    }

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup XSPI_OSPI)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Perform initialization based on SPI/OPI protocol
 *
 * @param[in]   p_instance_ctrl    Pointer to OSPI specific control structure
 * @param[in]   spi_protocol       SPI/OPI protocol request
 *
 * @retval      FSP_SUCCESS                Protocol based settings completed successfully.
 * @retval      FSP_ERR_CALIBRATE_FAILED   Auto-Calibration failed.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_ospi_spi_protocol_specific_settings (xspi_ospi_instance_ctrl_t * p_instance_ctrl,
                                                             spi_flash_protocol_t        spi_protocol)
{
    spi_flash_cfg_t const    * p_cfg        = p_instance_ctrl->p_cfg;
    xspi_ospi_extended_cfg_t * p_cfg_extend = (xspi_ospi_extended_cfg_t *) p_cfg->p_extend;
    fsp_err_t               ret             = FSP_SUCCESS;
    xspi_ospi_chip_select_t chip_select     = p_instance_ctrl->chip_select;

    /* Update the SPI protocol. */
    p_instance_ctrl->p_reg->LIOCFGCS_b[p_cfg_extend->chip_select].PRTMD = spi_protocol &
                                                                          XSPI_OSPI_PRV_LIOCFGCS_PRTMD_MASK;

    /* Specifies the read/write commands and Read dummy clocks for Device
     * (see RZ microprocessor Hardware Manual section "Flow of Memory-mapping"). */
    if ((SPI_FLASH_PROTOCOL_1S_1S_1S == spi_protocol))
    {
        uint32_t cmcfg0 =
            (0U << XSPI_OSPI_PRV_CMCFG0_FFMT_OFFSET) |
            ((p_cfg->address_bytes & XSPI_OSPI_PRV_CMCFG0_ADDSIZE_VALUE_MASK) << XSPI_OSPI_PRV_CMCFG0_ADDSIZE_OFFSET) |
            ((p_cfg_extend->wrap_separate & XSPI_OSPI_PRV_CMCFG0_WPBSTMD_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG0_WPBSTMD_OFFSET) |
            ((p_cfg_extend->address_msb_mask & XSPI_OSPI_PRV_CMCFG0_ADDRPEN_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG0_ADDRPEN_OFFSET);

        p_instance_ctrl->p_reg->CSa[chip_select].CMCFG0 = cmcfg0;

        p_instance_ctrl->p_reg->CSa[chip_select].CMCFG1 =
            ((p_cfg->read_command & XSPI_OSPI_PRV_CMCFG1_RDCMD_1B_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG1_RDCMD_UPPER_OFFSET) |
            ((p_cfg->dummy_clocks & XSPI_OSPI_PRV_CMCFG1_RDLATE_VALUE_MASK) << XSPI_OSPI_PRV_CMCFG1_RDLATE_OFFSET);

        p_instance_ctrl->p_reg->CSa[chip_select].CMCFG2 =
            ((p_cfg->page_program_command & XSPI_OSPI_PRV_CMCFG2_WRCMD_1B_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG2_WRCMD_UPPER_OFFSET) |
            (0 << XSPI_OSPI_PRV_CMCFG2_WRLATE_OFFSET);
    }
    else
    {
        xspi_ospi_opi_command_set_t const * p_opi_commands = p_cfg_extend->p_opi_commands;
        uint32_t cmcfg0 =
            (1U << XSPI_OSPI_PRV_CMCFG0_FFMT_OFFSET) |
            ((p_cfg->address_bytes & XSPI_OSPI_PRV_CMCFG0_ADDSIZE_VALUE_MASK) << XSPI_OSPI_PRV_CMCFG0_ADDSIZE_OFFSET) |
            ((p_cfg_extend->wrap_separate & XSPI_OSPI_PRV_CMCFG0_WPBSTMD_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG0_WPBSTMD_OFFSET) |
            ((p_cfg_extend->address_msb_mask & XSPI_OSPI_PRV_CMCFG0_ADDRPEN_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG0_ADDRPEN_OFFSET);

        p_instance_ctrl->p_reg->CSa[chip_select].CMCFG0 = cmcfg0;

        p_instance_ctrl->p_reg->CSa[chip_select].CMCFG1 =
            ((p_opi_commands->dual_read_command & XSPI_OSPI_PRV_CMCFG1_RDCMD_2B_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG1_RDCMD_OFFSET) |
            ((p_cfg_extend->opi_mem_read_dummy_cycles & XSPI_OSPI_PRV_CMCFG1_RDLATE_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG1_RDLATE_OFFSET);

        p_instance_ctrl->p_reg->CSa[chip_select].CMCFG2 =
            ((p_opi_commands->page_program_command & XSPI_OSPI_PRV_CMCFG2_WRCMD_2B_VALUE_MASK) <<
                XSPI_OSPI_PRV_CMCFG2_WRCMD_OFFSET) |
            (0 << XSPI_OSPI_PRV_CMCFG2_WRLATE_OFFSET);

        /* Perform Automatic Calibration to appropriately update WRAPCFG DSSFTCSn field. */
        if (0 == p_cfg_extend->data_latch_delay_clocks)
        {
            ret = r_xspi_ospi_automatic_calibration_seq(p_instance_ctrl);
        }
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Gets device status.
 *
 * @param[in]  p_instance_ctrl         Pointer to a driver handle
 * @param[in]  bit_pos                 Write-in-progress bit position
 *
 * @return True if busy, false if not.
 **********************************************************************************************************************/
static bool r_xspi_ospi_status_sub (xspi_ospi_instance_ctrl_t * p_instance_ctrl, uint8_t bit_pos)
{
    spi_flash_cfg_t const     * p_cfg          = p_instance_ctrl->p_cfg;
    spi_flash_direct_transfer_t direct_command = {0};

    if (SPI_FLASH_PROTOCOL_1S_1S_1S == p_instance_ctrl->spi_protocol)
    {
        direct_command.command        = p_cfg->status_command;
        direct_command.command_length = 1U;
    }
    else
    {
        xspi_ospi_opi_command_set_t const * p_opi_commands =
            ((xspi_ospi_extended_cfg_t *) p_cfg->p_extend)->p_opi_commands;
        direct_command.command        = p_opi_commands->status_command;
        direct_command.command_length = p_opi_commands->command_bytes;
        direct_command.address_length = (p_cfg->address_bytes + 1U) &
                                        XSPI_OSPI_PRV_DIRECT_ADDR_AND_DATA_MASK;
        direct_command.dummy_cycles = 4U;
    }

    direct_command.data_length = 1U;
    r_xspi_ospi_direct_transfer(p_instance_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_READ);

    return (direct_command.data >> bit_pos) & 1U;
}

/*******************************************************************************************************************//**
 * Send Write enable command to the OctaFlash
 *
 * @param[in]   p_instance_ctrl    Pointer to OSPI specific control structure
 *
 * @retval      FSP_SUCCESS                Write operation completed.
 * @retval      FSP_ERR_WRITE_FAILED       Write operation failed.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_ospi_write_enable (xspi_ospi_instance_ctrl_t * p_instance_ctrl)
{
    spi_flash_direct_transfer_t direct_command = {0};
    spi_flash_cfg_t const     * p_cfg          = p_instance_ctrl->p_cfg;

    if ((SPI_FLASH_PROTOCOL_1S_1S_1S == p_instance_ctrl->spi_protocol))
    {
        direct_command.command        = p_cfg->write_enable_command;
        direct_command.command_length = 1U;
    }
    else
    {
        xspi_ospi_opi_command_set_t const * p_opi_commands =
            ((xspi_ospi_extended_cfg_t *) p_cfg->p_extend)->p_opi_commands;
        direct_command.command        = p_opi_commands->write_enable_command;
        direct_command.command_length = p_opi_commands->command_bytes;
    }

    /* If the command is 0x00, then skip sending the write enable. */
    if (0 == p_cfg->write_enable_command)
    {
        return FSP_SUCCESS;
    }

    r_xspi_ospi_direct_transfer(p_instance_ctrl, &direct_command, SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE);

    /* In case write enable is not checked, assume write is enabled. */
    bool write_enabled = true;

#if XSPI_OSPI_MAX_WRITE_ENABLE_LOOPS > 0U

    /* Verify write is enabled. */
    for (uint32_t i = 0U; i < XSPI_OSPI_MAX_WRITE_ENABLE_LOOPS; i++)
    {
        write_enabled = r_xspi_ospi_status_sub(p_instance_ctrl, p_instance_ctrl->p_cfg->write_enable_bit);
        if (write_enabled)
        {
            break;
        }
    }
#endif

    FSP_ERROR_RETURN(write_enabled, FSP_ERR_WRITE_FAILED);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Perform Automatic Calibration
 *
 * @param[in]   p_instance_ctrl    Pointer to OSPI specific control structure
 *
 * @retval      FSP_SUCCESS                Auto-Calibration completed successfully.
 * @retval      FSP_ERR_CALIBRATE_FAILED   Auto-Calibration failed.
 **********************************************************************************************************************/
static fsp_err_t r_xspi_ospi_automatic_calibration_seq (xspi_ospi_instance_ctrl_t * p_instance_ctrl)
{
    fsp_err_t                           ret            = FSP_SUCCESS;
    spi_flash_cfg_t                   * p_cfg          = (spi_flash_cfg_t *) p_instance_ctrl->p_cfg;
    xspi_ospi_extended_cfg_t          * p_cfg_extend   = (xspi_ospi_extended_cfg_t *) p_cfg->p_extend;
    xspi_ospi_opi_command_set_t const * p_opi_commands = p_cfg_extend->p_opi_commands;

    xspi_ospi_chip_select_t chip_select = p_instance_ctrl->chip_select;

    uint32_t timeout = XSPI_OSPI_PRV_AUTOCALIBRATION_TIMEOUT_US;

    /* Perform Automatic Calibration
     * (see RZ microprocessor Hardware Manual section "Flow of Automatic Calibration") */

    /* Check no callibration run. */
    if (0 != p_instance_ctrl->p_reg->CSb[chip_select].CCCTL0_b.CAEN)
    {
        ret = FSP_ERR_CALIBRATE_FAILED;
    }
    else
    {
        p_instance_ctrl->p_reg->CSb[chip_select].CCCTL1 =
            ((p_opi_commands->command_bytes & XSPI_OSPI_PRV_CCCTL1_CACMDSIZE_VALUE_MASK) <<
                XSPI_OSPI_PRV_CCCTL1_CACMDSIZE_OFFSET) |
            (((p_cfg->address_bytes + 1U) & XSPI_OSPI_PRV_CCCTL1_CAADDSIZE_VALUE_MASK) <<
                XSPI_OSPI_PRV_CCCTL1_CAADDSIZE_OFFSET) |
            (0xF << XSPI_OSPI_PRV_CCCTL1_CADATASIZE_OFFSET) |
            (0 << XSPI_OSPI_PRV_CCCTL1_CAWRLATE_OFFSET) |
            ((p_cfg_extend->opi_mem_read_dummy_cycles & XSPI_OSPI_PRV_CCCTL1_CARDLATE_VALUE_MASK) <<
                XSPI_OSPI_PRV_CCCTL1_CARDLATE_OFFSET);

        p_instance_ctrl->p_reg->CSb[chip_select].CCCTL2 =
            ((p_opi_commands->dual_read_command & XSPI_OSPI_PRV_CCCTL2_CARDCMD_VALUE_MASK) <<
                XSPI_OSPI_PRV_CCCTL2_CARDCMD_OFFSET);
        p_instance_ctrl->p_reg->CSb[chip_select].CCCTL3 =
            (uint32_t) (uintptr_t) p_cfg_extend->p_autocalibration_preamble_pattern_addr &
            XSPI_OSPI_PRV_ADDRESS_REPLACE_MASK;

        if (XSPI_OSPI_BYTE_ORDER_1032 == p_cfg_extend->byte_order)
        {
            /* Apply byte_order_rev to match the preamble pattern with the data to be read in the auto calibration sequence. */
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL4 = byte_order_rev(
                XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_0);
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL5 = byte_order_rev(
                XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_1);
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL6 = byte_order_rev(
                XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_2);
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL7 = byte_order_rev(
                XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_3);
        }
        else
        {
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL4 = XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_0;
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL5 = XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_1;
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL6 = XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_2;
            p_instance_ctrl->p_reg->CSb[chip_select].CCCTL7 = XSPI_OSPI_PRV_AUTOCALIBRATION_PREAMBLE_PATTERN_3;
        }

        p_instance_ctrl->p_reg->CSb[chip_select].CCCTL0 = (1 << XSPI_OSPI_PRV_CCCTL0_CANOWR_OFFSET) |
                                                          (0x1F << XSPI_OSPI_PRV_CCCTL0_CAITV_OFFSET) |
                                                          (0 << XSPI_OSPI_PRV_CCCTL0_CASFTSTA_OFFSET) |
                                                          (0x1F << XSPI_OSPI_PRV_CCCTL0_CASFTEND_OFFSET);

        /* Automatic Calibration Enable */
        p_instance_ctrl->p_reg->CSb[chip_select].CCCTL0_b.CAEN = 1;

        /* Check calibration success or failure. */
        while (timeout)
        {
            if ((1 == ((p_instance_ctrl->p_reg->INTS >> (R_XSPI0_INTS_CASUCCS0_Pos + chip_select)) & 0x01)) ||
                (1 == ((p_instance_ctrl->p_reg->INTS >> (R_XSPI0_INTS_CAFAILCS0_Pos + chip_select)) & 0x01)))
            {
                break;
            }

            timeout--;
            R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        }

        /* Disable automatic calibration */
        p_instance_ctrl->p_reg->CSb[chip_select].CCCTL0_b.CAEN = 0;

        if (0 == timeout)
        {
            ret = FSP_ERR_CALIBRATE_FAILED;
        }
        else if (1 == ((p_instance_ctrl->p_reg->INTS >> (R_XSPI0_INTS_CASUCCS0_Pos + chip_select)) & 0x01))
        {
            /* Clear automatic calibration success status */
            p_instance_ctrl->p_reg->INTC = (uint32_t) 1 << (R_XSPI0_INTC_CASUCCS0C_Pos + chip_select);
        }
        else if (1 == ((p_instance_ctrl->p_reg->INTS >> (R_XSPI0_INTS_CAFAILCS0_Pos + chip_select)) & 0x01))
        {
            ret = FSP_ERR_CALIBRATE_FAILED;

            /* Clear automatic calibration failure status */
            p_instance_ctrl->p_reg->INTC = (uint32_t) 1 << (R_XSPI0_INTC_CAFAILCS0C_Pos + chip_select);
        }
        else
        {
            /* Do nothing. */
        }
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Performs direct data transfer with the OctaFlash
 *
 * @param[in]   p_instance_ctrl    Pointer to OSPI specific control structure
 * @param[in]   p_transfer         Pointer to transfer parameters
 * @param[in]   direction          Read/Write
 **********************************************************************************************************************/
static void r_xspi_ospi_direct_transfer (xspi_ospi_instance_ctrl_t         * p_instance_ctrl,
                                         spi_flash_direct_transfer_t * const p_transfer,
                                         spi_flash_direct_transfer_dir_t     direction)
{
    xspi_ospi_extended_cfg_t * p_cfg_extend = (xspi_ospi_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;
    p_instance_ctrl->p_reg->CDCTL0_b.TRNUM = 0;
    p_instance_ctrl->p_reg->CDCTL0_b.CSSEL = p_instance_ctrl->chip_select;

    /* Direct Read/Write settings
     * (see RZ microprocessor Hardware Manual section "Flow of Manual-command Procedure"). */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CDCTL0_b.TRREQ, 0);

    uint32_t cdtbuf0 =
        ((p_transfer->command_length & XSPI_OSPI_PRV_CDTBUF_CMDSIZE_VALUE_MASK) <<
            XSPI_OSPI_PRV_CDTBUF_CMDSIZE_OFFSET) |
        ((p_transfer->address_length & XSPI_OSPI_PRV_CDTBUF_ADDSIZE_VALUE_MASK) <<
            XSPI_OSPI_PRV_CDTBUF_ADDSIZE_OFFSET) |
        ((p_transfer->data_length & XSPI_OSPI_PRV_CDTBUF_DATASIZE_VALUE_MASK) <<
            XSPI_OSPI_PRV_CDTBUF_DATASIZE_OFFSET) |
        ((p_transfer->dummy_cycles & XSPI_OSPI_PRV_CDTBUF_LATE_VALUE_MASK) <<
            XSPI_OSPI_PRV_CDTBUF_LATE_OFFSET) |
        ((direction & XSPI_OSPI_PRV_CDTBUF_TRTYPE_VALUE_MASK) <<
            XSPI_OSPI_PRV_CDTBUF_TRTYPE_OFFSET);

    cdtbuf0 |= (1 == p_transfer->command_length) ?
               ((p_transfer->command & XSPI_OSPI_PRV_CDTBUF_CMD_1B_VALUE_MASK) <<
                XSPI_OSPI_PRV_CDTBUF_CMD_UPPER_OFFSET) :
               ((p_transfer->command & XSPI_OSPI_PRV_CDTBUF_CMD_2B_VALUE_MASK) << XSPI_OSPI_PRV_CDTBUF_CMD_OFFSET);

    p_instance_ctrl->p_reg->BUF[0].CDT = cdtbuf0;

    p_instance_ctrl->p_reg->BUF[0].CDA = p_transfer->address;

    if (SPI_FLASH_DIRECT_TRANSFER_DIR_WRITE == direction)
    {
        if ((1U < p_transfer->data_length) &&
            (XSPI_OSPI_BYTE_ORDER_1032 == p_cfg_extend->byte_order) &&
            (SPI_FLASH_PROTOCOL_8D_8D_8D == p_instance_ctrl->spi_protocol))
        {
            /* Apply byte_order_rev to convert the data to match the OctaFlash byte order. */
            p_instance_ctrl->p_reg->BUF[0].CDD0 = byte_order_rev(p_transfer->data_u64 & UINT32_MAX);
            if (p_transfer->data_length > sizeof(uint32_t))
            {
                p_instance_ctrl->p_reg->BUF[0].CDD1 =
                    byte_order_rev((uint32_t) (p_transfer->data_u64 >> XSPI_OSPI_PRV_UINT32_BITS) & UINT32_MAX);
            }
        }
        else
        {
            p_instance_ctrl->p_reg->BUF[0].CDD0 = (uint32_t) p_transfer->data_u64 & UINT32_MAX;
            if (p_transfer->data_length > sizeof(uint32_t))
            {
                p_instance_ctrl->p_reg->BUF[0].CDD1 = (uint32_t) (p_transfer->data_u64 >> XSPI_OSPI_PRV_UINT32_BITS) &
                                                      UINT32_MAX;
            }
        }
    }

    p_instance_ctrl->p_reg->CDCTL0_b.TRREQ = 1;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->INTS_b.CMDCMP, 1);

    if (SPI_FLASH_DIRECT_TRANSFER_DIR_READ == direction)
    {
        if ((1U < p_transfer->data_length) &&
            (XSPI_OSPI_BYTE_ORDER_1032 == p_cfg_extend->byte_order) &&
            (SPI_FLASH_PROTOCOL_8D_8D_8D == p_instance_ctrl->spi_protocol))
        {
            /* Apply byte_order_rev to convert the data to match the OctaFlash byte order. */
            p_transfer->data_u64 = byte_order_rev(p_instance_ctrl->p_reg->BUF[0].CDD0);
            if (p_transfer->data_length > sizeof(uint32_t))
            {
                p_transfer->data_u64 |= (uint64_t) (byte_order_rev(p_instance_ctrl->p_reg->BUF[0].CDD1)) <<
                                        XSPI_OSPI_PRV_UINT32_BITS;
            }
        }
        else
        {
            p_transfer->data_u64 = p_instance_ctrl->p_reg->BUF[0].CDD0;
            if (p_transfer->data_length > sizeof(uint32_t))
            {
                p_transfer->data_u64 |= (uint64_t) (p_instance_ctrl->p_reg->BUF[0].CDD1) << XSPI_OSPI_PRV_UINT32_BITS;
            }
        }
    }

    p_instance_ctrl->p_reg->INTC = 1 << XSPI_OSPI_PRV_INTC_CMDCMPC_OFFSET;
}

/*******************************************************************************************************************//**
 * Reverse byte order (16bit) to fit slave devices which byte order is byte1, byte0, byte3, byte2.
 *
 * @param[in]   value            32-bit data to be sent to or received from the slave device.
 *
 * @return      Byte order reversed value.
 **********************************************************************************************************************/
static uint32_t byte_order_rev (uint32_t value)
{
    return ((value & XSPI_OSPI_PRV_REV16_DECREMENT_BYTES_MASK) >> XSPI_OSPI_PRV_REV16_BYTES_SHIFT) |
           ((value & XSPI_OSPI_PRV_REV16_INCREMENT_BYTES_MASK) << XSPI_OSPI_PRV_REV16_BYTES_SHIFT);
}
