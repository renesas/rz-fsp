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
    r_rsip_func101(bswap_32big(0xc50b8055U),
                   bswap_32big(0xb29f6267U),
                   bswap_32big(0x82d608b2U),
                   bswap_32big(0x8657a758U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x011f1706U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007bU));
    r_rsip_func101(bswap_32big(0x7b095fc5U),
                   bswap_32big(0x5ddd3b69U),
                   bswap_32big(0x1f6abfa0U),
                   bswap_32big(0x1fc6236eU));
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
    r_rsip_func100(bswap_32big(0x6fa64aabU),
                   bswap_32big(0x898a04d5U),
                   bswap_32big(0x70edf2c3U),
                   bswap_32big(0xf7087a3eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x69f6ff47U), bswap_32big(0x40ab3d00U), bswap_32big(0xbd4b56b1U),
                       bswap_32big(0x80f6a822U));
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
        r_rsip_func100(bswap_32big(0x287152e6U), bswap_32big(0x1736fc8cU), bswap_32big(0xcb3d0130U),
                       bswap_32big(0xe61ecdbdU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xe1af2134U), bswap_32big(0xb0111beaU), bswap_32big(0x05120bb1U),
                           bswap_32big(0x39b6d3c8U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007bU));
            r_rsip_func101(bswap_32big(0xee893d11U), bswap_32big(0x4b2662adU), bswap_32big(0x8f14ef08U),
                           bswap_32big(0x7106fcb6U));
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
            r_rsip_func101(bswap_32big(0xa6caaa32U), bswap_32big(0xf0ddf9d6U), bswap_32big(0x987da559U),
                           bswap_32big(0x15bbf6b7U));
            r_rsip_func032();
            r_rsip_func100(bswap_32big(0xe2fe8a3aU), bswap_32big(0xef61f93aU), bswap_32big(0xac10cf00U),
                           bswap_32big(0xdec219c9U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0xffe52d35U), bswap_32big(0x9c66f95fU), bswap_32big(0x879aadf8U),
                           bswap_32big(0xa0e9171bU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0xc2eb6ccfU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007b01U));
            r_rsip_func101(bswap_32big(0x831711a5U), bswap_32big(0x8c2816f4U), bswap_32big(0xc91dac08U),
                           bswap_32big(0x0b773bd8U));
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
            r_rsip_func101(bswap_32big(0x461959d6U), bswap_32big(0x7dd7e1bcU), bswap_32big(0x0db0202eU),
                           bswap_32big(0x90092d08U));
            r_rsip_func032();
            r_rsip_subfunc007(bswap_32big(0x8d4eb33cU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0x063c0686U), bswap_32big(0xd6d2f8f1U), bswap_32big(0x2261f4e4U),
                           bswap_32big(0x30d1d887U));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 12; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                r_rsip_subfunc003(0x00c00201U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
                r_rsip_subfunc009(bswap_32big(0x00007b01U));
                r_rsip_func101(bswap_32big(0xe9b4fe37U),
                               bswap_32big(0x3936afe5U),
                               bswap_32big(0x3ada2869U),
                               bswap_32big(0x9cbe931eU));
                r_rsip_func034();
                r_rsip_func101(bswap_32big(0x8e6f1463U),
                               bswap_32big(0xd2535b8dU),
                               bswap_32big(0x6c42f5bbU),
                               bswap_32big(0xe3f622c6U));
            }

            r_rsip_subfunc007(bswap_32big(0x8d4eb33cU));
            OFS_ADR = 132;
            r_rsip_subfunc008(0x10200000U, 0x00000080U, bswap_32big(0x00007b01U));
            r_rsip_func101(bswap_32big(0x0cfff520U), bswap_32big(0x1c209796U), bswap_32big(0xffc04a75U),
                           bswap_32big(0x3bb1fb36U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0x2405fa95U), bswap_32big(0x5a8b119dU), bswap_32big(0x751179b2U),
                           bswap_32big(0x52f6d8d9U));
            r_rsip_func034();
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x800103e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x40400009U);
            r_rsip_subfunc007(bswap_32big(0xc2eb6ccfU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00007b02U));
            r_rsip_func101(bswap_32big(0x9740e19dU), bswap_32big(0x6fae7cd3U), bswap_32big(0x45c2fd1eU),
                           bswap_32big(0xae9c78f5U));
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
                r_rsip_func101(bswap_32big(0x4937dd6fU),
                               bswap_32big(0x4feab31aU),
                               bswap_32big(0xa18802d5U),
                               bswap_32big(0x9af0f911U));
                r_rsip_func034();
                WR1_PROG(REG_1600H, 0x3800dbffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0xbd8a7439U),
                               bswap_32big(0xdedc9406U),
                               bswap_32big(0x6d925392U),
                               bswap_32big(0xe411b4b0U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    WR1_PROG(REG_1404H, 0x18400000U);
                    r_rsip_subfunc003(0x00c00201U);
                    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x40400009U);
                    r_rsip_subfunc009(bswap_32big(0x00007b04U));
                    r_rsip_func101(bswap_32big(0xaad2e6a9U),
                                   bswap_32big(0x504bb7feU),
                                   bswap_32big(0xf339e99fU),
                                   bswap_32big(0xee3b614fU));
                    r_rsip_func034();
                    r_rsip_func101(bswap_32big(0x00a5f24bU),
                                   bswap_32big(0x1d624ae8U),
                                   bswap_32big(0x2934ef3fU),
                                   bswap_32big(0xe7515271U));
                }
                else
                {
                    r_rsip_func101(bswap_32big(0x38506839U),
                                   bswap_32big(0x25d2b35bU),
                                   bswap_32big(0xdd3a2601U),
                                   bswap_32big(0xb35ff63eU));
                }

                WR1_PROG(REG_1600H, 0x00016fffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xe48115e3U),
                               bswap_32big(0x10179dbdU),
                               bswap_32big(0x0560e192U),
                               bswap_32big(0x24b43380U));
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
            r_rsip_func101(bswap_32big(0xed351d01U), bswap_32big(0xe564d397U), bswap_32big(0x4641f4e5U),
                           bswap_32big(0x36e043ddU));
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
                r_rsip_func100(bswap_32big(0x1c0197c3U),
                               bswap_32big(0x6011c9c8U),
                               bswap_32big(0x91fa5fa5U),
                               bswap_32big(0x6e64470fU));
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
                r_rsip_func101(bswap_32big(0xebe44baaU),
                               bswap_32big(0xebf69c32U),
                               bswap_32big(0x788dab24U),
                               bswap_32big(0x8c9a5d0bU));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x7a335512U), bswap_32big(0x13a60334U), bswap_32big(0xaef372cfU),
                           bswap_32big(0xa45c440aU));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0x60d7f619U), bswap_32big(0xd74f1e3fU), bswap_32big(0xe15f6b07U),
                           bswap_32big(0x98796d42U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
