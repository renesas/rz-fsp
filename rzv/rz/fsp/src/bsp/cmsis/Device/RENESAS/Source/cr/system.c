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

#include "../../../../../mcu/all/bsp_clocks.h"

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

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
uint32_t g_wait_data            BSP_PLACE_IN_SECTION(".wait_data");
uint32_t g_wait_data_other_core BSP_PLACE_IN_SECTION(".wait_data_other_core");

extern mpu_region_table_cfg_t g_mpu_region_table_array[];

/** System Clock Frequency (Core Clock) */
uint32_t SystemCoreClock BSP_SECTION_EARLY_INIT;

#if defined(__ICCARM__)

 #pragma section="VECTOR_RBLOCK"
 #pragma section="VECTOR_WBLOCK"
 #pragma section="USER_PRG_RBLOCK"
 #pragma section="USER_PRG_WBLOCK"
 #pragma section="USER_DATA_RBLOCK"
 #pragma section="USER_DATA_WBLOCK"
 #pragma section="USER_DATA_ZBLOCK"
 #pragma section="NONCACHE_BUFFER_ZBLOCK"
 #pragma section="CACHE_BUFFER_ZBLOCK"

#endif                                 // __ICCARM__

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

#if defined(__ICCARM__)

void R_BSP_WarmStart(bsp_warm_start_event_t event);

 #pragma weak R_BSP_WarmStart

#elif defined(__GNUC__) || defined(__ARMCC_VERSION)

void R_BSP_WarmStart(bsp_warm_start_event_t event) __attribute__((weak));

#endif

#if BSP_CFG_EARLY_INIT
static void bsp_init_uninitialized_vars(void);

#endif

/* Initialize static constructors */
#if BSP_CFG_C_RUNTIME_INIT
void bsp_static_constructor_init(void);

 #if defined(__GNUC__)

extern void (* __preinit_array_start[])(void);
extern void (* __preinit_array_end[])(void);
extern void (* __init_array_start[])(void);
extern void (* __init_array_end[])(void);
 #elif defined(__ICCARM__)
extern void __call_ctors(void const *, void const *);

  #pragma section = "SHT$$PREINIT_ARRAY" const
  #pragma section = "SHT$$INIT_ARRAY" const
 #endif
#endif

/* Stacks */
BSP_DONT_REMOVE static uint8_t g_fiq_stack[BSP_CFG_STACK_FIQ_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_FIQ_STACK);
BSP_DONT_REMOVE static uint8_t g_irq_stack[BSP_CFG_STACK_IRQ_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_IRQ_STACK);
BSP_DONT_REMOVE static uint8_t g_abt_stack[BSP_CFG_STACK_ABT_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_ABT_STACK);
BSP_DONT_REMOVE static uint8_t g_und_stack[BSP_CFG_STACK_UND_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_UND_STACK);
BSP_DONT_REMOVE static uint8_t g_sys_stack[BSP_CFG_STACK_SYS_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_SYS_STACK);
BSP_DONT_REMOVE static uint8_t g_svc_stack[BSP_CFG_STACK_SVC_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_SVC_STACK);

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
    /* Waiting for other cores to complete initialization in a multi-core environment */
    if (0 != BSP_CR8_CORE_NUM)
    {
        while (g_wait_data_other_core == BSP_FEATURE_BSP_INIT_WAIT_DATA)
        {
            ;
        }
    }

#if BSP_CFG_EARLY_INIT

    /* Initialize uninitialized BSP variables early for use in R_BSP_WarmStart. */
    bsp_init_uninitialized_vars();
#endif

    R_BSP_WarmStart(BSP_WARM_START_RESET);

