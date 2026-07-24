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
    r_rsip_func101(bswap_32big(0xba9b0631U),
                   bswap_32big(0x6fd5b8e5U),
                   bswap_32big(0x32958b61U),
                   bswap_32big(0x64871c1cU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01f5023bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007aU));
    r_rsip_func101(bswap_32big(0x683e7510U),
                   bswap_32big(0x5dda6ac1U),
                   bswap_32big(0x4c876c07U),
                   bswap_32big(0xbd5fed99U));
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
    r_rsip_func100(bswap_32big(0xc4170259U),
                   bswap_32big(0x7610308dU),
                   bswap_32big(0xc8eeedaeU),
                   bswap_32big(0x87705314U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x54ad74f9U), bswap_32big(0xed5ebb09U), bswap_32big(0x97239e88U),
                       bswap_32big(0x070a3191U));
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
        r_rsip_func100(bswap_32big(0x35fd982eU), bswap_32big(0x5f6087caU), bswap_32big(0x1e100a24U),
                       bswap_32big(0x7c6d2a56U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x94839616U), bswap_32big(0x7a24a54dU), bswap_32big(0x954782dfU),
                           bswap_32big(0x25b9ed5eU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007aU));
            r_rsip_func101(bswap_32big(0xb0d7575eU), bswap_32big(0xccb7ba53U), bswap_32big(0xe25bc31dU),
                           bswap_32big(0xbe943940U));
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
            r_rsip_func101(bswap_32big(0xfe10be03U), bswap_32big(0x93cb227aU), bswap_32big(0x2001349dU),
                           bswap_32big(0xd69ed955U));
            r_rsip_func031();
            r_rsip_func100(bswap_32big(0x7f3323d8U), bswap_32big(0xcd80381aU), bswap_32big(0xd2961f88U),
                           bswap_32big(0xe9c1fb70U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0xe43307cbU), bswap_32big(0x2aff465cU), bswap_32big(0xfe15e809U),
                           bswap_32big(0x100d2770U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x50b12d8eU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0x906b52aeU), bswap_32big(0x2321ea01U), bswap_32big(0xca45824bU),
                           bswap_32big(0x1c76ae12U));
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
            r_rsip_func101(bswap_32big(0x531b42c0U), bswap_32big(0x124476e9U), bswap_32big(0x059dbf5bU),
                           bswap_32big(0xc6f0c4f5U));
            r_rsip_func031();
            r_rsip_subfunc007(bswap_32big(0x85a56606U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x24c774dbU), bswap_32big(0x57e7c4d5U), bswap_32big(0xcc904037U),
                           bswap_32big(0xd2b2d4feU));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 10; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18c00000U);
                r_rsip_subfunc003(0x00c00181U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc009(bswap_32big(0x00007a01U));
                r_rsip_func101(bswap_32big(0x50e8267aU),
                               bswap_32big(0xf3a2de23U),
                               bswap_32big(0x846d724dU),
                               bswap_32big(0xc908111bU));
                r_rsip_func033();
                r_rsip_func101(bswap_32big(0x7ae50c91U),
                               bswap_32big(0x4cc9cae8U),
                               bswap_32big(0xba91d134U),
                               bswap_32big(0x3581158dU));
            }

            r_rsip_subfunc007(bswap_32big(0x85a56606U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0xc2f8f3fcU), bswap_32big(0x937bd697U), bswap_32big(0xb18ff88fU),
                           bswap_32big(0x6b39676dU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x18efed2cU), bswap_32big(0x1889851fU), bswap_32big(0xe5e79dc9U),
                           bswap_32big(0x4887fb3aU));
            r_rsip_func033();
            r_rsip_subfunc007(bswap_32big(0x02388601U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a03U));
            r_rsip_func101(bswap_32big(0x40c3ba47U), bswap_32big(0xc246f96aU), bswap_32big(0x3c443b11U),
                           bswap_32big(0xc2116a40U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x50b12d8eU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x3ba39422U), bswap_32big(0x1c0137adU), bswap_32big(0xb632fc54U),
                           bswap_32big(0xc43ff95cU));
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
                    r_rsip_func101(bswap_32big(0x98f96c9bU),
                                   bswap_32big(0x85cd8fc9U),
                                   bswap_32big(0x7c8661e8U),
                                   bswap_32big(0x113884c4U));
                    r_rsip_func033();
                    WR1_PROG(REG_1600H, 0x3800dbffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x308f0a9cU),
                                   bswap_32big(0x19e2636eU),
                                   bswap_32big(0xb790a591U),
                                   bswap_32big(0x8dcc59f5U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc007(bswap_32big(0x02388601U));
                        OFS_ADR = 100;
                        r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a03U));
                        r_rsip_func101(bswap_32big(0xdd1b9da6U),
                                       bswap_32big(0x2d62643cU),
                                       bswap_32big(0x49259a89U),
                                       bswap_32big(0x914f530fU));
                        r_rsip_func017(OFS_ADR);
                        r_rsip_subfunc009(bswap_32big(0x00007a04U));
                        r_rsip_func101(bswap_32big(0x462aceb1U),
                                       bswap_32big(0x0845fba5U),
                                       bswap_32big(0x40ca0eb8U),
                                       bswap_32big(0xe08f3cceU));
                        r_rsip_func033();
                        r_rsip_func101(bswap_32big(0xb31d0942U),
                                       bswap_32big(0xd1a67179U),
                                       bswap_32big(0x7b0b075aU),
                                       bswap_32big(0xeead78edU));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x2efe6310U),
                                       bswap_32big(0x4c00db28U),
                                       bswap_32big(0x61daffc0U),
                                       bswap_32big(0xe5fcb4f2U));
                    }

                    WR1_PROG(REG_1600H, 0x00016fffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d80U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x986c8a42U),
                                   bswap_32big(0x17657386U),
                                   bswap_32big(0x3bbbb3adU),
                                   bswap_32big(0x1abd3c02U));
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
                r_rsip_func101(bswap_32big(0xc5450560U),
                               bswap_32big(0x0f6ad3c0U),
                               bswap_32big(0xa831e136U),
                               bswap_32big(0x83dc6903U));
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
            r_rsip_func101(bswap_32big(0xea13d4bcU), bswap_32big(0xd6a1f23bU), bswap_32big(0xb74afb59U),
                           bswap_32big(0x88489aa2U));
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
                r_rsip_func100(bswap_32big(0xd81978f7U),
                               bswap_32big(0xc1152e13U),
                               bswap_32big(0xc49a1dedU),
                               bswap_32big(0xbb698b8aU));
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
                r_rsip_func101(bswap_32big(0x36f6a0ddU),
                               bswap_32big(0xcc236561U),
                               bswap_32big(0x222df420U),
                               bswap_32big(0xe46172d9U));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x2ddb5607U), bswap_32big(0xe6d4db9bU), bswap_32big(0x75becb5eU),
                           bswap_32big(0xe91a4412U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0xc91e10bdU), bswap_32big(0x19a85039U), bswap_32big(0xa70dc6abU),
                           bswap_32big(0x72669511U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
