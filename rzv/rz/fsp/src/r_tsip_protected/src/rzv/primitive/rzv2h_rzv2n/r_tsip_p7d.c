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
    r_tsip_func100(0x23d1b49eU, 0xf40e1b69U, 0x1d698512U, 0x8ce07939U);
    WR1_PROG(REG_0028H, 0x008f0001U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000440U);
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
    WR1_PROG(REG_0100H, bswap_32big(0x0000007dU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0xa4181dd4U, 0x4ececed3U, 0x01353cfbU, 0xdeef8dc0U);
    r_tsip_func078(OFS_ADR);
    r_tsip_func100(0x6228e478U, 0x376db135U, 0x7f6404e1U, 0x208e6ebeU);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000025U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0xd56dc868U, 0xccc18e2fU, 0x670ed021U, 0x3552b4ffU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01080c04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func100(0xb53fe9bfU, 0xb7b0ba04U, 0xba9723a7U, 0xfa11e851U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01ac94f1U));
    r_tsip_func100(0xf6600c8bU, 0x5a663490U, 0x81d85f15U, 0x0ec3a81cU);
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

    r_tsip_func100(0x8afb0bcdU, 0x79811a88U, 0x533329c3U, 0xcdc08d1dU);
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
    r_tsip_func100(0x4007bc9bU, 0xc0460af5U, 0xbdd97547U, 0x258e2b5dU);
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
    r_tsip_func100(0x2a9a526cU, 0xf4482264U, 0x12124f9fU, 0x2acb22eaU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000011U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0xa175a5b0U, 0xf5907669U, 0x8c8c8816U, 0x03f7dd65U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x7bb4971bU, 0x9be07923U, 0xb7d43d82U, 0xf0733cf8U);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0000007dU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0x1a3d46daU, 0xa18ebe22U, 0xa7472093U, 0x9c9f45b5U);
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
    r_tsip_func100(0xb0cdbed1U, 0x6baa6f6dU, 0x3819b269U, 0xab4893bfU);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8190001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0x773e828eU, 0xf02a34baU, 0x52263c75U, 0x03724229U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000013U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0xcfe53f93U, 0x9312eff0U, 0x34b7eabbU, 0x3c0f0ebaU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x9cd5d487U, 0xa02b0eddU, 0x6817697dU, 0x274c8e6dU);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8190001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x9ca6f51dU, 0x16f91cdaU, 0xe330d376U, 0xfad38289U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008343U);
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
    WR1_PROG(REG_00ECH, 0x00000200U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b7a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000007dU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000607U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < 512; iLoop = iLoop + 1)
    {
        r_tsip_func101(0x1d999eeaU, 0xcf93e022U, 0x2a4ca3c8U, 0x8f23b354U);
        r_tsip_func300();
        if (S_RAM[0] == 0x00000001U)
        {
            break;
        }

        r_tsip_func101(0xd081f384U, 0x1152a590U, 0xb5d7cfcfU, 0x1dc9ab0cU);
    }

    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0x99ddc0ceU, 0xff6f3fefU, 0x2d356b8fU, 0x3c6cdc85U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x1ec18bf1U, 0xa2d0dfe8U, 0x86b1f5a9U, 0xd0767bd4U);
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
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003843U);
        WR1_PROG(REG_002CH, 0x00000013U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000028U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x000000c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000029U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        r_tsip_func100(0x3470715aU, 0x0231df65U, 0xded59160U, 0xf02c72bfU);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008343U);
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
        WR1_PROG(REG_00ECH, 0x00000200U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000008U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 512; iLoop = iLoop + 1)
        {
            r_tsip_func101(0x2a27da7fU, 0x31ef04d7U, 0x76afbd41U, 0x4e266098U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0x99fe66a6U, 0xf5329ce6U, 0xff0c0d11U, 0xc082db1cU);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x52cebcdfU, 0xb5f4d375U, 0x93241cbeU, 0xc8e64436U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xaaf65121U, 0xa8d56651U, 0x94dffdd5U, 0x30293b78U);
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
            WR1_PROG(REG_00E0H, 0x8090001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008343U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000010U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x800103a0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x0000007dU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0xff8221c4U, 0x09cc9eb4U, 0xc06cfb80U, 0x6415715fU);
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
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000018U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000019U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            r_tsip_func100(0x15a6ca05U, 0x0d5c6e23U, 0xc9245a15U, 0x0d67bfb6U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xdd7e1d99U, 0x87cf08bbU, 0xf7870adbU, 0xd4882ba2U);
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
                WR1_PROG(REG_00E0H, 0x8090001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00008343U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000010U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000015U));
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0xa5200757U, 0xeb8e0b9eU, 0xfd7a34a4U, 0x2dfdf471U);
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
                r_tsip_func100(0x9ed40ea6U, 0xdd88c039U, 0x699ca998U, 0x481d4406U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x23679ce1U, 0x35fbc6c6U, 0xf79d5480U, 0xbb71deafU);
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
                    WR1_PROG(REG_00E0H, 0x8190001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
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
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x8090001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00008343U);
                    WR1_PROG(REG_002CH, 0x00000021U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b7c0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000010U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0104H, 0x00000058U);
                    WR1_PROG(REG_00E0H, 0x800103a0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000016U));
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func101(0x0ca1e0f0U, 0x1938c066U, 0xbba86f46U, 0x245a7e94U);
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
                    r_tsip_func100(0x8d3f14bfU, 0xf8007e7aU, 0x902cba81U, 0x1f1ce176U);
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
                    r_tsip_func100(0x7aa7375aU, 0x2a909fc7U, 0xff0a8d42U, 0x229ff7adU);
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
                    r_tsip_func100(0x39ad25b2U, 0x3edb7bf7U, 0xa5795032U, 0xbed2bbf2U);
                    WR1_PROG(REG_0104H, 0x00000152U);
                    WR1_PROG(REG_00C4H, 0x00440a04U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_00C4H, 0x00080e14U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x0165c747U));
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
                    r_tsip_func100(0xe78eb9b8U, 0x97c9d469U, 0xfb7c166cU, 0xbc55e172U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0xc5f38b29U, 0x0f94895eU, 0x0f349782U, 0xe00f159fU);
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
                        r_tsip_func100(0xc6ccdb66U, 0x5e39a640U, 0x07b17e7dU, 0x835bf7d6U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0x2a70f6f3U, 0x65af18bcU, 0x0c20d3cbU, 0xada8a96aU);
                            WR1_PROG(REG_01B8H, 0x00000040U);
                            WAIT_STS(REG_0018H, 12U, 0U);

                            return TSIP_RET_FAIL;
                        }
                        else
                        {
                            r_tsip_func100(0x8c67d0c0U, 0x66d0e8c8U, 0xad8162b9U, 0xb8e94cb6U);
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
                            r_tsip_func100(0xa4b1a627U, 0x4a0396d0U, 0x0c32f137U, 0x9edc27eeU);
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
                            r_tsip_func102(0x1dd7df34U, 0x9236b35bU, 0x94b2c551U, 0x9d0b118cU);
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
