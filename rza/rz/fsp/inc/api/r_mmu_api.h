/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_SYSTEM_INTERFACES
 * @defgroup MMU_API Memory Managing Unit Interface
 * @brief Interface for Memory Managing Unit(MMU) functions.
 *
 * @section MMU_API_SUMMARY Summary
 * The MMU interface provides functions for initializing and modifying virtual memory page tables.
 *
 * @{
 **********************************************************************************************************************/

#ifndef R_MMU_API_H
#define R_MMU_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Common error codes and definitions. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define R_MMU_PG_ATTRIBUTE_NORMAL_CACHEABLE    (MMU_PG_DESC_AF | MMU_PG_DESC_SH_IS | MMU_PG_DESC_AP_RW_RW | \
                                                MMU_PG_DESC_MEMATTR_0)
#define R_MMU_PG_ATTRIBUTE_NORMAL_UNCACHE      (MMU_PG_DESC_AF | MMU_PG_DESC_SH_IS | MMU_PG_DESC_AP_RW_RW | \
                                                MMU_PG_DESC_MEMATTR_2)
#define R_MMU_PG_ATTRIBUTE_DEVICE              (MMU_PG_DESC_AF | MMU_PG_DESC_SH_IS | MMU_PG_DESC_AP_RW_RW | \
                                                MMU_PG_DESC_MEMATTR_1)
#define R_MMU_PG_ATTRIBUTE_ACCESS_FAULT        (0x00000000)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef struct st_mmu_table_info
{
    uint32_t table_level;              ///< Level of the page table
    uint64_t table_base_ptr;           ///< Base address of the page table
    uint64_t table_base_addr;          ///< Start address(virtual) handled by the page table
} mmu_table_info_t;

typedef struct st_mmu_section_info
{
    uint64_t vaddress;                 ///< Virtual address
    uint32_t paddress;                 ///< Physical address to map virtual address
    uint32_t size;                     ///< Size from vaddress (byte)
    uint64_t attribute;                ///< Memory attribute of page table entry
} mmu_section_info_t;

/** Page table configuration data for loading by R_MMU_Open()  */
typedef struct st_mmu_cfg
{
    /* Not used: for future expansion */
    const void * p_extend;             ///< Pointer to hardware extend configuration
} mmu_cfg_t;

/** MMU control block.  Allocate an instance specific control block to pass into the MMU API calls.
 */
typedef void mmu_ctrl_t;

/** MMU driver structure. MMU functions implemented at the HAL layer will follow this API. */
typedef struct st_mmu_api
{
    /** Initialize internal driver data. Called during startup.  Do not call this API during runtime.
     *
     * @param[in]  p_ctrl          Pointer to control structure.
     * @param[in]  p_cfg           Pointer to page table configuration data.
     */
    fsp_err_t (* open)(mmu_ctrl_t * const p_ctrl, const mmu_cfg_t * p_cfg);

    /** Close the API.
     *
     * @param[in]   p_ctrl  Pointer to control structure.
     **/
    fsp_err_t (* close)(mmu_ctrl_t * const p_ctrl);

    /** Initialize buffer for new page table region.
     *
     * @param[in]  p_ctrl          Pointer to control structure.
     * @param[in]  table_level     MMU page table level.
     * @param[in]  table_base_ptr  buffer address.
     **/
    fsp_err_t (* allocateTable)(mmu_ctrl_t * const p_ctrl, uint32_t table_level, uint64_t table_base_ptr);

    /** Write page table entries as next page table link.
     *
     * @param[in]   p_ctrl                Pointer to control structure.
     * @param[in]   p_table_info          Page table information.
     * @param[in]   vaddress              Base virtual address of page table.
     * @param[in]   next_table_base_adder Pointer to page table buffer.
     **/
    fsp_err_t (* writeTableLink)(mmu_ctrl_t * const p_ctrl, mmu_table_info_t * p_table_info, uint64_t vaddress,
                                 uint64_t next_table_base_ptr);

    /** Fill page table entries with specified attribute.
     *
     * @param[in]   p_ctrl                Pointer to control structure.
     * @param[in]   p_table_info          Page table information.
     * @param[in]   p_section_info        Section descripter information.
     **/
    fsp_err_t (* writeTable)(mmu_ctrl_t * const p_ctrl, mmu_table_info_t * p_table_info,
                             mmu_section_info_t * p_section_info);

    /** Fill page table entries with acccess fault attribute.
     *
     * @param[in]   p_ctrl  Pointer to control structure.
     * @param[in]   p_table_info          Page table information.
     * @param[in]   p_section_info        Section descripter information.
     **/
    fsp_err_t (* writeTableFault)(mmu_ctrl_t * const p_ctrl, mmu_table_info_t * p_table_info,
                                  mmu_section_info_t * p_section_info);
} mmu_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_mmu_instance
{
    mmu_ctrl_t      * p_ctrl;          ///< Pointer to the control structure for this instance
    mmu_cfg_t const * p_cfg;           ///< Pointer to the configuration structure for this instance
    mmu_api_t const * p_api;           ///< Pointer to the API structure for this instance
} mmu_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/*******************************************************************************************************************//**
 * @} (end defgroup MMU_API)
 **********************************************************************************************************************/
