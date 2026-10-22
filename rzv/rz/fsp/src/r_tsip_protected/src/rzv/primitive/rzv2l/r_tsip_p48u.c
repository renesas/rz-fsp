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

void r_tsip_p48u (const uint32_t InData_Text[], uint32_t OutData_Text[], const uint32_t MAX_CNT)
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
        r_tsip_func100(0x2bcbc34dU, 0x7d196ddbU, 0x11b54c1fU, 0x9081b9d1U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x00000a86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x2460f20dU, 0x164292daU, 0x6eeeb9cbU, 0x56afd963U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x00004a86U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x7eaf92d1U, 0x8ba22d12U, 0xd5ebecf9U, 0x2002c192U);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x00000e96U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x92a9669eU, 0x87c6508fU, 0x65efa30dU, 0x2dd07f2bU);
        WR1_PROG(REG_0104H, 0x000000b1U);
        WR1_PROG(REG_00A4H, 0x000049a6U);
        WR1_PROG(REG_0004H, 0x0000c100U);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        WR1_PROG(REG_0104H, 0x00000362U);
        r_tsip_func100(0x2fce23abU, 0x791084ffU, 0xc9f7b36bU, 0xa181086aU);
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
        r_tsip_func101(0x1f6104ccU, 0x446a1d3fU, 0x086f2891U, 0xc75ded39U);
    }
    else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x05567182U, 0xb9627219U, 0x9772c414U, 0x23594495U);
    }
    else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x2c3660cfU, 0x912d96feU, 0xde718f98U, 0x649b61efU);
    }
    else if (0x03000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0xdd96ee84U, 0xf57a5bdaU, 0xd56de5b6U, 0x9bc2dbefU);
    }
    else if (0x04000000U == RD1_MASK(REG_001CH, 0xff000000U))
    {
        r_tsip_func206();
        r_tsip_func101(0x3ac21062U, 0x4d9d0d81U, 0xf4bbc18bU, 0x49263f47U);
    }
}
