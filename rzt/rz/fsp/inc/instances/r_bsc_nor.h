/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_BSC_NOR_H
 #define R_BSC_NOR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_bsc_nor_cfg.h"
 #include "r_nor_flash_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSC_NOR
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Store CFI query result of Flash memory sector block information. */
struct st_bsc_nor_region_info
{
    uint32_t sector_size;
    uint32_t sector_number;
};

/** Store CFI query result of Flash memory sector block information. Please refer to the struct st_bsc_nor_region_info. */
typedef struct st_bsc_nor_region_info bsc_nor_block_info_t;

/** Number of insertion idle cycle between access cycles */
typedef enum e_bsc_nor_idle_cycle
{
    BSC_NOR_IDLE_CYCLE_0 = 0x0,        ///< No idle cycle insertion
    BSC_NOR_IDLE_CYCLE_1,              ///< 1 idle cycle insertion
    BSC_NOR_IDLE_CYCLE_2,              ///< 2 idle cycle insertion
    BSC_NOR_IDLE_CYCLE_4,              ///< 4 idle cycle insertion
    BSC_NOR_IDLE_CYCLE_6,              ///< 6 idle cycle insertion
    BSC_NOR_IDLE_CYCLE_8,              ///< 8 idle cycle insertion
    BSC_NOR_IDLE_CYCLE_10,             ///< 10 idle cycle insertion
    BSC_NOR_IDLE_CYCLE_12,             ///< 12 idle cycle insertion
} bsc_nor_idle_cycle_t;

/** Number of insertion access wait cycle */
typedef enum e_bsc_nor_access_wait_cycle
{
    BSC_NOR_ACCESS_WAIT_CYCLE_0 = 0x00,                   ///< No wait insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_1,                          ///< 1 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_2,                          ///< 2 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_3,                          ///< 3 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_4,                          ///< 4 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_5,                          ///< 5 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_6,                          ///< 6 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_8,                          ///< 8 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_10,                         ///< 10 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_12,                         ///< 12 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_14,                         ///< 14 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_18,                         ///< 18 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_24,                         ///< 24 access wait cycle insertion
    BSC_NOR_ACCESS_WAIT_CYCLE_SAME_AS_READ_ACCESS = 0xFF, ///< Insert the same weight cycle when read access (Used only for Write access wait settings)
} bsc_nor_access_wait_cycle_t;

/** Number of insertion CS wait cycle */
typedef enum e_bsc_nor_cs_wait_cycle_t
{
    BSC_NOR_CS_WAIT_CYCLE_0_5,         ///< CS wait 0.5 cycle insertion
    BSC_NOR_CS_WAIT_CYCLE_1_5,         ///< CS wait 1.5 cycle insertion
    BSC_NOR_CS_WAIT_CYCLE_2_5,         ///< CS wait 2.5 cycle insertion
    BSC_NOR_CS_WAIT_CYCLE_3_5,         ///< CS wait 3.5 cycle insertion
} bsc_nor_cs_wait_cycle_t;

/** External address space */
typedef enum e_bsc_nor_memory_space
{
    BSC_NOR_MEMORY_SPACE_CS,           ///< External address space CSn
    BSC_NOR_MEMORY_SPACE_CS_MIRROR,    ///< Mirror area of External address space CSn
} bsc_nor_memory_space_t;

/** Extended configuration. */
struct st_bsc_nor_extended_cfg
{
    /** Idle cycle between Read-Read cycles in the same CS space */
    bsc_nor_idle_cycle_t r_r_same_space_idle_cycle;

    /** Idle cycle between Read-Read cycles in the different CS space */
    bsc_nor_idle_cycle_t r_r_different_space_idle_cycle;

    /** Idle cycle between Read-Write cycles in the same CS space */
    bsc_nor_idle_cycle_t r_w_same_space_idle_cycle;

    /** Idle cycle between Read-Write cycles in the different CS space */
    bsc_nor_idle_cycle_t r_w_different_space_idle_cycle;

    /** Idle cycle between Write-Read cycles and Write-Write cycles */
    bsc_nor_idle_cycle_t w_r_w_w_idle_cycle;

    bsc_nor_access_wait_cycle_t read_access_wait_cycle;  ///< Number of read access cycle waits
    bsc_nor_access_wait_cycle_t write_access_wait_cycle; ///< Number of write access cycle waits

    bsc_nor_cs_wait_cycle_t cs_pullup_lag;               ///< Duration to de-assert CS line after RD#,WE# de-assert
    bsc_nor_cs_wait_cycle_t cs_pulldown_lead;            ///< Duration to assert CS line before RD#,WE# assert

    bsc_nor_memory_space_t initial_access_memory_space;  ///< Initial access memory space in nor_flash_api_t::open.
};

/** Extended configuration. Please refer to the struct st_bsc_nor_extended_cfg. */
typedef struct st_bsc_nor_extended_cfg bsc_nor_extended_cfg_t;

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::nor_flash_api_t::open is called */
struct st_bsc_nor_instance_ctrl
{
    uint32_t                open;        // Whether or not driver is open
    nor_flash_cfg_t const * p_cfg;       // Pointer to initial configuration
    void * p_cs_base;                    // Pointer to using CS area

    bsc_nor_block_info_t * p_block_info; // Pointer to store block information obtained by CFI Query
    uint32_t               block_number; // The number of regions in the device obtained by CFI Query
};

/** Instance control block. DO NOT INITIALIZE.  Initialization occurs when @ref RZT::nor_flash_api_t::open is called. Please refer to the struct st_bsc_nor_instance_ctrl. */
typedef struct st_bsc_nor_instance_ctrl bsc_nor_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const nor_flash_api_t g_nor_flash_on_bsc_nor;

/** @endcond */

fsp_err_t R_BSC_NOR_Open(nor_flash_ctrl_t * p_ctrl, nor_flash_cfg_t const * const p_cfg);
fsp_err_t R_BSC_NOR_Write(nor_flash_ctrl_t    * p_ctrl,
                          uint8_t const * const p_src,
                          uint8_t * const       p_dest,
                          uint32_t              byte_count);
fsp_err_t R_BSC_NOR_Erase(nor_flash_ctrl_t * p_ctrl, uint8_t * const p_device_address, uint32_t byte_count);
fsp_err_t R_BSC_NOR_StatusGet(nor_flash_ctrl_t         * p_ctrl,
                              uint8_t * const            p_device_address,
                              nor_flash_status_t * const p_status);
fsp_err_t R_BSC_NOR_Close(nor_flash_ctrl_t * p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup BSC_NOR)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
