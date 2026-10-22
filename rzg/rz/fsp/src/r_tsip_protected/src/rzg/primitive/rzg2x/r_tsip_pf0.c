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
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_CurveType[0]);
    WR1_PROG(REG_0104H, 0x00000068U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_0104H, 0x00000768U);
    WR1_PROG(REG_00E0H, 0x8088001eU);
    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_MsgDgst[iLoop + 0]);
    }

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
    r_tsip_func100(0x55efefd7U, 0x5de10a0cU, 0xb2889ec5U, 0x2edfc4c9U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x261f2c17U, 0x047a4641U, 0x4b29ae8dU, 0xb6f1d65fU);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x44e7a224U, 0x0bfc7a17U, 0x06a1ad36U, 0x84738f77U);
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
        WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
        r_tsip_func101(0x45fedef9U, 0xa175c6beU, 0x17e62ea7U, 0x48fbda2bU);
        r_tsip_func070(OFS_ADR);
        r_tsip_func100(0xa4deacf9U, 0x56e6fadeU, 0xb853c0caU, 0xf99f8b84U);
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
        r_tsip_func100(0x290a53e0U, 0xdedf9b20U, 0x9583102cU, 0x5f647e38U);
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
        r_tsip_func100(0x7b8817d3U, 0x1c4ebf34U, 0xe59de861U, 0x2f53b4e9U);
        r_tsip_func103();
        r_tsip_func100(0x230d9f8dU, 0x4195bc87U, 0xd653e0e8U, 0x4c36e49aU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0x6ec77cadU, 0x1bd24c28U, 0x10261752U, 0x2ce153cdU);
        WR1_PROG(REG_0104H, 0x00000152U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00090e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01113df9U));
        r_tsip_func100(0xe24791f8U, 0x2099680cU, 0xbbc0bf19U, 0xb8ff1c6fU);
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
        r_tsip_func100(0x70c541c3U, 0x288af16fU, 0x330455b0U, 0x35f0d994U);
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
        r_tsip_func100(0xd3d560a1U, 0xbcebaf33U, 0xa8bece5dU, 0x0207f415U);
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
        r_tsip_func100(0x3f5d8b54U, 0x5caa9ff2U, 0xd3885374U, 0xd5702d02U);
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
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
        r_tsip_func101(0x8994e27aU, 0x89938efbU, 0xb517af6dU, 0x8cd69f56U);
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
        r_tsip_func100(0xe269a42aU, 0x7b631d77U, 0x002991edU, 0xc916f944U);
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
        r_tsip_func100(0xf94d7aacU, 0xe3698944U, 0xfd7b789bU, 0x77a2ac1dU);
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
        r_tsip_func100(0xf7e1cd42U, 0x9fbca140U, 0xf1325ca9U, 0x8ed2c1b0U);
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
        WR1_PROG(REG_00ECH, 0x000000f0U);
        WR1_PROG(REG_00ECH, 0x0000373cU);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
        {
            r_tsip_func101(0xe1878057U, 0xf3a37779U, 0x655c3669U, 0xe9f17b14U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0x58d4e0dbU, 0x7fd200f4U, 0x8f30b074U, 0x01d30853U);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xd4e6f71aU, 0x1da2af88U, 0xe3de3c7dU, 0x394d99ecU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xd3d461ccU, 0xb5a52214U, 0x25f27601U, 0xb4a468a9U);
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
            r_tsip_func100(0x15834dabU, 0x2f84a6baU, 0xd9c07a3aU, 0x283451adU);
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
            WR1_PROG(REG_00ECH, 0x00000004U);
            WR1_PROG(REG_00ECH, 0x00000b9cU);
            WR1_PROG(REG_00E0H, 0x81010380U);
            WR1_PROG(REG_0004H, 0x00000607U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
            {
                r_tsip_func101(0xb1c1ca30U, 0x143071ceU, 0xc9421d68U, 0xe24b5a29U);
                r_tsip_func300();
                if (S_RAM[0] == 0x00000001U)
                {
                    break;
                }

                r_tsip_func101(0x803fbc5fU, 0x493b4e54U, 0xebdf6191U, 0xbf93ce07U);
            }

            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x0ba2acfbU, 0xd862e4bcU, 0xa49783c8U, 0xae381d22U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x28d9cb59U, 0x25666933U, 0x232021d2U, 0x2ea75c38U);
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
                WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
                r_tsip_func101(0x6129af88U, 0xc1a368d2U, 0x0ca90d85U, 0xf81d2c2bU);
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
                r_tsip_func100(0xf4558383U, 0x31dd8695U, 0x7e3cc98eU, 0xe57e1b39U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0xafcf4269U, 0xc1687290U, 0x23461f34U, 0xd90570ecU);
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
                    WR1_PROG(REG_0100H, bswap_32big(0x00000004U));
                    r_tsip_func101(0xec4a6d90U, 0x7c156f5eU, 0x6780582cU, 0x6df360efU);
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
                    r_tsip_func100(0x2ffdea68U, 0x142aa856U, 0x37047c95U, 0xb47cc0c3U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func102(0x4834bc2aU, 0x56c734ceU, 0x1326f573U, 0x2fe5839dU);
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
                        WR1_PROG(REG_0100H, bswap_32big(0x00000005U));
                        r_tsip_func101(0x3df1051bU, 0x91d21658U, 0xbd75c6efU, 0x6907caacU);
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
                        WR1_PROG(REG_00ECH, 0x00000140U);
                        WR1_PROG(REG_00E0H, 0x8188001fU);
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
                        r_tsip_func100(0xdd1bd349U, 0xd93d46c2U, 0x8b0fadaeU, 0xbc682dd9U);
                        WR1_PROG(REG_00ECH, 0x0000b540U);
                        WR1_PROG(REG_00ECH, 0x000001e0U);
                        WR1_PROG(REG_00C4H, 0x00080805U);
                        WR1_PROG(REG_00E0H, 0x8184000aU);
                        WR1_PROG(REG_0000H, 0x00002813U);
                        WAIT_STS(REG_0000H, 25U, 0U);
                        WR1_PROG(REG_001CH, 0x00001800U);
                        r_tsip_func100(0x42c66e17U, 0x821b3df2U, 0xc72e290dU, 0x74f9180fU);
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
                        WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
                        r_tsip_func101(0xc9995f1bU, 0x34c8095dU, 0x79923522U, 0x36681e8aU);
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
                        r_tsip_func100(0xeeb59e15U, 0x220a022eU, 0x555f67d2U, 0x02f0ea2eU);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 1U))
                        {
                            r_tsip_func102(0x325a53bfU, 0xeb933833U, 0xf4a807fbU, 0xcc47a51fU);
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
                            r_tsip_func100(0x1d856c3cU, 0x287aab1eU, 0x07f7b811U, 0xc8e8ec70U);
                            WR1_PROG(REG_001CH, 0x00400000U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            if (CHCK_STS(REG_001CH, 22U, 1U))
                            {
                                r_tsip_func102(0xc61bafe9U, 0x62d9f848U, 0x99535dceU, 0x4cf6a471U);
                                WR1_PROG(REG_01B8H, 0x00000040U);
                                WAIT_STS(REG_0018H, 12U, 0U);

                                return TSIP_RET_FAIL;
                            }
                            else
                            {
                                r_tsip_func100(0x81e4c73dU, 0x7f5ef0d4U, 0x4dd54a18U, 0x902daf30U);
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
                                r_tsip_func100(0x1e544757U, 0x5cfe50adU, 0x589664cfU, 0xb34df962U);
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
                                r_tsip_func102(0x67e3e7d6U, 0x2751f9c1U, 0x8ec2d538U, 0xe2bdd71cU);
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
