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

void r_rsip_func051 (void)
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
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800db40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x97adb886U), bswap_32big(0x5a9eb7beU), bswap_32big(0x2124597cU),
                       bswap_32big(0x9ea4f6b8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x1a380000U);
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
            r_rsip_func100(bswap_32big(0xa766773bU), bswap_32big(0xebbafeaeU), bswap_32big(0x7a68a185U),
                           bswap_32big(0xbf1448b4U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x13d80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x19f00000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x13d80000U);
                r_rsip_subfunc003(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19f00000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000428U, 0x00000428U, 0x0909000cU);
                r_rsip_subfunc004(0x00000a40U, 0x00000a40U, 0x0909000cU);
                WR1_PROG(REG_1404H, 0x13d80000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x19f00000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0x41679ab1U),
                               bswap_32big(0x7a3c6478U),
                               bswap_32big(0xf447dcfeU),
                               bswap_32big(0x420ceeefU));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1f880000U);
                WR1_PROG(REG_1600H, 0x00000b7bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x8190001bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00011U);
                r_rsip_subfunc003(0x00c90041U);
                WR1_PROG(REG_1404H, 0x17e80000U);
                r_rsip_subfunc003(0x00c00051U);
                r_rsip_subfunc001(0x00000428U, 0x00000838U, 0x00000838U, 0x0a0a0009U);
                r_rsip_subfunc009(bswap_32big(0x0000f051U));
                r_rsip_func101(bswap_32big(0x3ce65ae6U),
                               bswap_32big(0xcf64fb3cU),
                               bswap_32big(0x58c632a9U),
                               bswap_32big(0xebee7a64U));
                r_rsip_func300();
                WR1_PROG(REG_1404H, 0x17e80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x17e80000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000838U, 0x00000428U, 0x0909000cU);
                WR1_PROG(REG_1404H, 0x13d80000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1f880000U);
                r_rsip_subfunc003(0x00c00051U);
                r_rsip_subfunc007(bswap_32big(0x16ba58cdU));
                OFS_ADR = 96;
                r_rsip_subfunc008(0x1f980000U, 0x00000010U, bswap_32big(0x0000f051U));
                r_rsip_func101(bswap_32big(0x3d01d37eU),
                               bswap_32big(0x1e454b0bU),
                               bswap_32big(0x06ad2abcU),
                               bswap_32big(0xdc14920cU));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x17e80000U);
                r_rsip_subfunc003(0x00c00051U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000838U, 0x0a0a0009U);
                r_rsip_subfunc009(bswap_32big(0x0000f051U));
                r_rsip_func101(bswap_32big(0x452b3255U),
                               bswap_32big(0x5f96455eU),
                               bswap_32big(0x47c2af20U),
                               bswap_32big(0xf0f61b58U));
                r_rsip_func301();
                WR1_PROG(REG_1404H, 0x17e80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x17e80000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000838U, 0x00000a40U, 0x0909000cU);
                WR1_PROG(REG_1404H, 0x19f00000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0x48c1565eU),
                               bswap_32big(0x7678be68U),
                               bswap_32big(0xb98ce79fU),
                               bswap_32big(0x45fa5149U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x1d3e90e4U), bswap_32big(0x1768d8daU), bswap_32big(0xf1d27dfaU),
                           bswap_32big(0xab07dbc1U));
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
