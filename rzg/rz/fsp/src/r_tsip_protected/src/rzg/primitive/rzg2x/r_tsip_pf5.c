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

tsip_ret_t r_tsip_pf5 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       uint32_t       OutData_Signature[])
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

    WR1_PROG(REG_0084H, 0x0000f502U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x1a0dc60aU, 0xfed129b9U, 0x0ab6c9feU, 0xcd742c5dU);
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
    WR1_PROG(REG_0100H, bswap_32big(0x000000f5U));
    r_tsip_func101(0x59d1e3f8U, 0x7ee1bd89U, 0xe5cce385U, 0x6df95dcaU);
    r_tsip_func027(OFS_ADR);
    r_tsip_func100(0x87fff969U, 0x784121aaU, 0x1102e14fU, 0x9a0a4a13U);
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
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x800098d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000002U);
    WR1_PROG(REG_0024H, 0x800088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x009f0001U);
    r_tsip_func103();
    r_tsip_func100(0xf0c0dfc8U, 0xfd681bfeU, 0xe9a47142U, 0x59154947U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01080c04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func100(0x84f9bf18U, 0x46230b69U, 0xba91955eU, 0x52da2152U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0113d522U));
    r_tsip_func100(0xd45e5dc8U, 0x467e12e5U, 0x0c2c3002U, 0x8d5c5230U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x02e097b7U);
    WR1_PROG(REG_0000H, 0x00002383U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WR1_PROG(REG_0004H, 0x00000282U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    }

    r_tsip_func100(0x930df636U, 0x4ed0432dU, 0x4eafbc8fU, 0x3e8c9e6eU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x000019c5U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    WR1_PROG(REG_0028H, 0x008b0001U);
    r_tsip_func100(0x11229475U, 0x1f46ebf8U, 0xb1e8dea0U, 0x152eacb8U);
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
    r_tsip_func100(0xfc4b61c9U, 0x96806daaU, 0xe678c34eU, 0x5d44cd04U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000011U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x6b758ca4U, 0xdd60d33aU, 0x5eb384b6U, 0x9ed10fd9U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x00001228U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x100019b1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000a0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
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
    WR1_PROG(REG_0100H, bswap_32big(0x000000f5U));
    r_tsip_func101(0xcb9e9271U, 0x7cb9fd21U, 0x7d7e846fU, 0x4163886aU);
    r_tsip_func028(OFS_ADR);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x800088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x8000acd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c0c1U);
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
    WR1_PROG(REG_0024H, 0x00000dc0U);
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
    WR1_PROG(REG_0024H, 0x00000dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00005cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func100(0xfff312bfU, 0xba8f28ecU, 0x1fcf1b1eU, 0x8e0d283dU);
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
    r_tsip_func100(0xb26f4a79U, 0x8b7cea1eU, 0xd1938220U, 0x24841ca0U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000013U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x8950bd0cU, 0x98c09453U, 0xae380cd2U, 0x2ebe2567U);
    r_tsip_func103();
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
    r_tsip_func100(0xb2b6a22fU, 0x6e0707f0U, 0xaafe7a03U, 0x73b151a2U);
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
    WR1_PROG(REG_00ECH, 0x000000f5U);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_0004H, 0x00000607U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
    {
        r_tsip_func101(0xb8634cfeU, 0xda159910U, 0xc217ef43U, 0x1717aaddU);
        r_tsip_func300();
        if (S_RAM[0] == 0x00000001U)
        {
            break;
        }

        r_tsip_func101(0xa095d537U, 0x1bf80106U, 0x54c859e6U, 0x0adedc14U);
    }

    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0x09bcaa09U, 0xd4bb6b2bU, 0xaa9630e8U, 0xbfdb8e83U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x4a18517eU, 0x113a7088U, 0x08e35c54U, 0xe13390cfU);
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
        r_tsip_func100(0xfe879740U, 0x10352e1aU, 0xa43c7082U, 0x5508c180U);
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
        WR1_PROG(REG_00ECH, 0x00000006U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
        {
            r_tsip_func101(0x7d529a22U, 0xcca7f650U, 0xbf7976e1U, 0xb8c302cdU);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0x7ada3117U, 0x8d8182dbU, 0x19fd2005U, 0xa4b0b169U);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x2ca461fcU, 0x30a635a9U, 0x8d689470U, 0x0994658fU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x751b178fU, 0xcd8cb351U, 0xb9fb54d9U, 0xcac094eaU);
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
            WR1_PROG(REG_0100H, bswap_32big(0x000000f5U));
            r_tsip_func101(0x2dcae91cU, 0xb9de7296U, 0x6f1d32d9U, 0x15b3ecc2U);
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
            r_tsip_func100(0xf1cdb074U, 0x6c41aefaU, 0x3a312ca8U, 0xd6493defU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xaf3d74f8U, 0x9a51ac67U, 0x67c0ee19U, 0x5b13566dU);
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
                WR1_PROG(REG_0100H, bswap_32big(0x00000009U));
                r_tsip_func101(0x012a4e62U, 0xce1b5183U, 0x9d07985bU, 0x8badf36bU);
                r_tsip_func326();
                r_tsip_func301();
                WR1_PROG(REG_0028H, 0x008f0001U);
                WR1_PROG(REG_0104H, 0x00001f62U);
                WR1_PROG(REG_00D0H, 0x00000700U);
                WR1_PROG(REG_00C4H, 0x02f097b7U);
                WR1_PROG(REG_0000H, 0x00003243U);
                WR1_PROG(REG_002CH, 0x00000014U);
                for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
                }

                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0000H, 0x00003243U);
                WR1_PROG(REG_002CH, 0x0000001dU);
                for (iLoop = 16; iLoop < 32; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
                }

                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0104H, 0x00000362U);
                WR1_PROG(REG_00C4H, 0x000017b5U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
                WR1_PROG(REG_00C4H, 0x00800c45U);
                WR1_PROG(REG_0000H, 0x00002213U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0028H, 0x008b0001U);
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
                WR1_PROG(REG_0024H, 0x0000a8d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000020U);
                WR1_PROG(REG_0024H, 0x80001dc0U);
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
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000828U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00001f00U);
                WR1_PROG(REG_001CH, 0x00210000U);
                r_tsip_func100(0x7d11da4fU, 0xacbb1908U, 0x938a99adU, 0x01adc3c9U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x72b0ec3eU, 0x13920f06U, 0x0ad3a819U, 0xbd28c269U);
                    WR1_PROG(REG_01B8H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_FAIL;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x00000ac0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800060c2U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x0000b7e0U);
                    WR1_PROG(REG_00ECH, 0x00000140U);
                    WR1_PROG(REG_00E0H, 0x818c001fU);
                    WR1_PROG(REG_0000H, 0x00003833U);
                    WR1_PROG(REG_002CH, 0x00000010U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
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
                    WR1_PROG(REG_0100H, bswap_32big(0x00000011U));
                    r_tsip_func101(0x53f51effU, 0x1f5229deU, 0x354e7f89U, 0xc39cc601U);
                    r_tsip_func326();
                    WR1_PROG(REG_0024H, 0x00001028U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_002CH, 0x00000011U);
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
                    WR1_PROG(REG_0034H, 0x00000020U);
                    WR1_PROG(REG_0024H, 0x80001dc0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000002U);
                    WR1_PROG(REG_0024H, 0x80000a2cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000002U);
                    WR1_PROG(REG_0024H, 0x800009c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000a0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000020U);
                    WR1_PROG(REG_0024H, 0x80001dc0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    r_tsip_func100(0xa4e1a71eU, 0xa1e906c8U, 0x7eb28d1eU, 0x7ad44577U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x000001e0U);
                    WR1_PROG(REG_00C4H, 0x00080805U);
                    WR1_PROG(REG_00E0H, 0x8184000aU);
                    WR1_PROG(REG_0000H, 0x00002813U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0x9f7ce0cbU, 0x7dbd6ad3U, 0xc5bbaf3eU, 0x6846b1feU);
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
                    r_tsip_func076();
                    r_tsip_func100(0xe3423b9bU, 0x83abf1fdU, 0xb78397e5U, 0x3d77ac4bU);
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x00440a04U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x00080e14U);
                    WR1_PROG(REG_00E0H, 0x810103c0U);
                    WR1_PROG(REG_0000H, 0x00002807U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0104H, 0x00000b62U);
                    WR1_PROG(REG_00D0H, 0x00000200U);
                    WR1_PROG(REG_00C4H, 0x02f087b7U);
                    WR1_PROG(REG_0000H, 0x00003233U);
                    WR1_PROG(REG_002CH, 0x00000018U);
                    for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
                    {
                        WAIT_STS(REG_0104H, 31U, 1U);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 4]);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 5]);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 6]);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 7]);
                    }

                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0104H, 0x00000362U);
                    WR1_PROG(REG_00C4H, 0x000007b5U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[16]);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[17]);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[18]);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[19]);
                    WR1_PROG(REG_00C4H, 0x00900c45U);
                    WR1_PROG(REG_0000H, 0x00002213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0x00e76f86U, 0x53d99b59U, 0x16aa6fa6U, 0x0412a470U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0xa7f2622bU, 0x7b50ea0eU, 0x6253e3aeU, 0x90598a7dU);
                        WR1_PROG(REG_01B8H, 0x00000040U);
                        WAIT_STS(REG_0018H, 12U, 0U);

                        return TSIP_RET_KEY_FAIL;
                    }
                    else
                    {
                        WR1_PROG(REG_0024H, 0x000015c0U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0034H, 0x00000008U);
                        WR1_PROG(REG_0024H, 0x80000c2dU);
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
                        WR1_PROG(REG_0024H, 0x000080c1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0034H, 0x00000002U);
                        WR1_PROG(REG_0024H, 0x8000082cU);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x100019b1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x000019a1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0034H, 0x00000800U);
                        WR1_PROG(REG_0024H, 0x800040c1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0034H, 0x00000002U);
                        WR1_PROG(REG_0024H, 0x800009c0U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x00000591U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_001CH, 0x00001f00U);
                        WR1_PROG(REG_001CH, 0x00210000U);
                        r_tsip_func100(0xef0bc034U, 0x8c749b77U, 0x4fcdc540U, 0x2487a41cU);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0x9bc95fa8U, 0x696fd914U, 0x92d3b9dfU, 0x8ea5299aU);
                            WR1_PROG(REG_01B8H, 0x00000040U);
                            WAIT_STS(REG_0018H, 12U, 0U);

                            return TSIP_RET_FAIL;
                        }
                        else
                        {
                            r_tsip_func100(0x482f0ad2U, 0xf6d23ed0U, 0xcce905d3U, 0x20704e71U);
                            WR1_PROG(REG_002CH, 0x0000002bU);
                            WR1_PROG(REG_0004H, 0x00000332U);
                            WAIT_STS(REG_0004H, 30U, 1U);
                            RD1_ADDR(REG_0100H, &OutData_Signature[0]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[1]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[2]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[3]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[4]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[5]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[6]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[7]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[8]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[9]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[10]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[11]);
                            r_tsip_func100(0xcd076daeU, 0xa36c3d9eU, 0x70f113ffU, 0x20b29968U);
                            WR1_PROG(REG_002CH, 0x0000002aU);
                            WR1_PROG(REG_0004H, 0x00000332U);
                            WAIT_STS(REG_0004H, 30U, 1U);
                            RD1_ADDR(REG_0100H, &OutData_Signature[12]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[13]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[14]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[15]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[16]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[17]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[18]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[19]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[20]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[21]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[22]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[23]);
                            r_tsip_func102(0x008ba838U, 0xf1624f7eU, 0xde29cf5bU, 0x025d13baU);
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
