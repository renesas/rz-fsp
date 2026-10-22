/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#if defined(__GNUC__)
 #include \
    "../../../aws/FreeRTOS-Plus-TCP/source/portable/Compiler/GCC/pack_struct_start.h"
#elif defined(__IAR_SYSTEMS_ICC__)
 #include \
    "../../../aws/FreeRTOS-Plus-TCP/source/portable/Compiler/IAR/pack_struct_start.h"
#elif defined(__CC_ARM)
 #include \
    "../../../aws/FreeRTOS-Plus-TCP/source/portable/Compiler/Keil/pack_struct_start.h"
#else
 #error Unknown compiler.
#endif
