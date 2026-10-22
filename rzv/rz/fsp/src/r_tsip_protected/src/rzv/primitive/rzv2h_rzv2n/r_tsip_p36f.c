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

tsip_ret_t r_tsip_p36f (const uint32_t InData_Text[],
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_TextLen[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_TextLen[1]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b580U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000007FU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b5a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0xFFFFFF00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0c0029a9U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x04a02988U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_DataTLen[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38008940U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000010U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x34202beaU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    r_tsip_func100(0xeeec8a8bU, 0x0337288bU, 0xf0aeb716U, 0x6af9c2b4U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x4f864a60U, 0x04e9f347U, 0x4c4c095fU, 0xe43960aaU);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00ECH, 0x00003409U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00036800U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x08008c00U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000000fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x6985a2f8U, 0xf0c8d986U, 0xc2605729U, 0x3427b6c3U);
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
            WR1_PROG(REG_00D0H, 0x40000020U);
            WR1_PROG(REG_00C4H, 0x000087b5U);
            WR1_PROG(REG_0000H, 0x00007113U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000821U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x80840001U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x3c002be0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x12003c3fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00002fe0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
            }

            r_tsip_func100(0x5aec732eU, 0xbc87d82fU, 0x8903a731U, 0x581b3e29U);
            WR1_PROG(REG_00C4H, 0x00000885U);
            WR1_PROG(REG_00ECH, 0x00000821U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81840001U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00002813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0004H, 0x00000213U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &OutData_Text[0]);
            RD1_ADDR(REG_0100H, &OutData_Text[1]);
            RD1_ADDR(REG_0100H, &OutData_Text[2]);
            RD1_ADDR(REG_0100H, &OutData_Text[3]);
            r_tsip_func101(0x5dfbdd91U, 0xd884649dU, 0xfc8f160eU, 0xbbc53e8bU);
        }

        WR1_PROG(REG_0104H, 0x00000164U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_DataALen[0]);
        WR1_ADDR(REG_0100H, &InData_DataALen[1]);
        WR1_PROG(REG_00E0H, 0x81020100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x0000580bU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_0074H, 18U, 0U);
        WR1_PROG(REG_001CH, 0x00001600U);
        WR1_PROG(REG_0074H, 0x00000000U);
        WR1_PROG(REG_00C4H, 0x00040805U);
        WR1_PROG(REG_00E0H, 0x81040080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00002813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00D0H, 0x40000020U);
        WR1_PROG(REG_00C4H, 0x000087b5U);
        WR1_PROG(REG_0000H, 0x00002513U);
        WR1_PROG(REG_0074H, 0x00000008U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000821U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80840001U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_00ECH, 0x3c002beaU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x12003c3fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00002fe0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81840001U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00002813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func100(0x4c6d8f7bU, 0xe07ff1ddU, 0xcc61d64fU, 0x9d815da7U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x9ee6f362U, 0x4e385942U, 0xd9130b5dU, 0x614fb926U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_AUTH_FAIL;
        }
        else
        {
            r_tsip_func102(0x67b8f79cU, 0xf3183001U, 0x8fac0d82U, 0xd8d296f6U);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
