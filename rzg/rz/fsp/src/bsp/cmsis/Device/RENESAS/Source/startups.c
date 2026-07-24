/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : startups.c
 * Version      : 1.00
 * Description  : Vector table & exception handler for Secure.
 *********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZG
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

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
void Reset_Handler_S(void);
void Default_Handler_S(void);
void NMI_Handler_S(void);
void SecureFault_Handler(void);

/*******************************************************************************************************************//**
 * MPU starts executing here out of reset. Main stack pointer is set up already.
 **********************************************************************************************************************/
void Reset_Handler_S (void)
{
    /* Initialize system using BSP. */
    SystemInit_S();

    while (1)
    {
        /* Infinite Loop. */
    }
}

/*******************************************************************************************************************//**
 * Default exception handler.
 **********************************************************************************************************************/
void Default_Handler_S (void)
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
void NMI_Handler_S (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/*******************************************************************************************************************//**
 * SecureFault_Handler
 **********************************************************************************************************************/
void SecureFault_Handler (void)
{
    /** A error has occurred. The user will need to investigate the cause. Common problems are stack corruption
     *  or use of an invalid pointer. Use the Fault Status window in e2 studio or manually check the fault status
     *  registers for more information.
     */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/* Main stack */
static uint8_t g_main_s_stack[BSP_CFG_S_STACK_MAIN_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT) BSP_PLACE_IN_SECTION(
    BSP_SECTION_SECURE_STACK);

/* All system exceptions in the vector table are weak references to Default_Handler_S. If the user wishes to handle
 * these exceptions in their code they should define their own function with the same name.
 */
#if defined(__ICCARM__)
 #define WEAK_REF_ATTRIBUTE

 #pragma weak HardFault_Handler_S                      = Default_Handler_S
 #pragma weak MemManage_Handler_S                      = Default_Handler_S
 #pragma weak BusFault_Handler_S                       = Default_Handler_S
 #pragma weak UsageFault_Handler_S                     = Default_Handler_S
 #pragma weak SVC_Handler_S                            = Default_Handler_S
 #pragma weak DebugMon_Handler_S                       = Default_Handler_S
 #pragma weak PendSV_Handler_S                         = Default_Handler_S
 #pragma weak SysTick_Handler_S                        = Default_Handler_S
#elif defined(__GNUC__)

 #define WEAK_REF_ATTRIBUTE    __attribute__((weak, alias("Default_Handler_S")))
#endif

void HardFault_Handler_S(void) WEAK_REF_ATTRIBUTE;
void MemManage_Handler_S(void) WEAK_REF_ATTRIBUTE;
void BusFault_Handler_S(void) WEAK_REF_ATTRIBUTE;
void UsageFault_Handler_S(void) WEAK_REF_ATTRIBUTE;
void SVC_Handler_S(void) WEAK_REF_ATTRIBUTE;
void DebugMon_Handler_S(void) WEAK_REF_ATTRIBUTE;
void PendSV_Handler_S(void) WEAK_REF_ATTRIBUTE;
void SysTick_Handler_S(void) WEAK_REF_ATTRIBUTE;

/* Vector table. */
BSP_DONT_REMOVE const exc_ptr_t __Secure_Vectors[BSP_CORTEX_VECTOR_TABLE_ENTRIES] BSP_PLACE_IN_SECTION(
    BSP_SECTION_FIXED_SECURE_VECTORS) =
{
    (exc_ptr_t) (&g_main_s_stack[0] + BSP_CFG_S_STACK_MAIN_BYTES), /*      Initial Stack Pointer     */
    Reset_Handler_S,                                               /*      Reset Handler             */
    NMI_Handler_S,                                                 /*      NMI Handler               */
    HardFault_Handler_S,                                           /*      Hard Fault Handler        */
    MemManage_Handler_S,                                           /*      MPU Fault Handler         */
    BusFault_Handler_S,                                            /*      Bus Fault Handler         */
    UsageFault_Handler_S,                                          /*      Usage Fault Handler       */
    SecureFault_Handler,                                           /*      Secure Fault Handler      */
    0,                                                             /*      Reserved                  */
    0,                                                             /*      Reserved                  */
    0,                                                             /*      Reserved                  */
    SVC_Handler_S,                                                 /*      SVCall Handler            */
    DebugMon_Handler_S,                                            /*      Debug Monitor Handler     */
    0,                                                             /*      Reserved                  */
    PendSV_Handler_S,                                              /*      PendSV Handler            */
    SysTick_Handler_S,                                             /*      SysTick Handler           */
};

/** @} (end addtogroup BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif
