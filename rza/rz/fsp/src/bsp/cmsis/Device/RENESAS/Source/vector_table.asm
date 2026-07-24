/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

//==================================================================
// Entry point for the Reset handler
//==================================================================

    .section VECTOR_TABLE, "ax"
    .align 11

    .global Start
    .global vector_table

    .extern irq_handler
    .extern fiq_handler

//
// Current EL with SP0
//
vector_table:
SyncSp0:
    B SyncSp0

    .balign 0x80
IrqSp0:
    B irq_handler

    .balign 0x80
FiqSp0:
    B fiq_handler

    .balign 0x80
SerrSp0:
    WFI
    B SerrSp0
    .balign 0x80

//
// Current EL with SPx
//

SyncSpx:
    B SyncSpx

    .balign 0x80

IrqSpx:
    B irq_handler

    .balign 0x80
FiqSpx:
    B fiq_handler

    .balign 0x80
SerrSpx:
    WFI
    B SerrSpx

    .balign 0x80
//
// Lower EL using AArch64
//
SyncLowEl64:
    WFI
    B   SyncLowEl64

    .balign 0x80
IrqLowEl64:
    WFI
    B   IrqLowEl64

    .balign 0x80
FiqLowEl64:
    WFI
    B   FiqLowEl64

    .balign 0x80
SerrorLowEl64:
    WFI
    B   SerrorLowEl64

    .balign 0x80
//
// Lower EL using AArch32
//

SyncLowEl32:
    WFI
    B   SyncLowEl32

    .balign 0x80
IrqLowEl32:
    WFI
    B   IrqLowEl32

    .balign 0x80
FiqLowEl32:
    WFI
    B   FiqLowEl32

    .balign 0x80
SerrorLowEl32:
    WFI
    B   SerrorLowEl32

    .balign 0x80

    .END
