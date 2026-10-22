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

tsip_ret_t r_tsip_p32f (const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_Text[])
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
    WR1_PROG(REG_0104H, 0x00000168U);
    WR1_PROG(REG_00E0H, 0x80020100U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_TextLen[0]);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_TextLen[1]);
    WR1_PROG(REG_00ECH, 0x0000b580U);
    WR1_PROG(REG_00ECH, 0x0000007FU);
    WR1_PROG(REG_00ECH, 0x0000b5a0U);
    WR1_PROG(REG_00ECH, 0xFFFFFF00U);
    WR1_PROG(REG_00ECH, 0x0c0029a9U);
    WR1_PROG(REG_00ECH, 0x04a02988U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010140U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_DataTLen[0]);
    WR1_PROG(REG_00ECH, 0x38008940U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000010U);
    WR1_PROG(REG_00ECH, 0x34202beaU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    r_tsip_func100(0x89b0c58bU, 0xe326adb8U, 0x84685dcfU, 0xebe847dbU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x6a75948cU, 0xfbbaa868U, 0x77b15f02U, 0x95070c16U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00ECH, 0x00003409U);
        WR1_PROG(REG_00ECH, 0x00036800U);
        WR1_PROG(REG_00ECH, 0x08008c00U);
        WR1_PROG(REG_00ECH, 0x0000000fU);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x645a0a45U, 0x6ba5d01dU, 0x4475bc30U, 0xfeb202efU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00A4H, 0x00000885U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_Text[0]);
            WR1_ADDR(REG_0100H, &InData_Text[1]);
            WR1_ADDR(REG_0100H, &InData_Text[2]);
            WR1_ADDR(REG_0100H, &InData_Text[3]);
            WR1_PROG(REG_00D0H, 0x00000020U);
            WR1_PROG(REG_00C4H, 0x000087b5U);
            WR1_PROG(REG_0000H, 0x00007113U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000821U);
            WR1_PROG(REG_00E0H, 0x80840001U);
            WR1_PROG(REG_0000H, 0x00008213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x3c002be0U);
                WR1_PROG(REG_00ECH, 0x12003c3fU);
                WR1_PROG(REG_00ECH, 0x00002fe0U);
            }

            r_tsip_func100(0x0c2263efU, 0xde5bd098U, 0xe0b00e23U, 0x572b04f3U);
            WR1_PROG(REG_00C4H, 0x00000885U);
            WR1_PROG(REG_00ECH, 0x00000821U);
            WR1_PROG(REG_00E0H, 0x81840001U);
            WR1_PROG(REG_0000H, 0x00002813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0004H, 0x00000213U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &OutData_Text[0]);
            RD1_ADDR(REG_0100H, &OutData_Text[1]);
            RD1_ADDR(REG_0100H, &OutData_Text[2]);
            RD1_ADDR(REG_0100H, &OutData_Text[3]);
            r_tsip_func101(0xb55cd339U, 0xdd8cc5a7U, 0xa77816bbU, 0xc190e935U);
        }

        WR1_PROG(REG_0104H, 0x00000164U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_DataALen[0]);
        WR1_ADDR(REG_0100H, &InData_DataALen[1]);
        WR1_PROG(REG_00E0H, 0x81020100U);
        WR1_PROG(REG_0000H, 0x0000580bU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_0074H, 18U, 0U);
        WR1_PROG(REG_001CH, 0x00001600U);
        WR1_PROG(REG_0074H, 0x00000000U);
        WR1_PROG(REG_00C4H, 0x00040805U);
        WR1_PROG(REG_00E0H, 0x81040080U);
        WR1_PROG(REG_0000H, 0x00002813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00D0H, 0x00000020U);
        WR1_PROG(REG_00C4H, 0x000087b5U);
        WR1_PROG(REG_0000H, 0x00002513U);
        WR1_PROG(REG_0074H, 0x00000008U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000821U);
        WR1_PROG(REG_00E0H, 0x80840001U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_00ECH, 0x3c002beaU);
            WR1_PROG(REG_00ECH, 0x12003c3fU);
            WR1_PROG(REG_00ECH, 0x00002fe0U);
        }

        WR1_PROG(REG_0104H, 0x00000362U);
        WR1_PROG(REG_00C4H, 0x00050805U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_DataT[0]);
        WR1_ADDR(REG_0100H, &InData_DataT[1]);
        WR1_ADDR(REG_0100H, &InData_DataT[2]);
        WR1_ADDR(REG_0100H, &InData_DataT[3]);
        WR1_PROG(REG_00C4H, 0x00900c45U);
        WR1_PROG(REG_00ECH, 0x00000821U);
        WR1_PROG(REG_00E0H, 0x81840001U);
        WR1_PROG(REG_0000H, 0x00002813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00000000U);
        r_tsip_func100(0x79795486U, 0x0949018cU, 0x8dac1bbcU, 0xf2d013dbU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x8842e4b4U, 0x4f825f71U, 0xb5e2949eU, 0x54504d0bU);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_AUTH_FAIL;
        }
        else
        {
            r_tsip_func102(0x75e80266U, 0x45d7913cU, 0xae922700U, 0xaaa09494U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
