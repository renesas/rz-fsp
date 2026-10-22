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

tsip_ret_t r_tsip_p34f (const uint32_t InData_Text[],
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
    r_tsip_func100(0x2bb5c26aU, 0x8913b38aU, 0x64525b29U, 0x2be70f17U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x2206bba6U, 0x5f96a6b1U, 0x6fb5c1d6U, 0x9397b2caU);
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
        r_tsip_func100(0x0e5d2a25U, 0x6f05ebdcU, 0x183d9b25U, 0xd910aa26U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00B0H, 0x40000020U);
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

            r_tsip_func100(0x538fe34fU, 0x52c66137U, 0x2261f6ebU, 0x57c06f84U);
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
            r_tsip_func101(0xa44e3608U, 0x7a5e0a80U, 0xd6e2d23fU, 0xc65cbe6dU);
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
        r_tsip_func100(0xe1f3387cU, 0xb5aef54cU, 0xebf9ea61U, 0xb22b984eU);
        WR1_PROG(REG_00B0H, 0x40000020U);
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
        r_tsip_func102(0xae4b93e6U, 0x36a54bcbU, 0x4d4d35cbU, 0xcb7f3d87U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
