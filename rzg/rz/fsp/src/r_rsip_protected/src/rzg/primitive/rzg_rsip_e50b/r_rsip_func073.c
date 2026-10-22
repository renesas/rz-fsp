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

void r_rsip_func073 (const uint32_t ARG1[])
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
    WR1_PROG(REG_1600H, 0x0000377dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    r_rsip_subfunc009(bswap_32big(0x0000f073U));
    r_rsip_func101(bswap_32big(0xb3e01930U),
                   bswap_32big(0x181a5cf5U),
                   bswap_32big(0x9fe7cd93U),
                   bswap_32big(0x56e18803U));
    r_rsip_func086(ARG1);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
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
    r_rsip_func100(bswap_32big(0xa79849d9U),
                   bswap_32big(0x4f31d3acU),
                   bswap_32big(0x42ce51a0U),
                   bswap_32big(0x7b8b279bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xce3226faU), bswap_32big(0xec621419U), bswap_32big(0x276ba60fU),
                       bswap_32big(0xfcf9f6e9U));
    }
    else
    {
        r_rsip_func100(bswap_32big(0x2cae174cU), bswap_32big(0x91ff33caU), bswap_32big(0x0364e208U),
                       bswap_32big(0x9dfbab73U));
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
        r_rsip_subfunc009(bswap_32big(0x0000f073U));
        r_rsip_func101(bswap_32big(0x48b644f9U), bswap_32big(0x031480efU), bswap_32big(0x68006e1bU),
                       bswap_32big(0xf45fa0e5U));
        r_rsip_func087(ARG1);
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
        r_rsip_func100(bswap_32big(0xcfcad873U), bswap_32big(0x686769a7U), bswap_32big(0x9bcdd154U),
                       bswap_32big(0x02669270U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            WR1_PROG(REG_1018H, 0x00000a70U);
            r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x04040013U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0x2ef4247fU), bswap_32big(0xed00722bU), bswap_32big(0x9341348fU),
                           bswap_32big(0x38e9878fU));
        }
        else
        {
            WR1_PROG(REG_1014H, 0x00000b60U);
            r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x04040014U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func101(bswap_32big(0xa282b3b5U), bswap_32big(0x7fc84ce7U), bswap_32big(0x8f2657c7U),
                           bswap_32big(0x3c1d8e9fU));
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
                r_rsip_func100(bswap_32big(0x0a7ba7d7U),
                               bswap_32big(0x29e9c251U),
                               bswap_32big(0x6976d236U),
                               bswap_32big(0x2141abf1U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x04040014U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    r_rsip_func101(bswap_32big(0xc92b6344U),
                                   bswap_32big(0x3cd2a340U),
                                   bswap_32big(0x87e835a8U),
                                   bswap_32big(0x9520f9c8U));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x5b6a516aU),
                                   bswap_32big(0x9d1b3e6eU),
                                   bswap_32big(0xc0d4e2e5U),
                                   bswap_32big(0x80967c56U));
                }

                WR1_PROG(REG_1600H, 0x38000ca5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0x7bcac99dU),
                               bswap_32big(0x6afb3195U),
                               bswap_32big(0x04e6cb37U),
                               bswap_32big(0x72f5191dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func100(bswap_32big(0xdfb5f7dbU),
                                   bswap_32big(0x2a5257cdU),
                                   bswap_32big(0x47f11604U),
                                   bswap_32big(0xd95a7f0fU));
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
                        r_rsip_func101(bswap_32big(0x0bc67f7cU),
                                       bswap_32big(0xfe842e87U),
                                       bswap_32big(0x1937af61U),
                                       bswap_32big(0x2ddd3a60U));
                    }
                    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000b10U, 0x00000160U, 0x00000430U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b38U, 0x00000160U, 0x00000458U, 0x04040009U);
                        r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x90a2c769U),
                                       bswap_32big(0x336775b9U),
                                       bswap_32big(0xbc808ba2U),
                                       bswap_32big(0xfb41fb46U));
                    }
                    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                    {
                        r_rsip_subfunc001(0x00000c00U, 0x00000160U, 0x00000430U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c28U, 0x00000160U, 0x00000458U, 0x04040009U);
                        r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x78dca62eU),
                                       bswap_32big(0x0ae2528eU),
                                       bswap_32big(0xad04d37bU),
                                       bswap_32big(0xd10c8043U));
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
                    r_rsip_func100(bswap_32big(0x595d3abeU),
                                   bswap_32big(0x5e9fc873U),
                                   bswap_32big(0x63955cd8U),
                                   bswap_32big(0x8422e7ecU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0x55dd5a54U),
                                       bswap_32big(0x244c95e2U),
                                       bswap_32big(0xb0a98aacU),
                                       bswap_32big(0xa099f8bbU));
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
                            r_rsip_func100(bswap_32big(0x0e2938b6U),
                                           bswap_32big(0xb9be6b15U),
                                           bswap_32big(0x0aa55923U),
                                           bswap_32big(0x6093b4efU));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                WR1_PROG(REG_1018H, 0x00000480U);
                                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040013U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0xc8a16e3fU), bswap_32big(0x9a333290U),
                                               bswap_32big(0x47ef7000U), bswap_32big(0x3c5f3d81U));
                            }
                            else
                            {
                                WR1_PROG(REG_1014H, 0x00000250U);
                                r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x04040014U);
                                WR1_PROG(REG_143CH, 0x00000d00U);
                                r_rsip_func101(bswap_32big(0x9abd8435U), bswap_32big(0xbb51a9d6U),
                                               bswap_32big(0xcaab1805U), bswap_32big(0x7f88de86U));
                            }
                        }
                        else
                        {
                            r_rsip_func101(bswap_32big(0xe9cd9864U),
                                           bswap_32big(0xe5c1385fU),
                                           bswap_32big(0x531685d8U),
                                           bswap_32big(0x9b617799U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_subfunc003(0x00c00021U);
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x04040009U);
                        r_rsip_subfunc001(0x00000458U, 0x00000160U, 0x00000228U, 0x04040009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x8ef679d7U),
                                       bswap_32big(0x44614c7aU),
                                       bswap_32big(0x1a414fa1U),
                                       bswap_32big(0xa0d58a34U));
                    }
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x7196b396U),
                                   bswap_32big(0xf54e7415U),
                                   bswap_32big(0xaef88a79U),
                                   bswap_32big(0x2f8d7315U));
                }

                WR1_PROG(REG_1600H, 0x00002c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x82d7c601U),
                               bswap_32big(0xac287625U),
                               bswap_32big(0x00d6a38cU),
                               bswap_32big(0x76d04e70U));
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
            r_rsip_func101(bswap_32big(0x9f3f0c62U), bswap_32big(0xe71a04aeU), bswap_32big(0xde385bb6U),
                           bswap_32big(0x42f06830U));
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
        r_rsip_func100(bswap_32big(0xeedfd6a5U), bswap_32big(0x750e37d3U), bswap_32big(0x34e42e06U),
                       bswap_32big(0xe4000607U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc7e140abU), bswap_32big(0x78a365beU), bswap_32big(0x3a3d3224U),
                           bswap_32big(0x92cf78c0U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xb69f1debU), bswap_32big(0x01453000U), bswap_32big(0x4e1327bdU),
                           bswap_32big(0xfd2c652bU));
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
            r_rsip_func100(bswap_32big(0x6d219957U), bswap_32big(0x4cd4635eU), bswap_32big(0x42a458cdU),
                           bswap_32big(0x697a034eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xd26e1cffU),
                               bswap_32big(0x5fa11737U),
                               bswap_32big(0x4fbbc1ffU),
                               bswap_32big(0xb5a3713fU));
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x9ba0d38fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x541651f8U),
                               bswap_32big(0xc3356e23U),
                               bswap_32big(0xa30380faU),
                               bswap_32big(0xdf8d3a53U));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x9ba0d38fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x000037bbU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
