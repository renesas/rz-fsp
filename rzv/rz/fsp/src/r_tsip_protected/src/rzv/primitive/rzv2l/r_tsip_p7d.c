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

tsip_ret_t r_tsip_p7d (const uint32_t InData_KeyIndex[], const uint32_t InData_MsgDgst[], uint32_t OutData_Signature[])
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

    WR1_PROG(REG_0084H, 0x00007d02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x00793323U, 0x992c3fc4U, 0x25161f9dU, 0x6ef8efc2U);
    WR1_PROG(REG_0028H, 0x008f0001U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000440U);
    WR1_PROG(REG_00E0H, 0x81010000U);
    WR1_PROG(REG_0004H, 0x00000606U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    OFS_ADR = S_RAM[0];
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0000007dU));
    r_tsip_func101(0xe03fcecaU, 0x59680e49U, 0xdeb84acdU, 0x02caf728U);
    r_tsip_func078(OFS_ADR);
    r_tsip_func100(0x44bde7f7U, 0xbfd53992U, 0x62d6529dU, 0x4322aa46U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000025U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000040U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
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
    r_tsip_func100(0xde80d72cU, 0x43655cf3U, 0x7c8019cfU, 0xbb950c87U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01080c04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func100(0x8047aec5U, 0x95830d67U, 0x83bcf6c2U, 0x7db7ec19U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a74f5fU));
    r_tsip_func100(0x0a9a2afdU, 0x7b032f75U, 0x621faa73U, 0xe03cad0bU);
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

    r_tsip_func100(0xd810bce7U, 0x0c00ba4bU, 0xd7044947U, 0x4d3a7182U);
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
    WR1_PROG(REG_0028H, 0x008f0001U);
    r_tsip_func100(0x65fa9919U, 0xdac30acaU, 0x0d60e0e0U, 0x163c5e35U);
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
    r_tsip_func100(0x19e5e4ecU, 0x777e77ceU, 0x40f1cd63U, 0x043fc941U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000011U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x0f3edf90U, 0x183056ecU, 0x45b2a828U, 0x94c7436aU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x07229c04U, 0x8f9708dcU, 0x6e92846dU, 0x79036f4eU);
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
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0000007dU));
    r_tsip_func101(0xfc62e19cU, 0xcb601934U, 0xa6a91e33U, 0x1407b48dU);
    r_tsip_func079(OFS_ADR);
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
    r_tsip_func100(0x6d33fbf6U, 0x0154767bU, 0x4fcd2b27U, 0x33ba3aedU);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x8190001fU);
    WR1_PROG(REG_0000H, 0x00003843U);
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
    r_tsip_func100(0x20c73c88U, 0x9c1604b2U, 0x168e5888U, 0x53c41d14U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000013U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x32280f93U, 0x645c8484U, 0xbc0e4dbcU, 0xec533b15U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x131c72d3U, 0x0ce0e2f3U, 0xfb144f29U, 0x6383ba69U);
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
    WR1_PROG(REG_00E0H, 0x8190001fU);
    WR1_PROG(REG_0000H, 0x00003843U);
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
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x2f75cc94U, 0x51f6e25aU, 0x2ee6bf34U, 0xe14d0491U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_00ECH, 0x00000842U);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_00ECH, 0x00000200U);
    WR1_PROG(REG_00ECH, 0x0000b7a0U);
    WR1_PROG(REG_00ECH, 0x0000007dU);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_0004H, 0x00000607U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < 512; iLoop = iLoop + 1)
    {
        r_tsip_func101(0x3780543bU, 0x7fb1f44bU, 0x747ade12U, 0xbc78168cU);
        r_tsip_func300();
        if (S_RAM[0] == 0x00000001U)
        {
            break;
        }

        r_tsip_func101(0x5af8c179U, 0xbff9e664U, 0x55966a18U, 0x58c6ef3aU);
    }

    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0x2c693abbU, 0xfe41c059U, 0xc0a0c176U, 0x607e4150U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x27bad0ebU, 0x0e967c77U, 0x0d2ebea1U, 0xfca54f1bU);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_0000H, 0x00003843U);
        WR1_PROG(REG_002CH, 0x00000013U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000028U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x000000c0U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000029U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
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
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_0000H, 0x00003843U);
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
        r_tsip_func100(0xbb0441e5U, 0x7a0b5779U, 0x722e7764U, 0xbe30a529U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_00ECH, 0x00000842U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_00ECH, 0x0000b480U);
        WR1_PROG(REG_00ECH, 0x00000200U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_00ECH, 0x00000008U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 512; iLoop = iLoop + 1)
        {
            r_tsip_func101(0xc3b5d27dU, 0x651291bdU, 0xd536de67U, 0xbdd95d15U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0x6280e613U, 0xf5c9f45fU, 0xd3c7da66U, 0xe2b99587U);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xc3c76852U, 0xddfa3c65U, 0x3f073f94U, 0x1a5fa7a2U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x62ce7740U, 0x6b175bfbU, 0x1b80cb88U, 0x27a75d54U);
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
            WR1_PROG(REG_00E0H, 0x8090001fU);
            WR1_PROG(REG_0000H, 0x00008343U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7c0U);
            WR1_PROG(REG_00ECH, 0x00000010U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x800103a0U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x0000007dU));
            r_tsip_func101(0xeb4f7474U, 0x39b96676U, 0xa05bca7aU, 0xc466094bU);
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
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
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
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000018U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000019U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
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
            r_tsip_func100(0xc5138863U, 0x48a1c238U, 0xe89fa80fU, 0xe0392c00U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xd8b1e0b1U, 0xb0374785U, 0x8865df7eU, 0x8fbdcfbdU);
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
                WR1_PROG(REG_00E0H, 0x8090001fU);
                WR1_PROG(REG_0000H, 0x00008343U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7c0U);
                WR1_PROG(REG_00ECH, 0x00000010U);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000015U));
                r_tsip_func101(0xc18a8248U, 0x9f974622U, 0xae14be2fU, 0xf59e6a6bU);
                r_tsip_func326();
                r_tsip_func301();
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
                r_tsip_func100(0x9a515e74U, 0x25bc2601U, 0xff8a657dU, 0x4c90bd4bU);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x76b99f20U, 0x486404fbU, 0xde9e3308U, 0x8ef40e58U);
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
                    WR1_PROG(REG_00E0H, 0x8190001fU);
                    WR1_PROG(REG_0000H, 0x00003843U);
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
                    WR1_PROG(REG_00E0H, 0x8090001fU);
                    WR1_PROG(REG_0000H, 0x00008343U);
                    WR1_PROG(REG_002CH, 0x00000021U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b7c0U);
                    WR1_PROG(REG_00ECH, 0x00000010U);
                    WR1_PROG(REG_0104H, 0x00000058U);
                    WR1_PROG(REG_00E0H, 0x800103a0U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000016U));
                    r_tsip_func101(0xc3e25b53U, 0xd62b927aU, 0xf8911d81U, 0x7ef2f724U);
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
                    WR1_PROG(REG_0104H, 0x00000f67U);
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
                    WR1_ADDR(REG_0100H, &InData_MsgDgst[12]);
                    WR1_ADDR(REG_0100H, &InData_MsgDgst[13]);
                    WR1_ADDR(REG_0100H, &InData_MsgDgst[14]);
                    WR1_ADDR(REG_0100H, &InData_MsgDgst[15]);
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
                    r_tsip_func100(0xa5626f92U, 0x02f8ec95U, 0xdfdefc4fU, 0x8aa2d415U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_00ECH, 0x000001e0U);
                    WR1_PROG(REG_00C4H, 0x00080805U);
                    WR1_PROG(REG_00E0H, 0x8184000aU);
                    WR1_PROG(REG_0000H, 0x00002813U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0xa2c25057U, 0x192d38caU, 0xbef662caU, 0x9f97e416U);
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
                    r_tsip_func100(0xc533f4efU, 0xd3fcd32dU, 0x3824cfc3U, 0x7a4adb8fU);
                    WR1_PROG(REG_0104H, 0x00000152U);
                    WR1_PROG(REG_00C4H, 0x00440a04U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x00080e14U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x01febd0dU));
                    WR1_PROG(REG_0104H, 0x00000f62U);
                    WR1_PROG(REG_00D0H, 0x00000300U);
                    WR1_PROG(REG_00C4H, 0x02f087b7U);
                    WR1_PROG(REG_0000H, 0x00003243U);
                    WR1_PROG(REG_002CH, 0x00000018U);
                    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
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
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[20]);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[21]);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[22]);
                    WR1_ADDR(REG_0100H, &InData_KeyIndex[23]);
                    WR1_PROG(REG_00C4H, 0x00900c45U);
                    WR1_PROG(REG_0000H, 0x00002213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func100(0xe0826386U, 0xa779a435U, 0x5de7ba63U, 0x974bf4a0U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0x73ac6a80U, 0x65bcb4dcU, 0x5f4f5d90U, 0x29650ce2U);
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
                        r_tsip_func100(0xd8be3bf5U, 0x5cfe6325U, 0xfc13ed37U, 0x5e32a6fcU);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0xcfedf68eU, 0x51dd24c6U, 0x891fc8b9U, 0x6b2a8a8eU);
                            WR1_PROG(REG_01B8H, 0x00000040U);
                            WAIT_STS(REG_0018H, 12U, 0U);

                            return TSIP_RET_FAIL;
                        }
                        else
                        {
                            r_tsip_func100(0xec3c27a2U, 0xb508e559U, 0x376f42c8U, 0x10dd4127U);
                            WR1_PROG(REG_002CH, 0x0000002bU);
                            WR1_PROG(REG_0004H, 0x00000342U);
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
                            RD1_ADDR(REG_0100H, &OutData_Signature[12]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[13]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[14]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[15]);
                            r_tsip_func100(0xfdf672c3U, 0x67e61e72U, 0x7c13583eU, 0xf1aa53abU);
                            WR1_PROG(REG_002CH, 0x0000002aU);
                            WR1_PROG(REG_0004H, 0x00000342U);
                            WAIT_STS(REG_0004H, 30U, 1U);
                            RD1_ADDR(REG_0100H, &OutData_Signature[16]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[17]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[18]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[19]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[20]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[21]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[22]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[23]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[24]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[25]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[26]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[27]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[28]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[29]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[30]);
                            RD1_ADDR(REG_0100H, &OutData_Signature[31]);
                            r_tsip_func102(0x96b3ba2dU, 0x48c09730U, 0x2e7ad865U, 0xd183a360U);
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
