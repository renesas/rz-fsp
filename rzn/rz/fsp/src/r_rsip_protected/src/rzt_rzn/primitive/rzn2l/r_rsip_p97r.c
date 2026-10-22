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
    r_rsip_func100(bswap_32big(0x97f41568U),
                   bswap_32big(0x97c547c4U),
                   bswap_32big(0xa2bdfb01U),
                   bswap_32big(0x629e9fe6U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x6d8e91bcU), bswap_32big(0xe44c2637U), bswap_32big(0x2b5c85b7U),
                       bswap_32big(0x003431f6U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WAIT_STS(REG_1C30H, 8U, 0U);
        WR1_PROG(REG_143CH, 0x00001c00U);
        r_rsip_func100(bswap_32big(0xacabe285U), bswap_32big(0x854eff7fU), bswap_32big(0x4951553bU),
                       bswap_32big(0x522a833dU));
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
        r_rsip_func101(bswap_32big(0xb93ebd12U), bswap_32big(0xc3891a24U), bswap_32big(0xec0ffaacU),
                       bswap_32big(0x8e7b3497U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01d82abeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00009702U));
        r_rsip_func101(bswap_32big(0x975d8432U), bswap_32big(0xb13358d2U), bswap_32big(0x910c2f1bU),
                       bswap_32big(0xf0e9d98dU));
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
        r_rsip_func100(bswap_32big(0x28d06facU), bswap_32big(0xb0e30f40U), bswap_32big(0x92796b5eU),
                       bswap_32big(0xc6a0334eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xb0f4c906U), bswap_32big(0xf46e4a83U), bswap_32big(0xba2a444aU),
                           bswap_32big(0x4c6fe34dU));
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
            r_rsip_func100(bswap_32big(0xba9ed308U), bswap_32big(0x8725b112U), bswap_32big(0x20ab3c33U),
                           bswap_32big(0xc63d6657U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1C04H, 0x00010011U);
                r_rsip_func101(bswap_32big(0xa748683cU),
                               bswap_32big(0xaf6325a7U),
                               bswap_32big(0x4c9683d8U),
                               bswap_32big(0xe95dd8f5U));
            }
            else
            {
                WR1_PROG(REG_1C04H, 0x00010031U);
                r_rsip_func101(bswap_32big(0xbabbd1d4U),
                               bswap_32big(0xe896f983U),
                               bswap_32big(0xbec2b3d8U),
                               bswap_32big(0xf92443ecU));
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
            r_rsip_func101(bswap_32big(0x589dea65U), bswap_32big(0x7317a33dU), bswap_32big(0x1f1e8342U),
                           bswap_32big(0x46ce169dU));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01bc6d1aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00009703U));
            r_rsip_func101(bswap_32big(0x6034c5e7U), bswap_32big(0x0b20d395U), bswap_32big(0x5a61525aU),
                           bswap_32big(0xbb6ad48cU));
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
            r_rsip_func100(bswap_32big(0x25d81226U), bswap_32big(0x9f248ab0U), bswap_32big(0xe9c5bbffU),
                           bswap_32big(0x6a37e3fcU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xc54a24a8U),
                               bswap_32big(0x9ecafed7U),
                               bswap_32big(0x8fc7ec03U),
                               bswap_32big(0x6add4661U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x7f96195cU),
                               bswap_32big(0xf8c98bcbU),
                               bswap_32big(0x9b26f134U),
                               bswap_32big(0x807b4b83U));
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
                r_rsip_func100(bswap_32big(0xaf133298U),
                               bswap_32big(0x9c3e6600U),
                               bswap_32big(0xeea58eacU),
                               bswap_32big(0xd647641dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x583a6639U),
                                   bswap_32big(0x4aab639fU),
                                   bswap_32big(0xed8aac08U),
                                   bswap_32big(0x81a5a145U));

                    return RSIP_RET_PASS_1;
                }
                else
                {
                    r_rsip_func101(bswap_32big(0xcc21967fU),
                                   bswap_32big(0x0f11c61fU),
                                   bswap_32big(0x3de2c346U),
                                   bswap_32big(0xf4fb680fU));

                    return RSIP_RET_PASS_2;
                }
            }
        }
    }
}
