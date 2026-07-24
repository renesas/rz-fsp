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
    r_rsip_func100(bswap_32big(0x2c3c83aeU),
                   bswap_32big(0xd7093040U),
                   bswap_32big(0x8184c4beU),
                   bswap_32big(0x0a3cba85U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0x9c205c15U),
                   bswap_32big(0x38280811U),
                   bswap_32big(0x18a4a259U),
                   bswap_32big(0xa52afefaU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01b41ce9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0x64e7c6a9U),
                   bswap_32big(0xa978cebaU),
                   bswap_32big(0x4cbaad81U),
                   bswap_32big(0x6f3a8f29U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x84c63705U),
                   bswap_32big(0xa43226eeU),
                   bswap_32big(0xe5f077a5U),
                   bswap_32big(0x521205c4U));
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
    r_rsip_func100(bswap_32big(0x9a755241U),
                   bswap_32big(0xf6c295bdU),
                   bswap_32big(0x6fcd684eU),
                   bswap_32big(0xaa36ec7eU));
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
    r_rsip_func100(bswap_32big(0x324e0594U),
                   bswap_32big(0x790bf142U),
                   bswap_32big(0x8a92e123U),
                   bswap_32big(0xd7a141efU));
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
    r_rsip_func100(bswap_32big(0x7d18ed7aU),
                   bswap_32big(0xf8f2f5c8U),
                   bswap_32big(0xcdd4f4e0U),
                   bswap_32big(0x88386b76U));
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
    r_rsip_func100(bswap_32big(0x1aee038eU),
                   bswap_32big(0x57446557U),
                   bswap_32big(0x2c9a82beU),
                   bswap_32big(0xa61331bfU));
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
    r_rsip_func100(bswap_32big(0xed5e8c0eU),
                   bswap_32big(0x3297e3f4U),
                   bswap_32big(0x3a72624aU),
                   bswap_32big(0x36a2965fU));
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
    r_rsip_func100(bswap_32big(0xaadb3b80U),
                   bswap_32big(0x439e47ccU),
                   bswap_32big(0x8f8952b2U),
                   bswap_32big(0x7d76302fU));
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
    r_rsip_func102(bswap_32big(0xcbeba217U),
                   bswap_32big(0x4d802d87U),
                   bswap_32big(0x2960a8a1U),
                   bswap_32big(0x35f7dac9U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
