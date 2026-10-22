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

void r_rsip_func045 (void)
{
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
    r_rsip_func100(bswap_32big(0x5a749a6bU),
                   bswap_32big(0xb065e553U),
                   bswap_32big(0xe8e7f57eU),
                   bswap_32big(0xbaa22c26U));
    WR1_PROG(REG_1600H, 0x0000b540U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000001c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x8188000aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_subfunc003(0x00890011U);
    r_rsip_func100(bswap_32big(0x685b7c5eU),
                   bswap_32big(0x696c03b9U),
                   bswap_32big(0xe48fb401U),
                   bswap_32big(0x78de50cdU));
    WR1_PROG(REG_1A24H, 0x08000095U);
    r_rsip_subfunc003(0x00890011U);
    r_rsip_func100(bswap_32big(0x6b2f018bU),
                   bswap_32big(0x0a30c818U),
                   bswap_32big(0xd49f1c47U),
                   bswap_32big(0x4d611afdU));
    WR1_PROG(REG_1600H, 0x0000b540U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000001e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x8184000aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1A24H, 0x080000a5U);
    r_rsip_subfunc003(0x00890011U);
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_func100(bswap_32big(0x017f9867U),
                   bswap_32big(0x49c863e7U),
                   bswap_32big(0xb695508fU),
                   bswap_32big(0x24904a87U));
    WR1_PROG(REG_1A24H, 0x0b020105U);
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1608H, 0x80040140U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1600H, 0x00008d40U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00ffffffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00009140U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01000000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x30009105U);
    WR1_PROG(REG_1608H, 0x81040140U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000004U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x00008d40U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00ffffffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00009140U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x02000000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x30009045U);
    WR1_PROG(REG_1608H, 0x81040140U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000004U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_subfunc003(0x00820011U);
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_func100(bswap_32big(0xf5e0ee4eU),
                   bswap_32big(0xf4772808U),
                   bswap_32big(0x1946166fU),
                   bswap_32big(0xd6676e42U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000094U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
