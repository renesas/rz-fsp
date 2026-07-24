/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

    .extern  __FiqStackLimit     // Linker symbol from scatter file
    .extern  __IrqStackLimit     // Linker symbol from scatter file
    .extern  __SvcStackLimit     // Linker symbol from scatter file
    .extern  __SysStackLimit     // Linker symbol from scatter file
    .extern  __UndStackLimit     // Linker symbol from scatter file
    .extern  __AbtStackLimit     // Linker symbol from scatter file

    .extern  bsp_common_interrupt_handler
    .extern  SystemInit
    .extern  IRQ_Handler
    .extern  main

    .arm
    .section  .int_handler,"ax"

    .global Reset_Handler
    .type Reset_Handler, "function"
Reset_Handler:
// =========================================================================
// Enable DTCM (Mapped to 0x20000)
// =========================================================================
    mov r0, #0x00020000
    orr r0, #0x21
    mcr p15, #0, r0, c9, c1, 0

// =========================================================================
// Initialize stacks
// =========================================================================
    cps  #17    /* FIQ mode */
    ldr  r0, =__FiqStackLimit
    mov sp, r0

    cps  #18    /* IRQ mode */
    ldr  r0, =__IrqStackLimit
    mov sp, r0

    cps  #23    /* Abort mode */
    ldr  r0, =__AbtStackLimit
    mov sp, r0

    cps  #27    /* Undef mode */
    ldr  r0, =__UndStackLimit
    mov sp, r0

    cps  #31    /* System mode */
    ldr  r0, =__SysStackLimit
    mov sp, r0

    cps  #19    /* SVC mode */
    ldr  r0, =__SvcStackLimit
    mov sp, r0

// =========================================================================
// Enable FPU and Advanced SIMD
// =========================================================================
    /* Enables cp10 and cp11 accessing */
    mrc  p15, #0, r0, c1, c0, #2
    orr  r0, r0, #0xF00000
    mcr  p15, #0, r0, c1, c0, #2
    isb

    /* Enables the FPU */
    vmrs r0, fpexc
    orr  r0, r0, #0x40000000
    vmsr  fpexc, r0
    isb

// =========================================================================
// Branch to C library entry point
// =========================================================================
    bl   SystemInit                 //;; Branch to SytemInit */

    bl   main                       //;; Branch to C library entry point */

Exit_Loop:
    b    Exit_Loop


// =========================================================================
// Handlers for vector
// =========================================================================
    .global Default_Handler
    .type Default_Handler, "function"
Default_Handler:
    b Default_Handler

    .weak  Undefined_Handler
    .type Undefined_Handler, "function"
Undefined_Handler:
    b Undefined_Handler

    .weak  SVC_Handler
    .type SVC_Handler, "function"
SVC_Handler:
    b SVC_Handler

    .weak  Prefetch_Handler
    .type Prefetch_Handler, "function"
Prefetch_Handler:
    b Prefetch_Handler

    .weak  Abort_Handler
    .type Abort_Handler, "function"
Abort_Handler:
    b Abort_Handler

    .weak  Reserved_Handler
    .type Reserved_Handler, "function"
Reserved_Handler:
    b Reserved_Handler

    .weak  FIQ_Handler
    .type FIQ_Handler, "function"
FIQ_Handler:
    b FIQ_Handler

// =========================================================================
// vector table
// =========================================================================
    .section  .intvec,"ax"

vector_table:
    ldr pc,=Reset_Handler
    ldr pc,=Undefined_Handler
    ldr pc,=SVC_Handler
    ldr pc,=Prefetch_Handler
    ldr pc,=Abort_Handler
    ldr pc,=Reserved_Handler
    ldr pc,=IRQ_Handler
    ldr pc,=FIQ_Handler
