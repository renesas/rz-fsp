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

void r_rsip_func400 (const uint32_t ARG1[])
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
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1600H, 0x00000b5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000b9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10700000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x13400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x17f00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc009(bswap_32big(0x0000f400U));
    r_rsip_func101(bswap_32big(0x9f85beecU),
                   bswap_32big(0x1ac43533U),
                   bswap_32big(0xabb56241U),
                   bswap_32big(0x87032c2aU));
    r_rsip_func084();
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
    WR1_PROG(REG_1404H, 0x18e00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x19100000U);
    WR1_PROG(REG_1444H, 0x00000fc2U);
    WR1_PROG(REG_1A2CH, 0x00000300U);
    WR1_PROG(REG_1A24H, 0x08008107U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[0]);
    WR1_ADDR(REG_1420H, &ARG1[1]);
    WR1_ADDR(REG_1420H, &ARG1[2]);
    WR1_ADDR(REG_1420H, &ARG1[3]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[4]);
    WR1_ADDR(REG_1420H, &ARG1[5]);
    WR1_ADDR(REG_1420H, &ARG1[6]);
    WR1_ADDR(REG_1420H, &ARG1[7]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x19600000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[8]);
    WR1_ADDR(REG_1420H, &ARG1[9]);
    WR1_ADDR(REG_1420H, &ARG1[10]);
    WR1_ADDR(REG_1420H, &ARG1[11]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[12]);
    WR1_ADDR(REG_1420H, &ARG1[13]);
    WR1_ADDR(REG_1420H, &ARG1[14]);
    WR1_ADDR(REG_1420H, &ARG1[15]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x11e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0001dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000200U, 0x00000160U, 0x0404000aU);
    r_rsip_subfunc001(0x00000160U, 0x00000930U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000930U, 0x00000200U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000160U, 0x00000980U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000980U, 0x00000200U, 0x000001b0U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x6c70868aU),
                   bswap_32big(0x42dd0020U),
                   bswap_32big(0x53fd045fU),
                   bswap_32big(0x4c1611a4U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x765fb3d5U), bswap_32big(0xbd6c7da1U), bswap_32big(0xe1752276U),
                       bswap_32big(0x671f80ccU));
    }
    else
    {
        r_rsip_func100(bswap_32big(0xa8d8b75dU), bswap_32big(0x6c731177U), bswap_32big(0xe7861bacU),
                       bswap_32big(0x157be253U));
        r_rsip_subfunc001(0x00000160U, 0x00000200U, 0x000001b0U, 0x0404000aU);
        WR1_PROG(REG_1014H, 0x00000980U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_1004H, 0x0404000fU);
        WR1_PROG(REG_1408H, 0x00020000U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000840U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000160U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x10c00000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8188001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90021U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000160U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000480U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000930U);
        WR1_PROG(REG_1018H, 0x00000160U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000340U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1404H, 0x11400000U);
        r_rsip_subfunc003(0x00c00021U);
        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_subfunc003(0x00c002d1U);
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000a70U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x00000890U, 0x00000160U, 0x000002c8U, 0x04040009U);
        r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x04040009U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1608H, 0x81880001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90021U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000a20U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1600H, 0x000037e1U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000a7e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8188001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90021U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000a48U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x14800000U);
        r_rsip_subfunc003(0x00c000f1U);
        r_rsip_subfunc001(0x00000390U, 0x00000160U, 0x00000980U, 0x04040009U);
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000548U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x15500000U);
        r_rsip_subfunc003(0x00c00015U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c2000dU);
        r_rsip_subfunc003(0x00020005U);
        WR1_PROG(REG_1014H, 0x00000548U);
        WR1_PROG(REG_1018H, 0x00000570U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000980U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000a20U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000520U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000a48U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000548U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1014H, 0x00000520U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000a10U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000548U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000a40U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000a70U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x12500000U);
        r_rsip_subfunc003(0x00c000a1U);
        WR1_PROG(REG_1014H, 0x00000890U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000570U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000570U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000002c0U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x04040009U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        r_rsip_subfunc009(bswap_32big(0x0000f400U));
        r_rsip_func101(bswap_32big(0x813e13d4U), bswap_32big(0x3b0ed129U), bswap_32big(0x7e88d9b1U),
                       bswap_32big(0x587c87c3U));
        r_rsip_func085();
        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000520U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000228U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000548U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1014H, 0x00000520U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000001f0U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000548U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000220U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x000001f0U, 0x00000160U, 0x00000b00U, 0x04040009U);
        r_rsip_subfunc001(0x00000220U, 0x00000160U, 0x00000b30U, 0x04040009U);
        r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000b60U, 0x04040009U);
        r_rsip_subfunc001(0x00000b00U, 0x00000a10U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000a10U, 0x00000b00U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000b30U, 0x00000a40U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000a40U, 0x00000b30U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x97146a29U), bswap_32big(0x997936f5U), bswap_32big(0x8617e9bfU),
                       bswap_32big(0x4462f3a2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            WR1_PROG(REG_1018H, 0x00000a70U);
            r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x05050013U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0xae78299bU), bswap_32big(0xf1fc993bU), bswap_32big(0x1610bfe8U),
                           bswap_32big(0x44c7683bU));
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x05050014U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0x965a1d23U), bswap_32big(0xb8ea2227U), bswap_32big(0x86b59386U),
                           bswap_32big(0x806f918aU));
        }

        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x14600000U);
        WR1_PROG(REG_1608H, 0x80880001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03430021U);
        WR1_PROG(REG_1600H, 0x0000a420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000050U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x13200000U);
        WR1_PROG(REG_1608H, 0x80880001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03430021U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1600H, 0x000034a1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026ca5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003865U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003885U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000842U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x000008a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01816ca3U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01816ca4U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00016c63U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00016c84U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x11400000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x000001f0U, 0x00000160U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_func100(bswap_32big(0x4829ededU),
                               bswap_32big(0xff157cceU),
                               bswap_32big(0x29e4f19cU),
                               bswap_32big(0xafa38927U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x05050014U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    r_rsip_func101(bswap_32big(0xc73b34baU),
                                   bswap_32big(0xbc9bfb93U),
                                   bswap_32big(0x54737ac7U),
                                   bswap_32big(0xb5eb9c39U));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xb4d71b2bU),
                                   bswap_32big(0x88d23c54U),
                                   bswap_32big(0x8ab02720U),
                                   bswap_32big(0xcaef33d7U));
                }

                WR1_PROG(REG_1600H, 0x38000ca5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0xd1108bf2U),
                               bswap_32big(0x01601199U),
                               bswap_32big(0x624f08d2U),
                               bswap_32big(0x482f3ec7U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func100(bswap_32big(0x4ee82469U),
                                   bswap_32big(0x98d8a0c9U),
                                   bswap_32big(0xa1cc4802U),
                                   bswap_32big(0x20d2c5e5U));
                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_subfunc003(0x00c00021U);
                    WR1_PROG(REG_1600H, 0x00007c05U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00600000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000a10U, 0x00000160U, 0x00000420U, 0x04040009U);
                        r_rsip_subfunc001(0x00000a40U, 0x00000160U, 0x00000450U, 0x04040009U);
                        r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x45562028U),
                                       bswap_32big(0xc9e8c35aU),
                                       bswap_32big(0x3709b0c5U),
                                       bswap_32big(0x6da9c7ffU));
                    }
                    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000b00U, 0x00000160U, 0x00000420U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b30U, 0x00000160U, 0x00000450U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x788e537fU),
                                       bswap_32big(0x63209f0fU),
                                       bswap_32big(0x3d2902adU),
                                       bswap_32big(0x187d8d2fU));
                    }
                    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000bf0U, 0x00000160U, 0x00000420U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c20U, 0x00000160U, 0x00000450U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x89b486c1U),
                                       bswap_32big(0x5c60a627U),
                                       bswap_32big(0x890057f4U),
                                       bswap_32big(0x35c54bd7U));
                    }

                    WR1_PROG(REG_1404H, 0x11400000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                    r_rsip_subfunc003(0x00c0001dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x000001f0U, 0x00000160U, 0x00000110U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x6172daadU),
                                   bswap_32big(0x7cb8257fU),
                                   bswap_32big(0x56c34ca6U),
                                   bswap_32big(0xbb75a274U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000420U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0xf18c24f1U),
                                       bswap_32big(0x6ca1e638U),
                                       bswap_32big(0x273049d0U),
                                       bswap_32big(0x2b50a7e9U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x000001f0U, 0x00000420U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000420U, 0x000001f0U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000220U, 0x00000450U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000450U, 0x00000220U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000250U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_func100(bswap_32big(0xd09c9840U),
                                           bswap_32big(0x8df6e7c1U),
                                           bswap_32big(0x6a8432efU),
                                           bswap_32big(0x0de64671U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                WR1_PROG(REG_1018H, 0x00000480U);
                                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x05050013U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0x230c57bbU), bswap_32big(0x7e26e23bU),
                                               bswap_32big(0x64f4cce9U), bswap_32big(0xce56cfe1U));
                            }
                            else
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x05050014U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0x9f2730feU), bswap_32big(0x153277b1U),
                                               bswap_32big(0xf8f29f91U), bswap_32big(0x282bd00bU));
                            }
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0xce6affd8U),
                                           bswap_32big(0xc9e93a4aU),
                                           bswap_32big(0x5feb4d5eU),
                                           bswap_32big(0x95227c19U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_subfunc003(0x00c00021U);
                        r_rsip_subfunc001(0x00000420U, 0x00000160U, 0x000001f0U, 0x04040009U);
                        r_rsip_subfunc001(0x00000450U, 0x00000160U, 0x00000220U, 0x04040009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x74a399f5U),
                                       bswap_32big(0x8de924e1U),
                                       bswap_32big(0xbb23800fU),
                                       bswap_32big(0xb9ce4935U));
                    }
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xcdeb7b7cU),
                                   bswap_32big(0x02f9323cU),
                                   bswap_32big(0x7e1d195dU),
                                   bswap_32big(0x19b63f21U));
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x578086f3U),
                               bswap_32big(0x3ef005e0U),
                               bswap_32big(0x8a40025cU),
                               bswap_32big(0xc22eb4acU));
            }

            WR1_PROG(REG_1600H, 0x38008840U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002c20U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xaeadf101U), bswap_32big(0x3c863d50U), bswap_32big(0x50f4360bU),
                           bswap_32big(0xd4d5545fU));
        }

        WR1_PROG(REG_1600H, 0x38008820U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1014H, 0x000001f0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x05050004U);
        WR1_PROG(REG_1014H, 0x00000220U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x05050004U);
        WR1_PROG(REG_1014H, 0x00000250U);
        r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x05050004U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000200U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000228U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1004H, 0x04040002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x12800000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0001dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x28a9ae2eU), bswap_32big(0x1fd6d1f0U), bswap_32big(0x1b9b51f1U),
                       bswap_32big(0x77061a5eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xa309266bU), bswap_32big(0x96b03e33U), bswap_32big(0xdd1d6f25U),
                           bswap_32big(0x5f712e12U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x1e374694U), bswap_32big(0xdc4b2ebcU), bswap_32big(0x95f86e6aU),
                           bswap_32big(0xf9400147U));
            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002a0U);
            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x11400000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0001dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);
            WR1_PROG(REG_1014H, 0x000002a0U);
            WR1_PROG(REG_1018H, 0x00000110U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000160U);
            WR1_PROG(REG_1004H, 0x0404000fU);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000200U);
            WR1_PROG(REG_1018H, 0x00000160U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002a0U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x3cd36897U), bswap_32big(0x2825cbc0U), bswap_32big(0xb5116f10U),
                           bswap_32big(0x7b9a9297U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x143f8578U),
                               bswap_32big(0x5b9cc4c6U),
                               bswap_32big(0x6c105f28U),
                               bswap_32big(0xfb32e79dU));
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x19bac63dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xee54dda5U),
                               bswap_32big(0xefcb128bU),
                               bswap_32big(0x5ca54565U),
                               bswap_32big(0x8af6cb03U));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x19bac63dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
