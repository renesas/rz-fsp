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
    r_rsip_func101(bswap_32big(0xc14d5cf1U),
                   bswap_32big(0xa5ad74a9U),
                   bswap_32big(0x5abf72d8U),
                   bswap_32big(0x9c09b826U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01dd7922U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00000079U));
    r_rsip_func101(bswap_32big(0xbcc8f25fU),
                   bswap_32big(0x5bdb21b4U),
                   bswap_32big(0xdb7bb808U),
                   bswap_32big(0x44d8b9e6U));
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
    r_rsip_func100(bswap_32big(0xe0ab9acbU),
                   bswap_32big(0x69f6de11U),
                   bswap_32big(0x2da6a8e7U),
                   bswap_32big(0x9d354161U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x3c39caf3U), bswap_32big(0xc6833b3eU), bswap_32big(0xbdb04e96U),
                       bswap_32big(0x46fa9e59U));
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
        r_rsip_func100(bswap_32big(0x912b6074U), bswap_32big(0x955ec01fU), bswap_32big(0xb6e14cb4U),
                       bswap_32big(0xf33f13feU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x459f625fU), bswap_32big(0x663628d4U), bswap_32big(0x0d4e484eU),
                           bswap_32big(0xab5e977fU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x00000079U));
            r_rsip_func101(bswap_32big(0x2ded3c24U), bswap_32big(0xebf64bd8U), bswap_32big(0x8dc5a8a7U),
                           bswap_32big(0xcf89bc39U));
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
            r_rsip_func101(bswap_32big(0x268e0f38U), bswap_32big(0x6906cd7dU), bswap_32big(0xd4b0c169U),
                           bswap_32big(0x44186c77U));
            r_rsip_func031();
            r_rsip_func100(bswap_32big(0xf0645004U), bswap_32big(0xd0d3dd45U), bswap_32big(0x20b744f0U),
                           bswap_32big(0x0442abc0U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0x3e82f69bU), bswap_32big(0x9b346fcfU), bswap_32big(0xacafe79aU),
                           bswap_32big(0x95651f39U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x50b12d8eU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007901U));
            r_rsip_func101(bswap_32big(0xac82a4feU), bswap_32big(0xe9f97143U), bswap_32big(0x2074fef0U),
                           bswap_32big(0xebb349a7U));
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
            r_rsip_func101(bswap_32big(0x607218c2U), bswap_32big(0x04b26880U), bswap_32big(0x8bce1dd2U),
                           bswap_32big(0x6f4c2bcfU));
            r_rsip_func031();
            r_rsip_subfunc007(bswap_32big(0x5114ff5fU));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0xbe8102e1U), bswap_32big(0xa66bced1U), bswap_32big(0x90779694U),
                           bswap_32big(0xcf022e4dU));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 10; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18c00000U);
                r_rsip_subfunc003(0x00c00181U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc009(bswap_32big(0x00007901U));
                r_rsip_func101(bswap_32big(0x2c0ba285U),
                               bswap_32big(0xd8619bffU),
                               bswap_32big(0xa5c56fafU),
                               bswap_32big(0x3ab5f6b5U));
                r_rsip_func033();
                r_rsip_func101(bswap_32big(0x1d9c2a33U),
                               bswap_32big(0x3bd62e2bU),
                               bswap_32big(0xad421219U),
                               bswap_32big(0xd33a4ffaU));
            }

            r_rsip_subfunc007(bswap_32big(0x5114ff5fU));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007901U));
            r_rsip_func101(bswap_32big(0xdbf94935U), bswap_32big(0xb6035e67U), bswap_32big(0xf1391837U),
                           bswap_32big(0xb26d16c4U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0x5bd1dd4aU), bswap_32big(0x2f602d60U), bswap_32big(0x92338436U),
                           bswap_32big(0xbd9b3c53U));
            r_rsip_func033();
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x800103e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x18c00000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);
            r_rsip_subfunc007(bswap_32big(0x50b12d8eU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007902U));
            r_rsip_func101(bswap_32big(0x98e6dddcU), bswap_32big(0x6e748014U), bswap_32big(0xa3cad7a3U),
                           bswap_32big(0x7352ec57U));
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
                r_rsip_func101(bswap_32big(0x75c8bc08U),
                               bswap_32big(0x70b0e3c9U),
                               bswap_32big(0x20628af4U),
                               bswap_32big(0x6bf3dae0U));
                r_rsip_func033();
                WR1_PROG(REG_1600H, 0x3800dbffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0x53ad2c69U),
                               bswap_32big(0xc73f73d2U),
                               bswap_32big(0x0a4fd854U),
                               bswap_32big(0x717252e9U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1404H, 0x18c00000U);
                    r_rsip_subfunc003(0x00c00181U);
                    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x30300009U);
                    r_rsip_subfunc009(bswap_32big(0x00007904U));
                    r_rsip_func101(bswap_32big(0x036a3a97U),
                                   bswap_32big(0x83a731e9U),
                                   bswap_32big(0x81ce716dU),
                                   bswap_32big(0x51b1e194U));
                    r_rsip_func033();
                    r_rsip_func101(bswap_32big(0x488e597aU),
                                   bswap_32big(0xf283309cU),
                                   bswap_32big(0xd50a8667U),
                                   bswap_32big(0x33e4a2ddU));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xff713028U),
                                   bswap_32big(0xfe5bb8b3U),
                                   bswap_32big(0x3ad0d418U),
                                   bswap_32big(0xc37442ebU));
                }

                WR1_PROG(REG_1600H, 0x00016fffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x2117ffa1U),
                               bswap_32big(0x54085e2bU),
                               bswap_32big(0x2fd3f915U),
                               bswap_32big(0x15406afcU));
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
            r_rsip_func101(bswap_32big(0x078f0664U), bswap_32big(0x24fb3892U), bswap_32big(0xeb1230ccU),
                           bswap_32big(0x49706bc1U));
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
                r_rsip_func100(bswap_32big(0x89765be0U),
                               bswap_32big(0x0f398936U),
                               bswap_32big(0x51e44e8cU),
                               bswap_32big(0xcc20819fU));
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
                r_rsip_func101(bswap_32big(0xe90549c4U),
                               bswap_32big(0x41a9041eU),
                               bswap_32big(0x4026e2a7U),
                               bswap_32big(0x668245fdU));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x6733f3b1U), bswap_32big(0xe1653bcdU), bswap_32big(0x57c2baf9U),
                           bswap_32big(0x3fab878dU));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0xd91c13b4U), bswap_32big(0xfb29aab6U), bswap_32big(0x4af094f6U),
                           bswap_32big(0x64281709U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
