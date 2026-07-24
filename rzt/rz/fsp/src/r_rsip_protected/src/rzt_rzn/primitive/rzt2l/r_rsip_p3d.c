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

rsip_ret_t r_rsip_p3d (uint32_t OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x003d0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    r_rsip_func100(bswap_32big(0xdb659dc7U),
                   bswap_32big(0x473d5232U),
                   bswap_32big(0x462ad707U),
                   bswap_32big(0xecf6bf46U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000003dU));
    r_rsip_func101(bswap_32big(0x2c4d8943U),
                   bswap_32big(0xf18d4ac8U),
                   bswap_32big(0x0eee5c65U),
                   bswap_32big(0x014b7ab3U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01e2fe0aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000003dU));
    r_rsip_func101(bswap_32big(0x85265ceaU),
                   bswap_32big(0xc532c432U),
                   bswap_32big(0xe555c5adU),
                   bswap_32big(0x64ff4a43U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0xe6675b80U),
                   bswap_32big(0x878ace11U),
                   bswap_32big(0x51bb3f0bU),
                   bswap_32big(0x1eead141U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80100080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func100(bswap_32big(0x4a8750f1U),
                   bswap_32big(0xbdfbe8a2U),
                   bswap_32big(0xdc8ecd1dU),
                   bswap_32big(0x27360cc7U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func100(bswap_32big(0x54ae2299U),
                   bswap_32big(0xd6d197e4U),
                   bswap_32big(0x598ab6e6U),
                   bswap_32big(0x8184c2abU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func100(bswap_32big(0x9cb8b624U),
                   bswap_32big(0x7009b567U),
                   bswap_32big(0xef96e512U),
                   bswap_32big(0x90ad075aU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func100(bswap_32big(0x1fa89f5bU),
                   bswap_32big(0x6661b196U),
                   bswap_32big(0xd79c9eefU),
                   bswap_32big(0x5b0769e7U));
    WR1_PROG(REG_1A2CH, 0x40000300U);
    WR1_PROG(REG_1A24H, 0xe7009d47U);
    WR1_PROG(REG_1608H, 0x81100080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890031U);
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
    r_rsip_subfunc003(0x00890011U);
    r_rsip_func100(bswap_32big(0xe47c2a84U),
                   bswap_32big(0x376eb2cbU),
                   bswap_32big(0x2006c52dU),
                   bswap_32big(0x5d5f43ccU));
    WR1_PROG(REG_1444H, 0x000003a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000004U));
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[20]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[21]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[22]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[23]);
    r_rsip_func100(bswap_32big(0x2bddf5a4U),
                   bswap_32big(0x256ecb6bU),
                   bswap_32big(0xb628b053U),
                   bswap_32big(0xc5e27e79U));
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
    r_rsip_func102(bswap_32big(0x6349be40U),
                   bswap_32big(0x580ae139U),
                   bswap_32big(0xe552ac88U),
                   bswap_32big(0x9b03b8edU));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
