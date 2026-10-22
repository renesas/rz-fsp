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
        r_rsip_func100(bswap_32big(0xa57cb596U), bswap_32big(0x8b71e971U), bswap_32big(0xdcc9c827U),
                       bswap_32big(0x876a9ad2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1818000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc7dea591U), bswap_32big(0x20bc2257U), bswap_32big(0x992482b5U),
                           bswap_32big(0x93ce2e6bU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x6284bc20U), bswap_32big(0xe53b9ea3U), bswap_32big(0xb874bb0cU),
                           bswap_32big(0xb28659a5U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0x5c7fc321U));
    OFS_ADR = 56;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000561U));
    r_rsip_func101(bswap_32big(0x9690e942U),
                   bswap_32big(0x2f957122U),
                   bswap_32big(0xa7298fc7U),
                   bswap_32big(0x8643d044U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x8ddda849U));
    OFS_ADR = 112;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
    r_rsip_func101(bswap_32big(0x300fb70eU),
                   bswap_32big(0x37e6beefU),
                   bswap_32big(0x0f1e25e6U),
                   bswap_32big(0x78351c82U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x24016c13U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000563U));
    r_rsip_func101(bswap_32big(0x39b7e7d5U),
                   bswap_32big(0x35118d24U),
                   bswap_32big(0x55983da3U),
                   bswap_32big(0x5b8ae57aU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
    r_rsip_func101(bswap_32big(0x9b1908b1U),
                   bswap_32big(0x991d1b42U),
                   bswap_32big(0xb51bbacbU),
                   bswap_32big(0x6d98c5a6U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xab7ce7b2U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x00000565U));
    r_rsip_func101(bswap_32big(0x014574b7U),
                   bswap_32big(0xb33b5238U),
                   bswap_32big(0x5f2dc20eU),
                   bswap_32big(0x5ef311a5U));
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
        r_rsip_func100(bswap_32big(0xa97d263dU), bswap_32big(0xd5a90849U), bswap_32big(0x7e34ebdbU),
                       bswap_32big(0x1ded3410U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xdfe0595bU), bswap_32big(0xe541ed45U), bswap_32big(0x24b93b73U),
                           bswap_32big(0x57ce5be3U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x24016c13U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0xa1aeec11U), bswap_32big(0x98ff66bcU), bswap_32big(0xbee54e75U),
                           bswap_32big(0x75d0e869U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5c7fc321U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x7bd6333fU), bswap_32big(0x860522f8U), bswap_32big(0x2e345b4dU),
                           bswap_32big(0xc3f590b1U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0xe48e63beU), bswap_32big(0x5779f091U), bswap_32big(0x359cea38U),
                           bswap_32big(0xe10ce477U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x24016c13U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000566U));
            r_rsip_func101(bswap_32big(0xb15ecfeaU), bswap_32big(0x0520167cU), bswap_32big(0x38807af9U),
                           bswap_32big(0x44146c19U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5c7fc321U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000567U));
            r_rsip_func101(bswap_32big(0x0b7b0c1bU), bswap_32big(0x6dd0da0cU), bswap_32big(0x4a87a80fU),
                           bswap_32big(0x62aad1b0U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x8ddda849U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000563U));
            r_rsip_func101(bswap_32big(0xe745dbd7U), bswap_32big(0x0a6a5006U), bswap_32big(0x128410e3U),
                           bswap_32big(0x2ee00003U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
            r_rsip_func101(bswap_32big(0xa213f3f3U), bswap_32big(0x8754a79cU), bswap_32big(0x70167ecfU),
                           bswap_32big(0x126c2e79U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc009(bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0xa5fffbedU), bswap_32big(0x4f9386f1U), bswap_32big(0xc05ee163U),
                           bswap_32big(0xc5892079U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x8ddda849U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000568U));
            r_rsip_func101(bswap_32big(0x9c27979eU), bswap_32big(0x7f5c05f6U), bswap_32big(0x808fc083U),
                           bswap_32big(0x6ea97ebaU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000569U));
            r_rsip_func101(bswap_32big(0x7830a86bU), bswap_32big(0x73e5b64aU), bswap_32big(0xf4d8cdd3U),
                           bswap_32big(0x4fc7673cU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xfc0b0bc9U), bswap_32big(0x1508a0abU), bswap_32big(0x3cc196e3U),
                           bswap_32big(0xfc0e8fa2U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc007(bswap_32big(0x24016c13U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000565U));
                r_rsip_func101(bswap_32big(0x3754e76dU),
                               bswap_32big(0xce3982bdU),
                               bswap_32big(0x212e3ce8U),
                               bswap_32big(0x03e2ccabU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x8ddda849U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000566U));
                r_rsip_func101(bswap_32big(0x4e932452U),
                               bswap_32big(0x09c8714eU),
                               bswap_32big(0x968d3343U),
                               bswap_32big(0x406981bdU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000561U));
                r_rsip_func101(bswap_32big(0x672e6285U),
                               bswap_32big(0x6a557058U),
                               bswap_32big(0xc97e1c5bU),
                               bswap_32big(0x175544f5U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x24016c13U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xb5f53cfaU),
                               bswap_32big(0x0d34ebbfU),
                               bswap_32big(0xbf823b2fU),
                               bswap_32big(0xa09af83bU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5c7fc321U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000567U));
                r_rsip_func101(bswap_32big(0x5dd27ebeU),
                               bswap_32big(0x29e947cfU),
                               bswap_32big(0xf4977469U),
                               bswap_32big(0x6dd399b4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000568U));
                r_rsip_func101(bswap_32big(0x46990ce7U),
                               bswap_32big(0x086ecbe7U),
                               bswap_32big(0xf274a60bU),
                               bswap_32big(0x33d8c8b4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000562U));
                r_rsip_func101(bswap_32big(0x32823a9bU),
                               bswap_32big(0x8a7f5814U),
                               bswap_32big(0x0d043ddfU),
                               bswap_32big(0xb123ec9aU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x5c7fc321U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0xec255e0dU),
                               bswap_32big(0x32e9f205U),
                               bswap_32big(0x9a0a8c7fU),
                               bswap_32big(0xafa7a4cdU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x9765a202U),
                               bswap_32big(0x52a05746U),
                               bswap_32big(0x0bd246fbU),
                               bswap_32big(0x86f2fa6fU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);
                r_rsip_subfunc007(bswap_32big(0x8ddda849U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0x90377127U),
                               bswap_32big(0xc5d5ccfbU),
                               bswap_32big(0x5f074f87U),
                               bswap_32big(0x5819cb3dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x24016c13U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0xfb3e2139U),
                               bswap_32big(0xeb377ff4U),
                               bswap_32big(0x3af9fdaeU),
                               bswap_32big(0x0126e163U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000563U));
                r_rsip_func101(bswap_32big(0x5484f8f9U),
                               bswap_32big(0x4f6b2afbU),
                               bswap_32big(0xed4063f8U),
                               bswap_32big(0x8ed3a0b9U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x8ddda849U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0xed42ff9eU),
                               bswap_32big(0xd5b6d607U),
                               bswap_32big(0x7d33bc99U),
                               bswap_32big(0x0731a1efU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x7b51d520U),
                               bswap_32big(0xc6bb9d6dU),
                               bswap_32big(0x935ac32aU),
                               bswap_32big(0x46467e32U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5c7fc321U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x6efafdd0U),
                               bswap_32big(0xfff6994fU),
                               bswap_32big(0x6c2bed0aU),
                               bswap_32big(0x9365e40aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000564U));
                r_rsip_func101(bswap_32big(0x28b6c068U),
                               bswap_32big(0x67bffb40U),
                               bswap_32big(0xfbda72c7U),
                               bswap_32big(0x3894817aU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0x05cb2a7eU),
                               bswap_32big(0xe70f2ee8U),
                               bswap_32big(0x23515f0eU),
                               bswap_32big(0x53e8b177U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x5ec7127aU),
                               bswap_32big(0x3bcebcfeU),
                               bswap_32big(0x7a8af7cfU),
                               bswap_32big(0xd9c7ca23U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xab7ce7b2U));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x0000056eU));
    r_rsip_func101(bswap_32big(0x4ed0626fU),
                   bswap_32big(0x3adc285dU),
                   bswap_32big(0x4a097ae6U),
                   bswap_32big(0x832eb711U));
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
        r_rsip_func100(bswap_32big(0x7ac6bc49U), bswap_32big(0x1e3900d2U), bswap_32big(0xcac2ee7cU),
                       bswap_32big(0xdf91022eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x02a6fd91U), bswap_32big(0x790431a5U), bswap_32big(0x9219b4fcU),
                           bswap_32big(0x24966ccdU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x9dbe0389U), bswap_32big(0x373e34d5U), bswap_32big(0xe97659a3U),
                           bswap_32big(0x281f04aeU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xa2e37df4U));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056fU));
    r_rsip_func101(bswap_32big(0xbc6a5a2fU),
                   bswap_32big(0x62c13687U),
                   bswap_32big(0x2210d160U),
                   bswap_32big(0xe155a991U));
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
        r_rsip_func100(bswap_32big(0x4b2c1851U), bswap_32big(0xfe9c5c27U), bswap_32big(0xe059f847U),
                       bswap_32big(0x7b9b4d82U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);
            r_rsip_func101(bswap_32big(0x1df933fdU), bswap_32big(0x8bfa6e27U), bswap_32big(0x1d4bf9caU),
                           bswap_32big(0x57078dc9U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xf88a85f7U), bswap_32big(0xd5246febU), bswap_32big(0x265e80ceU),
                           bswap_32big(0x6088e001U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x1d2800b3U),
                   bswap_32big(0x6846072fU),
                   bswap_32big(0x45f4e0b3U),
                   bswap_32big(0x5d586fcaU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);
        r_rsip_func101(bswap_32big(0x418f4cd2U), bswap_32big(0xc20d4c5fU), bswap_32big(0x68418564U),
                       bswap_32big(0xb8e55394U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xc7d0fa23U), bswap_32big(0x4f28d6a7U), bswap_32big(0xc3492451U),
                       bswap_32big(0x3ea19739U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
