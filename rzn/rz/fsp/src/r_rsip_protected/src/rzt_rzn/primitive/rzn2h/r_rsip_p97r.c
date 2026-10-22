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
        WAIT_STS(REG_1C30H, 8U, 0U);
        WR1_PROG(REG_143CH, 0x00001c00U);
        r_rsip_func100(bswap_32big(0x8448934dU), bswap_32big(0x7bd6e8e6U), bswap_32big(0x3d33c1d8U),
                       bswap_32big(0x8f9cf45aU));
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
        r_rsip_func101(bswap_32big(0xc6d8988fU), bswap_32big(0xe53022f4U), bswap_32big(0x36254b51U),
                       bswap_32big(0xe049c4abU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0165e166U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00009702U));
        r_rsip_func101(bswap_32big(0x980cea21U), bswap_32big(0x699270c8U), bswap_32big(0x323164f1U),
                       bswap_32big(0x7f414730U));
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
        r_rsip_func100(bswap_32big(0x806f9a7aU), bswap_32big(0x7835eecdU), bswap_32big(0xe9fb4e59U),
                       bswap_32big(0x484349bbU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x3e8a0708U), bswap_32big(0x583e46e1U), bswap_32big(0x3d9be5afU),
                           bswap_32big(0x6aa5a346U));
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
            r_rsip_func100(bswap_32big(0x61424a4cU), bswap_32big(0x1e782de5U), bswap_32big(0x8b097c42U),
                           bswap_32big(0x986cdde4U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1C04H, 0x00010011U);
                r_rsip_func101(bswap_32big(0x9bb080e8U),
                               bswap_32big(0xd7f6ba00U),
                               bswap_32big(0x658e8baeU),
                               bswap_32big(0xa3a298d8U));
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00010031U);
                r_rsip_func101(bswap_32big(0x84a1e85eU),
                               bswap_32big(0x010eb676U),
                               bswap_32big(0x3bfbe80eU),
                               bswap_32big(0xea245c9dU));
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
            r_rsip_func101(bswap_32big(0x80995496U), bswap_32big(0xdd023b8cU), bswap_32big(0x4ea9fecaU),
                           bswap_32big(0x526a3efeU));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01ec40d6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00009703U));
            r_rsip_func101(bswap_32big(0x85589672U), bswap_32big(0xdd74afa5U), bswap_32big(0x5b0b5c93U),
                           bswap_32big(0x02fc6d43U));
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
            r_rsip_func100(bswap_32big(0xf65f70a4U), bswap_32big(0x10a84398U), bswap_32big(0xe7543b73U),
                           bswap_32big(0x7d2ef8d1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x6b1a0409U),
                               bswap_32big(0xb08e590cU),
                               bswap_32big(0x8e262a40U),
                               bswap_32big(0x5db7be14U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xe6efbbc6U),
                               bswap_32big(0x384f7e67U),
                               bswap_32big(0xb5b5e6bfU),
                               bswap_32big(0x4fcc37e2U));
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
                r_rsip_func100(bswap_32big(0xe178302eU),
                               bswap_32big(0xe72c88feU),
                               bswap_32big(0x7459369cU),
                               bswap_32big(0x2496994aU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x786f985dU),
                                   bswap_32big(0x990d9703U),
                                   bswap_32big(0x5fd9a23eU),
                                   bswap_32big(0xeb633285U));

                    return RSIP_RET_PASS_1;
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xec4c34e3U),
                                   bswap_32big(0xef8d2109U),
                                   bswap_32big(0x832c6a0aU),
                                   bswap_32big(0x4b12fa20U));

                    return RSIP_RET_PASS_2;
                }
            }
        }
    }
}
