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

tsip_ret_t r_tsip_p57 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_0084H, 0x00005702U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x75e13042U, 0x3daff3c3U, 0xef992fe7U, 0x632674c8U);
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
    r_tsip_func100(0xfb8e6e69U, 0x0547c4e3U, 0x2163c1e2U, 0x84e12772U);
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
    r_tsip_func100(0x628f4a3aU, 0xc275baa4U, 0x5bee39e6U, 0x4badea5cU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013a2341U));
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0000H, 0x00018103U);
    WR1_PROG(REG_00ECH, 0x00000821U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x80c00001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x0000bf61U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x02f087b7U);
    for (iLoop = 4; iLoop < 68; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00013103U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x00f087b7U);
    for (iLoop = 68; iLoop < 132; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 0]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 1]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 2]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00013103U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x00f087b7U);
    for (iLoop = 132; iLoop < 196; iLoop = iLoop + 4)
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
    WR1_ADDR(REG_0100H, &InData_KeyIndex[196]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[197]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[198]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[199]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x2f641d32U, 0x10c005bdU, 0x2adc8b17U, 0xee60bc8aU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x0f554ca5U, 0x9a1d664eU, 0xff8a667fU, 0x83180d4eU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0x6d54aa4aU, 0xcfd78815U, 0xcce8b921U, 0x7e78a4dbU);
        r_tsip_func103();
        r_tsip_func100(0x933cbdbbU, 0xc5e37871U, 0x7169066aU, 0x21da1a21U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x010c0c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x350ec06cU));
        r_tsip_func100(0x7f19f6dfU, 0xfdd9339aU, 0x8507602dU, 0x7ff2a13dU);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WR1_PROG(REG_0004H, 0x00000202U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        }

        r_tsip_func100(0xc67aa4d1U, 0xb4d78819U, 0x7539e5cbU, 0x2e1b436dU);
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
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
        {
            r_tsip_func100(0x86253989U, 0x21c06a7bU, 0xdca28da4U, 0x2b1bf72fU);
            r_tsip_func103();
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x01000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0xf02f5049U, 0x6ece14f6U, 0x9b3033ddU, 0x1616a72fU);
        }

        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x00000828U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xb353dd31U));
        r_tsip_func100(0xd8c6da6bU, 0xa8868047U, 0xed1c2275U, 0xc83af156U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WR1_PROG(REG_0004H, 0x00000202U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        r_tsip_func100(0x52a96c86U, 0xcc934093U, 0x70fb0969U, 0xbb652d02U);
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
        WR1_PROG(REG_00E0H, 0x81c0001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00013803U);
        WR1_PROG(REG_002CH, 0x00000014U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WR1_PROG(REG_0104H, 0x00003f67U);
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
        WR1_ADDR(REG_0100H, &InData_Text[32]);
        WR1_ADDR(REG_0100H, &InData_Text[33]);
        WR1_ADDR(REG_0100H, &InData_Text[34]);
        WR1_ADDR(REG_0100H, &InData_Text[35]);
        WR1_ADDR(REG_0100H, &InData_Text[36]);
        WR1_ADDR(REG_0100H, &InData_Text[37]);
        WR1_ADDR(REG_0100H, &InData_Text[38]);
        WR1_ADDR(REG_0100H, &InData_Text[39]);
        WR1_ADDR(REG_0100H, &InData_Text[40]);
        WR1_ADDR(REG_0100H, &InData_Text[41]);
        WR1_ADDR(REG_0100H, &InData_Text[42]);
        WR1_ADDR(REG_0100H, &InData_Text[43]);
        WR1_ADDR(REG_0100H, &InData_Text[44]);
        WR1_ADDR(REG_0100H, &InData_Text[45]);
        WR1_ADDR(REG_0100H, &InData_Text[46]);
        WR1_ADDR(REG_0100H, &InData_Text[47]);
        WR1_ADDR(REG_0100H, &InData_Text[48]);
        WR1_ADDR(REG_0100H, &InData_Text[49]);
        WR1_ADDR(REG_0100H, &InData_Text[50]);
        WR1_ADDR(REG_0100H, &InData_Text[51]);
        WR1_ADDR(REG_0100H, &InData_Text[52]);
        WR1_ADDR(REG_0100H, &InData_Text[53]);
        WR1_ADDR(REG_0100H, &InData_Text[54]);
        WR1_ADDR(REG_0100H, &InData_Text[55]);
        WR1_ADDR(REG_0100H, &InData_Text[56]);
        WR1_ADDR(REG_0100H, &InData_Text[57]);
        WR1_ADDR(REG_0100H, &InData_Text[58]);
        WR1_ADDR(REG_0100H, &InData_Text[59]);
        WR1_ADDR(REG_0100H, &InData_Text[60]);
        WR1_ADDR(REG_0100H, &InData_Text[61]);
        WR1_ADDR(REG_0100H, &InData_Text[62]);
        WR1_ADDR(REG_0100H, &InData_Text[63]);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xd8c795e0U));
        r_tsip_func100(0x9601f211U, 0x67417429U, 0x1c1dc21dU, 0xec28bfeeU);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000202U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 68]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 69]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 70]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 71]);
        }

        r_tsip_func100(0x4b15e258U, 0xa182d5c0U, 0xefb31144U, 0x50bbb0dbU);
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
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 68]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 69]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 70]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 71]);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80c0001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00018303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x350ec06cU));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x0000080cU);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x350ec06cU));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000057U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0xc33615bdU, 0x8fe8b9bfU, 0xa4d3278fU, 0x249e6560U);
        r_tsip_func327();
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xb353dd31U));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80c0001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00018203U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
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
        WR1_PROG(REG_0100H, bswap_32big(0x853d2086U));
        r_tsip_func100(0xa9ea1bafU, 0xe6ad6bf4U, 0xc415edd2U, 0xfc9d8d4fU);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42e087bfU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000202U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        r_tsip_func100(0x66d2966cU, 0x38284033U, 0x574e9914U, 0xbac20af0U);
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
        WR1_PROG(REG_0100H, bswap_32big(0xd8c795e0U));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 68]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 69]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 70]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 71]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 68]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 69]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 70]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 71]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x350ec06cU));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x0000082cU);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x350ec06cU));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        }

        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_00C8H, 6U, 0U);
        WR1_PROG(REG_00C4H, 0x400007bdU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 136]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 137]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 138]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 139]);
        WR1_PROG(REG_00C4H, 0x00800c45U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x800103a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0000005fU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x1de8b05fU, 0x0ea2f7efU, 0x2c38c9f0U, 0x5f3d867cU);
        r_tsip_func327();
        WR1_PROG(REG_00C4H, 0x00080b8cU);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x853d2086U));
        WR1_PROG(REG_0104H, 0x00003f62U);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x42f487bfU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000012U);
        for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
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
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x0000082cU);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func100(0xeb82c90aU, 0x5f9ab045U, 0xaa658ef8U, 0x669ff60bU);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000302U);
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
        RD1_ADDR(REG_0100H, &OutData_Text[32]);
        RD1_ADDR(REG_0100H, &OutData_Text[33]);
        RD1_ADDR(REG_0100H, &OutData_Text[34]);
        RD1_ADDR(REG_0100H, &OutData_Text[35]);
        RD1_ADDR(REG_0100H, &OutData_Text[36]);
        RD1_ADDR(REG_0100H, &OutData_Text[37]);
        RD1_ADDR(REG_0100H, &OutData_Text[38]);
        RD1_ADDR(REG_0100H, &OutData_Text[39]);
        RD1_ADDR(REG_0100H, &OutData_Text[40]);
        RD1_ADDR(REG_0100H, &OutData_Text[41]);
        RD1_ADDR(REG_0100H, &OutData_Text[42]);
        RD1_ADDR(REG_0100H, &OutData_Text[43]);
        RD1_ADDR(REG_0100H, &OutData_Text[44]);
        RD1_ADDR(REG_0100H, &OutData_Text[45]);
        RD1_ADDR(REG_0100H, &OutData_Text[46]);
        RD1_ADDR(REG_0100H, &OutData_Text[47]);
        RD1_ADDR(REG_0100H, &OutData_Text[48]);
        RD1_ADDR(REG_0100H, &OutData_Text[49]);
        RD1_ADDR(REG_0100H, &OutData_Text[50]);
        RD1_ADDR(REG_0100H, &OutData_Text[51]);
        RD1_ADDR(REG_0100H, &OutData_Text[52]);
        RD1_ADDR(REG_0100H, &OutData_Text[53]);
        RD1_ADDR(REG_0100H, &OutData_Text[54]);
        RD1_ADDR(REG_0100H, &OutData_Text[55]);
        RD1_ADDR(REG_0100H, &OutData_Text[56]);
        RD1_ADDR(REG_0100H, &OutData_Text[57]);
        RD1_ADDR(REG_0100H, &OutData_Text[58]);
        RD1_ADDR(REG_0100H, &OutData_Text[59]);
        RD1_ADDR(REG_0100H, &OutData_Text[60]);
        RD1_ADDR(REG_0100H, &OutData_Text[61]);
        RD1_ADDR(REG_0100H, &OutData_Text[62]);
        RD1_ADDR(REG_0100H, &OutData_Text[63]);
        r_tsip_func102(0x3422404cU, 0xfb7427feU, 0x762a743dU, 0xd34aa288U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
