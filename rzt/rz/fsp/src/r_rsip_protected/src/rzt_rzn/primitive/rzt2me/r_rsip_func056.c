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
        r_rsip_func100(bswap_32big(0x2e3fa324U), bswap_32big(0xdf8a9997U), bswap_32big(0xef33ef88U),
                       bswap_32big(0x490e048cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1818000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xf92e7ed1U), bswap_32big(0x2864a617U), bswap_32big(0x800f7b6bU),
                           bswap_32big(0x231be2bcU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x79809adaU), bswap_32big(0xbb8cafaeU), bswap_32big(0xa87fecf8U),
                           bswap_32big(0xbc095d39U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0xa277852fU));
    OFS_ADR = 56;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000561U));
    r_rsip_func101(bswap_32big(0x50ce222fU),
                   bswap_32big(0xfdc98f97U),
                   bswap_32big(0x1f59dbdcU),
                   bswap_32big(0x3d4154edU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x4db9e5b0U));
    OFS_ADR = 112;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
    r_rsip_func101(bswap_32big(0xf51dfd21U),
                   bswap_32big(0xef9434feU),
                   bswap_32big(0xfc92f799U),
                   bswap_32big(0x1b1dacf7U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xab580788U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000563U));
    r_rsip_func101(bswap_32big(0x133c611eU),
                   bswap_32big(0x40bd8578U),
                   bswap_32big(0xbb02b512U),
                   bswap_32big(0xf38c08f4U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc447d111U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
    r_rsip_func101(bswap_32big(0x1f7863a1U),
                   bswap_32big(0x44a5f922U),
                   bswap_32big(0x1e948f59U),
                   bswap_32big(0x79b2214eU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xf6428095U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x00000565U));
    r_rsip_func101(bswap_32big(0xcc15976fU),
                   bswap_32big(0x40250f85U),
                   bswap_32big(0x625dd659U),
                   bswap_32big(0x4bbd92c9U));
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
        r_rsip_func100(bswap_32big(0xb10430d3U), bswap_32big(0x21d39a0cU), bswap_32big(0x766e7869U),
                       bswap_32big(0xf3d64f04U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x9f68116bU), bswap_32big(0xcbe46916U), bswap_32big(0x79e595beU),
                           bswap_32big(0x09a4d7beU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xab580788U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0xd14abed0U), bswap_32big(0xa56051f7U), bswap_32big(0x2f08d18cU),
                           bswap_32big(0x5c279190U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa277852fU));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x7110c169U), bswap_32big(0xf265c0f3U), bswap_32big(0x7e02aa87U),
                           bswap_32big(0x835b6d23U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0x6fe4945eU), bswap_32big(0xb6797e61U), bswap_32big(0x2894079dU),
                           bswap_32big(0x5cf880b6U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0xab580788U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000566U));
            r_rsip_func101(bswap_32big(0x1a965df3U), bswap_32big(0xefa212b7U), bswap_32big(0xa7cab91aU),
                           bswap_32big(0x556f25dbU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa277852fU));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000567U));
            r_rsip_func101(bswap_32big(0x1f9ee460U), bswap_32big(0xbe4710dcU), bswap_32big(0x3f11f030U),
                           bswap_32big(0x61db3cd7U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x4db9e5b0U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000563U));
            r_rsip_func101(bswap_32big(0x7064ca92U), bswap_32big(0x20f096c8U), bswap_32big(0x835de534U),
                           bswap_32big(0xb2aed560U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc447d111U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
            r_rsip_func101(bswap_32big(0xcf7de344U), bswap_32big(0x4dc04e5bU), bswap_32big(0x3bdb9330U),
                           bswap_32big(0x63abb478U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc009(bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0xd5db8402U), bswap_32big(0x1b580330U), bswap_32big(0x401ba40bU),
                           bswap_32big(0x0977bec1U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x4db9e5b0U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000568U));
            r_rsip_func101(bswap_32big(0xc0f2e30fU), bswap_32big(0xe47b6e5cU), bswap_32big(0x45dae144U),
                           bswap_32big(0xd6b645d5U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc447d111U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000569U));
            r_rsip_func101(bswap_32big(0xfcd690e1U), bswap_32big(0xe9193095U), bswap_32big(0x9e064f04U),
                           bswap_32big(0x03977467U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x17e1c94fU), bswap_32big(0xf1ad5e78U), bswap_32big(0x8f57cce7U),
                           bswap_32big(0xda6ccfd0U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc007(bswap_32big(0xab580788U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000565U));
                r_rsip_func101(bswap_32big(0xaf51b38aU),
                               bswap_32big(0xdd490b7eU),
                               bswap_32big(0xa26bfe9fU),
                               bswap_32big(0x48becd86U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x4db9e5b0U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000566U));
                r_rsip_func101(bswap_32big(0x79357d61U),
                               bswap_32big(0xcd31088dU),
                               bswap_32big(0xc9f8ceeeU),
                               bswap_32big(0x39739809U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000561U));
                r_rsip_func101(bswap_32big(0x3ee1f808U),
                               bswap_32big(0xf3544678U),
                               bswap_32big(0x0394590eU),
                               bswap_32big(0x03fdffd4U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xab580788U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xb606d141U),
                               bswap_32big(0xc97f993dU),
                               bswap_32big(0x432a49ceU),
                               bswap_32big(0x2ae247a9U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa277852fU));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000567U));
                r_rsip_func101(bswap_32big(0x54c215f1U),
                               bswap_32big(0x98dbeadbU),
                               bswap_32big(0x8de1001dU),
                               bswap_32big(0x3b5d08b1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc447d111U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000568U));
                r_rsip_func101(bswap_32big(0x554e2949U),
                               bswap_32big(0x83dde5aaU),
                               bswap_32big(0xe22f3ce1U),
                               bswap_32big(0x880026f2U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000562U));
                r_rsip_func101(bswap_32big(0x9e715afcU),
                               bswap_32big(0x294216bbU),
                               bswap_32big(0xf9a2ae1bU),
                               bswap_32big(0x5bc935abU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xa277852fU));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x0412d364U),
                               bswap_32big(0x747643ccU),
                               bswap_32big(0x0426008cU),
                               bswap_32big(0xa6a3cb23U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x18d40c24U),
                               bswap_32big(0x89c039d2U),
                               bswap_32big(0x5d528e54U),
                               bswap_32big(0x1ca23c8dU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);
                r_rsip_subfunc007(bswap_32big(0x4db9e5b0U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0x1c6564a7U),
                               bswap_32big(0xaa87d96dU),
                               bswap_32big(0xa96e3d8aU),
                               bswap_32big(0x3c5f235bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xab580788U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x7a994ec2U),
                               bswap_32big(0x49abbbefU),
                               bswap_32big(0xfa765aeeU),
                               bswap_32big(0xdd32f848U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000563U));
                r_rsip_func101(bswap_32big(0xb262d141U),
                               bswap_32big(0xc0bac739U),
                               bswap_32big(0x87ffa53fU),
                               bswap_32big(0x1049de4cU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x4db9e5b0U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x1a4dc844U),
                               bswap_32big(0x0bd821e7U),
                               bswap_32big(0xfb6c6355U),
                               bswap_32big(0xe6e4ed64U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc447d111U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x43e84a58U),
                               bswap_32big(0x31212960U),
                               bswap_32big(0x93b230d5U),
                               bswap_32big(0x6af3f65aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa277852fU));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x5cacdd62U),
                               bswap_32big(0x62f3f7b8U),
                               bswap_32big(0x440b9c57U),
                               bswap_32big(0x4ae50dedU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000564U));
                r_rsip_func101(bswap_32big(0x680f8401U),
                               bswap_32big(0x70ac722dU),
                               bswap_32big(0x63ba86f6U),
                               bswap_32big(0x354c9ad5U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xc447d111U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x0731222bU),
                               bswap_32big(0x11ac74ceU),
                               bswap_32big(0xa3cd469aU),
                               bswap_32big(0x5d0dfb30U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xe3d874a7U),
                               bswap_32big(0x69d7d113U),
                               bswap_32big(0x9e77b543U),
                               bswap_32big(0x3a7edd5fU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xf6428095U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x0000056eU));
    r_rsip_func101(bswap_32big(0xdb57328aU),
                   bswap_32big(0x6c5e815bU),
                   bswap_32big(0xd2900d25U),
                   bswap_32big(0x78ae48ceU));
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
        r_rsip_func100(bswap_32big(0x57156b7fU), bswap_32big(0x673bcac4U), bswap_32big(0xf4622a7fU),
                       bswap_32big(0xa2790f2eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6c13b3a3U), bswap_32big(0x56b23013U), bswap_32big(0xd1d88d65U),
                           bswap_32big(0xdb15da10U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xe59440f6U), bswap_32big(0x1b572e55U), bswap_32big(0x7f273bcdU),
                           bswap_32big(0x318a7e0fU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xc447d111U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056fU));
    r_rsip_func101(bswap_32big(0x8c2078dfU),
                   bswap_32big(0x1662bbc8U),
                   bswap_32big(0x88228853U),
                   bswap_32big(0xf92c6de4U));
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
        r_rsip_func100(bswap_32big(0x6175e669U), bswap_32big(0xac0579bdU), bswap_32big(0x63495277U),
                       bswap_32big(0x74767b2aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);
            r_rsip_func101(bswap_32big(0x7e3d2eb7U), bswap_32big(0x7b764174U), bswap_32big(0x94d90d07U),
                           bswap_32big(0xe68213feU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x3cad7142U), bswap_32big(0x87f9415eU), bswap_32big(0x059eb791U),
                           bswap_32big(0xff8a976bU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x246da460U),
                   bswap_32big(0x37ada4caU),
                   bswap_32big(0x447728c3U),
                   bswap_32big(0xe03bc281U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);
        r_rsip_func101(bswap_32big(0xd1afb0edU), bswap_32big(0xef68e32fU), bswap_32big(0x3f56e8b6U),
                       bswap_32big(0xc31d6203U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xccbea907U), bswap_32big(0xfb277fa8U), bswap_32big(0xd9e09567U),
                       bswap_32big(0x41aa0649U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
