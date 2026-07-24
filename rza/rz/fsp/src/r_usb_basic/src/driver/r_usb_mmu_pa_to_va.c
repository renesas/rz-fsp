/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_MMU_va_to_pa.c
 * Description  : USB Host MSC application code
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "stdint.h"
#include "hal_data.h"
#include "r_mmu.h"

/***********************************************************************************************************************
 * Constant macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

uint64_t r_usb_pa_to_va(uint64_t paddr);
uint64_t r_usb_va_to_pa(uint64_t vaddr);
uint64_t r_usb_readtbl(uint64_t address);

/******************************************************************************
 * Function Name: r_usb_pa_to_va
 * Description  : Convert physical address to virtual address
 * Arguments    : uint32_t   paddr  ; I : physical address to be convert
 * Return Value : virtual address
 ******************************************************************************/
uint64_t r_usb_pa_to_va (uint64_t paddr)
{
    uint64_t vaddr;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    R_MMU_PAtoVA(&g_mmu_ctrl, paddr, &vaddr);
#else                                  /* #if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT) */
    vaddr = paddr;
#endif /* #if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT) */

    return vaddr;
}                                      /* End of function r_usb_pa_to_va() */

/******************************************************************************
 * End of function usb_serial_input
 ******************************************************************************/

/******************************************************************************
 * Function Name: r_usb_va_to_pa
 * Description  : Convert virtual address to physical address
 * Arguments    : uint32_t   vaddress  ; I : virtual address to be convert
 *              : uint32_t * paddress  ; O : physical address
 * Return Value : MMU_SUCCESS         : successful
 *                MMU_ERR_TRANSLATION : translation error
 ******************************************************************************/
uint64_t r_usb_va_to_pa (uint64_t vaddr)
{
    uint64_t paddr;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    R_MMU_VAtoPA(&g_mmu_ctrl, vaddr, &paddr);
#else                                  /* #if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT) */
    paddr = vaddr;
#endif /* #if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT) */

    return paddr;
}

/******************************************************************************
 * End of function R_MMU_VAtoPA
 ******************************************************************************/

/***********************************************************************************************************************
 * End  Of File
 ***********************************************************************************************************************/
