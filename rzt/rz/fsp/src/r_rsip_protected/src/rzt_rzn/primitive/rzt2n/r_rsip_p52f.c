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

rsip_ret_t r_rsip_p52f (uint32_t OutData_EncCertificateInfo[])
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
    r_rsip_func100(bswap_32big(0x052a66aaU),
                   bswap_32big(0x74a296d3U),
                   bswap_32big(0xd408c1b1U),
                   bswap_32big(0xdf23c46eU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00005202U));
    r_rsip_func101(bswap_32big(0x5b1ff342U),
                   bswap_32big(0x6705ebcfU),
                   bswap_32big(0xa8e8bc13U),
                   bswap_32big(0x72515597U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01800cb6U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005202U));
    r_rsip_func101(bswap_32big(0xb09f8831U),
                   bswap_32big(0x2a99d8c5U),
                   bswap_32big(0x334f2d80U),
                   bswap_32big(0xab913ab4U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x986b0dffU),
                   bswap_32big(0x3dde5c27U),
                   bswap_32big(0xd47a1ee1U),
                   bswap_32big(0x1781d3f5U));
    WR1_PROG(REG_1A2CH, 0x40000200U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    WR1_PROG(REG_1608H, 0x81900004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890031U);
    WR1_PROG(REG_1408H, 0x00002032U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[4]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[5]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[6]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[7]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[8]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[9]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[10]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[11]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[12]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[14]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[15]);
    r_rsip_func100(bswap_32big(0xbc045b6dU),
                   bswap_32big(0xe8b1de08U),
                   bswap_32big(0xe30fb4f4U),
                   bswap_32big(0xacbedf7cU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[16]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[18]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[19]);
    r_rsip_func100(bswap_32big(0x72147517U),
                   bswap_32big(0xfbdcafecU),
                   bswap_32big(0x25fa3ef2U),
                   bswap_32big(0xc043b5c0U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[20]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[21]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[22]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[23]);
    r_rsip_func100(bswap_32big(0xcf6cde65U),
                   bswap_32big(0xeb890d54U),
                   bswap_32big(0x007029fcU),
                   bswap_32big(0x1927474dU));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[3]);
    r_rsip_func102(bswap_32big(0x13b9dacbU),
                   bswap_32big(0x97b46bb7U),
                   bswap_32big(0xed6dde23U),
                   bswap_32big(0x12687acbU));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
