/*
 * FreeRTOS Kernel <DEVELOPMENT BRANCH>
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"

/* UNCRUSTIFY-OFF */
#ifndef configUNIQUE_INTERRUPT_PRIORITIES
 #error configUNIQUE_INTERRUPT_PRIORITIES must be defined.  See https://www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html
#endif

#ifndef configMAX_API_CALL_INTERRUPT_PRIORITY
 #error configMAX_API_CALL_INTERRUPT_PRIORITY must be defined.  See https://www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html
#endif
/* UNCRUSTIFY-ON */

#if configMAX_API_CALL_INTERRUPT_PRIORITY == 0
 #error configMAX_API_CALL_INTERRUPT_PRIORITY must not be set to 0
#endif

#if configMAX_API_CALL_INTERRUPT_PRIORITY > configUNIQUE_INTERRUPT_PRIORITIES
 #error \
    configMAX_API_CALL_INTERRUPT_PRIORITY must be less than or equal to configUNIQUE_INTERRUPT_PRIORITIES as the lower the numeric priority value the higher the logical interrupt priority
#endif

#if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1

/* Check the configuration. */
 #if (configMAX_PRIORITIES > 32)
  #error \
    configUSE_PORT_OPTIMISED_TASK_SELECTION can only be set to 1 when configMAX_PRIORITIES is less than or equal to 32.  It is very rare that a system requires more than 10 to 15 difference priorities as tasks that share a priority will time slice.
 #endif
#endif                                 /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

/* In case security extensions are implemented. */
#if configMAX_API_CALL_INTERRUPT_PRIORITY <= (configUNIQUE_INTERRUPT_PRIORITIES / 2)

// #error configMAX_API_CALL_INTERRUPT_PRIORITY must be greater than ( configUNIQUE_INTERRUPT_PRIORITIES / 2 )
#endif

/* Some vendor specific files default configCLEAR_TICK_INTERRUPT() in
 * portmacro.h. */
#ifndef configCLEAR_TICK_INTERRUPT
 #define configCLEAR_TICK_INTERRUPT()
#endif

/* A critical section is exited when the critical section nesting count reaches
 * this value. */
#define portNO_CRITICAL_NESTING          ((size_t) 0)

/* In all GICs 255 can be written to the priority mask register to unmask all
 * (but the lowest) interrupt priority. */
#define portUNMASK_VALUE                 (0xFFUL)

/* Tasks are not created with a floating point context, but can be given a
 * floating point context after they have been created.  A variable is stored as
 * part of the tasks context that holds portNO_FLOATING_POINT_CONTEXT if the task
 * does not have an FPU context, or any other value if the task does have an FPU
 * context. */
#define portNO_FLOATING_POINT_CONTEXT    ((StackType_t) 0)

/* Constants required to setup the initial task context. */
#define portSP_ELx                       ((StackType_t) 0x01)
#define portSP_EL0                       ((StackType_t) 0x00)

#if defined(GUEST)
 #define portEL1                         ((StackType_t) 0x04)
 #define portINITIAL_PSTATE              (portEL1 | portSP_EL0)
#else
 #define portEL3                         ((StackType_t) 0x0c)

/* At the time of writing, the BSP only supports EL3. */
 #define portINITIAL_PSTATE              (portEL3 | portSP_EL0)
#endif

/* Masks all bits in the APSR other than the mode bits. */
#define portAPSR_MODE_BITS_MASK          (0x0C)

/* The I bit in the DAIF bits. */
#define portDAIF_F                       (0x40)

/* Macro to unmask all interrupt priorities. */
/* s3_0_c4_c6_0 is ICC_PMR_EL1. */
#define portCLEAR_INTERRUPT_MASK()                  \
    {                                               \
        __asm volatile ("MSR DAIFSET, #1        \n" \
                        "DSB SY					\n" \
                        "ISB SY					\n" \
                        "MSR s3_0_c4_c6_0, %0   \n" \
                        "DSB SY					\n" \
                        "ISB SY					\n" \
                        "MSR DAIFCLR, #1        \n" \
                        "DSB SY					\n" \
                        "ISB SY					\n" \
                        ::"r" (portUNMASK_VALUE));  \
    }

/* Timeout count for Setup the timer. */
#define portTIMERSETUP_TIMEOUT    (10)

/*-----------------------------------------------------------*/

/* Generic Timer Registers */
#define GENERIC_TIMER_CLK         (R_GSC->CNTFID0)
#define CNTFRQ_READ()         __get_CNTFRQ()
#define CNTPCT_READ()         __get_CNTPCT()
#define CNTP_CTL_WRITE(v)     __set_CNTP_CTL(v)
#define CNTP_CVAL_READ()      __get_CNTP_CVAL()
#define CNTP_CVAL_WRITE(v)    __set_CNTP_CVAL(v)
static uint32_t g_timer_delay;

/*
 * Starts the first task executing.  This function is necessarily written in
 * assembly code so is implemented in portASM.s.
 */
extern void vPortRestoreTaskContext(void);

extern fsp_vector_t g_sgi_ppi_vector_table[BSP_CORTEX_VECTOR_TABLE_ENTRIES];

extern void * volatile pxCurrentTCB;
extern void vTaskSwitchContext(void);
extern void FIQ_ExecuteHandler(void);

/*
 * Exception handlers.
 */
void Generic_Timer_Interrupt_Handler(void);

/*
 * Setup the timer to generate the tick interrupts.  The implementation in this
 * file is weak to allow application writers to change the timer used to
 * generate the tick interrupt.
 */
void vPortSetupTimerInterrupt(void);

void SyncSp0_Handler(void);
void FreeRTOS_Abort(void);
void vPortRestoreTaskContext(void);
void FIQ_Handler(void);
void Exit_IRQ_No_Context_Switch(void);

/*-----------------------------------------------------------*/

/* A variable is used to keep track of the critical section nesting.  This
 * variable has to be stored as part of the task context and must be initialised to
 * a non zero value to ensure interrupts don't inadvertently become unmasked before
 * the scheduler starts.  As it is stored as part of the task context it will
 * automatically be set to 0 when the first task is started. */
