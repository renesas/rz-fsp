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

rsip_ret_t r_rsip_pea (uint32_t OutData_EncPreMasterSecret[])
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00ea0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    r_rsip_func100(bswap_32big(0x0e3d82bcU),
                   bswap_32big(0x0415576aU),
                   bswap_32big(0x078adbb1U),
                   bswap_32big(0x6dbad6faU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0x0a85629eU),
                   bswap_32big(0x1752a4c2U),
                   bswap_32big(0x47d1ff4aU),
                   bswap_32big(0xf1de0a3aU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0113edb0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0x23759d57U),
                   bswap_32big(0xfa19d5b8U),
                   bswap_32big(0xc2640e5eU),
                   bswap_32big(0x83c26c3cU));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x3a980758U),
                   bswap_32big(0x8656ccb3U),
                   bswap_32big(0xed0d898eU),
                   bswap_32big(0xb47cc9d8U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80840004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1600H, 0x0000a480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000010U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x263dac8dU),
                   bswap_32big(0x31b4d70cU),
                   bswap_32big(0x2ba740b2U),
                   bswap_32big(0x96d7a637U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80840004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1600H, 0x0000a480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000010U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x4c798852U),
                   bswap_32big(0x1a72e34fU),
                   bswap_32big(0x552c70b7U),
                   bswap_32big(0xfd6e8543U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80840004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000303U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01003ca4U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x2695ac6bU),
                   bswap_32big(0xa3352b4dU),
                   bswap_32big(0x6249e10cU),
                   bswap_32big(0xd333d9c3U));
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    WR1_PROG(REG_1608H, 0x818c0004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890021U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[4]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[5]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[6]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[7]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[8]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[9]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[10]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[11]);
    r_rsip_func100(bswap_32big(0xfe31f729U),
                   bswap_32big(0x424be516U),
                   bswap_32big(0x76fac3dfU),
                   bswap_32big(0x5eca1ebaU));
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7008d07U);
    r_rsip_subfunc003(0x00890011U);
    r_rsip_subfunc003(0x00800011U);
    WR1_PROG(REG_1408H, 0x00002022U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[12]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[13]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[14]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[15]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[16]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[17]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[18]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[19]);
    r_rsip_func100(bswap_32big(0x5d1e7c72U),
                   bswap_32big(0x1eeef347U),
                   bswap_32big(0x2623f24dU),
                   bswap_32big(0x1625b9beU));
    WR1_PROG(REG_1444H, 0x000003a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1420H, bswap_32big(0x00000004U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[20]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[21]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[22]);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[23]);
    r_rsip_func100(bswap_32big(0x0c2df6a7U),
                   bswap_32big(0x4553ed81U),
                   bswap_32big(0xc8aac28fU),
                   bswap_32big(0xcf675f7cU));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[3]);
    r_rsip_func102(bswap_32big(0x172f9c5aU),
                   bswap_32big(0x1a75537bU),
                   bswap_32big(0x527719beU),
                   bswap_32big(0xbc00d6f0U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
