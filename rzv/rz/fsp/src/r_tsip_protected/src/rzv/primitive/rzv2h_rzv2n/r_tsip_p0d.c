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

tsip_ret_t r_tsip_p0d (uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[])
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
    if (0x0U != RD1_MASK(REG_01BCH, 0x1fU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00000d02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x285f9850U, 0xa0d0e154U, 0xe8e52aa2U, 0x9935b7baU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00A4H, 0x000a0805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xa1f01262U, 0xe8c0d040U, 0x85158bb5U, 0xa2259906U);
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
    r_tsip_func100(0xdaae1c70U, 0x9c2398c6U, 0x0837d9f3U, 0xea9a4176U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a2e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01ef1cb9U));
    r_tsip_func100(0x8a141703U, 0xa9bd85efU, 0x06f1724aU, 0x7b97e091U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f82735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[4]);
    WR1_ADDR(REG_0100H, &S_INST2[5]);
    WR1_ADDR(REG_0100H, &S_INST2[6]);
    WR1_ADDR(REG_0100H, &S_INST2[7]);
    r_tsip_func100(0x79b8e621U, 0xa7b668cbU, 0xcb144acbU, 0xa6acda17U);
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
    r_tsip_func100(0xe0b6854bU, 0x3feaa9edU, 0x90d3c1d2U, 0x46dfe283U);
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
    r_tsip_func100(0xffeec583U, 0xa77aa93fU, 0x52e2e47cU, 0x3d7f5e05U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xe9f3e019U, 0xdb80b9aaU, 0xeaba2e4dU, 0x747ec4acU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xbca2c374U, 0xa575d944U, 0xc6a2f23cU, 0x1e4d6d04U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01cae143U));
    r_tsip_func100(0xafdde208U, 0x6cec4e0fU, 0xf2e67b87U, 0x72c02983U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0000H, 0x00013103U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WR1_PROG(REG_0104H, 0x00003f61U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x00d0c9a7U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x02f08887U);
    WR1_PROG(REG_0004H, 0x00000203U);
    for (iLoop = 4; iLoop < 68; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 1]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 2]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00451944U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func100(0x6b3527c0U, 0x38a364d0U, 0xadd3ec65U, 0x06fc4bd5U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00d049a5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[64]);
    WR1_ADDR(REG_0100H, &InData_InstData[65]);
    WR1_ADDR(REG_0100H, &InData_InstData[66]);
    WR1_ADDR(REG_0100H, &InData_InstData[67]);
    WR1_PROG(REG_00C4H, 0x00f00885U);
    WR1_PROG(REG_0000H, 0x00002113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[68]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[69]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[70]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[71]);
    WAIT_STS(REG_00C8H, 6U, 0U);
    r_tsip_func100(0x4679d735U, 0x60bd52b4U, 0x55a7bf03U, 0xab6fcf0aU);
    WR1_PROG(REG_0018H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x00004404U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0024H, 0x00004804U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0018H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000203U);
    for (iLoop = 72; iLoop < 136; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 1]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 2]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xe947dab9U, 0x2510c635U, 0xd33e5d4fU, 0x9d9557c2U);
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
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[136]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[137]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[138]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[139]);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[68]);
    WR1_ADDR(REG_0100H, &InData_InstData[69]);
    WR1_ADDR(REG_0100H, &InData_InstData[70]);
    WR1_ADDR(REG_0100H, &InData_InstData[71]);
    r_tsip_func100(0x0f87140eU, 0x6f76a5baU, 0xe425c393U, 0x82841062U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xca77d65cU, 0xd22233e4U, 0xbdc7c093U, 0x6b26521bU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0xd68f9b8cU, 0x9236aa02U, 0xa6bb9f4aU, 0xf1e46e4aU);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0004H, 0x00000613U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[0]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[2]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[3]);
        r_tsip_func102(0x055107dfU, 0x58afb3d7U, 0xf76035d7U, 0xef204631U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
