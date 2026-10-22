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

tsip_ret_t r_tsip_p21 (const uint32_t InData_HV[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_DataT[],
                       uint32_t       MAX_CNT)
{
    TSIP_PRV_PRIMITIVE_ENTRY;
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
    if (0x0U != RD1_MASK(REG_01BCH, 0x1fU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00002102U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_007CH, 0x00000001U);
    WR1_PROG(REG_007CH, 0x00000041U);
    WR1_PROG(REG_0074H, 0x00001000U);
    WR1_PROG(REG_0104H, 0x00000364U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_HV[0]);
    WR1_ADDR(REG_0100H, &InData_HV[1]);
    WR1_ADDR(REG_0100H, &InData_HV[2]);
    WR1_ADDR(REG_0100H, &InData_HV[3]);
    WR1_PROG(REG_0074H, 0x00000004U);
    WR1_PROG(REG_0104H, 0x00000364U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_IV[0]);
    WR1_ADDR(REG_0100H, &InData_IV[1]);
    WR1_ADDR(REG_0100H, &InData_IV[2]);
    WR1_ADDR(REG_0100H, &InData_IV[3]);
    WR1_PROG(REG_0074H, 0x00000002U);
    WR1_PROG(REG_0104H, 0x000000b4U);
    for (iLoop = 0; iLoop < MAX_CNT; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_Text[iLoop + 3]);
    }

    WAIT_STS(REG_0074H, 18U, 0U);
    WR1_PROG(REG_0104H, 0x00000000U);
    r_tsip_func100(0x19b3d93bU, 0xf983ef60U, 0x76816fdfU, 0xcbea0a2dU);
    WR1_PROG(REG_0074H, 0x00000008U);
    WR1_PROG(REG_0004H, 0x00000513U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_DataT[0]);
    RD1_ADDR(REG_0100H, &OutData_DataT[1]);
    RD1_ADDR(REG_0100H, &OutData_DataT[2]);
    RD1_ADDR(REG_0100H, &OutData_DataT[3]);
    r_tsip_func102(0xd5b9f455U, 0x5af9e326U, 0xe22cc64aU, 0x0d37c225U);
    WR1_PROG(REG_01BCH, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