#if BSP_CFG_C_RUNTIME_INIT
 #if defined(__ICCARM__)
    __iar_data_init3();

    /* Initialize the application data and clear the application bss.
     * This code is for RAM Execution. If you want to boot with ROM,
     * enable app_copy and app_bss_init, and disable this code.
     * Also need to change icf file. */
    __asm volatile (
        "    mov  r1, %[bss_block]  \n"
        ::[bss_block] "r" (__section_begin("BSS_BLOCK")) : "r1");

    __asm volatile (
        "    mov  r2, %[bss_block]  \n"
        ::[bss_block] "r" (__section_end("BSS_BLOCK")) : "r2");

    __asm volatile (

        /* Clear BSS. */
        "    ldr r0, = 0x00000000                            \n"
        "    cmp r2, r1                                      \n"
        "    beq bss_init_end                                \n"

        "clear_bss:                                          \n"
        "    strb r0, [r1], #0                               \n"
        "    add r1, r1, #1                                  \n"
        "    cmp r2, r1                                      \n"
        "    bne clear_bss                                   \n"
        "    bss_init_end:                                   \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (
        "    mov  r1, %[bss_usr_block]  \n"
        ::[bss_block] "r" (__section_begin("BSS_USR_BLOCK")) : "r1");

    __asm volatile (
        "    mov  r2, %[bss_usr_block]  \n"
        ::[bss_block] "r" (__section_end("BSS_USR_BLOCK")) : "r2");

    __asm volatile (

        /* Clear User BSS. */
        "    ldr r0, = 0x00000000                            \n"
        "    cmp r2, r1                                      \n"
        "    beq bss_usr_init_end                            \n"

        "clear_usr_bss:                                      \n"
        "    strb r0, [r1], #0                               \n"
        "    add r1, r1, #1                                  \n"
        "    cmp r2, r1                                      \n"
        "    bne clear_usr_bss                               \n"
        "    bss_usr_init_end:                               \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (
        "    mov  r1, %[sram_cache_buf_block]        \n"
        ::[sram_cache_buf_block] "r" (__section_begin("SRAM_CACHE_BUF_BLOCK")) : "r1");

    __asm volatile (
        "    mov  r2, %[sram_cache_buf_block]        \n"
        ::[sram_cache_buf_block] "r" (__section_end("SRAM_CACHE_BUF_BLOCK")) : "r2");

    __asm volatile (

        /* Clear SRAM cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    cmp  r2, r1                                     \n"
        "    beq  cache_buffer_init_end                      \n"
        "clear_cache_buffer:                                 \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   clear_cache_buffer                        \n"
        "    cache_buffer_init_end:                          \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (
        "    mov  r1, %[sram_noncache_buf_block]        \n"
        ::[sram_noncache_buf_block] "r" (__section_begin("SRAM_NONCACHE_BUF_BLOCK")) : "r1");

    __asm volatile (
        "    mov  r2, %[sram_noncache_buf_block]        \n"
        ::[sram_noncache_buf_block] "r" (__section_end("SRAM_NONCACHE_BUF_BLOCK")) : "r2");

    __asm volatile (

        /* Clear SRAM non-cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    cmp  r2, r1                                     \n"
        "    beq  noncache_buffer_init_end                   \n"
        "clear_noncache_buffer:                              \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   clear_noncache_buffer                     \n"
        "    noncache_buffer_init_end:                       \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (
        "    mov  r1, %[sdram_cache_buf_block]        \n"
        ::[sdram_cache_buf_block] "r" (__section_begin("SDRAM_CACHE_BUF_BLOCK")) : "r1");

    __asm volatile (
        "    mov  r2, %[sdram_cache_buf_block]        \n"
        ::[sdram_cache_buf_block] "r" (__section_end("SDRAM_CACHE_BUF_BLOCK")) : "r2");

    __asm volatile (

        /* Clear SDRAM cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    cmp  r2, r1                                     \n"
        "    beq  sdram_cache_buffer_init_end                \n"
        "sdram_clear_cache_buffer:                           \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   sdram_clear_cache_buffer                  \n"
        "    sdram_cache_buffer_init_end:                    \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (
        "    mov  r1, %[sdram_noncache_buf_block]        \n"
        ::[sdram_noncache_buf_block] "r" (__section_begin("SDRAM_NONCACHE_BUF_BLOCK")) : "r1");

    __asm volatile (
        "    mov  r2, %[sdram_noncache_buf_block]        \n"
        ::[sdram_noncache_buf_block] "r" (__section_end("SDRAM_NONCACHE_BUF_BLOCK")) : "r2");

    __asm volatile (

        /* Clear SDRAM non-cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    cmp  r2, r1                                     \n"
        "    beq  sdram_noncache_buffer_init_end             \n"
        "sdram_clear_noncache_buffer:                        \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   sdram_clear_noncache_buffer               \n"
        "    sdram_noncache_buffer_init_end:                 \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");
 #elif defined(__GNUC__)
    __asm volatile (

        /* Clear BSS. */
        "    ldr r0, = 0x00000000                            \n"
        "    ldr r1, = __bss_start__                         \n"
        "    ldr r2, = __bss_end__                           \n"
        "    cmp r2, r1                                      \n"
        "    beq bss_init_end                                \n"

        "clear_bss:                                          \n"
        "    strb r0, [r1], #0                               \n"
        "    add r1, r1, #1                                  \n"
        "    cmp r2, r1                                      \n"
        "    bne clear_bss                                   \n"
        "    bss_init_end:                                   \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (

        /* Clear User BSS. */
        "    ldr r0, = 0x00000000                            \n"
        "    ldr r1, = __bss_usr_start__                     \n"
        "    ldr r2, = __bss_usr_end__                       \n"
        "    cmp r2, r1                                      \n"
        "    beq bss_usr_init_end                            \n"

        "clear_usr_bss:                                      \n"
        "    strb r0, [r1], #0                               \n"
        "    add r1, r1, #1                                  \n"
        "    cmp r2, r1                                      \n"
        "    bne clear_usr_bss                               \n"
        "    bss_usr_init_end:                               \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");

    __asm volatile (

        /* Clear SRAM cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    ldr  r1, =_cbuffer_start                        \n"
        "    ldr  r2, =_cbuffer_end                          \n"
        "    cmp  r2, r1                                     \n"
        "    beq  cache_buffer_init_end                      \n"
        "clear_cache_buffer:                                 \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   clear_cache_buffer                        \n"
        "    cache_buffer_init_end:                          \n"
        "    dsb                                             \n" /* Ensuring data-changing */

        /* Clear SRAM non-cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    ldr  r1, =_ncbuffer_start                       \n"
        "    ldr  r2, =_ncbuffer_end                         \n"
        "    cmp  r2, r1                                     \n"
        "    beq  noncache_buffer_init_end                   \n"
        "clear_noncache_buffer:                              \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   clear_noncache_buffer                     \n"
        "    noncache_buffer_init_end:                       \n"
        "    dsb                                             \n" /* Ensuring data-changing */

        /* Clear SDRAM cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    ldr  r1, =_cbuffer_sdram_start                  \n"
        "    ldr  r2, =_cbuffer_sdram_end                    \n"
        "    cmp  r2, r1                                     \n"
        "    beq  sdram_cache_buffer_init_end                \n"
        "sdram_clear_cache_buffer:                           \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   sdram_clear_cache_buffer                  \n"
        "    sdram_cache_buffer_init_end:                    \n"
        "    dsb                                             \n" /* Ensuring data-changing */

        /* Clear SDRAM non-cache buffer. */
        "    ldr  r0, =0x00000000                            \n"
        "    ldr  r1, =_ncbuffer_start                       \n"
        "    ldr  r2, =_ncbuffer_end                         \n"
        "    cmp  r2, r1                                     \n"
        "    beq  sdram_noncache_buffer_init_end             \n"
        "sdram_clear_noncache_buffer:                        \n"
        "    strb  r0, [r1], #0                              \n"
        "    add   r1, r1, #1                                \n"
        "    cmp   r2, r1                                    \n"
        "    bne   sdram_clear_noncache_buffer               \n"
        "    sdram_noncache_buffer_init_end:                 \n"
        "    dsb                                             \n" /* Ensuring data-changing */
        ::: "r0", "r1", "r2", "memory");
 #endif
