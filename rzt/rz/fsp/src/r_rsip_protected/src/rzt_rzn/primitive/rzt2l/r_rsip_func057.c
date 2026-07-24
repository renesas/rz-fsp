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
        r_rsip_func100(bswap_32big(0x1aea3102U), bswap_32big(0x8daadd1eU), bswap_32big(0x6cbfcf18U),
                       bswap_32big(0x23d88eedU));
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
            r_rsip_func100(bswap_32big(0x61d398e4U), bswap_32big(0x78f6b014U), bswap_32big(0x0a8f4b11U),
                           bswap_32big(0x4402f939U));
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
                r_rsip_func101(bswap_32big(0x3144353cU),
                               bswap_32big(0xb2cf64f2U),
                               bswap_32big(0xc2f63facU),
                               bswap_32big(0x8ec7280cU));
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
                r_rsip_func101(bswap_32big(0x8bd91b4cU),
                               bswap_32big(0xbd5c8215U),
                               bswap_32big(0x7a4f9be7U),
                               bswap_32big(0xc574f57aU));
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
                r_rsip_subfunc007(bswap_32big(0xa46a75f3U));
                OFS_ADR = 224;
                r_rsip_subfunc008(0x1f180000U, 0x00000030U, bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0xbf3ba5d6U),
                               bswap_32big(0x8c66d494U),
                               bswap_32big(0x3a5e9489U),
                               bswap_32big(0xd7f464abU));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x17680000U);
                r_rsip_subfunc003(0x00c000d1U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000838U, 0x1a1a0009U);
                r_rsip_subfunc009(bswap_32big(0x0000f057U));
                r_rsip_func101(bswap_32big(0x15710981U),
                               bswap_32big(0xdda65e92U),
                               bswap_32big(0xd77befa2U),
                               bswap_32big(0x021e1920U));
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
                r_rsip_func101(bswap_32big(0xbeb7ae82U),
                               bswap_32big(0xefdea7e0U),
                               bswap_32big(0x0d826451U),
                               bswap_32big(0xbc89d300U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x90641bcbU), bswap_32big(0xae60811cU), bswap_32big(0xd54efea8U),
                           bswap_32big(0x7039ea28U));
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
