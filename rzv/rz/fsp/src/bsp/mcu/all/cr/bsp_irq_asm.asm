/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

    .arm
    .section  .int_handler,"ax"

    .weak   IRQ_Handler
    .global IRQ_Handler
    .type IRQ_Handler, %function
IRQ_Handler:
    sub     lr, lr, #4
    srsdb   sp!, #31           /* Store LR_irq and SPSR_irq in system mode stack. */
    cps     #31                /* Switch to system mode. */
    push    {r0-r3, r12}       /* Store other AAPCS registers. */

    vmrs    r0, fpscr
    stmdb   sp!, {r0}           /* Store fpscr register. */
    sub     sp, sp, #4
    vpush   {d0-d15}            /* Store fpu registers. */

    ldr     r1, =0x12c10118     /* Read ICCHPIR to r3. */
    ldr     r3, [r1]
    ldr     r2, =0x12c1010c     /* Read ICCIAR to r0. */
    ldr     r0, [r2]

    push    {r0}                /* Store the INTID. */
    mov     r1, sp              /* Make alignment for stack. */
    and     r1, r1, #4
    sub     sp, sp, r1
    push    {r1, lr}

    ldr     r1,=bsp_common_interrupt_handler
    blx     r1                  /* Jump to bsp_common_interrupt_handler, First argument (r0) is ICC_IAR1 read value. */

    pop     {r1, lr}
    add     sp, sp, r1
    pop     {r0}                /* Restore the INTID to r0. */

    ldr     r1, =0x12c10110     /* Write INTID to EOIR. */
    str     r0, [r1]

    vpop    {d0-d15}            /* Restore fpu registers. */
    add     sp, sp, #4
    pop     {r0}
    vmsr    fpscr, r0           /* Restore fpscr register. */

    pop     {r0-r3, r12}        /* Restore registers. */
    rfeia   sp!                 /* Return from system mode tack using RFE. */

