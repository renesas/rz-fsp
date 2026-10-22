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
    r_rsip_func100(bswap_32big(0xe698b8a5U),
                   bswap_32big(0x4045d83bU),
                   bswap_32big(0xeca695b5U),
                   bswap_32big(0xec1669e2U));
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
    r_rsip_func101(bswap_32big(0x43e7feaaU),
                   bswap_32big(0x732198c3U),
                   bswap_32big(0x0d4706c8U),
                   bswap_32big(0x0abaa234U));
    r_rsip_func045();
    r_rsip_subfunc009(bswap_32big(0x0000f080U));
    r_rsip_func101(bswap_32big(0x42f719f2U),
                   bswap_32big(0x3e4a6dbbU),
                   bswap_32big(0x2d54078eU),
                   bswap_32big(0xde4b664dU));
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
    r_rsip_func100(bswap_32big(0xa6d910b9U),
                   bswap_32big(0xbd7f7ae4U),
                   bswap_32big(0x7ff8b9bfU),
                   bswap_32big(0x60a558ffU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x13b6fb83U), bswap_32big(0x4d92aa47U), bswap_32big(0xce9cd394U),
                           bswap_32big(0x779be41fU));
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
            r_rsip_func101(bswap_32big(0x455934c1U), bswap_32big(0x3e99aa13U), bswap_32big(0x422fefe3U),
                           bswap_32big(0x26bb1225U));
        }

        r_rsip_func100(bswap_32big(0x188b466aU), bswap_32big(0x27238afcU), bswap_32big(0x71524489U),
                       bswap_32big(0xc377f091U));
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
        r_rsip_func100(bswap_32big(0x918ae4d2U), bswap_32big(0xc0586fa8U), bswap_32big(0xae729b9dU),
                       bswap_32big(0xf0207f11U));
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
        r_rsip_func101(bswap_32big(0x80d35b93U), bswap_32big(0x7fcdfad5U), bswap_32big(0xfd5a0a91U),
                       bswap_32big(0x31c6aff4U));
    }
    else
    {
        for (iLoop = 0; iLoop < (INST_DATA_SIZE - 8); iLoop = iLoop + 4)
        {
            r_rsip_func100(bswap_32big(0x9ff382f3U), bswap_32big(0xed478bb3U), bswap_32big(0xa1efc169U),
                           bswap_32big(0x6a884c5fU));
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
            r_rsip_func101(bswap_32big(0x8f4fb7e7U), bswap_32big(0xbb8fe427U), bswap_32big(0x01d77c6aU),
                           bswap_32big(0x9b44d73fU));
        }

        r_rsip_func100(bswap_32big(0xa3431d7aU), bswap_32big(0x2b13d659U), bswap_32big(0x3b55a5fbU),
                       bswap_32big(0xa2882696U));
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
        r_rsip_func100(bswap_32big(0xfcf770cdU), bswap_32big(0x63fc0e6cU), bswap_32big(0x5fcd4ca8U),
                       bswap_32big(0xe5236650U));
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
        r_rsip_func101(bswap_32big(0x83392189U), bswap_32big(0x8a59fb81U), bswap_32big(0x02f04f27U),
                       bswap_32big(0x299218b7U));
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
