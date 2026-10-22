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
        r_rsip_func101(bswap_32big(0x19c97226U), bswap_32big(0x0e68e102U), bswap_32big(0x971e8956U),
                       bswap_32big(0x7ecea7ecU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xd34dcac9U), bswap_32big(0x6d1e9a95U), bswap_32big(0x7ca27c8bU),
                       bswap_32big(0xfdf51670U));
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
    r_rsip_func101(bswap_32big(0x195f637bU),
                   bswap_32big(0x1b3303d4U),
                   bswap_32big(0x53139815U),
                   bswap_32big(0x16bd41faU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01db5943U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00009704U));
    r_rsip_func101(bswap_32big(0xc2f54cc9U),
                   bswap_32big(0x32113aaeU),
                   bswap_32big(0xe9a04f94U),
                   bswap_32big(0x35532110U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0xfdb783a2U),
                   bswap_32big(0xe8decd24U),
                   bswap_32big(0x5625e9daU),
                   bswap_32big(0x12a752e6U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009104U);
    WR1_PROG(REG_1608H, 0x810100a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[14]);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_func100(bswap_32big(0x9abf0774U),
                   bswap_32big(0x01790d27U),
                   bswap_32big(0x584af4aeU),
                   bswap_32big(0xa5d71f76U));
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
    r_rsip_func100(bswap_32big(0xadca7aa9U),
                   bswap_32big(0x819208b5U),
                   bswap_32big(0xa7b9f737U),
                   bswap_32big(0xa8f22173U));
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
    r_rsip_func102(bswap_32big(0x6c5ba83dU),
                   bswap_32big(0xc1d1a6e8U),
                   bswap_32big(0xfb3a3dcbU),
                   bswap_32big(0x30c48561U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
