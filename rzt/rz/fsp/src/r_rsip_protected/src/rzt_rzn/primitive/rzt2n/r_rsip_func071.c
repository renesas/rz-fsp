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
    r_rsip_func100(bswap_32big(0xd9bcb63fU),
                   bswap_32big(0xe03e4445U),
                   bswap_32big(0x377f8147U),
                   bswap_32big(0xb6b209ccU));
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
    r_rsip_func100(bswap_32big(0x4f0d6acaU),
                   bswap_32big(0x36db8a34U),
                   bswap_32big(0x4f80b858U),
                   bswap_32big(0xe6b12f9cU));
    WR1_PROG(REG_1404H, 0x10d00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xf05bef76U),
                   bswap_32big(0x2f921446U),
                   bswap_32big(0x778767e4U),
                   bswap_32big(0xb27d2414U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x2226c124U),
                   bswap_32big(0x8b0d89d3U),
                   bswap_32big(0x4fc2644eU),
                   bswap_32big(0xc1eda042U));
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
    r_rsip_func100(bswap_32big(0x0cad6a17U),
                   bswap_32big(0x00794b17U),
                   bswap_32big(0x81d4dae0U),
                   bswap_32big(0x1a0d4161U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xaa6760eaU), bswap_32big(0x88e6123dU), bswap_32big(0x49c9a044U),
                       bswap_32big(0x63106b62U));
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
        r_rsip_func100(bswap_32big(0xc779d44dU), bswap_32big(0x522b6a57U), bswap_32big(0x2e989005U),
                       bswap_32big(0x2c4690cfU));
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
        r_rsip_func100(bswap_32big(0xfa6f4f94U), bswap_32big(0x1605870bU), bswap_32big(0xc9a6a8adU),
                       bswap_32big(0x50aa7bc2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd78f33e7U), bswap_32big(0xf6dfad2fU), bswap_32big(0x8f7d9927U),
                           bswap_32big(0xd2c5669aU));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xe2bcdd42U), bswap_32big(0x343d6b57U), bswap_32big(0x674dbc9aU),
                           bswap_32big(0x05014150U));
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
            r_rsip_func100(bswap_32big(0x2cb8b897U), bswap_32big(0x967fb07eU), bswap_32big(0x477f4321U),
                           bswap_32big(0x0c30d4b6U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x98d42f38U),
                               bswap_32big(0xa73f74ffU),
                               bswap_32big(0x16bc74c8U),
                               bswap_32big(0xd07e55efU));
            }
            else
            {
                r_rsip_func100(bswap_32big(0xf58f84e0U),
                               bswap_32big(0x9ae8d500U),
                               bswap_32big(0x576bbb74U),
                               bswap_32big(0xb4ec3cb5U));
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
                r_rsip_func100(bswap_32big(0xab14e1a2U),
                               bswap_32big(0xf68f6962U),
                               bswap_32big(0xeca8b4a9U),
                               bswap_32big(0x3efa56e2U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x000004e0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x69df4361U),
                                   bswap_32big(0xa2ebbad9U),
                                   bswap_32big(0x9dff9821U),
                                   bswap_32big(0x96b7901fU));
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
                        r_rsip_func100(bswap_32big(0x6ada10f8U),
                                       bswap_32big(0x0541ff50U),
                                       bswap_32big(0x0223dea5U),
                                       bswap_32big(0xda80326cU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            WR1_PROG(REG_1018H, 0x00000570U);
                            r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x08080013U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0x7d9938abU),
                                           bswap_32big(0xf17318a1U),
                                           bswap_32big(0xc6f35ce5U),
                                           bswap_32big(0x5a8e2ff8U));
                        }
                        else
                        {
                            WR1_PROG(REG_1014H, 0x00000480U);
                            r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x08080014U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_func101(bswap_32big(0xdb6e5c43U),
                                           bswap_32big(0xe42b0931U),
                                           bswap_32big(0x17f9d322U),
                                           bswap_32big(0x9a44f586U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_subfunc003(0x00c00041U);
                        r_rsip_subfunc001(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);
                        r_rsip_subfunc001(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);
                        r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);
                        r_rsip_func101(bswap_32big(0xf04151bcU),
                                       bswap_32big(0x5abe29afU),
                                       bswap_32big(0xcf6ffa30U),
                                       bswap_32big(0xb525f12cU));
                    }
                }
                else
                {
                    WR1_PROG(REG_1404H, 0x11200000U);
                    r_rsip_subfunc003(0x00c00041U);
                    r_rsip_subfunc001(0x000004e0U, 0x00000160U, 0x000001c0U, 0x08080009U);
                    r_rsip_subfunc001(0x00000528U, 0x00000160U, 0x00000208U, 0x08080009U);
                    r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x08080009U);
                    r_rsip_func101(bswap_32big(0xc17ee39cU),
                                   bswap_32big(0x3d5c2b22U),
                                   bswap_32big(0xa7ca22b8U),
                                   bswap_32big(0xa6075357U));
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
                r_rsip_func100(bswap_32big(0x8da58cffU),
                               bswap_32big(0xed79194aU),
                               bswap_32big(0x11eb6c97U),
                               bswap_32big(0xc5a3f112U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x12070645U),
                                   bswap_32big(0x055dec9dU),
                                   bswap_32big(0xb43c0567U),
                                   bswap_32big(0x8afcb0e9U));
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x28f7d80cU),
                                   bswap_32big(0xefd4f7daU),
                                   bswap_32big(0x2d2410b2U),
                                   bswap_32big(0xfefd099aU));
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
                    WR1_PROG(REG_1600H, 0x04e6f11cU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x3c3ee526U),
                                   bswap_32big(0xac7be7edU),
                                   bswap_32big(0x88913e71U),
                                   bswap_32big(0x589212acU));
                }
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x04e6f11cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
