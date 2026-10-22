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

void r_rsip_p97a (const uint32_t InData_DataA[], uint32_t MAX_CNT)
{
    RSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL;
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
    WR1_PROG(REG_1444H, 0x00020066U);
    for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 3]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 7]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 11]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 12]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 13]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 14]);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 15]);
    }

    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_DataA[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_1C30H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001c00U);
    WAIT_STS(REG_1C30H, 0U, 1U);
    r_rsip_func101(bswap_32big(0x56b68fa6U),
                   bswap_32big(0x82d884d3U),
                   bswap_32big(0x16b6cff2U),
                   bswap_32big(0x21c8d99cU));
}
