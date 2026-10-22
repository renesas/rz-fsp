/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_OSPI_H
 #define R_OSPI_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include <string.h>
 #include "r_xspi_ospi_cfg.h"
 #include "r_spi_flash_api.h"

 #if XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE
  #include "r_transfer_api.h"
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

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
 * Typedef definitions
 **********************************************************************************************************************/

/* OSPI Flash chip select */
typedef enum e_xspi_ospi_chip_select
{
    XSPI_OSPI_CHIP_SELECT_0,           ///< Device connected to Chip-Select 0
    XSPI_OSPI_CHIP_SELECT_1,           ///< Device connected to Chip-Select 1
} xspi_ospi_chip_select_t;

/* OctaFlash memory size */
typedef enum e_xspi_ospi_memory_size
{
    XSPI_OSPI_MEMORY_SIZE_1MB  = 0x00, ///< Memory size 1MB
    XSPI_OSPI_MEMORY_SIZE_2MB  = 0x01, ///< Memory size 2MB
    XSPI_OSPI_MEMORY_SIZE_4MB  = 0x03, ///< Memory size 4MB
    XSPI_OSPI_MEMORY_SIZE_8MB  = 0x07, ///< Memory size 8MB
    XSPI_OSPI_MEMORY_SIZE_16MB = 0x0F, ///< Memory size 16MB
    XSPI_OSPI_MEMORY_SIZE_32MB = 0x1F, ///< Memory size 32MB
    XSPI_OSPI_MEMORY_SIZE_64MB = 0x3F, ///< Memory size 64MB
} xspi_ospi_memory_size_t;

/* Behavior when xSPI receive WRAP transaction */
typedef enum e_xspi_ospi_wrap_separate
{
    XSPI_OSPI_WRAP_SEPARATE_ENABLE,    ///< Separate xSPI frame at the wrapping address boundary
    XSPI_OSPI_WRAP_SEPARATE_DISABLE,   ///< Not separate xSPI frame at the wrapping address boundary
} xspi_ospi_wrap_separate_t;

/* OSPI command to command interval */
typedef enum e_xspi_ospi_command_interval_clocks
{
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_1,  ///< 1 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_2,  ///< 2 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_3,  ///< 3 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_4,  ///< 4 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_5,  ///< 5 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_6,  ///< 6 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_7,  ///< 7 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_8,  ///< 8 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_9,  ///< 9 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_10, ///< 10 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_11, ///< 11 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_12, ///< 12 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_13, ///< 13 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_14, ///< 14 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_15, ///< 15 interval clocks
    XSPI_OSPI_COMMAND_INTERVAL_CLOCKS_16, ///< 16 interval clocks
} xspi_ospi_command_interval_clocks_t;

/* OSPI chip select de-assertion duration */
typedef enum e_xspi_ospi_cs_pullup_clocks
{
    XSPI_OSPI_CS_PULLUP_CLOCKS_NO_EXTENSION = 0U, ///< CS asserting No extension
    XSPI_OSPI_CS_PULLUP_CLOCKS_1,                 ///< CS asserting Extend 1 cycle
} xspi_ospi_cs_pullup_clocks_t;

/* OSPI chip select assertion duration */
typedef enum e_xspi_ospi_cs_pulldown_clocks
{
    XSPI_OSPI_CS_PULLDOWN_CLOCKS_NO_EXTENSION = 0U, ///< CS negating No extension
    XSPI_OSPI_CS_PULLDOWN_CLOCKS_1,                 ///< CS negating Extend 1 cycle
} xspi_ospi_cs_pulldown_clocks_t;

/** Memory mapped timing */
struct st_xspi_ospi_timing_setting
{
    xspi_ospi_command_interval_clocks_t command_to_command_interval; ///< Interval between 2 consecutive commands
    xspi_ospi_cs_pullup_clocks_t        cs_pullup_lag;               ///< Duration to de-assert CS line after the last command
    xspi_ospi_cs_pulldown_clocks_t      cs_pulldown_lead;            ///< Duration to assert CS line before the first command
};

/** Memory mapped timing. Please refer to the struct st_xspi_ospi_timing_setting. */
typedef struct st_xspi_ospi_timing_setting xspi_ospi_timing_setting_t;

/* Prefetch function settings */
typedef enum e_xspi_ospi_prefetch_function
{
    XSPI_OSPI_PREFETCH_FUNCTION_DISABLE = 0x00, ///< Prefetch function disable
    XSPI_OSPI_PREFETCH_FUNCTION_ENABLE  = 0x01, ///< Prefetch function enable
} xspi_ospi_prefetch_function_t;

/* IO voltage settings */
typedef enum e_xspi_ospi_io_voltage
{
    XSPI_OSPI_IO_VOLTAGE_1_8V = 0x00,  ///< IO voltage 1.8V
    XSPI_OSPI_IO_VOLTAGE_3_3V = 0x01,  ///< IO voltage 3.3V
} xspi_ospi_io_voltage_t;

/* 8D-8D-8D(OPI) byte order options */
typedef enum e_xspi_ospi_byte_order
{
    XSPI_OSPI_BYTE_ORDER_0123,         ///< 8D-8D-8D(OPI) byte order byte 0, byte 1, byte 2, byte 3
    XSPI_OSPI_BYTE_ORDER_1032          ///< 8D-8D-8D(OPI) byte order byte 1, byte 0, byte 3, byte 2
} xspi_ospi_byte_order_t;

/** This command set is used only with OPI mode set under ospi_extended_cfg_t. spi_flash_cfg_t holds commands for SPI mode. */
struct st_xspi_ospi_opi_command_set
{
    uint16_t dual_read_command;        ///< Dual data Read command, valid only in DOPI mode
    uint16_t page_program_command;     ///< Page program command
    uint16_t write_enable_command;     ///< Command to enable write or erase, typically 0x06
    uint16_t status_command;           ///< Command to read the write status
    uint8_t  command_bytes;            ///< Command Bytes
};

/** This command set is used only with OPI mode set under ospi_extended_cfg_t. spi_flash_cfg_t holds commands for SPI mode. Please refer to the struct st_xspi_ospi_opi_command_set. */
typedef struct st_xspi_ospi_opi_command_set xspi_ospi_opi_command_set_t;

/** Address space settings */
struct st_ospi_address_space
{
    uint32_t unit0_cs0_end_address;    ///< xSPI unit0 cs0 end address
    uint32_t unit0_cs1_start_address;  ///< xSPI unit0 cs1 start address
    uint32_t unit0_cs1_end_address;    ///< xSPI unit0 cs1 end address
    uint32_t unit1_cs0_end_address;    ///< xSPI unit1 cs0 end address
    uint32_t unit1_cs1_start_address;  ///< xSPI unit1 cs1 start address
    uint32_t unit1_cs1_end_address;    ///< xSPI unit1 cs1 end address
};

/** Address space settings. Please refer to the struct st_ospi_address_space. */
typedef struct st_ospi_address_space xspi_ospi_address_space_t;

