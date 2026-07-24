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
        r_rsip_func100(bswap_32big(0xf00f3952U), bswap_32big(0x34f97b6aU), bswap_32big(0xb651db8eU),
                       bswap_32big(0xbd6b5879U));
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
            r_rsip_func100(bswap_32big(0xbf162a19U), bswap_32big(0x7be97167U), bswap_32big(0x98346a6eU),
                           bswap_32big(0x7e7993e8U));
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
                r_rsip_func101(bswap_32big(0x1c75069eU),
                               bswap_32big(0x14354662U),
                               bswap_32big(0x092696deU),
                               bswap_32big(0x183a7dfeU));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0xe66a71eeU));
                OFS_ADR = 676;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000621U));
                r_rsip_func101(bswap_32big(0x751535d2U),
                               bswap_32big(0xf1411f09U),
                               bswap_32big(0xb66a2a3bU),
                               bswap_32big(0xaa215df5U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000448U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0x1f3049e2U),
                               bswap_32big(0x16ae01eaU),
                               bswap_32big(0x51e32ce2U),
                               bswap_32big(0xb9f54d9eU));
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
                r_rsip_subfunc007(bswap_32big(0x1a2186a2U));
                OFS_ADR = 544;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000622U));
                r_rsip_func101(bswap_32big(0x10f119afU),
                               bswap_32big(0x7dc32215U),
                               bswap_32big(0x52422a2eU),
                               bswap_32big(0x65600a21U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000a90U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0xeda2f01cU),
                               bswap_32big(0x73c88a70U),
                               bswap_32big(0x0a6a98beU),
                               bswap_32big(0xc3d0711bU));
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
                r_rsip_func101(bswap_32big(0xf9d59ab2U),
                               bswap_32big(0x214f510dU),
                               bswap_32big(0x881a6de9U),
                               bswap_32big(0xfd950f21U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x954b41e6U), bswap_32big(0x9c2d2103U), bswap_32big(0x6fada37cU),
                           bswap_32big(0x264fb1d7U));
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
