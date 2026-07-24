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

void r_rsip_func027 (const uint32_t ARG1[])
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
    r_rsip_func100(bswap_32big(0xd2144147U),
                   bswap_32big(0xab564880U),
                   bswap_32big(0x2e57a0d6U),
                   bswap_32big(0x2ccc34a5U));
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
    WR1_PROG(REG_1600H, 0x38000f5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01b622ecU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x019f647eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xd171f4d3U),
                   bswap_32big(0x38eadd18U),
                   bswap_32big(0x1c691466U),
                   bswap_32big(0x6e7e4e40U));
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
    WR1_PROG(REG_1404H, 0x10400000U);
    WR1_PROG(REG_1444H, 0x000047c2U);
    WR1_PROG(REG_1A2CH, 0x00001100U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
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
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[36]);
    WR1_ADDR(REG_1420H, &ARG1[37]);
    WR1_ADDR(REG_1420H, &ARG1[38]);
    WR1_ADDR(REG_1420H, &ARG1[39]);
    r_rsip_subfunc003(0x00c20031U);
    WR1_PROG(REG_1404H, 0x13600000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[40]);
    WR1_ADDR(REG_1420H, &ARG1[41]);
    WR1_ADDR(REG_1420H, &ARG1[42]);
    WR1_ADDR(REG_1420H, &ARG1[43]);
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
    r_rsip_subfunc003(0x00c20031U);
    WR1_PROG(REG_1404H, 0x18600000U);
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
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[60]);
    WR1_ADDR(REG_1420H, &ARG1[61]);
    WR1_ADDR(REG_1420H, &ARG1[62]);
    WR1_ADDR(REG_1420H, &ARG1[63]);
    r_rsip_subfunc003(0x00c20031U);
    WR1_PROG(REG_1404H, 0x18b00000U);
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
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[72]);
    WR1_ADDR(REG_1420H, &ARG1[73]);
    WR1_ADDR(REG_1420H, &ARG1[74]);
    WR1_ADDR(REG_1420H, &ARG1[75]);
    r_rsip_subfunc003(0x00c20031U);
    WR1_PROG(REG_1404H, 0x10900000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[76]);
    WR1_ADDR(REG_1420H, &ARG1[77]);
    WR1_ADDR(REG_1420H, &ARG1[78]);
    WR1_ADDR(REG_1420H, &ARG1[79]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[80]);
    WR1_ADDR(REG_1420H, &ARG1[81]);
    WR1_ADDR(REG_1420H, &ARG1[82]);
    WR1_ADDR(REG_1420H, &ARG1[83]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[84]);
    WR1_ADDR(REG_1420H, &ARG1[85]);
    WR1_ADDR(REG_1420H, &ARG1[86]);
    WR1_ADDR(REG_1420H, &ARG1[87]);
    r_rsip_subfunc003(0x00c20031U);
    WR1_PROG(REG_1404H, 0x18100000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[88]);
    WR1_ADDR(REG_1420H, &ARG1[89]);
    WR1_ADDR(REG_1420H, &ARG1[90]);
    WR1_ADDR(REG_1420H, &ARG1[91]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[92]);
    WR1_ADDR(REG_1420H, &ARG1[93]);
    WR1_ADDR(REG_1420H, &ARG1[94]);
    WR1_ADDR(REG_1420H, &ARG1[95]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[96]);
    WR1_ADDR(REG_1420H, &ARG1[97]);
    WR1_ADDR(REG_1420H, &ARG1[98]);
    WR1_ADDR(REG_1420H, &ARG1[99]);
    r_rsip_subfunc003(0x00c20031U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x07000d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[100]);
    WR1_ADDR(REG_1420H, &ARG1[101]);
    WR1_ADDR(REG_1420H, &ARG1[102]);
    WR1_ADDR(REG_1420H, &ARG1[103]);
    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
