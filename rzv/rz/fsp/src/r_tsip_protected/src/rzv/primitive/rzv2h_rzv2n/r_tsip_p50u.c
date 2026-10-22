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
        r_tsip_func100(0x39217bb5U, 0xe43de303U, 0x362f62cdU, 0x7ccfe239U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x00008a86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0xb36c0c97U, 0xcdb894f4U, 0xe0f21392U, 0x4cc22ce3U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x0000ca86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x541fd6e8U, 0xdda0656dU, 0xcd5bdeb6U, 0xc59c585aU);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x00008e96U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x522d5537U, 0xa4166dacU, 0x481f2dfcU, 0x7a84cb44U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00B0H, 0x40000000U);
        WR1_PROG(REG_00A4H, 0x0000c9a6U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x74422836U, 0xf87733a4U, 0xf9b845f3U, 0x25308b1cU);
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
        r_tsip_func101(0x73abbda0U, 0x11d3052fU, 0x83d455c8U, 0x3b31a589U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x4e67f1b1U, 0x2cc82976U, 0x9a5c8b9aU, 0xf171f6b6U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x16d9063aU, 0xcf142937U, 0x3293fa13U, 0x1567fdc9U);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xc98b9c41U, 0x5f045f69U, 0x6a20c90fU, 0x44ddb2f0U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x71fdd5aaU, 0x8ce54eb6U, 0x39814eefU, 0x3a578488U);
    }
}
