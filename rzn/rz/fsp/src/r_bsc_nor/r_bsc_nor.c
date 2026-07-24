/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "bsp_api.h"

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_bsc_nor.h"
#include "r_bsc_nor_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "BNOR" in ASCII, used to determine if channel is open. */
#define BSC_NOR_PRV_OPEN                                           (0x424E4F52)

#define BSC_NOR_CHANNEL_DUMMY                                      (0x0U)

/* Address definition for CS space  */
#define BSC_NOR_PRV_NUM_CS                                         (6U)

#define BSC_NOR_PRV_WORD_SIZE                                      (2U)

#define BSC_NOR_VALID_CS_CHANNELS                                  (0x2D) /* Valid channel : CS0,2,3,5 */
#define BSC_NOR_R_W_SAME_ACCESS_WAIT_CHANNELS                      (0x0D) /* Valid channel : CS0,2,3 */
#define BSC_NOR_CS_TIMING_CONFIGURE_ENABLE_CHANNELS                (0x21) /* Valid channel : CS0,5 */

/* BSC CSNBCR register bit masks */
#define BSC_NOR_PRV_CSNBCR_BSZ_VALUE_MASK                          (0x03U)
#define BSC_NOR_PRV_CSNBCR_IWRRS_VALUE_MASK                        (0x07U)
#define BSC_NOR_PRV_CSNBCR_IWRRD_VALUE_MASK                        (0x07U)
#define BSC_NOR_PRV_CSNBCR_IWRWS_VALUE_MASK                        (0x07U)
#define BSC_NOR_PRV_CSNBCR_IWRWD_VALUE_MASK                        (0x07U)
#define BSC_NOR_PRV_CSNBCR_IWW_VALUE_MASK                          (0x07U)

#define BSC_NOR_PRV_CSNBCR_TYPE_NORMAL_SPACE                       (0x00U)
#define BSC_NOR_PRV_CSNBCR_RESERVED_Pos                            (11U)

/* BSC CSNWCR register bit masks */
#define BSC_NOR_PRV_CSNWCR_HW_VALUE_MASK                           (0x03U)
#define BSC_NOR_PRV_CSNWCR_SW_VALUE_MASK                           (0x03U)
#define BSC_NOR_PRV_CSNWCR_WM_VALUE_MASK                           (0x01U)
#define BSC_NOR_PRV_CSNWCR_WR_VALUE_MASK                           (0x0FU)

#define BSC_NOR_PRV_CSNWCR_WW_VALUE_MASK                           (0x07U)
#define BSC_NOR_PRV_CSNWCR_MPXWSBAS_VALUE_MASK                     (0x01U)
#define BSC_NOR_PRV_CSNWCR_SZSEL_VALUE_MASK                        (0x01U)

/* CFI Query Start/End/Verification Sequence */
#define BSC_NOR_COMMAND_CFI_ID_STRING_LENGTH                       (3U)
#define BSC_NOR_COMMAND_CFI_ENTER_1ST_ADDRESS                      (0x55U)
#define BSC_NOR_COMMAND_CFI_ENTER_1ST_DATA                         (0x98U)
#define BSC_NOR_COMMAND_CFI_ID_STRING_1ST_ADDRESS                  (0x10U) /* Q */
#define BSC_NOR_COMMAND_CFI_ID_STRING_2ND_ADDRESS                  (0x11U) /* R */
#define BSC_NOR_COMMAND_CFI_ID_STRING_3RD_ADDRESS                  (0x12U) /* Y */
#define BSC_NOR_COMMAND_CFI_EXIT_1ST_ADDRESS                       (0x00U)
#define BSC_NOR_COMMAND_CFI_EXIT_1ST_DATA                          (0xF0U)

/* CFI Query Device Geometry Definition Sequence */
#define BSC_NOR_CFI_DEV_GEO_NUM_ERASE_BLOCK_ADDRESS                (0x2CU)
#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_1ST_ADDRESS           (0x2DU)
#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_2ND_ADDRESS           (0x2EU)
#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_3RD_ADDRESS           (0x2FU)
#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_4TH_ADDRESS           (0x30U)
#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_NEXT_ADDRESS_DELTA    (0x04U)

#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_ZERO                  (128U)
#define BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_PER_SIZE              (256U)

/* Sector/Chip Erase Sequence */
#define BSC_NOR_ERASE_1ST_ADDRESS                                  (0x555U)
#define BSC_NOR_ERASE_1ST_DATA                                     (0xAAU)
#define BSC_NOR_ERASE_2ND_ADDRESS                                  (0x2AAU)
#define BSC_NOR_ERASE_2ND_DATA                                     (0x55U)
#define BSC_NOR_ERASE_3RD_ADDRESS                                  (0x555U)
#define BSC_NOR_ERASE_3RD_DATA                                     (0x80U)
#define BSC_NOR_ERASE_4TH_ADDRESS                                  (0x555U)
#define BSC_NOR_ERASE_4TH_DATA                                     (0xAAU)
#define BSC_NOR_ERASE_5TH_ADDRESS                                  (0x2AAU)
#define BSC_NOR_ERASE_5TH_DATA                                     (0x55U)
#define BSC_NOR_SECTOR_ERASE_6TH_DATA                              (0x30U)
#define BSC_NOR_CHIP_ERASE_6TH_ADDRESS                             (0x555U)
#define BSC_NOR_CHIP_ERASE_6TH_DATA                                (0x10U)

