/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"
#include "r_tsip_private.h"
#include "r_tsip_util.h"
#include "r_tsip_reg.h"
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define TSIP_PRV_CMD_JTAG_DEBUG_AUTH    (BSWAP_32BIG_C(0U))

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

tsip_ret_t r_tsip_open (void)
{
    tsip_ret_t            tsip_ret    = TSIP_RET_FAIL;
    static const uint32_t jtag_cmd[1] =
    {
        TSIP_PRV_CMD_JTAG_DEBUG_AUTH
    };

    r_tsip_p00();

    tsip_ret = r_tsip_p01();

    if (TSIP_RET_PASS == tsip_ret)
    {
        WR1_PROG(REG_01D4H, TSIP_PRV_CMD_REG_01D4H);
        tsip_ret = r_tsip_p06(jtag_cmd);

        if (TSIP_RET_PASS_0 == tsip_ret)
        {
            tsip_ret = r_tsip_p02();

            if (TSIP_RET_RETRY == tsip_ret)
            {
                tsip_ret = r_tsip_p02();

                if (TSIP_RET_RETRY == tsip_ret)
                {
                    tsip_ret = r_tsip_p02();
                }
            }
        }
    }

    return tsip_ret;
}

tsip_ret_t r_tsip_close (void)
{
    r_tsip_p00();

    return TSIP_RET_PASS;
}

void r_tsip_kuk_set (const void * p_key_update_key)
{
    S_INST2 = (uint32_t *) p_key_update_key;
}

fsp_err_t r_tsip_get_rfc3394_key_wrap_param (tsip_key_type_t key_type, uint32_t * wrapped_key_type)
{
    fsp_err_t err = FSP_ERR_INVALID_ARGUMENT;

    switch (key_type)
    {
        case TSIP_KEY_TYPE_AES_128:
        {
            wrapped_key_type[0] = BSWAP_32BIG_C(0U);
            err                 = FSP_SUCCESS;
            break;
        }

        case TSIP_KEY_TYPE_AES_256:
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
