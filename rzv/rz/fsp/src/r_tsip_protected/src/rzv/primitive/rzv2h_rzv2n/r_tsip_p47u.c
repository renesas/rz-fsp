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

void r_tsip_p47u (const uint32_t InData_Text[], uint32_t OutData_Text[], const uint32_t MAX_CNT)
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
        r_tsip_func100(0x1c9b3576U, 0x491c223bU, 0x543bd462U, 0x006ee323U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x00000a86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0xf7f824eaU, 0x3c3ae391U, 0x12d382aeU, 0x2d0ec5a8U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x00004a86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0xdf2e7632U, 0xc4a5b563U, 0x00c28686U, 0x6c6391abU);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x00000e96U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0xcd7a9072U, 0x8a3e98aaU, 0xb7d8103cU, 0x3fd67484U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x000049a6U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0xe8ff8cd5U, 0xbd439da5U, 0x69d02befU, 0x63506ef9U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x000007b6U);
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
        r_tsip_func101(0xa4dff38dU, 0x06b405a6U, 0x63c5bfd5U, 0x48b792e2U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x672518fdU, 0x375e65daU, 0x200dea57U, 0xc28060e1U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x98056717U, 0x244f0c40U, 0x56b14836U, 0x2fffa5ceU);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xa9c0e331U, 0x5261cefcU, 0x50729a10U, 0xaba4d9b3U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xb5c3b45cU, 0x0825d0e2U, 0xa8b47d32U, 0x7fd302d0U);
    }
}
