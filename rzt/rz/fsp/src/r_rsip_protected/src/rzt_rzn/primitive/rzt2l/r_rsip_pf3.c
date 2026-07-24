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

rsip_ret_t r_rsip_pf3 (const uint32_t InData_SharedKeyNum[],
                       const uint32_t InData_SharedKeyIndex[],
                       const uint32_t InData_SessionKey[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
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

    WR1_PROG(REG_1B00H, 0x00f30002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_SharedKeyNum[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xfffffff0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x461abe47U),
                   bswap_32big(0x8a2727c7U),
                   bswap_32big(0xfc28b722U),
                   bswap_32big(0xb6569547U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xae69ee65U), bswap_32big(0xe809264eU), bswap_32big(0x1b81cc2bU),
                       bswap_32big(0x4b8fdc20U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
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
        r_rsip_func100(bswap_32big(0x87c09cefU), bswap_32big(0xeb430c01U), bswap_32big(0x34b511a4U),
                       bswap_32big(0xe8eb0a46U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x263bf713U), bswap_32big(0x9442af55U), bswap_32big(0xaea140eeU),
                           bswap_32big(0xc6a83bb6U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x000000f3U));
            r_rsip_func101(bswap_32big(0x9a143344U), bswap_32big(0x8df0e824U), bswap_32big(0xf9bfe8a1U),
                           bswap_32big(0x77608fd0U));
            r_rsip_func041();
            r_rsip_func100(bswap_32big(0x87e18fc5U), bswap_32big(0x3d7bf08bU), bswap_32big(0x0906aa08U),
                           bswap_32big(0x7f202afbU));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xf7001cb5U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x5d2c727cU), bswap_32big(0xa5feb18aU), bswap_32big(0xbbe5038bU),
                           bswap_32big(0xf396df65U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x07000d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[4]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[5]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[6]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[7]);
            WR1_PROG(REG_1824H, 0x8c100005U);
            r_rsip_subfunc003(0x00410011U);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x0a03008dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SessionKey[0]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[1]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[2]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[3]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x155c0660U), bswap_32big(0xeba6c320U), bswap_32big(0x11b1bb0aU),
                           bswap_32big(0x2beb0b6aU));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x0a03009dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0xb6571ffcU), bswap_32big(0x81a56ccdU), bswap_32big(0xfee35cebU),
                           bswap_32big(0xfc6e7454U));
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
            r_rsip_subfunc009(bswap_32big(0x000000f3U));
            r_rsip_func101(bswap_32big(0xc2dd9193U), bswap_32big(0xfee52afdU), bswap_32big(0x8d22d678U),
                           bswap_32big(0xbd11634eU));
            r_rsip_func045();
            r_rsip_func022();
            r_rsip_subfunc009(bswap_32big(0x000000f3U));
            r_rsip_func101(bswap_32big(0xb821fbc0U), bswap_32big(0xa642787dU), bswap_32big(0x8c89196fU),
                           bswap_32big(0x9db6ac01U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xf5110965U), bswap_32big(0xa72dd203U), bswap_32big(0x6b9559acU),
                           bswap_32big(0x47aaef5fU));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_InstData[0]);
            WR1_ADDR(REG_1420H, &InData_InstData[1]);
            WR1_ADDR(REG_1420H, &InData_InstData[2]);
            WR1_ADDR(REG_1420H, &InData_InstData[3]);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7009d05U);
            r_rsip_subfunc003(0x00810011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
            r_rsip_func100(bswap_32big(0xb98e45cfU), bswap_32big(0x6de58eb5U), bswap_32big(0x7822ba79U),
                           bswap_32big(0x5cb0b78cU));
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x49110054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_InstData[4]);
            WR1_ADDR(REG_1420H, &InData_InstData[5]);
            WR1_ADDR(REG_1420H, &InData_InstData[6]);
            WR1_ADDR(REG_1420H, &InData_InstData[7]);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            r_rsip_subfunc003(0x00810011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
            r_rsip_func100(bswap_32big(0xc90eaa2aU), bswap_32big(0x071f377eU), bswap_32big(0xd5031b6cU),
                           bswap_32big(0xbea7fd31U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x09108105U);
            r_rsip_subfunc003(0x00820011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
            RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_InstData[8]);
            WR1_ADDR(REG_1420H, &InData_InstData[9]);
            WR1_ADDR(REG_1420H, &InData_InstData[10]);
            WR1_ADDR(REG_1420H, &InData_InstData[11]);
            r_rsip_func100(bswap_32big(0x54ec4f93U), bswap_32big(0x5ca08cdbU), bswap_32big(0x9e7e3b33U),
                           bswap_32big(0xdfaf8b7cU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xe67c3183U),
                               bswap_32big(0x6bd10a97U),
                               bswap_32big(0xd40ed0eaU),
                               bswap_32big(0x90065d57U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xaba06970U),
                               bswap_32big(0xb1d7b70eU),
                               bswap_32big(0x2a69e914U),
                               bswap_32big(0x3942aa9dU));
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
                r_rsip_func102(bswap_32big(0x207804c1U),
                               bswap_32big(0x4909d35aU),
                               bswap_32big(0x6b489edaU),
                               bswap_32big(0xb12bdacaU));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
