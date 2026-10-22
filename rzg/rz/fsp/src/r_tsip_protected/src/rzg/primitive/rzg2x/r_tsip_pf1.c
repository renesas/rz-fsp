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

tsip_ret_t r_tsip_pf1 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_Signature[])
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

    WR1_PROG(REG_0084H, 0x0000f102U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010340U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_0104H, 0x00001768U);
    WR1_PROG(REG_00E0H, 0x8098001eU);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_Signature[iLoop + 0]);
    }

    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[iLoop + 0]);
    }

    for (iLoop = 0; iLoop < 3; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00ECH, 0x30003380U);
        WR1_PROG(REG_00ECH, 0x00070020U);
        WR1_PROG(REG_00ECH, 0x0000d3e0U);
        WR1_PROG(REG_00ECH, 0x00030040U);
        WR1_PROG(REG_00ECH, 0x0000381eU);
        WR1_PROG(REG_00ECH, 0x38000c00U);
        WR1_PROG(REG_00ECH, 0x1000d3e0U);
        WR1_PROG(REG_00ECH, 0x00050040U);
        WR1_PROG(REG_00ECH, 0x0000381eU);
        WR1_PROG(REG_00ECH, 0x000037beU);
        WR1_PROG(REG_00ECH, 0x0000a7a0U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_00ECH, 0x0000383dU);
        WR1_PROG(REG_00ECH, 0x38001001U);
        WR1_PROG(REG_00ECH, 0x1000d3e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00ECH, 0x38000fffU);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        WR1_PROG(REG_00ECH, 0x0000a7c0U);
        WR1_PROG(REG_00ECH, 0x00000020U);
    }

    WR1_PROG(REG_00ECH, 0x30000f5aU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d3e1U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x38000f9cU);
    WR1_PROG(REG_00ECH, 0x1000d3e1U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x38008be0U);
    WR1_PROG(REG_00ECH, 0x00000003U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0xf3c7d6a0U, 0xf36c1b21U, 0x727361d4U, 0xa6212ed9U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xf85c6843U, 0xf445a562U, 0xf5f9b2b6U, 0xbeee6c29U);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_0028H, 0x00870001U);
        r_tsip_func100(0x5443dea1U, 0x302fe96aU, 0xe97ee420U, 0x8a32d577U);
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
        WR1_PROG(REG_0100H, bswap_32big(0x000000f1U));
        r_tsip_func101(0xfe2af7f7U, 0x2aaeec13U, 0x5273c57fU, 0x3a4d23faU);
        r_tsip_func070(OFS_ADR);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000bcd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_0000H, 0x00003823U);
        WR1_PROG(REG_002CH, 0x00000015U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0000H, 0x00003823U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000140U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000024U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000070d0U);
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
        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000060c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000d91U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        WR1_PROG(REG_0024H, 0x00000dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x5a3c7d70U, 0x7b9e9185U, 0xafbee942U, 0x47d387fcU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x38d513c5U, 0xaac69c4eU, 0x21a7828fU, 0x8a220d05U);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_0024H, 0x000019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000100U);
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
            WR1_PROG(REG_0100H, bswap_32big(0x000000f1U));
            r_tsip_func101(0xc8897736U, 0xf45dc9b7U, 0x73c76f1cU, 0x84e97aa7U);
            r_tsip_func326();
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000094aU);
            WR1_PROG(REG_00E0H, 0x8088000aU);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000023U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00000c2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00000c2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000e0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x8000d4d0U);
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
            WR1_PROG(REG_0034H, 0x00000003U);
            WR1_PROG(REG_0024H, 0x800048d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x800103a0U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x000000f1U));
            r_tsip_func101(0x6b55833cU, 0x9994fa37U, 0xab799180U, 0x7f491fbcU);
            r_tsip_func071(OFS_ADR);
            WR1_PROG(REG_0034H, 0x00000802U);
            WR1_PROG(REG_0024H, 0x800088d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000802U);
            WR1_PROG(REG_0024H, 0x8000acd0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_00E0H, 0x8088000aU);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000025U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001028U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000e0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000100U);
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
            WR1_PROG(REG_00ECH, 0x000000f1U);
            WR1_PROG(REG_00ECH, 0x0000377cU);
            WR1_PROG(REG_00ECH, 0x00000b9cU);
            r_tsip_func100(0x83e941efU, 0x03cd8bd5U, 0xeee94638U, 0x6cb2231fU);
            WR1_PROG(REG_00E0H, 0x81010380U);
            WR1_PROG(REG_0004H, 0x00000607U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
            {
                r_tsip_func101(0x1b96a71fU, 0xf288da48U, 0xb8a5cb0aU, 0xcdc5a041U);
                r_tsip_func302();
                if (S_RAM[0] == 0x00000001U)
                {
                    break;
                }

                r_tsip_func101(0x36c57abfU, 0x0eb6e688U, 0x1dfc53feU, 0xaaaaaf75U);
            }

            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_00E0H, 0x8188000aU);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x0000001aU);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xa3e81ad4U, 0x90a41d9eU, 0x51374c00U, 0xb3661d6fU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x29428d28U, 0xa628479fU, 0x4cb8dc09U, 0x154a85f6U);
                WR1_PROG(REG_01B8H, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_0034H, 0x00000003U);
                WR1_PROG(REG_0024H, 0x800048d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x800068d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001dc0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000100U);
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
                WR1_PROG(REG_0100H, bswap_32big(0x00000006U));
                r_tsip_func101(0x50235839U, 0x91032b78U, 0x7a8ecebaU, 0xd8fb3f31U);
                r_tsip_func326();
                WR1_PROG(REG_0034H, 0x00000002U);
                WR1_PROG(REG_0024H, 0x80000dc0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000a2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000a2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800015c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000e2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000e2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000e2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000015c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001028U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000e0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000002U);
                WR1_PROG(REG_0024H, 0x800009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x800080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x0000379bU);
                r_tsip_func100(0xbe1aa391U, 0x5f79d9fcU, 0xc8a5c84cU, 0xe4a0e272U);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_00ECH, 0x000001e0U);
                WR1_PROG(REG_00C4H, 0x00080805U);
                WR1_PROG(REG_00E0H, 0x8184000aU);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0xf22b5234U, 0x7843bf54U, 0x9faaa5bbU, 0xb9aed67fU);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_0104H, 0x00000362U);
                WR1_PROG(REG_00C4H, 0x00080e15U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[0]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[1]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[2]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[3]);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x000000f1U));
                r_tsip_func101(0xf26f04c4U, 0x571000e7U, 0xe98b8bfbU, 0xe8b69edaU);
                r_tsip_func023();
                WR1_PROG(REG_0104H, 0x00000b62U);
                WR1_PROG(REG_00D0H, 0x00000200U);
                WR1_PROG(REG_00C4H, 0x02f08887U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[4]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[5]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[6]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[7]);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[8]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[9]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[10]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[11]);
                WR1_PROG(REG_0000H, 0x00003223U);
                WR1_PROG(REG_002CH, 0x00000010U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[12]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[13]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[14]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[15]);
                WR1_PROG(REG_0000H, 0x00003213U);
                WR1_PROG(REG_002CH, 0x0000001bU);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00450944U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_0104H, 0x00000362U);
                WR1_PROG(REG_00C4H, 0x00f00885U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[16]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[17]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[18]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[19]);
                WR1_PROG(REG_0000H, 0x00003213U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0104H, 0x00000362U);
                WR1_PROG(REG_00C4H, 0x00000885U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[20]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[21]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[22]);
                WR1_ADDR(REG_0100H, &InData_KeyIndex[23]);
                WR1_PROG(REG_00C4H, 0x00900c45U);
                WR1_PROG(REG_0000H, 0x00002213U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x9bc241d5U, 0xb230c536U, 0x7b51b504U, 0x77453015U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x946bf04aU, 0xaf1b392dU, 0xce8742d7U, 0x29031caaU);
                    WR1_PROG(REG_01B8H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_KEY_FAIL;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x0000082cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000011c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000002U);
                    WR1_PROG(REG_0024H, 0x80008cd0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000082cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000011c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800060c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000008U);
                    WR1_PROG(REG_0024H, 0x800011c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000002U);
                    WR1_PROG(REG_0024H, 0x800009c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000002U);
                    WR1_PROG(REG_0024H, 0x80000dc0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x8000a0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x00000080U);
                    WR1_PROG(REG_00E0H, 0x8088000aU);
                    WR1_PROG(REG_0000H, 0x00008323U);
                    WR1_PROG(REG_002CH, 0x00000022U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x000000c0U);
                    WR1_PROG(REG_00E0H, 0x8088000aU);
                    WR1_PROG(REG_0000H, 0x00008323U);
                    WR1_PROG(REG_002CH, 0x00000023U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b7e0U);
                    WR1_PROG(REG_00ECH, 0x00000100U);
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
                    WR1_PROG(REG_00ECH, 0x00000001U);
                    WR1_PROG(REG_00ECH, 0x00000b9cU);
                    r_tsip_func100(0xc87aece0U, 0xac839260U, 0x4f56a44fU, 0xe10d30ccU);
                    WR1_PROG(REG_00E0H, 0x81010380U);
                    WR1_PROG(REG_0004H, 0x00000607U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
                    for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
                    {
                        r_tsip_func101(0xc6b675e9U, 0x2f827da3U, 0x11c39115U, 0x8744a251U);
                        r_tsip_func302();
                        if (S_RAM[0] == 0x00000001U)
                        {
                            break;
                        }

                        r_tsip_func101(0x54a5d42aU, 0xbaff751fU, 0xc443b1fdU, 0x1dd0667eU);
                    }

                    WR1_PROG(REG_0024H, 0x00001dc0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000591U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_001CH, 0x00001f00U);
                    WR1_PROG(REG_001CH, 0x00210000U);
                    r_tsip_func100(0x6861bab6U, 0x597c09cfU, 0x80949565U, 0xf785263cU);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0x7aa0bbbeU, 0xff32a9b6U, 0x44f6aaf2U, 0x5395c240U);
                        WR1_PROG(REG_01B8H, 0x00000040U);
                        WAIT_STS(REG_0018H, 12U, 0U);

                        return TSIP_RET_FAIL;
                    }
                    else
                    {
                        WR1_PROG(REG_00ECH, 0x0000b540U);
                        WR1_PROG(REG_00ECH, 0x00000080U);
                        WR1_PROG(REG_00E0H, 0x8188000aU);
                        WR1_PROG(REG_0000H, 0x00003823U);
                        WR1_PROG(REG_002CH, 0x0000001aU);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
                        WR1_PROG(REG_00ECH, 0x0000b540U);
                        WR1_PROG(REG_00ECH, 0x000000c0U);
                        WR1_PROG(REG_00E0H, 0x8188000aU);
                        WR1_PROG(REG_0000H, 0x00003823U);
                        WR1_PROG(REG_002CH, 0x0000001bU);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
                        r_tsip_func305();
                        WR1_PROG(REG_0024H, 0x00001dc0U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x00000591U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_001CH, 0x00001f00U);
                        WR1_PROG(REG_001CH, 0x00210000U);
                        r_tsip_func100(0x5ad3fe8cU, 0x4c0afd06U, 0xb9041121U, 0xeae0bd6eU);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0x323da661U, 0xe6aa2a23U, 0x01833532U, 0x595cadd6U);
                            WR1_PROG(REG_01B8H, 0x00000040U);
                            WAIT_STS(REG_0018H, 12U, 0U);

                            return TSIP_RET_FAIL;
                        }
                        else
                        {
                            WR1_PROG(REG_0034H, 0x00000003U);
                            WR1_PROG(REG_0024H, 0x800048d0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0034H, 0x00000800U);
                            WR1_PROG(REG_0024H, 0x800068d0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00001dc0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000080c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019c0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00000591U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00000591U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x0000a0c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_00ECH, 0x0000b7e0U);
                            WR1_PROG(REG_00ECH, 0x00000100U);
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
                            WR1_PROG(REG_0100H, bswap_32big(0x00000007U));
                            r_tsip_func101(0xa05fd6c6U, 0x17b13504U, 0xd5acd0eeU, 0xb0739316U);
                            r_tsip_func326();
                            WR1_PROG(REG_0034H, 0x00000002U);
                            WR1_PROG(REG_0024H, 0x80000dc0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000009c0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x0000a0c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0034H, 0x00000008U);
                            WR1_PROG(REG_0024H, 0x800011c0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00000a2cU);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x100019b1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019a1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x0000082cU);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x100019b1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019a1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x0000082cU);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x100019b1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019a1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_00ECH, 0x0000b7e0U);
                            WR1_PROG(REG_00ECH, 0x00000140U);
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
                            WR1_PROG(REG_0024H, 0x000088d0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00009004U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00001028U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x100019b1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019a1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_00ECH, 0x0000b540U);
                            WR1_PROG(REG_00ECH, 0x00000000U);
                            WR1_PROG(REG_00E0H, 0x8188000aU);
                            WR1_PROG(REG_0000H, 0x00003823U);
                            WR1_PROG(REG_002CH, 0x00000014U);
                            WAIT_STS(REG_0000H, 25U, 0U);
                            WR1_PROG(REG_001CH, 0x00001800U);
                            WR1_PROG(REG_0024H, 0x000009c0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00001991U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_001CH, 0x00001f00U);
                            WR1_PROG(REG_001CH, 0x00210000U);
                            WR1_PROG(REG_0024H, 0x000019c0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00000991U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_001CH, 0x00001f00U);
                            WR1_PROG(REG_001CH, 0x00210000U);
                            r_tsip_func100(0x214dec4aU, 0x6c827926U, 0x0d0ff1dcU, 0xfcf1a400U);
                            WR1_PROG(REG_001CH, 0x00400000U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            if (CHCK_STS(REG_001CH, 22U, 1U))
                            {
                                r_tsip_func102(0x4ba3f7ecU, 0x351caeb1U, 0x67b42e9cU, 0xa6005a38U);
                                WR1_PROG(REG_01B8H, 0x00000040U);
                                WAIT_STS(REG_0018H, 12U, 0U);

                                return TSIP_RET_FAIL;
                            }
                            else
                            {
                                r_tsip_func102(0x1ee9b4b6U, 0x4aeab93bU, 0x4320e19dU, 0x91c298d0U);
                                WR1_PROG(REG_01B8H, 0x00000040U);
                                WAIT_STS(REG_0018H, 12U, 0U);

                                return TSIP_RET_PASS;
                            }
                        }
                    }
                }
            }
        }
    }
}
