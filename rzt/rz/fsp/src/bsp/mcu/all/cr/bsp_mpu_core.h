/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MPU_CORE_H
 #define BSP_MPU_CORE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #define BSP_NON_SHAREABLE              (0 << 3)
 #define BSP_OUTER_SHAREABLE            (2 << 3)
 #define BSP_INNER_SHAREABLE            (3 << 3)
 #define BSP_EL1RW_EL0NO                (0 << 1)
 #define BSP_EL1RW_EL0RW                (1 << 1)
 #define BSP_EL1RO_EL0NO                (2 << 1)
 #define BSP_EL1RO_EL0RO                (3 << 1)
 #define BSP_EXECUTE_ENABLE             (0)
 #define BSP_EXECUTE_NEVER              (1)
 #define BSP_REGION_DISABLE             (0U)
 #define BSP_REGION_ENABLE              (1U)
 #define BSP_ATTRINDEX0                 (0 << 1)
 #define BSP_ATTRINDEX1                 (1 << 1)
 #define BSP_ATTRINDEX2                 (2 << 1)
 #define BSP_ATTRINDEX3                 (3 << 1)
 #define BSP_ATTRINDEX4                 (4 << 1)
 #define BSP_ATTRINDEX5                 (5 << 1)
 #define BSP_ATTRINDEX6                 (6 << 1)
 #define BSP_ATTRINDEX7                 (7 << 1)
 #define EL1_MPU_REGION_COUNT           (24)
 #define EL1_MPU_REGION_ADDRESS_MASK    (0xFFFFFFC0)
 #define BSP_REGION_ALIGNMENT           (0x40)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Region attribute information*/
typedef struct st_bsp_mpu_region_attribute
{
    uint32_t attribute_index;          ///< Set Attribute Index (AttrIndx)
    uint32_t shareablity;              ///< Set Shareability (SH)
    uint32_t access_permission;        ///< Set Access Permission (AP)
    uint32_t execute_never;            ///< Set Execute Never (XN)
} bsp_mpu_region_attribute_t;

/** Dynamic region configuration */
typedef struct st_bsp_mpu_dynamic_cfg
{
    uint32_t base;                        ///< Set the dynamic region start address
    uint32_t size;                        ///< Set the dynamic region size
    bsp_mpu_region_attribute_t attribute; ///< Set the dynamic region attribute
} bsp_mpu_dynamic_cfg_t;

/* Region configuration */
typedef struct st_bsp_mpu_region_ctrl
{
    uint32_t aligned_base;
    uint32_t aligned_limit;
    uint32_t aligned_size;
    uint32_t region_index;
    bsp_mpu_region_attribute_t attribute;
} bsp_mpu_region_ctrl_t;

/* MPU configuration*/
typedef struct st_bsp_mpu_config
{
    uint32_t base;
    uint32_t limit;
} bsp_mpu_config_t;

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

fsp_err_t R_BSP_MpuRegionDynamicConfig(bsp_mpu_dynamic_cfg_t * p_dynamic_region_cfg);
fsp_err_t R_BSP_MpuRegionRestoreConfig(void);

/** @} (end addtogroup BSP_MCU) */
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/***********************************************************************************************************************
 * Inline Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Clear all settings of MPU region.
 *
 * @param[in]  region   Region will be cleared
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_mpu_clear_region (uint32_t region)
{
    /* Selects the current EL1-controlled MPU region registers, PRBAR, and PRLAR */
    __set_PRSELR(region);

    /* Execute the DSB instruction before making changes to ensure all memory accesses are completed. */
    __DSB();

    /* Clear the base address and attributes of the MPU region controlled by EL1 */
    __set_PRLAR(0);

    /* Clear the limit address and attributes of the MPU region controlled by EL1 */
    __set_PRBAR(0);

    /* Execute the ISB instruction to flush the pipeline and guarantee that the MPU changes take effect. */
    __ISB();
}

/*******************************************************************************************************************//**
 * Disable a specific MPU region.
 *
 * @param[in]  region   Region will be disabled
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_mpu_disable_region (uint32_t region)
{
    uint32_t prlar = 0;

    /* Selects the current EL1-controlled MPU region registers */
    __set_PRSELR(region);

    prlar  = __get_PRLAR();
    prlar &= ~BSP_REGION_ENABLE;

    /* Execute the DSB instruction before making changes to ensure all memory accesses are completed. */
    __DSB();

    __set_PRLAR(prlar);

    /* Execute the ISB instruction to flush the pipeline and guarantee that the MPU changes take effect. */
    __ISB();
}

/*******************************************************************************************************************//**
 * Enable a specific MPU region.
 *
 * @param[in]  region   Region will be enabled
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_mpu_enable_region (uint32_t region)
{
    uint32_t prlar = 0;

    /* Selects the current EL1-controlled MPU region registers */
    __set_PRSELR(region);

    prlar  = __get_PRLAR();
    prlar |= BSP_REGION_ENABLE;

    /* Execute the DSB instruction before making changes to ensure all memory accesses are completed. */
    __DSB();

    __set_PRLAR(prlar);

    /* Execute the ISB instruction to flush the pipeline and guarantee that the MPU changes take effect. */
    __ISB();
}

/*******************************************************************************************************************//**
 * Get the settings of MPU region
 *
 * @param[in] region         Region which the context will be save
 *
 * @param[out] p_region_cfg  Pointer to save region context
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_mpu_region_get_config (bsp_mpu_config_t * p_region_cfg, uint32_t region)
{
    /* Selects the current EL1-controlled MPU region registers */
    __set_PRSELR(region);

    /* Execute the DSB instruction before making changes to ensure all memory accesses are completed. */
    __DSB();

    /* Get PRBAR register value
     * - Region Base Address
     * - Region Share-ability
     * - Region Access Permission
     * - Region Execute Never
     */
    p_region_cfg->base = __get_PRBAR();

    /* Get PRLAR register value
     * - Region Limit Address
     * - Region Attribute Index
     */
    p_region_cfg->limit = __get_PRLAR();
}

/*******************************************************************************************************************//**
 * Calculate the actual base address of region from PRBAR.BASE value.
 *
 * @param[in]  prbar_base  PRBAR.BASE value
 *
 * @return Actual base address of MPU region
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t bsp_mpu_prbar_actual_base_calculate (uint32_t prbar_base)
{
    return prbar_base & EL1_MPU_REGION_ADDRESS_MASK;
}

/*******************************************************************************************************************//**
 * Calculate the actual limit address of region from PRLAR.LIMIT value.
 *
 * @param[in]  prlar_limit  PRLAR.LIMIT value
 *
 * @return Actual limit address of MPU region
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t bsp_mpu_prlar_actual_limit_calculate (uint32_t prlar_limit)
{
    return ((prlar_limit & EL1_MPU_REGION_ADDRESS_MASK) + BSP_REGION_ALIGNMENT) - 1;
}

/*******************************************************************************************************************//**
 * Calculate the region size.
 *
 * @param[in]  limit_address limit address
 * @param[in]  base_address  base address
 *
 * @return Size of MPU region.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t bsp_mpu_size_calculate (uint32_t limit_address, uint32_t base_address)
{
    return (limit_address - base_address) + 1;
}

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
