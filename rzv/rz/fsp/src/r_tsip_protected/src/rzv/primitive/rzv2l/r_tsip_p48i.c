/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"
#include "r_tsip_reg.h"
#include "r_tsip_util.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

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

TSIP_PRV_PRIMITIVE_FUNC

tsip_ret_t r_tsip_p48i (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
{
    TSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t iLoop2;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t oLoop2;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) iLoop2;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) oLoop2;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_01BCH, 0x1fU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00004802U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x80010000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x3000a800U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x00010020U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    r_tsip_func100(0x4c854bdfU, 0x957bfdbaU, 0x1ebb10c4U, 0x0ed4fa4eU);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00A4H, 0x00090805U);
    WR1_PROG(REG_00E0H, 0x81840001U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x2fb284c3U, 0xc726aa58U, 0xcf243b05U, 0x0eac0d10U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00441a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00091e15U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[0]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[1]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[2]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[3]);
    r_tsip_func100(0x63ed45c8U, 0xba82898aU, 0x506de8c3U, 0x17dd5fd5U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00441a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00091e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x012279dbU));
    r_tsip_func100(0x8e4711caU, 0xe6fa3205U, 0xa3768a5bU, 0x6bfc30a2U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f81735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[7]);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000017b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[11]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xb5cb9268U, 0xcb0eebe4U, 0x6d16c53dU, 0xe96c5cc8U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xc71c7f87U, 0x5a0961a3U, 0x8e2c8a2aU, 0xaa8efe45U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0xed7a0e60U, 0x7566e568U, 0x96ee3adfU, 0x71f23071U);
        WR1_PROG(REG_00ECH, 0x00007c00U);
        WR1_PROG(REG_001CH, 0x00600000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            r_tsip_func101(0xce02742aU, 0x2e73ee48U, 0xd0926f0bU, 0xff5d17d9U);
        }
        else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            r_tsip_func101(0x97654171U, 0x0a3919e2U, 0xc3e3d2f1U, 0x383cf16dU);
        }
        else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00A4H, 0x00040805U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_IV[0]);
            WR1_ADDR(REG_0100H, &InData_IV[1]);
            WR1_ADDR(REG_0100H, &InData_IV[2]);
            WR1_ADDR(REG_0100H, &InData_IV[3]);
            r_tsip_func101(0xc36270c9U, 0x1e21d08eU, 0x09393eb9U, 0x1d4bcaa6U);
        }
        else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00A4H, 0x00040805U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_IV[0]);
            WR1_ADDR(REG_0100H, &InData_IV[1]);
            WR1_ADDR(REG_0100H, &InData_IV[2]);
            WR1_ADDR(REG_0100H, &InData_IV[3]);
            r_tsip_func101(0x5dcdb108U, 0x8f64040dU, 0x1596068cU, 0x0a2e09c5U);
        }
        else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00A4H, 0x00040805U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_IV[0]);
            WR1_ADDR(REG_0100H, &InData_IV[1]);
            WR1_ADDR(REG_0100H, &InData_IV[2]);
            WR1_ADDR(REG_0100H, &InData_IV[3]);
            r_tsip_func101(0xe8d23aaeU, 0x402f332eU, 0xc20afd10U, 0x139614c1U);
        }

        return TSIP_RET_PASS;
    }
}
