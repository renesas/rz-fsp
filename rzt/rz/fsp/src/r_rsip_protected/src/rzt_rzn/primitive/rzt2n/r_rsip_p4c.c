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

rsip_ret_t r_rsip_p4c (const uint32_t InData_PrivKeyIndex[],
                       const uint32_t InData_PubKeyIndex[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[],
                       uint64_t       MAX_CNT)
{
    RSIP_PRV_PRIMITIVE_ENTRY;
    uint64_t iLoop;
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x004c0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000008c8U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004c01U));
    r_rsip_func101(bswap_32big(0xf4c8adfdU),
                   bswap_32big(0xa00b6803U),
                   bswap_32big(0xacd8e568U),
                   bswap_32big(0x742a78ebU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01793385U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004c01U));
    r_rsip_func101(bswap_32big(0x4a52614bU),
                   bswap_32big(0xe9bf8aa4U),
                   bswap_32big(0xbcdc7134U),
                   bswap_32big(0x8f790ffbU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 7]);
    }

    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80880000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420021U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 4]);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 5]);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 6]);
    WR1_ADDR(REG_1420H, &InData_PrivKeyIndex[iLoop + 7]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0xee74cd0fU),
                   bswap_32big(0xe53479e6U),
                   bswap_32big(0xb7b2dd6fU),
                   bswap_32big(0x708b2708U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1afeaf29U), bswap_32big(0xae8d6191U), bswap_32big(0x81b01102U),
                       bswap_32big(0xe355a94bU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00004c02U));
        r_rsip_func101(bswap_32big(0x13e6eea3U), bswap_32big(0x9c96ae00U), bswap_32big(0x53dc9ac5U),
                       bswap_32big(0x13b6ed31U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01f7b873U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00004c02U));
        r_rsip_func101(bswap_32big(0xbb206c20U), bswap_32big(0x0dd05e2aU), bswap_32big(0xf0b3fd53U),
                       bswap_32big(0x70faebddU));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8009105U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[4]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[5]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[6]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[7]);
        WR1_PROG(REG_1404H, 0x19100000U);
        r_rsip_subfunc003(0x00c20011U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[8]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[9]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[10]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[11]);
        r_rsip_subfunc003(0x00c20011U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[12]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[13]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[14]);
        WR1_ADDR(REG_1420H, &InData_PubKeyIndex[15]);
        r_rsip_func100(bswap_32big(0x62838854U), bswap_32big(0x9d5d04cdU), bswap_32big(0x3103a1c4U),
                       bswap_32big(0xe0cf2a06U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xd2c63c1aU), bswap_32big(0xf04ae6ccU), bswap_32big(0x7b904afbU),
                           bswap_32big(0xa9092678U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_MsgLen[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_MsgLen[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x30008800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0xffffffffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00030020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3000a820U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0xfffffdffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00050020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x1000d3e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38008be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x528e3a15U), bswap_32big(0xbea19d59U), bswap_32big(0xefcc0de7U),
                           bswap_32big(0x7a484eadU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x0c4d938eU),
                               bswap_32big(0x0e7876edU),
                               bswap_32big(0x9c92bbe9U),
                               bswap_32big(0x39e87835U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xa1981cd4U),
                               bswap_32big(0xf1707065U),
                               bswap_32big(0x93b282a5U),
                               bswap_32big(0x1fd1bd41U));
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0c00a420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000100U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00802402U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81020000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x0000500aU);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                r_rsip_func100(bswap_32big(0xf3d5adf9U),
                               bswap_32big(0x806dfde1U),
                               bswap_32big(0xb91e7c9dU),
                               bswap_32big(0xd18cac7aU));
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0c00a420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000100U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00802402U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81020000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x0000500aU);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[3]);
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x000000b0U);
                WR1_PROG(REG_1444H, 0x00000020U);
                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x00000020U);
                WR1_PROG(REG_2010H, 0x00000100U);
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x8188001eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x01490021U);
                WAIT_STS(REG_2030H, 4U, 1U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80900001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450041U);
                WR1_PROG(REG_1600H, 0x00003841U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xf8ffffffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c41U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003841U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xffffff3fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00009040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c41U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x19600000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x000000b0U);
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2014H, &S_RAM[0]);
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2010H, &S_RAM[1]);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x01490021U);
                WR1_PROG(REG_1444H, 0x00020064U);
                for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffffffffffff0U); iLoop = iLoop + 8)
                {
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 3]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 4]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 5]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 6]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 7]);
                }

                WAIT_STS(REG_1444H, 31U, 1U);
                for (iLoop = (MAX_CNT & 0xfffffffffffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
                {
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
                }

                WR1_PROG(REG_1444H, 0x00000000U);
                WAIT_STS(REG_2030H, 4U, 1U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80900001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450041U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000003fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x02003801U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003843U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c41U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c03U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                r_rsip_subfunc009(bswap_32big(0x0000004cU));
                r_rsip_func101(bswap_32big(0x1962212cU),
                               bswap_32big(0xbb10b356U),
                               bswap_32big(0xc3404535U),
                               bswap_32big(0xde53c16dU));
                r_rsip_func401(InData_DomainParam);
                r_rsip_subfunc009(bswap_32big(0x0000004cU));
                r_rsip_func101(bswap_32big(0x49024278U),
                               bswap_32big(0x199f68b3U),
                               bswap_32big(0x50dbde0dU),
                               bswap_32big(0xfc751cc8U));
                r_rsip_func406(InData_DomainParam);
                WR1_PROG(REG_1404H, 0x12300000U);
                WR1_PROG(REG_1444H, 0x000007c2U);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0EEC73D2U));
                WR1_PROG(REG_1420H, bswap_32big(0x17F5BE65U));
                WR1_PROG(REG_1420H, bswap_32big(0xCB5C63AAU));
                WR1_PROG(REG_1420H, bswap_32big(0x97A331B5U));
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0665E1DBU));
                WR1_PROG(REG_1420H, bswap_32big(0x6EABA043U));
                WR1_PROG(REG_1420H, bswap_32big(0xF98B4BAAU));
                WR1_PROG(REG_1420H, bswap_32big(0x9C78F954U));
                r_rsip_subfunc003(0x00c20021U);
                WR1_PROG(REG_1404H, 0x12800000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x000002a0U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                WR1_PROG(REG_1020H, 0x000002f0U);
                WR1_PROG(REG_1010H, 0x00000010U);
                WR1_PROG(REG_1004H, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12300000U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000200U);
                r_rsip_subfunc002(0x000000c0U, 0x000002a0U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x000002a0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000250U, 0x04040004U);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x000002f0U);
                r_rsip_subfunc002(0x000000c0U, 0x000009d0U, 0x04040005U);
                WR1_PROG(REG_1404H, 0x15000000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
                r_rsip_subfunc003(0x00c00015U);
                r_rsip_subfunc003(0x00c2000dU);
                r_rsip_subfunc003(0x00020005U);
                WR1_PROG(REG_1404H, 0x16400000U);
                r_rsip_subfunc003(0x00c00021U);
                WR1_PROG(REG_1404H, 0x16900000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
                r_rsip_subfunc003(0x00c00015U);
                r_rsip_subfunc003(0x00c2000dU);
                r_rsip_subfunc003(0x00020005U);
                WR1_PROG(REG_1404H, 0x16e00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
                r_rsip_subfunc003(0x00c00015U);
                r_rsip_subfunc003(0x00c2000dU);
                r_rsip_subfunc003(0x00020005U);
                WR1_PROG(REG_1404H, 0x1b400000U);
                r_rsip_subfunc003(0x00c00021U);
                WR1_PROG(REG_1404H, 0x1b900000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
                r_rsip_subfunc003(0x00c00015U);
                r_rsip_subfunc003(0x00c2000dU);
                r_rsip_subfunc003(0x00020005U);
                WR1_PROG(REG_1404H, 0x1be00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
                r_rsip_subfunc003(0x00c00015U);
                r_rsip_subfunc003(0x00c2000dU);
                r_rsip_subfunc003(0x00020005U);
                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1600H, 0x00000bffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x8088001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430021U);
                WR1_PROG(REG_1600H, 0x00000908U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b660U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b520U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000100U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x0000004cU));
                for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
                {
                    r_rsip_func405();
                    r_rsip_func403();
                    r_rsip_func101(bswap_32big(0x1f5b0bbbU),
                                   bswap_32big(0x7f4a9435U),
                                   bswap_32big(0x57a0c136U),
                                   bswap_32big(0xb9e0dbc4U));
                    r_rsip_func402();
                    r_rsip_func404();
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xab31f28aU),
                                   bswap_32big(0x1bae740fU),
                                   bswap_32big(0x5f21e430U),
                                   bswap_32big(0xac577ad2U));
                }

                WR1_PROG(REG_1600H, 0x08000909U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc001(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);
                r_rsip_subfunc001(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);
                r_rsip_subfunc001(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);
                WR1_PROG(REG_1014H, 0x00000610U);
                WR1_PROG(REG_101CH, 0x00000070U);
                WR1_PROG(REG_1020H, 0x00000250U);
                WR1_PROG(REG_1010H, 0x00000008U);
                WR1_PROG(REG_1004H, 0x04040004U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x12d00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0001dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000070U, 0x000002f0U, 0x000002a0U, 0x0404000aU);
                r_rsip_func100(bswap_32big(0xacf12f39U),
                               bswap_32big(0x1057f00aU),
                               bswap_32big(0x0cabfda3U),
                               bswap_32big(0x6549181aU));
                r_rsip_subfunc005(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00020000U);
                WR1_PROG(REG_1014H, 0x00000570U);
                WR1_PROG(REG_1018H, 0x000002f0U);
                r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x000005c0U);
                WR1_PROG(REG_1018H, 0x000002f0U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040002U);
                WR1_PROG(REG_1404H, 0x12800000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430021U);
                WR1_PROG(REG_1600H, 0x00003801U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x7fffffffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x12300000U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430021U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000003cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003841U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x001f6c42U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00001002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c01U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x02003801U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003843U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c41U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c03U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1404H, 0x1c300000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x000000b0U);
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2014H, &S_RAM[2]);
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2010H, &S_RAM[3]);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x01490021U);
                WR1_PROG(REG_1404H, 0x19100000U);
                r_rsip_subfunc003(0x01430021U);
                WR1_PROG(REG_1444H, 0x00020064U);
                for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffffffffffff0U); iLoop = iLoop + 16)
                {
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 3]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 4]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 5]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 6]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 7]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 8]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 9]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 10]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 11]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 12]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 13]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 14]);
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 15]);
                }

                WAIT_STS(REG_1444H, 31U, 1U);
                for (iLoop = (MAX_CNT & 0xfffffffffffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
                {
                    WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
                }

                WR1_PROG(REG_1444H, 0x00000000U);
                WAIT_STS(REG_2030H, 4U, 1U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80900001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450041U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000003fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x02003801U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003843U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c41U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c03U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81900001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x1a000000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_1404H, 0x1a500000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_1404H, 0x19600000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430021U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x02003801U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003843U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c41U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c03U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1404H, 0x19600000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90021U);
                WR1_PROG(REG_1404H, 0x12300000U);
                WR1_PROG(REG_1444H, 0x000007c2U);
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0EEC73D2U));
                WR1_PROG(REG_1420H, bswap_32big(0x17F5BE65U));
                WR1_PROG(REG_1420H, bswap_32big(0xCB5C63AAU));
                WR1_PROG(REG_1420H, bswap_32big(0x97A331B5U));
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x0665E1DBU));
                WR1_PROG(REG_1420H, bswap_32big(0x6EABA043U));
                WR1_PROG(REG_1420H, bswap_32big(0xF98B4BAAU));
                WR1_PROG(REG_1420H, bswap_32big(0x9C78F954U));
                r_rsip_subfunc003(0x00c20021U);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000a20U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                WR1_PROG(REG_1020H, 0x000002a0U);
                WR1_PROG(REG_1010H, 0x00000010U);
                WR1_PROG(REG_1004H, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000a70U);
                WR1_PROG(REG_1018H, 0x00000200U);
                r_rsip_subfunc002(0x000000c0U, 0x00000250U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x00000250U);
                r_rsip_subfunc002(0x000000c0U, 0x000003e0U, 0x04040004U);
                WR1_PROG(REG_1014H, 0x000003e0U);
                WR1_PROG(REG_1018H, 0x000002a0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000340U, 0x04040005U);
                r_rsip_subfunc001(0x00000980U, 0x00000b10U, 0x00000430U, 0x0404000aU);
                WR1_PROG(REG_1014H, 0x00000200U);
                WR1_PROG(REG_1018H, 0x00000340U);
                r_rsip_subfunc002(0x000000c0U, 0x00000390U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x00000390U);
                WR1_PROG(REG_1018H, 0x00000430U);
                r_rsip_subfunc002(0x000000c0U, 0x000003e0U, 0x04040002U);
                r_rsip_subfunc001(0x000009d0U, 0x00000b10U, 0x000002f0U, 0x0404000aU);
                WR1_PROG(REG_1014H, 0x000002f0U);
                WR1_PROG(REG_1018H, 0x000003e0U);
                r_rsip_subfunc002(0x000000c0U, 0x000002a0U, 0x04040005U);
                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000842U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x12800000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430021U);
                for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x02003801U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003843U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c41U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x02003c03U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002c20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003060U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                r_rsip_func100(bswap_32big(0x65a134b9U),
                               bswap_32big(0x6d5afca1U),
                               bswap_32big(0x40fa9296U),
                               bswap_32big(0x389e5851U));
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                WR1_PROG(REG_1404H, 0x1c300000U);
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
                r_rsip_func100(bswap_32big(0xc22506e2U),
                               bswap_32big(0x30e2e9baU),
                               bswap_32big(0x1592a625U),
                               bswap_32big(0xb2366f46U));
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005022U);
                for (iLoop = 8; iLoop < 16; iLoop = iLoop + 1)
                {
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[iLoop]);
                }

                r_rsip_func102(bswap_32big(0x1c370f85U),
                               bswap_32big(0x0620ff67U),
                               bswap_32big(0x2750f11cU),
                               bswap_32big(0x82773dffU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
