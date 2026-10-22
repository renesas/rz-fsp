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

rsip_ret_t r_rsip_pf0 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
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

    WR1_PROG(REG_1B00H, 0x00f00002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000007c7U);
    WR1_PROG(REG_1608H, 0x8088001eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30003380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00070020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000381eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00050040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000381eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000037beU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000a7a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000383dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38001001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30000f5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000f9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008be0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xd286a968U),
                   bswap_32big(0xa1345a48U),
                   bswap_32big(0x2404bacfU),
                   bswap_32big(0xb7a5ac90U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xbba7c941U), bswap_32big(0x07a5b80dU), bswap_32big(0x9e28d729U),
                       bswap_32big(0x81ce1131U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_subfunc009(bswap_32big(0x000000f0U));
        r_rsip_func101(bswap_32big(0xa8844456U), bswap_32big(0xee8eb3b3U), bswap_32big(0x1ca5d8a8U),
                       bswap_32big(0x010a4adcU));
        r_rsip_func086(InData_DomainParam);
        r_rsip_func100(bswap_32big(0xfa570c20U), bswap_32big(0x4da46a96U), bswap_32big(0x792d5dfeU),
                       bswap_32big(0x3b576fdaU));
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
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0x8f51595dU), bswap_32big(0x99c83d02U), bswap_32big(0x9b77fbe1U),
                       bswap_32big(0x29edf7faU));
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
        WR1_PROG(REG_1020H, 0x00000160U);
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
        r_rsip_subfunc001(0x00000160U, 0x00000458U, 0x00000340U, 0x04040009U);
        r_rsip_subfunc009(bswap_32big(0x000000f0U));
        r_rsip_func101(bswap_32big(0xfef5e751U), bswap_32big(0xbc42d820U), bswap_32big(0xae3c261fU),
                       bswap_32big(0x250375dfU));
        r_rsip_func087(InData_DomainParam);
        r_rsip_subfunc009(bswap_32big(0x000000f0U));
        r_rsip_func101(bswap_32big(0x14d80bf3U), bswap_32big(0x1516fef6U), bswap_32big(0xbad6f1efU),
                       bswap_32big(0x20491779U));
        r_rsip_func088();
        r_rsip_func100(bswap_32big(0xabb895dfU), bswap_32big(0xdd6866bbU), bswap_32big(0x17f3b935U),
                       bswap_32big(0x0f652de9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x58e59b27U), bswap_32big(0x8724562bU), bswap_32big(0xd30483c4U),
                           bswap_32big(0x856b4c22U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
            WR1_PROG(REG_1014H, 0x000002a0U);
            WR1_PROG(REG_1018H, 0x00000840U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000020U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x000002f0U);
            r_rsip_subfunc002(0x000000c0U, 0x000002a0U, 0x04040004U);
            WR1_PROG(REG_1404H, 0x10f00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0001dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x000002a0U, 0x00000110U, 0x00000140U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x48a2477dU), bswap_32big(0x0f4b322aU), bswap_32big(0xd4833f92U),
                           bswap_32big(0x567d6462U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x5e690c17U),
                               bswap_32big(0x4789ec32U),
                               bswap_32big(0x043feac7U),
                               bswap_32big(0x29a21b13U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x308f7e9dU),
                               bswap_32big(0xc3799aeeU),
                               bswap_32big(0x5da52968U),
                               bswap_32big(0xb3015765U));
                WR1_PROG(REG_1404H, 0x11400000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000110U, 0x0404000aU);
                r_rsip_subfunc005(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0404000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x00000160U);
                WR1_PROG(REG_1018H, 0x00000840U);
                r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x04040002U);
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x8188001eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x11400000U);
                r_rsip_subfunc003(0x00c90021U);
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
                r_rsip_subfunc009(bswap_32big(0x000000f0U));
                r_rsip_func101(bswap_32big(0x0412b8ebU),
                               bswap_32big(0x17c8ff58U),
                               bswap_32big(0x465ddacfU),
                               bswap_32big(0xb11e54aeU));
                r_rsip_func045();
                r_rsip_func022();
                r_rsip_subfunc009(bswap_32big(0x000000f0U));
                r_rsip_func101(bswap_32big(0x6a03ff3bU),
                               bswap_32big(0xdc2d3d14U),
                               bswap_32big(0x18853ff7U),
                               bswap_32big(0xa8bf6907U));
                r_rsip_func046();
                WR1_PROG(REG_1444H, 0x000007c2U);
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xf7009d07U);
                for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
                    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
                    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
                    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
                }

                WR1_PROG(REG_1404H, 0x11e00000U);
                r_rsip_subfunc003(0x00c20021U);
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x07008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
                WR1_PROG(REG_1A24H, 0x9c100005U);
                r_rsip_subfunc003(0x00820011U);
                r_rsip_func100(bswap_32big(0x1e13a42dU),
                               bswap_32big(0xa9f4308aU),
                               bswap_32big(0x09c60dffU),
                               bswap_32big(0xd4c0a3d8U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x054ff3d8U),
                                   bswap_32big(0xb195669dU),
                                   bswap_32big(0x83c060cdU),
                                   bswap_32big(0x70927ce1U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_KEY_FAIL;
                }
                else
                {
                    WR1_PROG(REG_1014H, 0x00000200U);
                    WR1_PROG(REG_1018H, 0x00000840U);
                    r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x04040002U);
                    WR1_PROG(REG_1014H, 0x000001b0U);
                    WR1_PROG(REG_1018H, 0x000002a0U);
                    r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x04040002U);
                    WR1_PROG(REG_1014H, 0x00000160U);
                    WR1_PROG(REG_1018H, 0x00000200U);
                    r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x04040005U);
                    WR1_PROG(REG_1014H, 0x00000110U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x04040002U);
                    WR1_PROG(REG_1404H, 0x10f00000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                    r_rsip_subfunc003(0x00c0001dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000160U, 0x0404000aU);
                    WR1_PROG(REG_143CH, 0x00210000U);
                    r_rsip_func100(bswap_32big(0x409b9a43U),
                                   bswap_32big(0x0a708076U),
                                   bswap_32big(0x7fd30e40U),
                                   bswap_32big(0x7a1c72fcU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func102(bswap_32big(0x4d5e0492U),
                                       bswap_32big(0xb2721348U),
                                       bswap_32big(0xbaf32959U),
                                       bswap_32big(0xbebd0539U));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_FAIL;
                    }
                    else
                    {
                        r_rsip_func100(bswap_32big(0x061a9299U),
                                       bswap_32big(0x93cc2397U),
                                       bswap_32big(0xd8f339b7U),
                                       bswap_32big(0x379cc751U));
                        WR1_PROG(REG_1404H, 0x12800000U);
                        WR1_PROG(REG_1A2CH, 0x00000100U);
                        WR1_PROG(REG_1A24H, 0x08008107U);
                        r_rsip_subfunc003(0x00830021U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_Signature[0]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[1]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[2]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[3]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_Signature[4]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[5]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[6]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[7]);
                        r_rsip_func100(bswap_32big(0x98feb180U),
                                       bswap_32big(0x3568a29eU),
                                       bswap_32big(0x8864fd0aU),
                                       bswap_32big(0x6a486a88U));
                        WR1_PROG(REG_1404H, 0x11e00000U);
                        WR1_PROG(REG_1A2CH, 0x00000100U);
                        WR1_PROG(REG_1A24H, 0x08008107U);
                        r_rsip_subfunc003(0x00830021U);
                        WR1_PROG(REG_1408H, 0x00002022U);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_Signature[8]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[9]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[10]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[11]);
                        WAIT_STS(REG_1408H, 30U, 1U);
                        RD1_ADDR(REG_1420H, &OutData_Signature[12]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[13]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[14]);
                        RD1_ADDR(REG_1420H, &OutData_Signature[15]);
                        r_rsip_func102(bswap_32big(0xc5d1dfa3U),
                                       bswap_32big(0x91f3fdaeU),
                                       bswap_32big(0x5288c69bU),
                                       bswap_32big(0x18338345U));
                        WR1_PROG(REG_14B8H, 0x00000040U);
                        WAIT_STS(REG_142CH, 12U, 0U);

                        return RSIP_RET_PASS;
                    }
                }
            }
        }
    }
}
