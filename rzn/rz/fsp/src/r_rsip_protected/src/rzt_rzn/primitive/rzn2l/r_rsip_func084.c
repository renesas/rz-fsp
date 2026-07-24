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

void r_rsip_func084 ()
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
    r_rsip_func100(bswap_32big(0x17b7429dU),
                   bswap_32big(0xe9b2cdf0U),
                   bswap_32big(0x88268865U),
                   bswap_32big(0x72de707dU));
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
    WR1_PROG(REG_1600H, 0x00050020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01dc5032U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0164dbd1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00070040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30003380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00070020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01127607U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0146de8bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00050040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01e60332U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x14edaebcU),
                   bswap_32big(0x46d8b28aU),
                   bswap_32big(0x2808119dU),
                   bswap_32big(0xa6172b38U));
    WR1_PROG(REG_1A24H, 0x30001084U);
    WR1_PROG(REG_1608H, 0x810103c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000004U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1404H, 0x10500000U);
    WR1_PROG(REG_1444H, 0x00002fc2U);
    WR1_PROG(REG_1A2CH, 0x00000b00U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[20]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[21]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[22]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[23]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[24]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[25]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[26]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[27]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x13700000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[28]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[29]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[30]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[31]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[32]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[33]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[34]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[35]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x18700000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[36]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[37]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[38]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[39]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[40]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[41]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[42]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[43]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[44]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[45]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[46]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[47]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[48]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[49]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[50]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[51]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x10a00000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[52]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[53]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[54]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[55]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[56]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[57]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[58]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[59]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1404H, 0x18200000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[60]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[61]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[62]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[63]);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[64]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[65]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[66]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[67]);
    r_rsip_subfunc003(0x00c20021U);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x07000d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[68]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[69]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[70]);
    WR1_ADDR(REG_1420H, &DomainParam_NIST_P256[71]);
    WR1_PROG(REG_1A24H, 0x8c100005U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
