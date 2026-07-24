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
    r_rsip_func100(bswap_32big(0xec3e5a94U),
                   bswap_32big(0x81da376eU),
                   bswap_32big(0xf60444c3U),
                   bswap_32big(0x8e3068d7U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0xa4814cc1U),
                   bswap_32big(0x814c03abU),
                   bswap_32big(0x71db4782U),
                   bswap_32big(0xe03716b4U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01a5a796U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0xe9a04d8aU),
                   bswap_32big(0x9a866b76U),
                   bswap_32big(0xc2ff8395U),
                   bswap_32big(0xafde6b6aU));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xa1c394edU),
                   bswap_32big(0xbdf4297eU),
                   bswap_32big(0xf194e672U),
                   bswap_32big(0x00a999d6U));
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
    r_rsip_func100(bswap_32big(0xc104fe52U),
                   bswap_32big(0x6fb586b1U),
                   bswap_32big(0x3cb0c0dfU),
                   bswap_32big(0xba9fcdbfU));
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
    r_rsip_func100(bswap_32big(0x171cf401U),
                   bswap_32big(0x07546311U),
                   bswap_32big(0xb55a08c8U),
                   bswap_32big(0x8df1cc39U));
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
    r_rsip_func100(bswap_32big(0x0f54159eU),
                   bswap_32big(0x5b131485U),
                   bswap_32big(0x8e8d4001U),
                   bswap_32big(0x0c9fa19aU));
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
    r_rsip_func100(bswap_32big(0x3a3aed36U),
                   bswap_32big(0x76b48084U),
                   bswap_32big(0x2ae46cbeU),
                   bswap_32big(0x53f5a4e8U));
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
    r_rsip_func100(bswap_32big(0x96a0ee81U),
                   bswap_32big(0x60fc7489U),
                   bswap_32big(0xe98f4685U),
                   bswap_32big(0x2bd66ad4U));
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
    r_rsip_func100(bswap_32big(0x9c4dfe08U),
                   bswap_32big(0x02ab44d7U),
                   bswap_32big(0x4d9b2c1cU),
                   bswap_32big(0x97543326U));
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
    r_rsip_func102(bswap_32big(0xfe77f57aU),
                   bswap_32big(0x6c449ef2U),
                   bswap_32big(0xcbe7a87fU),
                   bswap_32big(0x7d3fd572U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
