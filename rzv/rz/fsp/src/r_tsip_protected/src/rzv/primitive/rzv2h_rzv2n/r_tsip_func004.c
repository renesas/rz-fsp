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

void r_tsip_func004 (uint32_t ARG1)
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
    WR1_PROG(REG_00ECH, 0x30003380U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00070020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01059cc6U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00030040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01b5267fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00050040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x016a6207U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00441a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00081e14U);
    WR1_PROG(REG_00E0H, 0x810103c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00002f62U);
    WR1_PROG(REG_00D0H, 0x00000b00U);
    WR1_PROG(REG_00C4H, 0x02f087b7U);
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
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x00000015U);
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
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000009aU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 84]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 85]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 86]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 87]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 88]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 89]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 90]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 91]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000001dU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
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
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000009dU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 100]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 101]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 102]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 103]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 104]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 105]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 106]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 107]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 108]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 109]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 110]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 111]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 112]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 113]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 114]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 115]);
    WR1_PROG(REG_0000H, 0x00003223U);
    WR1_PROG(REG_002CH, 0x0000001aU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 116]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 117]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 118]);
    WR1_ADDR(REG_0100H, &S_FLASH[ARG1 + 119]);
    WR1_PROG(REG_00C4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
}
