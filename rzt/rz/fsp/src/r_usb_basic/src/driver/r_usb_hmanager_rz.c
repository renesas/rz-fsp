/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hmanager.c
 * Description  : USB Host Control Manager
 ***********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 31.08.2015 1.00    First Release
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include <string.h>

#include "r_usb_basic_local.h"
#include "r_usb_hhci.h"
#include "r_usb_extern.h"

#if  USB_IP_EHCI_OHCI == 1
/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
 #define CLS_DATA_SIZE    (512U)

/***********************************************************************************************************************
 * External variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/*
 * st_usb_hcdreg_t   g_usb_hstd_device_drv[USB_MAXDEVADDR + 1u];     // Device driver (registration)
 * uint16_t            g_usb_hstd_mgr_mode[1u];                      //     Manager mode
 * uint16_t            g_usb_hstd_device_addr;                        //    Device address
 * uint16_t            g_usb_hstd_device_speed;                       //    reset handshake result
 * uint16_t            g_usb_hstd_device_num;                         //    Device driver number
 * uint16_t            g_usb_hstd_check_enu_result;
 */
#if USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE
volatile uint8_t g_usb_hstd_test_packet_parameter_flag = 0;
 #endif                                /* USB_HOST_COMPLIANCE_MODE */

/***********************************************************************************************************************
 * Static variables and functions
 ***********************************************************************************************************************/
 #ifdef __ICCARM__
 #endif                                /* __ICCARM__ */

/* #ifdef __GNUC__ */
/* #endif   __GNUC__ */

 #ifdef __CC_ARM
 #endif                                /* __CC_ARM */

#if USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE

#define USB_TEST_VAL_SE0_NAK           (0x0101)
#define USB_TEST_VAL_J                 (0x0102)
#define USB_TEST_VAL_K                 (0x0103)
#define USB_TEST_VAL_TEST_PACKET       (0x0104)
#define USB_TEST_VAL_RESERVED          (0x0105)
#define USB_TEST_VAL_SUSPEND_RESUME    (0x0106)
#define USB_TEST_VAL_GET_DEV_DESC      (0x0107)
#define USB_TEST_VAL_GET_DEV_DESC_DATA (0x0108)

/***********************************************************************************************************************
 * Function Name   : usb_hstd_electrical_test_mode
 * Description     : Host electrical test mode function
 * Argument        : product_id          : Task Start Code
 *              : port                : rootport number
 * Return          : none
 ***********************************************************************************************************************/
void usb_hstd_electrical_test_mode (usb_utr_t * ptr, uint16_t product_id, uint16_t port)
{
    uint16_t dev_addr;

    dev_addr = r_usb_hstd_hci_get_device_address_of_rootpoot(port);

    switch (product_id)
    {
        case USB_TEST_VAL_SE0_NAK:             /* Test_SE0_NAK */
        {
            r_usb_hstd_hci_electrical_test(ptr, port, 0);
            break;
        }

        case USB_TEST_VAL_J:                   /* Test_J */
        {
            r_usb_hstd_hci_electrical_test(ptr, port, 1);
            break;
        }

        case USB_TEST_VAL_K:                   /* Test_K */
        {
            r_usb_hstd_hci_electrical_test(ptr, port, 2);
            break;
        }

        case USB_TEST_VAL_TEST_PACKET:        /* Test_Packet */
        {
            r_usb_hstd_hci_electrical_test(ptr, port, 3);
            break;
        }

        case USB_TEST_VAL_RESERVED:          /* Reserved */
        {
            break;
        }

        case USB_TEST_VAL_SUSPEND_RESUME:    /* HS_HOST_PORT_SUSPEND_RESUME */
        {
            r_usb_hstd_hci_electrical_test(ptr, port, 4);
            break;
        }

        case USB_TEST_VAL_GET_DEV_DESC:      /* SINGLE_STEP_GET_DEV_DESC */
        {
            /* R_USB_HstdDelayXms(15000); */            /* wait 15sec */
            usb_hstd_enum_get_descriptor(ptr, dev_addr, 0);
            break;
        }

        case USB_TEST_VAL_GET_DEV_DESC_DATA: /* SINGLE_STEP_GET_DEV_DESC_DATA */
        {
            g_usb_hstd_test_packet_parameter_flag = 1;
            usb_hstd_enum_get_descriptor(ptr, dev_addr, 0);
            break;
        }

        default:
        {
            break;
        }
    }
}                                      /* End of function usb_hstd_electrical_test_mode() */

 #endif /* USB_HOST_COMPLIANCE_MODE */
#endif  /* USB_IP_EHCI_OHCI == 1 */

/***********************************************************************************************************************
 * End Of File
 ***********************************************************************************************************************/
