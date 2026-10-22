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

rsip_ret_t r_rsip_p97s (uint32_t OutData_State[])
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
    if (S_RAM[0] == 1)
    {
        r_rsip_func101(bswap_32big(0x0eb3b24fU), bswap_32big(0x875148acU), bswap_32big(0x1d85a9adU),
                       bswap_32big(0x383163c0U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x7e77add8U), bswap_32big(0xb689ad60U), bswap_32big(0x1da7686aU),
                       bswap_32big(0xd164f9a9U));
    }

    WAIT_STS(REG_1C30H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001c00U);
    RD1_ADDR(REG_1C08H, &OutData_State[0]);
    RD1_ADDR(REG_1C10H, &OutData_State[1]);
    RD1_ADDR(REG_1C14H, &OutData_State[2]);
    for (iLoop = 3; iLoop < 10; iLoop = iLoop + 1)
    {
        RD1_ADDR(REG_1C2CH, &OutData_State[iLoop]);
    }

    r_rsip_subfunc009(bswap_32big(0x00009704U));
    r_rsip_func101(bswap_32big(0x0b3228ffU),
                   bswap_32big(0xcffeafd1U),
                   bswap_32big(0x0b0b7561U),
                   bswap_32big(0x23f03ff3U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01bc6d1aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00009704U));
    r_rsip_func101(bswap_32big(0x5ed19b59U),
                   bswap_32big(0x1bb1a56fU),
                   bswap_32big(0x20ca9775U),
                   bswap_32big(0xf03c7c49U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x3d31a0eeU),
                   bswap_32big(0x7eb6ba14U),
                   bswap_32big(0xec618672U),
                   bswap_32big(0x70da93abU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009104U);
    WR1_PROG(REG_1608H, 0x810100a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[14]);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_func100(bswap_32big(0x138c35fbU),
                   bswap_32big(0x51ab81a6U),
                   bswap_32big(0xcc61ee3eU),
                   bswap_32big(0xff6ea10eU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[15]);
    RD1_ADDR(REG_1420H, &OutData_State[16]);
    RD1_ADDR(REG_1420H, &OutData_State[17]);
    RD1_ADDR(REG_1420H, &OutData_State[18]);
    r_rsip_func100(bswap_32big(0x178437a0U),
                   bswap_32big(0xccd11264U),
                   bswap_32big(0xddff8f17U),
                   bswap_32big(0xc26bcbc3U));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[10]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[11]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[12]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[13]);
    r_rsip_func102(bswap_32big(0xbf231f40U),
                   bswap_32big(0xbd093888U),
                   bswap_32big(0x9880ec28U),
                   bswap_32big(0x5a55b70dU));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
