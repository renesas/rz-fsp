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

void r_rsip_func071 (void)
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
    r_rsip_func100(bswap_32big(0xeb05580cU),
                   bswap_32big(0x2f8876cdU),
                   bswap_32big(0xab463134U),
                   bswap_32big(0xb83e29fcU));
    WR1_PROG(REG_1404H, 0x11200000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x000003f0U, 0x0808000aU);
    r_rsip_subfunc006(0x00000020U, 0x000003f0U, 0x08080010U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x1fc60bdeU),
                   bswap_32big(0x2dd0dcc8U),
                   bswap_32big(0xcc99f726U),
                   bswap_32big(0x68af5eabU));
    WR1_PROG(REG_1404H, 0x10d00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xd1cda61bU),
                   bswap_32big(0x1190d578U),
                   bswap_32big(0x3108fef4U),
                   bswap_32big(0x65e40816U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x0ef8fdd3U),
                   bswap_32big(0xaed57d43U),
                   bswap_32big(0x4c6b8bf4U),
                   bswap_32big(0x7ab8f9c1U));
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
    WR1_PROG(REG_101CH, 0x000003f0U);
    WR1_PROG(REG_1020H, 0x00000480U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x08080004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x13f80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000480U, 0x00000438U, 0x00000160U, 0x08080009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x08080010U);
    WR1_PROG(REG_1014H, 0x00000340U);
    WR1_PROG(REG_1018H, 0x00000160U);
    r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x08080005U);
    r_rsip_subfunc001(0x00000110U, 0x00000438U, 0x00000480U, 0x0808000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0xdaa795f2U),
                   bswap_32big(0xfdbae6eeU),
                   bswap_32big(0x215b264eU),
                   bswap_32big(0x94f9e998U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xfc05984eU), bswap_32big(0x4916c191U), bswap_32big(0x2292d06dU),
                       bswap_32big(0x8ce4b06cU));
    }
    else
    {
        WR1_PROG(REG_1014H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000250U);
        WR1_PROG(REG_1010H, 0x00000018U);
        WR1_PROG(REG_1004H, 0x08080004U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x13b00000U);
        r_rsip_subfunc003(0x00c00041U);
        r_rsip_subfunc001(0x00000890U, 0x000003f0U, 0x000002a8U, 0x08080009U);
        r_rsip_subfunc001(0x00000070U, 0x000003f0U, 0x000002f0U, 0x08080009U);
        r_rsip_func100(bswap_32big(0xf302aac4U), bswap_32big(0x477e4cffU), bswap_32big(0xd9320646U),
                       bswap_32big(0xdb87324fU));
        r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x000002f0U, 0x00000480U, 0x08080015U, 0x00020000U);
        WR1_PROG(REG_143CH, 0x00000d00U);
        WR1_PROG(REG_1404H, 0x10d00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000480U, 0x00000110U, 0x000004e0U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xe6dcca52U), bswap_32big(0x8582279fU), bswap_32big(0x4e848796U),
                       bswap_32big(0xb9781c41U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd50b1bc5U), bswap_32big(0x364d8dd9U), bswap_32big(0x8a1220a3U),
                           bswap_32big(0xcb9bda92U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xe8e7273dU), bswap_32big(0xda201003U), bswap_32big(0x688e4d55U),
                           bswap_32big(0x32fcbc30U));
            r_rsip_subfunc005(0x00000250U, 0x00000160U, 0x000002f0U, 0x00000570U, 0x08080015U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0003dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000570U, 0x00000110U, 0x000001b0U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x4917e4f5U), bswap_32big(0xd8c88789U), bswap_32big(0xe4a49315U),
                           bswap_32big(0xffbec775U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x46fd9104U),
                               bswap_32big(0xfdb0c225U),
                               bswap_32big(0x13de85e5U),
                               bswap_32big(0xf5c53ee4U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0xfe588c0fU),
                               bswap_32big(0xccf5ba54U),
                               bswap_32big(0xa7dc4b3dU),
                               bswap_32big(0xf46e11f3U));
                WR1_PROG(REG_1014H, 0x00000570U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x08080004U);
                WR1_PROG(REG_1404H, 0x11200000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);
                r_rsip_subfunc005(0x00000250U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000004e0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x08080002U);
                WR1_PROG(REG_1014H, 0x00000528U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x08080002U);
                r_rsip_subfunc001(0x00000070U, 0x00000200U, 0x00000110U, 0x0808000aU);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000528U, 0x08080002U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x08080002U);
                WR1_PROG(REG_1404H, 0x11200000U);
                r_rsip_subfunc003(0x00c00041U);
                r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x000004e0U, 0x08080009U);
                WR1_PROG(REG_1014H, 0x00000390U);
                r_rsip_subfunc002(0x00000070U, 0x00000570U, 0x08080004U);
                WR1_PROG(REG_1404H, 0x11200000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x000003f0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00a10000U);
                r_rsip_func100(bswap_32big(0x9efcf96cU),
                               bswap_32big(0xc65ea1d7U),
                               bswap_32big(0xb860753dU),
                               bswap_32big(0x03ffde85U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x000004e0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x2c46e803U),
                                   bswap_32big(0x0cc8f33bU),
                                   bswap_32big(0x9170cc1bU),
                                   bswap_32big(0x94e16bd2U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x000003f0U, 0x000004e0U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x000004e0U, 0x000003f0U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000438U, 0x00000528U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000528U, 0x00000438U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000480U, 0x00000570U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000570U, 0x00000480U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x58ddafd6U),
                                       bswap_32big(0x85292b55U),
                                       bswap_32big(0xed17237fU),
                                       bswap_32big(0xf084eea2U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x08080013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x19771782U),
                                           bswap_32big(0x90b7046fU),
                                           bswap_32big(0x86c076e6U),
                                           bswap_32big(0x4e8877c0U));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x08080014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x6344ef97U),
                                           bswap_32big(0x5c3addd0U),
                                           bswap_32big(0x4133d9b7U),
                                           bswap_32big(0x132924d7U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_subfunc003(0x00c00041U);
                        r_rsip_subfunc001(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);
                        r_rsip_subfunc001(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);
                        r_rsip_func101(bswap_32big(0xc450404fU),
                                       bswap_32big(0xd07a5ff6U),
                                       bswap_32big(0xaa0762e1U),
                                       bswap_32big(0x8f97a8cfU));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11200000U);
                    r_rsip_subfunc003(0x00c00041U);
                    r_rsip_subfunc001(0x000004e0U, 0x00000160U, 0x000001c0U, 0x08080009U);
                    r_rsip_subfunc001(0x00000528U, 0x00000160U, 0x00000208U, 0x08080009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x08080009U);
                    r_rsip_func101(bswap_32big(0x3cf574ddU),
                                   bswap_32big(0x79b97e2bU),
                                   bswap_32big(0x99d5accfU),
                                   bswap_32big(0x037be511U));
                }

                WR1_PROG(REG_1404H, 0x12b00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000250U, 0x000002f0U, 0x000002a0U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x5b11a498U),
                               bswap_32big(0xde39a1f2U),
                               bswap_32big(0x1f92090dU),
                               bswap_32big(0xec2b7625U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x76d8650bU),
                                   bswap_32big(0x709edc07U),
                                   bswap_32big(0xa6fcca2dU),
                                   bswap_32big(0xe0aab690U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0xfe78a392U),
                                   bswap_32big(0x738cd53cU),
                                   bswap_32big(0xc80fe591U),
                                   bswap_32big(0xe22e8081U));
                    WR1_PROG(REG_1014H, 0x00000250U);
                    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x08080004U);
                    WR1_PROG(REG_1404H, 0x11200000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                    r_rsip_subfunc003(0x00c0003dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    r_rsip_subfunc005(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0808000fU, 0x00020000U);
                    WR1_PROG(REG_143CH, 0x00000d00U);
                    WR1_PROG(REG_1014H, 0x000001c0U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x08080002U);
                    WR1_PROG(REG_1014H, 0x00000208U);
                    WR1_PROG(REG_1018H, 0x00000160U);
                    r_rsip_subfunc002(0x00000070U, 0x000002f0U, 0x08080002U);
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0xfc9e07f7U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x314b7e18U),
                                   bswap_32big(0xe5b4874dU),
                                   bswap_32big(0x74aa19e6U),
                                   bswap_32big(0x287e9628U));
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xfc9e07f7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
