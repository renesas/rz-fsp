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

void r_rsip_func303 (void)
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
    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    WR1_PROG(REG_1404H, 0x1f480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000e50U, 0x1111000aU);
    WR1_PROG(REG_143CH, 0x00a10000U);
    r_rsip_func100(bswap_32big(0xbfd5a6f7U),
                   bswap_32big(0x63cf5a22U),
                   bswap_32big(0xbd8b39caU),
                   bswap_32big(0x1ddcd722U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xed3b8f93U), bswap_32big(0xecac2b8cU), bswap_32big(0x3c421251U),
                       bswap_32big(0x61b1ff68U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0xe8ac9e4aU), bswap_32big(0x38784f0dU), bswap_32big(0x9d25526cU),
                           bswap_32big(0x81f84df5U));
        }
        else
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);
            r_rsip_func101(bswap_32big(0xc0875fd0U), bswap_32big(0xb5cf5226U), bswap_32big(0x572d0232U),
                           bswap_32big(0x6ad812b6U));
        }
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x5ce402f7U), bswap_32big(0xcb49e426U), bswap_32big(0x83f6fef6U),
                       bswap_32big(0xf1f8ee3bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000fd8U, 0x00000838U, 0x00000838U, 0x1111000aU);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x8ea8fe4fU), bswap_32big(0x1282d947U), bswap_32big(0xb7d59e35U),
                           bswap_32big(0xfded909bU));
        }
        else
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x11110009U);
            r_rsip_func101(bswap_32big(0x6de24ba0U), bswap_32big(0x0974580eU), bswap_32big(0x6854459eU),
                           bswap_32big(0x8d602c58U));
        }
    }

    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c90005U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
