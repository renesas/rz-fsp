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
    r_rsip_func100(bswap_32big(0x386c36e1U),
                   bswap_32big(0x7fbcd5fdU),
                   bswap_32big(0x6c7acc0fU),
                   bswap_32big(0x363c3596U));
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
    r_rsip_func101(bswap_32big(0x6e1c4467U),
                   bswap_32big(0x2498f8ddU),
                   bswap_32big(0x92892204U),
                   bswap_32big(0x842957efU));
    r_rsip_func045();
    r_rsip_subfunc009(bswap_32big(0x0000f080U));
    r_rsip_func101(bswap_32big(0x30ebda02U),
                   bswap_32big(0x1826ce96U),
                   bswap_32big(0x210643c3U),
                   bswap_32big(0x1e45ead9U));
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
    r_rsip_func100(bswap_32big(0x8a987f04U),
                   bswap_32big(0x82c7fef3U),
                   bswap_32big(0x1cbefcf4U),
                   bswap_32big(0x5f162caaU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0xde93eb20U), bswap_32big(0x2364dcf7U), bswap_32big(0xd2b4cccdU),
                           bswap_32big(0x321546d1U));
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
            r_rsip_func101(bswap_32big(0x61090705U), bswap_32big(0x81eb148fU), bswap_32big(0x8ff6c2e9U),
                           bswap_32big(0x4a825c75U));
        }

        r_rsip_func100(bswap_32big(0xf3564513U), bswap_32big(0x5c50ba2eU), bswap_32big(0x30b8e549U),
                       bswap_32big(0xd4c41b74U));
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
        r_rsip_func100(bswap_32big(0xb2d38d22U), bswap_32big(0x8ecf8ac5U), bswap_32big(0x60b34f6fU),
                       bswap_32big(0x248fa0eeU));
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
        r_rsip_func101(bswap_32big(0x3b3346e5U), bswap_32big(0x65c8a940U), bswap_32big(0x96927df2U),
                       bswap_32big(0x7fe89c6eU));
    }
    else
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x96701d9aU), bswap_32big(0x45853485U), bswap_32big(0x6f923345U),
                           bswap_32big(0x4134ff1cU));
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
            r_rsip_func101(bswap_32big(0x42fbba29U), bswap_32big(0xbece848dU), bswap_32big(0x1210ea1cU),
                           bswap_32big(0x767ee05bU));
        }

        r_rsip_func100(bswap_32big(0x40c437f7U), bswap_32big(0xcb26bedaU), bswap_32big(0xa4b3a95fU),
                       bswap_32big(0xcbea9760U));
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
        r_rsip_func100(bswap_32big(0x07f21015U), bswap_32big(0xc387c31aU), bswap_32big(0x089e5faaU),
                       bswap_32big(0xfff64c66U));
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
        r_rsip_func101(bswap_32big(0x8d6c48f8U), bswap_32big(0xe5ae768eU), bswap_32big(0x122dc7a0U),
                       bswap_32big(0x1e01a392U));
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
