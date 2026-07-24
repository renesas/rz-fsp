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
    r_rsip_func100(bswap_32big(0x96d116b5U),
                   bswap_32big(0xe0bad1f0U),
                   bswap_32big(0x9af731e7U),
                   bswap_32big(0xc190e5b3U));
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
    r_rsip_func100(bswap_32big(0x39f22b69U),
                   bswap_32big(0xcbb92ec3U),
                   bswap_32big(0xb90e96ecU),
                   bswap_32big(0x7f24370fU));
    WR1_PROG(REG_1404H, 0x10e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x13751a08U),
                   bswap_32big(0xd9501088U),
                   bswap_32big(0x2d05caecU),
                   bswap_32big(0x702a5ceeU));
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
    r_rsip_func100(bswap_32big(0x210c4c8eU),
                   bswap_32big(0xeb406da7U),
                   bswap_32big(0x6a05614eU),
                   bswap_32big(0xa21f92c9U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xe53b0320U), bswap_32big(0xd22f1736U), bswap_32big(0xfd2756c0U),
                       bswap_32big(0x3e856a15U));
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
        r_rsip_func100(bswap_32big(0x8ca41f75U), bswap_32big(0x0faeec1aU), bswap_32big(0x0c1b847cU),
                       bswap_32big(0x9b75ae00U));
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
        r_rsip_func100(bswap_32big(0x783ce8daU), bswap_32big(0xbee5befeU), bswap_32big(0x8f787e91U),
                       bswap_32big(0xa9acb1acU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x069286ebU), bswap_32big(0x8fd7c639U), bswap_32big(0xe7ad718aU),
                           bswap_32big(0x98002168U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xf220a573U), bswap_32big(0xd139f6bdU), bswap_32big(0x82b3604cU),
                           bswap_32big(0xadde800bU));
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
            r_rsip_func100(bswap_32big(0x6511d2ebU), bswap_32big(0x0c62346fU), bswap_32big(0x0ce6c42dU),
                           bswap_32big(0xd21a7f7cU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xa867f112U),
                               bswap_32big(0x6689dd1fU),
                               bswap_32big(0xe48af96fU),
                               bswap_32big(0xfeeaf03fU));
            }
            else
            {
                r_rsip_func100(bswap_32big(0xe4d80a22U),
                               bswap_32big(0xe98c43d1U),
                               bswap_32big(0x50b455b8U),
                               bswap_32big(0x6b634ddaU));
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
                r_rsip_func100(bswap_32big(0x939ae434U),
                               bswap_32big(0xbea5f7f7U),
                               bswap_32big(0xde4434f7U),
                               bswap_32big(0x8f25b730U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x000004f0U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0xc674fda8U),
                                   bswap_32big(0x52a44361U),
                                   bswap_32big(0x7010e0f9U),
                                   bswap_32big(0xe27ec82fU));
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
                        r_rsip_func100(bswap_32big(0x1b810201U),
                                       bswap_32big(0xc87b19e2U),
                                       bswap_32big(0xcbbd947bU),
                                       bswap_32big(0x62dc3e45U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x07070013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0xa534f14bU),
                                           bswap_32big(0x7c211a54U),
                                           bswap_32big(0xc999b101U),
                                           bswap_32big(0x550d5a7eU));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x07070014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0xb89dd702U),
                                           bswap_32big(0x6ce4705fU),
                                           bswap_32big(0xa7517b54U),
                                           bswap_32big(0x4fca1e13U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_subfunc003(0x00c00031U);
                        r_rsip_subfunc001(0x00000400U, 0x00000160U, 0x000001d0U, 0x06060009U);
                        r_rsip_subfunc001(0x00000440U, 0x00000160U, 0x00000210U, 0x06060009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);
                        r_rsip_func101(bswap_32big(0xf1d9d3a1U),
                                       bswap_32big(0x7ec5a710U),
                                       bswap_32big(0x92cae1c7U),
                                       bswap_32big(0x3c7ee126U));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11300000U);
                    r_rsip_subfunc003(0x00c00031U);
                    r_rsip_subfunc001(0x000004f0U, 0x00000160U, 0x000001d0U, 0x06060009U);
                    r_rsip_subfunc001(0x00000530U, 0x00000160U, 0x00000210U, 0x06060009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x06060009U);
                    r_rsip_func101(bswap_32big(0xb2b976d5U),
                                   bswap_32big(0xba015b01U),
                                   bswap_32big(0xa155373cU),
                                   bswap_32big(0x54052a78U));
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
                r_rsip_func100(bswap_32big(0x56000a1dU),
                               bswap_32big(0x0c1c0a1aU),
                               bswap_32big(0xf631886fU),
                               bswap_32big(0x94dcaf14U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x5dc67e40U),
                                   bswap_32big(0xe14da0cfU),
                                   bswap_32big(0x72bda5e5U),
                                   bswap_32big(0xc005c53eU));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x1e5fc251U),
                                   bswap_32big(0x92b75bb9U),
                                   bswap_32big(0xb9156f1fU),
                                   bswap_32big(0x890624efU));
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
                    r_rsip_func101(bswap_32big(0x6c9b802aU),
                                   bswap_32big(0x35d81146U),
                                   bswap_32big(0xa433cba0U),
                                   bswap_32big(0x23c49b9bU));
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
