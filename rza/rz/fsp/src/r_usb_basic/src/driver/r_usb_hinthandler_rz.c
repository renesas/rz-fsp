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
 #define USB_WAKEON_INT    0x00000010  /* Interrupt */
 #define USB_UCOM_INT      0x00000008  /* Interrupt */
 #define USB_USBH_INTB     0x00000004  /* EHCI interrupt */
 #define USB_USBH_INTA     0x00000002  /* OHCI interrupt */
 #define USB_AHB_INT       0x00000001  /* Bus master error interrupt */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

 #if (BSP_CFG_RTOS == 1)
extern void _ux_hcd_ohci_interrupt_handler(void);
extern void _ux_hcd_ehci_interrupt_handler(void);

 #else
extern void usb_hstd_hci_interrupt_handler(usb_utr_t * ptr);

 #endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
void R_USB_HstdIntInit(void);
void usb_hstd_int_enable(void);
void usb_hstd_int_disable(void);
void R_USB_isr(IRQn_Type const irq);
void R_USB_isr_port1(IRQn_Type const irq);

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

void R_USB_isr (IRQn_Type const irq)
{
    FSP_PARAMETER_NOT_USED(irq);

    uint32_t    int_state;
    usb_utr_t * ptr;

    /* Initial pointer */
    ptr     = &g_usb_cstd_int_msg[0][g_usb_cstd_int_msg_cnt[0]];
    ptr->ip = 0;

 #if defined(BSP_MCU_GROUP_RZA_USB)
    int_state = USB00->INT_STATUS;
 #else
    int_state = USB00->INTSTATUS;
 #endif
    if (USB_AHB_INT == (int_state & USB_AHB_INT))
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        USB00->INT_STATUS_b.AHB_INT = 1;
 #else
        USB00->INTSTATUS |= USB_AHB_INT;
 #endif
    }
    else if (USB_USBH_INTA == (int_state & USB_USBH_INTA)) /* OHCI interrupt */
    {
 #if (BSP_CFG_RTOS == 1)
        _ux_hcd_ohci_interrupt_handler();
 #else
        usb_hstd_hci_interrupt_handler(ptr);
 #endif
    }
    else if (USB_USBH_INTB == (int_state & USB_USBH_INTB)) /* EHCI interrupt */
    {
 #if (BSP_CFG_RTOS == 1)
        _ux_hcd_ehci_interrupt_handler();
 #else
        usb_hstd_hci_interrupt_handler(ptr);
 #endif
    }
    else if (USB_UCOM_INT == (int_state & USB_UCOM_INT))
    {
    }
    else if (USB_WAKEON_INT == (int_state & USB_WAKEON_INT))
    {
 #if defined(BSP_MCU_GROUP_RZA_USB)
        USB00->INT_STATUS_b.WAKEON_INT = 1;
 #else
        USB00->INTSTATUS |= USB_WAKEON_INT;
 #endif
    }
    else
    {
    }
}                                      /* End of function R_USB_isr() */

void R_USB_isr_port1 (IRQn_Type const irq)
{
    FSP_PARAMETER_NOT_USED(irq);

 #if USB_NUM_USBIP == 2
    uint32_t    int_state;
    usb_utr_t * ptr;

    /* Initial pointer */
    ptr     = &g_usb_cstd_int_msg[1][g_usb_cstd_int_msg_cnt[1]];
    ptr->ip = 1;

  #if defined(BSP_MCU_GROUP_RZA_USB)
    int_state = USB10->INT_STATUS;
  #else
    int_state = USB10->INTSTATUS;
  #endif
    if (USB_AHB_INT == (int_state & USB_AHB_INT))
    {
  #if defined(BSP_MCU_GROUP_RZA_USB)
        USB10->INT_STATUS_b.AHB_INT = 1;
  #else
        USB10->INTSTATUS |= USB_AHB_INT;
  #endif
    }
    else if (USB_USBH_INTA == (int_state & USB_USBH_INTA)) /* OHCI interrupt */
    {
  #if (BSP_CFG_RTOS == 1)
        _ux_hcd_ohci_interrupt_handler();
  #else
        usb_hstd_hci_interrupt_handler(ptr);
  #endif
    }
    else if (USB_USBH_INTB == (int_state & USB_USBH_INTB)) /* EHCI interrupt */
    {
  #if (BSP_CFG_RTOS == 1)
        _ux_hcd_ehci_interrupt_handler();
  #else
        usb_hstd_hci_interrupt_handler(ptr);
  #endif
    }
    else if (USB_UCOM_INT == (int_state & USB_UCOM_INT))
    {
    }
    else if (USB_WAKEON_INT == (int_state & USB_WAKEON_INT))
    {
  #if defined(BSP_MCU_GROUP_RZA_USB)
        USB10->INT_STATUS_b.WAKEON_INT = 1;
  #else
        USB10->INTSTATUS |= USB_WAKEON_INT;
  #endif
    }
    else
    {
    }
 #endif                                /* #if USB_NUM_USBIP == 2 */
}                                      /* End of function R_USB_isr() */

#endif                                 /* USB_IP_EHCI_OHCI == 1 */

/***********************************************************************************************************************
 * End Of File
 ***********************************************************************************************************************/
