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

tsip_ret_t r_tsip_p9e (uint32_t const InData_IV[], uint32_t const InData_InstData[], uint32_t OutData_KeyIndex[])
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

    WR1_PROG(REG_0084H, 0x00009e02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x27c764e3U, 0x48ec7e8eU, 0xc6d997f0U, 0x369203faU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00A4H, 0x000a0805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x01be447aU, 0xd71044f2U, 0x3855ab54U, 0x0845f1a3U);
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
    r_tsip_func100(0x2ddc8fb4U, 0x19c47e2dU, 0x81fe6e13U, 0x22269dcbU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a2e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x010168d1U));
    r_tsip_func100(0x8d00b188U, 0xc28acd76U, 0xb7eaf71dU, 0xe232c7dfU);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f82735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[4]);
    WR1_ADDR(REG_0100H, &S_INST2[5]);
    WR1_ADDR(REG_0100H, &S_INST2[6]);
    WR1_ADDR(REG_0100H, &S_INST2[7]);
    r_tsip_func100(0xd309dae1U, 0xc7c0e540U, 0x921e2f58U, 0x03e2f087U);
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
    r_tsip_func100(0xfaa6aa88U, 0x0f817b7eU, 0x6258c70aU, 0x1f06e334U);
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
    r_tsip_func100(0x8e7f7345U, 0xf97856b5U, 0x20eb7d5dU, 0x805e61dcU);
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
    r_tsip_func100(0x33f7e315U, 0x23870afbU, 0x79a68763U, 0xc3758665U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x429e58b1U, 0x34567571U, 0xd085561cU, 0x072df48eU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x010ed47dU));
    r_tsip_func100(0xfc327d08U, 0x35fb6142U, 0xd97480b5U, 0xfd43c1c3U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00012103U);
    WR1_PROG(REG_0104H, 0x00000031U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x00d0c9a7U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x02f08887U);
    WR1_PROG(REG_0004H, 0x00000203U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[0]);
    WR1_ADDR(REG_0100H, &InData_InstData[1]);
    WR1_ADDR(REG_0100H, &InData_InstData[2]);
    WR1_ADDR(REG_0100H, &InData_InstData[3]);
    for (iLoop = 4; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 3]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 1]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 2]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 1]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 2]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 3]);
    WR1_PROG(REG_0104H, 0x00000000U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_00C8H, 6U, 0U);
    r_tsip_func100(0x668d8c14U, 0xf23f010dU, 0xde54e26eU, 0x7530c0d1U);
    WR1_PROG(REG_0000H, 0x00012103U);
    WR1_PROG(REG_0104H, 0x00000031U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x00d0c9a7U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x00f08887U);
    WR1_PROG(REG_0004H, 0x00000203U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[64]);
    WR1_ADDR(REG_0100H, &InData_InstData[65]);
    WR1_ADDR(REG_0100H, &InData_InstData[66]);
    WR1_ADDR(REG_0100H, &InData_InstData[67]);
    for (iLoop = 68; iLoop < 128; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_InstData[iLoop + 3]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 1]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 2]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 1]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 2]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[iLoop + 3]);
    WR1_PROG(REG_0104H, 0x00000000U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_00C8H, 6U, 0U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00451944U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func100(0x935eb7faU, 0x1708589eU, 0x9278f701U, 0x43c37b35U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00d049a5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[128]);
    WR1_ADDR(REG_0100H, &InData_InstData[129]);
    WR1_ADDR(REG_0100H, &InData_InstData[130]);
    WR1_ADDR(REG_0100H, &InData_InstData[131]);
    WR1_PROG(REG_00C4H, 0x00f00885U);
    WR1_PROG(REG_0000H, 0x00002113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[132]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[133]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[134]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[135]);
    WAIT_STS(REG_00C8H, 6U, 0U);
    r_tsip_func100(0xb101a791U, 0x4156ac38U, 0x85e32efaU, 0x6cc56ceaU);
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
    WR1_ADDR(REG_0100H, &InData_InstData[132]);
    WR1_ADDR(REG_0100H, &InData_InstData[133]);
    WR1_ADDR(REG_0100H, &InData_InstData[134]);
    WR1_ADDR(REG_0100H, &InData_InstData[135]);
    r_tsip_func100(0xee7a02c0U, 0x1f4f3213U, 0xe431df8eU, 0xa4a78e71U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x4a3aec0fU, 0xc0bffce7U, 0x5cbb1875U, 0xcf98891aU);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0xf4c7510cU, 0x0d5b9bfbU, 0xfeb81712U, 0xb9be306cU);
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
        r_tsip_func102(0x53e73a3fU, 0x0ae8ca77U, 0x0acb5d94U, 0xcf7fa550U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
