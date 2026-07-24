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

rsip_ret_t r_rsip_p80 (const uint32_t InData_SharedKeyNum[],
                       const uint32_t InData_SharedKeyIndex[],
                       const uint32_t InData_SessionKey[],
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

    WR1_PROG(REG_1B00H, 0x00800002U);
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
    r_rsip_func100(bswap_32big(0x6e055defU),
                   bswap_32big(0x3f4da8d1U),
                   bswap_32big(0xcc89ae9dU),
                   bswap_32big(0xe7030153U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xbc5f0661U), bswap_32big(0x4a7f6357U), bswap_32big(0x5784f1e8U),
                       bswap_32big(0x337fdec0U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_subfunc009(bswap_32big(0x00000080U));
        r_rsip_func101(bswap_32big(0x8d7b28ccU), bswap_32big(0x28852f51U), bswap_32big(0xd9bd8978U),
                       bswap_32big(0x460f6080U));
        r_rsip_func041();
        r_rsip_func100(bswap_32big(0x91992838U), bswap_32big(0x5efc0781U), bswap_32big(0x3392311cU),
                       bswap_32big(0xe938bbafU));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xf7001cb5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0x0b761985U), bswap_32big(0x664baedfU), bswap_32big(0x7723f176U),
                       bswap_32big(0x931d91d1U));
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
        r_rsip_func100(bswap_32big(0x392bddc4U), bswap_32big(0x3009079bU), bswap_32big(0x34c98136U),
                       bswap_32big(0x5d42e8e6U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0a03009dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0xe6b87abbU), bswap_32big(0x1e5084f7U), bswap_32big(0xa0c5c3bcU),
                       bswap_32big(0x39aa4c83U));
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
        r_rsip_subfunc009(bswap_32big(0x00000080U));
        r_rsip_func101(bswap_32big(0xe6404468U), bswap_32big(0x77c70badU), bswap_32big(0x35992d56U),
                       bswap_32big(0xad284890U));
        r_rsip_func045();
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010140U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Cmd[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x30003140U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00070020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01ad9be9U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00030040U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01f50df4U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00050040U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01825405U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00000080U));
        r_rsip_func101(bswap_32big(0xf2e04b53U), bswap_32big(0xbeb858eeU), bswap_32big(0x4dfd44deU),
                       bswap_32big(0x4e7b1fa4U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xca42dea9U), bswap_32big(0xd3c3d4c9U), bswap_32big(0x0cfb200cU),
                       bswap_32big(0xf4fe2f2dU));
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
        r_rsip_func100(bswap_32big(0x59f6db09U), bswap_32big(0xb560a695U), bswap_32big(0x3596af88U),
                       bswap_32big(0x41adcf86U));
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
        r_rsip_func100(bswap_32big(0x0371e919U), bswap_32big(0x4ef7a601U), bswap_32big(0x3aa2f8e2U),
                       bswap_32big(0x3dfbcf72U));
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
        r_rsip_func100(bswap_32big(0xd0cbd099U), bswap_32big(0xd02d42afU), bswap_32big(0xd3a75dfaU),
                       bswap_32big(0x77b41156U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xee58b0f6U), bswap_32big(0xd663633dU), bswap_32big(0x3fb7c7b0U),
                           bswap_32big(0xcd77daebU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x79f1979cU), bswap_32big(0x81b0c7d7U), bswap_32big(0x771ca344U),
                           bswap_32big(0xc6654893U));
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
            r_rsip_func102(bswap_32big(0xdc6eafb6U), bswap_32big(0xc72a1354U), bswap_32big(0xcb2dbb71U),
                           bswap_32big(0xadb3cabbU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
