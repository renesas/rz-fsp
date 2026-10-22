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

tsip_ret_t r_tsip_pf0 (const uint32_t InData_CurveType[],
                       const uint32_t InData_Cmd[],
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

    WR1_PROG(REG_0084H, 0x0000f002U);
    WR1_PROG(REG_0108H, 0x00000000U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010340U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000768U);
    WR1_PROG(REG_00E0H, 0x8088001eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[iLoop + 0]);
        WR1_PROG(REG_01D0H, 0x00000000U);
    }

    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x30003380U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00070020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000d3e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00030040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38000c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x1000d3e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00050040U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000037beU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000a7a0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000383dU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38001001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x1000d3e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x30000f5aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000d3e1U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38000f9cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x1000d3e1U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38008be0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000003U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x5d971081U, 0xfd9ea078U, 0xad89f468U, 0x800a3400U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x12fcb85aU, 0x4bcc5e2bU, 0x06fbbf87U, 0x70ff4dbfU);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x69d496eeU, 0x281540aaU, 0xdfa40d0fU, 0x7d5e0b3eU);
        WR1_PROG(REG_0028H, 0x00870001U);
        WR1_PROG(REG_00ECH, 0x30003340U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000031CU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00070040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x30003380U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00070020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00030040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000013CU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00050040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x000001F8U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
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
        WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x824065c2U, 0xb8a8acabU, 0xe9face88U, 0xefeafd64U);
        r_tsip_func070(OFS_ADR);
        r_tsip_func100(0x4c39219cU, 0x8fc0c3d7U, 0xb97b53c5U, 0xa6532f7aU);
        WR1_PROG(REG_0034H, 0x00000003U);
        WR1_PROG(REG_0024H, 0x800068d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000025U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000023U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000024U);
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
        r_tsip_func100(0xa4c7a99bU, 0x6ac9befdU, 0x25d308d5U, 0xe8018aa7U);
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
        WR1_PROG(REG_0024H, 0x00001228U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func100(0x1246084bU, 0x1875fab9U, 0x317519f6U, 0x6ebac5a6U);
        r_tsip_func103();
        r_tsip_func100(0xe8871626U, 0xc59ef4f8U, 0xcd4425f6U, 0x08f1db28U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0x2df47864U, 0x4f697dcfU, 0x443f2b2aU, 0xb1e5cc75U);
        WR1_PROG(REG_0104H, 0x00000152U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00090e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01b5a19bU));
        r_tsip_func100(0xb0bf17b1U, 0x942fd07bU, 0xc3503cf3U, 0x7f26bf32U);
        WR1_PROG(REG_00D0H, 0x00000100U);
        WR1_PROG(REG_00C4H, 0x02e097b7U);
        WR1_PROG(REG_0000H, 0x00002323U);
        WR1_PROG(REG_002CH, 0x00000024U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000222U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[0]);
        RD1_ADDR(REG_0100H, &S_HEAP[1]);
        RD1_ADDR(REG_0100H, &S_HEAP[2]);
        RD1_ADDR(REG_0100H, &S_HEAP[3]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[4]);
        RD1_ADDR(REG_0100H, &S_HEAP[5]);
        RD1_ADDR(REG_0100H, &S_HEAP[6]);
        RD1_ADDR(REG_0100H, &S_HEAP[7]);
        r_tsip_func100(0x4d44d270U, 0xa1be2650U, 0xbfb280f0U, 0x3a9dbc3bU);
        WR1_PROG(REG_00D0H, 0x00000100U);
        WR1_PROG(REG_00C4H, 0x00e097b7U);
        WR1_PROG(REG_0000H, 0x00002323U);
        WR1_PROG(REG_002CH, 0x0000002aU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000222U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[8]);
        RD1_ADDR(REG_0100H, &S_HEAP[9]);
        RD1_ADDR(REG_0100H, &S_HEAP[10]);
        RD1_ADDR(REG_0100H, &S_HEAP[11]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[12]);
        RD1_ADDR(REG_0100H, &S_HEAP[13]);
        RD1_ADDR(REG_0100H, &S_HEAP[14]);
        RD1_ADDR(REG_0100H, &S_HEAP[15]);
        r_tsip_func100(0x06ba5770U, 0x9b00d4daU, 0x866bfea7U, 0x95d2b4ebU);
        WR1_PROG(REG_00D0H, 0x00000100U);
        WR1_PROG(REG_00C4H, 0x00e097b7U);
        WR1_PROG(REG_0000H, 0x00002323U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000222U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[16]);
        RD1_ADDR(REG_0100H, &S_HEAP[17]);
        RD1_ADDR(REG_0100H, &S_HEAP[18]);
        RD1_ADDR(REG_0100H, &S_HEAP[19]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[20]);
        RD1_ADDR(REG_0100H, &S_HEAP[21]);
        RD1_ADDR(REG_0100H, &S_HEAP[22]);
        RD1_ADDR(REG_0100H, &S_HEAP[23]);
        r_tsip_func100(0xc803e7ecU, 0x8f754d96U, 0xd8edec3eU, 0x5738e0b0U);
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
        RD1_ADDR(REG_0100H, &S_HEAP[24]);
        RD1_ADDR(REG_0100H, &S_HEAP[25]);
        RD1_ADDR(REG_0100H, &S_HEAP[26]);
        RD1_ADDR(REG_0100H, &S_HEAP[27]);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x326cc17fU, 0x191c7e0cU, 0xea843a72U, 0xc9f23c99U);
        r_tsip_func071(OFS_ADR);
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
        r_tsip_func100(0xc32b87c9U, 0x3ebd2e43U, 0x2cbb01c0U, 0x9f996947U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8188001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        r_tsip_func100(0x1b7e295dU, 0x84e191d1U, 0x83aaad7eU, 0xfcc7891eU);
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
        WR1_PROG(REG_00E0H, 0x8188001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000023U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0xbd54bad0U, 0xc08b7c4fU, 0x341a8ca1U, 0x50f91de4U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
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
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x000000f0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000373cU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
        {
            r_tsip_func101(0x0918c253U, 0xd1408283U, 0x38952cd7U, 0x295cf70eU);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0xe573fa31U, 0x47982ddcU, 0x5f695c01U, 0x535b49dcU);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x3a8d03c3U, 0xedec23e0U, 0xfd352a2bU, 0x969dde6dU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xf37ada29U, 0x05fdf84aU, 0x753e8d87U, 0x7b28ba72U);
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
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x00000013U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000028U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000029U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            r_tsip_func100(0xd031f96eU, 0xd5fb7083U, 0xd246eabfU, 0x3aba8ffbU);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
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
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000b7a0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000004U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000b9cU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81010380U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0004H, 0x00000607U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
            {
                r_tsip_func101(0x460cdc57U, 0x50bc7d41U, 0xcf2318cfU, 0x5522b6e9U);
                r_tsip_func300();
                if (S_RAM[0] == 0x00000001U)
                {
                    break;
                }

                r_tsip_func101(0x9c8e4885U, 0x6128d8ccU, 0xcc170b4bU, 0xb9540384U);
            }

            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x78be8262U, 0x7528bc1fU, 0x8b6d7ca1U, 0x17e5866dU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x1a9853c2U, 0xf61807b4U, 0xf8887b43U, 0xb5c4e49eU);
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
                WR1_PROG(REG_00E0H, 0x8088001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00008323U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000008U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0x4d56c7c3U, 0x99f1d62aU, 0x5df48ac8U, 0xb87d3035U);
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
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
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
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000080U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000018U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000000c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000019U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000100U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x8188001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
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
                r_tsip_func100(0x7b9a9861U, 0x3ef2bea5U, 0x2f245bb7U, 0xc4fb0175U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0xccc67af3U, 0x0e3db202U, 0xffe683e6U, 0x0bf9eacfU);
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
                    WR1_PROG(REG_00E0H, 0x8088001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00008323U);
                    WR1_PROG(REG_002CH, 0x00000021U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_00ECH, 0x0000b7c0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000008U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0104H, 0x00000058U);
                    WR1_PROG(REG_00E0H, 0x800103a0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000004U));
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func101(0xd858fa53U, 0xc9ecd3d3U, 0xf7aa5782U, 0x81bc2578U);
                    r_tsip_func326();
                    r_tsip_func301();
                    WR1_PROG(REG_0104H, 0x00001762U);
                    WR1_PROG(REG_00D0H, 0x00000500U);
                    WR1_PROG(REG_00C4H, 0x02f097b7U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[0]);
                    WR1_ADDR(REG_0100H, &S_HEAP[1]);
                    WR1_ADDR(REG_0100H, &S_HEAP[2]);
                    WR1_ADDR(REG_0100H, &S_HEAP[3]);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[4]);
                    WR1_ADDR(REG_0100H, &S_HEAP[5]);
                    WR1_ADDR(REG_0100H, &S_HEAP[6]);
                    WR1_ADDR(REG_0100H, &S_HEAP[7]);
                    WR1_PROG(REG_0000H, 0x00003223U);
                    WR1_PROG(REG_002CH, 0x00000014U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[8]);
                    WR1_ADDR(REG_0100H, &S_HEAP[9]);
                    WR1_ADDR(REG_0100H, &S_HEAP[10]);
                    WR1_ADDR(REG_0100H, &S_HEAP[11]);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[12]);
                    WR1_ADDR(REG_0100H, &S_HEAP[13]);
                    WR1_ADDR(REG_0100H, &S_HEAP[14]);
                    WR1_ADDR(REG_0100H, &S_HEAP[15]);
                    WR1_PROG(REG_0000H, 0x00003223U);
                    WR1_PROG(REG_002CH, 0x0000001dU);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[16]);
                    WR1_ADDR(REG_0100H, &S_HEAP[17]);
                    WR1_ADDR(REG_0100H, &S_HEAP[18]);
                    WR1_ADDR(REG_0100H, &S_HEAP[19]);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[20]);
                    WR1_ADDR(REG_0100H, &S_HEAP[21]);
                    WR1_ADDR(REG_0100H, &S_HEAP[22]);
                    WR1_ADDR(REG_0100H, &S_HEAP[23]);
                    WR1_PROG(REG_0000H, 0x00003223U);
                    WR1_PROG(REG_002CH, 0x0000001aU);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0104H, 0x00000362U);
                    WR1_PROG(REG_00C4H, 0x000017b5U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_ADDR(REG_0100H, &S_HEAP[24]);
                    WR1_ADDR(REG_0100H, &S_HEAP[25]);
                    WR1_ADDR(REG_0100H, &S_HEAP[26]);
                    WR1_ADDR(REG_0100H, &S_HEAP[27]);
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
                    r_tsip_func100(0xc49063feU, 0x7e84bda8U, 0x356d8d6eU, 0x030a8407U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0xbf07de5aU, 0x64ca5951U, 0xf7d59ccbU, 0x82b49b71U);
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
                        WR1_PROG(REG_0034H, 0x00000002U);
                        WR1_PROG(REG_0024H, 0x800088d0U);
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
                        WR1_PROG(REG_00E0H, 0x8088001fU);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_0000H, 0x00008323U);
                        WR1_PROG(REG_002CH, 0x00000021U);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
                        WR1_PROG(REG_00ECH, 0x0000b7c0U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_00ECH, 0x00000008U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_0104H, 0x00000058U);
                        WR1_PROG(REG_00E0H, 0x800103a0U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WAIT_STS(REG_0104H, 31U, 1U);
                        WR1_PROG(REG_0100H, bswap_32big(0x00000005U));
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        r_tsip_func101(0x64d38f97U, 0xd0b4835bU, 0xae5a2d2fU, 0x7adf0fbeU);
                        r_tsip_func326();
                        WR1_PROG(REG_0024H, 0x00001028U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x100019b1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x000019a1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x000080c1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_00ECH, 0x0000b7e0U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_00ECH, 0x00000140U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_00E0H, 0x8188001fU);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_0000H, 0x00003823U);
                        WR1_PROG(REG_002CH, 0x00000011U);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
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
                        WR1_PROG(REG_00ECH, 0x00003799U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        r_tsip_func100(0x2c0b720fU, 0xb51f11a9U, 0xcdd91f5eU, 0x7c40fa7bU);
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
                        r_tsip_func100(0x22a32881U, 0xf515705bU, 0x663b2207U, 0xa78217f1U);
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
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WAIT_STS(REG_0104H, 31U, 1U);
                        WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        r_tsip_func101(0x3aecccd3U, 0x624eacb9U, 0xdc5aa65bU, 0x5494f780U);
                        r_tsip_func022();
                        WR1_PROG(REG_0104H, 0x00000762U);
                        WR1_PROG(REG_00D0H, 0x00000100U);
                        WR1_PROG(REG_00C4H, 0x02f087b7U);
                        WR1_PROG(REG_0000H, 0x00003223U);
                        WR1_PROG(REG_002CH, 0x00000018U);
                        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
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
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[12]);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[13]);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[14]);
                        WR1_ADDR(REG_0100H, &InData_KeyIndex[15]);
                        WR1_PROG(REG_00C4H, 0x00900c45U);
                        WR1_PROG(REG_0000H, 0x00002213U);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
                        r_tsip_func100(0xed132e82U, 0xd0040b63U, 0x6543291cU, 0x3fed8549U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0xfb656186U, 0x0d3347afU, 0x31b4789bU, 0x42040637U);
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
                            r_tsip_func100(0xabb776f2U, 0x5bda11c5U, 0x9973cb7bU, 0xfbb1f5d4U);
                            WR1_PROG(REG_001CH, 0x00400000U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            if (CHCK_STS(REG_001CH, 22U, 1U))
                            {
                                r_tsip_func102(0x0b692ef8U, 0x75c05125U, 0xa42313f5U, 0xfa3a3460U);
                                WR1_PROG(REG_01B8H, 0x00000040U);
                                WAIT_STS(REG_0018H, 12U, 0U);

                                return TSIP_RET_FAIL;
                            }
                            else
                            {
                                r_tsip_func100(0x87dbaf50U, 0x0874e0ccU, 0x856e4f52U, 0x714c0d25U);
                                WR1_PROG(REG_002CH, 0x0000002bU);
                                WR1_PROG(REG_0004H, 0x00000322U);
                                WAIT_STS(REG_0004H, 30U, 1U);
                                RD1_ADDR(REG_0100H, &OutData_Signature[0]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[1]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[2]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[3]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[4]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[5]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[6]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[7]);
                                r_tsip_func100(0xedaf9b06U, 0x766e633eU, 0x4f4e4719U, 0x22d534c7U);
                                WR1_PROG(REG_002CH, 0x0000002aU);
                                WR1_PROG(REG_0004H, 0x00000322U);
                                WAIT_STS(REG_0004H, 30U, 1U);
                                RD1_ADDR(REG_0100H, &OutData_Signature[8]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[9]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[10]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[11]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[12]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[13]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[14]);
                                RD1_ADDR(REG_0100H, &OutData_Signature[15]);
                                r_tsip_func102(0xf246ef82U, 0x425f243aU, 0xfd8e9352U, 0x6290e79fU);
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
