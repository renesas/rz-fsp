/*
 * FreeRTOS Kernel V10.4.3 LTS Patch 2
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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
#include <string.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "hal_data.h"

#if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1

/* Check the configuration. */
 #if (configMAX_PRIORITIES > 32)
  #error \
    configUSE_PORT_OPTIMISED_TASK_SELECTION can only be set to 1 when configMAX_PRIORITIES is less than or equal to 32.  It is very rare that a system requires more than 10 to 15 difference priorities as tasks that share a priority will time slice.
 #endif
#endif                                 /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

/* A critical section is exited when the critical section nesting count reaches
 * this value. */
#define portNO_CRITICAL_NESTING               ((uint32_t) 0)

/* Tasks are not created with a floating point context, but can be given a
 * floating point context after they have been created.  A variable is stored as
 * part of the tasks context that holds portNO_FLOATING_POINT_CONTEXT if the task
 * does not have an FPU context, or any other value if the task does have an FPU
 * context. */
#define portNO_FLOATING_POINT_CONTEXT         ((StackType_t) 0)

/* Constants required to setup the initial task context. */
#define portINITIAL_SPSR                      ((StackType_t) 0x1f) /* System mode, ARM mode, IRQ enabled FIQ enabled. */
#define portTHUMB_MODE_BIT                    ((StackType_t) 0x20)
#define portTHUMB_MODE_ADDRESS                (0x01UL)

/* Masks all bits in the APSR other than the mode bits. */
#define portAPSR_MODE_BITS_MASK               (0x1F)

/* The value of the mode bits in the APSR when the CPU is executing in user
 * mode. */
#define portAPSR_USER_MODE                    (0x10)

#define portGICD_REGISTER_NUMBER              (15U)
#define portMAX_32_BIT_VALUE                  ((uint32_t) 0xffffffff)
#define portCRITICAL_NESTING_INITIAL_VALUE    (9999UL)
#define portSTACK_INITIAL_VALUE_R1            0x01010101
#define portSTACK_INITIAL_VALUE_R2            (portSTACK_INITIAL_VALUE_R1 * 0x02)
#define portSTACK_INITIAL_VALUE_R3            (portSTACK_INITIAL_VALUE_R1 * 0x03)
#define portSTACK_INITIAL_VALUE_R4            (portSTACK_INITIAL_VALUE_R1 * 0x04)
#define portSTACK_INITIAL_VALUE_R5            (portSTACK_INITIAL_VALUE_R1 * 0x05)
#define portSTACK_INITIAL_VALUE_R6            (portSTACK_INITIAL_VALUE_R1 * 0x06)
#define portSTACK_INITIAL_VALUE_R7            (portSTACK_INITIAL_VALUE_R1 * 0x07)
#define portSTACK_INITIAL_VALUE_R8            (portSTACK_INITIAL_VALUE_R1 * 0x08)
#define portSTACK_INITIAL_VALUE_R9            (portSTACK_INITIAL_VALUE_R1 * 0x09)
#define portSTACK_INITIAL_VALUE_R10           (portSTACK_INITIAL_VALUE_R1 * 0x10)
#define portSTACK_INITIAL_VALUE_R11           (portSTACK_INITIAL_VALUE_R1 * 0x11)
#define portSTACK_INITIAL_VALUE_R12           (portSTACK_INITIAL_VALUE_R1 * 0x12)

/* Let the user override the pre-loading of the initial LR with the address of
 * prvTaskExitError() in case it messes up unwinding of the stack in the
 * debugger. */
#ifdef configTASK_RETURN_ADDRESS
 #define portTASK_RETURN_ADDRESS              configTASK_RETURN_ADDRESS
#else
 #define portTASK_RETURN_ADDRESS              prvTaskExitError
#endif

/* The space on the stack required to hold the FPU registers.  This is 16 64-bit
 * registers, plus a 32-bit status register. */
#define portFPU_REGISTER_WORDS                ((16 * 2) + 1)

/*-----------------------------------------------------------*/

/*
 * Starts the first task executing.  This function is necessarily written in
 * assembly code so is implemented in portASM.asm.
 */
extern void vPortRestoreTaskContext(void);

