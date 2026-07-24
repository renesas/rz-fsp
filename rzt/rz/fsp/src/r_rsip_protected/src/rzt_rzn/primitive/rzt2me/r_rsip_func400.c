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
    r_rsip_func101(bswap_32big(0xdec81f30U),
                   bswap_32big(0xb4358080U),
                   bswap_32big(0xc9b09f70U),
                   bswap_32big(0x01adf604U));
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
    r_rsip_func100(bswap_32big(0xeb9e7772U),
                   bswap_32big(0x4bd561c1U),
                   bswap_32big(0xa2cecd54U),
                   bswap_32big(0xb18120ceU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x38eff0e4U), bswap_32big(0x074d4c65U), bswap_32big(0xf9e8a85eU),
                       bswap_32big(0xde97aebdU));
    }
    else
    {
        r_rsip_func100(bswap_32big(0xf009531aU), bswap_32big(0x187ac368U), bswap_32big(0xc96bd897U),
                       bswap_32big(0xd99cf267U));
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
        r_rsip_func101(bswap_32big(0xfba63d08U), bswap_32big(0x6bd37682U), bswap_32big(0x4b8d993eU),
                       bswap_32big(0x4f343e63U));
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
        r_rsip_func100(bswap_32big(0xb48a7c20U), bswap_32big(0xc4b67691U), bswap_32big(0x3dfb7602U),
                       bswap_32big(0x5fccccafU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            WR1_PROG(REG_1018H, 0x00000a70U);
            r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x05050013U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0xff89eddaU), bswap_32big(0xa6ba4783U), bswap_32big(0x338beeb8U),
                           bswap_32big(0x8fe0f07cU));
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x05050014U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0xb177f783U), bswap_32big(0x9b16e683U), bswap_32big(0x9b194b1bU),
                           bswap_32big(0xad420c6cU));
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
                r_rsip_func100(bswap_32big(0x22ca5a17U),
                               bswap_32big(0x64743cdfU),
                               bswap_32big(0x979c979aU),
                               bswap_32big(0x0bf50571U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x05050014U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    r_rsip_func101(bswap_32big(0xef51f4d1U),
                                   bswap_32big(0x2aae06c9U),
                                   bswap_32big(0x13c0a7c0U),
                                   bswap_32big(0x07f181aaU));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x3a6457cbU),
                                   bswap_32big(0x6d5a262eU),
                                   bswap_32big(0x17b0a0d9U),
                                   bswap_32big(0x020e3993U));
                }

                WR1_PROG(REG_1600H, 0x38000ca5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0x84e9ba3dU),
                               bswap_32big(0x60c4bae5U),
                               bswap_32big(0xa66f8515U),
                               bswap_32big(0x16592bb7U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func100(bswap_32big(0x48f24817U),
                                   bswap_32big(0x1a466882U),
                                   bswap_32big(0x1d653e32U),
                                   bswap_32big(0x6efb7d6eU));
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
                        r_rsip_func101(bswap_32big(0x8a977a4cU),
                                       bswap_32big(0x1cbf8288U),
                                       bswap_32big(0xf36a58f2U),
                                       bswap_32big(0x86254414U));
                    }
                    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000b00U, 0x00000160U, 0x00000420U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b30U, 0x00000160U, 0x00000450U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x83360498U),
                                       bswap_32big(0x4d633cc9U),
                                       bswap_32big(0xdd8f22abU),
                                       bswap_32big(0x837dbd1eU));
                    }
                    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000bf0U, 0x00000160U, 0x00000420U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c20U, 0x00000160U, 0x00000450U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x37724b5eU),
                                       bswap_32big(0xef3b9e88U),
                                       bswap_32big(0x155ece77U),
                                       bswap_32big(0x47c42ab5U));
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
                    r_rsip_func100(bswap_32big(0x3532e179U),
                                   bswap_32big(0xb342ca13U),
                                   bswap_32big(0x8be54ecaU),
                                   bswap_32big(0xbe308ca2U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000420U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0x30e83623U),
                                       bswap_32big(0x6114feb9U),
                                       bswap_32big(0x308991ddU),
                                       bswap_32big(0x6f0aaee4U));
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
                            r_rsip_func100(bswap_32big(0x0a03a776U),
                                           bswap_32big(0x65bc55e7U),
                                           bswap_32big(0x842ee903U),
                                           bswap_32big(0xfd6e624dU));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                WR1_PROG(REG_1018H, 0x00000480U);
                                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x05050013U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0xdebbe3acU), bswap_32big(0x0de3abfbU),
                                               bswap_32big(0x0c18669dU), bswap_32big(0x237e5c18U));
                            }
                            else
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x05050014U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0x3d3488a9U), bswap_32big(0x1726d74cU),
                                               bswap_32big(0x1695038eU), bswap_32big(0xff050899U));
                            }
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0x34bec7efU),
                                           bswap_32big(0xfdb97374U),
                                           bswap_32big(0x445c5f37U),
                                           bswap_32big(0x716923c0U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_subfunc003(0x00c00021U);
                        r_rsip_subfunc001(0x00000420U, 0x00000160U, 0x000001f0U, 0x04040009U);
                        r_rsip_subfunc001(0x00000450U, 0x00000160U, 0x00000220U, 0x04040009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x675389efU),
                                       bswap_32big(0x349fb819U),
                                       bswap_32big(0xe211c9c8U),
                                       bswap_32big(0xf78359fcU));
                    }
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x4f7b10f0U),
                                   bswap_32big(0x928d10aeU),
                                   bswap_32big(0x6c6dfefcU),
                                   bswap_32big(0x8c455a36U));
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xf3e23a63U),
                               bswap_32big(0xc0843abcU),
                               bswap_32big(0xef145a2eU),
                               bswap_32big(0x9bca19c6U));
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
            r_rsip_func101(bswap_32big(0x9737f33dU), bswap_32big(0x09745aeeU), bswap_32big(0x12166f53U),
                           bswap_32big(0x4c96b479U));
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
        r_rsip_func100(bswap_32big(0xe670965bU), bswap_32big(0x2309f902U), bswap_32big(0xb73eea70U),
                       bswap_32big(0xa93af0b7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd2e1b406U), bswap_32big(0xea10e4b6U), bswap_32big(0x90324ff4U),
                           bswap_32big(0xe3ab8c62U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x84e7de66U), bswap_32big(0x6d589914U), bswap_32big(0x40f3b07aU),
                           bswap_32big(0xf3379823U));
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
            r_rsip_func100(bswap_32big(0xbee6a81fU), bswap_32big(0xf626d183U), bswap_32big(0xc1ce2b2dU),
                           bswap_32big(0x4cce6351U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x891cdb84U),
                               bswap_32big(0xb8c718a2U),
                               bswap_32big(0x443504c2U),
                               bswap_32big(0x2cd1e5b0U));
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x19bac63dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x67bca289U),
                               bswap_32big(0xe9b8bebcU),
                               bswap_32big(0x75943c1fU),
                               bswap_32big(0x48d97339U));
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
