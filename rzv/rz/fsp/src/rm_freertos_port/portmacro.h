/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef PORTMACRO_H
 #define PORTMACRO_H
 #include "bsp_api.h"
 #if BSP_SUPPORT_CORE_CM33
  #include "cm33/portmacro_cm33.h"
 #endif                                /* BSP_SUPPORT_CORE_CM33 */
 #if BSP_SUPPORT_CORE_CR8
  #include "cr8/portmacro_cr8.h"
 #endif                                /* BSP_SUPPORT_CORE_CR8 */
#endif                                 /* PORTMACRO_H */