/*
 * Used to catch tasks that attempt to return from their implementing function.
 */
static void prvTaskExitError(void);

/*-----------------------------------------------------------*/

/* A variable is used to keep track of the critical section nesting.  This
 * variable has to be stored as part of the task context and must be initialised to
 * a non zero value to ensure interrupts don't inadvertently become unmasked before
 * the scheduler starts.  As it is stored as part of the task context it will
 * automatically be set to 0 when the first task is started. */
volatile uint32_t ulCriticalNesting = portCRITICAL_NESTING_INITIAL_VALUE;

/* Saved as part of the task context.  If ulPortTaskHasFPUContext is non-zero then
 * a floating point context must be saved and restored for the task. */
volatile uint32_t ulPortTaskHasFPUContext = pdFALSE;

/* Set to 1 to pend a context switch from an ISR. */
volatile uint32_t ulPortYieldRequired = pdFALSE;

#if (configAPPLICATION_ALLOCATED_HEAP == 1)
uint8_t ucHeap[configTOTAL_HEAP_SIZE];
#endif

/**
 * @brief IRQ Wake Up
 */
IRQn_Type vPortGetWakeUpIrq(void);

/**
 * @brief Setup the timer to generate the tick interrupts.
 *
 * The implementation in this file is weak to allow application writers to
 * change the timer used to generate the tick interrupt.
 */
void vPortSetupTimerInterrupt(void) PRIVILEGED_FUNCTION;

/**
 * @brief SysTick handler.
 */
void SysTick_Handler(timer_callback_args_t * p_args) PRIVILEGED_FUNCTION;

/**
 * @brief Idle Hook
 */
void rm_freertos_port_sleep_preserving_lpm(uint32_t xExpectedIdleTime);

void vApplicationIRQHandler(uint32_t ulICCIAR);

uint32_t FreeRTOS_GetActiveIRQ(void);

void FreeRTOS_EndOfInterrupt(uint32_t id);

/*-----------------------------------------------------------*/

uint32_t FreeRTOS_GetActiveIRQ (void)
{
    /* Read ICCHPIR */
    R_BSP_IoRegRead32((volatile uint32_t *) &R_INTC_GIC->GICC_ICCHPIR, 0, BSP_IO_NONMASK_ACCESS_32);

    /* Read ICCIAR */
    return R_BSP_IoRegRead32((volatile uint32_t *) &R_INTC_GIC->GICC_ICCIAR, 0, BSP_IO_NONMASK_ACCESS_32);
}

void FreeRTOS_EndOfInterrupt (uint32_t id)
{
    R_BSP_IoRegWrite32(&R_INTC_GIC->GICC_ICCEOIR, id, 0, BSP_IO_NONMASK_ACCESS_32);
}

/*-----------------------------------------------------------*/
__attribute__((weak)) void vPortSetupTimerInterrupt (void) /* PRIVILEGED_FUNCTION */
{
    /* Stop and reset the SysTick. */
    g_timer2.p_api->open(g_timer2.p_ctrl, g_timer2.p_cfg);

    /* Configure SysTick to interrupt at the requested rate. */
    g_timer2.p_api->callbackSet(g_timer2.p_ctrl, SysTick_Handler, NULL, NULL);

    /* Start the SysTick. */
    g_timer2.p_api->start(g_timer2.p_ctrl);

    /* Calculate the constants required to configure the tick interrupt. */
#if (configUSE_TICKLESS_IDLE == 1)
 #error Set configUSE_TICKLESS_IDLE = 0. Tickless Idle is not supported

    {
        ulTimerCountsForOneTick         = (configSYSTICK_CLOCK_HZ / configTICK_RATE_HZ);
        xMaximumPossibleSuppressedTicks = portMAX_24_BIT_NUMBER / ulTimerCountsForOneTick;
        ulStoppedTimerCompensation      = portMISSED_COUNTS_FACTOR / (configCPU_CLOCK_HZ / configSYSTICK_CLOCK_HZ);
    }
#endif                                 /* configUSE_TICKLESS_IDLE */
}

/*
 * See header file for description.
 */
