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

void r_rsip_func080 (const uint32_t ARG1[], const uint32_t ARG2[], uint32_t ARG3[], uint32_t INST_DATA_SIZE)
{
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
    r_rsip_func100(bswap_32big(0xa1cb6d7bU),
                   bswap_32big(0x26811907U),
                   bswap_32big(0x798a14d9U),
                   bswap_32big(0x5d85f81aU));
    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x08000045U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG1[0]);
    WR1_ADDR(REG_1420H, &ARG1[1]);
    WR1_ADDR(REG_1420H, &ARG1[2]);
    WR1_ADDR(REG_1420H, &ARG1[3]);
    WR1_PROG(REG_1444H, 0x000000a1U);
    WR1_PROG(REG_1824H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000f080U));
    r_rsip_func101(bswap_32big(0x6402c7beU),
                   bswap_32big(0x54be5166U),
                   bswap_32big(0xb910c5a9U),
                   bswap_32big(0xa2cb2102U));
    r_rsip_func045();
    r_rsip_subfunc009(bswap_32big(0x0000f080U));
    r_rsip_func101(bswap_32big(0xd31677f1U),
                   bswap_32big(0xca47cc1cU),
                   bswap_32big(0x9cb769e8U),
                   bswap_32big(0xf134795aU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x380088a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xccc9861dU),
                   bswap_32big(0x01138551U),
                   bswap_32big(0x8dacf899U),
                   bswap_32big(0x99beac6aU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x4f4d3062U), bswap_32big(0x88857fd0U), bswap_32big(0xdbfac1efU),
                           bswap_32big(0x992302a7U));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 0]);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 1]);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 2]);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 3]);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_subfunc003(0x00810011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 4]);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 5]);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 6]);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 7]);
            r_rsip_func101(bswap_32big(0x46858d82U), bswap_32big(0xdb4e0fa8U), bswap_32big(0x6e8d5453U),
                           bswap_32big(0x08d5b284U));
        }

        r_rsip_func100(bswap_32big(0x5c58a21bU), bswap_32big(0x81307342U), bswap_32big(0xc2ac0b5dU),
                       bswap_32big(0x960ca871U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x49110054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 3]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 4]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 5]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 6]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 7]);
        r_rsip_func100(bswap_32big(0x5c89ce6eU), bswap_32big(0x03ad782cU), bswap_32big(0x5b4b4133U),
                       bswap_32big(0x71429ad6U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 8]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 9]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 10]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 11]);
        r_rsip_func101(bswap_32big(0x5fd73238U), bswap_32big(0xa1814625U), bswap_32big(0xbf868dbbU),
                       bswap_32big(0x1fca37f9U));
    }
    else
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x04c45ed3U), bswap_32big(0xc3660ac6U), bswap_32big(0x28721643U),
                           bswap_32big(0xa844221cU));
            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0xd900090dU);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 0]);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 1]);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 2]);
            WR1_ADDR(REG_1420H, &ARG2[iLoop + 3]);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe7008d05U);
            r_rsip_subfunc003(0x00810011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 4]);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 5]);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 6]);
            RD1_ADDR(REG_1420H, &ARG3[iLoop + 7]);
            r_rsip_func101(bswap_32big(0x1fa83527U), bswap_32big(0x873e6c3fU), bswap_32big(0x36184cbcU),
                           bswap_32big(0x95b102abU));
        }

        r_rsip_func100(bswap_32big(0x2e8e4f7cU), bswap_32big(0xd7533b80U), bswap_32big(0x8b38bf5dU),
                       bswap_32big(0xf51a8380U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x49110054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000003c1U);
        WR1_PROG(REG_1824H, 0xd900090dU);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 0]);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 1]);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 2]);
        WR1_ADDR(REG_1420H, &ARG2[iLoop + 3]);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00810011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 4]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 5]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 6]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 7]);
        r_rsip_func100(bswap_32big(0xc4d86a31U), bswap_32big(0x6e14a530U), bswap_32big(0x64c0859aU),
                       bswap_32big(0xeb2a7422U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 8]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 9]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 10]);
        RD1_ADDR(REG_1420H, &ARG3[iLoop + 11]);
        r_rsip_func101(bswap_32big(0x58d7a606U), bswap_32big(0x82d6833fU), bswap_32big(0xae3deaf8U),
                       bswap_32big(0x24989affU));
    }

    WR1_PROG(REG_1444H, 0x000003c1U);
    WR1_PROG(REG_1824H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &ARG2[INST_DATA_SIZE - 4]);
    WR1_ADDR(REG_1420H, &ARG2[INST_DATA_SIZE - 3]);
    WR1_ADDR(REG_1420H, &ARG2[INST_DATA_SIZE - 2]);
    WR1_ADDR(REG_1420H, &ARG2[INST_DATA_SIZE - 1]);
    WR1_PROG(REG_1600H, 0x00007c1cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
