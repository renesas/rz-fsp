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

tsip_ret_t r_tsip_p19 (const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[])
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
    if (0x0U != RD1_MASK(REG_01B4H, 0x1dU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00001902U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x5078616dU, 0x150cef8bU, 0x78bfc76eU, 0xa27269c2U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00A4H, 0x000a0805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xf5da3c7fU, 0x7da4cc7eU, 0x3b1beac4U, 0x0713c459U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000a2e15U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[0]);
    WR1_ADDR(REG_0100H, &S_INST2[1]);
    WR1_ADDR(REG_0100H, &S_INST2[2]);
    WR1_ADDR(REG_0100H, &S_INST2[3]);
    r_tsip_func100(0x1ab23576U, 0x20675784U, 0xb3aae516U, 0xe0b3d052U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a2e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x010168d1U));
    r_tsip_func100(0x2bf60dc2U, 0x90045ee4U, 0x38656fbdU, 0xa51fda3fU);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f82735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[4]);
    WR1_ADDR(REG_0100H, &S_INST2[5]);
    WR1_ADDR(REG_0100H, &S_INST2[6]);
    WR1_ADDR(REG_0100H, &S_INST2[7]);
    r_tsip_func100(0x9aa221edU, 0x8e9976f6U, 0x9904394aU, 0xacae660fU);
    WR1_PROG(REG_0104H, 0x00000761U);
    WR1_PROG(REG_00A4H, 0x00f92735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[8]);
    WR1_ADDR(REG_0100H, &S_INST2[9]);
    WR1_ADDR(REG_0100H, &S_INST2[10]);
    WR1_ADDR(REG_0100H, &S_INST2[11]);
    WR1_PROG(REG_00A4H, 0x000027b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[12]);
    WR1_ADDR(REG_0100H, &S_INST2[13]);
    WR1_ADDR(REG_0100H, &S_INST2[14]);
    WR1_ADDR(REG_0100H, &S_INST2[15]);
    WR1_PROG(REG_00A4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x56d0e25cU, 0x489862d9U, 0xffde83c6U, 0xb77d7822U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00040805U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_IV[0]);
    WR1_ADDR(REG_0100H, &InData_IV[1]);
    WR1_ADDR(REG_0100H, &InData_IV[2]);
    WR1_ADDR(REG_0100H, &InData_IV[3]);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00050804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func103();
    r_tsip_func100(0x6387c947U, 0xf652de36U, 0x147f6c97U, 0x3c6425ebU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xbd6f3220U, 0x346f757aU, 0xa64ca05bU, 0x023d268cU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xb35a1f4bU, 0x923be4bcU, 0x334f0fbcU, 0xdb1b2c58U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x012279dbU));
    r_tsip_func100(0xcfd5f8a4U, 0x508fdbf5U, 0x7bf2acf5U, 0x771c251aU);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00451944U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00002113U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00d049a5U);
    WR1_PROG(REG_00C4H, 0x02e007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[0]);
    WR1_ADDR(REG_0100H, &InData_InstData[1]);
    WR1_ADDR(REG_0100H, &InData_InstData[2]);
    WR1_ADDR(REG_0100H, &InData_InstData[3]);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[4]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[5]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[6]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[7]);
    r_tsip_func100(0x450b739dU, 0x627ff455U, 0x18a1a867U, 0x0785faf1U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x000009c5U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[8]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[9]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[10]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[11]);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[4]);
    WR1_ADDR(REG_0100H, &InData_InstData[5]);
    WR1_ADDR(REG_0100H, &InData_InstData[6]);
    WR1_ADDR(REG_0100H, &InData_InstData[7]);
    r_tsip_func100(0x57e9d18bU, 0xc2410230U, 0xd564ffe1U, 0xd6602164U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xcf4c06f4U, 0x1b689acdU, 0xb3912e49U, 0x46fa95b4U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x5d3b006bU, 0xd1eb3cc5U, 0x9f4b4dcaU, 0x7f2eab58U);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_0004H, 0x00000613U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[0]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[2]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[3]);
        r_tsip_func102(0x6c43b5e1U, 0xda487673U, 0x2d9116dbU, 0x574d0396U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
