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
    r_rsip_func100(bswap_32big(0x40e31582U),
                   bswap_32big(0x8871bf30U),
                   bswap_32big(0xc6192a50U),
                   bswap_32big(0x0415b50dU));
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
        r_rsip_func101(bswap_32big(0x04ec0fbfU), bswap_32big(0x1aa8e878U), bswap_32big(0x5fb826e4U),
                       bswap_32big(0x3c83943dU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000040U);
        r_rsip_func101(bswap_32big(0x2c7d0acaU), bswap_32big(0x032aa38aU), bswap_32big(0xe4f7ad9aU),
                       bswap_32big(0x9c0f8044U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000050U);
        r_rsip_func101(bswap_32big(0x7a14feaeU), bswap_32big(0x919fba39U), bswap_32big(0x8d64780dU),
                       bswap_32big(0x3ac13899U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000080U);
        r_rsip_func101(bswap_32big(0xaacd6002U), bswap_32big(0x630eaf99U), bswap_32big(0x33a38b03U),
                       bswap_32big(0xcf662ac3U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00000090U);
        r_rsip_func101(bswap_32big(0x18d270c5U), bswap_32big(0xe3f15989U), bswap_32big(0x72de9e08U),
                       bswap_32big(0x7e9b7dc2U));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000a0U);
        r_rsip_func101(bswap_32big(0x2634afa7U), bswap_32big(0xb47e9a16U), bswap_32big(0xdc7ddf3dU),
                       bswap_32big(0x9f220d87U));
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000000b0U);
        r_rsip_func101(bswap_32big(0x4e3b9725U), bswap_32big(0x481676a9U), bswap_32big(0x0cde1bc7U),
                       bswap_32big(0xff0642d3U));
    }

    if ((InData_MsgLen[0] == 0) && (InData_MsgLen[1] == 0))
    {
        WR1_PROG(REG_200CH, 0x00000100U);
        r_rsip_func101(bswap_32big(0x7fd9d352U), bswap_32big(0x9892a07dU), bswap_32big(0xedc75d39U),
                       bswap_32big(0x637eba96U));
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2014H, &InData_MsgLen[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2010H, &InData_MsgLen[1]);
        r_rsip_func101(bswap_32big(0x3dad3b35U), bswap_32big(0x0f0efbf2U), bswap_32big(0x2b16119eU),
                       bswap_32big(0x667e6d8fU));
    }

    return RSIP_RET_PASS;
}
