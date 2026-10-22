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

rsip_ret_t r_rsip_p96r (const uint32_t InData_KeyIndex[], const uint32_t InData_Nonce[], const uint32_t InData_State[])
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

    WR1_PROG(REG_1B00H, 0x00960002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WAIT_STS(REG_1C30H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001c00U);
    r_rsip_func100(bswap_32big(0xde869eb3U),
                   bswap_32big(0x3c2f9daeU),
                   bswap_32big(0x5e13601dU),
                   bswap_32big(0x021a9083U));
    WR1_PROG(REG_1C00H, 0x00000001U);
    WR1_PROG(REG_1C04H, 0x00001001U);
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
    r_rsip_subfunc009(bswap_32big(0x00009602U));
    r_rsip_func101(bswap_32big(0x8d40c87cU),
                   bswap_32big(0x8539b580U),
                   bswap_32big(0xef33a7a2U),
                   bswap_32big(0x44bc36e4U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01d82abeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00009602U));
    r_rsip_func101(bswap_32big(0x2d2779faU),
                   bswap_32big(0x9bdeb10dU),
                   bswap_32big(0xc6174ecdU),
                   bswap_32big(0xb66552c1U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
    r_rsip_subfunc003(0x01c20021U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[12]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[13]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[14]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[15]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0x1286b250U),
                   bswap_32big(0x51dffde7U),
                   bswap_32big(0x12226103U),
                   bswap_32big(0x811a3372U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xbb4650b1U), bswap_32big(0xc4ab93feU), bswap_32big(0x1f62a508U),
                       bswap_32big(0xa618ce70U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_1C10H, &InData_State[1]);
        WR1_PROG(REG_1C04H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_1C08H, &InData_State[0]);
        WR1_PROG(REG_1C04H, 0x00000001U);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_1C0CH, &InData_Nonce[0]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_1C0CH, &InData_Nonce[1]);
        WR1_PROG(REG_1444H, 0x00000040U);
        WR1_ADDR(REG_1C0CH, &InData_Nonce[2]);
        r_rsip_func101(bswap_32big(0x9c21c9d4U), bswap_32big(0x45adb6a7U), bswap_32big(0x75916bc8U),
                       bswap_32big(0xc5ff7c22U));

        return RSIP_RET_PASS;
    }
}
