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

rsip_ret_t r_rsip_p51f (uint32_t OutData_EncCertificateInfo[])
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
    r_rsip_func100(bswap_32big(0x01e03d80U),
                   bswap_32big(0xf214afecU),
                   bswap_32big(0xff423507U),
                   bswap_32big(0x098934bcU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00005102U));
    r_rsip_func101(bswap_32big(0x056f7c3cU),
                   bswap_32big(0xf3ef69e0U),
                   bswap_32big(0xfe31180aU),
                   bswap_32big(0x6f84e265U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x8af26001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005102U));
    r_rsip_func101(bswap_32big(0x9e8f4e79U),
                   bswap_32big(0xf4087499U),
                   bswap_32big(0x63e7410eU),
                   bswap_32big(0x52a17334U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x5a58a376U),
                   bswap_32big(0x084ad63bU),
                   bswap_32big(0xe24d9f71U),
                   bswap_32big(0x31cb60e5U));
    WR1_PROG(REG_1A2CH, 0x40000200U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    WR1_PROG(REG_1608H, 0x818c0004U);
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
    r_rsip_func100(bswap_32big(0x0fe7cd17U),
                   bswap_32big(0x758f0a85U),
                   bswap_32big(0xfde20b35U),
                   bswap_32big(0x5f124240U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[16]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[17]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[18]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[19]);
    r_rsip_func100(bswap_32big(0x55ebae08U),
                   bswap_32big(0xa3af5565U),
                   bswap_32big(0x92cbf64eU),
                   bswap_32big(0x7bb06b7dU));
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
    r_rsip_func102(bswap_32big(0x5fffe80fU),
                   bswap_32big(0xb3ecc2afU),
                   bswap_32big(0xd36e23daU),
                   bswap_32big(0x99f8aa65U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
