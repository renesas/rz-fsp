/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <string.h>
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_BG_REGION_ENABLE            (0x00020000)           /* Enable EL1 background region */
#define BSP_BG_REGION_DISABLE           (0x00000000)           /* Disable EL1 background region */
#define BSP_SCTLR_BR_BIT                (BSP_CFG_SCTLR_BR_BIT) /* Enable EL1 background region */

#define BSP_ICACHE_ENABLE               (0x00001000)
#define BSP_ICACHE_DISABLE              (0x00000000)

#define BSP_DATACACHE_ENABLE            (0x00000004)
#define BSP_DATACACHE_DISABLE           (0x00000000)

#define BSP_WRITE_THROUGH_TRANSIENT     (0x0003) /* Normal-Memory: Write-Through transient */
#define BSP_NON_CACHEABLE               (0x0004) /* Normal-Memory: Non-Cacheable */
#define BSP_WRITE_BACK_TRANSIENT        (0x0007) /* Normal-Memory: Write-Back transient */
#define BSP_WRITE_NON_THROUGH           (0x000B) /* Normal-Memory: Write-Through non-transient. */
#define BSP_WRITE_BACK_NON_TRANSIENT    (0x000F) /* Normal-Memory: Write-Back non-transient. */

#define BSP_TYPE_NORMAL_MEMORY          (0)
#define BSP_TYPE_DEVICE_MEMORY          (1)

#define BSP_READ_ALLOCATE               (0xFFFF) /* Read allocate (bit1=1, "1" mask except bit1) */
#define BSP_READ_NOT_ALLOCATE           (0xFFFD) /* Read not allocate (bit1=0, "1" mask except bit1) */
#define BSP_WRITE_ALLOCATE              (0xFFFF) /* Write allocate (bit0=1, "1" mask except bit0) */
#define BSP_WRITE_NOT_ALLOCATE          (0xFFFE) /* Write not allocate (bit0=0, "1" mask except bit0) */

#define BSP_DEVICE_NGNRNE               (0x0000) /* Device-nGnRnE memory */
#define BSP_DEVICE_NGNRE                (0x0004) /* Device-nGnRE memory */
#define BSP_DEVICE_NGRE                 (0x0008) /* Device-nGRE memory */
#define BSP_DEVICE_GRE                  (0x000C) /* Device-GRE memory */

#define BSP_OFFSET_ATTR0_INNER          (0)
#define BSP_OFFSET_ATTR0_OUTER          (4)
#define BSP_OFFSET_ATTR0_DEVICE         (0)
#define BSP_OFFSET_ATTR1_INNER          (8)
#define BSP_OFFSET_ATTR1_OUTER          (12)
#define BSP_OFFSET_ATTR1_DEVICE         (8)

#define BSP_OFFSET_ATTR2_INNER          (16)
#define BSP_OFFSET_ATTR2_OUTER          (20)
#define BSP_OFFSET_ATTR2_DEVICE         (16)
#define BSP_OFFSET_ATTR3_INNER          (24)
#define BSP_OFFSET_ATTR3_OUTER          (28)
#define BSP_OFFSET_ATTR3_DEVICE         (24)

#define BSP_OFFSET_ATTR4_INNER          (0)
#define BSP_OFFSET_ATTR4_OUTER          (4)
#define BSP_OFFSET_ATTR4_DEVICE         (0)
#define BSP_OFFSET_ATTR5_INNER          (8)
#define BSP_OFFSET_ATTR5_OUTER          (12)
#define BSP_OFFSET_ATTR5_DEVICE         (8)

#define BSP_OFFSET_ATTR6_INNER          (16)
#define BSP_OFFSET_ATTR6_OUTER          (20)
#define BSP_OFFSET_ATTR6_DEVICE         (16)
#define BSP_OFFSET_ATTR7_INNER          (24)
#define BSP_OFFSET_ATTR7_OUTER          (28)
#define BSP_OFFSET_ATTR7_DEVICE         (24)

/* Attr0 */
#if BSP_CFG_CPU_MPU_ATTR0_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR0          (BSP_CFG_CPU_MPU_ATTR0_DEVICE_TYPE << BSP_OFFSET_ATTR0_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR0          (((BSP_CFG_CPU_MPU_ATTR0_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR0_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR0_INNER_WRITE)) << BSP_OFFSET_ATTR0_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR0_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR0_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR0_OUTER_WRITE)) << BSP_OFFSET_ATTR0_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR0_TYPE */

/* Attr1 */
#if BSP_CFG_CPU_MPU_ATTR1_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR1          (BSP_CFG_CPU_MPU_ATTR1_DEVICE_TYPE << BSP_OFFSET_ATTR1_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR1          (((BSP_CFG_CPU_MPU_ATTR1_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR1_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR1_INNER_WRITE)) << BSP_OFFSET_ATTR1_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR1_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR1_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR1_OUTER_WRITE)) << BSP_OFFSET_ATTR1_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR1_TYPE */

/* Attr2 */
#if BSP_CFG_CPU_MPU_ATTR2_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR2          (BSP_CFG_CPU_MPU_ATTR2_DEVICE_TYPE << BSP_OFFSET_ATTR2_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR2          (((BSP_CFG_CPU_MPU_ATTR2_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR2_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR2_INNER_WRITE)) << BSP_OFFSET_ATTR2_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR2_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR2_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR2_OUTER_WRITE)) << BSP_OFFSET_ATTR2_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR2_TYPE */

/* Attr3 */
#if BSP_CFG_CPU_MPU_ATTR3_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR3          (BSP_CFG_CPU_MPU_ATTR3_DEVICE_TYPE << BSP_OFFSET_ATTR3_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR3          (((BSP_CFG_CPU_MPU_ATTR3_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR3_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR3_INNER_WRITE)) << BSP_OFFSET_ATTR3_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR3_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR3_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR3_OUTER_WRITE)) << BSP_OFFSET_ATTR3_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR3_TYPE */

/* Attr4 */
#if BSP_CFG_CPU_MPU_ATTR4_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR4          (BSP_CFG_CPU_MPU_ATTR4_DEVICE_TYPE << BSP_OFFSET_ATTR4_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR4          (((BSP_CFG_CPU_MPU_ATTR4_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR4_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR4_INNER_WRITE)) << BSP_OFFSET_ATTR4_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR4_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR4_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR4_OUTER_WRITE)) << BSP_OFFSET_ATTR4_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR4_TYPE */

/* Attr5 */
#if BSP_CFG_CPU_MPU_ATTR5_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR5          (BSP_CFG_CPU_MPU_ATTR5_DEVICE_TYPE << BSP_OFFSET_ATTR5_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR5          (((BSP_CFG_CPU_MPU_ATTR5_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR5_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR5_INNER_WRITE)) << BSP_OFFSET_ATTR5_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR5_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR5_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR5_OUTER_WRITE)) << BSP_OFFSET_ATTR5_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR5_TYPE */

/* Attr6 */
#if BSP_CFG_CPU_MPU_ATTR6_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR6          (BSP_CFG_CPU_MPU_ATTR6_DEVICE_TYPE << BSP_OFFSET_ATTR6_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR6          (((BSP_CFG_CPU_MPU_ATTR6_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR6_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR6_INNER_WRITE)) << BSP_OFFSET_ATTR6_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR6_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR6_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR6_OUTER_WRITE)) << BSP_OFFSET_ATTR6_OUTER))
#endif                                                   /* BSP_CFG_CPU_MPU_ATTR6_TYPE */

/* Attr7 */
#if BSP_CFG_CPU_MPU_ATTR7_TYPE == BSP_TYPE_DEVICE_MEMORY /* MEMORY TYPE == DEVICE */
 #define BSP_CFG_CPU_MPU_ATTR7          (BSP_CFG_CPU_MPU_ATTR7_DEVICE_TYPE << BSP_OFFSET_ATTR7_DEVICE)
#else                                                    /* MEMORY TYPE == NORMAL MEMORY */
 #define BSP_CFG_CPU_MPU_ATTR7          (((BSP_CFG_CPU_MPU_ATTR7_INNER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR7_INNER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR7_INNER_WRITE)) << BSP_OFFSET_ATTR7_INNER) | \
                                         ((BSP_CFG_CPU_MPU_ATTR7_OUTER &                                     \
                                           (BSP_CFG_CPU_MPU_ATTR7_OUTER_READ) &                              \
                                           (BSP_CFG_CPU_MPU_ATTR7_OUTER_WRITE)) << BSP_OFFSET_ATTR7_OUTER))
#endif                                 /* BSP_CFG_CPU_MPU_ATTR7_TYPE */

#define ATTR_3_2_1_0                    (BSP_CFG_CPU_MPU_ATTR3 | BSP_CFG_CPU_MPU_ATTR2 | BSP_CFG_CPU_MPU_ATTR1 | \
                                         BSP_CFG_CPU_MPU_ATTR0)
#define ATTR_7_6_5_4                    (BSP_CFG_CPU_MPU_ATTR7 | BSP_CFG_CPU_MPU_ATTR6 | BSP_CFG_CPU_MPU_ATTR5 | \
                                         BSP_CFG_CPU_MPU_ATTR4)

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR0_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR0_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR0_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR0_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR0_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR0_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR0_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR1_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR1_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR1_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR1_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR1_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR1_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR1_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR2_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR2_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR2_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR2_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR2_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR2_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR2_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR3_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR3_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR3_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR3_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR3_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR3_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR3_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR4_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR4_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR4_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR4_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR4_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR4_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR4_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR5_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR5_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR5_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR5_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR5_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR5_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR5_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR6_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR6_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR6_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR6_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR6_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR6_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR6_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

#if (BSP_TYPE_NORMAL_MEMORY == BSP_CFG_CPU_MPU_ATTR7_TYPE)
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR7_INNER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR7_INNER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR7_INNER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
 #if ((BSP_WRITE_THROUGH_TRANSIENT == BSP_CFG_CPU_MPU_ATTR7_OUTER) && \
    (BSP_READ_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR7_OUTER_READ) &&    \
    (BSP_WRITE_NOT_ALLOCATE == BSP_CFG_CPU_MPU_ATTR7_OUTER_WRITE))
  #error "If you select Write-Through transient, set either Read or Write to allocate."
 #endif
#endif

/* Region template */
#if (1 != _RZ_ORDINAL) && (0 == BSP_FEATURE_BSP_HAS_SYSTEMRAM_MIRROR_AREA)
 #define EL1_MPU_REGION_ATTRIBUTE_MASK                      (0x3F)
 #define EL1_MPU_REGION_SYSTEMRAM_CACHE_ADDRESS_START       (0x10000000)
 #define EL1_MPU_REGION_SYSTEMRAM_CACHE_ADDRESS_END         (0x100FFFC0)
 #define EL1_MPU_REGION_SYSTEMRAM_NONCACHE_ADDRESS_START    (0x10100000)
 #define EL1_MPU_REGION_SYSTEMRAM_NONCACHE_ADDRESS_END      (0x101FFFC0)

#endif

#define EL1_MPU_REGIONXX_BASE(n)     ((BSP_CFG_EL1_MPU_REGION ## n ## _BASE & EL1_MPU_REGION_ADDRESS_MASK) | \
                                      BSP_CFG_EL1_MPU_REGION ## n ## _SH |                                   \
                                      BSP_CFG_EL1_MPU_REGION ## n ## _AP |                                   \
                                      BSP_CFG_EL1_MPU_REGION ## n ## _XN)

#define EL1_MPU_REGIONXX_LIMIT(n)    ((BSP_CFG_EL1_MPU_REGION ## n ## _LIMIT & EL1_MPU_REGION_ADDRESS_MASK) | \
                                      BSP_CFG_EL1_MPU_REGION ## n ## _ATTRINDEX |                             \
                                      BSP_CFG_EL1_MPU_REGION ## n ## _ENABLE)

/* region 0 */
#define EL1_MPU_REGION00_BASE     EL1_MPU_REGIONXX_BASE(00)
#define EL1_MPU_REGION00_LIMIT    EL1_MPU_REGIONXX_LIMIT(00)

/* region 1 */
#define EL1_MPU_REGION01_BASE     EL1_MPU_REGIONXX_BASE(01)
#define EL1_MPU_REGION01_LIMIT    EL1_MPU_REGIONXX_LIMIT(01)

/* region 2 */
#define EL1_MPU_REGION02_BASE     EL1_MPU_REGIONXX_BASE(02)
#define EL1_MPU_REGION02_LIMIT    EL1_MPU_REGIONXX_LIMIT(02)

/* region 3 */
#define EL1_MPU_REGION03_BASE     EL1_MPU_REGIONXX_BASE(03)
#define EL1_MPU_REGION03_LIMIT    EL1_MPU_REGIONXX_LIMIT(03)

/* region 4 */
#define EL1_MPU_REGION04_BASE     EL1_MPU_REGIONXX_BASE(04)
#define EL1_MPU_REGION04_LIMIT    EL1_MPU_REGIONXX_LIMIT(04)

/* region 5 */
#define EL1_MPU_REGION05_BASE     EL1_MPU_REGIONXX_BASE(05)
#define EL1_MPU_REGION05_LIMIT    EL1_MPU_REGIONXX_LIMIT(05)

/* region 6 */
#define EL1_MPU_REGION06_BASE     EL1_MPU_REGIONXX_BASE(06)
#define EL1_MPU_REGION06_LIMIT    EL1_MPU_REGIONXX_LIMIT(06)

/* region 7 */
#define EL1_MPU_REGION07_BASE     EL1_MPU_REGIONXX_BASE(07)
#define EL1_MPU_REGION07_LIMIT    EL1_MPU_REGIONXX_LIMIT(07)

/* region 8 */
#define EL1_MPU_REGION08_BASE     EL1_MPU_REGIONXX_BASE(08)
#define EL1_MPU_REGION08_LIMIT    EL1_MPU_REGIONXX_LIMIT(08)

/* region 9 */
#define EL1_MPU_REGION09_BASE     EL1_MPU_REGIONXX_BASE(09)
#define EL1_MPU_REGION09_LIMIT    EL1_MPU_REGIONXX_LIMIT(09)

/* region 10 */
#define EL1_MPU_REGION10_BASE     EL1_MPU_REGIONXX_BASE(10)
#define EL1_MPU_REGION10_LIMIT    EL1_MPU_REGIONXX_LIMIT(10)

/* region 11 */
#define EL1_MPU_REGION11_BASE     EL1_MPU_REGIONXX_BASE(11)
#define EL1_MPU_REGION11_LIMIT    EL1_MPU_REGIONXX_LIMIT(11)

/* region 12 */
#define EL1_MPU_REGION12_BASE     EL1_MPU_REGIONXX_BASE(12)
#define EL1_MPU_REGION12_LIMIT    EL1_MPU_REGIONXX_LIMIT(12)

/* region 13 */
#define EL1_MPU_REGION13_BASE     EL1_MPU_REGIONXX_BASE(13)
#define EL1_MPU_REGION13_LIMIT    EL1_MPU_REGIONXX_LIMIT(13)

/* region 14 */
#define EL1_MPU_REGION14_BASE     EL1_MPU_REGIONXX_BASE(14)
#define EL1_MPU_REGION14_LIMIT    EL1_MPU_REGIONXX_LIMIT(14)

/* region 15 */
#define EL1_MPU_REGION15_BASE     EL1_MPU_REGIONXX_BASE(15)
#define EL1_MPU_REGION15_LIMIT    EL1_MPU_REGIONXX_LIMIT(15)

/* region 16 */
#define EL1_MPU_REGION16_BASE     EL1_MPU_REGIONXX_BASE(16)
#define EL1_MPU_REGION16_LIMIT    EL1_MPU_REGIONXX_LIMIT(16)

/* region 17 */
#define EL1_MPU_REGION17_BASE     EL1_MPU_REGIONXX_BASE(17)
#define EL1_MPU_REGION17_LIMIT    EL1_MPU_REGIONXX_LIMIT(17)

/* region 18 */
#define EL1_MPU_REGION18_BASE     EL1_MPU_REGIONXX_BASE(18)
#define EL1_MPU_REGION18_LIMIT    EL1_MPU_REGIONXX_LIMIT(18)

/* region 19 */
#define EL1_MPU_REGION19_BASE     EL1_MPU_REGIONXX_BASE(19)
#define EL1_MPU_REGION19_LIMIT    EL1_MPU_REGIONXX_LIMIT(19)

/* region 20 */
#define EL1_MPU_REGION20_BASE     EL1_MPU_REGIONXX_BASE(20)
#define EL1_MPU_REGION20_LIMIT    EL1_MPU_REGIONXX_LIMIT(20)

/* region 21 */
#define EL1_MPU_REGION21_BASE     EL1_MPU_REGIONXX_BASE(21)
#define EL1_MPU_REGION21_LIMIT    EL1_MPU_REGIONXX_LIMIT(21)

/* region 22 */
#define EL1_MPU_REGION22_BASE     EL1_MPU_REGIONXX_BASE(22)
#define EL1_MPU_REGION22_LIMIT    EL1_MPU_REGIONXX_LIMIT(22)

/* region 23 */
#define EL1_MPU_REGION23_BASE     EL1_MPU_REGIONXX_BASE(23)
#define EL1_MPU_REGION23_LIMIT    EL1_MPU_REGIONXX_LIMIT(23)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* Store default setting of static region */
bsp_mpu_config_t g_mpu_static_regions[EL1_MPU_REGION_COUNT] = {0};

/* Store setting of dynamic region */
bsp_mpu_region_ctrl_t g_mpu_dynamic_ctrl = {0};

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* Store overlapping static region indices */
static uint8_t g_mpu_static_overlap_index[EL1_MPU_REGION_COUNT] = {UINT8_MAX};

/* Flag to check whether MPU static configuration is get */
static uint8_t g_mpu_static_get_flag = 0;

/* Store the dynamic initial status */
static uint8_t g_mpu_dynamic_initialized = 0U;

static const bsp_mpu_config_t g_bsp_el1_mpu[EL1_MPU_REGION_COUNT] =
{
    {EL1_MPU_REGION00_BASE, EL1_MPU_REGION00_LIMIT},
    {EL1_MPU_REGION01_BASE, EL1_MPU_REGION01_LIMIT},
    {EL1_MPU_REGION02_BASE, EL1_MPU_REGION02_LIMIT},
    {EL1_MPU_REGION03_BASE, EL1_MPU_REGION03_LIMIT},
    {EL1_MPU_REGION04_BASE, EL1_MPU_REGION04_LIMIT},
    {EL1_MPU_REGION05_BASE, EL1_MPU_REGION05_LIMIT},
    {EL1_MPU_REGION06_BASE, EL1_MPU_REGION06_LIMIT},
    {EL1_MPU_REGION07_BASE, EL1_MPU_REGION07_LIMIT},
    {EL1_MPU_REGION08_BASE, EL1_MPU_REGION08_LIMIT},
    {EL1_MPU_REGION09_BASE, EL1_MPU_REGION09_LIMIT},
    {EL1_MPU_REGION10_BASE, EL1_MPU_REGION10_LIMIT},
    {EL1_MPU_REGION11_BASE, EL1_MPU_REGION11_LIMIT},
    {EL1_MPU_REGION12_BASE, EL1_MPU_REGION12_LIMIT},
    {EL1_MPU_REGION13_BASE, EL1_MPU_REGION13_LIMIT},
    {EL1_MPU_REGION14_BASE, EL1_MPU_REGION14_LIMIT},
    {EL1_MPU_REGION15_BASE, EL1_MPU_REGION15_LIMIT},
    {EL1_MPU_REGION16_BASE, EL1_MPU_REGION16_LIMIT},
    {EL1_MPU_REGION17_BASE, EL1_MPU_REGION17_LIMIT},
    {EL1_MPU_REGION18_BASE, EL1_MPU_REGION18_LIMIT},
    {EL1_MPU_REGION19_BASE, EL1_MPU_REGION19_LIMIT},
    {EL1_MPU_REGION20_BASE, EL1_MPU_REGION20_LIMIT},
    {EL1_MPU_REGION21_BASE, EL1_MPU_REGION21_LIMIT},
    {EL1_MPU_REGION22_BASE, EL1_MPU_REGION22_LIMIT},
    {EL1_MPU_REGION23_BASE, EL1_MPU_REGION23_LIMIT},
};

void bsp_memory_protect_setting(void);
void bsp_mpu_init(uint32_t region, uint32_t base, uint32_t limit);

static void bsp_mpu_region_save_and_disable(bsp_mpu_region_ctrl_t const * const p_dynamic_region_cfg);
static void bsp_mpu_region_config(bsp_mpu_region_ctrl_t const * const p_dynamic_region_cfg);
static void bsp_mpu_dynamic_region_config(bsp_mpu_region_ctrl_t const * const p_dynamic_region_cfg);

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
 * Change the setting of the MPU region at runtime. There is only one dynamic region setting at a time.
 *
 * @param[in]  p_dynamic_region_cfg      Pointer to dynamically region configuration.
 *
 * @retval     FSP_SUCCESS               No configuration errors detected.
 * @retval     FSP_ERR_CLAMPED           There are no available regions for dynamic settings.
 * @retval     FSP_ERR_IN_USE            Dynamic region configuration has already been used.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MpuRegionDynamicConfig (bsp_mpu_dynamic_cfg_t * p_dynamic_region_cfg)
{
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Verify that the configuration parameters are valid */
    FSP_ASSERT(NULL != p_dynamic_region_cfg);

    /* Verify that the input size is valid */
    FSP_ASSERT(0 != p_dynamic_region_cfg->size);
#endif

    /* Verify that the dynamic region configuration has not already been used */
    FSP_ERROR_RETURN(1U != g_mpu_dynamic_initialized, FSP_ERR_IN_USE);

    /* Get dynamic region configuration */
    g_mpu_dynamic_ctrl.attribute = p_dynamic_region_cfg->attribute;

    /* Adjusted address range for dynamic MPU settings */
    uint64_t dynamic_region_limit = (uint64_t) p_dynamic_region_cfg->base + (uint64_t) p_dynamic_region_cfg->size - 1;
    FSP_ERROR_RETURN(dynamic_region_limit <= UINT32_MAX, FSP_ERR_INVALID_ARGUMENT);
    dynamic_region_limit = ((dynamic_region_limit + BSP_REGION_ALIGNMENT) & EL1_MPU_REGION_ADDRESS_MASK) - 1;

    g_mpu_dynamic_ctrl.aligned_base  = p_dynamic_region_cfg->base & EL1_MPU_REGION_ADDRESS_MASK;
    g_mpu_dynamic_ctrl.aligned_limit = (uint32_t) dynamic_region_limit;
    g_mpu_dynamic_ctrl.aligned_size  = g_mpu_dynamic_ctrl.aligned_limit - g_mpu_dynamic_ctrl.aligned_base + 1;

    /* Critical section required to prevent memory access during MPU configuration changes. */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Save original static region setting */
    if (0 == g_mpu_static_get_flag)
    {
        for (uint32_t region = 0; region < EL1_MPU_REGION_COUNT; region++)
        {
            bsp_mpu_region_get_config(&g_mpu_static_regions[region], region);
        }

        g_mpu_static_get_flag = 1;
    }

    /* Get the index for dynamic region */
    uint32_t valid_dynamic_region_index = UINT32_MAX;
    uint8_t  dynamic_index_found        = 0;

    for (uint32_t region = 0; region < EL1_MPU_REGION_COUNT && !dynamic_index_found; region++)
    {
        uint8_t static_region_is_enable = 0;

        static_region_is_enable = g_mpu_static_regions[region].limit & BSP_REGION_ENABLE;

        if (!static_region_is_enable)
        {
            valid_dynamic_region_index = region;
            dynamic_index_found        = 1;
        }
    }

    /* Check available region for dynamic settings.
     * Exit critical section and return error if enabled static and SoC-supported regions are equal.*/
    if (0 == dynamic_index_found)
    {
        FSP_CRITICAL_SECTION_EXIT;

        return FSP_ERR_CLAMPED;
    }

    /* Get dynamic region index */
    g_mpu_dynamic_ctrl.region_index = valid_dynamic_region_index;

    /* Configure the dynamic region */
    bsp_mpu_dynamic_region_config(&g_mpu_dynamic_ctrl);

    /* Mark Dynamic MPU configuration as initialized */
    g_mpu_dynamic_initialized = 1U;

    FSP_CRITICAL_SECTION_EXIT;

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Restore static and dynamic MPU regions.
 *
 * @retval     FSP_SUCCESS                 No configuration errors detected
 * @retval     FSP_ERR_NOT_INITIALIZED     Dynamic region configuration has not been initialized yet.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MpuRegionRestoreConfig (void)
{
    /* Verify that the dynamic region configuration has already been initialized */
    FSP_ERROR_RETURN(1U == g_mpu_dynamic_initialized, FSP_ERR_NOT_INITIALIZED);

    /* Critical section required to prevent memory access during MPU configuration changes. */
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Mark Dynamic MPU as uninitialized */
    g_mpu_dynamic_initialized = 0U;

    /* Implement cache memory clean and invalidate. */
    R_BSP_CacheCleanInvalidateAll();

    /* Reset static and dynamic region settings to default */
    uint32_t dynamic_index = UINT8_MAX;
    uint32_t static_index  = UINT8_MAX;

    dynamic_index = g_mpu_dynamic_ctrl.region_index;

    /* Disable the static region settings before configuring the program. */
    bsp_mpu_disable_region(dynamic_index);

    /* Restore the static region. */
    bsp_mpu_init(dynamic_index, g_mpu_static_regions[dynamic_index].base, g_mpu_static_regions[dynamic_index].limit);

    uint8_t i = 0;
    while (UINT8_MAX != g_mpu_static_overlap_index[i])
    {
        static_index = g_mpu_static_overlap_index[i];

        /* Disable the static region settings before configuring the program. */
        bsp_mpu_disable_region(static_index);

        /* Restore the static region. */
        bsp_mpu_init(static_index, g_mpu_static_regions[static_index].base, g_mpu_static_regions[static_index].limit);

        i++;
    }

    /* Reset static region index array to init value */
    memset(g_mpu_static_overlap_index, UINT8_MAX, sizeof(g_mpu_static_overlap_index));

    FSP_CRITICAL_SECTION_EXIT;

    /* Return the error code */
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
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize memory protection settings.
 **********************************************************************************************************************/
void bsp_memory_protect_setting (void)
{
    uint32_t sctlr;
    uint32_t mair0;
    uint32_t mair1;
    uint32_t region;

    uint32_t base_address;
    uint32_t limit_address;

    /* Adopt EL1 default memory map as background map */
    sctlr = __get_SCTLR();

    /* BSP_BG_REGION_ENABLE is a non-negative int value within the range of uint32_t. */
    sctlr &= ~(uint32_t) BSP_BG_REGION_ENABLE;
    sctlr |= BSP_SCTLR_BR_BIT;
    __DSB();
    __set_SCTLR(sctlr);
    __ISB();

    /* Configure Memory Attribute Indirection Registers */
    mair0 = ATTR_3_2_1_0;
    mair1 = ATTR_7_6_5_4;
    __set_MAIR0(mair0);
    __set_MAIR1(mair1);

    /* Execute the ISB instruction to flush the pipeline and guarantee that the MPU changes take effect. */
    __ISB();

    /* Setup region. */
    for (region = 0; region < EL1_MPU_REGION_COUNT; region++)
    {
        base_address  = g_bsp_el1_mpu[region].base;
        limit_address = g_bsp_el1_mpu[region].limit;
        bsp_mpu_init(region, base_address, limit_address);
    }

    R_BSP_CacheInvalidateAll();

    R_BSP_CacheEnableMemoryProtect();

#if (BSP_ICACHE_ENABLE == BSP_CFG_SCTLR_I_BIT)
    R_BSP_CacheEnableInst();
#else
    R_BSP_CacheDisableInst();
#endif

#if (BSP_DATACACHE_ENABLE == BSP_CFG_SCTLR_C_BIT)
    R_BSP_CacheEnableData();
#else
    R_BSP_CacheDisableData();
#endif
}

/*******************************************************************************************************************//**
 * Core MPU initialization block.
 **********************************************************************************************************************/
void bsp_mpu_init (uint32_t region, uint32_t base, uint32_t limit)
{
    /* Selects the current EL1-controlled MPU region registers, PRBAR, and PRLAR */
    __set_PRSELR(region);

    /* Execute the DSB instruction before making changes to ensure all memory accesses are completed. */
    __DSB();

    /* Set the base address and attributes of the MPU region controlled by EL1 */
    __set_PRBAR(base);

    /* Set the limit address and attributes of the MPU region controlled by EL1 */
    __set_PRLAR(limit);

    /* Execute the ISB instruction to flush the pipeline and guarantee that the MPU changes take effect. */
    __ISB();
}

/*******************************************************************************************************************//**
 * Save the setting of static MPU region and disable it.
 *
 * @param[in]  p_dynamic_region_cfg      Pointer to dynamically region configuration.
 **********************************************************************************************************************/
static void bsp_mpu_region_save_and_disable (bsp_mpu_region_ctrl_t const * const p_dynamic_region_cfg)
{
    uint32_t index_match = 0;

    /* Initial overlapping static region index array */
    memset(g_mpu_static_overlap_index, UINT8_MAX, sizeof(g_mpu_static_overlap_index));

    for (uint8_t region = 0; region < EL1_MPU_REGION_COUNT; region++)
    {
        uint32_t static_region_base  = bsp_mpu_prbar_actual_base_calculate(g_mpu_static_regions[region].base);
        uint32_t static_region_limit = bsp_mpu_prlar_actual_limit_calculate(g_mpu_static_regions[region].limit);

        if ((p_dynamic_region_cfg->aligned_base > static_region_limit) ||
            (p_dynamic_region_cfg->aligned_limit < static_region_base))
        {
            /* Skip the non-overlap region */
        }
        else
        {
            /* Save the overlapping region index */
            g_mpu_static_overlap_index[index_match++] = region;

            /* Implement cache memory clean and invalidate */
            R_BSP_CacheCleanInvalidateAll();

            /* Disable overlapping static region */
            bsp_mpu_disable_region(region);

            if ((p_dynamic_region_cfg->aligned_base >= static_region_base) &&
                (p_dynamic_region_cfg->aligned_limit <= static_region_limit))
            {
                break;
            }
        }
    }
}

/*******************************************************************************************************************//**
 * Configure specific MPU region with the index input.
 *
 * @param[in]  p_dynamic_region_cfg   Pointer to dynamically region configuration.
 **********************************************************************************************************************/
static void bsp_mpu_region_config (bsp_mpu_region_ctrl_t const * const p_dynamic_region_cfg)
{
    bsp_mpu_config_t region_cfg;

    /* Get value for setting PRBAR register */
    region_cfg.base = (p_dynamic_region_cfg->aligned_base & EL1_MPU_REGION_ADDRESS_MASK) |
                      (p_dynamic_region_cfg->attribute.execute_never |
                       p_dynamic_region_cfg->attribute.access_permission |
                       p_dynamic_region_cfg->attribute.shareablity);

    /* Get value for setting PRLAR register */
    region_cfg.limit = (p_dynamic_region_cfg->aligned_limit & EL1_MPU_REGION_ADDRESS_MASK) | \
                       (p_dynamic_region_cfg->attribute.attribute_index);

    bsp_mpu_init(p_dynamic_region_cfg->region_index, region_cfg.base, region_cfg.limit);

    /* Enable dynamic region */
    bsp_mpu_enable_region(p_dynamic_region_cfg->region_index);
}

/*******************************************************************************************************************//**
 * Configure a dynamic region.
 *
 * @param[in]  p_dynamic_region_cfg      Pointer to dynamically region configuration.
 **********************************************************************************************************************/
static void bsp_mpu_dynamic_region_config (bsp_mpu_region_ctrl_t const * const p_dynamic_region_cfg)
{
    /* Save region context that is overlapped to dynamic region.*/
    bsp_mpu_region_save_and_disable(p_dynamic_region_cfg);

    /* Clear the setting of dynamic region before programming */
    bsp_mpu_clear_region(p_dynamic_region_cfg->region_index);

    /* Set the dynamic region */
    bsp_mpu_region_config(p_dynamic_region_cfg);
}
