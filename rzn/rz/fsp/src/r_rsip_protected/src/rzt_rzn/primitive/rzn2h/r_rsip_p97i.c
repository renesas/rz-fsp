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
    r_rsip_func100(bswap_32big(0x289733c1U),
                   bswap_32big(0xc16f465dU),
                   bswap_32big(0x86b7eb61U),
                   bswap_32big(0x8cebaa20U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7a0a48c5U), bswap_32big(0x12416b14U), bswap_32big(0x32e80024U),
                       bswap_32big(0x3bf31994U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x18738043U), bswap_32big(0x71727876U), bswap_32big(0x3755dcd7U),
                       bswap_32big(0x4cf6ef4fU));
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
        r_rsip_func101(bswap_32big(0x12b9e37aU), bswap_32big(0x8217cb43U), bswap_32big(0xd7dfa4e6U),
                       bswap_32big(0x2376e88cU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0165e166U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00009701U));
        r_rsip_func101(bswap_32big(0x39a9a016U), bswap_32big(0x11c64fa0U), bswap_32big(0x39e92725U),
                       bswap_32big(0x3c738fc5U));
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
        r_rsip_func100(bswap_32big(0x1f5f7c7fU), bswap_32big(0xb1f80eacU), bswap_32big(0x4f46fc32U),
                       bswap_32big(0xf08e3417U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xfb8bfa41U), bswap_32big(0xb03eb855U), bswap_32big(0xbb747af4U),
                           bswap_32big(0xe8774d02U));
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
            r_rsip_func100(bswap_32big(0x29068054U), bswap_32big(0x2fc49836U), bswap_32big(0xad6e6d89U),
                           bswap_32big(0xfb36e977U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1C04H, 0x00000011U);
                r_rsip_func101(bswap_32big(0xcad54fb5U),
                               bswap_32big(0xef0682bcU),
                               bswap_32big(0x671ba019U),
                               bswap_32big(0x805255ffU));
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00000031U);
                r_rsip_func101(bswap_32big(0x7711e24fU),
                               bswap_32big(0x0a249f88U),
                               bswap_32big(0x05789813U),
                               bswap_32big(0x57a4b383U));
            }

            r_rsip_func100(bswap_32big(0xf307e913U), bswap_32big(0x21835e04U), bswap_32big(0x2617e703U),
                           bswap_32big(0x4d0dcb80U));
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
            r_rsip_func101(bswap_32big(0x4a509718U), bswap_32big(0x987943ceU), bswap_32big(0xc520a388U),
                           bswap_32big(0xd3bc3ed4U));

            return RSIP_RET_PASS;
        }
    }
}
