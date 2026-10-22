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
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0014H, 0x10300007U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x0000007BU);
    WR1_PROG(REG_0068H, 0x00000007U);
    WR1_PROG(REG_006CH, 0xc691b92fU);
    WR1_PROG(REG_0010H, 0x3e5c6a49U);
    WR1_PROG(REG_0014H, 0x10300017U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0014H, 0x10300007U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x0000007BU);
    WR1_PROG(REG_0068H, 0x00003807U);
    WR1_PROG(REG_006CH, 0x98745152U);
    WR1_PROG(REG_0014H, 0x10303017U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_007CH, 0x00000001U);
    WR1_PROG(REG_0074H, 0x00000008U);
    WR1_PROG(REG_0078H, 0x00000106U);
    WR1_PROG(REG_0134H, 0xd58f9470U);
    WR1_PROG(REG_0014H, 0x00100005U);
    WR1_PROG(REG_0014H, 0x00100015U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0080H, 0x00000000U);
    WR1_PROG(REG_0080H, 0x00000001U);
    WR1_PROG(REG_008CH, 0x0000818BU);
    WR1_PROG(REG_0094H, 0x4214ff5fU);
    WR1_PROG(REG_0014H, 0x00001005U);
    WR1_PROG(REG_0014H, 0x00001015U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0028H, 0x00000001U);
    WR1_PROG(REG_0028H, 0x00Bf0001U);
    WR1_PROG(REG_004CH, 0xbe020102U);
    WR1_PROG(REG_0024H, 0x00008080U);
    WAIT_STS(REG_0024H, 20U, 0U);
    WR1_PROG(REG_0024H, 0x00004080U);
    WAIT_STS(REG_0024H, 20U, 0U);
    WR1_PROG(REG_0024H, 0x0000C080U);
    WAIT_STS(REG_0024H, 20U, 0U);
    WR1_PROG(REG_002CH, 0x00000050U);
    WAIT_STS(REG_0000H, 23U, 1U);
    WR1_PROG(REG_0020H, 0xFFFFFFFFU);
    WR1_PROG(REG_003CH, 0x00210343U);
    WR1_PROG(REG_004CH, 0xf704d202U);
    WR1_PROG(REG_0014H, 0x00001005U);
    WR1_PROG(REG_0014H, 0x00001015U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0028H, 0x00000001U);
    WR1_PROG(REG_0028H, 0xfdBf0001U);
    WR1_PROG(REG_003CH, 0x00211B4BU);
    WR1_PROG(REG_004CH, 0xed6ba3e2U);
    WR1_PROG(REG_0014H, 0x00301005U);
    WR1_PROG(REG_0014H, 0x00301015U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0028H, 0x00000001U);
    WR1_PROG(REG_0028H, 0xfeBf0001U);
    WR1_PROG(REG_003CH, 0x0021134BU);
    WR1_PROG(REG_004CH, 0x0b97839dU);
    WR1_PROG(REG_0014H, 0x00101005U);
    WR1_PROG(REG_0014H, 0x00101015U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_010CH, 0x00010001U);
    WR1_PROG(REG_0000H, 0x0000E14DU);
    WR1_PROG(REG_0004H, 0x00400E40U);
    WR1_PROG(REG_0014H, 0xa1f03007U);
    WR1_PROG(REG_0014H, 0xa1f03017U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0000H, 31U, 0U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000000U);
    for (iLoop = 0; iLoop < 15; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_0138H, 0xf597806AU);
        WR1_PROG(REG_00F0H, 0x00000000U);
        WR1_PROG(REG_010CH, 0x00010001U);
        WR1_PROG(REG_0080H, 0x00000001U);
        WR1_PROG(REG_008CH, 0x0000800fU);
        WR1_PROG(REG_0094H, 0x23ca8d9fU);
        WR1_PROG(REG_0014H, 0x00003007U);
        WR1_PROG(REG_0014H, 0x00003017U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 15; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_0138H, 0xf597806AU);
        WR1_PROG(REG_00F0H, 0x00000000U);
        WR1_PROG(REG_010CH, 0x00010001U);
        WR1_PROG(REG_0080H, 0x00000001U);
        WR1_PROG(REG_008CH, 0x0000870fU);
        WR1_PROG(REG_0094H, 0x5d0f32eeU);
        WR1_PROG(REG_0014H, 0xc0703007U);
        WR1_PROG(REG_0014H, 0xc0703017U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_0138H, 0xf597806AU);
        WR1_PROG(REG_00F0H, 0x00000000U);
        WR1_PROG(REG_010CH, 0x00010001U);
        WR1_PROG(REG_0028H, 0x00000001U);
        WR1_PROG(REG_0028H, 0x00Bf0001U);
        WR1_PROG(REG_003CH, 0x000c24bfU);
        WR1_PROG(REG_004CH, 0x335bd674U);
        WR1_PROG(REG_0014H, 0xe6f03007U);
        WR1_PROG(REG_0014H, 0xe6f03017U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 15; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_0138H, 0xf597806AU);
        WR1_PROG(REG_00F0H, 0x00000000U);
        WR1_PROG(REG_010CH, 0x00010001U);
        WR1_PROG(REG_0028H, 0x00000001U);
        WR1_PROG(REG_0028H, 0xfdBf0001U);
        WR1_PROG(REG_003CH, 0x00211B4BU);
        WR1_PROG(REG_004CH, 0x5d376d87U);
        WR1_PROG(REG_0014H, 0x00303007U);
        WR1_PROG(REG_0014H, 0x00303017U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 15; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_0138H, 0xf597806AU);
        WR1_PROG(REG_00F0H, 0x00000000U);
        WR1_PROG(REG_010CH, 0x00010001U);
        WR1_PROG(REG_0028H, 0x00000001U);
        WR1_PROG(REG_0028H, 0xfeBf0001U);
        WR1_PROG(REG_003CH, 0x00211B4BU);
        WR1_PROG(REG_004CH, 0xa9a9720eU);
        WR1_PROG(REG_0014H, 0x00303007U);
        WR1_PROG(REG_0014H, 0x00303017U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }

    for (iLoop = 0; iLoop < 15; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_0138H, 0xf597806AU);
        WR1_PROG(REG_00F0H, 0x00000000U);
        WR1_PROG(REG_010CH, 0x00010001U);
        WR1_PROG(REG_007CH, 0x00000001U);
        WR1_PROG(REG_007CH, 0x00000011U);
        WR1_PROG(REG_0078H, 0x0000001fU);
        WR1_PROG(REG_0134H, 0x94283b4bU);
        WR1_PROG(REG_0014H, 0x00303007U);
        WR1_PROG(REG_0014H, 0x00303017U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0000H, 31U, 0U);
    }
}
