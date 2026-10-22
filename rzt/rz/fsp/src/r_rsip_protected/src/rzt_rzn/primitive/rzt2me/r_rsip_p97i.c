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

rsip_ret_t r_rsip_p97i (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_Nonce[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataALen[])
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

    WR1_PROG(REG_1B00H, 0x00970002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_TextLen[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xf30ad5afU),
                   bswap_32big(0x4b6d24ddU),
                   bswap_32big(0x65dc8a50U),
                   bswap_32big(0xe5411250U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1b53ad57U), bswap_32big(0x764599b4U), bswap_32big(0x916887d5U),
                       bswap_32big(0x2d07e211U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x2c27beb7U), bswap_32big(0x8d9b06b1U), bswap_32big(0x8efdb29dU),
                       bswap_32big(0xeb08dd0bU));
        WR1_PROG(REG_1C00H, 0x00000001U);
        WR1_PROG(REG_1C04H, 0x00001001U);
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
        r_rsip_subfunc009(bswap_32big(0x00009701U));
        r_rsip_func101(bswap_32big(0xdddbca63U), bswap_32big(0x7b67825aU), bswap_32big(0x0daa45d9U),
                       bswap_32big(0x65aedc54U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01d0ad24U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00009701U));
        r_rsip_func101(bswap_32big(0x6ce924baU), bswap_32big(0xad1453abU), bswap_32big(0x6af324c8U),
                       bswap_32big(0xd1ea676aU));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x000007c2U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
        r_rsip_subfunc003(0x01c20021U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[12]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[13]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[14]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[15]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x16c65029U), bswap_32big(0xb5e4ae01U), bswap_32big(0xd18cb3cdU),
                       bswap_32big(0xce87a07dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xaa07cdb5U), bswap_32big(0x542f2b1aU), bswap_32big(0x540a1f94U),
                           bswap_32big(0xf8dc8d2eU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000c7U);
            WR1_PROG(REG_1608H, 0x80010080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Cmd[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000c84U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x62097295U), bswap_32big(0x92ac5cd0U), bswap_32big(0x9d87d57dU),
                           bswap_32big(0x1b7d541eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1C04H, 0x00000011U);
                r_rsip_func101(bswap_32big(0x662186d5U),
                               bswap_32big(0xa5e1e38eU),
                               bswap_32big(0x7d2ca116U),
                               bswap_32big(0x700ea1adU));
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00000031U);
                r_rsip_func101(bswap_32big(0xd285661fU),
                               bswap_32big(0xec75f269U),
                               bswap_32big(0x6d717913U),
                               bswap_32big(0x6feb1b9eU));
            }

            r_rsip_func100(bswap_32big(0x08b2a54bU), bswap_32big(0x46ca55a4U), bswap_32big(0x851d491fU),
                           bswap_32big(0x74749f13U));
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C10H, &InData_TextLen[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C14H, &InData_DataALen[0]);
            WR1_PROG(REG_1C08H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C0CH, &InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C0CH, &InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C0CH, &InData_Nonce[2]);
            WAIT_STS(REG_1C30H, 0U, 1U);
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x810100a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            r_rsip_func101(bswap_32big(0x849231d7U), bswap_32big(0x914859e7U), bswap_32big(0x7b42a95dU),
                           bswap_32big(0x45e147e9U));

            return RSIP_RET_PASS;
        }
    }
}
