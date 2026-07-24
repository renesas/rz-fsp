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

void r_rsip_func443 (const uint32_t ARG1[])
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
    WR1_ADDR(REG_1420H, &ARG1[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00000443U));
    r_rsip_func101(bswap_32big(0x0eb88441U),
                   bswap_32big(0x5f576a22U),
                   bswap_32big(0xfe969720U),
                   bswap_32big(0x45baf511U));
    r_rsip_func045();
    r_rsip_subfunc009(bswap_32big(0x00000443U));
    r_rsip_func101(bswap_32big(0x1edd7b25U),
                   bswap_32big(0x3cdc60f2U),
                   bswap_32big(0x47c853aeU),
                   bswap_32big(0x8491cd40U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x502fb540U),
                   bswap_32big(0xba97156cU),
                   bswap_32big(0xd0f8ebfcU),
                   bswap_32big(0xde9b3b8cU));
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[4]);
    WR1_ADDR(REG_1420H, &ARG1[5]);
    WR1_ADDR(REG_1420H, &ARG1[6]);
    WR1_ADDR(REG_1420H, &ARG1[7]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[8]);
    WR1_ADDR(REG_1420H, &ARG1[9]);
    WR1_ADDR(REG_1420H, &ARG1[10]);
    WR1_ADDR(REG_1420H, &ARG1[11]);
    WR1_PROG(REG_1824H, 0x08000085U);
    r_rsip_subfunc003(0x00420011U);
    WAIT_STS(REG_1828H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000500U);
    r_rsip_func100(bswap_32big(0xf548d9fdU),
                   bswap_32big(0x5f1571c2U),
                   bswap_32big(0xd55d4941U),
                   bswap_32big(0x7ec976a7U));
    WR1_PROG(REG_1824H, 0x08000095U);
    r_rsip_subfunc003(0x00420011U);
    WAIT_STS(REG_1828H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000500U);
    r_rsip_func100(bswap_32big(0x082899cfU),
                   bswap_32big(0x4edc5df8U),
                   bswap_32big(0xcfff0820U),
                   bswap_32big(0x821fd932U));
    WR1_PROG(REG_1444H, 0x000007c2U);
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[12]);
    WR1_ADDR(REG_1420H, &ARG1[13]);
    WR1_ADDR(REG_1420H, &ARG1[14]);
    WR1_ADDR(REG_1420H, &ARG1[15]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[16]);
    WR1_ADDR(REG_1420H, &ARG1[17]);
    WR1_ADDR(REG_1420H, &ARG1[18]);
    WR1_ADDR(REG_1420H, &ARG1[19]);
    WR1_PROG(REG_1824H, 0x080000a5U);
    r_rsip_subfunc003(0x00420011U);
    WAIT_STS(REG_1828H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000500U);
    r_rsip_func100(bswap_32big(0x779422ccU),
                   bswap_32big(0xc90e19aeU),
                   bswap_32big(0xff23a7adU),
                   bswap_32big(0x0d6297e5U));
    WR1_PROG(REG_1824H, 0x080000b5U);
    r_rsip_subfunc003(0x00420011U);
    WAIT_STS(REG_1828H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000500U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[20]);
    WR1_ADDR(REG_1420H, &ARG1[21]);
    WR1_ADDR(REG_1420H, &ARG1[22]);
    WR1_ADDR(REG_1420H, &ARG1[23]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1600H, 0x00007c1cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
