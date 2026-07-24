/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_BSC_H
 #define R_BSC_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_bsc_cfg.h"
 #include "r_external_bus_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** BSC callback event definitions  */
typedef enum e_bsc_event
{
    BSC_EVENT_EXTERNAL_WAIT_TIMEOUT,   ///< External wait timeout detection.
} bsc_event_t;

/** Memory type connected to a CS space */
typedef enum e_bsc_memory_type
{
    BSC_MEMORY_TYPE_SRAM = 0x00,       ///< Normal space (SRAM)
} bsc_memory_type_t;

/** Number of insertion idle cycle between access cycles */
typedef enum e_bsc_idle_cycle
{
    BSC_IDLE_CYCLE_0 = 0x0,            ///< No idle cycle insertion
    BSC_IDLE_CYCLE_1,                  ///< 1 idle cycle insertion
    BSC_IDLE_CYCLE_2,                  ///< 2 idle cycle insertion
    BSC_IDLE_CYCLE_4,                  ///< 4 idle cycle insertion
    BSC_IDLE_CYCLE_6,                  ///< 6 idle cycle insertion
    BSC_IDLE_CYCLE_8,                  ///< 8 idle cycle insertion
    BSC_IDLE_CYCLE_10,                 ///< 10 idle cycle insertion
    BSC_IDLE_CYCLE_12,                 ///< 12 idle cycle insertion
} bsc_idle_cycle_t;

/** Number of insertion access wait cycle */
typedef enum e_bsc_access_wait_cycle
{
    BSC_ACCESS_WAIT_CYCLE_0 = 0x00,                   ///< No wait insertion
    BSC_ACCESS_WAIT_CYCLE_1,                          ///< 1 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_2,                          ///< 2 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_3,                          ///< 3 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_4,                          ///< 4 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_5,                          ///< 5 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_6,                          ///< 6 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_8,                          ///< 8 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_10,                         ///< 10 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_12,                         ///< 12 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_14,                         ///< 14 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_18,                         ///< 18 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_24,                         ///< 24 access wait cycle insertion
    BSC_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS = 0xFF, ///< Insert the same weight cycle when read access (Used only for Write access wait settings)
} bsc_access_wait_cycle_t;

/** Number of insertion CS wait cycle */
typedef enum e_bsc_cs_wait_cycle_t
{
    BSC_CS_WAIT_CYCLE_0_5,             ///< CS wait 0.5 cycle insertion
    BSC_CS_WAIT_CYCLE_1_5,             ///< CS wait 1.5 cycle insertion
    BSC_CS_WAIT_CYCLE_2_5,             ///< CS wait 2.5 cycle insertion
    BSC_CS_WAIT_CYCLE_3_5,             ///< CS wait 3.5 cycle insertion
} bsc_cs_wait_cycle_t;

/** External wait timeout detection setting */
typedef enum e_bsc_external_wait_timeout
{
    BSC_EXTERNAL_WAIT_TIMEOUT_DISABLE = 0x00, ///< External WAIT timeout detection disable
    BSC_EXTERNAL_WAIT_TIMEOUT_ENABLE  = 0x01, ///< External WAIT timeout detection enable
} bsc_external_wait_timeout_t;

/** Callback function parameter data. */
struct st_bsc_callback_args
{
    bsc_event_t event;                 ///< BSC callback event
    void      * p_context;             ///< Placeholder for user data.
};

/** Callback function parameter data. Please refer to the struct st_bsc_callback_args. */
typedef struct st_bsc_callback_args bsc_callback_args_t;

/** Extended configuration. */
struct st_bsc_extended_cfg
{
    bsc_memory_type_t memory_type;                            ///< Configure memory type

    bsc_idle_cycle_t r_r_same_space_idle_cycle;               ///< Idle cycle between Read-Read cycles in the same CS space
    bsc_idle_cycle_t r_r_different_space_idle_cycle;          ///< Idle cycle between Read-Read cycles in the different CS space
    bsc_idle_cycle_t r_w_same_space_idle_cycle;               ///< Idle cycle between Read-Write cycles in the same CS space
    bsc_idle_cycle_t r_w_different_space_idle_cycle;          ///< Idle cycle between Read-Write cycles in the different CS space
    bsc_idle_cycle_t w_r_w_w_idle_cycle;                      ///< Idle cycle between Write-Read cycles and Write-Write cycles

    bsc_access_wait_cycle_t read_access_wait_cycle;           ///< Number of read access cycle waits
    bsc_access_wait_cycle_t write_access_wait_cycle;          ///< Number of write access cycle waits

    bsc_cs_wait_cycle_t cs_pullup_lag;                        ///< Duration to de-assert CS line after RD#,WE# de-assert
    bsc_cs_wait_cycle_t cs_pulldown_lead;                     ///< Duration to assert CS line before RD#,WE# assert

    bsc_external_wait_timeout_t external_wait_timeout_enable; ///< External wait timeout enable/disable setting
    uint32_t external_wait_timeout_counts;                    ///< External wait timeout cycle

    void (* p_callback)(bsc_callback_args_t * p_args);        ///< Callback for external wait timeout detection interrupt.

    void * p_context;                                         ///< Placeholder for user data.  Passed to the user p_callback in RZN::bsc_callback_args_t.
};

/** Extended configuration. Please refer to the struct st_bsc_extended_cfg. */
typedef struct st_bsc_extended_cfg bsc_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZN::external_bus_api_t::open is called */
struct st_bsc_instance_ctrl
{
    uint32_t open;                              // Whether or not driver is open
    external_bus_cfg_t const * p_cfg;           // Pointer to initial configuration

    void (* p_callback)(bsc_callback_args_t *); // Pointer to callback
    bsc_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void                * p_context;            // Pointer to context to be passed into callback function
};

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZN::external_bus_api_t::open is called. Please refer to the struct st_bsc_instance_ctrl. */
typedef struct st_bsc_instance_ctrl bsc_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const external_bus_api_t g_external_bus_on_bsc;

/** @endcond */

fsp_err_t R_BSC_Open(external_bus_ctrl_t * p_ctrl, external_bus_cfg_t const * const p_cfg);
fsp_err_t R_BSC_Close(external_bus_ctrl_t * p_ctrl);
fsp_err_t R_BSC_CallbackSet(external_bus_ctrl_t       * p_ctrl,
                            void (                    * p_callback)(bsc_callback_args_t *),
                            void * const                p_context,
                            bsc_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup BSC)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
