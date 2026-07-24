/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

#if (1 == BSP_CFG_ESD_BOOT) || (1 == BSP_CFG_EMMC_BOOT)

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define BSP_PRV_SDHI_SECTOR_SIZE    (512)

/* In this project, the SDHI memory device flash contents is virtually located in unused memory address.
 * See the linker file for more details. */
 #if defined(__ICCARM__)

/* In this project, the MBR parameters are placed at the beginning of the SDHI Flash device,
 * so the start address of the Flash contents is the start address of .mbr_param. */
  #pragma section=".mbr_param"
  #define BSP_PRV_FLASH_CONTENTS_START_SECTION            ".mbr_param"
  #define BSP_PRV_FLASH_CONTENTS_START_VIRTUAL_ADDRESS    __section_begin(BSP_PRV_FLASH_CONTENTS_START_SECTION)

 #elif defined(__GNUC__)
extern void * __sdhi_flash_contents_virtual_address;
  #define BSP_PRV_FLASH_CONTENTS_START_VIRTUAL_ADDRESS    &__sdhi_flash_contents_virtual_address
 #endif

 #define BSP_PRV_CONVERT_SDHI_FLASH_CONTENTS_ADDRESS(x)    ((uintptr_t) (x) - \
                                                            (uintptr_t) BSP_PRV_FLASH_CONTENTS_START_VIRTUAL_ADDRESS)

 #if (1 == BSP_CFG_EMMC_BOOT)

  #define BSP_PRV_SD_CLK_CTRL_DEFAULT                      (0x20U)

  #define BSP_PRV_SD_OPTION_DEFAULT                        (0x40E0U)
  #define BSP_PRV_BUS_WIDTH_1_BIT                          (4U)
  #define BSP_PRV_BUS_WIDTH_8_BIT                          (1U)
  #define BSP_PRV_SD_OPTION_WIDTH8_BIT                     (13)
  #define BSP_PRV_CMD_GO_IDLE_STATE                        (0U)

/* 400 kHz maximum clock required for initialization. */
  #define BSP_PRV_INIT_MAX_CLOCK_RATE_HZ                   (400000U)
  #define BSP_PRV_BITS_PER_COMMAND                         (48U)
  #define BSP_PRV_BITS_PER_RESPONSE                        (48U)
  #define BSP_PRV_CLOCKS_BETWEEN_COMMANDS                  (8U)
  #define BSP_PRV_MIN_CYCLES_PER_COMMAND_RESPONSE          ((BSP_PRV_BITS_PER_COMMAND +   \
                                                             BSP_PRV_BITS_PER_RESPONSE) + \
                                                            BSP_PRV_CLOCKS_BETWEEN_COMMANDS)
  #define BSP_PRV_INIT_ONE_SECOND_TIMEOUT_ITERATIONS       (BSP_PRV_INIT_MAX_CLOCK_RATE_HZ / \
                                                            BSP_PRV_MIN_CYCLES_PER_COMMAND_RESPONSE)

  #define BSP_PRV_CMD_ALL_SEND_CID                         (2U)

  #define BSP_PRV_CLK_CTRL_DIV_INVALID                     (0xFFU)

