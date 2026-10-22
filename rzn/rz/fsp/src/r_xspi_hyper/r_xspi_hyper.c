/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_xspi_hyper.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define XSPI_HYPER_PRV_OPEN                                    (0x48595045)

#define XSPI_HYPER_PRV_WRAPCFG_DSSFTCS0_OFFSET                 (8U)
#define XSPI_HYPER_PRV_WRAPCFG_DSSFTCS0_VALUE_MASK             (0x1FU)
#define XSPI_HYPER_PRV_WRAPCFG_DSSFTCS1_OFFSET                 (24U)
#define XSPI_HYPER_PRV_WRAPCFG_DSSFTCS1_VALUE_MASK             (0x1FU)

#define XSPI_HYPER_PRV_LIOCFGCS_PRTMD_OFFSET                   (0U)
#define XSPI_HYPER_PRV_LIOCFGCS_PRTMD_VALUE_MASK               (0x3FFU)
#define XSPI_HYPER_PRV_LIOCFGCS_PRTMD_PROTOCOL_8D_8D_8D        (0x3FFU)
#define XSPI_HYPER_PRV_LIOCFGCS_LATEMD_OFFSET                  (10U)
#define XSPI_HYPER_PRV_LIOCFGCS_LATEMD_VALUE_MASK              (0x01U)
#define XSPI_HYPER_PRV_LIOCFGCS_LATEMD_VARIABLE_LATENCY        (1U)
#define XSPI_HYPER_PRV_LIOCFGCS_WRMSKMD_OFFSET                 (11U)
#define XSPI_HYPER_PRV_LIOCFGCS_WRMSKMD_VALUE_MASK             (0x01U)
#define XSPI_HYPER_PRV_LIOCFGCS_WRMSKMD_WRITE_MASK_ENABLE      (1U)
#define XSPI_HYPER_PRV_LIOCFGCS_CSMIN_OFFSET                   (16U)
#define XSPI_HYPER_PRV_LIOCFGCS_CSMIN_VALUE_MASK               (0x0FU)
#define XSPI_HYPER_PRV_LIOCFGCS_CSASTEX_OFFSET                 (20U)
#define XSPI_HYPER_PRV_LIOCFGCS_CSASTEX_VALUE_MASK             (0x01U)
#define XSPI_HYPER_PRV_LIOCFGCS_CSENGEX_OFFSET                 (21U)
#define XSPI_HYPER_PRV_LIOCFGCS_CSENGEX_VALUE_MASK             (0x01U)

#define XSPI_HYPER_PRV_CMCFG0_DEFAULT_VALUE                    (0x00F0000FU)
#define XSPI_HYPER_PRV_CMCFG0_WPBSTMD_OFFSET                   (4U)
#define XSPI_HYPER_PRV_CMCFG0_WPBSTMD_VALUE_MASK               (0x01U)
#define XSPI_HYPER_PRV_CMCFG0_ADDRPEN_OFFSET                   (16U)
#define XSPI_HYPER_PRV_CMCFG0_ADDRPEN_VALUE_MASK               (0xFFU)

#define XSPI_HYPER_PRV_CMCFG1_ACCESS_MEMORY                    (0xFFFFBFFFU)
#define XSPI_HYPER_PRV_CMCFG1_ACCESS_REGISETR                  (0x00004000U)
#define XSPI_HYPER_PRV_CMCFG1_ACCESS_WRAP                      (0xFFFFDFFFU)
#define XSPI_HYPER_PRV_CMCFG1_ACCESS_LINEAR                    (0x00002000U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_ACCESS_MEMORY              (0xBFFFU)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_ACCESS_REGISETR            (0x4000U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_15TH_BIT_OFFSET            (15U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_15TH_BIT_VALUE_MASK        (0x1U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_14TH_BIT_OFFSET            (14U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_14TH_BIT_VALUE_MASK        (0x1U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_13TH_BIT_OFFSET            (13U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_13TH_BIT_VALUE_MASK        (0x1U)
#define XSPI_HYPER_PRV_CMCFG1_RDCMD_HYPERBUS_READ              (1U)
#define XSPI_HYPER_PRV_CMCFG1_RDLATE_OFFSET                    (16U)
#define XSPI_HYPER_PRV_CMCFG1_RDLATE_VALUE_MASK                (0x1FU)

#define XSPI_HYPER_PRV_CMCFG2_ACCESS_MEMORY                    (0xFFFFBFFFU)
#define XSPI_HYPER_PRV_CMCFG2_ACCESS_REGISETR                  (0x00004000U)
#define XSPI_HYPER_PRV_CMCFG2_ACCESS_WRAP                      (0xFFFFDFFFU)
#define XSPI_HYPER_PRV_CMCFG2_ACCESS_LINEAR                    (0x00002000U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_ACCESS_MEMORY              (0xBFFFU)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_ACCESS_REGISETR            (0x4000U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_15TH_BIT_OFFSET            (15U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_15TH_BIT_VALUE_MASK        (0x1U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_14TH_BIT_OFFSET            (14U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_14TH_BIT_VALUE_MASK        (0x1U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_13TH_BIT_OFFSET            (13U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_13TH_BIT_VALUE_MASK        (0x1U)
#define XSPI_HYPER_PRV_CMCFG2_WRCMD_HYPERBUS_WRITE             (0U)
#define XSPI_HYPER_PRV_CMCFG2_WRLATE_OFFSET                    (16U)
#define XSPI_HYPER_PRV_CMCFG2_WRLATE_VALUE_MASK                (0x1FU)

#define XSPI_HYPER_PRV_BMCFG_WRMD_OFFSET                       (0U)
#define XSPI_HYPER_PRV_BMCFG_MWRCOMB_OFFSET                    (7U)
#define XSPI_HYPER_PRV_BMCFG_MWRSIZE_OFFSET                    (8U)
#define XSPI_HYPER_PRV_BMCFG_PREEN_OFFSET                      (16U)
#define XSPI_HYPER_PRV_BMCFG_PREEN_VALUE_MASK                  (0x01U)

#define XSPI_HYPER_PRV_BMCTL_DEFAULT_VALUE                     (0x000000FFUL)

#define XSPI_HYPER_PRV_CDTBUF_CMDSIZE_OFFSET                   (0U)
#define XSPI_HYPER_PRV_CDTBUF_CMDSIZE_VALUE_MASK               (0x03U)
#define XSPI_HYPER_PRV_CDTBUF_ADDSIZE_OFFSET                   (2U)
#define XSPI_HYPER_PRV_CDTBUF_ADDSIZE_VALUE_MASK               (0x07U)
#define XSPI_HYPER_PRV_CDTBUF_DATASIZE_OFFSET                  (5U)
#define XSPI_HYPER_PRV_CDTBUF_DATASIZE_VALUE_MASK              (0x0FU)
#define XSPI_HYPER_PRV_CDTBUF_LATE_OFFSET                      (9U)
#define XSPI_HYPER_PRV_CDTBUF_LATE_VALUE_MASK                  (0x1FU)
#define XSPI_HYPER_PRV_CDTBUF_TRTYPE_OFFSET                    (15U)
#define XSPI_HYPER_PRV_CDTBUF_TRTYPE_VALUE_MASK                (0x01U)
#define XSPI_HYPER_PRV_CDTBUF_CMD_OFFSET                       (16U)
#define XSPI_HYPER_PRV_CDTBUF_CMD_UPPER_OFFSET                 (24U)
#define XSPI_HYPER_PRV_CDTBUF_CMD_1B_VALUE_MASK                (0xFFU)
#define XSPI_HYPER_PRV_CDTBUF_CMD_2B_VALUE_MASK                (0xFFFFU)

#define XSPI_HYPER_PRV_CCCTL0_CANOWR_OFFSET                    (1U)
#define XSPI_HYPER_PRV_CCCTL0_CAITV_OFFSET                     (8U)
#define XSPI_HYPER_PRV_CCCTL0_CASFTSTA_OFFSET                  (16U)
#define XSPI_HYPER_PRV_CCCTL0_CASFTEND_OFFSET                  (24U)

#define XSPI_HYPER_PRV_CCCTL1_CACMDSIZE_OFFSET                 (0U)
#define XSPI_HYPER_PRV_CCCTL1_CACMDSIZE_VALUE_MASK             (0x3U)
#define XSPI_HYPER_PRV_CCCTL1_CAADDSIZE_OFFSET                 (2U)
#define XSPI_HYPER_PRV_CCCTL1_CAADDSIZE_VALUE_MASK             (0x7U)
#define XSPI_HYPER_PRV_CCCTL1_CADATASIZE_OFFSET                (5U)
#define XSPI_HYPER_PRV_CCCTL1_CAWRLATE_OFFSET                  (16U)
#define XSPI_HYPER_PRV_CCCTL1_CAWRLATE_VALUE_MASK              (0x1FU)
#define XSPI_HYPER_PRV_CCCTL1_CARDLATE_OFFSET                  (24U)
#define XSPI_HYPER_PRV_CCCTL1_CARDLATE_VALUE_MASK              (0x1FU)

#define XSPI_HYPER_PRV_CCCTL2_DEFAULT_VALUE                    (0xA0002000U)

#define XSPI_HYPER_PRV_ADDRESS_REPLACE_VALUE                   (0xF0)
#define XSPI_HYPER_PRV_ADDRESS_REPLACE_ENABLE_BITS             (XSPI_HYPER_PRV_ADDRESS_REPLACE_VALUE << \
                                                                XSPI_HYPER_PRV_CMCFG0_ADDRPEN_OFFSET)

#define XSPI_HYPER_PRV_INTC_CMDCMPC_OFFSET                     (0U)
#define XSPI_HYPER_PRV_AUTOCALIBARION_PREAMBLE_PATTERN_0       (0xFFFF0000)
#define XSPI_HYPER_PRV_AUTOCALIBARION_PREAMBLE_PATTERN_1       (0x000800FF)
#define XSPI_HYPER_PRV_AUTOCALIBARION_PREAMBLE_PATTERN_2       (0x00FFF700)
#define XSPI_HYPER_PRV_AUTOCALIBARION_PREAMBLE_PATTERN_3       (0xF700F708)

#define XSPI_HYPER_PRV_CDTBUF_CMDSIZE_2_BYTES                  (0x02U)
#define XSPI_HYPER_PRV_CDTBUF_ADDSIZE_4_BYTES                  (0x04U)

#define XSPI_HYPER_PRV_COMMAND_ADDRESS_FOR_CDTBUF_SHIFT        (32U)
#define XSPI_HYPER_PRV_COMMAND_ADDRESS_FOR_CDABUF_MASK         (0x00000000FFFFFFFF)
#define XSPI_HYPER_PRV_COMMAND_ADDRESS_MASK                    (0x0000FFFFFFFFFFFF)

#define XSPI_HYPER_PRV_1MB_MEMORY_SPACE                        (0xFFFFF)
#define XSPI_HYPER_PRV_MEMORY_SIZE_SHIFT                       (20U)
#define XSPI_HYPER_PRV_UNIT_FLAG_MASK                          (3U)

#define XSPI_HYPER_PRV_UINT32_BITS                             (32)

#define XSPI_HYPER_PRV_1MB_MEMORY_SIZE                         (0x100000)
#define XSPI_HYPER_PRV_2MB_MEMORY_SIZE                         (0x200000)
#define XSPI_HYPER_PRV_4MB_MEMORY_SIZE                         (0x400000)
#define XSPI_HYPER_PRV_8MB_MEMORY_SIZE                         (0x800000)
#define XSPI_HYPER_PRV_16MB_MEMORY_SIZE                        (0x1000000)
#define XSPI_HYPER_PRV_32MB_MEMORY_SIZE                        (0x2000000)
#define XSPI_HYPER_PRV_64MB_MEMORY_SIZE                        (0x4000000)

#define XSPI_HYPER_UNIT_FLAG_MASK                              (3U)

#define XSPI_HYPER_PRV_WORD_SIZE                               (2)
#define XSPI_HYPER_PRV_ODD_ADDRESS_BIT_MASK                    (1)
#define XSPI_HYPER_PRV_WORD_PROGRAM_1ST_ADDRESS                (0x555)
#define XSPI_HYPER_PRV_WORD_PROGRAM_1ST_DATA                   (0xAA)
#define XSPI_HYPER_PRV_WORD_PROGRAM_2ND_ADDRESS                (0x2AA)
#define XSPI_HYPER_PRV_WORD_PROGRAM_2ND_DATA                   (0x55)
#define XSPI_HYPER_PRV_WORD_PROGRAM_3RD_ADDRESS                (0x555)
#define XSPI_HYPER_PRV_WORD_PROGRAM_3RD_DATA                   (0xA0)

#define XSPI_HYPER_PRV_WRITE_BUFFER_1ST_ADDRESS                (0x555)
#define XSPI_HYPER_PRV_WRITE_BUFFER_1ST_DATA                   (0xAA)
#define XSPI_HYPER_PRV_WRITE_BUFFER_2ND_ADDRESS                (0x2AA)
#define XSPI_HYPER_PRV_WRITE_BUFFER_2ND_DATA                   (0x55)
#define XSPI_HYPER_PRV_WRITE_BUFFER_3RD_DATA                   (0x25)
#define XSPI_HYPER_PRV_PROGRAM_BUFFER_TO_FLASH_DATA            (0x29)

#define XSPI_HYPER_PRV_WRITE_PADDING_BYTE_DATA                 (0xFF)
#define XSPI_HYPER_PRV_BYTE_SHIFT                              (8)

#define XSPI_HYPER_PRV_ERASE_1ST_ADDRESS                       (0x555U)
#define XSPI_HYPER_PRV_ERASE_1ST_DATA                          (0xAAU)
#define XSPI_HYPER_PRV_ERASE_2ND_ADDRESS                       (0x2AAU)
#define XSPI_HYPER_PRV_ERASE_2ND_DATA                          (0x55U)
#define XSPI_HYPER_PRV_ERASE_3RD_ADDRESS                       (0x555U)
#define XSPI_HYPER_PRV_ERASE_3RD_DATA                          (0x80U)
#define XSPI_HYPER_PRV_ERASE_4TH_ADDRESS                       (0x555U)
#define XSPI_HYPER_PRV_ERASE_4TH_DATA                          (0xAAU)
#define XSPI_HYPER_PRV_ERASE_5TH_ADDRESS                       (0x2AAU)
#define XSPI_HYPER_PRV_ERASE_5TH_DATA                          (0x55U)
#define XSPI_HYPER_PRV_SECTOR_ERASE_6TH_DATA                   (0x30U)
#define XSPI_HYPER_PRV_CHIP_ERASE_6TH_ADDRESS                  (0x555U)
#define XSPI_HYPER_PRV_CHIP_ERASE_6TH_DATA                     (0x10U)

#define XSPI_HYPER_STATUS_REGISTER_READ_1ST_COMMAND_ADDRESS    (0x200000AA0005)
#define XSPI_HYPER_STATUS_REGISTER_READ_1ST_DATA               (0x70U)
#define XSPU_HYPER_DEVICE_READY_BIT_MASK                       (0x80U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Select flash erase size  */
typedef enum e_xspi_hyper_flash_erase_size
{
    XSPI_HYPER_FLASH_ERASE_SIZE_SECTOR = 0,
    XSPI_HYPER_FLASH_ERASE_SIZE_CHIP   = 1,
    XSPI_HYPER_FLASH_ERASE_SIZE_ERROR  = 0xFF,
} xspi_hyper_flash_erase_size_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static bool r_xspi_hyper_status_sub(xspi_hyper_instance_ctrl_t * const p_instance_ctrl);
static void r_xspi_hyper_direct_transfer(xspi_hyper_instance_ctrl_t * const p_instance_ctrl,
                                         hyperbus_direct_transfer_t * const p_transfer);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Bit-flags specifying which channels are open so the module can be stopped when all are closed. */
static uint32_t g_xspi_hyper_channels_open_flags = 0;

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_XSPI_HYPER
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

const hyperbus_api_t g_hyperbus_on_xspi_hyper =
{
    .open           = R_XSPI_HYPER_Open,
    .burstTypeSet   = R_XSPI_HYPER_BurstTypeSet,
    .accessSpaceSet = R_XSPI_HYPER_AccessSpaceSet,
    .directTransfer = R_XSPI_HYPER_DirectTransfer,
    .write          = R_XSPI_HYPER_Write,
    .erase          = R_XSPI_HYPER_Erase,
    .statusGet      = R_XSPI_HYPER_StatusGet,
    .autoCalibrate  = R_XSPI_HYPER_AutoCalibrate,
    .close          = R_XSPI_HYPER_Close,
};

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Open the HYPER driver module. After the driver is open, the HyperRAM or HyperFlash can be accessed like internal memory.
 *
 * Implements @ref hyperbus_api_t::open.
 *
 * @retval FSP_SUCCESS              Configuration was successful.
 * @retval FSP_ERR_ASSERTION        The parameter p_ctrl or p_cfg is NULL.
 * @retval FSP_ERR_ALREADY_OPEN     Driver has already been opened with the same p_ctrl.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_Open (hyperbus_ctrl_t * p_ctrl, hyperbus_cfg_t const * const p_cfg)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;

#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) p_cfg->p_extend;

#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_cfg_extend->p_reg);
    FSP_ERROR_RETURN((g_xspi_hyper_channels_open_flags &
                      (1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select))) == 0,
                     FSP_ERR_ALREADY_OPEN);
