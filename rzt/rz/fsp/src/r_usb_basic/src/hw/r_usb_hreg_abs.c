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

#define USB_VALUE_50           (50)
#define USB_VALUE_300          (300)
#define USB_VALUE_00FFH        (0x00FF)
#define USB_VALUE_000000FFH    (0x000000FF)

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
/******************************************************************************
 * Function Name   : usb_hstd_chk_clk
 * Description     : Checks SOF sending setting when USB Device is detached or suspended
 *               : , BCHG interrupt enable setting and clock stop processing
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 *               : uint16_t event    : device state
 * Return value    : none
 ******************************************************************************/
void usb_hstd_chk_clk (usb_utr_t * ptr, uint16_t event)
{
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(event);
}                                      /* End of function usb_hstd_chk_clk */

/******************************************************************************
 * End of function usb_hstd_chk_clk
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_detach_process
 * Description     : Handles the require processing when USB device is detached
 *               : (Data transfer forcibly termination processing to the connected USB Device,
 *               : the clock supply stop setting and the USB interrupt dissable setteing etc)
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 * Return value    : none
 ******************************************************************************/
void usb_hstd_detach_process (usb_utr_t * ptr)
{
    FSP_PARAMETER_NOT_USED(ptr);
}

/******************************************************************************
 * End of function usb_hstd_detach_process
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_attach_process
 * Description     : Interrupt disable setting when USB Device is attached and
 *               : handles the required interrupt disable setting etc when USB device
 *               : is attached.
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 * Return value    : none
 * Note            : Please change for your SYSTEM
 ******************************************************************************/
void usb_hstd_attach_process (usb_utr_t * ptr)
{
    FSP_PARAMETER_NOT_USED(ptr);
}

/******************************************************************************
 * End of function usb_hstd_attach_process
 ******************************************************************************/


/******************************************************************************
 * Function Name   : usb_hstd_bus_reset
 * Description     : Setting USB register when BUS Reset
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 * Return value    : none
 ******************************************************************************/
void usb_hstd_bus_reset (usb_utr_t * ptr)
{
    FSP_PARAMETER_NOT_USED(ptr);
}

/******************************************************************************
 * End of function usb_hstd_bus_reset
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_support_speed_check
 * Description     : Get USB-speed of the specified port.
 * Arguments       : usb_utr_t *ptr   : Pointer to usb_utr_t structure.
 * Return value    : uint16_t         : HSCONNECT : Hi-Speed
 *               :                  : FSCONNECT : Full-Speed
 *               :                  : LSCONNECT : Low-Speed
 *               :                  : NOCONNECT : not connect
 ******************************************************************************/
uint16_t usb_hstd_support_speed_check (usb_utr_t * ptr)
{
    uint16_t conn_inf = 0;
    FSP_PARAMETER_NOT_USED(ptr);
    return conn_inf;
}

/******************************************************************************
 * End of function usb_hstd_support_speed_check
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_forced_termination
 * Description     : Terminate data transmission and reception.
 * Arguments       : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 *               : uint16_t     pipe    : Pipe Number
 *               : uint16_t     status  : Transfer status type
 * Return value    : none
 * Note            : In the case of timeout status, it does not call back.
 ******************************************************************************/
void usb_hstd_forced_termination (usb_utr_t * ptr, uint16_t pipe, uint16_t status)
{
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(pipe);
    FSP_PARAMETER_NOT_USED(status);
}

/******************************************************************************
 * End of function usb_hstd_forced_termination
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_get_usb_ip_adr
 * Description     : Get base address of the selected USB channel's peripheral
 *               : registers.
 * Argument        : uint16_t ipnum  : USB_IP0 (0), or USB_IP1 (1).
 * Return          : usb_regadr_t    : A pointer to the USB_597IP register
 *               : structure USB_REGISTER containing all USB
 *               : channel's registers.
 ******************************************************************************/
usb_regadr_t usb_hstd_get_usb_ip_adr (uint16_t ipnum)
{
    usb_regadr_t ptr = 0;
    FSP_PARAMETER_NOT_USED(ipnum);
    ptr = (usb_regadr_t) R_USBHC;
    return ptr;
}

/******************************************************************************
 * End of function usb_hstd_get_usb_ip_adr
 ******************************************************************************/

#endif /* ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST) */

/******************************************************************************
 * End of file
 ******************************************************************************/
