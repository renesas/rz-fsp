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
    WR1_PROG(REG_0088H, 0x00008001U);
    WR1_PROG(REG_0104H, 0x00000352U);
    r_tsip_func101(bswap_32big(0x84439908U),
                   bswap_32big(0x06b9f8eaU),
                   bswap_32big(0x8c0dddd4U),
                   bswap_32big(0xed040894U));
    WR1_PROG(REG_0088H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000f3a0dU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, 0x5e48456dU);
    WR1_PROG(REG_0100H, 0x360b0072U);
    WR1_PROG(REG_0100H, 0x39efc3d8U);
    WR1_PROG(REG_0100H, 0x636a621dU);
    r_tsip_func101(bswap_32big(0x15fbe7f9U),
                   bswap_32big(0xef77343cU),
                   bswap_32big(0x4bc04ff8U),
                   bswap_32big(0x6a3f848aU));
    r_tsip_func100(bswap_32big(0xb488b55cU),
                   bswap_32big(0xefb7fc31U),
                   bswap_32big(0x97c6f5c0U),
                   bswap_32big(0xcddba304U));
    WR1_PROG(REG_0004H, 0x00001001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_0018H, 13U, 0U))
    {
        WR1_PROG(REG_01BCH, 0x00000020U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00C4H, 0x200c3a0cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, 0x45f89f31U);
        WR1_PROG(REG_00C4H, 0x00000a8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, 0xa105739aU);
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
        WR1_PROG(REG_0100H, 0x7621230fU);
        WR1_PROG(REG_00C4H, 0x00000a8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, 0xe8cd442fU);
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
        r_tsip_func102(bswap_32big(0x5c6d3a40U), bswap_32big(0x1fa784dbU), bswap_32big(0x6b71d80fU),
                       bswap_32big(0x0c7f8829U));
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
