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

rsip_ret_t r_rsip_p7a (uint32_t const InData_KeyIndex[], uint32_t const InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_1B00H, 0x007a0002U);
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
    r_rsip_subfunc009(bswap_32big(0x0000007aU));
    r_rsip_func101(bswap_32big(0x3bf253a0U),
                   bswap_32big(0xd1d01208U),
                   bswap_32big(0xcd9d5065U),
                   bswap_32big(0xdc400348U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0173ba21U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007aU));
    r_rsip_func101(bswap_32big(0x4b6a32baU),
                   bswap_32big(0x4ce52947U),
                   bswap_32big(0xa80b8326U),
                   bswap_32big(0xd0b0490fU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x0000bfc2U);
    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
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

    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);
    WR1_PROG(REG_1404H, 0x12a80000U);
    for (iLoop = 96; iLoop < 192; iLoop = iLoop + 8)
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
    WR1_ADDR(REG_1420H, &InData_KeyIndex[196]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[197]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[198]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[199]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0xa97bac5bU),
                   bswap_32big(0xb19ec320U),
                   bswap_32big(0xb0d6f019U),
                   bswap_32big(0x9d66b7ccU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x93cd1ed3U), bswap_32big(0x06257fe6U), bswap_32big(0x375d10d6U),
                       bswap_32big(0x55cf53f4U));
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
        r_rsip_func100(bswap_32big(0xc3b820eeU), bswap_32big(0x4fbcfc82U), bswap_32big(0xf7d66225U),
                       bswap_32big(0x8d5a1637U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x88235793U), bswap_32big(0xd01e3ddbU), bswap_32big(0x432b516dU),
                           bswap_32big(0xae361d51U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007aU));
            r_rsip_func101(bswap_32big(0xf7dd3946U), bswap_32big(0xe46cf890U), bswap_32big(0x85ecbb0eU),
                           bswap_32big(0xc93acad3U));
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
            r_rsip_subfunc009(bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0xd758bab3U), bswap_32big(0x36f992faU), bswap_32big(0x05f0ccb7U),
                           bswap_32big(0x8551a0d1U));
            r_rsip_func031();
            r_rsip_func100(bswap_32big(0xe641e6afU), bswap_32big(0x34378c5eU), bswap_32big(0x65128ba0U),
                           bswap_32big(0x02b52e5dU));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0x300873aaU), bswap_32big(0x7d0c405dU), bswap_32big(0x7b0c1830U),
                           bswap_32big(0xc8ce6375U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0xd1909ef0U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0xc36527fdU), bswap_32big(0xf2666cbaU), bswap_32big(0x70ed084fU),
                           bswap_32big(0x22b61483U));
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
            r_rsip_subfunc009(bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x685bd43dU), bswap_32big(0xd57d525cU), bswap_32big(0xc880af75U),
                           bswap_32big(0xd98e4d6eU));
            r_rsip_func031();
            r_rsip_subfunc007(bswap_32big(0x362980f4U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0xccfad063U), bswap_32big(0x09590846U), bswap_32big(0x97c6451eU),
                           bswap_32big(0x1a0a4781U));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 10; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18c00000U);
                r_rsip_subfunc003(0x00c00181U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc009(bswap_32big(0x00007a01U));
                r_rsip_func101(bswap_32big(0xffd9c44eU),
                               bswap_32big(0xd8b64d75U),
                               bswap_32big(0xd8f1b9acU),
                               bswap_32big(0xb776e255U));
                r_rsip_func033();
                r_rsip_func101(bswap_32big(0x10252f09U),
                               bswap_32big(0x5f895052U),
                               bswap_32big(0x98c4ac17U),
                               bswap_32big(0x83d39d8cU));
            }

            r_rsip_subfunc007(bswap_32big(0x362980f4U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0x7455a5a9U), bswap_32big(0x8aa46859U), bswap_32big(0x7e8762ebU),
                           bswap_32big(0xc3138d16U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x4ca2fb8dU), bswap_32big(0x70fe602cU), bswap_32big(0x72b6fa49U),
                           bswap_32big(0x1222a963U));
            r_rsip_func033();
            r_rsip_subfunc007(bswap_32big(0x5a522c31U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a03U));
            r_rsip_func101(bswap_32big(0x501970e1U), bswap_32big(0xd3de7b4aU), bswap_32big(0xc5e099c8U),
                           bswap_32big(0x6c8a6154U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd1909ef0U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x3c2a0721U), bswap_32big(0x2a366619U), bswap_32big(0xbc81d637U),
                           bswap_32big(0xc90d8017U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b5a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 96; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x12a80000U);
                WR1_PROG(REG_1608H, 0x800103e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430005U);
                r_rsip_subfunc003(0x00030005U);
                WR1_PROG(REG_1600H, 0x0000098cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop++)
                {
                    WR1_PROG(REG_1404H, 0x18c00000U);
                    r_rsip_subfunc003(0x00c00181U);
                    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                    r_rsip_subfunc009(bswap_32big(0x00007a03U));
                    r_rsip_func101(bswap_32big(0x2e3b4da6U),
                                   bswap_32big(0x36fc1bf7U),
                                   bswap_32big(0xd745ab48U),
                                   bswap_32big(0x62cd2d56U));
                    r_rsip_func033();
                    WR1_PROG(REG_1600H, 0x3800dbffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x9c97fdd7U),
                                   bswap_32big(0x05250f14U),
                                   bswap_32big(0xcd8322c9U),
                                   bswap_32big(0x621bbeeaU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc007(bswap_32big(0x5a522c31U));
                        OFS_ADR = 100;
                        r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a03U));
                        r_rsip_func101(bswap_32big(0xc3718252U),
                                       bswap_32big(0x92889279U),
                                       bswap_32big(0xebc3c63fU),
                                       bswap_32big(0x049b73b2U));
                        r_rsip_func017(OFS_ADR);
                        r_rsip_subfunc009(bswap_32big(0x00007a04U));
                        r_rsip_func101(bswap_32big(0xf6e03777U),
                                       bswap_32big(0xe4af784fU),
                                       bswap_32big(0xa69d1653U),
                                       bswap_32big(0x9569113aU));
                        r_rsip_func033();
                        r_rsip_func101(bswap_32big(0x49740c0cU),
                                       bswap_32big(0x0518ba67U),
                                       bswap_32big(0x61246ff2U),
                                       bswap_32big(0x0d6b9025U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xb91222cfU),
                                       bswap_32big(0x379ae645U),
                                       bswap_32big(0x7f8d168eU),
                                       bswap_32big(0xb38fb862U));
                    }

                    WR1_PROG(REG_1600H, 0x00016fffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d80U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xc50f1824U),
                                   bswap_32big(0xb2695bedU),
                                   bswap_32big(0x67ed6ecbU),
                                   bswap_32big(0x803d9774U));
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
                r_rsip_subfunc001(0x00000a40U, 0x00000428U, 0x00000428U, 0x30300008U);
                WR1_PROG(REG_1600H, 0x00002d40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x6fef4230U),
                               bswap_32big(0x7d6ad7ffU),
                               bswap_32big(0x2bfaed08U),
                               bswap_32big(0x23cc0649U));
            }

            WR1_PROG(REG_1600H, 0x3800094bU);
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
            r_rsip_subfunc009(bswap_32big(0x00007a05U));
            r_rsip_func101(bswap_32big(0x7c6b6402U), bswap_32big(0x4b1d9f8cU), bswap_32big(0xffd0c23cU),
                           bswap_32big(0xc7dea728U));
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
                r_rsip_func100(bswap_32big(0x7a327a3dU),
                               bswap_32big(0x1736706dU),
                               bswap_32big(0xe15d99e0U),
                               bswap_32big(0x66023914U));
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
                r_rsip_func101(bswap_32big(0x912fb0faU),
                               bswap_32big(0xbd695040U),
                               bswap_32big(0x30a6505eU),
                               bswap_32big(0xbcfff80dU));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xadfb2d42U), bswap_32big(0x5a18870aU), bswap_32big(0xf3169782U),
                           bswap_32big(0xe10ad935U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x67efbb98U), bswap_32big(0x343f18fdU), bswap_32big(0xa1108af8U),
                           bswap_32big(0x9ce4d4d2U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
