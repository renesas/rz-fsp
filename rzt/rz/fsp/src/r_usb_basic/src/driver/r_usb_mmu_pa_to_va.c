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
#include "bsp_api.h"
 #if defined(BSP_CFG_CORE_CA55)

/***********************************************************************************************************************
 * Constant macro definitions
 ***********************************************************************************************************************/
#define USB_MMU_VA_BOTTOM (0x10200000)
#define USB_MMU_VA_TOP    (0x103FFFFF)
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
    uint64_t vaddr = 0;

#if defined(BSP_CFG_CORE_CA55)

    /* Converts a physical address to a virtual address.  */
    if (FSP_SUCCESS != R_BSP_MmuPatoVa(paddr, &vaddr, BSP_MMU_CONVERSION_NON_CACHE))
    {
        /* On error, returns the physical address without conversion. */
        vaddr = paddr;
    }
#else /* #if defined(BSP_CFG_CORE_CA55) */
    vaddr = paddr;
#endif /* #if defined(BSP_CFG_CORE_CA55) */

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
    uint64_t paddr = 0;

#if defined(BSP_CFG_CORE_CA55)

    /* Converts a virtual address to a physical address.  */
    if (FSP_SUCCESS != R_BSP_MmuVatoPa(vaddr, &paddr))
    {
        /* On error, returns the virtual address without conversion. */
        paddr = vaddr;
    }
#else /* #if defined(BSP_CFG_CORE_CA55) */
    paddr = vaddr;
#endif /* #if defined(BSP_CFG_CORE_CA55) */

    return paddr;
}

/******************************************************************************
 * End of function R_MMU_VAtoPA
 ******************************************************************************/
#endif /* defined(BSP_CFG_CORE_CA55) */
/***********************************************************************************************************************
 * End  Of File
 ***********************************************************************************************************************/
