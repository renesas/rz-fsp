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

void r_tsip_p50u (const uint32_t InData_Text[], uint32_t OutData_Text[], const uint32_t MAX_CNT)
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
    if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x819e6816U, 0x8fa36fdaU, 0x44214f50U, 0x212141c0U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x00008a86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x525e5299U, 0x423aa214U, 0x6ad7f9a7U, 0x7d8657efU);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x0000ca86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x4cfc5acbU, 0x74b9d1aaU, 0xe964224cU, 0x16e4ab30U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x00008e96U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x1551decfU, 0xa4fc1ea0U, 0x37d2edafU, 0xebc9b4deU);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x0000c9a6U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0xb0abf9daU, 0xeae457c0U, 0x954f6479U, 0x528490d4U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x000087b6U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }

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
    RD1_ADDR(REG_0100H, &OutData_Text[MAX_CNT - 4]);
    RD1_ADDR(REG_0100H, &OutData_Text[MAX_CNT - 3]);
    RD1_ADDR(REG_0100H, &OutData_Text[MAX_CNT - 2]);
    RD1_ADDR(REG_0100H, &OutData_Text[MAX_CNT - 1]);
    if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xbf0a71acU, 0x590fa68fU, 0x1e214011U, 0xde73f437U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xce78b393U, 0xe37f89ccU, 0x58e713ddU, 0x91bd5773U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x711a497cU, 0x4e4ec555U, 0x1d311e96U, 0xe65d123eU);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xaa7a7e40U, 0x9843c723U, 0xa573128dU, 0x8f3c7070U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x5236dfd5U, 0x1aa06173U, 0x2b55a6dbU, 0x8417acefU);
    }
}
