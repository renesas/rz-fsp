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

void r_tsip_func009 (void)
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
    WR1_PROG(REG_0024H, 0x000019c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000a0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0018H, 0x00000004U);
    WR1_PROG(REG_0038H, 0x000000b0U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0018H, 0x00000000U);
    WR1_PROG(REG_0034H, 0x00000002U);
    WR1_PROG(REG_0024H, 0x800048d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000880cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000020U);
    WR1_PROG(REG_0024H, 0x80007cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00004c0cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000070d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000010U);
    WR1_PROG(REG_0024H, 0x800098d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000ac0cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000400U);
    WR1_PROG(REG_0024H, 0x8000a8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000003U);
    WR1_PROG(REG_0024H, 0x8000c8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000084d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00029008U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000094aU);
    WR1_PROG(REG_00E0H, 0x8088000aU);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x000000a5U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x00000020U);
    WR1_PROG(REG_00E0H, 0x8088000aU);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x00000025U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x00000040U);
    WR1_PROG(REG_00E0H, 0x8088000aU);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x0000002aU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00E0H, 0x8088000aU);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x000000adU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0034H, 0x0000080cU);
    WR1_PROG(REG_0024H, 0x8000f4d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000810U);
    WR1_PROG(REG_0024H, 0x80009cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000808U);
    WR1_PROG(REG_0024H, 0x80009008U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000808U);
    WR1_PROG(REG_0024H, 0x8000b0d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000e0d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
}
