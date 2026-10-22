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

tsip_ret_t r_tsip_p1e (uint32_t const InData_CurveType[],
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

    WR1_PROG(REG_0084H, 0x00001e02U);
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
    r_tsip_func100(0xe478060cU, 0x5a79a1d4U, 0x2b33b550U, 0x54827ec6U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x258d012fU, 0xc0347cdfU, 0x834aab05U, 0x4a43848fU);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0xc2dd5679U, 0x72de3c1eU, 0x9ab66e84U, 0x34ad6f8fU);
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
        r_tsip_func100(0xeb6bb394U, 0x71d5144aU, 0x7865009fU, 0xf17e62c1U);
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
        r_tsip_func100(0x98d04516U, 0x6af4a258U, 0xd7fd65b7U, 0xfe00d168U);
        WR1_PROG(REG_0104H, 0x00000151U);
        WR1_PROG(REG_00A4H, 0x00442a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00A4H, 0x000a2e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01ef1cb9U));
        r_tsip_func100(0xbd2bc939U, 0x576c3fcdU, 0x3e166e2dU, 0x3c35b78dU);
        WR1_PROG(REG_0104H, 0x00000361U);
        WR1_PROG(REG_00A4H, 0x02f82735U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_INST2[4]);
        WR1_ADDR(REG_0100H, &S_INST2[5]);
        WR1_ADDR(REG_0100H, &S_INST2[6]);
        WR1_ADDR(REG_0100H, &S_INST2[7]);
        r_tsip_func100(0x1e2b7816U, 0xa60d6ef6U, 0x6d0bea95U, 0xa10634fcU);
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
        r_tsip_func100(0x8a2ea44fU, 0x74ce50d2U, 0x15de1adaU, 0x771a0164U);
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
        r_tsip_func100(0xbf59b72bU, 0x0f66a598U, 0x78904d3dU, 0xb736f0e7U);
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
        r_tsip_func100(0x4b6be27dU, 0x0feed753U, 0x839c403fU, 0xa7bc7314U);
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
        WR1_PROG(REG_0100H, bswap_32big(0x0000001eU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0xe9f50cddU, 0xdcf1a53cU, 0x862dd24eU, 0x4984a809U);
        r_tsip_func022();
        r_tsip_func100(0x29e1ec8bU, 0xa7c15e1eU, 0x3a0b8b5fU, 0xc87a15b0U);
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
        r_tsip_func100(0x51334e56U, 0xc5e8351fU, 0x1897d255U, 0x496673b6U);
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
        r_tsip_func100(0x7bacbca6U, 0x8488efa4U, 0x6fa00ca5U, 0x9bd53965U);
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
        r_tsip_func100(0x8ec8fee2U, 0x4c9e46a8U, 0xdd65af73U, 0x1bd37ea2U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x2e9a7581U, 0x7b34270bU, 0x0cc85c5dU, 0x255d2144U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            r_tsip_func100(0xed75ae60U, 0xe6b5d7b9U, 0x3a37162cU, 0x80523674U);
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
            r_tsip_func102(0x2544def8U, 0x9cfcb13aU, 0xc0cfdf2aU, 0xe8a06f1fU);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