#endif

    /* Enable clock to the HYPER block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_XSPI, p_cfg_extend->unit);
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
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

    /* Set base address. */
    p_instance_ctrl->p_reg = (R_XSPI0_Type *) p_cfg_extend->p_reg;

    /* Initialize control block. */
    p_instance_ctrl->p_cfg = p_cfg;

    /* xSPI configuration (see "Flow of Configuration" in the xSPI Operation section of the relevant hardware manual). */
    /* Set xSPI CSn slave memory size. */
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
    xspi_hyper_memory_size_t memory_size_reg = XSPI_HYPER_MEMORY_SIZE_1MB;

    switch (p_cfg_extend->memory_size)
    {
        case XSPI_HYPER_PRV_1MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_1MB;
            break;
        }

        case XSPI_HYPER_PRV_2MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_2MB;
            break;
        }

        case XSPI_HYPER_PRV_4MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_4MB;
            break;
        }

        case XSPI_HYPER_PRV_8MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_8MB;
            break;
        }

        case XSPI_HYPER_PRV_16MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_16MB;
            break;
        }

        case XSPI_HYPER_PRV_32MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_32MB;
            break;
        }

        case XSPI_HYPER_PRV_64MB_MEMORY_SIZE:
        {
            memory_size_reg = XSPI_HYPER_MEMORY_SIZE_64MB;
            break;
        }

        default:
        {
            break;
        }
    }

    if (XSPI_HYPER_CHIP_SELECT_0 == p_cfg_extend->chip_select)
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
    p_instance_ctrl->p_reg->LIOCFGCS[p_cfg_extend->chip_select] =
        XSPI_HYPER_PRV_LIOCFGCS_PRTMD_PROTOCOL_8D_8D_8D << XSPI_HYPER_PRV_LIOCFGCS_PRTMD_OFFSET;

    /* Set xSPI drive/sampling timing. */
    if (XSPI_HYPER_CHIP_SELECT_0 == p_cfg_extend->chip_select)
    {
        p_instance_ctrl->p_reg->WRAPCFG_b.DSSFTCS0 =
            p_cfg_extend->data_latching_delay_clock & XSPI_HYPER_PRV_WRAPCFG_DSSFTCS0_VALUE_MASK;
    }
    else
    {
        p_instance_ctrl->p_reg->WRAPCFG_b.DSSFTCS1 =
            p_cfg_extend->data_latching_delay_clock & XSPI_HYPER_PRV_WRAPCFG_DSSFTCS1_VALUE_MASK;
    }

    /* Set xSPI CSn signal timings. */
    p_instance_ctrl->p_reg->LIOCFGCS[p_cfg_extend->chip_select] =
        ((XSPI_HYPER_PRV_LIOCFGCS_PRTMD_PROTOCOL_8D_8D_8D & XSPI_HYPER_PRV_LIOCFGCS_PRTMD_VALUE_MASK) <<
            XSPI_HYPER_PRV_LIOCFGCS_PRTMD_OFFSET) |
        ((XSPI_HYPER_PRV_LIOCFGCS_LATEMD_VARIABLE_LATENCY & XSPI_HYPER_PRV_LIOCFGCS_LATEMD_VALUE_MASK) <<
            XSPI_HYPER_PRV_LIOCFGCS_LATEMD_OFFSET) |
        ((XSPI_HYPER_PRV_LIOCFGCS_WRMSKMD_WRITE_MASK_ENABLE & XSPI_HYPER_PRV_LIOCFGCS_WRMSKMD_VALUE_MASK) <<
            XSPI_HYPER_PRV_LIOCFGCS_WRMSKMD_OFFSET) |
        ((p_cfg_extend->p_cs_timing_settings->transaction_interval &
          XSPI_HYPER_PRV_LIOCFGCS_CSMIN_VALUE_MASK) << XSPI_HYPER_PRV_LIOCFGCS_CSMIN_OFFSET) |
        ((p_cfg_extend->p_cs_timing_settings->cs_pulldown_lead & XSPI_HYPER_PRV_LIOCFGCS_CSASTEX_VALUE_MASK) <<
            XSPI_HYPER_PRV_LIOCFGCS_CSASTEX_OFFSET) |
        ((p_cfg_extend->p_cs_timing_settings->cs_pullup_lag & XSPI_HYPER_PRV_LIOCFGCS_CSENGEX_VALUE_MASK) <<
            XSPI_HYPER_PRV_LIOCFGCS_CSENGEX_OFFSET);

    /* Specifies the read/write commands and dummy clocks for Device
     * (see "Flow of Memory-mapping" in the xSPI Operation section of the relevant hardware manual). */

    /* Set command map configuration register for HyperBus protocol */
    p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG0 = XSPI_HYPER_PRV_CMCFG0_DEFAULT_VALUE |
                                                                    ((p_cfg_extend->wrap_separate &
                                                                      XSPI_HYPER_PRV_CMCFG0_WPBSTMD_VALUE_MASK) <<
                                                                     XSPI_HYPER_PRV_CMCFG0_WPBSTMD_OFFSET) |
                                                                    ((p_cfg_extend->address_msb_mask &
                                                                      XSPI_HYPER_PRV_CMCFG0_ADDRPEN_VALUE_MASK) <<
                                                                     XSPI_HYPER_PRV_CMCFG0_ADDRPEN_OFFSET);

    /* Memory-mapping mode read setting */
    /* Command and latency settings when issuing read AHB transaction to memory space */
    p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG1 =
        ((XSPI_HYPER_PRV_CMCFG1_RDCMD_HYPERBUS_READ & XSPI_HYPER_PRV_CMCFG1_RDCMD_15TH_BIT_VALUE_MASK) <<
            XSPI_HYPER_PRV_CMCFG1_RDCMD_15TH_BIT_OFFSET) |
        ((p_cfg->access_space & XSPI_HYPER_PRV_CMCFG1_RDCMD_14TH_BIT_VALUE_MASK) <<
            XSPI_HYPER_PRV_CMCFG1_RDCMD_14TH_BIT_OFFSET) |
        ((p_cfg->burst_type & XSPI_HYPER_PRV_CMCFG1_RDCMD_13TH_BIT_VALUE_MASK) <<
            XSPI_HYPER_PRV_CMCFG1_RDCMD_13TH_BIT_OFFSET) |
        ((p_cfg->read_latency_count & XSPI_HYPER_PRV_CMCFG1_RDLATE_VALUE_MASK) << XSPI_HYPER_PRV_CMCFG1_RDLATE_OFFSET);

    /* Memory-mapping mode write setting */
    /* Command and latency settings when issuing write AHB transaction to memory space */
    /* Write latency is set differently for memory space access and register space access */
    hyperbus_latency_count_t write_latency_count;
    if (HYPERBUS_SPACE_SELECT_MEMORY_SPACE == p_cfg->access_space)
    {
        write_latency_count = p_cfg->memory_write_latency_count;
    }
    else
    {
        write_latency_count = p_cfg->register_write_latency_count;
    }

    p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG2 =
        ((XSPI_HYPER_PRV_CMCFG2_WRCMD_HYPERBUS_WRITE & XSPI_HYPER_PRV_CMCFG2_WRCMD_15TH_BIT_VALUE_MASK) <<
            XSPI_HYPER_PRV_CMCFG2_WRCMD_15TH_BIT_OFFSET) |
        ((p_cfg->access_space & XSPI_HYPER_PRV_CMCFG2_WRCMD_14TH_BIT_VALUE_MASK) <<
            XSPI_HYPER_PRV_CMCFG2_WRCMD_14TH_BIT_OFFSET) |
        ((p_cfg->burst_type & XSPI_HYPER_PRV_CMCFG2_WRCMD_13TH_BIT_VALUE_MASK) <<
            XSPI_HYPER_PRV_CMCFG2_WRCMD_13TH_BIT_OFFSET) |
        ((write_latency_count & XSPI_HYPER_PRV_CMCFG2_WRLATE_VALUE_MASK) << XSPI_HYPER_PRV_CMCFG2_WRLATE_OFFSET);

    /* Set the access from AHB channel. */
    p_instance_ctrl->p_reg->BMCTL0 = XSPI_HYPER_PRV_BMCTL_DEFAULT_VALUE;

    /* Return response after issuing write transaction to xSPI bus, Enable prefetch function. */
    p_instance_ctrl->p_reg->BMCFG = (1 << XSPI_HYPER_PRV_BMCFG_WRMD_OFFSET) |
                                    (0 << XSPI_HYPER_PRV_BMCFG_MWRCOMB_OFFSET) |
                                    (0 << XSPI_HYPER_PRV_BMCFG_MWRSIZE_OFFSET) |
                                    ((p_cfg_extend->prefetch_en & XSPI_HYPER_PRV_BMCFG_PREEN_VALUE_MASK) <<
                                     XSPI_HYPER_PRV_BMCFG_PREEN_OFFSET);

    p_instance_ctrl->open             = XSPI_HYPER_PRV_OPEN;
    g_xspi_hyper_channels_open_flags |= (1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select));

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Dynamic burst type configuration for read access.
 *
 * Implements @ref hyperbus_api_t::burstTypeSet
 *
 * @retval FSP_SUCCESS             Burst type configuration for read access is successfully changed.
 * @retval FSP_ERR_ASSERTION       The parameter p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 * @retval FSP_ERR_UNSUPPORTED     Burst type configuration is not supported on this device.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_BurstTypeSet (hyperbus_ctrl_t * p_ctrl, hyperbus_burst_type_t burst_type)
{
#if BSP_FEATURE_XSPI_HAS_AXI_BRIDGE
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;

 #if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
 #endif

    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    if (HYPERBUS_BURST_TYPE_LINEAR == burst_type)
    {
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG1 |= XSPI_HYPER_PRV_CMCFG1_ACCESS_LINEAR;
    }
    else
    {
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG1 &= XSPI_HYPER_PRV_CMCFG1_ACCESS_WRAP;
    }

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(burst_type);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Dynamic access address space configuration.
 *
 * Implements @ref hyperbus_api_t::accessSpaceSet
 *
 * @retval FSP_SUCCESS             Address space successfully changed as specified by the argument.
 * @retval FSP_ERR_ASSERTION       The parameter p_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_AccessSpaceSet (hyperbus_ctrl_t * const p_ctrl, hyperbus_space_select_t access_space)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;

#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Set to access address space of argument */
    /* Write latency depends on module configuration */
    if (HYPERBUS_SPACE_SELECT_REGISTER_SPACE == access_space)
    {
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG1 |= XSPI_HYPER_PRV_CMCFG1_ACCESS_REGISETR;

        /* Set latency cycles separately (different for memory space and register space when writing) */
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG2_b.WRCMD |=
            XSPI_HYPER_PRV_CMCFG2_WRCMD_ACCESS_REGISETR;
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG2_b.WRLATE =
            p_instance_ctrl->p_cfg->register_write_latency_count;
    }
    else
    {
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG1 &= XSPI_HYPER_PRV_CMCFG1_ACCESS_MEMORY;

        /* Set latency cycles separately (different for memory space and register space when writing) */
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG2_b.WRCMD &=
            XSPI_HYPER_PRV_CMCFG2_WRCMD_ACCESS_MEMORY;
        p_instance_ctrl->p_reg->CSa[p_cfg_extend->chip_select].CMCFG2_b.WRLATE =
            p_instance_ctrl->p_cfg->memory_write_latency_count;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Read/Write raw data directly with the HyperRAM or HyperFlash.
 *
 * Implements @ref hyperbus_api_t::directTransfer.
 *
 * @retval FSP_SUCCESS                 The command was send successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_DirectTransfer (hyperbus_ctrl_t * const p_ctrl, hyperbus_direct_transfer_t * const p_transfer)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;
#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_transfer);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    r_xspi_hyper_direct_transfer(p_instance_ctrl, p_transfer);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Program a write buffer line of data to the HyperFlash.
 *
 * Implements @ref hyperbus_api_t::write.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL or programming range extends beyond write buffer line boundary.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_Write (hyperbus_ctrl_t * const p_ctrl,
                              uint8_t const * const   p_src,
                              uint8_t * const         p_dest,
                              uint32_t                byte_count)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;
#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(0 != byte_count);
#endif

    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) (p_instance_ctrl->p_cfg)->p_extend;

    uint8_t unit        = p_cfg_extend->unit;
    uint8_t chip_select = p_cfg_extend->chip_select;

    uintptr_t chip_address = 0;
    uint32_t  mirror_address_delta;

#ifdef BSP_CFG_CORE_CA55
    uintptr_t device_address_va = (uintptr_t) p_dest;
    uintptr_t device_address_pa = 0U;

    fsp_err_t mmu_err;
    mmu_err = R_BSP_MmuVatoPa(device_address_va, &device_address_pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == mmu_err, mmu_err);
#else
    uintptr_t device_address_pa = (uintptr_t) p_dest;
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

#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE

    /* Write to Buffer command writes data in buffer lines. */
    FSP_ASSERT(p_cfg_extend->write_buffer_size - chip_address % p_cfg_extend->write_buffer_size >= byte_count);
#endif

    /* To issue Write Program sequence, the base address of CSn must be obtained from p_dest. */
    uint16_t * p_cs_base = (uint16_t *) ((uintptr_t) p_dest - chip_address);

    uint32_t odd_addr_flag  = chip_address % XSPI_HYPER_PRV_WORD_SIZE;
    uint32_t odd_bytes_flag = byte_count % XSPI_HYPER_PRV_WORD_SIZE;

    FSP_ERROR_RETURN(false == r_xspi_hyper_status_sub(p_instance_ctrl), FSP_ERR_DEVICE_BUSY);

    /* - HyperFlash is word-addressed (2bytes). The uint16_t pointer arithmetic converts the word address to the corresponding system address.
     * - Command data is byte-swapped to compensate for the byte ordering difference between the HyperFlash interface and the peripheral specification.
     */
    if (XSPI_HYPER_PRV_WORD_SIZE >= byte_count)
    {
        /* Start Word Program Sequence */
        *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_WORD_PROGRAM_1ST_ADDRESS) = (uint16_t) __REV16(
            XSPI_HYPER_PRV_WORD_PROGRAM_1ST_DATA);
        __DSB();
        *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_WORD_PROGRAM_2ND_ADDRESS) = (uint16_t) __REV16(
            XSPI_HYPER_PRV_WORD_PROGRAM_2ND_DATA);
        __DSB();
        *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_WORD_PROGRAM_3RD_ADDRESS) = (uint16_t) __REV16(
            XSPI_HYPER_PRV_WORD_PROGRAM_3RD_DATA);
        __DSB();

        /* If chip_address is an odd address, the preceding byte data is padded with 0xFF,
         * since HyperFlash handles data in byte pairs; it cannot handle data in single-byte unit.
         * The padded byte retains the original value in the Flash,
         * since the write command does not overwrite memory bits from '0' to '1'. */
        if (true == odd_addr_flag)
        {
            /* Write 1-byte data to the odd-numbered address. The preceding byte of the byte pair is padded with 0xFF. */
            *((volatile uint16_t *) ((uintptr_t) p_dest -
                                     1)) =
                (uint16_t) ((*(uint8_t *) p_src << XSPI_HYPER_PRV_BYTE_SHIFT) + XSPI_HYPER_PRV_WRITE_PADDING_BYTE_DATA);
        }
        else
        {
            /* If byte_count is an odd number, the following byte data is padded with 0xFF,
             * since HyperFlash handles data in byte pairs; it cannot handle data in single-byte unit.
             * The padded byte retains the original value in the Flash,
             * since the write command does not overwrite memory bits from '0' to '1'. */
            if (true == odd_bytes_flag)
            {
                /* Write 1-byte data to an even-numbered address. The following byte of the byte pair is padded with 0xFF. */
                *((volatile uint16_t *) p_dest) =
                    (uint16_t) ((*(uint8_t *) p_src) +
                                (XSPI_HYPER_PRV_WRITE_PADDING_BYTE_DATA << XSPI_HYPER_PRV_BYTE_SHIFT));
            }
            else
            {
                /* Write 2-byte data. */
                *((volatile uint16_t *) p_dest) = *(uint16_t *) p_src;
            }
        }

        __DSB();
    }
    else
    {
        uintptr_t sect_addr = (uintptr_t) p_cs_base +
                              (chip_address & ~((uintptr_t) XSPI_HYPER_PRV_ODD_ADDRESS_BIT_MASK));
        uint32_t   word_index         = 0;
        uint32_t   final_byte_padding = odd_bytes_flag ^ odd_addr_flag;
        uint16_t * p_dest_adj         = (uint16_t *) ((uintptr_t) p_dest - odd_addr_flag);
        uint32_t   word_count         = byte_count / XSPI_HYPER_PRV_WORD_SIZE + (final_byte_padding | odd_addr_flag);

        /* Start Write to Buffer Sequence */
        *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_WRITE_BUFFER_1ST_ADDRESS) = (uint16_t) __REV16(
            XSPI_HYPER_PRV_WRITE_BUFFER_1ST_DATA);
        __DSB();
        *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_WRITE_BUFFER_2ND_ADDRESS) = (uint16_t) __REV16(
            XSPI_HYPER_PRV_WRITE_BUFFER_2ND_DATA);
        __DSB();
        *((volatile uint16_t *) sect_addr) = (uint16_t) __REV16(XSPI_HYPER_PRV_WRITE_BUFFER_3RD_DATA);
        __DSB();
        *((volatile uint16_t *) sect_addr) = (uint16_t) __REV16(word_count - 1);
        __DSB();

        /* For the first data transmission, if chip_address is an odd address, the preceding byte data is padded with 0xFF,
         * since HyperFlash handles data in byte pairs; it cannot handle data in single-byte unit.
         * The padded byte retains the original value in the Flash,
         * since the write command does not overwrite memory bits from '0' to '1'. */
        if (true == odd_addr_flag)
        {
            /* Write 1-byte data to an odd-numbered address. The preceding byte of the byte pair is padded with 0xFF. */
            *(volatile uint16_t *) p_dest_adj =
                (uint16_t) ((*(uint8_t *) p_src << XSPI_HYPER_PRV_BYTE_SHIFT) + XSPI_HYPER_PRV_WRITE_PADDING_BYTE_DATA);
            __DSB();
            word_index++;
        }

        for ( ; word_index < word_count - final_byte_padding; word_index++)
        {
            *((volatile uint16_t *) p_dest_adj +
              word_index) = *((uint16_t *) &p_src[odd_addr_flag] + word_index - odd_addr_flag);
            __DSB();
        }

        /* For the final data transmission, if only 1 byte of data remains, the following byte data is padded with 0xFF,
         * since HyperFlash handles data in byte pairs; it cannot handle data in single-byte unit.
         * The padded byte retains the original value in the Flash,
         * since the write command does not overwrite memory bits from '0' to '1'. */
        if (true == final_byte_padding)
        {
            /* Write 1-byte data to an even-numbered address. The following byte of the byte pair is padded with 0xFF. */
            *((volatile uint16_t *) p_dest_adj +
              word_index) =
                (uint16_t) ((*(uint8_t *) (&p_src[odd_addr_flag] + ((word_index - odd_addr_flag) << 1))) +
                            (XSPI_HYPER_PRV_WRITE_PADDING_BYTE_DATA << XSPI_HYPER_PRV_BYTE_SHIFT));
            __DSB();
        }

        /* Start Program Buffer to Flash Sequence */
        *((volatile uint16_t *) sect_addr) =
            (uint16_t) __REV16(XSPI_HYPER_PRV_PROGRAM_BUFFER_TO_FLASH_DATA);
        __DSB();
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Erase a sector of data in the HyperFlash.  The byte_count must exactly match one of the erase sector size defined in hyperbus_cfg_t.
 * For chip erase, byte_count must be HYPER_FLASH_ERASE_SIZE_CHIP_ERASE.
 *
 * Implements @ref hyperbus_api_t::erase.
 *
 * @retval FSP_SUCCESS                 The flash was erased successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL or erase size is invalid.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_Erase (hyperbus_ctrl_t * const p_ctrl, uint8_t * const p_device_address, uint32_t byte_count)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;
