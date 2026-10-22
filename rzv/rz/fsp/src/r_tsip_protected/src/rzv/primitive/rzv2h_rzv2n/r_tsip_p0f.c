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

tsip_ret_t r_tsip_p0f (const uint32_t InData_Cmd[],
                       const uint32_t InData_IV[],
                       const uint32_t InData_InstData[],
                       uint32_t       OutData_KeyIndex[])
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

    WR1_PROG(REG_0084H, 0x00000f02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x77295c44U, 0x8535d1aaU, 0xbb1efa18U, 0x349187c9U);
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
    r_tsip_func100(0x48bd1861U, 0x5277aed1U, 0x8b25b3c6U, 0x1c11a935U);
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
    r_tsip_func100(0x2f60e956U, 0x5767c9c9U, 0xca29dcd8U, 0x2339f6b9U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a2e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01ef1cb9U));
    r_tsip_func100(0x444053e2U, 0x25b3848bU, 0xd3c5dde9U, 0xa3cf41aeU);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f82735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[4]);
    WR1_ADDR(REG_0100H, &S_INST2[5]);
    WR1_ADDR(REG_0100H, &S_INST2[6]);
    WR1_ADDR(REG_0100H, &S_INST2[7]);
    r_tsip_func100(0xaf0ef9ceU, 0x2ecae79bU, 0xeb2f7671U, 0xc8ca6459U);
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
    r_tsip_func100(0x67ba1567U, 0xe1fa464aU, 0xf5cf0339U, 0xffef5e4fU);
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
    r_tsip_func100(0x32efa747U, 0x19f7929fU, 0x39951e7eU, 0x2bc58377U);
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
    r_tsip_func100(0xb94a2adfU, 0xa35defcdU, 0xca24d160U, 0xda689415U);
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
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x30003140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00070020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b580U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01294396U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00030040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b580U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x018fd17cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00050040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b580U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x015e9038U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0x62b58e5fU, 0xde5d517cU, 0x89f474aaU, 0x5b3e91e6U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WR1_PROG(REG_00E0H, 0x81010180U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x5c385483U, 0x5cd54f2fU, 0x3071e02fU, 0xa4e21d01U);
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
    r_tsip_func100(0x7e613abcU, 0xa68079b7U, 0x44963ea8U, 0x822e150aU);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00451944U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00002113U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00d049a5U);
    WR1_PROG(REG_00C4H, 0x00e007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[4]);
    WR1_ADDR(REG_0100H, &InData_InstData[5]);
    WR1_ADDR(REG_0100H, &InData_InstData[6]);
    WR1_ADDR(REG_0100H, &InData_InstData[7]);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[8]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[9]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[10]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[11]);
    r_tsip_func100(0x97f4be79U, 0xbc254e19U, 0xdbf006a2U, 0x577f9827U);
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
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[12]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[13]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[14]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[15]);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[8]);
    WR1_ADDR(REG_0100H, &InData_InstData[9]);
    WR1_ADDR(REG_0100H, &InData_InstData[10]);
    WR1_ADDR(REG_0100H, &InData_InstData[11]);
    r_tsip_func100(0x07c80d9bU, 0xce79ca53U, 0x8d985b32U, 0x3e6683abU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xa4179041U, 0xd308c915U, 0xa802dd1eU, 0xc822e6d5U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x9deadf56U, 0x4b73854cU, 0xe44a24fcU, 0x0f5f95afU);
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
        r_tsip_func102(0x08e469b8U, 0x5e4b899dU, 0x083c02f5U, 0xf87262c7U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
