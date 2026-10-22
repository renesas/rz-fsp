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

tsip_ret_t r_tsip_pf6 (const uint32_t InData_CurveType[],
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

    WR1_PROG(REG_0084H, 0x0000f602U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x00ddb417U, 0x9f022705U, 0x51175941U, 0xe8a702faU);
    WR1_PROG(REG_0028H, 0x008b0001U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010340U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_00ECH, 0x38000f5aU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x000002B4U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x000003D8U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x81010000U);
    WR1_PROG(REG_0004H, 0x00000606U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    OFS_ADR = S_RAM[0];
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000f6U));
    r_tsip_func101(0x2dabac9dU, 0x8878d300U, 0x514f19f2U, 0xe3b89e62U);
    r_tsip_func027(OFS_ADR);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x80006cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000bcd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000015U);
    WR1_PROG(REG_0104H, 0x00000b67U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Signature[0]);
    WR1_ADDR(REG_0100H, &InData_Signature[1]);
    WR1_ADDR(REG_0100H, &InData_Signature[2]);
    WR1_ADDR(REG_0100H, &InData_Signature[3]);
    WR1_ADDR(REG_0100H, &InData_Signature[4]);
    WR1_ADDR(REG_0100H, &InData_Signature[5]);
    WR1_ADDR(REG_0100H, &InData_Signature[6]);
    WR1_ADDR(REG_0100H, &InData_Signature[7]);
    WR1_ADDR(REG_0100H, &InData_Signature[8]);
    WR1_ADDR(REG_0100H, &InData_Signature[9]);
    WR1_ADDR(REG_0100H, &InData_Signature[10]);
    WR1_ADDR(REG_0100H, &InData_Signature[11]);
    WR1_PROG(REG_002CH, 0x00000010U);
    WR1_PROG(REG_0104H, 0x00000b67U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Signature[12]);
    WR1_ADDR(REG_0100H, &InData_Signature[13]);
    WR1_ADDR(REG_0100H, &InData_Signature[14]);
    WR1_ADDR(REG_0100H, &InData_Signature[15]);
    WR1_ADDR(REG_0100H, &InData_Signature[16]);
    WR1_ADDR(REG_0100H, &InData_Signature[17]);
    WR1_ADDR(REG_0100H, &InData_Signature[18]);
    WR1_ADDR(REG_0100H, &InData_Signature[19]);
    WR1_ADDR(REG_0100H, &InData_Signature[20]);
    WR1_ADDR(REG_0100H, &InData_Signature[21]);
    WR1_ADDR(REG_0100H, &InData_Signature[22]);
    WR1_ADDR(REG_0100H, &InData_Signature[23]);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_0000H, 0x00008333U);
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
    r_tsip_func100(0xfd607a88U, 0x754a342bU, 0x5befe11eU, 0xf491820fU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x33c96b60U, 0x4f529bb6U, 0x3f9f0382U, 0x07081384U);
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
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_00ECH, 0x0000000cU);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x000000f6U));
        r_tsip_func101(0xd7d72eb1U, 0x7171a19fU, 0xdaaf133cU, 0x36197013U);
        r_tsip_func326();
        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000060c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_00E0H, 0x808c000aU);
        WR1_PROG(REG_0000H, 0x00008333U);
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
        WR1_PROG(REG_002CH, 0x00000010U);
        WR1_PROG(REG_0104H, 0x00000b67U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[0]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[1]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[2]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[3]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[4]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[5]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[6]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[7]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[8]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[9]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[10]);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[11]);
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
        WR1_PROG(REG_0034H, 0x00000002U);
        WR1_PROG(REG_0024H, 0x80004cd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x000000f6U));
        r_tsip_func101(0x0d1e60e9U, 0xde96cf88U, 0x7e9851e5U, 0xff509557U);
        r_tsip_func028(OFS_ADR);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x800088d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x8000acd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b540U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_00E0H, 0x808c000aU);
        WR1_PROG(REG_0000H, 0x00008333U);
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
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_00ECH, 0x00000842U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_00ECH, 0x0000b480U);
        WR1_PROG(REG_00ECH, 0x00000180U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_00ECH, 0x000000f6U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        r_tsip_func100(0xdbdf1d1eU, 0x6612e4aeU, 0x91b9d537U, 0x0b49b9f7U);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
        {
            r_tsip_func101(0x8e97c63aU, 0xd1f70aa7U, 0xf16b9092U, 0x9f22a5faU);
            r_tsip_func302();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0xb81482cfU, 0x8d1b5668U, 0x2d560603U, 0x0a2c4043U);
        }

        WR1_PROG(REG_00ECH, 0x0000b540U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_00E0H, 0x818c000aU);
        WR1_PROG(REG_0000H, 0x00003833U);
        WR1_PROG(REG_002CH, 0x0000001aU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x413bd0ccU, 0x48c08135U, 0xb8911ff6U, 0x3457f962U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xbf7aa81cU, 0xd525a843U, 0xc17d5444U, 0x66981810U);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_0024H, 0x00004404U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00004804U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_00E0H, 0x808c001fU);
            WR1_PROG(REG_0000H, 0x00008333U);
            WR1_PROG(REG_002CH, 0x00000022U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
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
            WR1_PROG(REG_00E0H, 0x808c001fU);
            WR1_PROG(REG_0000H, 0x00008333U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7c0U);
            WR1_PROG(REG_00ECH, 0x0000000cU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x800103a0U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000012U));
            r_tsip_func101(0xafd7775fU, 0x14b95fd6U, 0xedd7abeeU, 0x2f25669cU);
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
            r_tsip_func100(0x8c2744beU, 0x3ce65723U, 0x1071f876U, 0xe74319c6U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_00ECH, 0x000001e0U);
            WR1_PROG(REG_00C4H, 0x00080805U);
            WR1_PROG(REG_00E0H, 0x8184000aU);
            WR1_PROG(REG_0000H, 0x00002813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func100(0xbdc0e8a3U, 0xd032aa33U, 0xc0470553U, 0xab693aaeU);
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
            r_tsip_func077();
            r_tsip_func100(0x5ceeed44U, 0xd2546fe0U, 0x41cbbcd6U, 0xb3ecb879U);
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x00440a04U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_00C4H, 0x00080e14U);
            WR1_PROG(REG_00E0H, 0x810103c0U);
            WR1_PROG(REG_0000H, 0x00002807U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0104H, 0x00001362U);
            WR1_PROG(REG_00D0H, 0x00000400U);
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
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[12]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[13]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[14]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[15]);
            WR1_PROG(REG_0000H, 0x00003233U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[16]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[17]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[18]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[19]);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[20]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[21]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[22]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[23]);
            WR1_PROG(REG_0000H, 0x00003223U);
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
            WR1_ADDR(REG_0100H, &InData_KeyIndex[24]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[25]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[26]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[27]);
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0104H, 0x00000362U);
            WR1_PROG(REG_00C4H, 0x00000885U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[28]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[29]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[30]);
            WR1_ADDR(REG_0100H, &InData_KeyIndex[31]);
            WR1_PROG(REG_00C4H, 0x00900c45U);
            WR1_PROG(REG_0000H, 0x00002213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func100(0xe45353e7U, 0x5139fa31U, 0xda402a0dU, 0x57878b58U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x8e4b1e7eU, 0x4a9b887fU, 0x8717baffU, 0x89a024d4U);
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
                WR1_PROG(REG_00E0H, 0x808c000aU);
                WR1_PROG(REG_0000H, 0x00008333U);
                WR1_PROG(REG_002CH, 0x00000022U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_00ECH, 0x000000c0U);
                WR1_PROG(REG_00E0H, 0x808c000aU);
                WR1_PROG(REG_0000H, 0x00008333U);
                WR1_PROG(REG_002CH, 0x00000023U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000100U);
                WR1_PROG(REG_00E0H, 0x808c001fU);
                WR1_PROG(REG_0000H, 0x00008333U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x00000bdeU);
                WR1_PROG(REG_00ECH, 0x00000842U);
                WR1_PROG(REG_00ECH, 0x0000b420U);
                WR1_PROG(REG_00ECH, 0x00000004U);
                WR1_PROG(REG_00ECH, 0x0000b480U);
                WR1_PROG(REG_00ECH, 0x00000180U);
                WR1_PROG(REG_00ECH, 0x0000b7a0U);
                WR1_PROG(REG_00ECH, 0x00000002U);
                WR1_PROG(REG_00ECH, 0x00000b9cU);
                r_tsip_func100(0xcbf77081U, 0x8ce3deb8U, 0x8f2c34ecU, 0xc37206f4U);
                WR1_PROG(REG_00E0H, 0x81010380U);
                WR1_PROG(REG_0004H, 0x00000607U);
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
                for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
                {
                    r_tsip_func101(0x8077c4dbU, 0x608889f7U, 0x513545b3U, 0x92a28d77U);
                    r_tsip_func302();
                    if (S_RAM[0] == 0x00000001U)
                    {
                        break;
                    }

                    r_tsip_func101(0x5477b932U, 0x19d5a77fU, 0xfda34473U, 0x2465a7d9U);
                }

                WR1_PROG(REG_0024H, 0x00001dc0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00001f00U);
                WR1_PROG(REG_001CH, 0x00210000U);
                r_tsip_func100(0x2ac53171U, 0x78747f3eU, 0x4f86f8fcU, 0x40dbc5d3U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x31334c07U, 0xaf101903U, 0x3f485861U, 0xb4205ce3U);
                    WR1_PROG(REG_01B8H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x00000080U);
                    WR1_PROG(REG_00E0H, 0x818c000aU);
                    WR1_PROG(REG_0000H, 0x00003833U);
                    WR1_PROG(REG_002CH, 0x0000001aU);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x000000c0U);
                    WR1_PROG(REG_00E0H, 0x818c000aU);
                    WR1_PROG(REG_0000H, 0x00003833U);
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
                    r_tsip_func100(0x467d9284U, 0x2fd12f63U, 0x1d10fcf5U, 0x7e2b8cdcU);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0xb8d170b5U, 0x88880398U, 0x51d66b56U, 0x101adf26U);
                        WR1_PROG(REG_01B8H, 0x00000040U);
                        WAIT_STS(REG_0018H, 12U, 0U);

                        return TSIP_RET_FAIL;
                    }
                    else
                    {
                        WR1_PROG(REG_00ECH, 0x0000b7e0U);
                        WR1_PROG(REG_00ECH, 0x00000040U);
                        WR1_PROG(REG_00E0H, 0x818c001fU);
                        WR1_PROG(REG_0000H, 0x00003833U);
                        WR1_PROG(REG_002CH, 0x00000012U);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
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
                        WR1_PROG(REG_00E0H, 0x808c001fU);
                        WR1_PROG(REG_0000H, 0x00008333U);
                        WR1_PROG(REG_002CH, 0x00000021U);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
                        WR1_PROG(REG_00ECH, 0x0000b7c0U);
                        WR1_PROG(REG_00ECH, 0x0000000cU);
                        WR1_PROG(REG_0104H, 0x00000058U);
                        WR1_PROG(REG_00E0H, 0x800103a0U);
                        WAIT_STS(REG_0104H, 31U, 1U);
                        WR1_PROG(REG_0100H, bswap_32big(0x00000013U));
                        r_tsip_func101(0x46b88b4cU, 0xd4b2315dU, 0xf29b6e90U, 0xad02c65eU);
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
                        WR1_PROG(REG_00E0H, 0x818c001fU);
                        WR1_PROG(REG_0000H, 0x00003833U);
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
                        WR1_PROG(REG_00E0H, 0x818c000aU);
                        WR1_PROG(REG_0000H, 0x00003833U);
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
                        r_tsip_func100(0x971465c7U, 0x782c0f89U, 0x080791bdU, 0x031b06e9U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0x07dd476aU, 0xfcfe1bffU, 0x09b97172U, 0x746d1cb6U);
                            WR1_PROG(REG_01B8H, 0x00000040U);
                            WAIT_STS(REG_0018H, 12U, 0U);

                            return TSIP_RET_FAIL;
                        }
                        else
                        {
                            r_tsip_func102(0x70574932U, 0x5d750f19U, 0xc2cada19U, 0x6ef20b41U);
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