#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_device_address);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    hyperbus_cfg_t            * p_cfg        = (hyperbus_cfg_t *) p_instance_ctrl->p_cfg;
    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) (p_instance_ctrl->p_cfg)->p_extend;

    uint8_t unit        = p_cfg_extend->unit;
    uint8_t chip_select = p_cfg_extend->chip_select;

    uintptr_t chip_address = 0;
    uint32_t  mirror_address_delta;

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

    /* To issue Write Program sequence,
     * the base address of CSn must be obtained from the destination address (p_dest).
     */
    uint16_t * p_cs_base = (uint16_t *) ((uintptr_t) p_device_address - chip_address);
    uintptr_t  sect_addr = (uintptr_t) p_cs_base + (chip_address & ~((uintptr_t) XSPI_HYPER_PRV_ODD_ADDRESS_BIT_MASK));

    FSP_ERROR_RETURN(false == r_xspi_hyper_status_sub(p_instance_ctrl), FSP_ERR_DEVICE_BUSY);

    xspi_hyper_flash_erase_size_t erase_type = XSPI_HYPER_FLASH_ERASE_SIZE_ERROR;
    if (byte_count == HYPERBUS_ERASE_SIZE_CHIP_ERASE)
    {
        erase_type = XSPI_HYPER_FLASH_ERASE_SIZE_CHIP;
    }
    else if (byte_count == p_cfg->sector_erase_size)
    {
        erase_type = XSPI_HYPER_FLASH_ERASE_SIZE_SECTOR;
    }
    else
    {
        /* Do nothing. */
    }