StackType_t * pxPortInitialiseStack (StackType_t * pxTopOfStack, TaskFunction_t pxCode, void * pvParameters)
{
    /* Setup the initial stack of the task.  The stack is set exactly as
     * expected by the portRESTORE_CONTEXT() macro.
     *
     * The fist real value on the stack is the status register, which is set for
     * system mode, with interrupts enabled.  A few NULLs are added first to ensure
     * GDB does not try decoding a non-existent return address. */
    *pxTopOfStack = (StackType_t) NULL;
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) NULL;
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) NULL;
    pxTopOfStack--;
    *pxTopOfStack = portINITIAL_SPSR;

    if (((uint32_t) pxCode & portTHUMB_MODE_ADDRESS) != 0x00UL)
    {
        /* The task will start in THUMB mode. */
        *pxTopOfStack |= portTHUMB_MODE_BIT;
    }

    pxTopOfStack--;

    /* Next the return address, which in this case is the start of the task. */
    *pxTopOfStack = (StackType_t) pxCode;
    pxTopOfStack--;

    /* Next all the registers other than the stack pointer. */
    *pxTopOfStack = (StackType_t) portTASK_RETURN_ADDRESS;     /* R14 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R12; /* R12 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R11; /* R11 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R10; /* R10 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R9;  /* R9 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R8;  /* R8 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R7;  /* R7 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R6;  /* R6 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R5;  /* R5 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R4;  /* R4 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R3;  /* R3 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R2;  /* R2 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) portSTACK_INITIAL_VALUE_R1;  /* R1 */
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t) pvParameters;                /* R0 */
    pxTopOfStack--;

    /* The task will start with a critical nesting count of 0 as interrupts are
     * enabled. */
    *pxTopOfStack = portNO_CRITICAL_NESTING;

#if (configUSE_TASK_FPU_SUPPORT == 1)
    {
        /* The task will start without a floating point context.  A task that
         * uses the floating point hardware must call vPortTaskUsesFPU() before
         * executing any floating point instructions. */
        pxTopOfStack--;
        *pxTopOfStack = portNO_FLOATING_POINT_CONTEXT;
    }
#elif (configUSE_TASK_FPU_SUPPORT == 2)
    {
        /* The task will start with a floating point context.  Leave enough
         * space for the registers - and ensure they are initialised to 0. */
        pxTopOfStack -= portFPU_REGISTER_WORDS;
        memset(pxTopOfStack, 0x00, portFPU_REGISTER_WORDS * sizeof(StackType_t));

        pxTopOfStack--;
        *pxTopOfStack           = pdTRUE;
        ulPortTaskHasFPUContext = pdTRUE;
    }
#elif (configUSE_TASK_FPU_SUPPORT != 0)
    {
 #error Invalid configUSE_TASK_FPU_SUPPORT setting - configUSE_TASK_FPU_SUPPORT must be set to 0, 1, or 2.
    }
#endif

    return pxTopOfStack;
}

/*-----------------------------------------------------------*/

static void prvTaskExitError (void)
{
    /* A function that implements a task must not exit or attempt to return to
     * its caller as there is nothing to return to.  If a task wants to exit it
     * should instead call vTaskDelete( NULL ).
     *
     * Artificially force an assert() to be triggered if configASSERT() is
     * defined, then stop here so application writers can catch the error. */
    portDISABLE_INTERRUPTS();
    for ( ; ; )
    {
        ;
    }
}

/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler (void)
{
    uint32_t ulAPSR;

    /* Only continue if the CPU is not in User mode.  The CPU must be in a
     * Privileged mode for the scheduler to start. */
    __asm volatile ("MRS %0, APSR" : "=r" (ulAPSR)::"memory");
    ulAPSR &= portAPSR_MODE_BITS_MASK;
    configASSERT(ulAPSR != portAPSR_USER_MODE);

    if (ulAPSR != portAPSR_USER_MODE)
    {
        /* Start the timer that generates the tick ISR. */
        portDISABLE_INTERRUPTS();
        vPortSetupTimerInterrupt();

        /* Start the first task executing. */
        vPortRestoreTaskContext();
    }

    /* Will only get here if vTaskStartScheduler() was called with the CPU in
     * a non-privileged mode or the binary point register was not set to its lowest
     * possible value.  prvTaskExitError() is referenced to prevent a compiler
     * warning about it being defined but not referenced in the case that the user
     * defines their own exit address. */
    (void) prvTaskExitError;

    return 0;
}

