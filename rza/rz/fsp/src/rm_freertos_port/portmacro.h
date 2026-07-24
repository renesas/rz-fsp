/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef PORTMACRO_H
 #define PORTMACRO_H
 #include "bsp_api.h"
 #if defined(RZA_H)
  #include "ca55/portmacro_ca55.h"
 #endif                                /* RZA_H */
 #if BSP_SUPPORT_CORE_CM33
  #include "cm33/portmacro_cm33.h"
 #endif                                /* BSP_SUPPORT_CORE_CM33 */
 #if BSP_SUPPORT_CORE_CR8
  #include "cr8/portmacro_cr8.h"
 #endif                                /* BSP_SUPPORT_CORE_CR8 */
 #if defined(BSP_CFG_CORE_CA55)
  #include "ca55/portmacro_ca55.h"
 #endif                                /* BSP_CFG_CORE_CA55 */
 #if defined(BSP_CFG_CORE_CR52)
  #include "cr52/portmacro_cr52.h"
 #endif                                /* BSP_CFG_CORE_CR52 */
#endif                                 /* PORTMACRO_H */
