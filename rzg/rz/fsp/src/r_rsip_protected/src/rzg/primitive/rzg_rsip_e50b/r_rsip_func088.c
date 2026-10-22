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
    r_rsip_func100(bswap_32big(0xff082780U),
                   bswap_32big(0xf4c319abU),
                   bswap_32big(0xf6249295U),
                   bswap_32big(0x916c8960U));
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
    r_rsip_func100(bswap_32big(0x9ec21c24U),
                   bswap_32big(0xc6446ee8U),
                   bswap_32big(0x0ea23b5bU),
                   bswap_32big(0xd3c79ce6U));
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
    r_rsip_subfunc001(0x00000110U, 0x00000458U, 0x00000480U, 0x0404000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x89143a23U),
                   bswap_32big(0x868f9a5dU),
                   bswap_32big(0x8eb308f8U),
                   bswap_32big(0x91ee5478U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1404H, 0x14100000U);
        r_rsip_subfunc003(0x00c00071U);
        r_rsip_subfunc001(0x00000250U, 0x00000430U, 0x00000458U, 0x04040009U);
        r_rsip_func101(bswap_32big(0x5069534fU), bswap_32big(0x2d82b72aU), bswap_32big(0x81c68792U),
                       bswap_32big(0xa42df58dU));
    }
    else
    {
        r_rsip_func100(bswap_32big(0xd05776e5U), bswap_32big(0x749545ddU), bswap_32big(0x7bb4ad87U),
                       bswap_32big(0x15313af6U));
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
        r_rsip_func101(bswap_32big(0x85db0af5U), bswap_32big(0x568cbec0U), bswap_32big(0xc300792dU),
                       bswap_32big(0x1656fd0bU));
    }

    r_rsip_func100(bswap_32big(0x029341adU),
                   bswap_32big(0x57838dc9U),
                   bswap_32big(0x64db46e2U),
                   bswap_32big(0x2772f2e3U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xcf1cfb02U), bswap_32big(0x1094231cU), bswap_32big(0x1faa9de6U),
                       bswap_32big(0x9ce77f04U));
    }
    else
    {
        r_rsip_func100(bswap_32big(0xe0e5f8eaU), bswap_32big(0x9485c97fU), bswap_32big(0xa8c9fac3U),
                       bswap_32big(0x8218a104U));
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
        r_rsip_func100(bswap_32big(0x6281ff85U), bswap_32big(0x87b217feU), bswap_32big(0x83e4c51aU),
                       bswap_32big(0x5f0cff66U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc1ba6d55U), bswap_32big(0x314be3fcU), bswap_32big(0xe4c58be3U),
                           bswap_32big(0xe774e356U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xc0a3b175U), bswap_32big(0x19c5271cU), bswap_32big(0xc43327e4U),
                           bswap_32big(0x97c0ef1bU));
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
            r_rsip_subfunc002(0x00000070U, 0x00000520U, 0x04040002U);
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
            r_rsip_subfunc001(0x00000458U, 0x00000570U, 0x00000110U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000570U, 0x00000458U, 0x00000110U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x52345b5bU), bswap_32big(0xff8d55e2U), bswap_32big(0x0da10ad0U),
                           bswap_32big(0x4a99a86eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000480U);
                WR1_PROG(REG_1018H, 0x00000570U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0xcb9c0cb0U),
                               bswap_32big(0x75ae6bfdU),
                               bswap_32big(0x119b970eU),
                               bswap_32big(0x9ebbabe2U));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_subfunc003(0x00c00021U);
                r_rsip_subfunc001(0x00000520U, 0x00000160U, 0x00000200U, 0x04040009U);
                r_rsip_subfunc001(0x00000548U, 0x00000160U, 0x00000228U, 0x04040009U);
                r_rsip_subfunc001(0x00000570U, 0x00000160U, 0x00000250U, 0x04040009U);
                r_rsip_func101(bswap_32big(0xe4e7b5e2U),
                               bswap_32big(0x64f4e291U),
                               bswap_32big(0xb3cebce2U),
                               bswap_32big(0x18cef52aU));
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
            r_rsip_func100(bswap_32big(0xb53e7ec4U), bswap_32big(0x574ce587U), bswap_32big(0x6c52d26aU),
                           bswap_32big(0xf08b1c0dU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x9e8aefb7U),
                               bswap_32big(0x6622c44eU),
                               bswap_32big(0x1aa13912U),
                               bswap_32big(0x6ae183b2U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x235cee87U),
                               bswap_32big(0x321c8134U),
                               bswap_32big(0x90b350ffU),
                               bswap_32big(0x04599fe5U));
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
                r_rsip_func101(bswap_32big(0xeb5a31e7U),
                               bswap_32big(0x32448c00U),
                               bswap_32big(0xbb5847e4U),
                               bswap_32big(0x75b12191U));
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
