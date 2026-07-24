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

void r_rsip_func047 (void)
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
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000f047U));
    r_rsip_func101(bswap_32big(0x4b58af82U),
                   bswap_32big(0xa344ecbdU),
                   bswap_32big(0x99531856U),
                   bswap_32big(0x11f3e1fcU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x011389bfU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000f047U));
    r_rsip_func101(bswap_32big(0x9acfa766U),
                   bswap_32big(0x6694c0afU),
                   bswap_32big(0x8bc63a9eU),
                   bswap_32big(0xf4162c54U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0xd872aff0U),
                   bswap_32big(0x505706e8U),
                   bswap_32big(0xf107fb82U),
                   bswap_32big(0xccea9f45U));
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[4]);
    WR1_ADDR(REG_1420H, &S_INST2[5]);
    WR1_ADDR(REG_1420H, &S_INST2[6]);
    WR1_ADDR(REG_1420H, &S_INST2[7]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[8]);
    WR1_ADDR(REG_1420H, &S_INST2[9]);
    WR1_ADDR(REG_1420H, &S_INST2[10]);
    WR1_ADDR(REG_1420H, &S_INST2[11]);
    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_subfunc003(0x00420011U);
    WAIT_STS(REG_1828H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000500U);
    r_rsip_func100(bswap_32big(0x65d669f2U),
                   bswap_32big(0xcb18cfedU),
                   bswap_32big(0xe7ea4b3cU),
                   bswap_32big(0x91cf13c6U));
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_subfunc003(0x00420011U);
    WAIT_STS(REG_1828H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000500U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &S_INST2[12]);
    WR1_ADDR(REG_1420H, &S_INST2[13]);
    WR1_ADDR(REG_1420H, &S_INST2[14]);
    WR1_ADDR(REG_1420H, &S_INST2[15]);
    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1600H, 0x00007c1cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
