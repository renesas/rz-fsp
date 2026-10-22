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

void r_tsip_p29u (const uint32_t InData_Text[], uint32_t OutData_Text[], uint32_t MAX_CNT)
{
    TSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL;
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
    r_tsip_func100(0x5ce5fd7dU, 0x6f85a240U, 0x54ce8775U, 0x52d6d353U);
    WR1_PROG(REG_0000H, 0x80007100U);
    WR1_PROG(REG_0104H, 0x000000b1U);
    WR1_PROG(REG_00B0H, 0x00000020U);
    WR1_PROG(REG_00A4H, 0x000087b6U);
    WR1_PROG(REG_00C4H, 0x00000886U);
    WR1_PROG(REG_0004H, 0x0000c200U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Text[0]);
    WR1_ADDR(REG_0100H, &InData_Text[1]);
    WR1_ADDR(REG_0100H, &InData_Text[2]);
    WR1_ADDR(REG_0100H, &InData_Text[3]);
    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 3]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 4]);
        RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 3]);
        RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 2]);
        RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 1]);
    }

    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 4]);
    RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 3]);
    RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 2]);
    RD1_ADDR(REG_0100H, &OutData_Text[iLoop - 1]);
    WAIT_STS(REG_0074H, 18U, 0U);
    r_tsip_func200();
    r_tsip_func101(0x74e9d3afU, 0xfae6b486U, 0xcd72ec21U, 0x05f6fba2U);
}
