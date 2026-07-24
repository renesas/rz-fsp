/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MMU_CORE_H
#define BSP_MMU_CORE_H

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZT
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU) */
#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_NON_CACHEABLE                 (0x0004) /* Normal-Memory: Non-Cacheable */
#define BSP_WRITE_BACK_TRANSIENT          (0x0007) /* Normal-Memory: Write-Back transient */
#define BSP_WRITE_BACK_NON_TRANSIENT      (0x000F) /* Normal-Memory: Write-Back non-transient. */

#define BSP_TYPE_NORMAL_MEMORY            (0)
#define BSP_TYPE_DEVICE_MEMORY            (1)

#define BSP_READ_ALLOCATE                 (0xFFFF) /* Read allocate (bit1=1, "1" mask except bit1) */
#define BSP_READ_NOT_ALLOCATE             (0xFFFD) /* Read not allocate (bit1=0, "1" mask except bit1) */
#define BSP_WRITE_ALLOCATE                (0xFFFF) /* Write allocate (bit0=1, "1" mask except bit0) */
#define BSP_WRITE_NOT_ALLOCATE            (0xFFFE) /* Write not allocate (bit0=0, "1" mask except bit0) */

#define BSP_DEVICE_NGNRNE                 (0x0000) /* Device-nGnRnE memory */
#define BSP_DEVICE_NGNRE                  (0x0004) /* Device-nGnRE memory */
#define BSP_DEVICE_NGRE                   (0x0008) /* Device-nGRE memory */
#define BSP_DEVICE_GRE                    (0x000C) /* Device-GRE memory */

#define BSP_OFFSET_ATTR0_INNER            (0)
#define BSP_OFFSET_ATTR0_OUTER            (4)
#define BSP_OFFSET_ATTR0_DEVICE           (0)
#define BSP_OFFSET_ATTR1_INNER            (8)
#define BSP_OFFSET_ATTR1_OUTER            (12)
#define BSP_OFFSET_ATTR1_DEVICE           (8)

#define BSP_OFFSET_ATTR2_INNER            (16)
#define BSP_OFFSET_ATTR2_OUTER            (20)
#define BSP_OFFSET_ATTR2_DEVICE           (16)
#define BSP_OFFSET_ATTR3_INNER            (24)
#define BSP_OFFSET_ATTR3_OUTER            (28)
#define BSP_OFFSET_ATTR3_DEVICE           (24)

#define BSP_OFFSET_ATTR4_INNER            (0)
#define BSP_OFFSET_ATTR4_OUTER            (4)
#define BSP_OFFSET_ATTR4_DEVICE           (0)
#define BSP_OFFSET_ATTR5_INNER            (8)
#define BSP_OFFSET_ATTR5_OUTER            (12)
#define BSP_OFFSET_ATTR5_DEVICE           (8)

#define BSP_OFFSET_ATTR6_INNER            (16)
#define BSP_OFFSET_ATTR6_OUTER            (20)
#define BSP_OFFSET_ATTR6_DEVICE           (16)
#define BSP_OFFSET_ATTR7_INNER            (24)
#define BSP_OFFSET_ATTR7_OUTER            (28)
#define BSP_OFFSET_ATTR7_DEVICE           (24)

/* Attr0 */
#if BSP_CFG_CPU_MPU_ATTR0_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR0            (BSP_CFG_CPU_MPU_ATTR0_DEVICE_TYPE << BSP_OFFSET_ATTR0_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR0            (((BSP_CFG_CPU_MPU_ATTR0_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR0_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR0_INNER_WRITE)) << BSP_OFFSET_ATTR0_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR0_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR0_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR0_OUTER_WRITE)) << BSP_OFFSET_ATTR0_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR0_TYPE */

/* Attr1 */
#if BSP_CFG_CPU_MPU_ATTR1_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR1            (BSP_CFG_CPU_MPU_ATTR1_DEVICE_TYPE << BSP_OFFSET_ATTR1_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR1            (((BSP_CFG_CPU_MPU_ATTR1_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR1_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR1_INNER_WRITE)) << BSP_OFFSET_ATTR1_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR1_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR1_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR1_OUTER_WRITE)) << BSP_OFFSET_ATTR1_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR1_TYPE */

/* Attr2 */
#if BSP_CFG_CPU_MPU_ATTR2_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR2            (BSP_CFG_CPU_MPU_ATTR2_DEVICE_TYPE << BSP_OFFSET_ATTR2_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR2            (((BSP_CFG_CPU_MPU_ATTR2_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR2_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR2_INNER_WRITE)) << BSP_OFFSET_ATTR2_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR2_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR2_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR2_OUTER_WRITE)) << BSP_OFFSET_ATTR2_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR2_TYPE */

