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

rsip_ret_t r_rsip_p01 (void)
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
    WR1_PROG(REG_1D04H, 0x0007ad35U);
    WR1_PROG(REG_1D08H, 0x000ba56eU);
    WR1_PROG(REG_1D00H, 0x00000001U);
    WAIT_STS(REG_1D00H, 1U, 0U);
    if (0x00000000U != RD1_MASK(REG_1D00H, 0x00030000U))
    {
        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_140CH, 0x38c60eedU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1448H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00000001U);
        WR1_PROG(REG_1414H, 0x00001401U);
        if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
        {
            return RSIP_RET_RESOURCE_CONFLICT;
        }

        WR1_PROG(REG_1800H, 0x00000001U);
        WR1_PROG(REG_1700H, 0x00000001U);
        WR1_PROG(REG_1B00H, 0x00018001U);
        WR1_PROG(REG_1B08H, 0x00000d00U);
        WR1_PROG(REG_1804H, 0x00008005U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0701e5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, 0xb7034498U);
        WR1_PROG(REG_1420H, 0xdccaac36U);
        WR1_PROG(REG_1420H, 0xfc171146U);
        WR1_PROG(REG_1420H, 0x66ca7c05U);
        WAIT_STS(REG_1A28H, 17U, 0U);
        WR1_PROG(REG_1804H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, 0xa5bce527U);
        WR1_PROG(REG_1420H, 0x12ccb49cU);
        WR1_PROG(REG_1420H, 0x2ae15c2fU);
        WR1_PROG(REG_1420H, 0xb46b09aaU);
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        WR1_PROG(REG_1A24H, 0x0a0701e5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, 0x11a076d6U);
        WR1_PROG(REG_1420H, 0xd0acff96U);
        WR1_PROG(REG_1420H, 0x602b773bU);
        WR1_PROG(REG_1420H, 0xb79b200fU);
        WAIT_STS(REG_1A28H, 17U, 0U);
        WR1_PROG(REG_1A24H, 0x0a0701f5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, 0xef0d0c06U);
        WR1_PROG(REG_1420H, 0x213efe7cU);
        WR1_PROG(REG_1420H, 0x757533d3U);
        WR1_PROG(REG_1420H, 0x9b2e2dacU);
        WAIT_STS(REG_1A28H, 16U, 0U);
        WR1_PROG(REG_1408H, 0x00020000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_142CH, 13U, 0U))
        {
            WR1_PROG(REG_14BCH, 0x00000020U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000001a2U);
            WR1_PROG(REG_1A24H, 0x0a4700c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0x61fc601cU);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x0a040104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0x0e232633U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000001e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80840000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1444H, 0x000001a2U);
            WR1_PROG(REG_1A24H, 0x0a0700c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0xe6237cf7U);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x0a040104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0x8542d022U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000001f0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80840000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1B08H, 0x00000201U);
            WR1_PROG(REG_1A24H, 0x0a0701d5U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0x87b817ddU);
            WR1_PROG(REG_1420H, 0x7ef72c37U);
            WR1_PROG(REG_1420H, 0xd3ea391aU);
            WR1_PROG(REG_1420H, 0xadeeae39U);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