#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(XSPI_HYPER_FLASH_ERASE_SIZE_ERROR != erase_type);
#endif

    /* - HyperFlash is word-addressed (2bytes). The uint16_t pointer arithmetic converts the word address to the corresponding system address.
     * - Command data is byte-swapped to compensate for the byte ordering difference between the HyperFlash interface and the peripheral specification.
     */

    /* Start Sector/Chip Erase Sequence */
    *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_ERASE_1ST_ADDRESS) = (uint16_t) __REV16(
        XSPI_HYPER_PRV_ERASE_1ST_DATA);
    __DSB();
    *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_ERASE_2ND_ADDRESS) = (uint16_t) __REV16(
        XSPI_HYPER_PRV_ERASE_2ND_DATA);
    __DSB();
    *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_ERASE_3RD_ADDRESS) = (uint16_t) __REV16(
        XSPI_HYPER_PRV_ERASE_3RD_DATA);
    __DSB();
    *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_ERASE_4TH_ADDRESS) = (uint16_t) __REV16(
        XSPI_HYPER_PRV_ERASE_4TH_DATA);
    __DSB();
    *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_ERASE_5TH_ADDRESS) = (uint16_t) __REV16(
        XSPI_HYPER_PRV_ERASE_5TH_DATA);
    __DSB();

    if (XSPI_HYPER_FLASH_ERASE_SIZE_SECTOR == erase_type)
    {
        /* Do the 6th of Sector Erase Sequence Cycles */
        *((volatile uint16_t *) sect_addr) = (uint16_t) __REV16(XSPI_HYPER_PRV_SECTOR_ERASE_6TH_DATA);
        __DSB();
    }

    if (XSPI_HYPER_FLASH_ERASE_SIZE_CHIP == erase_type)
    {
        /* Do the 6th of Chip Erase Sequence Cycles */
        *((volatile uint16_t *) p_cs_base + XSPI_HYPER_PRV_CHIP_ERASE_6TH_ADDRESS) = (uint16_t) __REV16(
            XSPI_HYPER_PRV_CHIP_ERASE_6TH_DATA);
        __DSB();
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the write or erase status of the HyperFlash.
 *
 * Implements @ref hyperbus_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 The flash was erased successfully.
 * @retval FSP_ERR_ASSERTION           A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_StatusGet (hyperbus_ctrl_t * const p_ctrl, hyperbus_status_t * const p_status)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;
#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Read device status. */
    p_status->device_busy = r_xspi_hyper_status_sub(p_instance_ctrl);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Auto-calibrate the HyperRAM device using the preamble pattern.
 *
 * Implements @ref hyperbus_api_t::autoCalibrate.
 * @note The preamble pattern must be written to the configured address before calling this API.
 *
 * @retval FSP_ERR_UNSUPPORTED        API not supported by HyperBus - HyperFlash. (Planned support for FSP v2.1.0 or later.)
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_AutoCalibrate (hyperbus_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    FSP_RETURN(FSP_ERR_UNSUPPORTED);
}

/*******************************************************************************************************************//**
 * Close the HYPER driver module.
 *
 * Implements @ref hyperbus_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 *
 * @note If another chip select of the same unit is used by other drivers,
 * the other chip select operation will also stop when this function is executed.
 **********************************************************************************************************************/
fsp_err_t R_XSPI_HYPER_Close (hyperbus_ctrl_t * const p_ctrl)
{
    xspi_hyper_instance_ctrl_t * p_instance_ctrl = (xspi_hyper_instance_ctrl_t *) p_ctrl;
#if XSPI_HYPER_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(XSPI_HYPER_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif
    hyperbus_cfg_t            * p_cfg        = (hyperbus_cfg_t *) p_instance_ctrl->p_cfg;
    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) p_cfg->p_extend;

    p_instance_ctrl->open             = 0U;
    g_xspi_hyper_channels_open_flags &= ~(1U << ((p_cfg_extend->unit << 1U) + p_cfg_extend->chip_select));

    if ((g_xspi_hyper_channels_open_flags & (XSPI_HYPER_PRV_UNIT_FLAG_MASK << (p_cfg_extend->unit << 1U))) == 0)
    {
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

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

        /* Disable clock to the Hyper block */
        R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
        if (0U == p_cfg_extend->unit)
        {
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_XSPI0);
        }
        else
        {
            R_BSP_ModuleResetEnable(BSP_MODULE_RESET_XSPI1);
        }

        R_BSP_MODULE_STOP(FSP_IP_XSPI, p_cfg_extend->unit);
        R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets device status.
 *
 * @param[in]  p_instance_ctrl        Pointer to specific control structure
 *
 * @return True if busy, false if not.
 **********************************************************************************************************************/
static bool r_xspi_hyper_status_sub (xspi_hyper_instance_ctrl_t * const p_instance_ctrl)
{
    /* Command data is byte-swapped to compensate for the byte ordering difference between the HyperFlash interface and the peripheral specification. */

    hyperbus_direct_transfer_t direct_command = {0};

    /* Enter status register mode. */
    direct_command.command_address.command_address_info =
        (uint64_t) XSPI_HYPER_STATUS_REGISTER_READ_1ST_COMMAND_ADDRESS;
    direct_command.data_length  = XSPI_HYPER_PRV_WORD_SIZE;
    direct_command.data         = (uint16_t) __REV16(XSPI_HYPER_STATUS_REGISTER_READ_1ST_DATA);
    direct_command.dummy_cycles = p_instance_ctrl->p_cfg->memory_write_latency_count;

    r_xspi_hyper_direct_transfer(p_instance_ctrl, &direct_command);

    /* Read status register data. */
    direct_command.command_address.command_address_info_b.read_operation = 1;
    direct_command.dummy_cycles = p_instance_ctrl->p_cfg->read_latency_count;

    r_xspi_hyper_direct_transfer(p_instance_ctrl, &direct_command);
    uint16_t status_register = (uint16_t) __REV16(direct_command.data);

    return !(bool) (status_register & XSPU_HYPER_DEVICE_READY_BIT_MASK);
}

/*******************************************************************************************************************//**
 * Performs direct data transfer with the HyperFlash
 *
 * @param[in]   p_instance_ctrl    Pointer to specific control structure
 * @param[in]   p_transfer         Pointer to transfer parameters
 **********************************************************************************************************************/
static void r_xspi_hyper_direct_transfer (xspi_hyper_instance_ctrl_t * const p_instance_ctrl,
                                          hyperbus_direct_transfer_t * const p_transfer)
{
    xspi_hyper_extended_cfg_t * p_cfg_extend = (xspi_hyper_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    p_instance_ctrl->p_reg->CDCTL0_b.TRNUM = 0;
    p_instance_ctrl->p_reg->CDCTL0_b.CSSEL = p_cfg_extend->chip_select;

    /* Direct Read/Write settings
     * (see "Flow of Manual-command Procedure" in the xSPI Operation section of the relevant hardware manual). */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CDCTL0_b.TRREQ, 0);

    uint32_t write_operation = ~(p_transfer->command_address.command_address_info_b.read_operation) & 0x1;

    uint32_t cdtbuf0 = ((XSPI_HYPER_PRV_CDTBUF_CMDSIZE_2_BYTES) << XSPI_HYPER_PRV_CDTBUF_CMDSIZE_OFFSET) |
                       ((XSPI_HYPER_PRV_CDTBUF_ADDSIZE_4_BYTES) << XSPI_HYPER_PRV_CDTBUF_ADDSIZE_OFFSET) |
                       ((p_transfer->data_length & XSPI_HYPER_PRV_CDTBUF_DATASIZE_VALUE_MASK) <<
                        XSPI_HYPER_PRV_CDTBUF_DATASIZE_OFFSET) |
                       ((p_transfer->dummy_cycles & XSPI_HYPER_PRV_CDTBUF_LATE_VALUE_MASK) <<
                        XSPI_HYPER_PRV_CDTBUF_LATE_OFFSET) |
                       ((write_operation & XSPI_HYPER_PRV_CDTBUF_TRTYPE_VALUE_MASK) <<
                        XSPI_HYPER_PRV_CDTBUF_TRTYPE_OFFSET);

    uint16_t ca_info_upper = (p_transfer->command_address.command_address_info & XSPI_HYPER_PRV_COMMAND_ADDRESS_MASK) >>
                             XSPI_HYPER_PRV_COMMAND_ADDRESS_FOR_CDTBUF_SHIFT;
    uint32_t ca_info_lower = p_transfer->command_address.command_address_info &
                             XSPI_HYPER_PRV_COMMAND_ADDRESS_FOR_CDABUF_MASK;

    cdtbuf0 |= (uint32_t) ca_info_upper << XSPI_HYPER_PRV_CDTBUF_CMD_OFFSET;

    p_instance_ctrl->p_reg->BUF[0].CDT = cdtbuf0;

    p_instance_ctrl->p_reg->BUF[0].CDA = ca_info_lower;

    if (1 == write_operation)
    {
        p_instance_ctrl->p_reg->BUF[0].CDD0 = (uint32_t) p_transfer->data_u64 & UINT32_MAX;
        if (p_transfer->data_length > sizeof(uint32_t))
        {
            p_instance_ctrl->p_reg->BUF[0].CDD1 = (uint32_t) (p_transfer->data_u64 >> XSPI_HYPER_PRV_UINT32_BITS) &
                                                  UINT32_MAX;
        }
    }

    p_instance_ctrl->p_reg->CDCTL0_b.TRREQ = 1;
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->INTS_b.CMDCMP, 1);

    if (0 == write_operation)
    {
        p_transfer->data_u64 = p_instance_ctrl->p_reg->BUF[0].CDD0;
        if (p_transfer->data_length > sizeof(uint32_t))
        {
            p_transfer->data_u64 |= (uint64_t) (p_instance_ctrl->p_reg->BUF[0].CDD1) << XSPI_HYPER_PRV_UINT32_BITS;
        }
    }

    p_instance_ctrl->p_reg->INTC = 1 << XSPI_HYPER_PRV_INTC_CMDCMPC_OFFSET;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RZN_XSPI_HYPER)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif
