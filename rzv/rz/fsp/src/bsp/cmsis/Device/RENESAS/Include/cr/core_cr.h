/***********************************************************************************************************************
 * Copyright [2020-2022] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/*
 * @file     core_cr.h
 * @brief    Core setting HeaderFile for Cortex-R
 */

/** @addtogroup Renesas
 * @{
 */

/** @addtogroup R9A09G057H
 * @{
 */

#ifndef CORE_CR_H
#define CORE_CR_H

#if defined(__GNUC__)
 #if defined(__VFP_FP__) && !defined(__SOFTFP__)
  #if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U)
   #define __FPU_USED    1U
   #define __FPU_D32     1U
  #else
   #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
   #define __FPU_USED    0U
  #endif
 #else
  #define __FPU_USED     0U
 #endif

#elif defined(__ICCARM__)
 #if defined __ARMVFP__
  #if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1U)
   #define __FPU_USED    1U
   #ifndef __ARMVFP_D16__
    #define __FPU_D32    1U
   #endif
  #else
   #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
   #define __FPU_USED    0U
  #endif
 #else
  #define __FPU_USED     0U
 #endif
#endif

#endif                                 /* CORE_CR_H */

/** @} */ /* End of group R9A09G057H */

/** @} */ /* End of group Renesas */