/*-----------------------------------------------------------*/

void vPortEndScheduler (void)
{
    /* Not implemented in ports where there is nothing to return to.
     * Artificially force an assert. */
    configASSERT(ulCriticalNesting == 1000UL);
}

/*-----------------------------------------------------------*/

void vPortEnterCritical (void)
{
    portDISABLE_INTERRUPTS();

    /* Now interrupts are disabled ulCriticalNesting can be accessed
     * directly.  Increment ulCriticalNesting to keep a count of how many times
     * portENTER_CRITICAL() has been called. */
    ulCriticalNesting++;
}

/*-----------------------------------------------------------*/

void vPortExitCritical (void)
{
    if (ulCriticalNesting > portNO_CRITICAL_NESTING)
    {
        /* Decrement the nesting count as the critical section is being
         * exited. */
        ulCriticalNesting--;

        /* If the nesting level has reached zero then all interrupt
         * priorities must be re-enabled. */
        if (ulCriticalNesting == portNO_CRITICAL_NESTING)
        {
            /* Critical nesting has reached zero so all interrupt priorities
             * should be unmasked. */
            portENABLE_INTERRUPTS();
        }
    }
}

/*-----------------------------------------------------------*/

void vApplicationIRQHandler (uint32_t ulICCIAR)
{
    bsp_common_interrupt_handler(ulICCIAR);
}

void SysTick_Handler (__attribute__((unused)) timer_callback_args_t * p_args) /* PRIVILEGED_FUNCTION */
{
    uint32_t ulInterruptStatus;

    ulInterruptStatus = portSET_INTERRUPT_MASK_FROM_ISR();

    /* Increment the RTOS tick. */
    if (xTaskIncrementTick() != pdFALSE)
    {
        ulPortYieldRequired = pdTRUE;
    }

    portCLEAR_INTERRUPT_MASK_FROM_ISR(ulInterruptStatus);
}

/*-----------------------------------------------------------*/

#if (configUSE_TASK_FPU_SUPPORT == 1)

void vPortTaskUsesFPU (void)
{
    uint32_t ulInitialFPSCR = 0;

    /* A task is registering the fact that it needs an FPU context.  Set the
     * FPU flag (which is saved as part of the task context). */
    ulPortTaskHasFPUContext = pdTRUE;

    /* Initialise the floating point status register. */
    __asm volatile ("FMXR   FPSCR, %0" ::"r" (ulInitialFPSCR) : "memory");
}

#endif                                 /* configUSE_TASK_FPU_SUPPORT */
/*-----------------------------------------------------------*/
#if configUSE_IDLE_HOOK || configUSE_TICKLESS_IDLE

/*-----------------------------------------------------------*/
 #if !defined(portGENERATED_GET_WAKEUP_IRQ)
__attribute__((weak)) IRQn_Type vPortGetWakeUpIrq (void)
{
    return GTM2_OSTM2INT_IRQn;
}

 #endif

