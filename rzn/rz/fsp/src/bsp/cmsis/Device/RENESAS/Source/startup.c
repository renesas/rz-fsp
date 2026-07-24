/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern bool g_bsp_software_reset_occurred;
extern bool g_bsp_first_operation;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
#if (1 == _RZ_ORDINAL)
extern void bsp_master_mpu_init(void);
extern void bsp_global_system_counter_init(void);

 #if (1 == BSP_CFG_EMMC_BOOT)
extern void bsp_sdhi_emmc_media_init(void);

 #endif
#endif

#if defined(BSP_CFG_CORE_CR52)
 #if (BSP_FEATURE_TFU_SUPPORTED & BSP_CFG_USE_TFU_MATHLIB)
extern void bsp_tfu_init(void);

 #endif
#endif

#if BSP_CFG_C_RUNTIME_INIT
extern void bsp_loader_data_init(void);
extern void bsp_loader_bss_init(void);
extern void bsp_static_constructor_init(void);

#endif

#if !(BSP_CFG_RAM_EXECUTION)
extern void bsp_application_bss_init(void);
extern void bsp_copy_to_ram(void);

 #if (1U < BSP_FEATURE_BSP_CR52_CORE_NUM) || (1U < BSP_FEATURE_BSP_CA55_CORE_NUM)
extern void bsp_cpu_reset_release(void);

 #endif
#endif

#if !BSP_CFG_PORT_PROTECT
extern void bsp_release_port_protect(void);

#endif

extern void bsp_memory_protect_setting(void);
extern void bsp_irq_cfg_common(void);

extern void R_BSP_WarmStart(bsp_warm_start_event_t event);

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
int32_t main(void);

#if BSP_CFG_EARLY_INIT
static void bsp_init_uninitialized_vars(void);

#endif

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZN
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_BSP_MCU
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize the MPU and the runtime environment.
 **********************************************************************************************************************/
void SystemInit (void)
{
    /* This process runs only once after startup. */
    if (true == g_bsp_first_operation)
    {
        g_bsp_software_reset_occurred = false;
    }

#if BSP_CFG_EARLY_INIT

    /* Initialize uninitialized BSP variables early for use in R_BSP_WarmStart. */
    bsp_init_uninitialized_vars();
#endif

    /* Call before initializing clock and variables. */
    R_BSP_WarmStart(BSP_WARM_START_RESET);

#if (1 == _RZ_ORDINAL)

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* Configure system clocks. */
        bsp_clock_init();
    }
#endif

    /* Call post clock initialization hook. */
    R_BSP_WarmStart(BSP_WARM_START_POST_CLOCK);

#if BSP_CFG_C_RUNTIME_INIT
 #if (1 == _RZ_ORDINAL)
  #if (1 == BSP_CFG_ESD_BOOT) || (1 == BSP_CFG_EMMC_BOOT)

    /* Initialize uninitialized BSP SDHI variables for use in eSD boot or eMMC boot. */
    bsp_sdhi_init_uninitialized_vars();

    /* Stores the SDHI register settings. */
    bsp_sdhi_store_sdhi_register();

   #if (1 == BSP_CFG_EMMC_BOOT)

    /* Initializes eMMC device. */
    bsp_sdhi_emmc_media_init();
   #endif
  #endif
 #endif

    /* Copy the primary core loader data from external Flash to internal RAM. */
    bsp_loader_data_init();

    /* Clear loader bss section in internal RAM. */
    bsp_loader_bss_init();
#endif

#if BSP_FEATURE_ADDRESS_EXPANDER_SUPPORTED
 #if (1 == _RZ_ORDINAL)

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* Initialize the Address Expander settings. */
        bsp_address_expander_init();
    }
 #endif
#endif

#if BSP_FEATURE_TZC400_SUPPORTED
 #if (1 == _RZ_ORDINAL)

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* Initialize the TZC-400 settings. */
        bsp_tzc_400_cfg();
    }
 #endif
#endif

    /* Initialize SystemCoreClock variable. */
    SystemCoreClockUpdate();

    /* Set memory attributes, etc. */
    bsp_memory_protect_setting();

#if !(BSP_CFG_RAM_EXECUTION)

    /* Clear bss section in internal RAM. */
    bsp_application_bss_init();

    /* Copy the application program from external Flash to internal RAM.
     * In the case of multi-core operation, copies each section (vector, loader(program/data), user(program/data)) of
     * the secondary core (or later). */
    bsp_copy_to_ram();

 #if (1 == _RZ_ORDINAL)
  #if (1 == BSP_CFG_ESD_BOOT) || (1 == BSP_CFG_EMMC_BOOT)

    /* Restores the saved SDHI register setting value. */
    bsp_sdhi_restore_sdhi_register();
  #endif
 #endif
#endif

#if BSP_CFG_C_RUNTIME_INIT

    /* Initialize static constructors */
    bsp_static_constructor_init();
#endif

#if !BSP_CFG_PORT_PROTECT

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* When writing to the PRCR register the upper 8-bits must be the correct key.
         * Set lower bits to 0 to disable writes. */
        bsp_release_port_protect();
    }
#endif

    /* Call Post C runtime initialization hook. */
    R_BSP_WarmStart(BSP_WARM_START_POST_C);

#if (1 == _RZ_ORDINAL)

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* Initialize the Master-MPU settings. */
        bsp_master_mpu_init();

        /* Initialize global system counter. The counter is enabled and is incrementing. */
        bsp_global_system_counter_init();
    }
#endif

    /* GIC initialization */
    bsp_irq_cfg_common();

    /* Initialize GIC interrupts. */
    bsp_irq_cfg();

#if defined(BSP_CFG_CORE_CR52)
 #if (BSP_FEATURE_TFU_SUPPORTED & BSP_CFG_USE_TFU_MATHLIB)

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* Initialize the TFU settings. */
        bsp_tfu_init();
    }
 #endif
#endif

    /* Call any BSP specific code. No arguments are needed so NULL is sent. */
    bsp_init(NULL);

#if !(BSP_CFG_RAM_EXECUTION)
 #if (1U < BSP_FEATURE_BSP_CR52_CORE_NUM) || (1U < BSP_FEATURE_BSP_CA55_CORE_NUM)

    /* After a software reset, the following processes are not executed. */
    if (false == g_bsp_software_reset_occurred)
    {
        /* Reset release each CPU */
        bsp_cpu_reset_release();
    }
 #endif
#endif

    /* The first operation has been completed at this point. */
    g_bsp_first_operation = false;

    /* Jump to main. */
    main();

    while (1)
    {
        /* Infinite Loop. */
    }
}

/** @} (end addtogroup BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

#if BSP_CFG_EARLY_INIT

/*******************************************************************************************************************//**
 * Initialize BSP variables not handled by C runtime startup.
 **********************************************************************************************************************/
static void bsp_init_uninitialized_vars (void)
{
    extern volatile uint16_t g_protect_counters[];
    for (uint32_t i = 0; i < 4; i++)
    {
        g_protect_counters[i] = 0;
    }

    SystemCoreClockUpdate();
}

#endif
