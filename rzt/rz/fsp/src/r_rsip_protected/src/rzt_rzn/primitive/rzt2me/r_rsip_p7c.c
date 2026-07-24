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
    r_rsip_func101(bswap_32big(0x1676dca2U),
                   bswap_32big(0xa18cdb07U),
                   bswap_32big(0x87eae159U),
                   bswap_32big(0x54347a38U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01b4e039U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007cU));
    r_rsip_func101(bswap_32big(0x50538a2fU),
                   bswap_32big(0x26ea8219U),
                   bswap_32big(0x06d10e42U),
                   bswap_32big(0xdfe1ed39U));
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
    r_rsip_func100(bswap_32big(0xc4edf0ceU),
                   bswap_32big(0x6d2880b5U),
                   bswap_32big(0xa6e44d0dU),
                   bswap_32big(0x1b015694U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x88a17043U), bswap_32big(0x970c8787U), bswap_32big(0x9e62e191U),
                       bswap_32big(0x23a1da8dU));
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
        r_rsip_func100(bswap_32big(0xf170f8ecU), bswap_32big(0x673ca25aU), bswap_32big(0x2ad6114bU),
                       bswap_32big(0xae9c92d7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x2f7c6d6eU), bswap_32big(0x6262e8caU), bswap_32big(0x993cd2c5U),
                           bswap_32big(0x8de9e857U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007cU));
            r_rsip_func101(bswap_32big(0x125f9b81U), bswap_32big(0x0cbb153bU), bswap_32big(0x06dec827U),
                           bswap_32big(0x08b7ed7dU));
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
            r_rsip_func101(bswap_32big(0x75fd89c9U), bswap_32big(0xe85454bdU), bswap_32big(0xc856f4f1U),
                           bswap_32big(0xc8631d70U));
            r_rsip_func032();
            r_rsip_func100(bswap_32big(0x808aa90cU), bswap_32big(0x02f72957U), bswap_32big(0x2da8a014U),
                           bswap_32big(0xc17218afU));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0xf705fea8U), bswap_32big(0x148745a1U), bswap_32big(0x40ab43afU),
                           bswap_32big(0x1516950fU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x4f742083U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0xc3176401U), bswap_32big(0x1774c8dcU), bswap_32big(0xc8df8320U),
                           bswap_32big(0xbe8b3df9U));
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
            r_rsip_func101(bswap_32big(0xa59007caU), bswap_32big(0x7158c883U), bswap_32big(0x7fa48458U),
                           bswap_32big(0x56eb04dbU));
            r_rsip_func032();
            r_rsip_subfunc007(bswap_32big(0x1e7f01feU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0x928a1fd0U), bswap_32big(0x430a9584U), bswap_32big(0xdb9e4b68U),
                           bswap_32big(0xe8542d5aU));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 12; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                r_rsip_subfunc003(0x00c00201U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                r_rsip_subfunc009(bswap_32big(0x00007c01U));
                r_rsip_func101(bswap_32big(0x20747ea4U),
                               bswap_32big(0x2d18478aU),
                               bswap_32big(0xdd4d2230U),
                               bswap_32big(0x5b3fc44eU));
                r_rsip_func034();
                r_rsip_func101(bswap_32big(0xa13e1cd6U),
                               bswap_32big(0xc4c29315U),
                               bswap_32big(0x80ee2f89U),
                               bswap_32big(0xe99c847eU));
            }

            r_rsip_subfunc007(bswap_32big(0x1e7f01feU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c01U));
            r_rsip_func101(bswap_32big(0x87fcbcc0U), bswap_32big(0x591647ecU), bswap_32big(0x133a4244U),
                           bswap_32big(0x7ae336cbU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0x7dc200f7U), bswap_32big(0xdeb344f1U), bswap_32big(0xc8d9752aU),
                           bswap_32big(0x9ed3a5f1U));
            r_rsip_func034();
            r_rsip_subfunc007(bswap_32big(0x17ce64aaU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c03U));
            r_rsip_func101(bswap_32big(0x8207ff74U), bswap_32big(0x9b4baa66U), bswap_32big(0xcae0d722U),
                           bswap_32big(0x302fb120U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x4f742083U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007c02U));
            r_rsip_func101(bswap_32big(0xc4e1f3bfU), bswap_32big(0xe7a35b12U), bswap_32big(0x4066206eU),
                           bswap_32big(0xd06d03cfU));
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
                    r_rsip_func101(bswap_32big(0x5e8c35b2U),
                                   bswap_32big(0x44b6164fU),
                                   bswap_32big(0x46c42186U),
                                   bswap_32big(0xfc06e708U));
                    r_rsip_func034();
                    WR1_PROG(REG_1600H, 0x3800dbffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0xa76ff2d2U),
                                   bswap_32big(0x29e2655bU),
                                   bswap_32big(0x9d691b0dU),
                                   bswap_32big(0xd375e524U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc007(bswap_32big(0x17ce64aaU));
                        OFS_ADR = 132;
                        r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007c03U));
                        r_rsip_func101(bswap_32big(0x7bdf2b98U),
                                       bswap_32big(0xcdea5f7dU),
                                       bswap_32big(0x73418427U),
                                       bswap_32big(0xa64207b8U));
                        r_rsip_func017(OFS_ADR);
                        r_rsip_subfunc009(bswap_32big(0x00007c04U));
                        r_rsip_func101(bswap_32big(0xe43c6674U),
                                       bswap_32big(0x24240c4fU),
                                       bswap_32big(0x4e0ff54eU),
                                       bswap_32big(0xf67ddfa3U));
                        r_rsip_func034();
                        r_rsip_func101(bswap_32big(0x810c4966U),
                                       bswap_32big(0x62199e59U),
                                       bswap_32big(0xbe454c78U),
                                       bswap_32big(0x57326b06U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xc4216e12U),
                                       bswap_32big(0x24d56a20U),
                                       bswap_32big(0x967b8a24U),
                                       bswap_32big(0xc14677acU));
                    }

                    WR1_PROG(REG_1600H, 0x00016fffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d80U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xcfa751aeU),
                                   bswap_32big(0xc81df467U),
                                   bswap_32big(0xc074e36aU),
                                   bswap_32big(0x0b32f8ccU));
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
                r_rsip_func101(bswap_32big(0x0d6da998U),
                               bswap_32big(0x62c61107U),
                               bswap_32big(0x30e47a41U),
                               bswap_32big(0x006004b1U));
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
            r_rsip_func101(bswap_32big(0x8af9e041U), bswap_32big(0x8a57dc08U), bswap_32big(0x0a3989c2U),
                           bswap_32big(0x27a838b6U));
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
                r_rsip_func100(bswap_32big(0xc22bd667U),
                               bswap_32big(0xd0fb31efU),
                               bswap_32big(0x8a1265baU),
                               bswap_32big(0x517ed060U));
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
                r_rsip_func101(bswap_32big(0x35f808d0U),
                               bswap_32big(0xf3bf4fabU),
                               bswap_32big(0x8517bfa9U),
                               bswap_32big(0x1926c9c2U));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x5bc5edc7U), bswap_32big(0x65154c77U), bswap_32big(0x3b6ae9a4U),
                           bswap_32big(0xccb9005fU));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x23b26789U), bswap_32big(0x4bc532ecU), bswap_32big(0x758cdbefU),
                           bswap_32big(0xd31bda31U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
