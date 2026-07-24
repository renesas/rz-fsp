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

rsip_ret_t r_rsip_p5fi (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_MsgDgst[],
                        const uint32_t InData_Signature[],
                        const uint32_t InData_DomainParam[])
{
    RSIP_PRV_PRIMITIVE_ENTRY;
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x005f0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005f01U));
    r_rsip_func101(bswap_32big(0x662aad3bU),
                   bswap_32big(0xe549516aU),
                   bswap_32big(0x8182ebd1U),
                   bswap_32big(0xad73966dU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x014a2920U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005f01U));
    r_rsip_func101(bswap_32big(0x1bdf9221U),
                   bswap_32big(0x34c44b29U),
                   bswap_32big(0x3d218af8U),
                   bswap_32big(0x19aaa548U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x00001bc2U);
    WR1_PROG(REG_1A2CH, 0x40000600U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a00001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 28; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        r_rsip_subfunc003(0x03420011U);
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
    r_rsip_func100(bswap_32big(0xa3672de1U),
                   bswap_32big(0x51b60380U),
                   bswap_32big(0xdd1848b3U),
                   bswap_32big(0x71b84254U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xcf2b19c0U), bswap_32big(0xa5a9811cU), bswap_32big(0x6e9183ebU),
                       bswap_32big(0xb0be9173U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000fc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x8090001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
        {
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b7e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1A2CH, 0x00000300U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1608H, 0x8184001eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00890011U);
            WR1_PROG(REG_1608H, 0x8084001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1600H, 0x0000a7c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000005fU));
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);
        r_rsip_subfunc009(bswap_32big(0x0000005fU));
        r_rsip_func101(bswap_32big(0x3461e9c5U), bswap_32big(0x484f0e18U), bswap_32big(0x764f1d44U),
                       bswap_32big(0x7dc48324U));
        r_rsip_func078(InData_DomainParam);
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x08080010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x08080010U);
        WR1_PROG(REG_1404H, 0x18f00000U);
        WR1_PROG(REG_1444H, 0x00001fc2U);
        WR1_PROG(REG_1A2CH, 0x00000700U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[0]);
        WR1_ADDR(REG_1420H, &InData_Signature[1]);
        WR1_ADDR(REG_1420H, &InData_Signature[2]);
        WR1_ADDR(REG_1420H, &InData_Signature[3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[4]);
        WR1_ADDR(REG_1420H, &InData_Signature[5]);
        WR1_ADDR(REG_1420H, &InData_Signature[6]);
        WR1_ADDR(REG_1420H, &InData_Signature[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[8]);
        WR1_ADDR(REG_1420H, &InData_Signature[9]);
        WR1_ADDR(REG_1420H, &InData_Signature[10]);
        WR1_ADDR(REG_1420H, &InData_Signature[11]);
        r_rsip_subfunc003(0x00c20031U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[12]);
        WR1_ADDR(REG_1420H, &InData_Signature[13]);
        WR1_ADDR(REG_1420H, &InData_Signature[14]);
        WR1_ADDR(REG_1420H, &InData_Signature[15]);
        r_rsip_subfunc003(0x00c20011U);
        WR1_PROG(REG_1404H, 0x19400000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[16]);
        WR1_ADDR(REG_1420H, &InData_Signature[17]);
        WR1_ADDR(REG_1420H, &InData_Signature[18]);
        WR1_ADDR(REG_1420H, &InData_Signature[19]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[20]);
        WR1_ADDR(REG_1420H, &InData_Signature[21]);
        WR1_ADDR(REG_1420H, &InData_Signature[22]);
        WR1_ADDR(REG_1420H, &InData_Signature[23]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[24]);
        WR1_ADDR(REG_1420H, &InData_Signature[25]);
        WR1_ADDR(REG_1420H, &InData_Signature[26]);
        WR1_ADDR(REG_1420H, &InData_Signature[27]);
        r_rsip_subfunc003(0x00c20031U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[28]);
        WR1_ADDR(REG_1420H, &InData_Signature[29]);
        WR1_ADDR(REG_1420H, &InData_Signature[30]);
        WR1_ADDR(REG_1420H, &InData_Signature[31]);
        r_rsip_subfunc003(0x00c20011U);
        WR1_PROG(REG_1404H, 0x11c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000000c0U, 0x00000200U, 0x00000160U, 0x0808000aU);
        r_rsip_subfunc001(0x00000160U, 0x00000930U, 0x000001b0U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000930U, 0x00000200U, 0x000001b0U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000980U, 0x000001b0U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000980U, 0x00000200U, 0x000001b0U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xf03674b8U), bswap_32big(0xc2c68246U), bswap_32big(0x080a1450U),
                       bswap_32big(0xc6860930U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xde8f8ed5U), bswap_32big(0x5d59d45aU), bswap_32big(0x74b48aabU),
                           bswap_32big(0x033049a1U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xa05b9459U), bswap_32big(0x991f472aU), bswap_32big(0x8cfc11f7U),
                           bswap_32big(0x3029b31bU));
            r_rsip_subfunc001(0x00000160U, 0x00000200U, 0x000001b0U, 0x0808000aU);
            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);
            WR1_PROG(REG_1004H, 0x0808000fU);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000840U);
            r_rsip_subfunc002(0x000000c0U, 0x00000160U, 0x08080002U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x000000c0U, 0x00000480U, 0x08080002U);
            WR1_PROG(REG_1014H, 0x00000930U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x000000c0U, 0x00000340U, 0x08080002U);
            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_subfunc003(0x00c00041U);
            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_subfunc003(0x00c002d1U);
            WR1_PROG(REG_1014H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a70U, 0x08080004U);
            r_rsip_subfunc001(0x00000890U, 0x00000160U, 0x000002a8U, 0x08080009U);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x08080009U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1608H, 0x81900001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x000009e0U, 0x08080002U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1600H, 0x000037e1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a28U, 0x08080002U);
            r_rsip_subfunc009(bswap_32big(0x0000005fU));
            r_rsip_func101(bswap_32big(0x80c9b4a9U), bswap_32big(0x84639cc2U), bswap_32big(0x031aabb4U),
                           bswap_32big(0xa6966278U));
            r_rsip_func079(InData_DomainParam);
            r_rsip_subfunc001(0x000001c0U, 0x00000160U, 0x00000ad0U, 0x08080009U);
            r_rsip_subfunc001(0x00000208U, 0x00000160U, 0x00000b18U, 0x08080009U);
            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000b60U, 0x08080009U);
            r_rsip_subfunc001(0x00000ad0U, 0x000009e0U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x000009e0U, 0x00000ad0U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000b18U, 0x00000a28U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a28U, 0x00000b18U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xbbee9cecU), bswap_32big(0x3dd51617U), bswap_32big(0x7d802703U),
                           bswap_32big(0x3fd3f8b7U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x08080013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0xb9e13f6aU),
                               bswap_32big(0x12904803U),
                               bswap_32big(0x2ee7a98eU),
                               bswap_32big(0x71b95e50U));
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x08080014U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0x9ff081c2U),
                               bswap_32big(0x1e2a2945U),
                               bswap_32big(0xbe440f69U),
                               bswap_32big(0xdb93a8efU));
            }

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430041U);
            WR1_PROG(REG_1600H, 0x0000a420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x13000000U);
            WR1_PROG(REG_1608H, 0x80900001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430041U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
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
                    WR1_PROG(REG_1404H, 0x11200000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                    r_rsip_subfunc003(0x00c0003dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x000001c0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0xe195fa87U),
                                   bswap_32big(0x35ce9f24U),
                                   bswap_32big(0xc95ce4acU),
                                   bswap_32big(0x35038cd1U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x08080014U);
                        WR1_PROG(REG_143CH, 0x00000d00U);
                        r_rsip_func101(bswap_32big(0x83b05977U),
                                       bswap_32big(0xf4a48875U),
                                       bswap_32big(0x51781c94U),
                                       bswap_32big(0xe850c15aU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xb2dece00U),
                                       bswap_32big(0x4943cd23U),
                                       bswap_32big(0x40cb1aa5U),
                                       bswap_32big(0x41c6f9bbU));
                    }

                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x72aa9378U),
                                   bswap_32big(0x7d9eaa59U),
                                   bswap_32big(0x2165b9a7U),
                                   bswap_32big(0xb04a9a27U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x2dfaa9d1U),
                                       bswap_32big(0x917afe32U),
                                       bswap_32big(0x9e4d4b1bU),
                                       bswap_32big(0x782ecc8dU));
                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_subfunc003(0x00c00041U);
                        WR1_PROG(REG_1600H, 0x00007c05U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_143CH, 0x00600000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x000009e0U, 0x00000160U, 0x000003f0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000a28U, 0x00000160U, 0x00000438U, 0x08080009U);
                            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000480U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0x11fb8e1cU),
                                           bswap_32big(0xfa4695b6U),
                                           bswap_32big(0xfc6ade06U),
                                           bswap_32big(0x948dae92U));
                        }
                        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000ad0U, 0x00000160U, 0x000003f0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000b18U, 0x00000160U, 0x00000438U, 0x08080009U);
                            r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0x562999ffU),
                                           bswap_32big(0x48f0ff30U),
                                           bswap_32big(0xd0f3990cU),
                                           bswap_32big(0x05494790U));
                        }
                        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000bc0U, 0x00000160U, 0x000003f0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000c08U, 0x00000160U, 0x00000438U, 0x08080009U);
                            r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0x57b90667U),
                                           bswap_32big(0x67e1672fU),
                                           bswap_32big(0xdef468c3U),
                                           bswap_32big(0x02ef16b7U));
                        }

                        WR1_PROG(REG_1404H, 0x11200000U);
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x08000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                        r_rsip_subfunc003(0x00c0003dU);
                        r_rsip_subfunc003(0x00c20005U);
                        r_rsip_subfunc003(0x0002000dU);
                        r_rsip_subfunc001(0x000001c0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0x10761823U),
                                       bswap_32big(0x622a4150U),
                                       bswap_32big(0xdb4deebcU),
                                       bswap_32big(0xbe89b297U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x000003f0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_func100(bswap_32big(0xb37b530aU),
                                           bswap_32big(0x1bed1257U),
                                           bswap_32big(0x852896beU),
                                           bswap_32big(0xccfafaf1U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                r_rsip_subfunc001(0x000001c0U, 0x000003f0U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x000003f0U, 0x000001c0U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000208U, 0x00000438U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000438U, 0x00000208U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000480U, 0x00000250U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_func100(bswap_32big(0xb2642c48U), bswap_32big(0x9c85afc1U),
                                               bswap_32big(0xc7964034U), bswap_32big(0x2beae45cU));
                                WR1_PROG(REG_143CH, 0x00400000U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                if (CHCK_STS(REG_143CH, 22U, 1U))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x08080013U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x51d84149U), bswap_32big(0xaa65365cU),
                                                   bswap_32big(0xd1811d2fU), bswap_32big(0x18c9f69dU));
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x08080014U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x9cf380edU), bswap_32big(0x51a8b649U),
                                                   bswap_32big(0xd47616fdU), bswap_32big(0xcd5b8776U));
                                }
                            }
                            else
                            {
                                r_rsip_func101(bswap_32big(0xe0f29a5eU), bswap_32big(0xb8eea7d3U),
                                               bswap_32big(0x78ddf54fU), bswap_32big(0xfd815cb1U));
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11200000U);
                            r_rsip_subfunc003(0x00c00041U);
                            r_rsip_subfunc001(0x000003f0U, 0x00000160U, 0x000001c0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000438U, 0x00000160U, 0x00000208U, 0x08080009U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0x7e660928U),
                                           bswap_32big(0x04a4f1a6U),
                                           bswap_32big(0x8a729c28U),
                                           bswap_32big(0x84cd951dU));
                        }
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x966bf883U),
                                       bswap_32big(0x6e181f2bU),
                                       bswap_32big(0x42ff127aU),
                                       bswap_32big(0x180cf846U));
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x569acb8fU),
                                   bswap_32big(0x05877804U),
                                   bswap_32big(0x5ab56fe8U),
                                   bswap_32big(0x59f7d790U));
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
                r_rsip_func101(bswap_32big(0x356f45a3U),
                               bswap_32big(0x7084b30eU),
                               bswap_32big(0x21cd1352U),
                               bswap_32big(0x112fedf8U));
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x12600000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0003dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x67c97eefU), bswap_32big(0x19abc4b1U), bswap_32big(0x42aba71aU),
                           bswap_32big(0xebbcf7d2U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xfb0d7e51U),
                               bswap_32big(0x314af4beU),
                               bswap_32big(0x93167ad1U),
                               bswap_32big(0x924e01d0U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x279610c0U),
                               bswap_32big(0x4748e511U),
                               bswap_32big(0x489e986bU),
                               bswap_32big(0x3fa411c6U));
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
                r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0xe0882854U),
                               bswap_32big(0xe0fbbbdaU),
                               bswap_32big(0x6e4a7f1bU),
                               bswap_32big(0xcb5c4b2eU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x95c201d0U),
                                   bswap_32big(0xbfb60629U),
                                   bswap_32big(0x9161897eU),
                                   bswap_32big(0xcc2a48f5U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x19bac63dU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x5e10e8a2U),
                                   bswap_32big(0xece5d293U),
                                   bswap_32big(0x6edb52d6U),
                                   bswap_32big(0xcd80cbebU));
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
        r_rsip_func100(bswap_32big(0xd4123376U), bswap_32big(0x16becfe2U), bswap_32big(0xff0e5d94U),
                       bswap_32big(0x41411a8bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x862b1d32U), bswap_32big(0x05d9472aU), bswap_32big(0x8f30f2feU),
                           bswap_32big(0x0d7eea95U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b7c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000100U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1608H, 0x8184001eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00890011U);
                WR1_PROG(REG_1608H, 0x8084001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                WR1_PROG(REG_1600H, 0x0000a7c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            return RSIP_RET_PASS;
        }
    }
}
