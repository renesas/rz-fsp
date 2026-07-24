/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_mmu_core.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_MMU_CONVERSION_SUCCESS                              (0ULL)
#define BSP_PRV_MMU_CONVERSION_FAULT                                (1ULL)
#define BSP_PRV_MMU_CONVERSION_FAULT_MASK                           (1ULL << 0)
#define BSP_PRV_MMU_LOWER_PHYSICAL_ADDRESS_MASK                     (0x0000000000000FFFULL)
#define BSP_PRV_MMU_UPPER_PHYSICAL_ADDRESS_MASK                     (0x000FFFFFFFFFF000ULL)

#define BSP_PRV_MMU_TABLE_REGION_MASK                               (1ULL << 0)
#define BSP_PRV_MMU_TABLE_ATTRINDX_MASK                             (7ULL << 2)
#define BSP_PRV_MMU_TABLE_ATTRINDX_SHIFT                            (2)
#define BSP_PRV_MMU_MAIR_ATTR_OFFSET                                (8ULL)
#define BSP_PRV_MMU_MAIR_ATTR_MASK                                  (0xFFULL)
#define BSP_PRV_MMU_MAIR_ATTR_UPPER_MASK                            (0xF0ULL)
#define BSP_PRV_MMU_MAIR_ATTR_LOWER_MASK                            (0x0FULL)
#define BSP_PRV_MMU_MAIR_DEVICE_MEMORY                              (0x00ULL)
#define BSP_PRV_MMU_MAIR_NORMAL_MEMORY_OUTER_INNER_NON_CACHEABLE    (0x4ULL << 4 | 0x4ULL << 0)

#define BSP_PRV_MMU_INDEX_MASK                                      (0xFFFF)
#define BSP_PRV_ATTRINDEX_NO_MATCH                                  (0xFFU)

#define BSP_PRV_MMU_TARGET_DYNAMIC                                  (1)
#define BSP_PRV_MMU_TARGET_STATIC                                   (0)

#if   ((BSP_CFG_CPU_MPU_ATTR0_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR0_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR0_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX0)

#elif ((BSP_CFG_CPU_MPU_ATTR1_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR1_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR1_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX1)

#elif ((BSP_CFG_CPU_MPU_ATTR2_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR2_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR2_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX2)

#elif ((BSP_CFG_CPU_MPU_ATTR3_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR3_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR3_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX3)

#elif ((BSP_CFG_CPU_MPU_ATTR4_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR4_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR4_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX4)

#elif ((BSP_CFG_CPU_MPU_ATTR5_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR5_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR5_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX5)

#elif ((BSP_CFG_CPU_MPU_ATTR6_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR6_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR6_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX6)

#elif ((BSP_CFG_CPU_MPU_ATTR7_TYPE == BSP_TYPE_NORMAL_MEMORY) && \
    (BSP_CFG_CPU_MPU_ATTR7_INNER == BSP_NON_CACHEABLE) && (BSP_CFG_CPU_MPU_ATTR7_OUTER == BSP_NON_CACHEABLE))

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_ATTRINDEX7)

#else

 #define BSP_PRV_MMU_NOCACHE_ATTRIBUTE                              (BSP_PRV_ATTRINDEX_NO_MATCH)

#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_bsp_mmu_talbe_level
{
    BSP_MMU_TABLE_LEVEL_0 = 0,
    BSP_MMU_TABLE_LEVEL_1 = 1,
    BSP_MMU_TABLE_LEVEL_2 = 2,
    BSP_MMU_TABLE_LEVEL_3 = 3,
} bsp_mmu_talbe_level_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
uint64_t g_mmu_ttbr0_base[BSP_MMU_LEVEL2_TABLE_INDEX_MAX +
                          28] BSP_ALIGN_VARIABLE(BSP_MMU_TABLE_ALIGN) BSP_PLACE_IN_SECTION(BSP_SECTION_MMU_TABLE_SECTION);
uint64_t g_mmu_level2_table_1_base[BSP_MMU_TABLE_ENTRY]   BSP_ALIGN_VARIABLE(BSP_MMU_TABLE_ALIGN)
BSP_PLACE_IN_SECTION(BSP_SECTION_MMU_TABLE_SECTION);
uint64_t g_mmu_level2_table_2_base[BSP_MMU_TABLE_ENTRY]   BSP_ALIGN_VARIABLE(BSP_MMU_TABLE_ALIGN)
BSP_PLACE_IN_SECTION(BSP_SECTION_MMU_TABLE_SECTION);
uint64_t g_mmu_level2_table_3_base[BSP_MMU_TABLE_ENTRY]   BSP_ALIGN_VARIABLE(BSP_MMU_TABLE_ALIGN)
BSP_PLACE_IN_SECTION(BSP_SECTION_MMU_TABLE_SECTION);
uint64_t g_mmu_level2_table_4_base[BSP_MMU_TABLE_ENTRY]   BSP_ALIGN_VARIABLE(BSP_MMU_TABLE_ALIGN)
BSP_PLACE_IN_SECTION(BSP_SECTION_MMU_TABLE_SECTION);

