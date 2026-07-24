/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r__basic_config.h
 * Version      : 1.0
 * Description  : USB Host Ch0 User definition
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 15.01.2017 1.00     First Release
 **********************************************************************************************************************/

#ifndef R_USB_BASIC_CONFIG_H
#define R_USB_BASIC_CONFIG_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "r_usb_basic_if.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Select PIPE NUM */
#define USB_MAXPIPE    (32U)

/* defined: Host COMPLIANCE mode, undefined: Host NORMAL mode */

#if USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE
 #define USB_COMPLIANCE_DISP(data1, data2)
#endif                                 /* USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE */

#define USB_OVERCURRENT(rootport)

/** [Device class setting]
 * @code
 *  #define USB_CFG_HHID_USE : Host Human Interface Device Class
 *  #define USB_CFG_HMSC_USE : Host Mass Storage Class
 * @endcode
 * */

/** [Target board setting]
 * @code
 *  #define BSP_CFG_BOARD_RZA2_EVB : Target board is RZ/A2M Evaluation Board
 *  #define BSP_CFG_BOARD_GR_MANGO : Target board is GR-MANGO
 * @endcode
 * */
#define BSP_CFG_BOARD_RZA2_EVB    (0)
#define BSP_CFG_BOARD_GR_MANGO    (1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif                                 /* R_USB_BASIC_CONFIG_H */
