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
    r_rsip_subfunc009(bswap_32big(0x0000004eU));
    r_rsip_func101(bswap_32big(0x3912c78cU),
                   bswap_32big(0x331f6778U),
                   bswap_32big(0x4470d0f2U),
                   bswap_32big(0x70daca76U));
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
    r_rsip_func101(bswap_32big(0xde266c5dU),
                   bswap_32big(0x444d16a6U),
                   bswap_32big(0xf7715b6aU),
                   bswap_32big(0xcf0ac988U));
    r_rsip_func045();
    r_rsip_func076();
    r_rsip_subfunc009(bswap_32big(0x00004e01U));
    r_rsip_func101(bswap_32big(0x01b8c7c5U),
                   bswap_32big(0x217a9284U),
                   bswap_32big(0x9d9834a7U),
                   bswap_32big(0xa2a26e72U));
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
    r_rsip_func100(bswap_32big(0x00e4526eU),
                   bswap_32big(0xfbcef767U),
                   bswap_32big(0x0f59e0f1U),
                   bswap_32big(0xd4ec8c4eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x9c8fee0cU), bswap_32big(0xfa33723cU), bswap_32big(0x35f8b91eU),
                       bswap_32big(0x1b7dc97fU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
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
        r_rsip_func100(bswap_32big(0x121e79b8U), bswap_32big(0xfa46ce94U), bswap_32big(0x9855f676U),
                       bswap_32big(0xa041fca3U));
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

            r_rsip_func101(bswap_32big(0x8cc3d13eU), bswap_32big(0x7049c871U), bswap_32big(0x5dabcc4cU),
                           bswap_32big(0x03fc29f3U));
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
            r_rsip_func101(bswap_32big(0xca19d2b7U), bswap_32big(0xc4ee0e90U), bswap_32big(0xe4463ed6U),
                           bswap_32big(0x8b09ce1cU));
            r_rsip_func045();
            r_rsip_func077();
            r_rsip_subfunc009(bswap_32big(0x00004e02U));
            r_rsip_func101(bswap_32big(0x8003d705U), bswap_32big(0x8a3e2536U), bswap_32big(0xc32a5f84U),
                           bswap_32big(0xe993eb29U));
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
            r_rsip_func100(bswap_32big(0xff01e931U), bswap_32big(0xeff9e98fU), bswap_32big(0x5c621119U),
                           bswap_32big(0xf51b5289U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x4c9d9028U),
                               bswap_32big(0x255e4887U),
                               bswap_32big(0x5b1a38e7U),
                               bswap_32big(0xbc246e31U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x1c3f2a1aU),
                               bswap_32big(0xb181a59eU),
                               bswap_32big(0x2b23023aU),
                               bswap_32big(0xdb9d18efU));
            }
        }

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x06060002U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x06060002U);
        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x06060001U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000890U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x06060005U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x06060002U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x000008e0U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x06060005U);
        WR1_PROG(REG_1014H, 0x00000200U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x06060001U);
        r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x00000250U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000110U, 0x00000250U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xb3e56fe9U), bswap_32big(0x95524e18U), bswap_32big(0xa3d3a176U),
                       bswap_32big(0x8bd77bf1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x73b86585U), bswap_32big(0xe3c78c74U), bswap_32big(0x7166a051U),
                           bswap_32big(0xc44ba819U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10e00000U);
            r_rsip_subfunc003(0x00c00031U);
            r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000218U, 0x06060009U);
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x000001e0U, 0x06060009U);
            r_rsip_subfunc009(bswap_32big(0x0000004eU));
            r_rsip_func101(bswap_32big(0x99940552U), bswap_32big(0x511ef917U), bswap_32big(0xaf34b39dU),
                           bswap_32big(0x8c786c47U));
            r_rsip_func089();
            r_rsip_func100(bswap_32big(0xa851356bU), bswap_32big(0x3ae2d0a8U), bswap_32big(0x193e6c88U),
                           bswap_32big(0x5ed9578aU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x39ab8a31U),
                               bswap_32big(0xec3dc479U),
                               bswap_32big(0xdcaab4b6U),
                               bswap_32big(0xc6a23e1bU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x95b6f413U),
                               bswap_32big(0x67a595eaU),
                               bswap_32big(0x64fc04c9U),
                               bswap_32big(0x116a3368U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00004e03U));
                r_rsip_func101(bswap_32big(0xd89f8657U),
                               bswap_32big(0x96677badU),
                               bswap_32big(0x846b5e29U),
                               bswap_32big(0xbcfcb3f7U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01a2597cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00004e03U));
                r_rsip_func101(bswap_32big(0x18c9f08eU),
                               bswap_32big(0xb8e333dcU),
                               bswap_32big(0xe7e48ea0U),
                               bswap_32big(0xb8fd4955U));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0x58e9c242U),
                               bswap_32big(0x0b8a6cd2U),
                               bswap_32big(0x3b53138cU),
                               bswap_32big(0x2b6e4e4dU));
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
                r_rsip_func100(bswap_32big(0x866fd115U),
                               bswap_32big(0x02125e82U),
                               bswap_32big(0x2688f369U),
                               bswap_32big(0xb644b90fU));
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
                r_rsip_func100(bswap_32big(0x0f2f03f6U),
                               bswap_32big(0x3a84d122U),
                               bswap_32big(0x7d7dd6b2U),
                               bswap_32big(0x3062bdd3U));
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
                r_rsip_func102(bswap_32big(0x8c6bb13eU),
                               bswap_32big(0x68b398e3U),
                               bswap_32big(0xf5dc9ebaU),
                               bswap_32big(0xbcbd83e6U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
