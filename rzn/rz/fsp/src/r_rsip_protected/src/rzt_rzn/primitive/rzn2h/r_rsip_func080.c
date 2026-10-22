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
    r_rsip_func100(bswap_32big(0x8139b597U),
                   bswap_32big(0x2ddc8568U),
                   bswap_32big(0xa49203d1U),
                   bswap_32big(0x36412ce7U));
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
    r_rsip_func101(bswap_32big(0xc0dabcd9U),
                   bswap_32big(0x427e56ebU),
                   bswap_32big(0x0409b764U),
                   bswap_32big(0x93bbe7a7U));
    r_rsip_func045();
    r_rsip_subfunc009(bswap_32big(0x0000f080U));
    r_rsip_func101(bswap_32big(0xcf3d063fU),
                   bswap_32big(0xbea62cd0U),
                   bswap_32big(0x5af0638eU),
                   bswap_32big(0x512640bbU));
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
    r_rsip_func100(bswap_32big(0x60ab537eU),
                   bswap_32big(0x791144a6U),
                   bswap_32big(0xbe0e5e95U),
                   bswap_32big(0x1b997603U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0xc66d1960U), bswap_32big(0x18b5715bU), bswap_32big(0xe50da330U),
                           bswap_32big(0x7d4a2becU));
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
            r_rsip_func101(bswap_32big(0x728f5ee0U), bswap_32big(0x01f2bda6U), bswap_32big(0x2e9f7160U),
                           bswap_32big(0xef9fcca0U));
        }

        r_rsip_func100(bswap_32big(0x48d29fddU), bswap_32big(0xb24dad3eU), bswap_32big(0xe8894a03U),
                       bswap_32big(0x6cfdfbfcU));
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
        r_rsip_func100(bswap_32big(0xf1bfd0a1U), bswap_32big(0x92ec7c18U), bswap_32big(0xabf56fbaU),
                       bswap_32big(0x1d1ecfdbU));
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
        r_rsip_func101(bswap_32big(0xa028f460U), bswap_32big(0xe032dd26U), bswap_32big(0xbcd48dccU),
                       bswap_32big(0x2ac19be6U));
    }
    else
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x37e99e3cU), bswap_32big(0x80cf6be8U), bswap_32big(0xb78e5c1dU),
                           bswap_32big(0xe40ace60U));
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
            r_rsip_func101(bswap_32big(0xe2f59031U), bswap_32big(0xc321b81fU), bswap_32big(0x02448139U),
                           bswap_32big(0xdb68860fU));
        }

        r_rsip_func100(bswap_32big(0xb1cbaa07U), bswap_32big(0x8754b7bbU), bswap_32big(0x32462132U),
                       bswap_32big(0xfd27d1d3U));
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
        r_rsip_func100(bswap_32big(0x49902473U), bswap_32big(0xb86187dfU), bswap_32big(0x8fcff5e7U),
                       bswap_32big(0xeaadd1c8U));
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
        r_rsip_func101(bswap_32big(0x89158b8fU), bswap_32big(0x3bb31457U), bswap_32big(0x087eb8c0U),
                       bswap_32big(0x8aaf55aeU));
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
