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

rsip_ret_t r_rsip_p7c (uint32_t const InData_KeyIndex[], uint32_t const InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_1B00H, 0x007c0002U);
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
    r_rsip_subfunc009(bswap_32big(0x0000007cU));
    r_rsip_func101(bswap_32big(0x4aca64a2U),
                   bswap_32big(0xea6f8718U),
                   bswap_32big(0x5bdf9303U),
                   bswap_32big(0xcac736d6U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01490ab7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007cU));
    r_rsip_func101(bswap_32big(0x767190d6U),
                   bswap_32big(0x61d2999fU),
                   bswap_32big(0x4d8e08b2U),
                   bswap_32big(0x07b3c633U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x0000ffc2U);
    WR1_PROG(REG_1A2CH, 0x40001f00U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WR1_PROG(REG_1404H, 0x14300000U);
    for (iLoop = 0; iLoop < 128; iLoop = iLoop + 8)
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

    WR1_PROG(REG_1A2CH, 0x40001f00U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);
    WR1_PROG(REG_1404H, 0x12280000U);
    for (iLoop = 128; iLoop < 256; iLoop = iLoop + 8)
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

    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[260]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[261]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[262]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[263]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0x4b805e15U),
                   bswap_32big(0x608a3d99U),
                   bswap_32big(0xe0f57875U),
                   bswap_32big(0x4d91618eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4e5a5b37U), bswap_32big(0x9bdfe4caU), bswap_32big(0x54a1b7d6U),
                       bswap_32big(0x64ce0293U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00007fd0U);
        for (iLoop = 0; iLoop < 512; iLoop = iLoop + 4)
        {
            WR1_ADDR((&(REG_0020H))[iLoop / 4], &InData_Text[(iLoop / 4) + 0]);
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
        WR1_PROG(REG_1404H, 0x18400000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c001fdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000838U, 0x4040000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        WR1_PROG(REG_1404H, 0x18400000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
        r_rsip_subfunc003(0x00c001fdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x4040000aU);
        r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000a40U, 0x4040000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xf2a318a1U), bswap_32big(0xb7b45003U), bswap_32big(0x67c14029U),
                       bswap_32big(0xec3da4bcU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xfa5b621cU), bswap_32big(0xb9a185f5U), bswap_32big(0x41ff2038U),
                           bswap_32big(0x569a1258U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007cU));
            r_rsip_func101(bswap_32big(0x45fa9f40U), bswap_32big(0xad426a82U), bswap_32big(0x5a922f07U),
                           bswap_32big(0xee80d43aU));
            r_rsip_func030();
            WR1_PROG(REG_1404H, 0x1a600000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c00005U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00109U);
            r_rsip_subfunc009(bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0x13ce696fU), bswap_32big(0x92130881U), bswap_32big(0xff760df9U),
                           bswap_32big(0x6974a224U));
            r_rsip_func032();
            r_rsip_func100(bswap_32big(0x9aa64f8eU), bswap_32big(0x37901620U), bswap_32big(0xc751af2dU),
                           bswap_32big(0xa826f813U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0xf55ac2f6U), bswap_32big(0x06cc3bf9U), bswap_32big(0x0d1840fdU),
                           bswap_32big(0x713121c2U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x8360494dU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0x53414a0cU), bswap_32big(0xbda231fdU), bswap_32big(0x7d249cf9U),
                           bswap_32big(0x6dd9920dU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1a600000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c00005U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00109U);
            r_rsip_subfunc009(bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0xcf419f00U), bswap_32big(0x179c7dddU), bswap_32big(0x7c81d078U),
                           bswap_32big(0x5035b708U));
            r_rsip_func032();
            r_rsip_subfunc007(bswap_32big(0x30908732U));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0x2be4b2fcU), bswap_32big(0x8cd68061U), bswap_32big(0x1c5069c6U),
                           bswap_32big(0x30e65d66U));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 12; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                r_rsip_subfunc003(0x00c00201U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                r_rsip_subfunc009(bswap_32big(0x00007c01U));
                r_rsip_func101(bswap_32big(0x15694b01U),
                               bswap_32big(0x2c65cadaU),
                               bswap_32big(0xfe553840U),
                               bswap_32big(0x68e7845fU));
                r_rsip_func034();
                r_rsip_func101(bswap_32big(0x61a0d7dbU),
                               bswap_32big(0x9c3fca41U),
                               bswap_32big(0x5e2516b3U),
                               bswap_32big(0x4296b304U));
            }

            r_rsip_subfunc007(bswap_32big(0x30908732U));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0x78ce738fU), bswap_32big(0xc0e5662cU), bswap_32big(0x0217cd2cU),
                           bswap_32big(0x8f772889U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0xf968157bU), bswap_32big(0x281224eaU), bswap_32big(0x29a4c209U),
                           bswap_32big(0x86adda7fU));
            r_rsip_func034();
            r_rsip_subfunc007(bswap_32big(0x6ece1339U));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c03U));
            r_rsip_func101(bswap_32big(0xc537ef17U), bswap_32big(0x1aed890dU), bswap_32big(0x6fec1fc4U),
                           bswap_32big(0xa01d4120U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x8360494dU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0xfae776b6U), bswap_32big(0xbe05c2a8U), bswap_32big(0x4a86f708U),
                           bswap_32big(0x1c165da7U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b5a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 128; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x12280000U);
                WR1_PROG(REG_1608H, 0x800103e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430005U);
                r_rsip_subfunc003(0x00030005U);
                WR1_PROG(REG_1600H, 0x0000098cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop++)
                {
                    WR1_PROG(REG_1404H, 0x18400000U);
                    r_rsip_subfunc003(0x00c00201U);
                    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                    r_rsip_subfunc009(bswap_32big(0x00007c03U));
                    r_rsip_func101(bswap_32big(0x6fddcdfbU),
                                   bswap_32big(0xd26a72d6U),
                                   bswap_32big(0x0b09b45bU),
                                   bswap_32big(0x48b57d0dU));
                    r_rsip_func034();
                    WR1_PROG(REG_1600H, 0x3800dbffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x508ab9ceU),
                                   bswap_32big(0xf6fc73a6U),
                                   bswap_32big(0x6d3e7f58U),
                                   bswap_32big(0xda1442d2U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc007(bswap_32big(0x6ece1339U));
                        OFS_ADR = 132;
                        r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c03U));
                        r_rsip_func101(bswap_32big(0x8181eb70U),
                                       bswap_32big(0x1b83e591U),
                                       bswap_32big(0x5d3555b8U),
                                       bswap_32big(0xf77be401U));
                        r_rsip_func017(OFS_ADR);
                        r_rsip_subfunc009(bswap_32big(0x00007c04U));
                        r_rsip_func101(bswap_32big(0x84126213U),
                                       bswap_32big(0xbf073954U),
                                       bswap_32big(0x5721aeccU),
                                       bswap_32big(0xe11edd3cU));
                        r_rsip_func034();
                        r_rsip_func101(bswap_32big(0x2916e564U),
                                       bswap_32big(0x3dda802bU),
                                       bswap_32big(0x901588fdU),
                                       bswap_32big(0x7c131194U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xc6163d1dU),
                                       bswap_32big(0x7b2d5729U),
                                       bswap_32big(0xa61273bdU),
                                       bswap_32big(0x1ea74b5dU));
                    }

                    WR1_PROG(REG_1600H, 0x00016fffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d80U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x9b48599aU),
                                   bswap_32big(0xaf91bc17U),
                                   bswap_32big(0x06262202U),
                                   bswap_32big(0x3bbb6ad4U));
                }

                WR1_PROG(REG_1600H, 0x3800098dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x1a380000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000a40U, 0x00000428U, 0x00000428U, 0x40400008U);
                WR1_PROG(REG_1600H, 0x00002d40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x2afcfc18U),
                               bswap_32big(0x5fc523c0U),
                               bswap_32big(0x354dc602U),
                               bswap_32big(0x0d41a9cfU));
            }

            WR1_PROG(REG_1600H, 0x3800094bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x10200000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c001fdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc009(bswap_32big(0x00007c05U));
            r_rsip_func101(bswap_32big(0xadb7fb73U), bswap_32big(0x8836b62eU), bswap_32big(0x8e8239a7U),
                           bswap_32big(0x0da70440U));
            r_rsip_func034();
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x16380000U);
            for (iLoop = 0; iLoop < 128; iLoop = iLoop + 8)
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
                r_rsip_func100(bswap_32big(0x0e838f3fU),
                               bswap_32big(0x16cd03c3U),
                               bswap_32big(0xf9d72b4dU),
                               bswap_32big(0x8e431f55U));
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
                r_rsip_func101(bswap_32big(0x8cd6a1a6U),
                               bswap_32big(0xd18c8615U),
                               bswap_32big(0x707ab164U),
                               bswap_32big(0x2e4eab4aU));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xa9cab154U), bswap_32big(0xf60eac93U), bswap_32big(0xa88dd4ceU),
                           bswap_32big(0x75de2d48U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x60683e1aU), bswap_32big(0x0eddba7dU), bswap_32big(0xd3209636U),
                           bswap_32big(0x5ce7915bU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
