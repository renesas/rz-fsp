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

tsip_ret_t r_tsip_p54 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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
    if (0x0U != RD1_MASK(REG_01BCH, 0x1fU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00005402U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x46fc9549U, 0xc7bd0489U, 0x8ccde3d0U, 0x8a1288acU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xb281b92cU, 0xeef20aa1U, 0x34b3fe00U, 0x1140ebf8U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00080e15U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[0]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[1]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[2]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[3]);
    r_tsip_func100(0x63943f59U, 0x1e4c6126U, 0x40c1cf40U, 0xde2235afU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019184b5U));
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_0000H, 0x00008183U);
    WR1_PROG(REG_00ECH, 0x00000821U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x80a00001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00005f61U);
    WR1_PROG(REG_00B0H, 0x00000700U);
    WR1_PROG(REG_00A4H, 0x02f087b7U);
    for (iLoop = 4; iLoop < 36; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003183U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WR1_PROG(REG_00B0H, 0x00000700U);
    WR1_PROG(REG_00A4H, 0x00f087b7U);
    for (iLoop = 36; iLoop < 68; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003183U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WR1_PROG(REG_00B0H, 0x00000700U);
    WR1_PROG(REG_00A4H, 0x00f087b7U);
    for (iLoop = 68; iLoop < 100; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[100]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[101]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[102]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[103]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x08337f73U, 0xbbf4ee5eU, 0x06cda826U, 0xef4fdac1U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x892ba65fU, 0x83189ecbU, 0x5474d97aU, 0x0ba3d824U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0x5ae414fbU, 0xbdd4c2e7U, 0x3bc03ea3U, 0x153aedfbU);
        r_tsip_func103();
        r_tsip_func100(0xdfdfca1eU, 0xcab6f667U, 0xde4ebf5aU, 0xe3c5c3dcU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x010c0c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xae7884b4U));
        r_tsip_func100(0x841950c4U, 0xb5772180U, 0x3c84d3e7U, 0x03689b67U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00002383U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WR1_PROG(REG_0004H, 0x00000282U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        }

        r_tsip_func100(0x6a84fcaaU, 0x46bf0b51U, 0xce789cbaU, 0xa4fcaa3dU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x400009cdU);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000213U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
        {
            r_tsip_func100(0x905328c0U, 0xe1efa94fU, 0x9c013948U, 0x90efba4aU);
            r_tsip_func103();
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x01000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0xda164edaU, 0xb2bb0cc9U, 0xe8a09611U, 0x5359f057U);
        }

        WR1_PROG(REG_0024H, 0x00000828U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xc97abc1dU));
        r_tsip_func100(0xfa0a621cU, 0x1da6ea50U, 0x42dfb21bU, 0x309cfe23U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00002383U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WR1_PROG(REG_0004H, 0x00000282U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        r_tsip_func100(0x285161dfU, 0x5a5a108fU, 0x729a0f41U, 0x4497a866U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x400009cdU);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000213U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81a0001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003883U);
        WR1_PROG(REG_002CH, 0x00000014U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WR1_PROG(REG_0104H, 0x00001f67U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_Text[0]);
        WR1_ADDR(REG_0100H, &InData_Text[1]);
        WR1_ADDR(REG_0100H, &InData_Text[2]);
        WR1_ADDR(REG_0100H, &InData_Text[3]);
        WR1_ADDR(REG_0100H, &InData_Text[4]);
        WR1_ADDR(REG_0100H, &InData_Text[5]);
        WR1_ADDR(REG_0100H, &InData_Text[6]);
        WR1_ADDR(REG_0100H, &InData_Text[7]);
        WR1_ADDR(REG_0100H, &InData_Text[8]);
        WR1_ADDR(REG_0100H, &InData_Text[9]);
        WR1_ADDR(REG_0100H, &InData_Text[10]);
        WR1_ADDR(REG_0100H, &InData_Text[11]);
        WR1_ADDR(REG_0100H, &InData_Text[12]);
        WR1_ADDR(REG_0100H, &InData_Text[13]);
        WR1_ADDR(REG_0100H, &InData_Text[14]);
        WR1_ADDR(REG_0100H, &InData_Text[15]);
        WR1_ADDR(REG_0100H, &InData_Text[16]);
        WR1_ADDR(REG_0100H, &InData_Text[17]);
        WR1_ADDR(REG_0100H, &InData_Text[18]);
        WR1_ADDR(REG_0100H, &InData_Text[19]);
        WR1_ADDR(REG_0100H, &InData_Text[20]);
        WR1_ADDR(REG_0100H, &InData_Text[21]);
        WR1_ADDR(REG_0100H, &InData_Text[22]);
        WR1_ADDR(REG_0100H, &InData_Text[23]);
        WR1_ADDR(REG_0100H, &InData_Text[24]);
        WR1_ADDR(REG_0100H, &InData_Text[25]);
        WR1_ADDR(REG_0100H, &InData_Text[26]);
        WR1_ADDR(REG_0100H, &InData_Text[27]);
        WR1_ADDR(REG_0100H, &InData_Text[28]);
        WR1_ADDR(REG_0100H, &InData_Text[29]);
        WR1_ADDR(REG_0100H, &InData_Text[30]);
        WR1_ADDR(REG_0100H, &InData_Text[31]);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x8e65c43eU));
        r_tsip_func100(0x187fdfadU, 0x9f36d0a1U, 0xe504ba3bU, 0xf1e240ceU);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00002383U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000282U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 36]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 37]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 38]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 39]);
        }

        r_tsip_func100(0x1ae154e9U, 0xf585f587U, 0x855c9b2cU, 0x60dd2a86U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x400009cdU);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000213U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 36]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 37]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 38]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 39]);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80a0001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008383U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xae7884b4U));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00003283U);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x0000082cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xae7884b4U));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00003283U);
        WR1_PROG(REG_002CH, 0x00000010U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000054U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x24206c92U, 0xdcd0ed4fU, 0xa27d2a78U, 0x5138cb03U);
        r_tsip_func327();
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xc97abc1dU));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80a0001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008283U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xe198b41bU));
        r_tsip_func100(0xa0a1ef43U, 0x0305f66eU, 0x974fd172U, 0xac7535d4U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
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

        r_tsip_func100(0x4c219ca8U, 0xaff52ba1U, 0xb9475dcdU, 0x9dde02f8U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x400009cdU);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000213U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x8e65c43eU));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00003283U);
        WR1_PROG(REG_002CH, 0x00000010U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 36]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 37]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 38]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 39]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 36]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 37]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 38]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 39]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xae7884b4U));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00003283U);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x0000082cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xae7884b4U));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00003283U);
        WR1_PROG(REG_002CH, 0x00000010U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 72]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 73]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 74]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 75]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0000005eU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x9c5cf9fcU, 0xc0ddd0dbU, 0x13cc9f18U, 0x561f64acU);
        r_tsip_func327();
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xe198b41bU));
        WR1_PROG(REG_0104H, 0x00001f62U);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00003283U);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x0000082cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func100(0xf64559bdU, 0xaaa9c547U, 0xd7abccfdU, 0x45c5ecceU);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000382U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_Text[0]);
        RD1_ADDR(REG_0100H, &OutData_Text[1]);
        RD1_ADDR(REG_0100H, &OutData_Text[2]);
        RD1_ADDR(REG_0100H, &OutData_Text[3]);
        RD1_ADDR(REG_0100H, &OutData_Text[4]);
        RD1_ADDR(REG_0100H, &OutData_Text[5]);
        RD1_ADDR(REG_0100H, &OutData_Text[6]);
        RD1_ADDR(REG_0100H, &OutData_Text[7]);
        RD1_ADDR(REG_0100H, &OutData_Text[8]);
        RD1_ADDR(REG_0100H, &OutData_Text[9]);
        RD1_ADDR(REG_0100H, &OutData_Text[10]);
        RD1_ADDR(REG_0100H, &OutData_Text[11]);
        RD1_ADDR(REG_0100H, &OutData_Text[12]);
        RD1_ADDR(REG_0100H, &OutData_Text[13]);
        RD1_ADDR(REG_0100H, &OutData_Text[14]);
        RD1_ADDR(REG_0100H, &OutData_Text[15]);
        RD1_ADDR(REG_0100H, &OutData_Text[16]);
        RD1_ADDR(REG_0100H, &OutData_Text[17]);
        RD1_ADDR(REG_0100H, &OutData_Text[18]);
        RD1_ADDR(REG_0100H, &OutData_Text[19]);
        RD1_ADDR(REG_0100H, &OutData_Text[20]);
        RD1_ADDR(REG_0100H, &OutData_Text[21]);
        RD1_ADDR(REG_0100H, &OutData_Text[22]);
        RD1_ADDR(REG_0100H, &OutData_Text[23]);
        RD1_ADDR(REG_0100H, &OutData_Text[24]);
        RD1_ADDR(REG_0100H, &OutData_Text[25]);
        RD1_ADDR(REG_0100H, &OutData_Text[26]);
        RD1_ADDR(REG_0100H, &OutData_Text[27]);
        RD1_ADDR(REG_0100H, &OutData_Text[28]);
        RD1_ADDR(REG_0100H, &OutData_Text[29]);
        RD1_ADDR(REG_0100H, &OutData_Text[30]);
        RD1_ADDR(REG_0100H, &OutData_Text[31]);
        r_tsip_func102(0x7fc05e83U, 0x8e43453fU, 0x02d20cfdU, 0x2a7ec0e2U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
