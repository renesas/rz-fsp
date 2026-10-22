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

tsip_ret_t r_tsip_p29f (const uint32_t InData_Text[],
                        const uint32_t InData_DataALen[],
                        const uint32_t InData_TextLen[],
                        uint32_t       OutData_Text[],
                        uint32_t       OutData_DataT[])
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
    r_tsip_func100(0x74c1e9aaU, 0x274691caU, 0x7368ff16U, 0x5f6719d4U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x854f4cb3U, 0x32765ad4U, 0x84bc2b03U, 0x024b74b0U);
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
        r_tsip_func100(0xea094f36U, 0x457c0563U, 0xe6440d06U, 0xbbabea3eU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00B0H, 0x00000020U);
            WR1_PROG(REG_00A4H, 0x000087b5U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_Text[0]);
            WR1_ADDR(REG_0100H, &InData_Text[1]);
            WR1_ADDR(REG_0100H, &InData_Text[2]);
            WR1_ADDR(REG_0100H, &InData_Text[3]);
            WR1_PROG(REG_00ECH, 0x00000821U);
            WR1_PROG(REG_00E0H, 0x80840001U);
            WR1_PROG(REG_0000H, 0x00008113U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x3c002be0U);
                WR1_PROG(REG_00ECH, 0x12003c3fU);
                WR1_PROG(REG_00ECH, 0x00002fe0U);
            }

            r_tsip_func100(0x8215e765U, 0xbea37f7bU, 0x36d6ccd4U, 0xc5392cd5U);
            WR1_PROG(REG_00A4H, 0x00000885U);
            WR1_PROG(REG_00ECH, 0x00000821U);
            WR1_PROG(REG_00E0H, 0x81840001U);
            WR1_PROG(REG_0000H, 0x00004813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0004H, 0x00000113U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &OutData_Text[0]);
            RD1_ADDR(REG_0100H, &OutData_Text[1]);
            RD1_ADDR(REG_0100H, &OutData_Text[2]);
            RD1_ADDR(REG_0100H, &OutData_Text[3]);
            r_tsip_func101(0xc4135694U, 0x182dade7U, 0xd515c600U, 0x2e829e60U);
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
        WR1_PROG(REG_00A4H, 0x00040805U);
        WR1_PROG(REG_00E0H, 0x81040080U);
        WR1_PROG(REG_0000H, 0x00001813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x551c2ebbU, 0x8380ec94U, 0x1a59c2f2U, 0x33352b68U);
        WR1_PROG(REG_00B0H, 0x00000020U);
        WR1_PROG(REG_00A4H, 0x000087b5U);
        WR1_PROG(REG_0000H, 0x00001513U);
        WR1_PROG(REG_0074H, 0x00000008U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000113U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_DataT[0]);
        RD1_ADDR(REG_0100H, &OutData_DataT[1]);
        RD1_ADDR(REG_0100H, &OutData_DataT[2]);
        RD1_ADDR(REG_0100H, &OutData_DataT[3]);
        r_tsip_func102(0xa0f6b955U, 0xf4f5842bU, 0x51763ef9U, 0x4fceb530U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
