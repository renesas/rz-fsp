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

void r_tsip_func027 (uint32_t ARG1)
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
    WR1_PROG(REG_00ECH, 0x01305c44U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x0142859dU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    r_tsip_func100(0x744cc2eaU, 0x9ec86764U, 0x9f8cbdf3U, 0x6b18d085U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x1614cdc6U, 0x33a91cb5U, 0xed681d69U, 0xf469af8eU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WR1_PROG(REG_00E0H, 0x810103c0U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00003b62U);
    WR1_PROG(REG_00D0H, 0x00000e00U);
    WR1_PROG(REG_00C4H, 0x02f087b7U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 28]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 29]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 30]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 31]);
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
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x00000015U);
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
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 48]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 49]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 50]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 51]);
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x00000013U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 52]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 53]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 54]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 55]);
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
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x0000001dU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 64]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 65]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 66]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 67]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 68]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 69]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 70]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 71]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 72]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 73]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 74]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 75]);
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x0000001cU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 76]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 77]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 78]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 79]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 80]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 81]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 82]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 83]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 84]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 85]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 86]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 87]);
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000b62U);
    WR1_PROG(REG_00D0H, 0x00000200U);
    WR1_PROG(REG_00C4H, 0x00f087b7U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 88]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 89]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 90]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 91]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 92]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 93]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 94]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 95]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 96]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 97]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 98]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 99]);
    WR1_PROG(REG_0000H, 0x00003233U);
    WR1_PROG(REG_002CH, 0x0000001aU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 100]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 101]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 102]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 103]);
    WR1_PROG(REG_00C4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_001CH, 0x00602000U);
}
