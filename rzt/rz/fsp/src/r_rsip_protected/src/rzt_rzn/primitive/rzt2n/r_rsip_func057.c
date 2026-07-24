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
        r_rsip_func100(bswap_32big(0x844ff551U), bswap_32big(0x9be85624U), bswap_32big(0x4de3faddU),
                       bswap_32big(0x197eccceU));
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
            r_rsip_func100(bswap_32big(0x87b82c43U), bswap_32big(0xeb813cdeU), bswap_32big(0x0e4c9c3aU),
                           bswap_32big(0x7cfc23ecU));
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
                r_rsip_func101(bswap_32big(0x074d44caU),
                               bswap_32big(0xa166aaf4U),
                               bswap_32big(0xdbf4909fU),
                               bswap_32big(0x5fd4b469U));
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
                r_rsip_func101(bswap_32big(0x75ad9f8dU),
                               bswap_32big(0x882d9f18U),
                               bswap_32big(0xf8f7f642U),
                               bswap_32big(0xc15c204bU));
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
                r_rsip_subfunc007(bswap_32big(0xcf8e2cfeU));
                OFS_ADR = 224;
                r_rsip_subfunc008(0x1f180000U, 0x00000030U, bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0x96890710U),
                               bswap_32big(0x0a9635e7U),
                               bswap_32big(0x9f569bffU),
                               bswap_32big(0xc71326e4U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_subfunc003(0x00c000d1U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000838U, 0x1a1a0009U);
                r_rsip_subfunc009(bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0x48c0546dU),
                               bswap_32big(0xc0e4c2b8U),
                               bswap_32big(0x3b40dab4U),
                               bswap_32big(0x6d4a2b83U));
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
                r_rsip_func101(bswap_32big(0xfabca756U),
                               bswap_32big(0x73e81d0eU),
                               bswap_32big(0x7dff3ce7U),
                               bswap_32big(0x0c27fdc6U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0xa8c94219U), bswap_32big(0xf015b0f6U), bswap_32big(0x2e31f9a3U),
                           bswap_32big(0x09679e6bU));
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