/* The relationship of the SD Clock Control Register SD_CLK_CTRL CLKSEL to the division of the source PCLK
 * b7            b0
 * 1 1 1 1 1 1 1 1: PCLK
 * 0 0 0 0 0 0 0 0: PCLK/2
 * 0 0 0 0 0 0 0 1: PCLK/4
 * 0 0 0 0 0 0 1 0: PCLK/8
 * 0 0 0 0 0 1 0 0: PCLK/16
 * 0 0 0 0 1 0 0 0: PCLK/32
 * 0 0 0 1 0 0 0 0: PCLK/64
 * 0 0 1 0 0 0 0 0: PCLK/128
 * 0 1 0 0 0 0 0 0: PCLK/256
 * 1 0 0 0 0 0 0 0: PCLK/512.
 * Other settings are prohibited.
 */
  #define BSP_PRV_MAX_CLOCK_DIVISION_SHIFT                 (9U) /* 512 (2^9) is max clock division supported */

  #define BSP_PRV_SCLKDIVEN_TIMEOUT                        (8U * 512U)

  #define BSP_PRV_BSP_PRV_SD_CLK_CTRL_CLKCTRLEN_MASK       (1U << 9)
  #define BSP_PRV_BSP_PRV_SD_CLK_CTRL_CLKEN_MASK           (1U << 8)

  #define BSP_PRV_BSP_PRV_SD_CLK_AUTO_CLOCK_ENABLE_MASK    (0x300U)

  #define BSP_PRV_OCR_CAPACITY_HC                          (1U << 30)

  #define BSP_PRV_CMD_SEL_DES_CARD                         (7U)
  #define BSP_PRV_CMD_SET_BLOCKLEN                         (16U)

  #define BSP_PRV_CMD_SEND_CSD                             (9U)

  #define BSP_PRV_SD_DEFAULT_CLOCK_RATE                    (25000000U) /* 25 MHz */
  #define BSP_PRV_EMMC_DEFAULT_CLOCK_RATE                  (26000000U) /* 26 MHz */
  #define BSP_PRV_EMMC_HIGH_SPEED_CLOCK_RATE               (52000000U) /* 52 MHz */
  #define BSP_PRV_EMMC_HIGH_SPEED_52_MHZ_BIT               (2U)
  #define BSP_PRV_EMMC_SWITCH_ACCESS_WRITE_BYTE            (3U)
  #define BSP_PRV_EMMC_EXT_CSD_HS_TIMING_OFFSET            (185U)
  #define BSP_PRV_EMMC_HIGH_SPEED_MODE                     (((BSP_PRV_EMMC_SWITCH_ACCESS_WRITE_BYTE << 24U) |  \
                                                             (BSP_PRV_EMMC_EXT_CSD_HS_TIMING_OFFSET << 16U)) | \
                                                            (BSP_PRV_EMMC_HIGH_SPEED_52_MHZ_BIT << 8U))
  #define BSP_PRV_EMMC_CMD_SWITCH_WBUSY                    (0x506U)  /* eMMC CMD6 switch command "with response busy" */

  #define BSP_PRV_EMMC_CMD_SEND_EXT_CSD                    (0x1C08U) /* CMD 8, read data */
  #define BSP_PRV_EMMC_EXT_CSD_SIZE                        (512U)
  #define BSP_PRV_EMMC_EXT_CSD_DEVICE_TYPE_OFFSET          (196U)
  #define BSP_PRV_EMMC_EXT_CSD_SEC_COUNT_OFFSET            (212U)

  #define BSP_PRV_SWITCH_ACCESS_SHIFT                      (24U)
  #define BSP_PRV_SWITCH_INDEX_SHIFT                       (16U)
  #define BSP_PRV_SWITCH_VALUE_SHIFT                       (8U)
  #define BSP_PRV_EMMC_BUS_WIDTH_INDEX                     (183U)

  #define BSP_PRV_BUSY_TIMEOUT_US                          (5000000U)

  #define BSP_PRV_SD_INFO2_CBSY_DAT0_IDLE_VAL              (0x80)

  #define BSP_PRV_SD_INFO2_CBSY_DAT0_IDLE_MASK             (0x4080)

  #define BSP_PRV_OCR_VDD_2_7_V                            (1U << 15)
  #define BSP_PRV_OCR_VDD_2_8_V                            (1U << 16)
  #define BSP_PRV_OCR_VDD_2_9_V                            (1U << 17)
  #define BSP_PRV_OCR_VDD_3_0_V                            (1U << 18)
  #define BSP_PRV_OCR_VDD_3_1_V                            (1U << 19)
  #define BSP_PRV_OCR_VDD_3_2_V                            (1U << 20)
  #define BSP_PRV_OCR_VDD_3_3_V                            (1U << 21)
  #define BSP_PRV_OCR_VDD_3_4_V                            (1U << 22)
  #define BSP_PRV_OCR_VDD_3_5_V                            (1U << 23)
  #define BSP_PRV_OCR_VDD_SUPPORTED                                                                  \
    (BSP_PRV_OCR_VDD_2_7_V | BSP_PRV_OCR_VDD_2_8_V | BSP_PRV_OCR_VDD_2_9_V | BSP_PRV_OCR_VDD_3_0_V | \
     BSP_PRV_OCR_VDD_3_1_V |                                                                         \
     BSP_PRV_OCR_VDD_3_2_V | BSP_PRV_OCR_VDD_3_3_V | BSP_PRV_OCR_VDD_3_4_V | BSP_PRV_OCR_VDD_3_5_V)

  #define BSP_PRV_EMMC_SEND_OP_COND                        (0x701U)

  #define BSP_PRV_CMD_SEND_RELATIVE_ADDR                   (3U)

  #define BSP_PRV_SD_STOP_SD_SECCNT_ENABLE                 (0x100U)

  #define BSP_PRV_SDHI_INFO1_RESPONSE_END                  (1U << 0) // Response End
  #define BSP_PRV_SDHI_INFO1_ACCESS_END                    (1U << 2) // Access End

  #define BSP_PRV_SDHI_INFO1_ACCESS_MASK                   ((BSP_PRV_SDHI_INFO1_RESPONSE_END | \
                                                             BSP_PRV_SDHI_INFO1_ACCESS_END))

  #define BSP_PRV_SDHI_INFO2_CARD_CMD_ERR                  (1U << 0)  // Command error
  #define BSP_PRV_SDHI_INFO2_CARD_CRC_ERR                  (1U << 1)  // CRC error
  #define BSP_PRV_SDHI_INFO2_CARD_END_ERR                  (1U << 2)  // End bit error
  #define BSP_PRV_SDHI_INFO2_CARD_DTO                      (1U << 3)  // Data Timeout
  #define BSP_PRV_SDHI_INFO2_CARD_ILW                      (1U << 4)  // Illegal write address
  #define BSP_PRV_SDHI_INFO2_CARD_ILR                      (1U << 5)  // Illegal read address
  #define BSP_PRV_SDHI_INFO2_CARD_RSPT                     (1U << 6)  // Response timeout
  #define BSP_PRV_SDHI_INFO2_CARD_BRE                      (1U << 8)  // Buffer read enable
  #define BSP_PRV_SDHI_INFO2_CARD_BWE                      (1U << 9)  // Buffer write enable
  #define BSP_PRV_SDHI_INFO2_CARD_ILA_ERR                  (1U << 15) // Illegal access

  #define BSP_PRV_SDHI_INFO2_MASK                                                                           \
    ((BSP_PRV_SDHI_INFO2_CARD_CMD_ERR | BSP_PRV_SDHI_INFO2_CARD_CRC_ERR | BSP_PRV_SDHI_INFO2_CARD_END_ERR | \
      BSP_PRV_SDHI_INFO2_CARD_DTO | BSP_PRV_SDHI_INFO2_CARD_ILW | BSP_PRV_SDHI_INFO2_CARD_ILR |             \
      BSP_PRV_SDHI_INFO2_CARD_RSPT | BSP_PRV_SDHI_INFO2_CARD_BRE | BSP_PRV_SDHI_INFO2_CARD_BWE |            \
      BSP_PRV_SDHI_INFO2_CARD_ILA_ERR))

  #define BSP_PRV_HOST_MODE_WMODE_BIT                      (0U)
  #define BSP_PRV_HOST_MODE_BUSWIDTH_BIT                   (8U)

  #define BSP_PRV_SD_CC_EXT_MODE_DMASDRW_CLEAR             (0x1010U) // Added setting for SDHI built-in DMAC.

  #define BSP_PRV_POWER_UP_STATUS_SHIFT                    (31)
  #define BSP_PRV_POWER_UP_STATUS_MASK                     (1U)
 #endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_sdhi_read_command_issue(uint32_t start_sector, uint32_t sector_count);
