/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#include "bsp_asm_cfg.h"
//==================================================================
// Entry point for the FIQ handler
//==================================================================
    .section    IRQ_FIQ_HANDLER, "ax"
    .align 8

    .extern  IRQ_ExecuteHandler
    .extern  FIQ_ExecuteHandler

    .global  irq_handler
    .global  fiq_handler

    .equ     DAIF_BIT_F, (1 << 0)

//******************************************************************************
// fiq_handler
//******************************************************************************
fiq_handler:

        MSR             SPSEL, #1

        STP             x29, x30, [SP, #-0x10]!
        STP             x18, x19, [SP, #-0x10]!
        STP             x16, x17, [SP, #-0x10]!
        STP             x14, x15, [SP, #-0x10]!
        STP             x12, x13, [SP, #-0x10]!
        STP             x10, x11, [SP, #-0x10]!
        STP             x8, x9, [SP, #-0x10]!
        STP             x6, x7, [SP, #-0x10]!
        STP             x4, x5, [SP, #-0x10]!
        STP             x2, x3, [SP, #-0x10]!
        STP             x0, x1, [SP, #-0x10]!
#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
        MRS             x0, FPCR
        MRS             x1, FPSR
        STP             x0, x1, [SP, #-0x10]!
        MOV             x0, #-0x40

        /* Reserve for 4 Q regsiters */
        SUB             SP, SP, #0x40
        /* Store all 32 Q registers using LD1 (8 groups of 4 registers) */
        ST1             {v28.2d, v29.2d, v30.2d, v31.2d}, [SP], x0
        ST1             {v24.2d, v25.2d, v26.2d, v27.2d}, [SP], x0
        ST1             {v20.2d, v21.2d, v22.2d, v23.2d}, [SP], x0
        ST1             {v16.2d, v17.2d, v18.2d, v19.2d}, [SP], x0
        ST1             {v12.2d, v13.2d, v14.2d, v15.2d}, [SP], x0
        ST1             {v8.2d, v9.2d, v10.2d, v11.2d}, [SP], x0
        ST1             {v4.2d, v5.2d, v6.2d, v7.2d}, [SP], x0
        ST1             {v0.2d, v1.2d, v2.2d, v3.2d}, [SP]
#endif
        /* Save the SPSR and ELR. */
        MRS             x3, SPSR_EL3
        MRS             x2, ELR_EL3
        STP             x2, x3, [sp, #-0x10]!

        BL              FIQ_ExecuteHandler

        MSR             DAIFSET, #DAIF_BIT_F

        /* Restore volatile registers. */
        LDP             x4, x5, [sp], #0x10     /* SPSR and ELR. */

        MSR             SPSR_EL3, x5
        MSR             ELR_EL3, x4

        DMB             SY
        ISB             SY

#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))

        /* Restore all 32 Q registers using LD1 (8 groups of 4 registers) */
        LD1             {v0.2d, v1.2d, v2.2d, v3.2d}, [SP], #0x40
        LD1             {v4.2d, v5.2d, v6.2d, v7.2d}, [SP], #0x40
        LD1             {v8.2d, v9.2d, v10.2d, v11.2d}, [SP], #0x40
        LD1             {v12.2d, v13.2d, v14.2d, v15.2d}, [SP], #0x40
        LD1             {v16.2d, v17.2d, v18.2d, v19.2d}, [SP], #0x40
        LD1             {v20.2d, v21.2d, v22.2d, v23.2d}, [SP], #0x40
        LD1             {v24.2d, v25.2d, v26.2d, v27.2d}, [SP], #0x40
        LD1             {v28.2d, v29.2d, v30.2d, v31.2d}, [SP], #0x40

        /* Restore FPCR and FPSR */
        LDP             x0, x1, [SP], #0x10
        MSR             FPCR, x0
        MSR             FPSR, x1

#endif
        LDP             x0, x1, [sp], #0x10
        LDP             x2, x3, [sp], #0x10
        LDP             x4, x5, [sp], #0x10
        LDP             x6, x7, [sp], #0x10
        LDP             x8, x9, [sp], #0x10
        LDP             x10, x11, [sp], #0x10
        LDP             x12, x13, [sp], #0x10
        LDP             x14, x15, [sp], #0x10
        LDP             x16, x17, [sp], #0x10
        LDP             x18, x19, [sp], #0x10
        LDP             x29, x30, [sp], #0x10

        ERET

//******************************************************************************
// irq_handler
//******************************************************************************
irq_handler:

        MSR             SPSEL, #1

        STP     x0, x1, [sp, #-0x10]!
        STP     x2, x3, [sp, #-0x10]!
        STP     x4, x5, [sp, #-0x10]!
        STP     x6, x7, [sp, #-0x10]!
        STP     x8, x9, [sp, #-0x10]!
        STP     x10, x11, [sp, #-0x10]!
        STP     x12, x13, [sp, #-0x10]!
        STP     x14, x15, [sp, #-0x10]!
        STP     x16, x17, [sp, #-0x10]!
        STP     x18, x19, [sp, #-0x10]!
        STP     x29, x30, [sp, #-0x10]!
#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
        MRS     x0, FPCR
        MRS     x1, FPSR
        STP     x0, x1, [SP, #-0x10]!
        STP     q30, q31, [SP, #-0x20]!
        STP     q28, q29, [SP, #-0x20]!
        STP     q26, q27, [SP, #-0x20]!
        STP     q24, q25, [SP, #-0x20]!
        STP     q22, q23, [SP, #-0x20]!
        STP     q20, q21, [SP, #-0x20]!
        STP     q18, q19, [SP, #-0x20]!
        STP     q16, q17, [SP, #-0x20]!
        STP     q14, q15, [SP, #-0x20]!
        STP     q12, q13, [SP, #-0x20]!
        STP     q10, q11, [SP, #-0x20]!
        STP     q8, q9, [SP, #-0x20]!
        STP     q6, q7, [SP, #-0x20]!
        STP     q4, q5, [SP, #-0x20]!
        STP     q2, q3, [SP, #-0x20]!
        STP     q0, q1, [SP, #-0x20]!
#endif

        /* Save the SPSR and ELR. */
//;     MRS     x3, SPSR_EL3
//;     MRS     x2, ELR_EL3
//;     STP     x2, x3, [sp, #-0x10]!
//;
//;     LDR     x5, g_interrupt_nesting_count
//;     LDR     x1, [x5]
//;     ADD     x6, x1, #1
//;     STR     x6, [x5]
//;
//;     STP     x1, x5, [sp, #-0x10]!
//;
//;     mrs     x0, ICC_IAR1_EL1
//;
//;     STP     x0, x1, [sp, #-0x10]!

        BL      IRQ_ExecuteHandler

//;     MSR     DAIFSET, #2
//;     DSB     SY
//;     ISB     SY
//;
//;     LDP     x0, x1, [sp], #0x10
//;
//;     /* End IRQ processing by writing ICCIAR to the EOI register */
//;     msr     ICC_EOIR1_EL1, x0
//;
//;     /* Restore the critical nesting count */
//;     LDP     x1, x5, [sp], #0x10
//;     STR     x1, [x5]
//;
//;     /* Restore volatile registers. */
//;     LDP     x4, x5, [sp], #0x10     /* SPSR and ELR. */
//;
//;     MSR     SPSR_EL3, x5
//;     MSR     ELR_EL3, x4
//;
//;     DSB     SY
//;     ISB     SY

#if ((__FPU_USED || __ARM_NEON) && (BSP_CFG_FPU_REGISTERS_SAVING))
        LDP     q0, q1, [sp], #0x20
        LDP     q2, q3, [sp], #0x20
        LDP     q4, q5, [sp], #0x20
        LDP     q6, q7, [sp], #0x20
        LDP     q8, q9, [sp], #0x20
        LDP     q10, q11, [sp], #0x20
        LDP     q12, q13, [sp], #0x20
        LDP     q14, q15, [sp], #0x20
        LDP     q16, q17, [sp], #0x20
        LDP     q18, q19, [sp], #0x20
        LDP     q20, q21, [sp], #0x20
        LDP     q22, q23, [sp], #0x20
        LDP     q24, q25, [sp], #0x20
        LDP     q26, q27, [sp], #0x20
        LDP     q28, q29, [sp], #0x20
        LDP     q30, q31, [sp], #0x20
        LDP     x0, x1, [sp], #0x10
        MSR     FPCR, x0
        MSR     FPSR, x1
#endif
        LDP     x29, x30, [sp], #0x10
        LDP     x18, x19, [sp], #0x10
        LDP     x16, x17, [sp], #0x10
        LDP     x14, x15, [sp], #0x10
        LDP     x12, x13, [sp], #0x10
        LDP     x10, x11, [sp], #0x10
        LDP     x8, x9, [sp], #0x10
        LDP     x6, x7, [sp], #0x10
        LDP     x4, x5, [sp], #0x10
        LDP     x2, x3, [sp], #0x10
        LDP     x0, x1, [sp], #0x10

        ERET

    .END