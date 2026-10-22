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

void r_tsip_func028 (uint32_t ARG1)
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
    WR1_PROG(REG_00ECH, 0x38000f5aU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x01166403U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x013659ffU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    r_tsip_func100(0xcde75759U, 0x1e384057U, 0xb6afa0a2U, 0xd9f3b5d1U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xed6a5475U, 0x665841faU, 0x10643794U, 0x8bd62035U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WR1_PROG(REG_00E0H, 0x810103c0U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00001762U);
    WR1_PROG(REG_00D0H, 0x00000500U);
    WR1_PROG(REG_00C4H, 0x02f087b7U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 0]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 1]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 2]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 3]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 4]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 5]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 6]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 7]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 8]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 9]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 10]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 11]);
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x0000001aU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 12]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 13]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 14]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 15]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 16]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 17]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 18]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 19]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 20]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 21]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 22]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 23]);
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x0000001bU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 24]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 25]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 26]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 27]);
    WR1_PROG(REG_00C4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_001CH, 0x00602000U);
}
