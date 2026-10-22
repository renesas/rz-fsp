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

rsip_ret_t r_rsip_p97f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[],
                        uint32_t       MAX_CNT)
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
    r_rsip_func100(bswap_32big(0x9ad4eec1U),
                   bswap_32big(0x3c7ffe48U),
                   bswap_32big(0xcad7518bU),
                   bswap_32big(0x2c19fcf1U));
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &MAX_CNT);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    r_rsip_func100(bswap_32big(0x86115384U),
                   bswap_32big(0x9526393eU),
                   bswap_32big(0x301d69c3U),
                   bswap_32big(0x64f46af9U));
    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);
    for (iLoop = 0; iLoop < (S_RAM[0] & 0xfffffff0U); iLoop = iLoop + 16)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 3]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 7]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 11]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 12]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 13]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 14]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 15]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 2]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 3]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 7]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 8]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 9]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 10]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 11]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 12]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 13]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 14]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 15]);
    }

    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
    }

    for (iLoop = (S_RAM[0] & 0xfffffff0U); iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001c00U);
    r_rsip_func100(bswap_32big(0x509c40feU),
                   bswap_32big(0xac6a2abbU),
                   bswap_32big(0x3e643a5aU),
                   bswap_32big(0x57f08532U));
    WR1_PROG(REG_1600H, 0x00008c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000000fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c21U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000010U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = S_RAM[0]; iLoop < 16; iLoop = iLoop + 1)
    {
        r_rsip_subfunc003(0x00070005U);
        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7f8fe5f7U), bswap_32big(0x7e3b43a2U), bswap_32big(0xa3b7128fU),
                       bswap_32big(0xbe42d8eeU));
    }

    WR1_PROG(REG_1600H, 0x38008820U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000010U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c84U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xe56aa102U),
                   bswap_32big(0xd709fe0cU),
                   bswap_32big(0xc02abd5cU),
                   bswap_32big(0x784246cbU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func100(bswap_32big(0xfea63c32U), bswap_32big(0x4ad9250fU), bswap_32big(0x8c2c4a51U),
                       bswap_32big(0x2a5a1003U));
        WR1_PROG(REG_1408H, 0x00007012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_DataT[0]);
        RD1_ADDR(REG_1420H, &OutData_DataT[1]);
        RD1_ADDR(REG_1420H, &OutData_DataT[2]);
        RD1_ADDR(REG_1420H, &OutData_DataT[3]);
        r_rsip_func102(bswap_32big(0x9e279f45U), bswap_32big(0xab38e31cU), bswap_32big(0x073db498U),
                       bswap_32big(0xbfe5fc73U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A24H, 0x08000055U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_DataT[0]);
        WR1_ADDR(REG_1420H, &InData_DataT[1]);
        WR1_ADDR(REG_1420H, &InData_DataT[2]);
        WR1_ADDR(REG_1420H, &InData_DataT[3]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00870011U);
        r_rsip_func100(bswap_32big(0x56b2d3f1U), bswap_32big(0x51479478U), bswap_32big(0x79f4c23fU),
                       bswap_32big(0x6b92e9c5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xfb6ac2afU), bswap_32big(0x705cfe74U), bswap_32big(0xaf6b9383U),
                           bswap_32big(0xf4b210e0U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            r_rsip_func102(bswap_32big(0xf698b089U), bswap_32big(0x06e8d26dU), bswap_32big(0x996ff476U),
                           bswap_32big(0x9d776a56U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
