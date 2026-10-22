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

void r_rsip_func301 (void)
{
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
    WR1_PROG(REG_1404H, 0x17e80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    WR1_PROG(REG_1404H, 0x1f880000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x0909000aU);
    WR1_PROG(REG_143CH, 0x00a10000U);
    r_rsip_func100(bswap_32big(0x8941b1f6U),
                   bswap_32big(0xf1923204U),
                   bswap_32big(0x643dea5aU),
                   bswap_32big(0x706ae2c9U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x6c5b021cU), bswap_32big(0x3b142a06U), bswap_32big(0x06f3c7f7U),
                       bswap_32big(0x2c8075ebU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0xdfeacc41U), bswap_32big(0xcbfa536bU), bswap_32big(0xaa07b3caU),
                           bswap_32big(0x80ec2340U));
        }
        else
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x09090009U);
            r_rsip_func101(bswap_32big(0x201e86d9U), bswap_32big(0x687794b3U), bswap_32big(0x8b561a75U),
                           bswap_32big(0xdb422c5cU));
        }
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x51acd5daU), bswap_32big(0x5ef79d3fU), bswap_32big(0xdebfb881U),
                       bswap_32big(0x6b18d524U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000fd8U, 0x00000838U, 0x00000838U, 0x0909000aU);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6d49f738U), bswap_32big(0xb3fef8efU), bswap_32big(0x729d0241U),
                           bswap_32big(0xc3dbf1bbU));
        }
        else
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x09090009U);
            r_rsip_func101(bswap_32big(0x97b29d6cU), bswap_32big(0xbe1d6b1cU), bswap_32big(0xcfea3622U),
                           bswap_32big(0x8f0d4d30U));
        }
    }

    WR1_PROG(REG_1404H, 0x17e80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c90005U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
