/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MHU_H
 #define BSP_MHU_H

 #include "bsp_api.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZG
{
  #endif
 #endif

/**********************************************************************************************************************
 * @addtogroup RZG_BSP_MPU_RZG3L
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

extern uint32_t R_BSP_IntStatusControlGet(fsp_ip_t ip, uint8_t channel, IRQn_Type irq);

void     R_BSP_MHU_ContextSet(IRQn_Type const irq, uint32_t ch, void * p_context);
void   * R_BSP_MHU_ContextGet(IRQn_Type const irq, uint32_t ch);
uint32_t R_BSP_MHU_CurrentChannelGet(IRQn_Type const irq);

/** @} (end addtogroup RZG_BSP_MPU_RZG3L) */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif                                 /* BSP_MHU_H */
