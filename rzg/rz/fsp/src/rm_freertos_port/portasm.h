/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef PORTASM_H
 #define PORTASM_H
 #include "bsp_api.h"
 #if BSP_SUPPORT_CORE_CM33
  #include "cm33/portasm_cm33.h"
 #endif                                /* BSP_SUPPORT_CORE_CM33 */
#endif                                 /* PORTASM_H */
