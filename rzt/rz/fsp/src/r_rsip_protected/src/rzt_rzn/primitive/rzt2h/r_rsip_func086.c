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

void r_rsip_func086 (const uint32_t ARG1[])
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
    r_rsip_func100(bswap_32big(0x6bce6557U),
                   bswap_32big(0x42e087b5U),
                   bswap_32big(0x26298fe3U),
                   bswap_32big(0x1cbba690U));
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
    WR1_PROG(REG_1600H, 0x30003340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x011922f0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30003380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00070020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01c72842U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x012af360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00050040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x016479c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xe74a8c83U),
                   bswap_32big(0x072f28e2U),
                   bswap_32big(0x02abd569U),
                   bswap_32big(0x789253a1U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x4a000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A24H, 0x0e000484U);
    WR1_PROG(REG_1608H, 0x810103c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    WR1_PROG(REG_1404H, 0x10500000U);
    WR1_PROG(REG_1444H, 0x00002fc2U);
    WR1_PROG(REG_1A2CH, 0x00000b00U);
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
    WR1_PROG(REG_1404H, 0x13700000U);
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
    WR1_PROG(REG_1404H, 0x18700000U);
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
    WR1_PROG(REG_1404H, 0x18c00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[44]);
    WR1_ADDR(REG_1420H, &ARG1[45]);
    WR1_ADDR(REG_1420H, &ARG1[46]);
    WR1_ADDR(REG_1420H, &ARG1[47]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[48]);
    WR1_ADDR(REG_1420H, &ARG1[49]);
    WR1_ADDR(REG_1420H, &ARG1[50]);
    WR1_ADDR(REG_1420H, &ARG1[51]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x10a00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[52]);
    WR1_ADDR(REG_1420H, &ARG1[53]);
    WR1_ADDR(REG_1420H, &ARG1[54]);
    WR1_ADDR(REG_1420H, &ARG1[55]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[56]);
    WR1_ADDR(REG_1420H, &ARG1[57]);
    WR1_ADDR(REG_1420H, &ARG1[58]);
    WR1_ADDR(REG_1420H, &ARG1[59]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x18200000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[60]);
    WR1_ADDR(REG_1420H, &ARG1[61]);
    WR1_ADDR(REG_1420H, &ARG1[62]);
    WR1_ADDR(REG_1420H, &ARG1[63]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[64]);
    WR1_ADDR(REG_1420H, &ARG1[65]);
    WR1_ADDR(REG_1420H, &ARG1[66]);
    WR1_ADDR(REG_1420H, &ARG1[67]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x07000d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[68]);
    WR1_ADDR(REG_1420H, &ARG1[69]);
    WR1_ADDR(REG_1420H, &ARG1[70]);
    WR1_ADDR(REG_1420H, &ARG1[71]);
    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
