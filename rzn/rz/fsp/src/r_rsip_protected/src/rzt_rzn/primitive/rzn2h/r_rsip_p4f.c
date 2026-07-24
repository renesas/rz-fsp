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
    r_rsip_func101(bswap_32big(0x8ea74d86U),
                   bswap_32big(0x4290792bU),
                   bswap_32big(0xaaf4f5f9U),
                   bswap_32big(0x9860d71bU));
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
    r_rsip_func101(bswap_32big(0x73bd2ae9U),
                   bswap_32big(0xeb1ecc2dU),
                   bswap_32big(0x64f4ba4dU),
                   bswap_32big(0x18a279b5U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01640a92U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004f01U));
    r_rsip_func101(bswap_32big(0x4da40e29U),
                   bswap_32big(0x07f40d70U),
                   bswap_32big(0x968762bcU),
                   bswap_32big(0xb689a733U));
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
    r_rsip_func100(bswap_32big(0x009c1a9aU),
                   bswap_32big(0x1e645a61U),
                   bswap_32big(0x02b131caU),
                   bswap_32big(0x431f631fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7b7aab3aU), bswap_32big(0x7bfe26abU), bswap_32big(0xdbc40943U),
                       bswap_32big(0xde36c4e8U));
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
        r_rsip_func100(bswap_32big(0x21d372b2U), bswap_32big(0xae62331fU), bswap_32big(0x7c650e6dU),
                       bswap_32big(0x91a99ee4U));
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
            r_rsip_func100(bswap_32big(0x7225b103U), bswap_32big(0x0297b2f7U), bswap_32big(0xe4f8527cU),
                           bswap_32big(0x47de05e0U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x1142ca3cU),
                               bswap_32big(0xd1caf14aU),
                               bswap_32big(0xeb4271abU),
                               bswap_32big(0x856443c6U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xdff43e5dU),
                               bswap_32big(0x056f7a79U),
                               bswap_32big(0x04d99c20U),
                               bswap_32big(0x1271c481U));
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
            r_rsip_func101(bswap_32big(0x72639c10U), bswap_32big(0x31043520U), bswap_32big(0xf77f953cU),
                           bswap_32big(0x8c7b89d4U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0122f7d5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00004f02U));
            r_rsip_func101(bswap_32big(0x0d6f3a6aU), bswap_32big(0x16679a13U), bswap_32big(0xf13fb178U),
                           bswap_32big(0x53d7e1a3U));
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
            r_rsip_func100(bswap_32big(0xa1b5acd6U), bswap_32big(0xc054b485U), bswap_32big(0xbda7bf57U),
                           bswap_32big(0x3e9c3e51U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x58201d21U),
                               bswap_32big(0x4a1cf4acU),
                               bswap_32big(0x986b0bd5U),
                               bswap_32big(0x349bcd91U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x1a41094eU),
                               bswap_32big(0x1ca2b837U),
                               bswap_32big(0x2dc27852U),
                               bswap_32big(0x47919bddU));
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
        r_rsip_func100(bswap_32big(0xc587cfe5U), bswap_32big(0x5ce793eeU), bswap_32big(0x35a1be6dU),
                       bswap_32big(0xb0ada9b6U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x823da862U), bswap_32big(0x2b2b259cU), bswap_32big(0x2d6991f4U),
                           bswap_32big(0x5f70abbbU));
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
            r_rsip_func101(bswap_32big(0xecd68dfaU), bswap_32big(0xc0c22401U), bswap_32big(0x49e2ac75U),
                           bswap_32big(0xb0c4bbccU));
            r_rsip_func072();
            r_rsip_func100(bswap_32big(0x1a4bd96dU), bswap_32big(0xeaf467e9U), bswap_32big(0xc03859aeU),
                           bswap_32big(0x2d95da52U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x4d005552U),
                               bswap_32big(0xe0fe305bU),
                               bswap_32big(0x5c127e3bU),
                               bswap_32big(0x13a3db9eU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xda24eac1U),
                               bswap_32big(0x5e7fcc68U),
                               bswap_32big(0xf1989b61U),
                               bswap_32big(0x90856adaU));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00004f03U));
                r_rsip_func101(bswap_32big(0x93d0e31fU),
                               bswap_32big(0x126b0c94U),
                               bswap_32big(0xc16add15U),
                               bswap_32big(0x91d93df5U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01893e93U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00004f03U));
                r_rsip_func101(bswap_32big(0x34621ee0U),
                               bswap_32big(0x74386528U),
                               bswap_32big(0x0cbd4197U),
                               bswap_32big(0xd7c180e6U));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0xe2a145f5U),
                               bswap_32big(0x45d3d309U),
                               bswap_32big(0x0bd8d733U),
                               bswap_32big(0xf78148c5U));
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

                r_rsip_func100(bswap_32big(0x07cc268eU),
                               bswap_32big(0x679b0cdbU),
                               bswap_32big(0x8f965307U),
                               bswap_32big(0xf742020cU));
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
                r_rsip_func100(bswap_32big(0x043f31a2U),
                               bswap_32big(0x4f9fbfb2U),
                               bswap_32big(0x3f9b5e72U),
                               bswap_32big(0x5a2a6262U));
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
                r_rsip_func100(bswap_32big(0x6ab617deU),
                               bswap_32big(0x556b36b9U),
                               bswap_32big(0x9b82b540U),
                               bswap_32big(0xa31aae10U));
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
                r_rsip_func102(bswap_32big(0x12c3a252U),
                               bswap_32big(0xb44ce8f6U),
                               bswap_32big(0x7589c3b1U),
                               bswap_32big(0xace10e7bU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
