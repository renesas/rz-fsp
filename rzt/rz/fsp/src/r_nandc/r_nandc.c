/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_nandc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** "NAND" in ASCII, used to determine if channel is open. */
#define NANDC_OPEN                               (0x4E414E44ULL)

/* Macro definition for command registers configuration. */
#define NANDC_PRV_ADDR_HIGHER_PART_OFFSET        (32)
#define NANDC_PRV_ROW_ADDRESS_SIZE               (32)
#define NANDC_PRV_CMDSTAT_FAIL_BIT_OFFSET        (14)
#define NANDC_PRV_CMDREG_0_CMD_TYPE_MASK         (0x0000FFFF)
#define NANDC_PRV_CMDREG_0_CMD_TYPE_OFFSET       (0)
#define NANDC_PRV_CMDSTATEXT_OFFSET              (32)
#define NANDC_PRV_CMDREG_4_BANK_OFFSET           (24)

#define NANDC_PRV_CMD_TYPE_READ                  (0x2200)
#define NANDC_PRV_CMD_TYPE_WRITE                 (0x2100)
#define NANDC_PRV_CMD_TYPE_ERASE                 (0x1000)
#define NANDC_PRV_CMD_TYPE_RESET                 (0x1100)
#define NANDC_PRV_CMD_TYPE_THREAD_RESET          (0x0200)
#define NANDC_PRV_CMD_TYPE_SET_FEATURE           (0x0100)
#define NANDC_PRV_CMD_TYPE_COPYBACK              (0x1200)
#define NANDC_PRV_CMD_TYPE_UPPER_MSK             (0xFF00)

#define NANDC_PRV_VOL_ID_0                       (0) /* Volume addressing is unsupported. */
#define NANDC_PRV_TRDCOMP_INT_ENABLE             (1) /* This driver uses thread completion interrupt. */
#define NANDC_PRV_TRDCOMP_INT_DISABLE            (0) /* Thread reset command does not use completion interrupt. */
#define NANDC_PRV_DMA_SEL                        (1) /* Must be set to 1. (DMA Master) */
#define NANDC_PRV_THREAD_NUM_0                   (0) /* This driver uses thread 0 except for reset operation. */
#define NANDC_PRV_THREAD_NUM_1                   (1) /* This driver used thread 1 in reset operation. */
#define NANDC_PRV_CT                             (1) /* This field must have the value 01b for the PIO work mode. */
#define NANDC_PRV_CHIP_SELECT_0                  (0) /* This driver always access to the target connected to CE0#. */

#define NANDC_PRV_TIMING_MODE_ADDRESS            (1)

/* Macro definition for interrupt service routine. */
#define NANDC_PRV_THREAD_0_STATUS_MASK           (0x01)
#define NANDC_PRV_THREAD_1_STATUS_MASK           (0x02)
#define NANDC_PRV_THREAD_NUMBER                  (8)
#define NANDC_PRV_INTERRUPT_ENABLE_MASK          (0xFF)

/* Macro definitions for RAM access area configuration. */
#define NANDC_PRV_TCM_END_ADDRESS                (0x00110000)
#define NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET    (0x20000000)
#define NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET    (0x21000000)

/* Macro definitions for parameter checking. */
#define NANDC_PRV_CHIP_SELECT_MAX_NUM            (4)
#define NANDC_PRV_MAX_POLLING_CYCLES             (0xFFFF)
#define NANDC_PRV_TRDSTAT_THREAD_0_MASK          (0x01)
#define NANDC_PRV_TRDSTAT_THREAD_1_MASK          (0x02)
#define NANDC_PRV_WRITE_PROTECT_REGION_NUM       (2)

/* Macro definition for timing register configuration. */
#define NANDC_PRV_TWP_ACTUAL_CYCLES_DIFF         (1)
#define NANDC_PRV_TWH_ACTUAL_CYCLES_DIFF         (1)
#define NANDC_PRV_TRP_ACTUAL_CYCLES_DIFF         (1)
#define NANDC_PRV_TREH_ACTUAL_CYCLES_DIFF        (1)
#define NANDC_PRV_TRHW_ACTUAL_CYCLES_DIFF        (1)
#define NANDC_PRV_TWHR_ACTUAL_CYCLES_DIFF        (2)
#define NANDC_PRV_TADL_ACTUAL_CYCLES_DIFF        (57)
#define NANDC_PRV_TWB_ACTUAL_CYCLES_DIFF         (11)
#define NANDC_PRV_TRHZ_ACTUAL_CYCLES_DIFF        (2)
#define NANDC_PRV_TCS_ACTUAL_CYCLES_DIFF         (11)
#define NANDC_PRV_TCEH_ACTUAL_CYCLES_DIFF        (1)
#define NANDC_PRV_TITC_ACTUAL_CYCLES_DIFF        (318)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Index to store thread operation. */
typedef enum e_nandc_operation
{
    NANDC_OPERATION_PAGE_READ = 0,
    NANDC_OPERATION_PAGE_PROGRAM,
    NANDC_OPERATION_COPYBACK,
    NANDC_OPERATION_BLOCK_ERASE,
    NANDC_OPERATION_RESET,
    NANDC_OPERATION_SET_FEATURE,
} nandc_operation_t;

/* Selected chip select in each thread. */
typedef enum e_nandc_chip_select
{
    NANDC_CHIP_SELECT_0 = 1,
    NANDC_CHIP_SELECT_1,
    NANDC_CHIP_SELECT_2,
    NANDC_CHIP_SELECT_3,
} nandc_chip_select_t;

/* Bit field of command register 0 */
typedef struct st_nandc_command_0_data
{
    union
    {
        uint32_t command_0_reg;

        struct
        {
            uint32_t cmd_type   : 16;
            uint32_t vol_id     : 4;
            uint32_t interrupt  : 1;
            uint32_t dma_sel    : 1;
            uint32_t reserved_1 : 2;
            uint32_t trd_num    : 3;
            uint32_t reserved_2 : 3;
            uint32_t ct         : 2;
        } command_0_bit;
    };
} nandc_command_0_data_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_nandc_call_callback(nandc_instance_ctrl_t * p_instance_ctrl, nand_flash_callback_args_t * p_args);
static void r_nandc_hw_config(nandc_instance_ctrl_t * p_instance_ctrl);
static void r_nandc_timing_config(nandc_instance_ctrl_t * p_instance_ctrl);
static void r_nandc_raw_access_config(nandc_instance_ctrl_t * p_instance_ctrl);
static void r_nandc_raw_access_config_recovery(nandc_instance_ctrl_t * p_instance_ctrl);

/***********************************************************************************************************************
 * ISR prototypes
 **********************************************************************************************************************/