r_mmu_pgtbl_cfg_t const g_mmu_pagetable_array[] =
{
    {BSP_CFG_EL3_MMU_REGION00_VADDR, BSP_CFG_EL3_MMU_REGION00_PADDR, BSP_CFG_EL3_MMU_REGION00_SIZE,
     EL3_MMU_REGIONXX_DATA(00)},       /* Region 00 */
    {BSP_CFG_EL3_MMU_REGION01_VADDR, BSP_CFG_EL3_MMU_REGION01_PADDR, BSP_CFG_EL3_MMU_REGION01_SIZE,
     EL3_MMU_REGIONXX_DATA(01)},       /* Region 01 */
    {BSP_CFG_EL3_MMU_REGION02_VADDR, BSP_CFG_EL3_MMU_REGION02_PADDR, BSP_CFG_EL3_MMU_REGION02_SIZE,
     EL3_MMU_REGIONXX_DATA(02)},       /* Region 02 */
    {BSP_CFG_EL3_MMU_REGION03_VADDR, BSP_CFG_EL3_MMU_REGION03_PADDR, BSP_CFG_EL3_MMU_REGION03_SIZE,
     EL3_MMU_REGIONXX_DATA(03)},       /* Region 03 */
    {BSP_CFG_EL3_MMU_REGION04_VADDR, BSP_CFG_EL3_MMU_REGION04_PADDR, BSP_CFG_EL3_MMU_REGION04_SIZE,
     EL3_MMU_REGIONXX_DATA(04)},       /* Region 04 */
    {BSP_CFG_EL3_MMU_REGION05_VADDR, BSP_CFG_EL3_MMU_REGION05_PADDR, BSP_CFG_EL3_MMU_REGION05_SIZE,
     EL3_MMU_REGIONXX_DATA(05)},       /* Region 05 */
    {BSP_CFG_EL3_MMU_REGION06_VADDR, BSP_CFG_EL3_MMU_REGION06_PADDR, BSP_CFG_EL3_MMU_REGION06_SIZE,
     EL3_MMU_REGIONXX_DATA(06)},       /* Region 06 */
    {BSP_CFG_EL3_MMU_REGION07_VADDR, BSP_CFG_EL3_MMU_REGION07_PADDR, BSP_CFG_EL3_MMU_REGION07_SIZE,
     EL3_MMU_REGIONXX_DATA(07)},       /* Region 07 */
    {BSP_CFG_EL3_MMU_REGION08_VADDR, BSP_CFG_EL3_MMU_REGION08_PADDR, BSP_CFG_EL3_MMU_REGION08_SIZE,
     EL3_MMU_REGIONXX_DATA(08)},       /* Region 08 */
    {BSP_CFG_EL3_MMU_REGION09_VADDR, BSP_CFG_EL3_MMU_REGION09_PADDR, BSP_CFG_EL3_MMU_REGION09_SIZE,
     EL3_MMU_REGIONXX_DATA(09)},       /* Region 09 */
    {BSP_CFG_EL3_MMU_REGION10_VADDR, BSP_CFG_EL3_MMU_REGION10_PADDR, BSP_CFG_EL3_MMU_REGION10_SIZE,
     EL3_MMU_REGIONXX_DATA(10)},       /* Region 10 */
    {BSP_CFG_EL3_MMU_REGION11_VADDR, BSP_CFG_EL3_MMU_REGION11_PADDR, BSP_CFG_EL3_MMU_REGION11_SIZE,
     EL3_MMU_REGIONXX_DATA(11)},       /* Region 11 */
    {BSP_CFG_EL3_MMU_REGION12_VADDR, BSP_CFG_EL3_MMU_REGION12_PADDR, BSP_CFG_EL3_MMU_REGION12_SIZE,
     EL3_MMU_REGIONXX_DATA(12)},       /* Region 12 */
    {BSP_CFG_EL3_MMU_REGION13_VADDR, BSP_CFG_EL3_MMU_REGION13_PADDR, BSP_CFG_EL3_MMU_REGION13_SIZE,
     EL3_MMU_REGIONXX_DATA(13)},       /* Region 13 */
    {BSP_CFG_EL3_MMU_REGION14_VADDR, BSP_CFG_EL3_MMU_REGION14_PADDR, BSP_CFG_EL3_MMU_REGION14_SIZE,
     EL3_MMU_REGIONXX_DATA(14)},       /* Region 14 */
    {BSP_CFG_EL3_MMU_REGION15_VADDR, BSP_CFG_EL3_MMU_REGION15_PADDR, BSP_CFG_EL3_MMU_REGION15_SIZE,
     EL3_MMU_REGIONXX_DATA(15)},       /* Region 15 */
    {BSP_CFG_EL3_MMU_REGION16_VADDR, BSP_CFG_EL3_MMU_REGION16_PADDR, BSP_CFG_EL3_MMU_REGION16_SIZE,
     EL3_MMU_REGIONXX_DATA(16)},       /* Region 16 */
    {BSP_CFG_EL3_MMU_REGION17_VADDR, BSP_CFG_EL3_MMU_REGION17_PADDR, BSP_CFG_EL3_MMU_REGION17_SIZE,
     EL3_MMU_REGIONXX_DATA(17)},       /* Region 17 */
    {BSP_CFG_EL3_MMU_REGION18_VADDR, BSP_CFG_EL3_MMU_REGION18_PADDR, BSP_CFG_EL3_MMU_REGION18_SIZE,
     EL3_MMU_REGIONXX_DATA(18)},       /* Region 18 */
    {BSP_CFG_EL3_MMU_REGION19_VADDR, BSP_CFG_EL3_MMU_REGION19_PADDR, BSP_CFG_EL3_MMU_REGION19_SIZE,
     EL3_MMU_REGIONXX_DATA(19)},       /* Region 19 */
    {BSP_CFG_EL3_MMU_REGION20_VADDR, BSP_CFG_EL3_MMU_REGION20_PADDR, BSP_CFG_EL3_MMU_REGION20_SIZE,
     EL3_MMU_REGIONXX_DATA(20)},       /* Region 20 */
    {BSP_CFG_EL3_MMU_REGION21_VADDR, BSP_CFG_EL3_MMU_REGION21_PADDR, BSP_CFG_EL3_MMU_REGION21_SIZE,
     EL3_MMU_REGIONXX_DATA(21)},       /* Region 21 */
    {BSP_CFG_EL3_MMU_REGION22_VADDR, BSP_CFG_EL3_MMU_REGION22_PADDR, BSP_CFG_EL3_MMU_REGION22_SIZE,
     EL3_MMU_REGIONXX_DATA(22)},       /* Region 22 */
    {BSP_CFG_EL3_MMU_REGION23_VADDR, BSP_CFG_EL3_MMU_REGION23_PADDR, BSP_CFG_EL3_MMU_REGION23_SIZE,
     EL3_MMU_REGIONXX_DATA(23)},       /* Region 23 */
    {BSP_CFG_EL3_MMU_REGION24_VADDR, BSP_CFG_EL3_MMU_REGION24_PADDR, BSP_CFG_EL3_MMU_REGION24_SIZE,
     EL3_MMU_REGIONXX_DATA(24)},       /* Region 24 */
    {BSP_CFG_EL3_MMU_REGION25_VADDR, BSP_CFG_EL3_MMU_REGION25_PADDR, BSP_CFG_EL3_MMU_REGION25_SIZE,
     EL3_MMU_REGIONXX_DATA(25)},       /* Region 25 */
    {BSP_CFG_EL3_MMU_REGION26_VADDR, BSP_CFG_EL3_MMU_REGION26_PADDR, BSP_CFG_EL3_MMU_REGION26_SIZE,
     EL3_MMU_REGIONXX_DATA(26)},       /* Region 26 */
    {BSP_CFG_EL3_MMU_REGION27_VADDR, BSP_CFG_EL3_MMU_REGION27_PADDR, BSP_CFG_EL3_MMU_REGION27_SIZE,
     EL3_MMU_REGIONXX_DATA(27)},       /* Region 27 */
    {BSP_CFG_EL3_MMU_REGION28_VADDR, BSP_CFG_EL3_MMU_REGION28_PADDR, BSP_CFG_EL3_MMU_REGION28_SIZE,
     EL3_MMU_REGIONXX_DATA(28)},       /* Region 28 */
    {BSP_CFG_EL3_MMU_REGION29_VADDR, BSP_CFG_EL3_MMU_REGION29_PADDR, BSP_CFG_EL3_MMU_REGION29_SIZE,
     EL3_MMU_REGIONXX_DATA(29)},       /* Region 29 */
    {BSP_CFG_EL3_MMU_REGION30_VADDR, BSP_CFG_EL3_MMU_REGION30_PADDR, BSP_CFG_EL3_MMU_REGION30_SIZE,
     EL3_MMU_REGIONXX_DATA(30)},       /* Region 30 */
    {BSP_CFG_EL3_MMU_REGION31_VADDR, BSP_CFG_EL3_MMU_REGION31_PADDR, BSP_CFG_EL3_MMU_REGION31_SIZE,
     EL3_MMU_REGIONXX_DATA(31)},       /* Region 31 */
    {BSP_CFG_EL3_MMU_REGION32_VADDR, BSP_CFG_EL3_MMU_REGION32_PADDR, BSP_CFG_EL3_MMU_REGION32_SIZE,
     EL3_MMU_REGIONXX_DATA(32)},       /* Region 32 */
    {BSP_CFG_EL3_MMU_REGION33_VADDR, BSP_CFG_EL3_MMU_REGION33_PADDR, BSP_CFG_EL3_MMU_REGION33_SIZE,
     EL3_MMU_REGIONXX_DATA(33)},       /* Region 33 */
    {BSP_CFG_EL3_MMU_REGION34_VADDR, BSP_CFG_EL3_MMU_REGION34_PADDR, BSP_CFG_EL3_MMU_REGION34_SIZE,
     EL3_MMU_REGIONXX_DATA(34)},       /* Region 34 */
    {BSP_CFG_EL3_MMU_REGION35_VADDR, BSP_CFG_EL3_MMU_REGION35_PADDR, BSP_CFG_EL3_MMU_REGION35_SIZE,
     EL3_MMU_REGIONXX_DATA(35)},       /* Region 35 */
    {BSP_CFG_EL3_MMU_REGION36_VADDR, BSP_CFG_EL3_MMU_REGION36_PADDR, BSP_CFG_EL3_MMU_REGION36_SIZE,
     EL3_MMU_REGIONXX_DATA(36)},       /* Region 36 */
    {BSP_CFG_EL3_MMU_REGION37_VADDR, BSP_CFG_EL3_MMU_REGION37_PADDR, BSP_CFG_EL3_MMU_REGION37_SIZE,
     EL3_MMU_REGIONXX_DATA(37)},       /* Region 37 */
    {BSP_CFG_EL3_MMU_REGION38_VADDR, BSP_CFG_EL3_MMU_REGION38_PADDR, BSP_CFG_EL3_MMU_REGION38_SIZE,
     EL3_MMU_REGIONXX_DATA(38)},       /* Region 38 */
    {BSP_CFG_EL3_MMU_REGION39_VADDR, BSP_CFG_EL3_MMU_REGION39_PADDR, BSP_CFG_EL3_MMU_REGION39_SIZE,
     EL3_MMU_REGIONXX_DATA(39)},       /* Region 39 */
    {BSP_CFG_EL3_MMU_REGION40_VADDR, BSP_CFG_EL3_MMU_REGION40_PADDR, BSP_CFG_EL3_MMU_REGION40_SIZE,
     EL3_MMU_REGIONXX_DATA(40)},       /* Region 40 */
    {BSP_CFG_EL3_MMU_REGION41_VADDR, BSP_CFG_EL3_MMU_REGION41_PADDR, BSP_CFG_EL3_MMU_REGION41_SIZE,
     EL3_MMU_REGIONXX_DATA(41)},       /* Region 41 */
    {BSP_CFG_EL3_MMU_REGION42_VADDR, BSP_CFG_EL3_MMU_REGION42_PADDR, BSP_CFG_EL3_MMU_REGION42_SIZE,
     EL3_MMU_REGIONXX_DATA(42)},       /* Region 42 */
    {BSP_CFG_EL3_MMU_REGION43_VADDR, BSP_CFG_EL3_MMU_REGION43_PADDR, BSP_CFG_EL3_MMU_REGION43_SIZE,
     EL3_MMU_REGIONXX_DATA(43)},       /* Region 43 */
    {BSP_CFG_EL3_MMU_REGION44_VADDR, BSP_CFG_EL3_MMU_REGION44_PADDR, BSP_CFG_EL3_MMU_REGION44_SIZE,
     EL3_MMU_REGIONXX_DATA(44)},       /* Region 44 */
    {BSP_CFG_EL3_MMU_REGION45_VADDR, BSP_CFG_EL3_MMU_REGION45_PADDR, BSP_CFG_EL3_MMU_REGION45_SIZE,
     EL3_MMU_REGIONXX_DATA(45)},       /* Region 45 */
    {BSP_CFG_EL3_MMU_REGION46_VADDR, BSP_CFG_EL3_MMU_REGION46_PADDR, BSP_CFG_EL3_MMU_REGION46_SIZE,
     EL3_MMU_REGIONXX_DATA(46)},       /* Region 46 */
    {BSP_CFG_EL3_MMU_REGION47_VADDR, BSP_CFG_EL3_MMU_REGION47_PADDR, BSP_CFG_EL3_MMU_REGION47_SIZE,
     EL3_MMU_REGIONXX_DATA(47)}        /* Region 47 */
};

