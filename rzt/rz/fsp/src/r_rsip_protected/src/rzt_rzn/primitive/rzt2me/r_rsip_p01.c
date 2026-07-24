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
        WR1_PROG(REG_1804H, 0x00008001U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        r_rsip_func101(0x284bfd3cU, 0xd56d6c98U, 0xeae0c97fU, 0xfce3c8a5U);
        WR1_PROG(REG_1804H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000003a2U);
        WR1_PROG(REG_1A24H, 0x0a0700f5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, 0x6d831f87U);
        WR1_PROG(REG_1420H, 0x7d5a636dU);
        WR1_PROG(REG_1420H, 0x7fd2ff09U);
        WR1_PROG(REG_1420H, 0xb70f0257U);
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        r_rsip_func101(0x7594f5c7U, 0x1541908eU, 0x08378327U, 0x0dfc012dU);
        r_rsip_func100(0xd53c880dU, 0x73517348U, 0xa0238e21U, 0x838cc341U);
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
            WR1_PROG(REG_1420H, 0xdae4f8c5U);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x0a040104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0xc867a3aaU);
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
            WR1_PROG(REG_1420H, 0x39acf060U);
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            WR1_PROG(REG_1A24H, 0x0a040104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, 0x69228da3U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000001f0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80840000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1B08H, 0x00000201U);
            r_rsip_func102(0x65fa3309U, 0x051a3533U, 0xf330c3f1U, 0xdaf19d2eU);
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
