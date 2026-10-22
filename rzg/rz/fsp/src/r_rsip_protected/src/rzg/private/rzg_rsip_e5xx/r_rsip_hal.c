/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_private.h"
#include "r_rsip_util.h"
#include "r_rsip_reg.h"
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define RSIP_PRV_CMD_JTAG_DEBUG_AUTH    (BSWAP_32BIG_C(0U))

#if BSP_MCU_GROUP_RZG3E
 #define RSIP_PRV_WHUK_ADDR             ((uint32_t *) 0x40451240U)
#elif BSP_MCU_GROUP_RZG3L
 #define RSIP_PRV_WHUK_ADDR             ((uint32_t *) 0x418615d0U)
#else
 #define RSIP_PRV_WHUK_ADDR             ((uint32_t *) 0x418611d0U)
#endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

rsip_ret_t r_rsip_open (void)
{
    rsip_ret_t            rsip_ret    = RSIP_RET_FAIL;
    static const uint32_t jtag_cmd[1] =
    {
        RSIP_PRV_CMD_JTAG_DEBUG_AUTH
    };

    r_rsip_p00();

    rsip_ret = r_rsip_p01();

    if (RSIP_RET_PASS == rsip_ret)
    {
        WR1_PROG(REG_1424H, RSIP_PRV_CMD_REG_1424H);
        WR1_PROG(REG_1428H, RSIP_PRV_CMD_REG_1428H);
        rsip_ret = r_rsip_p02();
        if (RSIP_RET_RETRY == rsip_ret)
        {
            rsip_ret = r_rsip_p02();
            if (RSIP_RET_RETRY == rsip_ret)
            {
                rsip_ret = r_rsip_p02();
            }
        }
    }

    if (RSIP_RET_PASS == rsip_ret)
    {
        rsip_ret = r_rsip_p06(jtag_cmd);
        if (RSIP_RET_PASS_0 == rsip_ret)
        {
            rsip_ret = r_rsip_p40(RSIP_PRV_WHUK_ADDR);
        }
    }

    return rsip_ret;
}

rsip_ret_t r_rsip_close (void)
{
    r_rsip_p00();

    return RSIP_RET_PASS;
}

void r_rsip_kuk_set (const void * p_key_update_key)
{
    S_INST2 = (uint32_t *) p_key_update_key;
}

fsp_err_t r_rsip_get_rfc3394_key_wrap_param (rsip_key_type_t key_type, uint32_t * wrapped_key_type)
{
    fsp_err_t err = FSP_ERR_INVALID_ARGUMENT;

    switch (key_type)
    {
        case RSIP_KEY_TYPE_AES_128:
        {
            wrapped_key_type[0] = BSWAP_32BIG_C(0U);
            err                 = FSP_SUCCESS;
            break;
        }

        case RSIP_KEY_TYPE_AES_256:
        {
            wrapped_key_type[0] = BSWAP_32BIG_C(2U);
            err                 = FSP_SUCCESS;
            break;
        }

        default:
        {
            /* Do nothing */
        }
    }

    return err;
}