void nandc_int_isr(void);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
static nandc_operation_t   thread_last_operation[NANDC_PRV_THREAD_NUMBER];
static nandc_chip_select_t thread_chip_select[NANDC_PRV_THREAD_NUMBER];
static uint32_t            raw_config_flag;

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* NANDC implementation of NANDC interface  */
const nand_flash_api_t g_nand_flash_on_nandc =
{
    .open        = R_NANDC_Open,
    .close       = R_NANDC_Close,
    .deviceReset = R_NANDC_DeviceReset,
    .erase       = R_NANDC_Erase,
    .read        = R_NANDC_Read,
    .write       = R_NANDC_Write,
    .copyback    = R_NANDC_Copyback,
    .featureSet  = R_NANDC_FeatureSet,
    .statusGet   = R_NANDC_StatusGet,
    .callbackSet = R_NANDC_CallbackSet,
    .infoGet     = R_NANDC_InfoGet,
    .rawRead     = R_NANDC_RawRead,
    .rawWrite    = R_NANDC_RawWrite,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_NANDC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize the NANDC module and enables interrupts. Implements @ref nand_flash_api_t::open.
 *
 * @retval FSP_SUCCESS              Initializes the NANDC module.
 * @retval FSP_ERR_ALREADY_OPEN     NANDC module is open already.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_ABORTED          Failed Device Discovery process.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Open (nand_flash_ctrl_t * const p_ctrl, nand_flash_cfg_t const * const p_cfg)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
#endif

    nandc_extended_cfg_t * p_cfg_extend = (nandc_extended_cfg_t *) p_cfg->p_extend;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_cfg_extend);
    FSP_ASSERT(NULL != p_cfg_extend->p_reg);
    FSP_ERROR_RETURN(NANDC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    p_instance_ctrl->p_cfg = p_cfg;
    p_instance_ctrl->p_reg = (R_NANDC_Type *) p_cfg_extend->p_reg;

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);
    R_NANDC_MISC->DDCTRL0 = 0;
    R_NANDC_MISC->DDCTRL1 = p_cfg_extend->rb_valid_time_cycles;
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

    /* Release modules */
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_NANDC_SYSTEM);
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_NANDC_SLAVE_PHY_REGISTERS);
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_NANDC_PROTECT_REGISTERS);

    /* Power on NANDC */
    R_BSP_MODULE_START(FSP_IP_NANDC, 0);

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Waiting for NANDC Device Discovery process to complete. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CTRLSTAT_b.INITCOMP, 1);

    /* Verify that the initialization process was successful. */
    FSP_ERROR_RETURN(0 == p_instance_ctrl->p_reg->CTRLSTAT_b.INITFAIL, FSP_ERR_ABORTED);

    /* Wait for controller to be idle state. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, 0);

    /* Register settings. */
    r_nandc_hw_config(p_instance_ctrl);

    /* Set callback and context pointers, if configured */
    p_instance_ctrl->p_callback        = p_cfg->p_callback;
    p_instance_ctrl->p_context         = p_cfg->p_context;
    p_instance_ctrl->p_callback_memory = NULL;

    /* Enable thread error interrupt. */
    if (NANDC_INT_ENABLE == p_cfg_extend->command_error_interrupt)
    {
        p_instance_ctrl->p_reg->TRDERRINTEN = NANDC_PRV_INTERRUPT_ENABLE_MASK;
    }

    /* Enable thread timeout interrupt.*/
    if (NANDC_INT_ENABLE == p_cfg_extend->command_timeout_interrupt)
    {
        p_instance_ctrl->p_reg->TRDTMOINTEN = NANDC_PRV_INTERRUPT_ENABLE_MASK;
    }

    /* Global Interrupt Enable. */
    p_instance_ctrl->p_reg->INTENABLE_b.INTEN = 1;

    if (p_cfg->irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->irq, p_cfg->ipl, p_instance_ctrl);
    }

    p_instance_ctrl->open = NANDC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the NANDC module. Implements @ref nand_flash_api_t::close.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Close (nand_flash_ctrl_t * const p_ctrl)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    nand_flash_cfg_t * p_cfg = (nand_flash_cfg_t *) p_instance_ctrl->p_cfg;

    /* Disable interrupt */
    if (p_cfg->irq >= 0)
    {
        R_BSP_IrqDisable(p_cfg->irq);
        R_FSP_IsrContextSet(p_cfg->irq, NULL);
    }

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

    /* Remove power */
    R_BSP_MODULE_STOP(FSP_IP_NANDC, 0);

    /* Reset modules */
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_NANDC_SYSTEM);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_NANDC_SLAVE_PHY_REGISTERS);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_NANDC_PROTECT_REGISTERS);

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_instance_ctrl->open = 0;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads data from the NAND Flash. Implements @ref nand_flash_api_t::read.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 * @retval FSP_ERR_INVALID_STATE    Configurations of the controller are changed to access raw data.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 * @retval FSP_ERR_INVALID_ADDRESS  Destination address is invalid.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Read (nand_flash_ctrl_t * const              p_ctrl,
                        nand_flash_device_page_t const * const p_src_page,
                        nand_flash_data_buffer_t * const       p_dest_buffer,
                        uint32_t const                         chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_dest_buffer);
    FSP_ASSERT(NULL != p_dest_buffer->p_main_data_buffer);
    FSP_ASSERT(NULL != p_src_page);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(0 < p_src_page->page_count, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(row_addr_upper_limit >= (p_src_page->row_address + p_src_page->page_count),
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    if ((NANDC_MULTIPLANE_COMMAND_ENABLE == p_extend->multiplane_read_enable) &&
        (NANDC_MULTIPLANE_NUMBER_1 != p_extend->plane_number))
    {
        uint32_t block_addr_start_offset = NANDC_PRV_ROW_ADDRESS_SIZE - __CLZ(page_per_block - 1);
        uint32_t block_number            = (p_src_page->row_address >> block_addr_start_offset) & (block_per_lun - 1);
        uint32_t num_plane               = p_extend->plane_number << 1U;

        FSP_ERROR_RETURN(0 == block_number % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(0 == p_src_page->page_count % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(row_addr_upper_limit >=
                         (p_src_page->row_address + ((p_src_page->page_count / num_plane) << block_addr_start_offset) +
                          p_src_page->page_count / num_plane),
                         FSP_ERR_INVALID_ARGUMENT);
    }
#endif

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check thread status. */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->TRDSTAT & NANDC_PRV_TRDSTAT_THREAD_0_MASK), FSP_ERR_DEVICE_BUSY);

    /* Modify destination address for TCM. */
    uintptr_t dest_address;
    uintptr_t dest_address_oob;

    dest_address = (uintptr_t) p_dest_buffer->p_main_data_buffer;

#if defined(BSP_CFG_CORE_CA55)
    fsp_err_t err;
    uint64_t  va;                      // Virtual address.
    uint64_t  pa;                      // Physical address.

    va  = dest_address;
    err = R_BSP_MmuVatoPa(va, &pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_INVALID_ADDRESS);

    dest_address = pa;
#elif defined(BSP_CFG_CORE_CR52)
 #if 0 == BSP_CFG_CORE_CR52

    /* CPU0 TCM access via AXIS */
    if (dest_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        dest_address += NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET;
    }

 #else

    /* CPU1 TCM access via AXIS */
    if (dest_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        dest_address += NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET;
    }
 #endif
#endif

    if (0 != p_extend->oob_data_size)
    {
        dest_address_oob = (uintptr_t) p_dest_buffer->p_oob_data_buffer;

#if defined(BSP_CFG_CORE_CA55)
        va  = dest_address_oob;
        err = R_BSP_MmuVatoPa(va, &pa);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_INVALID_ADDRESS);

        dest_address_oob = pa;
#elif defined(BSP_CFG_CORE_CR52)
 #if 0 == BSP_CFG_CORE_CR52

        /* CPU0 TCM access via AXIS */
        if (dest_address_oob < NANDC_PRV_TCM_END_ADDRESS)
        {
            dest_address_oob += NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET;
        }

 #else

        /* CPU1 TCM access via AXIS */
        if (dest_address_oob < NANDC_PRV_TCM_END_ADDRESS)
        {
            dest_address_oob += NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET;
        }
 #endif
#endif

        /* Set lower part of destination address of oob data. */
        p_instance_ctrl->p_reg->CMDREG5 = (uint32_t) dest_address_oob;

        /* Set higher part of destination address of oob data. */
        p_instance_ctrl->p_reg->CMDREG6 =
            (uint32_t) ((uint64_t) dest_address_oob >> NANDC_PRV_ADDR_HIGHER_PART_OFFSET);
    }

    /* Set row address of NAND Flash. */
    p_instance_ctrl->p_reg->CMDREG1 = p_src_page->row_address;

    /* Set lower part of destination address */
    p_instance_ctrl->p_reg->CMDREG2 = (uint32_t) dest_address;

    /* Set higher part of destination address. */
    p_instance_ctrl->p_reg->CMDREG3 = (uint32_t) ((uint64_t) dest_address >> NANDC_PRV_ADDR_HIGHER_PART_OFFSET);

    /* Select CE# pin. Only CE0# is used in this driver. */
    p_instance_ctrl->p_reg->CMDREG4 = NANDC_PRV_CHIP_SELECT_0 << NANDC_PRV_CMDREG_4_BANK_OFFSET;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_READ | (p_src_page->page_count - 1));
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_PAGE_READ;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Program data to the NAND Flash. Implements @ref nand_flash_api_t::write.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 * @retval FSP_ERR_INVALID_STATE    Configurations of the controller are changed to access raw data.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 * @retval FSP_ERR_INVALID_ADDRESS  Source address is invalid.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Write (nand_flash_ctrl_t * const              p_ctrl,
                         nand_flash_data_buffer_t const * const p_src_buffer,
                         nand_flash_device_page_t const * const p_dest_page,
                         uint32_t const                         chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_src_buffer);
    FSP_ASSERT(NULL != p_src_buffer->p_main_data_buffer);
    FSP_ASSERT(NULL != p_dest_page);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(row_addr_upper_limit >= (p_dest_page->row_address + p_dest_page->page_count),
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(0 < p_dest_page->page_count, FSP_ERR_INVALID_ARGUMENT);
#endif

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    if ((NANDC_MULTIPLANE_COMMAND_ENABLE == p_extend->multiplane_write_enable) &&
        (NANDC_MULTIPLANE_NUMBER_1 != p_extend->plane_number))
    {
        uint32_t block_addr_start_offset = NANDC_PRV_ROW_ADDRESS_SIZE - __CLZ(page_per_block - 1);
        uint32_t block_number            = (p_dest_page->row_address >> block_addr_start_offset) & (block_per_lun - 1);
        uint32_t num_plane               = p_extend->plane_number << 1U;

        FSP_ERROR_RETURN(0 == block_number % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(0 == p_dest_page->page_count % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(row_addr_upper_limit >=
                         (p_dest_page->row_address +
                          ((p_dest_page->page_count / num_plane) << block_addr_start_offset) +
                          p_dest_page->page_count / num_plane),
                         FSP_ERR_INVALID_ARGUMENT);
    }
#endif

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check thread status */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->TRDSTAT & NANDC_PRV_TRDSTAT_THREAD_0_MASK), FSP_ERR_DEVICE_BUSY);

    /* Modify source address for TCM. */
    uintptr_t src_address;
    uintptr_t src_address_oob;

    src_address = (uintptr_t) p_src_buffer->p_main_data_buffer;

#if defined(BSP_CFG_CORE_CA55)
    fsp_err_t err;
    uint64_t  va;                      // Virtual address.
    uint64_t  pa;                      // Physical address.

    va  = src_address;
    err = R_BSP_MmuVatoPa(va, &pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_INVALID_ADDRESS);

    src_address = pa;
#elif defined(BSP_CFG_CORE_CR52)
 #if 0 == BSP_CFG_CORE_CR52

    /* CPU0 TCM access via AXIS */
    if (src_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        src_address += NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET;
    }

 #else

    /* CPU1 TCM access via AXIS */
    if (src_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        src_address += NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET;
    }
 #endif
#endif

    if (0 != p_extend->oob_data_size)
    {
        src_address_oob = (uintptr_t) p_src_buffer->p_oob_data_buffer;

#if defined(BSP_CFG_CORE_CA55)
        va  = src_address_oob;
        err = R_BSP_MmuVatoPa(va, &pa);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_INVALID_ADDRESS);

        src_address_oob = pa;
#elif defined(BSP_CFG_CORE_CR52)
 #if 0 == BSP_CFG_CORE_CR52

        /* CPU0 TCM access via AXIS */
        if (src_address_oob < NANDC_PRV_TCM_END_ADDRESS)
        {
            src_address_oob += NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET;
        }

 #else

        /* CPU1 TCM access via AXIS */
        if (src_address_oob < NANDC_PRV_TCM_END_ADDRESS)
        {
            src_address_oob += NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET;
        }
 #endif
#endif

        /* Set lower part of destination address of OOB data. */
        p_instance_ctrl->p_reg->CMDREG5 = (uint32_t) src_address_oob;

        /* Set higher part of destination address of OOB data. */
        p_instance_ctrl->p_reg->CMDREG6 =
            (uint32_t) ((uint64_t) src_address_oob >> NANDC_PRV_ADDR_HIGHER_PART_OFFSET);
    }

    /* Set row address of NAND Flash. */
    p_instance_ctrl->p_reg->CMDREG1 = p_dest_page->row_address;

    /* Set lower part of source address */
    p_instance_ctrl->p_reg->CMDREG2 = (uint32_t) src_address;

    /* Set higher part of source address. */
    p_instance_ctrl->p_reg->CMDREG3 = (uint32_t) ((uint64_t) src_address >> NANDC_PRV_ADDR_HIGHER_PART_OFFSET);

    /* Select CE# pin. Only CE0# is used in this driver. */
    p_instance_ctrl->p_reg->CMDREG4 = NANDC_PRV_CHIP_SELECT_0 << NANDC_PRV_CMDREG_4_BANK_OFFSET;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_WRITE | (p_dest_page->page_count - 1));
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_PAGE_PROGRAM;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Erases block data in the NAND Flash. Implements @ref nand_flash_api_t::erase.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_STATE    Configurations of the controller are changed to access raw data.
 * @retval FSP_ERR_INVALID_ARGUMENT Device block information is invalid.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Erase (nand_flash_ctrl_t * const p_ctrl,
                         uint32_t const            block,
                         uint32_t const            block_count,
                         uint32_t const            chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t block_per_lun = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t number_of_lun = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;

    FSP_ERROR_RETURN(0 < block_count, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(block_per_lun * number_of_lun > block + block_count, FSP_ERR_INVALID_ARGUMENT);
#endif

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    if ((NANDC_MULTIPLANE_COMMAND_ENABLE == p_extend->multiplane_write_enable) &&
        (NANDC_MULTIPLANE_NUMBER_1 != p_extend->plane_number))
    {
        uint32_t num_plane = p_extend->plane_number << 1U;

        FSP_ERROR_RETURN(0 == block % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(0 == block_count % num_plane, FSP_ERR_INVALID_ARGUMENT);
    }
#endif

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check thread status */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->TRDSTAT & NANDC_PRV_TRDSTAT_THREAD_0_MASK), FSP_ERR_DEVICE_BUSY);

    /* Set row address of NAND Flash. */
    uint32_t block_addr_start_offset = NANDC_PRV_ROW_ADDRESS_SIZE -
                                       __CLZ(p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB - 1);

    p_instance_ctrl->p_reg->CMDREG1 = block << block_addr_start_offset;

    /* Select CE# pin. Only CE0# is used in this driver. */
    p_instance_ctrl->p_reg->CMDREG4 = NANDC_PRV_CHIP_SELECT_0 << NANDC_PRV_CMDREG_4_BANK_OFFSET;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_ERASE | (block_count - 1));
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_BLOCK_ERASE;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Copy pages to another NAND Flash region. Implements @ref nand_flash_api_t::copyback.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_STATE    Configurations of the controller are changed to access raw data.
 *                                  Multi-plane configurations for read and write do not match.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_Copyback (nand_flash_ctrl_t * const              p_ctrl,
                            nand_flash_device_page_t const * const p_src_page,
                            nand_flash_device_page_t const * const p_dest_page,
                            uint32_t const                         chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_src_page);
    FSP_ASSERT(NULL != p_dest_page);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    FSP_ERROR_RETURN(p_src_page->page_count == p_dest_page->page_count, FSP_ERR_INVALID_ARGUMENT);

    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(row_addr_upper_limit >= (p_src_page->row_address + p_src_page->page_count),
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(row_addr_upper_limit >= (p_dest_page->row_address + p_dest_page->page_count),
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(0 < p_src_page->page_count, FSP_ERR_INVALID_ARGUMENT);
#endif

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_extend->multiplane_read_enable == p_extend->multiplane_write_enable, FSP_ERR_INVALID_STATE);

    if ((NANDC_MULTIPLANE_COMMAND_ENABLE == p_extend->multiplane_read_enable) &&
        (NANDC_MULTIPLANE_NUMBER_1 != p_extend->plane_number))
    {
        uint32_t block_addr_start_offset = NANDC_PRV_ROW_ADDRESS_SIZE - __CLZ(page_per_block - 1);
        uint32_t block_number_src        = (p_src_page->row_address >> block_addr_start_offset) & (block_per_lun - 1);
        uint32_t block_number_dest       = (p_dest_page->row_address >> block_addr_start_offset) & (block_per_lun - 1);
        uint32_t num_plane               = p_extend->plane_number << 1U;

        FSP_ERROR_RETURN(0 == block_number_src % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(0 == block_number_dest % num_plane, FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(row_addr_upper_limit >=
                         (p_src_page->row_address + ((p_src_page->page_count / num_plane) << block_addr_start_offset) +
                          p_src_page->page_count / num_plane),
                         FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(row_addr_upper_limit >=
                         (p_dest_page->row_address +
                          ((p_dest_page->page_count / num_plane) << block_addr_start_offset) +
                          p_dest_page->page_count / num_plane),
                         FSP_ERR_INVALID_ARGUMENT);
        FSP_ERROR_RETURN(0 == p_src_page->page_count % num_plane, FSP_ERR_INVALID_ARGUMENT);
    }
#endif

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check thread status */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->TRDSTAT & NANDC_PRV_TRDSTAT_THREAD_0_MASK), FSP_ERR_DEVICE_BUSY);

    p_instance_ctrl->p_reg->CMDREG1 = p_src_page->row_address;
    p_instance_ctrl->p_reg->CMDREG2 = p_dest_page->row_address;

    /* Select CE# pin. Only CE0# is used in this driver. */
    p_instance_ctrl->p_reg->CMDREG4 = NANDC_PRV_CHIP_SELECT_0 << NANDC_PRV_CMDREG_4_BANK_OFFSET;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_COPYBACK | (p_src_page->page_count - 1));
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_COPYBACK;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Send reset command to the NAND Flash. Implements @ref nand_flash_api_t::deviceReset.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_STATE    Configurations of the controller are changed to access raw data.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_DeviceReset (nand_flash_ctrl_t * const p_ctrl, uint32_t const chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check thread status */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->TRDSTAT & NANDC_PRV_TRDSTAT_THREAD_1_MASK), FSP_ERR_DEVICE_BUSY);

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

    /* Abort thread operation before send reset command. */
    nandc_command_0_data_t dev_reset_command_0;
    dev_reset_command_0.command_0_reg = 0;

    dev_reset_command_0.command_0_bit.cmd_type  = (uint16_t) NANDC_PRV_CMD_TYPE_THREAD_RESET;
    dev_reset_command_0.command_0_bit.interrupt = NANDC_PRV_TRDCOMP_INT_DISABLE;
    dev_reset_command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    dev_reset_command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Set CMDREG0 and trigger thread reset. */
    p_instance_ctrl->p_reg->CMDREG0 = dev_reset_command_0.command_0_reg;

    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    /* Configure CMDREG0 */
    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_RESET);
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_1;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_1] = NANDC_OPERATION_RESET;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Send set feature command to the NAND Flash. Implements @ref nand_flash_api_t::featureSet.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_FeatureSet (nand_flash_ctrl_t * const p_ctrl,
                              uint32_t const            feature_address,
                              uint32_t const            feature_value,
                              uint32_t const            chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* Check thread status */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->TRDSTAT & NANDC_PRV_TRDSTAT_THREAD_0_MASK), FSP_ERR_DEVICE_BUSY);

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

    /* Set feature address of set feature command. */
    p_instance_ctrl->p_reg->CMDREG1 = feature_address;

    /* Set feature value of set feature command. */
    p_instance_ctrl->p_reg->CMDREG2 = feature_value;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) NANDC_PRV_CMD_TYPE_SET_FEATURE;
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_SET_FEATURE;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the device status by checking whether the threads are ready or not. Implements @ref nand_flash_api_t::statusGet.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_StatusGet (nand_flash_ctrl_t * const   p_ctrl,
                             uint32_t const              chip_select,
                             nand_flash_status_t * const p_status)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t chip_select_status_bits = 0;
    for (uint32_t thread = 0; thread < NANDC_PRV_THREAD_NUMBER; thread++)
    {
        chip_select_status_bits |= (uint32_t) (chip_select == thread_chip_select[thread]) << thread;
    }

    p_status->device_status =
        (nand_flash_device_status_t) (0 != ((p_instance_ctrl->p_reg->TRDSTAT) & chip_select_status_bits));

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 * Implements @ref nand_flash_api_t::callbackSet.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_CallbackSet (nand_flash_ctrl_t * const          p_ctrl,
                               void (                           * p_callback)(nand_flash_callback_args_t *),
                               void const * const                 p_context,
                               nand_flash_callback_args_t * const p_callback_memory)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get NAND Flash information obtained in Device Discovery process. Implements @ref nand_flash_api_t::infoGet.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_InfoGet (nand_flash_ctrl_t * const p_ctrl, nand_flash_device_info_t * const p_info)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_info);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    uint32_t nfdevarea = p_instance_ctrl->p_reg->NFDEVAREA;
    p_info->data_bytes_per_page  = (nfdevarea & R_NANDC_NFDEVAREA_MAINAREASZ_Msk) >> R_NANDC_NFDEVAREA_MAINAREASZ_Pos;
    p_info->spare_bytes_per_page = (nfdevarea & R_NANDC_NFDEVAREA_SPAREASZ_Msk) >> R_NANDC_NFDEVAREA_SPAREASZ_Pos;

    p_info->number_of_luns           = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;
    p_info->number_of_blocks_per_lun = p_instance_ctrl->p_reg->DEVBLKPERLUN;

    uint32_t devfeat = p_instance_ctrl->p_reg->DEVFEAT;
    p_info->device_feature.device_features = (uint16_t) ((devfeat & R_NANDC_DEVFEAT_DEVFEATURE_Msk) >>
                                                         R_NANDC_DEVFEAT_DEVFEATURE_Pos);
    p_info->optional_commands.optional_commands = (uint16_t) ((devfeat & R_NANDC_DEVFEAT_OPTIONCMD_Msk) >>
                                                              R_NANDC_DEVFEAT_OPTIONCMD_Pos);

    p_info->support_timing_mode.timing_modes = (uint16_t) p_instance_ctrl->p_reg->ONFITMD0;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads raw data from the NAND Flash. Implements @ref nand_flash_api_t::rawRead.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 * @retval FSP_ERR_INVALID_STATE    Command complete interrupt is disabled. This function can only be used when command complete interrupt is enabled.
 *                                  \n Another access to raw data is in progress.
 * @retval FSP_ERR_INVALID_ADDRESS  Destination address is invalid.
 *
 * @note This function accesses all bytes on the selected pages, independent of sector configurations.
 *       Therefore, confirm the number of bytes per page for the connected NAND Flash, and prepare the data buffer for all bytes of the pages to be accessed.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_RawRead (nand_flash_ctrl_t * const              p_ctrl,
                           nand_flash_device_page_t const * const p_src_page,
                           uint8_t * const                        p_dest,
                           uint32_t const                         chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_dest);
    FSP_ASSERT(NULL != p_src_page);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(row_addr_upper_limit >= (p_src_page->row_address + p_src_page->page_count),
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(0 < p_src_page->page_count, FSP_ERR_INVALID_ARGUMENT);
#endif

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* RawRead works only when command complete interrupt is enabled. */
    FSP_ERROR_RETURN(NANDC_INT_ENABLE == p_extend->command_complete_interrupt, FSP_ERR_INVALID_STATE);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check controller status. */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY), FSP_ERR_DEVICE_BUSY);

    /* Set registers and set a flag for raw access.*/
    r_nandc_raw_access_config(p_instance_ctrl);

    /* Modify destination address for TCM. */
    uintptr_t dest_address = (uintptr_t) p_dest;

