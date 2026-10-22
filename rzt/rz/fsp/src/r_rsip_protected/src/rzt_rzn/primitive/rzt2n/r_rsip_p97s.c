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
        r_rsip_func101(bswap_32big(0x7143dffbU), bswap_32big(0xf3e6e5cbU), bswap_32big(0x80877c9cU),
                       bswap_32big(0xfea40120U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xa8b49f70U), bswap_32big(0x80be63e8U), bswap_32big(0x936a46b6U),
                       bswap_32big(0x0a5d27ecU));
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
    r_rsip_func101(bswap_32big(0x82130b14U),
                   bswap_32big(0x88f69cf6U),
                   bswap_32big(0x5c0ba32bU),
                   bswap_32big(0xa9a53e40U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01e5ed93U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00009704U));
    r_rsip_func101(bswap_32big(0xbb7b7d80U),
                   bswap_32big(0xb5fd2843U),
                   bswap_32big(0xe6a3fcb9U),
                   bswap_32big(0x1c7ad406U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x95e66f7cU),
                   bswap_32big(0x42fd6ef4U),
                   bswap_32big(0x16ae128eU),
                   bswap_32big(0xdb37c385U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009104U);
    WR1_PROG(REG_1608H, 0x810100a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_State[14]);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_func100(bswap_32big(0xe88a0507U),
                   bswap_32big(0xd7fc2713U),
                   bswap_32big(0xe035d59dU),
                   bswap_32big(0x8155750bU));
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
    r_rsip_func100(bswap_32big(0xff701ebaU),
                   bswap_32big(0x55498bebU),
                   bswap_32big(0xff0a5a02U),
                   bswap_32big(0x48c3505cU));
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
    r_rsip_func102(bswap_32big(0x9d8fcc75U),
                   bswap_32big(0xa9b7bce5U),
                   bswap_32big(0xeed0ecb6U),
                   bswap_32big(0x8bfd32a2U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
