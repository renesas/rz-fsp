/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_basic_if.h
 * Version      : 1.0
 * Description  : Interface file for USB basic API for RZ/T1
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 15.01.2017 1.00     First Release
 **********************************************************************************************************************/

#ifndef R_USB_BASIC_IF_H
#define R_USB_BASIC_IF_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#if 0
 #ifdef   __ICCARM__
  #include <stdint.h>
 #endif
 #ifdef   __CC_ARM
  #include <stdint.h>
 #endif
 #ifdef __GNUC__
  #include "platform.h"
 #endif
#endif

#include <stdint.h>
#include <stddef.h>
#include "r_usb_basic.h"
#include "r_usb_basic_config.h"
#include "r_usb_typedef.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Standard Configuration Descriptor Offset Define */
#define USB_CON_W_TOTAL_LENGTH_L         (2U)    /* Total length of data returned for this configuration */
#define USB_CON_W_TOTAL_LENGTH_H         (3U)    /* Total length of data returned for this configuration */
#define USB_CON_B_NUM_INTERFACES         (4U)    /* Number of interfaces supported by this configuration */
#define USB_CON_B_CONFIGURATION_VALUE    (5U)    /* Configuration value */
#define USB_CON_I_CONFIGURATION          (6U)    /* Index of string descriptor describing this configuration */
#define USB_CON_BM_ATTRIBUTES            (7U)    /* Configuration characteristics */
#define USB_CON_B_MAX_POWER              (8U)    /* Max power consumption of the USB device from the bus */

/* OTG descriptor bit define */
#define USB_OTG_HNP                      (0x02U) /* HNP support */
#define USB_OTG_SRP                      (0x01U) /* SRP support */

#if USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE
 #define USB_COMP_ATTACH                 (0x00U)
 #define USB_COMP_DETACH                 (0x01U)
 #define USB_COMP_TPL                    (0x02U)
 #define USB_COMP_NOTTPL                 (0x03U)
 #define USB_COMP_HUB                    (0x04U)
 #define USB_COMP_STOP                   (0x05U)
 #define USB_COMP_NOTRESP                (0x06U)
 #define USB_COMP_VID                    (0x07U)
 #define USB_COMP_PID                    (0x08U)
 #define USB_COMP_ERR                    (0x09U)
#endif                                 /* USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* USB Transfer Request Callback Type */
typedef struct usb_utr st_usb_utr_t;
typedef void        (* usb_utr_cb_t)(st_usb_utr_t *);

/* Registration Structure */
typedef struct
{
    uint16_t       rootport;           /* Root port */
    uint16_t       devaddr;            /* Device address */
    uint16_t       devstate;           /* Device state */
    uint16_t       ifclass;            /* Interface Class */
    uint16_t     * p_tpl;              /* Target peripheral list (Vendor ID, Product ID) */
    usb_cb_t       classinit;          /* Driver init */
    usb_cb_check_t classcheck;         /* Driver check */
    usb_cb_t       devconfig;          /* Device configured */
    usb_cb_t       devdetach;          /* Device detach */
    usb_cb_t       devsuspend;         /* Device suspend */
    usb_cb_t       devresume;          /* Device resume */
} st_usb_hcdreg_t;

/* Setup Structure */
typedef struct USB_SETUP
{
    uint16_t type;                     /* bRequest[b15-b8], bmRequestType[b7-b0] */
    uint16_t value;                    /* wValue */
    uint16_t index;                    /* wIndex */
    uint16_t length;                   /* wLength */
    uint16_t devaddr;                  /* Device Address */
} st_usb_setup_t;

/* Transfer Request Structure */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* USB API (Host) */
usb_er_t R_USB_HstdTransferStart(st_usb_utr_t * utr);
usb_er_t R_USB_HstdTransferEnd(uint16_t pipe_id);
usb_er_t R_USB_HstdDriverRegistration(st_usb_hcdreg_t * callback);
void     R_USB_HstdReturnEnuMGR(uint16_t cls_result);

usb_er_t R_USB_HstdChangeDeviceState(usb_utr_t * ptr, usb_cb_t complete, uint16_t msginfo, uint16_t member);

usb_er_t R_USB_HstdClearPipe(uint16_t devaddr);
void     R_USB_HstdMgrTask(void);
void     R_USB_HstdDelayXms(uint32_t ms);
void     R_USB_HstdMgrClose(void);
void     r_usb_hstd_mgr_task(void);

/* USB API (Hub) */
void R_USB_HhubTask(void);

/* NonOS Scheduler */
usb_er_t R_USB_CstdRecMsg(uint8_t id, usb_msg_t ** mess);
usb_er_t R_USB_CstdSndMsg(uint8_t id, usb_msg_t * mess);
usb_er_t R_USB_CstdWaiMsg(uint8_t id, usb_msg_t * p_mess, uint16_t times);
usb_er_t R_USB_CstdPgetBlk(uint8_t id, st_usb_utr_t ** blk);
usb_er_t R_USB_CstdRelBlk(uint8_t id, st_usb_utr_t * blk);
void     R_USB_CstdScheduler(void);
void     R_USB_CstdSetTaskPri(uint8_t tasknum, uint8_t pri);
uint8_t  R_USB_CstdCheckSchedule(void);
uint16_t R_USB_HstdGetMaxPacketSize(uint16_t devadr);
uint16_t R_USB_HstdGetDevAddr(uint16_t devadr);

void R_USB_Init(void);

#endif                                 /* R_USB_BASIC_IF_H */
