/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#if BSP_TZ_SECURE_BUILD
 #define BSP_TZ_STACK_SEAL_SIZE    (8U)
#else
 #define BSP_TZ_STACK_SEAL_SIZE    (0U)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Defines function pointers to be used with vector table. */
typedef void (* exc_ptr_t)(void);

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void    Reset_Handler_NS(void);
void    Default_Handler(void);
void    NMI_Handler_NS(void);
int32_t main(void);

/*******************************************************************************************************************//**
 * MPU starts executing here out of reset. Main stack pointer is set up already.
 **********************************************************************************************************************/
void Reset_Handler_NS (void)
{
    /* Initialize system using BSP. */
    SystemInit();

    /* Call user application. */
    main();

    while (1)
    {
        /* Infinite Loop. */
    }
}

/*******************************************************************************************************************//**
 * Default exception handler.
 **********************************************************************************************************************/
void Default_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/*******************************************************************************************************************//**
 * Non-maskable interrupt handler.
 **********************************************************************************************************************/
void NMI_Handler_NS (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/* Main stack */
static uint8_t g_main_stack[BSP_CFG_STACK_MAIN_BYTES + BSP_TZ_STACK_SEAL_SIZE] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_STACK);

/* Heap */
#if (BSP_CFG_HEAP_BYTES > 0)

BSP_DONT_REMOVE static uint8_t g_heap[BSP_CFG_HEAP_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT) \
    BSP_PLACE_IN_SECTION(BSP_SECTION_HEAP);
#endif

/* All system exceptions in the vector table are weak references to Default_Handler. If the user wishes to handle
 * these exceptions in their code they should define their own function with the same name.
 */
#if defined(__ICCARM__)
 #define WEAK_REF_ATTRIBUTE

 #pragma weak HardFault_Handler_NS                     = Default_Handler
 #pragma weak MemManage_Handler_NS                     = Default_Handler
 #pragma weak BusFault_Handler_NS                      = Default_Handler
 #pragma weak UsageFault_Handler_NS                    = Default_Handler
 #pragma weak SVC_Handler_NS                           = Default_Handler
 #pragma weak DebugMon_Handler_NS                      = Default_Handler
 #pragma weak PendSV_Handler_NS                        = Default_Handler
 #pragma weak SysTick_Handler_NS                       = Default_Handler
#elif defined(__GNUC__)

 #define WEAK_REF_ATTRIBUTE    __attribute__((weak, alias("Default_Handler")))
#endif

void HardFault_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void MemManage_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void BusFault_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void UsageFault_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void SVC_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void DebugMon_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void PendSV_Handler_NS(void) WEAK_REF_ATTRIBUTE;
void SysTick_Handler_NS(void) WEAK_REF_ATTRIBUTE;

#if !BSP_NONSECURE_TRANSITION
BSP_DONT_REMOVE const exc_ptr_t __Vectors = {NULL};

#else

/* Vector table. */
BSP_DONT_REMOVE const exc_ptr_t __Vectors[BSP_CORTEX_VECTOR_TABLE_ENTRIES] BSP_PLACE_IN_SECTION(
    BSP_SECTION_FIXED_VECTORS) =
{
    (exc_ptr_t) (&g_main_stack[0] + BSP_CFG_STACK_MAIN_BYTES), /*      Initial Stack Pointer     */
    Reset_Handler_NS,                                          /*      Reset Handler             */
    NMI_Handler_NS,                                            /*      NMI Handler               */
    HardFault_Handler_NS,                                      /*      Hard Fault Handler        */
    MemManage_Handler_NS,                                      /*      MPU Fault Handler         */
    BusFault_Handler_NS,                                       /*      Bus Fault Handler         */
    UsageFault_Handler_NS,                                     /*      Usage Fault Handler       */
    0,                                                         /*      Reserved                  */
    0,                                                         /*      Reserved                  */
    0,                                                         /*      Reserved                  */
    0,                                                         /*      Reserved                  */
    SVC_Handler_NS,                                            /*      SVCall Handler            */
    DebugMon_Handler_NS,                                       /*      Debug Monitor Handler     */
    0,                                                         /*      Reserved                  */
    PendSV_Handler_NS,                                         /*      PendSV Handler            */
    SysTick_Handler_NS,                                        /*      SysTick Handler           */
};
#endif

/** @} (end addtogroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif
