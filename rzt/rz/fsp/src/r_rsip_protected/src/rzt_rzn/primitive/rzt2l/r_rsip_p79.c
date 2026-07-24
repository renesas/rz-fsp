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

rsip_ret_t r_rsip_p79 (uint32_t const InData_KeyIndex[], uint32_t const InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_1B00H, 0x00790002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000fe8U);
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
    r_rsip_subfunc009(bswap_32big(0x00000079U));
    r_rsip_func101(bswap_32big(0x08c8a9bbU),
                   bswap_32big(0x51aca273U),
                   bswap_32big(0x3b2347c0U),
                   bswap_32big(0x659b9ba4U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01d1a79cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00000079U));
    r_rsip_func101(bswap_32big(0x7fead8c7U),
                   bswap_32big(0x9e27d49cU),
                   bswap_32big(0x5fa5e32aU),
                   bswap_32big(0x9093a1a0U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x00005fc2U);
    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0; iLoop < 96; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
        r_rsip_subfunc003(0x00c20021U);
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
    WR1_ADDR(REG_1420H, &InData_KeyIndex[100]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[101]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[102]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[103]);
    WR1_PROG(REG_1404H, 0x14200000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[104]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[105]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[106]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[107]);
    r_rsip_func100(bswap_32big(0x58ce4136U),
                   bswap_32big(0xaadafcdcU),
                   bswap_32big(0xf3cadb1eU),
                   bswap_32big(0x082f919eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x9d2f8111U), bswap_32big(0xa2221d49U), bswap_32big(0x909817e1U),
                       bswap_32big(0xb4032a66U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00005fd0U);
        for (iLoop = 0; iLoop < 384; iLoop = iLoop + 4)
        {
            WR1_ADDR((&(REG_00A0H))[iLoop / 4], &InData_Text[(iLoop / 4) + 0]);
        }

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800dbe0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0017dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000838U, 0x3030000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
        r_rsip_subfunc003(0x00c0017dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x3030000aU);
        r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000a40U, 0x3030000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x14542cb8U), bswap_32big(0xcdb45f7eU), bswap_32big(0x72516c7cU),
                       bswap_32big(0x06be05f4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xd9b4bc46U), bswap_32big(0x87b0af8cU), bswap_32big(0x2c6b41f7U),
                           bswap_32big(0x409c79faU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x00000079U));
            r_rsip_func101(bswap_32big(0x001c1d87U), bswap_32big(0x606bf5a8U), bswap_32big(0x35cd502eU),
                           bswap_32big(0x18591706U));
            r_rsip_func030();
            WR1_PROG(REG_1404H, 0x1ae00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c00005U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00109U);
            r_rsip_subfunc009(bswap_32big(0x00007901U));
            r_rsip_func101(bswap_32big(0xb186c1f8U), bswap_32big(0x31ab65d5U), bswap_32big(0x95d33d98U),
                           bswap_32big(0xc875bfdfU));
            r_rsip_func031();
            r_rsip_func100(bswap_32big(0x9cfeff32U), bswap_32big(0xe07b55e7U), bswap_32big(0xbb03554eU),
                           bswap_32big(0x0897a18cU));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0x9c20234dU), bswap_32big(0x8aa2c916U), bswap_32big(0xaa857fa0U),
                           bswap_32big(0x352be19bU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x9d5fee47U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007901U));
            r_rsip_func101(bswap_32big(0x9325585cU), bswap_32big(0x4fb90ebdU), bswap_32big(0x83f62d58U),
                           bswap_32big(0x0c2f4d4eU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000008U));
            r_rsip_subfunc003(0x00c00005U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000948U, 0x00000838U, 0x00000838U, 0x30300008U);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00109U);
            r_rsip_subfunc001(0x00000738U, 0x00000948U, 0x00000b68U, 0x11110009U);
            r_rsip_subfunc001(0x00000838U, 0x00000948U, 0x00000948U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0x7f6d669dU), bswap_32big(0x733ffb62U), bswap_32big(0xea85ca49U),
                           bswap_32big(0xe18eb875U));
            r_rsip_func031();
            r_rsip_subfunc007(bswap_32big(0x8de0d963U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0xc86c3462U), bswap_32big(0xf92c6f9cU), bswap_32big(0x5d8993a5U),
                           bswap_32big(0x977578eaU));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 10; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18c00000U);
                r_rsip_subfunc003(0x00c00181U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc009(bswap_32big(0x00007901U));
                r_rsip_func101(bswap_32big(0xe85fb7cfU),
                               bswap_32big(0xef3ac1e6U),
                               bswap_32big(0x98a0f984U),
                               bswap_32big(0x6820a267U));
                r_rsip_func033();
                r_rsip_func101(bswap_32big(0x4299c9f5U),
                               bswap_32big(0x19c4cc63U),
                               bswap_32big(0x9eb736ddU),
                               bswap_32big(0xa315d1c8U));
            }

            r_rsip_subfunc007(bswap_32big(0x8de0d963U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007901U));
            r_rsip_func101(bswap_32big(0xcae1f607U), bswap_32big(0xb839b7cbU), bswap_32big(0xd235ae2eU),
                           bswap_32big(0xd4fa4cb3U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0x9bcbe282U), bswap_32big(0x5ab7e31fU), bswap_32big(0x26832259U),
                           bswap_32big(0xa4369a14U));
            r_rsip_func033();
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x800103e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x18c00000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);
            r_rsip_subfunc007(bswap_32big(0x9d5fee47U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0x494694e9U), bswap_32big(0x7cd9a045U), bswap_32big(0xf97df832U),
                           bswap_32big(0xa66aeab2U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 32; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18c00000U);
                r_rsip_subfunc003(0x00c00181U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc009(bswap_32big(0x00007903U));
                r_rsip_func101(bswap_32big(0xeeadac81U),
                               bswap_32big(0x2837fbcaU),
                               bswap_32big(0x807df214U),
                               bswap_32big(0xbadeb23bU));
                r_rsip_func033();
                WR1_PROG(REG_1600H, 0x3800dbffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0xf5bebcd1U),
                               bswap_32big(0xec3f6060U),
                               bswap_32big(0xbc597f76U),
                               bswap_32big(0x97ad10bcU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1404H, 0x18c00000U);
                    r_rsip_subfunc003(0x00c00181U);
                    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x30300009U);
                    r_rsip_subfunc009(bswap_32big(0x00007904U));
                    r_rsip_func101(bswap_32big(0xf5cb17f2U),
                                   bswap_32big(0x1b9cc42cU),
                                   bswap_32big(0x7466b49dU),
                                   bswap_32big(0x755c72f5U));
                    r_rsip_func033();
                    r_rsip_func101(bswap_32big(0x6283b6b5U),
                                   bswap_32big(0xbe6439d3U),
                                   bswap_32big(0x9f92aa39U),
                                   bswap_32big(0xc6cf6b56U));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xfb207ec2U),
                                   bswap_32big(0x6be2606aU),
                                   bswap_32big(0x3718bbf9U),
                                   bswap_32big(0xb6f2939dU));
                }

                WR1_PROG(REG_1600H, 0x00016fffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x681e0950U),
                               bswap_32big(0x803c5d86U),
                               bswap_32big(0xddda6f07U),
                               bswap_32big(0xa1385790U));
            }

            WR1_PROG(REG_1600H, 0x38000801U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x10a00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0017dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc009(bswap_32big(0x00007905U));
            r_rsip_func101(bswap_32big(0x39429615U), bswap_32big(0xa6dd3e99U), bswap_32big(0x5f07bc22U),
                           bswap_32big(0x87b7d69cU));
            r_rsip_func033();
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x16b80000U);
            for (iLoop = 0; iLoop < 96; iLoop = iLoop + 8)
            {
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x34202be0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d3c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c1eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x44725cabU),
                               bswap_32big(0x8142350bU),
                               bswap_32big(0x891956a3U),
                               bswap_32big(0xea3cacf7U));
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_subfunc003(0x00830021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 2]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 3]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 5]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 6]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 7]);
                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000008U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x6f20d0d8U),
                               bswap_32big(0x842cfda6U),
                               bswap_32big(0xdba6f941U),
                               bswap_32big(0x402a7f8cU));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xb90ef568U), bswap_32big(0x25ffb0faU), bswap_32big(0xd5826109U),
                           bswap_32big(0x7ba9fa64U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x4b544c84U), bswap_32big(0x5d7c9fd8U), bswap_32big(0xcb236a8dU),
                           bswap_32big(0x4bfb6984U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
