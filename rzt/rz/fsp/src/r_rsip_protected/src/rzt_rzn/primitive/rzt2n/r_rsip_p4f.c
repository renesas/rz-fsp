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

rsip_ret_t r_rsip_p4f (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
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

    WR1_PROG(REG_1B00H, 0x004f0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    r_rsip_subfunc009(bswap_32big(0x0000004fU));
    r_rsip_func101(bswap_32big(0x866037e2U),
                   bswap_32big(0xfe88527bU),
                   bswap_32big(0x52afb28eU),
                   bswap_32big(0xd756eabdU));
    r_rsip_func074(InData_DomainParam);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x09090010U);
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
    r_rsip_subfunc009(bswap_32big(0x00004f01U));
    r_rsip_func101(bswap_32big(0xab1f1f5bU),
                   bswap_32big(0x19073de7U),
                   bswap_32big(0xca0b8de7U),
                   bswap_32big(0x9ad7a378U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x010851a5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004f01U));
    r_rsip_func101(bswap_32big(0xa150387dU),
                   bswap_32big(0x9b5436e3U),
                   bswap_32big(0x5296a82fU),
                   bswap_32big(0x6c331baeU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000013c2U);
    WR1_PROG(REG_1A2CH, 0x40000400U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WR1_PROG(REG_1404H, 0x12f00000U);
    for (iLoop = 0; iLoop < 20; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        r_rsip_subfunc003(0x00c20011U);
    }

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
    r_rsip_func100(bswap_32big(0xa22eef2eU),
                   bswap_32big(0x4b4aafabU),
                   bswap_32big(0x63029172U),
                   bswap_32big(0x8a0b7f75U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4e7fedc3U), bswap_32big(0x5ae38b40U), bswap_32big(0x6f521413U),
                       bswap_32big(0xcc8ebb48U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000f7bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x0bec16d4U), bswap_32big(0xd1930be3U), bswap_32big(0x00a165d7U),
                       bswap_32big(0x04129482U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000027c7U);
            WR1_PROG(REG_1608H, 0x80a8001eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 40; iLoop = iLoop + 1)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 0]);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bbdU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 2; iLoop = iLoop + 1)
            {
                for (jLoop = 0; jLoop < 3; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x0000381eU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x38000c00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x100053fdU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002fa0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x0000a7c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000004U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1600H, 0x0000381eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38008c00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xfffffe00U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x100053fdU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002fa0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b7c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000050U);
                WR1_PROG(REG_1458H, 0x00000000U);
            }

            WR1_PROG(REG_1600H, 0x38008be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000000ffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0xcc6f9550U), bswap_32big(0x62e0746aU), bswap_32big(0xbb28993dU),
                           bswap_32big(0x5f67dd93U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x1a4db79aU),
                               bswap_32big(0xab9cacaaU),
                               bswap_32big(0xd30e37fcU),
                               bswap_32big(0xedd4ca10U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x395b2bf1U),
                               bswap_32big(0x24ba27d4U),
                               bswap_32big(0xe92fec48U),
                               bswap_32big(0xfa249455U));
            }
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00004f02U));
            r_rsip_func101(bswap_32big(0x6911588cU), bswap_32big(0xd61df1fcU), bswap_32big(0x6c4b4bc0U),
                           bswap_32big(0x1053a384U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0103c0b8U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00004f02U));
            r_rsip_func101(bswap_32big(0x75fc8d2cU), bswap_32big(0x1ad5f0aeU), bswap_32big(0xf0831affU),
                           bswap_32big(0x828e60f9U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000023c2U);
            WR1_PROG(REG_1A2CH, 0x40000800U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            WR1_PROG(REG_1600H, 0x00000821U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80a80001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 20; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
                r_rsip_subfunc003(0x03420011U);
            }

            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 24]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 25]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 26]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 27]);
                r_rsip_subfunc003(0x03420011U);
            }

            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[40]);
            WR1_ADDR(REG_1420H, &InData_PubKey[41]);
            WR1_ADDR(REG_1420H, &InData_PubKey[42]);
            WR1_ADDR(REG_1420H, &InData_PubKey[43]);
            r_rsip_subfunc003(0x03420011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[44]);
            WR1_ADDR(REG_1420H, &InData_PubKey[45]);
            WR1_ADDR(REG_1420H, &InData_PubKey[46]);
            WR1_ADDR(REG_1420H, &InData_PubKey[47]);
            r_rsip_func100(bswap_32big(0xac280ea1U), bswap_32big(0x497d6f38U), bswap_32big(0x420b88fdU),
                           bswap_32big(0xf7006091U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xf682a76aU),
                               bswap_32big(0x9b3f4ad2U),
                               bswap_32big(0x76ca10e2U),
                               bswap_32big(0xd8eda9c5U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x08d555e2U),
                               bswap_32big(0xf7776f96U),
                               bswap_32big(0x84fa281cU),
                               bswap_32big(0x463fb543U));
            }
        }

        WR1_PROG(REG_1600H, 0x00000bdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81a8001eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10c00000U);
        r_rsip_subfunc003(0x00c90051U);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_subfunc003(0x00c90051U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x09090002U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x09090002U);
        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x09090001U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000890U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x09090005U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x09090002U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x000008e0U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x09090005U);
        WR1_PROG(REG_1014H, 0x00000200U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x09090001U);
        r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x00000250U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000110U, 0x00000250U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x13934175U), bswap_32big(0xb9940efbU), bswap_32big(0xf1a3e050U),
                       bswap_32big(0x82e62eadU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x1cf0b173U), bswap_32big(0x7a82d40cU), bswap_32big(0xddc97818U),
                           bswap_32big(0xf9e2dabcU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10c80000U);
            r_rsip_subfunc003(0x00c00049U);
            r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000200U, 0x09090009U);
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x000001b0U, 0x09090009U);
            r_rsip_subfunc009(bswap_32big(0x0000004fU));
            r_rsip_func101(bswap_32big(0x18d1e0a5U), bswap_32big(0x484c54faU), bswap_32big(0x09dc40a9U),
                           bswap_32big(0xad927f30U));
            r_rsip_func072();
            r_rsip_func100(bswap_32big(0xcf5a8019U), bswap_32big(0xbf58de98U), bswap_32big(0xd37770f4U),
                           bswap_32big(0x52aa48bfU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x1433fbc1U),
                               bswap_32big(0xcddc1a7aU),
                               bswap_32big(0xfc296fc1U),
                               bswap_32big(0x6a228fe4U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xf7ce4406U),
                               bswap_32big(0xc2128783U),
                               bswap_32big(0x84d8c69eU),
                               bswap_32big(0x5043901cU));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00004f03U));
                r_rsip_func101(bswap_32big(0x9fa773f9U),
                               bswap_32big(0x039eddb3U),
                               bswap_32big(0x8b69ff16U),
                               bswap_32big(0x29ddf1e7U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x017d11fdU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00004f03U));
                r_rsip_func101(bswap_32big(0xc75c8529U),
                               bswap_32big(0xd73e43bdU),
                               bswap_32big(0x30279d49U),
                               bswap_32big(0x6ea6f3dfU));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0xec5cbe92U),
                               bswap_32big(0x665da0ccU),
                               bswap_32big(0xa6d0d864U),
                               bswap_32big(0x2fd0df82U));
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12580000U);
                r_rsip_subfunc003(0x00800009U);
                r_rsip_subfunc003(0x00830029U);
                WR1_PROG(REG_1408H, 0x00002032U);
                for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 7]);
                }

                r_rsip_func100(bswap_32big(0x129db796U),
                               bswap_32big(0x6d97c367U),
                               bswap_32big(0x506c3b5dU),
                               bswap_32big(0xade2b8e6U));
                WR1_PROG(REG_1A2CH, 0x40000100U);
                WR1_PROG(REG_1A24H, 0xe7008d07U);
                r_rsip_subfunc003(0x00830021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 4]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 6]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 7]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 8]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 9]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 10]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 11]);
                r_rsip_func100(bswap_32big(0xc78c67e6U),
                               bswap_32big(0xcf42fc99U),
                               bswap_32big(0x06ee3023U),
                               bswap_32big(0x2a59b3daU));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_subfunc003(0x00820011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 12]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 13]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 14]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 15]);
                r_rsip_func100(bswap_32big(0xb203688cU),
                               bswap_32big(0xfee8a354U),
                               bswap_32big(0x003b5d4aU),
                               bswap_32big(0xaa16eb20U));
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[3]);
                r_rsip_func102(bswap_32big(0x7b38ba22U),
                               bswap_32big(0x00897f96U),
                               bswap_32big(0x257cfdfbU),
                               bswap_32big(0x97e25bc3U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
