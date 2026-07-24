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
    r_rsip_func100(bswap_32big(0x937ade31U),
                   bswap_32big(0x5f88505eU),
                   bswap_32big(0xb59816aaU),
                   bswap_32big(0x8bab14a4U));
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
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xb4c0b566U),
                   bswap_32big(0x746382a1U),
                   bswap_32big(0x482e1148U),
                   bswap_32big(0x2bdb61cfU));
    WR1_PROG(REG_1404H, 0x10c80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x4b7d875cU),
                   bswap_32big(0x86276c2aU),
                   bswap_32big(0xd610865dU),
                   bswap_32big(0x5d2ce683U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x18744555U),
                   bswap_32big(0x7b22971bU),
                   bswap_32big(0xd41f8f4eU),
                   bswap_32big(0x2a59964bU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x9ce0c62dU),
                   bswap_32big(0x92d6cf4aU),
                   bswap_32big(0x1e06c60fU),
                   bswap_32big(0x3644a47bU));
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
    r_rsip_subfunc003(0x00c20011U);
    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x000003e0U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x09090004U);
    WR1_PROG(REG_1000H, 0x00010001U);
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
    r_rsip_func100(bswap_32big(0x9a6dfbf6U),
                   bswap_32big(0xe194bce1U),
                   bswap_32big(0xfb7caa42U),
                   bswap_32big(0xab4484d2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa661e8b0U), bswap_32big(0xcb05a9b8U), bswap_32big(0x5d09dfe5U),
                       bswap_32big(0xd9f9c75dU));
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1004H, 0x09090004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x13980000U);
        r_rsip_subfunc003(0x00c00049U);
        r_rsip_subfunc001(0x00000890U, 0x000003e0U, 0x000002a0U, 0x09090009U);
        r_rsip_subfunc001(0x00000070U, 0x000003e0U, 0x000002f0U, 0x09090009U);
        r_rsip_func100(bswap_32big(0xd3b4128eU), bswap_32big(0xe8032fb3U), bswap_32big(0x835ef5edU),
                       bswap_32big(0x44d6d8f1U));
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
        r_rsip_func100(bswap_32big(0xd7e8533aU), bswap_32big(0x1f9c1d2dU), bswap_32big(0xc15539c9U),
                       bswap_32big(0x755ab0bcU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x704d2fc0U), bswap_32big(0x3004109fU), bswap_32big(0x57583629U),
                           bswap_32big(0x19fc02d9U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x15ae883cU), bswap_32big(0x4ea3314cU), bswap_32big(0xee4bc5e0U),
                           bswap_32big(0xb6b04e24U));
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
            r_rsip_func100(bswap_32big(0x3081b34dU), bswap_32big(0x3f4d38a3U), bswap_32big(0x19909ffcU),
                           bswap_32big(0xf73a555cU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x51179bbeU),
                               bswap_32big(0xe7df3e95U),
                               bswap_32big(0xff706b27U),
                               bswap_32big(0x53d4e267U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x793604d9U),
                               bswap_32big(0xef92e80aU),
                               bswap_32big(0x81a5fab5U),
                               bswap_32big(0x12e8674fU));
                WR1_PROG(REG_1014H, 0x00000570U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x09090004U);
                WR1_PROG(REG_1404H, 0x11180000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c00045U);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);
                r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000004d0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x09090002U);
                WR1_PROG(REG_1014H, 0x00000520U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x09090002U);
                r_rsip_subfunc001(0x00000070U, 0x00000200U, 0x00000110U, 0x0909000aU);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000520U, 0x09090002U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x09090002U);
                WR1_PROG(REG_1404H, 0x11180000U);
                r_rsip_subfunc003(0x00c00049U);
                r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x000004d0U, 0x09090009U);
                WR1_PROG(REG_1014H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000570U, 0x09090004U);
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
                r_rsip_func100(bswap_32big(0x430f0d11U),
                               bswap_32big(0xc0298d39U),
                               bswap_32big(0x25de0787U),
                               bswap_32big(0x501aade7U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x000004d0U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x9aab4effU),
                                   bswap_32big(0xc3c88e39U),
                                   bswap_32big(0xd990c8a8U),
                                   bswap_32big(0x0a271688U));
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
                        r_rsip_func100(bswap_32big(0xb560f2f0U),
                                       bswap_32big(0x271477e0U),
                                       bswap_32big(0xefa06185U),
                                       bswap_32big(0x9b22eb93U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x09090013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x77fbb318U),
                                           bswap_32big(0x17a53c41U),
                                           bswap_32big(0xa7c57712U),
                                           bswap_32big(0x455cddacU));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0xc62cd8e0U),
                                           bswap_32big(0x0fafc547U),
                                           bswap_32big(0xb971b188U),
                                           bswap_32big(0x3926f7d5U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11180000U);
                        r_rsip_subfunc003(0x00c00049U);
                        r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x000001b0U, 0x09090009U);
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x09090009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x09090009U);
                        r_rsip_func101(bswap_32big(0x4fe84c5dU),
                                       bswap_32big(0x3c748a0bU),
                                       bswap_32big(0xcaa73be1U),
                                       bswap_32big(0x1e35460bU));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11180000U);
                    r_rsip_subfunc003(0x00c00049U);
                    r_rsip_subfunc001(0x000004d0U, 0x00000160U, 0x000001b0U, 0x09090009U);
                    r_rsip_subfunc001(0x00000520U, 0x00000160U, 0x00000200U, 0x09090009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x09090009U);
                    r_rsip_func101(bswap_32big(0xd82a9c03U),
                                   bswap_32big(0xacd335baU),
                                   bswap_32big(0x8dae7762U),
                                   bswap_32big(0xc9eb9c6cU));
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
                r_rsip_func100(bswap_32big(0x42d3f1c7U),
                               bswap_32big(0xef87bd79U),
                               bswap_32big(0xe1b3a08aU),
                               bswap_32big(0x3f357e10U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xb967656eU),
                                   bswap_32big(0xcb94018aU),
                                   bswap_32big(0x480404b0U),
                                   bswap_32big(0x71b8c8e2U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x80e49b1bU),
                                   bswap_32big(0x6c612dbfU),
                                   bswap_32big(0xe5b5e429U),
                                   bswap_32big(0xa4f421b8U));
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x09090004U);
                    WR1_PROG(REG_1404H, 0x11180000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                    r_rsip_subfunc003(0x00c00045U);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0909000aU);
                    r_rsip_subfunc005(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0909000fU, 0x00020000U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    WR1_PROG(REG_1014H, 0x000001b0U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x09090002U);
                    WR1_PROG(REG_1014H, 0x00000200U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x000002f0U, 0x09090002U);
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x6ca63b96U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xd1a822c6U),
                                   bswap_32big(0x8fdaf6e1U),
                                   bswap_32big(0x882db6baU),
                                   bswap_32big(0x6293199aU));
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x6ca63b96U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