static void bsp_sdhi_sector_read(uint8_t * p_dest);
static void bsp_sdhi_operation_complete_wait(void);

static uint8_t g_bsp_sdhi_read_buffer[BSP_PRV_SDHI_SECTOR_SIZE] BSP_PLACE_IN_SECTION(".bsp_sdhi_data");

static R_SDHI0_Type * p_reg;

/* Saves the current SDHI register value.
 *   - The SD_CMD register is not saved because it issues commands when writing data during restore.
 *   - Read-only registers are not saved because they cannot be restored. */
static uint32_t sd_arg      BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sd_arg1     BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sd_stop     BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sd_seccnt   BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sd_info1    BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sd_clk_ctrl BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sd_option   BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t sdio_info1  BSP_PLACE_IN_SECTION(".bsp_sdhi_data");
static uint32_t host_mode   BSP_PLACE_IN_SECTION(".bsp_sdhi_data");

 #if (1 == BSP_CFG_EMMC_BOOT)
static void bsp_sdhi_max_clock_rate_set(uint32_t max_rate);
static void bsp_sdhi_command_send(uint32_t command, uint32_t argument);
static void bsp_sdhi_wait_for_device(void);
static void bsp_sdhi_command_send_no_wait(uint32_t command, uint32_t argument);
static void bsp_sdhi_emmc_check(void);
static void bsp_sdhi_bus_cfg(void);
static void bsp_sdhi_rca_get(uint32_t * p_rca);
static void bsp_sdhi_clock_optimize(uint32_t rca);
static void bsp_sdhi_csd_extended_get(uint32_t rca, uint8_t * p_device_type);
static void bsp_sdhi_read_and_block(uint32_t command, uint32_t argument, uint32_t byte_count);
static void bsp_sdhi_read_write_common(uint32_t sector_count, uint32_t sector_size, uint32_t command,
                                       uint32_t argument);
static void bsp_sdhi_transfer_read(void);
static void bsp_sdhi_bus_width_set(void);

 #endif

/*******************************************************************************************************************//**
 * Copy the memory block from SDHI Source address to Destination address by the multi byte unit.
 *
 * @param[in]   channel          SDHI channel.
 * @param[in]   src              Pointer to copy from.
 * @param[in]   dest             Pointer to copy to.
 * @param[in]   bytesize         Number of bytes to copy.
 **********************************************************************************************************************/
void bsp_sdhi_copy_multibyte (uint32_t             channel,
                              volatile uintptr_t * src,
                              volatile uintptr_t * dst,
                              volatile uintptr_t   bytesize)
{
    /* If the number of bytes to copy is 0, return here. */
    if (0 == bytesize)
    {
        return;
    }

    p_reg = (0 == channel) ? R_SDHI0 : R_SDHI1;

    volatile uint8_t * src_single_byte = (volatile uint8_t *) BSP_PRV_CONVERT_SDHI_FLASH_CONTENTS_ADDRESS(src);
    volatile uint8_t * dst_single_byte = (volatile uint8_t *) dst;

    /* Get start sector to read. */
    uint32_t read_first_sector = (uint32_t) (uintptr_t) src_single_byte / BSP_PRV_SDHI_SECTOR_SIZE;

    /* Get the number of sectors to read. */
    uint32_t read_sector_count;
    uint32_t read_begin_address_in_first_sector = (uintptr_t) src_single_byte % BSP_PRV_SDHI_SECTOR_SIZE;
    uint32_t read_size_from_first_sector        = BSP_PRV_SDHI_SECTOR_SIZE - read_begin_address_in_first_sector;
    if (read_size_from_first_sector > bytesize)
    {
        read_size_from_first_sector = (uint32_t) bytesize;
        read_sector_count           = 1;
    }
    else
    {
        uint32_t remain_size   = (uint32_t) bytesize - read_size_from_first_sector;
        uint32_t remain_sector = remain_size / BSP_PRV_SDHI_SECTOR_SIZE;
        if (remain_size % BSP_PRV_SDHI_SECTOR_SIZE)
        {
            /* Add the last sector for the remainder. */
            remain_sector += 1;
        }

        read_sector_count = 1 + remain_sector; // First sector + Remain sector
    }

    /* Issue Read command */
    bsp_sdhi_read_command_issue(read_first_sector, read_sector_count);

    uint32_t remain_byte = (uint32_t) bytesize;
    while (remain_byte > 0)
    {
        /* Read sector from SDHI */
        bsp_sdhi_sector_read(&g_bsp_sdhi_read_buffer[0]);

        /* Copy as much as needed from g_bsp_sdhi_read_buffer to the destination RAM. */
        uint32_t read_begin_address_in_this_sector = (uintptr_t) src_single_byte % BSP_PRV_SDHI_SECTOR_SIZE;
        uint32_t read_size_from_this_sector        = BSP_PRV_SDHI_SECTOR_SIZE - read_begin_address_in_this_sector;

        if (read_size_from_this_sector > remain_byte)
        {
            read_size_from_this_sector = remain_byte;
        }

        for (uint32_t i = 0; i < read_size_from_this_sector; i++)
        {
            *dst_single_byte++ = g_bsp_sdhi_read_buffer[read_begin_address_in_this_sector + i];
        }

        /* Prepare to read from the next sector. */
        src_single_byte += read_size_from_this_sector;
        remain_byte     -= read_size_from_this_sector;
    }

    bsp_sdhi_operation_complete_wait();
    __DSB();
    __ISB();
}