/***********************************************************************************************************************
 * Saves the LPM state, then enters sleep mode. After waking, reenables interrupts briefly to allow any pending
 * interrupts to run.
 *
 * @pre Disable interrupts an suspend all tasks before calling this function.
 *
 * @param[in] xExpectedIdleTime Expected idle time in ticks
 **********************************************************************************************************************/
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
        /* Procedure for transition to the sleep mode
         * (Refer to "Sleep Mode" section of the Hardware Manual for details.)
         * NOTE: Sequences 2-5 are ignored as this isn't a deep sleep transition, aiming for better performance.
         *
         * Sequence 1. Set the request for transition to sleep mode state. */
        BSP_SLEEP_SET_SLEEP_REQ();

        /* Sequence 2.
         * Reduce the clock frequency if necessary.
         *
         * Sequence 3.
         * Disable interrupts from being accepted by the core from the Interrupt Controller Unit (ICU), if necessary.
         *
         * Sequence 4.
         * Enable only the interrupt that will wake the core, from the core's interrupt controller (such as the
         * NVIC or GIC).
         *
         * Sequence 5.
         * Configure the core-specific registers to enable deep sleep mode (if it is supported).
         *
         * Sequence 6.
         * Execute the WFI or WFE instruction after issuing a memory barrier instruction.
         */
        __DSB();
        __WFI();
        __ISB();

        /* Procedures for returning from sleep mode
         *
         * NOTE: Sequence 1 - 3 are ignored, as this isn't a deep sleep transition, aiming for better performance.
         *
         * Sequence 1.
         * Perform core-specific processing to exit deep sleep mode.
         *
         * Sequence 2.
         * Restore the interrupt settings that were modified before entering deep sleep mode.
         *
         * Sequence 3.
         * Restore the clock frequency if it was changed.
         *
         * Sequence 4.
         * Clear the request for transition to sleep mode state.
         */
        BSP_SLEEP_CLEAR_SLEEP_REQ();

        /* Re-enable interrupts to allow the interrupt that brought the MPU
         * out of sleep mode to execute immediately. This will not cause a
         * context switch because all tasks are currently suspended. */
        __enable_irq();
        __ISB();

        /* Disable interrupts again to restore the LPM state. */
        __disable_irq();
    }

    configPOST_SLEEP_PROCESSING(xExpectedIdleTime);
}

#endif

#if configUSE_IDLE_HOOK

/***********************************************************************************************************************
 * Suspends tasks and sleeps, waking for each interrupt.
 *
 * @note This is a weak function. It can be overridden by an application specific implementation if desired.
 **********************************************************************************************************************/
__attribute__((weak)) void vApplicationIdleHook (void)
{
    /* Enter a critical section but don't use the taskENTER_CRITICAL() method as that will mask interrupts that should
     * exit sleep mode. This must be done before suspending tasks because a pending interrupt will prevent sleep from
     * WFI, but a task ready to run will not. If a task becomes ready to run before disabling interrupts, a context
     * switch will happen. */
    __disable_irq();

    /* Don't allow a context switch during sleep processing to ensure the LPM state is restored
     * before switching from idle to the next ready task. This is done in the idle task
     * before vPortSuppressTicksAndSleep when configUSE_TICKLESS_IDLE is used. */
    vTaskSuspendAll();

    /* Save current LPM state, then sleep. */
    rm_freertos_port_sleep_preserving_lpm(1);

    /* Exit with interrupts enabled. */
    __enable_irq();

    /* Allow context switches again. No need to yield here since the idle task yields when it loops around. */
    (void) xTaskResumeAll();
}

#endif

#if configGENERATE_RUN_TIME_STATS
__attribute__((weak)) void vPortConfigureTimerForRunTimeStatus (void)
{
    /* open and start GTM0 */
}

#endif

#if configGENERATE_RUN_TIME_STATS

/* Count clock = 100MHz
 * 10-bits-right-shift makes 10.24us counting interval */
 #define runtimeCLOCK_SCALE_SHIFT    (10)

/* GTM overflows 32bit */
 #define runtimeOVERFLOW_SHIFT       (32 - runtimeCLOCK_SCALE_SHIFT)
__attribute__((weak)) unsigned long ulGetRunTimeCounterValue (void)
{
    static unsigned long ulLastCounterValue = 0UL, ulOverflows = 0;
    unsigned long        ulValueNow = 0;
    timer_status_t       timer_status;

    /* copy the count value of GTM0 to timer_status.counter. */
    {
        ulValueNow = timer_status.counter;

        /* Has the value overflowed since it was last read. */
        if (ulValueNow < ulLastCounterValue)
        {
            ulOverflows++;
        }

        ulLastCounterValue = ulValueNow;

        /* move the count value to  */
        ulValueNow >>= runtimeCLOCK_SCALE_SHIFT;
        ulValueNow  += ulOverflows << runtimeOVERFLOW_SHIFT;
    }

    return ulValueNow;
}

#endif

__attribute__((weak)) void vPortDefineHeapRegions (__attribute__((unused)) const HeapRegion_t * const pxHeapRegions)
{
}
