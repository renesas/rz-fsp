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

rsip_ret_t r_rsip_p2e (uint32_t const InData_CurveType[],
                       uint32_t const InData_IV[],
                       uint32_t const InData_InstData[],
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
    if (0x0U != RD1_MASK(REG_14B4H, 0x1dU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002e0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000002eU));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x8cb0559bU),
                   bswap_32big(0x63e22498U),
                   bswap_32big(0x7ad6cba7U),
                   bswap_32big(0xe0b79f97U));
    r_rsip_func047();
    r_rsip_func100(bswap_32big(0x39010084U),
                   bswap_32big(0x764224b6U),
                   bswap_32big(0x6520eab2U),
                   bswap_32big(0x22732634U));
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
    r_rsip_subfunc009(bswap_32big(0x0000002eU));
    r_rsip_func101(bswap_32big(0xdac111f2U),
                   bswap_32big(0xbc27ce92U),
                   bswap_32big(0x71bc3deaU),
                   bswap_32big(0xa898ee3cU));
    r_rsip_func045();
    r_rsip_func076();
    r_rsip_subfunc009(bswap_32big(0x0000002eU));
    r_rsip_func101(bswap_32big(0x4a6898c0U),
                   bswap_32big(0xa7507493U),
                   bswap_32big(0x6d735050U),
                   bswap_32big(0xbbd64d2aU));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x80ed5cbfU),
                   bswap_32big(0xbb5c5044U),
                   bswap_32big(0x812b2a41U),
                   bswap_32big(0x7a9fa218U));
    WR1_PROG(REG_1444H, 0x000007c1U);
    WR1_PROG(REG_182CH, 0x00000100U);
    WR1_PROG(REG_1824H, 0xd900890fU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[0]);
    WR1_ADDR(REG_1420H, &InData_InstData[1]);
    WR1_ADDR(REG_1420H, &InData_InstData[2]);
    WR1_ADDR(REG_1420H, &InData_InstData[3]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[4]);
    WR1_ADDR(REG_1420H, &InData_InstData[5]);
    WR1_ADDR(REG_1420H, &InData_InstData[6]);
    WR1_ADDR(REG_1420H, &InData_InstData[7]);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    r_rsip_subfunc003(0x00810021U);
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
    r_rsip_func100(bswap_32big(0xfd35919eU),
                   bswap_32big(0xc9fb725cU),
                   bswap_32big(0x64188748U),
                   bswap_32big(0x104f4bc3U));
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x49110054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[8]);
    WR1_ADDR(REG_1420H, &InData_InstData[9]);
    WR1_ADDR(REG_1420H, &InData_InstData[10]);
    WR1_ADDR(REG_1420H, &InData_InstData[11]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
    r_rsip_func100(bswap_32big(0x2ea8ff9fU),
                   bswap_32big(0x74e7bc66U),
                   bswap_32big(0x3cb8b539U),
                   bswap_32big(0xebc3fc48U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[12]);
    WR1_ADDR(REG_1420H, &InData_InstData[13]);
    WR1_ADDR(REG_1420H, &InData_InstData[14]);
    WR1_ADDR(REG_1420H, &InData_InstData[15]);
    r_rsip_func100(bswap_32big(0xe569b78eU),
                   bswap_32big(0x4658d13cU),
                   bswap_32big(0x1273fc84U),
                   bswap_32big(0xccafb483U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xb69cd83eU), bswap_32big(0x8d42c540U), bswap_32big(0x938cd1e0U),
                       bswap_32big(0x29c0cb3fU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x8bd6393cU), bswap_32big(0x77b5200fU), bswap_32big(0x24c53723U),
                       bswap_32big(0x822a9e19U));
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
        r_rsip_func102(bswap_32big(0xd3889ffbU), bswap_32big(0x60a4ea6fU), bswap_32big(0x8f5fcbf8U),
                       bswap_32big(0x74583edbU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
