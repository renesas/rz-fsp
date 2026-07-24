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
    r_rsip_func100(bswap_32big(0xb412dcf0U),
                   bswap_32big(0x674fc94cU),
                   bswap_32big(0xdf3a1126U),
                   bswap_32big(0x7a5cf41fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x5417a110U), bswap_32big(0xa2f40f09U), bswap_32big(0x7f0bc367U),
                       bswap_32big(0x14d5b9f9U));
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
        r_rsip_func100(bswap_32big(0x5f216e54U), bswap_32big(0x36b45832U), bswap_32big(0x39902d67U),
                       bswap_32big(0xe7e9e231U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xd18dac94U), bswap_32big(0xde53ea5bU), bswap_32big(0xd9a1564dU),
                           bswap_32big(0x7667e2bcU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x000000faU));
            r_rsip_func101(bswap_32big(0xd2bdc820U), bswap_32big(0xe58b80b7U), bswap_32big(0xdd55abfcU),
                           bswap_32big(0xde79bfc0U));
            r_rsip_func041();
            r_rsip_func100(bswap_32big(0xfdd7b10aU), bswap_32big(0xe99a9074U), bswap_32big(0x13aaca51U),
                           bswap_32big(0x40cf1ae1U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xf7001cb5U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[0]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[1]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[2]);
            WR1_ADDR(REG_1420H, &InData_SharedKeyIndex[3]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x63293394U), bswap_32big(0x8a67030eU), bswap_32big(0xedba2c47U),
                           bswap_32big(0xcbcd7dc2U));
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
            r_rsip_func100(bswap_32big(0x14c9697eU), bswap_32big(0x7cb79898U), bswap_32big(0x1df15c89U),
                           bswap_32big(0xfd30d947U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x0a03009dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_SessionKey[4]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[5]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[6]);
            WR1_ADDR(REG_1420H, &InData_SessionKey[7]);
            WAIT_STS(REG_1828H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000500U);
            r_rsip_func100(bswap_32big(0x6e33b860U), bswap_32big(0xbdce3be1U), bswap_32big(0xf8445360U),
                           bswap_32big(0xb9e72b5fU));
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
            r_rsip_func101(bswap_32big(0xd0b87a90U), bswap_32big(0x36e9f603U), bswap_32big(0x0ec0c70cU),
                           bswap_32big(0xb1352385U));
            r_rsip_func045();
            r_rsip_func023();
            r_rsip_subfunc009(bswap_32big(0x000000faU));
            r_rsip_func101(bswap_32big(0x7f6a114eU), bswap_32big(0xfc683683U), bswap_32big(0x4bc984edU),
                           bswap_32big(0x49b1c00aU));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xe50e3122U), bswap_32big(0x515208a0U), bswap_32big(0xb3c5d0f6U),
                           bswap_32big(0xfd22fc1eU));
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
            r_rsip_func100(bswap_32big(0x215d89abU), bswap_32big(0xf339407bU), bswap_32big(0xef5b431fU),
                           bswap_32big(0x9cbc5859U));
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
            r_rsip_func100(bswap_32big(0x6bc790d8U), bswap_32big(0x514d7745U), bswap_32big(0x86d31dcaU),
                           bswap_32big(0x6e22013aU));
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
            r_rsip_func100(bswap_32big(0x57aab7ecU), bswap_32big(0x0d31e134U), bswap_32big(0x19e32280U),
                           bswap_32big(0x56e28d31U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x387e35c2U),
                               bswap_32big(0x64c7f560U),
                               bswap_32big(0xedadd470U),
                               bswap_32big(0x3e520033U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x20bd2751U),
                               bswap_32big(0x48897f47U),
                               bswap_32big(0xc7236552U),
                               bswap_32big(0x2af16a9dU));
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
                r_rsip_func102(bswap_32big(0x6b7e71b8U),
                               bswap_32big(0x1072d87aU),
                               bswap_32big(0x85425c6eU),
                               bswap_32big(0x257af713U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
