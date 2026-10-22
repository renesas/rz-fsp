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
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00ECH, 0x30000f5aU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d3e0U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x38000f9cU);
    WR1_PROG(REG_00ECH, 0x1000d3e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x38008be0U);
    WR1_PROG(REG_00ECH, 0x00000001U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x7c685933U, 0xbfe681d7U, 0x582d6d3eU, 0xfe06799aU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xd8245f6aU, 0x3e387c29U, 0xd0e720d3U, 0x4c44e3b2U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x8fc4130bU, 0xf2fed0cdU, 0x414925faU, 0x39e5ec0aU);
        WR1_PROG(REG_00ECH, 0x0000b540U);
        WR1_PROG(REG_00ECH, 0x000001e0U);
        WR1_PROG(REG_00A4H, 0x000a0805U);
        WR1_PROG(REG_00E0H, 0x8184000aU);
        WR1_PROG(REG_0000H, 0x00001813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x8e716a7bU, 0x70ffa5a8U, 0xdb5ddc8cU, 0x64168fe8U);
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
        r_tsip_func100(0x11e95eedU, 0x620182efU, 0xffc2b14aU, 0xc378264dU);
        WR1_PROG(REG_0104H, 0x00000151U);
        WR1_PROG(REG_00A4H, 0x00442a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00A4H, 0x000a2e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x010168d1U));
        r_tsip_func100(0x2a3d5014U, 0x89a41772U, 0xc186570eU, 0xf95a4994U);
        WR1_PROG(REG_0104H, 0x00000361U);
        WR1_PROG(REG_00A4H, 0x02f82735U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_INST2[4]);
        WR1_ADDR(REG_0100H, &S_INST2[5]);
        WR1_ADDR(REG_0100H, &S_INST2[6]);
        WR1_ADDR(REG_0100H, &S_INST2[7]);
        r_tsip_func100(0x8baaee26U, 0x3bd3936cU, 0xf9f3c0e3U, 0x585a224cU);
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
        r_tsip_func100(0xc1d24ea4U, 0x0a104f1dU, 0xeede1ef5U, 0x8cfcb55cU);
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
        r_tsip_func100(0x98ee386eU, 0x1ca6e5f3U, 0x43f3c800U, 0x3548b8dcU);
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
        r_tsip_func100(0xab07516eU, 0x58d0065bU, 0x09e09480U, 0x4ce46970U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00080e15U);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_0000H, 0x00002813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0000002cU));
        r_tsip_func101(0x745ea4efU, 0x9c2904eaU, 0x82740573U, 0x704a0ac7U);
        r_tsip_func023();
        r_tsip_func100(0x71f4a146U, 0x21c2e5a7U, 0x3ac7742eU, 0xea8d7633U);
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
        r_tsip_func100(0x2716f0c3U, 0x01291156U, 0xe421cd45U, 0x0be780b6U);
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
        r_tsip_func100(0x5e6d34e7U, 0xb61acecfU, 0xdb56c94fU, 0x576e28eaU);
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
        r_tsip_func100(0x675942bbU, 0x10b54c57U, 0x0c4710bbU, 0x4695f9a7U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x305be665U, 0x096d314cU, 0x617e860cU, 0x6a278857U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            r_tsip_func100(0x39713f33U, 0x0d79af47U, 0x1ca23ec8U, 0xe7e70759U);
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
            r_tsip_func102(0xaf9beab3U, 0x37994cb0U, 0xc240abdcU, 0x36b91b19U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