/*******************************************************************************************************************//**
 * Copy the memory block from SDHI Source address to Destination address by the 8 byte unit.
 *
 * @param[in]   channel          SDHI channel.
 * @param[in]   src              Pointer to copy from.
 * @param[in]   dest             Pointer to copy to.
 * @param[in]   bytesize         Number of bytes to copy.
 **********************************************************************************************************************/
void bsp_sdhi_copy_multibyte_8byte (uint32_t             channel,
                                    volatile uintptr_t * src,
                                    volatile uintptr_t * dst,
                                    volatile uintptr_t   bytesize)
{
    /* If the number of bytes to copy is 0, return here. */
    if (0 == bytesize)
    {
        return;
    }

    p_reg = (0 == channel) ? R_SDHI0 : R_SDHI1;

    uint8_t read_buffer[BSP_PRV_SDHI_SECTOR_SIZE];

    volatile uint8_t * src_single_byte = (volatile uint8_t *) BSP_PRV_CONVERT_SDHI_FLASH_CONTENTS_ADDRESS(src);
    volatile uint8_t * dst_single_byte = (volatile uint8_t *) dst;

    /* Get start sector to read. */
    uint32_t read_first_sector = (uint32_t) (uintptr_t) src_single_byte / BSP_PRV_SDHI_SECTOR_SIZE;

    /* Get the number of sectors to read. */
    uint32_t read_sector_count;
    uint32_t read_begin_address_in_first_sector = (uintptr_t) src_single_byte % BSP_PRV_SDHI_SECTOR_SIZE;
    uint32_t read_size_from_first_sector        = BSP_PRV_SDHI_SECTOR_SIZE - read_begin_address_in_first_sector;
    if (read_size_from_first_sector > bytesize)
    {
        read_size_from_first_sector = (uint32_t) bytesize;
        read_sector_count           = 1;
    }
    else
    {
        uint32_t remain_size   = (uint32_t) bytesize - read_size_from_first_sector;
        uint32_t remain_sector = remain_size / BSP_PRV_SDHI_SECTOR_SIZE;
        if (remain_size % BSP_PRV_SDHI_SECTOR_SIZE)
        {
            /* Add the last sector for the remainder. */
            remain_sector += 1;
        }

        read_sector_count = 1 + remain_sector; // First sector + Remain sector
    }

    /* Issue Read command */
    bsp_sdhi_read_command_issue(read_first_sector, read_sector_count);

    uint32_t remain_byte = (uint32_t) bytesize;
    while (remain_byte > 0)
    {
        /* Read sector from SDHI */
        bsp_sdhi_sector_read(&read_buffer[0]);

        /* Copy as much as needed from read_buffer to the destination RAM. */
        uint32_t read_begin_address_in_this_sector = (uintptr_t) src_single_byte % BSP_PRV_SDHI_SECTOR_SIZE;
        uint32_t read_size_from_this_sector        = BSP_PRV_SDHI_SECTOR_SIZE - read_begin_address_in_this_sector;

        if (read_size_from_this_sector > remain_byte)
        {
            read_size_from_this_sector = remain_byte;
        }

        for (uint32_t i = 0; i < read_size_from_this_sector; i += sizeof(uint64_t))
        {
            uint64_t * src_8byte = (uint64_t *) &read_buffer[read_begin_address_in_this_sector + i];
            uint64_t * dst_8byte = (uint64_t *) dst_single_byte;

 #if defined(BSP_CFG_CORE_CR52)
            __asm volatile (
                "    MOV    r6, %[src_8byte]   \n"
                "    LDR    r4, [r6], #4       \n"
                "    LDR    r5, [r6]           \n"
                "    MOV    r6, %[dst_8byte]   \n"
                "    STRD   r4, r5, [r6]       \n"
                "    DSB SY                    \n"
                ::[src_8byte] "r" (src_8byte),
                [dst_8byte] "r" (dst_8byte) : "memory", "r4", "r5", "r6");
 #elif defined(BSP_CFG_CORE_CA55)
            __asm volatile (
                "    MOV    x6, %[src_8byte]   \n"
                "    LDR    x5, [x6]           \n"
                "    MOV    x6, %[dst_8byte]   \n"
                "    STR    x5, [x6]           \n"
                "    DSB SY                    \n"
                ::[src_8byte] "r" (src_8byte),
                [dst_8byte] "r" (dst_8byte) : "memory", "x5", "x6");
 #endif

            dst_single_byte += sizeof(uint64_t);
        }

        /* Prepare to read from the next sector. */
        src_single_byte += read_size_from_this_sector;
        remain_byte     -= read_size_from_this_sector;
    }

    bsp_sdhi_operation_complete_wait();
    __DSB();
    __ISB();
}

/*******************************************************************************************************************//**
 * Issue a Read command to an SDHI memory device.
 *
 * @param[in]   start_sector     First sector address to read.
 * @param[in]   sector_count     Number of sectors to read.
 **********************************************************************************************************************/
