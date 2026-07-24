/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************
 * File Name    : r_usb_dmaca_rz_private.h
 * Description  : Specific file for DMACA driver
 *******************************************************************************/

/*******************************************************************************
 * History : DD.MM.YYYY Version Description
 *         : 30.06.2014 1.00    Initial revision
 *         : 27.08.2014 1.01    Not change program due to updating application note only.
 *         : 30.01.2015 1.02    Added RX71M.
 *         : 13.04.2015 1.03    Added RX231 and RX230.
 *         : 30.09.2016 1.04    Added RX65N.
 *******************************************************************************/
#ifndef USB_DMACA_RX_PRIVATE_H
#define USB_DMACA_RX_PRIVATE_H

/*******************************************************************************
 * Includes   <System Includes>, "Project Includes"
 *******************************************************************************/

/* bool support */
#include <stdbool.h>

/* DMACA driver targets header file */
#include "r_usb_dmaca_rz_target.h"

/*****************************************************************************
 * Macro definitions
 ******************************************************************************/

#if USB_CFG_DMA == USB_CFG_ENABLE

/*****************************************************************************
 * Typedef definitions
 ******************************************************************************/

/* CHCTRL.b00:SETEN ... CHSTAT.b00:EN bit set  */
 #define USB_DMACA_DMA_ENABLE         (1 << 0)

/* CHCTRL.b01:CLREN ... CHSTAT.b00:EN bit clear  */
 #define USB_DMACA_DMA_DISABLE        (1 << 1)

/* CHCTRL.b02:STG ... CHSTAT.b01:RQST bit set */
 #define USB_DMACA_SOFT_TRIG          (1 << 2)
 #define USB_DMACA_STAT_RQST          (1 << 2)

/* CHCTRL.b04:CLRRQ ... CHSTAT.b01:RQST bit clear */
 #define USB_DMACA_STAT_RQST_CLEAR    (1 << 4)

/*******************************************************************************
 * Exported global variables and functions (to be accessed by other files)
 *******************************************************************************/
extern void * p_USB_DMACI_Handlers[];

bool               r_usb_dmaca_channel_valid_check(uint8_t channel);
void               r_usb_dmaca_module_enable(void);
void               r_usb_dmaca_module_disable(void);
usb_dmaca_return_t r_usb_dmaca_int_enable_set(uint8_t channel, uint8_t priority);
usb_dmaca_return_t r_usb_dmaca_int_disable_set(uint8_t channel);

#endif
#endif                                 /* USB_DMACA_RX_PRIVATE_H */

/* End of File */
