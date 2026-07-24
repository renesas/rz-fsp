/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

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

void R_BSP_MPUInit (mpu_region_table_cfg_t * mpu_table)
{
    uint32_t table_num;
    uint8_t  region_number;
    uint32_t base_addr;
    uint32_t size;
    uint32_t attr;

    for (table_num = 0; table_num < BSP_FEATURE_MPU_REGION_NUM; table_num++)
    {
        region_number = mpu_table[table_num].region_number;
        base_addr     = mpu_table[table_num].base_addr;
        size          = (mpu_table[table_num].size | mpu_table[table_num].sub_region);
        size         |=
            (0 != (mpu_table[table_num].size & BSP_MPU_SIZE_MASK)) ? (BSP_MPU_DRSR_ENABLE) : (BSP_MPU_DRSR_DISABLE);
        attr = mpu_table[table_num].attr;

        bsp_mpu_init(region_number, base_addr, size, attr);
    }

    bsp_mpu_enable();
}

/** @} (end addtogroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif
