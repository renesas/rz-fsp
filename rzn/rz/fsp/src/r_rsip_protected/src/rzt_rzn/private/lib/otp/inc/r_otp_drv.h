/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_OTP_DRV_H
#define R_OTP_DRV_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "r_typedefs.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/* Selector for reading keys and hashes from OTP */
typedef enum e_otp_content_t
{
    OTP_CONTENT_ADDITIONAL_KEY4             = 0,
    OTP_CONTENT_ADDITIONAL_KEY3             = 1,
    OTP_CONTENT_SCI_AUTHENTICATION_ID_HASH  = 2,
    OTP_CONTENT_JTAG_AUTHENTICATION_ID4     = 3,
    OTP_CONTENT_JTAG_AUTHENTICATION_ID1     = 4,
    OTP_CONTENT_ROOT_PUBLIC_KEY_HASH        = 5,
    OTP_CONTENT_HARDWARE_UNIQUE_KEY         = 6,
    OTP_CONTENT_ADDITIONAL_KEY2             = 7,
    OTP_CONTENT_ADDITIONAL_KEY1             = 8,
    OTP_CONTENT_SCI_AUTHENTICATION_ID_PLAIN = 9,
    OTP_CONTENT_UNIQUE_ID = 10,
} e_otp_content_t;

/***********************************************************************************************************************
 * Exported global variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/
extern int32_t R_OTP_GetContent(e_otp_content_t otp_content, uint8_t * p_content, uint32_t len);

#endif                                 /* R_OTP_DRV_H */
