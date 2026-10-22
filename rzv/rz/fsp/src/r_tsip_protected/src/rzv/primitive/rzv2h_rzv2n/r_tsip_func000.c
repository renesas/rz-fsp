/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"
#include "r_tsip_reg.h"
#include "r_tsip_util.h"

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

TSIP_PRV_PRIMITIVE_FUNC

void r_tsip_func000 (const uint32_t InData_PaddedMsg[], uint32_t MAX_CNT)
{
    uint32_t iLoop;
    uint32_t iLoop2;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t oLoop2;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) iLoop2;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) oLoop2;
    (void) OFS_ADR;
    WR1_PROG(REG_0104H, 0x000000b4U);
    for (iLoop = 0; iLoop < MAX_CNT; iLoop = iLoop + 16)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 3]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 4]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 5]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 6]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 7]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 8]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 9]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 10]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 11]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 12]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 13]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 14]);
        WR1_ADDR(REG_0100H, &InData_PaddedMsg[iLoop + 15]);
    }

    WAIT_STS(REG_0074H, 18U, 0U);
    WR1_PROG(REG_0104H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00001600U);
}
