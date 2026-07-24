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

rsip_ret_t r_rsip_p8b (uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x008b0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000008bU));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x8f0e417bU),
                   bswap_32big(0xfe03b501U),
                   bswap_32big(0xee68938eU),
                   bswap_32big(0xf9ef2898U));
    r_rsip_func047();
    r_rsip_func100(bswap_32big(0x1806d9deU),
                   bswap_32big(0x6c643ee0U),
                   bswap_32big(0xc9f25cf3U),
                   bswap_32big(0xa028f0aeU));
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
    r_rsip_subfunc009(bswap_32big(0x0000008bU));
    r_rsip_func101(bswap_32big(0x7e9169f3U),
                   bswap_32big(0x05a96302U),
                   bswap_32big(0x9d377aadU),
                   bswap_32big(0x76889c65U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0130c80eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000008bU));
    r_rsip_func101(bswap_32big(0xad15fe0aU),
                   bswap_32big(0x1f4e5cc9U),
                   bswap_32big(0xb75be9b0U),
                   bswap_32big(0xdf02c21dU));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x30277ee4U),
                   bswap_32big(0x7a06aab9U),
                   bswap_32big(0xb2fe84bfU),
                   bswap_32big(0x6a62630aU));
    WR1_PROG(REG_1444H, 0x00000bc1U);
    WR1_PROG(REG_182CH, 0x00000200U);
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
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[8]);
    WR1_ADDR(REG_1420H, &InData_InstData[9]);
    WR1_ADDR(REG_1420H, &InData_InstData[10]);
    WR1_ADDR(REG_1420H, &InData_InstData[11]);
    WR1_PROG(REG_1A2CH, 0x40000200U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    r_rsip_subfunc003(0x00810031U);
    WR1_PROG(REG_1408H, 0x00002032U);
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
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
    r_rsip_func100(bswap_32big(0x1598de18U),
                   bswap_32big(0x1a1ea0baU),
                   bswap_32big(0xdbf27c01U),
                   bswap_32big(0x4d3adb0fU));
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x49110054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[12]);
    WR1_ADDR(REG_1420H, &InData_InstData[13]);
    WR1_ADDR(REG_1420H, &InData_InstData[14]);
    WR1_ADDR(REG_1420H, &InData_InstData[15]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
    r_rsip_func100(bswap_32big(0xd3288a8fU),
                   bswap_32big(0x88b0c018U),
                   bswap_32big(0x63eefb0bU),
                   bswap_32big(0x189b25aaU));
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
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[16]);
    WR1_ADDR(REG_1420H, &InData_InstData[17]);
    WR1_ADDR(REG_1420H, &InData_InstData[18]);
    WR1_ADDR(REG_1420H, &InData_InstData[19]);
    r_rsip_func100(bswap_32big(0x1b32e6fdU),
                   bswap_32big(0x2236edf5U),
                   bswap_32big(0xa38323e1U),
                   bswap_32big(0x49dd6684U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x12965265U), bswap_32big(0xc44a6f4bU), bswap_32big(0x45e03e51U),
                       bswap_32big(0x2fd50156U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xf15c6d93U), bswap_32big(0x55da3864U), bswap_32big(0xe67984aaU),
                       bswap_32big(0x17d0c7a6U));
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
        r_rsip_func102(bswap_32big(0xfde04e01U), bswap_32big(0xbf8f19ffU), bswap_32big(0xe57fa799U),
                       bswap_32big(0x77b567e2U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
