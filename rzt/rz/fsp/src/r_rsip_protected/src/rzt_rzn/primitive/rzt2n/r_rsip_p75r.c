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

rsip_ret_t r_rsip_p75r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_HashType[],
                        const uint32_t InData_State[],
                        uint32_t       KEY_INDEX_SIZE)
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00750002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008880U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_1600H, 0x38008880U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0x48ccab07U),
                   bswap_32big(0xbd645b38U),
                   bswap_32big(0x35e2cba8U),
                   bswap_32big(0xa50e2d1bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xda0a25d6U), bswap_32big(0x8d6db141U), bswap_32big(0x2ee6b670U),
                       bswap_32big(0x62de5facU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x39161f55U), bswap_32big(0x0a895ae4U), bswap_32big(0x133e9441U),
                       bswap_32big(0xb0f5f867U));
        WR1_PROG(REG_1600H, 0x3420a880U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000007U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000b480U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000006U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01db6812U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2004H, 0x00001000U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x60451ad4U), bswap_32big(0x0984e504U), bswap_32big(0xe1273f71U),
                           bswap_32big(0x4da77a7aU));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01954defU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2004H, 0x00001040U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc3d9d311U), bswap_32big(0x1bbe26f2U), bswap_32big(0x3dd276c1U),
                           bswap_32big(0x0bc56d00U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01394e42U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2004H, 0x00001050U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6dba956eU), bswap_32big(0x47d1ac04U), bswap_32big(0xf01a8adbU),
                           bswap_32big(0xc4fb9f5fU));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x014b49a1U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2004H, 0x000010a0U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xdb1d540dU), bswap_32big(0xdbcbad16U), bswap_32big(0x3acafd40U),
                           bswap_32big(0xfa642f0dU));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01d9e28cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_2004H, 0x000010b0U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x1a332adcU), bswap_32big(0xa68168f2U), bswap_32big(0x2bba44a2U),
                           bswap_32big(0xa9b9c26bU));
        }

        WR1_PROG(REG_2008H, 0x00000003U);
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00007502U));
        r_rsip_func101(bswap_32big(0xd3950418U), bswap_32big(0x751c5438U), bswap_32big(0x4b0db10cU),
                       bswap_32big(0x34f7691bU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x000034e5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00007502U));
        r_rsip_func101(bswap_32big(0x394fa9c3U), bswap_32big(0x1e50d97dU), bswap_32big(0xbf263c2eU),
                       bswap_32big(0x2d3a661fU));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1600H, 0x000008e7U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < KEY_INDEX_SIZE - 8; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
            r_rsip_subfunc003(0x01420011U);
            WR1_PROG(REG_1600H, 0x0000a4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x1ff11f03U), bswap_32big(0x61c9d5edU), bswap_32big(0xf7077a6bU),
                           bswap_32big(0x4cc22219U));
        }

        WR1_PROG(REG_1600H, 0x380008e6U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x017e5db6U), bswap_32big(0x12f0e85aU), bswap_32big(0xdbef01caU),
                       bswap_32big(0x00f08855U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xc64de013U), bswap_32big(0x9b1b41feU), bswap_32big(0xb5a23b68U),
                           bswap_32big(0x14d3ecfaU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2014H, &InData_State[18]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_2010H, &InData_State[19]);
            for (iLoop = 0; iLoop < 18; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_2028H, &InData_State[iLoop + 0]);
            }

            r_rsip_func101(bswap_32big(0xe9664c03U), bswap_32big(0x79f86b5eU), bswap_32big(0x6f950889U),
                           bswap_32big(0x314a4a69U));

            return RSIP_RET_PASS;
        }
    }
}
