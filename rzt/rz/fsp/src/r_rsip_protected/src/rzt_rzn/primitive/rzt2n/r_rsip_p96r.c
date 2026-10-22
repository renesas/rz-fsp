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
    r_rsip_func100(bswap_32big(0x3f05dc6fU),
                   bswap_32big(0xad69814aU),
                   bswap_32big(0xe1a189d7U),
                   bswap_32big(0x66fb55cbU));
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
    r_rsip_func101(bswap_32big(0x56d1b800U),
                   bswap_32big(0x457b5d0dU),
                   bswap_32big(0xc6e4311cU),
                   bswap_32big(0x9821f1e8U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x016f84f1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00009602U));
    r_rsip_func101(bswap_32big(0x87f316adU),
                   bswap_32big(0x6dff445eU),
                   bswap_32big(0xb5831519U),
                   bswap_32big(0x8067e04dU));
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
    r_rsip_func100(bswap_32big(0xe419a15fU),
                   bswap_32big(0x970cc220U),
                   bswap_32big(0xb1462595U),
                   bswap_32big(0x7a15493fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x32f9537fU), bswap_32big(0x36d7c467U), bswap_32big(0x1a730b9dU),
                       bswap_32big(0xa77964a2U));
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
        r_rsip_func101(bswap_32big(0x8964ed8fU), bswap_32big(0xa5083900U), bswap_32big(0x37e68644U),
                       bswap_32big(0xc1738040U));

        return RSIP_RET_PASS;
    }
}
