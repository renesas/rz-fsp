/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************
 * File Name     : r_usb_dmaca_rx_config.h
 * Description   : Configuration file for DMACA driver
 ********************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 30.06.2014 1.00    Initial revision
 *         : 27.08.2014 1.01    Not change program due to updating application note only.
 *         : 30.01.2015 1.02    Added RX71M.
 *         : 13.04.2015 1.03    Added RX231 and RX230.
 *******************************************************************************/
#ifndef USB_DMACA_RX_CONFIG_H
#define USB_DMACA_RX_CONFIG_H

/*
 * SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING
 *  0 : Compiles out parameter checking.
 *  1 : Includes parameter checking.
 * Default value is set to BSP_CFG_PARAM_CHECKING_ENABLE to re-use the system default setting
 */
#define USB_DMACA_CFG_PARAM_CHECKING_ENABLE    BSP_CFG_PARAM_CHECKING_ENABLE

/*
 * SPECIFY WHETHER THE DTC DRIVER IS USED WITH DMACA DRIVER
 *  0 : DTC driver is not used with DMACA driver.
 *  1 : DTC driver is used with DMACA driver.
 */
#define USB_DMACA_CFG_USE_DTC_FIT_MODULE       (0)

#endif                                 /* USB_DMACA_RX_CONFIG_H */