#if defined(BSP_CFG_CORE_CA55)
    fsp_err_t err;
    uint64_t  va;                      // Virtual address.
    uint64_t  pa;                      // Physical address.

    va  = dest_address;
    err = R_BSP_MmuVatoPa(va, &pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_INVALID_ADDRESS);

    dest_address = pa;
#elif defined(BSP_CFG_CORE_CR52)
 #if 0 == BSP_CFG_CORE_CR52

    /* CPU0 TCM access via AXIS */
    if (dest_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        dest_address += NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET;
    }

 #else

    /* CPU1 TCM access via AXIS */
    if (dest_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        dest_address += NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET;
    }
 #endif
#endif

    /* Set row address of NAND Flash. */
    p_instance_ctrl->p_reg->CMDREG1 = p_src_page->row_address;

    /* Set lower part of destination address */
    p_instance_ctrl->p_reg->CMDREG2 = (uint32_t) dest_address;

    /* Set higher part of destination address. */
    p_instance_ctrl->p_reg->CMDREG3 = (uint32_t) ((uint64_t) dest_address >> NANDC_PRV_ADDR_HIGHER_PART_OFFSET);

    /* Select CE# pin. Only CE0# is used in this driver. */
    p_instance_ctrl->p_reg->CMDREG4 = NANDC_PRV_CHIP_SELECT_0 << NANDC_PRV_CMDREG_4_BANK_OFFSET;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_READ | (p_src_page->page_count - 1));
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_PAGE_READ;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Program data to the NAND Flash. Implements @ref nand_flash_api_t::rawWrite.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 * @retval FSP_ERR_INVALID_STATE    Command complete interrupt is disabled. This function can only be used when command complete interrupt is enabled.
 *                                  \n Another access to raw data is in progress.
 * @retval FSP_ERR_INVALID_ADDRESS  Source address is invalid.
 *
 * @note This function accesses all bytes on the selected pages, independent of sector configurations.
 *       Therefore, confirm the number of bytes per page for the connected NAND Flash, and prepare the source data for all bytes of the pages to be accessed.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_RawWrite (nand_flash_ctrl_t * const              p_ctrl,
                            uint8_t const * const                  p_src,
                            nand_flash_device_page_t const * const p_dest_page,
                            uint32_t const                         chip_select)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest_page);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(row_addr_upper_limit >= (p_dest_page->row_address + p_dest_page->page_count),
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(0 < p_dest_page->page_count, FSP_ERR_INVALID_ARGUMENT);
#endif

    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

    /* This driver always access to chip select 0 target. */
    FSP_PARAMETER_NOT_USED(chip_select);

    /* RawWrite works only when command complete interrupt is enabled. */
    FSP_ERROR_RETURN(NANDC_INT_ENABLE == p_extend->command_complete_interrupt, FSP_ERR_INVALID_STATE);

    /* Check raw access flag. */
    FSP_ERROR_RETURN(0 == raw_config_flag, FSP_ERR_INVALID_STATE);

    /* Check controller status. */
    FSP_ERROR_RETURN(0 == (p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY), FSP_ERR_DEVICE_BUSY);

    /* Set registers and set a flag for raw access.*/
    r_nandc_raw_access_config(p_instance_ctrl);

    /* Modify source address for TCM. */
    uintptr_t src_address = (uintptr_t) p_src;

#if defined(BSP_CFG_CORE_CA55)
    fsp_err_t err;
    uint64_t  va;                      // Virtual address.
    uint64_t  pa;                      // Physical address.

    va  = src_address;
    err = R_BSP_MmuVatoPa(va, &pa);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, FSP_ERR_INVALID_ADDRESS);

    src_address = pa;
