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

tsip_ret_t r_tsip_pf9 (const uint32_t InData_CurveType[],
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

    WR1_PROG(REG_0084H, 0x0000f902U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x926536adU, 0x9a8aee3aU, 0xb189d90aU, 0x68c5320eU);
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
    WR1_PROG(REG_0100H, bswap_32big(0x000000f9U));
    r_tsip_func101(0x7a8e3d94U, 0x1a9c0708U, 0x403fda3aU, 0x703f864cU);
    r_tsip_func027(OFS_ADR);
    r_tsip_func100(0x26940960U, 0xdc91d286U, 0xff4f0789U, 0xd5a91569U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000025U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000040U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x008d0001U);
    r_tsip_func103();
    r_tsip_func100(0x147476d0U, 0xa310158eU, 0xc94582b0U, 0x40eb9127U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000011U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0xb898f5eaU, 0xcc10182fU, 0xff412da1U, 0xd0a8b159U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x2288dc25U, 0x33376df1U, 0xb30148d9U, 0x78daceb5U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
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
    WR1_PROG(REG_0028H, 0x008b0001U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000f9U));
    r_tsip_func101(0x03ca8fd4U, 0xae947d11U, 0xd1b6cacbU, 0x96256b25U);
    r_tsip_func028(OFS_ADR);
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
    r_tsip_func100(0x2eea00aaU, 0x3e1483ceU, 0xfca3219bU, 0x9587a81bU);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
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
    r_tsip_func103();
    r_tsip_func100(0xc54cdc20U, 0x1d7f4e2aU, 0xd719e9b5U, 0x2318e32fU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000013U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x12511437U, 0x16023bcdU, 0xda0ab181U, 0x825aba2bU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x9b272730U, 0xf984e725U, 0x60cd719fU, 0xb5a2303eU);
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
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
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
    WR1_PROG(REG_00ECH, 0x000000f9U);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_0004H, 0x00000607U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
    {
        r_tsip_func101(0x26924035U, 0x41bafc3fU, 0xcf73acccU, 0x0343600fU);
        r_tsip_func300();
        if (S_RAM[0] == 0x00000001U)
        {
            break;
        }

        r_tsip_func101(0xb69dffb4U, 0xc2980bc5U, 0x411e789eU, 0xf7f69980U);
    }

    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0x4b6f9f50U, 0x3dadb512U, 0xa3ffdf0fU, 0xce6a6a0aU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x5065ca2aU, 0x0eda9de5U, 0x2934101cU, 0x2ec1b757U);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x818c001fU);
        WR1_PROG(REG_0000H, 0x00003833U);
        WR1_PROG(REG_002CH, 0x00000013U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000028U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x000000c0U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000029U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_0000H, 0x00008333U);
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
        WR1_PROG(REG_00E0H, 0x818c001fU);
        WR1_PROG(REG_0000H, 0x00003833U);
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
        r_tsip_func100(0x8360524aU, 0x993ccf93U, 0x3fe3c4d9U, 0x6a421035U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
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
        WR1_PROG(REG_00ECH, 0x00000007U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
        {
            r_tsip_func101(0x674af14cU, 0x106f300aU, 0x145c05f8U, 0xc0c15ff6U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0xc633fc95U, 0x97f7cf58U, 0x2494f494U, 0x9e40d181U);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xc279e0f6U, 0x141bebc6U, 0x2d12f232U, 0xda923af6U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xf32059f2U, 0x5803b07cU, 0x030a96dcU, 0x1a1b93b3U);
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
            WR1_PROG(REG_0100H, bswap_32big(0x000000f9U));
            r_tsip_func101(0xbb4f49baU, 0xf3d7104cU, 0x6a74bf9fU, 0xdf5c387aU);
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
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_0000H, 0x00003833U);
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
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_0000H, 0x00003833U);
            WR1_PROG(REG_002CH, 0x00000018U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_0000H, 0x00003833U);
            WR1_PROG(REG_002CH, 0x00000019U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_0000H, 0x00003833U);
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
            r_tsip_func100(0x51715f31U, 0x96a1bc0dU, 0x9b2a3d44U, 0xe2f4d86dU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x849e3920U, 0x0323d79fU, 0xace2e913U, 0x9a4463c4U);
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
                WR1_PROG(REG_0100H, bswap_32big(0x00000014U));
                r_tsip_func101(0x9f40a91cU, 0x92cdb80fU, 0x8092cc06U, 0xb258593fU);
                r_tsip_func326();
                r_tsip_func301();
                r_tsip_func100(0xd4e789e4U, 0x9bd32bbaU, 0x8fb6ba22U, 0x1a97dda4U);
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
                r_tsip_func100(0x78fd1865U, 0x547268b2U, 0xfd42afc7U, 0xb9ee022cU);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_00ECH, 0x000001e0U);
                WR1_PROG(REG_00C4H, 0x00080805U);
                WR1_PROG(REG_00E0H, 0x8184000aU);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0xffc16dafU, 0x56e9bc7cU, 0x08231a62U, 0x2434c199U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e15U);
                WR1_PROG(REG_00E0H, 0x81040000U);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func076();
                r_tsip_func100(0xdbb02da9U, 0x923043b6U, 0x79776c9aU, 0xb327f8e8U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e14U);
                WR1_PROG(REG_00E0H, 0x810103c0U);
                WR1_PROG(REG_0000H, 0x00002807U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x8de6978fU, 0xb3cead60U, 0x50144b3dU, 0xeb7a2e74U);
                WR1_PROG(REG_00D0H, 0x00000200U);
                WR1_PROG(REG_00C4H, 0x02e087b7U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000140U);
                WR1_PROG(REG_00E0H, 0x818c001fU);
                WR1_PROG(REG_0000H, 0x00002833U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0004H, 0x00000232U);
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
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[12]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[13]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[14]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[15]);
                r_tsip_func100(0xa101fe32U, 0x8f3de96bU, 0xe0498193U, 0x17c950efU);
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
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[16]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[17]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[18]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[19]);
                r_tsip_func100(0x5cdbad6bU, 0xce9ff512U, 0xfdd3d981U, 0x0aff2b82U);
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
                r_tsip_func100(0xfc62b01fU, 0x54c48a56U, 0x07c763c9U, 0xd68a5a93U);
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
                r_tsip_func100(0xef8e3282U, 0x4f74bca4U, 0xd3772e70U, 0x06dbf344U);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_00ECH, 0x000001e0U);
                WR1_PROG(REG_00C4H, 0x00080805U);
                WR1_PROG(REG_00E0H, 0x8184000aU);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x4452790fU, 0x41a29f5eU, 0xc6a631c9U, 0x7bd78d02U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e15U);
                WR1_PROG(REG_00E0H, 0x81040000U);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func077();
                r_tsip_func100(0x4da48e17U, 0xe9b16f78U, 0x29086f1bU, 0xb4b76b8fU);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e14U);
                WR1_PROG(REG_00E0H, 0x810103c0U);
                WR1_PROG(REG_0000H, 0x00002807U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x8b15ebffU, 0x529303b1U, 0xd601d91bU, 0xbfec4290U);
                WR1_PROG(REG_00D0H, 0x00000200U);
                WR1_PROG(REG_00C4H, 0x02e08887U);
                WR1_PROG(REG_0000H, 0x00002333U);
                WR1_PROG(REG_002CH, 0x00000022U);
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
                r_tsip_func100(0x7303840bU, 0x9e3b6bc5U, 0x931677b4U, 0x0ed20234U);
                WR1_PROG(REG_00D0H, 0x00000100U);
                WR1_PROG(REG_00C4H, 0x00e08887U);
                WR1_PROG(REG_0000H, 0x00002323U);
                WR1_PROG(REG_002CH, 0x00000023U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
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
                r_tsip_func100(0x068793e0U, 0x471d122eU, 0x6a375060U, 0x98a8d5fdU);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00450944U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00e00885U);
                WR1_PROG(REG_0000H, 0x00002313U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0004H, 0x00000212U);
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[24]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[25]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[26]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[27]);
                r_tsip_func100(0xbe43a689U, 0x9a5bd958U, 0xdf934a89U, 0x40c0632fU);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00000cc4U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_0004H, 0x00000212U);
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[28]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[29]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[30]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[31]);
                r_tsip_func100(0x5f535ee1U, 0x3de48d64U, 0x13407790U, 0x148adbdaU);
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
                r_tsip_func102(0x36daec25U, 0x49740950U, 0xf4a05e3dU, 0xfe549e31U);
                WR1_PROG(REG_01B8H, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_PASS;
            }
        }
    }
}
