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
    r_rsip_func101(bswap_32big(0x51c17d97U),
                   bswap_32big(0x1de84302U),
                   bswap_32big(0xffb2897dU),
                   bswap_32big(0x301b5c7dU));
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
    r_rsip_func101(bswap_32big(0xbee63699U),
                   bswap_32big(0xcf8acec2U),
                   bswap_32big(0x0915ac78U),
                   bswap_32big(0x57d8a1a4U));
    r_rsip_func045();
    r_rsip_func076();
    r_rsip_subfunc009(bswap_32big(0x00004e01U));
    r_rsip_func101(bswap_32big(0x23f63736U),
                   bswap_32big(0xd4a7308bU),
                   bswap_32big(0x2e828330U),
                   bswap_32big(0x82f692dbU));
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
    r_rsip_func100(bswap_32big(0xb968bc36U),
                   bswap_32big(0x47f9fe29U),
                   bswap_32big(0x4800500bU),
                   bswap_32big(0xca2789abU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1247840fU), bswap_32big(0xb11450dbU), bswap_32big(0x8713fe5eU),
                       bswap_32big(0x48b233b8U));
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
        r_rsip_func100(bswap_32big(0x63d4cdc6U), bswap_32big(0x6b7e0222U), bswap_32big(0x10d4c515U),
                       bswap_32big(0x098d051bU));
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

            r_rsip_func101(bswap_32big(0x5eddd687U), bswap_32big(0xbe2628c6U), bswap_32big(0x8c306270U),
                           bswap_32big(0x6fec5193U));
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
            r_rsip_func101(bswap_32big(0x7e1d3c0fU), bswap_32big(0xe2c0daf1U), bswap_32big(0xd083d76cU),
                           bswap_32big(0x49f0eb88U));
            r_rsip_func045();
            r_rsip_func077();
            r_rsip_subfunc009(bswap_32big(0x00004e02U));
            r_rsip_func101(bswap_32big(0x1d727608U), bswap_32big(0x2b585016U), bswap_32big(0x29b9356eU),
                           bswap_32big(0x8051b98aU));
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
            r_rsip_func100(bswap_32big(0xb9b673dcU), bswap_32big(0x073116afU), bswap_32big(0xe91eb6bbU),
                           bswap_32big(0xca6674d8U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xe25d10c0U),
                               bswap_32big(0x9003b553U),
                               bswap_32big(0xe462dbe1U),
                               bswap_32big(0x36a531feU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xd638eac1U),
                               bswap_32big(0xe20aab1cU),
                               bswap_32big(0xd9fc98b2U),
                               bswap_32big(0xd86b5105U));
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
        r_rsip_func100(bswap_32big(0xb2b951e9U), bswap_32big(0x7b24469eU), bswap_32big(0x521284e5U),
                       bswap_32big(0xcad2f6ebU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xb766abd0U), bswap_32big(0x080e5ab9U), bswap_32big(0x284204cfU),
                           bswap_32big(0xe7027338U));
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
            r_rsip_func101(bswap_32big(0x4e614ff3U), bswap_32big(0x9e6a9774U), bswap_32big(0x7cef2ba8U),
                           bswap_32big(0x4db646b3U));
            r_rsip_func089();
            r_rsip_func100(bswap_32big(0x25e340e2U), bswap_32big(0xc36b9973U), bswap_32big(0x1d7dea2dU),
                           bswap_32big(0x177e6732U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x53fc5f9dU),
                               bswap_32big(0x43652d69U),
                               bswap_32big(0x780ac30aU),
                               bswap_32big(0xdafa754bU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x39fdca2eU),
                               bswap_32big(0xa5d205d6U),
                               bswap_32big(0x951504f3U),
                               bswap_32big(0x6e8aef24U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00004e03U));
                r_rsip_func101(bswap_32big(0xb0393800U),
                               bswap_32big(0x8a3f70c5U),
                               bswap_32big(0x58080d6eU),
                               bswap_32big(0x14ba8a54U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0123a38cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00004e03U));
                r_rsip_func101(bswap_32big(0x78bc0daaU),
                               bswap_32big(0x3f830a27U),
                               bswap_32big(0xa23b032eU),
                               bswap_32big(0x6dacdde0U));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0x0435df91U),
                               bswap_32big(0xcb145d10U),
                               bswap_32big(0x4ee8df38U),
                               bswap_32big(0x6ad87344U));
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
                r_rsip_func100(bswap_32big(0x1b29df6cU),
                               bswap_32big(0x93ec7210U),
                               bswap_32big(0xa3be8f6fU),
                               bswap_32big(0x80b3b199U));
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
                r_rsip_func100(bswap_32big(0x5ebfcd2dU),
                               bswap_32big(0x01711706U),
                               bswap_32big(0x8916bff3U),
                               bswap_32big(0x45a74a5eU));
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
                r_rsip_func102(bswap_32big(0x32c325fbU),
                               bswap_32big(0xa4094f36U),
                               bswap_32big(0x6ec93ff0U),
                               bswap_32big(0x8e2b7f5bU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
