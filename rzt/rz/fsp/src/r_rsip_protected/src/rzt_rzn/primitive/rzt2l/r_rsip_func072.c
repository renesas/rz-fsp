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

void r_rsip_func072 (void)
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
    r_rsip_func100(bswap_32big(0x56c6a8abU),
                   bswap_32big(0xd6bdc6eeU),
                   bswap_32big(0x850a8a8cU),
                   bswap_32big(0x6bc798e3U));
    WR1_PROG(REG_1404H, 0x11180000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x000003e0U, 0x0909000aU);
    r_rsip_subfunc006(0x00000020U, 0x000003e0U, 0x09090010U);
    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x75d7fc4bU),
                   bswap_32big(0xc23a3c6fU),
                   bswap_32big(0x62dd8efdU),
                   bswap_32big(0xa95c9c80U));
    WR1_PROG(REG_1404H, 0x10c80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x43fd8712U),
                   bswap_32big(0xaf182381U),
                   bswap_32big(0x15917dd4U),
                   bswap_32big(0xfbafcd57U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xd50d8b70U),
                   bswap_32big(0x40f769b1U),
                   bswap_32big(0x2060d07cU),
                   bswap_32big(0xd1522abfU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa7a51188U),
                   bswap_32big(0x86d69e4eU),
                   bswap_32big(0xf209575dU),
                   bswap_32big(0x00245da3U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20009U);
    r_rsip_subfunc003(0x00020009U);
    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x000003e0U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x09090004U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x13e80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000480U, 0x00000430U, 0x00000160U, 0x09090009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x09090010U);
    WR1_PROG(REG_1014H, 0x00000340U);
    WR1_PROG(REG_1018H, 0x00000160U);
    r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x09090005U);
    r_rsip_subfunc001(0x00000110U, 0x00000430U, 0x00000480U, 0x0909000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x19e6bd73U),
                   bswap_32big(0x504506c6U),
                   bswap_32big(0x4cd4f46fU),
                   bswap_32big(0xaded8b8fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa35717d8U), bswap_32big(0x55783fd5U), bswap_32big(0x19af2b0eU),
                       bswap_32big(0xe80447c7U));
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1004H, 0x09090004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x13980000U);
        r_rsip_subfunc003(0x00c00049U);
        WR1_PROG(REG_1404H, 0x12500000U);
        r_rsip_subfunc003(0x00c000a1U);
        r_rsip_subfunc001(0x00000890U, 0x000003e0U, 0x000002a0U, 0x09090009U);
        r_rsip_subfunc001(0x00000070U, 0x000003e0U, 0x000002f0U, 0x09090009U);
        r_rsip_func100(bswap_32big(0x773943a6U), bswap_32big(0x21ef79a7U), bswap_32big(0xb1961f33U),
                       bswap_32big(0x84dff589U));
        r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x09090015U, 0x00020000U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1404H, 0x10c80000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c00045U);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000480U, 0x00000110U, 0x000004d0U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xf2956535U), bswap_32big(0x329b96b0U), bswap_32big(0xce67a8b4U),
                       bswap_32big(0x96fa6d47U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc24ad66bU), bswap_32big(0x004d007fU), bswap_32big(0x99b8f780U),
                           bswap_32big(0x55f38f37U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x4b2e8aa9U), bswap_32big(0x8b0c26c2U), bswap_32big(0x26fd0e21U),
                           bswap_32big(0x472d75c7U));
            r_rsip_subfunc005(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x09090015U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1404H, 0x10c80000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c00045U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000570U, 0x00000110U, 0x000001b0U, 0x0909000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xe16c2b1dU), bswap_32big(0xedde5963U), bswap_32big(0x86846275U),
                           bswap_32big(0x6852bfcaU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x74f8db77U),
                               bswap_32big(0x84586e88U),
                               bswap_32big(0x239a169eU),
                               bswap_32big(0xf257305cU));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x05347b1fU),
                               bswap_32big(0x06a9315eU),
                               bswap_32big(0xc179763fU),
                               bswap_32big(0xdd042beeU));
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000250U);
                WR1_PROG(REG_1004H, 0x09090004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x11180000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c00045U);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000160U);
                WR1_PROG(REG_1004H, 0x0909000fU);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000004d0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x000001b0U);
                WR1_PROG(REG_1004H, 0x09090002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000520U);
                WR1_PROG(REG_1018H, 0x00000160U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000200U);
                WR1_PROG(REG_1004H, 0x09090002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_subfunc001(0x00000070U, 0x00000200U, 0x00000110U, 0x0909000aU);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000520U);
                WR1_PROG(REG_1004H, 0x09090002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000110U);
                WR1_PROG(REG_1004H, 0x09090002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_subfunc003(0x00c00049U);
                r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x000004d0U, 0x09090009U);
                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000570U);
                WR1_PROG(REG_1004H, 0x09090004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x11180000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c00045U);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0909000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_func100(bswap_32big(0x3bf0243aU),
                               bswap_32big(0x150295f4U),
                               bswap_32big(0xf722368cU),
                               bswap_32big(0x4b991ab5U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x000004d0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x9de8370eU),
                                   bswap_32big(0x86a8dbaaU),
                                   bswap_32big(0x4703ecc7U),
                                   bswap_32big(0x008ac958U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x000003e0U, 0x000004d0U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x000004d0U, 0x000003e0U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000430U, 0x00000520U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000520U, 0x00000430U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000570U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000570U, 0x00000480U, 0x00000110U, 0x0909000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0xe39bbc00U),
                                       bswap_32big(0xe6f33d0eU),
                                       bswap_32big(0x1b298064U),
                                       bswap_32big(0x7f0a28b3U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x09090013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x09e30dd2U),
                                           bswap_32big(0x788331a5U),
                                           bswap_32big(0x1bfd277cU),
                                           bswap_32big(0x5c38d0e5U));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x1271a6cbU),
                                           bswap_32big(0x406829ceU),
                                           bswap_32big(0x097f8c29U),
                                           bswap_32big(0x7f0fce97U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_subfunc003(0x00c00049U);
                        r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);
                        r_rsip_func101(bswap_32big(0x3dc0ab72U),
                                       bswap_32big(0x52ec4557U),
                                       bswap_32big(0x82e687daU),
                                       bswap_32big(0xbc153702U));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_subfunc003(0x00c00049U);
                    r_rsip_subfunc001(0x000004d0U, 0x00000160U, 0x000001b0U, 0x09090009U);
                    r_rsip_subfunc001(0x00000520U, 0x00000160U, 0x00000200U, 0x09090009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x09090009U);
                    r_rsip_func101(bswap_32big(0x08c34397U),
                                   bswap_32big(0x6d748a2eU),
                                   bswap_32big(0x18f4e9d8U),
                                   bswap_32big(0xee261b26U));
                }

                WR1_PROG(REG_1404H, 0x12a80000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c00045U);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0909000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x7fe94f62U),
                               bswap_32big(0xa967205cU),
                               bswap_32big(0x2e2b8b9dU),
                               bswap_32big(0x4982ca6cU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xe7e97c2fU),
                                   bswap_32big(0x5e821cf3U),
                                   bswap_32big(0x82a1a847U),
                                   bswap_32big(0x50112170U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0xa334808dU),
                                   bswap_32big(0xc4b5f49fU),
                                   bswap_32big(0x3ebdb5faU),
                                   bswap_32big(0x1c15f1f0U));
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000002a0U);
                    WR1_PROG(REG_1004H, 0x09090004U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1404H, 0x11180000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                    r_rsip_subfunc003(0x00c00045U);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_1014H, 0x000002a0U);
                    WR1_PROG(REG_1018H, 0x00000110U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000160U);
                    WR1_PROG(REG_1004H, 0x0909000fU);
                    WR1_PROG(REG_1408H, 0x00020000U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    WR1_PROG(REG_1014H, 0x000001b0U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000002a0U);
                    WR1_PROG(REG_1004H, 0x09090002U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1014H, 0x00000200U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000002f0U);
                    WR1_PROG(REG_1004H, 0x09090002U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0xeea53c1eU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x41998f18U),
                                   bswap_32big(0xbac09276U),
                                   bswap_32big(0xeee6490cU),
                                   bswap_32big(0x887d02a9U));
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xeea53c1eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
