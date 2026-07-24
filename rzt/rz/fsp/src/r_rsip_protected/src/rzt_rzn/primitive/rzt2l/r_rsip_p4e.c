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

rsip_ret_t r_rsip_p4e (const uint32_t InData_CurveType[],
                       const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
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

    WR1_PROG(REG_1B00H, 0x004e0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
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
    r_rsip_subfunc009(bswap_32big(0x0000004eU));
    r_rsip_func101(bswap_32big(0x2dd11864U),
                   bswap_32big(0x5850d71dU),
                   bswap_32big(0x8dd866c5U),
                   bswap_32big(0x2bb88760U));
    r_rsip_func027(InData_DomainParam);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x06060010U);
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
    r_rsip_subfunc009(bswap_32big(0x00004e01U));
    r_rsip_func101(bswap_32big(0x6512bab3U),
                   bswap_32big(0x4cbd9035U),
                   bswap_32big(0xb02e84fcU),
                   bswap_32big(0x03b0e64eU));
    r_rsip_func045();
    r_rsip_func076();
    r_rsip_subfunc009(bswap_32big(0x00004e01U));
    r_rsip_func101(bswap_32big(0xbf7e7913U),
                   bswap_32big(0xab01e218U),
                   bswap_32big(0x758a54ecU),
                   bswap_32big(0x95decaddU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x00000bc2U);
    WR1_PROG(REG_1A2CH, 0x40000200U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    }

    WR1_PROG(REG_1404H, 0x13100000U);
    r_rsip_subfunc003(0x00c20031U);
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
    r_rsip_func100(bswap_32big(0x6aa59cb5U),
                   bswap_32big(0x60e3c62cU),
                   bswap_32big(0x5133f73aU),
                   bswap_32big(0x67cbbff8U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xeee7d0deU), bswap_32big(0x6290eb02U), bswap_32big(0xf21366bfU),
                       bswap_32big(0x8c35f647U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1404H, 0x10c00000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000f7bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x8a46a8fbU), bswap_32big(0x77cbc7edU), bswap_32big(0xc395eaa0U),
                       bswap_32big(0xed3e5d49U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1444H, 0x00000bd0U);
            for (iLoop = 0; iLoop < 48; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_00E0H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 0]);
            }

            WR1_PROG(REG_1444H, 0x00000bd0U);
            for (iLoop = 0; iLoop < 48; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_0130H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 12]);
            }

            r_rsip_func101(bswap_32big(0x026ee18aU), bswap_32big(0xa83f8ec4U), bswap_32big(0xfd071764U),
                           bswap_32big(0x193cbdf0U));
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00004e02U));
            r_rsip_func101(bswap_32big(0x49afb6a5U), bswap_32big(0x06b7d0afU), bswap_32big(0xd0202677U),
                           bswap_32big(0xbb0e529bU));
            r_rsip_func045();
            r_rsip_func077();
            r_rsip_subfunc009(bswap_32big(0x00004e02U));
            r_rsip_func101(bswap_32big(0x13f09a5aU), bswap_32big(0x81089183U), bswap_32big(0x44f178deU),
                           bswap_32big(0xd4d3c675U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000013c2U);
            WR1_PROG(REG_1A2CH, 0x40000400U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
            }

            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_subfunc003(0x00c20031U);
            for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 16]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 17]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 18]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 19]);
            }

            WR1_PROG(REG_1404H, 0x11300000U);
            r_rsip_subfunc003(0x00c20021U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[24]);
            WR1_ADDR(REG_1420H, &InData_PubKey[25]);
            WR1_ADDR(REG_1420H, &InData_PubKey[26]);
            WR1_ADDR(REG_1420H, &InData_PubKey[27]);
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[28]);
            WR1_ADDR(REG_1420H, &InData_PubKey[29]);
            WR1_ADDR(REG_1420H, &InData_PubKey[30]);
            WR1_ADDR(REG_1420H, &InData_PubKey[31]);
            r_rsip_func100(bswap_32big(0xda2cbd7eU), bswap_32big(0xed1cd0caU), bswap_32big(0x56f19dbeU),
                           bswap_32big(0x318e24e5U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x0ae9197cU),
                               bswap_32big(0x093807b6U),
                               bswap_32big(0x60641b7eU),
                               bswap_32big(0x176e2566U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x97e92ad1U),
                               bswap_32big(0x7ef9c2a4U),
                               bswap_32big(0x91dea018U),
                               bswap_32big(0x2e602819U));
            }
        }

        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000001b0U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000200U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1004H, 0x06060001U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000890U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x06060005U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x000008e0U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x06060005U);
        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1004H, 0x06060001U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x00000250U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000110U, 0x00000250U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x88db6a80U), bswap_32big(0x178e69f9U), bswap_32big(0xb7091748U),
                       bswap_32big(0x2e06f5ecU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xd45d3f73U), bswap_32big(0xbf8828d3U), bswap_32big(0xc17798e1U),
                           bswap_32big(0x8c0c773dU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_subfunc003(0x00c00031U);
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x000002a0U, 0x06060009U);
            r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x000002f0U, 0x06060009U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            r_rsip_subfunc001(0x000002a0U, 0x00000110U, 0x000001e0U, 0x06060009U);
            r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000218U, 0x06060009U);
            r_rsip_subfunc009(bswap_32big(0x0000004eU));
            r_rsip_func101(bswap_32big(0xad72bcc0U), bswap_32big(0x4736c28fU), bswap_32big(0x7e5122a6U),
                           bswap_32big(0xdc431333U));
            r_rsip_func089();
            r_rsip_func100(bswap_32big(0xe7116325U), bswap_32big(0x494493feU), bswap_32big(0x041ba444U),
                           bswap_32big(0x2bdb667dU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x2671680eU),
                               bswap_32big(0x7d08ab9eU),
                               bswap_32big(0xa59a4868U),
                               bswap_32big(0x4cc5bf30U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x7a47ab51U),
                               bswap_32big(0x15aa206eU),
                               bswap_32big(0x0c33eeb2U),
                               bswap_32big(0xc32e82a9U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00004e03U));
                r_rsip_func101(bswap_32big(0xc4725149U),
                               bswap_32big(0x1f9cc106U),
                               bswap_32big(0x84f0b058U),
                               bswap_32big(0x22ea6bc9U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01864cb4U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00004e03U));
                r_rsip_func101(bswap_32big(0xf90b4f73U),
                               bswap_32big(0xb977f16fU),
                               bswap_32big(0x102ea006U),
                               bswap_32big(0x05665f42U));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0x20f667fcU),
                               bswap_32big(0xcc83ffbaU),
                               bswap_32big(0xf2b0ee65U),
                               bswap_32big(0x7d2b3248U));
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12700000U);
                r_rsip_subfunc003(0x00830031U);
                WR1_PROG(REG_1408H, 0x00002032U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[4]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[5]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[6]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[7]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[8]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[9]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[10]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[11]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[12]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[13]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[14]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[15]);
                r_rsip_func100(bswap_32big(0x5ec46af3U),
                               bswap_32big(0x218ccad3U),
                               bswap_32big(0xd410e771U),
                               bswap_32big(0x92c69527U));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_subfunc003(0x00820011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[16]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[17]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[18]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[19]);
                r_rsip_func100(bswap_32big(0xe844bfb9U),
                               bswap_32big(0x1bf88001U),
                               bswap_32big(0x3631693bU),
                               bswap_32big(0x1f5847f2U));
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[3]);
                r_rsip_func102(bswap_32big(0xd8501275U),
                               bswap_32big(0xbcd81f45U),
                               bswap_32big(0xdf6e227eU),
                               bswap_32big(0x7d5a4a50U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
