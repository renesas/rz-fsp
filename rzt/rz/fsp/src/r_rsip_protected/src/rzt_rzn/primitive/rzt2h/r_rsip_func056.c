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
        r_rsip_func100(bswap_32big(0xa70064bbU), bswap_32big(0xcc7e3222U), bswap_32big(0x1e1a5071U),
                       bswap_32big(0x3e1b60f3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1818000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xedb00708U), bswap_32big(0xe2d2349dU), bswap_32big(0x6e2ac310U),
                           bswap_32big(0xf32d60c4U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x7714d0e1U), bswap_32big(0x3925b801U), bswap_32big(0xa45fa879U),
                           bswap_32big(0x9f5bc803U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0x1f13418eU));
    OFS_ADR = 56;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000561U));
    r_rsip_func101(bswap_32big(0x831fa49dU),
                   bswap_32big(0x6396499fU),
                   bswap_32big(0x451a18bfU),
                   bswap_32big(0x321410e8U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0bae5bd9U));
    OFS_ADR = 112;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
    r_rsip_func101(bswap_32big(0x538d7ddeU),
                   bswap_32big(0xd552b4f8U),
                   bswap_32big(0xf4f72db7U),
                   bswap_32big(0xa9e74464U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x2edefaffU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000563U));
    r_rsip_func101(bswap_32big(0xb56341a7U),
                   bswap_32big(0x71c71326U),
                   bswap_32big(0x0fadbd92U),
                   bswap_32big(0x3a3194b0U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x48479262U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
    r_rsip_func101(bswap_32big(0x7db249e2U),
                   bswap_32big(0x5fd39123U),
                   bswap_32big(0x8a4b2bceU),
                   bswap_32big(0x6113082dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x262a6aa6U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x00000565U));
    r_rsip_func101(bswap_32big(0xbff36175U),
                   bswap_32big(0x6b4c8f0dU),
                   bswap_32big(0x885c40e6U),
                   bswap_32big(0x7792c03dU));
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
        r_rsip_func100(bswap_32big(0x18ff94c7U), bswap_32big(0x392f498bU), bswap_32big(0x42486229U),
                       bswap_32big(0x44696e09U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x577c99b9U), bswap_32big(0x394a1135U), bswap_32big(0x54777b01U),
                           bswap_32big(0xc33f38ffU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x2edefaffU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0xf86302e5U), bswap_32big(0xcdd8f6a2U), bswap_32big(0x4e3db81eU),
                           bswap_32big(0xd9fd179eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x1f13418eU));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x36552a97U), bswap_32big(0x3036b69aU), bswap_32big(0x4e1402b6U),
                           bswap_32big(0x657cf614U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0x2ddf9c20U), bswap_32big(0xf83ee383U), bswap_32big(0x0604d4afU),
                           bswap_32big(0xebd12decU));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x2edefaffU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000566U));
            r_rsip_func101(bswap_32big(0xd423947eU), bswap_32big(0xed1cc690U), bswap_32big(0x66aedec0U),
                           bswap_32big(0xb1012c7eU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x1f13418eU));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000567U));
            r_rsip_func101(bswap_32big(0xd1ec2d2fU), bswap_32big(0x3f69c1b9U), bswap_32big(0x7208b728U),
                           bswap_32big(0xbd97e626U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0bae5bd9U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000563U));
            r_rsip_func101(bswap_32big(0x47dc321bU), bswap_32big(0x8b9c6a51U), bswap_32big(0x2061b00aU),
                           bswap_32big(0x232cc254U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x48479262U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
            r_rsip_func101(bswap_32big(0x414b5a35U), bswap_32big(0x432206bfU), bswap_32big(0x1df6b3f1U),
                           bswap_32big(0x4175235dU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc009(bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x1e2770e4U), bswap_32big(0x079a7682U), bswap_32big(0xdee9ac99U),
                           bswap_32big(0xb30b34ceU));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x0bae5bd9U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000568U));
            r_rsip_func101(bswap_32big(0x3633b801U), bswap_32big(0x7f07bc1fU), bswap_32big(0xe08a5ef1U),
                           bswap_32big(0xf7868ae6U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x48479262U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000569U));
            r_rsip_func101(bswap_32big(0x2ecc5ad1U), bswap_32big(0x25f7c86cU), bswap_32big(0xf90960e9U),
                           bswap_32big(0x0c45ce36U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x9371c67fU), bswap_32big(0x1cee8c26U), bswap_32big(0x4724e844U),
                           bswap_32big(0xde216639U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc007(bswap_32big(0x2edefaffU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000565U));
                r_rsip_func101(bswap_32big(0x00c1dd0fU),
                               bswap_32big(0x2f857cf7U),
                               bswap_32big(0x2d156812U),
                               bswap_32big(0xd4a08469U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0bae5bd9U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000566U));
                r_rsip_func101(bswap_32big(0x2e04f51aU),
                               bswap_32big(0x253e8b70U),
                               bswap_32big(0x27cad41fU),
                               bswap_32big(0xa4a90550U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000561U));
                r_rsip_func101(bswap_32big(0x1ae1fed4U),
                               bswap_32big(0xd08cd259U),
                               bswap_32big(0x1c28c9f3U),
                               bswap_32big(0x260f3023U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x2edefaffU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xb5106612U),
                               bswap_32big(0x6f21a2dfU),
                               bswap_32big(0xe51f8d4eU),
                               bswap_32big(0xdf1d4420U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x1f13418eU));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000567U));
                r_rsip_func101(bswap_32big(0x9c8c2cdfU),
                               bswap_32big(0x5e53c69fU),
                               bswap_32big(0x6312da5fU),
                               bswap_32big(0x4cb4bd2eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x48479262U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000568U));
                r_rsip_func101(bswap_32big(0xefc363e3U),
                               bswap_32big(0x11b8a53cU),
                               bswap_32big(0x0548c8fcU),
                               bswap_32big(0x7fbd6724U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000562U));
                r_rsip_func101(bswap_32big(0xa177b529U),
                               bswap_32big(0x31cc913aU),
                               bswap_32big(0xd86bf990U),
                               bswap_32big(0xec8d30d9U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x1f13418eU));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x12da939aU),
                               bswap_32big(0x80702fe9U),
                               bswap_32big(0x6a741a36U),
                               bswap_32big(0xb272cba0U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x0234df39U),
                               bswap_32big(0x746bf5aeU),
                               bswap_32big(0xc1489d53U),
                               bswap_32big(0x0b11d66fU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);
                r_rsip_subfunc007(bswap_32big(0x0bae5bd9U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xf765c433U),
                               bswap_32big(0xcda456d4U),
                               bswap_32big(0xa2aff982U),
                               bswap_32big(0x8ff095f8U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x2edefaffU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x1c6ec422U),
                               bswap_32big(0x01469214U),
                               bswap_32big(0xc64e48bcU),
                               bswap_32big(0x18226563U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000563U));
                r_rsip_func101(bswap_32big(0x5c2b7cc1U),
                               bswap_32big(0xe6bc4603U),
                               bswap_32big(0x05ae72f4U),
                               bswap_32big(0x3788fba0U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x0bae5bd9U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x68413861U),
                               bswap_32big(0xbc57bfe4U),
                               bswap_32big(0x829b23f0U),
                               bswap_32big(0x1e3382c6U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x48479262U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x93f5579eU),
                               bswap_32big(0xb70e914bU),
                               bswap_32big(0xb07de8f7U),
                               bswap_32big(0x3dd7719aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x1f13418eU));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x49611ef1U),
                               bswap_32big(0x00dda030U),
                               bswap_32big(0x6de9693cU),
                               bswap_32big(0x6ebfd91dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000564U));
                r_rsip_func101(bswap_32big(0x6f4f1768U),
                               bswap_32big(0xbd13a692U),
                               bswap_32big(0x7c8553e6U),
                               bswap_32big(0xc3470de2U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x48479262U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x1935242fU),
                               bswap_32big(0xff5a69d8U),
                               bswap_32big(0x2113e311U),
                               bswap_32big(0x4689c829U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x328d4b57U),
                               bswap_32big(0xc6009e73U),
                               bswap_32big(0x073e6778U),
                               bswap_32big(0x8771c0f2U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x262a6aa6U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x0000056eU));
    r_rsip_func101(bswap_32big(0x53d90fc6U),
                   bswap_32big(0x2edeca6bU),
                   bswap_32big(0xf0372d11U),
                   bswap_32big(0x69f96c2eU));
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
        r_rsip_func100(bswap_32big(0x1fecfaf3U), bswap_32big(0xa5b12382U), bswap_32big(0x837acf37U),
                       bswap_32big(0x18d94dbdU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x443eae58U), bswap_32big(0x894e5bc8U), bswap_32big(0xb9bf1cdcU),
                           bswap_32big(0xbee6a58aU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xdae2956fU), bswap_32big(0xfdd57084U), bswap_32big(0x19fbaf77U),
                           bswap_32big(0x553a2d5eU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x48479262U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056fU));
    r_rsip_func101(bswap_32big(0xa3cd47fbU),
                   bswap_32big(0xf283d088U),
                   bswap_32big(0x23b50344U),
                   bswap_32big(0x24ab60d8U));
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
        r_rsip_func100(bswap_32big(0xf332f7c4U), bswap_32big(0xcff712e1U), bswap_32big(0x331327f0U),
                       bswap_32big(0x2cc2eb4dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);
            r_rsip_func101(bswap_32big(0xfc1b2175U), bswap_32big(0x30a94b46U), bswap_32big(0x6609cfb1U),
                           bswap_32big(0xcf273939U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xda807812U), bswap_32big(0x2c1e646aU), bswap_32big(0xf2359cd8U),
                           bswap_32big(0x63882da0U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xfe545300U),
                   bswap_32big(0xc1667c61U),
                   bswap_32big(0x5229557eU),
                   bswap_32big(0x7d9fac54U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);
        r_rsip_func101(bswap_32big(0x708a24a8U), bswap_32big(0x551d61dcU), bswap_32big(0x0f4c272cU),
                       bswap_32big(0x772c076eU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xf5b9c2a5U), bswap_32big(0x52b018b7U), bswap_32big(0x6a7d766eU),
                       bswap_32big(0xd17c33c7U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
