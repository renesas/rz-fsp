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

rsip_ret_t r_rsip_p54 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00540002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);
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
    r_rsip_subfunc009(bswap_32big(0x00000054U));
    r_rsip_func101(bswap_32big(0x62c9ca1cU),
                   bswap_32big(0x61161cfbU),
                   bswap_32big(0xa01bab37U),
                   bswap_32big(0xa10ce0efU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01bf4c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00000054U));
    r_rsip_func101(bswap_32big(0x6637d266U),
                   bswap_32big(0x67899458U),
                   bswap_32big(0xb3d7d5c2U),
                   bswap_32big(0x2d4d01f9U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x00003fc2U);
    WR1_PROG(REG_1A2CH, 0x40000700U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WR1_PROG(REG_1404H, 0x15b00000U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1A2CH, 0x40000700U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);
    WR1_PROG(REG_1404H, 0x13a80000U);
    for (iLoop = 32; iLoop < 64; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[68]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[69]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[70]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[71]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0x13a2355bU),
                   bswap_32big(0xe1f77925U),
                   bswap_32big(0x597ef019U),
                   bswap_32big(0xdd936216U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x44b71de6U), bswap_32big(0x035b909eU), bswap_32big(0x18c9e575U),
                       bswap_32big(0xdeaca886U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x10100010U);
        WR1_PROG(REG_1444H, 0x00001fd0U);
        for (iLoop = 0; iLoop < 128; iLoop = iLoop + 4)
        {
            WR1_ADDR((&(REG_01A0H))[iLoop / 4], &InData_Text[(iLoop / 4) + 0]);
        }

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800dbe0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000838U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);
        r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000a40U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x60e83b91U), bswap_32big(0x99f1e1b4U), bswap_32big(0xe1cb1539U),
                       bswap_32big(0xc0763b4dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x170b6761U), bswap_32big(0xa2b28090U), bswap_32big(0x7c5ec130U),
                           bswap_32big(0x2f349052U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xbeb42237U), bswap_32big(0xae34883bU), bswap_32big(0x111288e3U),
                           bswap_32big(0xa76eb28aU));
            r_rsip_subfunc005(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x10100000U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_func100(bswap_32big(0x0559e0c8U), bswap_32big(0xd7d9559cU), bswap_32big(0x80f21303U),
                           bswap_32big(0x3f17d9c4U));
            WR1_PROG(REG_1404H, 0x17b80000U);
            WR1_PROG(REG_1A2CH, 0x00000200U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            r_rsip_subfunc003(0x00830031U);
            WR1_PROG(REG_1408H, 0x00002032U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[0]);
            RD1_ADDR(REG_1420H, &OutData_Text[1]);
            RD1_ADDR(REG_1420H, &OutData_Text[2]);
            RD1_ADDR(REG_1420H, &OutData_Text[3]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[4]);
            RD1_ADDR(REG_1420H, &OutData_Text[5]);
            RD1_ADDR(REG_1420H, &OutData_Text[6]);
            RD1_ADDR(REG_1420H, &OutData_Text[7]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[8]);
            RD1_ADDR(REG_1420H, &OutData_Text[9]);
            RD1_ADDR(REG_1420H, &OutData_Text[10]);
            RD1_ADDR(REG_1420H, &OutData_Text[11]);
            r_rsip_func100(bswap_32big(0x9998ce99U), bswap_32big(0xa70eb92aU), bswap_32big(0xa67f2250U),
                           bswap_32big(0x23b58d09U));
            WR1_PROG(REG_1A2CH, 0x00000200U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            r_rsip_subfunc003(0x00830031U);
            WR1_PROG(REG_1408H, 0x00002032U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[12]);
            RD1_ADDR(REG_1420H, &OutData_Text[13]);
            RD1_ADDR(REG_1420H, &OutData_Text[14]);
            RD1_ADDR(REG_1420H, &OutData_Text[15]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[16]);
            RD1_ADDR(REG_1420H, &OutData_Text[17]);
            RD1_ADDR(REG_1420H, &OutData_Text[18]);
            RD1_ADDR(REG_1420H, &OutData_Text[19]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[20]);
            RD1_ADDR(REG_1420H, &OutData_Text[21]);
            RD1_ADDR(REG_1420H, &OutData_Text[22]);
            RD1_ADDR(REG_1420H, &OutData_Text[23]);
            r_rsip_func100(bswap_32big(0x73bfdd55U), bswap_32big(0x3445e4a3U), bswap_32big(0xeab39527U),
                           bswap_32big(0x3b42feffU));
            WR1_PROG(REG_1A2CH, 0x00000100U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            r_rsip_subfunc003(0x00830021U);
            WR1_PROG(REG_1408H, 0x00002022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[24]);
            RD1_ADDR(REG_1420H, &OutData_Text[25]);
            RD1_ADDR(REG_1420H, &OutData_Text[26]);
            RD1_ADDR(REG_1420H, &OutData_Text[27]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_Text[28]);
            RD1_ADDR(REG_1420H, &OutData_Text[29]);
            RD1_ADDR(REG_1420H, &OutData_Text[30]);
            RD1_ADDR(REG_1420H, &OutData_Text[31]);
            r_rsip_func102(bswap_32big(0x687462d4U), bswap_32big(0x4a2903f8U), bswap_32big(0x78a3ca06U),
                           bswap_32big(0x0eaf5e50U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
