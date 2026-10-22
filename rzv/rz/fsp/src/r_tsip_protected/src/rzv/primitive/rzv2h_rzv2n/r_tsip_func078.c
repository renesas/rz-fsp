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

void r_tsip_func078 (uint32_t ARG1)
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
    r_tsip_func100(0x0cefa3f4U, 0x0d1488fbU, 0x70ba01f6U, 0xf9dad890U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x0cfa0b62U, 0xd0b50cb9U, 0x5737a7a6U, 0x2d2e11f7U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0195d979U));
    WR1_PROG(REG_0104H, 0x00005f62U);
    WR1_PROG(REG_00D0H, 0x00001700U);
    WR1_PROG(REG_00C4H, 0x02f087b7U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x00000015U);
    for (iLoop = ARG1 + 0; iLoop < ARG1 + 16; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x00000013U);
    for (iLoop = ARG1 + 16; iLoop < ARG1 + 32; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x0000001dU);
    for (iLoop = ARG1 + 32; iLoop < ARG1 + 48; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x0000001cU);
    for (iLoop = ARG1 + 48; iLoop < ARG1 + 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x00000014U);
    for (iLoop = ARG1 + 64; iLoop < ARG1 + 80; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003243U);
    WR1_PROG(REG_002CH, 0x0000001aU);
    for (iLoop = ARG1 + 80; iLoop < ARG1 + 96; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 36]);
    WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 37]);
    WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 38]);
    WR1_ADDR(REG_0100H, &S_FLASH[iLoop + 39]);
    WR1_PROG(REG_00C4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
}
