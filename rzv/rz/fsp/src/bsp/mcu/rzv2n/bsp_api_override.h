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
 * @addtogroup RZV_BSP_MPU_RZV2N
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup RZV_BSP_MPU_RZV2N) */

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
 #include "../all/cm/bsp_common.h"

/* BSP MPU Specific Includes. */
 #include "../all/bsp_io.h"
 #include "../all/bsp_group_irq.h"
 #include "../all/bsp_clocks.h"
 #include "../all/bsp_module_stop.h"
 #include "../all/bsp_io_register.h"
 #include "../all/cm/bsp_irq.h"
 #include "../all/cm/bsp_security.h"

/* Factory MPU information. */
 #include "../../../../inc/fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
 #include "../all/bsp_delay.h"
 #include "../all/bsp_mcu_api.h"

#endif
