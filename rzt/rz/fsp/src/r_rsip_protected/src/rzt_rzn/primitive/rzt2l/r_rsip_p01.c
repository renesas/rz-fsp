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
    WR1_PROG(REG_1D04H, 0x00013934U);
    WR1_PROG(REG_1D08H, 0x0009d44dU);
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
        WR1_PROG(REG_1804H, 0x00008003U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        r_rsip_func101(0x4a56a51fU, 0xa58eb3dcU, 0x50414841U, 0x2349fab9U);
        WR1_PROG(REG_1804H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, 0xfc45d788U);
        WR1_PROG(REG_1420H, 0x68b9e93cU);
        WR1_PROG(REG_1420H, 0x2fb1d055U);
        WR1_PROG(REG_1420H, 0xaa18da0dU);
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        r_rsip_func101(0x3eb628a3U, 0xacd6d69aU, 0x6e5128dcU, 0xcdf62668U);
        r_rsip_func100(0x8934814fU, 0x4f0ef9f2U, 0xd64a8dbcU, 0x55a8a2cbU);
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
            WR1_PROG(REG_1420H, 0x9caef873U);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x0a040104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0xd5506fdbU);
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
            WR1_PROG(REG_1420H, 0xd479f4b0U);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x0a040104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0xc4c49e0eU);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000001f0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80840000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1B08H, 0x00000201U);
            r_rsip_func102(0xc134c5bdU, 0xafb0f898U, 0xc8504875U, 0xb8de7dadU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
