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

rsip_ret_t r_rsip_p9d (uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x009d0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000009dU));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x2c66c85eU),
                   bswap_32big(0xa4fe33c8U),
                   bswap_32big(0x7a35a4a1U),
                   bswap_32big(0x197e317bU));
    r_rsip_func047();
    r_rsip_func100(bswap_32big(0x7b1aba8eU),
                   bswap_32big(0x074ad23dU),
                   bswap_32big(0xe3331a0cU),
                   bswap_32big(0x06da9cedU));
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
    r_rsip_subfunc009(bswap_32big(0x0000009dU));
    r_rsip_func101(bswap_32big(0x990aadd6U),
                   bswap_32big(0xa5e2e407U),
                   bswap_32big(0x9bca27a6U),
                   bswap_32big(0x45155cd9U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0198fae4U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000009dU));
    r_rsip_func101(bswap_32big(0xbe6b7f96U),
                   bswap_32big(0x3ecd164dU),
                   bswap_32big(0xd9b202a7U),
                   bswap_32big(0x9c16f54aU));
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
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 96; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0x05e3986fU), bswap_32big(0xf1744b2eU), bswap_32big(0x8adca7a8U),
                       bswap_32big(0xb2a95e6cU));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 3]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xf1541854U), bswap_32big(0x3f282227U), bswap_32big(0x64315c61U),
                       bswap_32big(0x3b28ee7eU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000005cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 92; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0xdc01086bU), bswap_32big(0x2cd6e022U), bswap_32big(0x7bfd3f83U),
                       bswap_32big(0x1f88424cU));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 96]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 97]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 98]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 99]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 100]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 101]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 102]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 103]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa9f1d232U), bswap_32big(0x3fa54343U), bswap_32big(0x86c10644U),
                       bswap_32big(0x7c6289dfU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x7d5bc18cU),
                   bswap_32big(0xfae28892U),
                   bswap_32big(0xf3aa4f95U),
                   bswap_32big(0x3e74ac73U));
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x49110054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[188]);
    WR1_ADDR(REG_1420H, &InData_InstData[189]);
    WR1_ADDR(REG_1420H, &InData_InstData[190]);
    WR1_ADDR(REG_1420H, &InData_InstData[191]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[192]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[193]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[194]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[195]);
    r_rsip_func100(bswap_32big(0x97885e2eU),
                   bswap_32big(0x34de2dddU),
                   bswap_32big(0x7669d894U),
                   bswap_32big(0x96246672U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[196]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[197]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[198]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[199]);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[192]);
    WR1_ADDR(REG_1420H, &InData_InstData[193]);
    WR1_ADDR(REG_1420H, &InData_InstData[194]);
    WR1_ADDR(REG_1420H, &InData_InstData[195]);
    r_rsip_func100(bswap_32big(0x56c7cd2eU),
                   bswap_32big(0xe83abd20U),
                   bswap_32big(0x5179c618U),
                   bswap_32big(0x179bfffbU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xac451acbU), bswap_32big(0x1891b5fcU), bswap_32big(0xe28a1776U),
                       bswap_32big(0xb0742d06U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xb4031322U), bswap_32big(0x7b2fe82fU), bswap_32big(0xe2341dbeU),
                       bswap_32big(0x988c111aU));
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
        r_rsip_func102(bswap_32big(0xc4dbc876U), bswap_32big(0xc0555cf4U), bswap_32big(0xf1b146a5U),
                       bswap_32big(0x5c1b11ecU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
