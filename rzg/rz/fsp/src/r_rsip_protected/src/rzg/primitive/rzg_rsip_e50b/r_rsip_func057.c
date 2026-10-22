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

void r_rsip_func057 (void)
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
        r_rsip_func100(bswap_32big(0xe49c7b2dU), bswap_32big(0x72a69256U), bswap_32big(0xc9bc21f3U),
                       bswap_32big(0x194f0179U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
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
            r_rsip_func100(bswap_32big(0x598eb09fU), bswap_32big(0x3ef8e765U), bswap_32big(0x3b3922afU),
                           bswap_32big(0x8980794cU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x13580000U);
                r_rsip_subfunc003(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19700000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000428U, 0x00000428U, 0x1919000cU);
                r_rsip_subfunc004(0x00000a40U, 0x00000a40U, 0x1919000cU);
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0x73e54244U),
                               bswap_32big(0xb4829bd0U),
                               bswap_32big(0x73565a87U),
                               bswap_32big(0x02e66d8aU));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1f080000U);
                WR1_PROG(REG_1600H, 0x00000b7bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81b0001bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00011U);
                r_rsip_subfunc003(0x00c900c1U);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_subfunc003(0x00c000d1U);
                r_rsip_subfunc001(0x00000428U, 0x00000838U, 0x00000838U, 0x1a1a0009U);
                r_rsip_subfunc009(bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0xaeb70c7bU),
                               bswap_32big(0x47e1f48dU),
                               bswap_32big(0xb34464b4U),
                               bswap_32big(0x0af2510cU));
                r_rsip_func306();
                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000838U, 0x00000428U, 0x1919000cU);
                WR1_PROG(REG_1404H, 0x13580000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1f080000U);
                r_rsip_subfunc003(0x00c000d1U);
                r_rsip_subfunc007(bswap_32big(0xab7ce7b2U));
                OFS_ADR = 224;
                r_rsip_subfunc008(0x1f180000U, 0x00000030U, bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0x60185ee6U),
                               bswap_32big(0x2343fbe2U),
                               bswap_32big(0x5084a2f1U),
                               bswap_32big(0x447a3cc9U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_subfunc003(0x00c000d1U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000838U, 0x1a1a0009U);
                r_rsip_subfunc009(bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0x3f779aabU),
                               bswap_32big(0x494a3068U),
                               bswap_32big(0xeb555a93U),
                               bswap_32big(0xf89f8dd2U));
                r_rsip_func307();
                WR1_PROG(REG_1404H, 0x17680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000838U, 0x00000a40U, 0x1919000cU);
                WR1_PROG(REG_1404H, 0x19700000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0xeb376557U),
                               bswap_32big(0xecb4dbffU),
                               bswap_32big(0x550a95a5U),
                               bswap_32big(0xe045f994U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x0d912d05U), bswap_32big(0x6463dd79U), bswap_32big(0xae38948dU),
                           bswap_32big(0x40ccb2b9U));
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