#elif defined(BSP_CFG_CORE_CR52)
 #if 0 == BSP_CFG_CORE_CR52

    /* CPU0 TCM access via AXIS */
    if (src_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        src_address += NANDC_PRV_CPU0_TCM_AXIS_ACCESS_OFFSET;
    }

 #else

    /* CPU1 TCM access via AXIS */
    if (src_address < NANDC_PRV_TCM_END_ADDRESS)
    {
        src_address += NANDC_PRV_CPU1_TCM_AXIS_ACCESS_OFFSET;
    }
 #endif
#endif

    /* Set row address of NAND Flash. */
    p_instance_ctrl->p_reg->CMDREG1 = p_dest_page->row_address;

    /* Set lower part of source address */
    p_instance_ctrl->p_reg->CMDREG2 = (uint32_t) src_address;

    /* Set higher part of source address. */
    p_instance_ctrl->p_reg->CMDREG3 = (uint32_t) ((uint64_t) src_address >> NANDC_PRV_ADDR_HIGHER_PART_OFFSET);

    /* Select CE# pin. Only CE0# is used in this driver. */
    p_instance_ctrl->p_reg->CMDREG4 = NANDC_PRV_CHIP_SELECT_0 << NANDC_PRV_CMDREG_4_BANK_OFFSET;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) (NANDC_PRV_CMD_TYPE_WRITE | (p_dest_page->page_count - 1));
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = p_extend->command_complete_interrupt;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Store last operation. */
    thread_last_operation[NANDC_PRV_THREAD_NUM_0] = NANDC_OPERATION_PAGE_PROGRAM;
    thread_chip_select[NANDC_PRV_THREAD_NUM_0]    = NANDC_CHIP_SELECT_0;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Set logical address to physical address mapping table in NANDC.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_RemapSet (nand_flash_ctrl_t * const p_ctrl,
                            uint32_t const            logical_address,
                            uint32_t const            physical_address)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(row_addr_upper_limit >= physical_address, FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Check controller status */
    FSP_ERROR_RETURN(0 == p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, FSP_ERR_DEVICE_BUSY);

    /* Set write record mode. */
    p_instance_ctrl->p_reg->REMAPACCESS_b.RECACTYPE = 0;

    p_instance_ctrl->p_reg->REMAPLOGADDR = logical_address;

    p_instance_ctrl->p_reg->REMAPPHYSADDR = physical_address;

    /* Start write record. */
    p_instance_ctrl->p_reg->REMAPACCESS_b.RECACCESS = 1;

    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->REMAPACCESS_b.RECACCESS, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Clear all data in logical address to physical address mapping table in NANDC.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_RemapClear (nand_flash_ctrl_t * const p_ctrl)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Check controller status */
    FSP_ERROR_RETURN(0 == p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, FSP_ERR_DEVICE_BUSY);

    /* Set clear all record mode. */
    p_instance_ctrl->p_reg->REMAPACCESS_b.RECACTYPE = 2;

    /* Start clear record. */
    p_instance_ctrl->p_reg->REMAPACCESS_b.RECACCESS = 1;

    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->REMAPACCESS_b.RECACCESS, 0);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the controller status by checking whether the controller is ready or not.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Device address information is invalid.
 *                                  Index exceeds the number of the write-protected address ranges that the controller can set.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 *
 * @note NANDC can specify up to two write-protected address ranges. Therefore, index should be set to 0 or 1.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_WriteProtectEnable (nand_flash_ctrl_t * const p_ctrl,
                                      uint32_t const            start_address,
                                      uint32_t const            size,
                                      uint32_t const            index)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    uint32_t number_of_lun  = p_instance_ctrl->p_reg->DEVPARAM0_b.NUMLUN;
    uint32_t block_per_lun  = p_instance_ctrl->p_reg->DEVBLKPERLUN;
    uint32_t page_per_block = p_instance_ctrl->p_reg->NFDEVLAYOUT_b.PPB;

    uint32_t row_addr_upper_limit = number_of_lun * block_per_lun * page_per_block - 1;

    FSP_ERROR_RETURN(0 < size, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(row_addr_upper_limit >= (start_address + size), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(index < NANDC_PRV_WRITE_PROTECT_REGION_NUM, FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Check controller status */
    FSP_ERROR_RETURN(0 == p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, FSP_ERR_DEVICE_BUSY);

    if (0 == index)
    {
        p_instance_ctrl->p_reg->PROTCTRL0 = 1;
        p_instance_ctrl->p_reg->PROTDOWN0 = start_address;
        p_instance_ctrl->p_reg->PROTUP0   = start_address + size;
    }
    else if (1 == index)
    {
        p_instance_ctrl->p_reg->PROTCTRL1 = 1;
        p_instance_ctrl->p_reg->PROTDOWN1 = start_address;
        p_instance_ctrl->p_reg->PROTUP1   = start_address + size;
    }
    else
    {
        /* Do nothing. */
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Clear the address range to protect write access.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 * @retval FSP_ERR_INVALID_ARGUMENT Index exceeds the number of the address range that the controller can set as write protect.
 * @retval FSP_ERR_DEVICE_BUSY      The thread is in busy state.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_WriteProtectDisable (nand_flash_ctrl_t * const p_ctrl, uint32_t const index)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    FSP_ERROR_RETURN(index < NANDC_PRV_WRITE_PROTECT_REGION_NUM, FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Check controller status */
    FSP_ERROR_RETURN(0 == p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, FSP_ERR_DEVICE_BUSY);

    if (0 == index)
    {
        p_instance_ctrl->p_reg->PROTCTRL0 = 0;
    }
    else if (1 == index)
    {
        p_instance_ctrl->p_reg->PROTCTRL1 = 0;
    }
    else
    {
        /* Do nothing. */
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the device status by checking whether the controller is ready or not.
 *
 * @retval FSP_SUCCESS              Successful close.
 * @retval FSP_ERR_ASSERTION        A required pointer is NULL.
 * @retval FSP_ERR_NOT_OPEN         Driver has not been initialized.
 **********************************************************************************************************************/
fsp_err_t R_NANDC_ControllerStatusGet (nand_flash_ctrl_t * const p_ctrl, nandc_controller_status_t * const p_status)
{
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) p_ctrl;

#if NANDC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(NANDC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    p_status->status = (nandc_controller_state_t) p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY;

    return FSP_SUCCESS;
}

/** @} (end addtogroup NANDC) */
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures NANDC registers based on the user configuration.
 * @param      p_instance_ctrl          Pointer to control structure.
 **********************************************************************************************************************/
static void r_nandc_hw_config (nandc_instance_ctrl_t * p_instance_ctrl)
{
    nandc_extended_cfg_t * p_cfg_extend = (nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* ECC enabling configuration (see RZ microprocessor Hardware Manual section "ECC Enabling") */
    p_instance_ctrl->p_reg->ECCCFG0 = (p_cfg_extend->ecc_enable << R_NANDC_ECCCFG0_ECCEN_Pos) |
                                      (p_cfg_extend->ecc_correction_ability << R_NANDC_ECCCFG0_CORRSTR_Pos);

    p_instance_ctrl->p_reg->TRFCFG0_b.SECTORCNT = p_cfg_extend->sector_number;
    p_instance_ctrl->p_reg->TRFCFG1             = (p_cfg_extend->sector_bytes << R_NANDC_TRFCFG1_SECTORSZ_Pos) |
                                                  (p_cfg_extend->sector_bytes << R_NANDC_TRFCFG1_LASTSECTORSZ_Pos);

    p_instance_ctrl->p_reg->CTRLDATACTRL = p_cfg_extend->oob_data_size;

    p_instance_ctrl->p_reg->ECCCFG0_b.SCRAMEN = p_cfg_extend->data_scrambling_enable;

    p_instance_ctrl->p_reg->SKIPBYTEOFFSET = p_cfg_extend->skip_bytes_offset <<
                                             R_NANDC_SKIPBYTEOFFSET_SKIPBYTEOFFSET_Pos;
    p_instance_ctrl->p_reg->SKIPBYTECFG = (p_cfg_extend->skip_bytes_size << R_NANDC_SKIPBYTECFG_SKIPBYTE_Pos) |
                                          (p_cfg_extend->skip_bytes_marker_value << R_NANDC_SKIPBYTECFG_MARKER_Pos);

    p_instance_ctrl->p_reg->ECCCFG0_b.ERSDETEN  = p_cfg_extend->erased_page_detection;
    p_instance_ctrl->p_reg->ECCCFG1_b.ERSDETLVL = p_cfg_extend->erase_detection_level;

    /* CRC settings. */
    p_instance_ctrl->p_reg->DICTRL_b.CRCEN = p_cfg_extend->crc_enable;

    /* Multi-plane settings. */
    p_instance_ctrl->p_reg->MPLCFG = (p_cfg_extend->multiplane_read_enable << R_NANDC_MPLCFG_MPLRDEN_Pos) |
                                     (p_cfg_extend->multiplane_write_enable << R_NANDC_MPLCFG_MPLWREN_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLCPBKRDSEQ_Pos) |
                                     (p_cfg_extend->plane_number << R_NANDC_MPLCFG_MPLPLNUM_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLPRGSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLRDSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLERASESEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_LASTWRCMD_Pos) |
                                     (0 << R_NANDC_MPLCFG_PLSTATEN_Pos);

    /* Cache command is enabled if supported. */
    /* Check cache command feature support. */
    uint32_t optional_command    = p_instance_ctrl->p_reg->DEVFEAT_b.OPTIONCMD;
    uint32_t cache_read_support  = (optional_command >> 1U) & 1U;
    uint32_t cache_write_support = (optional_command >> 0U) & 1U;

    /* Check multi-plane cache operation support. */
    uint32_t multiplane_attribute = p_instance_ctrl->p_reg->ONFIILOPATTR;
    cache_read_support  &= ((multiplane_attribute >> 4U) & 1U) | !(p_cfg_extend->multiplane_read_enable);
    cache_write_support &= ((multiplane_attribute >> 2U) & 1U) | !(p_cfg_extend->multiplane_write_enable);

    p_instance_ctrl->p_reg->CACHECFG = (cache_read_support << R_NANDC_CACHECFG_CACHERDEN_Pos) |
                                       (cache_write_support << R_NANDC_CACHECFG_CACHEWREN_Pos);

    /* Set command timeout cycles. */
    if (0 != p_cfg_extend->command_timeout_count)
    {
        p_instance_ctrl->p_reg->TIMEOUT             = p_cfg_extend->command_timeout_count;
        p_instance_ctrl->p_reg->DEVCTRL_b.TIMEOUTEN = 1;
    }

    /* Set REMAP common settings. */
    p_instance_ctrl->p_reg->REMAPCTRL_b.RMPEN = p_cfg_extend->remap_enable;
    p_instance_ctrl->p_reg->REMAPMASK         = p_cfg_extend->remap_valid_bits;

    /* Set RE# and WE# timing mode. */
    uint32_t dllphyctrl = p_instance_ctrl->p_reg->DLLPHYCTRL;

    dllphyctrl &= ~((uint32_t) R_NANDC_DLLPHYCTRL_EXTENDRMD_Msk | (uint32_t) R_NANDC_DLLPHYCTRL_EXTENDWMD_Msk);

    dllphyctrl |= (uint32_t) (((p_cfg_extend->read_enable_signal_timing_mode << R_NANDC_DLLPHYCTRL_EXTENDRMD_Pos) &
                               R_NANDC_DLLPHYCTRL_EXTENDRMD_Msk) |
                              ((p_cfg_extend->write_enable_signal_timing_mode << R_NANDC_DLLPHYCTRL_EXTENDWMD_Pos) &
                               R_NANDC_DLLPHYCTRL_EXTENDWMD_Msk));

    p_instance_ctrl->p_reg->DLLPHYCTRL = dllphyctrl;

    /* Set ready status detection mode. */
    p_instance_ctrl->p_reg->RDSTCTRL0_b.RBEN = p_cfg_extend->ready_status_detection_method;

    /* Set status polling delay */
    if (NANDC_DEVICE_STATUS_DETECTION_POLLING == p_cfg_extend->ready_status_detection_method)
    {
        p_instance_ctrl->p_reg->LONGPOLL  = p_cfg_extend->long_polling_time;
        p_instance_ctrl->p_reg->SHORTPOLL = p_cfg_extend->short_polling_time;
    }

    /* Send set feature command and change timing mode of NAND Flash before changing signal timings. */
    /* Set feature address of set feature command. */
    p_instance_ctrl->p_reg->CMDREG1 = NANDC_PRV_TIMING_MODE_ADDRESS;

    /* Set feature value of set feature command. */
    p_instance_ctrl->p_reg->CMDREG2 = p_cfg_extend->flash_timing_mode;

    /* Configure CMDREG0 */
    nandc_command_0_data_t command_0;
    command_0.command_0_reg = 0;

    command_0.command_0_bit.cmd_type  = (uint16_t) NANDC_PRV_CMD_TYPE_SET_FEATURE;
    command_0.command_0_bit.vol_id    = NANDC_PRV_VOL_ID_0;
    command_0.command_0_bit.interrupt = 0;
    command_0.command_0_bit.dma_sel   = NANDC_PRV_DMA_SEL;
    command_0.command_0_bit.trd_num   = NANDC_PRV_THREAD_NUM_0;
    command_0.command_0_bit.ct        = NANDC_PRV_CT;

    /* Set CMDREG0 and trigger PIO Work Mode operation. */
    p_instance_ctrl->p_reg->CMDREG0 = command_0.command_0_reg;

    /* Wait for controller to be idle state. */
    FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, 0);

    r_nandc_timing_config(p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * Configures NANDC timing registers based on the user configuration.
 * @param      p_instance_ctrl          Pointer to control structure.
 **********************************************************************************************************************/
static void r_nandc_timing_config (nandc_instance_ctrl_t * p_instance_ctrl)
{
    nandc_extended_cfg_t * p_cfg_extend = (nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Modify data for register value specifications. */
    uint32_t we_pulse_width    = p_cfg_extend->p_signal_timing_info->we_pulse_width - NANDC_PRV_TWP_ACTUAL_CYCLES_DIFF;
    uint32_t we_high_hold_time = p_cfg_extend->p_signal_timing_info->we_high_hold_time -
                                 NANDC_PRV_TWH_ACTUAL_CYCLES_DIFF;
    uint32_t re_pulse_width    = p_cfg_extend->p_signal_timing_info->re_pulse_width - NANDC_PRV_TRP_ACTUAL_CYCLES_DIFF;
    uint32_t re_high_hold_time = p_cfg_extend->p_signal_timing_info->re_high_hold_time -
                                 NANDC_PRV_TREH_ACTUAL_CYCLES_DIFF;

    /* Configure timings for tWP, tWH, tRP, tREH. */
    uint32_t asynctoggletiming = p_instance_ctrl->p_reg->ASYNCTOGGLETIMING;
    asynctoggletiming &= ~((uint32_t) R_NANDC_ASYNCTOGGLETIMING_TWP_Msk | (uint32_t) R_NANDC_ASYNCTOGGLETIMING_TWH_Msk |
                           (uint32_t) R_NANDC_ASYNCTOGGLETIMING_TRP_Msk | (uint32_t) R_NANDC_ASYNCTOGGLETIMING_TRH_Msk);
    asynctoggletiming |=
        (uint32_t) ((we_pulse_width << R_NANDC_ASYNCTOGGLETIMING_TWP_Pos) & R_NANDC_ASYNCTOGGLETIMING_TWP_Msk);
    asynctoggletiming |=
        (uint32_t) ((we_high_hold_time << R_NANDC_ASYNCTOGGLETIMING_TWH_Pos) & R_NANDC_ASYNCTOGGLETIMING_TWH_Msk);
    asynctoggletiming |=
        (uint32_t) ((re_pulse_width << R_NANDC_ASYNCTOGGLETIMING_TRP_Pos) & R_NANDC_ASYNCTOGGLETIMING_TRP_Msk);
    asynctoggletiming |=
        (uint32_t) ((re_high_hold_time << R_NANDC_ASYNCTOGGLETIMING_TRH_Pos) & R_NANDC_ASYNCTOGGLETIMING_TRH_Msk);
    p_instance_ctrl->p_reg->ASYNCTOGGLETIMING = asynctoggletiming;
    p_instance_ctrl->p_reg->PHYCTRLREG        = (re_pulse_width << R_NANDC_PHYCTRLREG_PHONYDQSTIMING_Pos) &
                                                R_NANDC_PHYCTRLREG_PHONYDQSTIMING_Msk;

    /* Modify data for register value specifications. */
    uint32_t re_high_to_we_low_time = p_cfg_extend->p_signal_timing_info->re_high_to_we_low_time -
                                      NANDC_PRV_TRHW_ACTUAL_CYCLES_DIFF;
    uint32_t we_high_to_re_low_time = p_cfg_extend->p_signal_timing_info->we_high_to_re_low_time -
                                      NANDC_PRV_TWHR_ACTUAL_CYCLES_DIFF;
    uint32_t ale_to_data_loading_time = p_cfg_extend->p_signal_timing_info->ale_to_data_loading_time -
                                        NANDC_PRV_TADL_ACTUAL_CYCLES_DIFF;

    /* Configure timings for tRHW, tWHR, tADL. */
    uint32_t timing0 = p_instance_ctrl->p_reg->TIMING0;
    timing0 &=
        ~((uint32_t) R_NANDC_TIMING0_TRHW_Msk | (uint32_t) R_NANDC_TIMING0_TWHR_Msk |
          (uint32_t) R_NANDC_TIMING0_TADL_Msk);
    timing0 |= (uint32_t) ((re_high_to_we_low_time << R_NANDC_TIMING0_TRHW_Pos) & R_NANDC_TIMING0_TRHW_Msk);
    timing0 |= (uint32_t) ((we_high_to_re_low_time << R_NANDC_TIMING0_TWHR_Pos) & R_NANDC_TIMING0_TWHR_Msk);
    timing0 |= (uint32_t) ((ale_to_data_loading_time << R_NANDC_TIMING0_TADL_Pos) & R_NANDC_TIMING0_TADL_Msk);
    p_instance_ctrl->p_reg->TIMING0 = timing0;

    /* Modify data for register value specifications. */
    uint32_t command_end_to_sr6_low = p_cfg_extend->p_signal_timing_info->command_end_to_sr6_low -
                                      NANDC_PRV_TWB_ACTUAL_CYCLES_DIFF;
    uint32_t re_high_to_output_hiz = p_cfg_extend->p_signal_timing_info->re_high_to_output_hiz -
                                     NANDC_PRV_TRHZ_ACTUAL_CYCLES_DIFF;

    /* Configure timings for tWB, tRHZ. */
    uint32_t timing1 = p_instance_ctrl->p_reg->TIMING1;
    timing1 &= ~((uint32_t) R_NANDC_TIMING1_TWB_Msk | (uint32_t) R_NANDC_TIMING1_TRHZ_Msk);
    timing1 |= (uint32_t) ((command_end_to_sr6_low << R_NANDC_TIMING1_TWB_Pos) & R_NANDC_TIMING1_TWB_Msk);
    timing1 |= (uint32_t) ((re_high_to_output_hiz << R_NANDC_TIMING1_TRHZ_Pos) & R_NANDC_TIMING1_TRHZ_Msk);
    p_instance_ctrl->p_reg->TIMING1 = timing1;

    /* Modify data for register value specifications. */
    uint32_t ce_setup_time     = p_cfg_extend->p_signal_timing_info->ce_setup_time - NANDC_PRV_TCS_ACTUAL_CYCLES_DIFF;
    uint32_t ce_high_hold_time = p_cfg_extend->p_signal_timing_info->ce_high_hold_time -
                                 NANDC_PRV_TCEH_ACTUAL_CYCLES_DIFF;
    uint32_t interface_and_timing_mode_change_time =
        p_cfg_extend->p_signal_timing_info->interface_and_timing_mode_change_time -
        NANDC_PRV_TITC_ACTUAL_CYCLES_DIFF;

    /* Configure timings for tCS, tCEH, tITC. */
    uint32_t timing2 = p_instance_ctrl->p_reg->TIMING2;
    timing2 &=
        ~((uint32_t) R_NANDC_TIMING2_CSSETUP_Msk | (uint32_t) R_NANDC_TIMING2_CSHOLD_Msk |
          (uint32_t) R_NANDC_TIMING2_TFEAT_Msk);
    timing2 |= (uint32_t) ((ce_setup_time << R_NANDC_TIMING2_CSSETUP_Pos) & R_NANDC_TIMING2_CSSETUP_Msk);
    timing2 |= (uint32_t) ((ce_high_hold_time << R_NANDC_TIMING2_CSHOLD_Pos) & R_NANDC_TIMING2_CSHOLD_Msk);
    timing2 |=
        (uint32_t) ((interface_and_timing_mode_change_time << R_NANDC_TIMING2_TFEAT_Pos) & R_NANDC_TIMING2_TFEAT_Msk);
    p_instance_ctrl->p_reg->TIMING2 = timing2;
}

/*******************************************************************************************************************//**
 * Configures NANDC registers for raw data access operation.
 * @param      p_instance_ctrl          Pointer to control structure.
 **********************************************************************************************************************/
static void r_nandc_raw_access_config (nandc_instance_ctrl_t * p_instance_ctrl)
{
    /* Temporarily set configurations to invalid. */
    raw_config_flag = 1;

    /* Set sector to access all bytes in a page. */
    uint32_t page_size = p_instance_ctrl->p_reg->NFDEVAREA_b.MAINAREASZ + p_instance_ctrl->p_reg->NFDEVAREA_b.SPAREASZ;
    p_instance_ctrl->p_reg->TRFCFG0_b.SECTORCNT = 1;

    p_instance_ctrl->p_reg->TRFCFG1 =
        (uint32_t) ((page_size << R_NANDC_TRFCFG1_SECTORSZ_Pos) & R_NANDC_TRFCFG1_SECTORSZ_Msk) |
        (uint32_t) ((page_size << R_NANDC_TRFCFG1_LASTSECTORSZ_Pos) & R_NANDC_TRFCFG1_LASTSECTORSZ_Msk);

    p_instance_ctrl->p_reg->CTRLDATACTRL = 0;

    /* Disable ECC, CRC, Scrambling, Remap, erased page detection, skip bytes, multi-plane, and cache. */
    p_instance_ctrl->p_reg->ECCCFG0 = ((0 << R_NANDC_ECCCFG0_ECCEN_Pos) & R_NANDC_ECCCFG0_ECCEN_Msk) |
                                      ((0 << R_NANDC_ECCCFG0_ERSDETEN_Pos) & R_NANDC_ECCCFG0_ERSDETEN_Msk) |
                                      ((0 << R_NANDC_ECCCFG0_SCRAMEN_Pos) & R_NANDC_ECCCFG0_SCRAMEN_Msk) |
                                      ((0 << R_NANDC_ECCCFG0_CORRSTR_Pos) & R_NANDC_ECCCFG0_CORRSTR_Msk);
    p_instance_ctrl->p_reg->MPLCFG = (0 << R_NANDC_MPLCFG_MPLRDEN_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLWREN_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLCPBKRDSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLPLNUM_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLPRGSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLRDSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLERASESEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_LASTWRCMD_Pos) |
                                     (0 << R_NANDC_MPLCFG_PLSTATEN_Pos);
    p_instance_ctrl->p_reg->CACHECFG = ((0 << R_NANDC_CACHECFG_CACHERDEN_Pos) & R_NANDC_CACHECFG_CACHERDEN_Msk) |
                                       ((0 << R_NANDC_CACHECFG_CACHEWREN_Pos) & R_NANDC_CACHECFG_CACHEWREN_Msk);
    p_instance_ctrl->p_reg->DICTRL_b.CRCEN         = 0;
    p_instance_ctrl->p_reg->REMAPCTRL_b.RMPEN      = 0;
    p_instance_ctrl->p_reg->SKIPBYTECFG_b.SKIPBYTE = 0;
}

/*******************************************************************************************************************//**
 * Restore NANDC registers configured for raw data access operation.
 * @param      p_instance_ctrl          Pointer to control structure.
 **********************************************************************************************************************/
static void r_nandc_raw_access_config_recovery (nandc_instance_ctrl_t * p_instance_ctrl)
{
    nandc_extended_cfg_t * p_extend = ((nandc_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend);

    /* Restore registers. */
    p_instance_ctrl->p_reg->TRFCFG0_b.SECTORCNT = p_extend->sector_number;
    p_instance_ctrl->p_reg->TRFCFG1             =
        (uint32_t) ((p_extend->sector_bytes << R_NANDC_TRFCFG1_SECTORSZ_Pos) & R_NANDC_TRFCFG1_SECTORSZ_Msk) |
        (uint32_t) ((p_extend->sector_bytes << R_NANDC_TRFCFG1_LASTSECTORSZ_Pos) & R_NANDC_TRFCFG1_LASTSECTORSZ_Msk);

    p_instance_ctrl->p_reg->CTRLDATACTRL = p_extend->oob_data_size;

    p_instance_ctrl->p_reg->ECCCFG0 =
        (uint32_t) ((p_extend->ecc_enable << R_NANDC_ECCCFG0_ECCEN_Pos) & R_NANDC_ECCCFG0_ECCEN_Msk) |
        (uint32_t) ((p_extend->erased_page_detection << R_NANDC_ECCCFG0_ERSDETEN_Pos) &
                    R_NANDC_ECCCFG0_ERSDETEN_Msk) |
        (uint32_t) ((p_extend->data_scrambling_enable << R_NANDC_ECCCFG0_SCRAMEN_Pos) &
                    R_NANDC_ECCCFG0_SCRAMEN_Msk) |
        (uint32_t) ((p_extend->ecc_correction_ability << R_NANDC_ECCCFG0_CORRSTR_Pos) &
                    R_NANDC_ECCCFG0_CORRSTR_Msk);

    p_instance_ctrl->p_reg->MPLCFG = (p_extend->multiplane_read_enable << R_NANDC_MPLCFG_MPLRDEN_Pos) |
                                     (p_extend->multiplane_write_enable << R_NANDC_MPLCFG_MPLWREN_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLCPBKRDSEQ_Pos) |
                                     (p_extend->plane_number << R_NANDC_MPLCFG_MPLPLNUM_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLPRGSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLRDSEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_MPLERASESEQ_Pos) |
                                     (0 << R_NANDC_MPLCFG_LASTWRCMD_Pos) |
                                     (0 << R_NANDC_MPLCFG_PLSTATEN_Pos);

    uint32_t optional_command    = p_instance_ctrl->p_reg->DEVFEAT_b.OPTIONCMD;
    uint32_t cache_read_support  = (optional_command >> 1U) & 1U;
    uint32_t cache_write_support = (optional_command >> 0U) & 1U;

    uint32_t multiplane_attribute = p_instance_ctrl->p_reg->ONFIILOPATTR;
    cache_read_support  &= ((multiplane_attribute >> 4U) & 1U) | !(p_extend->multiplane_read_enable);
    cache_write_support &= ((multiplane_attribute >> 2U) & 1U) | !(p_extend->multiplane_write_enable);

    p_instance_ctrl->p_reg->CACHECFG = (cache_read_support << R_NANDC_CACHECFG_CACHERDEN_Pos) |
                                       (cache_write_support << R_NANDC_CACHECFG_CACHEWREN_Pos);

    p_instance_ctrl->p_reg->DICTRL_b.CRCEN         = p_extend->crc_enable;
    p_instance_ctrl->p_reg->REMAPCTRL_b.RMPEN      = p_extend->remap_enable;
    p_instance_ctrl->p_reg->SKIPBYTECFG_b.SKIPBYTE = p_extend->skip_bytes_size & R_NANDC_SKIPBYTECFG_SKIPBYTE_Msk;

    raw_config_flag = 0;
}

/*******************************************************************************************************************//**
 * Calls user callback.
 *
 * @param[in]     p_instance_ctrl     Pointer to NANDC instance control block
 * @param[in]     p_args              Pointer to callback arguments.
 **********************************************************************************************************************/
static void r_nandc_call_callback (nandc_instance_ctrl_t * p_instance_ctrl, nand_flash_callback_args_t * p_args)
{
    nand_flash_callback_args_t args;

    /* Store callback arguments in memory provided by user if available. */
    nand_flash_callback_args_t * p_args_memory = p_instance_ctrl->p_callback_memory;
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

    p_args_memory->p_context = p_instance_ctrl->p_context;

    p_instance_ctrl->p_callback(p_args_memory);

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }
}

/*******************************************************************************************************************//**
 * NANDC ISR
 **********************************************************************************************************************/
void nandc_int_isr (void)
{
    NANDC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    /* Recover ISR context saved in open. */
    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    nandc_instance_ctrl_t * p_instance_ctrl = (nandc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    nand_flash_callback_args_t args = {0};

    uint32_t thread_error_status   = p_instance_ctrl->p_reg->TRDERRINTSTAT;
    uint32_t thread_timeout_status = p_instance_ctrl->p_reg->TRDTMOINTSTAT;
    uint32_t thread_status         = p_instance_ctrl->p_reg->TRDCOMPINTSTAT;

    uint32_t thread =
        (NANDC_PRV_THREAD_0_STATUS_MASK == (thread_error_status | thread_timeout_status | thread_status)) ?
        NANDC_PRV_THREAD_NUM_0 :
        NANDC_PRV_THREAD_NUM_1;

    uint32_t thread_mask = 1U << thread;

    /* Read command status error. */
    uint32_t command_status_lower = p_instance_ctrl->p_reg->CMDSTAT;
    uint32_t command_status_upper = p_instance_ctrl->p_reg->CMDSTATEXT;

    /* This argument is intended to be cast to nandc_command_status_t. */
    args.error =
        (uint64_t) (((uint64_t) command_status_upper << NANDC_PRV_CMDSTATEXT_OFFSET) |
                    (uint64_t) command_status_lower);

    /* Handle error events. */
    if (0 != (thread_error_status & thread_mask))
    {
        /* Set CMDSTAT to selected thread. */
        p_instance_ctrl->p_reg->CMDSTATPTR = thread;

        FSP_REGISTER_READ(p_instance_ctrl->p_reg->CMDSTATPTR);

        switch (thread_last_operation[thread])
        {
            case NANDC_OPERATION_PAGE_READ:
            {
                args.event = NAND_FLASH_EVENT_READ_ERROR;
                break;
            }

            case NANDC_OPERATION_PAGE_PROGRAM:
            {
                args.event = NAND_FLASH_EVENT_WRITE_ERROR;
                break;
            }

            case NANDC_OPERATION_BLOCK_ERASE:
            {
                args.event = NAND_FLASH_EVENT_ERASE_ERROR;
                break;
            }

            case NANDC_OPERATION_RESET:
            {
                args.event = NAND_FLASH_EVENT_RESET_ERROR;
                break;
            }

            case NANDC_OPERATION_SET_FEATURE:
            {
                args.event = NAND_FLASH_EVENT_SET_FEATURE_ERROR;
                break;
            }

            case NANDC_OPERATION_COPYBACK:
            {
                args.event = NAND_FLASH_EVENT_COPYBACK_ERROR;
                break;
            }

            default:
            {
                /* Do nothing. */
                break;
            }
        }
    }
    /* Handle timeout events */
    else if (0 != (thread_timeout_status & thread_mask))
    {
        switch (thread_last_operation[thread])
        {
            case NANDC_OPERATION_PAGE_READ:
            {
                args.event = NAND_FLASH_EVENT_READ_TIMEOUT;
                break;
            }

            case NANDC_OPERATION_PAGE_PROGRAM:
            {
                args.event = NAND_FLASH_EVENT_WRITE_TIMEOUT;
                break;
            }

            case NANDC_OPERATION_BLOCK_ERASE:
            {
                args.event = NAND_FLASH_EVENT_ERASE_TIMEOUT;
                break;
            }

            case NANDC_OPERATION_RESET:
            {
                args.event = NAND_FLASH_EVENT_RESET_TIMEOUT;
                break;
            }

            case NANDC_OPERATION_SET_FEATURE:
            {
                args.event = NAND_FLASH_EVENT_SET_FEATURE_TIMEOUT;
                break;
            }

            case NANDC_OPERATION_COPYBACK:
            {
                args.event = NAND_FLASH_EVENT_COPYBACK_TIMEOUT;
                break;
            }

            default:
            {
                /* Do nothing. */
                break;
            }
        }
    }
    /* Handle complete events. */
    else
    {
        switch (thread_last_operation[thread])
        {
            case NANDC_OPERATION_PAGE_READ:
            {
                args.event = NAND_FLASH_EVENT_READ_COMPLETE;
                break;
            }

            case NANDC_OPERATION_PAGE_PROGRAM:
            {
                args.event = NAND_FLASH_EVENT_WRITE_COMPLETE;
                break;
            }

            case NANDC_OPERATION_BLOCK_ERASE:
            {
                args.event = NAND_FLASH_EVENT_ERASE_COMPLETE;
                break;
            }

            case NANDC_OPERATION_RESET:
            {
                args.event = NAND_FLASH_EVENT_RESET_COMPLETE;
                break;
            }

            case NANDC_OPERATION_SET_FEATURE:
            {
                args.event = NAND_FLASH_EVENT_SET_FEATURE_COMPLETE;
                break;
            }

            case NANDC_OPERATION_COPYBACK:
            {
                args.event = NAND_FLASH_EVENT_COPYBACK_COMPLETE;
                break;
            }

            default:
            {
                /* Do nothing. */
                break;
            }
        }
    }

    if (NULL != p_instance_ctrl->p_callback)
    {
        r_nandc_call_callback(p_instance_ctrl, &args);
    }

    /* Reset interrupt status flags. */
    if (0 != (thread_error_status & thread_mask))
    {
        p_instance_ctrl->p_reg->TRDERRINTSTAT = thread_mask;

        /* Dummy read to ensure that interrupt event is cleared. */
        FSP_REGISTER_READ(p_instance_ctrl->p_reg->TRDERRINTSTAT);
    }
    else if (0 != (thread_timeout_status & thread_mask))
    {
        p_instance_ctrl->p_reg->TRDTMOINTSTAT = thread_mask;

        /* Dummy read to ensure that interrupt event is cleared. */
        FSP_REGISTER_READ(p_instance_ctrl->p_reg->TRDTMOINTSTAT);
    }
    else
    {
        /* Do nothing. */
    }

    p_instance_ctrl->p_reg->TRDCOMPINTSTAT = thread_mask;

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_instance_ctrl->p_reg->TRDCOMPINTSTAT);

    /* Restore raw access configuration */
    if (1 == raw_config_flag)
    {
        FSP_HARDWARE_REGISTER_WAIT(p_instance_ctrl->p_reg->CTRLSTAT_b.CTRLBUSY, 0);
        r_nandc_raw_access_config_recovery(p_instance_ctrl);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    NANDC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
