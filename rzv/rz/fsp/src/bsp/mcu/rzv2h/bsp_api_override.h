/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZV
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MPU_RZV2H
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup RZV_BSP_MPU_RZV2H) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

#ifndef BSP_API_OVERRIDE_H
 #define BSP_API_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* BSP Common Includes. */
 #if defined(BSP_SUPPORT_CORE_CM33)
  #include "../all/cm/bsp_common.h"
 #elif defined(BSP_SUPPORT_CORE_CR8)
  #include "../all/cr/bsp_common.h"
 #endif

/* BSP MPU Specific Includes. */
 #include "../all/bsp_io.h"
 #include "../all/bsp_group_irq.h"
 #include "../all/bsp_clocks.h"
 #include "../all/bsp_module_stop.h"
 #include "../all/bsp_io_register.h"
 #if defined(BSP_SUPPORT_CORE_CM33)
  #include "../all/cm/bsp_irq.h"
  #include "../all/cm/bsp_security.h"
 #elif defined(BSP_SUPPORT_CORE_CR8)
  #include "../all/cr/bsp_irq_gic.h"
  #include "../all/cr/bsp_irq.h"
  #include "../all/cr/bsp_cache.h"
  #include "../all/cr/bsp_security.h"
  #include "../all/cr/bsp_mpu.h"
 #endif

/* Factory MPU information. */
 #include "../../../../inc/fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
 #include "../all/bsp_delay.h"
 #include "../all/bsp_mcu_api.h"

#endif
