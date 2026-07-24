/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hinthandler.c
 * Version      : 1.0
 * Description  : This module solves all the world's problems
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 15.01.2007 1.00     First Release
 **********************************************************************************************************************/


/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "r_usb_basic_if.h"
#include "r_usb_extern.h"

#if   USB_IP_EHCI_OHCI == 1
/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define USB00_WAKEON_INT    0x00000010 /* Interrupt */
 #define USB00_UCOM_INT      0x00000008 /* Interrupt */
 #define USB00_USBH_INTB     0x00000004 /* EHCI interrupt */
 #define USB00_USBH_INTA     0x00000002 /* OHCI interrupt */
 #define USB00_AHB_INT       0x00000001 /* Bus master error interrupt */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern void usb_hstd_hci_interrupt_handler(void);
extern void R_USB_isr(void);

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void R_USB_HstdIntInit(void);
void usb_hstd_int_enable(void);
void usb_hstd_int_disable(void);

/***********************************************************************************************************************
 * Function Name: usb_hstd_int_enable
 * Description  : USB host interrupt enable
 * Arguments    : none
 * Return Value : none
 **********************************************************************************************************************/
void usb_hstd_int_enable (void)
{
    usb_cpu_int_enable();
}                                      /* End of function usb_hstd_int_enable() */

/***********************************************************************************************************************
 * Function Name: usb_hstd_int_disable
 * Description  : USB host interrupt disable
 * Arguments    : none
 * Return Value : none
 **********************************************************************************************************************/
void usb_hstd_int_disable (void)
{
    usb_cpu_int_disable();
}                                      /* End of function usb_hstd_int_disable() */

/***********************************************************************************************************************
 * Function Name: R_USB_isr
 * Description  : Interrupt service routine of USB host
 * Arguments    : none
 * Return Value : none
 **********************************************************************************************************************/

void R_USB_isr (void)
{
    uint32_t int_state;

    USB_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    int_state = USB00->INTSTATUS;
    if (USB00_AHB_INT == (int_state & USB00_AHB_INT))
    {
        USB00->INTSTATUS |= USB00_AHB_INT;
        FSP_ERROR_LOG(FSP_ERR_USB_FAILED);
    }
    else if ((USB00_USBH_INTA == (int_state & USB00_USBH_INTA)) || (USB00_USBH_INTB == (int_state & USB00_USBH_INTB))) /* EHCI or OHCI interrupt */
    {
        usb_hstd_hci_interrupt_handler();
    }
    else if (USB00_UCOM_INT == (int_state & USB00_UCOM_INT))
    {
    }
    else if (USB00_WAKEON_INT == (int_state & USB00_WAKEON_INT))
    {
        USB00->INTSTATUS |= USB00_WAKEON_INT;
    }
    else
    {
    }
    USB_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}                                      /* End of function R_USB_isr() */

#endif                                 /* USB_IP_EHCI_OHCI == 1 */

/***********************************************************************************************************************
 * End Of File
 ***********************************************************************************************************************/
