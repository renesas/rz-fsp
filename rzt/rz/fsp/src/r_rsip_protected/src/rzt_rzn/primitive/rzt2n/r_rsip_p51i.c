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

rsip_ret_t r_rsip_p51i (const uint32_t InData_CurveType[],
                        const uint32_t InData_KeyIndex[],
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

    WR1_PROG(REG_1B00H, 0x00510002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
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
    r_rsip_subfunc009(bswap_32big(0x00005101U));
    r_rsip_func101(bswap_32big(0xa55de577U),
                   bswap_32big(0x43283df5U),
                   bswap_32big(0xd85ce29bU),
                   bswap_32big(0xc049c5b2U));
    r_rsip_func045();
    r_rsip_func077();
    r_rsip_subfunc009(bswap_32big(0x00005101U));
    r_rsip_func101(bswap_32big(0x0c4295a5U),
                   bswap_32big(0xbf041e43U),
                   bswap_32big(0xcdca677aU),
                   bswap_32big(0x9a9031daU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000013c2U);
    WR1_PROG(REG_1A2CH, 0x40000400U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80980001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        r_rsip_subfunc003(0x03420011U);
    }

    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 16]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 17]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 18]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 19]);
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
    WR1_ADDR(REG_1420H, &InData_KeyIndex[24]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[25]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[26]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[27]);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[28]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[29]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[30]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[31]);
    r_rsip_func100(bswap_32big(0xc5990ac7U),
                   bswap_32big(0x2b0e48e0U),
                   bswap_32big(0xa0ecb7d1U),
                   bswap_32big(0x37f65a06U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x775798edU), bswap_32big(0xa64f1428U), bswap_32big(0xa59f6acdU),
                       bswap_32big(0xc6956a22U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000bc7U);
        WR1_PROG(REG_1600H, 0x00000bffU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x808c001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 12; iLoop = iLoop + 1)
        {
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1A2CH, 0x00000200U);
        WR1_PROG(REG_1A24H, 0x08008107U);
        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x818c001eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00890031U);
        WR1_PROG(REG_1600H, 0x0000b7c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x808c001eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420031U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000051U));
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1000H, 0x00010000U);
        WR1_PROG(REG_1024H, 0x000007f0U);
        r_rsip_subfunc009(bswap_32big(0x00000051U));
        r_rsip_func101(bswap_32big(0x5e673954U), bswap_32big(0xdbaeedd1U), bswap_32big(0xa5371417U),
                       bswap_32big(0x64005a33U));
        r_rsip_func027(InData_DomainParam);
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x06060010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x06060010U);
        WR1_PROG(REG_1404H, 0x19000000U);
        WR1_PROG(REG_1444H, 0x000017c2U);
        WR1_PROG(REG_1A2CH, 0x00000500U);
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
        WR1_PROG(REG_1404H, 0x19500000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Signature[12]);
        WR1_ADDR(REG_1420H, &InData_Signature[13]);
        WR1_ADDR(REG_1420H, &InData_Signature[14]);
        WR1_ADDR(REG_1420H, &InData_Signature[15]);
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
        r_rsip_subfunc003(0x00c20031U);
        WR1_PROG(REG_1404H, 0x11d00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0002dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000000c0U, 0x00000200U, 0x00000160U, 0x0606000aU);
        r_rsip_subfunc001(0x00000160U, 0x00000930U, 0x000001b0U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000930U, 0x00000200U, 0x000001b0U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000980U, 0x000001b0U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000980U, 0x00000200U, 0x000001b0U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xbf0d43abU), bswap_32big(0x8e6c5a3aU), bswap_32big(0x08904aa6U),
                       bswap_32big(0x0d8c23b2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x15d8e18fU), bswap_32big(0x8812b125U), bswap_32big(0x2fb42076U),
                           bswap_32big(0xb4359d56U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x23befc11U), bswap_32big(0x1acf6292U), bswap_32big(0xd750273aU),
                           bswap_32big(0xfd9e2045U));
            r_rsip_subfunc001(0x00000160U, 0x00000200U, 0x000001b0U, 0x0606000aU);
            WR1_PROG(REG_1014H, 0x00000980U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x000000c0U);
            WR1_PROG(REG_1020H, 0x00000110U);
            WR1_PROG(REG_1010H, 0x00000020U);
            WR1_PROG(REG_1004H, 0x0606000fU);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000840U);
            r_rsip_subfunc002(0x000000c0U, 0x00000160U, 0x06060002U);
            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x818c001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90031U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x000000c0U, 0x00000480U, 0x06060002U);
            WR1_PROG(REG_1014H, 0x00000930U);
            WR1_PROG(REG_1018H, 0x00000160U);
            r_rsip_subfunc002(0x000000c0U, 0x00000340U, 0x06060002U);
            WR1_PROG(REG_1010H, 0x00000018U);
            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_subfunc003(0x00c00031U);
            WR1_PROG(REG_1404H, 0x19800000U);
            r_rsip_subfunc003(0x00c002d1U);
            WR1_PROG(REG_1014H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a70U, 0x06060004U);
            r_rsip_subfunc001(0x00000890U, 0x00000160U, 0x000002b8U, 0x06060009U);
            r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x000002f0U, 0x06060009U);
            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1608H, 0x818c0001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90031U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a00U, 0x06060002U);
            WR1_PROG(REG_1404H, 0x10e00000U);
            WR1_PROG(REG_1600H, 0x000037e1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x818c001fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90031U);
            WR1_PROG(REG_1014H, 0x00000110U);
            WR1_PROG(REG_1018H, 0x00000390U);
            r_rsip_subfunc002(0x00000070U, 0x00000a38U, 0x06060002U);
            r_rsip_subfunc009(bswap_32big(0x00000051U));
            r_rsip_func101(bswap_32big(0x42ef9359U), bswap_32big(0x0a41c4d6U), bswap_32big(0xab234233U),
                           bswap_32big(0x58bc3fcfU));
            r_rsip_func028(InData_DomainParam);
            r_rsip_subfunc001(0x000001e0U, 0x00000160U, 0x00000af0U, 0x06060009U);
            r_rsip_subfunc001(0x00000218U, 0x00000160U, 0x00000b28U, 0x06060009U);
            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000b60U, 0x06060009U);
            r_rsip_subfunc001(0x00000af0U, 0x00000a00U, 0x00000110U, 0x0606000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a00U, 0x00000af0U, 0x00000110U, 0x0606000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000b28U, 0x00000a38U, 0x00000110U, 0x0606000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a38U, 0x00000b28U, 0x00000110U, 0x0606000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x50bae9f2U), bswap_32big(0x7b12b7afU), bswap_32big(0xb9397e1dU),
                           bswap_32big(0xb15daf0fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                WR1_PROG(REG_1018H, 0x00000a70U);
                r_rsip_subfunc002(0x00000070U, 0x00000c50U, 0x06060013U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0xcf79f2d7U),
                               bswap_32big(0xa7bde4faU),
                               bswap_32big(0x9e2b6f5eU),
                               bswap_32big(0x9dd5f8b7U));
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000b60U);
                r_rsip_subfunc002(0x000002f0U, 0x00000c50U, 0x06060014U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                r_rsip_func101(bswap_32big(0x9df312e4U),
                               bswap_32big(0x501157a6U),
                               bswap_32big(0x9ffac217U),
                               bswap_32big(0x4f7b9542U));
            }

            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x14500000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430031U);
            WR1_PROG(REG_1600H, 0x0000a420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000050U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x13100000U);
            WR1_PROG(REG_1608H, 0x808c0001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430031U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 1)
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
                    WR1_PROG(REG_1404H, 0x11300000U);
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x08000104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                    r_rsip_subfunc003(0x00c0002dU);
                    r_rsip_subfunc003(0x00c20005U);
                    r_rsip_subfunc003(0x0002000dU);
                    r_rsip_subfunc001(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);
                    WR1_PROG(REG_143CH, 0x00a10000U);
                    r_rsip_func100(bswap_32big(0x3c96d17dU),
                                   bswap_32big(0x3c555129U),
                                   bswap_32big(0x25a9adabU),
                                   bswap_32big(0xe54eb043U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        WR1_PROG(REG_1014H, 0x00000250U);
                        r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x06060014U);
                        WR1_PROG(REG_143CH, 0x00000d00U);
                        r_rsip_func101(bswap_32big(0x9352531cU),
                                       bswap_32big(0x7e6e9c16U),
                                       bswap_32big(0xc53816c3U),
                                       bswap_32big(0xbfd1f87fU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x2319cd8dU),
                                       bswap_32big(0x3b85105eU),
                                       bswap_32big(0x5c53de72U),
                                       bswap_32big(0x8f9626c9U));
                    }

                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x1d3c7cb4U),
                                   bswap_32big(0x3e600ac3U),
                                   bswap_32big(0x5ea96c4cU),
                                   bswap_32big(0x73bef0edU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func100(bswap_32big(0x65a368bbU),
                                       bswap_32big(0xfaea41c0U),
                                       bswap_32big(0x5b6364f0U),
                                       bswap_32big(0x75210d4dU));
                        WR1_PROG(REG_1404H, 0x11300000U);
                        r_rsip_subfunc003(0x00c00031U);
                        WR1_PROG(REG_1600H, 0x00007c05U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_143CH, 0x00600000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000a00U, 0x00000160U, 0x00000410U, 0x06060009U);
                            r_rsip_subfunc001(0x00000a38U, 0x00000160U, 0x00000448U, 0x06060009U);
                            r_rsip_subfunc001(0x00000a70U, 0x00000160U, 0x00000480U, 0x06060009U);
                            r_rsip_func101(bswap_32big(0xb273c996U),
                                           bswap_32big(0x4d7c7bf7U),
                                           bswap_32big(0xa63dd871U),
                                           bswap_32big(0x0f379515U));
                        }
                        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000af0U, 0x00000160U, 0x00000410U, 0x06060009U);
                            r_rsip_subfunc001(0x00000b28U, 0x00000160U, 0x00000448U, 0x06060009U);
                            r_rsip_subfunc001(0x00000b60U, 0x00000160U, 0x00000480U, 0x06060009U);
                            r_rsip_func101(bswap_32big(0xa72992c3U),
                                           bswap_32big(0x8270af2aU),
                                           bswap_32big(0xfedc0b72U),
                                           bswap_32big(0x2536a535U));
                        }
                        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
                        {
                            r_rsip_subfunc001(0x00000be0U, 0x00000160U, 0x00000410U, 0x06060009U);
                            r_rsip_subfunc001(0x00000c18U, 0x00000160U, 0x00000448U, 0x06060009U);
                            r_rsip_subfunc001(0x00000c50U, 0x00000160U, 0x00000480U, 0x06060009U);
                            r_rsip_func101(bswap_32big(0x6ef3b9a6U),
                                           bswap_32big(0x070723daU),
                                           bswap_32big(0x8cdfea68U),
                                           bswap_32big(0x2ec68241U));
                        }

                        WR1_PROG(REG_1404H, 0x11300000U);
                        WR1_PROG(REG_1444H, 0x000000a2U);
                        WR1_PROG(REG_1A24H, 0x08000104U);
                        WAIT_STS(REG_1444H, 31U, 1U);
                        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                        r_rsip_subfunc003(0x00c0002dU);
                        r_rsip_subfunc003(0x00c20005U);
                        r_rsip_subfunc003(0x0002000dU);
                        r_rsip_subfunc001(0x000001e0U, 0x00000160U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_subfunc001(0x00000250U, 0x00000160U, 0x00000110U, 0x0606000aU);
                        WR1_PROG(REG_143CH, 0x00a10000U);
                        r_rsip_func100(bswap_32big(0xf53ac38dU),
                                       bswap_32big(0xdf296b60U),
                                       bswap_32big(0x70d864d5U),
                                       bswap_32big(0x5e6a109dU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_subfunc001(0x00000410U, 0x00000160U, 0x00000110U, 0x0606000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000110U, 0x0606000aU);
                            WR1_PROG(REG_143CH, 0x00a10000U);
                            r_rsip_func100(bswap_32big(0xa09e3b44U),
                                           bswap_32big(0xc65b9926U),
                                           bswap_32big(0x5fe37e39U),
                                           bswap_32big(0x03f101a3U));
                            WR1_PROG(REG_143CH, 0x00400000U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            if (CHCK_STS(REG_143CH, 22U, 1U))
                            {
                                r_rsip_subfunc001(0x000001e0U, 0x00000410U, 0x00000110U, 0x0606000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000410U, 0x000001e0U, 0x00000110U, 0x0606000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000218U, 0x00000448U, 0x00000110U, 0x0606000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000448U, 0x00000218U, 0x00000110U, 0x0606000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x00000110U, 0x0606000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_subfunc001(0x00000480U, 0x00000250U, 0x00000110U, 0x0606000aU);
                                WR1_PROG(REG_143CH, 0x00210000U);
                                r_rsip_func100(bswap_32big(0xd89fb669U), bswap_32big(0x8f08dfc2U),
                                               bswap_32big(0x2696e058U), bswap_32big(0x2be1d7d1U));
                                WR1_PROG(REG_143CH, 0x00400000U);
                                WR1_PROG(REG_1458H, 0x00000000U);
                                if (CHCK_STS(REG_143CH, 22U, 1U))
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    WR1_PROG(REG_1018H, 0x00000480U);
                                    r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x06060013U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x25a8f95dU), bswap_32big(0x9645371eU),
                                                   bswap_32big(0xc5fdad58U), bswap_32big(0xd0cdb059U));
                                }
                                else
                                {
                                    WR1_PROG(REG_1014H, 0x00000250U);
                                    r_rsip_subfunc002(0x000002f0U, 0x00000250U, 0x06060014U);
                                    WR1_PROG(REG_143CH, 0x00000d00U);
                                    r_rsip_func101(bswap_32big(0x0e7d7e45U), bswap_32big(0x985746bdU),
                                                   bswap_32big(0xadc2ff53U), bswap_32big(0xec75d7e9U));
                                }
                            }
                            else
                            {
                                r_rsip_func101(bswap_32big(0xdaa05cc8U), bswap_32big(0x04b82628U),
                                               bswap_32big(0xee5e0cbdU), bswap_32big(0x320996a0U));
                            }
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x11300000U);
                            r_rsip_subfunc003(0x00c00031U);
                            r_rsip_subfunc001(0x00000410U, 0x00000160U, 0x000001e0U, 0x06060009U);
                            r_rsip_subfunc001(0x00000448U, 0x00000160U, 0x00000218U, 0x06060009U);
                            r_rsip_subfunc001(0x00000480U, 0x00000160U, 0x00000250U, 0x06060009U);
                            r_rsip_func101(bswap_32big(0x9ed398d5U),
                                           bswap_32big(0xab7fb71bU),
                                           bswap_32big(0x8ba3057aU),
                                           bswap_32big(0xb257fb80U));
                        }
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xb982b99eU),
                                       bswap_32big(0x07a291c7U),
                                       bswap_32big(0x4c937664U),
                                       bswap_32big(0xa71612aaU));
                    }

                    WR1_PROG(REG_1600H, 0x00002c40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xed1589b7U),
                                   bswap_32big(0x88fbeb51U),
                                   bswap_32big(0x3b095638U),
                                   bswap_32big(0x8cf728abU));
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
                r_rsip_func101(bswap_32big(0x53bf3b2eU),
                               bswap_32big(0x1ea3b1c2U),
                               bswap_32big(0xc7c5a204U),
                               bswap_32big(0x4d22389aU));
            }

            WR1_PROG(REG_1600H, 0x38008820U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x12700000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0002dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000250U, 0x000002a0U, 0x000002f0U, 0x0606000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x969362a2U), bswap_32big(0xeb92c204U), bswap_32big(0xc233f5beU),
                           bswap_32big(0x6d919bf7U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x628adf8fU),
                               bswap_32big(0x0512294eU),
                               bswap_32big(0x32f51d32U),
                               bswap_32big(0xb8455536U));
            }
            else
            {
                r_rsip_func100(bswap_32big(0x04f33b84U),
                               bswap_32big(0x0a962ea5U),
                               bswap_32big(0x06d74dc3U),
                               bswap_32big(0x93fb56faU));
                WR1_PROG(REG_1014H, 0x00000250U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x06060004U);
                WR1_PROG(REG_1404H, 0x11300000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0002dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x00000160U, 0x00000110U, 0x0606000aU);
                r_rsip_subfunc005(0x000002a0U, 0x00000110U, 0x00000070U, 0x00000160U, 0x0606000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1014H, 0x000001e0U);
                WR1_PROG(REG_1018H, 0x00000160U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x06060002U);
                r_rsip_subfunc001(0x000002a0U, 0x00000930U, 0x000001b0U, 0x0606000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000930U, 0x000002a0U, 0x000001b0U, 0x0606000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0xb336165aU),
                               bswap_32big(0x393d791aU),
                               bswap_32big(0x2693f9b7U),
                               bswap_32big(0x5e313e35U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xef28ba99U),
                                   bswap_32big(0xc361bea0U),
                                   bswap_32big(0xf2b2f6b7U),
                                   bswap_32big(0x2147b535U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x19bac63dU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xc81adae6U),
                                   bswap_32big(0xec7eae88U),
                                   bswap_32big(0x95d79ac3U),
                                   bswap_32big(0x19f001edU));
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
        r_rsip_func100(bswap_32big(0xe56ac356U), bswap_32big(0x2930ccb1U), bswap_32big(0x02705db6U),
                       bswap_32big(0x7edcca00U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x97571124U), bswap_32big(0x8fe61522U), bswap_32big(0x3e8675cbU),
                           bswap_32big(0x3be71aa1U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1A2CH, 0x00000200U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1600H, 0x0000b7c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000100U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x818c001eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00890031U);
            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x808c001eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420031U);
            r_rsip_func101(bswap_32big(0x5059820bU), bswap_32big(0x894f4021U), bswap_32big(0x4a2bdc3aU),
                           bswap_32big(0xfba1227dU));

            return RSIP_RET_PASS;
        }
    }
}