r_mmu_pgtbl_cfg_t g_mmu_dynamic_cfg = {0};

uint8_t g_mmu_invalid_static_index[BSP_MMU_TOTAL_REGION];
uint8_t g_mmu_invalid_static_num = 0;

uint8_t g_mmu_dynamic_flag     = false;
uint8_t g_mmu_chg_shareble_flg = false;

static void bsp_mmu_writetablelink(st_mmu_table_info_t * p_table_info, uint64_t vaddress, uint64_t next_table_base_ptr);
static void bsp_mmu_writetable(st_mmu_table_info_t * p_table_info, r_mmu_pgtbl_cfg_t * p_section_info);
static void bsp_mmu_disable_region(const r_mmu_pgtbl_cfg_t * mmu_region_cfg);
static void bsp_mmu_config_region(const r_mmu_pgtbl_cfg_t * mmu_region_cfg);
static void bsp_mmu_set_region(const r_mmu_pgtbl_cfg_t * mmu_region_cfg);

static void      bsp_mmu_ttbr_refresh(void);
static fsp_err_t bsp_mmu_adjust_dynamic_region(void);

static fsp_err_t bsp_mmu_check_valid_vaddress(uint64_t                  paddress,
                                              uint64_t                * p_vaddress,
                                              const r_mmu_pgtbl_cfg_t * g_mmu_taget_info,
                                              uint8_t                   target_mmu_type);

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZN
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Convert virtual address into physical address.
 *
 * @param[in]  vaddress          Virtual address to convert.
 * @param[out] p_paddress        Pointer to store physical address.
 * @retval FSP_SUCCESS           Successful
 * @retval FSP_ERR_INVALID_ADDRESS         Virtual address is invalid address.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MmuVatoPa (uint64_t vaddress, uint64_t * p_paddress)
{
    fsp_err_t err = FSP_SUCCESS;

    uint64_t par_el1_r = 0;
    uint64_t par_el1_w = 0;

    /* Get the physical address from bit47 to bit12. */
    __asm volatile (
        "AT S1E3R, %1 \n"
        "MRS %0, PAR_EL1"
        : "=r" (par_el1_r)
        : "r"  (vaddress)
        : "memory");

    __asm volatile (
        "AT S1E3W, %1 \n"
        "MRS %0, PAR_EL1"
        : "=r" (par_el1_w)
        : "r"  (vaddress)
        : "memory");

    /* Get the physical address from bit11 to bit0 and combines it with the physical address of the upper bits.  */
    if (BSP_PRV_MMU_CONVERSION_SUCCESS == (par_el1_r & BSP_PRV_MMU_CONVERSION_FAULT_MASK))
    {
        *p_paddress = (par_el1_r & BSP_PRV_MMU_UPPER_PHYSICAL_ADDRESS_MASK) +
                      (vaddress & BSP_PRV_MMU_LOWER_PHYSICAL_ADDRESS_MASK);
    }
    else if (BSP_PRV_MMU_CONVERSION_SUCCESS == (par_el1_w & BSP_PRV_MMU_CONVERSION_FAULT_MASK))
    {
        *p_paddress = (par_el1_w & BSP_PRV_MMU_UPPER_PHYSICAL_ADDRESS_MASK) +
                      (vaddress & BSP_PRV_MMU_LOWER_PHYSICAL_ADDRESS_MASK);
    }
    else
    {
        err = FSP_ERR_INVALID_ADDRESS;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Convert physical address into virtual address.
 *
 * @param[in]  paddress          Physical address to convert.
 * @param[out] p_vaddress        Pointer to store virtual address.
 * @param[in]  cache_flag        Cache flag to select VA.
 * @retval FSP_SUCCESS           Successful
 * @retval FSP_ERR_INVALID_ADDRESS         Physical address is invalid address.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MmuPatoVa (uint64_t paddress, uint64_t * p_vaddress, bsp_mmu_conversion_flag_t cache_flag)
{
    fsp_err_t                 err = FSP_SUCCESS;
    uint32_t                  cfg_index;
    uint8_t                   target_mmu_type;
    const r_mmu_pgtbl_cfg_t * g_mmu_taget_info;

    if (true == g_mmu_dynamic_flag)
    {
        target_mmu_type = BSP_PRV_MMU_TARGET_DYNAMIC;
    }
    else
    {
        target_mmu_type = BSP_PRV_MMU_TARGET_STATIC;
    }

    /* Search for the region number of the address to be converted */
    cfg_index = 0;
    while (cfg_index < BSP_MMU_TOTAL_REGION)
    {
        r_mmu_pgtbl_cfg_t section_info;

        /* Determine whether the target area is a static area or a dynamic area. */
        if (BSP_PRV_MMU_TARGET_DYNAMIC == target_mmu_type)
        {
            g_mmu_taget_info = &g_mmu_dynamic_cfg;
        }
        else
        {
            g_mmu_taget_info = &g_mmu_pagetable_array[cfg_index];
        }

        /* Get attribute on the region from the MMU table. */
        section_info.attribute = g_mmu_taget_info->attribute;

        /* Check the region enable. */
        if (BSP_PRV_MMU_TABLE_REGION_MASK & section_info.attribute)
        {
            /* Get address information on the region from the MMU table. */
            section_info.vaddress = g_mmu_taget_info->vaddress;
            section_info.paddress = g_mmu_taget_info->paddress;
            section_info.size     = g_mmu_taget_info->size;

            /* Check if the specified physical address is included in the target region. */
            if ((section_info.paddress <= paddress) && ((section_info.paddress + section_info.size) > paddress))
            {
                /* Get the attributes for that region. */
                uint64_t mair    = __get_MAIR();
                uint64_t attr_no =
                    ((section_info.attribute & BSP_PRV_MMU_TABLE_ATTRINDX_MASK) >> BSP_PRV_MMU_TABLE_ATTRINDX_SHIFT);
                uint64_t mair_shift  = (attr_no * BSP_PRV_MMU_MAIR_ATTR_OFFSET);
                uint64_t region_mair = (mair >> mair_shift) & BSP_PRV_MMU_MAIR_ATTR_MASK;

                /* If the cache attribute for that region matches the cache attribute set in cache_flag,
                 * the for statement loop branches. */
                if ((BSP_PRV_MMU_MAIR_DEVICE_MEMORY != (region_mair & BSP_PRV_MMU_MAIR_ATTR_UPPER_MASK)) &&
                    (BSP_PRV_MMU_MAIR_DEVICE_MEMORY != (region_mair & BSP_PRV_MMU_MAIR_ATTR_LOWER_MASK)))
                {
                    if (BSP_PRV_MMU_MAIR_NORMAL_MEMORY_OUTER_INNER_NON_CACHEABLE == region_mair)
                    {
                        if (BSP_MMU_CONVERSION_NON_CACHE == cache_flag)
                        {
                            if (FSP_SUCCESS ==
                                bsp_mmu_check_valid_vaddress(paddress, p_vaddress, g_mmu_taget_info, target_mmu_type))
                            {
                                break;
                            }
                        }
                        else
                        {
                            /* Do nothing. */
                        }
                    }
                    else
                    {
                        if (BSP_MMU_CONVERSION_CACHE == cache_flag)
                        {
                            if (FSP_SUCCESS ==
                                bsp_mmu_check_valid_vaddress(paddress, p_vaddress, g_mmu_taget_info, target_mmu_type))
                            {
                                break;
                            }
                        }
                        else
                        {
                            /* Do nothing. */
                        }
                    }
                }
            }
        }

        if (BSP_PRV_MMU_TARGET_DYNAMIC == target_mmu_type)
        {
            target_mmu_type = BSP_PRV_MMU_TARGET_STATIC;
        }
        else
        {
            cfg_index++;
        }
    }

    /* If the search fails, return FSP_ERR_INVALID_ADDRESS. */
    if (BSP_MMU_TOTAL_REGION <= cfg_index)
    {
        err = FSP_ERR_INVALID_ADDRESS;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Change the setting of Memory Map in run-time
 *
 * @param[in]  p_memory_map_cfg          Pointer to configuration memory map
 *
 * @retval     FSP_SUCCESS               No configuration errors detected
 * @retval     FSP_ERR_IN_USE            Dynamic configuration is in use.
 * @retval     FSP_ERR_INVALID_ARGUMENT  Invalid input configuration
 **********************************************************************************************************************/
fsp_err_t R_BSP_MemoryMap (r_mmu_pgtbl_cfg_t * p_memory_map_cfg)
{
    uint64_t  dynamic_region_base;
    uint64_t  dynamic_region_limit;
    fsp_err_t err;

#if BSP_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_memory_map_cfg);
    FSP_ASSERT(0 != p_memory_map_cfg->size);

    FSP_ERROR_RETURN((p_memory_map_cfg->vaddress >= BSP_MMU_N5_TABLE_START_VADDR) ||
                     ((p_memory_map_cfg->vaddress + p_memory_map_cfg->size) <= BSP_MMU_N5_TABLE_START_VADDR),
                     FSP_ERR_INVALID_ARGUMENT);
#endif
    FSP_ERROR_RETURN(true != g_mmu_dynamic_flag, FSP_ERR_IN_USE);

    g_mmu_chg_shareble_flg   = false;
    g_mmu_invalid_static_num = 0;

    g_mmu_dynamic_cfg.vaddress  = p_memory_map_cfg->vaddress;
    g_mmu_dynamic_cfg.paddress  = p_memory_map_cfg->paddress;
    g_mmu_dynamic_cfg.size      = p_memory_map_cfg->size;
    g_mmu_dynamic_cfg.attribute = p_memory_map_cfg->attribute | BSP_AF_BLOCK_USED;

    err = bsp_mmu_adjust_dynamic_region();
    if (FSP_SUCCESS != err)
    {
        return err;
    }

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    dynamic_region_base  = g_mmu_dynamic_cfg.vaddress;
    dynamic_region_limit = dynamic_region_base + g_mmu_dynamic_cfg.size - 1;

    /* Range overlap check with static region. */
    for (uint8_t region_id = 0; region_id < BSP_MMU_TOTAL_REGION; region_id++)
    {
        if (0 != g_mmu_pagetable_array[region_id].size)
        {
            uint64_t static_region_base  = g_mmu_pagetable_array[region_id].vaddress;
            uint64_t static_region_limit = static_region_base + g_mmu_pagetable_array[region_id].size - 1;

            /* In case of region configuration with non-overlapping */
            if ((dynamic_region_base > static_region_limit) || (dynamic_region_limit < static_region_base))
            {
                /* Skip the non-overlap region*/
            }
            else                       /* In the case of region overlapping */
            {
                g_mmu_invalid_static_index[g_mmu_invalid_static_num++] = region_id;

                if ((dynamic_region_base >= static_region_base) && (dynamic_region_limit <= static_region_limit))
                {
                    break;
                }
            }
        }
    }

    /* Clear cache in advance for areas to be prohibited. */
    R_BSP_CacheCleanInvalidateAll();

    for (uint8_t i = 0; i < g_mmu_invalid_static_num; i++)
    {
        uint8_t           mmu_disabled_id = g_mmu_invalid_static_index[i];
        r_mmu_pgtbl_cfg_t mmu_region_cfg  = g_mmu_pagetable_array[mmu_disabled_id];

        if (BSP_PRV_MMU_TABLE_REGION_MASK & mmu_region_cfg.attribute)
        {
            /* When changing Shareble, set the cache to be disabled in advance. */
            if ((mmu_region_cfg.attribute & BSP_SHAREABLE_MASK) != (g_mmu_dynamic_cfg.attribute & BSP_SHAREABLE_MASK))
            {
#if (BSP_PRV_MMU_NOCACHE_ATTRIBUTE != BSP_PRV_ATTRINDEX_NO_MATCH)
                g_mmu_chg_shareble_flg = true;

                /* Change memory attributes to cache disabled and Outer Shareable. */
                mmu_region_cfg = g_mmu_dynamic_cfg;
                bsp_mmu_disable_region(&mmu_region_cfg);

                mmu_region_cfg.attribute &= (~BSP_SHAREABLE_MASK) & (~BSP_ATTRINDEX_MASK);
                mmu_region_cfg.attribute |= (BSP_PRV_MMU_NOCACHE_ATTRIBUTE | BSP_OUTER_SHAREABLE);
                bsp_mmu_config_region(&mmu_region_cfg);

                /* Clear IRGN and ORGN bit */
                __set_TCR((uint64_t) BSP_MMU_TCR_INVALID_CACHE);

                /* Performs cache cleaning and invalidation on the TLB tables. */
                R_BSP_CacheCleanInvalidateAll();

                /* Set IRGN and ORGN bit */
                __set_TCR((uint64_t) BSP_MMU_TCR);

                break;
#else
                FSP_CRITICAL_SECTION_EXIT;

                return FSP_ERR_INVALID_ARGUMENT;
#endif
            }
        }
    }

    /* Replace the old translation table entry with an invalid entry.*/
    /* Disabled the setting of all dynamically configured MMUs */
    /* Clear cache in advance for areas to be prohibited. */
    bsp_mmu_disable_region(&g_mmu_dynamic_cfg);

    /* Write the new translation table entry, and execute a DSB instruction to ensure that the new entry is visible. */
    bsp_mmu_config_region(&g_mmu_dynamic_cfg);

    g_mmu_dynamic_flag = true;

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Canceling memory mapping settings
 *
 * @retval     FSP_SUCCESS               No configuration errors detected.
 * @retval     FSP_ERR_NOT_INITIALIZED   Memory map configuration has not beeen initialized yet.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MemoryUnMap (void)
{
    FSP_ERROR_RETURN(true == g_mmu_dynamic_flag, FSP_ERR_NOT_INITIALIZED);

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Clear cache in advance for areas to be prohibited. */
    R_BSP_CacheCleanInvalidateAll();

    if (true == g_mmu_chg_shareble_flg)
    {
        /* When changing Shareble, set the cache to be disabled in advance. */
        g_mmu_dynamic_cfg.attribute &= (~BSP_SHAREABLE_MASK) & (~BSP_ATTRINDEX_MASK);
        g_mmu_dynamic_cfg.attribute |= (BSP_PRV_MMU_NOCACHE_ATTRIBUTE | BSP_OUTER_SHAREABLE);

        bsp_mmu_config_region(&g_mmu_dynamic_cfg);
    }

    /* Disabled the setting of all dynamically configured MMUs */
    bsp_mmu_disable_region(&g_mmu_dynamic_cfg);

    /* Execute TLB invalidation instruction. */
    __asm volatile (
        "TLBI ALLE3                             \n" /* Cortex-A55 I-TLB and D-TLB invalidation (TLBIALL) */
        ::: "memory");

    /* Write the new translation table entry, and execute a DSB instruction to ensure that the new entry is visible. */
    /* Restore static MMU setting */
    bsp_mmu_configure();
    bsp_mmu_ttbr_refresh();

    /* Execute DSB instruction. */
    __DSB();

    g_mmu_dynamic_flag       = false;
    g_mmu_invalid_static_num = 0;

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_MCU)
 **********************************************************************************************************************/
#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/*******************************************************************************************************************//**
 * Determining whether the value after virtual address translation is valid.
 *
 * @param[in]  paddress          Physical address to convert.
 * @param[out] p_vaddress        Pointer to store virtual address.
 * @param[in]  g_mmu_taget_info  Target mmu infomation.
 * @param[in]  target_mmu_type   Target mmu type.
 * @retval FSP_SUCCESS           Successful
 * @retval FSP_ERR_INVALID_ADDRESS         Physical address is invalid address.
 **********************************************************************************************************************/
static fsp_err_t bsp_mmu_check_valid_vaddress (uint64_t                  paddress,
                                               uint64_t                * p_vaddress,
                                               const r_mmu_pgtbl_cfg_t * g_mmu_taget_info,
                                               uint8_t                   target_mmu_type)
{
    fsp_err_t err             = FSP_SUCCESS;
    uint64_t  region_vaddress = g_mmu_taget_info->vaddress;
    uint64_t  region_paddress = g_mmu_taget_info->paddress;
    uint64_t  cal_vaddress    = region_vaddress + (paddress - region_paddress);

    if ((BSP_PRV_MMU_TARGET_DYNAMIC == target_mmu_type) || (false == g_mmu_dynamic_flag) ||
        ((g_mmu_dynamic_cfg.vaddress > cal_vaddress) ||
         ((g_mmu_dynamic_cfg.vaddress + g_mmu_dynamic_cfg.size) <= cal_vaddress)))
    {
        *p_vaddress = cal_vaddress;
    }
    else
    {
        err = FSP_ERR_INVALID_ADDRESS;
    }

    return err;
}

/*******************************************************************************************************************//**
 * Configure MMU settings.
 **********************************************************************************************************************/
void bsp_mmu_configure (void)
{
    uint32_t            cfg_index;
    st_mmu_table_info_t table_info;

    __set_TTBR0((uint32_t) (((uint64_t) &g_mmu_ttbr0_base) | 0x01));

    /* Set level1 table */
    table_info.table_level     = BSP_MMU_TABLE_LEVEL_1;
    table_info.table_base_ptr  = (uint64_t) &g_mmu_ttbr0_base;
    table_info.table_base_addr = 0x00000000;

    bsp_mmu_writetablelink(&table_info, BSP_MMU_N1_TABLE_START_VADDR, (uint64_t) &g_mmu_level2_table_1_base);
    bsp_mmu_writetablelink(&table_info, BSP_MMU_N2_TABLE_START_VADDR, (uint64_t) &g_mmu_level2_table_2_base);
    bsp_mmu_writetablelink(&table_info, BSP_MMU_N3_TABLE_START_VADDR, (uint64_t) &g_mmu_level2_table_3_base);
    bsp_mmu_writetablelink(&table_info, BSP_MMU_N4_TABLE_START_VADDR, (uint64_t) &g_mmu_level2_table_4_base);

    for (cfg_index = 0; cfg_index < BSP_MMU_TOTAL_REGION; cfg_index++)
    {
        bsp_mmu_set_region(&g_mmu_pagetable_array[cfg_index]);
    }

    uint64_t mair = 0;
    mair = ((uint64_t) ATTR_3_2_1_0 | ((uint64_t) ATTR_7_6_5_4 << 32U));

    __set_MAIR(mair);

    __set_TCR((uint64_t) BSP_MMU_TCR);
}

/*******************************************************************************************************************//**
 * Write page table entries as next page table link.
 *  @param[in]     p_table_info  The table information to set a descriptor.
 *  @param[in]     vaddress  Starting address of level 1 table.
 *  @param[in]     next_table_base_ptr  Base address for level 2 table.
 **********************************************************************************************************************/
static void bsp_mmu_writetablelink (st_mmu_table_info_t * p_table_info, uint64_t vaddress, uint64_t next_table_base_ptr)
{
    uint64_t offset     = 0;
    uint64_t descriptor = 0;

    /* Calculate page offset */
    if (BSP_MMU_TABLE_LEVEL_1 == p_table_info->table_level)
    {
        offset = ((vaddress - p_table_info->table_base_addr) / BSP_MMU_PA_STRIDE_LEVEL_1) * BSP_MMU_PG_DESC_SIZE;
    }
    else
    {
        offset = ((vaddress - p_table_info->table_base_addr) / BSP_MMU_PA_STRIDE_LEVEL_2) * BSP_MMU_PG_DESC_SIZE;
    }

    /* Make attribute bits */
    descriptor = (next_table_base_ptr | BSP_MMU_PG_ATTR_NEXT_TBL);

    /* Write Page Entry */
    *(uint64_t *) (p_table_info->table_base_ptr + offset) = descriptor;
}

/*******************************************************************************************************************//**
 * Fill page table entries.
 *  @param[in]     p_table_info  The table information to set a descriptor.
 *  @param[in]     p_section_info  The pagetable information.
 **********************************************************************************************************************/
static void bsp_mmu_writetable (st_mmu_table_info_t * p_table_info, r_mmu_pgtbl_cfg_t * p_section_info)
{
    volatile int32_t i;
    int32_t          num_of_desc;
    int32_t          table_index;
    uint64_t       * pg_desc_ptr;
    uint32_t         pa_stride;

    if (BSP_MMU_TABLE_LEVEL_1 == p_table_info->table_level)
    {
        pa_stride = BSP_MMU_PA_STRIDE_LEVEL_1;
    }
    else if (BSP_MMU_TABLE_LEVEL_2 == p_table_info->table_level)
    {
        pa_stride = BSP_MMU_PA_STRIDE_LEVEL_2;
    }
    else                               /* BSP_MMU_TABLE_LEVEL_3 */
    {
        pa_stride = BSP_MMU_PA_STRIDE_LEVEL_3;
    }

    num_of_desc = (int32_t) (p_section_info->size / pa_stride);
    table_index = (int32_t) ((p_section_info->vaddress - p_table_info->table_base_addr) / pa_stride);
    pg_desc_ptr = (uint64_t *) (p_table_info->table_base_ptr + ((uint64_t) (table_index * BSP_MMU_PG_DESC_SIZE)));

    for (i = 0; i < num_of_desc; i++)
    {
        if ((p_section_info->attribute & BSP_MMU_DESCRIPTOR_VALID) == BSP_MMU_DESCRIPTOR_VALID)
        {
            *pg_desc_ptr++ = p_section_info->paddress | p_section_info->attribute;
        }
        else
        {
            *pg_desc_ptr++ = (uint64_t) 0U;
        }

        p_section_info->paddress += pa_stride;
    }
}

/*******************************************************************************************************************//**
 * Disable a specific MMU region.
 *
 * @param[in]  mmu_region_cfg   Region config to disabled
 **********************************************************************************************************************/
static void bsp_mmu_disable_region (const r_mmu_pgtbl_cfg_t * mmu_region_cfg)
{
    r_mmu_pgtbl_cfg_t mmu_disabled_cfg;
    mmu_disabled_cfg = *mmu_region_cfg;

    mmu_disabled_cfg.attribute = mmu_disabled_cfg.attribute & (~BSP_MMU_DESCRIPTOR_VALID);
    bsp_mmu_set_region(&mmu_disabled_cfg);
    bsp_mmu_ttbr_refresh();
}

/*******************************************************************************************************************//**
 * Configure specific MMU regions.
 *
 * @param[in]  mmu_region_cfg   Region config to disabled
 **********************************************************************************************************************/
static void bsp_mmu_config_region (const r_mmu_pgtbl_cfg_t * mmu_region_cfg)
{
    /* Invalidate the translation table entry with a broadcast TLB invalidation instruction,
     * and execute a DSB instruction to ensure the completion of that invalidation. */

    /* Execute TLB invalidation instruction. */
    __asm volatile (
        "TLBI ALLE3                             \n" /* Cortex-A55 I-TLB and D-TLB invalidation (TLBIALL) */
        ::: "memory");

    /* Execute DSB and ISB instruction. */
    __DSB();
    __ISB();

    bsp_mmu_set_region(mmu_region_cfg);
    bsp_mmu_ttbr_refresh();
}

/*******************************************************************************************************************//**
 * Set the TLB table for the specified dynamic MMU configuration.
 *
 * @param[in]  mmu_region_cfg   New configuration of MMU region data
 **********************************************************************************************************************/
static void bsp_mmu_set_region (const r_mmu_pgtbl_cfg_t * mmu_region_cfg)
{
    st_mmu_table_info_t table_info;
    r_mmu_pgtbl_cfg_t   section_info;

    /* Set level2 tables */
    table_info.table_level = BSP_MMU_TABLE_LEVEL_2;

    section_info.vaddress  = mmu_region_cfg->vaddress;
    section_info.paddress  = mmu_region_cfg->paddress;
    section_info.size      = mmu_region_cfg->size;
    section_info.attribute = mmu_region_cfg->attribute;

    /* Set attribute */
    if (BSP_MMU_N2_TABLE_START_VADDR > section_info.vaddress)
    {
        if (BSP_MMU_N4_TABLE_START_VADDR < (section_info.vaddress + section_info.size))
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_1_base;
            table_info.table_base_addr = BSP_MMU_N1_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_N2_TABLE_START_VADDR - section_info.vaddress;
            bsp_mmu_writetable(&table_info, &section_info);

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_2_base;
            table_info.table_base_addr = BSP_MMU_N2_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_LEVEL1_TABLE_SIZE;
            section_info.vaddress      = BSP_MMU_N2_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_3_base;
            table_info.table_base_addr = BSP_MMU_N3_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N3_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_LEVEL1_TABLE_SIZE;
            bsp_mmu_writetable(&table_info, &section_info);

            section_info.size     = mmu_region_cfg->size;
            section_info.vaddress = mmu_region_cfg->vaddress;

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_4_base;
            table_info.table_base_addr = BSP_MMU_N4_TABLE_START_VADDR;
            section_info.size          = section_info.vaddress + section_info.size - BSP_MMU_N4_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N4_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
        else if (BSP_MMU_N3_TABLE_START_VADDR < (section_info.vaddress + section_info.size))
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_1_base;
            table_info.table_base_addr = BSP_MMU_N1_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_N2_TABLE_START_VADDR - section_info.vaddress;
            bsp_mmu_writetable(&table_info, &section_info);

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_2_base;
            table_info.table_base_addr = BSP_MMU_N2_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_LEVEL1_TABLE_SIZE;
            section_info.vaddress      = BSP_MMU_N2_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);

            section_info.size     = mmu_region_cfg->size;
            section_info.vaddress = mmu_region_cfg->vaddress;

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_3_base;
            table_info.table_base_addr = BSP_MMU_N3_TABLE_START_VADDR;
            section_info.size          = section_info.vaddress + section_info.size - BSP_MMU_N2_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N3_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
        else if (BSP_MMU_N2_TABLE_START_VADDR < (section_info.vaddress + section_info.size))
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_1_base;
            table_info.table_base_addr = BSP_MMU_N1_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_N2_TABLE_START_VADDR - section_info.vaddress;
            bsp_mmu_writetable(&table_info, &section_info);

            section_info.size = mmu_region_cfg->size;

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_2_base;
            table_info.table_base_addr = BSP_MMU_N2_TABLE_START_VADDR;
            section_info.size          = section_info.vaddress + section_info.size - BSP_MMU_N2_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N2_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
        else
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_1_base;
            table_info.table_base_addr = BSP_MMU_N1_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
    }
    else if (BSP_MMU_N3_TABLE_START_VADDR > section_info.vaddress)
    {
        if (BSP_MMU_N4_TABLE_START_VADDR < (section_info.vaddress + section_info.size))
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_2_base;
            table_info.table_base_addr = BSP_MMU_N2_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_N3_TABLE_START_VADDR - section_info.vaddress;
            bsp_mmu_writetable(&table_info, &section_info);

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_3_base;
            table_info.table_base_addr = BSP_MMU_N3_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_LEVEL1_TABLE_SIZE;
            section_info.vaddress      = BSP_MMU_N3_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);

            section_info.size     = mmu_region_cfg->size;
            section_info.vaddress = mmu_region_cfg->vaddress;

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_4_base;
            table_info.table_base_addr = BSP_MMU_N4_TABLE_START_VADDR;
            section_info.size          = section_info.vaddress + section_info.size - BSP_MMU_N4_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N4_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
        else if (BSP_MMU_N3_TABLE_START_VADDR < (section_info.vaddress + section_info.size))
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_2_base;
            table_info.table_base_addr = BSP_MMU_N2_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_N3_TABLE_START_VADDR - section_info.vaddress;
            bsp_mmu_writetable(&table_info, &section_info);

            section_info.size = mmu_region_cfg->size;

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_3_base;
            table_info.table_base_addr = BSP_MMU_N3_TABLE_START_VADDR;
            section_info.size          = section_info.vaddress + section_info.size - BSP_MMU_N3_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N3_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
        else
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_2_base;
            table_info.table_base_addr = BSP_MMU_N2_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
    }
    else if (BSP_MMU_N4_TABLE_START_VADDR > section_info.vaddress)
    {
        if (BSP_MMU_N4_TABLE_START_VADDR < (section_info.vaddress + section_info.size))
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_3_base;
            table_info.table_base_addr = BSP_MMU_N3_TABLE_START_VADDR;
            section_info.size          = BSP_MMU_N4_TABLE_START_VADDR - section_info.vaddress;
            bsp_mmu_writetable(&table_info, &section_info);

            section_info.size = mmu_region_cfg->size;

            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_4_base;
            table_info.table_base_addr = BSP_MMU_N4_TABLE_START_VADDR;
            section_info.size          = section_info.vaddress + section_info.size - BSP_MMU_N4_TABLE_START_VADDR;
            section_info.vaddress      = BSP_MMU_N4_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
        else
        {
            table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_3_base;
            table_info.table_base_addr = BSP_MMU_N3_TABLE_START_VADDR;
            bsp_mmu_writetable(&table_info, &section_info);
        }
    }
    else if (BSP_MMU_N5_TABLE_START_VADDR > section_info.vaddress)
    {
        table_info.table_base_ptr  = (uint64_t) &g_mmu_level2_table_4_base;
        table_info.table_base_addr = BSP_MMU_N4_TABLE_START_VADDR;
        bsp_mmu_writetable(&table_info, &section_info);
    }
    else
    {
        table_info.table_level     = BSP_MMU_TABLE_LEVEL_1;
        table_info.table_base_ptr  = (uint64_t) &g_mmu_ttbr0_base[4];
        table_info.table_base_addr = BSP_MMU_N5_TABLE_START_VADDR;
        bsp_mmu_writetable(&table_info, &section_info);
    }
}

/*******************************************************************************************************************//**
 * TTRB table refresh.
 **********************************************************************************************************************/
static void bsp_mmu_ttbr_refresh (void)
{
    R_BSP_CacheCleanInvalidateRange((uintptr_t) &g_mmu_ttbr0_base[0], sizeof(g_mmu_ttbr0_base) * sizeof(uint64_t));
    R_BSP_CacheCleanInvalidateRange((uintptr_t) &g_mmu_level2_table_1_base[0],
                                    sizeof(g_mmu_level2_table_1_base) * sizeof(uint64_t));
    R_BSP_CacheCleanInvalidateRange((uintptr_t) &g_mmu_level2_table_2_base[0],
                                    sizeof(g_mmu_level2_table_2_base) * sizeof(uint64_t));
    R_BSP_CacheCleanInvalidateRange((uintptr_t) &g_mmu_level2_table_3_base[0],
                                    sizeof(g_mmu_level2_table_3_base) * sizeof(uint64_t));
    R_BSP_CacheCleanInvalidateRange((uintptr_t) &g_mmu_level2_table_4_base[0],
                                    sizeof(g_mmu_level2_table_4_base) * sizeof(uint64_t));
}

/*******************************************************************************************************************//**
 * Adjusted address range for dynamic MMU settings
 *
 * @retval     FSP_SUCCESS               No configuration errors detected
 * @retval     FSP_ERR_INVALID_ARGUMENT  Invalid dynamic mmu configuration
 **********************************************************************************************************************/
fsp_err_t bsp_mmu_adjust_dynamic_region (void)
{
    uint64_t offset = 0;

    if (g_mmu_dynamic_cfg.vaddress < BSP_MMU_N5_TABLE_START_VADDR)
    {
        /* For dynamic MMU configuration within 4GB space */

#if BSP_CFG_PARAM_CHECKING_ENABLE
        if ((g_mmu_dynamic_cfg.vaddress & (BSP_MMU_PA_STRIDE_LEVEL_2 - 1)) !=
            (g_mmu_dynamic_cfg.paddress & (BSP_MMU_PA_STRIDE_LEVEL_2 - 1)))
        {
            return FSP_ERR_INVALID_ARGUMENT;
        }
#endif

        /* Make it 2MB unit of the vaddress and paddress */
        offset = g_mmu_dynamic_cfg.vaddress & (BSP_MMU_PA_STRIDE_LEVEL_2 - 1);
        g_mmu_dynamic_cfg.vaddress -= offset;
        g_mmu_dynamic_cfg.paddress -= offset;
        g_mmu_dynamic_cfg.size     += offset;

        offset = BSP_MMU_PA_STRIDE_LEVEL_2 -
                 (g_mmu_dynamic_cfg.size & (BSP_MMU_PA_STRIDE_LEVEL_2 - 1));
        offset = offset & (BSP_MMU_PA_STRIDE_LEVEL_2 - 1);

        /* Make it 2MB unit of the size */
        g_mmu_dynamic_cfg.size += offset;
    }
    else
    {
        /* For dynamic MMU settings in 4GB space or more */

#if BSP_CFG_PARAM_CHECKING_ENABLE
        if ((g_mmu_dynamic_cfg.vaddress & (BSP_MMU_PA_STRIDE_LEVEL_1 - 1)) !=
            (g_mmu_dynamic_cfg.paddress & (BSP_MMU_PA_STRIDE_LEVEL_1 - 1)))
        {
            return FSP_ERR_INVALID_ARGUMENT;
        }
#endif

        /* Make it 1GB unit of the vaddress and paddress */
        offset = g_mmu_dynamic_cfg.vaddress & (BSP_MMU_PA_STRIDE_LEVEL_1 - 1);
        g_mmu_dynamic_cfg.vaddress -= offset;
        g_mmu_dynamic_cfg.paddress -= offset;
        g_mmu_dynamic_cfg.size     += offset;

        /* Make it 1GB unit of the size */
        offset = BSP_MMU_PA_STRIDE_LEVEL_1 - (g_mmu_dynamic_cfg.size & (BSP_MMU_PA_STRIDE_LEVEL_1 - 1));
        offset = offset & (BSP_MMU_PA_STRIDE_LEVEL_1 - 1);

        g_mmu_dynamic_cfg.size += offset;
    }

    return FSP_SUCCESS;
}
