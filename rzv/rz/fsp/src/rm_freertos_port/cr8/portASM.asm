;/*
; * FreeRTOS Kernel V10.4.3 LTS Patch 2
; * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
; *
; * Permission is hereby granted, free of charge, to any person obtaining a copy of
; * this software and associated documentation files (the "Software"), to deal in
; * the Software without restriction, including without limitation the rights to
; * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
; * the Software, and to permit persons to whom the Software is furnished to do so,
; * subject to the following conditions:
; *
; * The above copyright notice and this permission notice shall be included in all
; * copies or substantial portions of the Software.
; *
; * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
; * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
; * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
; * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
; * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
; *
; * http://www.FreeRTOS.org
; * https://github.com/FreeRTOS
; *
; */

#if (defined(__VFP_FP__) && !defined(__SOFTFP__))
/* Use FPU context for all tasks */
#define configUSE_TASK_FPU_SUPPORT 2
#else
/* Disable the FPU */
#define configUSE_TASK_FPU_SUPPORT 0
#endif

    .text
    .arm

    .set SYS_MODE,  0x1f
    .set SVC_MODE,  0x13
    .set IRQ_MODE,  0x12

    /* Variables and functions. */
    .extern pxCurrentTCB
    .extern vTaskSwitchContext
    .extern FreeRTOS_GetActiveIRQ
    .extern vApplicationIRQHandler
    .extern FreeRTOS_EndOfInterrupt
    .extern ulPortTaskHasFPUContext
    .extern ulCriticalNesting

    .global IRQ_Handler
    .global SVC_Handler
    .global vPortRestoreTaskContext

.macro portSAVE_CONTEXT

    /* Save the LR and SPSR onto the system mode stack before switching to
    system mode to save the remaining system mode registers. */
    SRSDB   sp!, #SYS_MODE
    CPS     #SYS_MODE
    PUSH    {R0-R12, R14}

    /* Push the critical nesting count. */
    LDR     R2, =ulCriticalNesting
    LDR     R1, [R2]
    PUSH    {R1}

#if (configUSE_TASK_FPU_SUPPORT != 0)
    /* Does the task have a floating point context that needs saving?  If
    ulPortTaskHasFPUContext is 0 then no. */
    LDR     R2, =ulPortTaskHasFPUContext
    LDR     R3, [R2]
    CMP     R3, #0

    /* Save the floating point context, if any. */
    FMRXNE  R1,  FPSCR
    VPUSHNE {D0-D15}
#if configFPU_D32 == 1
    VPUSHNE {D16-D31}
#endif /* configFPU_D32 */
    PUSHNE  {R1}

    /* Save ulPortTaskHasFPUContext itself. */
    PUSH    {R3}
#endif /* (configUSE_TASK_FPU_SUPPORT != 0) */

    /* Save the stack pointer in the TCB. */
    LDR     R0, =pxCurrentTCB
    LDR     R1, [R0]
    STR     SP, [R1]

    .endm

; /**********************************************************************/

.macro portRESTORE_CONTEXT

    /* Set the SP to point to the stack of the task being restored. */
    LDR     R0, =pxCurrentTCB
    LDR     R1, [R0]
    LDR     SP, [R1]

#if (configUSE_TASK_FPU_SUPPORT != 0)
    /* Is there a floating point context to restore?  If the restored
    ulPortTaskHasFPUContext is zero then no. */
    LDR     R0, =ulPortTaskHasFPUContext
    POP     {R1}
    STR     R1, [R0]
    CMP     R1, #0

    /* Restore the floating point context, if any. */
    POPNE   {R0}
#if configFPU_D32 == 1
    VPOPNE  {D16-D31}
#endif /* configFPU_D32 */
    VPOPNE  {D0-D15}
    VMSRNE  FPSCR, R0
#endif /* (configUSE_TASK_FPU_SUPPORT != 0) */

    /* Restore the critical section nesting depth. */
    LDR     R0, =ulCriticalNesting
    POP     {R1}
    STR     R1, [R0]

    /* Restore all system mode registers other than the SP (which is already
    being used). */
    POP     {R0-R12, R14}

    /* Return to the task code, loading CPSR on the way. */
    RFEIA   sp!

    .endm




/******************************************************************************
 * SVC handler is used to start the scheduler.
 *****************************************************************************/
.align 4
.type SVC_Handler, %function
SVC_Handler:
    /* Save the context of the current task and select a new task to run. */
    portSAVE_CONTEXT
    LDR R0, =vTaskSwitchContext
    BLX R0
    portRESTORE_CONTEXT


/******************************************************************************
 * vPortRestoreTaskContext is used to start the scheduler.
 *****************************************************************************/
.type vPortRestoreTaskContext, %function
vPortRestoreTaskContext:
    /* Switch to system mode. */
    CPS     #SYS_MODE
    DSB
    ISB
    portRESTORE_CONTEXT

.align 4
.type IRQ_Handler, %function
IRQ_Handler:

    /* Return to the interrupted instruction. */
    SUB     lr, lr, #4

    /* Push the return address and SPSR. */
    PUSH    {lr}
    MRS     lr, SPSR
    PUSH    {lr}

    /* Change to supervisor mode to allow reentry. */
    CPS     #SVC_MODE

    /* Push used registers. */
    PUSH    {r0-r4, r12}

    /* Ensure bit 2 of the stack pointer is clear.  r2 holds the bit 2 value for
    future use.  */
    MOV     r2, sp
    AND     r2, r2, #4
    SUB     sp, sp, r2
    PUSH    {r2}

    BLX     FreeRTOS_GetActiveIRQ
    MOV     r4, r0

    BLX     vApplicationIRQHandler

    CPSID   i
    DSB
    ISB

    MOV     r0, r4
    BLX     FreeRTOS_EndOfInterrupt

    /* Restore spack pointer */
    POP     {r2}
    ADD     sp, sp, r2

    /* Did the interrupt request a context switch?  r1 holds the address of
    ulPortYieldRequired and r0 the value of ulPortYieldRequired for future
    use. */
    LDR     r1, =ulPortYieldRequired
    LDR     r0, [r1]
    CMP     r0, #0
    BNE     switch_before_exit

exit_without_switch:
    /* No context switch.  Restore used registers, LR_irq and SPSR before
    returning. */
    POP     {r0-r4, r12}
    CPS     #IRQ_MODE
    POP     {LR}
    MSR     SPSR_cxsf, LR
    POP     {LR}
    MOVS    PC, LR

switch_before_exit:
    /* A context swtich is to be performed.  Clear the context switch pending
    flag. */
    MOV     r0, #0
    STR     r0, [r1]

    /* Restore used registers, LR-irq and SPSR before saving the context
    to the task stack. */
    POP     {r0-r4, r12}
    CPS     #IRQ_MODE
    POP     {LR}
    MSR     SPSR_cxsf, LR
    POP     {LR}
    portSAVE_CONTEXT

    /* Call the function that selects the new task to execute.
    vTaskSwitchContext() if vTaskSwitchContext() uses LDRD or STRD
    instructions, or 8 byte aligned stack allocated data.  LR does not need
    saving as a new LR will be loaded by portRESTORE_CONTEXT anyway. */
    LDR     R0, =vTaskSwitchContext
    BLX     R0

    /* Restore the context of, and branch to, the task selected to execute
    next. */
    portRESTORE_CONTEXT

vApplicationIRQHandlerConst: .word vApplicationIRQHandler

.end





