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

rsip_ret_t r_rsip_p7b (uint32_t const InData_KeyIndex[], uint32_t const InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_1B00H, 0x007b0002U);
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
    r_rsip_subfunc009(bswap_32big(0x0000007bU));
    r_rsip_func101(bswap_32big(0x800339b6U),
                   bswap_32big(0xeba57a13U),
                   bswap_32big(0x6ea8391bU),
                   bswap_32big(0xda61183bU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01026b0bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007bU));
    r_rsip_func101(bswap_32big(0xfc59a3f8U),
                   bswap_32big(0x9b01452dU),
                   bswap_32big(0xc216a538U),
                   bswap_32big(0xeda407c7U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x00007fc2U);
    WR1_PROG(REG_1A2CH, 0x40001f00U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
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

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[132]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[133]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[134]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[135]);
    WR1_PROG(REG_1404H, 0x14200000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[136]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[137]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[138]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[139]);
    r_rsip_func100(bswap_32big(0x57d52d92U),
                   bswap_32big(0xb14464f5U),
                   bswap_32big(0x7e462095U),
                   bswap_32big(0x4b20df5bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x90f11ac4U), bswap_32big(0x4cad6d67U), bswap_32big(0x8666d1d8U),
                       bswap_32big(0x9da84599U));
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
        r_rsip_func100(bswap_32big(0xeff84d3fU), bswap_32big(0x82fe76a0U), bswap_32big(0x7d46ee55U),
                       bswap_32big(0x10516f14U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x3d25ade9U), bswap_32big(0x28c13392U), bswap_32big(0x0991b097U),
                           bswap_32big(0xace7b86dU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007bU));
            r_rsip_func101(bswap_32big(0x13e9f827U), bswap_32big(0x52194548U), bswap_32big(0x6498e8dcU),
                           bswap_32big(0xcd25406aU));
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
            r_rsip_subfunc009(bswap_32big(0x00007b01U));
            r_rsip_func101(bswap_32big(0x2185fa39U), bswap_32big(0x27a4f90bU), bswap_32big(0x516ff3aeU),
                           bswap_32big(0xfc0d66d6U));
            r_rsip_func032();
            r_rsip_func100(bswap_32big(0x0118f3e6U), bswap_32big(0x2cf0a683U), bswap_32big(0x34f4f465U),
                           bswap_32big(0x6ae5f8e2U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0xf63472eaU), bswap_32big(0x4a048bdeU), bswap_32big(0xc1e21a47U),
                           bswap_32big(0xba09eb0bU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x4f742083U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007b01U));
            r_rsip_func101(bswap_32big(0xd15117fbU), bswap_32big(0xb8bcbfaeU), bswap_32big(0x5d97a341U),
                           bswap_32big(0xb6dd33dfU));
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
            r_rsip_subfunc009(bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0xdfbebb38U), bswap_32big(0x3fc25e20U), bswap_32big(0x248dd542U),
                           bswap_32big(0x4fd35ad2U));
            r_rsip_func032();
            r_rsip_subfunc007(bswap_32big(0x2b67731bU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0x00f9365eU), bswap_32big(0x460fa321U), bswap_32big(0xc461b1e3U),
                           bswap_32big(0x9918d169U));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 12; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                r_rsip_subfunc003(0x00c00201U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                r_rsip_subfunc009(bswap_32big(0x00007b01U));
                r_rsip_func101(bswap_32big(0x19c49136U),
                               bswap_32big(0xa90a2acdU),
                               bswap_32big(0x763c7c3fU),
                               bswap_32big(0x52a77e14U));
                r_rsip_func034();
                r_rsip_func101(bswap_32big(0x2483fd65U),
                               bswap_32big(0xa900838fU),
                               bswap_32big(0xd5a33a34U),
                               bswap_32big(0xf3d274b7U));
            }

            r_rsip_subfunc007(bswap_32big(0x2b67731bU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007b01U));
            r_rsip_func101(bswap_32big(0x206029eaU), bswap_32big(0x8dcd0071U), bswap_32big(0x9550641bU),
                           bswap_32big(0x24a5b107U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0xce04f595U), bswap_32big(0x2f1039eeU), bswap_32big(0x04b2de7cU),
                           bswap_32big(0x0c7e5e96U));
            r_rsip_func034();
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x800103e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x40400009U);
            r_rsip_subfunc007(bswap_32big(0x4f742083U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0xcbe8c486U), bswap_32big(0xd688010dU), bswap_32big(0x24c3d520U),
                           bswap_32big(0xa8ccaca2U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 32; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                r_rsip_subfunc003(0x00c00201U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                r_rsip_subfunc009(bswap_32big(0x00007b03U));
                r_rsip_func101(bswap_32big(0xa5b612e0U),
                               bswap_32big(0xf5373eaeU),
                               bswap_32big(0xd986be4cU),
                               bswap_32big(0x1a3fd1c4U));
                r_rsip_func034();
                WR1_PROG(REG_1600H, 0x3800dbffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0xc1433a98U),
                               bswap_32big(0x223c7334U),
                               bswap_32big(0x683c37f3U),
                               bswap_32big(0xf9f8f093U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1404H, 0x18400000U);
                    r_rsip_subfunc003(0x00c00201U);
                    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x40400009U);
                    r_rsip_subfunc009(bswap_32big(0x00007b04U));
                    r_rsip_func101(bswap_32big(0x936fafccU),
                                   bswap_32big(0xdd747748U),
                                   bswap_32big(0x5ae9b51fU),
                                   bswap_32big(0x1ce8d4b2U));
                    r_rsip_func034();
                    r_rsip_func101(bswap_32big(0xc42c8d75U),
                                   bswap_32big(0x940155c0U),
                                   bswap_32big(0x1286e764U),
                                   bswap_32big(0x99a68f21U));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x2ce4def6U),
                                   bswap_32big(0x14e3805fU),
                                   bswap_32big(0x7fca988aU),
                                   bswap_32big(0xf7dfe20cU));
                }

                WR1_PROG(REG_1600H, 0x00016fffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xeb00e607U),
                               bswap_32big(0x767c404bU),
                               bswap_32big(0xfb291414U),
                               bswap_32big(0x6b68a108U));
            }

            WR1_PROG(REG_1600H, 0x38000801U);
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
            r_rsip_subfunc009(bswap_32big(0x00007b05U));
            r_rsip_func101(bswap_32big(0x64a3643cU), bswap_32big(0x83f9afd3U), bswap_32big(0xdb93acd0U),
                           bswap_32big(0x7255a96cU));
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
                r_rsip_func100(bswap_32big(0x5e6791faU),
                               bswap_32big(0x020eef1fU),
                               bswap_32big(0xae3d1f56U),
                               bswap_32big(0x539bc961U));
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
                r_rsip_func101(bswap_32big(0x24be3a49U),
                               bswap_32big(0xdbe094dbU),
                               bswap_32big(0x73016537U),
                               bswap_32big(0x1ec1c0f2U));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x0d648970U), bswap_32big(0x33a31b11U), bswap_32big(0xaf4591eaU),
                           bswap_32big(0xfc93e794U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x9e73e0aeU), bswap_32big(0x76e34008U), bswap_32big(0xeb7f3f29U),
                           bswap_32big(0x76d1964fU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
