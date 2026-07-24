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

rsip_ret_t r_rsip_p70i (const uint32_t InData_HashType[], const uint32_t InData_MsgLen[])
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
    r_rsip_func100(bswap_32big(0x1a3526b5U),
                   bswap_32big(0xe8b0b790U),
                   bswap_32big(0xddcd9c3dU),
                   bswap_32big(0xae74450cU));
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
        WR1_PROG(REG_2004H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x134ade04U), bswap_32big(0x9c283f93U), bswap_32big(0x0fa268bcU),
                       bswap_32big(0x15f4fa5aU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000040U);
        r_rsip_func101(bswap_32big(0x77b1e402U), bswap_32big(0x08abded0U), bswap_32big(0x8c91fe56U),
                       bswap_32big(0x36ab153eU));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000050U);
        r_rsip_func101(bswap_32big(0xd23e11cfU), bswap_32big(0xa93b1fe3U), bswap_32big(0xd453337eU),
                       bswap_32big(0xdb3406e5U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000080U);
        r_rsip_func101(bswap_32big(0x0e57008aU), bswap_32big(0x423fa499U), bswap_32big(0x4eba56bfU),
                       bswap_32big(0x525ce729U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000090U);
        r_rsip_func101(bswap_32big(0xe3bfbc8eU), bswap_32big(0xd0724129U), bswap_32big(0x9acd4ac8U),
                       bswap_32big(0xd05c1bf1U));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000a0U);
        r_rsip_func101(bswap_32big(0x2422724cU), bswap_32big(0x3cf957d7U), bswap_32big(0xae0ccfa7U),
                       bswap_32big(0xad572aa5U));
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000b0U);
        r_rsip_func101(bswap_32big(0xcb7d0e9aU), bswap_32big(0x69259c8eU), bswap_32big(0xc3770ca5U),
                       bswap_32big(0xfb3148ccU));
    }

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);
        r_rsip_func101(bswap_32big(0x7bec0313U), bswap_32big(0x6c8e2e2dU), bswap_32big(0x8a131713U),
                       bswap_32big(0x92b8cb55U));
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2014H, &InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2010H, &InData_MsgLen[1]);
        r_rsip_func101(bswap_32big(0x2e51ce3cU), bswap_32big(0xf0fd1395U), bswap_32big(0x55b041c7U),
                       bswap_32big(0xc0be8ab3U));
    }

    return RSIP_RET_PASS;
}
