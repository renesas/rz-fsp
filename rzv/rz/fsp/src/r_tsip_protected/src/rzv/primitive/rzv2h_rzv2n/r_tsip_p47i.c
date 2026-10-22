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

tsip_ret_t r_tsip_p47i (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_IV[])
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

    WR1_PROG(REG_0084H, 0x00004701U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x80010000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x3000a800U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0xaac2f196U, 0x627af4c6U, 0x09b70f4fU, 0x91c5e203U);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00A4H, 0x00090805U);
    WR1_PROG(REG_00E0H, 0x81840001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xa7d46783U, 0x78c0d28fU, 0x99ab2ff0U, 0x60cf9e46U);
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
    r_tsip_func100(0x003ad0c6U, 0xcfa55d00U, 0xe62b6413U, 0x7e42dc78U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00441a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00091e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01efbcb4U));
    r_tsip_func100(0x80f3cc23U, 0x7ae72428U, 0x669476c0U, 0x085c5648U);
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
    r_tsip_func100(0x6b340877U, 0xbcf16bb5U, 0xb0bac539U, 0x12fe5d55U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x0fe34597U, 0xf432729eU, 0x5190e7bdU, 0x9b9e3e35U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0xb45845c8U, 0x63d7f618U, 0x93c648c4U, 0xd9f04e94U);
        WR1_PROG(REG_00ECH, 0x00007c00U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_001CH, 0x00600000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            r_tsip_func101(0x0e78ad5cU, 0xeb7de444U, 0xedbdce6dU, 0x36f60e94U);
        }
        else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            r_tsip_func101(0xfffc1574U, 0xf4d69eddU, 0xfc7a7073U, 0x7507f24cU);
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
            r_tsip_func101(0x62203bd8U, 0x4e88cf0fU, 0x3bdf7bf5U, 0x0ba835a3U);
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
            r_tsip_func101(0x5760f0e9U, 0xe29eca1aU, 0x5743dad3U, 0xad9cc6cdU);
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
            r_tsip_func101(0xde4946cdU, 0xa8afae36U, 0x4f163bdaU, 0xd6183ff1U);
        }

        return TSIP_RET_PASS;
    }
}
