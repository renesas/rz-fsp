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

void r_rsip_func078 (const uint32_t ARG1[])
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
    r_rsip_func100(bswap_32big(0x41deed86U),
                   bswap_32big(0x48fa831dU),
                   bswap_32big(0x53459b14U),
                   bswap_32big(0x232f88f4U));
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
    r_rsip_func100(bswap_32big(0xf7cfa93aU),
                   bswap_32big(0xf589eb5cU),
                   bswap_32big(0x51712d8dU),
                   bswap_32big(0x96f73593U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x4a000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0e000484U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0183d1afU));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    WR1_PROG(REG_1444H, 0x00005fc2U);
    WR1_PROG(REG_1A2CH, 0x00001700U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WR1_PROG(REG_1404H, 0x10300000U);
    for (iLoop = 36; iLoop < 52; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 5]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 6]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 7]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1404H, 0x13500000U);
    for (iLoop = 52; iLoop < 68; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 5]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 6]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 7]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1404H, 0x18500000U);
    for (iLoop = 68; iLoop < 84; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 5]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 6]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 7]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1404H, 0x18a00000U);
    for (iLoop = 84; iLoop < 100; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 5]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 6]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 7]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1404H, 0x10800000U);
    for (iLoop = 100; iLoop < 116; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 5]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 6]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 7]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1404H, 0x18000000U);
    for (iLoop = 116; iLoop < 132; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 4]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 5]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 6]);
        WR1_ADDR(REG_1420H, &ARG1[iLoop + 7]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x07000d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[132]);
    WR1_ADDR(REG_1420H, &ARG1[133]);
    WR1_ADDR(REG_1420H, &ARG1[134]);
    WR1_ADDR(REG_1420H, &ARG1[135]);
    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