static void bsp_sdhi_read_command_issue (uint32_t start_sector, uint32_t sector_count)
{
    uint32_t command;
    uint32_t argument = start_sector;

    /* Set the command and sector count. */
    if (sector_count > 1U)
    {
        command          = 18;         /* CMD18 */
        p_reg->SD_STOP   = 0x100;
        p_reg->SD_SECCNT = sector_count;
    }
    else
    {
        command        = 17;           /* CMD17 */
        p_reg->SD_STOP = 0U;
    }

    /* Set sector size */
    p_reg->SD_SIZE = BSP_PRV_SDHI_SECTOR_SIZE;

    p_reg->SD_INFO1 = 0U;
    p_reg->SD_INFO2 = 0U;

    /* Enable Clock */
    p_reg->SD_CLK_CTRL |= 0x300U;

    /* Write argument, then command to the SDHI peripheral. */
    p_reg->SD_ARG  = argument & UINT16_MAX;
    p_reg->SD_ARG1 = argument >> 16;
    p_reg->SD_CMD  = command;

    /* 32bit access to SD_BUF for read process without built-in DMAC. */
    p_reg->HOST_MODE |= (1U << 0) | (1U << 8);

    /* SD_BUF read/write DMA transfer is disabled. */
    p_reg->CC_EXT_MODE_b.DMASDRW = 0;
}

/*******************************************************************************************************************//**
 * Read one sector data stored in the SDHI SD_BUF register that was read from the SDHI device.
 *
 * @param[in]   p_dest     Pointer to data buffer to read data to.
 **********************************************************************************************************************/
static void bsp_sdhi_sector_read (uint8_t * p_dest)
{
    /* Wait until the read data from SDHI memory device can be read from SD_BUF. */
    FSP_HARDWARE_REGISTER_WAIT(p_reg->SD_INFO2_b.BRE, 1);
    p_reg->SD_INFO2_b.BRE = 0;

    uint32_t * p_transfer_data_32 = (uint32_t *) &p_dest[0];
    for (uint32_t i = 0; i < BSP_PRV_SDHI_SECTOR_SIZE / sizeof(uint32_t); i += 2)
    {
        p_transfer_data_32[i]     = p_reg->SD_BUF0H;
        p_transfer_data_32[i + 1] = p_reg->SD_BUF0L;
    }

    /* Wait SDHI memory device busy state. */
    FSP_HARDWARE_REGISTER_WAIT(p_reg->SD_INFO2_b.DAT0, 1);
}

/*******************************************************************************************************************//**
 * Wait for read access completion for the SDHI device.
 **********************************************************************************************************************/
static void bsp_sdhi_operation_complete_wait (void)
{
    /* Wait Operation complete. */
    FSP_HARDWARE_REGISTER_WAIT(p_reg->SD_INFO1_b.INFO2, 1);
    p_reg->SD_INFO1_b.INFO2 = 0;
}

/*******************************************************************************************************************//**
 * Saves the current SDHI setting value for SDHI access by the loader program.
 * This is to preserve the value of registers at the time when eSD boot mode finishes
 * even after the loader program has executed.
 *
 * (For details, see table 'Setting register values of the related peripheral modules
 * when eSD boot mode finishes' of RZ microprocessor manual.)
 **********************************************************************************************************************/
void bsp_sdhi_store_sdhi_register (void)
{
    uint32_t channel;
 #if (1 == BSP_CFG_ESD_BOOT)
    channel = BSP_FEATURE_BSP_ESD_BOOT_CHANNEL;
 #elif (1 == BSP_CFG_EMMC_BOOT)
    channel = BSP_FEATURE_BSP_EMMC_BOOT_CHANNEL;
 #endif

    p_reg = (0 == channel) ? R_SDHI0 : R_SDHI1;

    sd_arg      = p_reg->SD_ARG;
    sd_arg1     = p_reg->SD_ARG1;
    sd_stop     = p_reg->SD_STOP;
    sd_seccnt   = p_reg->SD_SECCNT;
    sd_info1    = p_reg->SD_INFO1;
    sd_clk_ctrl = p_reg->SD_CLK_CTRL;
    sd_option   = p_reg->SD_OPTION;
    sdio_info1  = p_reg->SDIO_INFO1;
    host_mode   = p_reg->HOST_MODE;
}

/*******************************************************************************************************************//**
 * Restores the saved SDHI register setting value.
 **********************************************************************************************************************/
void bsp_sdhi_restore_sdhi_register (void)
{
    p_reg->SD_ARG      = sd_arg;
    p_reg->SD_ARG1     = sd_arg1;
    p_reg->SD_STOP     = sd_stop;
    p_reg->SD_SECCNT   = sd_seccnt;
    p_reg->SD_INFO1    = sd_info1;
    p_reg->SD_CLK_CTRL = sd_clk_ctrl;
    p_reg->SD_OPTION   = sd_option;
    p_reg->SDIO_INFO1  = sdio_info1;
    p_reg->HOST_MODE   = host_mode;
}

/*******************************************************************************************************************//**
 * Initialize uninitialized BSP SDHI variables for use in eSD boot or eMMC boot.
 **********************************************************************************************************************/
void bsp_sdhi_init_uninitialized_vars (void)
{
    uintptr_t * p_buffer = (uintptr_t *) g_bsp_sdhi_read_buffer;
    for (uint32_t i = 0; i < (BSP_PRV_SDHI_SECTOR_SIZE / sizeof(uintptr_t)); i++)
    {
        *p_buffer++ = 0;
    }

    sd_arg      = 0;
    sd_arg1     = 0;
    sd_stop     = 0;
    sd_seccnt   = 0;
    sd_info1    = 0;
    sd_clk_ctrl = 0;
    sd_option   = 0;
    sdio_info1  = 0;
    host_mode   = 0;
}

 #if (1 == BSP_CFG_EMMC_BOOT)

/*******************************************************************************************************************//**
 * Initializes the SDHI hardware and completes identification and configuration for the eMMC device.  This
 * procedure requires several sequential commands.  This function blocks until all identification and configuration
 * commands are complete.
 **********************************************************************************************************************/
