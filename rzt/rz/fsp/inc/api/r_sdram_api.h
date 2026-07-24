/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_SYSTEM_INTERFACES
 * @defgroup SDRAM_API SDRAM Interface
 * @brief Interface for external sdram communication.
 *
 * @section SDRAM_API_SUMMARY Summary
 * The SDRAM interface provides APIs and definitions for SDRAM communication.
 *
 * @{
 **********************************************************************************************************************/
#ifndef R_SDRAM_API_H
#define R_SDRAM_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Register definitions, common services and error codes. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** SDRAM data bus width. */
typedef enum e_sdram_data_bus_width
{
    SDRAM_DATA_BUS_WIDTH_8BIT  = 0x01, ///< Data bus width 8bit
    SDRAM_DATA_BUS_WIDTH_16BIT = 0x02, ///< Data bus width 16bit
    SDRAM_DATA_BUS_WIDTH_32BIT = 0x03, ///< Data bus width 32bit
} sdram_data_bus_width_t;

/** Number of bits of SDRAM Row/Column address. */
typedef enum e_sdram_address_width
{
    SDRAM_ADDRESS_BUS_WIDTH_8_BITS  = 0x0, ///< Address bus width 8bit
    SDRAM_ADDRESS_BUS_WIDTH_9_BITS  = 0x1, ///< Address bus width 9bit
    SDRAM_ADDRESS_BUS_WIDTH_10_BITS = 0x2, ///< Address bus width 10bit
    SDRAM_ADDRESS_BUS_WIDTH_11_BITS = 0x3, ///< Address bus width 11bit
    SDRAM_ADDRESS_BUS_WIDTH_12_BITS = 0x4, ///< Address bus width 12bit
    SDRAM_ADDRESS_BUS_WIDTH_13_BITS = 0x5, ///< Address bus width 13bit
} sdram_address_bus_width_t;

/** Write burst mode */
typedef enum e_sdram_write_burst_mode
{
    SDRAM_WRITE_BURST_MODE_BURST  = 0x0U,  ///< Burst write setting
    SDRAM_WRITE_BURST_MODE_SINGLE = 0x01U, ///< Single write setting
} sdram_write_burst_mode_t;

/** SDRAM Refresh cycle clock source divisors */
typedef enum e_sdram_refresh_cycle_source_div
{
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_1    = 0,  ///< SDRAM Refresh cycle clock source divided by 1
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_2    = 1,  ///< SDRAM Refresh cycle clock source divided by 2
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_4    = 2,  ///< SDRAM Refresh cycle clock source divided by 4
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_8    = 3,  ///< SDRAM Refresh cycle clock source divided by 8
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_16   = 4,  ///< SDRAM Refresh cycle clock source divided by 16
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_32   = 5,  ///< SDRAM Refresh cycle clock source divided by 32
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_64   = 6,  ///< SDRAM Refresh cycle clock source divided by 64
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_128  = 7,  ///< SDRAM Refresh cycle clock source divided by 128
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_256  = 8,  ///< SDRAM Refresh cycle clock source divided by 256
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_512  = 9,  ///< SDRAM Refresh cycle clock source divided by 512
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_1024 = 10, ///< SDRAM Refresh cycle clock source divided by 1024
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_2048 = 11, ///< SDRAM Refresh cycle clock source divided by 2048
    SDRAM_REFRESH_CYCLE_SOURCE_DIV_4096 = 12, ///< SDRAM Refresh cycle clock source divided by 4096
} sdram_refresh_cycle_source_div_t;

/** SDRAM configuration */
typedef struct st_sdram_cfg
{
    sdram_data_bus_width_t data_width;              ///< Select data bus width

    sdram_address_bus_width_t row_address_width;    ///< Number of bits of SDRAM Row address
    sdram_address_bus_width_t column_address_width; ///< Number of bits of SDRAM Column address

    uint32_t ras_precharge_cycle;                   ///< Cycle between PRECHARGE and ACTIVE command (tRP)
    uint32_t ras_to_cas_delay_cycle;                ///< Cycle between ACTIVE and READ/WRITE command (tRCD)
    uint32_t cas_latency;                           ///< CAS Latency cycle (tCL)
    uint32_t write_recovery_cycle;                  ///< Cycle between Data In and PRECHARGE command (tWR)
    uint32_t row_cycle;                             ///< Cycle between REFRESH/ACTIVE and REFRESH/ACTIVE command (tRC)

    uint32_t auto_refresh_cycle;                    ///< Auto-Refresh cycle time
    sdram_refresh_cycle_source_div_t source_div;    ///< Auto-Refresh cycle clock source divider

    uint32_t refresh_request_count;                 ///< The number of continuous refresh cycles

    /** Select Burst Write or Single Write in MRS */
    sdram_write_burst_mode_t write_burst_mode;

    void const * p_extend;             ///< SDRAM hardware dependent configuration
} sdram_cfg_t;

/** SDRAM control block.  Allocate an instance specific control block to pass into the SDRAM API calls. */
typedef void sdram_ctrl_t;

/** SDRAM implementations follow this API. */
typedef struct st_sdram_api
{
    /** Open the SDRAM driver module.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     * @param[in] p_cfg                Pointer to a configuration structure
     **/
    fsp_err_t (* open)(sdram_ctrl_t * p_ctrl, sdram_cfg_t const * const p_cfg);

    /** Enter Self Refresh mode.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     **/
    fsp_err_t (* selfRefreshEnter)(sdram_ctrl_t * p_ctrl);

    /** Exit Self Refresh mode.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     **/
    fsp_err_t (* selfRefreshExit)(sdram_ctrl_t * p_ctrl);

    /** Enter Power Down mode.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     **/
    fsp_err_t (* powerDownEnter)(sdram_ctrl_t * p_ctrl);

    /** Exit Power Down mode.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     **/
    fsp_err_t (* powerDownExit)(sdram_ctrl_t * p_ctrl);

    /** Close the SDRAM driver module.
     *
     * @param[in] p_ctrl               Pointer to a driver handle
     **/
    fsp_err_t (* close)(sdram_ctrl_t * p_ctrl);
} sdram_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_sdram_instance
{
    sdram_ctrl_t      * p_ctrl;        ///< Pointer to the control structure for this instance
    sdram_cfg_t const * p_cfg;         ///< Pointer to the configuration structure for this instance
    sdram_api_t const * p_api;         ///< Pointer to the API structure for this instance
} sdram_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/******************************************************************************************************************//**
 * @} (end defgroup SDRAM_API)
 **********************************************************************************************************************/