/* Word Program Sequence */
#define BSC_NOR_WORD_PROGRAM_1ST_ADDRESS                           (0x555U)
#define BSC_NOR_WORD_PROGRAM_1ST_DATA                              (0xAAU)
#define BSC_NOR_WORD_PROGRAM_2ND_ADDRESS                           (0x2AAU)
#define BSC_NOR_WORD_PROGRAM_2ND_DATA                              (0x55U)
#define BSC_NOR_WORD_PROGRAM_3RD_ADDRESS                           (0x555U)
#define BSC_NOR_WORD_PROGRAM_3RD_DATA                              (0xA0U)

/* Write to Buffer Sequence */
#define BSC_NOR_WRITE_BUFFER_1ST_ADDRESS                           (0x555U)
#define BSC_NOR_WRITE_BUFFER_1ST_DATA                              (0xAAU)
#define BSC_NOR_WRITE_BUFFER_2ND_ADDRESS                           (0x2AAU)
#define BSC_NOR_WRITE_BUFFER_2ND_DATA                              (0x55U)
#define BSC_NOR_WRITE_BUFFER_3RD_DATA                              (0x25U)

/* Program Buffer To Flash (confirm) Sequence */
#define BSC_NOR_PROGRAM_BUFFER_TO_FLASH_DATA                       (0x29U)

/* Bit definition for NOR Flash status get */
#define BSC_NOR_STATUS_Q6_TOGGLE_BIT_Pos                           (6U)
#define BSC_NOR_STATUS_Q6_TOGGLE_BIT_Msk                           (1U << BSC_NOR_STATUS_Q6_TOGGLE_BIT_Pos)

/* Each CSn area size */
#define BSC_NOR_CS_AREA_SIZE                                       (BSP_FEATURE_BSC_NOR_CS3_BASE_ADDRESS - \
                                                                    BSP_FEATURE_BSC_NOR_CS2_BASE_ADDRESS)

/* Number of flash memory block information store sizes of CFI query result.
 * BSC_NOR HAL driver support up to 8 block information. */
#define BSC_NOR_CFI_BLOCK_MEMORY_STORE_SIZE                        (8)

/* Select flash erase size  */
typedef enum e_bsc_nor_flash_erase_size
{
    BSC_NOR_FLASH_ERASE_SIZE_SECTOR = 0,
    BSC_NOR_FLASH_ERASE_SIZE_CHIP   = 1,
    BSC_NOR_FLASH_ERASE_SIZE_ERROR  = 0xFF,
} bsc_nor_flash_erase_size_t;

/* Store target block information */
typedef struct st_bsc_nor_target_block_info
{
    uint8_t * p_block_start_address;   /* Start address of the block. */
    uint32_t  block_position;          /* Nth block from the bottom in the device. */
} bsc_nor_target_block_info_t;

/* Store target sector information */
typedef struct st_bsc_nor_target_sector_info
{
    uint8_t * p_sector_start_address;  /* Start address of the sector. */
    uint32_t  sector_position;         /* Nth sector from the bottom in the block. */
} bsc_nor_target_sector_info_t;

static bool      r_bsc_nor_status_sub(uint8_t * const p_device_address);
static fsp_err_t r_bsc_nor_cfi_query_sector_block_info(bsc_nor_instance_ctrl_t * p_instance_ctrl);

static fsp_err_t r_bsc_nor_get_geometry_block_number(bsc_nor_instance_ctrl_t     * p_instance_ctrl,
                                                     uint8_t * const               p_address,
                                                     bsc_nor_target_block_info_t * p_write_target_block);
static fsp_err_t r_bsc_nor_get_sector_number_in_block(bsc_nor_instance_ctrl_t           * p_instance_ctrl,
                                                      uint8_t * const                     p_address,
                                                      bsc_nor_target_block_info_t * const p_write_target_block,
                                                      bsc_nor_target_sector_info_t      * p_write_target_sector);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
#if 1 == BSP_FEATURE_BSC_HAS_CS_MIRROR_AREA

static uint8_t volatile * const gp_bsc_nor_cs_base_mirror_address[BSC_NOR_PRV_NUM_CS] =
{
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS0_BASE_MIRROR_ADDRESS,
    0,
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS2_BASE_MIRROR_ADDRESS,
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS3_BASE_MIRROR_ADDRESS,
    0,
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS5_BASE_MIRROR_ADDRESS
};
#endif

static uint8_t volatile * const gp_bsc_nor_cs_base_address[BSC_NOR_PRV_NUM_CS] =
{
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS0_BASE_ADDRESS,
    0,
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS2_BASE_ADDRESS,
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS3_BASE_ADDRESS,
    0,
    (uint8_t *) BSP_FEATURE_BSC_NOR_CS5_BASE_ADDRESS
};

