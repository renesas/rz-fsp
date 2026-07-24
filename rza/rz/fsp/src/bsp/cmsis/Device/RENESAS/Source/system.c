/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <string.h>
#include "bsp_api.h"
#include "../../../../mcu/all/bsp_clocks.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZA
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_BSP_MCU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** System Clock Frequency (Core Clock) */
uint32_t SystemCoreClock BSP_SECTION_EARLY_INIT;

/* Initialize static constructors */
#if defined(__ARMCC_VERSION)
extern void (* Image$$INIT_ARRAY$$Base[])(void);
extern void (* Image$$INIT_ARRAY$$Limit[])(void);
 #if defined(__ARMCC_USING_STANDARDLIB)
  #include <rt_misc.h>
extern uint32_t Image$$ARM_LIB_HEAP$$ZI$$Base;
extern uint32_t Image$$ARM_LIB_HEAP$$ZI$$Length;
 #endif
#elif defined(__GNUC__)

extern void (* __init_array_start[])(void);

extern void (* __init_array_end[])(void);
#elif defined(__ICCARM__)
extern void __call_ctors(void const *, void const *);

 #pragma section = "SHT$$PREINIT_ARRAY" const
 #pragma section = "SHT$$INIT_ARRAY" const
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

#if defined(__ICCARM__)

void R_BSP_WarmStart(bsp_warm_start_event_t event);

 #pragma weak R_BSP_WarmStart

#elif defined(__GNUC__) || defined(__ARMCC_VERSION)

void R_BSP_WarmStart(bsp_warm_start_event_t event) __attribute__((weak));

#endif

#if defined(__ICCARM__)

void R_BSP_HardwareInit(void);

 #pragma weak R_BSP_HardwareInit

#elif defined(__GNUC__) || defined(__ARMCC_VERSION)

void R_BSP_HardwareInit(void) __attribute__((weak));

#endif

#if BSP_CFG_EARLY_INIT
static void bsp_init_uninitialized_vars(void);

#endif

/* Stacks */
BSP_DONT_REMOVE static uint8_t g_stack[BSP_CFG_STACK_MAIN_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_STACK);

/* Heap */
#if (BSP_CFG_HEAP_BYTES > 0)

BSP_DONT_REMOVE static uint8_t g_heap[BSP_CFG_HEAP_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT) \
    BSP_PLACE_IN_SECTION(BSP_SECTION_HEAP);
#endif

/*******************************************************************************************************************//**
 * Initialize the MPU and the runtime environment.
 **********************************************************************************************************************/
