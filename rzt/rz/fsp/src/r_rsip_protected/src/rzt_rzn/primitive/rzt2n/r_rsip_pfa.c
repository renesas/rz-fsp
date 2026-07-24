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

rsip_ret_t r_rsip_pfa (const uint32_t InData_SharedKeyNum[],
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

    WR1_PROG(REG_1B00H, 0x00fa0002U);
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
    r_rsip_func100(bswap_32big(0x9ce15e74U),
                   bswap_32big(0xe8d975feU),
                   bswap_32big(0x3ce1ab3fU),
                   bswap_32big(0xd86aef2bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x3820af8eU), bswap_32big(0x9b496b14U), bswap_32big(0x44193017U),
                       bswap_32big(0xf7fc2ac9U));
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
        r_rsip_func100(bswap_32big(0x96e99b5dU), bswap_32big(0x049d49e1U), bswap_32big(0x10cc0f55U),
                       bswap_32big(0x456c1666U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x00b7b153U), bswap_32big(0xbbee1f0aU), bswap_32big(0xa3d94a11U),
                           bswap_32big(0x433dc21dU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x000000faU));
            r_rsip_func101(bswap_32big(0xcddbd084U), bswap_32big(0xacd4e330U), bswap_32big(0x542be469U),
                           bswap_32big(0x22bbabf9U));
            r_rsip_func041();
            r_rsip_func100(bswap_32big(0xfb41ef6fU), bswap_32big(0xbf91436cU), bswap_32big(0x64bc6aebU),
                           bswap_32big(0x6312db29U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xf7001cb5U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x7e4e52dfU), bswap_32big(0x3fafcf94U), bswap_32big(0x14f52429U),
                           bswap_32big(0xd6d37bbfU));
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
            r_rsip_func100(bswap_32big(0xbf7b319cU), bswap_32big(0x1048e150U), bswap_32big(0xe43f446bU),
                           bswap_32big(0xe1e38abcU));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x0a03009dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x0b4288afU), bswap_32big(0xd84ad8d5U), bswap_32big(0x3bc2428eU),
                           bswap_32big(0x4e477231U));
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
            r_rsip_subfunc009(bswap_32big(0x000000faU));
            r_rsip_func101(bswap_32big(0x2a60bf9cU), bswap_32big(0x5c034c1cU), bswap_32big(0x27dca6ddU),
                           bswap_32big(0x62ac571cU));
            r_rsip_func045();
            r_rsip_func023();
            r_rsip_subfunc009(bswap_32big(0x000000faU));
            r_rsip_func101(bswap_32big(0x7af8a163U), bswap_32big(0xf9345737U), bswap_32big(0xf95f5ae4U),
                           bswap_32big(0x21b33272U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x9d4ca8ccU), bswap_32big(0xa22eeeceU), bswap_32big(0xe3d75c41U),
                           bswap_32big(0xd6255ae7U));
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
            r_rsip_func100(bswap_32big(0x971c509cU), bswap_32big(0x651b5844U), bswap_32big(0xd5fffbe1U),
                           bswap_32big(0x1e6e9cb0U));
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
            r_rsip_func100(bswap_32big(0xf70c1a82U), bswap_32big(0x79735e9aU), bswap_32big(0x9b853bddU),
                           bswap_32big(0xd6566c8cU));
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
            r_rsip_func100(bswap_32big(0x619f59c6U), bswap_32big(0xc9cde091U), bswap_32big(0x711e5772U),
                           bswap_32big(0x64b7ae05U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x9fb212deU),
                               bswap_32big(0xa2b629f8U),
                               bswap_32big(0x33385cb1U),
                               bswap_32big(0x19d43438U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x7f631cf0U),
                               bswap_32big(0x34791aaeU),
                               bswap_32big(0x8c9e5e8fU),
                               bswap_32big(0x51531cb6U));
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
                r_rsip_func102(bswap_32big(0xc1c78cc4U),
                               bswap_32big(0xf3a15858U),
                               bswap_32big(0x826b20eaU),
                               bswap_32big(0x51c3010fU));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
