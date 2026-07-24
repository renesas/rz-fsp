/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SELECT_IRQ_H
 #define BSP_SELECT_IRQ_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MCU
 *
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

 #define BSP_PRV_SELECT_IRQ_PER_REG     (3U)
 #define BSP_PRV_SELECT_IRQ_PER_BIT     (10U)

 #define BSP_PRV_SELECT_IRQSEL_MASK     (0x3FFU)
 #define BSP_PRV_SELECT_IRQSEL_CLEAR    (0x3FFU)

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/** @} (end addtogroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* BSP_SELECT_IRQ_H */
