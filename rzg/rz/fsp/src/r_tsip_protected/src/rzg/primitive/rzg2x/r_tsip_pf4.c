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

tsip_ret_t r_tsip_pf4 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
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
    if (0x0U != RD1_MASK(REG_01B8H, 0x1eU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x0000f402U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010340U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x3020ab80U);
    WR1_PROG(REG_00ECH, 0x00000003U);
    WR1_PROG(REG_00ECH, 0x00060020U);
    WR1_PROG(REG_00ECH, 0x0000b780U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00ECH, 0x30000f5aU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d3e1U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x38000f9cU);
    WR1_PROG(REG_00ECH, 0x1000d3e1U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x38008be0U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x92398d07U, 0xe67a84b9U, 0xdf15052dU, 0x0697ab70U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x3139f23cU, 0x10369134U, 0x78170c48U, 0xffce1fa6U);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0xd001bad4U, 0x7d50f0b8U, 0x5f4047f8U, 0x4ba413d5U);
        WR1_PROG(REG_0028H, 0x00870001U);
        WR1_PROG(REG_00ECH, 0x30003340U);
        WR1_PROG(REG_00ECH, 0x00010020U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_00ECH, 0x0000031CU);
        WR1_PROG(REG_00ECH, 0x00070040U);
        WR1_PROG(REG_00ECH, 0x30003380U);
        WR1_PROG(REG_00ECH, 0x00070020U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00ECH, 0x00030040U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_00ECH, 0x0000013CU);
        WR1_PROG(REG_00ECH, 0x00050040U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_00ECH, 0x000001F8U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x81010000U);
        WR1_PROG(REG_0004H, 0x00000606U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        OFS_ADR = S_RAM[0];
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x000000f4U));
        r_tsip_func101(0x0b3d91a5U, 0x580c2306U, 0x29597f89U, 0x75ddc92bU);
        r_tsip_func070(OFS_ADR);
        r_tsip_func100(0xb4677774U, 0xd6459bdbU, 0x2751ca6eU, 0x3cfa7271U);
        WR1_PROG(REG_0034H, 0x00000003U);
        WR1_PROG(REG_0024H, 0x800068d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000025U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000023U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000024U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x8000c0d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00890001U);
        r_tsip_func103();
        r_tsip_func100(0x01e6bbddU, 0xd17f8866U, 0xf67b6dc6U, 0xfee009f4U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0000H, 0x00003213U);
        WR1_PROG(REG_002CH, 0x00000011U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func103();
        r_tsip_func100(0x3fec3d50U, 0x04e323f7U, 0x7a5a4020U, 0xb9c37b81U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0000H, 0x00003213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func103();
        r_tsip_func100(0x6f1ec72bU, 0xb7a5062eU, 0x68ec5231U, 0xc2697509U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0000H, 0x0000320bU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0000H, 0x0000020bU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00007c1cU);
        WR1_PROG(REG_001CH, 0x00600000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WR1_PROG(REG_0028H, 0x00890001U);
            r_tsip_func101(0x69f304a1U, 0x7d3bab43U, 0x2482c1b5U, 0x3fafb2e3U);
        }
        else if (0x01000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WR1_PROG(REG_0028H, 0x00880001U);
            r_tsip_func101(0x06543467U, 0xc25676beU, 0xe0f64b44U, 0x81b5b043U);
        }
        else if (0x02000000U == RD1_MASK(REG_001CH, 0xff000000U))
        {
            WR1_PROG(REG_0028H, 0x00870001U);
            r_tsip_func101(0xd8771ffaU, 0xb9826adbU, 0x4fbdde0eU, 0xed55a364U);
        }

        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x0000a206U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x000016c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000682U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c2U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00870001U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000140U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x000000f4U));
        r_tsip_func101(0x7f0d7047U, 0x91e6dc72U, 0x03e476dbU, 0x793bd9e0U);
        r_tsip_func071(OFS_ADR);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x800088d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x8000acd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000dcd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000084d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00021028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00008cd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000e0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func100(0xdcc1ba89U, 0x34b00886U, 0xdf646b20U, 0x0f616527U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8188001fU);
        WR1_PROG(REG_0000H, 0x00003823U);
        WR1_PROG(REG_002CH, 0x00000014U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000084d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00021028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func103();
        r_tsip_func100(0x2bca5ca0U, 0xa2ad182cU, 0x8da42ec9U, 0xc8cc76ebU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0000H, 0x00003213U);
        WR1_PROG(REG_002CH, 0x00000013U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func103();
        r_tsip_func100(0x4fba34d1U, 0xd171fbb2U, 0x1f92e037U, 0x83896760U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0000H, 0x00003213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00000c28U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000060c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000015c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000d41U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00E0H, 0x8188001fU);
        WR1_PROG(REG_0000H, 0x00003823U);
        WR1_PROG(REG_002CH, 0x00000014U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000084d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00021028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000023U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_00ECH, 0x00000842U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_00ECH, 0x0000b480U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_00ECH, 0x000000f4U);
        WR1_PROG(REG_00ECH, 0x0000377cU);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
        {
            r_tsip_func101(0x4719ad5aU, 0xd0b4eecfU, 0xd740e69bU, 0x15b628c9U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0x55f0e7a9U, 0x5895de00U, 0x3b8514cbU, 0x2be45460U);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xf03ebbbeU, 0x37b6bd83U, 0xc7087e2aU, 0xf49338cfU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x5c013a7bU, 0x5f0b7f37U, 0xb1154ec9U, 0xf1840b07U);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x00000013U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000028U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000029U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000025U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0034H, 0x00000802U);
            WR1_PROG(REG_0024H, 0x800088d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000802U);
            WR1_PROG(REG_0024H, 0x8000acd0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x00000012U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00000828U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000e0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000acd0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func100(0x4179b1d3U, 0x811a46feU, 0x03cd2e5bU, 0x1d1574deU);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000bdeU);
            WR1_PROG(REG_00ECH, 0x00000842U);
            WR1_PROG(REG_00ECH, 0x0000b420U);
            WR1_PROG(REG_00ECH, 0x00000004U);
            WR1_PROG(REG_00ECH, 0x0000b480U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_00ECH, 0x0000b7a0U);
            WR1_PROG(REG_00ECH, 0x00000005U);
            WR1_PROG(REG_00ECH, 0x00000b9cU);
            WR1_PROG(REG_00E0H, 0x81010380U);
            WR1_PROG(REG_0004H, 0x00000607U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
            {
                r_tsip_func101(0x47a68385U, 0xed1a6dadU, 0x7651fc27U, 0xead96c75U);
                r_tsip_func300();
                if (S_RAM[0] == 0x00000001U)
                {
                    break;
                }

                r_tsip_func101(0x8d1b8009U, 0x221fff76U, 0x12a6080fU, 0xd7845bccU);
            }

            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x4435d99cU, 0xbcd7fadeU, 0x95764b81U, 0xa9aede11U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x6c7f0554U, 0x56cc1ff6U, 0xb7d70a0dU, 0xe1bfcdedU);
                WR1_PROG(REG_01B8H, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_0024H, 0x00009cd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x00000bffU);
                WR1_PROG(REG_00E0H, 0x8088001fU);
                WR1_PROG(REG_0000H, 0x00008323U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7c0U);
                WR1_PROG(REG_00ECH, 0x00000008U);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x000000f4U));
                r_tsip_func101(0x1d3279e0U, 0x154d99ccU, 0x81ddbc76U, 0x0477f24cU);
                r_tsip_func326();
                r_tsip_func301();
                WR1_PROG(REG_0024H, 0x000019c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000d91U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x8000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000040U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x0000001aU);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0034H, 0x0000000aU);
                WR1_PROG(REG_0024H, 0x80000a2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x800060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x800088d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x0000000aU);
                WR1_PROG(REG_0024H, 0x8000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x800040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000080U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000018U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x000000c0U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000019U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000100U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000015U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func305();
                WR1_PROG(REG_0024H, 0x00001dc0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00001f00U);
                WR1_PROG(REG_001CH, 0x00210000U);
                r_tsip_func100(0x42ef79c3U, 0x005ca04eU, 0x554e6937U, 0xddb41eb5U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0xf3689755U, 0xf19ff9b2U, 0x6414f2d0U, 0x62f0258aU);
                    WR1_PROG(REG_01B8H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x00009cd0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000591U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000591U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000a0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x00000bffU);
                    WR1_PROG(REG_00E0H, 0x8088001fU);
                    WR1_PROG(REG_0000H, 0x00008323U);
                    WR1_PROG(REG_002CH, 0x00000021U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b7c0U);
                    WR1_PROG(REG_00ECH, 0x00000008U);
                    WR1_PROG(REG_0104H, 0x00000058U);
                    WR1_PROG(REG_00E0H, 0x800103a0U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000008U));
                    r_tsip_func101(0xcca1e21aU, 0x1e34ca4dU, 0xa4a02e26U, 0xe92bb0eeU);
                    r_tsip_func326();
                    r_tsip_func301();
                    r_tsip_func100(0x84603907U, 0xcf10b6a0U, 0xe576f00bU, 0x0074da4fU);
                    r_tsip_func103();
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
                    r_tsip_func100(0x8232a88fU, 0x225fef31U, 0x8597d400U, 0x3a4f9c15U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x000001e0U);
                    WR1_PROG(REG_00C4H, 0x00080805U);
                    WR1_PROG(REG_00E0H, 0x8184000aU);
                    WR1_PROG(REG_0000H, 0x00002813U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0x5b373a85U, 0xc5404783U, 0x367847a7U, 0xd096c2ebU);
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x00440a04U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x00080e15U);
                    WR1_PROG(REG_00E0H, 0x81040000U);
                    WR1_PROG(REG_0000H, 0x00002813U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000379bU);
                    WR1_PROG(REG_0104H, 0x00000058U);
                    WR1_PROG(REG_00E0H, 0x800103a0U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x000000f4U));
                    r_tsip_func101(0x858d806fU, 0x1d937409U, 0x9c42c2a1U, 0x5b935122U);
                    r_tsip_func022();
                    r_tsip_func100(0xb95d19d5U, 0xde3fd76aU, 0x6cc62dbdU, 0x1dd56a69U);
                    WR1_PROG(REG_00D0H, 0x00000100U);
                    WR1_PROG(REG_00C4H, 0x02e087b7U);
                    WR1_PROG(REG_00ECH, 0x0000b7e0U);
                    WR1_PROG(REG_00ECH, 0x00000140U);
                    WR1_PROG(REG_00E0H, 0x8188001fU);
                    WR1_PROG(REG_0000H, 0x00002823U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0004H, 0x00000222U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[4]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[5]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[6]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[7]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[8]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[9]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[10]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[11]);
                    r_tsip_func100(0x80e4eb7fU, 0x67a84755U, 0xadb3c7f1U, 0xb4327cbfU);
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x00000c84U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x000009c5U);
                    WR1_PROG(REG_0000H, 0x00002213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0004H, 0x00000212U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[12]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[13]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[14]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[15]);
                    r_tsip_func100(0x54113667U, 0x55caf9baU, 0x71e92b6eU, 0x80f14768U);
                    WR1_PROG(REG_00E0H, 0x81040000U);
                    WR1_PROG(REG_0004H, 0x00000612U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[0]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[1]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[2]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[3]);
                    r_tsip_func100(0x102dc06cU, 0xd7dde5f2U, 0xb6309649U, 0xd5e121bdU);
                    r_tsip_func103();
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
                    r_tsip_func100(0xe839f059U, 0x5562e331U, 0x2627b77eU, 0x8d2c8501U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x000001e0U);
                    WR1_PROG(REG_00C4H, 0x00080805U);
                    WR1_PROG(REG_00E0H, 0x8184000aU);
                    WR1_PROG(REG_0000H, 0x00002813U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0xaabcb295U, 0x2046f90fU, 0xb5d7611bU, 0xeaf943f9U);
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
                    WR1_PROG(REG_0100H, bswap_32big(0x000000f4U));
                    r_tsip_func101(0x6b4df6d1U, 0x5998c7faU, 0xb6fcc0acU, 0x7d742c46U);
                    r_tsip_func023();
                    r_tsip_func100(0x9987d815U, 0x2428a1a7U, 0x733ff0c4U, 0xe013f5bfU);
                    WR1_PROG(REG_00D0H, 0x00000200U);
                    WR1_PROG(REG_00C4H, 0x02e08887U);
                    WR1_PROG(REG_0000H, 0x00002323U);
                    WR1_PROG(REG_002CH, 0x00000022U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0000H, 0x00002313U);
                    WR1_PROG(REG_002CH, 0x00000023U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0004H, 0x00000232U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[4]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[5]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[6]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[7]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[8]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[9]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[10]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[11]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[12]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[13]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[14]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[15]);
                    r_tsip_func100(0x05fb574aU, 0xb16b9866U, 0x85a0cd74U, 0xcafd4e61U);
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x00450944U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x00e00885U);
                    WR1_PROG(REG_0000H, 0x00002313U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x00000cc4U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_0004H, 0x00000222U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[16]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[17]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[18]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[19]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[20]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[21]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[22]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[23]);
                    r_tsip_func100(0x84bcb76cU, 0x45f48b19U, 0xc39caa45U, 0x425d4721U);
                    WR1_PROG(REG_00E0H, 0x81040000U);
                    WR1_PROG(REG_0004H, 0x00000612U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[0]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[1]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[2]);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[3]);
                    r_tsip_func102(0x30aa77e9U, 0x51e6ea68U, 0xdde9afe8U, 0xededd1f2U);
                    WR1_PROG(REG_01B8H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_PASS;
                }
            }
        }
    }
}
