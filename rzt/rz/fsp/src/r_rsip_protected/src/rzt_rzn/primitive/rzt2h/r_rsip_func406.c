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

void r_rsip_func406 (const uint32_t ARG1[])
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
    r_rsip_func100(bswap_32big(0x6b8e43f0U),
                   bswap_32big(0x6b48d50eU),
                   bswap_32big(0x3b2a8490U),
                   bswap_32big(0xe1a0694aU));
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000001f0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x8184001eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1A24H, 0x08000085U);
    r_rsip_subfunc003(0x00890011U);
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_func100(bswap_32big(0x60004e04U),
                   bswap_32big(0x68a7e47dU),
                   bswap_32big(0x9a116bb6U),
                   bswap_32big(0x1ba0cb99U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x4a000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0e000484U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x01a3568bU));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    WR1_PROG(REG_1404H, 0x10500000U);
    WR1_PROG(REG_1444H, 0x000033c2U);
    WR1_PROG(REG_1A2CH, 0x00000c00U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[20]);
    WR1_ADDR(REG_1420H, &ARG1[21]);
    WR1_ADDR(REG_1420H, &ARG1[22]);
    WR1_ADDR(REG_1420H, &ARG1[23]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[24]);
    WR1_ADDR(REG_1420H, &ARG1[25]);
    WR1_ADDR(REG_1420H, &ARG1[26]);
    WR1_ADDR(REG_1420H, &ARG1[27]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x10a00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[28]);
    WR1_ADDR(REG_1420H, &ARG1[29]);
    WR1_ADDR(REG_1420H, &ARG1[30]);
    WR1_ADDR(REG_1420H, &ARG1[31]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[32]);
    WR1_ADDR(REG_1420H, &ARG1[33]);
    WR1_ADDR(REG_1420H, &ARG1[34]);
    WR1_ADDR(REG_1420H, &ARG1[35]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x11e00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[36]);
    WR1_ADDR(REG_1420H, &ARG1[37]);
    WR1_ADDR(REG_1420H, &ARG1[38]);
    WR1_ADDR(REG_1420H, &ARG1[39]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[40]);
    WR1_ADDR(REG_1420H, &ARG1[41]);
    WR1_ADDR(REG_1420H, &ARG1[42]);
    WR1_ADDR(REG_1420H, &ARG1[43]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x10000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[44]);
    WR1_ADDR(REG_1420H, &ARG1[45]);
    WR1_ADDR(REG_1420H, &ARG1[46]);
    WR1_ADDR(REG_1420H, &ARG1[47]);
    r_rsip_subfunc003(0x00c20011U);
    WR1_PROG(REG_1404H, 0x11900000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[48]);
    WR1_ADDR(REG_1420H, &ARG1[49]);
    WR1_ADDR(REG_1420H, &ARG1[50]);
    WR1_ADDR(REG_1420H, &ARG1[51]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[52]);
    WR1_ADDR(REG_1420H, &ARG1[53]);
    WR1_ADDR(REG_1420H, &ARG1[54]);
    WR1_ADDR(REG_1420H, &ARG1[55]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x10f00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[56]);
    WR1_ADDR(REG_1420H, &ARG1[57]);
    WR1_ADDR(REG_1420H, &ARG1[58]);
    WR1_ADDR(REG_1420H, &ARG1[59]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[60]);
    WR1_ADDR(REG_1420H, &ARG1[61]);
    WR1_ADDR(REG_1420H, &ARG1[62]);
    WR1_ADDR(REG_1420H, &ARG1[63]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x11400000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[64]);
    WR1_ADDR(REG_1420H, &ARG1[65]);
    WR1_ADDR(REG_1420H, &ARG1[66]);
    WR1_ADDR(REG_1420H, &ARG1[67]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[68]);
    WR1_ADDR(REG_1420H, &ARG1[69]);
    WR1_ADDR(REG_1420H, &ARG1[70]);
    WR1_ADDR(REG_1420H, &ARG1[71]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x07000d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[72]);
    WR1_ADDR(REG_1420H, &ARG1[73]);
    WR1_ADDR(REG_1420H, &ARG1[74]);
    WR1_ADDR(REG_1420H, &ARG1[75]);
    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1404H, 0x1af00000U);
    r_rsip_subfunc003(0x00c00021U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
