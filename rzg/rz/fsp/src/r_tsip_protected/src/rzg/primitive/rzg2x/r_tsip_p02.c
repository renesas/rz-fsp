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
    r_tsip_func100(0x919ed1f4U, 0x3c0a3271U, 0xa2cff35dU, 0xaba633f6U);
    WR1_PROG(REG_010CH, 0x0010057bU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00093b8cU);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01645957U));
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00070804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00ECH, 0x3000a820U);
    WR1_PROG(REG_00ECH, 0x00000003U);
    WR1_PROG(REG_00ECH, 0x00010020U);
    WR1_PROG(REG_00ECH, 0x00000821U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00000008U);
    WAIT_STS(REG_0064H, 11U, 0U);
    WR1_PROG(REG_0064H, 0x00002008U);
    WR1_PROG(REG_00ECH, 0x00000863U);
    WR1_PROG(REG_00ECH, 0x00000884U);
    WR1_PROG(REG_00ECH, 0x000008a5U);
    WR1_PROG(REG_00ECH, 0x0000b4c0U);
    WR1_PROG(REG_00ECH, 0x00000013U);
    WR1_PROG(REG_00ECH, 0x0000b4e0U);
    WR1_PROG(REG_00ECH, 0x00000348U);
    WR1_PROG(REG_00ECH, 0x0000b500U);
    WR1_PROG(REG_00ECH, 0x000000b7U);
    for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
    {
        r_tsip_func100(0x183b8b38U, 0x8b2089f9U, 0x4cbad6c8U, 0x46d448fdU);
        WR1_PROG(REG_00ECH, 0x00007c01U);
        WR1_PROG(REG_001CH, 0x00600000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WAIT_STS(REG_0064H, 11U, 0U);
            WR1_PROG(REG_0064H, 0x0020901cU);
            r_tsip_func101(0xb6f05053U, 0x7bb72e3bU, 0xc12f39f7U, 0x08f2c074U);
        }
        else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WAIT_STS(REG_0064H, 11U, 0U);
            WR1_PROG(REG_0064H, 0x0020901eU);
            r_tsip_func101(0x4593f664U, 0x67b8355eU, 0x17caecd5U, 0xaf9fa4aaU);
        }
        else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WAIT_STS(REG_0064H, 11U, 0U);
            WR1_PROG(REG_0064H, 0x0020901dU);
            r_tsip_func101(0x270a8504U, 0x4fa3374bU, 0x52a5fdfdU, 0x8413b05bU);
        }

        WR1_PROG(REG_00C4H, 0x41001e5eU);
        WR1_PROG(REG_0000H, 0x80002401U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_001CH, 0x00001200U);
        WAIT_STS(REG_0000H, 30U, 0U);
        WR1_PROG(REG_0000H, 0x00000001U);
        WR1_PROG(REG_00C4H, 0x00000000U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x0010B008U);
        WR1_PROG(REG_00ECH, 0x00000800U);
        WR1_PROG(REG_00E0H, 0x80900000U);
        WR1_PROG(REG_0000H, 0x00008443U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000038a0U);
        WR1_PROG(REG_00ECH, 0x00003405U);
        WR1_PROG(REG_00ECH, 0x00002804U);
        WR1_PROG(REG_00ECH, 0x342028e0U);
        WR1_PROG(REG_00ECH, 0x10005066U);
        WR1_PROG(REG_00ECH, 0x34202808U);
        WR1_PROG(REG_00ECH, 0x10005066U);
        WR1_PROG(REG_00ECH, 0x00003485U);
        r_tsip_func101(0x640b18caU, 0xab210feaU, 0x85b24fffU, 0xd0ed982bU);
    }

    WR1_PROG(REG_00ECH, 0x0000b4e0U);
    WR1_PROG(REG_00ECH, 0x00000B50U);
    WR1_PROG(REG_00ECH, 0x00000842U);
    WR1_PROG(REG_00ECH, 0x000008c6U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x0000b4a0U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x01003804U);
        WR1_PROG(REG_00ECH, 0x342028e0U);
        WR1_PROG(REG_00ECH, 0x10005066U);
        WR1_PROG(REG_00ECH, 0x00002440U);
        WR1_PROG(REG_00ECH, 0x00002cc0U);
        WR1_PROG(REG_00ECH, 0x00002485U);
    }

    WR1_PROG(REG_00ECH, 0x00002c20U);
    WR1_PROG(REG_00ECH, 0x38008840U);
    WR1_PROG(REG_00ECH, 0x00002000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    WR1_PROG(REG_00ECH, 0x0000b4e0U);
    WR1_PROG(REG_00ECH, 0x00000033U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_00ECH, 0x0000003cU);
    WR1_PROG(REG_00ECH, 0x01003804U);
    WR1_PROG(REG_00ECH, 0x342028e0U);
    WR1_PROG(REG_00ECH, 0x10005066U);
    WR1_PROG(REG_00ECH, 0x00002cc0U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_00ECH, 0x0000003eU);
    WR1_PROG(REG_00ECH, 0x01003804U);
    WR1_PROG(REG_00ECH, 0x342028e0U);
    WR1_PROG(REG_00ECH, 0x10005066U);
    WR1_PROG(REG_00ECH, 0x38008860U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x391ac89cU, 0xa8067ecdU, 0x68fc90cfU, 0x63ddb9eaU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x1b7474c7U, 0xac06e636U, 0x6b37436aU, 0x60d6cff7U);
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
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x41001eddU);
        WR1_PROG(REG_0000H, 0x00002413U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_0064H, 11U, 0U);
        WR1_PROG(REG_0064H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80040080U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0xb902caafU, 0x31e777dfU, 0x4e788befU, 0xfcfaa3dcU);
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
        r_tsip_func100(0xe2ef5eecU, 0xa8590e71U, 0x4d59dc17U, 0x76b8da49U);
        WR1_PROG(REG_00D0H, 0x00000100U);
        WR1_PROG(REG_00C4H, 0x0100b7f7U);
        WR1_PROG(REG_00E0H, 0x81080000U);
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
        r_tsip_func100(0xe23cd6f5U, 0xd4224126U, 0xbdb83ccbU, 0x58694402U);
        r_tsip_func103();
        r_tsip_func100(0x130ebfe0U, 0xd69c7795U, 0xc74b13edU, 0xf2b69c13U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x010d0c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0x4ee37152U, 0xc84ef14cU, 0x976fac3aU, 0xef24f1ccU);
        r_tsip_func103();
        r_tsip_func100(0x485fe41cU, 0xb44b0f8dU, 0x2467844fU, 0x0cad1defU);
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
        r_tsip_func102(0x06b456adU, 0x1fa62b8eU, 0xe287fb66U, 0x6988158bU);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
