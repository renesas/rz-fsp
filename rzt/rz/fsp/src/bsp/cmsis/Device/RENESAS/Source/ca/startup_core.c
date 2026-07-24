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
#define SCR_EL3_BIT_ST                   (1 << 11)
#define SCR_EL3_BIT_RW                   (1 << 10)
#define SCR_EL3_BIT_EA                   (1 << 3)
#define SCR_EL3_BIT_FIQ                  (1 << 2)
#define SCR_EL3_BIT_IRQ                  (1 << 1)
#define HCR_EL2_BIT_RW                   ((uint64_t) 1 << 31)

#define R_BSP_GIC_INTID_1020             (1020)
#define R_BSP_GIC_INTID_1023             (1023)

#if defined(__GNUC__)
 #define BSP_STACK_LIMIT                 &__AArch64StackLimit
 #define BSP_SYSTEMINIT_B_INSTRUCTION \
    {                                 \
        __asm volatile (              \
            "b SystemInit   \n"       \
            ::: "memory");            \
    }                                 \

#elif defined(__ICCARM__)
 #define BSP_STACK_LIMIT                 __section_end(BSP_SECTION_AARCH64_STACK)
 #define BSP_SYSTEMINIT_B_INSTRUCTION    SystemInit();

#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
#if VECTOR_DATA_IRQ_COUNT > 0
extern fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES];
#endif
extern fsp_vector_t g_sgi_ppi_vector_table[BSP_CORTEX_VECTOR_TABLE_ENTRIES];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
extern void R_BSP_WarmStart_StackLess(void);

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void system_init(void) BSP_PLACE_IN_SECTION(".loader_text");
void bsp_register_initialization(void);
void bsp_reset_vector_address_setting(void);

void Default_Handler(void);

/* Determine whether a software reset has occurred */
bool g_bsp_software_reset_occurred BSP_PLACE_IN_SECTION(".software_reset");

/* Determine whether it is the initial startup or the state after a software reset. */
#if (1 == _RZ_ORDINAL) || (!BSP_CFG_ESD_BOOT && !BSP_CFG_EMMC_BOOT)
bool g_bsp_first_operation = true;
#else
bool g_bsp_first_operation BSP_PLACE_IN_SECTION(".first_operation") = true;

#endif

/*******************************************************************************************************************//**
 * Default exception handler.
 **********************************************************************************************************************/
void Default_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

void SyncSp0_Handler(void);
void SerrSp0_Handler(void);
void SyncSpx_Handler(void);
void SerrSpx_Handler(void);
void SyncLowEl64_Handler(void);
void IrqLowEl64_Handler(void);
void FiqLowEl64_Handler(void);
void SerrorLowEl64_Handler(void);
void SyncLowEl32_Handler(void);
void IrqLowEl32_Handler(void);
void FiqLowEl32_Handler(void);
void SerrorLowEl32_Handler(void);

void __Vectors(void)                       BSP_PLACE_IN_SECTION(".intvec"); /* branch_to_SyncSp0_Handler */
void branch_to_IrqSp0_Handler(void)        BSP_PLACE_IN_SECTION(".intvec_0x080");
void branch_to_FiqSp0_Handler(void)        BSP_PLACE_IN_SECTION(".intvec_0x100");
void branch_to_SerrSp0_Handler(void)       BSP_PLACE_IN_SECTION(".intvec_0x180");
void branch_to_SyncSpx_Handler(void)       BSP_PLACE_IN_SECTION(".intvec_0x200");
void branch_to_IrqSpx_Handler(void)        BSP_PLACE_IN_SECTION(".intvec_0x280");
void branch_to_FiqSpx_Handler(void)        BSP_PLACE_IN_SECTION(".intvec_0x300");
void branch_to_SerrSpx_Handler(void)       BSP_PLACE_IN_SECTION(".intvec_0x380");
void branch_to_SyncLowEl64_Handler(void)   BSP_PLACE_IN_SECTION(".intvec_0x400");
void branch_to_IrqLowEl64_Handler(void)    BSP_PLACE_IN_SECTION(".intvec_0x480");
void branch_to_FiqLowEl64_Handler(void)    BSP_PLACE_IN_SECTION(".intvec_0x500");
void branch_to_SerrorLowEl64_Handler(void) BSP_PLACE_IN_SECTION(".intvec_0x580");
void branch_to_SyncLowEl32_Handler(void)   BSP_PLACE_IN_SECTION(".intvec_0x600");
void branch_to_IrqLowEl32_Handler(void)    BSP_PLACE_IN_SECTION(".intvec_0x680");
void branch_to_FiqLowEl32_Handler(void)    BSP_PLACE_IN_SECTION(".intvec_0x700");
void branch_to_SerrorLowEl32_Handler(void) BSP_PLACE_IN_SECTION(".intvec_0x780");

void Software_Reset_Handler(void);
void FIQ_Handler(void);
void IRQ_Handler(void);
void FIQ_ExecuteHandler(void);
void IRQ_ExecuteHandler(void);

/* Stacks */
BSP_DONT_REMOVE static uint8_t g_stack[BSP_CFG_STACK_AARCH64_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_AARCH64_STACK);

/* Heap */
#if (BSP_CFG_HEAP_BYTES > 0)

BSP_DONT_REMOVE static uint8_t g_heap[BSP_CFG_HEAP_BYTES] BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT)
BSP_PLACE_IN_SECTION(BSP_SECTION_HEAP);
#endif

#if defined(__GNUC__)
extern uint64_t __AArch64StackLimit;

#elif defined(__ICCARM__)
 #pragma section=BSP_SECTION_AARCH64_STACK

#endif

/*******************************************************************************************************************//**
 * Exception handlers
 *********************************************************************************************************************/

__WEAK void SyncSp0_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SerrSp0_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SyncSpx_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SerrSpx_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SyncLowEl64_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void IrqLowEl64_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void FiqLowEl64_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SerrorLowEl64_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SyncLowEl32_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void IrqLowEl32_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void FiqLowEl32_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

__WEAK void SerrorLowEl32_Handler (void)
{
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
}

/*******************************************************************************************************************//**
 * Vector table
 *********************************************************************************************************************/

BSP_ATTRIBUTE_STACKLESS void __Vectors (void) /* branch_to_SyncSp0_Handler */
{
    __asm volatile (
        "SyncSp0:                       \n"
        "    B SyncSp0_Handler          \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SerrSp0_Handler (void)
{
    __asm volatile (
        "SerrSp0:                       \n"
        "    WFI                        \n"
        "    B SerrSp0_Handler          \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_IrqSp0_Handler (void)
{
    __asm volatile (
        "IrqSp0:                        \n"
        "    B IRQ_Handler              \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_FiqSp0_Handler (void)
{
    __asm volatile (
        "FiqSp0:                        \n"
        "    B FIQ_Handler              \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SyncSpx_Handler (void)
{
    __asm volatile (
        "SyncSpx:                       \n"
        "    B SyncSpx_Handler          \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SerrSpx_Handler (void)
{
    __asm volatile (
        "SerrSpx:                       \n"
        "    WFI                        \n"
        "    B SerrSpx_Handler          \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_IrqSpx_Handler (void)
{
    __asm volatile (
        "IrqSpx:                        \n"
        "    B IRQ_Handler              \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_FiqSpx_Handler (void)
{
    __asm volatile (
        "FiqSpx:                        \n"
        "    B FIQ_Handler              \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SyncLowEl64_Handler (void)
{
    __asm volatile (
        "SyncLowEl64:                   \n"
        "    WFI                        \n"
        "    B SyncLowEl64_Handler      \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_IrqLowEl64_Handler (void)
{
    __asm volatile (
        "IrqLowEl64:                    \n"
        "    WFI                        \n"
        "    B IrqLowEl64_Handler       \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_FiqLowEl64_Handler (void)
{
    __asm volatile (
        "FiqLowEl64:                    \n"
        "    WFI                        \n"
        "    B FiqLowEl64_Handler       \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SerrorLowEl64_Handler (void)
{
    __asm volatile (
        "SerrorLowEl64:                 \n"
        "    WFI                        \n"
        "    B SerrorLowEl64_Handler    \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SyncLowEl32_Handler (void)
{
    __asm volatile (
        "SyncLowEl32:                   \n"
        "    WFI                        \n"
        "    B SyncLowEl32_Handler      \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_IrqLowEl32_Handler (void)
{
    __asm volatile (
        "IrqLowEl32:                    \n"
        "    WFI                        \n"
        "    B IrqLowEl32_Handler       \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_FiqLowEl32_Handler (void)
{
    __asm volatile (
        "FiqLowEl32:                    \n"
        "    WFI                        \n"
        "    B FiqLowEl32_Handler       \n"
        ::: "memory");
}

BSP_ATTRIBUTE_STACKLESS void branch_to_SerrorLowEl32_Handler (void)
{
    __asm volatile (
        "SerrorLowEl32:                 \n"
        "    WFI                        \n"
        "    B SerrorLowEl32_Handler    \n"
        ::: "memory");
}

/*******************************************************************************************************************//**
 * After boot processing, LSI starts executing here.
 **********************************************************************************************************************/
BSP_ATTRIBUTE_STACKLESS void system_init (void)
{
    /* Call R_BSP_WarmStart_StackLess. Return here when processing is complete. */
    __asm volatile (
        "BLR  %0        \n"
        ::"r" (&R_BSP_WarmStart_StackLess) : "memory");

    /* g_bsp_software_reset_occurred = false */
    __asm volatile (
        "MOV  x0, %0    \n"
        "MOV  w1, #0    \n"
        "STRB  w1, [x0] \n"
        ::"r" (&g_bsp_software_reset_occurred) : "memory");

    /* g_bsp_first_operation = true */
    __asm volatile (
        "MOV  x0, %0    \n"
        "MOV  w1, #1    \n"
        "STRB  w1, [x0] \n"
        ::"r" (&g_bsp_first_operation) : "memory");

    __asm volatile (
        "b bsp_register_initialization          \n"
        ::: "memory");
}

/*******************************************************************************************************************//**
 * Initialize each register.
 **********************************************************************************************************************/
BSP_ATTRIBUTE_STACKLESS void bsp_register_initialization (void)
{
    /* Set Vector Base Address Register (VBAR) to point to initializer routine */
    __asm volatile (
        "LDR  x0, =__Vectors                    \n"
        "MSR  VBAR_EL3, x0                      \n"
        "MSR  VBAR_EL2, x0                      \n"
        "MSR  VBAR_EL1, x0                      \n"
        ::: "memory");

    /* Top of level system control init at each EL level
     *  Stop the following systems
     *  MMU, cache, and some memory control system, Tag check fault, pointer authentication */
    __asm volatile (
        "MOV  x0, #0                            \n"
        "MSR  SCTLR_EL3, x0                     \n"
        "MSR  SCTLR_EL2, x0                     \n"
        "MSR  SCTLR_EL1, x0                     \n"
        ::: "memory");

    /* Setting up Stack Area (EL3) */
    __asm volatile (
        "MOV  x1, %0 \n"
        "MOV  sp, x1 \n"
        ::"r" (BSP_STACK_LIMIT) : "memory");

    /* Stop trapping to EL3 or EL2 for low EL level tracing,
     *  activity monitoring, SVE, and access to SIMD and floating point features */
    __asm volatile (
        "MOV  x0, #0                            \n"
        "MSR  CPTR_EL3, x0                      \n"
        "MSR  CPTR_EL2, x0                      \n"
        ::: "memory");

    /* Secure configuration */
    __asm volatile (
        "MSR  SCR_EL3, xzr                      \n"
        "ISB                                    \n"
        "MOV  w1, #0                            \n"
        "ORR  w1, w1, %[scr_el3_bit_st]         \n"
        "ORR  w1, w1, %[scr_el3_bit_rw]         \n"
        "ORR  w1, w1, %[scr_el3_bit_ea]         \n"
        "ORR  w1, w1, %[scr_el3_bit_fiq]        \n"
        "ORR  w1, w1, %[scr_el3_bit_irq]        \n"
        "MSR  SCR_EL3, x1                       \n"
        "ISB                                    \n"
        ::[scr_el3_bit_st] "i" (SCR_EL3_BIT_ST),
        [scr_el3_bit_rw] "i" (SCR_EL3_BIT_RW),
        [scr_el3_bit_ea] "i" (SCR_EL3_BIT_EA),
        [scr_el3_bit_fiq] "i" (SCR_EL3_BIT_FIQ),
        [scr_el3_bit_irq] "i" (SCR_EL3_BIT_IRQ) : "memory");

    /* Set EL1 to execute with Aarch64 */
    __asm volatile (
        "MOV  x2, %[hcr_el2_bit_rw]             \n"
        "MSR  HCR_EL2, x2                       \n"
        ::[hcr_el2_bit_rw] "i" (HCR_EL2_BIT_RW) : "memory");

    /* Copy the multiprocessor ID information to the virtual multiprocessor ID register */
    __asm volatile (
        "MRS  x0, MPIDR_EL1                     \n"
        "MSR  VMPIDR_EL2, x0                    \n"
        ::: "memory");

    /* Copy processing element information to the virtual processor ID register */
    __asm volatile (
        "MRS  x0, MIDR_EL1                      \n"
        "MSR  VPIDR_EL2, x0                     \n"
        ::: "memory");

    /* Set 0 to Virtual Translation Table Address */
    __asm volatile (
        "MSR  VTTBR_EL2, xzr                    \n"
        ::: "memory");

    /* Set system counter frequency */
    __asm volatile (
        "MOV  x0, %0                            \n"
        "MSR  CNTFRQ_EL0, x0                    \n"
        ::"r" (BSP_GLOBAL_SYSTEM_COUNTER_CLOCK_HZ) : "memory");

    /* TLB maintenance, Invalidate Data and Instruction TLBs */
    __asm volatile (
        "TLBI ALLE3                             \n" /* Cortex-A55 I-TLB and D-TLB invalidation (TLBIALL) */
        ::: "memory");

    /* Invalidate instruction cache, also flushes BTAC */
    __asm volatile (
        "IC IALLUIS                             \n" /* ICIALLUIS - Instruction Cache Invalidate All to PoU */
        ::: "memory");

    __asm volatile (
        "b bsp_reset_vector_address_setting     \n"
        ::: "memory");
}

void bsp_reset_vector_address_setting (void)
{
#if BSP_CFG_SEMAPHORE_ENABLE

    /* Initialize semaphores required for synchronization and exclusive control between CPUs. */
    bsp_semaphore_init();
#endif

    bsp_regiser_protect_semaphore_take(BSP_REG_PROTECT_PRCR_SYSTEM);

    R_RWP_S->PRCRS = (uint16_t) ((R_RWP_S->PRCRS | BSP_REG_PROTECT_PRCR_KEY) | BSP_REG_PROTECT_PRCR_SYSTEM);

    R_CA55->RVBA[BSP_CFG_CORE_CA55].L = (uint32_t) ((uintptr_t) &Software_Reset_Handler);

    R_RWP_S->PRCRS = ((R_RWP_S->PRCRS | BSP_REG_PROTECT_PRCR_KEY) & (uint16_t) (~BSP_REG_PROTECT_PRCR_SYSTEM));

    BSP_SEMAPHORE_INTERNAL_CPU_RELEASE_FOR_PROTECTION;

    BSP_SYSTEMINIT_B_INSTRUCTION
}

/*******************************************************************************************************************//**
 * Software Reset handler Function.
 *********************************************************************************************************************/
BSP_ATTRIBUTE_STACKLESS void Software_Reset_Handler (void)
{
    /* Processing equivalent to R_BSP_CacheInvalidateAll */
    __asm volatile (
        "DSB       SY                                       \n"
        "IC        IALLU                                    \n"
        "DMB       SY                                       \n"
        "MRS       x2, CLIDR_EL1                            \n"
        "UBFX      x0, x2, #24, #3                          \n"
        "AND       x3, x0, #0x7                             \n"
        "CBZ       x3, cache_invalidation_end               \n"
        "MOVZ      x4, #0x0                                 \n"
        "B         cache_invalidation_per_level             \n"

        "cache_invalidation_next_way:                       \n"
        "SUB       x8, x8, #0x1, LSL #0                     \n"

        "cache_invalidation_per_way:                        \n"
        "UXTB      w9, w0                                   \n"
        "LSL       x9, x8, x9                               \n"
        "ORR       x9, x9, x5, LSL #0                       \n"
        "UXTB      w10, w6                                  \n"
        "LSL       x10, x7, x10                             \n"
        "ORR       x9, x9, x10, LSL #0                      \n"
        "DC        ISW, x9                                  \n"
        "CBNZ      x8, cache_invalidation_next_way          \n"
        "CBNZ      x7, cache_invalidation_next_set          \n"

        "cache_invalidation_next_level:                     \n"
        "ADD       x4, x4, #0x1                             \n"

        "cache_invalidation_per_level:                      \n"
        "CMP       x4, x3, LSL #0                           \n"
        "B.CS      cache_invalidation_per_level_end         \n"
        "MOV       x0, #0x3                                 \n"
        "MUL       x0, x4, x0                               \n"
        "UXTB      w0, w0                                   \n"
        "LSR       x0, x2, x0                               \n"
        "AND       x0, x0, #0x7                             \n"
        "CMP       x0, #0x2, LSL #0                         \n"
        "B.CC      cache_invalidation_next_level            \n"
        "LSL       x5, x4, #1                               \n"
        "MOV       x0, x5                                   \n"
        "MSR       CSSELR_EL1, x0                           \n"
        "DSB       SY                                       \n"
        "MRS       x0, CCSIDR_EL1                           \n"
        "AND       x1, x0, #0x7                             \n"
        "ADD       x6, x1, #0x4                             \n"
        "UBFX      x1, x0, #3, #10                          \n"
        "AND       x1, x1, #0x3ff                           \n"
        "UBFX      x7, x0, #13, #15                         \n"
        "AND       x7, x7, #0x7fff                          \n"
        "CLZ       w0, w1                                   \n"
        "UBFX      x0, x0, #0, #32                          \n"
        "CMP       x0, #0x20, LSL #0                        \n"
        "B.NE      cache_invalidation_per_set               \n"
        "SUB       x0, x0, #0x1, LSL #0                     \n"
        "B         cache_invalidation_per_set               \n"

        "cache_invalidation_next_set:                       \n"
        "SUB       x7, x7, #0x1, LSL #0                     \n"

        "cache_invalidation_per_set:                        \n"
        "MOV       x8, x1                                   \n"
        "B         cache_invalidation_per_way               \n"

        "cache_invalidation_per_level_end:                  \n"
        "DSB       SY                                       \n"
        "ISB       SY                                       \n"
        "cache_invalidation_end:                            \n"
        ::: "memory");

    /* g_bsp_software_reset_occurred = true */
    __asm volatile (
        "MOV  x0, %0                                        \n"
        "MOV  w1, #1                                        \n"
        "STRB  w1, [x0]                                     \n"
        ::"r" (&g_bsp_software_reset_occurred) : "memory");

    __asm volatile (
        "b bsp_register_initialization                      \n"
        ::: "memory");
}

/*******************************************************************************************************************//**
 * FIQ handler Function.
 *********************************************************************************************************************/
__WEAK void FIQ_Handler (void)
{
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
        "MRS  x3, SPSR_EL3                      \n"
        "MRS  x2, ELR_EL3                       \n"
        "STP  x2, x3, [sp, #-0x10]!             \n"

        "BL   FIQ_ExecuteHandler                \n"

        /* Restore volatile registers. */
        "LDP  x4, x5, [sp], #0x10               \n" /* SPSR and ELR. */

        "MSR  SPSR_EL3, x5                      \n"
        "MSR  ELR_EL3, x4                       \n"
        "DSB  SY                                \n"
        "ISB  SY                                \n"

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

        "ERET                                   \n"
        ::: "memory");
}

/*******************************************************************************************************************//**
 * IRQ handler Function.
 *********************************************************************************************************************/
__WEAK void IRQ_Handler (void)
{
    __asm volatile (
        "MSR  SPSEL, #0                         \n"
        "STP  x0, x1, [sp, #-0x10]!             \n"
        "STP  x2, x3, [sp, #-0x10]!             \n"
        "STP  x4, x5, [sp, #-0x10]!             \n"
        "STP  x6, x7, [sp, #-0x10]!             \n"
        "STP  x8, x9, [sp, #-0x10]!             \n"
        "STP  x10, x11, [sp, #-0x10]!           \n"
        "STP  x12, x13, [sp, #-0x10]!           \n"
        "STP  x14, x15, [sp, #-0x10]!           \n"
        "STP  x16, x17, [sp, #-0x10]!           \n"
        "STP  x18, x19, [sp, #-0x10]!           \n"
        "STP  x29, x30, [sp, #-0x10]!           \n"
        "BL   IRQ_ExecuteHandler                \n"
        "LDP  x29, x30, [sp], #0x10             \n"
        "LDP  x18, x19, [sp], #0x10             \n"
        "LDP  x16, x17, [sp], #0x10             \n"
        "LDP  x14, x15, [sp], #0x10             \n"
        "LDP  x12, x13, [sp], #0x10             \n"
        "LDP  x10, x11, [sp], #0x10             \n"
        "LDP  x8, x9, [sp], #0x10               \n"
        "LDP  x6, x7, [sp], #0x10               \n"
        "LDP  x4, x5, [sp], #0x10               \n"
        "LDP  x2, x3, [sp], #0x10               \n"
        "LDP  x0, x1, [sp], #0x10               \n"
        "ERET                                   \n"
        ::: "memory");
}

/*******************************************************************************************************************//**
 * IRQ handler Function.
 * This function calls the interrupt function registered in the vector table.
 *********************************************************************************************************************/
void IRQ_ExecuteHandler (void)
{
    uint32_t       int_id;
    fsp_vector_t * p_vector;
    IRQn_Type      irq;

    int_id = R_BSP_GICC_Get_IntIdGrp1();

    irq = (IRQn_Type) (int_id - BSP_CORTEX_VECTOR_TABLE_ENTRIES);

#if VECTOR_DATA_IRQ_COUNT > 0
    if (BSP_CORTEX_VECTOR_TABLE_ENTRIES <= int_id)
    {
        p_vector = &g_vector_table[irq];
    }
    else
#endif
    {
        p_vector = &g_sgi_ppi_vector_table[int_id];
    }

    if (p_vector)
    {
        g_current_interrupt_num[g_current_interrupt_pointer++] = irq;
        __DMB();

        (*p_vector)();
    }

    R_BSP_GICC_SetEoiGrp1(irq);
}

/*******************************************************************************************************************//**
 * FIQ handler Function.
 * This function calls the interrupt function registered in the vector table.
 *********************************************************************************************************************/
void FIQ_ExecuteHandler (void)
{
    uint32_t  int_id[2];
    uint32_t  aliased = 0;
    uint32_t  target_int_id;
    IRQn_Type irq;

    int_id[0]     = R_BSP_GICC_Get_IntIdGrp0();
    target_int_id = int_id[0];

    if ((R_BSP_GIC_INTID_1020 <= int_id[0]) && (int_id[0] <= R_BSP_GIC_INTID_1023))
    {
        int_id[1]     = R_BSP_GICC_Get_IntIdGrp1();
        aliased       = 1;
        target_int_id = int_id[1];

        FSP_ASSERT_NOT_RETURN_VALUE((R_BSP_GIC_INTID_1020 > int_id[1]) || (int_id[1] > R_BSP_GIC_INTID_1023));
    }

    irq = (IRQn_Type) (target_int_id - BSP_CORTEX_VECTOR_TABLE_ENTRIES);

    g_current_interrupt_num[g_current_interrupt_pointer++] = irq;
    __DMB();

    /* Enable nested interrupts */
    BSP_INTERRUPT_ENABLE;

#if VECTOR_DATA_IRQ_COUNT > 0
    if (BSP_CORTEX_VECTOR_TABLE_ENTRIES <= target_int_id)
    {
        g_vector_table[irq]();
    }
    else
#endif
    {
        g_sgi_ppi_vector_table[target_int_id]();
    }

    /* Disable nested interrupts */
    BSP_INTERRUPT_DISABLE;

    g_current_interrupt_pointer--;

    if (0 == aliased)
    {
        R_BSP_GICC_SetEoiGrp0(irq);
    }
    else
    {
        R_BSP_GICC_SetEoiGrp1(irq);
    }
}