volatile uint64_t ullCriticalNesting = UCN0;

/* Saved as part of the task context.  If ullPortTaskHasFPUContext is non-zero
 * then floating point context must be saved and restored for the task. */
uint64_t ullPortTaskHasFPUContext = pdFALSE;

/* Set to 1 to pend a context switch from an ISR. */
uint64_t ullPortYieldRequired = pdFALSE;

/* Counts the interrupt nesting depth.  A context switch is only performed if
 * if the nesting depth is 0. */
uint64_t ullPortInterruptNesting = 0;

/* Used in the ASM code. */
__attribute__((used)) const uint64_t ullMaxAPIPriorityMask =
    (configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT);

/*-----------------------------------------------------------*/
#define portSAVE_CONTEXT_1()                                                    \
    {                                                                           \
        __asm volatile (                                                        \
            "MSR    SPSEL, #0                                               \n" \
            "STP    X0, X1, [SP, #-0x10]!                                   \n" \
            "STP    X2, X3, [SP, #-0x10]!                                   \n" \
            "STP    X4, X5, [SP, #-0x10]!                                   \n" \
            "STP    X6, X7, [SP, #-0x10]!                                   \n" \
            "STP    X8, X9, [SP, #-0x10]!                                   \n" \
            "STP    X10, X11, [SP, #-0x10]!                                 \n" \
            "STP    X12, X13, [SP, #-0x10]!                                 \n" \
            "STP    X14, X15, [SP, #-0x10]!                                 \n" \
            "STP    X16, X17, [SP, #-0x10]!                                 \n" \
            "STP    X18, X19, [SP, #-0x10]!                                 \n" \
            "STP    X20, X21, [SP, #-0x10]!                                 \n" \
            "STP    X22, X23, [SP, #-0x10]!                                 \n" \
            "STP    X24, X25, [SP, #-0x10]!                                 \n" \
            "STP    X26, X27, [SP, #-0x10]!                                 \n" \
            "STP    X28, X29, [SP, #-0x10]!                                 \n" \
            "STP    X30, XZR, [SP, #-0x10]!                                 \n" \
            ::: "memory");                                                      \
    }

#define portSAVE_CONTEXT_2_EL1()                                                \
    {                                                                           \
        __asm volatile (                                                        \
            /* Save the SPSR. */                                                \
            "MRS    X3, SPSR_EL1                                            \n" \
            /* Save the ELR. */                                                 \
            "MRS    X2, ELR_EL1                                             \n" \
            ::: "memory");                                                      \
    }

#define portSAVE_CONTEXT_2_EL3()                                                \
    {                                                                           \
        __asm volatile (                                                        \
            /* Save the SPSR. */                                                \
            "MRS    X3, SPSR_EL3                                            \n" \
            /* Save the ELR. */                                                 \
            "MRS    X2, ELR_EL3                                             \n" \
            ::: "memory");                                                      \
    }

#define portSAVE_CONTEXT_3()                                                        \
    {                                                                               \
        __asm volatile (                                                            \
            "STP    X2, X3, [SP, #-0x10]!                                   \n"     \
            /* Save the critical section nesting depth. */                          \
            "LDR    X0, =ullCriticalNesting                                 \n"     \
            "LDR    X3, [X0]                                                \n"     \
            /* Save the FPU context indicator. */                                   \
            "LDR    X0, =ullPortTaskHasFPUContext                           \n"     \
            "LDR    X2, [X0]                                                \n"     \
            /* Save the FPU context, if any (32 128-bit registers). */              \
            "CMP    X2, #0                                                  \n"     \
            "B.EQ   1f                                                      \n"     \
            "STP    Q0, Q1, [SP,#-0x20]!                                    \n"     \
            "STP    Q2, Q3, [SP,#-0x20]!                                    \n"     \
            "STP    Q4, Q5, [SP,#-0x20]!                                    \n"     \
            "STP    Q6, Q7, [SP,#-0x20]!                                    \n"     \
            "STP    Q8, Q9, [SP,#-0x20]!                                    \n"     \
            "STP    Q10, Q11, [SP,#-0x20]!                                  \n"     \
            "STP    Q12, Q13, [SP,#-0x20]!                                  \n"     \
            "STP    Q14, Q15, [SP,#-0x20]!                                  \n"     \
            "STP    Q16, Q17, [SP,#-0x20]!                                  \n"     \
            "STP    Q18, Q19, [SP,#-0x20]!                                  \n"     \
            "STP    Q20, Q21, [SP,#-0x20]!                                  \n"     \
            "STP    Q22, Q23, [SP,#-0x20]!                                  \n"     \
            "STP    Q24, Q25, [SP,#-0x20]!                                  \n"     \
            "STP    Q26, Q27, [SP,#-0x20]!                                  \n"     \
            "STP    Q28, Q29, [SP,#-0x20]!                                  \n"     \
            "STP    Q30, Q31, [SP,#-0x20]!                                  \n"     \
            "1:                                                                 \n" \
            /* Store the critical nesting count and FPU context indicator. */       \
            "STP    X2, X3, [SP, #-0x10]!                                   \n"     \
            "LDR    X0, =pxCurrentTCB                                       \n"     \
            "LDR    X1, [X0]                                                \n"     \
            "MOV    X0, SP                \n" /* Move SP into X0 for saving. */     \
            "STR    X0, [X1]                                                \n"     \
            /* Switch to use the ELx stack pointer. */                              \
            "MSR    SPSEL, #1                                               \n"     \
            ::: "memory");                                                          \
    }

#define portRESTORE_CONTEXT_1()                                                              \
    {                                                                                        \
        __asm volatile (                                                                     \
            /* Switch to use the EL0 stack pointer. */                                       \
            "MSR    SPSEL, #0                                               \n"              \
            /* Set the SP to point to the stack of the task being restored. */               \
            "LDR    X0, =pxCurrentTCB                                       \n"              \
            "LDR    X1, [X0]                                                \n"              \
            "LDR    X0, [X1]                                                \n"              \
            "MOV    SP, X0                                                  \n"              \
            /* Critical nesting and FPU context. */                                          \
            "LDP    X2, X3, [SP], #0x10                                     \n"              \
            /* Set the PMR register to be correct for the current critical nesting depth. */ \
            /* X0 holds the address of ullCriticalNesting. */                                \
            "LDR    X0, =ullCriticalNesting                                 \n"              \
            /* X1 holds the unmask value. */                                                 \
            "MOV    X1, #255                                                \n"              \
            "CMP    X3, #0                                                  \n"              \
            "B.EQ   1f                                                      \n"              \
            "LDR    X6, =ullMaxAPIPriorityMask                              \n"              \
            /* X1 holds the mask value. */                                                   \
            "LDR    X1, [X6]                                                \n"              \
            "1:                                                                 \n"          \
            /* Write the mask value to ICCPMR. s3_0_c4_c6_0 is ICC_PMR_EL1. */               \
            "MSR    s3_0_c4_c6_0, X1                                        \n"              \
            /* _RB_Barriers probably not required here. */                                   \
            "DSB    SY                                                      \n"              \
            "ISB    SY                                                      \n"              \
            /* Restore the task's critical nesting count. */                                 \
            "STR    X3, [X0]                                                \n"              \
            /* Restore the FPU context indicator. */                                         \
            "LDR    X0, =ullPortTaskHasFPUContext                           \n"              \
            "STR    X2, [X0]                                                \n"              \
            /* Restore the FPU context, if any. */                                           \
            "CMP    X2, #0                                                  \n"              \
            "B.EQ   1f                                                      \n"              \
            "LDP    Q30, Q31, [SP], #0x20                                   \n"              \
            "LDP    Q28, Q29, [SP], #0x20                                   \n"              \
            "LDP    Q26, Q27, [SP], #0x20                                   \n"              \
            "LDP    Q24, Q25, [SP], #0x20                                   \n"              \
            "LDP    Q22, Q23, [SP], #0x20                                   \n"              \
            "LDP    Q20, Q21, [SP], #0x20                                   \n"              \
            "LDP    Q18, Q19, [SP], #0x20                                   \n"              \
            "LDP    Q16, Q17, [SP], #0x20                                   \n"              \
            "LDP    Q14, Q15, [SP], #0x20                                   \n"              \
            "LDP    Q12, Q13, [SP], #0x20                                   \n"              \
            "LDP    Q10, Q11, [SP], #0x20                                   \n"              \
            "LDP    Q8, Q9, [SP], #0x20                                     \n"              \
            "LDP    Q6, Q7, [SP], #0x20                                     \n"              \
            "LDP    Q4, Q5, [SP], #0x20                                     \n"              \
            "LDP    Q2, Q3, [SP], #0x20                                     \n"              \
            "LDP    Q0, Q1, [SP], #0x20                                     \n"              \
            "1:                                                                 \n"          \
            /* SPSR and ELR. */                                                              \
            "LDP    X2, X3, [SP], #0x10                                     \n"              \
            ::: "memory");                                                                   \
    }

#define portRESTORE_CONTEXT_2_EL1()                                             \
    {                                                                           \
        __asm volatile (                                                        \
            /* Restore the SPSR. */                                             \
            "MSR    SPSR_EL1, X3                                            \n" \
            /* Restore the ELR. */                                              \
            "MSR    ELR_EL1, X2                                             \n" \
            ::: "memory");                                                      \
    }

#define portRESTORE_CONTEXT_2_EL3()                                             \
    {                                                                           \
        __asm volatile (                                                        \
            /* Restore the SPSR. */                                             \
            /*_RB_ Assumes started in EL3. */                                   \
            "MSR    SPSR_EL3, X3                                            \n" \
            /* Restore the ELR. */                                              \
            "MSR    ELR_EL3, X2                                             \n" \
            ::: "memory");                                                      \
    }

#define portRESTORE_CONTEXT_3()                                                     \
    {                                                                               \
        __asm volatile (                                                            \
            "LDP    X30, XZR, [SP], #0x10                                   \n"     \
            "LDP    X28, X29, [SP], #0x10                                   \n"     \
            "LDP    X26, X27, [SP], #0x10                                   \n"     \
            "LDP    X24, X25, [SP], #0x10                                   \n"     \
            "LDP    X22, X23, [SP], #0x10                                   \n"     \
            "LDP    X20, X21, [SP], #0x10                                   \n"     \
            "LDP    X18, X19, [SP], #0x10                                   \n"     \
            "LDP    X16, X17, [SP], #0x10                                   \n"     \
            "LDP    X14, X15, [SP], #0x10                                   \n"     \
            "LDP    X12, X13, [SP], #0x10                                   \n"     \
            "LDP    X10, X11, [SP], #0x10                                   \n"     \
            "LDP    X8, X9, [SP], #0x10                                     \n"     \
            "LDP    X6, X7, [SP], #0x10                                     \n"     \
            "LDP    X4, X5, [SP], #0x10                                     \n"     \
            "LDP    X2, X3, [SP], #0x10                                     \n"     \
            "LDP    X0, X1, [SP], #0x10                                     \n"     \
            /* Switch to use the ELx stack pointer.  _RB_ Might not be required. */ \
            "MSR    SPSEL, #1                                               \n"     \
            "ERET                                                           \n"     \
            ::: "memory");                                                          \
    }

#if defined(GUEST)
 #define portSAVE_CONTEXT()       \
    {                             \
        portSAVE_CONTEXT_1();     \
        portSAVE_CONTEXT_2_EL1(); \
        portSAVE_CONTEXT_3();     \
    }

 #define portRESTORE_CONTEXT()       \
    {                                \
        portRESTORE_CONTEXT_1();     \
        portRESTORE_CONTEXT_2_EL1(); \
        portRESTORE_CONTEXT_3();     \
    }

#else
 #define portSAVE_CONTEXT()       \
    {                             \
        portSAVE_CONTEXT_1();     \
        portSAVE_CONTEXT_2_EL3(); \
        portSAVE_CONTEXT_3();     \
    }

 #define portRESTORE_CONTEXT()       \
    {                                \
        portRESTORE_CONTEXT_1();     \
        portRESTORE_CONTEXT_2_EL3(); \
        portRESTORE_CONTEXT_3();     \
    }
#endif

