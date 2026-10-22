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
    r_tsip_func100(0x380e6ac3U, 0x31b11a54U, 0xb65e3503U, 0x9129f7a9U);
    WR1_PROG(REG_0028H, 0x008b0001U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010340U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38000f5aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000002B4U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000003D8U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x81010000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000606U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    OFS_ADR = S_RAM[0];
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000f5U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0x0687b4c4U, 0x44991ea1U, 0xf3d30ad4U, 0x8d99add4U);
    r_tsip_func027(OFS_ADR);
    r_tsip_func100(0x797ebe3cU, 0xf59ac133U, 0x50876e2aU, 0xa9a0a4c7U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000025U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0xf0a83f01U, 0x09d874b6U, 0x67558548U, 0x5c0bc735U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01080c04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func100(0xc3ba3415U, 0xda397187U, 0xa35db927U, 0xde2796dcU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01851b67U));
    r_tsip_func100(0xa8354f7eU, 0x82f67becU, 0x0ca8e345U, 0xf2f799e3U);
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

    r_tsip_func100(0x5b09f5aaU, 0xc0d7c553U, 0xb9e08389U, 0x56c4885aU);
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
    r_tsip_func100(0x0d4cb948U, 0xc7575bb1U, 0x70a0e654U, 0xa871876bU);
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
    r_tsip_func100(0xfab38563U, 0xd49abd02U, 0x076acdc5U, 0xe22adb26U);
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
    r_tsip_func100(0xe90de333U, 0xce9cf686U, 0xf927caf7U, 0xa0d0a15eU);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000f5U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0x63e9812aU, 0x6ac5ad8eU, 0xef3185c0U, 0xa4c39004U);
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
    r_tsip_func100(0x46a768f2U, 0xbe511550U, 0xc6e9e9b5U, 0xe158ea95U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x818c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0x376c951dU, 0xb764291bU, 0x3fbe4ed5U, 0xe4681432U);
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
    r_tsip_func100(0xdd87e8d7U, 0x3ce24a2bU, 0x7081c30bU, 0x89c7007aU);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x818c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x74b5a9e2U, 0xb3f44b82U, 0xefba47f9U, 0x5025f608U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x808c001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008333U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000842U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000180U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b7a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000000f5U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000607U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
    {
        r_tsip_func101(0xdfc30061U, 0x332ac018U, 0xfc706e1dU, 0x547ef375U);
        r_tsip_func300();
        if (S_RAM[0] == 0x00000001U)
        {
            break;
        }

        r_tsip_func101(0xfef3e0afU, 0x9bf26842U, 0x5608b91dU, 0xb261916aU);
    }

    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0x10a8b45bU, 0x066c581dU, 0x1b33ae95U, 0x30f18dfaU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x30501acbU, 0xf6284503U, 0x1a3b7256U, 0x8c374120U);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x818c001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003833U);
        WR1_PROG(REG_002CH, 0x00000013U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000028U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x000000c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000029U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x818c001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        r_tsip_func100(0x369cdb9eU, 0xd31b3401U, 0x091d4101U, 0x9d6adefeU);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x808c001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008333U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000842U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b480U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000180U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000006U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 384; iLoop = iLoop + 1)
        {
            r_tsip_func101(0xca9ee426U, 0x59e1be1cU, 0x9ba706fcU, 0x46f80744U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0x0a7719f2U, 0x5bc03864U, 0x7362cb6dU, 0x3641bc08U);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x8233aecdU, 0x2f579113U, 0xac4ca528U, 0x1e5f6c6bU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x5aab63b6U, 0x93cc43bcU, 0xd7c576b6U, 0x6fefcab4U);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x808c001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008333U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000000cU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x800103a0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x000000f5U));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0xdaa51240U, 0xbe3ae317U, 0xbf17596cU, 0x96f1477aU);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003833U);
            WR1_PROG(REG_002CH, 0x00000018U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003833U);
            WR1_PROG(REG_002CH, 0x00000019U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x818c001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            r_tsip_func100(0x0783b6abU, 0x22bd41e3U, 0x3de41f1dU, 0xc30899e0U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x756e5fe9U, 0x88d50c5cU, 0xa3ef0618U, 0x2909cdbaU);
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
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x808c001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00008333U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000000cU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000009U));
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0x7982d96dU, 0xd1351b95U, 0xc12fcbd0U, 0x96d09786U);
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
                r_tsip_func100(0x158419d9U, 0xb9667090U, 0x793cd540U, 0xe61360a6U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x31f9c5b4U, 0x32554a21U, 0xc09cd84dU, 0xd3594114U);
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
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000140U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x818c001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
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
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x808c001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00008333U);
                    WR1_PROG(REG_002CH, 0x00000021U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b7c0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x0000000cU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0104H, 0x00000058U);
                    WR1_PROG(REG_00E0H, 0x800103a0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000011U));
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func101(0x65277d2dU, 0x8be9b822U, 0xb1226fffU, 0x4b088e7fU);
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
                    r_tsip_func100(0x613a3b92U, 0xd7007ff9U, 0x5f645213U, 0x890c623fU);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x000001e0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00C4H, 0x00080805U);
                    WR1_PROG(REG_00E0H, 0x8184000aU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00002813U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0x00bd6343U, 0x62192e18U, 0xb4de8d3fU, 0x9e6db4fdU);
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
                    r_tsip_func100(0x8bfae7c5U, 0x9f265e1fU, 0xf04b33dfU, 0xef90e387U);
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x00440a04U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x00080e14U);
                    WR1_PROG(REG_00E0H, 0x810103c0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
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
                    r_tsip_func100(0x3ddf732aU, 0xa1684c03U, 0x1f1de91eU, 0xe7885554U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0x208d33d1U, 0x8e1c5034U, 0x8ce7bb4dU, 0xc9b9256eU);
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
                        r_tsip_func100(0x4e30533eU, 0x7d5dd949U, 0x43a06ba2U, 0xd0d2aa71U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0x84be6b03U, 0xed304b53U, 0x86e13bcaU, 0x00ab3374U);
                            WR1_PROG(REG_01B8H, 0x00000040U);
                            WAIT_STS(REG_0018H, 12U, 0U);

                            return TSIP_RET_FAIL;
                        }
                        else
                        {
                            r_tsip_func100(0xd05172d8U, 0x300b34efU, 0xef82c7f2U, 0xcbd325f3U);
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
                            r_tsip_func100(0xaceccb6bU, 0xc3789c1aU, 0x87f9cc99U, 0x68348bbaU);
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
                            r_tsip_func102(0xf4ef5062U, 0xbe3c4ac8U, 0xc6fe9383U, 0xeac93a81U);
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
