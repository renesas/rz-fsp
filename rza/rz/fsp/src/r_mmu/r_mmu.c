/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_mmu.h"

extern uint64_t * __ttbr0_base;
extern uint64_t * __level2_table_1_base;
extern uint64_t * __level2_table_2_base;
extern uint64_t * __level2_table_3_base;
extern uint64_t * __level2_table_4_base;

extern r_mmu_pgtbl_cfg_t g_mmu_pagetable_array[];

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define R_MMU_PA_STRIDE_LEVEL_1       (0x40000000) /* 1GB */
#define R_MMU_PA_STRIDE_LEVEL_2       (0x00200000) /* 2MB */
#define R_MMU_PA_STRIDE_LEVEL_3       (0x00001000) /* 4KB */

#define R_MMU_PG_DESC_SIZE            (8)

#define R_MMU_TTBR0_ADDR_MASK         (0xFFFFFFFC)
#define R_MMU_PGTBL_ADDR_MASK         (0xFFFFFFFC)

#define R_MMU_N1_TABLE_START_VADDR    (0x00000000)
#define R_MMU_N2_TABLE_START_VADDR    (0x40000000)
#define R_MMU_N3_TABLE_START_VADDR    (0x80000000)
#define R_MMU_N4_TABLE_START_VADDR    (0xC0000000)

#define R_MMU_PG_ATTR_NEXT_TBL        (0x00000003)

#define R_MMU_CONFIG_TABLE_END        (0xFFFFFFFF)

static void mmu_table_write_64(volatile uint64_t * entry, uint64_t write_value);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* MMU Implementation of MMU Driver  */
const mmu_api_t g_mmu_on_mmu =
{
    .open            = R_MMU_Open,
    .close           = R_MMU_Close,
    .allocateTable   = R_MMU_AllocateTable,
    .writeTableLink  = R_MMU_WriteTableLink,
    .writeTable      = R_MMU_WriteTable,
    .writeTableFault = R_MMU_WriteTableFault,
};

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
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes whole of MMU page table.
 *
 * @retval FSP_SUCCESS                  Initialized Page Table.
 * @retval FSP_ERR_INVALID_ARGUMENT     Illegal parameter.
 **********************************************************************************************************************/
