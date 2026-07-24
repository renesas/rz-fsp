/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"

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

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p70r (const uint32_t InData_HashType[], const uint32_t InData_State[])
{
    RSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00700002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    r_rsip_func100(bswap_32big(0xa958f8b8U),
                   bswap_32big(0xf52540bbU),
                   bswap_32big(0x3fe60d7cU),
                   bswap_32big(0xea77c85dU));
    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000007U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000006U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001000U);
        r_rsip_func101(bswap_32big(0x5e144fe9U), bswap_32big(0xca0c1d26U), bswap_32big(0x740b1485U),
                       bswap_32big(0x0164ffbaU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001040U);
        r_rsip_func101(bswap_32big(0xff751f8fU), bswap_32big(0x031115a4U), bswap_32big(0x5ec3cd6fU),
                       bswap_32big(0xd269d461U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001050U);
        r_rsip_func101(bswap_32big(0x5ceff75cU), bswap_32big(0x12b061e8U), bswap_32big(0xf9318fffU),
                       bswap_32big(0x5e79c25dU));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001080U);
        r_rsip_func101(bswap_32big(0x691d8a0dU), bswap_32big(0x1df19b0dU), bswap_32big(0xd7af68a4U),
                       bswap_32big(0xce901355U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001090U);
        r_rsip_func101(bswap_32big(0x6caeeaddU), bswap_32big(0xa4a7f7b0U), bswap_32big(0xf5747415U),
                       bswap_32big(0x77b9cf41U));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010a0U);
        r_rsip_func101(bswap_32big(0x25400f3fU), bswap_32big(0x4eab10f9U), bswap_32big(0x72ba4730U),
                       bswap_32big(0x856e6653U));
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010b0U);
        r_rsip_func101(bswap_32big(0xb1eea1bbU), bswap_32big(0xfec784d4U), bswap_32big(0x9036d304U),
                       bswap_32big(0xfa2a8b56U));
    }

    WR1_PROG(REG_1444H, 0x00000040U);
    WR1_ADDR(REG_2014H, &InData_State[18]);
    WR1_PROG(REG_1444H, 0x00000040U);
    WR1_ADDR(REG_2010H, &InData_State[19]);
    for (iLoop = 0; iLoop < 18; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2028H, &InData_State[iLoop + 0]);
    }

    r_rsip_func101(bswap_32big(0x167ae67cU),
                   bswap_32big(0xf0052229U),
                   bswap_32big(0xa96eac40U),
                   bswap_32big(0x3af7d0e8U));

    return RSIP_RET_PASS;
}
