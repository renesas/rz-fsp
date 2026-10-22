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

tsip_ret_t r_tsip_p01 (void)
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
    r_tsip_subprc01();

    WR1_PROG(REG_0138H, 0xf597806AU);
    WR1_PROG(REG_00F0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000001U);
    WR1_PROG(REG_010CH, 0x0000057bU);
    if (0x0U != RD1_MASK(REG_01BCH, 0x1fU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0080H, 0x00000001U);
    WR1_PROG(REG_0028H, 0x00000001U);
    WR1_PROG(REG_007CH, 0x00000001U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WR1_PROG(REG_0084H, 0x00010101U);
    WR1_PROG(REG_013CH, 0x00000F00U);
    WR1_PROG(REG_0088H, 0x00008002U);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000e3a8dU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, 0x569daf32U);
    WR1_PROG(REG_0100H, 0x272bb16aU);
    WR1_PROG(REG_0100H, 0xb6f49238U);
    WR1_PROG(REG_0100H, 0x9593be33U);
    WAIT_STS(REG_00C8H, 17U, 0U);
    WR1_PROG(REG_0088H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000f3a0dU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, 0x24014b2fU);
    WR1_PROG(REG_0100H, 0x063346bfU);
    WR1_PROG(REG_0100H, 0xb996e35bU);
    WR1_PROG(REG_0100H, 0x3786659dU);
    WR1_PROG(REG_00C4H, 0x000e3a8dU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, 0xf2e9d5ccU);
    WR1_PROG(REG_0100H, 0xb4723a64U);
    WR1_PROG(REG_0100H, 0x975a1268U);
    WR1_PROG(REG_0100H, 0xcc0319d5U);
    WAIT_STS(REG_00C8H, 17U, 0U);
    WR1_PROG(REG_00C4H, 0x000f3a8dU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, 0x873bc717U);
    WR1_PROG(REG_0100H, 0x61e62242U);
    WR1_PROG(REG_0100H, 0xfc19515bU);
    WR1_PROG(REG_0100H, 0x7c002e52U);
    WAIT_STS(REG_00C8H, 16U, 0U);
    WR1_PROG(REG_0004H, 0x00001001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_0018H, 13U, 0U))
    {
        WR1_PROG(REG_01BCH, 0x00000020U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0008H, 0x0000FFFFU);
        WR1_PROG(REG_001CH, 0x003e0000U);
        WR1_PROG(REG_00C4H, 0x000f3a8dU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, 0x230240b4U);
        WR1_PROG(REG_0100H, 0xbb867ea2U);
        WR1_PROG(REG_0100H, 0x9e6ae49eU);
        WR1_PROG(REG_0100H, 0xfb0554f4U);
        WAIT_STS(REG_00C8H, 16U, 0U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_01BCH, 0x00000020U);

            return TSIP_RET_LIFECYCLE_FAIL;
        }
        else
        {
            WR1_PROG(REG_00C4H, 0x200c3a0cU);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, 0x13cb6c7bU);
            WR1_PROG(REG_00C4H, 0x00000a8cU);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, 0x6a049496U);
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000001e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x80840000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00C4H, 0x000c3a0cU);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, 0xbb23de5aU);
            WR1_PROG(REG_00C4H, 0x00000a8cU);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, 0xe7dd8dc9U);
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000001f0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x80840000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_013CH, 0x00000291U);
            WR1_PROG(REG_00C4H, 0x000d3a8dU);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, 0xef5726d8U);
            WR1_PROG(REG_0100H, 0x1bb731d8U);
            WR1_PROG(REG_0100H, 0x86ceb9c4U);
            WR1_PROG(REG_0100H, 0x72d3a1f6U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