fsp_err_t R_MMU_Open (mmu_ctrl_t * const p_api_ctrl, mmu_cfg_t const * const p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;

    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_cfg);

    uint32_t         cfg_index;
    mmu_table_info_t table_info;

    R_MMU_SetTranslationTableBaseAddress(p_api_ctrl, (uint32_t) (((uint64_t) &__ttbr0_base) | 0x01));

    /* Set level1 table */
    table_info.table_level     = MMU_TABLE_LEVEL_1;
    table_info.table_base_ptr  = (uint64_t) &__ttbr0_base;
    table_info.table_base_addr = 0x00000000;

    R_MMU_WriteTableLink(p_api_ctrl, &table_info, R_MMU_N1_TABLE_START_VADDR, (uint64_t) &__level2_table_1_base);
    R_MMU_WriteTableLink(p_api_ctrl, &table_info, R_MMU_N2_TABLE_START_VADDR, (uint64_t) &__level2_table_2_base);
    R_MMU_WriteTableLink(p_api_ctrl, &table_info, R_MMU_N3_TABLE_START_VADDR, (uint64_t) &__level2_table_3_base);
    R_MMU_WriteTableLink(p_api_ctrl, &table_info, R_MMU_N4_TABLE_START_VADDR, (uint64_t) &__level2_table_4_base);

    /* Set level2 tables */
    table_info.table_level = MMU_TABLE_LEVEL_2;

    for (cfg_index = 0; R_MMU_CONFIG_TABLE_END != g_mmu_pagetable_array[cfg_index].attribute; cfg_index++)
    {
        mmu_section_info_t section_info;

        section_info.vaddress  = g_mmu_pagetable_array[cfg_index].vaddress;
        section_info.paddress  = (uint32_t) g_mmu_pagetable_array[cfg_index].paddress;
        section_info.size      = (uint32_t) g_mmu_pagetable_array[cfg_index].size;
        section_info.attribute = g_mmu_pagetable_array[cfg_index].attribute;

        if (R_MMU_N2_TABLE_START_VADDR > section_info.vaddress)
        {
            table_info.table_base_ptr  = (uint64_t) &__level2_table_1_base;
            table_info.table_base_addr = R_MMU_N1_TABLE_START_VADDR;
        }
        else if (R_MMU_N3_TABLE_START_VADDR > section_info.vaddress)
        {
            table_info.table_base_ptr  = (uint64_t) &__level2_table_2_base;
            table_info.table_base_addr = R_MMU_N2_TABLE_START_VADDR;
        }
        else if (R_MMU_N4_TABLE_START_VADDR > section_info.vaddress)
        {
            table_info.table_base_ptr  = (uint64_t) &__level2_table_3_base;
            table_info.table_base_addr = R_MMU_N3_TABLE_START_VADDR;
        }
        else
        {
            table_info.table_base_ptr  = (uint64_t) &__level2_table_4_base;
            table_info.table_base_addr = R_MMU_N4_TABLE_START_VADDR;
        }

        if (0x00000000 == section_info.attribute)
        {
            /* set access fault */
            R_MMU_WriteTableFault(p_api_ctrl, &table_info, &section_info);
        }
        else
        {
            /* set attribute */
            R_MMU_WriteTable(p_api_ctrl, &table_info, &section_info);
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * Close the MMU driver.
 *
 * @retval FSP_SUCCESS          Close the MMU
 **********************************************************************************************************************/
fsp_err_t R_MMU_Close (mmu_ctrl_t * const p_api_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;

    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return err;
}

/*******************************************************************************************************************//**
 * Initializes specified MMU page table.
 *
 * @retval FSP_ERR_UNSUPPORTED                  Will be supported in a future version.
 **********************************************************************************************************************/
fsp_err_t R_MMU_AllocateTable (mmu_ctrl_t * const p_api_ctrl, uint32_t table_level, uint64_t table_base_ptr)
{
    (void) table_level;
    (void) table_base_ptr;
    fsp_err_t ret = FSP_ERR_UNSUPPORTED;

    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    return ret;
}

/*******************************************************************************************************************//**
 * Write page table entries as next page table link.
 *
 * @retval FSP_SUCCESS                  Successfully updated page table link.
 * @retval FSP_ERR_INVALID_ARGUMENT     Illegal parameter.
 **********************************************************************************************************************/
fsp_err_t R_MMU_WriteTableLink (mmu_ctrl_t * const p_api_ctrl,
                                mmu_table_info_t * p_table_info,
                                uint64_t           vaddress,
                                uint64_t           next_table_base_ptr)
{
    fsp_err_t ret        = FSP_SUCCESS;
    uint64_t  offset     = 0;
    uint64_t  descriptor = 0;

    FSP_PARAMETER_NOT_USED(p_api_ctrl);

#if MMU_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_table_info != NULL, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_table_info->table_level <= MMU_TABLE_LEVEL_2, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_table_info->table_base_addr <= vaddress, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(((MMU_TABLE_LEVEL_1 == p_table_info->table_level) && (0 == (vaddress % 0x40000000))) ||
                     ((MMU_TABLE_LEVEL_2 == p_table_info->table_level) && (0 == (vaddress % 0x00200000))),
                     FSP_ERR_INVALID_ARGUMENT);
#endif

    /* Calculate page offset */
    if (MMU_TABLE_LEVEL_1 == p_table_info->table_level)
    {
        offset = ((vaddress - p_table_info->table_base_addr) / R_MMU_PA_STRIDE_LEVEL_1) * R_MMU_PG_DESC_SIZE;
    }
    else
    {
        offset = ((vaddress - p_table_info->table_base_addr) / R_MMU_PA_STRIDE_LEVEL_2) * R_MMU_PG_DESC_SIZE;
    }

    /* Make attribute bits */
    descriptor = (next_table_base_ptr | R_MMU_PG_ATTR_NEXT_TBL);

    /* Write Page Entry */
    mmu_table_write_64((uint64_t *) (p_table_info->table_base_ptr + offset), descriptor);

    return ret;
}

/*******************************************************************************************************************//**
 * Fill page table entries with specified attribute.
 *
 * @retval FSP_SUCCESS                  Successfully updated page table.
 * @retval FSP_ERR_INVALID_ARGUMENT     Illegal parameter.
 **********************************************************************************************************************/
fsp_err_t R_MMU_WriteTable (mmu_ctrl_t * const   p_api_ctrl,
                            mmu_table_info_t   * p_table_info,
                            mmu_section_info_t * p_section_info)
{
    int32_t    i;
    int32_t    num_of_desc;
    int32_t    table_index;
    uint64_t * pg_desc_ptr;
    uint32_t   pa_stride;

    FSP_PARAMETER_NOT_USED(p_api_ctrl);

#if MMU_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_table_info != NULL, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_table_info->table_level <= MMU_TABLE_LEVEL_3, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_table_info->table_base_addr <= p_section_info->vaddress, FSP_ERR_INVALID_ARGUMENT);
#endif

    if (MMU_TABLE_LEVEL_1 == p_table_info->table_level)
    {
        p_section_info->attribute |= MMU_PG_DESC_SEC_L12;
        pa_stride                  = R_MMU_PA_STRIDE_LEVEL_1;
    }
    else if (MMU_TABLE_LEVEL_2 == p_table_info->table_level)
    {
        p_section_info->attribute |= MMU_PG_DESC_SEC_L12;
        pa_stride                  = R_MMU_PA_STRIDE_LEVEL_2;
    }
    else                               /* MMU_TABLE_LEVEL_3 */
    {
        p_section_info->attribute |= MMU_PG_DESC_SEC_L3;
        pa_stride                  = R_MMU_PA_STRIDE_LEVEL_3;
    }

#if MMU_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN((p_section_info->vaddress % pa_stride) == 0, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_section_info->paddress % pa_stride) == 0, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_section_info->size % pa_stride) == 0, FSP_ERR_INVALID_ARGUMENT);
#endif

    num_of_desc = (int32_t) (p_section_info->size / pa_stride);
    table_index = (int32_t) ((p_section_info->vaddress - p_table_info->table_base_addr) / pa_stride);
    pg_desc_ptr = (uint64_t *) (p_table_info->table_base_ptr + ((uint64_t) (table_index * R_MMU_PG_DESC_SIZE)));

    for (i = 0; i < num_of_desc; i++)
    {
        *pg_desc_ptr++            = p_section_info->paddress | p_section_info->attribute;
        p_section_info->paddress += pa_stride;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Fill page table entries with acccess fault attribute.
 *
 * @retval FSP_SUCCESS                  Successfully updated page table.
 * @retval FSP_ERR_INVALID_ARGUMENT     Illegal parameter.
 **********************************************************************************************************************/
fsp_err_t R_MMU_WriteTableFault (mmu_ctrl_t * const   p_api_ctrl,
                                 mmu_table_info_t   * p_table_info,
                                 mmu_section_info_t * p_section_info)
{
    int32_t    i;
    int32_t    num_of_desc;
    int32_t    table_index;
    uint64_t * pg_desc_ptr;
    uint32_t   pa_stride;

    FSP_PARAMETER_NOT_USED(p_api_ctrl);

#if MMU_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN(p_table_info != NULL, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_table_info->table_level <= MMU_TABLE_LEVEL_3, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_table_info->table_base_addr <= p_section_info->vaddress, FSP_ERR_INVALID_ARGUMENT);
#endif

    if (MMU_TABLE_LEVEL_1 == p_table_info->table_level)
    {
        pa_stride = R_MMU_PA_STRIDE_LEVEL_1;
    }
    else if (MMU_TABLE_LEVEL_2 == p_table_info->table_level)
    {
        pa_stride = R_MMU_PA_STRIDE_LEVEL_2;
    }
    else                               /* MMU_TABLE_LEVEL_3 */
    {
        pa_stride = R_MMU_PA_STRIDE_LEVEL_3;
    }

#if MMU_CFG_PARAM_CHECKING_ENABLE
    FSP_ERROR_RETURN((p_section_info->vaddress % pa_stride) == 0, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_section_info->size % pa_stride) == 0, FSP_ERR_INVALID_ARGUMENT);
#endif

    num_of_desc = (int32_t) (p_section_info->size / pa_stride);
    table_index = (int32_t) ((p_section_info->vaddress - p_table_info->table_base_addr) / pa_stride);
    pg_desc_ptr = (uint64_t *) (p_table_info->table_base_ptr + ((uint64_t) (table_index * R_MMU_PG_DESC_SIZE)));

    for (i = 0; i < num_of_desc; i++)
    {
        mmu_table_write_64(pg_desc_ptr, 0);
        pg_desc_ptr++;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup MMU)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * page table 64-bit write
 *
 * @param[in]   * entry            page table entry for writing
 * @param[in]   write_value        Write value for the IO register
 *
 * @retval      None.
 *********************************************************************************************************************/
static void mmu_table_write_64 (volatile uint64_t * entry, uint64_t write_value)
{
    *entry = write_value;
}
