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
    r_rsip_func100(bswap_32big(0x342f3d2aU),
                   bswap_32big(0x9ad79e86U),
                   bswap_32big(0x458153f8U),
                   bswap_32big(0xb03fafc8U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0x246f1270U),
                   bswap_32big(0x3f7df548U),
                   bswap_32big(0x9d484e92U),
                   bswap_32big(0xcbdc842cU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01c54b98U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0x0956ba59U),
                   bswap_32big(0x18c0967fU),
                   bswap_32big(0x0a315feaU),
                   bswap_32big(0xc7a70599U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x17121cc4U),
                   bswap_32big(0xd5fca3c1U),
                   bswap_32big(0x5ad13d20U),
                   bswap_32big(0xed9cc0cdU));
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
    r_rsip_func100(bswap_32big(0xbbbed113U),
                   bswap_32big(0xe73cb3caU),
                   bswap_32big(0xaf932a80U),
                   bswap_32big(0xe601e4aaU));
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
    r_rsip_func100(bswap_32big(0xf45417eaU),
                   bswap_32big(0x6a0b6bd3U),
                   bswap_32big(0x8469b7d8U),
                   bswap_32big(0xb2bd59edU));
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
    r_rsip_func100(bswap_32big(0x9d9e8260U),
                   bswap_32big(0x102a4c81U),
                   bswap_32big(0xf1b90232U),
                   bswap_32big(0xd24c3222U));
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
    r_rsip_func100(bswap_32big(0xcaae7d5fU),
                   bswap_32big(0xdcda7e5bU),
                   bswap_32big(0x3f78bbafU),
                   bswap_32big(0x41c077baU));
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
    r_rsip_func100(bswap_32big(0xf51101b2U),
                   bswap_32big(0x9c5baa76U),
                   bswap_32big(0x912c098dU),
                   bswap_32big(0x6531faedU));
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
    r_rsip_func100(bswap_32big(0x304e2337U),
                   bswap_32big(0x86ed8268U),
                   bswap_32big(0x5b5b8bafU),
                   bswap_32big(0x6c35c983U));
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
    r_rsip_func102(bswap_32big(0x3e4ce6daU),
                   bswap_32big(0x7bd04d71U),
                   bswap_32big(0xb0746b40U),
                   bswap_32big(0x38b2713aU));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
