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
    r_rsip_func100(bswap_32big(0xa8c24cfdU),
                   bswap_32big(0xfa586564U),
                   bswap_32big(0x327dbfc9U),
                   bswap_32big(0xe68016e2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x5d24c6ccU), bswap_32big(0x9ff2df4fU), bswap_32big(0x7e52ceadU),
                       bswap_32big(0x07f2338eU));
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
        r_rsip_func100(bswap_32big(0x3daba43bU), bswap_32big(0xcfc1e808U), bswap_32big(0x566d0487U),
                       bswap_32big(0x7af582bcU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xa4277563U), bswap_32big(0x64cc7d9eU), bswap_32big(0x61252ef7U),
                           bswap_32big(0x2a6b3be3U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x000000f3U));
            r_rsip_func101(bswap_32big(0x36d3c133U), bswap_32big(0xd1f10bb6U), bswap_32big(0x033c0307U),
                           bswap_32big(0x6949e1abU));
            r_rsip_func041();
            r_rsip_func100(bswap_32big(0x35470ab1U), bswap_32big(0x86fa341cU), bswap_32big(0x31b59cffU),
                           bswap_32big(0x6ae2c802U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xf7001cb5U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x99e80e8eU), bswap_32big(0xee3126e0U), bswap_32big(0xc2cd72e8U),
                           bswap_32big(0x1923fa49U));
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
            r_rsip_func100(bswap_32big(0xec31438eU), bswap_32big(0x7278b3c4U), bswap_32big(0x89a3d0ecU),
                           bswap_32big(0x4d573a5fU));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x0a03009dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0xc788c7a7U), bswap_32big(0x4247474bU), bswap_32big(0xe209c8d0U),
                           bswap_32big(0xf3ecdb4cU));
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
            r_rsip_func101(bswap_32big(0x774df4f1U), bswap_32big(0xc4269780U), bswap_32big(0xd2d114c8U),
                           bswap_32big(0xd7ba4a17U));
            r_rsip_func045();
            r_rsip_func022();
            r_rsip_subfunc009(bswap_32big(0x000000f3U));
            r_rsip_func101(bswap_32big(0xaa80bd65U), bswap_32big(0x239bb265U), bswap_32big(0x436fccd8U),
                           bswap_32big(0xf8c922e0U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xd6f6f0b3U), bswap_32big(0x76deaec6U), bswap_32big(0x819efae4U),
                           bswap_32big(0x3f4732f1U));
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
            r_rsip_func100(bswap_32big(0xa520e59cU), bswap_32big(0x6a2d2d7cU), bswap_32big(0xe19edd81U),
                           bswap_32big(0x5234309cU));
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
            r_rsip_func100(bswap_32big(0xf61354d4U), bswap_32big(0x8b7e83d9U), bswap_32big(0x47e105eaU),
                           bswap_32big(0x47bbbeefU));
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
            r_rsip_func100(bswap_32big(0xdabe0993U), bswap_32big(0xee6a652fU), bswap_32big(0x6be5a510U),
                           bswap_32big(0x0bb05b3eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x11f5bf47U),
                               bswap_32big(0xf697bdaeU),
                               bswap_32big(0xe57356feU),
                               bswap_32big(0x07234695U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xf886f876U),
                               bswap_32big(0xcc8d8a2eU),
                               bswap_32big(0x498352fdU),
                               bswap_32big(0x947a3d10U));
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
                r_rsip_func102(bswap_32big(0x136ac8cdU),
                               bswap_32big(0xa646d5a9U),
                               bswap_32big(0x83ae282dU),
                               bswap_32big(0x78ed3c52U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
