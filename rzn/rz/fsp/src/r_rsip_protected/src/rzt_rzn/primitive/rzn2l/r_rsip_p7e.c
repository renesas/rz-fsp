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

rsip_ret_t r_rsip_p7e (const uint32_t InData_KeyIndex[],
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

    WR1_PROG(REG_1B00H, 0x007e0002U);
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
    r_rsip_subfunc009(bswap_32big(0x0000007eU));
    r_rsip_func101(bswap_32big(0xe19cdca1U),
                   bswap_32big(0xb697eb87U),
                   bswap_32big(0x14f69ea2U),
                   bswap_32big(0x95800a5aU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0160f11aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007eU));
    r_rsip_func101(bswap_32big(0xdd3ad367U),
                   bswap_32big(0x9536029eU),
                   bswap_32big(0xad8a3cc3U),
                   bswap_32big(0x095e2d67U));
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
    r_rsip_func100(bswap_32big(0xfb1b759fU),
                   bswap_32big(0xa9e002bfU),
                   bswap_32big(0x25b4b6e7U),
                   bswap_32big(0x08d15fa6U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x139bdf48U), bswap_32big(0xf822e1b4U), bswap_32big(0x7a31e89bU),
                       bswap_32big(0x2e8a9f40U));
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

        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000007eU));
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);
        WR1_PROG(REG_1404H, 0x10200000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x10700000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x13400000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x17f00000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x18900000U);
        r_rsip_subfunc003(0x00c00051U);
        r_rsip_subfunc009(bswap_32big(0x0000007eU));
        r_rsip_func101(bswap_32big(0xf2efd77fU), bswap_32big(0x93bb5aaaU), bswap_32big(0xf9d67867U),
                       bswap_32big(0xf4b3c084U));
        r_rsip_func078(InData_DomainParam);
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x08080010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x08080010U);
        WR1_PROG(REG_1404H, 0x18e00000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x19300000U);
        r_rsip_subfunc003(0x00c00051U);
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
        r_rsip_func100(bswap_32big(0x9fe23430U), bswap_32big(0x3f921c5cU), bswap_32big(0xde50debaU),
                       bswap_32big(0xc0ea6ee9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x4ecdbaf3U), bswap_32big(0x9a9feff9U), bswap_32big(0xbe35122aU),
                           bswap_32big(0x09c35908U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x82752b52U), bswap_32big(0xa786dc74U), bswap_32big(0x64459d70U),
                           bswap_32big(0xafb7ff9eU));
            r_rsip_subfunc001(0x00000160U, 0x00000200U, 0x000001b0U, 0x0808000aU);
            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);
            WR1_PROG(REG_1004H, 0x0808000fU);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000840U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000160U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x10c00000U);
            r_rsip_subfunc003(0x00c00051U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8190001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000160U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000480U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000930U);
            WR1_PROG(REG_1018H, 0x00000160U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000340U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_subfunc003(0x00c00041U);
            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_subfunc003(0x00c002d1U);
            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000a70U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x00000890U, 0x00000160U, 0x000002a8U, 0x08080009U);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x08080009U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            WR1_PROG(REG_1608H, 0x81900001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000009e0U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
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
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000a28U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x14800000U);
            r_rsip_subfunc003(0x00c000f1U);
            r_rsip_subfunc001(0x00000390U, 0x00000160U, 0x00000980U, 0x08080009U);
            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_1018H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000528U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x15300000U);
            r_rsip_subfunc003(0x00c00035U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c2000dU);
            r_rsip_subfunc003(0x00020005U);
            WR1_PROG(REG_1014H, 0x00000528U);
            WR1_PROG(REG_1018H, 0x00000570U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000980U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x000009e0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000004e0U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000a28U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000528U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_subfunc003(0x00c000f1U);
            WR1_PROG(REG_1014H, 0x000004e0U);
            WR1_PROG(REG_1018H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000009d0U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000528U);
            WR1_PROG(REG_1018H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000a20U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000a70U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x12500000U);
            r_rsip_subfunc003(0x00c000a1U);
            WR1_PROG(REG_1014H, 0x00000890U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000570U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000570U);
            WR1_PROG(REG_1018H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002a0U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x08080009U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            r_rsip_subfunc009(bswap_32big(0x0000007eU));
            r_rsip_func101(bswap_32big(0x1481ff90U), bswap_32big(0x17aba851U), bswap_32big(0x857bd7ffU),
                           bswap_32big(0xde8d85caU));
            r_rsip_func079(InData_DomainParam);
            WR1_PROG(REG_1014H, 0x000001c0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000004e0U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000208U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000528U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            WR1_PROG(REG_1014H, 0x000004e0U);
            WR1_PROG(REG_1018H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000001b0U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000528U);
            WR1_PROG(REG_1018H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000200U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1004H, 0x08080004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000ac0U, 0x08080009U);
            r_rsip_subfunc001(0x00000200U, 0x00000160U, 0x00000b10U, 0x08080009U);
            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000b60U, 0x08080009U);
            r_rsip_subfunc001(0x00000ac0U, 0x000009d0U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x000009d0U, 0x00000ac0U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000b10U, 0x00000a20U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a20U, 0x00000b10U, 0x00000110U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x1b27211fU), bswap_32big(0xbd2d91a2U), bswap_32big(0xcbb66aa1U),
                           bswap_32big(0x41f2bebcU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x09090013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0x2e6f5463U),
                               bswap_32big(0x9b2e3513U),
                               bswap_32big(0x21577640U),
                               bswap_32big(0x405b596fU));
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x09090014U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0x5dce1c52U),
                               bswap_32big(0x3364fdcbU),
                               bswap_32big(0x90193d3aU),
                               bswap_32big(0xc64a9071U));
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
                    r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x55f66d5aU),
                                   bswap_32big(0x35a438e1U),
                                   bswap_32big(0x9af16cb3U),
                                   bswap_32big(0x8d62e573U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                        WR1_PROG(REG_143CH, 0x00000d00U);
                        r_rsip_func101(bswap_32big(0xc78f3211U),
                                       bswap_32big(0x21c2c162U),
                                       bswap_32big(0xe1ffb6c0U),
                                       bswap_32big(0x911c624bU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x600741bfU),
                                       bswap_32big(0x8f42b624U),
                                       bswap_32big(0x7fb48165U),
                                       bswap_32big(0xd38fb624U));
                    }

                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0xa6209196U),
                                   bswap_32big(0xf4fd62dfU),
                                   bswap_32big(0x49ecd9bbU),
                                   bswap_32big(0x2852c142U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x2ff79876U),
                                       bswap_32big(0x8e7291d6U),
                                       bswap_32big(0x9b513e47U),
                                       bswap_32big(0x852e03aaU));
                        WR1_PROG(REG_1404H, 0x11200000U);
                        r_rsip_subfunc003(0x00c00041U);
                        WR1_PROG(REG_1600H, 0x00007c05U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_143CH, 0x00600000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x000009d0U, 0x00000160U, 0x000003e0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000a20U, 0x00000160U, 0x00000430U, 0x08080009U);
                            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000480U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0xebbf0ff6U),
                                           bswap_32big(0x2cc8a221U),
                                           bswap_32big(0x5fd700b5U),
                                           bswap_32big(0xce08c2b7U));
                        }
                        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000ac0U, 0x00000160U, 0x000003e0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000b10U, 0x00000160U, 0x00000430U, 0x08080009U);
                            r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0x06c4715fU),
                                           bswap_32big(0x0b9a8affU),
                                           bswap_32big(0xcc00e2ddU),
                                           bswap_32big(0x4ce92648U));
                        }
                        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000bb0U, 0x00000160U, 0x000003e0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000c00U, 0x00000160U, 0x00000430U, 0x08080009U);
                            r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0xa68af33dU),
                                           bswap_32big(0x2ac6e284U),
                                           bswap_32big(0x22d415aaU),
                                           bswap_32big(0x548535cdU));
                        }

                        WR1_PROG(REG_1404H, 0x11200000U);
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x08000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                        r_rsip_subfunc003(0x00c0003dU);
                        r_rsip_subfunc003(0x00c20005U);
                        r_rsip_subfunc003(0x0002000dU);
                        r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0x592e671cU),
                                       bswap_32big(0x95c6c8acU),
                                       bswap_32big(0x321d1976U),
                                       bswap_32big(0x519e43b0U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x00000110U, 0x0808000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0808000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_func100(bswap_32big(0x3f92909dU),
                                           bswap_32big(0xa209b418U),
                                           bswap_32big(0x3f667647U),
                                           bswap_32big(0x78283d98U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                r_rsip_subfunc001(0x000001b0U, 0x000003e0U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x000003e0U, 0x000001b0U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000200U, 0x00000430U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000430U, 0x00000200U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000480U, 0x00000250U, 0x00000110U, 0x0808000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_func100(bswap_32big(0x28e174ceU), bswap_32big(0xda34114fU),
                                               bswap_32big(0xa13243b4U), bswap_32big(0x3a240f01U));
                                WR1_PROG(REG_143CH, 0x00400000U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                if (CHCK_STS(REG_143CH, 22U, 1U))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x09090013U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x963e2340U), bswap_32big(0x3138ed92U),
                                                   bswap_32big(0x82af36f0U), bswap_32big(0x1eb1aa0cU));
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x09090014U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x82f674ebU), bswap_32big(0x8cd96c1bU),
                                                   bswap_32big(0x5f0d6af0U), bswap_32big(0x76ed8477U));
                                }
                            }
                            else
                            {
                                r_rsip_func101(bswap_32big(0x7f6d5b46U), bswap_32big(0xa2994c71U),
                                               bswap_32big(0x0d9e538cU), bswap_32big(0x239690dcU));
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11200000U);
                            r_rsip_subfunc003(0x00c00041U);
                            r_rsip_subfunc001(0x000003e0U, 0x00000160U, 0x000001b0U, 0x08080009U);
                            r_rsip_subfunc001(0x00000430U, 0x00000160U, 0x00000200U, 0x08080009U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0x573b8a82U),
                                           bswap_32big(0x1c3ab734U),
                                           bswap_32big(0x89fb63a3U),
                                           bswap_32big(0xabb04a85U));
                        }
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x5f68f820U),
                                       bswap_32big(0x377aa09fU),
                                       bswap_32big(0x74801bc7U),
                                       bswap_32big(0xf88a1c07U));
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xd87fb6e7U),
                                   bswap_32big(0x5edc48a8U),
                                   bswap_32big(0xf859da07U),
                                   bswap_32big(0x5b467412U));
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
                r_rsip_func101(bswap_32big(0x981545adU),
                               bswap_32big(0xba174f84U),
                               bswap_32big(0xcb71b762U),
                               bswap_32big(0xae1d7017U));
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1014H, 0x000001b0U);
            r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x09090004U);
            WR1_PROG(REG_1014H, 0x00000200U);
            r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x09090004U);
            WR1_PROG(REG_1014H, 0x00000250U);
            r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x09090004U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000001c0U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000160U);
            WR1_PROG(REG_1018H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000208U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x000002a0U);
            WR1_PROG(REG_1018H, 0x00000390U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1004H, 0x08080002U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
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
            r_rsip_func100(bswap_32big(0x66be7f63U), bswap_32big(0x57ee5e4dU), bswap_32big(0x17d58f1aU),
                           bswap_32big(0x0cc6d449U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x3a831605U),
                               bswap_32big(0x84a36842U),
                               bswap_32big(0x6a8a237fU),
                               bswap_32big(0x4ca2f4e4U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0xd4b6fe17U),
                               bswap_32big(0x2a20243dU),
                               bswap_32big(0xf005f7a1U),
                               bswap_32big(0x4e953ad5U));
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x000002a0U);
                WR1_PROG(REG_1004H, 0x08080004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x11200000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0808000aU);
                WR1_PROG(REG_1014H, 0x000002a0U);
                WR1_PROG(REG_1018H, 0x00000110U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000160U);
                WR1_PROG(REG_1004H, 0x0808000fU);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000001c0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x000002a0U);
                WR1_PROG(REG_1004H, 0x08080002U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0xf3f0e7c3U),
                               bswap_32big(0x9dd16163U),
                               bswap_32big(0x32406505U),
                               bswap_32big(0x35eb9976U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xf5241321U),
                                   bswap_32big(0x83843abfU),
                                   bswap_32big(0x30378eb2U),
                                   bswap_32big(0x26d66aeaU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x19bac63dU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xca25ebe7U),
                                   bswap_32big(0x160812dfU),
                                   bswap_32big(0xf89c9703U),
                                   bswap_32big(0x0bddf149U));
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
        r_rsip_func100(bswap_32big(0xe909138bU), bswap_32big(0xf7e18841U), bswap_32big(0x5272993aU),
                       bswap_32big(0x4a6ac378U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x24353b1cU), bswap_32big(0x0f1fea0eU), bswap_32big(0xb7aa3b22U),
                           bswap_32big(0xf43c4e35U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func102(bswap_32big(0x24ccde57U), bswap_32big(0x4d470630U), bswap_32big(0xe27d526bU),
                           bswap_32big(0xeb07501cU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
