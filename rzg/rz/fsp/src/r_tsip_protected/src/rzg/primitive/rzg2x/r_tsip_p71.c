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

tsip_ret_t r_tsip_p71 (const uint32_t InData_SHA1InitVal[],
                       const uint32_t InData_PaddedMsg[],
                       const uint32_t MAX_CNT,
                       uint32_t       OutData_MsgDigest[])
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

    WR1_PROG(REG_0084H, 0x00007102U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x1a55ebbfU, 0xdeb22890U, 0x7117ee62U, 0xa829af5fU);
    WR1_PROG(REG_007CH, 0x00000001U);
    WR1_PROG(REG_0104H, 0x00000464U);
    WR1_PROG(REG_0074H, 0x00000004U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_SHA1InitVal[0]);
    WR1_ADDR(REG_0100H, &InData_SHA1InitVal[1]);
    WR1_ADDR(REG_0100H, &InData_SHA1InitVal[2]);
    WR1_ADDR(REG_0100H, &InData_SHA1InitVal[3]);
    WR1_ADDR(REG_0100H, &InData_SHA1InitVal[4]);
    WR1_PROG(REG_0104H, 0x000000b4U);
    WR1_PROG(REG_0074H, 0x08000002U);
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
    WR1_PROG(REG_0074H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00001600U);
    WR1_PROG(REG_0074H, 0x00000008U);
    WR1_PROG(REG_0004H, 0x00000517U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_MsgDigest[0]);
    RD1_ADDR(REG_0100H, &OutData_MsgDigest[1]);
    RD1_ADDR(REG_0100H, &OutData_MsgDigest[2]);
    RD1_ADDR(REG_0100H, &OutData_MsgDigest[3]);
    RD1_ADDR(REG_0100H, &OutData_MsgDigest[4]);
    r_tsip_func102(0xd9b5da2bU, 0xc32cf9b4U, 0xbfafaf47U, 0x746c834bU);
    WR1_PROG(REG_01BCH, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
