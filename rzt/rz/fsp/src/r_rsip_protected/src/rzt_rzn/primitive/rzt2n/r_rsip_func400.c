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
    r_rsip_subfunc009(bswap_32big(0x0000f400U));
    r_rsip_func101(bswap_32big(0x5acedf4dU),
                   bswap_32big(0x9798ad73U),
                   bswap_32big(0x02810297U),
                   bswap_32big(0x677bb685U));
    r_rsip_func084();
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
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
    r_rsip_func100(bswap_32big(0xbc46d14cU),
                   bswap_32big(0x83fcda13U),
                   bswap_32big(0x28861432U),
                   bswap_32big(0x1318cbbcU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x610bc614U), bswap_32big(0xecc292aaU), bswap_32big(0x72406c36U),
                       bswap_32big(0x73745c56U));
    }
    else
    {
        r_rsip_func100(bswap_32big(0x05bad924U), bswap_32big(0xcf7f1bb4U), bswap_32big(0x264164d2U),
                       bswap_32big(0x298a49a3U));
        r_rsip_subfunc001(0x00000160U, 0x00000200U, 0x000001b0U, 0x0404000aU);
        WR1_PROG(REG_1014H, 0x00000980U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_1004H, 0x0404000fU);
        WR1_PROG(REG_1408H, 0x00020000U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000840U);
        r_rsip_subfunc002(0x000000c0U, 0x00000160U, 0x04040002U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8188001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90021U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000160U);
        r_rsip_subfunc002(0x000000c0U, 0x00000480U, 0x04040002U);
        WR1_PROG(REG_1014H, 0x00000930U);
        WR1_PROG(REG_1018H, 0x00000160U);
        r_rsip_subfunc002(0x000000c0U, 0x00000340U, 0x04040002U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1404H, 0x11400000U);
        r_rsip_subfunc003(0x00c00021U);
        WR1_PROG(REG_1404H, 0x19800000U);
        r_rsip_subfunc003(0x00c002d1U);
        WR1_PROG(REG_1014H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x00000a70U, 0x04040004U);
        r_rsip_subfunc001(0x00000890U, 0x00000160U, 0x000002c8U, 0x04040009U);
        r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x04040009U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1608H, 0x81880001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90021U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x00000a20U, 0x04040002U);
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
        r_rsip_subfunc002(0x00000070U, 0x00000a48U, 0x04040002U);
        r_rsip_subfunc009(bswap_32big(0x0000f400U));
        r_rsip_func101(bswap_32big(0x4107ec53U), bswap_32big(0x413d7430U), bswap_32big(0xb6106d63U),
                       bswap_32big(0x2ed870eaU));
        r_rsip_func085();
        r_rsip_subfunc001(0x00000200U, 0x00000160U, 0x00000b10U, 0x04040009U);
        r_rsip_subfunc001(0x00000228U, 0x00000160U, 0x00000b38U, 0x04040009U);
        r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000b60U, 0x04040009U);
        r_rsip_subfunc001(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000b38U, 0x00000a48U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000a48U, 0x00000b38U, 0x00000110U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x913cc083U), bswap_32big(0x3d7800bcU), bswap_32big(0x221c7ae5U),
                       bswap_32big(0x9572630cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            WR1_PROG(REG_1018H, 0x00000a70U);
            r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x04040013U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0x500b9157U), bswap_32big(0xadbac354U), bswap_32big(0xc0579402U),
                           bswap_32big(0xdc850580U));
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x04040014U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0x6a3ed662U), bswap_32big(0xd89d3c06U), bswap_32big(0x3350ae54U),
                           bswap_32big(0x6b2ba730U));
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
                r_rsip_subfunc001(0x00000200U, 0x00000160U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_func100(bswap_32big(0x4040720bU),
                               bswap_32big(0x05d9e699U),
                               bswap_32big(0xb1ec4a4aU),
                               bswap_32big(0x0a3b4588U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x04040014U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    r_rsip_func101(bswap_32big(0xafde2fbfU),
                                   bswap_32big(0xe3b55939U),
                                   bswap_32big(0xf77eb85eU),
                                   bswap_32big(0x7ccb42ceU));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x77bcc755U),
                                   bswap_32big(0x3b7d196aU),
                                   bswap_32big(0x39d3847eU),
                                   bswap_32big(0xecc4c484U));
                }

                WR1_PROG(REG_1600H, 0x38000ca5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0x12e60a68U),
                               bswap_32big(0x0977f51cU),
                               bswap_32big(0x79161454U),
                               bswap_32big(0x61ee1823U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func100(bswap_32big(0x7f638de1U),
                                   bswap_32big(0xc3f7a542U),
                                   bswap_32big(0xf6d01aabU),
                                   bswap_32big(0x3ffb9a0eU));
                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_subfunc003(0x00c00021U);
                    WR1_PROG(REG_1600H, 0x00007c05U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00600000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000a20U, 0x00000160U, 0x00000430U, 0x04040009U);
                        r_rsip_subfunc001(0x00000a48U, 0x00000160U, 0x00000458U, 0x04040009U);
                        r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x98552f8eU),
                                       bswap_32big(0x51fea4f7U),
                                       bswap_32big(0xdf459b27U),
                                       bswap_32big(0x38f60ad0U));
                    }
                    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000b10U, 0x00000160U, 0x00000430U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b38U, 0x00000160U, 0x00000458U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x77f152aeU),
                                       bswap_32big(0xf7c36f77U),
                                       bswap_32big(0xb0c375f9U),
                                       bswap_32big(0xbc90b259U));
                    }
                    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000c00U, 0x00000160U, 0x00000430U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c28U, 0x00000160U, 0x00000458U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0xbb507393U),
                                       bswap_32big(0x01a8d408U),
                                       bswap_32big(0x4e58f678U),
                                       bswap_32big(0x0c3e428aU));
                    }

                    WR1_PROG(REG_1404H, 0x11400000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                    r_rsip_subfunc003(0x00c0001dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x00000200U, 0x00000160U, 0x00000110U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x977153d7U),
                                   bswap_32big(0x237787cbU),
                                   bswap_32big(0x4f7e27adU),
                                   bswap_32big(0x6bdc5989U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0xb393f9afU),
                                       bswap_32big(0xc22e3663U),
                                       bswap_32big(0x10a4283cU),
                                       bswap_32big(0x8cd24dd7U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x00000200U, 0x00000430U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000430U, 0x00000200U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000228U, 0x00000458U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000458U, 0x00000228U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000250U, 0x00000110U, 0x0404000aU);
                            WR1_PROG(REG_143CH, 0x00210000U);
                            r_rsip_func100(bswap_32big(0xf1f5a9d7U),
                                           bswap_32big(0x4aab2ef3U),
                                           bswap_32big(0xe97f737dU),
                                           bswap_32big(0x36e3a93fU));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                WR1_PROG(REG_1018H, 0x00000480U);
                                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040013U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0x69b2bf19U), bswap_32big(0xa4613c0bU),
                                               bswap_32big(0x81cce3edU), bswap_32big(0x53d2d950U));
                            }
                            else
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x04040014U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0x45c12a10U), bswap_32big(0x129b2b4cU),
                                               bswap_32big(0x9cff2d9fU), bswap_32big(0xcaa45832U));
                            }
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0x47b4941bU),
                                           bswap_32big(0x95b52260U),
                                           bswap_32big(0x7c8c96b1U),
                                           bswap_32big(0xe3800b1fU));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_subfunc003(0x00c00021U);
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x04040009U);
                        r_rsip_subfunc001(0x00000458U, 0x00000160U, 0x00000228U, 0x04040009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x0c4decf5U),
                                       bswap_32big(0xbaec74ccU),
                                       bswap_32big(0x83d6c86fU),
                                       bswap_32big(0xd1acfa70U));
                    }
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xc2063372U),
                                   bswap_32big(0x6b864dd2U),
                                   bswap_32big(0x7d8ce44fU),
                                   bswap_32big(0x4c9346a7U));
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x1127b744U),
                               bswap_32big(0x01aebceaU),
                               bswap_32big(0xef30fdbeU),
                               bswap_32big(0x66a9ef7dU));
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
            r_rsip_func101(bswap_32big(0xf96a8adeU), bswap_32big(0xde4a6497U), bswap_32big(0x2727a3b0U),
                           bswap_32big(0x4c6b3508U));
        }

        WR1_PROG(REG_1600H, 0x38008820U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
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
        r_rsip_func100(bswap_32big(0xbeb627e0U), bswap_32big(0xf4933a17U), bswap_32big(0x7c6938baU),
                       bswap_32big(0x68195303U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xfb0d5ee0U), bswap_32big(0x9d70c257U), bswap_32big(0x68d4581fU),
                           bswap_32big(0xdc91e2cfU));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x0b3e0210U), bswap_32big(0x91c5ad54U), bswap_32big(0xd4a0a51cU),
                           bswap_32big(0x255d5acaU));
            WR1_PROG(REG_1014H, 0x00000250U);
            r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040004U);
            WR1_PROG(REG_1404H, 0x11400000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0001dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);
            r_rsip_subfunc005(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000200U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040002U);
            r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x23c32775U), bswap_32big(0x17f918e5U), bswap_32big(0xa9b8cef6U),
                           bswap_32big(0xeebc2bedU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xc5c541e1U),
                               bswap_32big(0xc8c2d5a8U),
                               bswap_32big(0x892c354dU),
                               bswap_32big(0x53d4f1cfU));
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x19bac63dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xcab187f1U),
                               bswap_32big(0xde9f4002U),
                               bswap_32big(0xdba1dec5U),
                               bswap_32big(0xbbf42f55U));
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
