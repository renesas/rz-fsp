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
    r_rsip_func101(bswap_32big(0x7cd296eeU),
                   bswap_32big(0xf8333364U),
                   bswap_32big(0x1f20317cU),
                   bswap_32big(0x56f0b0dcU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x016e55f2U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007cU));
    r_rsip_func101(bswap_32big(0x1c039efaU),
                   bswap_32big(0x69aeb884U),
                   bswap_32big(0x9a33fea7U),
                   bswap_32big(0xd829e8d5U));
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
    r_rsip_func100(bswap_32big(0x3a1844d3U),
                   bswap_32big(0xe6fc7b41U),
                   bswap_32big(0xfb6ed40aU),
                   bswap_32big(0x81c5af36U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xea72ec80U), bswap_32big(0x79e60ef5U), bswap_32big(0x329d2b99U),
                       bswap_32big(0xb27b5cf2U));
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
        r_rsip_func100(bswap_32big(0x95d90e70U), bswap_32big(0xeb0c05aeU), bswap_32big(0xe47b38e7U),
                       bswap_32big(0xaf49b117U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x5add359bU), bswap_32big(0xa8c38de0U), bswap_32big(0x21f9910aU),
                           bswap_32big(0xce842eeaU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007cU));
            r_rsip_func101(bswap_32big(0x53f29bbbU), bswap_32big(0xbe3b9923U), bswap_32big(0xb0d62163U),
                           bswap_32big(0x06cadda7U));
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
            r_rsip_func101(bswap_32big(0x245f475bU), bswap_32big(0x158fbc69U), bswap_32big(0x9bcd2353U),
                           bswap_32big(0x362c3678U));
            r_rsip_func032();
            r_rsip_func100(bswap_32big(0xf7f4dc06U), bswap_32big(0xe5315bfdU), bswap_32big(0x014d43c2U),
                           bswap_32big(0x4208b4a1U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0xbdb25822U), bswap_32big(0x658489e1U), bswap_32big(0x4cf06a1dU),
                           bswap_32big(0x2cd91bdaU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0xc2eb6ccfU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0x415b3b2aU), bswap_32big(0xe984ea71U), bswap_32big(0x1f9cc543U),
                           bswap_32big(0x371bcc78U));
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
            r_rsip_func101(bswap_32big(0x2cab6f81U), bswap_32big(0x86b8164fU), bswap_32big(0xec6f932aU),
                           bswap_32big(0x8421fa2bU));
            r_rsip_func032();
            r_rsip_subfunc007(bswap_32big(0x48e8de0fU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0xda2e651aU), bswap_32big(0xfd311297U), bswap_32big(0x3c1e1993U),
                           bswap_32big(0xeeacf507U));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 12; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                r_rsip_subfunc003(0x00c00201U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                r_rsip_subfunc009(bswap_32big(0x00007c01U));
                r_rsip_func101(bswap_32big(0xa8a88caeU),
                               bswap_32big(0x464ff860U),
                               bswap_32big(0x31b9f0c1U),
                               bswap_32big(0x98256443U));
                r_rsip_func034();
                r_rsip_func101(bswap_32big(0x240f69e0U),
                               bswap_32big(0x9ff58dddU),
                               bswap_32big(0x92398490U),
                               bswap_32big(0xf8677475U));
            }

            r_rsip_subfunc007(bswap_32big(0x48e8de0fU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0xdf26eb41U), bswap_32big(0x364f0ae9U), bswap_32big(0xeb82b213U),
                           bswap_32big(0x865a7a7eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0x87b381d8U), bswap_32big(0x52b1573cU), bswap_32big(0xc078bd1aU),
                           bswap_32big(0xd0a455a8U));
            r_rsip_func034();
            r_rsip_subfunc007(bswap_32big(0x43ccad4eU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c03U));
            r_rsip_func101(bswap_32big(0xa4e40075U), bswap_32big(0x83f00858U), bswap_32big(0x9867da8fU),
                           bswap_32big(0x07fcc0faU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc2eb6ccfU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0xe14dc4adU), bswap_32big(0xfca5c2a7U), bswap_32big(0x72689bb2U),
                           bswap_32big(0xc1ebc003U));
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
                    r_rsip_func101(bswap_32big(0x82f1bc52U),
                                   bswap_32big(0xf8970041U),
                                   bswap_32big(0xc916f831U),
                                   bswap_32big(0xd6ff3182U));
                    r_rsip_func034();
                    WR1_PROG(REG_1600H, 0x3800dbffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0xffad3a46U),
                                   bswap_32big(0x0fddffa0U),
                                   bswap_32big(0xc5250f19U),
                                   bswap_32big(0x9c692123U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc007(bswap_32big(0x43ccad4eU));
                        OFS_ADR = 132;
                        r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c03U));
                        r_rsip_func101(bswap_32big(0x60547046U),
                                       bswap_32big(0xac08010cU),
                                       bswap_32big(0xcb46315fU),
                                       bswap_32big(0xf71a9936U));
                        r_rsip_func017(OFS_ADR);
                        r_rsip_subfunc009(bswap_32big(0x00007c04U));
                        r_rsip_func101(bswap_32big(0x560e6f99U),
                                       bswap_32big(0x0192fe2bU),
                                       bswap_32big(0x76473a31U),
                                       bswap_32big(0x7947d068U));
                        r_rsip_func034();
                        r_rsip_func101(bswap_32big(0x75f929f2U),
                                       bswap_32big(0xf9d9dcf5U),
                                       bswap_32big(0xaf6da203U),
                                       bswap_32big(0x43e47e8fU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xb2a291cfU),
                                       bswap_32big(0xbf9b2d61U),
                                       bswap_32big(0xa3bf8ab1U),
                                       bswap_32big(0x1d5defa8U));
                    }

                    WR1_PROG(REG_1600H, 0x00016fffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d80U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x5ef2829cU),
                                   bswap_32big(0xd54fa5d6U),
                                   bswap_32big(0x3e478afaU),
                                   bswap_32big(0x9054fca2U));
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
                r_rsip_func101(bswap_32big(0x72165608U),
                               bswap_32big(0xfb7678baU),
                               bswap_32big(0x44fdd017U),
                               bswap_32big(0x4203bce5U));
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
            r_rsip_func101(bswap_32big(0xe3f2ed40U), bswap_32big(0xa4959159U), bswap_32big(0x9887a498U),
                           bswap_32big(0x59ecc207U));
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
                r_rsip_func100(bswap_32big(0x69aac7bfU),
                               bswap_32big(0xdfaafcf7U),
                               bswap_32big(0x5e7312e0U),
                               bswap_32big(0xb1596ee1U));
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
                r_rsip_func101(bswap_32big(0xccc37a0dU),
                               bswap_32big(0xc6ad5316U),
                               bswap_32big(0xe2b59b7cU),
                               bswap_32big(0xeeebd597U));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x8da9d40fU), bswap_32big(0x4dc9113fU), bswap_32big(0xef938c1fU),
                           bswap_32big(0x4306f9a2U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x4c42ff9dU), bswap_32big(0x638e764bU), bswap_32big(0x1c7f4693U),
                           bswap_32big(0xdd0e5993U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
