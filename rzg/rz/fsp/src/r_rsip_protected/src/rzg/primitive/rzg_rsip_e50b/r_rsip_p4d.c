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

rsip_ret_t r_rsip_p4d (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_Msg[],
                       const uint32_t InData_MsgLen[],
                       const uint32_t InData_Signature[],
                       const uint32_t InData_DomainParam[],
                       uint64_t       MAX_CNT)
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x004d0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000008c8U);
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
    r_rsip_subfunc009(bswap_32big(0x0000004dU));
    r_rsip_func101(bswap_32big(0x3336f33eU),
                   bswap_32big(0x3dd219cfU),
                   bswap_32big(0xfd745f3bU),
                   bswap_32big(0xb4f14234U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01f49b81U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000004dU));
    r_rsip_func101(bswap_32big(0x1ae3c32dU),
                   bswap_32big(0xa994b12eU),
                   bswap_32big(0x4553aeb5U),
                   bswap_32big(0x4719c4cdU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
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
    WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
    r_rsip_subfunc003(0x00c20011U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[12]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[14]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[15]);
    r_rsip_func100(bswap_32big(0xec0ef536U),
                   bswap_32big(0xf71deafaU),
                   bswap_32big(0x6027318fU),
                   bswap_32big(0x61f6bcbeU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4cbd3adaU), bswap_32big(0xa43f4809U), bswap_32big(0x404f061eU),
                       bswap_32big(0x50265128U));
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
        r_rsip_func100(bswap_32big(0x57cbfc22U), bswap_32big(0x4e59b97aU), bswap_32big(0x4c56929cU),
                       bswap_32big(0x9d15742bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x910dce87U), bswap_32big(0x39c4d4fbU), bswap_32big(0x4f9668bcU),
                           bswap_32big(0x6a9b61c7U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1404H, 0x1c300000U);
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
            r_rsip_subfunc003(0x00c20021U);
            r_rsip_func100(bswap_32big(0x359f55d2U), bswap_32big(0x9d2ba9bdU), bswap_32big(0xdaa5daefU),
                           bswap_32big(0x7975bc15U));
            WR1_PROG(REG_1600H, 0x00000842U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0c00a420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000200U);
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
            WR1_PROG(REG_2000H, 0x00000001U);
            WR1_PROG(REG_2004H, 0x000000b0U);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2014H, &S_RAM[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2010H, &S_RAM[1]);
            WR1_PROG(REG_1404H, 0x1c300000U);
            r_rsip_subfunc003(0x01430021U);
            WR1_PROG(REG_1404H, 0x19100000U);
            r_rsip_subfunc003(0x01430021U);
            WR1_PROG(REG_1444H, 0x00020064U);
            for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
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
            for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
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
            r_rsip_subfunc009(bswap_32big(0x0000004dU));
            r_rsip_func101(bswap_32big(0xbc85c532U), bswap_32big(0x3be333f1U), bswap_32big(0xc871e165U),
                           bswap_32big(0xe35c1c9aU));
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
            r_rsip_subfunc002(0x000000c0U, 0x000009d0U, 0x04040005U);
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
            WR1_PROG(REG_1404H, 0x19100000U);
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

            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x02003801U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00076800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000037e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00008c40U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000007FU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x02003c41U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81880000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x12300000U);
            r_rsip_subfunc003(0x00c90021U);
            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000004d0U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x000004d0U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);
            WR1_PROG(REG_1014H, 0x000004d0U);
            WR1_PROG(REG_1018H, 0x00000ac0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002a0U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x000002a0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040006U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000250U);
            WR1_PROG(REG_1018H, 0x00000160U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000390U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000390U);
            WR1_PROG(REG_1018H, 0x000002a0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000340U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040005U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000340U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000250U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x12800000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0001dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1014H, 0x00000070U);
            WR1_PROG(REG_1018H, 0x000002a0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000003e0U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040006U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_func100(bswap_32big(0xc3ad9f78U), bswap_32big(0x4e8c8357U), bswap_32big(0x4cf8d6cdU),
                           bswap_32big(0xec64180cU));
            r_rsip_subfunc005(0x00000250U, 0x000003e0U, 0x00000070U, 0x000002a0U, 0x0404000fU, 0x00020000U);
            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_1018H, 0x000002a0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000390U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x12300000U);
            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x0FFFFFFFU));
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFFU));
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_1420H, bswap_32big(0xFFFFFFFEU));
            r_rsip_subfunc003(0x00c20021U);
            r_rsip_func100(bswap_32big(0xf37f0c54U), bswap_32big(0x7af16e93U), bswap_32big(0xabed3afaU),
                           bswap_32big(0xf5cf17faU));
            r_rsip_subfunc005(0x00000390U, 0x00000250U, 0x00000070U, 0x000003e0U, 0x0404000fU, 0x00020000U);
            WR1_PROG(REG_1014H, 0x000003e0U);
            WR1_PROG(REG_1018H, 0x000001b0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x000002f0U, 0x00000b10U, 0x00000ac0U, 0x0404000aU);
            WR1_PROG(REG_1014H, 0x000002f0U);
            WR1_PROG(REG_1018H, 0x00000ac0U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x00000340U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040002U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1014H, 0x00000340U);
            WR1_PROG(REG_101CH, 0x00000070U);
            WR1_PROG(REG_1020H, 0x000002f0U);
            WR1_PROG(REG_1010H, 0x00000008U);
            WR1_PROG(REG_1004H, 0x04040004U);
            WR1_PROG(REG_1000H, 0x00010001U);
            WAIT_STS(REG_1000H, 0U, 0U);
            r_rsip_subfunc001(0x00000070U, 0x00000390U, 0x00000250U, 0x04040006U);
            r_rsip_subfunc001(0x000002f0U, 0x00000390U, 0x00000ac0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000390U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xeaaf9690U), bswap_32big(0x4a4c1656U), bswap_32big(0xac984242U),
                           bswap_32big(0x6a8f59cfU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x000002f0U, 0x00000250U, 0x00000ac0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000250U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x7f5ab3f9U),
                               bswap_32big(0xd8b9907aU),
                               bswap_32big(0xb2f5999cU),
                               bswap_32big(0x90085b20U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xc864f7f2U),
                                   bswap_32big(0xc3d5d0dfU),
                                   bswap_32big(0x01b16775U),
                                   bswap_32big(0x71e4bec2U));
                }
                else
                {
                    WR1_PROG(REG_1014H, 0x000003e0U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000250U);
                    WR1_PROG(REG_1010H, 0x00000008U);
                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1404H, 0x12800000U);
                    WR1_PROG(REG_1444H, 0x000007c2U);
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x2B832480U));
                    WR1_PROG(REG_1420H, bswap_32big(0x4FC1DF0BU));
                    WR1_PROG(REG_1420H, bswap_32big(0x2B4D0099U));
                    WR1_PROG(REG_1420H, bswap_32big(0x3DFBD7A7U));
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x2F431806U));
                    WR1_PROG(REG_1420H, bswap_32big(0xAD2FE478U));
                    WR1_PROG(REG_1420H, bswap_32big(0xC4EE1B27U));
                    WR1_PROG(REG_1420H, bswap_32big(0x4A0EA0B0U));
                    r_rsip_subfunc003(0x00c20021U);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_1018H, 0x000002a0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x000003e0U);
                    WR1_PROG(REG_1010H, 0x00000008U);
                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    WR1_PROG(REG_1600H, 0x0000b400U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0xfd3bc9fcU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xe2dc4677U),
                                   bswap_32big(0xc9d06172U),
                                   bswap_32big(0x0287817dU),
                                   bswap_32big(0x9b4b0f47U));
                }
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xfd3bc9fcU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xa82a3f6aU),
                               bswap_32big(0x941a2f76U),
                               bswap_32big(0xbba02b39U),
                               bswap_32big(0xc61c8c3eU));
            }

            WR1_PROG(REG_1600H, 0x38008800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0xfd3bc9fcU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0x4c999aa8U), bswap_32big(0x409b9ae8U), bswap_32big(0x18f90827U),
                           bswap_32big(0x9b4f306bU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xe109e2b9U),
                               bswap_32big(0xecfd41f1U),
                               bswap_32big(0x48e9ad56U),
                               bswap_32big(0xc6aee0f8U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_1404H, 0x13c00000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430021U);
                WR1_PROG(REG_1600H, 0x0000b420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x02003841U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00008c40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3800085fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0x6bc6ad42U),
                               bswap_32big(0xf4821a03U),
                               bswap_32big(0xd44d3f6dU),
                               bswap_32big(0x07e596a1U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1014H, 0x000003e0U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000480U);
                    WR1_PROG(REG_1010H, 0x00000008U);
                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    r_rsip_func101(bswap_32big(0x53d40e9bU),
                                   bswap_32big(0x9e5fe59fU),
                                   bswap_32big(0x129b7379U),
                                   bswap_32big(0xc962d298U));
                }
                else
                {
                    r_rsip_subfunc001(0x00000070U, 0x000003e0U, 0x00000250U, 0x04040006U);
                    WR1_PROG(REG_1014H, 0x00000250U);
                    WR1_PROG(REG_1018H, 0x000001b0U);
                    WR1_PROG(REG_101CH, 0x00000070U);
                    WR1_PROG(REG_1020H, 0x00000480U);
                    WR1_PROG(REG_1010H, 0x00000008U);
                    WR1_PROG(REG_1004H, 0x04040002U);
                    WR1_PROG(REG_1000H, 0x00010001U);
                    WAIT_STS(REG_1000H, 0U, 0U);
                    r_rsip_func101(bswap_32big(0xc9aa2a0dU),
                                   bswap_32big(0x2b20fec7U),
                                   bswap_32big(0x41a82e69U),
                                   bswap_32big(0xf5d0a206U));
                }

                WR1_PROG(REG_1010H, 0x00000008U);
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
                r_rsip_subfunc009(bswap_32big(0x00004d01U));
                for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
                {
                    r_rsip_func405();
                    r_rsip_func403();
                    r_rsip_func101(bswap_32big(0xac3e58fcU),
                                   bswap_32big(0xc810bd95U),
                                   bswap_32big(0x67439fd1U),
                                   bswap_32big(0x8c8e1e52U));
                    r_rsip_func402();
                    r_rsip_func404();
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xf5c00294U),
                                   bswap_32big(0x03ab066fU),
                                   bswap_32big(0x44b8b4a4U),
                                   bswap_32big(0xda65e8faU));
                }

                WR1_PROG(REG_1600H, 0x08000909U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc001(0x00000660U, 0x00000b10U, 0x00000ca0U, 0x0404000aU);
                r_rsip_subfunc001(0x000006b0U, 0x00000b10U, 0x00000cf0U, 0x0404000aU);
                r_rsip_subfunc001(0x00000700U, 0x00000b10U, 0x00000d40U, 0x0404000aU);
                WR1_PROG(REG_1444H, 0x000007c7U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x80880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 8; iLoop < 16; iLoop = iLoop + 1)
                {
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_Signature[iLoop + 0]);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

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
                WR1_PROG(REG_1404H, 0x12800000U);
                r_rsip_subfunc003(0x00c00021U);
                WR1_PROG(REG_1014H, 0x000002a0U);
                WR1_PROG(REG_1018H, 0x00000250U);
                WR1_PROG(REG_101CH, 0x000000c0U);
                WR1_PROG(REG_1020H, 0x000002f0U);
                WR1_PROG(REG_1010H, 0x00000010U);
                WR1_PROG(REG_1004H, 0x04040002U);
                WR1_PROG(REG_1000H, 0x00010001U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1014H, 0x00000980U);
                WR1_PROG(REG_1018H, 0x00000200U);
                r_rsip_subfunc002(0x000000c0U, 0x00000250U, 0x04040002U);
                WR1_PROG(REG_1014H, 0x00000250U);
                r_rsip_subfunc002(0x000000c0U, 0x000003e0U, 0x04040004U);
                WR1_PROG(REG_1014H, 0x000003e0U);
                WR1_PROG(REG_1018H, 0x000002f0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000980U, 0x04040005U);
                WR1_PROG(REG_1010H, 0x00000008U);
                r_rsip_subfunc009(bswap_32big(0x0000004dU));
                r_rsip_func101(bswap_32big(0xd45a2554U),
                               bswap_32big(0x44ebc1afU),
                               bswap_32big(0x94260fe6U),
                               bswap_32big(0xa8583a54U));
                r_rsip_func401(InData_DomainParam);
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
                WR1_PROG(REG_1404H, 0x19600000U);
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
                r_rsip_subfunc009(bswap_32big(0x00004d02U));
                for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
                {
                    r_rsip_func405();
                    r_rsip_func403();
                    r_rsip_func101(bswap_32big(0x5ad5c7a9U),
                                   bswap_32big(0xee16384dU),
                                   bswap_32big(0xb0fe0acaU),
                                   bswap_32big(0x1d33df24U));
                    r_rsip_func402();
                    r_rsip_func404();
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xb4ccd440U),
                                   bswap_32big(0xe774ef5eU),
                                   bswap_32big(0xc5493a78U),
                                   bswap_32big(0x7299144fU));
                }

                WR1_PROG(REG_1600H, 0x08000909U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc001(0x00000660U, 0x00000b10U, 0x00000750U, 0x0404000aU);
                r_rsip_subfunc001(0x000006b0U, 0x00000b10U, 0x000007a0U, 0x0404000aU);
                r_rsip_subfunc001(0x00000700U, 0x00000b10U, 0x000007f0U, 0x0404000aU);
                WR1_PROG(REG_1404H, 0x12300000U);
                r_rsip_subfunc003(0x00c00021U);
                WR1_PROG(REG_1014H, 0x00000250U);
                WR1_PROG(REG_1018H, 0x00000ca0U);
                r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040006U);
                r_rsip_subfunc001(0x000002a0U, 0x00000b10U, 0x00000ca0U, 0x0404000aU);
                r_rsip_subfunc001(0x00000ca0U, 0x00000b10U, 0x00000570U, 0x0404000aU);
                r_rsip_subfunc001(0x00000cf0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);
                r_rsip_subfunc001(0x00000d40U, 0x00000b10U, 0x00000610U, 0x0404000aU);
                r_rsip_func404();
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
                r_rsip_subfunc001(0x00000070U, 0x000002f0U, 0x000002a0U, 0x04040006U);
                r_rsip_func100(bswap_32big(0xf3d0d6b6U),
                               bswap_32big(0x7c7d142eU),
                               bswap_32big(0x78b3801dU),
                               bswap_32big(0x362ea1fcU));
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

                WR1_PROG(REG_1404H, 0x12300000U);
                WR1_PROG(REG_1600H, 0x00000821U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81880001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90021U);
                r_rsip_subfunc001(0x00000250U, 0x00000c50U, 0x000002a0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000c50U, 0x00000250U, 0x000002a0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x4a9018bbU),
                               bswap_32big(0xac77f7cbU),
                               bswap_32big(0x2d027b0dU),
                               bswap_32big(0xb16660b1U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x05790cf6U),
                                   bswap_32big(0x8cdb6526U),
                                   bswap_32big(0x5c8b010cU),
                                   bswap_32big(0x7adf74f6U));
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func102(bswap_32big(0xb6ec2dc3U),
                                   bswap_32big(0x167a026bU),
                                   bswap_32big(0xf7cab2dfU),
                                   bswap_32big(0x95725a62U));
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
