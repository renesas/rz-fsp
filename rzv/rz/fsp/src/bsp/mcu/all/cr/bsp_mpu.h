/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MPU_H
 #define BSP_MPU_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
 #include "bsp_api.h"

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Sub-region disable */
 #define BSP_MPU_SUB_REGION0_DISABLE                                (0x0001 << 8)
 #define BSP_MPU_SUB_REGION1_DISABLE                                (0x0002 << 8)
 #define BSP_MPU_SUB_REGION2_DISABLE                                (0x0004 << 8)
 #define BSP_MPU_SUB_REGION3_DISABLE                                (0x0008 << 8)
 #define BSP_MPU_SUB_REGION4_DISABLE                                (0x0010 << 8)
 #define BSP_MPU_SUB_REGION5_DISABLE                                (0x0020 << 8)
 #define BSP_MPU_SUB_REGION6_DISABLE                                (0x0040 << 8)
 #define BSP_MPU_SUB_REGION7_DISABLE                                (0x0080 << 8)
 #define BSP_MPU_SUB_REGION_ALL_ENABLE                              (0x0000 << 8)

/* Region size */
 #define BSP_MPU_SIZE_256B                                          (0x0007 << 1)
 #define BSP_MPU_SIZE_512B                                          (0x0008 << 1)
 #define BSP_MPU_SIZE_1KB                                           (0x0009 << 1)
 #define BSP_MPU_SIZE_2KB                                           (0x000A << 1)
 #define BSP_MPU_SIZE_4KB                                           (0x000B << 1)
 #define BSP_MPU_SIZE_8KB                                           (0x000C << 1)
 #define BSP_MPU_SIZE_16KB                                          (0x000D << 1)
 #define BSP_MPU_SIZE_32KB                                          (0x000E << 1)
 #define BSP_MPU_SIZE_64KB                                          (0x000F << 1)
 #define BSP_MPU_SIZE_128KB                                         (0x0010 << 1)
 #define BSP_MPU_SIZE_256KB                                         (0x0011 << 1)
 #define BSP_MPU_SIZE_512KB                                         (0x0012 << 1)
 #define BSP_MPU_SIZE_1MB                                           (0x0013 << 1)
 #define BSP_MPU_SIZE_2MB                                           (0x0014 << 1)
 #define BSP_MPU_SIZE_4MB                                           (0x0015 << 1)
 #define BSP_MPU_SIZE_8MB                                           (0x0016 << 1)
 #define BSP_MPU_SIZE_16MB                                          (0x0017 << 1)
 #define BSP_MPU_SIZE_32MB                                          (0x0018 << 1)
 #define BSP_MPU_SIZE_64MB                                          (0x0019 << 1)
 #define BSP_MPU_SIZE_128MB                                         (0x001A << 1)
 #define BSP_MPU_SIZE_256MB                                         (0x001B << 1)
 #define BSP_MPU_SIZE_512MB                                         (0x001C << 1)
 #define BSP_MPU_SIZE_1GB                                           (0x001D << 1)
 #define BSP_MPU_SIZE_2GB                                           (0x001E << 1)
 #define BSP_MPU_SIZE_4GB                                           (0x001F << 1)

 #define BSP_MPU_SIZE_MASK                                          (0x001F << 1)

/* Enable memory region */
 #define BSP_MPU_DRSR_ENABLE                                        (0x0001 << 0)
 #define BSP_MPU_DRSR_DISABLE                                       (0x0000 << 0)

/* Execute never */
 #define BSP_MPU_ATTR_XN                                            (0x0001 << 12)

/* Access permission */
 #define BSP_MPU_ATTR_AP_PRIVILEGED_NOACCESS_USER_NOACCESS          (0x0000 << 8)
 #define BSP_MPU_ATTR_AP_PRIVILEGED_READWRITE_USER_NOACCESS         (0x0001 << 8)
 #define BSP_MPU_ATTR_AP_PRIVILEGED_READWRITE_USER_READONLY         (0x0002 << 8)
 #define BSP_MPU_ATTR_AP_PRIVILEGED_READWRITE_USER_READWRITE        (0x0003 << 8)
 #define BSP_MPU_ATTR_AP_PRIVILEGED_READONLY_USER_NOACCESS          (0x0005 << 8)
 #define BSP_MPU_ATTR_AP_PRIVILEGED_READONLY_USER_READONLY          (0x0006 << 8)

/* Memory region attributes */
 #define BSP_MPU_ATTR_TEX_C_B_STRONGLY_ORDERED                      ((0x0000 << 3) | (0x0000 << 1) | (0x0000 << 0))
 #define BSP_MPU_ATTR_TEX_C_B_DEVICE_SHAREABLE                      ((0x0000 << 3) | (0x0000 << 1) | (0x0001 << 0))
 #define BSP_MPU_ATTR_TEX_C_B_DEVICE_NON_SHAREABLE                  ((0x0002 << 3) | (0x0000 << 1) | (0x0000 << 0))
 #define BSP_MPU_ATTR_TEX_C_B_NORMAL_OUTER_DISABLE_INNER_DISABLE    ((0x0001 << 3) | (0x0000 << 1) | (0x0000 << 0))
 #define BSP_MPU_ATTR_TEX_C_B_NORMAL_OUTER_DISABLE_INNER_ENABLE     ((0x0004 << 3) | (0x0000 << 1) | (0x0001 << 0))
 #define BSP_MPU_ATTR_TEX_C_B_NORMAL_OUTER_ENABLE_INNER_DISABLE     ((0x0005 << 3) | (0x0000 << 1) | (0x0000 << 0))
 #define BSP_MPU_ATTR_TEX_C_B_NORMAL_OUTER_ENABLE_INNER_ENABLE      ((0x0001 << 3) | (0x0001 << 1) | (0x0001 << 0))

/* Shareable. Only applies to Normal memory */
 #define BSP_MPU_ATTR_S                                             (0x0001 << 2)

 #define BSP_SCTLR_BR_BIT                                           (0x00020000) /* Enable MPU background region */
 #define BSP_SCTLR_M_BIT                                            (0x00000001) /* Enable MPU */

typedef struct st_mpu_region_table_cfg
{
    uint8_t  region_number;
    uint32_t base_addr;
    uint32_t size;
    uint32_t sub_region;
    uint32_t attr;
} mpu_region_table_cfg_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void bsp_mpu_init(uint8_t region_number, uint32_t addr, uint32_t size, uint32_t attribute);
void bsp_mpu_enable(void);
void R_BSP_MPUInit(mpu_region_table_cfg_t * mpu_table);

/** @} (end addtogroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

#endif                                 /* BSP_MPU_H */
