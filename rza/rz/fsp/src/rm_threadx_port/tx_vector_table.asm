/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

//==================================================================
// Entry point for the Reset handler
//==================================================================
#include "bsp_asm_cfg.h"

    .global  _tx_vector_table
    .extern  _tx_thread_context_save
    .extern  _tx_thread_context_restore

    .global  _tx_irq_handler
    .global  _tx_fiq_handler
    .global	 _tx_vector_table_set

    .section    IRQ_FIQ_HANDLER, "ax"
    .align 8
//******************************************************************************
// fiq_handler
//******************************************************************************
_tx_fiq_handler:
  MSR      SPSEL, #0

  STP      x29, x30, [sp, #-16]!

  BL       _tx_thread_context_save

#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
  MRS      x0, FPCR
  MRS      x1, FPSR
  STP      x0, x1, [SP, #-0x10]!
  STP      q30, q31, [SP, #-0x20]!
  STP      q28, q29, [SP, #-0x20]!
  STP      q26, q27, [SP, #-0x20]!
  STP      q24, q25, [SP, #-0x20]!
  STP      q22, q23, [SP, #-0x20]!
  STP      q20, q21, [SP, #-0x20]!
  STP      q18, q19, [SP, #-0x20]!
  STP      q16, q17, [SP, #-0x20]!
  STP      q14, q15, [SP, #-0x20]!
  STP      q12, q13, [SP, #-0x20]!
  STP      q10, q11, [SP, #-0x20]!
  STP      q8, q9, [SP, #-0x20]!
  STP      q6, q7, [SP, #-0x20]!
  STP      q4, q5, [SP, #-0x20]!
  STP      q2, q3, [SP, #-0x20]!
  STP      q0, q1, [SP, #-0x20]!
#endif

  BL       FIQ_ExecuteHandler

#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
  LDP      q0, q1, [sp], #0x20
  LDP      q2, q3, [sp], #0x20
  LDP      q4, q5, [sp], #0x20
  LDP      q6, q7, [sp], #0x20
  LDP      q8, q9, [sp], #0x20
  LDP      q10, q11, [sp], #0x20
  LDP      q12, q13, [sp], #0x20
  LDP      q14, q15, [sp], #0x20
  LDP      q16, q17, [sp], #0x20
  LDP      q18, q19, [sp], #0x20
  LDP      q20, q21, [sp], #0x20
  LDP      q22, q23, [sp], #0x20
  LDP      q24, q25, [sp], #0x20
  LDP      q26, q27, [sp], #0x20
  LDP      q28, q29, [sp], #0x20
  LDP      q30, q31, [sp], #0x20
  LDP      x0, x1, [sp], #0x10
  MSR      FPCR, x0
  MSR      FPSR, x1
#endif

  B        _tx_thread_context_restore

//******************************************************************************
// irq_handler
//******************************************************************************
_tx_irq_handler:
  MSR      SPSEL, #0

  STP      x29, x30, [sp, #-16]!

  BL       _tx_thread_context_save

#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
  MRS      x0, FPCR
  MRS      x1, FPSR
  STP      x0, x1, [SP, #-0x10]!
  STP      q30, q31, [SP, #-0x20]!
  STP      q28, q29, [SP, #-0x20]!
  STP      q26, q27, [SP, #-0x20]!
  STP      q24, q25, [SP, #-0x20]!
  STP      q22, q23, [SP, #-0x20]!
  STP      q20, q21, [SP, #-0x20]!
  STP      q18, q19, [SP, #-0x20]!
  STP      q16, q17, [SP, #-0x20]!
  STP      q14, q15, [SP, #-0x20]!
  STP      q12, q13, [SP, #-0x20]!
  STP      q10, q11, [SP, #-0x20]!
  STP      q8, q9, [SP, #-0x20]!
  STP      q6, q7, [SP, #-0x20]!
  STP      q4, q5, [SP, #-0x20]!
  STP      q2, q3, [SP, #-0x20]!
  STP      q0, q1, [SP, #-0x20]!
#endif

  BL       IRQ_ExecuteHandler

#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
  LDP      q0, q1, [sp], #0x20
  LDP      q2, q3, [sp], #0x20
  LDP      q4, q5, [sp], #0x20
  LDP      q6, q7, [sp], #0x20
  LDP      q8, q9, [sp], #0x20
  LDP      q10, q11, [sp], #0x20
  LDP      q12, q13, [sp], #0x20
  LDP      q14, q15, [sp], #0x20
  LDP      q16, q17, [sp], #0x20
  LDP      q18, q19, [sp], #0x20
  LDP      q20, q21, [sp], #0x20
  LDP      q22, q23, [sp], #0x20
  LDP      q24, q25, [sp], #0x20
  LDP      q26, q27, [sp], #0x20
  LDP      q28, q29, [sp], #0x20
  LDP      q30, q31, [sp], #0x20
  LDP      x0, x1, [sp], #0x10
  MSR      FPCR, x0
  MSR      FPSR, x1
#endif

  B        _tx_thread_context_restore


//******************************************************************************
// vector table
//******************************************************************************
    .section VECTOR_TABLE, "ax"
    .align 11

//
// Current EL with SP0
//
_tx_vector_table:
SyncSp0:
    B SyncSp0

    .balign 0x80
IrqSp0:
    B _tx_irq_handler

    .balign 0x80
FiqSp0:
    B _tx_fiq_handler

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


//******************************************************************************
// Setup vector table for ThreadX
//******************************************************************************
 _tx_vector_table_set:
	LDR		X1, =_tx_vector_table
#ifdef EL1
	MSR		VBAR_EL1, X1
#else
#ifdef EL2
	MSR		VBAR_EL2, X1
#else
	MSR		VBAR_EL3, X1
#endif
#endif
	DSB		SY
	ISB		SY

    RET

    .END