/* Attr3 */
#if BSP_CFG_CPU_MPU_ATTR3_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR3            (BSP_CFG_CPU_MPU_ATTR3_DEVICE_TYPE << BSP_OFFSET_ATTR3_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR3            (((BSP_CFG_CPU_MPU_ATTR3_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR3_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR3_INNER_WRITE)) << BSP_OFFSET_ATTR3_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR3_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR3_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR3_OUTER_WRITE)) << BSP_OFFSET_ATTR3_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR3_TYPE */

/* Attr4 */
#if BSP_CFG_CPU_MPU_ATTR4_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR4            (BSP_CFG_CPU_MPU_ATTR4_DEVICE_TYPE << BSP_OFFSET_ATTR4_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR4            (((BSP_CFG_CPU_MPU_ATTR4_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR4_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR4_INNER_WRITE)) << BSP_OFFSET_ATTR4_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR4_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR4_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR4_OUTER_WRITE)) << BSP_OFFSET_ATTR4_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR4_TYPE */

/* Attr5 */
#if BSP_CFG_CPU_MPU_ATTR5_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR5            (BSP_CFG_CPU_MPU_ATTR5_DEVICE_TYPE << BSP_OFFSET_ATTR5_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR5            (((BSP_CFG_CPU_MPU_ATTR5_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR5_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR5_INNER_WRITE)) << BSP_OFFSET_ATTR5_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR5_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR5_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR5_OUTER_WRITE)) << BSP_OFFSET_ATTR5_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR5_TYPE */

/* Attr6 */
#if BSP_CFG_CPU_MPU_ATTR6_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR6            (BSP_CFG_CPU_MPU_ATTR6_DEVICE_TYPE << BSP_OFFSET_ATTR6_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR6            (((BSP_CFG_CPU_MPU_ATTR6_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR6_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR6_INNER_WRITE)) << BSP_OFFSET_ATTR6_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR6_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR6_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR6_OUTER_WRITE)) << BSP_OFFSET_ATTR6_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR6_TYPE */

/* Attr7 */
#if BSP_CFG_CPU_MPU_ATTR7_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR7            (BSP_CFG_CPU_MPU_ATTR7_DEVICE_TYPE << BSP_OFFSET_ATTR7_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR7            (((BSP_CFG_CPU_MPU_ATTR7_INNER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR7_INNER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR7_INNER_WRITE)) << BSP_OFFSET_ATTR7_INNER) | \
                                           ((BSP_CFG_CPU_MPU_ATTR7_OUTER &                                     \
                                             (BSP_CFG_CPU_MPU_ATTR7_OUTER_READ) &                              \
                                             (BSP_CFG_CPU_MPU_ATTR7_OUTER_WRITE)) << BSP_OFFSET_ATTR7_OUTER))
#endif                                 /* BSP_CFG_CPU_MPU_ATTR7_TYPE */

#define ATTR_3_2_1_0                      (BSP_CFG_CPU_MPU_ATTR3 | BSP_CFG_CPU_MPU_ATTR2 | BSP_CFG_CPU_MPU_ATTR1 | \
                                           BSP_CFG_CPU_MPU_ATTR0)
#define ATTR_7_6_5_4                      (BSP_CFG_CPU_MPU_ATTR7 | BSP_CFG_CPU_MPU_ATTR6 | BSP_CFG_CPU_MPU_ATTR5 | \
                                           BSP_CFG_CPU_MPU_ATTR4)

#define BSP_UXN_EXECUTE_DISABLE           (0x100000000 << 22)
#define BSP_UXN_EXECUTE_ENABLE            (0x000000000 << 22)
#define BSP_PXN_EXECUTE_DISABLE           (0x100000000 << 21)
#define BSP_PXN_EXECUTE_ENABLE            (0x000000000 << 21)
#define BSP_AF_BLOCK_USED                 (1 << 10)
#define BSP_SHAREABLE_MASK                (3UL << 8)
#define BSP_NON_SHAREABLE                 (0 << 8)
#define BSP_OUTER_SHAREABLE               (2 << 8)
#define BSP_INNER_SHAREABLE               (3 << 8)
#define BSP_EL321RW_EL0NO                 (0 << 6)
#define BSP_EL321RW_EL0RW                 (1 << 6)
#define BSP_EL321RO_EL0NO                 (2 << 6)
#define BSP_EL321RO_EL0RO                 (3 << 6)
#define BSP_NS_NON_SECURE                 (1 << 5)
#define BSP_NS_SECURE                     (0 << 5)
#define BSP_ATTRINDEX0                    (0 << 2)
#define BSP_ATTRINDEX1                    (1 << 2)
#define BSP_ATTRINDEX2                    (2 << 2)
#define BSP_ATTRINDEX3                    (3 << 2)
#define BSP_ATTRINDEX4                    (4 << 2)
#define BSP_ATTRINDEX5                    (5 << 2)
#define BSP_ATTRINDEX6                    (6 << 2)
#define BSP_ATTRINDEX7                    (7 << 2)
#define BSP_ATTRINDEX_MASK                (7UL << 2)

