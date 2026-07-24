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

#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)

 #define USB_VAL_BWAIT3F    (0x003f)

/******************************************************************************
 * Function Name   : hw_usb_pset_dprpu
 * Description     : Set DPRPU-bit SYSCFG0 register.
 *               : (Enable D+Line pullup when PeripheralController function is selected)
 * Arguments       : usb_utr_t *ptr  : USB internal structure. Selects USB channel.
 * Return value    : none
 ******************************************************************************/
void hw_usb_pset_dprpu (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->SYSCFG0 |= USB_DPRPU;
    }
    else
    {
        USB_M1->SYSCFG0 |= USB_DPRPU;
    }
}

/******************************************************************************
 * End of function hw_usb_pset_dprpu
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pclear_dprpu
 * Description     : Clear DPRPU-bit of the SYSCFG0 register.
 *               : (Disable D+Line pullup when PeripheralController function is
 *               : selected.)
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 * Return value    : none
 ******************************************************************************/
void hw_usb_pclear_dprpu (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->SYSCFG0 = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DPRPU));
    }
    else
    {
        USB_M1->SYSCFG0 = (uint16_t) (USB_M1->SYSCFG0 & (~USB_DPRPU));
    }
}

/******************************************************************************
 * End of function hw_usb_pclear_dprpu
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pset_wkup
 * Description     : Set WKUP-bit DVSTCTR register.
 *               : (Output Remote wakeup signal when PeripheralController function is selected)
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 * Return value    : none
 ******************************************************************************/
void hw_usb_pset_wkup (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->DVSTCTR0 |= USB_WKUP;
    }
    else
    {
        USB_M1->DVSTCTR0 |= USB_WKUP;
    }
}

/******************************************************************************
 * End of function hw_usb_pset_wkup
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pset_enb_rsme
 * Description     : Enable interrupt from RESUME
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void hw_usb_pset_enb_rsme (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->INTENB0 |= USB_RSME;
    }
    else
    {
        USB_M1->INTENB0 |= USB_RSME;
    }
}

/******************************************************************************
 * End of function hw_usb_pset_enb_rsme
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pclear_enb_rsme
 * Description     : Disable interrupt from RESUME
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void hw_usb_pclear_enb_rsme (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->INTENB0 = (uint16_t) (USB_M0->INTENB0 & (~USB_RSME));
    }
    else
    {
        USB_M1->INTENB0 = (uint16_t) (USB_M1->INTENB0 & (~USB_RSME));
    }
}

/******************************************************************************
 * End of function hw_usb_pclear_enb_rsme
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pclear_sts_resm
 * Description     : Clear interrupt status of RESUME.
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void hw_usb_pclear_sts_resm (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->INTSTS0 = (uint16_t) ~USB_RESM;
    }
    else
    {
        USB_M1->INTSTS0 = (uint16_t) ~USB_RESM;
    }
}

/******************************************************************************
 * End of function hw_usb_pclear_sts_resm
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pclear_sts_valid
 * Description     : Clear the Setup Packet Reception interrupt flag.
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void hw_usb_pclear_sts_valid (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->INTSTS0 = (uint16_t) ~USB_VALID;
    }
    else
    {
        USB_M1->INTSTS0 = (uint16_t) ~USB_VALID;
    }
}

/******************************************************************************
 * End of function hw_usb_pclear_sts_valid
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pset_ccpl
 * Description     : Enable termination of control transfer status stage.
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void hw_usb_pset_ccpl (uint8_t usb_ip)
{
    if (USB_CFG_IP0 == usb_ip)
    {
        USB_M0->DCPCTR |= USB_CCPL;
    }
    else
    {
        USB_M1->DCPCTR |= USB_CCPL;
    }
}

/******************************************************************************
 * End of function hw_usb_pset_ccpl
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pmodule_init
 * Description     :
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void hw_usb_pmodule_init (uint8_t usb_ip)
{
    FSP_PARAMETER_NOT_USED(usb_ip);
    USB_M0->SYSCFG1   = (USB_CFG_BUSWAIT & USB_VAL_BWAIT3F);
    USB_M0->CFIFOSEL  = USB0_CFIFO_MBW;
    USB_M0->D0FIFOSEL = USB0_D0FIFO_MBW;
    USB_M0->D1FIFOSEL = USB0_D1FIFO_MBW;
  #if USB_CFG_ENDIAN == USB_CFG_BIG
    USB_M0->CFIFOSEL  |= USB_BIGEND;
    USB_M0->D0FIFOSEL |= USB_BIGEND;
    USB_M0->D1FIFOSEL |= USB_BIGEND;
  #endif                               /* USB_CFG_ENDIAN == USB_CFG_BIG */
}

/******************************************************************************
 * End of function hw_usb_pmodule_init
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pcontrol_dprpu
 * Description     : Set/Clear DPRPU-bit SYSCFG0 register.
 * Arguments       : usb_ip   : USB module number (USB_IP0/USB_IP1)
 *               : state    : USB_ON  (D+ Line Pullup Enable)
 *               :          : USB_OFF (D+ Line Pullup Disable)
 * Return value    : none
 ******************************************************************************/
void hw_usb_pcontrol_dprpu (uint8_t usb_ip, uint8_t state)
{
    if (USB_IP0 == usb_ip)
    {
        if (USB_ON == state)
        {
            USB_M0->SYSCFG0 |= (uint16_t) (USB_DPRPU);
        }
        else
        {
            USB_M0->SYSCFG0 &= (uint16_t) (~USB_DPRPU);
        }
    }
    else
    {
        if (USB_ON == state)
        {
            USB_M1->SYSCFG0 |= (uint16_t) (USB_DPRPU);
        }
        else
        {
            USB_M1->SYSCFG0 &= (uint16_t) (~USB_DPRPU);
        }
    }
}

/******************************************************************************
 * End of function hw_usb_pcontrol_dprpu
 ******************************************************************************/

/******************************************************************************
 * Function Name   : hw_usb_pcontrol_dcpctr_pid
 * Description     : Set ACK /STALL to PID bit for DCPCTR register
 * Arguments       : usb_ip   : USB module number (USB_IP0/USB_IP1)
 *               : data     : USB_PID_BUF   (ACK)
 *               :          : USB_PID_STALL (STALL)
 * Return value    : none
 ******************************************************************************/
void hw_usb_pcontrol_dcpctr_pid (uint8_t usb_ip, uint16_t data)
{
    if (USB_IP0 == usb_ip)
    {
        USB_M0->DCPCTR &= (uint16_t) (~USB_PID);
        if (data == USB_SETUP_STATUS_ACK)
        {
            USB_M0->DCPCTR |= (uint16_t) USB_PID_BUF;
        }
        else
        {
            USB_M0->DCPCTR |= (uint16_t) USB_PID_STALL;
        }
    }
    else
    {
        USB_M1->DCPCTR &= (uint16_t) (~USB_PID);
        if (data == USB_SETUP_STATUS_ACK)
        {
            USB_M1->DCPCTR |= (uint16_t) USB_PID_BUF;
        }
        else
        {
            USB_M1->DCPCTR |= (uint16_t) USB_PID_STALL;
        }
    }
}

/******************************************************************************
 * End of function hw_usb_pcontrol_dcpctr_pid
 ******************************************************************************/

#endif                                 /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_REPI */

/******************************************************************************
 * End of file
 ******************************************************************************/
