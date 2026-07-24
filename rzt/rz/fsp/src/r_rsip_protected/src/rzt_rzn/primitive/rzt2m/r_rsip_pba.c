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

rsip_ret_t r_rsip_pba (const uint32_t InData_Cmd[], const uint32_t InData_KeyIndex[], const uint32_t InData_DOTFSEED[])
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
    if (0x0U != RD1_MASK(REG_14B0H, 0x1cU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ba0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
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
    r_rsip_subfunc009(bswap_32big(0x000000baU));
    r_rsip_func101(bswap_32big(0x329969b1U),
                   bswap_32big(0xfe9f8244U),
                   bswap_32big(0x7e8f554cU),
                   bswap_32big(0xb7239018U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01352c2eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000baU));
    r_rsip_func101(bswap_32big(0x4020b6e6U),
                   bswap_32big(0xd889f237U),
                   bswap_32big(0x1adffb16U),
                   bswap_32big(0x33a58490U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xf7009d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80840001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0x5e0842a0U),
                   bswap_32big(0x040f3645U),
                   bswap_32big(0xcf71e03fU),
                   bswap_32big(0x70ddf901U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xc0396eeeU), bswap_32big(0x60c00941U), bswap_32big(0xfad3f1b4U),
                       bswap_32big(0xe6d84cd4U));
        WR1_PROG(REG_14B0H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000c00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x16f7a6e2U), bswap_32big(0x454608f7U), bswap_32big(0x01efa8b7U),
                       bswap_32big(0x060e28f1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func100(bswap_32big(0xd0dd52e2U), bswap_32big(0x0ccbbaccU), bswap_32big(0xfcf19ae0U),
                           bswap_32big(0xb0059f67U));
            WR1_PROG(REG_1438H, 0x40000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090005U);
            r_rsip_func100(bswap_32big(0x73750902U), bswap_32big(0xc14e7c7fU), bswap_32big(0xef9911d4U),
                           bswap_32big(0xae8203d0U));
            WR1_PROG(REG_1438H, 0x40000004U);
            r_rsip_subfunc003(0x02000011U);
            r_rsip_func100(bswap_32big(0x324d010fU), bswap_32big(0x21a7ae07U), bswap_32big(0x0764a4fdU),
                           bswap_32big(0xeeb3a344U));
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090011U);
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x04ae6ddaU), bswap_32big(0xe72cf78aU), bswap_32big(0x97f06b75U),
                           bswap_32big(0xdd2b5e53U));
            WR1_PROG(REG_1438H, 0x40000024U);
            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090009U);
            r_rsip_func102(bswap_32big(0x1e4f9431U), bswap_32big(0x9785dbebU), bswap_32big(0x1d4c125fU),
                           bswap_32big(0xe68ac74dU));
            WR1_PROG(REG_14B0H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xed75c78eU), bswap_32big(0x55f43ddfU), bswap_32big(0x6af0e705U),
                           bswap_32big(0x0aaac664U));
            WR1_PROG(REG_1438H, 0x40000100U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090005U);
            r_rsip_func100(bswap_32big(0xe5e100e0U), bswap_32big(0x02315f6fU), bswap_32big(0x418ea168U),
                           bswap_32big(0x8718c0f5U));
            WR1_PROG(REG_1438H, 0x40000104U);
            r_rsip_subfunc003(0x02000011U);
            r_rsip_func100(bswap_32big(0x3bc33177U), bswap_32big(0x0f39e0ebU), bswap_32big(0xe23d3453U),
                           bswap_32big(0xf0521921U));
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81840001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090011U);
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_DOTFSEED[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xca667bd0U), bswap_32big(0x17ffd2edU), bswap_32big(0x4e9ee71aU),
                           bswap_32big(0xc1f88036U));
            WR1_PROG(REG_1438H, 0x40000124U);
            WR1_PROG(REG_1608H, 0x81020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x02090009U);
            r_rsip_func102(bswap_32big(0xa9e28d8fU), bswap_32big(0x7d380409U), bswap_32big(0xcf926bd3U),
                           bswap_32big(0x5baef0a2U));
            WR1_PROG(REG_14B0H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