void SystemInit (void)
{
#if BSP_TZ_CFG_SKIP_INIT

    /* Initialize clock variables to be used with R_BSP_SoftwareDelay. */
    bsp_clock_freq_var_init();
#else
 #if BSP_FEATURE_TFU_SUPPORTED
    R_BSP_MODULE_START(FSP_IP_TFU, 0U);
 #endif

 #if BSP_CFG_EARLY_INIT

    /* Initialize uninitialized BSP variables early for use in R_BSP_WarmStart. */
    bsp_init_uninitialized_vars();
 #endif

    /* Call pre clock initialization hook. */
    R_BSP_WarmStart(BSP_WARM_START_RESET);

    /* Configure system clocks. */
    bsp_clock_init();
#endif

    /* Call post clock initialization hook. */
    R_BSP_WarmStart(BSP_WARM_START_POST_CLOCK);

#if BSP_CFG_C_RUNTIME_INIT

    /* Initialize static constructors */
 #if defined(__ARMCC_VERSION)
  #if defined(__ARMCC_USING_STANDARDLIB)
    __rt_lib_init((uint32_t) &Image$$ARM_LIB_HEAP$$ZI$$Base,
                  (uint32_t) &Image$$ARM_LIB_HEAP$$ZI$$Base + (uint32_t) &Image$$ARM_LIB_HEAP$$ZI$$Length);
  #else
    int32_t count = Image$$INIT_ARRAY$$Limit - Image$$INIT_ARRAY$$Base;
    for (int32_t i = 0; i < count; i++)
    {
        void (* p_init_func)(void) =
            (void (*)(void))((uint32_t) &Image$$INIT_ARRAY$$Base + (uint32_t) Image$$INIT_ARRAY$$Base[i]);
        p_init_func();
    }
  #endif
 #elif defined(__GNUC__)
    int32_t count = (int32_t) (__init_array_end - __init_array_start);
    for (int32_t i = 0; i < count; i++)
    {
        __init_array_start[i]();
    }

 #elif defined(__ICCARM__)
    void const * pibase = __section_begin("SHT$$PREINIT_ARRAY");
    void const * ilimit = __section_end("SHT$$INIT_ARRAY");
    __call_ctors(pibase, ilimit);
 #endif
#endif                                 // BSP_CFG_C_RUNTIME_INIT

    /* Initialize SystemCoreClock variable. */
    SystemCoreClockUpdate();

#if !BSP_CFG_PFS_PROTECT
    R_GPIO->PWPR = 0;                              ///< Clear BOWI bit - writing to PFSWE bit enabled
    R_GPIO->PWPR = 1U << BSP_IO_PWPR_PFSWE_OFFSET; ///< Set PFSWE bit - writing to PFS register enabled
#endif

    /* Call Post C runtime initialization hook. */
    R_BSP_WarmStart(BSP_WARM_START_POST_C);

    /* Initialize GIC interrupts. */
    bsp_irq_cfg();

    /* Call any BSP specific code. No arguments are needed so NULL is sent. */
    bsp_init(NULL);

    /* Initial setting of the cache */
    R_BSP_CACHE_EnableInst();
    R_BSP_CACHE_EnableData();
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.
 * This function is declared as a weak symbol higher up in this file because it is meant to be overridden by a user
 * implemented version. One of the main uses for this function is to call functional safety code during the startup
 * process. To use this function just copy this function into your own code and modify it to meet your needs.
 *
 * @param[in]  event    Where the code currently is in the start up process
 **********************************************************************************************************************/
void R_BSP_WarmStart (bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
        /* C runtime environment has not been setup so you cannot use globals. System clocks are not setup. */
    }

    if (BSP_WARM_START_POST_CLOCK == event)
    {
        /* C runtime environment has not been setup so you cannot use globals. Clocks have been initialized. */
    }
    else if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment, system clocks, and pins are all setup. */
    }
    else
    {
        /* Do nothing */
    }
}

/*******************************************************************************************************************//**
 * Function Name: R_BSP_HardwareInit
 * This function is called at various points during the startup process.
 * This function is declared as a weak symbol higher up in this file because it is meant to be overridden by a user
 * implemented version. One of the main uses for this function is to call functional safety code during the startup
 * process. To use this function just copy this function into your own code and modify it to meet your needs.
 *
 **********************************************************************************************************************/
void R_BSP_HardwareInit (void)
{
    /* Do nothing */
}

#if BSP_CFG_EARLY_INIT

/*******************************************************************************************************************//**
 * Initialize BSP variables not handled by C runtime startup.
 **********************************************************************************************************************/
static void bsp_init_uninitialized_vars (void)
{
    g_protect_pfswe_counter = 0;

    extern volatile uint16_t g_protect_counters[];
    for (uint32_t i = 0; i < 4; i++)
    {
        g_protect_counters[i] = 0;
    }

    extern bsp_grp_irq_cb_t g_bsp_group_irq_sources[];
    for (uint32_t i = 0; i < 16; i++)
    {
        g_bsp_group_irq_sources[i] = 0;
    }

 #if BSP_CFG_EARLY_INIT

    /* Set SystemCoreClock to I2CLK */
    SystemCoreClock = BSP_CFG_CLOCK_I2CLK_HZ;
 #endif
}

#endif

/** @} (end addtogroup BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif
