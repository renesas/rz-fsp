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

void r_rsip_func304 (void)
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
    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    WR1_PROG(REG_1404H, 0x1ec80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x2121000aU);
    WR1_PROG(REG_143CH, 0x00a10000U);
    r_rsip_func100(bswap_32big(0x336fff93U),
                   bswap_32big(0x2bac6baeU),
                   bswap_32big(0x696cd182U),
                   bswap_32big(0x5049f035U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xf0903a3cU), bswap_32big(0x7d65385bU), bswap_32big(0xbdd6693eU),
                       bswap_32big(0x45de7f7dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);
            r_rsip_func101(bswap_32big(0xd0baf97fU), bswap_32big(0xe72661d0U), bswap_32big(0xa71ee969U),
                           bswap_32big(0xd6040d57U));
        }
        else
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0x162f2e47U), bswap_32big(0x4a10d359U), bswap_32big(0xa4b7780cU),
                           bswap_32big(0x3897c87bU));
        }
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x930e67deU), bswap_32big(0x3d63b4f3U), bswap_32big(0x211e83f5U),
                       bswap_32big(0x885bd0d2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x21210009U);
            r_rsip_func101(bswap_32big(0x9a785c6eU), bswap_32big(0x54f6a30aU), bswap_32big(0x779e7bd0U),
                           bswap_32big(0x88edc1bbU));
        }
        else
        {
            r_rsip_subfunc001(0x00000fd8U, 0x00000838U, 0x00000838U, 0x2121000aU);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xcbfc8eceU), bswap_32big(0x6b1ae705U), bswap_32big(0x23a645f7U),
                           bswap_32big(0xaf4c1444U));
        }
    }

    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c90005U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
