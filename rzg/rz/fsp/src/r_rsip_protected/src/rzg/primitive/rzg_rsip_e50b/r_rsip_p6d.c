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

rsip_ret_t r_rsip_p6d (uint32_t OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x006d0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    r_rsip_func100(bswap_32big(0xfa0ffec4U),
                   bswap_32big(0xd4c6ff60U),
                   bswap_32big(0x4332e0caU),
                   bswap_32big(0x0cc7b87aU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000006dU));
    r_rsip_func101(bswap_32big(0x055c7358U),
                   bswap_32big(0xc3a5ef53U),
                   bswap_32big(0x5ea81d0dU),
                   bswap_32big(0x7e38eef5U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01c9d4a2U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000006dU));
    r_rsip_func101(bswap_32big(0x033af5e2U),
                   bswap_32big(0x18eec1b7U),
                   bswap_32big(0x17d025f1U),
                   bswap_32big(0xada4a98aU));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x7044fd66U),
                   bswap_32big(0xac85ea81U),
                   bswap_32big(0x27d09973U),
                   bswap_32big(0xd9cb3468U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80080080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func100(bswap_32big(0xc0829861U),
                   bswap_32big(0x5c88712dU),
                   bswap_32big(0x2d2b944cU),
                   bswap_32big(0x95ddcf2eU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func100(bswap_32big(0xcd342255U),
                   bswap_32big(0x6e4abd62U),
                   bswap_32big(0x9d1fc5edU),
                   bswap_32big(0x6f38688eU));
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d47U);
    WR1_PROG(REG_1608H, 0x81050080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890015U);
    r_rsip_subfunc003(0x0080000dU);
    WR1_PROG(REG_1444H, 0x000003a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
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
    r_rsip_func100(bswap_32big(0x4a69a901U),
                   bswap_32big(0x308bca11U),
                   bswap_32big(0xcfe97ca0U),
                   bswap_32big(0x30ab42e9U));
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
    r_rsip_func102(bswap_32big(0x4f4aaa2dU),
                   bswap_32big(0x519da63fU),
                   bswap_32big(0x493f887fU),
                   bswap_32big(0x6c37d448U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
