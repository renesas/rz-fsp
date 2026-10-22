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
    r_rsip_func100(bswap_32big(0x2491007dU),
                   bswap_32big(0x9e59e167U),
                   bswap_32big(0xa71c5489U),
                   bswap_32big(0xb55f9570U));
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
    r_rsip_func101(bswap_32big(0xa9676408U),
                   bswap_32big(0x8086629eU),
                   bswap_32big(0xbd5de02cU),
                   bswap_32big(0xdb510b46U));
    r_rsip_func045();
    r_rsip_subfunc009(bswap_32big(0x0000f080U));
    r_rsip_func101(bswap_32big(0x02a982b0U),
                   bswap_32big(0x23164f87U),
                   bswap_32big(0xad2b9724U),
                   bswap_32big(0x54b866aaU));
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
    r_rsip_func100(bswap_32big(0xb03da7cdU),
                   bswap_32big(0xd24b85e2U),
                   bswap_32big(0x83a60395U),
                   bswap_32big(0x13ac7b21U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x9b55e0ccU), bswap_32big(0x98c90fecU), bswap_32big(0x87400f93U),
                           bswap_32big(0x1c74bc6dU));
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
            r_rsip_func101(bswap_32big(0x4780eea3U), bswap_32big(0x69fa7ad8U), bswap_32big(0x72bebb6dU),
                           bswap_32big(0x4e067e89U));
        }

        r_rsip_func100(bswap_32big(0x3eae31eaU), bswap_32big(0xdb3214d4U), bswap_32big(0x99c38457U),
                       bswap_32big(0x96059530U));
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
        r_rsip_func100(bswap_32big(0x3f8ac922U), bswap_32big(0xf16148d2U), bswap_32big(0x77c8adfaU),
                       bswap_32big(0x56a2c2c6U));
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
        r_rsip_func101(bswap_32big(0xb71dfba3U), bswap_32big(0x5cd01bf1U), bswap_32big(0x08c106e9U),
                       bswap_32big(0x18a74d1eU));
    }
    else
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x4fa31825U), bswap_32big(0xbba92645U), bswap_32big(0xc3e3a9c3U),
                           bswap_32big(0x432d72bbU));
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
            r_rsip_func101(bswap_32big(0x2dfc3ba8U), bswap_32big(0xf10e83f3U), bswap_32big(0x764fe64cU),
                           bswap_32big(0x0411e305U));
        }

        r_rsip_func100(bswap_32big(0x42fb34eaU), bswap_32big(0x79248e21U), bswap_32big(0x9c4c70d5U),
                       bswap_32big(0xed111f59U));
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
        r_rsip_func100(bswap_32big(0xc7f833caU), bswap_32big(0x79b72d53U), bswap_32big(0x5c0d134dU),
                       bswap_32big(0xbc9ab175U));
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
        r_rsip_func101(bswap_32big(0x3cbc9ac7U), bswap_32big(0x44ec2e4aU), bswap_32big(0xc7e7f2ccU),
                       bswap_32big(0xa20749aaU));
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
