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
    r_rsip_func100(bswap_32big(0x99b73963U),
                   bswap_32big(0xcd2d9d10U),
                   bswap_32big(0x8c582699U),
                   bswap_32big(0x17943fb1U));
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
    r_rsip_func100(bswap_32big(0xec6535a0U),
                   bswap_32big(0xc7cb0e7fU),
                   bswap_32big(0xcf170482U),
                   bswap_32big(0x2a7ae1c1U));
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
    r_rsip_func100(bswap_32big(0x37094d80U),
                   bswap_32big(0x8e8febdfU),
                   bswap_32big(0x15474819U),
                   bswap_32big(0x34cd597eU));
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
        r_rsip_func101(bswap_32big(0x961f8c14U), bswap_32big(0xa4a5b293U), bswap_32big(0xc5b51bd7U),
                       bswap_32big(0x2291285fU));
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
    r_rsip_func100(bswap_32big(0x65e437b4U),
                   bswap_32big(0x496209beU),
                   bswap_32big(0x19033057U),
                   bswap_32big(0xa7408341U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func100(bswap_32big(0xbfe35335U), bswap_32big(0x7e4ee944U), bswap_32big(0xe692b182U),
                       bswap_32big(0x8caadc69U));
        WR1_PROG(REG_1408H, 0x00007012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_DataT[0]);
        RD1_ADDR(REG_1420H, &OutData_DataT[1]);
        RD1_ADDR(REG_1420H, &OutData_DataT[2]);
        RD1_ADDR(REG_1420H, &OutData_DataT[3]);
        r_rsip_func102(bswap_32big(0xf18f120aU), bswap_32big(0x58e297ebU), bswap_32big(0x899ef1e5U),
                       bswap_32big(0x1a6f7d1bU));
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
        r_rsip_func100(bswap_32big(0x654d8e31U), bswap_32big(0x1d68723fU), bswap_32big(0xc7a0f5aeU),
                       bswap_32big(0x3d792609U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x39856609U), bswap_32big(0x25cac52eU), bswap_32big(0xa0a936a2U),
                           bswap_32big(0x52e95d86U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_AUTH_FAIL;
        }
        else
        {
            r_rsip_func102(bswap_32big(0x9aebfa99U), bswap_32big(0x85507733U), bswap_32big(0x5e91a896U),
                           bswap_32big(0x38fcb119U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
