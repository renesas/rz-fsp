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
    r_rsip_func100(bswap_32big(0xabdc210cU),
                   bswap_32big(0x51666a92U),
                   bswap_32big(0x0bcf31f6U),
                   bswap_32big(0xf8e82fc5U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0xc4cf680dU),
                   bswap_32big(0x39ae67c9U),
                   bswap_32big(0x0acaf073U),
                   bswap_32big(0x00028a1cU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01b7bbf3U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000eaU));
    r_rsip_func101(bswap_32big(0xbfec3e19U),
                   bswap_32big(0x3b5df05eU),
                   bswap_32big(0x01280493U),
                   bswap_32big(0xb31ed0a1U));
    r_rsip_func046();
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x66370923U),
                   bswap_32big(0x9c00a7c3U),
                   bswap_32big(0x3188abe8U),
                   bswap_32big(0xfbb69002U));
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
    r_rsip_func100(bswap_32big(0x6019ea2cU),
                   bswap_32big(0x0cb16009U),
                   bswap_32big(0xb6e2ee83U),
                   bswap_32big(0x4d0d58c4U));
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
    r_rsip_func100(bswap_32big(0xd32a5d6fU),
                   bswap_32big(0x2f062a31U),
                   bswap_32big(0x4df34394U),
                   bswap_32big(0xc658c494U));
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
    r_rsip_func100(bswap_32big(0x17f169bfU),
                   bswap_32big(0xa153718aU),
                   bswap_32big(0xe528c553U),
                   bswap_32big(0x21b808efU));
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
    r_rsip_func100(bswap_32big(0x0f6b9a74U),
                   bswap_32big(0x1357f394U),
                   bswap_32big(0x7fac40feU),
                   bswap_32big(0x6f1c316cU));
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
    r_rsip_func100(bswap_32big(0xc1a6f653U),
                   bswap_32big(0x0e98b796U),
                   bswap_32big(0xc64e292dU),
                   bswap_32big(0x801f593bU));
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
    r_rsip_func100(bswap_32big(0x59a772f0U),
                   bswap_32big(0x6b28ba12U),
                   bswap_32big(0x10300ed9U),
                   bswap_32big(0x7e0b950bU));
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
    r_rsip_func102(bswap_32big(0x5ad6e863U),
                   bswap_32big(0xdd493e0dU),
                   bswap_32big(0xb1e4c138U),
                   bswap_32big(0x21ebc671U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
