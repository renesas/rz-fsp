/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_rtos_config.h
 * Version      : 1.0
 * Description  : Config file for Free RTOS used
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 15.01.2017 1.00     First Release
 **********************************************************************************************************************/

// #include "r_usb_basic_drv_sc_cfg.h"

#ifndef R_USBH1_RTOS_CONFIG_H
#define R_USBH1_RTOS_CONFIG_H

/******************************************************************************
 * Constant macro definitions
 ******************************************************************************/

/* Avoid nest define */
#ifndef BSP_CFG_RTOS_USED
 #define BSP_CFG_RTOS_USED    (0)
#endif                                 /* BSP_CFG_RTOS_USED */

/******************************************************************************
 * End  Of File
 ******************************************************************************/
#endif                                 /* R_USB_RTOS_CONFIG_H */
