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

rsip_ret_t r_rsip_p2c (uint32_t const InData_CurveType[],
                       uint32_t const InData_Cmd[],
                       uint32_t const InData_IV[],
                       uint32_t const InData_InstData[],
                       uint32_t       OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x002c0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30000f5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000f9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008be0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xbd5e721eU),
                   bswap_32big(0xb19d8922U),
                   bswap_32big(0xf186da51U),
                   bswap_32big(0xae44561cU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xd9607eebU), bswap_32big(0x0b56ca3fU), bswap_32big(0x3590c822U),
                       bswap_32big(0x793bd2ccU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x0000369cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000000a7U);
        WR1_PROG(REG_1608H, 0x80010380U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x0000002cU));
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x8af92fcfU), bswap_32big(0x50ade34fU), bswap_32big(0xc8f18fbfU),
                       bswap_32big(0x43768b67U));
        r_rsip_func047();
        WR1_PROG(REG_1600H, 0x00003794U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x170338a7U), bswap_32big(0x0461e7c5U), bswap_32big(0x0ae4fcd2U),
                       bswap_32big(0x391ed148U));
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
        r_rsip_subfunc009(bswap_32big(0x0000002cU));
        r_rsip_func101(bswap_32big(0x9690bd04U), bswap_32big(0x8be868a1U), bswap_32big(0x8e8be420U),
                       bswap_32big(0xb7dd1848U));
        r_rsip_func045();
        r_rsip_func023();
        r_rsip_subfunc009(bswap_32big(0x0000002cU));
        r_rsip_func101(bswap_32big(0x96490115U), bswap_32big(0x2010bf09U), bswap_32big(0xcde866b4U),
                       bswap_32big(0x6013a831U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x3d9f9a48U), bswap_32big(0x1cb204b9U), bswap_32big(0x81454c96U),
                       bswap_32big(0x8ab28f2fU));
        WR1_PROG(REG_1444H, 0x00000bc1U);
        WR1_PROG(REG_182CH, 0x00000200U);
        WR1_PROG(REG_1824H, 0xd900890fU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[0]);
        WR1_ADDR(REG_1420H, &InData_InstData[1]);
        WR1_ADDR(REG_1420H, &InData_InstData[2]);
        WR1_ADDR(REG_1420H, &InData_InstData[3]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[4]);
        WR1_ADDR(REG_1420H, &InData_InstData[5]);
        WR1_ADDR(REG_1420H, &InData_InstData[6]);
        WR1_ADDR(REG_1420H, &InData_InstData[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[8]);
        WR1_ADDR(REG_1420H, &InData_InstData[9]);
        WR1_ADDR(REG_1420H, &InData_InstData[10]);
        WR1_ADDR(REG_1420H, &InData_InstData[11]);
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        r_rsip_subfunc003(0x00810031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
        r_rsip_func100(bswap_32big(0xe2bd15b2U), bswap_32big(0x833efec6U), bswap_32big(0x6d8b2f6eU),
                       bswap_32big(0xd3b1bce2U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x49110054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[12]);
        WR1_ADDR(REG_1420H, &InData_InstData[13]);
        WR1_ADDR(REG_1420H, &InData_InstData[14]);
        WR1_ADDR(REG_1420H, &InData_InstData[15]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
        r_rsip_func100(bswap_32big(0x32fdf959U), bswap_32big(0x307861dcU), bswap_32big(0xdd63f2b4U),
                       bswap_32big(0xb3f31dd9U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[20]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[21]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[22]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[23]);
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x9c100005U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_InstData[16]);
        WR1_ADDR(REG_1420H, &InData_InstData[17]);
        WR1_ADDR(REG_1420H, &InData_InstData[18]);
        WR1_ADDR(REG_1420H, &InData_InstData[19]);
        r_rsip_func100(bswap_32big(0x3455924bU), bswap_32big(0x3a232b7dU), bswap_32big(0xa4a051f7U),
                       bswap_32big(0xeb78aa49U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x2c8ace84U), bswap_32big(0x95b805b1U), bswap_32big(0xea50becbU),
                           bswap_32big(0x0956d36dU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xa5039b5cU), bswap_32big(0x4461821fU), bswap_32big(0x07aef211U),
                           bswap_32big(0xa191b39dU));
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
            r_rsip_func102(bswap_32big(0xc9abb9b1U), bswap_32big(0x5dd16713U), bswap_32big(0xf54ef21eU),
                           bswap_32big(0xe55e9745U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
