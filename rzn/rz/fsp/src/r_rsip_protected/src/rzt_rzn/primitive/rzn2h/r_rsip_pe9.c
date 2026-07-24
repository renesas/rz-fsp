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

rsip_ret_t r_rsip_pe9 (const uint32_t InData_HashType[],
                       const uint32_t InData_Hash[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_FinishedLabel[],
                       uint32_t       OutData_VerifyData[])
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

    WR1_PROG(REG_1B00H, 0x00e90002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x1a37dd0fU),
                   bswap_32big(0x60bfbbf3U),
                   bswap_32big(0x4e6d5896U),
                   bswap_32big(0x208ae464U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1b1968e5U), bswap_32big(0x5ce06cfeU), bswap_32big(0xd4e049f5U),
                       bswap_32big(0xad1185f6U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_2000H, 0x00000001U);
        WR1_PROG(REG_2004H, 0x00000050U);
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
        r_rsip_subfunc009(bswap_32big(0x000000e9U));
        r_rsip_func101(bswap_32big(0x29cd9f10U), bswap_32big(0x5a20c646U), bswap_32big(0x5159541aU),
                       bswap_32big(0xe535a273U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01a5a796U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x000000e9U));
        r_rsip_func101(bswap_32big(0xbcbd130bU), bswap_32big(0x9d220b66U), bswap_32big(0xac11219eU),
                       bswap_32big(0xb3667999U));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x00000fc2U);
        WR1_PROG(REG_1A2CH, 0x40000300U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
            r_rsip_subfunc003(0x01420011U);
        }

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[20]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[21]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[22]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[23]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x98fe6966U), bswap_32big(0x6404002bU), bswap_32big(0xa8c7859dU),
                       bswap_32big(0x9e45fbf2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xbc008facU), bswap_32big(0x8c071d4eU), bswap_32big(0x5ee4f662U),
                           bswap_32big(0x4f814688U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2014H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2010H, 0x00000178U);
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x800100a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_FinishedLabel[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000ca5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x93356b8eU), bswap_32big(0x7bafa8e2U), bswap_32big(0xd8ba227aU),
                           bswap_32big(0x11867933U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1444H, 0x000002a7U);
                WR1_PROG(REG_1608H, 0x80830000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x636c6965U));
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x6e742066U));
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x696e6973U));
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x1fc440a8U),
                               bswap_32big(0xba04aa91U),
                               bswap_32big(0x6f36a160U),
                               bswap_32big(0x1f549d0fU));
            }
            else
            {
                WR1_PROG(REG_1444H, 0x000002a7U);
                WR1_PROG(REG_1608H, 0x80830000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x73657276U));
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x65722066U));
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x696e6973U));
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x45ef7ebbU),
                               bswap_32big(0x7d00167bU),
                               bswap_32big(0x54116bd6U),
                               bswap_32big(0x9ef84554U));
            }

            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Hash[0]);
            WR1_ADDR(REG_1420H, &InData_Hash[1]);
            WR1_ADDR(REG_1420H, &InData_Hash[2]);
            WR1_ADDR(REG_1420H, &InData_Hash[3]);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Hash[4]);
            WR1_ADDR(REG_1420H, &InData_Hash[5]);
            WR1_ADDR(REG_1420H, &InData_Hash[6]);
            WR1_ADDR(REG_1420H, &InData_Hash[7]);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000002cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b420U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00686564U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1608H, 0x80010040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420005U);
                WR1_PROG(REG_1600H, 0x01886c22U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003422U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1600H, 0x00086c21U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003c20U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_200CH, 0x00000001U);
            WAIT_STS(REG_2030H, 0U, 1U);
            WR1_PROG(REG_1608H, 0x818c0000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x01490031U);
            WAIT_STS(REG_2030H, 8U, 0U);
            WR1_PROG(REG_143CH, 0x00001600U);
            WAIT_STS(REG_2030H, 4U, 1U);
            WR1_PROG(REG_1600H, 0x00000800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80880000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03450021U);
            WR1_PROG(REG_2000H, 0x00000001U);
            WR1_PROG(REG_2004H, 0x00000050U);
            WR1_PROG(REG_2008H, 0x00000003U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2014H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x00000020U);
            WR1_PROG(REG_2010H, 0x00000278U);
            WR1_PROG(REG_200CH, 0x00000001U);
            WAIT_STS(REG_2030H, 0U, 1U);
            WR1_PROG(REG_1608H, 0x81940000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x01490051U);
            WAIT_STS(REG_2030H, 8U, 0U);
            WR1_PROG(REG_143CH, 0x00001600U);
            WAIT_STS(REG_2030H, 4U, 1U);
            r_rsip_func100(bswap_32big(0x42a2f75aU), bswap_32big(0x69f9546bU), bswap_32big(0x800ccbd6U),
                           bswap_32big(0xa2c54e25U));
            WR1_PROG(REG_1408H, 0x0000400eU);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_VerifyData[0]);
            RD1_ADDR(REG_1420H, &OutData_VerifyData[1]);
            RD1_ADDR(REG_1420H, &OutData_VerifyData[2]);
            r_rsip_func102(bswap_32big(0x44c6c3cbU), bswap_32big(0x2901723bU), bswap_32big(0x3099a41cU),
                           bswap_32big(0x4d5a893dU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
