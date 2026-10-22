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

void r_rsip_func311 (void)
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
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    WR1_PROG(REG_1404H, 0x1dc80000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000dc0U, 0x4141000aU);
    WR1_PROG(REG_143CH, 0x00a10000U);
    r_rsip_func100(bswap_32big(0x30cbf05eU),
                   bswap_32big(0x18705cc1U),
                   bswap_32big(0xbdf046a7U),
                   bswap_32big(0xc8a4edc5U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xc8db0b8bU), bswap_32big(0x04be2d34U), bswap_32big(0xba599729U),
                       bswap_32big(0x2d05a4f9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xc9158014U), bswap_32big(0x2de60748U), bswap_32big(0xd964b119U),
                           bswap_32big(0xedd578d2U));
        }
        else
        {
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000878U, 0x41410009U);
            r_rsip_func101(bswap_32big(0xf02a3a79U), bswap_32big(0xb8aac3dbU), bswap_32big(0x4da0720aU),
                           bswap_32big(0x73fc7045U));
        }
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xab4aab89U), bswap_32big(0x05b88e7bU), bswap_32big(0x2e47ce9aU),
                       bswap_32big(0xa0b89270U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000fd8U, 0x00000878U, 0x00000878U, 0x4141000aU);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x7b2efe46U), bswap_32big(0xae0f121fU), bswap_32big(0x98ca8b39U),
                           bswap_32big(0x838439ccU));
        }
        else
        {
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000878U, 0x41410009U);
            r_rsip_func101(bswap_32big(0x1dcc6b2aU), bswap_32big(0x7a5483c5U), bswap_32big(0xdb31db7fU),
                           bswap_32big(0x238b7a01U));
        }
    }

    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c90005U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
