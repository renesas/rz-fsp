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

rsip_ret_t r_rsip_pe5f (const uint32_t InData_Msg[],
                        const uint32_t InData_EncMsg[],
                        uint32_t       OutData_KDFInfo[],
                        const uint32_t MAX_CNT,
                        const uint32_t MAX_CNT2)
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
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    uint32_t max_cnt2 = bswap_32big(MAX_CNT2);
    WR1_ADDR(REG_1420H, &max_cnt2);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000d08U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xc831a0e7U),
                   bswap_32big(0x51ecf709U),
                   bswap_32big(0x0fcb5776U),
                   bswap_32big(0x81825cd2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e504U));
        r_rsip_func101(bswap_32big(0xe39e0975U), bswap_32big(0x2435e7a1U), bswap_32big(0x766d6366U),
                       bswap_32big(0x5c6171bdU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01799093U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e504U));
        r_rsip_func101(bswap_32big(0xb0f0e4f8U), bswap_32big(0x32395034U), bswap_32big(0x1d6e0f08U),
                       bswap_32big(0x1abe0993U));
        r_rsip_func046();
        WAIT_STS(REG_2030H, 0U, 1U);
        r_rsip_func100(bswap_32big(0x6ad4025aU), bswap_32big(0xa28caedeU), bswap_32big(0x1d80616aU),
                       bswap_32big(0xa249bfbfU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x81010100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        OFS_ADR = S_RAM[0];
        WR1_PROG(REG_1600H, 0x0000a900U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00026908U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3800a900U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x3a912720U), bswap_32big(0x91149d41U), bswap_32big(0x9dac2d22U),
                       bswap_32big(0x98241ba2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0] - 12; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xf7008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
                r_rsip_subfunc003(0x01420011U);
                WR1_PROG(REG_1600H, 0x00002d20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xb4eb23feU),
                               bswap_32big(0x211811c3U),
                               bswap_32big(0xa15e00c9U),
                               bswap_32big(0xb57fce8bU));
            }

            WR1_PROG(REG_1600H, 0x000037e8U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000033e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000be9U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
            r_rsip_subfunc003(0x01420005U);
            r_rsip_subfunc003(0x0002000dU);
            iLoop = iLoop + 4;
            r_rsip_func101(bswap_32big(0x307806d2U), bswap_32big(0x8c421cebU), bswap_32big(0x6d1a4e3dU),
                           bswap_32big(0xc49b5dbfU));
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0] - 8; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xf7008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
                r_rsip_subfunc003(0x01420011U);
                WR1_PROG(REG_1600H, 0x00002d20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x6950ffeaU),
                               bswap_32big(0x4af22f61U),
                               bswap_32big(0x0e5422baU),
                               bswap_32big(0xcb793a77U));
            }

            WR1_PROG(REG_1600H, 0x38000909U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2e56ebc5U), bswap_32big(0x5b3e4761U), bswap_32big(0xd4c72d95U),
                           bswap_32big(0xbe67e70cU));
        }

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 3]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 2]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 1]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0xf68da42dU), bswap_32big(0x84d001e2U), bswap_32big(0x215ea274U),
                       bswap_32big(0x7c4ec784U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x3dc96a5dU), bswap_32big(0x54cc7663U), bswap_32big(0x372ea08dU),
                           bswap_32big(0x77077b26U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func101(bswap_32big(0xd2767adaU), bswap_32big(0x4aabf777U), bswap_32big(0x62156fc8U),
                           bswap_32big(0x5b6ed9abU));
        }
    }
    else
    {
        r_rsip_func101(bswap_32big(0xdc41a8abU), bswap_32big(0x8f052b19U), bswap_32big(0x575e6644U),
                       bswap_32big(0x3c7c6102U));
    }

    WAIT_STS(REG_2030H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020064U);
    for (iLoop = 0; iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001600U);
    WAIT_STS(REG_2030H, 4U, 1U);
    r_rsip_func100(bswap_32big(0x9ec41f6eU),
                   bswap_32big(0x106b5223U),
                   bswap_32big(0x622ff9aeU),
                   bswap_32big(0xff64fe4eU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000e505U));
    r_rsip_func101(bswap_32big(0x7976aee2U),
                   bswap_32big(0x34fa921eU),
                   bswap_32big(0x6fd26609U),
                   bswap_32big(0xe080b4c5U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01799093U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000e505U));
    r_rsip_func101(bswap_32big(0x4dc995ddU),
                   bswap_32big(0x6181baa2U),
                   bswap_32big(0x789f068bU),
                   bswap_32big(0x464a4862U));
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
    r_rsip_func100(bswap_32big(0xa2c75675U),
                   bswap_32big(0xce7429f7U),
                   bswap_32big(0xc27db033U),
                   bswap_32big(0xeb93967fU));
    WR1_PROG(REG_1608H, 0x810101e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0x678aa42eU), bswap_32big(0xf4857a77U), bswap_32big(0x792c316cU),
                       bswap_32big(0x0cfa1627U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00850011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xcb41c490U), bswap_32big(0x8ffccb65U), bswap_32big(0x0ab6f0c6U),
                       bswap_32big(0xdb90c791U));
    }

    WR1_PROG(REG_1600H, 0x380008efU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x5019796bU),
                   bswap_32big(0x15e98c13U),
                   bswap_32big(0x1f3d7854U),
                   bswap_32big(0xf82ac36bU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 4]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 5]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 6]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 7]);
    r_rsip_func100(bswap_32big(0x0ea7848aU),
                   bswap_32big(0x31b5003fU),
                   bswap_32big(0xe8345105U),
                   bswap_32big(0xb3372490U));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[3]);
    r_rsip_func102(bswap_32big(0x9bfc47deU),
                   bswap_32big(0x04627097U),
                   bswap_32big(0x7c8b81a7U),
                   bswap_32big(0xc8c9843fU));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
