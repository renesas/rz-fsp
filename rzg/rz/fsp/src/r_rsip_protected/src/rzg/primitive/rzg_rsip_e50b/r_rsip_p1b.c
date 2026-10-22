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

rsip_ret_t r_rsip_p1b (const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x001b0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000001bU));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x5dd7f84fU),
                   bswap_32big(0x1fb402b3U),
                   bswap_32big(0xe9b8be6dU),
                   bswap_32big(0x391ab264U));
    r_rsip_func047();
    r_rsip_func100(bswap_32big(0x8989f568U),
                   bswap_32big(0x32a86b90U),
                   bswap_32big(0x53f8d349U),
                   bswap_32big(0xc14fa995U));
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
    r_rsip_subfunc009(bswap_32big(0x0000001bU));
    r_rsip_func101(bswap_32big(0x6a68cef7U),
                   bswap_32big(0x13ba30f4U),
                   bswap_32big(0x273e9083U),
                   bswap_32big(0xd88c6a6fU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01054129U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000001bU));
    r_rsip_func101(bswap_32big(0x1d769976U),
                   bswap_32big(0x7fc66910U),
                   bswap_32big(0x50f9ad01U),
                   bswap_32big(0x775ad732U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x680a90f8U),
                   bswap_32big(0x2e6bf7d2U),
                   bswap_32big(0x25cd4bcfU),
                   bswap_32big(0x41c9bef0U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[0]);
    WR1_ADDR(REG_1420H, &InData_InstData[1]);
    WR1_ADDR(REG_1420H, &InData_InstData[2]);
    WR1_ADDR(REG_1420H, &InData_InstData[3]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7009d05U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
    r_rsip_func100(bswap_32big(0xb983c618U),
                   bswap_32big(0xb13883c2U),
                   bswap_32big(0xc2911141U),
                   bswap_32big(0x4b10c7bdU));
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x49110054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[4]);
    WR1_ADDR(REG_1420H, &InData_InstData[5]);
    WR1_ADDR(REG_1420H, &InData_InstData[6]);
    WR1_ADDR(REG_1420H, &InData_InstData[7]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
    r_rsip_func100(bswap_32big(0x22de7f6dU),
                   bswap_32big(0x14edcf29U),
                   bswap_32big(0x49e573b0U),
                   bswap_32big(0xab00258eU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[8]);
    WR1_ADDR(REG_1420H, &InData_InstData[9]);
    WR1_ADDR(REG_1420H, &InData_InstData[10]);
    WR1_ADDR(REG_1420H, &InData_InstData[11]);
    r_rsip_func100(bswap_32big(0x6dd3d7baU),
                   bswap_32big(0x63a0363fU),
                   bswap_32big(0x95bc5162U),
                   bswap_32big(0x844020f2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7ddedabdU), bswap_32big(0x52245e19U), bswap_32big(0x2a697803U),
                       bswap_32big(0xe610f7c8U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x362e46b9U), bswap_32big(0x462e2c2eU), bswap_32big(0x3aa92090U),
                       bswap_32big(0xc0ec7d3cU));
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
        r_rsip_func102(bswap_32big(0xbfb69929U), bswap_32big(0xd4e0e75aU), bswap_32big(0x9782a898U),
                       bswap_32big(0xf9008b6fU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
