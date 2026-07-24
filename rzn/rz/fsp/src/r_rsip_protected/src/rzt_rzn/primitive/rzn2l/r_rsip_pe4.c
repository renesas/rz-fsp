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

rsip_ret_t r_rsip_pe4 (const uint32_t InData_HashType[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_EncSecret[],
                       uint32_t       OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x00e40002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a880U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000009ceU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xa393df40U),
                   bswap_32big(0xcf0b0d36U),
                   bswap_32big(0x01b233ddU),
                   bswap_32big(0xd7efc0deU));
    WR1_PROG(REG_1600H, 0x00007c04U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01dec19dU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01c54b98U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7f85955eU), bswap_32big(0xfca6729dU), bswap_32big(0x23613484U),
                       bswap_32big(0x23bd533bU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x018c0d0aU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0119d8d4U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x085f54c5U), bswap_32big(0x542c723dU), bswap_32big(0x56fe8049U),
                       bswap_32big(0xa17d3ad8U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800101c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_CurveType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000dceU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x018a4a04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000014U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01d0b7b0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x013083c5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x083bd7ffU), bswap_32big(0x359696a3U), bswap_32big(0x554110a3U),
                       bswap_32big(0x397024ecU));
    }

    r_rsip_subfunc009(bswap_32big(0x000000e4U));
    r_rsip_func101(bswap_32big(0xb1f00226U),
                   bswap_32big(0x64533ab4U),
                   bswap_32big(0x96547f7cU),
                   bswap_32big(0x55ac7fe5U));
    r_rsip_func407(InData_EncSecret);
    r_rsip_func100(bswap_32big(0x32873386U),
                   bswap_32big(0xc9c2241eU),
                   bswap_32big(0x12e59727U),
                   bswap_32big(0xf41b2372U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x840ada04U), bswap_32big(0x1bff136bU), bswap_32big(0x2f52f0ecU),
                       bswap_32big(0x6ad18dc3U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38008880U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x8d1559d0U), bswap_32big(0xe3ecf943U), bswap_32big(0x69c5182eU),
                       bswap_32big(0x3a639a96U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x38000dceU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x4f2c8b31U), bswap_32big(0x6d1d7f00U), bswap_32big(0x3397e217U),
                           bswap_32big(0x174f421fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x000000b0U);
                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_2010H, 0x00000210U);
                r_rsip_func408();
                WR1_PROG(REG_1600H, 0x000008a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81910005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x01490045U);
                WAIT_STS(REG_2030H, 8U, 0U);
                WR1_PROG(REG_143CH, 0x00001600U);
                WR1_PROG(REG_1608H, 0x80900005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450041U);
                r_rsip_func101(bswap_32big(0x3006435dU),
                               bswap_32big(0x30636597U),
                               bswap_32big(0x64cc180aU),
                               bswap_32big(0x3a1a2bbdU));
            }
            else
            {
                r_rsip_func101(bswap_32big(0xf9017459U),
                               bswap_32big(0x46244486U),
                               bswap_32big(0x5d30f1b7U),
                               bswap_32big(0xffa955d3U));
            }
        }
        else
        {
            r_rsip_func100(bswap_32big(0x352657f5U), bswap_32big(0x4f34c9ccU), bswap_32big(0xdb8ee686U),
                           bswap_32big(0x2f4e498fU));
            WR1_PROG(REG_1608H, 0x81010120U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = S_RAM[0]; iLoop < 16; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1608H, 0x80840005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03400011U);
                WR1_PROG(REG_1600H, 0x0000a4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xb7f219eaU),
                               bswap_32big(0x46490aacU),
                               bswap_32big(0x10c9b734U),
                               bswap_32big(0x7ac8e386U));
            }

            WR1_PROG(REG_1600H, 0x380088e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2637aa30U), bswap_32big(0xe1ddb752U), bswap_32big(0xae391619U),
                           bswap_32big(0xea219543U));
        }

        r_rsip_func100(bswap_32big(0x4e1cecd8U), bswap_32big(0x2d0f4f62U), bswap_32big(0x2a51e6feU),
                       bswap_32big(0x3117611dU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x000000e4U));
        r_rsip_func101(bswap_32big(0x880aba61U), bswap_32big(0xdd85d0d6U), bswap_32big(0x18a398dcU),
                       bswap_32big(0x6bf6e7c2U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x000034e8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x000000e4U));
        r_rsip_func101(bswap_32big(0x576f824cU), bswap_32big(0x6fdcd732U), bswap_32big(0x34c6b042U),
                       bswap_32big(0xeed28773U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x792d1cf1U), bswap_32big(0x43a75d96U), bswap_32big(0x61d9de9cU),
                       bswap_32big(0x7095aa6aU));
        WR1_PROG(REG_1600H, 0x000008a5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1608H, 0x81900005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
        r_rsip_func100(bswap_32big(0xaec2aa1bU), bswap_32big(0x1d3baba7U), bswap_32big(0xd4b7a71dU),
                       bswap_32big(0x5e36ab2aU));
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_subfunc003(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
        r_rsip_func100(bswap_32big(0xf6b15959U), bswap_32big(0x5e11ec35U), bswap_32big(0x44cd86c3U),
                       bswap_32big(0x63708e5aU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[20]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[21]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[22]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[23]);
        r_rsip_func100(bswap_32big(0x081a2cffU), bswap_32big(0xd926de89U), bswap_32big(0xf442ee35U),
                       bswap_32big(0x32426ca7U));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[3]);
        r_rsip_func102(bswap_32big(0x3947e4a7U), bswap_32big(0x046df94eU), bswap_32big(0x04d09ce6U),
                       bswap_32big(0xc78bb77fU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
