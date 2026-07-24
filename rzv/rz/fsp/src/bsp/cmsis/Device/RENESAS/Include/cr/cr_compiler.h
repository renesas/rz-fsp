/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*
 * @file     cr_compiler.h
 * @brief    CMSIS HeaderFile for Cortex-R
 */

/*
 * Copyright (c) 2009-2020 Arm Limited. All rights reserved.
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates. All Rights Reserved.
 *
 * This file is based on the "\CMSIS\Core\Include\cmsis_gcc.h"
 *
 * Changes:
 *    - Add CP15 descriptions by
 * Renesas Electronics Corporation on 2021-08-31
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @addtogroup Renesas
 * @{
 */

/** @addtogroup R9A09G057H
 * @{
 */

#ifndef CR_COMPILER_H
#define CR_COMPILER_H

#ifndef __I
 #ifdef __cplusplus
  #define   __I     volatile           /*!< Defines 'read only' permissions */
 #else
  #define   __I     volatile const     /*!< Defines 'read only' permissions */
 #endif
#endif
#ifndef __O
 #define    __O     volatile           /*!< Defines 'write only' permissions */
#endif
#ifndef __IO
 #define    __IO    volatile           /*!< Defines 'read / write' permissions */
#endif

/* ========================================  Start of section using anonymous unions  ======================================== */

/* CMSIS compiler specific defines */
#ifndef   __ASM
 #define __ASM                   __asm
#endif
#ifndef   __INLINE
 #define __INLINE                inline
#endif
#ifndef   __STATIC_INLINE
 #define __STATIC_INLINE         static inline
#endif
#ifndef   __STATIC_FORCEINLINE
 #define __STATIC_FORCEINLINE    __attribute__((always_inline)) static inline
#endif
#ifndef   __NO_RETURN
 #define __NO_RETURN             __attribute__((__noreturn__))
#endif
#ifndef   __USED
 #define __USED                  __attribute__((used))
#endif
#ifndef   __WEAK
 #define __WEAK                  __attribute__((weak))
#endif
#ifndef   __PACKED
 #define __PACKED                __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_STRUCT
 #define __PACKED_STRUCT         struct __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_UNION
 #define __PACKED_UNION          union __attribute__((packed, aligned(1)))
#endif
#ifndef   __UNALIGNED_UINT32           /* deprecated */
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wpacked"
 #pragma GCC diagnostic ignored "-Wattributes"
struct __attribute__((packed)) T_UINT32
{
    uint32_t v;
};
 #pragma GCC diagnostic pop
 #define __UNALIGNED_UINT32(x)    (((struct T_UINT32 *) (x))->v)
#endif
#ifndef   __UNALIGNED_UINT16_WRITE
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wpacked"
 #pragma GCC diagnostic ignored "-Wattributes"
__PACKED_STRUCT T_UINT16_WRITE {
    uint16_t v;
};
 #pragma GCC diagnostic pop
 #define __UNALIGNED_UINT16_WRITE(addr, val)    (void) ((((struct T_UINT16_WRITE *) (void *) (addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT16_READ
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wpacked"
 #pragma GCC diagnostic ignored "-Wattributes"
__PACKED_STRUCT T_UINT16_READ {
    uint16_t v;
};
 #pragma GCC diagnostic pop
 #define __UNALIGNED_UINT16_READ(addr)    (((const struct T_UINT16_READ *) (const void *) (addr))->v)
#endif
#ifndef   __UNALIGNED_UINT32_WRITE
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wpacked"
 #pragma GCC diagnostic ignored "-Wattributes"
__PACKED_STRUCT T_UINT32_WRITE {
    uint32_t v;
};
 #pragma GCC diagnostic pop
 #define __UNALIGNED_UINT32_WRITE(addr, val)    (void) ((((struct T_UINT32_WRITE *) (void *) (addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT32_READ
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wpacked"
 #pragma GCC diagnostic ignored "-Wattributes"
__PACKED_STRUCT T_UINT32_READ {
    uint32_t v;
};
 #pragma GCC diagnostic pop
 #define __UNALIGNED_UINT32_READ(addr)    (((const struct T_UINT32_READ *) (const void *) (addr))->v)
#endif
#ifndef   __ALIGNED
 #define __ALIGNED(x)                     __attribute__((aligned(x)))
#endif
#ifndef   __RESTRICT
 #define __RESTRICT    __restrict
#endif
#ifndef   __COMPILER_BARRIER
 #define __COMPILER_BARRIER()    __ASM volatile ("" ::: "memory")
#endif

#if defined(__GNUC__)

/*******************************************************************************************************************//**
 * Enable IRQ Interrupts.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void __enable_irq (void)
{
    __ASM volatile ("cpsie i" : : : "memory");
}

/*******************************************************************************************************************//**
 * Disable IRQ Interrupts.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void __disable_irq (void)
{
    __ASM volatile ("cpsid i" : : : "memory");
}

#endif

/*******************************************************************************************************************//**
 * Instruction Synchronization Barrier.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void __ISB (void)
{
    __ASM volatile ("isb 0xF" ::: "memory");
}

/*******************************************************************************************************************//**
 * Instruction Synchronization Barrier.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void __DSB (void)
{
    __ASM volatile ("dsb 0xF" ::: "memory");
}

/*******************************************************************************************************************//**
 * Data Memory Barrier.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE void __DMB (void)
{
    __ASM volatile ("dmb 0xF" ::: "memory");
}

/*******************************************************************************************************************//**
 * Get MPIDR.
 * This function returns the value of the Multiprocessor Affinity Register.
 *
 * @return  Multiprocessor Affinity Register value.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint32_t __get_MPIDR (void)
{
    uint32_t result;
    __ASM volatile ("MRC p15, #0, %0, c0, c0, #5" : "=r" (result) : : "memory");

    return result;
}

/*******************************************************************************************************************//**
 * Built in CLZ instruction.
 *
 * @param[in] value          value to count the leading zeros.
 *
 * @return  number of leading zeros in value.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint8_t __CLZ (uint32_t value)
{
    if (value == 0U)
    {
        return 32U;
    }

    return __builtin_clz(value);
}

/*******************************************************************************************************************//**
 * Reverse bit order of value.
 *
 * @param[in] value          value to reverse.
 *
 * @return  reversed value.
 **********************************************************************************************************************/
__STATIC_FORCEINLINE uint32_t __RBIT (uint32_t value)
{
    uint32_t result;

    uint32_t s = (4U /*sizeof(v)*/ * 8U) - 1U; /* extra shift needed at end */

    result = value;                            /* r will be reversed bits of v; first get LSB of v */
    for (value >>= 1U; value != 0U; value >>= 1U)
    {
        result <<= 1U;
        result  |= value & 1U;
        s--;
    }

    result <<= s;                      /* shift when v's highest bits are zero */

    return result;
}

/* Wait For Interrupt */
#define __WFI()          __ASM volatile ("wfi" ::: "memory")

/* Breakpoint. */
#define __BKPT(value)    __ASM volatile ("bkpt "#value)

#endif                                 /* CR_COMPILER_H */

/** @} */ /* End of group R9A09G057H */

/** @} */ /* End of group Renesas */
