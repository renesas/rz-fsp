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

void r_rsip_func089 (void)
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
    r_rsip_func100(bswap_32big(0x2babe948U),
                   bswap_32big(0xa760cf46U),
                   bswap_32big(0x8b92bb27U),
                   bswap_32big(0x2b7256e8U));
    WR1_PROG(REG_1404H, 0x11300000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000410U, 0x0606000aU);
    r_rsip_subfunc006(0x00000020U, 0x00000410U, 0x06060010U);
    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa034c710U),
                   bswap_32big(0x2190ce6dU),
                   bswap_32big(0x73bb64b8U),
                   bswap_32big(0x6cb47c86U));
    WR1_PROG(REG_1404H, 0x10e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x2fbf5693U),
                   bswap_32big(0xa84c0d3cU),
                   bswap_32big(0x2d94140fU),
                   bswap_32big(0x3ee1502eU));
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
    WR1_PROG(REG_101CH, 0x00000410U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x06060004U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x14180000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000480U, 0x00000448U, 0x00000160U, 0x06060009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x06060010U);
    WR1_PROG(REG_1014H, 0x00000340U);
    WR1_PROG(REG_1018H, 0x00000160U);
    r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x06060005U);
    r_rsip_subfunc001(0x00000110U, 0x00000448U, 0x00000480U, 0x0606000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x4a7615a2U),
                   bswap_32big(0xa995a844U),
                   bswap_32big(0xd8fa641aU),
                   bswap_32big(0x548f7b7dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa67f5b9eU), bswap_32big(0xee394a0bU), bswap_32big(0x98f82d65U),
                       bswap_32big(0x11a261a8U));
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1004H, 0x06060004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x13e00000U);
        r_rsip_subfunc003(0x00c00031U);
        r_rsip_subfunc001(0x00000890U, 0x00000410U, 0x000002b8U, 0x06060009U);
        WR1_PROG(REG_1404H, 0x14800000U);
        r_rsip_subfunc003(0x00c000f1U);
        r_rsip_subfunc001(0x00000390U, 0x00000410U, 0x00000980U, 0x06060009U);
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000538U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x15400000U);
        r_rsip_subfunc003(0x00c00025U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c2000dU);
        r_rsip_subfunc003(0x00020005U);
        WR1_PROG(REG_1014H, 0x00000538U);
        WR1_PROG(REG_1018H, 0x00000570U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000980U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000001e0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000500U);
        WR1_PROG(REG_1004H, 0x06060004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000218U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000538U);
        WR1_PROG(REG_1004H, 0x06060004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1014H, 0x00000500U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000001d0U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000538U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000210U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1004H, 0x06060004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x12500000U);
        r_rsip_subfunc003(0x00c000a1U);
        WR1_PROG(REG_1014H, 0x00000890U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000570U);
        WR1_PROG(REG_1004H, 0x06060004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000570U);
        WR1_PROG(REG_1018H, 0x00000980U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000002b0U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x00000070U, 0x00000410U, 0x000002f0U, 0x06060009U);
        r_rsip_func100(bswap_32big(0x15d7d5f5U), bswap_32big(0xd0a42190U), bswap_32big(0x6f42a40aU),
                       bswap_32big(0xdd71583fU));
        r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x07070015U, 0x00020000U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1404H, 0x10e00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0002dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000480U, 0x00000110U, 0x00000500U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x47eaeeeeU), bswap_32big(0x5a524c13U), bswap_32big(0x18e860c2U),
                       bswap_32big(0x39f93aa2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x94b7be83U), bswap_32big(0xacabd919U), bswap_32big(0xe11f5cbbU),
                           bswap_32big(0x11451312U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x4ff9f5e6U), bswap_32big(0xeb06e434U), bswap_32big(0x72b4bbc5U),
                           bswap_32big(0xdc908ff1U));
            r_rsip_subfunc005(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x07070015U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0002dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000570U, 0x00000110U, 0x000001b0U, 0x0606000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xce222dafU), bswap_32big(0xd19bacbcU), bswap_32big(0x76306bb7U),
                           bswap_32big(0xcab8afd6U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xd87d1670U),
                               bswap_32big(0x60e41e09U),
                               bswap_32big(0x6f5fe977U),
                               bswap_32big(0x29500088U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0xead9f878U),
                               bswap_32big(0xfa2e324aU),
                               bswap_32big(0x1ab37fd6U),
                               bswap_32big(0x487c6f4fU));
                WR1_PROG(REG_1014H, 0x00000570U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x07070004U);
                WR1_PROG(REG_1404H, 0x11300000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0002dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000160U);
                WR1_PROG(REG_1004H, 0x0606000fU);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000004f0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x07070002U);
                WR1_PROG(REG_1014H, 0x00000530U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x07070002U);
                r_rsip_subfunc001(0x00000070U, 0x00000200U, 0x00000110U, 0x0606000aU);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000980U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000530U);
                WR1_PROG(REG_1004H, 0x06060002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000980U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000110U);
                WR1_PROG(REG_1004H, 0x06060002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x11300000U);
                r_rsip_subfunc003(0x00c00031U);
                r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x000004f0U, 0x06060009U);
                WR1_PROG(REG_1014H, 0x00000980U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000570U);
                WR1_PROG(REG_1004H, 0x06060004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x11300000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0002dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000400U, 0x00000160U, 0x00000110U, 0x0606000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0606000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_func100(bswap_32big(0xcf2859e6U),
                               bswap_32big(0xde743a78U),
                               bswap_32big(0x9a5d9322U),
                               bswap_32big(0xae9fe882U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x000004f0U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x72865b7dU),
                                   bswap_32big(0x03dfa007U),
                                   bswap_32big(0x5f063694U),
                                   bswap_32big(0xc769f785U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000400U, 0x000004f0U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x000004f0U, 0x00000400U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000440U, 0x00000530U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000530U, 0x00000440U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000570U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000570U, 0x00000480U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x20210630U),
                                       bswap_32big(0xd0b82c0cU),
                                       bswap_32big(0x24f37817U),
                                       bswap_32big(0x795e4387U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x07070013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x6b0ac0f6U),
                                           bswap_32big(0xf561d602U),
                                           bswap_32big(0x2efb0b22U),
                                           bswap_32big(0x8290d8c4U));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x07070014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x2cb0a23cU),
                                           bswap_32big(0x95f95522U),
                                           bswap_32big(0xfbde3f55U),
                                           bswap_32big(0xcb8f6ac3U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_subfunc003(0x00c00031U);
                        r_rsip_subfunc001(0x00000400U, 0x00000160U, 0x000001d0U, 0x06060009U);
                        r_rsip_subfunc001(0x00000440U, 0x00000160U, 0x00000210U, 0x06060009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);
                        r_rsip_func101(bswap_32big(0x10f8fccaU),
                                       bswap_32big(0xfc6c930fU),
                                       bswap_32big(0xec014e88U),
                                       bswap_32big(0x490885e5U));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_subfunc003(0x00c00031U);
                    r_rsip_subfunc001(0x000004f0U, 0x00000160U, 0x000001d0U, 0x06060009U);
                    r_rsip_subfunc001(0x00000530U, 0x00000160U, 0x00000210U, 0x06060009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x06060009U);
                    r_rsip_func101(bswap_32big(0xc4954ee1U),
                                   bswap_32big(0x373a7cd4U),
                                   bswap_32big(0x8e5bbb61U),
                                   bswap_32big(0x048c88e5U));
                }

                WR1_PROG(REG_1014H, 0x000001d0U);
                r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x07070004U);
                WR1_PROG(REG_1014H, 0x00000210U);
                r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x07070004U);
                WR1_PROG(REG_1014H, 0x00000250U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x07070004U);
                WR1_PROG(REG_1404H, 0x11600000U);
                r_rsip_subfunc003(0x00c000f1U);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x000001e0U);
                WR1_PROG(REG_1004H, 0x06060002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000160U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000218U);
                WR1_PROG(REG_1004H, 0x06060002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x000002a0U);
                WR1_PROG(REG_1018H, 0x00000390U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000250U);
                WR1_PROG(REG_1004H, 0x06060002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12c00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0002dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0606000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x3ac54991U),
                               bswap_32big(0xc4529c31U),
                               bswap_32big(0xa3c803ceU),
                               bswap_32big(0xd3d615afU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xd759a741U),
                                   bswap_32big(0x50248e5aU),
                                   bswap_32big(0x2817c618U),
                                   bswap_32big(0xe58e4484U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x845c9003U),
                                   bswap_32big(0x8fb0d773U),
                                   bswap_32big(0x650b4fd0U),
                                   bswap_32big(0xe8d6c50dU));
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000002a0U);
                    WR1_PROG(REG_1004H, 0x06060004U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1404H, 0x11300000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                    r_rsip_subfunc003(0x00c0002dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_1014H, 0x000002a0U);
                    WR1_PROG(REG_1018H, 0x00000110U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000160U);
                    WR1_PROG(REG_1004H, 0x0606000fU);
                    WR1_PROG(REG_1408H, 0x00020000U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    WR1_PROG(REG_1014H, 0x000001e0U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000002a0U);
                    WR1_PROG(REG_1004H, 0x06060002U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1014H, 0x00000218U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000002f0U);
                    WR1_PROG(REG_1004H, 0x06060002U);
                    WR1_PROG(REG_1000H, 0x00010201U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x92f47a78U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xe3161b81U),
                                   bswap_32big(0x47272e14U),
                                   bswap_32big(0x06b8e8d8U),
                                   bswap_32big(0x85f344f6U));
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x92f47a78U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
