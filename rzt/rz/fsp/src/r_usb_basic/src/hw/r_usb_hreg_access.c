/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/

#include <r_usb_basic.h>
#include <r_usb_basic_api.h>

#include "../driver/inc/r_usb_typedef.h"
#include "../driver/inc/r_usb_extern.h"
#include "inc/r_usb_bitdefine.h"
#include "inc/r_usb_reg_access.h"

#define USB_VALUE_50       (50)
#define USB_VALUE_100      (100)
#define USB_VALUE_450      (450)
#define USB_VALUE_500      (500)
#define USB_VALUE_0F00H    (0x0f00)

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)

/******************************************************************************
 * Function Name   : hw_usb_hmodule_init
 * Description     : USB module initialization for USB Host mode
 * Arguments       : usb_utr_t *ptr   : Pointer to usb_utr_t structure
 * Return value    : none
 ******************************************************************************/
void hw_usb_hmodule_init (usb_ctrl_t * p_api_ctrl)
{
    volatile unsigned long dummy;
    volatile uint8_t       dummy_buf = 0;

    FSP_PARAMETER_NOT_USED(dummy_buf);
    FSP_PARAMETER_NOT_USED(p_api_ctrl);

    for (dummy = 0; dummy < (USB_VALUE_450 * USB_VALUE_500); dummy++)
    {
        ;                              /* Wait 500us */
    }

    USB00->COMMCTRL_b.PERI = 0;        /* Operation mode setting (0 : Host, 1 : Peri) */

    USB00->USBCTR &= ~0x00000002U;     /* UTMI+PHY reset release */

    for (dummy = 0; dummy < (USB_VALUE_450 * USB_VALUE_100); dummy++)
    {
        ;                              /* Wait 100us */
    }
}

/******************************************************************************
 * End of function hw_usb_hmodule_init
 ******************************************************************************/
#endif /* ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */

/******************************************************************************
 * End of file
 ******************************************************************************/
