/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef USB_HHID_H
 #define USB_HHID_H

/**********************************************************************************************************************
 * File Name    : r_usb_hhid.h
 * Description  : USB HHID public APIs.
 **********************************************************************************************************************/

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/
 #include "r_usb_hhid_cfg.h"
 #include "r_usb_basic_api.h"
 #include "r_usb_hhid_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_USB_HHID
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
extern const usb_hhid_api_t g_hhid_on_usb;

/** @endcond */

/******************************************************************************
 * Exported global functions (to be accessed by other files)
 ******************************************************************************/
fsp_err_t R_USB_HHID_TypeGet(usb_ctrl_t * const p_ctrl, uint8_t * p_type, uint8_t device_address);
fsp_err_t R_USB_HHID_MaxPacketSizeGet(usb_ctrl_t * const p_ctrl,
                                      uint16_t         * p_size,
                                      uint8_t            direction,
                                      uint8_t            device_address);

/*******************************************************************************************************************//**
 * @} (end addtogroup USB_HHID)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* USB_HHID_H */
