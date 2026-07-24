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
    r_rsip_func100(bswap_32big(0xade13e4fU),
                   bswap_32big(0xa52eadd8U),
                   bswap_32big(0xde8a349bU),
                   bswap_32big(0x519a9680U));
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
        r_rsip_func101(bswap_32big(0x8f741507U), bswap_32big(0xc369944eU), bswap_32big(0xe7c2f042U),
                       bswap_32big(0x73c19210U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001040U);
        r_rsip_func101(bswap_32big(0x2b7e295bU), bswap_32big(0xfe20c80fU), bswap_32big(0x5c086f50U),
                       bswap_32big(0x09f99dc7U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001050U);
        r_rsip_func101(bswap_32big(0x71c76ddbU), bswap_32big(0x4600d98aU), bswap_32big(0x597db4c1U),
                       bswap_32big(0x250276b7U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001080U);
        r_rsip_func101(bswap_32big(0x34a7e2e9U), bswap_32big(0xa40f445cU), bswap_32big(0x5d8947dbU),
                       bswap_32big(0xf8136cc3U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001090U);
        r_rsip_func101(bswap_32big(0x5729e5c6U), bswap_32big(0xfe21b0daU), bswap_32big(0x391c0588U),
                       bswap_32big(0x3a932fbcU));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010a0U);
        r_rsip_func101(bswap_32big(0x4751fd09U), bswap_32big(0xfabc4184U), bswap_32big(0xbda8fb53U),
                       bswap_32big(0x104a6244U));
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010b0U);
        r_rsip_func101(bswap_32big(0x79e9e794U), bswap_32big(0x06396e47U), bswap_32big(0x3af2ea1fU),
                       bswap_32big(0x3093055fU));
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

    r_rsip_func101(bswap_32big(0x19909f62U),
                   bswap_32big(0xb2b291b5U),
                   bswap_32big(0x605f2679U),
                   bswap_32big(0xca2eaafcU));

    return RSIP_RET_PASS;
}