static bsc_nor_block_info_t block_info[BSC_NOR_CFI_BLOCK_MEMORY_STORE_SIZE];

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSC_NOR
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/
const nor_flash_api_t g_nor_flash_on_bsc_nor =
{
    .open      = R_BSC_NOR_Open,
    .write     = R_BSC_NOR_Write,
    .erase     = R_BSC_NOR_Erase,
    .statusGet = R_BSC_NOR_StatusGet,
    .close     = R_BSC_NOR_Close,
};

/*******************************************************************************************************************//**
 * Open the BSC_NOR driver module. After the driver is open, the BSC can be accessed like internal flash memory starting
 * at address 0x70000000 or 0x50000000.
 *
 * Implements @ref nor_flash_api_t::open.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       The parameter p_instance_ctrl or p_cfg is NULL.
 *                                 Connected Flash memory device does not support CFI query,
 *                                 or insufficient memory area for storing CFI query.
 * @retval FSP_ERR_IP_CHANNEL_NOT_PRESENT Invalid Channel.
 * @retval FSP_ERR_ALREADY_OPEN    Driver has already been opened with the same p_instance_ctrl.
 **********************************************************************************************************************/
fsp_err_t R_BSC_NOR_Open (nor_flash_ctrl_t * p_ctrl, nor_flash_cfg_t const * const p_cfg)
{
    bsc_nor_instance_ctrl_t * p_instance_ctrl = (bsc_nor_instance_ctrl_t *) p_ctrl;

#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);
    FSP_ERROR_RETURN(BSC_NOR_VALID_CS_CHANNELS & (1U << p_cfg->chip_select), FSP_ERR_IP_CHANNEL_NOT_PRESENT);
    FSP_ERROR_RETURN(BSC_NOR_PRV_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);

    /* The number of wait insertions for read and write access cannot be set individually.
     * This depends on the CS number. */
    if (BSC_NOR_R_W_SAME_ACCESS_WAIT_CHANNELS & (1U << p_cfg->chip_select))
    {
        FSP_ASSERT(BSC_NOR_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS ==
                   ((bsc_nor_extended_cfg_t *) p_cfg->p_extend)->write_access_wait_cycle);
    }

    /* If wait insertion can be set individually for read and write,
     * the number of wait insertion for write access should be less than 6 wait or the same as read access waits. */
    if (!(BSC_NOR_R_W_SAME_ACCESS_WAIT_CHANNELS & (1U << p_cfg->chip_select)))
    {
        FSP_ASSERT((((bsc_nor_extended_cfg_t *) p_cfg->p_extend)->write_access_wait_cycle <= BSC_NOR_ACCESS_WAIT_CYCLE_6) ||
                   ((bsc_nor_extended_cfg_t *) p_cfg->p_extend)->write_access_wait_cycle ==
                   BSC_NOR_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS);
    }
#endif

    bsc_nor_extended_cfg_t * p_cfg_extend = (bsc_nor_extended_cfg_t *) p_cfg->p_extend;

    /* Enable clock to the BSC block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_BSC, BSC_NOR_CHANNEL_DUMMY);
    R_BSP_MODULE_START(FSP_IP_CKIO, BSC_NOR_CHANNEL_DUMMY);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Save configurations. */
    p_instance_ctrl->p_cfg = p_cfg;

    /* Set using CS base address during initial settings.  */
    uint32_t chip_select = (uint32_t) p_instance_ctrl->p_cfg->chip_select;
#if 0 == BSP_FEATURE_BSC_HAS_CS_MIRROR_AREA
    p_instance_ctrl->p_cs_base = (void *) gp_bsc_nor_cs_base_address[chip_select];
#else
    p_instance_ctrl->p_cs_base = (BSC_NOR_MEMORY_SPACE_CS == p_cfg_extend->initial_access_memory_space) ?
                                 (void *) gp_bsc_nor_cs_base_address[chip_select] :
                                 (void *) gp_bsc_nor_cs_base_mirror_address[chip_select];
#endif

    /* Calculate the CSnWCR register base address. */
    uint32_t   address_gap = (uint32_t) ((uintptr_t) &R_BSC->CS3WCR_0 - (uintptr_t) &R_BSC->CS2WCR_0);
    uint32_t * p_csnwcr    = (uint32_t *) ((uintptr_t) &R_BSC->CS0WCR_0 + (address_gap * p_cfg->chip_select));

    /* Set bus access idle cycle. */
    uint32_t csnbcr = (((p_cfg->data_width & BSC_NOR_PRV_CSNBCR_BSZ_VALUE_MASK) <<
                        R_BSC_CSnBCR_BSZ_Pos) |
                       1U << BSC_NOR_PRV_CSNBCR_RESERVED_Pos |
                       (BSC_NOR_PRV_CSNBCR_TYPE_NORMAL_SPACE << R_BSC_CSnBCR_TYPE_Pos) |
                       ((p_cfg_extend->r_r_same_space_idle_cycle & BSC_NOR_PRV_CSNBCR_IWRRS_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRRS_Pos) |
                       ((p_cfg_extend->r_r_different_space_idle_cycle & BSC_NOR_PRV_CSNBCR_IWRRD_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRRD_Pos) |
                       ((p_cfg_extend->r_w_same_space_idle_cycle & BSC_NOR_PRV_CSNBCR_IWRWS_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRWS_Pos) |
                       ((p_cfg_extend->r_w_different_space_idle_cycle & BSC_NOR_PRV_CSNBCR_IWRWD_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWRWD_Pos) |
                       ((p_cfg_extend->w_r_w_w_idle_cycle & BSC_NOR_PRV_CSNBCR_IWW_VALUE_MASK) <<
                        R_BSC_CSnBCR_IWW_Pos));

    /* Set access wait cycle.
     * If the channel can be set read/write individually, set read access wait cycle here. */
    uint32_t csnwcr = (p_cfg_extend->read_access_wait_cycle & BSC_NOR_PRV_CSNWCR_WR_VALUE_MASK) <<
                      R_BSC_CS0WCR_0_WR_Pos;

    /* Set write access wait cycle if it can be set individually. */
    if (!((BSC_NOR_R_W_SAME_ACCESS_WAIT_CHANNELS) & (1U << p_cfg->chip_select)))
    {
        if (BSC_NOR_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS != p_cfg_extend->write_access_wait_cycle)
        {
            csnwcr |=
                (uint32_t) ((p_cfg_extend->write_access_wait_cycle & BSC_NOR_PRV_CSNWCR_WW_VALUE_MASK) + 1) <<
                    R_BSC_CS5WCR_WW_Pos;
        }
        else
        {
            /* Set 0 if set write access wait cycle to be the same as the read access wait cycle. */
            csnwcr &= ~(uint32_t) R_BSC_CS5WCR_WW_Msk;
        }
    }

    /* Set CS timing. */
    if (BSC_NOR_CS_TIMING_CONFIGURE_ENABLE_CHANNELS & (1U << p_cfg->chip_select))
    {
        csnwcr |= (((p_cfg_extend->cs_pullup_lag & BSC_NOR_PRV_CSNWCR_HW_VALUE_MASK) << R_BSC_CS0WCR_0_HW_Pos) |
                   ((p_cfg_extend->cs_pulldown_lead & BSC_NOR_PRV_CSNWCR_SW_VALUE_MASK) << R_BSC_CS0WCR_0_SW_Pos));
    }

    /* Set external wait setting. */
    csnwcr |= (1U & BSC_NOR_PRV_CSNWCR_WM_VALUE_MASK) << R_BSC_CS0WCR_0_WM_Pos;

    R_BSC->CSnBCR[p_cfg->chip_select] = csnbcr;
    *p_csnwcr = csnwcr;

    /* Query NOR Flash memory sector layout using CFI (Common Flash Interface). */
    p_instance_ctrl->p_block_info = &block_info[0];
    fsp_err_t ret = r_bsc_nor_cfi_query_sector_block_info(p_instance_ctrl);

    if (FSP_SUCCESS == ret)
    {
        p_instance_ctrl->open = BSC_NOR_PRV_OPEN;
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Program data to the flash.
 *
 * Implements @ref nor_flash_api_t::write.
 *
 * @retval FSP_SUCCESS                 The flash was programmed successfully.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl, p_dest or p_src is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         Another Write/Erase transaction is in progress.
 * @retval FSP_ERR_INVALID_ARGUMENT    p_dest is invalid for connected device.
 *
 * @note The size that can be written to the buffer at one time depends on the device.
 *       Please refer to the data sheet of the connected device for details.
 **********************************************************************************************************************/
fsp_err_t R_BSC_NOR_Write (nor_flash_ctrl_t    * p_ctrl,
                           uint8_t const * const p_src,
                           uint8_t * const       p_dest,
                           uint32_t              byte_count)
{
    bsc_nor_instance_ctrl_t * p_instance_ctrl = (bsc_nor_instance_ctrl_t *) p_ctrl;
#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_src);
    FSP_ASSERT(NULL != p_dest);
    FSP_ERROR_RETURN(BSC_NOR_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(0 != byte_count);
#endif

    /* To issue Write Program sequence,
     * the base address of CSn must be obtained from the destination address (p_dest).
     *
     * Example is as below on some devices :
     *   - p_dest : 0x50020000 (write via CSn mirror address) -> CSn base address : 0x50000000.
     *   - p_dest : 0x70020000 (write via CSn address) -> CSn base is 0x70000000.
     */
    uint16_t * p_cs_base = (uint16_t *) ((uintptr_t) p_dest & (~((uintptr_t) BSC_NOR_CS_AREA_SIZE - 1U)));

    if (BSC_NOR_PRV_WORD_SIZE == byte_count)
    {
        FSP_ERROR_RETURN(false == r_bsc_nor_status_sub(p_dest), FSP_ERR_DEVICE_BUSY);

        /* Start Write Program Sequence */
        *((volatile uint16_t *) p_cs_base + BSC_NOR_WORD_PROGRAM_1ST_ADDRESS) = BSC_NOR_WORD_PROGRAM_1ST_DATA;
        __DSB();
        *((volatile uint16_t *) p_cs_base + BSC_NOR_WORD_PROGRAM_2ND_ADDRESS) = BSC_NOR_WORD_PROGRAM_2ND_DATA;
        __DSB();
        *((volatile uint16_t *) p_cs_base + BSC_NOR_WORD_PROGRAM_3RD_ADDRESS) = BSC_NOR_WORD_PROGRAM_3RD_DATA;
        __DSB();
        *((volatile uint16_t *) p_dest) = *(uint16_t *) p_src;
        __DSB();
    }
    else
    {
        fsp_err_t err;

        /* To get write sector start address, first get the block information which the write address belongs to. */
        bsc_nor_target_block_info_t write_target_block;
        err = r_bsc_nor_get_geometry_block_number(p_instance_ctrl, p_dest, &write_target_block);
        FSP_ERROR_RETURN(err == FSP_SUCCESS, err);

        /* Get write sector start address from the block information acquired earlier. */
        bsc_nor_target_sector_info_t write_target_sector;
        err = r_bsc_nor_get_sector_number_in_block(p_instance_ctrl, p_dest, &write_target_block, &write_target_sector);
        FSP_ERROR_RETURN(err == FSP_SUCCESS, err);

        FSP_ERROR_RETURN(false == r_bsc_nor_status_sub(p_dest), FSP_ERR_DEVICE_BUSY);

        uint32_t sect_addr  = (uint32_t) (uintptr_t) write_target_sector.p_sector_start_address;
        uint32_t word_count = byte_count / BSC_NOR_PRV_WORD_SIZE;

        /* Start Write to Buffer Sequence */
        *((volatile uint16_t *) p_cs_base + BSC_NOR_WRITE_BUFFER_1ST_ADDRESS) = BSC_NOR_WRITE_BUFFER_1ST_DATA;
        __DSB();
        *((volatile uint16_t *) p_cs_base + BSC_NOR_WRITE_BUFFER_2ND_ADDRESS) = BSC_NOR_WRITE_BUFFER_2ND_DATA;
        __DSB();
        *((volatile uint16_t *) (uintptr_t) sect_addr) = BSC_NOR_WRITE_BUFFER_3RD_DATA;
        __DSB();
        *((volatile uint16_t *) (uintptr_t) sect_addr) = (uint16_t) (word_count - 1);
        __DSB();
        for (uint32_t i = 0U; i < word_count; i++)
        {
            *((volatile uint16_t *) p_dest + i) = *((uint16_t *) p_src + i);
            __DSB();
        }

        /* Start Program Buffer To Flash Sequence */
        *((volatile uint16_t *) (uintptr_t) sect_addr) = BSC_NOR_PROGRAM_BUFFER_TO_FLASH_DATA;
        __DSB();
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Erase a sector or a chip of flash.
 *
 * Implements @ref nor_flash_api_t::erase.
 *
 * @retval FSP_SUCCESS                 The command to erase the flash was executed successfully.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl or p_device_address is NULL, or byte_count doesn't match
 *                                     the device defined erase size resulting from the CFI query.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 * @retval FSP_ERR_DEVICE_BUSY         The device is busy.
 **********************************************************************************************************************/
fsp_err_t R_BSC_NOR_Erase (nor_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count)
{
    bsc_nor_instance_ctrl_t * p_instance_ctrl = (bsc_nor_instance_ctrl_t *) p_ctrl;
#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_device_address);
    FSP_ERROR_RETURN(BSC_NOR_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    FSP_ERROR_RETURN(false == r_bsc_nor_status_sub(p_device_address), FSP_ERR_DEVICE_BUSY);

    /* To issue Erase sequence,
     * the base address of CSn must be obtained from the destination address (p_device_address).
     *
     * Example is as below on some devices :
     *   - p_dest : 0x50020000 (erase via CSn mirror address) -> CSn base address : 0x50000000.
     *   - p_dest : 0x70020000 (erase via CSn address) -> CSn base is 0x70000000.
     */
    uint16_t * p_cs_base = (uint16_t *) ((uintptr_t) p_device_address & (~((uintptr_t) BSC_NOR_CS_AREA_SIZE - 1U)));

    bsc_nor_flash_erase_size_t erase_type = BSC_NOR_FLASH_ERASE_SIZE_ERROR;
    if (byte_count == NOR_FLASH_ERASE_SIZE_CHIP_ERASE)
    {
        erase_type = BSC_NOR_FLASH_ERASE_SIZE_CHIP;
    }
    else
    {
        uint32_t block_number = p_instance_ctrl->block_number;

        /* Check whether requested byte_count is supported by underlying flash. */
        for (uint32_t i = 0; i < block_number; i++)
        {
            if (byte_count == p_instance_ctrl->p_block_info[i].sector_size)
            {
                erase_type = BSC_NOR_FLASH_ERASE_SIZE_SECTOR;
            }
        }
    }

#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(BSC_NOR_FLASH_ERASE_SIZE_ERROR != erase_type);
#endif

    /* Start Sector/Chip Erase Sequence */
    *((volatile uint16_t *) p_cs_base + BSC_NOR_ERASE_1ST_ADDRESS) = BSC_NOR_ERASE_1ST_DATA;
    __DSB();
    *((volatile uint16_t *) p_cs_base + BSC_NOR_ERASE_2ND_ADDRESS) = BSC_NOR_ERASE_2ND_DATA;
    __DSB();
    *((volatile uint16_t *) p_cs_base + BSC_NOR_ERASE_3RD_ADDRESS) = BSC_NOR_ERASE_3RD_DATA;
    __DSB();
    *((volatile uint16_t *) p_cs_base + BSC_NOR_ERASE_4TH_ADDRESS) = BSC_NOR_ERASE_4TH_DATA;
    __DSB();
    *((volatile uint16_t *) p_cs_base + BSC_NOR_ERASE_5TH_ADDRESS) = BSC_NOR_ERASE_5TH_DATA;
    __DSB();

    if (BSC_NOR_FLASH_ERASE_SIZE_SECTOR == erase_type)
    {
        /* Do the 6th of Sector Erase Sequence Cycles */
        *((volatile uint16_t *) p_device_address) = BSC_NOR_SECTOR_ERASE_6TH_DATA;
        __DSB();
    }

    if (BSC_NOR_FLASH_ERASE_SIZE_CHIP == erase_type)
    {
        /* Do the 6th of Chip Erase Sequence Cycles */
        *((volatile uint16_t *) p_cs_base + BSC_NOR_CHIP_ERASE_6TH_ADDRESS) = BSC_NOR_CHIP_ERASE_6TH_DATA;
        __DSB();
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Gets the write or erase status of the flash.
 *
 * Implements @ref nor_flash_api_t::statusGet.
 *
 * @retval FSP_SUCCESS                 The write status is in p_status.
 * @retval FSP_ERR_ASSERTION           p_instance_ctrl, p_device_address or p_status is NULL.
 * @retval FSP_ERR_NOT_OPEN            Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_NOR_StatusGet (nor_flash_ctrl_t         * p_ctrl,
                               uint8_t * const            p_device_address,
                               nor_flash_status_t * const p_status)
{
    bsc_nor_instance_ctrl_t * p_instance_ctrl = (bsc_nor_instance_ctrl_t *) p_ctrl;
#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_device_address);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(BSC_NOR_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
#endif

    /* Read device status. */
    p_status->write_in_progress = r_bsc_nor_status_sub(p_device_address);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Close the BSC_NOR driver module.
 *
 * Implements @ref nor_flash_api_t::close.
 *
 * @retval FSP_SUCCESS             Configuration was successful.
 * @retval FSP_ERR_ASSERTION       p_instance_ctrl is NULL.
 * @retval FSP_ERR_NOT_OPEN        Driver is not opened.
 **********************************************************************************************************************/
fsp_err_t R_BSC_NOR_Close (nor_flash_ctrl_t * p_ctrl)
{
    bsc_nor_instance_ctrl_t * p_instance_ctrl = (bsc_nor_instance_ctrl_t *) p_ctrl;
#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(BSC_NOR_PRV_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#endif

    /* Disable clock to the BSC block */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_BSC, BSC_NOR_CHANNEL_DUMMY);
    R_BSP_MODULE_STOP(FSP_IP_CKIO, BSC_NOR_CHANNEL_DUMMY);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_instance_ctrl->open = 0U;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSC_NOR)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/*******************************************************************************************************************//**
 * Gets device status.
 *
 * @param[in]  p_device_address         The location in the flash device address space
 *
 * @return True if busy, false if not.
 **********************************************************************************************************************/
static bool r_bsc_nor_status_sub (uint8_t * const p_device_address)
{
    /* During a Program or Erase operation, read cycles cause 6th bit toggle.
     * When the operation is complete, 6th bit stops toggling. */
    uint16_t read1 = *(volatile uint16_t *) p_device_address;
    __DSB();
    uint16_t read2 = *(volatile uint16_t *) p_device_address;
    __DSB();

    return (bool) (((read1 ^ read2) & BSC_NOR_STATUS_Q6_TOGGLE_BIT_Msk) >> BSC_NOR_STATUS_Q6_TOGGLE_BIT_Pos);
}

/*******************************************************************************************************************//**
 * Query Erase Block Block Information using CFI(Common Flash Interface).
 *
 * @param[in]  p_instance_ctrl         Pointer to a driver handle
 *
 * @retval FSP_SUCCESS                 CFI Query was successful.
 * @retval FSP_ERR_ASSERTION           Connected Flash memory device does not support CFI query,
 *                                     or insufficient memory area for storing CFI query.
 **********************************************************************************************************************/
static fsp_err_t r_bsc_nor_cfi_query_sector_block_info (bsc_nor_instance_ctrl_t * p_instance_ctrl)
{
    uint16_t * p_cs_base = (uint16_t *) p_instance_ctrl->p_cs_base;

    /* CFI Enter Sequence */
    *((volatile uint16_t *) p_cs_base + BSC_NOR_COMMAND_CFI_ENTER_1ST_ADDRESS) = BSC_NOR_COMMAND_CFI_ENTER_1ST_DATA;
    __DSB();

#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE

    /* Check whether using device supports CFI by Identification String. */
    uint8_t cfi_query_unique_string[BSC_NOR_COMMAND_CFI_ID_STRING_LENGTH];
    cfi_query_unique_string[0] =
        (uint8_t) (*((volatile uint16_t *) p_cs_base + BSC_NOR_COMMAND_CFI_ID_STRING_1ST_ADDRESS));
    __DSB();
    cfi_query_unique_string[1] =
        (uint8_t) (*((volatile uint16_t *) p_cs_base + BSC_NOR_COMMAND_CFI_ID_STRING_2ND_ADDRESS));
    __DSB();
    cfi_query_unique_string[2] =
        (uint8_t) (*((volatile uint16_t *) p_cs_base + BSC_NOR_COMMAND_CFI_ID_STRING_3RD_ADDRESS));
    __DSB();

    FSP_ASSERT('Q' == cfi_query_unique_string[0]);
    FSP_ASSERT('R' == cfi_query_unique_string[1]);
    FSP_ASSERT('Y' == cfi_query_unique_string[2]);
#endif

    /* Query Number of erase blocks within device */
    uint16_t block_number = *((volatile uint16_t *) p_cs_base + BSC_NOR_CFI_DEV_GEO_NUM_ERASE_BLOCK_ADDRESS);
    __DSB();

    p_instance_ctrl->block_number = block_number;

#if BSC_NOR_CFG_PARAM_CHECKING_ENABLE

    /* Check if there is enough space to store block information from CFI query. */
    FSP_ASSERT(block_number <= BSC_NOR_CFI_BLOCK_MEMORY_STORE_SIZE);
#endif

    bsc_nor_block_info_t * p_block_info = p_instance_ctrl->p_block_info;

    for (uint16_t i = 0U; i < block_number; i++)
    {
        /* Query Block Block Information. */
        uint16_t block_num_l = *((volatile uint16_t *) p_cs_base +
                                 BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_1ST_ADDRESS + i *
                                 BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_NEXT_ADDRESS_DELTA);
        __DSB();
        uint16_t block_num_h = *((volatile uint16_t *) p_cs_base +
                                 BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_2ND_ADDRESS + i *
                                 BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_NEXT_ADDRESS_DELTA);
        __DSB();
        uint16_t block_size_l = *((volatile uint16_t *) p_cs_base +
                                  BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_3RD_ADDRESS + i *
                                  BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_NEXT_ADDRESS_DELTA);
        __DSB();
        uint16_t block_size_h = *((volatile uint16_t *) p_cs_base +
                                  BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_4TH_ADDRESS + i *
                                  BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_NEXT_ADDRESS_DELTA);
        __DSB();

        /* Number of block in the block = N + 1 (see CFI specification). */
        p_block_info[i].sector_number = (uint32_t) ((block_num_h << 8U) | block_num_l) + 1;

        /* Size of block in the block = N * 256byte
         * The value N = 0 is used for 128byte block (see CFI specification). */
        uint32_t block_region_info = (uint32_t) ((block_size_h << 8U) | block_size_l);
        if (0 == block_region_info)
        {
            p_block_info[i].sector_size = BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_ZERO;
        }
        else
        {
            p_block_info[i].sector_size = block_region_info * BSC_NOR_CFI_DEV_GEO_ERASE_BLOCK_INFO_PER_SIZE;
        }
    }

    /* CFI Exit Sequence */
    *((volatile uint16_t *) p_cs_base + BSC_NOR_COMMAND_CFI_EXIT_1ST_ADDRESS) = BSC_NOR_COMMAND_CFI_EXIT_1ST_DATA;
    __DSB();

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the block information which the address belongs to from the result of the CFI query.
 *
 * @param[in] p_instance_ctrl           Pointer to a driver handle
 * @param[in] p_address                 Search address
 * @param[out] p_write_target_block     Block information which the address belongs to if successful.
 *
 * @retval FSP_SUCCESS                  Block search was successful.
 * @retval FSP_ERR_INVALID_ARGUMENT     Target block was not in the device.
 **********************************************************************************************************************/
static fsp_err_t r_bsc_nor_get_geometry_block_number (bsc_nor_instance_ctrl_t     * p_instance_ctrl,
                                                      uint8_t * const               p_address,
                                                      bsc_nor_target_block_info_t * p_write_target_block)
{
    fsp_err_t err = FSP_ERR_INVALID_ARGUMENT;

    /* The initial value of the block start address is the start address of the CS space.
     * The start address of CSn must be obtained from p_address.
     *
     * Example is as below  on some devices :
     *   - p_dest : 0x50020000 (erase via CSn mirror address) -> CSn base address : 0x50000000.
     *   - p_dest : 0x70020000 (erase via CSn address) -> CSn base is 0x70000000.
     */
    uintptr_t block_start_addr = (uintptr_t) p_address & (~((uintptr_t) BSC_NOR_CS_AREA_SIZE - 1U));

    /* Loop through each block. */
    uint32_t block_number = p_instance_ctrl->block_number;

    uint32_t previous_block_size = 0;
    for (uint32_t i = 0; i < block_number + 1; i++)
    {
        /* If the block start address is exceeded, it is the block which the previous block belongs to.
         *
         *     For example, Consider which block the address 0x05040020 belongs to.
         *     Suppose the memory map of the device is as follows.
         *          Block 0 :
         *             Start address = 0x50000000, each sector size = 16Kbyte = 0x00004000, sector num = 1
         *
         *          Block 1 :
         *             Start address = 0x50004000, each sector size = 8Kbyte  = 0x00002000, sector num = 2
         *
         *          Block 2 :
         *             Start address = 0x50008000, each sector size = 32Kbyte = 0x00008000, sector num = 1
         *
         *          Block 3 :
         *             Start address = 0x50010000, each sector size = 64Kbyte = 0x00010000, sector num = 31
         *
         *     Block 0 start address : 0x50000000 < 0x50040020
         *     Block 1 start address : 0x50004000 < 0x50040020
         *     Block 2 start address : 0x50008000 > 0x50040020
         *
         *        <- Block 2 start address exceeds 0x50040020,
         *           therefore 0x50040020 address belongs to the Block 1 immediately before Block 2.
         *           so p_block_start_address = 0x50040000, block_position = 1.
         */
        if ((uintptr_t) p_address < block_start_addr)
        {
            p_write_target_block->p_block_start_address =
                (uint8_t *) (uintptr_t) (block_start_addr - previous_block_size);
            p_write_target_block->block_position = i - 1;
            err = FSP_SUCCESS;
            break;
        }

        bsc_nor_block_info_t block      = p_instance_ctrl->p_block_info[i];
        uint32_t             block_size = block.sector_number * block.sector_size;

        /* Set next sector start address. */
        block_start_addr += block_size;

        /* Memory the size of the previous block. */
        previous_block_size = block_size;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Get the sector information which the address belongs to from the specified block.
 *
 * @param[in] p_instance_ctrl           Pointer to a driver handle
 * @param[in] p_address                 Search address
 * @param[in] p_write_target_block      Block information which the address belongs to.
 * @param[out] p_write_target_sector    Sector information which the address belongs to if successful.
 *
 * @retval FSP_SUCCESS                  Sector search was successful.
 * @retval FSP_ERR_INVALID_ARGUMENT     Target sector was not in specified block.
 **********************************************************************************************************************/
static fsp_err_t r_bsc_nor_get_sector_number_in_block (bsc_nor_instance_ctrl_t           * p_instance_ctrl,
                                                       uint8_t * const                     p_address,
                                                       bsc_nor_target_block_info_t * const p_write_target_block,
                                                       bsc_nor_target_sector_info_t      * p_write_target_sector)
{
    fsp_err_t err = FSP_ERR_INVALID_ARGUMENT;

    /* Get block number to search for sector number/start address. */
    uint32_t             position = p_write_target_block->block_position;
    bsc_nor_block_info_t block    = p_instance_ctrl->p_block_info[position];

    /* The initial value of the sector start address is the start address of the block to which the sector belongs. */
    uintptr_t sector_start_address = (uintptr_t) p_write_target_block->p_block_start_address;

    /* Loop through each sector in the block. */
    for (uint32_t i = 0; i < block.sector_number + 1; i++)
    {
        /* If the sector start address is exceeded, it is the sector which the previous sector belongs to.
         *
         *     For example, Consider which sector the address 0x05040020 belongs to.
         *     For the device memory map, assume that the sector size is uniform as 128 Kbyte. (128Kbyte = 0x00020000)
         *     when Sector 0 start address = 0x50000000,
         *
         *     Sector 0 start address : 0x50000000 < 0x50040020
         *     Sector 1 start address : 0x50020000 < 0x50040020
         *     Sector 2 start address : 0x50040000 < 0x50040020
         *     Sector 3 start address : 0x50060000 > 0x50040020
         *
         *        <- Sector 3 start address exceeds 0x50040020,
         *           therefore 0x50040020 address belongs to the Sector 2 immediately before Sector 3.
         *           so p_sector_start_address = 0x50040000, sector_position = 2.
         */
        if ((uintptr_t) p_address < sector_start_address)
        {
            /* The previous sector is the sector it belongs to. */
            p_write_target_sector->p_sector_start_address =
                (uint8_t *) (uintptr_t) (sector_start_address - block.sector_size);
            p_write_target_sector->sector_position = i - 1;
            err = FSP_SUCCESS;
            break;
        }

        /* Set next sector start address. */
        sector_start_address += block.sector_size;
    }

    return err;
}
