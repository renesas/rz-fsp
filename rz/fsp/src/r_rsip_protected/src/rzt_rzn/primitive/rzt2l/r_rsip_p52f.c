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
    r_rsip_func100(bswap_32big(0xa49597efU),
                   bswap_32big(0xe30c5833U),
                   bswap_32big(0x4c5a97abU),
                   bswap_32big(0x5e39df22U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00005202U));
    r_rsip_func101(bswap_32big(0xb745833fU),
                   bswap_32big(0x6814be5eU),
                   bswap_32big(0x52e84725U),
                   bswap_32big(0xbf51b0daU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0157ac72U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005202U));
    r_rsip_func101(bswap_32big(0x132f7589U),
                   bswap_32big(0x5d520df9U),
                   bswap_32big(0x33b20c0eU),
                   bswap_32big(0x5ed4bb02U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x103cedbdU),
                   bswap_32big(0x95780025U),
                   bswap_32big(0x39672fd8U),
                   bswap_32big(0x305191aaU));
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
    r_rsip_func100(bswap_32big(0x536b02d0U),
                   bswap_32big(0xe2326568U),
                   bswap_32big(0x8222a221U),
                   bswap_32big(0xbe03c01fU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[16]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[18]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[19]);
    r_rsip_func100(bswap_32big(0xea2a8174U),
                   bswap_32big(0x08651fb6U),
                   bswap_32big(0x72d2dab3U),
                   bswap_32big(0x35770284U));
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
    r_rsip_func100(bswap_32big(0x2a3f85f4U),
                   bswap_32big(0x645370aeU),
                   bswap_32big(0xeaf6340cU),
                   bswap_32big(0x2abbacefU));
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
    r_rsip_func102(bswap_32big(0xe63c23cfU),
                   bswap_32big(0x0ef09283U),
                   bswap_32big(0x4bf45b6aU),
                   bswap_32big(0xe98e9ea1U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
