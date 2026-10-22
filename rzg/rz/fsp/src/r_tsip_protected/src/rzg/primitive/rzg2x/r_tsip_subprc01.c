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

void r_tsip_subprc01 (void)
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
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0010H, 0x01234567U);
    WR1_PROG(REG_007CH, 0x00000001U);
    WR1_PROG(REG_0078H, 0x00008007U);
    WR1_PROG(REG_0134H, 0x76543210U);
    r_tsip_func054(0x00003008U, 0x00003018U);
    WAIT_STS(REG_0000H, 31U, 0U);
    r_tsip_func050(0x00010001U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WR1_PROG(REG_0068H, 0x00000417U);
    WR1_PROG(REG_006CH, 0xabcdef01U);
    r_tsip_func054(0x10003008U, 0x10003018U);
    WAIT_STS(REG_0000H, 31U, 0U);
    r_tsip_func050(0x00000001U);
    WR1_PROG(REG_0028H, 0x00000001U);
    WR1_PROG(REG_003CH, 0x00010173U);
    WR1_PROG(REG_004CH, 0x23456789U);
    WR1_PROG(REG_0080H, 0x00000001U);
    WR1_PROG(REG_008CH, 0x000080BBU);
    WR1_PROG(REG_0094H, 0xabcdef01U);
    WR1_PROG(REG_007CH, 0x00000001U);
    WR1_PROG(REG_0078H, 0x0000011fU);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WR1_PROG(REG_0068H, 0x00000017U);
    r_tsip_func054(0x72f01007U, 0x72f01017U);
    WAIT_STS(REG_0000H, 31U, 0U);
    for (iLoop = 0; iLoop < 6; iLoop = iLoop + 1)
    {
        r_tsip_func050(0x00000001U);
        r_tsip_func054(0x72f03007U, 0x72f03017U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 6; iLoop = iLoop + 1)
    {
        r_tsip_func050(0x00000001U);
        WR1_PROG(REG_0028H, 0x00000001U);
        WR1_PROG(REG_0080H, 0x00000001U);
        WR1_PROG(REG_007CH, 0x00000001U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x00000008U);
        r_tsip_func054(0x72f03007U, 0x72f03017U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        r_tsip_func050(0x00000001U);
        WR1_PROG(REG_0028H, 0x00000001U);
        WR1_PROG(REG_003CH, 0x00010173U);
        WR1_PROG(REG_0080H, 0x00000001U);
        WR1_PROG(REG_00B0H, 0x40000010U);
        WR1_PROG(REG_00D0H, 0x40000010U);
        WR1_PROG(REG_00A4H, 0x00008000U);
        WR1_PROG(REG_00C4H, 0x00008000U);
        WR1_PROG(REG_008CH, 0x0000888BU);
        WR1_PROG(REG_007CH, 0x00000001U);
        WR1_PROG(REG_0078H, 0x00000007U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x00000008U);
        WR1_PROG(REG_0068H, 0x00000017U);
        r_tsip_func054(0x7af03007U, 0x7af03017U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    r_tsip_func051();
    WR1_PROG(REG_0028H, 0x00000001U);
    WR1_PROG(REG_003CH, 0x00810173U);
    r_tsip_func054(0x00003008U, 0x00003018U);
    WAIT_STS(REG_0000H, 31U, 0U);
    for (iLoop = 0; iLoop < 6; iLoop = iLoop + 1)
    {
        r_tsip_func052(0x00810173U);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        r_tsip_func052(0x0080197fU);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        r_tsip_func052(0x00fe017bU);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        r_tsip_func052(0x00af091FU);
    }

    r_tsip_func053(0x000380BBU);
    for (iLoop = 0; iLoop < 6; iLoop = iLoop + 1)
    {
        r_tsip_func053(0x000380BBU);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        r_tsip_func053(0x000191BBU);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        r_tsip_func053(0x000185B7U);
    }
}
