/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "bsp_api.h"
#include "r_typedefs.h"
#include "r_error_codes.h"
#include "iodefine.h"
#include "r_otp_drv.h"
#include "r_rsip_otp.h"
#include "r_rsip_primitive.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

#define OTP_STATIC    static

OTP_STATIC int32_t r_otp_secure_read(uint16_t addr, uint8_t * p_value, uint8_t count);
OTP_STATIC void    R_CORE_RndDelay(void);

/***********************************************************************************************************************
 * Function Name: R_OTP_GetContent
 * Description  : Check the OTP to obtain a key or hash
 * Arguments    : otp_content - identifies the content to get
 *                p_content - location for key or hash.
 *                len - length of buffer for content, must be correct for the data requested
 * Return Value : D_BOOT_ERR or D_BOOT_OK
 ***********************************************************************************************************************/
int32_t R_OTP_GetContent (e_otp_content_t otp_content, uint8_t * p_content, uint32_t len)
{
    static const struct
    {
        uint16_t otp_address;
        uint8_t  size;
    } content_info[] =
    {
        /* OTP Address                            Size in 16 bit words                         Index Enum */
        {OTP_IP_ADDITIONAL_KEY4_ADDR,             OTP_IP_ADDITIONAL_KEY4_SIZE            }, /* OTP_CONTENT_ADDITIONAL_KEY4 */
        {OTP_IP_ADDITIONAL_KEY3_ADDR,             OTP_IP_ADDITIONAL_KEY3_SIZE            }, /* OTP_CONTENT_ADDITIONAL_KEY3 */
        {OTP_IP_SCI_AUTHENTICATION_ID_ADDR,       OTP_IP_SCI_AUTHENTICATION_ID_SIZE      }, /* OTP_CONTENT_SCI_AUTHENTICATION_ID_HASH */
        {OTP_IP_JTAG_AUTHENTICATION_ID4_ADDR,     OTP_IP_JTAG_AUTHENTICATION_ID4_SIZE    }, /* OTP_CONTENT_JTAG_AUTHENTICATION_ID4 */
        {OTP_IP_JTAG_AUTHENTICATION_ID1_ADDR,     OTP_IP_JTAG_AUTHENTICATION_ID1_SIZE    }, /* OTP_CONTENT_JTAG_AUTHENTICATION_ID1 */
        {OTP_IP_ROOT_PUBLIC_KEY_HASH_ADDR,        OTP_IP_ROOT_PUBLIC_KEY_HASH_SIZE       }, /* OTP_CONTENT_ROOT_PUBLIC_KEY_HASH */
        {OTP_IP_HARDWARE_UNIQUE_ID_ADDR,          OTP_IP_HARDWARE_UNIQUE_ID_SIZE         }, /* OTP_CONTENT_HARDWARE_UNIQUE_KEY */
        {OTP_IP_ADDITIONAL_KEY2_ADDR,             OTP_IP_ADDITIONAL_KEY2_SIZE            }, /* OTP_CONTENT_ADDITIONAL_KEY2 */
        {OTP_IP_ADDITIONAL_KEY1_ADDR,             OTP_IP_ADDITIONAL_KEY1_SIZE            }, /* OTP_CONTENT_ADDITIONAL_KEY1 */
        {OTP_IP_SCI_AUTHENTICATION_ID_PLAIN_ADDR, OTP_IP_SCI_AUTHENTICATION_ID_PLAIN_SIZE}, /* OTP_CONTENT_SCI_AUTHENTICATION_ID_PLAIN */
        {OTP_IP_UNIQUE_ID_ADDR,                   OTP_IP_UNIQUE_ID_SIZE                  }, /* OTP_CONTENT_UNIQUE_ID */
    };

    int32_t ret = D_BOOT_ERR;

    if ((uint32_t) otp_content < sizeof(content_info) / sizeof(content_info[0]))
    {
        len = len / 2u;
        if ((NULL != p_content) && (len == content_info[otp_content].size))
        {
            if (0 == r_rsip_otp_power_on())
            {
                if (0 ==
                    r_otp_secure_read(content_info[otp_content].otp_address, p_content, content_info[otp_content].size))
                {
                    r_rsip_otp_power_off();
                    ret = D_BOOT_OK;
                }
            }
        }
    }

    return ret;
}                                      /* End of function R_OTP_GetContent() */

/***********************************************************************************************************************
 * Function Name: r_otp_secure_read
 * Description  : Securely read bits to p_value from the OTP
 * Arguments    : addr - Address of where reading the functions
 *                p_value - Pointer of where to put the read values
 *                count - number of values to read
 * Return Value : D_BOOT_ERR or D_BOOT_OK
 ***********************************************************************************************************************/
OTP_STATIC int32_t r_otp_secure_read (uint16_t addr, uint8_t * p_value, uint8_t count)
{
    int32_t ret = D_BOOT_ERR;

    R_CORE_RndDelay();
    ret = r_rsip_otp_multiple_data_read(addr, p_value, (uint8_t) (count * (sizeof(uint16_t) / sizeof(uint8_t))));

    return ret;
}                                      /* End of function r_otp_secure_read() */

/***********************************************************************************************************************
 * Function Name: R_CORE_RndDelay()
 * Description  : Generates a random delay for Security purposes
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
OTP_STATIC void R_CORE_RndDelay (void)
{
    uint16_t rand[8] = {0};
    r_rsip_p20((uint32_t *) rand);
    uint16_t count = rand[0];

    while (0u < count)
    {
        __NOP();
        count--;
    }
}                                      /* End of function R_CORE_RndDelay() */
