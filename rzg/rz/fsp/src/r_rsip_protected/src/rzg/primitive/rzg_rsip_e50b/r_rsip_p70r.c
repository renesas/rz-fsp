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
        WR1_PROG(REG_2004H, 0x00001000U);
        r_rsip_func101(bswap_32big(0x6ed58978U), bswap_32big(0x768052c9U), bswap_32big(0xe929c59dU),
                       bswap_32big(0xd23aee28U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001040U);
        r_rsip_func101(bswap_32big(0x3309f532U), bswap_32big(0x6a11bd93U), bswap_32big(0x134b6c99U),
                       bswap_32big(0x590bc424U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001050U);
        r_rsip_func101(bswap_32big(0xe30cb59fU), bswap_32big(0x616fb20eU), bswap_32big(0xeb1d7882U),
                       bswap_32big(0xe9095351U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001080U);
        r_rsip_func101(bswap_32big(0xc1d9c5d0U), bswap_32big(0x1610fde4U), bswap_32big(0xebcda638U),
                       bswap_32big(0x9c34b018U));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x00001090U);
        r_rsip_func101(bswap_32big(0xd202e23bU), bswap_32big(0x90cd2c2cU), bswap_32big(0x36f19f20U),
                       bswap_32big(0x6a5c07b4U));
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010a0U);
        r_rsip_func101(bswap_32big(0xa2150075U), bswap_32big(0x409f9c37U), bswap_32big(0xa8c1a9a1U),
                       bswap_32big(0x4db4989cU));
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_2004H, 0x000010b0U);
        r_rsip_func101(bswap_32big(0x64d68dc6U), bswap_32big(0xf3bc1847U), bswap_32big(0xd212f8d9U),
                       bswap_32big(0x134a95f6U));
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

    r_rsip_func101(bswap_32big(0xdd78d232U),
                   bswap_32big(0x07e58ec3U),
                   bswap_32big(0xe8bd94a7U),
                   bswap_32big(0x01819e6eU));

    return RSIP_RET_PASS;
}
