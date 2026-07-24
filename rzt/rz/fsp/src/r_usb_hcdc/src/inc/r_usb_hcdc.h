/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef R_USB_HCDC_H
#define R_USB_HCDC_H

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/
#include "r_usb_hcdc_api.h"

/*****************************************************************************
 * Macro definitions
 ******************************************************************************/

/* CDC Transfer data size */
#define     USB_HCDC_EP_OFFSET_DATA    (0) /* Ep Table Bulk Pipe offset */
#define     USB_HCDC_EP_OFFSET_CTL     (2) /* Ep Table Int Pipe offset */

#define     USB_NOPIPE                 ((uint8_t) 0xFF)

/* Host Sample Task */
#if (BSP_CFG_RTOS != 2)
 #define USB_HCDC_TSK                  (USB_TID_6)    /* Task ID */
 #define USB_HCDC_MBX                  (USB_HCDC_TSK) /* Mailbox ID */
 #define USB_HCDC_MPL                  (USB_HCDC_TSK) /* Memorypool ID */
#else
 #define USB_HCDC_TSK                  (USB_TID_8)    /* Task ID */
 #define USB_HCDC_MBX                  (USB_HCDC_TSK) /* Mailbox ID */
 #define USB_HCDC_MPL                  (USB_HCDC_TSK) /* Memorypool ID */
#endif /* (BSP_CFG_RTOS_USED == 0) */
#define USB_MAX_CONNECT_DEVICE_NUM     (2U)           /* 1-2 */
#define USB_MAX_WLANGID_NUM            (32U)          /* Max Index Num of wLANGID. */

 #define USB_HCDC_SPECIFIC_DEV_MAX      (5)            /* Maximum number of registrations for a specific device.*/

/******************************************************************************
 * Exported global variables
 ******************************************************************************/
extern uint8_t  * g_p_usb_hcdc_device_table[];
extern uint8_t  * g_p_usb_hcdc_config_table[];
extern uint8_t  * g_p_usb_hcdc_interface_table[];
extern uint16_t   g_usb_hcdc_speed[];
extern uint16_t   g_usb_hcdc_devaddr[];
extern int16_t    g_usb_hcdc_smpl_class_seq[];
extern uint16_t * g_p_usb_hcdc_pipe_table[];

extern void usb_hcdc_configured(usb_utr_t * ptr, uint16_t devadr, uint16_t data2);
extern void usb_hcdc_detach(usb_utr_t * ptr, uint16_t devadr, uint16_t data2);

extern usb_er_t usb_hcdc_set_pipe_registration(usb_utr_t * ptr, uint16_t dev_addr);
extern void     usb_hcdc_class_check(usb_utr_t * ptr, uint16_t ** table);

/******************************************************************************
 * Exported global functions (to be accessed by other files)
 ******************************************************************************/

void     usb_hcdc_enumeration(usb_clsinfo_t * mess);
uint16_t usb_hcdc_pipe_info(usb_utr_t * ptr, uint8_t * table, uint16_t speed, uint16_t length);
uint16_t * usb_hcdc_get_vendor_table(void);

fsp_err_t R_USB_HCDC_ControlDataRead (usb_ctrl_t * const p_api_ctrl,
                                      uint8_t          * p_buf,
                                      uint32_t           size,
                                      uint8_t            device_address);
fsp_err_t R_USB_HCDC_SpecificDeviceRegister (usb_ctrl_t * const p_api_ctrl, uint16_t vendor_id, uint16_t product_id);
fsp_err_t R_USB_HCDC_DeviceInfoGet (usb_ctrl_t * const       p_api_ctrl,
                                    usb_hcdc_device_info_t * p_info,
                                    uint8_t                  device_address);

void usb_hcdc_set_control_line_state(usb_instance_ctrl_t * p_ctrl, uint8_t device_address, usb_setup_t * setup); /* DEPRECATED */
void usb_hcdc_set_line_coding(usb_instance_ctrl_t   * p_ctrl,
                              uint8_t                 device_address,
                              usb_hcdc_linecoding_t * g_com_parm,
                              usb_setup_t           * setup);                                                    /* DEPRECATED */
void usb_hcdc_get_line_coding(usb_instance_ctrl_t   * p_ctrl,
                              uint8_t                 device_address,
                              usb_hcdc_linecoding_t * g_com_parm,
                              usb_setup_t           * setup);                                                    /* DEPRECATED */


#endif                                 /* R_USB_HCDC_H */

/******************************************************************************
 * End Of File
 ******************************************************************************/
