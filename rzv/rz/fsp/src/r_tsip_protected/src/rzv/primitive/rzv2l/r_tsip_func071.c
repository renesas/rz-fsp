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

void r_tsip_func071 (uint32_t ARG1)
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
    WR1_PROG(REG_00ECH, 0x30003340U);
    WR1_PROG(REG_00ECH, 0x00010020U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x0163c737U);
    WR1_PROG(REG_00ECH, 0x00070040U);
    WR1_PROG(REG_00ECH, 0x30003380U);
    WR1_PROG(REG_00ECH, 0x00070020U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x017c67d8U);
    WR1_PROG(REG_00ECH, 0x00030040U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x0126ddb5U);
    WR1_PROG(REG_00ECH, 0x00050040U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x01bcfa36U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_0028H, 0x00870001U);
    r_tsip_func100(0x7c13d539U, 0x2a364128U, 0xd4df4800U, 0x77508e5eU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x74de113aU, 0xf3f58408U, 0x763c1bdaU, 0x3563134fU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WR1_PROG(REG_00E0H, 0x810103c0U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00003f62U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
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
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000001aU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 8]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 9]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 10]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 11]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 12]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 13]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 14]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 15]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000001bU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
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
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x00000098U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 24]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 25]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 26]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 27]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 28]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 29]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 30]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 31]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x00000099U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 32]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 33]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 34]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 35]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 36]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 37]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 38]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 39]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x00000094U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 40]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 41]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 42]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 43]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 44]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 45]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 46]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 47]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x00000095U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 48]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 49]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 50]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 51]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 52]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 53]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 54]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 55]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000009cU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 56]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 57]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 58]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 59]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 60]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 61]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 62]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 63]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000009dU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 64]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 65]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 66]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 67]);
    WR1_PROG(REG_00C4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_001CH, 0x00602000U);
}
