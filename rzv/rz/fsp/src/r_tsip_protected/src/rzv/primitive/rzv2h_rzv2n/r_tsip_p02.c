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

tsip_ret_t r_tsip_p02 (void)
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

    WR1_PROG(REG_0084H, 0x00000202U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00093b8cU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b8471dU));
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00070804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00ECH, 0x3000a820U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000003U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000821U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00002008U);
    WR1_PROG(REG_00ECH, 0x00000863U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000884U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000008a5U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b4c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000013U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b4e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000348U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b500U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000000b7U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
    {
        r_tsip_func100(0x994c181dU, 0xc88fbd34U, 0x80bc4492U, 0x8383b32dU);
        WR1_PROG(REG_00ECH, 0x00007c01U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_001CH, 0x00600000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WAIT_STS(REG_0064H, 11U, 0U);
            WR1_PROG(REG_0064H, 0x0020901cU);
            r_tsip_func101(0x4ed31396U, 0xec7a9c79U, 0x3babc3daU, 0xdcbdabe5U);
        }
        else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WAIT_STS(REG_0064H, 11U, 0U);
            WR1_PROG(REG_0064H, 0x0020901eU);
            r_tsip_func101(0xf0ed1358U, 0x1ef5a90cU, 0xdd05ceefU, 0xdf5a909aU);
        }
        else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WAIT_STS(REG_0064H, 11U, 0U);
            WR1_PROG(REG_0064H, 0x0020901dU);
            r_tsip_func101(0xe56f1bf1U, 0xa72c9360U, 0x3b53a0a5U, 0xd257548cU);
        }

        WR1_PROG(REG_00C4H, 0x41001e5eU);
        WR1_PROG(REG_0000H, 0x80002401U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_001CH, 0x00001200U);
        WAIT_STS(REG_0000H, 30U, 0U);
        WR1_PROG(REG_0000H, 0x00000001U);
        WR1_PROG(REG_00C4H, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x0010B008U);
        WR1_PROG(REG_00ECH, 0x00000800U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80900000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008443U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000038a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00003405U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00002804U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x342028e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x10005066U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x34202808U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x10005066U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00003485U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x6d5b9865U, 0x15768c80U, 0xb750460aU, 0x01299357U);
    }

    WR1_PROG(REG_00ECH, 0x0000b4e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000B50U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000842U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000008c6U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b4a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x01003804U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x342028e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x10005066U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00002440U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00002cc0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00002485U);
        WR1_PROG(REG_01D0H, 0x00000000U);
    }

    WR1_PROG(REG_00ECH, 0x00002c20U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38008840U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00002000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b4e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000033U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000003cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01003804U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x342028e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x10005066U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00002cc0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000003eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01003804U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x342028e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x10005066U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38000c63U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x9e47007fU, 0xaa1f34e5U, 0x8c6c2f77U, 0xc5a48556U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x86e2bf84U, 0xec543854U, 0xe291898aU, 0xef8ede73U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_RETRY;
    }
    else
    {
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x0000001cU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000cc4U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00E0H, 0x80040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00D0H, 0x00000600U);
        WR1_PROG(REG_00C4H, 0x43009e5fU);
        WR1_PROG(REG_0000H, 0x00002473U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x41001eddU);
        WR1_PROG(REG_0000H, 0x00002413U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80040080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x40ff6abdU, 0xbb0a9b72U, 0xbb6970c4U, 0xbddb3f5aU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x000b0804U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0104H, 0x00000352U);
        WR1_PROG(REG_00C4H, 0x00070805U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0100H, bswap_32big(0x00000001U));
        r_tsip_func100(0xb4fedac2U, 0xa6eeb859U, 0x58c96dc1U, 0x60cdae6bU);
        WR1_PROG(REG_00D0H, 0x00000100U);
        WR1_PROG(REG_00C4H, 0x0100b7f7U);
        WR1_PROG(REG_00E0H, 0x81080000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00002823U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x000b0805U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00070805U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x0025feb7U, 0x5eedba10U, 0xf4125b75U, 0x311b09cfU);
        r_tsip_func103();
        r_tsip_func100(0x294a72aeU, 0x55026593U, 0x3c28f593U, 0xda338a60U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x010d0c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0xce6667ceU, 0xea6dcb31U, 0xc4f06122U, 0x56294327U);
        r_tsip_func103();
        r_tsip_func100(0x996e2349U, 0xdb78cef2U, 0x67cbc1d0U, 0xaa13d545U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0004H, 0x00000212U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[16]);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[17]);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[18]);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[19]);
        WR1_PROG(REG_013CH, 0x00000202U);
        r_tsip_func102(0x622cb761U, 0xaf038fd4U, 0x5805ac34U, 0x9d8864abU);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