void bsp_sdhi_emmc_media_init (void)
{
    /* Reset SDHI. */
    p_reg->SOFT_RST = 0x0U;
    p_reg->SOFT_RST = 0x1U;

    /* The host shall low RST_n signal supply at least 1us to the eMMC device (tRSTW).
     * Reference section 6.15.9 "H/W Reset Operation" in the Embedded Multi-Media Card (eMMC) Electrical Standard (5.0)
     * JESD84-B50. */
    p_reg->SD_STATUS_b.SD_RST = 0;
    R_BSP_SoftwareDelay(2, BSP_DELAY_UNITS_MICROSECONDS);

    /* The host shall high RST_n supply at least 200us to the eMMC device (tRSCA).
     * Reference section 6.15.9 "H/W Reset Operation" in the Embedded Multi-Media Card (eMMC) Electrical Standard (5.0)
     * JESD84-B50. */
    p_reg->SD_STATUS_b.SD_RST = 1;
    R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MICROSECONDS);

    /* Reset SDHI. */
    p_reg->SOFT_RST = 0x0U;
    p_reg->SOFT_RST = 0x1U;

    /* Execute software reset or check SD_INFO2.SCLKDIVEN prior to calling this function. */
    p_reg->SD_CLK_CTRL = BSP_PRV_SD_CLK_CTRL_DEFAULT;          // Automatic clock control disabled.
    p_reg->SDIO_MODE   = 0x00U;                                // SDIO not supported.
    p_reg->CC_EXT_MODE = BSP_PRV_SD_CC_EXT_MODE_DMASDRW_CLEAR; // Not in DMA mode initially.
    p_reg->SDIF_MODE   = 0x00U;                                // CRC check is valid.

    /* Set the clock frequency to 400 kHz or less for identification. */
    bsp_sdhi_max_clock_rate_set(BSP_PRV_INIT_MAX_CLOCK_RATE_HZ);

    /* Set initial bus width to one bit wide. */
    p_reg->SD_OPTION = BSP_PRV_SD_OPTION_DEFAULT |
                       (BSP_PRV_BUS_WIDTH_1_BIT << BSP_PRV_SD_OPTION_WIDTH8_BIT);

    /* The host shall supply at least 74 SD clocks to the SD card while keeping CMD line high.  Reference section
     * 6.4.1.1 "Power Up Time of Card" in the SD Physical Layer Specification Version 6.00. */
    R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);

    /* Automatic clock control can be enabled only after 74 SD/MMC clock cycles are output.  Reference section
     * 'Automatic Control of SDCLK Output' of the RZ microprocessor manual. */

    /* For eMMC devices, follow the procedure in A.6.1 "Bus Initialization" in JEDEC Standard No. 84-B51A. */

    /* Put the card in idle state. */
    bsp_sdhi_command_send(BSP_PRV_CMD_GO_IDLE_STATE, 0);

    /* If the device is not SD memory, check to see if it is an eMMC device (CMD1). */
    bsp_sdhi_emmc_check();

    /* Enter identification state (CMD2). */
    bsp_sdhi_command_send(BSP_PRV_CMD_ALL_SEND_CID, 0); /* send SD CMD2 */

    /* Configure bus clock, block size, and bus width. */
    bsp_sdhi_bus_cfg();
}

/*******************************************************************************************************************//**
 * Set the SD clock to a rate less than or equal to the requested maximum rate.
 *
 * @param[in]  max_rate                  Maximum SD clock rate to set
 **********************************************************************************************************************/
static void bsp_sdhi_max_clock_rate_set (uint32_t max_rate)
{
    uint32_t setting = BSP_PRV_CLK_CTRL_DIV_INVALID;

    /* Get the runtime frequency of the source of the SD clock */
    uint32_t frequency = R_FSP_SystemClockHzGet(BSP_FEATURE_SDHI_CLOCK);

    /* Iterate over all possible divisors, starting with the smallest, until the resulting clock rate is less than
     * or equal to the requested maximum rate. */
    for (uint32_t divisor_shift = BSP_FEATURE_SDHI_MIN_CLOCK_DIVISION_SHIFT;
         divisor_shift <= BSP_PRV_MAX_CLOCK_DIVISION_SHIFT;
         divisor_shift++)
    {
        if ((frequency >> divisor_shift) <= max_rate)
        {
            /* If the calculated frequency is less than or equal to the maximum supported by the device,
             * select this frequency. The register setting is the divisor value divided by 4, or 0xFF for no divider. */
            setting = divisor_shift ? ((1U << divisor_shift) >> 2U) : UINT8_MAX;

            /* Set the clock setting. */

            /* The clock register is accessible 8 SD clock counts after the last command completes.  Each register access
             * requires at least one PCLK count, so check the register up to 8 times the maximum PCLK divisor value (512). */
            uint32_t timeout = BSP_PRV_SCLKDIVEN_TIMEOUT;

            while (timeout > 0U)
            {
                /* Do not write to clock control register until this bit is set. */
                if (p_reg->SD_INFO2_b.SCLKDIVEN)
                {
                    /* Set the calculated divider and enable clock output to start the 74 clocks required before
                     * initialization. Do not change the automatic clock control setting. */
                    uint32_t clkctrlen = p_reg->SD_CLK_CTRL & BSP_PRV_BSP_PRV_SD_CLK_CTRL_CLKCTRLEN_MASK;
                    p_reg->SD_CLK_CTRL = setting | clkctrlen | BSP_PRV_BSP_PRV_SD_CLK_CTRL_CLKEN_MASK;

                    return;
                }

                timeout--;
            }

            /* Valid setting already found, stop looking. */
            break;
        }
    }

    /* eMMC device failed to initialize. */
}

