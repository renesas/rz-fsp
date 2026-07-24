/*
 * FreeRTOS Kernel V11.1.0
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

#ifndef PORTMACRO_CA55_H
 #define PORTMACRO_CA55_H

 #ifdef __cplusplus
extern "C" {
 #endif
 #if defined(BSP_MCU_GROUP_RZA3M) || defined(BSP_MCU_GROUP_RZA3UL)
  #include "r_timer_api.h"
 #endif

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the given hardware
 * and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
 #define portCHAR           char
 #define portFLOAT          float
 #define portDOUBLE         double
 #define portLONG           long
 #define portSHORT          short
 #if defined(BSP_MCU_GROUP_RZA3M) || defined(BSP_MCU_GROUP_RZA3UL)
  #define portSTACK_TYPE    uint64_t
 #else
  #define portSTACK_TYPE    size_t
 #endif
 #define portBASE_TYPE      long

typedef portSTACK_TYPE StackType_t;
typedef portBASE_TYPE  BaseType_t;
typedef uint64_t       UBaseType_t;

typedef uint64_t TickType_t;
 #define portMAX_DELAY              ((TickType_t) 0xffffffffffffffff)

/* 32-bit tick type on a 32-bit architecture, so reads of the tick count do
 * not need to be guarded with a critical section. */
 #define portTICK_TYPE_IS_ATOMIC    1

/*-----------------------------------------------------------*/

/* Hardware specifics. */
 #define portSTACK_GROWTH           (-1)
 #define portTICK_PERIOD_MS         ((TickType_t) 1000 / configTICK_RATE_HZ)
 #define portBYTE_ALIGNMENT         16
 #define portPOINTER_SIZE_TYPE      uint64_t

/*-----------------------------------------------------------*/

/* General purpose registers */
 #define R1_INIT_VALUE              (0x0101010101010101ULL)
 #define R2_INIT_VALUE              (0x0202020202020202ULL)
 #define R3_INIT_VALUE              (0x0303030303030303ULL)
 #define R4_INIT_VALUE              (0x0404040404040404ULL)
 #define R5_INIT_VALUE              (0x0505050505050505ULL)
 #define R6_INIT_VALUE              (0x0606060606060606ULL)
 #define R7_INIT_VALUE              (0x0707070707070707ULL)
 #define R8_INIT_VALUE              (0x0808080808080808ULL)
 #define R9_INIT_VALUE              (0x0909090909090909ULL)
 #define R10_INIT_VALUE             (0x1010101010101010ULL)
 #define R11_INIT_VALUE             (0x1111111111111111ULL)
 #define R12_INIT_VALUE             (0x1212121212121212ULL)
 #define R13_INIT_VALUE             (0x1313131313131313ULL)
 #define R14_INIT_VALUE             (0x1414141414141414ULL)
 #define R15_INIT_VALUE             (0x1515151515151515ULL)
 #define R16_INIT_VALUE             (0x1616161616161616ULL)
 #define R17_INIT_VALUE             (0x1717171717171717ULL)
 #define R18_INIT_VALUE             (0x1818181818181818ULL)
 #define R19_INIT_VALUE             (0x1919191919191919ULL)
 #define R20_INIT_VALUE             (0x2020202020202020ULL)
 #define R21_INIT_VALUE             (0x2121212121212121ULL)
 #define R22_INIT_VALUE             (0x2222222222222222ULL)
 #define R23_INIT_VALUE             (0x2323232323232323ULL)
 #define R24_INIT_VALUE             (0x2424242424242424ULL)
 #define R25_INIT_VALUE             (0x2525252525252525ULL)
 #define R26_INIT_VALUE             (0x2626262626262626ULL)
 #define R27_INIT_VALUE             (0x2727272727272727ULL)
 #define R28_INIT_VALUE             (0x2828282828282828ULL)
 #define R29_INIT_VALUE             (0x2929292929292929ULL)

/*-----------------------------------------------------------*/
/* Initial value of variable */
 #define UCN0                       (9999ULL)
 #define UCN1                       (1000ULL)

/*-----------------------------------------------------------*/

/* Task utilities. */

