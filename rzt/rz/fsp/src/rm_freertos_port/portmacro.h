/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef PORTMACRO_H
 #define PORTMACRO_H
 #include "bsp_api.h"
 #if defined(BSP_CFG_CORE_CA55)
  #include "ca55/portmacro_ca55.h"
 #endif                                /* BSP_CFG_CORE_CA55 */
 #if defined(BSP_CFG_CORE_CR52)
  #include "cr52/portmacro_cr52.h"
 #endif                                /* BSP_CFG_CORE_CR52 */
#endif                                 /* PORTMACRO_H */
