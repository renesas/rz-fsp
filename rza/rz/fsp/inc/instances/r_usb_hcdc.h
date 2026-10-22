/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : r_usb_hcdc.h
 * Description  : USB HCDC public APIs.
 **********************************************************************************************************************/

#ifndef USB_HCDC_H
#define USB_HCDC_H

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/
#include "r_usb_hcdc_cfg.h"
#include "r_usb_basic_api.h"
#include "r_usb_hcdc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZA
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_USB_HCDC
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
extern const usb_hcdc_api_t g_hcdc_on_usb;

/** @endcond */

/******************************************************************************
 * Exported global functions (to be accessed by other files)
 ******************************************************************************/
fsp_err_t R_USB_HCDC_ControlDataRead(usb_ctrl_t * const p_api_ctrl,
                                     uint8_t          * p_buf,
                                     uint32_t           size,
                                     uint8_t            device_address);
fsp_err_t R_USB_HCDC_SpecificDeviceRegister(usb_ctrl_t * const p_api_ctrl, uint16_t vendor_id, uint16_t product_id);
fsp_err_t R_USB_HCDC_DeviceInfoGet(usb_ctrl_t * const       p_api_ctrl,
                                   usb_hcdc_device_info_t * p_info,
                                   uint8_t                  device_address);

/*******************************************************************************************************************//**
 * @} (end addtogroup USB_HCDC)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* USB_HCDC_H */
