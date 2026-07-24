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
    r_rsip_func101(bswap_32big(0xff5a8d1dU),
                   bswap_32big(0xd7350f4dU),
                   bswap_32big(0x755e73a7U),
                   bswap_32big(0x6f3073b4U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01f7b873U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000004dU));
    r_rsip_func101(bswap_32big(0xffe52a3bU),
                   bswap_32big(0xcfebbfd7U),
                   bswap_32big(0xfdd08fd2U),
                   bswap_32big(0xb0e19173U));
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
    r_rsip_func100(bswap_32big(0x39835572U),
                   bswap_32big(0xb92e06e4U),
                   bswap_32big(0x8382584eU),
                   bswap_32big(0xe07fe90eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1ca09ad7U), bswap_32big(0x78a3abd8U), bswap_32big(0x77ebdd17U),
                       bswap_32big(0x2913c23bU));
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
        r_rsip_func100(bswap_32big(0x119849f8U), bswap_32big(0xb289d209U), bswap_32big(0x8d46408eU),
                       bswap_32big(0xf3fa370aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x9bddb81dU), bswap_32big(0x2b8438f1U), bswap_32big(0xbbd67961U),
                           bswap_32big(0xc724f689U));
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
            r_rsip_func100(bswap_32big(0x9020aee7U), bswap_32big(0x6d76d3feU), bswap_32big(0x4b8c6e18U),
                           bswap_32big(0x0d1e036aU));
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
            r_rsip_subfunc009(bswap_32big(0x0000004dU));
            r_rsip_func101(bswap_32big(0x8778f8feU), bswap_32big(0xcdf18f65U), bswap_32big(0xc7742697U),
                           bswap_32big(0x8cba1901U));
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
            r_rsip_func100(bswap_32big(0xbbcaeaa9U), bswap_32big(0x6953d46aU), bswap_32big(0xd154d331U),
                           bswap_32big(0xb8338cb6U));
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
            r_rsip_func100(bswap_32big(0x565c70ceU), bswap_32big(0x3e5786c8U), bswap_32big(0xa93870edU),
                           bswap_32big(0x61a04efcU));
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
            r_rsip_func100(bswap_32big(0x1185ef59U), bswap_32big(0x01f954b1U), bswap_32big(0x286ccd7fU),
                           bswap_32big(0x39b7788eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x000002f0U, 0x00000250U, 0x00000ac0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000250U, 0x000002f0U, 0x00000ac0U, 0x0404000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0xcc4df2a0U),
                               bswap_32big(0x3a14dd4bU),
                               bswap_32big(0x3f1498a7U),
                               bswap_32big(0x74a628e3U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1600H, 0x00000800U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x7080f243U),
                                   bswap_32big(0xd5ed357bU),
                                   bswap_32big(0x689212e1U),
                                   bswap_32big(0x4a58cdc6U));
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
                    WR1_PROG(REG_1600H, 0x13b56e43U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xd029af82U),
                                   bswap_32big(0x0ec5f8d6U),
                                   bswap_32big(0x04071754U),
                                   bswap_32big(0xffa33ec6U));
                }
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x13b56e43U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xdea6ee18U),
                               bswap_32big(0xc6670c40U),
                               bswap_32big(0x8bf52e59U),
                               bswap_32big(0x6524dba9U));
            }

            WR1_PROG(REG_1600H, 0x38008800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x13b56e43U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0x38f8968fU), bswap_32big(0xc111981dU), bswap_32big(0x6059ae2fU),
                           bswap_32big(0x196cd225U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xa215b0f7U),
                               bswap_32big(0xa14fafe9U),
                               bswap_32big(0x34d2ae24U),
                               bswap_32big(0x5fcf49e9U));
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
                r_rsip_func100(bswap_32big(0xd0a4acf4U),
                               bswap_32big(0xdb48ee24U),
                               bswap_32big(0x0dc908c9U),
                               bswap_32big(0x68d8a1feU));
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
                    r_rsip_func101(bswap_32big(0xd9d035d6U),
                                   bswap_32big(0x3ffffc5cU),
                                   bswap_32big(0x611d6964U),
                                   bswap_32big(0xd7102148U));
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
                    r_rsip_func101(bswap_32big(0x6e42fb4eU),
                                   bswap_32big(0x3c1b764fU),
                                   bswap_32big(0xf9694f4cU),
                                   bswap_32big(0xa97af6afU));
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
                    r_rsip_func101(bswap_32big(0x702ba745U),
                                   bswap_32big(0x058fa4e4U),
                                   bswap_32big(0xb791de43U),
                                   bswap_32big(0xfb811089U));
                    r_rsip_func402();
                    r_rsip_func404();
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x9fdb52a2U),
                                   bswap_32big(0x2647c19cU),
                                   bswap_32big(0x9036de8dU),
                                   bswap_32big(0x1892e28eU));
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
                r_rsip_func101(bswap_32big(0x1c1e25dbU),
                               bswap_32big(0xd2443417U),
                               bswap_32big(0x5da3d6b5U),
                               bswap_32big(0x07f7ddb0U));
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
                    r_rsip_func101(bswap_32big(0xf36d9221U),
                                   bswap_32big(0x0859ee55U),
                                   bswap_32big(0xc95501a0U),
                                   bswap_32big(0xdf6530fbU));
                    r_rsip_func402();
                    r_rsip_func404();
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x232f488dU),
                                   bswap_32big(0x43ad9348U),
                                   bswap_32big(0xee6bcf15U),
                                   bswap_32big(0x6db858a8U));
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
                r_rsip_func100(bswap_32big(0xd165543bU),
                               bswap_32big(0x6bfa6d1dU),
                               bswap_32big(0x4155287eU),
                               bswap_32big(0xd3b32d63U));
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
                r_rsip_func100(bswap_32big(0xc4d129eaU),
                               bswap_32big(0x8dc01c1aU),
                               bswap_32big(0xc382c138U),
                               bswap_32big(0xcf1a11e6U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x05c31174U),
                                   bswap_32big(0xf462d2daU),
                                   bswap_32big(0x085092d4U),
                                   bswap_32big(0x9fcc6414U));
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func102(bswap_32big(0x61ebbce6U),
                                   bswap_32big(0xca03830bU),
                                   bswap_32big(0xd828834bU),
                                   bswap_32big(0x31541f69U));
                    WR1_PROG(REG_14BCH, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
