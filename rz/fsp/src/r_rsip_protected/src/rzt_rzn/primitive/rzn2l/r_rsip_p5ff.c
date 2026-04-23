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

rsip_ret_t r_rsip_p5ff (uint32_t OutData_EncCertificateInfo[])
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
    r_rsip_func100(bswap_32big(0x524bfe32U),
                   bswap_32big(0xa76847ffU),
                   bswap_32big(0x313741f0U),
                   bswap_32big(0x0e1778fdU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00005f02U));
    r_rsip_func101(bswap_32big(0xe3afed7eU),
                   bswap_32big(0xfe295d1dU),
                   bswap_32big(0x814381c9U),
                   bswap_32big(0x55748ba4U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x018d2bd5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005f02U));
    r_rsip_func101(bswap_32big(0x10e18cc1U),
                   bswap_32big(0xcaaec0dfU),
                   bswap_32big(0xb121d063U),
                   bswap_32big(0xb52682c1U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x93a77220U),
                   bswap_32big(0x4a4b01bcU),
                   bswap_32big(0x2e46942fU),
                   bswap_32big(0x9014fac2U));
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
    r_rsip_func100(bswap_32big(0x16e1d5caU),
                   bswap_32big(0x78ec5da3U),
                   bswap_32big(0xd76152ebU),
                   bswap_32big(0x80f4d72bU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[16]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[18]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[19]);
    r_rsip_func100(bswap_32big(0xbae85c79U),
                   bswap_32big(0xb5c79f2cU),
                   bswap_32big(0x29ba7666U),
                   bswap_32big(0x9f6cb939U));
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
    r_rsip_func100(bswap_32big(0xc994f309U),
                   bswap_32big(0xec5b5eccU),
                   bswap_32big(0x42b10feeU),
                   bswap_32big(0x3981dbcfU));
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
    r_rsip_func102(bswap_32big(0x75bfa083U),
                   bswap_32big(0x7ee8e583U),
                   bswap_32big(0x1bd6e5b7U),
                   bswap_32big(0x7da4a80fU));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