/*******************************************************************************************************************//**
 * Send a command to the eMMC device and wait for response.
 *
 * @param[in]  command         Command to send.
 * @param[in]  argument        Argument to send with the command.
 **********************************************************************************************************************/
static void bsp_sdhi_command_send (uint32_t command, uint32_t argument)
{
    uint32_t info1;
    uint32_t info2;

    /* Verify the device is not busy. */
    bsp_sdhi_wait_for_device();

    /* Send the command. */
    bsp_sdhi_command_send_no_wait(command, argument);

    /* Wait for end of response. */
    FSP_HARDWARE_REGISTER_WAIT(p_reg->SD_INFO1_b.INFO0, 1);

    /* Clear stop register after access end. */
    p_reg->SD_STOP_b.STP = 0U;

    /* Read interrupt flag registers. */
    info1 = p_reg->SD_INFO1;
    info2 = p_reg->SD_INFO2;

    /* Clear interrupt flags processed in this ISR. */
    info1          &= BSP_PRV_SDHI_INFO1_ACCESS_MASK;
    info2          &= BSP_PRV_SDHI_INFO2_MASK;
    p_reg->SD_INFO1 = (~info1);
    p_reg->SD_INFO2 = (~info2);

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(p_reg->SD_INFO1);
    FSP_REGISTER_READ(p_reg->SD_INFO2);
}

/*******************************************************************************************************************//**
 * Wait for the device.
 **********************************************************************************************************************/
static void bsp_sdhi_wait_for_device (void)
{
    /* Wait for the device to stop holding DAT0 low. */
    uint32_t timeout = BSP_PRV_BUSY_TIMEOUT_US;
    while (BSP_PRV_SD_INFO2_CBSY_DAT0_IDLE_VAL !=
           (p_reg->SD_INFO2 & BSP_PRV_SD_INFO2_CBSY_DAT0_IDLE_MASK))
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MICROSECONDS);
        timeout--;
    }
}

/*******************************************************************************************************************//**
 * Send a command to the eMMC device.
 *
 * @param[in]  command         Command to send.
 * @param[in]  argument        Argument to send with the command.
 **********************************************************************************************************************/
static void bsp_sdhi_command_send_no_wait (uint32_t command, uint32_t argument)
{
    /* Clear Status */
    p_reg->SD_INFO1 = 0U;
    p_reg->SD_INFO2 = 0U;

    /* Enable Clock */
    p_reg->SD_CLK_CTRL |= BSP_PRV_BSP_PRV_SD_CLK_AUTO_CLOCK_ENABLE_MASK;

    /* Write argument, then command to the SDHI peripheral. */
    p_reg->SD_ARG  = argument & UINT16_MAX;
    p_reg->SD_ARG1 = argument >> 16;
    p_reg->SD_CMD  = command;
}

/*******************************************************************************************************************//**
 * Checks to see if the device is an eMMC.
 **********************************************************************************************************************/
