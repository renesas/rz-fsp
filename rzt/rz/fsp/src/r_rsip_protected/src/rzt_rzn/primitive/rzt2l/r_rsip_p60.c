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

rsip_ret_t r_rsip_p60 (const uint32_t InData_SharedKeyNum[],
                       const uint32_t InData_SharedKeyIndex[],
                       const uint32_t InData_SessionKey[],
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

    WR1_PROG(REG_1B00H, 0x00600002U);
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
    r_rsip_func100(bswap_32big(0x83ae19a0U),
                   bswap_32big(0xc33db396U),
                   bswap_32big(0xa0b31372U),
                   bswap_32big(0xdf317592U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x86ede829U), bswap_32big(0xd60512b6U), bswap_32big(0xf799967aU),
                       bswap_32big(0x3c3a5d98U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_subfunc009(bswap_32big(0x00000060U));
        r_rsip_func101(bswap_32big(0x8a922ceaU), bswap_32big(0x29197f03U), bswap_32big(0x7d807969U),
                       bswap_32big(0x092b36a7U));
        r_rsip_func041();
        r_rsip_func100(bswap_32big(0x048b5a44U), bswap_32big(0xb6f1049bU), bswap_32big(0x63160e41U),
                       bswap_32big(0x843e02c7U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xf7001cb5U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
        WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0xa0848661U), bswap_32big(0x92329a70U), bswap_32big(0x5a33004dU),
                       bswap_32big(0x264c0b85U));
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
        r_rsip_func100(bswap_32big(0x48191e5cU), bswap_32big(0x18344921U), bswap_32big(0x24645bbfU),
                       bswap_32big(0x67aac760U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0x0a03009dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
        WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
        WAIT_STS(REG_1828H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000500U);
        r_rsip_func100(bswap_32big(0xe2592731U), bswap_32big(0x24a1f19bU), bswap_32big(0x345e16caU),
                       bswap_32big(0x75218e33U));
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
        r_rsip_subfunc009(bswap_32big(0x00000060U));
        r_rsip_func101(bswap_32big(0x4567a06bU), bswap_32big(0xfe63bb35U), bswap_32big(0xe7c112f0U),
                       bswap_32big(0x7687032aU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01ff3ef1U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00000060U));
        r_rsip_func101(bswap_32big(0xb943f6c4U), bswap_32big(0x30f48342U), bswap_32big(0x42230c3dU),
                       bswap_32big(0x2e5d5f34U));
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
            r_rsip_func100(bswap_32big(0xbbc3e9ccU), bswap_32big(0xea40bf1fU), bswap_32big(0x3ab38d57U),
                           bswap_32big(0x5db0539cU));
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
            r_rsip_func101(bswap_32big(0x07d48d46U), bswap_32big(0xbd258a02U), bswap_32big(0xd3297493U),
                           bswap_32big(0x6b97f83bU));
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
            r_rsip_func100(bswap_32big(0x0e8f945fU), bswap_32big(0x339e126eU), bswap_32big(0x32cc30a5U),
                           bswap_32big(0x39ab0934U));
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
            r_rsip_func101(bswap_32big(0xdbd7730bU), bswap_32big(0x2d60e447U), bswap_32big(0x2013ea47U),
                           bswap_32big(0x25b11fe0U));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xa42b6530U), bswap_32big(0x0ab0f577U), bswap_32big(0x8aff9b4fU),
                       bswap_32big(0x0db79be5U));
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
        r_rsip_func100(bswap_32big(0x9f8ee8d5U), bswap_32big(0x4648087dU), bswap_32big(0xe6b9a1caU),
                       bswap_32big(0x60184e02U));
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
        r_rsip_func100(bswap_32big(0x2b8991a8U), bswap_32big(0xe4eb2eafU), bswap_32big(0x84b0d716U),
                       bswap_32big(0xfd81b8abU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xb570ef15U), bswap_32big(0x3f0c7cfdU), bswap_32big(0x41901e55U),
                           bswap_32big(0xc8f4128fU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x1d64fbbaU), bswap_32big(0x8b50b719U), bswap_32big(0xab50fdaaU),
                           bswap_32big(0x4d63eeb6U));
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
            r_rsip_func102(bswap_32big(0x722e1b3eU), bswap_32big(0x9211108bU), bswap_32big(0x7038e2b3U),
                           bswap_32big(0x4ec52994U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
