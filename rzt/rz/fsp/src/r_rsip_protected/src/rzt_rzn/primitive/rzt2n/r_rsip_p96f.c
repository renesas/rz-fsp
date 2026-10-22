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

rsip_ret_t r_rsip_p96f (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
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
    r_rsip_func100(bswap_32big(0x39122501U),
                   bswap_32big(0xf0583ad3U),
                   bswap_32big(0x22e125a2U),
                   bswap_32big(0xba5368daU));
    WR1_PROG(REG_1444H, 0x00020066U);
    WR1_PROG(REG_1408H, 0x000c7000U);
    for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
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

    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
    }

    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
    }

    WR1_PROG(REG_1408H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001c00U);
    r_rsip_func102(bswap_32big(0xad5a0f24U),
                   bswap_32big(0xd44f69ddU),
                   bswap_32big(0xc50e01b2U),
                   bswap_32big(0x2206f28bU));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