static void bsp_sdhi_emmc_check (void)
{
    uint32_t ocr;
    uint32_t response = {0U};
    uint32_t capacity;
    capacity = BSP_PRV_OCR_CAPACITY_HC; /* SDHC cards supported */

    /* Tries to send CMD1 for up to 1 second as long as the device is responding and initialization is not complete.
     * Returns immediately if the device fails to respond to CMD1. */

    /* To ensure the 1 second timeout, consider that there are 48 bits in a command, 48 bits in a response, and 8 clock
     * cycles minimum between commands, so there are 104 clocks minimum, and the maximum clock rate at this point is 400
     * kHz, so issue the command 400000 / 104 times to ensure a timeout of at least 1 second. */
    for (uint32_t i = 0U; i < BSP_PRV_INIT_ONE_SECOND_TIMEOUT_ITERATIONS; i++)
    {
        /*  Format and send cmd: Volt. window is usually 0x00300000 (3.4-3.2v) */
        /* SD cards will not respond to CMD1  */
        ocr  = BSP_PRV_OCR_VDD_SUPPORTED;
        ocr |= capacity;

        bsp_sdhi_command_send(BSP_PRV_EMMC_SEND_OP_COND, ocr);

        /* get response of CMD1  */
        response = p_reg->SD_RSP10L;
        uint32_t power_up_status = ((response >> BSP_PRV_POWER_UP_STATUS_SHIFT) & BSP_PRV_POWER_UP_STATUS_MASK);

        /* Initialization complete? */
        if (power_up_status)
        {
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Initializes bus clock, block length, and bus width.
 **********************************************************************************************************************/
static void bsp_sdhi_bus_cfg (void)
{
    /* Get relative card address (CMD3). */
    uint32_t rca;
    bsp_sdhi_rca_get(&rca);

    /* Switch to transfer state (CMD7). */
    bsp_sdhi_command_send(BSP_PRV_CMD_SEL_DES_CARD, rca << 16);

    /* Set clock to highest supported frequency. */
    bsp_sdhi_clock_optimize(rca);

    /* Set the block length (CMD16) to 512 bytes. */
    bsp_sdhi_command_send(BSP_PRV_CMD_SET_BLOCKLEN, 512U);

    /* Set bus width. */
    bsp_sdhi_bus_width_set();
}

/*******************************************************************************************************************//**
 * Gets or assigns the relative card address.
 *
 * @param[out] p_rca                Pointer to store relative card address.
 **********************************************************************************************************************/
static void bsp_sdhi_rca_get (uint32_t * p_rca)
{
    /* Send CMD3.  For eMMC, assign an RCA of SDHI channel number + 2. These bits of the argument are ignored for SD
     * cards. */

    uint32_t rca = (0U + 2U);
    bsp_sdhi_command_send(BSP_PRV_CMD_SEND_RELATIVE_ADDR, rca << 16);

    *p_rca = rca;
}

/*******************************************************************************************************************//**
 * Set SDHI clock to fastest allowable speed for card.
 *
 * @param[in]  rca                       Relative card address
 **********************************************************************************************************************/
static void bsp_sdhi_clock_optimize (uint32_t rca)
{
    uint32_t max_clock_rate = BSP_PRV_SD_DEFAULT_CLOCK_RATE;

    uint8_t device_type;
    bsp_sdhi_csd_extended_get(rca, &device_type);

    max_clock_rate = BSP_PRV_EMMC_DEFAULT_CLOCK_RATE;
    if ((BSP_PRV_EMMC_HIGH_SPEED_52_MHZ_BIT & device_type) > 0U)
    {
        /* 52 MHz high speed supported, switch to this mode (CMD6). */
        bsp_sdhi_command_send(BSP_PRV_EMMC_CMD_SWITCH_WBUSY, BSP_PRV_EMMC_HIGH_SPEED_MODE);

        max_clock_rate = BSP_PRV_EMMC_HIGH_SPEED_CLOCK_RATE; // Set clock rate to 52 MHz maximum

        /* Device may signal busy after CMD6.  Wait for busy to clear. */
        bsp_sdhi_wait_for_device();
    }

    bsp_sdhi_max_clock_rate_set(max_clock_rate);
}

/*******************************************************************************************************************//**
 * Get and store relevant extended card specific data.
 *
 * @param[in]  rca                  Relative card address
 * @param[out] p_device_type        Pointer to store device type, which is used to determine if high speed is supported.
 **********************************************************************************************************************/
static void bsp_sdhi_csd_extended_get (uint32_t rca, uint8_t * p_device_type)
{
    /* Ask card to send extended CSD (CMD8). */
    bsp_sdhi_read_and_block(BSP_PRV_EMMC_CMD_SEND_EXT_CSD, rca << 16, BSP_PRV_EMMC_EXT_CSD_SIZE);

    /* Store device type.  Also store sector count if it is not already determined. */
    uint8_t * p_read_data_8 = (uint8_t *) g_bsp_sdhi_read_buffer;
    *p_device_type = p_read_data_8[BSP_PRV_EMMC_EXT_CSD_DEVICE_TYPE_OFFSET];
}

/*******************************************************************************************************************//**
 * Issue command expecting data to be returned, and block until read data is returned.
 *
 * @param[in]  command              Command to issue.
 * @param[in]  argument             Argument to send with command.
 * @param[in]  byte_count           Expected number of bytes to read.
 **********************************************************************************************************************/
static void bsp_sdhi_read_and_block (uint32_t command, uint32_t argument, uint32_t byte_count)
{
    /* Issue command. */
    bsp_sdhi_read_write_common(1U, byte_count, command, argument);

    /* Prepare transfer interface to read. */
    bsp_sdhi_transfer_read();

    /* Wait for access end. */
    bsp_sdhi_sector_read(g_bsp_sdhi_read_buffer);

    bsp_sdhi_operation_complete_wait();
}

/*******************************************************************************************************************//**
 * Read or write data.
 *
 * @param[in]  sector_count    Number of sectors to read or write.
 * @param[in]  sector_size     Size of one sector in bytes.
 * @param[in]  command         Command number
 * @param[in]  argument        Argument
 **********************************************************************************************************************/
static void bsp_sdhi_read_write_common (uint32_t sector_count, uint32_t sector_size, uint32_t command,
                                        uint32_t argument)
{
    /* Set the sector count. */
    if (sector_count > 1U)
    {
        p_reg->SD_STOP   = BSP_PRV_SD_STOP_SD_SECCNT_ENABLE;
        p_reg->SD_SECCNT = sector_count;
    }
    else
    {
        p_reg->SD_STOP = 0U;
    }

    /* Set sector size */
    p_reg->SD_SIZE = sector_size;

    /* Send command. */
    bsp_sdhi_command_send_no_wait(command, argument);
}

/*******************************************************************************************************************//**
 * Set bus width.
 **********************************************************************************************************************/
static void bsp_sdhi_bus_width_set (void)
{
    uint32_t bus_width;
    uint32_t bus_width_setting;

    bus_width = 8;

    /* For eMMC, set bus width using CMD6. */
    bus_width_setting = ((bus_width >> 2U) & 0x03U);
    bsp_sdhi_command_send(BSP_PRV_EMMC_CMD_SWITCH_WBUSY,
                          ((0x1U << BSP_PRV_SWITCH_ACCESS_SHIFT) |
                           (BSP_PRV_EMMC_BUS_WIDTH_INDEX <<
                            BSP_PRV_SWITCH_INDEX_SHIFT) |
                           (bus_width_setting << BSP_PRV_SWITCH_VALUE_SHIFT)));

    /* Device may signal busy after CMD6.  Wait for busy to clear. */
    bsp_sdhi_wait_for_device();

    /* Set the bus width in the SDHI peripheral. */
    p_reg->SD_OPTION = BSP_PRV_SD_OPTION_DEFAULT | (BSP_PRV_BUS_WIDTH_8_BIT << BSP_PRV_SD_OPTION_WIDTH8_BIT);
}

/*******************************************************************************************************************//**
 * Set up transfer to read from device.
 **********************************************************************************************************************/
static void bsp_sdhi_transfer_read (void)
{
    /* 32bit access to SD_BUF for read process without built-in DMAC. */
    p_reg->HOST_MODE |= (1U << BSP_PRV_HOST_MODE_WMODE_BIT) |
                        (1U << BSP_PRV_HOST_MODE_BUSWIDTH_BIT);

    /* SD_BUF read/write DMA transfer is disabled. */
    p_reg->CC_EXT_MODE_b.DMASDRW = 0;
}

 #endif

#endif
