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
        r_rsip_func100(bswap_32big(0x21440ad9U), bswap_32big(0xcd4da50cU), bswap_32big(0x434f9597U),
                       bswap_32big(0xbd538334U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1818000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x014c9e56U), bswap_32big(0xdb7a5fbeU), bswap_32big(0x92f69711U),
                           bswap_32big(0xa8298cdaU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x51c144adU), bswap_32big(0xa8c12288U), bswap_32big(0x2fc56579U),
                           bswap_32big(0xf3a993adU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0x1056c9b1U));
    OFS_ADR = 56;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000561U));
    r_rsip_func101(bswap_32big(0x988f5e9cU),
                   bswap_32big(0x8331c526U),
                   bswap_32big(0xdb2a5e3bU),
                   bswap_32big(0x574497caU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x37e65606U));
    OFS_ADR = 112;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
    r_rsip_func101(bswap_32big(0x679d689aU),
                   bswap_32big(0xd4e38455U),
                   bswap_32big(0x4091c95fU),
                   bswap_32big(0x052ebd4dU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x2c299482U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000563U));
    r_rsip_func101(bswap_32big(0x2eefb7aaU),
                   bswap_32big(0x06405115U),
                   bswap_32big(0x2f8db43aU),
                   bswap_32big(0x5f775d83U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x4b181880U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
    r_rsip_func101(bswap_32big(0x0168926aU),
                   bswap_32big(0xde6a0829U),
                   bswap_32big(0x945108bcU),
                   bswap_32big(0xd7328ffdU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xa46a75f3U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x00000565U));
    r_rsip_func101(bswap_32big(0xb897c137U),
                   bswap_32big(0x2fafe1e9U),
                   bswap_32big(0x979397fdU),
                   bswap_32big(0x4f86c35fU));
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
        r_rsip_func100(bswap_32big(0xab92700aU), bswap_32big(0x8a70d89bU), bswap_32big(0x2e69f194U),
                       bswap_32big(0x8373fdd5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x4e82a257U), bswap_32big(0x78698b15U), bswap_32big(0xc7b77f0eU),
                           bswap_32big(0x9cc1ea11U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x2c299482U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0x8efa809cU), bswap_32big(0x94351302U), bswap_32big(0xb0ad03cdU),
                           bswap_32big(0x5853fe06U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x1056c9b1U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0xd9ebf671U), bswap_32big(0x6918cc4dU), bswap_32big(0xc36c602cU),
                           bswap_32big(0x72580f71U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0xed30b429U), bswap_32big(0x8ee3d74dU), bswap_32big(0x620fd0d4U),
                           bswap_32big(0x1b7e3662U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x2c299482U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000566U));
            r_rsip_func101(bswap_32big(0x43f3e6a0U), bswap_32big(0x76659ff3U), bswap_32big(0xe7f9debcU),
                           bswap_32big(0x88dd2d08U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x1056c9b1U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000567U));
            r_rsip_func101(bswap_32big(0xa75c5cc7U), bswap_32big(0x9c1d94bcU), bswap_32big(0x89a22e25U),
                           bswap_32big(0x39feb222U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x37e65606U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000563U));
            r_rsip_func101(bswap_32big(0x712fae40U), bswap_32big(0x3ae35735U), bswap_32big(0x32b11cacU),
                           bswap_32big(0xb3578f91U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x4b181880U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
            r_rsip_func101(bswap_32big(0x0e1636b2U), bswap_32big(0x2b9e4948U), bswap_32big(0xbfe30bb9U),
                           bswap_32big(0xc8ef9698U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc009(bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x66c81457U), bswap_32big(0x03628f52U), bswap_32big(0x57baf709U),
                           bswap_32big(0xea64e555U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x37e65606U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000568U));
            r_rsip_func101(bswap_32big(0x05370e97U), bswap_32big(0x575f1e7eU), bswap_32big(0x627f92a3U),
                           bswap_32big(0xbd9313f0U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x4b181880U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000569U));
            r_rsip_func101(bswap_32big(0xa20ce938U), bswap_32big(0xff85f3d5U), bswap_32big(0x30f21d16U),
                           bswap_32big(0x68069e91U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xac32c6ccU), bswap_32big(0x35db020cU), bswap_32big(0x9ff7aa96U),
                           bswap_32big(0xee8705d8U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc007(bswap_32big(0x2c299482U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000565U));
                r_rsip_func101(bswap_32big(0xb226389bU),
                               bswap_32big(0x11c219e2U),
                               bswap_32big(0x59967eabU),
                               bswap_32big(0x86579d8fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x37e65606U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000566U));
                r_rsip_func101(bswap_32big(0xe305b699U),
                               bswap_32big(0xb65f96dfU),
                               bswap_32big(0xf915e124U),
                               bswap_32big(0x06d8c645U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000561U));
                r_rsip_func101(bswap_32big(0x8f27fe91U),
                               bswap_32big(0x8db7b0adU),
                               bswap_32big(0x5cb54aa5U),
                               bswap_32big(0x5405bfc5U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x2c299482U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0x5d12afdfU),
                               bswap_32big(0xccf2820aU),
                               bswap_32big(0xd2b015bfU),
                               bswap_32big(0xf02a629aU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x1056c9b1U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000567U));
                r_rsip_func101(bswap_32big(0xf3309096U),
                               bswap_32big(0xea6d2a7eU),
                               bswap_32big(0xf462405aU),
                               bswap_32big(0x95278cc0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x4b181880U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000568U));
                r_rsip_func101(bswap_32big(0xca22f756U),
                               bswap_32big(0x75170743U),
                               bswap_32big(0x71edc964U),
                               bswap_32big(0xdfa83464U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000562U));
                r_rsip_func101(bswap_32big(0x5cecf04fU),
                               bswap_32big(0xea7e09a8U),
                               bswap_32big(0x226e1e3eU),
                               bswap_32big(0xffcc89ffU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x1056c9b1U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x09aadfbbU),
                               bswap_32big(0xec9bc84bU),
                               bswap_32big(0x9c275d36U),
                               bswap_32big(0x45f1663fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x6ca92c25U),
                               bswap_32big(0x00ea31c2U),
                               bswap_32big(0x8891687fU),
                               bswap_32big(0xf0131ce9U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);
                r_rsip_subfunc007(bswap_32big(0x37e65606U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xb9564761U),
                               bswap_32big(0x61b8d844U),
                               bswap_32big(0x9f2bc76bU),
                               bswap_32big(0x4d2b80e6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x2c299482U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x6115e617U),
                               bswap_32big(0x5565f79dU),
                               bswap_32big(0x8ed1a9f7U),
                               bswap_32big(0x7513df75U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000563U));
                r_rsip_func101(bswap_32big(0xbfca856dU),
                               bswap_32big(0xad39c79eU),
                               bswap_32big(0xc2cd7922U),
                               bswap_32big(0x785599caU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x37e65606U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x9ce29413U),
                               bswap_32big(0xad219bc2U),
                               bswap_32big(0xa30e9407U),
                               bswap_32big(0x6fb66b4dU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x4b181880U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0xde280aa9U),
                               bswap_32big(0x76b7a0afU),
                               bswap_32big(0x268f32d1U),
                               bswap_32big(0x2e5396f6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x1056c9b1U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x7066a3fbU),
                               bswap_32big(0x7379282fU),
                               bswap_32big(0x7efdf7d1U),
                               bswap_32big(0xd22f309dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000564U));
                r_rsip_func101(bswap_32big(0x373494bfU),
                               bswap_32big(0x9764de8cU),
                               bswap_32big(0x224c5765U),
                               bswap_32big(0xcb161a11U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x4b181880U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x329abb07U),
                               bswap_32big(0x4741f439U),
                               bswap_32big(0xed603938U),
                               bswap_32big(0x65ccdc34U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xa4b61cabU),
                               bswap_32big(0xc8fd9918U),
                               bswap_32big(0x6256668bU),
                               bswap_32big(0xc476e0abU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xa46a75f3U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x0000056eU));
    r_rsip_func101(bswap_32big(0x197c98b8U),
                   bswap_32big(0x4a5634d7U),
                   bswap_32big(0x69c0e510U),
                   bswap_32big(0x92664d9eU));
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
        r_rsip_func100(bswap_32big(0x59064eaaU), bswap_32big(0x7b0e1bb8U), bswap_32big(0x5e644cd9U),
                       bswap_32big(0x918b3821U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x21b9df82U), bswap_32big(0xd9a8e376U), bswap_32big(0x3b4e4389U),
                           bswap_32big(0xeb58faa9U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xaac4db39U), bswap_32big(0x9d7676f1U), bswap_32big(0xf12bbcdbU),
                           bswap_32big(0x8d5ae926U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x4b181880U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056fU));
    r_rsip_func101(bswap_32big(0xe95c063eU),
                   bswap_32big(0xba7cd0c2U),
                   bswap_32big(0xc2615714U),
                   bswap_32big(0x39f239e6U));
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
        r_rsip_func100(bswap_32big(0x77745ddcU), bswap_32big(0x4f25acdbU), bswap_32big(0xa9badf52U),
                       bswap_32big(0x5b16e884U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);
            r_rsip_func101(bswap_32big(0x7a803eb2U), bswap_32big(0x37975d0cU), bswap_32big(0x156d6e45U),
                           bswap_32big(0x0750cf2eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xd057a20bU), bswap_32big(0xb5606b4eU), bswap_32big(0x6cb5389bU),
                           bswap_32big(0x69beb19aU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x95f9556cU),
                   bswap_32big(0x9e553ffeU),
                   bswap_32big(0x78bf725eU),
                   bswap_32big(0xa7bd83c5U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);
        r_rsip_func101(bswap_32big(0x51c7631fU), bswap_32big(0x449f1a7dU), bswap_32big(0x5630120bU),
                       bswap_32big(0xe06f2475U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x98e3fa25U), bswap_32big(0x08e1668dU), bswap_32big(0x93e242baU),
                       bswap_32big(0xcd518e61U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