/* Called at the end of an ISR that can cause a context switch. */
 #define portEND_SWITCHING_ISR(xSwitchRequired) \
    {                                           \
        extern uint64_t ullPortYieldRequired;   \
                                                \
        if (xSwitchRequired != pdFALSE)         \
        {                                       \
            ullPortYieldRequired = pdTRUE;      \
        }                                       \
    }

 #define portYIELD_FROM_ISR(x)    portEND_SWITCHING_ISR(x)
 #if defined(GUEST)
  #define portYIELD()             __asm volatile ("SVC 0" ::: "memory")
 #else
  #define portYIELD()             __asm volatile ("SMC 0" ::: "memory")
 #endif

/*-----------------------------------------------------------
 * Critical section control
 *----------------------------------------------------------*/

extern void        vPortEnterCritical(void);
extern void        vPortExitCritical(void);
extern UBaseType_t uxPortSetInterruptMask(void);
extern void        vPortClearInterruptMask(UBaseType_t uxNewMaskValue);
extern void        vPortInstallFreeRTOSVectorTable(void);
extern void        vApplicationIRQHandler(uint64_t ulICCIAR);
extern void        vApplicationIdleHook(void);

 #define portDISABLE_INTERRUPTS()                    \
    __asm volatile ("MSR DAIFSET, #1" ::: "memory"); \
    __asm volatile ("DSB SY");                       \
    __asm volatile ("ISB SY");

 #define portENABLE_INTERRUPTS()                     \
    __asm volatile ("MSR DAIFCLR, #1" ::: "memory"); \
    __asm volatile ("DSB SY");                       \
    __asm volatile ("ISB SY");

/* These macros do not globally disable/enable interrupts.  They do mask off
 * interrupts that have a priority below configMAX_API_CALL_INTERRUPT_PRIORITY. */
 #define portENTER_CRITICAL()                                vPortEnterCritical();
 #define portEXIT_CRITICAL()                                 vPortExitCritical();
 #define portSET_INTERRUPT_MASK_FROM_ISR()                   uxPortSetInterruptMask()
 #define portCLEAR_INTERRUPT_MASK_FROM_ISR(x)                vPortClearInterruptMask(x)

/*-----------------------------------------------------------*/

/* Task function macros as described on the FreeRTOS.org WEB site.  These are
 * not required for this port but included in case common demo code that uses these
 * macros is used. */
 #define portTASK_FUNCTION_PROTO(vFunction, pvParameters)    void vFunction(void * pvParameters)
 #define portTASK_FUNCTION(vFunction, pvParameters)          void vFunction(void * pvParameters)

/* Prototype of the FreeRTOS tick handler.  This must be installed as the
 * handler for whichever peripheral is used to generate the RTOS tick. */
 #if defined(BSP_MCU_GROUP_RZA3M) || defined(BSP_MCU_GROUP_RZA3UL)
void FreeRTOS_Tick_Handler(timer_callback_args_t * unused);

 #else
void FreeRTOS_Tick_Handler(void);

 #endif

/* Any task that uses the floating point unit MUST call vPortTaskUsesFPU()
 * before any floating point instructions are executed. */
void vPortTaskUsesFPU(void);

 #define portTASK_USES_FLOATING_POINT()    vPortTaskUsesFPU()

 #define portLOWEST_INTERRUPT_PRIORITY               (((uint32_t) configUNIQUE_INTERRUPT_PRIORITIES) - 1UL)
 #define portLOWEST_USABLE_INTERRUPT_PRIORITY        (portLOWEST_INTERRUPT_PRIORITY - 1UL)

/* Architecture specific optimisations. */
 #ifndef configUSE_PORT_OPTIMISED_TASK_SELECTION
  #define configUSE_PORT_OPTIMISED_TASK_SELECTION    1
 #endif

 #if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1

/* Store/clear the ready priorities in a bit map. */
  #define portRECORD_READY_PRIORITY(uxPriority, uxReadyPriorities)    (uxReadyPriorities) |= (1UL << (uxPriority))
  #define portRESET_READY_PRIORITY(uxPriority, uxReadyPriorities)     (uxReadyPriorities) &= ~(1UL << (uxPriority))

/*-----------------------------------------------------------*/

  #define portGET_HIGHEST_PRIORITY(uxTopPriority,                                     \
                                   uxReadyPriorities)                 uxTopPriority = \
    (31 - __builtin_clz(uxReadyPriorities))

 #endif                                /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

 #ifdef configASSERT
