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

rsip_ret_t r_rsip_p97r (const uint32_t InData_KeyIndex[],
                        const uint32_t InData_Cmd[],
                        const uint32_t InData_Nonce[],
                        const uint32_t InData_State[])
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
    WR1_ADDR(REG_1420H, &InData_State[1]);
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
        WAIT_STS(REG_1C30H, 8U, 0U);
        WR1_PROG(REG_143CH, 0x00001c00U);
        r_rsip_func100(bswap_32big(0xc2330df8U), bswap_32big(0x72bb7d83U), bswap_32big(0xc323006fU),
                       bswap_32big(0xfcc0e740U));
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
        r_rsip_subfunc009(bswap_32big(0x00009702U));
        r_rsip_func101(bswap_32big(0x5b53593aU), bswap_32big(0xf3f27c1bU), bswap_32big(0x7aec7e92U),
                       bswap_32big(0x4679358dU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01d0ad24U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00009702U));
        r_rsip_func101(bswap_32big(0xcb5e7ecdU), bswap_32big(0xd478cbc5U), bswap_32big(0xdd038910U),
                       bswap_32big(0xaacfba99U));
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
        r_rsip_func100(bswap_32big(0xc1f5483eU), bswap_32big(0x45e4a1cfU), bswap_32big(0x40991c11U),
                       bswap_32big(0x65f3141cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xa06e8d92U), bswap_32big(0xe21385c3U), bswap_32big(0x2d52c75aU),
                           bswap_32big(0xcfd8294bU));
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
            WR1_PROG(REG_1C04H, 0x00010011U);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C10H, &InData_State[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C14H, &InData_State[2]);
            WR1_PROG(REG_1C04H, 0x00010010U);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C08H, &InData_State[0]);
            WR1_PROG(REG_1600H, 0x38000c84U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x72258d83U), bswap_32big(0xc302fec7U), bswap_32big(0x547d4962U),
                           bswap_32big(0xfb36172dU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1C04H, 0x00010011U);
                r_rsip_func101(bswap_32big(0xbb1eb94bU),
                               bswap_32big(0x5ce3b7beU),
                               bswap_32big(0x9118fc08U),
                               bswap_32big(0xff6513f2U));
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00010031U);
                r_rsip_func101(bswap_32big(0xff7c74e9U),
                               bswap_32big(0xa2e1648dU),
                               bswap_32big(0x4db18764U),
                               bswap_32big(0x185b83e2U));
            }

            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C0CH, &InData_Nonce[0]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C0CH, &InData_Nonce[1]);
            WR1_PROG(REG_1444H, 0x00000040U);
            WR1_ADDR(REG_1C0CH, &InData_Nonce[2]);
            for (iLoop = 3; iLoop < 10; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1444H, 0x00000040U);
                WR1_ADDR(REG_1C28H, &InData_State[iLoop + 0]);
            }

            r_rsip_subfunc009(bswap_32big(0x00009703U));
            r_rsip_func101(bswap_32big(0x9220cfbdU), bswap_32big(0x973c984dU), bswap_32big(0x43bad6a6U),
                           bswap_32big(0x8f911d13U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01db5943U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00009703U));
            r_rsip_func101(bswap_32big(0xcf0eae98U), bswap_32big(0xb322b204U), bswap_32big(0xcaaadc8fU),
                           bswap_32big(0x73177063U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000000c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8009104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_State[14]);
            WR1_PROG(REG_1608H, 0x800100a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420005U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_State[15]);
            WR1_ADDR(REG_1420H, &InData_State[16]);
            WR1_ADDR(REG_1420H, &InData_State[17]);
            WR1_ADDR(REG_1420H, &InData_State[18]);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_subfunc003(0x00820011U);
            r_rsip_func100(bswap_32big(0x5278f7abU), bswap_32big(0x43f62091U), bswap_32big(0x2c73b525U),
                           bswap_32big(0xb114cd62U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x187d3fe9U),
                               bswap_32big(0x26696ff4U),
                               bswap_32big(0xc8c69791U),
                               bswap_32big(0xa692c9afU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x25358efeU),
                               bswap_32big(0x325201bdU),
                               bswap_32big(0xaaf25486U),
                               bswap_32big(0x5cf0a4f6U));
                WR1_PROG(REG_1608H, 0x810100a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005006U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
                WR1_PROG(REG_1600H, 0x380088a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0xf702ff20U),
                               bswap_32big(0xbf78473aU),
                               bswap_32big(0xe54d1d6aU),
                               bswap_32big(0x574ca43cU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x639b86bbU),
                                   bswap_32big(0x52c7e517U),
                                   bswap_32big(0xb39f5469U),
                                   bswap_32big(0x2bc57915U));

                    return RSIP_RET_PASS_1;
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xf82fc41cU),
                                   bswap_32big(0xc40b59c0U),
                                   bswap_32big(0x002d9f0bU),
                                   bswap_32big(0x25136285U));

                    return RSIP_RET_PASS_2;
                }
            }
        }
    }
}
