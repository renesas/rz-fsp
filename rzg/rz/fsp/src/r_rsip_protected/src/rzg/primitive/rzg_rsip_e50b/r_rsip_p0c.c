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

rsip_ret_t r_rsip_p0c (uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[])
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
    if (0x0U != RD1_MASK(REG_14B4H, 0x1dU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x000c0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x0000000cU));
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func101(bswap_32big(0x6f9b3c38U),
                   bswap_32big(0xf79402a1U),
                   bswap_32big(0xde42048fU),
                   bswap_32big(0xafdbe148U));
    r_rsip_func047();
    r_rsip_func100(bswap_32big(0xa07a467dU),
                   bswap_32big(0x181a68b2U),
                   bswap_32big(0xe8836fe8U),
                   bswap_32big(0xc268da89U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x08000045U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_IV[0]);
    WR1_ADDR(REG_1420H, &InData_IV[1]);
    WR1_ADDR(REG_1420H, &InData_IV[2]);
    WR1_ADDR(REG_1420H, &InData_IV[3]);
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000000cU));
    r_rsip_func101(bswap_32big(0xa2637a86U),
                   bswap_32big(0x70d8acf8U),
                   bswap_32big(0xd2fdeadeU),
                   bswap_32big(0x6fcba52dU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01abe599U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000000cU));
    r_rsip_func101(bswap_32big(0x2a197e90U),
                   bswap_32big(0x92b27e47U),
                   bswap_32big(0xef9739c4U),
                   bswap_32big(0x9e7378dcU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0xe39010f6U), bswap_32big(0x226b7adcU), bswap_32big(0x2f90e6f4U),
                       bswap_32big(0x019a1388U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 3]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x088c6b96U), bswap_32big(0xde0f8e44U), bswap_32big(0x81bf1edbU),
                       bswap_32big(0xf94c9995U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 28; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0xf8e2a2c3U), bswap_32big(0xc5c90ff3U), bswap_32big(0x677e7311U),
                       bswap_32big(0x76ff41afU));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 32]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 33]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 34]);
        WR1_ADDR(REG_1420H, &InData_InstData[iLoop + 35]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 36]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 37]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 38]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 39]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x5f2af7baU), bswap_32big(0x4c8d48c5U), bswap_32big(0xd8d30bacU),
                       bswap_32big(0x6ec231fdU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x5cc31837U),
                   bswap_32big(0x98752d3dU),
                   bswap_32big(0xd257d58cU),
                   bswap_32big(0xcb037e1bU));
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x49110054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0xd900090dU);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[60]);
    WR1_ADDR(REG_1420H, &InData_InstData[61]);
    WR1_ADDR(REG_1420H, &InData_InstData[62]);
    WR1_ADDR(REG_1420H, &InData_InstData[63]);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe7008d05U);
    r_rsip_subfunc003(0x00810011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[64]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[65]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[66]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[67]);
    r_rsip_func100(bswap_32big(0x0b47c48cU),
                   bswap_32big(0xd69dc440U),
                   bswap_32big(0xdb64aa24U),
                   bswap_32big(0x990c3b62U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[68]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[69]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[70]);
    RD1_ADDR(REG_1420H, &OutData_KeyIndex[71]);
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_InstData[64]);
    WR1_ADDR(REG_1420H, &InData_InstData[65]);
    WR1_ADDR(REG_1420H, &InData_InstData[66]);
    WR1_ADDR(REG_1420H, &InData_InstData[67]);
    r_rsip_func100(bswap_32big(0xe137675bU),
                   bswap_32big(0x5fc9d4cbU),
                   bswap_32big(0x3284ccddU),
                   bswap_32big(0x41055647U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x526a1e8fU), bswap_32big(0x03ea2164U), bswap_32big(0x138c1ed7U),
                       bswap_32big(0x96b1044eU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x189db26dU), bswap_32big(0x09d1d6b6U), bswap_32big(0x4ce5faa0U),
                       bswap_32big(0x8e992c0cU));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[3]);
        r_rsip_func102(bswap_32big(0x92f335edU), bswap_32big(0xff07b605U), bswap_32big(0x1d547c15U),
                       bswap_32big(0xca732e2dU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