void vPortValidateInterruptPriority(void);

  #define portASSERT_IF_INTERRUPT_PRIORITY_INVALID()    vPortValidateInterruptPriority()
 #endif                                /* configASSERT */

 #define portNOP()                                      __asm volatile ("NOP")

 #if defined(__GNUC__) || defined(__ARMCC_VERSION)
  #define portINLINE    __inline
 #elif defined(__ICCARM__)
  #define portINLINE    inline
 #endif

 #ifdef __cplusplus
}                                      /* extern C */
 #endif

/* The number of bits to shift for an interrupt priority is dependent on the
 * number of bits implemented by the interrupt controller. */
 #if configUNIQUE_INTERRUPT_PRIORITIES == 16
  #define portPRIORITY_SHIFT            4
  #define portMAX_BINARY_POINT_VALUE    3
 #elif configUNIQUE_INTERRUPT_PRIORITIES == 32
  #define portPRIORITY_SHIFT            3
  #define portMAX_BINARY_POINT_VALUE    2
 #elif configUNIQUE_INTERRUPT_PRIORITIES == 64
  #define portPRIORITY_SHIFT            2
  #define portMAX_BINARY_POINT_VALUE    1
 #elif configUNIQUE_INTERRUPT_PRIORITIES == 128
  #define portPRIORITY_SHIFT            1
  #define portMAX_BINARY_POINT_VALUE    0
 #elif configUNIQUE_INTERRUPT_PRIORITIES == 256
  #define portPRIORITY_SHIFT            0
  #define portMAX_BINARY_POINT_VALUE    0
 #else
  #error \
    Invalid configUNIQUE_INTERRUPT_PRIORITIES setting.  configUNIQUE_INTERRUPT_PRIORITIES must be set to the number of unique priorities implemented by the target hardware
 #endif

/*-----------------------------------------------------------*/

/* Structure passed to pvParameters when task creation code is generated. */
typedef struct st_rm_freertos_port_parameters
{
    void * p_context;                  // Pointer to user data
} rm_freertos_port_parameters_t;

/*-----------------------------------------------------------*/

/* Interrupt controller access addresses. */
 #define portICCPMR_PRIORITY_MASK_OFFSET                      (0x04)
 #define portICCIAR_INTERRUPT_ACKNOWLEDGE_OFFSET              (0x0C)
 #define portICCEOIR_END_OF_INTERRUPT_OFFSET                  (0x10)
 #define portICCBPR_BINARY_POINT_OFFSET                       (0x08)
 #define portICCRPR_RUNNING_PRIORITY_OFFSET                   (0x14)

 #define portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS       (configINTERRUPT_CONTROLLER_BASE_ADDRESS + \
                                                               configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET)
 #define portICCPMR_PRIORITY_MASK_REGISTER                    (*((volatile uint32_t *) (                              \
                                                                     portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS + \
                                                                     portICCPMR_PRIORITY_MASK_OFFSET)))
 #define portICCIAR_INTERRUPT_ACKNOWLEDGE_REGISTER_ADDRESS    (portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS + \
                                                               portICCIAR_INTERRUPT_ACKNOWLEDGE_OFFSET)
 #define portICCEOIR_END_OF_INTERRUPT_REGISTER_ADDRESS        (portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS + \
                                                               portICCEOIR_END_OF_INTERRUPT_OFFSET)
 #define portICCPMR_PRIORITY_MASK_REGISTER_ADDRESS            (portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS + \
                                                               portICCPMR_PRIORITY_MASK_OFFSET)
 #define portICCBPR_BINARY_POINT_REGISTER                     (*((const volatile uint32_t *) (                        \
                                                                     portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS + \
                                                                     portICCBPR_BINARY_POINT_OFFSET)))
 #define portICCRPR_RUNNING_PRIORITY_REGISTER                 (*((const volatile uint32_t *) (                        \
                                                                     portINTERRUPT_CONTROLLER_CPU_INTERFACE_ADDRESS + \
                                                                     portICCRPR_RUNNING_PRIORITY_OFFSET)))

 #define portMEMORY_BARRIER()    __asm volatile ("" ::: "memory")

#endif                                 /* PORTMACRO_CA55_H */