#endif

    bsp_clock_init();

    R_BSP_WarmStart(BSP_WARM_START_POST_CLOCK);

    /* Prediction, instruction cache, data cache disable */
    R_BSP_CacheDisable();

    /* Prediction, instruction cache, data cache invalidate */
    R_BSP_CacheInvalidate();

    /* Setup MPU regions */
    R_BSP_MPUInit(g_mpu_region_table_array);

    R_BSP_CacheEnable();

#if BSP_CFG_C_RUNTIME_INIT

    /* Initialize static constructors */
    bsp_static_constructor_init();
#endif

#if !BSP_CFG_PFS_PROTECT
    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;
 #if BSP_FEATURE_BSP_SUPPORT_PFCWE_PROTECT
    R_GPIO->PWPR = 0;                                                               ///< Clear BOWI bit - writing to PFCWE bit enabled
    R_GPIO->PWPR = 1U << BSP_FEATURE_IOPORT_PWPR_PFCWE_OFFSET;                      ///< Set PFCWE bit - writing to PFC register enabled
 #else
    R_GPIO->PWPR = (uint32_t) ((BSP_FEATURE_IOPORT_PFC_PWPR_REGWE_A_MASK & R_GPIO->PWPR) | \
                               (1U << BSP_FEATURE_IOPORT_PFC_PWPR_REGWE_A_OFFSET)); ///< Set REGWE_A bit - writing to PFC and PMC registers enabled
 #endif
    FSP_CRITICAL_SECTION_EXIT;
#endif

    R_BSP_WarmStart(BSP_WARM_START_POST_C);

    /* Jump to bsp_irq_cfg */
    bsp_irq_cfg();

    __enable_irq();

    /* Clear data for wait initialize */
    g_wait_data = 0;
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

#if BSP_CFG_EARLY_INIT

/*******************************************************************************************************************//**
 * Initialize BSP variables not handled by C runtime startup.
 **********************************************************************************************************************/
static void bsp_init_uninitialized_vars (void)
{
    g_protect_pfswe_counter = 0;

 #if BSP_CFG_EARLY_INIT

    /* Set SystemCoreClock */
    SystemCoreClock = BSP_FEATURE_BSP_SYSTEM_CORE_CLOCK;
 #endif
}

#endif

/*******************************************************************************************************************//**
 * Initialize static constructors.
 **********************************************************************************************************************/
#if BSP_CFG_C_RUNTIME_INIT
void bsp_static_constructor_init (void)
{
 #if defined(__ICCARM__)
    void const * pibase = __section_begin("SHT$$PREINIT_ARRAY");
    void const * ilimit = __section_end("SHT$$INIT_ARRAY");
    __call_ctors(pibase, ilimit);
 #elif defined(__GNUC__)
    int32_t count;
    int32_t i;

    count = __preinit_array_end - __preinit_array_start;
    for (i = 0; i < count; i++)
    {
        __preinit_array_start[i]();
    }

    count = __init_array_end - __init_array_start;
    for (i = 0; i < count; i++)
    {
        __init_array_start[i]();
    }
 #endif
}

#endif

/** @} (end addtogroup RZV_BSP_MCU) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif
