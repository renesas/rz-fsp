/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_XSPI_HYPER_H
 #define R_XSPI_HYPER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include <string.h>
 #include "r_xspi_hyper_cfg.h"
 #include "r_hyperbus_api.h"

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
 * @addtogroup RZT_XSPI_HYPER
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* XSPI_HYPER device chip select */
typedef enum e_xspi_hyper_chip_select
{
    XSPI_HYPER_CHIP_SELECT_0,          ///< Device connected to Chip-Select 0
    XSPI_HYPER_CHIP_SELECT_1,          ///< Device connected to Chip-Select 1
} xspi_hyper_chip_select_t;

/* XSPI_HYPER Memory device type select */
typedef enum e_xspi_hyper_device_type
{
    XSPI_HYPER_DEVICE_TYPE_FLASH = 0,  ///< Device Memory type HyperFlash
    XSPI_HYPER_DEVICE_TYPE_RAM,        ///< Device Memory type HyperRAM
} xspi_hyper_device_type_t;

/* XSPI_HYPER device memory size */
typedef enum e_xspi_hyper_memory_size
{
    XSPI_HYPER_MEMORY_SIZE_1MB  = 0x00, ///< Memory size 1MB
    XSPI_HYPER_MEMORY_SIZE_2MB  = 0x01, ///< Memory size 2MB
    XSPI_HYPER_MEMORY_SIZE_4MB  = 0x03, ///< Memory size 4MB
    XSPI_HYPER_MEMORY_SIZE_8MB  = 0x07, ///< Memory size 8MB
    XSPI_HYPER_MEMORY_SIZE_16MB = 0x0F, ///< Memory size 16MB
    XSPI_HYPER_MEMORY_SIZE_32MB = 0x1F, ///< Memory size 32MB
    XSPI_HYPER_MEMORY_SIZE_64MB = 0x3F, ///< Memory size 64MB
} xspi_hyper_memory_size_t;

/* Interval clocks between former transaction and new access */
typedef enum e_xspi_hyper_transaction_interval_clocks
{
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_1,  ///< 1 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_2,  ///< 2 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_3,  ///< 3 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_4,  ///< 4 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_5,  ///< 5 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_6,  ///< 6 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_7,  ///< 7 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_8,  ///< 8 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_9,  ///< 9 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_10, ///< 10 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_11, ///< 11 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_12, ///< 12 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_13, ///< 13 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_14, ///< 14 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_15, ///< 15 interval clocks
    XSPI_HYPER_TRANSACTION_INTERVAL_CLOCKS_16, ///< 16 interval clocks
} xspi_hyper_transaction_interval_clocks_t;

/* XSPI_HYPER device chip select assertion duration */
typedef enum e_xspi_hyper_cs_pulldown_clocks
{
    XSPI_HYPER_CS_PULLDOWN_CLOCKS_NO_EXTENSION = 0, ///< CS asserting No extension
    XSPI_HYPER_CS_PULLDOWN_CLOCKS_1,                ///< CS asserting Extend 1 cycle
} xspi_hyper_cs_pulldown_clocks_t;

/* XSPI_HYPER device chip select de-assertion duration */
typedef enum e_xspi_hyper_cs_pullup_clocks
{
    XSPI_HYPER_CS_PULLUP_CLOCKS_NO_EXTENSION = 0, ///< CS negating No extension
    XSPI_HYPER_CS_PULLUP_CLOCKS_1,                ///< CS negating Extend 1 cycle
} xspi_hyper_cs_pullup_clocks_t;

/* Prefetch function settings */
typedef enum e_xspi_hyper_prefetch_function
{
    XSPI_HYPER_PREFETCH_FUNCTION_DISABLE = 0x00, ///< Prefetch function disable
    XSPI_HYPER_PREFETCH_FUNCTION_ENABLE  = 0x01, ///< Prefetch function enable
} xspi_hyper_prefetch_function_t;

/* IO voltage settings */
typedef enum e_xspi_hyper_io_voltage
{
    XSPI_HYPER_IO_VOLTAGE_1_8V = 0x00, ///< IO voltage 1.8V
    XSPI_HYPER_IO_VOLTAGE_3_3V = 0x01, ///< IO voltage 3.3V
} xspi_hyper_io_voltage_t;

/** Memory mapped timing */
struct st_hyper_cs_timing_setting
{
    xspi_hyper_transaction_interval_clocks_t transaction_interval; ///< Interval between former transaction and new access
    xspi_hyper_cs_pullup_clocks_t            cs_pullup_lag;        ///< Duration to de-assert CS line after the last command
    xspi_hyper_cs_pulldown_clocks_t          cs_pulldown_lead;     ///< Duration to assert CS line before the first command
};

/** Memory mapped timing Please refer to the struct st_hyper_cs_timing_setting. */
typedef struct st_hyper_cs_timing_setting xspi_hyper_cs_timing_setting_t;

/** Address space settings */
struct st_hyper_address_space
{
    uint32_t unit0_cs0_end_address;    ///< xSPI unit0 cs0 end address
    uint32_t unit0_cs1_start_address;  ///< xSPI unit0 cs1 start address
    uint32_t unit0_cs1_end_address;    ///< xSPI unit0 cs1 end address
    uint32_t unit1_cs0_end_address;    ///< xSPI unit1 cs0 end address
    uint32_t unit1_cs1_start_address;  ///< xSPI unit1 cs1 start address
    uint32_t unit1_cs1_end_address;    ///< xSPI unit1 cs1 end address
};

/** Address space settings Please refer to the struct st_hyper_address_space. */
typedef struct st_hyper_address_space xspi_hyper_address_space_t;

/** Extended configuration */
struct st_xspi_hyper_extended_cfg
{
    uint8_t unit;                                                                   ///< Unit number
    xspi_hyper_chip_select_t               chip_select;                             ///< Device number to be used for memory device
    uint32_t                               memory_size;                             ///< Size of memory device
    xspi_hyper_device_type_t               memory_type;                             ///< Type of memory device
    xspi_hyper_prefetch_function_t         prefetch_en;                             ///< Prefetch function settings
    xspi_hyper_io_voltage_t                io_voltage;                              ///< Voltage setting of xSPI IO domains
    uint32_t                               data_latching_delay_clock;               ///< Specify delay between DQ and RWDS. Set to 0 to auto-callibrate.
    uint8_t                              * p_autocalibration_preamble_pattern_addr; ///< HyperBus memory address holding the preamble pattern
    xspi_hyper_cs_timing_setting_t const * p_cs_timing_settings;                    ///< Chip select bus timing settings
    xspi_hyper_address_space_t const     * p_address_space;                         ///< Memory mapped address space settings
    void * p_reg;                                                                   ///< Register base address for specified channel
};

/** Extended configuration Please refer to the struct st_xspi_hyper_extended_cfg. */
typedef struct st_xspi_hyper_extended_cfg xspi_hyper_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE. Initialization occurs when @ref RZT::hyperbus_api_t::open is called */
struct st_xspi_hyper_instance_ctrl
{
    uint32_t                 open;        // whether or not driver is open
    hyperbus_cfg_t const   * p_cfg;       // Pointer to initial configuration
    R_XSPI0_Type           * p_reg;       // Base register for this channel
    xspi_hyper_chip_select_t chip_select; // Device number to be used for memory device
};

/** Instance control block. DO NOT INITIALIZE. Initialization occurs when @ref RZT::hyperbus_api_t::open is called Please refer to the struct st_xspi_hyper_instance_ctrl. */
typedef struct st_xspi_hyper_instance_ctrl xspi_hyper_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const hyperbus_api_t g_hyperbus_on_xspi_hyper;

/** @endcond */

fsp_err_t R_XSPI_HYPER_Open(hyperbus_ctrl_t * p_ctrl, hyperbus_cfg_t const * const p_cfg);
fsp_err_t R_XSPI_HYPER_BurstTypeSet(hyperbus_ctrl_t * p_ctrl, hyperbus_burst_type_t burst_type);
fsp_err_t R_XSPI_HYPER_AccessSpaceSet(hyperbus_ctrl_t * p_ctrl, hyperbus_space_select_t access_space);
fsp_err_t R_XSPI_HYPER_DirectTransfer(hyperbus_ctrl_t * const p_ctrl, hyperbus_direct_transfer_t * const p_transfer);
fsp_err_t R_XSPI_HYPER_Write(hyperbus_ctrl_t     * p_ctrl,
                             uint8_t const * const p_src,
                             uint8_t * const       p_dest,
                             uint32_t              byte_count);
fsp_err_t R_XSPI_HYPER_Erase(hyperbus_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);
fsp_err_t R_XSPI_HYPER_StatusGet(hyperbus_ctrl_t * p_ctrl, hyperbus_status_t * const p_status);
fsp_err_t R_XSPI_HYPER_AutoCalibrate(hyperbus_ctrl_t * p_ctrl);
fsp_err_t R_XSPI_HYPER_Close(hyperbus_ctrl_t * p_ctrl);

/*******************************************************************************************************************//**
 * @} (end addtogroup XSPI_HYPER)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
