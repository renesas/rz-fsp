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

rsip_ret_t r_rsip_p0d (uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[])
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
    if (0x0U != RD1_MASK(REG_14B4H, 0x1dU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000d0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000000dU));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x6a4fd76fU),
                   bswap_32big(0x67f5bc1fU),
                   bswap_32big(0xabd52b70U),
                   bswap_32big(0x6996edf2U));
    r_rsip_func047();
    r_rsip_func100(bswap_32big(0x88a429c0U),
                   bswap_32big(0xf91fcef9U),
                   bswap_32big(0xad6b9df0U),
                   bswap_32big(0x86040149U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x08000045U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_IV[0]);
    WR1_ADDR(REG_1420H, &InData_IV[1]);
    WR1_ADDR(REG_1420H, &InData_IV[2]);
    WR1_ADDR(REG_1420H, &InData_IV[3]);
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000000dU));
    r_rsip_func101(bswap_32big(0x8e5eeabfU),
                   bswap_32big(0xb92de0fdU),
                   bswap_32big(0xcc783053U),
                   bswap_32big(0xbbecf3cdU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0185023cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000000dU));
    r_rsip_func101(bswap_32big(0xef506fd5U),
                   bswap_32big(0x5a4c3d06U),
                   bswap_32big(0xbaa993c2U),
                   bswap_32big(0xe8dfa85eU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0xa409fcb0U), bswap_32big(0xe80ee610U), bswap_32big(0x03452885U),
                       bswap_32big(0x94855656U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 3]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x0b53247eU), bswap_32big(0xd417186cU), bswap_32big(0x5d0fda56U),
                       bswap_32big(0xa408fab2U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xaaa91756U),
                   bswap_32big(0x70692a34U),
                   bswap_32big(0x5e0ace01U),
                   bswap_32big(0x5347c50bU));
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x49110054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[64]);
    WR1_ADDR(REG_1420H, &InData_InstData[65]);
    WR1_ADDR(REG_1420H, &InData_InstData[66]);
    WR1_ADDR(REG_1420H, &InData_InstData[67]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[68]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[69]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[70]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[71]);
    r_rsip_func100(bswap_32big(0x77d8997aU),
                   bswap_32big(0x0e38958bU),
                   bswap_32big(0xdacb4b78U),
                   bswap_32big(0xb289865aU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c100104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[72]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[73]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[74]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[75]);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[68]);
    WR1_ADDR(REG_1420H, &InData_InstData[69]);
    WR1_ADDR(REG_1420H, &InData_InstData[70]);
    WR1_ADDR(REG_1420H, &InData_InstData[71]);
    r_rsip_func100(bswap_32big(0x9b9bd407U),
                   bswap_32big(0x0558fefbU),
                   bswap_32big(0x519318a9U),
                   bswap_32big(0xb509f0bcU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1022448dU), bswap_32big(0x87549100U), bswap_32big(0x83658b1dU),
                       bswap_32big(0x5cd1ba22U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xa970487dU), bswap_32big(0x59deaec4U), bswap_32big(0x8ec4c676U),
                       bswap_32big(0xda788bf9U));
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
        r_rsip_func102(bswap_32big(0xd114be35U), bswap_32big(0xa8df88ebU), bswap_32big(0x4014135dU),
                       bswap_32big(0x10ca5a5cU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