#define BSP_REGION_ENABLE                 (1 << 0)
#define BSP_REGION_DISABLE                (0 << 0)

#define BSP_MMU_LEVEL2_TABLE_INDEX_MAX    (4)
#define BSP_MMU_TABLE_ENTRY               (512)
#define BSP_MMU_TABLE_ALIGN               (0x1000)

#define BSP_MMU_LEVEL1_TABLE_SIZE         (0x40000000)
#define BSP_MMU_PA_STRIDE_LEVEL_1         (0x40000000) /* 1GB */
#define BSP_MMU_PA_STRIDE_LEVEL_2         (0x00200000) /* 2MB */
#define BSP_MMU_PA_STRIDE_LEVEL_3         (0x00001000) /* 4KB */

#define BSP_MMU_PG_DESC_SIZE              (8)

#define BSP_MMU_N1_TABLE_START_VADDR      (0x00000000)
#define BSP_MMU_N2_TABLE_START_VADDR      (0x40000000)
#define BSP_MMU_N3_TABLE_START_VADDR      (0x80000000)
#define BSP_MMU_N4_TABLE_START_VADDR      (0xC0000000)
#define BSP_MMU_N5_TABLE_START_VADDR      (0x100000000)

#define BSP_MMU_TOTAL_REGION              (48U)

#define BSP_MMU_PG_ATTR_NEXT_TBL          (0x00000003)

#define BSP_MMU_TCR                       (0x8081351D)
#define BSP_MMU_TCR_INVALID_CACHE         (0x8081301D)

#define BSP_MMU_DESCRIPTOR_VALID          (0x1U)

#define EL3_MMU_REGIONXX_DATA(n)    (BSP_CFG_EL3_MMU_REGION ## n ## _UXN |       \
                                     BSP_CFG_EL3_MMU_REGION ## n ## _PXN |       \
                                     BSP_AF_BLOCK_USED |                         \
                                     BSP_CFG_EL3_MMU_REGION ## n ## _SH |        \
                                     BSP_CFG_EL3_MMU_REGION ## n ## _AP |        \
                                     BSP_CFG_EL3_MMU_REGION ## n ## _NS |        \
                                     BSP_CFG_EL3_MMU_REGION ## n ## _ATTRINDEX | \
                                     BSP_CFG_EL3_MMU_REGION ## n ## _ENABLE)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*Table information*/
typedef struct st_bsp_mmu_table_info
{
    uint32_t table_level;
    uint64_t table_base_ptr;
    uint64_t table_base_addr;
} st_mmu_table_info_t;

/*Page table information*/
typedef struct mmu_pagetable_config
{
    uint64_t vaddress;
    uint64_t paddress;
    uint64_t size;
    uint64_t attribute;
} r_mmu_pgtbl_cfg_t;

/*Cache Flag*/
typedef enum e_bsp_mmu_conversion_flag
{
    BSP_MMU_CONVERSION_CACHE     = 0x00000000UL,
    BSP_MMU_CONVERSION_NON_CACHE = 0x00000001UL,
} bsp_mmu_conversion_flag_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

fsp_err_t R_BSP_MmuVatoPa(uint64_t vaddress, uint64_t * p_paddress);
fsp_err_t R_BSP_MmuPatoVa(uint64_t paddress, uint64_t * p_vaddress, bsp_mmu_conversion_flag_t cache_flag);
fsp_err_t R_BSP_MemoryMap(r_mmu_pgtbl_cfg_t * p_memory_map_cfg);
fsp_err_t R_BSP_MemoryUnMap(void);
void      bsp_mmu_configure(void);

#endif                                 /* RZT_FSP_SRC_BSP_MCU_ALL_CA_BSP_MMU_H_ */
