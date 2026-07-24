/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_MMU_H
 #define R_MMU_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_mmu_cfg.h"
 #include "r_mmu_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

typedef enum e_mmu_talbe_level
{
    MMU_TABLE_LEVEL_0 = 0,
    MMU_TABLE_LEVEL_1 = 1,
    MMU_TABLE_LEVEL_2 = 2,
    MMU_TABLE_LEVEL_3 = 3,
} mmu_talbe_level_t;

 #define    MMU_PG_DESC_XN            (1 << 54UL)
 #define    MMU_PG_DESC_PXN           (1 << 53UL)
 #define    MMU_PG_DESC_CONT          (1 << 52UL)
 #define    MMU_PG_DESC_DBM           (1 << 51UL)
 #define    MMU_PG_DESC_GP            (1 << 50UL)
 #define    MMU_PG_DESC_NT            (1 << 16UL)
 #define    MMU_PG_DESC_NG            (1 << 11UL)
 #define    MMU_PG_DESC_AF            (1 << 10UL)
 #define    MMU_PG_DESC_SH_NS         (0 << 8UL)
 #define    MMU_PG_DESC_SH_OS         (2 << 8UL)
 #define    MMU_PG_DESC_SH_IS         (3 << 8UL)
 #define    MMU_PG_DESC_AP_RW_NONE    (0 << 6UL)
 #define    MMU_PG_DESC_AP_RW_RW      (1 << 6UL)
 #define    MMU_PG_DESC_AP_RO_NONE    (2 << 6UL)
 #define    MMU_PG_DESC_AP_RO_RO      (3 << 6UL)
 #define    MMU_PG_DESC_NS            (1 << 5UL)
 #define    MMU_PG_DESC_MEMATTR_0     (0 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_1     (1 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_2     (2 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_3     (3 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_4     (4 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_5     (5 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_6     (6 << 2UL)
 #define    MMU_PG_DESC_MEMATTR_7     (7 << 2UL)
 #define    MMU_PG_DESC_SEC_L12       (1 << 0UL)
 #define    MMU_PG_DESC_SEC_L3        (3 << 0UL)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZA
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_MMU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
struct st_mmu_instance_ctrl
{
    uint32_t          open;            // Whether or not channel is open
    const mmu_cfg_t * p_cfg;           // Pointer to initial configurations
};

/** Please refer to the struct st_mmu_instance_ctrl. */
typedef struct st_mmu_instance_ctrl mmu_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const mmu_api_t g_mmu_on_mmu;

/** @endcond */

fsp_err_t R_MMU_Open(mmu_ctrl_t * const p_api_ctrl, mmu_cfg_t const * const p_cfg);
fsp_err_t R_MMU_Close(mmu_ctrl_t * const p_api_ctrl);

/* base address of the translation table */
fsp_err_t R_MMU_GetTranslationTableBaseAddress(mmu_ctrl_t * const p_api_ctrl, uint32_t * p_address);
fsp_err_t R_MMU_SetTranslationTableBaseAddress(mmu_ctrl_t * const p_api_ctrl, uint32_t address);
fsp_err_t R_MMU_AllocateTable(mmu_ctrl_t * const p_api_ctrl, uint32_t table_level, uint64_t table_base_ptr);
fsp_err_t R_MMU_WriteTableLink(mmu_ctrl_t * const p_api_ctrl,
                               mmu_table_info_t * p_table_info,
                               uint64_t           vaddress,
                               uint64_t           next_table_base_ptr);
fsp_err_t R_MMU_WriteTable(mmu_ctrl_t * const   p_api_ctrl,
                           mmu_table_info_t   * p_table_info,
                           mmu_section_info_t * p_section_info);
fsp_err_t R_MMU_WriteTableFault(mmu_ctrl_t * const   p_api_ctrl,
                                mmu_table_info_t   * p_table_info,
                                mmu_section_info_t * p_section_info);

fsp_err_t R_MMU_VAtoPA(mmu_ctrl_t * const p_api_ctrl, uint64_t vaddress, uint64_t * p_paddress);
fsp_err_t R_MMU_PAtoVA(mmu_ctrl_t * const p_api_ctrl, uint64_t paddress, uint64_t * p_vaddress);

/*******************************************************************************************************************//**
 * @} (end defgroup MMU)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER

#endif                                 /* R_MMU_H */
