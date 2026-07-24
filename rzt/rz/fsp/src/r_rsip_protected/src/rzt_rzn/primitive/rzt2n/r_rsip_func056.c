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

void r_rsip_func056 (void)
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
    WR1_PROG(REG_1600H, 0x0000373dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1404H, 0x16280000U);
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
        r_rsip_func100(bswap_32big(0x372fc385U), bswap_32big(0x2ee3395fU), bswap_32big(0x7e5ace04U),
                       bswap_32big(0x75c2f598U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1818000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x13316ca6U), bswap_32big(0x7a70821eU), bswap_32big(0x9e504bd0U),
                           bswap_32big(0x9005e200U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xe0a4e8b2U), bswap_32big(0xa1d3becfU), bswap_32big(0x6b7afc04U),
                           bswap_32big(0xb38e95f3U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0x9940ee19U));
    OFS_ADR = 56;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000561U));
    r_rsip_func101(bswap_32big(0x289d7ecaU),
                   bswap_32big(0xb020dfddU),
                   bswap_32big(0x62ed54e5U),
                   bswap_32big(0xbdb3ad0aU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x7b40eaa0U));
    OFS_ADR = 112;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
    r_rsip_func101(bswap_32big(0x5bb3110bU),
                   bswap_32big(0xdc6578edU),
                   bswap_32big(0x13ca5722U),
                   bswap_32big(0x0058e38bU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x6b759de3U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000563U));
    r_rsip_func101(bswap_32big(0x92af10f1U),
                   bswap_32big(0xffde18b5U),
                   bswap_32big(0x68e1fff4U),
                   bswap_32big(0x8bdf3570U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
    r_rsip_func101(bswap_32big(0xc40c5776U),
                   bswap_32big(0x31ce1085U),
                   bswap_32big(0xad32db43U),
                   bswap_32big(0x883a866dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xcf8e2cfeU));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x00000565U));
    r_rsip_func101(bswap_32big(0x15017d31U),
                   bswap_32big(0x94223426U),
                   bswap_32big(0xe6553b3bU),
                   bswap_32big(0x83017725U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15700000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80b0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x034300c1U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19800000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c000bdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1818000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x3af29650U), bswap_32big(0x9841e963U), bswap_32big(0xce2a1cd6U),
                       bswap_32big(0xbb49a0f2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x3745e0a5U), bswap_32big(0x3ca2be01U), bswap_32big(0x84679507U),
                           bswap_32big(0xac2f0ccfU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x6b759de3U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0x2446a49eU), bswap_32big(0x930beff1U), bswap_32big(0xd6f83003U),
                           bswap_32big(0x0b219376U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9940ee19U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x96d1e8feU), bswap_32big(0xa60d84adU), bswap_32big(0x7b31a03fU),
                           bswap_32big(0xedadc622U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0x43a21122U), bswap_32big(0x261226d7U), bswap_32big(0x63a63c0fU),
                           bswap_32big(0x51369b19U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x6b759de3U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000566U));
            r_rsip_func101(bswap_32big(0x4ee958f7U), bswap_32big(0x6b610d07U), bswap_32big(0x2582c660U),
                           bswap_32big(0xb2a7163fU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9940ee19U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000567U));
            r_rsip_func101(bswap_32big(0x6e3bb1b1U), bswap_32big(0xe7f15a5aU), bswap_32big(0x374503b8U),
                           bswap_32big(0xcbb70cedU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x7b40eaa0U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000563U));
            r_rsip_func101(bswap_32big(0xea43a5f0U), bswap_32big(0x4dc4f831U), bswap_32big(0x3af43382U),
                           bswap_32big(0x2797613eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
            r_rsip_func101(bswap_32big(0x8581ac3eU), bswap_32big(0x923df2f2U), bswap_32big(0x2089b113U),
                           bswap_32big(0x604daf62U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc009(bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0xfeb6341bU), bswap_32big(0x3fc7cacdU), bswap_32big(0x05458e09U),
                           bswap_32big(0xcf55a3b4U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x7b40eaa0U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000568U));
            r_rsip_func101(bswap_32big(0xbf3f989dU), bswap_32big(0x17579e10U), bswap_32big(0x1d27ee51U),
                           bswap_32big(0x9f1fcbaaU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000569U));
            r_rsip_func101(bswap_32big(0x73ff9e7dU), bswap_32big(0x4c4a1a59U), bswap_32big(0xe2422ba2U),
                           bswap_32big(0xb25a0655U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x25d4675fU), bswap_32big(0x29b114a1U), bswap_32big(0xa3fb9dbdU),
                           bswap_32big(0xaefe842aU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc007(bswap_32big(0x6b759de3U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000565U));
                r_rsip_func101(bswap_32big(0xd67ac295U),
                               bswap_32big(0xdf888ebeU),
                               bswap_32big(0x6cdc38dfU),
                               bswap_32big(0xb501ebaaU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x7b40eaa0U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000566U));
                r_rsip_func101(bswap_32big(0x2e1181d2U),
                               bswap_32big(0xf08ec84aU),
                               bswap_32big(0xdfbbd728U),
                               bswap_32big(0xc9966123U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000561U));
                r_rsip_func101(bswap_32big(0x787e4878U),
                               bswap_32big(0xd4314ba5U),
                               bswap_32big(0x601d8e3aU),
                               bswap_32big(0xd2098e53U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x6b759de3U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0x4931339fU),
                               bswap_32big(0xdb7a49e1U),
                               bswap_32big(0x0d0c5032U),
                               bswap_32big(0x2f72830dU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9940ee19U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000567U));
                r_rsip_func101(bswap_32big(0xd10ff6a0U),
                               bswap_32big(0x2c1eb251U),
                               bswap_32big(0xd703e24eU),
                               bswap_32big(0x56a196b5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000568U));
                r_rsip_func101(bswap_32big(0x97be82dbU),
                               bswap_32big(0x6f6a01ecU),
                               bswap_32big(0x9816746eU),
                               bswap_32big(0xaaa493edU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000562U));
                r_rsip_func101(bswap_32big(0x70b72ba3U),
                               bswap_32big(0x74fd250fU),
                               bswap_32big(0x8be3692aU),
                               bswap_32big(0xb0422049U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x9940ee19U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0xaec8a101U),
                               bswap_32big(0x2a4f534fU),
                               bswap_32big(0x0db703c7U),
                               bswap_32big(0x2ac3a861U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x6d4211edU),
                               bswap_32big(0x5be0ba6cU),
                               bswap_32big(0x5e2877f5U),
                               bswap_32big(0x95396d4dU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);
                r_rsip_subfunc007(bswap_32big(0x7b40eaa0U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xcd2f4b7bU),
                               bswap_32big(0xa910167dU),
                               bswap_32big(0xe883447fU),
                               bswap_32big(0xd806582cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x6b759de3U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0xea35c28aU),
                               bswap_32big(0x09a6469bU),
                               bswap_32big(0x0a041797U),
                               bswap_32big(0x7fa308c5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000563U));
                r_rsip_func101(bswap_32big(0xcde52df0U),
                               bswap_32big(0xe57a499bU),
                               bswap_32big(0x31482a08U),
                               bswap_32big(0x14486506U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x7b40eaa0U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0xc4b001a3U),
                               bswap_32big(0xbd9a04b2U),
                               bswap_32big(0x69f9cd2bU),
                               bswap_32big(0x0bed76d6U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x815ed330U),
                               bswap_32big(0x3d7a008eU),
                               bswap_32big(0x94dc3291U),
                               bswap_32big(0xbe72109dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9940ee19U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0xff3c5d04U),
                               bswap_32big(0x64c10057U),
                               bswap_32big(0xa770512fU),
                               bswap_32big(0x29ec9bc9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000564U));
                r_rsip_func101(bswap_32big(0x06825732U),
                               bswap_32big(0x297d8842U),
                               bswap_32big(0x129cd603U),
                               bswap_32big(0x62ba0793U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x36f5345dU),
                               bswap_32big(0x301dda06U),
                               bswap_32big(0x0fea81c7U),
                               bswap_32big(0x98549e8bU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x24bfabcaU),
                               bswap_32big(0x715a7d4fU),
                               bswap_32big(0x9c64feacU),
                               bswap_32big(0xcd0a91eeU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xcf8e2cfeU));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x0000056eU));
    r_rsip_func101(bswap_32big(0x1975e8ecU),
                   bswap_32big(0xb09bfd55U),
                   bswap_32big(0x08409daeU),
                   bswap_32big(0x3012f9a9U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xd3403ea2U), bswap_32big(0x9fb5c333U), bswap_32big(0xca08f70cU),
                       bswap_32big(0x4d7724ffU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x31281f6fU), bswap_32big(0xe574b665U), bswap_32big(0xd4035d12U),
                           bswap_32big(0xb92b5547U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x3d01d038U), bswap_32big(0xe981ca05U), bswap_32big(0xc0c8dbc0U),
                           bswap_32big(0x6dedb739U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x7aa0c9edU));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056fU));
    r_rsip_func101(bswap_32big(0x5dff5882U),
                   bswap_32big(0x4da0bf90U),
                   bswap_32big(0xc9a5e79eU),
                   bswap_32big(0xee86adc9U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x1919000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xb9840fb5U), bswap_32big(0xe1d0545dU), bswap_32big(0x7b7fc148U),
                       bswap_32big(0x4c5c47f2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);
            r_rsip_func101(bswap_32big(0xf5e7fc38U), bswap_32big(0xbddb4a6eU), bswap_32big(0x5894be07U),
                           bswap_32big(0xad7fe437U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x1295b361U), bswap_32big(0xd54df63fU), bswap_32big(0x89592141U),
                           bswap_32big(0x81b35651U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x34fe0038U),
                   bswap_32big(0x9a05ec8fU),
                   bswap_32big(0x755eed47U),
                   bswap_32big(0x25fee186U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);
        r_rsip_func101(bswap_32big(0xf8701e6fU), bswap_32big(0x48159ef2U), bswap_32big(0x291fe097U),
                       bswap_32big(0x9fd5765dU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xbbdd73e7U), bswap_32big(0x3d360f82U), bswap_32big(0x4993076aU),
                       bswap_32big(0x061222d3U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
