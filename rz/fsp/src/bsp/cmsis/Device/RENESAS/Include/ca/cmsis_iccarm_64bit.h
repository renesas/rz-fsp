/**************************************************************************//**
 * @file     cmsis_iccarm.h
 * @brief    CMSIS compiler ICCARM (IAR Compiler for Arm) header file
 * @date     03. October 2024
 ******************************************************************************/

/*
 * Copyright [2020-2024] Renesas Electronics Corporation and/or its affiliates. All Rights Reserved.
 *
 * This file is based on the "CMSIS\Core_A\Include\cmsis_iccarm.h"
 *
 * Changes:
 *    - Changed to be related to Cortex-A55 64bit by
 * Renesas Electronics Corporation on 2024-06-17
 *    - Changed DMB, DSB, and ISB instructions to support IAR 64-bit C++.
 * Renesas Electronics Corporation on 2024-06-17
 *    - Changed DMB, DSB, and ISB instructions to support IAR 64-bit C.
 * Renesas Electronics Corporation on 2024-10-03
 */

// ------------------------------------------------------------------------------
//
// Copyright (c) 2017-2018 IAR Systems
// Copyright (c) 2018-2019 Arm Limited
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// ------------------------------------------------------------------------------

#ifndef __CMSIS_ICCARM_H__
#define __CMSIS_ICCARM_H__

#ifndef __ICCARM__
 #error This file should only be compiled by ICCARM
#endif

#pragma system_include

#define __IAR_FT        _Pragma("inline=forced") __intrinsic

#if (__VER__ >= 8000000)
 #define __ICCARM_V8    1
#else
 #define __ICCARM_V8    0
#endif

#pragma language=extended

#ifndef __ALIGNED
 #if __ICCARM_V8
  #define __ALIGNED(x)    __attribute__((aligned(x)))
 #elif (__VER__ >= 7080000)

/* Needs IAR language extensions */
  #define __ALIGNED(x)    __attribute__((aligned(x)))
 #else
  #warning No compiler specific solution for __ALIGNED.__ALIGNED is ignored.
  #define __ALIGNED(x)
 #endif
#endif

/* Define compiler macros for CPU architecture, used in CMSIS 5.
 */
#if __ARM_ARCH_7A__

/* Macro already defined */
#else
 #if defined(__ARM7A__)
  #define __ARM_ARCH_7A__    1
 #endif
#endif

#ifndef __ASM
 #define __ASM               __asm
#endif

#ifndef   __COMPILER_BARRIER
 #define __COMPILER_BARRIER()    __ASM volatile ("" ::: "memory")
#endif

#ifndef __INLINE
 #define __INLINE        inline
#endif

#ifndef   __NO_RETURN
 #if __ICCARM_V8
  #define __NO_RETURN    __attribute__((__noreturn__))
 #else
  #define __NO_RETURN    _Pragma("object_attribute=__noreturn")
 #endif
#endif

#ifndef   __PACKED

/* Needs IAR language extensions */
 #if __ICCARM_V8
  #define __PACKED    __attribute__((packed, aligned(1)))
 #else
  #define __PACKED    __packed
 #endif
#endif

#ifndef   __PACKED_STRUCT

/* Needs IAR language extensions */
 #if __ICCARM_V8
  #define __PACKED_STRUCT    struct __attribute__((packed, aligned(1)))
 #else
  #define __PACKED_STRUCT    __packed struct
 #endif
#endif

#ifndef   __PACKED_UNION

/* Needs IAR language extensions */
 #if __ICCARM_V8
  #define __PACKED_UNION    union __attribute__((packed, aligned(1)))
 #else
  #define __PACKED_UNION    __packed union
 #endif
#endif

#ifndef   __RESTRICT
 #if __ICCARM_V8
  #define __RESTRICT        __restrict
 #else

/* Needs IAR language extensions */
  #define __RESTRICT        restrict
 #endif
#endif

#ifndef   __STATIC_INLINE
 #define __STATIC_INLINE    static inline
#endif

#ifndef   __FORCEINLINE
 #define __FORCEINLINE      _Pragma("inline=forced")
#endif

#ifndef   __STATIC_FORCEINLINE
 #define __STATIC_FORCEINLINE    __FORCEINLINE __STATIC_INLINE
#endif

#ifndef   CMSIS_DEPRECATED
 #define CMSIS_DEPRECATED        __attribute__((deprecated))
#endif

#ifndef __UNALIGNED_UINT16_READ
 #pragma language=save
 #pragma language=extended
__IAR_FT uint16_t __iar_uint16_read (void const * ptr)
{
    return *(__packed uint16_t *) (ptr);
}

 #pragma language=restore
 #define __UNALIGNED_UINT16_READ(PTR)    __iar_uint16_read(PTR)
#endif

#ifndef __UNALIGNED_UINT16_WRITE
 #pragma language=save
 #pragma language=extended
__IAR_FT void __iar_uint16_write (void const * ptr, uint16_t val)
{
    *(__packed uint16_t *) (ptr) = val;;
}

 #pragma language=restore
 #define __UNALIGNED_UINT16_WRITE(PTR, VAL)    __iar_uint16_write(PTR, VAL)
#endif

#ifndef __UNALIGNED_UINT32_READ
 #pragma language=save
 #pragma language=extended
__IAR_FT uint32_t __iar_uint32_read (void const * ptr)
{
    return *(__packed uint32_t *) (ptr);
}

 #pragma language=restore
 #define __UNALIGNED_UINT32_READ(PTR)    __iar_uint32_read(PTR)
#endif

#ifndef __UNALIGNED_UINT32_WRITE
 #pragma language=save
 #pragma language=extended
__IAR_FT void __iar_uint32_write (void const * ptr, uint32_t val)
{
    *(__packed uint32_t *) (ptr) = val;;
}

 #pragma language=restore
 #define __UNALIGNED_UINT32_WRITE(PTR, VAL)    __iar_uint32_write(PTR, VAL)
#endif

#if 0
 #ifndef __UNALIGNED_UINT32            /* deprecated */
  #pragma language=save
  #pragma language=extended
__packed struct  __iar_u32
{
    uint32_t v;
};
  #pragma language=restore
  #define __UNALIGNED_UINT32(PTR)    (((struct __iar_u32 *) (PTR))->v)
 #endif
#endif

#ifndef   __USED
 #if __ICCARM_V8
  #define __USED    __attribute__((used))
 #else
  #define __USED    _Pragma("__root")
 #endif
#endif

#undef __WEAK                          /* undo the definition from DLib_Defaults.h */
#ifndef   __WEAK
 #if __ICCARM_V8
  #define __WEAK                          __attribute__((weak))
 #else
  #define __WEAK                          _Pragma("__weak")
 #endif
#endif

#ifndef __ICCARM_INTRINSICS_VERSION__
 #define __ICCARM_INTRINSICS_VERSION__    0
#endif

#if __ICCARM_INTRINSICS_VERSION__ == 2

 #if defined(__CLZ)
  #undef __CLZ
 #endif
 #if defined(__REVSH)
  #undef __REVSH
 #endif
 #if defined(__RBIT)
  #undef __RBIT
 #endif
 #if defined(__SSAT)
  #undef __SSAT
 #endif
 #if defined(__USAT)
  #undef __USAT
 #endif

 #include "iccarm_builtin.h"

 #define __enable_irq           __iar_builtin_enable_interrupt  // DEPRECATED
 #define __disable_irq          __iar_builtin_disable_interrupt // DEPRECATED
 #define __enable_fault_irq     __iar_builtin_enable_fiq        // DEPRECATED
 #define __disable_fault_irq    __iar_builtin_disable_fiq       // DEPRECATED
 #define __arm_rsr              __iar_builtin_rsr               // DEPRECATED
 #define __arm_wsr              __iar_builtin_wsr               // DEPRECATED

 #if __FPU_PRESENT
  #define __get_FPSCR()        (__arm_rsr("FPSCR"))
 #else
  #define __get_FPSCR()        (0)
 #endif

 #define __set_FPSCR(VALUE)    (__arm_wsr("FPSCR", VALUE))

 #define __get_CPSR()          (__arm_rsr("CPSR"))
 #define __get_mode()          (__get_CPSR() & 0x1FU)

 #define __set_CPSR(VALUE)     (__arm_wsr("CPSR", (VALUE)))
 #define __set_mode(VALUE)     (__arm_wsr("CPSR_c", (VALUE)))

 #define __get_FPEXC()         (__arm_rsr("FPEXC"))
 #define __set_FPEXC(VALUE)    (__arm_wsr("FPEXC", VALUE))

 #define __get_CP(cp, op1, RT, CRn, CRm, op2) \
    __ASM volatile ("MRS %0, S" # cp "_" # op1 "_C" # CRn "_C" # CRm "_" # op2:"=r" (RT) : : "memory")

 #define __set_CP(cp, op1, RT, CRn, CRm, op2) \
    __ASM volatile ("MSR S" # cp "_" # op1 "_C" # CRn "_C" # CRm "_" # op2 ", %0" : : "r" (RT) : "memory")

 #define __get_CP64(cp, op1, Rt, CRm) \
    __ASM volatile ("MRRC p" # cp ", " # op1 ", %Q0, %R0, c" # CRm:"=r" (Rt) : : "memory")

 #define __set_CP64(cp, op1, Rt, CRm) \
    __ASM volatile ("MCRR p" # cp ", " # op1 ", %Q0, %R0, c" # CRm::"r" (Rt) : "memory")

 #if (1 == BSP_LP64_SUPPORT)
  #include "cmsis_cp15_64bit.h"

 #else
  #include "cmsis_cp15.h"

 #endif

 #define __NOP()    __ASM volatile ("NOP")

__STATIC_FORCEINLINE uint8_t __CLZ (uint32_t value)
{
    uint8_t n = 0;

    if (value == 0)
    {
        return 32;
    }

    if (!(value & 0xffff0000))
    {
        n      += 16;
        value <<= 16;
    }

    if (!(value & 0xff000000))
    {
        n      += 8;
        value <<= 8;
    }

    if (!(value & 0xf0000000))
    {
        n      += 4;
        value <<= 4;
    }

    if (!(value & 0xc0000000))
    {
        n      += 2;
        value <<= 2;
    }

    if (!(value & 0x80000000))
    {
        n += 1;
    }

    return n;
}

 #define __CLREX    __iar_builtin_CLREX // DEPRECATED

__STATIC_FORCEINLINE void __DMB (void)
{
    __ASM volatile ("DMB SY");
}

__STATIC_FORCEINLINE void __DSB (void)
{
    __ASM volatile ("DSB SY");
}

__STATIC_FORCEINLINE void __ISB (void)
{
    __ASM volatile ("ISB SY");
}

 #define __LDREXB    __iar_builtin_LDREXB // DEPRECATED
 #define __LDREXH    __iar_builtin_LDREXH // DEPRECATED
 #define __LDREXW    __iar_builtin_LDREX  // DEPRECATED

__STATIC_FORCEINLINE uint32_t __RBIT (uint32_t value)
{
    uint32_t result = value;
    result = (result >> 16) | (result << 16);
    result = ((result & 0xff00ff00) >> 8) | ((result & 0x00ff00ff) << 8);
    result = ((result & 0xf0f0f0f0) >> 4) | ((result & 0x0f0f0f0f) << 4);
    result = ((result & 0xcccccccc) >> 2) | ((result & 0x33333333) << 2);
    result = ((result & 0xaaaaaaaa) >> 1) | ((result & 0x55555555) << 1);

    return result;
}

__STATIC_FORCEINLINE uint32_t __REV (uint32_t value)
{
    uint32_t result;

    result = ((value & 0x000000FF) << 24) |
             ((value & 0x0000FF00) << 8) |
             ((value & 0x00FF0000) >> 8) |
             ((value & 0xFF000000) >> 24);

    return result;
}

__STATIC_FORCEINLINE uint32_t __REV16 (uint32_t value)
{
    uint32_t result = 0;

    result  = (value & 0x00FF00FF) << 8;
    result |= (value & 0xFF00FF00) >> 8;

    return result;
}

__IAR_FT int16_t __REVSH (int16_t val) // DEPRECATED
{
    return (int16_t) __iar_builtin_REVSH(val);
}

 #define __ROR           __iar_builtin_ROR    // DEPRECATED
 #define __RRX           __iar_builtin_RRX    // DEPRECATED

 #define __SEV           __iar_builtin_SEV    // DEPRECATED

 #define __SSAT          __iar_builtin_SSAT   // DEPRECATED

 #define __STREXB        __iar_builtin_STREXB // DEPRECATED
 #define __STREXH        __iar_builtin_STREXH // DEPRECATED
 #define __STREXW        __iar_builtin_STREX  // DEPRECATED

 #define __USAT          __iar_builtin_USAT   // DEPRECATED

 #define __WFI()    __ASM volatile ("wfi" ::: "memory")
 #define __WFE()    __ASM volatile ("wfe" ::: "memory")

 #define __SADD8         __iar_builtin_SADD8   // DEPRECATED
 #define __QADD8         __iar_builtin_QADD8   // DEPRECATED
 #define __SHADD8        __iar_builtin_SHADD8  // DEPRECATED
 #define __UADD8         __iar_builtin_UADD8   // DEPRECATED
 #define __UQADD8        __iar_builtin_UQADD8  // DEPRECATED
 #define __UHADD8        __iar_builtin_UHADD8  // DEPRECATED
 #define __SSUB8         __iar_builtin_SSUB8   // DEPRECATED
 #define __QSUB8         __iar_builtin_QSUB8   // DEPRECATED
 #define __SHSUB8        __iar_builtin_SHSUB8  // DEPRECATED
 #define __USUB8         __iar_builtin_USUB8   // DEPRECATED
 #define __UQSUB8        __iar_builtin_UQSUB8  // DEPRECATED
 #define __UHSUB8        __iar_builtin_UHSUB8  // DEPRECATED
 #define __SADD16        __iar_builtin_SADD16  // DEPRECATED
 #define __QADD16        __iar_builtin_QADD16  // DEPRECATED
 #define __SHADD16       __iar_builtin_SHADD16 // DEPRECATED
 #define __UADD16        __iar_builtin_UADD16  // DEPRECATED
 #define __UQADD16       __iar_builtin_UQADD16 // DEPRECATED
 #define __UHADD16       __iar_builtin_UHADD16 // DEPRECATED
 #define __SSUB16        __iar_builtin_SSUB16  // DEPRECATED
 #define __QSUB16        __iar_builtin_QSUB16  // DEPRECATED
 #define __SHSUB16       __iar_builtin_SHSUB16 // DEPRECATED
 #define __USUB16        __iar_builtin_USUB16  // DEPRECATED
 #define __UQSUB16       __iar_builtin_UQSUB16 // DEPRECATED
 #define __UHSUB16       __iar_builtin_UHSUB16 // DEPRECATED
 #define __SASX          __iar_builtin_SASX    // DEPRECATED
 #define __QASX          __iar_builtin_QASX    // DEPRECATED
 #define __SHASX         __iar_builtin_SHASX   // DEPRECATED
 #define __UASX          __iar_builtin_UASX    // DEPRECATED
 #define __UQASX         __iar_builtin_UQASX   // DEPRECATED
 #define __UHASX         __iar_builtin_UHASX   // DEPRECATED
 #define __SSAX          __iar_builtin_SSAX    // DEPRECATED
 #define __QSAX          __iar_builtin_QSAX    // DEPRECATED
 #define __SHSAX         __iar_builtin_SHSAX   // DEPRECATED
 #define __USAX          __iar_builtin_USAX    // DEPRECATED
 #define __UQSAX         __iar_builtin_UQSAX   // DEPRECATED
 #define __UHSAX         __iar_builtin_UHSAX   // DEPRECATED
 #define __USAD8         __iar_builtin_USAD8   // DEPRECATED
 #define __USADA8        __iar_builtin_USADA8  // DEPRECATED
 #define __SSAT16        __iar_builtin_SSAT16  // DEPRECATED
 #define __USAT16        __iar_builtin_USAT16  // DEPRECATED
 #define __UXTB16        __iar_builtin_UXTB16  // DEPRECATED
 #define __UXTAB16       __iar_builtin_UXTAB16 // DEPRECATED
 #define __SXTB16        __iar_builtin_SXTB16  // DEPRECATED
 #define __SXTAB16       __iar_builtin_SXTAB16 // DEPRECATED
 #define __SMUAD         __iar_builtin_SMUAD   // DEPRECATED
 #define __SMUADX        __iar_builtin_SMUADX  // DEPRECATED
 #define __SMMLA         __iar_builtin_SMMLA   // DEPRECATED
 #define __SMLAD         __iar_builtin_SMLAD   // DEPRECATED
 #define __SMLADX        __iar_builtin_SMLADX  // DEPRECATED
 #define __SMLALD        __iar_builtin_SMLALD  // DEPRECATED
 #define __SMLALDX       __iar_builtin_SMLALDX // DEPRECATED
 #define __SMUSD         __iar_builtin_SMUSD   // DEPRECATED
 #define __SMUSDX        __iar_builtin_SMUSDX  // DEPRECATED
 #define __SMLSD         __iar_builtin_SMLSD   // DEPRECATED
 #define __SMLSDX        __iar_builtin_SMLSDX  // DEPRECATED
 #define __SMLSLD        __iar_builtin_SMLSLD  // DEPRECATED
 #define __SMLSLDX       __iar_builtin_SMLSLDX // DEPRECATED
 #define __SEL           __iar_builtin_SEL     // DEPRECATED
 #define __QADD          __iar_builtin_QADD    // DEPRECATED
 #define __QSUB          __iar_builtin_QSUB    // DEPRECATED
 #define __PKHBT         __iar_builtin_PKHBT   // DEPRECATED
 #define __PKHTB         __iar_builtin_PKHTB   // DEPRECATED

#else                                          /* __ICCARM_INTRINSICS_VERSION__ == 2 */

 #if !__FPU_PRESENT
  #define __get_FPSCR    __cmsis_iar_get_FPSR_not_active
 #endif

 #ifdef __INTRINSICS_INCLUDED
  #error intrinsics.h is already included previously!
 #endif

 #include <intrinsics.h>

 #if !__FPU_PRESENT
  #define __get_FPSCR()    (0)
 #endif

 #pragma diag_suppress=Pe940
 #pragma diag_suppress=Pe177

 #define __enable_irq           __enable_interrupt
 #define __disable_irq          __disable_interrupt
 #define __enable_fault_irq     __enable_fiq
 #define __disable_fault_irq    __disable_fiq
 #define __NOP                  __no_operation

 #define __get_xPSR             __get_PSR

__IAR_FT void __set_mode (uint32_t mode)
{
    __ASM volatile ("MSR  cpsr_c, %0" : : "r" (mode) : "memory");
}

__IAR_FT uint32_t __LDREXW (uint32_t volatile * ptr)
{
    return __LDREX((unsigned long *) ptr);
}

__IAR_FT uint32_t __STREXW (uint32_t value, uint32_t volatile * ptr)
{
    return __STREX(value, (unsigned long *) ptr);
}

__IAR_FT uint32_t __RRX (uint32_t value)
{
    uint32_t result;
    __ASM("RRX      %0, %1" : "=r" (result) : "r" (value) : "cc");

    return result;
}

__IAR_FT uint32_t __ROR (uint32_t op1, uint32_t op2)
{
    return (op1 >> op2) | (op1 << ((sizeof(op1) * 8) - op2));
}

__IAR_FT uint32_t __get_FPEXC (void)
{
 #if (__FPU_PRESENT == 1)
    uint32_t result;
    __ASM volatile ("VMRS %0, fpexc" : "=r" (result) : : "memory");

    return result;
 #else
    return 0;
 #endif
}

__IAR_FT void __set_FPEXC (uint32_t fpexc)
{
 #if (__FPU_PRESENT == 1)
    __ASM volatile ("VMSR fpexc, %0" : : "r" (fpexc) : "memory");
 #endif
}

 #define __get_CP(cp, op1, Rt, CRn, CRm, op2) \
    __ASM volatile ("MRC p" # cp ", " # op1 ", %0, c" # CRn ", c" # CRm ", " # op2:"=r" (Rt) : : "memory")
 #define __set_CP(cp, op1, Rt, CRn, CRm, op2) \
    __ASM volatile ("MCR p" # cp ", " # op1 ", %0, c" # CRn ", c" # CRm ", " # op2::"r" (Rt) : "memory")
 #define __get_CP64(cp, op1, Rt, CRm) \
    __ASM volatile ("MRRC p" # cp ", " # op1 ", %Q0, %R0, c" # CRm:"=r" (Rt) : : "memory")
 #define __set_CP64(cp, op1, Rt, CRm) \
    __ASM volatile ("MCRR p" # cp ", " # op1 ", %Q0, %R0, c" # CRm::"r" (Rt) : "memory")

 #if (1 == BSP_LP64_SUPPORT)
  #include "cmsis_cp15_64bit.h"

 #else
  #include "cmsis_cp15.h"

 #endif

#endif                                 /* __ICCARM_INTRINSICS_VERSION__ == 2 */

#define __BKPT(value)    __asm volatile ("BRK     %0" : : "i" (value))

__IAR_FT uint32_t __get_SP_usr (void)
{
    uint32_t cpsr;
    uint32_t result;
    __ASM volatile (
        "MRS     %0, cpsr   \n"
        "CPS     #0x1F      \n"        // no effect in USR mode
        "MOV     %1, sp     \n"
        "MSR     cpsr_c, %2 \n"        // no effect in USR mode
        "ISB" :  "=r" (cpsr), "=r" (result) : "r" (cpsr) : "memory"
        );

    return result;
}

__IAR_FT void __set_SP_usr (uint32_t topOfProcStack)
{
    uint32_t cpsr;
    __ASM volatile (
        "MRS     %0, cpsr   \n"
        "CPS     #0x1F      \n"        // no effect in USR mode
        "MOV     sp, %1     \n"
        "MSR     cpsr_c, %2 \n"        // no effect in USR mode
        "ISB" : "=r" (cpsr) : "r" (topOfProcStack), "r" (cpsr) : "memory"
        );
}

#define __get_mode()    (__get_CPSR() & 0x1FU)

/* Alternativ core deduction for older ICCARM's */
#if !defined(__ARM_ARCH_6M__) && !defined(__ARM_ARCH_7M__) && !defined(__ARM_ARCH_7EM__) && \
    !defined(__ARM_ARCH_8M_BASE__) && !defined(__ARM_ARCH_8M_MAIN__)
 #if defined(__ARM6M__) && (__CORE__ == __ARM6M__)
  #define __ARM_ARCH_6M__         1
 #elif defined(__ARM7M__) && (__CORE__ == __ARM7M__)
  #define __ARM_ARCH_7M__         1
 #elif defined(__ARM7EM__) && (__CORE__ == __ARM7EM__)
  #define __ARM_ARCH_7EM__        1
 #elif defined(__ARM8M_BASELINE__) && (__CORE == __ARM8M_BASELINE__)
  #define __ARM_ARCH_8M_BASE__    1
 #elif defined(__ARM8M_MAINLINE__) && (__CORE == __ARM8M_MAINLINE__)
  #define __ARM_ARCH_8M_MAIN__    1
 #elif defined(__ARM8EM_MAINLINE__) && (__CORE == __ARM8EM_MAINLINE__)
  #define __ARM_ARCH_8M_MAIN__    1
 #elif defined(__ARM8R__) && (__CORE__ == __ARM8R__)
  #define __ARM_ARCH_8R__         1
 #elif defined(__ARM8A__) && (__CORE__ == __ARM8A__)
  #define __ARM_ARCH_8A__         1
 #else
  #error "Unknown target."
 #endif
#endif

#undef __IAR_FT
#undef __ICCARM_V8

#pragma diag_default=Pe940
#pragma diag_default=Pe177

#endif                                 /* __CMSIS_ICCARM_H__ */
