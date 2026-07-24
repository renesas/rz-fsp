/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_BSC_SDRAM_H
 #define R_BSC_SDRAM_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_bsc_sdram_cfg.h"
 #include "r_sdram_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSC_SDRAM
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Callback function parameter data. */
struct st_bsc_sdram_callback_args
{
    void * p_context;                  ///< Placeholder for user data.
};

/** Callback function parameter data. Please refer to the struct st_bsc_sdram_callback_args. */
typedef struct st_bsc_sdram_callback_args bsc_sdram_callback_args_t;

/** SDRAM chip select. */
typedef enum e_bsc_sdram_chip_select
{
    BSC_SDRAM_CHIP_SELECT_2_3 = 2,     ///< Device connected to Chip-Select 2 and 3
    BSC_SDRAM_CHIP_SELECT_3   = 3,     ///< Device connected to Chip-Select 3
} bsc_sdram_chip_select_t;

/** Number of insertion idle cycle between access cycles */
typedef enum e_bsc_sdram_idle_cycle
{
    BSC_SDRAM_IDLE_CYCLE_0 = 0x0,      ///< No idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_1,            ///< 1 idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_2,            ///< 2 idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_4,            ///< 4 idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_6,            ///< 6 idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_8,            ///< 8 idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_10,           ///< 10 idle cycle insertion
    BSC_SDRAM_IDLE_CYCLE_12,           ///< 12 idle cycle insertion
} bsc_sdram_idle_cycle_t;

/** Specify SDRAM command */
typedef enum e_bsc_sdram_command
{
    BSC_SDRAM_COMMAND_AUTO_PRECHARGE_MODE = 0x00,
    BSC_SDRAM_COMMAND_BANK_ACTIVE_MODE,
} bsc_sdram_command_t;

/** Specify SDRAM CS2 configuration */
struct st_bsc_sdram_cs2_settings
{
    sdram_data_bus_width_t    data_width;           ///< Select data bus width
    uint32_t                  cas_latency;          ///< CAS Latency cycle (tCL)
    sdram_address_bus_width_t row_address_width;    ///< Number of bits of SDRAM Row address
    sdram_address_bus_width_t column_address_width; ///< Number of bits of SDRAM Column address

    /** Idle cycle between Read-Read cycles in the same CS space */
    bsc_sdram_idle_cycle_t r_r_same_space_idle_cycle;

    /** Idle cycle between Read-Read cycles in the different CS space */
    bsc_sdram_idle_cycle_t r_r_different_space_idle_cycle;

    /** Idle cycle between Read-Write cycles in the same CS space */
    bsc_sdram_idle_cycle_t r_w_same_space_idle_cycle;

    /** Idle cycle between Read-Write cycles in the different CS space */
    bsc_sdram_idle_cycle_t r_w_different_space_idle_cycle;

    /** Idle cycle between Write-Read cycles and Write-Write cycles */
    bsc_sdram_idle_cycle_t w_r_w_w_idle_cycle;
};

/** Specify SDRAM CS2 configuration. Please refer to the struct st_bsc_sdram_cs2_settings. */
typedef struct st_bsc_sdram_cs2_settings bsc_sdram_cs2_settings_t;

/** Extended configuration. */
struct st_bsc_sdram_extended_cfg
{
    bsc_sdram_chip_select_t chip_select; ///< Select which device to use

    /** Idle cycle between Read-Read cycles in the same CS space */
    bsc_sdram_idle_cycle_t r_r_same_space_idle_cycle;

    /** Idle cycle between Read-Read cycles in the different CS space */
    bsc_sdram_idle_cycle_t r_r_different_space_idle_cycle;

    /** Idle cycle between Read-Write cycles in the same CS space */
    bsc_sdram_idle_cycle_t r_w_same_space_idle_cycle;

    /** Idle cycle between Read-Write cycles in the different CS space */
    bsc_sdram_idle_cycle_t r_w_different_space_idle_cycle;

    /** Idle cycle between Write-Read cycles and Write-Write cycles */
    bsc_sdram_idle_cycle_t w_r_w_w_idle_cycle;

    /** Auto-precharge mode (using READA/WRITA commands) or Bank active mode (using READ/WRIT commands) */
    bsc_sdram_command_t command_mode;

    uint8_t   cmi_ipl;                 ///< SDRAM refresh compare match interrupt
    IRQn_Type cmi_irq;                 ///< SDRAM refresh compare match interrupt priority

    /** CS2 SDRAM configuration */
    bsc_sdram_cs2_settings_t const * p_cs2_cfg;

    /** Callback for SDRAM refresh compare match. */
    void (* p_callback)(bsc_sdram_callback_args_t * p_args);

    /** Placeholder for user data.  Passed to the user callback in @ref bsc_sdram_callback_args_t. */
    void * p_context;
};

/** Extended configuration. Please refer to the struct st_bsc_sdram_extended_cfg. */
typedef struct st_bsc_sdram_extended_cfg bsc_sdram_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::sdram_api_t::open is called */
struct st_bsc_sdram_instance_ctrl
{
    uint32_t            open;                           // Whether or not driver is open
    sdram_cfg_t const * p_cfg;                          // Pointer to initial configuration

    void   (* p_callback)(bsc_sdram_callback_args_t *); // Pointer to callback that is called when a timer_event_t occurs.
    void * p_context;                                   // Pointer to context to be passed into callback function
};

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::sdram_api_t::open is called. Please refer to the struct st_bsc_sdram_instance_ctrl. */
typedef struct st_bsc_sdram_instance_ctrl bsc_sdram_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const sdram_api_t g_sdram_on_bsc_sdram;

/** @endcond */

fsp_err_t R_BSC_SDRAM_Open(sdram_ctrl_t * p_ctrl, sdram_cfg_t const * const p_cfg);
fsp_err_t R_BSC_SDRAM_SelfRefreshEnter(sdram_ctrl_t * p_ctrl);
fsp_err_t R_BSC_SDRAM_SelfRefreshExit(sdram_ctrl_t * p_ctrl);
fsp_err_t R_BSC_SDRAM_PowerDownEnter(sdram_ctrl_t * p_ctrl);
fsp_err_t R_BSC_SDRAM_PowerDownExit(sdram_ctrl_t * p_ctrl);
fsp_err_t R_BSC_SDRAM_Close(sdram_ctrl_t * p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup BSC_SDRAM)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