BSP_ATTRIBUTE_STACKLESS void SyncSp0_Handler (void)
{
    /* Save the context of the current task and select a new task to run. */
    portSAVE_CONTEXT();

    /*STP       X0, X1, [SP, #-0x10]!*/
    __asm volatile (
#if defined(GUEST)
        "MRS    X0, ESR_EL1                         \n"
#else
        "MRS    X0, ESR_EL3                         \n"
#endif

        "LSR    X1, X0, #26                         \n"

#if defined(GUEST)
        "CMP    X1, #0x15                           \n" /* 0x15 = SVC instruction. */
#else
        "CMP    X1, #0x17                           \n" /* 0x17 = SMC instruction. */
#endif
        "B.NE   FreeRTOS_Abort                      \n"
        "LDR    X1, =vTaskSwitchContext             \n"
        "BLR    X1                                  \n"
        ::: "memory");

    portRESTORE_CONTEXT();
}

BSP_ATTRIBUTE_STACKLESS void FreeRTOS_Abort (void)
{
    /* Full ESR is in X0, exception class code is in X1. */
    __asm volatile ("B      ." ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void vPortRestoreTaskContext (void)
{
    /* Start the first task. */
    portRESTORE_CONTEXT();
}

BSP_ATTRIBUTE_STACKLESS void FIQ_Handler (void)
{
    /* Save volatile registers. */
    __asm volatile (
        "STP  x30, XZR, [SP, #-0x10]!           \n"
        "STP  x28, x29, [SP, #-0x10]!           \n"
        "STP  x26, x27, [SP, #-0x10]!           \n"
        "STP  x24, x25, [SP, #-0x10]!           \n"
        "STP  x22, x23, [SP, #-0x10]!           \n"
        "STP  x20, x21, [SP, #-0x10]!           \n"
        "STP  x18, x19, [SP, #-0x10]!           \n"
        "STP  x16, x17, [SP, #-0x10]!           \n"
        "STP  x14, x15, [SP, #-0x10]!           \n"
        "STP  x12, x13, [SP, #-0x10]!           \n"
        "STP  x10, x11, [SP, #-0x10]!           \n"
        "STP  x8, x9, [SP, #-0x10]!             \n"
        "STP  x6, x7, [SP, #-0x10]!             \n"
        "STP  x4, x5, [SP, #-0x10]!             \n"
        "STP  x2, x3, [SP, #-0x10]!             \n"
        "STP  x0, x1, [SP, #-0x10]!             \n"

#if __FPU_USED
        "MRS  x0, FPCR                          \n"
        "MRS  x1, FPSR                          \n"
        "STP  x0, x1, [SP, #-0x10]!             \n"
        "STP  q30, q31, [SP, #-0x20]!           \n"
        "STP  q28, q29, [SP, #-0x20]!           \n"
        "STP  q26, q27, [SP, #-0x20]!           \n"
        "STP  q24, q25, [SP, #-0x20]!           \n"
        "STP  q22, q23, [SP, #-0x20]!           \n"
        "STP  q20, q21, [SP, #-0x20]!           \n"
        "STP  q18, q19, [SP, #-0x20]!           \n"
        "STP  q16, q17, [SP, #-0x20]!           \n"
        "STP  q14, q15, [SP, #-0x20]!           \n"
        "STP  q12, q13, [SP, #-0x20]!           \n"
        "STP  q10, q11, [SP, #-0x20]!           \n"
        "STP  q8, q9, [SP, #-0x20]!             \n"
        "STP  q6, q7, [SP, #-0x20]!             \n"
        "STP  q4, q5, [SP, #-0x20]!             \n"
        "STP  q2, q3, [SP, #-0x20]!             \n"
        "STP  q0, q1, [SP, #-0x20]!             \n"
#endif

        /* Save the SPSR and ELR. */
#if defined(GUEST)
        "MRS    X3, SPSR_EL1                        \n"
        "MRS    X2, ELR_EL1                         \n"
#else
        "MRS    X3, SPSR_EL3                        \n"
        "MRS    X2, ELR_EL3                         \n"
#endif

        "STP    X2, X3, [SP, #-0x10]!               \n"

        /* Increment the interrupt nesting counter. */
        "LDR    X5, =ullPortInterruptNesting        \n"
        "LDR    X1, [X5]                            \n" /* Old nesting count in X1. */
        "ADD    X6, X1, #1                          \n"
        "STR    X6, [X5]                            \n" /* Address of nesting count variable in X5. */

        /* Maintain the interrupt nesting information across the function call. */
        "STP    X1, X5, [SP, #-0x10]!               \n"

        /* Call the C handler. */
        "LDR    X1, =FIQ_ExecuteHandler             \n"
        "BLR    X1                                  \n"

        /* Restore the critical nesting count. */
        "LDP    X1, X5, [SP], #0x10                 \n"
        "STR    X1, [X5]                            \n"

        /* Has interrupt nesting unwound? */
        "CMP    X1, #0                              \n"
        "B.NE   Exit_IRQ_No_Context_Switch          \n"

        /* Is a context switch required? */
        "LDR    X0, =ullPortYieldRequired           \n"
        "LDR    X1, [X0]                            \n"
        "CMP    X1, #0                              \n"
        "B.EQ   Exit_IRQ_No_Context_Switch          \n"

        /* Reset ullPortYieldRequired to 0. */
        "MOV    X2, #0                              \n"
        "STR    X2, [X0]                            \n"

        /* Restore volatile registers. */
        "LDP    X4, X5, [SP], #0x10                 \n" /* SPSR and ELR. */

#if defined(GUEST)
        "MSR    SPSR_EL1, X5                        \n"
        "MSR    ELR_EL1, X4                         \n"
#else
        "MSR    SPSR_EL3, X5                        \n" /*_RB_ Assumes started in EL3. */
        "MSR    ELR_EL3, X4                         \n"
#endif

        "DSB    SY                                  \n"
        "ISB    SY                                  \n"

#if __FPU_USED
        "LDP  q0, q1, [sp], #0x20               \n"
        "LDP  q2, q3, [sp], #0x20               \n"
        "LDP  q4, q5, [sp], #0x20               \n"
        "LDP  q6, q7, [sp], #0x20               \n"
        "LDP  q8, q9, [sp], #0x20               \n"
        "LDP  q10, q11, [sp], #0x20             \n"
        "LDP  q12, q13, [sp], #0x20             \n"
        "LDP  q14, q15, [sp], #0x20             \n"
        "LDP  q16, q17, [sp], #0x20             \n"
        "LDP  q18, q19, [sp], #0x20             \n"
        "LDP  q20, q21, [sp], #0x20             \n"
        "LDP  q22, q23, [sp], #0x20             \n"
        "LDP  q24, q25, [sp], #0x20             \n"
        "LDP  q26, q27, [sp], #0x20             \n"
        "LDP  q28, q29, [sp], #0x20             \n"
        "LDP  q30, q31, [sp], #0x20             \n"
        "LDP  x0, x1, [sp], #0x10               \n"
        "MSR  FPCR, x0                          \n"
        "MSR  FPSR, x1                          \n"
#endif

        "LDP  x0, x1, [sp], #0x10               \n"
        "LDP  x2, x3, [sp], #0x10               \n"
        "LDP  x4, x5, [sp], #0x10               \n"
        "LDP  x6, x7, [sp], #0x10               \n"
        "LDP  x8, x9, [sp], #0x10               \n"
        "LDP  x10, x11, [sp], #0x10             \n"
        "LDP  x12, x13, [sp], #0x10             \n"
        "LDP  x14, x15, [sp], #0x10             \n"
        "LDP  x16, x17, [sp], #0x10             \n"
        "LDP  x18, x19, [sp], #0x10             \n"
        "LDP  x20, x21, [sp], #0x10             \n"
        "LDP  x22, x23, [sp], #0x10             \n"
        "LDP  x24, x25, [sp], #0x10             \n"
        "LDP  x26, x27, [sp], #0x10             \n"
        "LDP  x28, x29, [sp], #0x10             \n"
        "LDP  x30, XZR, [sp], #0x10             \n"
        ::: "memory");

    /* Save the context of the current task and select a new task to run. */
    portSAVE_CONTEXT();

    __asm volatile (
        "LDR    X1, =vTaskSwitchContext             \n"
        "BLR    X1                                  \n"
        ::: "memory");

    portRESTORE_CONTEXT();
}

BSP_ATTRIBUTE_STACKLESS void Exit_IRQ_No_Context_Switch (void)
{
    /* Restore volatile registers. */
    __asm volatile (
        "LDP    X4, X5, [SP], #0x10                 \n" /* SPSR and ELR. */

#if defined(GUEST)
        "MSR    SPSR_EL1, X5                        \n"
        "MSR    ELR_EL1, X4                         \n"
#else
        "MSR    SPSR_EL3, X5                        \n" /*_RB_ Assumes started in EL3. */
        "MSR    ELR_EL3, X4                         \n"
#endif

        "DSB    SY                                  \n"
        "ISB    SY                                  \n"

#if __FPU_USED
        "LDP  q0, q1, [sp], #0x20               \n"
        "LDP  q2, q3, [sp], #0x20               \n"
        "LDP  q4, q5, [sp], #0x20               \n"
        "LDP  q6, q7, [sp], #0x20               \n"
        "LDP  q8, q9, [sp], #0x20               \n"
        "LDP  q10, q11, [sp], #0x20             \n"
        "LDP  q12, q13, [sp], #0x20             \n"
        "LDP  q14, q15, [sp], #0x20             \n"
        "LDP  q16, q17, [sp], #0x20             \n"
        "LDP  q18, q19, [sp], #0x20             \n"
        "LDP  q20, q21, [sp], #0x20             \n"
        "LDP  q22, q23, [sp], #0x20             \n"
        "LDP  q24, q25, [sp], #0x20             \n"
        "LDP  q26, q27, [sp], #0x20             \n"
        "LDP  q28, q29, [sp], #0x20             \n"
        "LDP  q30, q31, [sp], #0x20             \n"
        "LDP  x0, x1, [sp], #0x10               \n"
        "MSR  FPCR, x0                          \n"
        "MSR  FPSR, x1                          \n"
#endif

        "LDP  x0, x1, [sp], #0x10               \n"
        "LDP  x2, x3, [sp], #0x10               \n"
        "LDP  x4, x5, [sp], #0x10               \n"
        "LDP  x6, x7, [sp], #0x10               \n"
        "LDP  x8, x9, [sp], #0x10               \n"
        "LDP  x10, x11, [sp], #0x10             \n"
        "LDP  x12, x13, [sp], #0x10             \n"
        "LDP  x14, x15, [sp], #0x10             \n"
        "LDP  x16, x17, [sp], #0x10             \n"
        "LDP  x18, x19, [sp], #0x10             \n"
        "LDP  x20, x21, [sp], #0x10             \n"
        "LDP  x22, x23, [sp], #0x10             \n"
        "LDP  x24, x25, [sp], #0x10             \n"
        "LDP  x26, x27, [sp], #0x10             \n"
        "LDP  x28, x29, [sp], #0x10             \n"
        "LDP  x30, XZR, [sp], #0x10             \n"
        "ERET                                       \n"
        ::: "memory");
}

/*
 * See header file for description.
 */
StackType_t * pxPortInitialiseStack (StackType_t * pxTopOfStack, TaskFunction_t pxCode, void * pvParameters)
{
    /* Setup the initial stack of the task.  The stack is set exactly as
     * expected by the portRESTORE_CONTEXT() macro. */

    /* First all the general purpose registers. */
    pxTopOfStack--;
    *pxTopOfStack = R1_INIT_VALUE;              /* R1 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) pvParameters; /* R0 */
    pxTopOfStack--;
    *pxTopOfStack = R3_INIT_VALUE;              /* R3 */
    pxTopOfStack--;
    *pxTopOfStack = R2_INIT_VALUE;              /* R2 */
    pxTopOfStack--;
    *pxTopOfStack = R5_INIT_VALUE;              /* R5 */
    pxTopOfStack--;
    *pxTopOfStack = R4_INIT_VALUE;              /* R4 */
    pxTopOfStack--;
    *pxTopOfStack = R7_INIT_VALUE;              /* R7 */
    pxTopOfStack--;
    *pxTopOfStack = R6_INIT_VALUE;              /* R6 */
    pxTopOfStack--;
    *pxTopOfStack = R9_INIT_VALUE;              /* R9 */
    pxTopOfStack--;
    *pxTopOfStack = R8_INIT_VALUE;              /* R8 */
    pxTopOfStack--;
    *pxTopOfStack = R11_INIT_VALUE;             /* R11 */
    pxTopOfStack--;
    *pxTopOfStack = R10_INIT_VALUE;             /* R10 */
    pxTopOfStack--;
    *pxTopOfStack = R13_INIT_VALUE;             /* R13 */
    pxTopOfStack--;
    *pxTopOfStack = R12_INIT_VALUE;             /* R12 */
    pxTopOfStack--;
    *pxTopOfStack = R15_INIT_VALUE;             /* R15 */
    pxTopOfStack--;
    *pxTopOfStack = R14_INIT_VALUE;             /* R14 */
    pxTopOfStack--;
    *pxTopOfStack = R17_INIT_VALUE;             /* R17 */
    pxTopOfStack--;
    *pxTopOfStack = R16_INIT_VALUE;             /* R16 */
    pxTopOfStack--;
    *pxTopOfStack = R19_INIT_VALUE;             /* R19 */
    pxTopOfStack--;
    *pxTopOfStack = R18_INIT_VALUE;             /* R18 */
    pxTopOfStack--;
    *pxTopOfStack = R21_INIT_VALUE;             /* R21 */
    pxTopOfStack--;
    *pxTopOfStack = R20_INIT_VALUE;             /* R20 */
    pxTopOfStack--;
    *pxTopOfStack = R23_INIT_VALUE;             /* R23 */
    pxTopOfStack--;
    *pxTopOfStack = R22_INIT_VALUE;             /* R22 */
    pxTopOfStack--;
    *pxTopOfStack = R25_INIT_VALUE;             /* R25 */
    pxTopOfStack--;
    *pxTopOfStack = R24_INIT_VALUE;             /* R24 */
    pxTopOfStack--;
    *pxTopOfStack = R27_INIT_VALUE;             /* R27 */
    pxTopOfStack--;
    *pxTopOfStack = R26_INIT_VALUE;             /* R26 */
    pxTopOfStack--;
    *pxTopOfStack = R29_INIT_VALUE;             /* R29 */
    pxTopOfStack--;
    *pxTopOfStack = R28_INIT_VALUE;             /* R28 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) 0x00;         /* XZR - has no effect, used so there are an even number of registers. */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) 0x00;         /* R30 - procedure call link register. */
    pxTopOfStack--;

    *pxTopOfStack = portINITIAL_PSTATE;
    pxTopOfStack--;

    *pxTopOfStack = (StackType_t) pxCode; /* Exception return address. */
    pxTopOfStack--;

    /* The task will start with a critical nesting count of 0 as interrupts are
     * enabled. */
    *pxTopOfStack = portNO_CRITICAL_NESTING;
    pxTopOfStack--;

    /* The task will start without a floating point context.  A task that uses
     * the floating point hardware must call vPortTaskUsesFPU() before executing
     * any floating point instructions. */
    *pxTopOfStack = portNO_FLOATING_POINT_CONTEXT;

    return pxTopOfStack;
}

/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler (void)
{
    uint32_t ulAPSR;

    __asm volatile ("MRS %0, CurrentEL" : "=r" (ulAPSR));
    ulAPSR &= portAPSR_MODE_BITS_MASK;

#if defined(GUEST)
    configASSERT(ulAPSR == portEL1);
    if (ulAPSR == portEL1)
#else
    configASSERT(ulAPSR == portEL3);
    if (ulAPSR == portEL3)
#endif
    {
        /* Interrupts are turned off in the CPU itself to ensure a tick does
         * not execute  while the scheduler is being started.  Interrupts are
         * automatically turned back on in the CPU when the first task starts
         * executing. */
        portDISABLE_INTERRUPTS();

        /* Start the timer that generates the tick ISR. */
        vPortSetupTimerInterrupt();

        /* Start the first task executing. */
        vPortRestoreTaskContext();
    }

    return 0;
}

/*-----------------------------------------------------------*/

void vPortEndScheduler (void)
{
    /* Not implemented in ports where there is nothing to return to.
     * Artificially force an assert. */
    configASSERT(ullCriticalNesting == UCN1);
}

/*-----------------------------------------------------------*/

void vPortEnterCritical (void)
{
    /* Mask interrupts up to the max syscall interrupt priority. */
    uxPortSetInterruptMask();

    /* Now interrupts are disabled ullCriticalNesting can be accessed
     * directly.  Increment ullCriticalNesting to keep a count of how many times
     * portENTER_CRITICAL() has been called. */
    ullCriticalNesting++;

    /* This is not the interrupt safe version of the enter critical function so
     * assert() if it is being called from an interrupt context.  Only API
     * functions that end in "FromISR" can be used in an interrupt.  Only assert if
     * the critical nesting count is 1 to protect against recursive calls if the
     * assert function also uses a critical section. */
    if (ullCriticalNesting == 1ULL)
    {
        configASSERT(ullPortInterruptNesting == 0);
    }
}

/*-----------------------------------------------------------*/

void vPortExitCritical (void)
{
    if (ullCriticalNesting > portNO_CRITICAL_NESTING)
    {
        /* Decrement the nesting count as the critical section is being
         * exited. */
        ullCriticalNesting--;

        /* If the nesting level has reached zero then all interrupt
         * priorities must be re-enabled. */
        if (ullCriticalNesting == portNO_CRITICAL_NESTING)
        {
            /* Critical nesting has reached zero so all interrupt priorities
             * should be unmasked. */
            portCLEAR_INTERRUPT_MASK();
        }
    }
}

/*-----------------------------------------------------------*/

#if defined(BSP_MCU_GROUP_RZA3M) || defined(BSP_MCU_GROUP_RZA3UL)
void FreeRTOS_Tick_Handler (__attribute__((unused)) timer_callback_args_t * unused)
#else
void FreeRTOS_Tick_Handler (void)
#endif
{
    /* Must be the lowest possible priority. */
#if !defined(QEMU)

// {
// uint64_t ullRunningInterruptPriority;
//
/// * s3_0_c12_c11_3 is ICC_RPR_EL1. */
// __asm volatile ("MRS %0, s3_0_c12_c11_3" : "=r" (ullRunningInterruptPriority));
// configASSERT(ullRunningInterruptPriority == (portLOWEST_USABLE_INTERRUPT_PRIORITY << portPRIORITY_SHIFT));
// }
#endif

    /* Interrupts should not be enabled before this point. */
#if (configASSERT_DEFINED == 1)

// {
// uint32_t ulMaskBits;
//
// __asm volatile ("MRS %0, DAIF" : "=r" (ulMaskBits)::"memory");
// configASSERT((ulMaskBits & portDAIF_F) != 0);
// }
#endif                                 /* configASSERT_DEFINED */

    /* Set interrupt mask before altering scheduler structures.   The tick
     * handler runs at the lowest priority, so interrupts cannot already be masked,
     * so there is no need to save and restore the current mask value.  It is
     * necessary to turn off interrupts in the CPU itself while the ICCPMR is being
     * updated. *//* s3_0_c4_c6_0 is ICC_PMR_EL1. */
    __asm volatile ("MSR s3_0_c4_c6_0, %0		\n"
                    "DSB SY					\n"
                    "ISB SY					\n"
                    ::"r" (configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT) : "memory");

    /* Ok to enable interrupts after the interrupt source has been cleared. */
    configCLEAR_TICK_INTERRUPT();
    portENABLE_INTERRUPTS();

    /* Increment the RTOS tick. */
    if (xTaskIncrementTick() != pdFALSE)
    {
        ullPortYieldRequired = pdTRUE;
    }

    /* Ensure all interrupt priorities are active again. */
    portCLEAR_INTERRUPT_MASK();
}

/*-----------------------------------------------------------*/

void vPortTaskUsesFPU (void)
{
    /* A task is registering the fact that it needs an FPU context.  Set the
     * FPU flag (which is saved as part of the task context). */
    ullPortTaskHasFPUContext = pdTRUE;

    /* Consider initialising the FPSR here - but probably not necessary in
     * AArch64. */
}

/*-----------------------------------------------------------*/

void vPortClearInterruptMask (UBaseType_t uxNewMaskValue)
{
    if (uxNewMaskValue == pdFALSE)
    {
        portCLEAR_INTERRUPT_MASK();
    }
}

/*-----------------------------------------------------------*/

UBaseType_t uxPortSetInterruptMask (void)
{
    uint32_t ulReturn;
    uint64_t ullPMRValue;

    /* Interrupt in the CPU must be turned off while the ICCPMR is being
     * updated. */
    portDISABLE_INTERRUPTS();

    /* s3_0_c4_c6_0 is ICC_PMR_EL1. */
    __asm volatile ("MRS %0, s3_0_c4_c6_0" : "=r" (ullPMRValue));
    if (ullPMRValue == (configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT))
    {
        /* Interrupts were already masked. */
        ulReturn = pdTRUE;
    }
    else
    {
        ulReturn = pdFALSE;

        /* s3_0_c4_c6_0 is ICC_PMR_EL1. */
        __asm volatile ("MSR s3_0_c4_c6_0, %0		\n"
                        "DSB SY					\n"
                        "ISB SY					\n"
                        ::"r" (configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT) : "memory");
    }

    portENABLE_INTERRUPTS();

    return ulReturn;
}

/*-----------------------------------------------------------*/

#if (configASSERT_DEFINED == 1)

void vPortValidateInterruptPriority (void)
{
    /* The following assertion will fail if a service routine (ISR) for
     * an interrupt that has been assigned a priority above
     * configMAX_SYSCALL_INTERRUPT_PRIORITY calls an ISR safe FreeRTOS API
     * function.  ISR safe FreeRTOS API functions must *only* be called
     * from interrupts that have been assigned a priority at or below
     * configMAX_SYSCALL_INTERRUPT_PRIORITY.
     *
     * Numerically low interrupt priority numbers represent logically high
     * interrupt priorities, therefore the priority of the interrupt must
     * be set to a value equal to or numerically *higher* than
     * configMAX_SYSCALL_INTERRUPT_PRIORITY.
     *
     * FreeRTOS maintains separate thread and ISR API functions to ensure
     * interrupt entry is as fast and simple as possible. */
    uint64_t ullRunningInterruptPriority;

    /* s3_0_c12_c11_3 is ICC_RPR_EL1. */
    __asm volatile ("MRS %0, s3_0_c12_c11_3" : "=r" (ullRunningInterruptPriority));
    configASSERT(ullRunningInterruptPriority >= (configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT));
}

#endif                                 /* configASSERT_DEFINED */
/*-----------------------------------------------------------*/
/*#include "GICv3_gicc.h"*/
#define GIC_INTERRUPT_NUMBER    512
#define CPU_CORE_NUMBER         1

// #define __BKPT(value)   __asm volatile ("bkpt "#value)

typedef void (* INTC_IntHandler)(void *);

typedef struct
{
    INTC_IntHandler handler;
    void          * arg;
} st_irq_handler_info;

typedef struct
{
    uintptr_t           base_address;
    uint32_t            route;
    st_irq_handler_info handler_table[GIC_INTERRUPT_NUMBER];
} st_gic_info;

static inline uint64_t getICC_IAR1 (void)
{
    uint64_t retc;
    __asm("mrs  %0, S3_0_C12_C12_0\n" : "=r" (retc));

    return retc;
}

static inline void setICC_EOIR1 (uint64_t interrupt)
{
    __asm("msr  S3_0_C12_C12_1, %0\n; isb" ::"r" (interrupt));
}

st_gic_info g_gic_info[CPU_CORE_NUMBER];

#if 0
void rm_freertos_port_sleep_preserving_lpm(uint32_t xExpectedIdleTime);

void rm_freertos_port_sleep_preserving_lpm (uint32_t xExpectedIdleTime)
{
    /* Sleep until something happens.  configPRE_SLEEP_PROCESSING() can
     * set its parameter to 0 to indicate that its implementation contains
     * its own wait for interrupt or wait for event instruction, and so wfi
     * should not be executed again. The original expected idle
     * time variable must remain unmodified, so this is done in a subroutine. */
    configPRE_SLEEP_PROCESSING(xExpectedIdleTime);
    if (xExpectedIdleTime > 0)
    {
        /*
         * (1) Set the STBYCTL bit of the SYS_LP_CTL2 register to 1 to start the Cortex-A55 Sleep Mode.
         */
        R_SYSC->SYS_LP_CTL2_b.CA55_STBYCTL = 1;

        /*
         * (2) Set the return factor to GIC. Enables only the interrupts used for return from the sleep mode and disables the
         * interrupts used for the normal operation.
         *//* all the enabled interrupts are the triggers of waking up *//*
         * (3) Issue Barrier instruction.
         * Issue the WFI instruction for Cortex-A55 core0. The Cortex-A55 core0 is put into the sleep mode.
         */
        __asm volatile ("dsb 0xF" ::: "memory");
        __asm volatile ("wfi" ::: "memory");

        /*
         * (4) Return from the sleep mode when the event occurs or the interrupt set in GIC occurs.
         */

        /*
         * (5) Confirm the interrupt cause and perform the processing required for returning from the sleep mode.
         * And then clear the interrupt cause.
         * Set the end of interrupt to GIC.
         * Set the interrupt causes for the normal operation to GIC.
         *//* Instruction Synchronization Barrier. *//*__ISB();*/
        __asm volatile ("isb 0xF" ::: "memory");

        /* Re-enable interrupts to allow the interrupt that brought the MPU
         * out of sleep mode to execute immediately. This will not cause a
         * context switch because all tasks are currently suspended. */
        BSP_INTERRUPT_ENABLE;

        /*__ISB();*/
        __asm volatile ("isb 0xF" ::: "memory");

        /* Disable interrupts again to restore the LPM state. */
        BSP_INTERRUPT_DISABLE;

        /*
         * (6) Clear the STBYCTL bit of the SYS_LP_CTL2 register.
         */
        R_SYSC->SYS_LP_CTL2_b.CA55_STBYCTL = 0;
    }

    configPOST_SLEEP_PROCESSING(xExpectedIdleTime);
}

#endif

/***********************************************************************************************************************
 * Setup the timer to generate the tick interrupts.  The implementation in this
 * file is weak to allow application writers to change the timer used to
 * generate the tick interrupt.
 **********************************************************************************************************************/
void vPortSetupTimerInterrupt (void)
{
    uint64_t tempCNTPCT = CNTPCT_READ();
    uint32_t timeout    = portTIMERSETUP_TIMEOUT;

    /* Wait for counter supply */
    while (CNTPCT_READ() == tempCNTPCT)
    {
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

        /* Verify if a timeout has occurred. */
        timeout--;
        if (timeout == 0)
        {
            break;
        }
    }

    configASSERT(timeout > 0);

    /* generic timer initialize */
    /* set interrupt handler */
    g_sgi_ppi_vector_table[(int32_t) BSP_CORTEX_VECTOR_TABLE_ENTRIES +
                           NonSecurePhysicalTimerInt] = Generic_Timer_Interrupt_Handler;

    g_timer_delay = GENERIC_TIMER_CLK / configTICK_RATE_HZ;

    /* set timer expiration from current counter value */
    CNTP_CVAL_WRITE(CNTPCT_READ() + g_timer_delay);

    /* configure CNTP_CTL to enable timer interrupts */
    CNTP_CTL_WRITE(1);
    R_BSP_IrqCfgEnable(NonSecurePhysicalTimerInt, portLOWEST_USABLE_INTERRUPT_PRIORITY, NULL);

    BSP_INTERRUPT_ENABLE;
}

void vApplicationIRQHandler (__attribute__((unused)) uint64_t ulICCIAR)
{
    uint64_t              int_id;
    st_irq_handler_info * p_vector;
    uint64_t              core_no;

    // core_no = GetCPUID();
    core_no = 0;
    int_id  = getICC_IAR1();

    if (int_id < GIC_INTERRUPT_NUMBER)
    {
        p_vector = &(g_gic_info[core_no].handler_table[int_id]);
        if (p_vector->handler)
        {
            p_vector->handler(p_vector->arg);
        }
    }

    setICC_EOIR1(int_id);
}

void Generic_Timer_Interrupt_Handler (void)
{
    /* update next timer expiration */
    CNTP_CVAL_WRITE(CNTP_CVAL_READ() + g_timer_delay);

    /* call FreeRTOS tick interrupt handler */
#if defined(BSP_MCU_GROUP_RZA3M) || defined(BSP_MCU_GROUP_RZA3UL)
    FreeRTOS_Tick_Handler(NULL);
#else
    FreeRTOS_Tick_Handler();
#endif
}

__attribute__((weak)) void vPortDefineHeapRegions (__attribute__((unused)) const HeapRegion_t * const pxHeapRegions)
{
}

void vApplicationIdleHook (void)
{
#if 0

    /* Enter a critical section but don't use the taskENTER_CRITICAL() method as that will mask interrupts that should
     * exit sleep mode. This must be done before suspending tasks because a pending interrupt will prevent sleep from
     * WFI, but a task ready to run will not. If a task becomes ready to run before disabling interrupts, a context
     * switch will happen. */
    BSP_INTERRUPT_DISABLE;

    /* Don't allow a context switch during sleep processing to ensure the LPM state is restored
     * before switching from idle to the next ready task. This is done in the idle task
     * before vPortSuppressTicksAndSleep when configUSE_TICKLESS_IDLE is used. */
    vTaskSuspendAll();

    /* Save current LPM state, then sleep. */
    rm_freertos_port_sleep_preserving_lpm(1);

    /* Exit with interrupts enabled. */
    BSP_INTERRUPT_ENABLE;

    /* Allow context switches again. No need to yield here since the idle task yields when it loops around. */
    (void) xTaskResumeAll();
#endif
}
