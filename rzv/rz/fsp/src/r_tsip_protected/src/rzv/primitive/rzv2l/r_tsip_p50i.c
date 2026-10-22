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

tsip_ret_t r_tsip_p50i (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
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

    WR1_PROG(REG_0084H, 0x00005002U);
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
    r_tsip_func100(0xaf23d1d3U, 0x94d15122U, 0x0e166735U, 0xf7bb4fdeU);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00A4H, 0x000a0805U);
    WR1_PROG(REG_00E0H, 0x81840001U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x779bc55cU, 0x53a2cbc2U, 0xb07e5b0bU, 0xd38ca237U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000a2e15U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[0]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[1]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[2]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[3]);
    r_tsip_func100(0x79fb1b2aU, 0xb6776a38U, 0x2826d199U, 0x6f78654dU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a2e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0178d478U));
    r_tsip_func100(0xc1323d11U, 0x53ba82fbU, 0x1833becdU, 0x8ed2246dU);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f82735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[7]);
    r_tsip_func100(0xf925fe9bU, 0x246859e3U, 0xf52bb14aU, 0x9583e083U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00f92735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[11]);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000027b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[12]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[13]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[14]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[15]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x6fe5cab1U, 0x9be98641U, 0x21e09a12U, 0x5a3c4ddcU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x9870304dU, 0x7094fa6eU, 0x6e67f11eU, 0x239b3133U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0xeb89566aU, 0xc749575eU, 0xb53158b0U, 0x8ed68a23U);
        WR1_PROG(REG_00ECH, 0x00007c00U);
        WR1_PROG(REG_001CH, 0x00600000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            r_tsip_func101(0x26bc864cU, 0x2b58a64dU, 0xe7759c43U, 0xac98662aU);
        }
        else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            r_tsip_func101(0x8d8e6957U, 0xddb0ad1bU, 0x68844ba9U, 0x657f1fafU);
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
            r_tsip_func101(0xaf732ec7U, 0x4d8d7caaU, 0x4bfbd72dU, 0x2ff813b1U);
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
            r_tsip_func101(0x7f184fadU, 0xa02a10e9U, 0x0b333f7bU, 0x237ccf4aU);
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
            r_tsip_func101(0x2e565d6aU, 0xca8c5e98U, 0xfa50f85eU, 0x4552a8c8U);
        }

        return TSIP_RET_PASS;
    }
}
