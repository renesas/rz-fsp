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
        r_rsip_func101(bswap_32big(0xdc5a27cdU), bswap_32big(0x4fccaa90U), bswap_32big(0x1524d0ceU),
                       bswap_32big(0xc8ed7c78U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xd4b00361U), bswap_32big(0xdf0aade1U), bswap_32big(0x7ac01a58U),
                       bswap_32big(0x15c423f2U));
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
    r_rsip_func101(bswap_32big(0x3a421403U),
                   bswap_32big(0xfd706896U),
                   bswap_32big(0x82362579U),
                   bswap_32big(0x24836bd9U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01ec40d6U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00009704U));
    r_rsip_func101(bswap_32big(0xc0adae55U),
                   bswap_32big(0xceeacfbcU),
                   bswap_32big(0x05e4049bU),
                   bswap_32big(0x7d18ea6dU));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0xc2ccc51fU),
                   bswap_32big(0x7ddd002cU),
                   bswap_32big(0xb1b66765U),
                   bswap_32big(0xa25ca962U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009104U);
    WR1_PROG(REG_1608H, 0x810100a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[14]);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_func100(bswap_32big(0xc078b6b7U),
                   bswap_32big(0x09c3b288U),
                   bswap_32big(0x52b7a834U),
                   bswap_32big(0xc1753e40U));
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
    r_rsip_func100(bswap_32big(0x6e77c643U),
                   bswap_32big(0xb3c6c08dU),
                   bswap_32big(0x67b30c46U),
                   bswap_32big(0xcfb14903U));
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
    r_rsip_func102(bswap_32big(0x6aa4be83U),
                   bswap_32big(0x1117b4dbU),
                   bswap_32big(0x2bbc4dcbU),
                   bswap_32big(0x5e64d36fU));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
