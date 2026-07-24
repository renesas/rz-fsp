/**************************************************************************//**
 * @file     cmsis_cp15.h
 * @brief    CMSIS compiler specific macros, functions, instructions
 * @date     17. June 2024
 ******************************************************************************/

/*
 * Copyright [2020-2024] Renesas Electronics Corporation and/or its affiliates. All Rights Reserved.
 *
 * This file is based on the "CMSIS\Core_A\Include\cmsis_cp15.h"
 *
 * Changes:
 *    - Changed to be related to Cortex-A55 64bit by
 *    - Functions are sorted according to the Arm technical reference.
 * Renesas Electronics Corporation on 2024-06-17
 */

/*
 * Copyright (c) 2009-2017 ARM Limited. All rights reserved.
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

#if   defined(__ICCARM__)
 #pragma system_include         /* treat file as system include file for MISRA check */
#elif defined(__clang__)
 #pragma clang system_header   /* treat file as system include file */
#endif

#ifndef __CMSIS_CP15_H
 #define __CMSIS_CP15_H

/** \brief  Get CTR_EL0
 *  \return               Cache Type Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CTR (void)
{
    uint64_t result;
    __get_CP(3, 3, result, 0, 0, 1);

    return result;
}

/** \brief  Get MPIDR_EL1
 *
 *  This function returns the value of the Multiprocessor Affinity Register.
 *
 *  \return               Multiprocessor Affinity Register value
 */
__STATIC_FORCEINLINE uint64_t __get_MPIDR (void)
{
    uint64_t result;
    __get_CP(3, 0, result, 0, 0, 5);

    return result;
}

/** \brief  Get CCSIDR_EL1
 *  \return CCSIDR Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CCSIDR (void)
{
    uint64_t result;
    __get_CP(3, 1, result, 0, 0, 0);

    return result;
}

/** \brief  Get CLIDR_EL1
 *  \return CLIDR Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CLIDR (void)
{
    uint64_t result;
    __get_CP(3, 1, result, 0, 0, 1);

    return result;
}

/** \brief  Get CSSELR_EL1
 *  \return CSSELR Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CSSELR (void)
{
    uint64_t result;
    __get_CP(3, 2, result, 0, 0, 0);

    return result;
}

/** \brief  Set CSSELR_EL1
 */
__STATIC_FORCEINLINE void __set_CSSELR (uint64_t value)
{
    __set_CP(3, 2, value, 0, 0, 0);
}

/** \brief  Get SCTLR_EL3
 *
 *  This function assigns the given value to the System Control Register.
 *
 *  \return               System Control Register value
 */
__STATIC_FORCEINLINE uint64_t __get_SCTLR (void)
{
    uint64_t result;
    __get_CP(3, 6, result, 1, 0, 0);

    return result;
}

/** \brief  Set SCTLR_EL3
 *  \param [in]    value  System Control Register value to set
 */
__STATIC_FORCEINLINE void __set_SCTLR (uint64_t value)
{
    __set_CP(3, 6, value, 1, 0, 0);
}

/** \brief  Get ACTLR_EL3
 *  \return               Auxiliary Control register value
 */
__STATIC_FORCEINLINE uint64_t __get_ACTLR (void)
{
    uint64_t result;
    __get_CP(3, 6, result, 1, 0, 1);

    return result;
}

/** \brief  Set ACTLR_EL3
 *  \param [in]    value  Auxiliary Control value to set
 */
__STATIC_FORCEINLINE void __set_ACTLR (uint64_t value)
{
    __set_CP(3, 6, value, 1, 0, 1);
}

/** \brief  Get CPACR_EL1
 *  \return               Coprocessor Access Control register value
 */
__STATIC_FORCEINLINE uint64_t __get_CPACR (void)
{
    uint64_t result;
    __get_CP(3, 0, result, 1, 0, 2);

    return result;
}

/** \brief  Set CPACR_EL1
 *  \param [in]    value  Coprocessor Access Control value to set
 */
__STATIC_FORCEINLINE void __set_CPACR (uint64_t value)
{
    __set_CP(3, 0, value, 1, 0, 2);
}

/** \brief  Get TTBR0_EL3
 *
 *  This function returns the value of the Translation Table Base Register 0.
 *
 *  \return               Translation Table Base Register 0 value
 */
__STATIC_FORCEINLINE uint64_t __get_TTBR0 (void)
{
    uint64_t result;
    __get_CP(3, 6, result, 2, 0, 0);

    return result;
}

/** \brief  Set TTBR0_EL3
 *  \param [in]    value  Translation Table Base value to set
 */
__STATIC_FORCEINLINE void __set_TTBR0 (uint64_t value)
{
    __set_CP(3, 6, value, 2, 0, 0);
}

/** \brief  Get TCR_EL3
 *
 *  This function returns the value of the Translation Control Register.
 *
 *  \return               Translation Control Register value
 */
__STATIC_FORCEINLINE uint64_t __get_TCR (void)
{
    uint64_t result;
    __get_CP(3, 6, result, 2, 0, 2);

    return result;
}

/** \brief  Set TCR_EL3
 *  \param [in]    value  Translation Control value to set
 */
__STATIC_FORCEINLINE void __set_TCR (uint64_t value)
{
    __set_CP(3, 6, value, 2, 0, 2);
}

/** \brief  Get DACR32_EL2
 *
 *  This function returns the value of the Domain Access Control Register.
 *
 *  \return               Domain Access Control Register value
 */
__STATIC_FORCEINLINE uint64_t __get_DACR (void)
{
    uint64_t result;
    __get_CP(3, 4, result, 3, 0, 0);

    return result;
}

/** \brief  Set DACR32_EL2
 *
 *  This function assigns the given value to the Domain Access Control Register.
 *
 *  \param [in]    value   Domain Access Control Register value to set
 */
__STATIC_FORCEINLINE void __set_DACR (uint64_t value)
{
    __set_CP(3, 4, value, 3, 0, 0);
}

/** \brief  Get ICC_PMR_EL1
 */
__STATIC_FORCEINLINE uint64_t __get_ICC_PMR (void)
{
    uint64_t result;
    __get_CP(3, 0, result, 4, 6, 0);

    return result;
}

/** \brief  Set ICC_PMR_EL1
 */
__STATIC_FORCEINLINE void __set_ICC_PMR (uint64_t value)
{
    __set_CP(3, 0, value, 4, 6, 0);
}

/** \brief  Get IFSR32_EL2
 *  \return               Instruction Fault Status Register value
 */
__STATIC_FORCEINLINE uint64_t __get_IFSR (void)
{
    uint64_t result;
    __get_CP(3, 4, result, 5, 0, 1);

    return result;
}

/** \brief  Set IFSR32_EL2
 *  \param [in]    value  Instruction Fault Status value to set
 */
__STATIC_FORCEINLINE void __set_IFSR (uint64_t value)
{
    __set_CP(3, 4, value, 5, 0, 1);
}

/** \brief  Get MAIR_EL3
 *
 *  This function returns the value of the Memory Attribute Indirection Register.
 *
 *  \return               Memory Attribute Indirection Register value
 */
__STATIC_FORCEINLINE uint64_t __get_MAIR (void)
{
    uint64_t result;
    __get_CP(3, 6, result, 10, 2, 0);

    return result;
}

/** \brief  Set MAIR_EL3
 *  \param [in]    value  Memory Attribute Indirection value to set
 */
__STATIC_FORCEINLINE void __set_MAIR (uint64_t value)
{
    __set_CP(3, 6, value, 10, 2, 0);
}

/** \brief  Get ISR_EL1
 *  \return               Interrupt Status Register value
 */
__STATIC_FORCEINLINE uint64_t __get_ISR (void)
{
    uint64_t result;
    __get_CP(3, 0, result, 12, 1, 0);

    return result;
}

/** \brief  Get VBAR_EL3
 *
 *  This function returns the value of the Vector Base Address Register.
 *
 *  \return               Vector Base Address Register
 */
__STATIC_FORCEINLINE uint64_t __get_VBAR (void)
{
    uint64_t result;
    __get_CP(3, 6, result, 12, 0, 0);

    return result;
}

/** \brief  Set VBAR_EL3
 *
 *  This function assigns the given value to the Vector Base Address Register.
 *
 *  \param [in]    value  Vector Base Address Register value to set
 */
__STATIC_FORCEINLINE void __set_VBAR (uint64_t value)
{
    __set_CP(3, 6, value, 12, 0, 0);
}

/** \brief  Set CNTFRQ_EL0
 *
 * This function assigns the given value to PL1 Physical Timer Counter Frequency Register (CNTFRQ).
 *
 * \param [in]    value  CNTFRQ Register value to set
 */
__STATIC_FORCEINLINE void __set_CNTFRQ (uint64_t value)
{
    __set_CP(3, 3, value, 14, 0, 0);
}

/** \brief  Get CNTFRQ_EL0
 *
 *  This function returns the value of the PL1 Physical Timer Counter Frequency Register (CNTFRQ).
 *
 *  \return               CNTFRQ Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CNTFRQ (void)
{
    uint64_t result;
    __get_CP(3, 3, result, 14, 0, 0);

    return result;
}

/** \brief  Get CNTPCT_EL0
 *
 *  This function returns the value of the 64 bits PL1 Physical Count Register (CNTPCT).
 *
 *  \return               CNTPCT Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CNTPCT (void)
{
    uint64_t result;
    __get_CP(3, 3, result, 14, 0, 1);

    return result;
}

/** \brief  Set CNTP_TVAL_EL0
 *
 * This function assigns the given value to PL1 Physical Timer Value Register (CNTP_TVAL).
 *
 * \param [in]    value  CNTP_TVAL Register value to set
 */
__STATIC_FORCEINLINE void __set_CNTP_TVAL (uint64_t value)
{
    __set_CP(3, 3, value, 14, 2, 0);
}

/** \brief  Get CNTP_TVAL_EL0
 *
 *  This function returns the value of the PL1 Physical Timer Value Register (CNTP_TVAL).
 *
 *  \return               CNTP_TVAL Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CNTP_TVAL (void)
{
    uint64_t result;
    __get_CP(3, 3, result, 14, 2, 0);

    return result;
}

/** \brief  Set CNTP_CTL_EL0
 *
 * This function assigns the given value to PL1 Physical Timer Control Register (CNTP_CTL).
 *
 * \param [in]    value  CNTP_CTL Register value to set
 */
__STATIC_FORCEINLINE void __set_CNTP_CTL (uint64_t value)
{
    __set_CP(3, 3, value, 14, 2, 1);
}

/** \brief  Get CNTP_CTL_EL0
 *  \return               CNTP_CTL Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CNTP_CTL (void)
{
    uint64_t result;
    __get_CP(3, 3, result, 14, 2, 1);

    return result;
}

/** \brief  Set CNTP_CVAL_EL0
 *
 * This function assigns the given value to 64bits PL1 Physical Timer CompareValue Register (CNTP_CVAL).
 *
 * \param [in]    value  CNTP_CVAL Register value to set
 */
__STATIC_FORCEINLINE void __set_CNTP_CVAL (uint64_t value)
{
    __set_CP(3, 3, value, 14, 2, 2);
}

/** \brief  Get CNTP_CVAL_EL0
 *
 *  This function returns the value of the 64 bits PL1 Physical Timer CompareValue Register (CNTP_CVAL).
 *
 *  \return               CNTP_CVAL Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CNTP_CVAL (void)
{
    uint64_t result;
    __get_CP(3, 3, result, 14, 2, 2);

    return result;
}

/** \brief  Set CLUSTERPWRCTLR
 *
 *  This function controls power features of the cluster.
 *
 *  \param [in]    value  CLUSTERPWRCTLR Register value to set
 */
__STATIC_FORCEINLINE void __set_CLUSTERPWRCTLR (uint64_t value)
{
    __set_CP(3, 0, value, 15, 3, 5);
}

/** \brief  Get CLUSTERPWRCTLR
 *  \return               CLUSTERPWRCTLR Register value
 */
__STATIC_FORCEINLINE uint64_t __get_CLUSTERPWRCTLR (void)
{
    uint64_t result;
    __get_CP(3, 0, result, 15, 3, 5);

    return result;
}

/** \brief  Set TLBIALLE3
 *
 * TLB Invalidate All
 */
__STATIC_FORCEINLINE void __set_TLBIALL (uint64_t value)
{
    __asm volatile ("TLBI ALLE3, %0" ::"r" (value) : "memory");
}

/** \brief  Set ICIALLU
 *
 * Instruction Cache Invalidate All
 */
__STATIC_FORCEINLINE void __set_ICIALLU (uint64_t value)
{
    FSP_PARAMETER_NOT_USED(value);
    __asm volatile ("IC IALLU" ::: "memory");
}

/** \brief  Set DCISW
 */
__STATIC_FORCEINLINE void __set_DCISW (uint64_t dcisw)
{
    __asm volatile ("DC ISW, %0" ::"r" (dcisw) : "memory");
}

/** \brief  Set DCCSW
 */
__STATIC_FORCEINLINE void __set_DCCSW (uint64_t dccsw)
{
    __asm volatile ("DC CSW, %0" ::"r" (dccsw) : "memory");
}

/** \brief  Set DCCISW
 */
__STATIC_FORCEINLINE void __set_DCCISW (uint64_t dccisw)
{
    __asm volatile ("DC CISW, %0" ::"r" (dccisw) : "memory");
}

/** \brief  Set DCCVAC
 */
__STATIC_FORCEINLINE void __set_DCCVAC (uint64_t dccvac)
{
    __asm volatile ("DC CVAC, %0" ::"r" (dccvac) : "memory");
}

/** \brief  Set DCIVAC
 */
__STATIC_FORCEINLINE void __set_DCIVAC (uint64_t dcivac)
{
    __asm volatile ("DC IVAC, %0" ::"r" (dcivac) : "memory");
}

/** \brief  Set DCCIVAC
 */
__STATIC_FORCEINLINE void __set_DCCIVAC (uint64_t dccivac)
{
    __asm volatile ("DC CIVAC, %0" ::"r" (dccivac) : "memory");
}

/** \brief  Set ICIVAU
 */
__STATIC_FORCEINLINE void __set_ICIVAU (uint64_t icivau)
{
    __asm volatile ("IC IVAU, %0" ::"r" (icivau) : "memory");
}

/**
 * \brief   Set RMR_EL3
 * \details A write to the register RMR_EL3 at EL3 can request a Warm reset.
 * \param [in]    rmr_el3 Reset Management value to set
 */
__STATIC_FORCEINLINE void __set_RMR_EL3 (uint8_t rmr_el3)
{
    __asm volatile ("MSR  RMR_EL3, %0" : : "r" (rmr_el3) : "memory");
}

/**
 * \brief   Get RMR_EL3
 * \details A write to the register RMR_EL3 at EL3 can request a Warm reset.
 * \param [in]    rmr_el3 Reset Management value to set
 */
__STATIC_FORCEINLINE uint8_t __get_RMR_EL3 (void)
{
    uint8_t result;
    __asm volatile ("MRS %0, RMR_EL3" : "=r" (result));

    return result;
}

#endif
