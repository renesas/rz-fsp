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

rsip_ret_t r_rsip_p58r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[],
                        uint32_t       KEY_INDEX_SIZE)
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00580002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_2400H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x5a5038e3U),
                   bswap_32big(0xca10432bU),
                   bswap_32big(0x08dedba3U),
                   bswap_32big(0xd1927234U));
    WR1_PROG(REG_1600H, 0x3420a880U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c04U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x018bcbb3U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_2404H, 0x00001001U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000024U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xe208034dU), bswap_32big(0x70895418U), bswap_32big(0x052a83adU),
                       bswap_32big(0x88fd6a3cU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01a67068U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_2404H, 0x00001011U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000022U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x6eeed509U), bswap_32big(0x6792961dU), bswap_32big(0x2166a351U),
                       bswap_32big(0x862b974cU));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01b60df9U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_2404H, 0x00001021U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001aU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xfdfd5520U), bswap_32big(0x0ec6ad09U), bswap_32big(0x2b2da7b7U),
                       bswap_32big(0x678ce0e0U));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01353db9U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_2404H, 0x00001031U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000012U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x53bda837U), bswap_32big(0x20e963aeU), bswap_32big(0x46802323U),
                       bswap_32big(0x8896a4d5U));
    }

    WR1_PROG(REG_2408H, 0x00000003U);
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
    r_rsip_subfunc009(bswap_32big(0x00005802U));
    r_rsip_func101(bswap_32big(0xf91c66b1U),
                   bswap_32big(0x37719769U),
                   bswap_32big(0xe14d0198U),
                   bswap_32big(0x59af8cb9U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x000034e5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005802U));
    r_rsip_func101(bswap_32big(0x4747c9baU),
                   bswap_32big(0xa20998c5U),
                   bswap_32big(0x14362cbdU),
                   bswap_32big(0x5cf5f5ecU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < KEY_INDEX_SIZE - 8; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xf7008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        r_rsip_subfunc003(0x01820011U);
        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x2d0b9810U), bswap_32big(0x3ff12bd4U), bswap_32big(0x4e83481cU),
                       bswap_32big(0x763935d5U));
    }

    WR1_PROG(REG_1600H, 0x380008e6U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0xb8ce9674U),
                   bswap_32big(0x6cb65bdcU),
                   bswap_32big(0x4bc68115U),
                   bswap_32big(0x88eaf612U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x248e6e4fU), bswap_32big(0xc5e1c68fU), bswap_32big(0x561da7d3U),
                       bswap_32big(0x1efd579aU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x5264967bU), bswap_32big(0x7e73a5f7U), bswap_32big(0xdbe12dc4U),
                       bswap_32big(0x975e0131U));
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2414H, &InData_State[50]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_2410H, &InData_State[51]);
        for (iLoop = 0; iLoop < 50; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2438H, &InData_State[iLoop + 0]);
        }

        WR1_PROG(REG_1608H, 0x81010100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        r_rsip_func101(bswap_32big(0x3f33a068U), bswap_32big(0xd265b628U), bswap_32big(0xcc3f82b5U),
                       bswap_32big(0xfed2cf50U));

        return RSIP_RET_PASS;
    }
}
