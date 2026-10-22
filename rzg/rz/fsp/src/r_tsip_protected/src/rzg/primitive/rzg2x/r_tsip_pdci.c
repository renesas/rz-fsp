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
    r_tsip_func100(0xf5103a71U, 0x209077e8U, 0x3061802bU, 0xa75324c0U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x6b75c38dU, 0x8ef0a95fU, 0xd9a525b3U, 0x5f878cd0U);
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
    r_tsip_func100(0x60e2597dU, 0x19c1cdf6U, 0xc82b4674U, 0x2cddd641U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01d7ff9eU));
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
    r_tsip_func100(0xfe3b5372U, 0x5c1ffb83U, 0x7f7d8f64U, 0xfd0216daU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x2f016092U, 0x706eb573U, 0xe49ed7a0U, 0x307b5b01U);
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
        r_tsip_func101(0x4d91d446U, 0xfc72a381U, 0x3593dfd6U, 0x2c5efa9aU);

        return TSIP_RET_PASS;
    }
}
