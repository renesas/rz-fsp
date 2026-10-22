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

tsip_ret_t r_tsip_p2c (uint32_t const InData_CurveType[],
                       uint32_t const InData_Cmd[],
                       uint32_t const InData_IV[],
                       uint32_t const InData_InstData[],
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

    WR1_PROG(REG_0084H, 0x00002c02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010340U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x30000f5aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000d3e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38000f9cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x1000d3e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38008be0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x0e5638f9U, 0x95f6ea86U, 0x6b18dc43U, 0x7766fea4U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xaee7092aU, 0x438f8ff8U, 0x5fab78bfU, 0xb82890ddU);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x6da75352U, 0xf17cbe71U, 0xd029378bU, 0x7968556aU);
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
        r_tsip_func100(0xf55d8a92U, 0xb104be90U, 0x333094f4U, 0x6579c490U);
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
        r_tsip_func100(0x824b4cefU, 0x95b9dd82U, 0x870fe96cU, 0xb45b6251U);
        WR1_PROG(REG_0104H, 0x00000151U);
        WR1_PROG(REG_00A4H, 0x00442a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00A4H, 0x000a2e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01ef1cb9U));
        r_tsip_func100(0x345aa7edU, 0x40a31e93U, 0x1d7453ebU, 0xd62367b9U);
        WR1_PROG(REG_0104H, 0x00000361U);
        WR1_PROG(REG_00A4H, 0x02f82735U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_INST2[4]);
        WR1_ADDR(REG_0100H, &S_INST2[5]);
        WR1_ADDR(REG_0100H, &S_INST2[6]);
        WR1_ADDR(REG_0100H, &S_INST2[7]);
        r_tsip_func100(0x2013147aU, 0x9ae16945U, 0x9f0cfa11U, 0x1e61c061U);
        WR1_PROG(REG_0104H, 0x00000361U);
        WR1_PROG(REG_00A4H, 0x00f92735U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_INST2[8]);
        WR1_ADDR(REG_0100H, &S_INST2[9]);
        WR1_ADDR(REG_0100H, &S_INST2[10]);
        WR1_ADDR(REG_0100H, &S_INST2[11]);
        WR1_PROG(REG_0104H, 0x00000361U);
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
        r_tsip_func100(0x98542ae5U, 0x6f46ba85U, 0xe8abd36aU, 0xb4745849U);
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
        r_tsip_func100(0xf8c44ae6U, 0xe2ebd4afU, 0xe1760d1cU, 0x3d022d78U);
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
        r_tsip_func100(0xcc4bae47U, 0x9c2f5981U, 0x9c916fffU, 0xaa6195c4U);
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
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0000002cU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x5ee6c04fU, 0x26ef7bc5U, 0x49dc4ba4U, 0x248ac1feU);
        r_tsip_func023();
        r_tsip_func100(0x8507fbeeU, 0x0c4f7910U, 0xbf5d2d30U, 0x625cdde0U);
        WR1_PROG(REG_0000H, 0x00002133U);
        WR1_PROG(REG_0104H, 0x00000b61U);
        WR1_PROG(REG_00B0H, 0x00000200U);
        WR1_PROG(REG_00A4H, 0x00d0c9a7U);
        WR1_PROG(REG_00D0H, 0x00000200U);
        WR1_PROG(REG_00C4H, 0x02e08887U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[0]);
        WR1_ADDR(REG_0100H, &InData_InstData[1]);
        WR1_ADDR(REG_0100H, &InData_InstData[2]);
        WR1_ADDR(REG_0100H, &InData_InstData[3]);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[4]);
        WR1_ADDR(REG_0100H, &InData_InstData[5]);
        WR1_ADDR(REG_0100H, &InData_InstData[6]);
        WR1_ADDR(REG_0100H, &InData_InstData[7]);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[8]);
        WR1_ADDR(REG_0100H, &InData_InstData[9]);
        WR1_ADDR(REG_0100H, &InData_InstData[10]);
        WR1_ADDR(REG_0100H, &InData_InstData[11]);
        WR1_PROG(REG_0004H, 0x00000233U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[4]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[5]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[6]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[7]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[8]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[9]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[10]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[11]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[12]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[13]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[14]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[15]);
        r_tsip_func100(0x61e00859U, 0xb66aecd1U, 0xcc5491d9U, 0xc67e64f4U);
        WR1_PROG(REG_0104H, 0x00000051U);
        WR1_PROG(REG_00A4H, 0x00451944U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00450944U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0000H, 0x00002113U);
        WR1_PROG(REG_0104H, 0x00000361U);
        WR1_PROG(REG_00A4H, 0x00d049a5U);
        WR1_PROG(REG_00C4H, 0x00e00885U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[12]);
        WR1_ADDR(REG_0100H, &InData_InstData[13]);
        WR1_ADDR(REG_0100H, &InData_InstData[14]);
        WR1_ADDR(REG_0100H, &InData_InstData[15]);
        WR1_PROG(REG_0004H, 0x00000213U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[16]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[17]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[18]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[19]);
        r_tsip_func100(0x953da536U, 0xcd779a45U, 0x4799e859U, 0xf96f95e9U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00000cc4U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0004H, 0x00000213U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[20]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[21]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[22]);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[23]);
        WR1_PROG(REG_0104H, 0x00000361U);
        WR1_PROG(REG_00A4H, 0x00900c45U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_InstData[16]);
        WR1_ADDR(REG_0100H, &InData_InstData[17]);
        WR1_ADDR(REG_0100H, &InData_InstData[18]);
        WR1_ADDR(REG_0100H, &InData_InstData[19]);
        r_tsip_func100(0xc3b64bf8U, 0x17868392U, 0x0d24c340U, 0xb480e191U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xe3c61cabU, 0xbce70c81U, 0xcdc69aeaU, 0x82f41f05U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            r_tsip_func100(0x24874c3cU, 0xf208421aU, 0x635a39b8U, 0x7febbd52U);
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
            r_tsip_func102(0x07fc52a2U, 0x1732e1baU, 0xa35fe71dU, 0x88abcb94U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
