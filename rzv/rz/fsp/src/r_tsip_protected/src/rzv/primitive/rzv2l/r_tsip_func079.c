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

void r_tsip_func079 (uint32_t ARG1)
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
    r_tsip_func100(0xd85096dcU, 0x3952c4c3U, 0xbf112632U, 0xabd11573U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xd23e8240U, 0x5ef532deU, 0x4c53c0c0U, 0xe44327a7U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0193623bU));
    WR1_PROG(REG_0104H, 0x00001f62U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x02f087b7U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x0000001aU);
    for (iLoop = ARG1 + 0; iLoop < ARG1 + 16; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 0]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 1]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 2]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x0000001bU);
    for (iLoop = ARG1 + 16; iLoop < ARG1 + 32; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 0]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 1]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 2]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 32]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 33]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 34]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 35]);
    WR1_PROG(REG_00C4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_001CH, 0x00602000U);
}
