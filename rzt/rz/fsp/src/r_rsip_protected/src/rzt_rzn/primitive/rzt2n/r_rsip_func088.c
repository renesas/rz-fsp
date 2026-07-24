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

void r_rsip_func088 (void)
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
    r_rsip_func100(bswap_32big(0xaf90e7e8U),
                   bswap_32big(0xfcf2308aU),
                   bswap_32big(0x62f5d9aeU),
                   bswap_32big(0x818c86ebU));
    WR1_PROG(REG_1404H, 0x11400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0001dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000430U, 0x0404000aU);
    r_rsip_subfunc006(0x00000020U, 0x00000430U, 0x04040010U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xc43d4f23U),
                   bswap_32big(0xd183ad2aU),
                   bswap_32big(0x01aa9108U),
                   bswap_32big(0x354a1c7bU));
    WR1_PROG(REG_1404H, 0x10f00000U);
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
    WR1_PROG(REG_101CH, 0x00000430U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x04040004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x14380000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0001dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000480U, 0x00000458U, 0x00000160U, 0x04040009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
    WR1_PROG(REG_1014H, 0x00000340U);
    WR1_PROG(REG_1018H, 0x00000160U);
    r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x04040005U);
    r_rsip_subfunc001(0x00000110U, 0x00000458U, 0x00000480U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x30b8592aU),
                   bswap_32big(0xfec46db0U),
                   bswap_32big(0x5e44c014U),
                   bswap_32big(0xbff6ff37U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x13672756U), bswap_32big(0x35dd56e6U), bswap_32big(0x2522bb29U),
                       bswap_32big(0xe89e9084U));
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1004H, 0x04040004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x14100000U);
        r_rsip_subfunc003(0x00c00021U);
        r_rsip_subfunc001(0x00000890U, 0x00000430U, 0x000002c8U, 0x04040009U);
        r_rsip_subfunc001(0x00000070U, 0x00000430U, 0x000002f0U, 0x04040009U);
        r_rsip_func100(bswap_32big(0xa2e61e2cU), bswap_32big(0x28a61a44U), bswap_32big(0x7846f673U),
                       bswap_32big(0xc43c121bU));
        r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x04040015U, 0x00020000U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0001dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000480U, 0x00000110U, 0x00000520U, 0x0404000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x6ffd5bdcU), bswap_32big(0xa00a7082U), bswap_32big(0x0fa74746U),
                       bswap_32big(0x84e60ff0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x609008bbU), bswap_32big(0x0f66d258U), bswap_32big(0xd855ec9eU),
                           bswap_32big(0xd375ab44U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x671c2c72U), bswap_32big(0xbd389151U), bswap_32big(0x2d8adbadU),
                           bswap_32big(0x9ee1a72cU));
            r_rsip_subfunc005(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x04040015U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0001dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000570U, 0x00000110U, 0x000001b0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x4dffd72fU), bswap_32big(0x8e18f683U), bswap_32big(0xaddb7ba5U),
                           bswap_32big(0xc7826d2bU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x3d802c71U),
                               bswap_32big(0x1afbe4baU),
                               bswap_32big(0xfa391ca1U),
                               bswap_32big(0xc501bd95U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x420725f0U),
                               bswap_32big(0x6bfd3a3fU),
                               bswap_32big(0x441b9d27U),
                               bswap_32big(0x05294e8aU));
                WR1_PROG(REG_1014H, 0x00000570U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040004U);
                WR1_PROG(REG_1404H, 0x11400000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0404000aU);
                r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0404000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x00000520U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x00000548U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x04040002U);
                r_rsip_subfunc001(0x00000070U, 0x00000200U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000548U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x04040002U);
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_subfunc003(0x00c00021U);
                r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x00000520U, 0x04040009U);
                WR1_PROG(REG_1014H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000570U, 0x04040004U);
                WR1_PROG(REG_1404H, 0x11400000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_func100(bswap_32big(0x23010b09U),
                               bswap_32big(0xb71727ecU),
                               bswap_32big(0x4a091009U),
                               bswap_32big(0x9d3caad0U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x00000520U, 0x00000160U, 0x00000110U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x2a8bfac1U),
                                   bswap_32big(0x718e09bdU),
                                   bswap_32big(0x7907408cU),
                                   bswap_32big(0xa7f1e21cU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000430U, 0x00000520U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000520U, 0x00000430U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000458U, 0x00000548U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000548U, 0x00000458U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000570U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000570U, 0x00000480U, 0x00000110U, 0x0404000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x8a76e447U),
                                       bswap_32big(0x2776a4b9U),
                                       bswap_32big(0xd615c711U),
                                       bswap_32big(0x9f701c3bU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0xc2bde635U),
                                           bswap_32big(0x7e9e65b5U),
                                           bswap_32big(0x6e715c27U),
                                           bswap_32big(0xb2390805U));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x04040014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x63e00e8aU),
                                           bswap_32big(0x3e244b8eU),
                                           bswap_32big(0xcdad8826U),
                                           bswap_32big(0x4079a691U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11400000U);
                        r_rsip_subfunc003(0x00c00021U);
                        r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x04040009U);
                        r_rsip_subfunc001(0x00000458U, 0x00000160U, 0x00000228U, 0x04040009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x04040009U);
                        r_rsip_func101(bswap_32big(0x449d5ce2U),
                                       bswap_32big(0xfc36441aU),
                                       bswap_32big(0xe912c1ecU),
                                       bswap_32big(0x4575b0d8U));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11400000U);
                    r_rsip_subfunc003(0x00c00021U);
                    r_rsip_subfunc001(0x00000520U, 0x00000160U, 0x00000200U, 0x04040009U);
                    r_rsip_subfunc001(0x00000548U, 0x00000160U, 0x00000228U, 0x04040009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x04040009U);
                    r_rsip_func101(bswap_32big(0x51817fabU),
                                   bswap_32big(0x4a4a56acU),
                                   bswap_32big(0x7ca049bbU),
                                   bswap_32big(0xd647a639U));
                }

                WR1_PROG(REG_1404H, 0x12d00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x7191b3aaU),
                               bswap_32big(0xbd084963U),
                               bswap_32big(0xa78783f9U),
                               bswap_32big(0xcb180520U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x61da7edcU),
                                   bswap_32big(0x494236e0U),
                                   bswap_32big(0xf9c5e695U),
                                   bswap_32big(0xa1964182U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x7fce8d37U),
                                   bswap_32big(0x561ccfabU),
                                   bswap_32big(0x71bc20beU),
                                   bswap_32big(0xb548895bU));
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
                    WR1_PROG(REG_1014H, 0x00000228U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x000002f0U, 0x04040002U);
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x5bbd746cU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x50ea3324U),
                                   bswap_32big(0xfccd7b00U),
                                   bswap_32big(0x91e7faf8U),
                                   bswap_32big(0x3abb782cU));
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x5bbd746cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
