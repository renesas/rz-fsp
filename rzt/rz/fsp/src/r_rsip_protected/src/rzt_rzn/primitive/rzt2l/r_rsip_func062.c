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

void r_rsip_func062 (void)
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
    WR1_PROG(REG_1600H, 0x0000379dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800db40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xaa6f4827U), bswap_32big(0x68694425U), bswap_32big(0x76e858ccU),
                       bswap_32big(0xec2315feU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x1a880000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1600H, 0x0000135bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3800db40U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0xe22ff2ebU), bswap_32big(0x1e3891d0U), bswap_32big(0x673ab5aaU),
                           bswap_32big(0x87acc0abU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x12380000U);
                r_rsip_subfunc003(0x00c00009U);
                WR1_PROG(REG_1404H, 0x18800000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000448U, 0x00000448U, 0x4141000cU);
                r_rsip_subfunc004(0x00000a90U, 0x00000a90U, 0x4141000cU);
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0x7760db22U),
                               bswap_32big(0xa9076797U),
                               bswap_32big(0xc722c37cU),
                               bswap_32big(0xc95c7ce3U));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0xe7a909b7U));
                OFS_ADR = 676;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000621U));
                r_rsip_func101(bswap_32big(0xa6ae26f7U),
                               bswap_32big(0xbcb97012U),
                               bswap_32big(0xc2a70da4U),
                               bswap_32big(0xc2b901d0U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000448U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0xfdd88d03U),
                               bswap_32big(0x0fbb25c3U),
                               bswap_32big(0x18d8e767U),
                               bswap_32big(0x9d3655a8U));
                r_rsip_func310();
                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000878U, 0x00000448U, 0x4141000cU);
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0x2a8c92d0U));
                OFS_ADR = 544;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000622U));
                r_rsip_func101(bswap_32big(0x4a858719U),
                               bswap_32big(0x5196a2f9U),
                               bswap_32big(0xaaf69ac5U),
                               bswap_32big(0x35115317U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000a90U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0x80565e34U),
                               bswap_32big(0xbe8d14bbU),
                               bswap_32big(0x3ed9b980U),
                               bswap_32big(0x4dbfef02U));
                r_rsip_func311();
                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000878U, 0x00000a90U, 0x4141000cU);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0x80394777U),
                               bswap_32big(0x7f6b954cU),
                               bswap_32big(0x5e64bc8cU),
                               bswap_32big(0x5b135b5fU));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x6ea14c6aU), bswap_32big(0xe91f3fabU), bswap_32big(0x26748102U),
                           bswap_32big(0xcb423fe8U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
