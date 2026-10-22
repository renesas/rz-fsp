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

tsip_ret_t r_tsip_pdci (const uint32_t InData_KeyIndex[])
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

    WR1_PROG(REG_0084H, 0x0000dc02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_007CH, 0x00000011U);
    r_tsip_func100(0x0037c5aaU, 0x69435a80U, 0x5fcc75c8U, 0xd3171b7dU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xeedcf535U, 0xd461b2c6U, 0xc0f91af4U, 0xc4e6d321U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00080e15U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[0]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[1]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[2]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[3]);
    r_tsip_func100(0x9e3198a0U, 0xf24cf3e4U, 0x5d1b1bb3U, 0xeba3b711U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x018fd17cU));
    WR1_PROG(REG_0104H, 0x00000761U);
    WR1_PROG(REG_00B0H, 0x00000100U);
    WR1_PROG(REG_00A4H, 0x02f087b7U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[7]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[11]);
    WR1_PROG(REG_00E0H, 0x80080000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008123U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[12]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[13]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[14]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[15]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x208e9781U, 0xeefa08c7U, 0xc86f64f9U, 0x3e00ac4aU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x0292e610U, 0x6a7b4393U, 0x3890a732U, 0x2f0ea079U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_007CH, 0x00000011U);
        WR1_PROG(REG_0104H, 0x00000754U);
        WR1_PROG(REG_0074H, 0x00000004U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xc1059ed8U));
        WR1_PROG(REG_0100H, bswap_32big(0x367cd507U));
        WR1_PROG(REG_0100H, bswap_32big(0x3070dd17U));
        WR1_PROG(REG_0100H, bswap_32big(0xf70e5939U));
        WR1_PROG(REG_0100H, bswap_32big(0xffc00b31U));
        WR1_PROG(REG_0100H, bswap_32big(0x68581511U));
        WR1_PROG(REG_0100H, bswap_32big(0x64f98fa7U));
        WR1_PROG(REG_0100H, bswap_32big(0xbefa4fa4U));
        WR1_PROG(REG_0074H, 0x00000002U);
        r_tsip_func001();
        WAIT_STS(REG_0074H, 18U, 0U);
        WR1_PROG(REG_001CH, 0x00001600U);
        r_tsip_func101(0x30ed8023U, 0x450329bdU, 0xf1b503c9U, 0x2484ad45U);

        return TSIP_RET_PASS;
    }
}