/** Extended configuration. */
struct st_xspi_ospi_extended_cfg
{
    uint8_t                             unit;                                    ///< Unit number of xSPI
    xspi_ospi_chip_select_t             chip_select;                             ///< Device number to be used for memory device
    uint32_t                            memory_size;                             ///< Size of memory device
    uint8_t                             address_msb_mask;                        ///< Mask of bits to zero when using memory-mapped operations; only applies to the most-significant byte.
    xspi_ospi_wrap_separate_t           wrap_separate;                           ///< Behavior when xSPI receive WRAP transaction
    xspi_ospi_timing_setting_t const  * p_timing_settings;                       ///< Memory mapped timing settings
    xspi_ospi_opi_command_set_t const * p_opi_commands;                          ///< If OPI commands are not used set this to NULL
    uint8_t                             opi_mem_read_dummy_cycles;               ///< Dummy cycles to be inserted for memory mapped reads
    uint8_t                           * p_autocalibration_preamble_pattern_addr; ///< OctaFlash memory address holding the preamble pattern
    uint8_t                             data_latch_delay_clocks;                 ///< Specify delay between OM_DQS and OM_DQS Strobe. Set to 0 to auto-callibrate. Typical value is 0x80.
    xspi_ospi_prefetch_function_t       prefetch_en;                             ///< Prefetch function settings
    xspi_ospi_io_voltage_t              io_voltage;                              ///< Voltage setting of xSPI IO domain
    xspi_ospi_byte_order_t              byte_order;                              ///< Byte order on external bus. Only applicable in 8D-8D-8D(OPI) mode.
    xspi_ospi_address_space_t const   * p_address_space;                         ///< Memory mapped address space settings
    void * p_reg;                                                                ///< Register base address for specified channel
 #if XSPI_OSPI_CFG_DMAC_SUPPORT_ENABLE
    transfer_instance_t const * p_lower_lvl_transfer;                            ///< DMAC Transfer instance used for data transmission
 #endif
};

/** Extended configuration. Please refer to the struct st_xspi_ospi_extended_cfg. */
typedef struct st_xspi_ospi_extended_cfg xspi_ospi_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::spi_flash_api_t::open is called */
struct st_xspi_ospi_instance_ctrl
{
    spi_flash_cfg_t const * p_cfg;        // Pointer to initial configuration
    uint32_t                open;         // Whether or not driver is open
    R_XSPI0_Type          * p_reg;        // Base register for this channel
    spi_flash_protocol_t    spi_protocol; // Current OSPI protocol selected
    xspi_ospi_chip_select_t chip_select;  // Device number to be used for memory device
};

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::spi_flash_api_t::open is called. Please refer to the struct st_xspi_ospi_instance_ctrl. */
typedef struct st_xspi_ospi_instance_ctrl xspi_ospi_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const spi_flash_api_t g_spi_flash_on_xspi_ospi;

/** @endcond */

fsp_err_t R_XSPI_OSPI_Open(spi_flash_ctrl_t * const p_ctrl, spi_flash_cfg_t const * const p_cfg);
fsp_err_t R_XSPI_OSPI_DirectWrite(spi_flash_ctrl_t * const p_ctrl,
                                  uint8_t const * const    p_src,
                                  uint32_t const           bytes,
                                  bool const               read_after_write);
fsp_err_t R_XSPI_OSPI_DirectRead(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_dest, uint32_t const bytes);
fsp_err_t R_XSPI_OSPI_DirectTransfer(spi_flash_ctrl_t * const            p_ctrl,
                                     spi_flash_direct_transfer_t * const p_transfer,
                                     spi_flash_direct_transfer_dir_t     direction);
fsp_err_t R_XSPI_OSPI_XipEnter(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_OSPI_XipExit(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_OSPI_Write(spi_flash_ctrl_t * const p_ctrl,
                            uint8_t const * const    p_src,
                            uint8_t * const          p_dest,
                            uint32_t                 byte_count);
fsp_err_t R_XSPI_OSPI_Erase(spi_flash_ctrl_t * const p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);
fsp_err_t R_XSPI_OSPI_StatusGet(spi_flash_ctrl_t * const p_ctrl, spi_flash_status_t * const p_status);
fsp_err_t R_XSPI_OSPI_BankSet(spi_flash_ctrl_t * const p_ctrl, uint32_t bank);
fsp_err_t R_XSPI_OSPI_SpiProtocolSet(spi_flash_ctrl_t * const p_ctrl, spi_flash_protocol_t spi_protocol);
fsp_err_t R_XSPI_OSPI_AutoCalibrate(spi_flash_ctrl_t * const p_ctrl);
fsp_err_t R_XSPI_OSPI_Close(spi_flash_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup XSPI_OSPI)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
