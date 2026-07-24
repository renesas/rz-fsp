/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#if defined(__GNUC__)
 #include \
    "../../aws/FreeRTOS-Plus-TCP/source/portable/Compiler/GCC/pack_struct_end.h"
#elif defined(__IAR_SYSTEMS_ICC__)
 #include \
    "../../aws/FreeRTOS-Plus-TCP/source/portable/Compiler/IAR/pack_struct_end.h"

/* Check Pe1644 error (definition at end of file not followed by a semicolon or a declarator). */
 #pragma diag_default=Pe1644
#elif defined(__CC_ARM)
 #include \
    "../../aws/FreeRTOS-Plus-TCP/source/portable/Compiler/Keil/pack_struct_end.h"
#else
 #error Unknown compiler.
#endif
