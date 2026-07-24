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

rsip_ret_t r_rsip_peef (uint32_t OutData_EncCertificateInfo[])
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
    r_rsip_func100(bswap_32big(0xd878f371U),
                   bswap_32big(0xdeeb6b23U),
                   bswap_32big(0xe5733fe6U),
                   bswap_32big(0x79aed438U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000ee02U));
    r_rsip_func101(bswap_32big(0x22851714U),
                   bswap_32big(0x573d28d6U),
                   bswap_32big(0x82c36ff0U),
                   bswap_32big(0x6e411c40U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x010f6caaU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000ee02U));
    r_rsip_func101(bswap_32big(0x29c55346U),
                   bswap_32big(0xe752c23dU),
                   bswap_32big(0x16b661e8U),
                   bswap_32big(0x0e7d7ea9U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x8d4a452cU),
                   bswap_32big(0x5164d308U),
                   bswap_32big(0xc033963dU),
                   bswap_32big(0xfd9ab4e4U));
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    WR1_PROG(REG_1608H, 0x81880004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890021U);
    WR1_PROG(REG_1408H, 0x00002022U);
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
    r_rsip_func100(bswap_32big(0x0fb2a31cU),
                   bswap_32big(0xfc3f9efeU),
                   bswap_32big(0x24992ea0U),
                   bswap_32big(0x11991c0aU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[12]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[13]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[14]);
    RD1_ADDR(REG_1420H, &OutData_EncCertificateInfo[15]);
    r_rsip_func100(bswap_32big(0x4a746284U),
                   bswap_32big(0x6bb6f5e6U),
                   bswap_32big(0x119b7464U),
                   bswap_32big(0x62768919U));
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
    r_rsip_func102(bswap_32big(0xa62239c3U),
                   bswap_32big(0x4fa69862U),
                   bswap_32big(0x6411eb01U),
                   bswap_32big(0x17895b22U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
