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

tsip_ret_t r_tsip_p53 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_0084H, 0x00005302U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x119c20e2U, 0x6a6b2bbbU, 0x4420687cU, 0xc21417f4U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x8dfd86e9U, 0x735ca3f7U, 0x3788ab0dU, 0xb2df9634U);
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
    r_tsip_func100(0x6f87178bU, 0xc87ea3f4U, 0x02f365b7U, 0x0d6708e3U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01241e7bU));
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_0000H, 0x00003183U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WR1_PROG(REG_0104H, 0x00004361U);
    WR1_PROG(REG_00B0H, 0x00000700U);
    WR1_PROG(REG_00A4H, 0x02f08887U);
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
    WR1_PROG(REG_00A4H, 0x00f00885U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[36]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[37]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[38]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[39]);
    WR1_PROG(REG_00E0H, 0x80010000U);
    WR1_PROG(REG_0000H, 0x00008107U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x0000010fU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00003183U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WR1_PROG(REG_00B0H, 0x00000700U);
    WR1_PROG(REG_00A4H, 0x00f087b7U);
    for (iLoop = 40; iLoop < 72; iLoop = iLoop + 4)
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
    WR1_ADDR(REG_0100H, &InData_KeyIndex[72]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[73]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[74]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[75]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x6c853559U, 0xaf7eb89cU, 0xd57c5772U, 0xee573426U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x45783077U, 0x34b1571aU, 0xdae36db7U, 0xb9d3675fU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0x60cd5af0U, 0xfa9a9118U, 0xfd50a563U, 0x7093d4e5U);
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
        WR1_PROG(REG_0024H, 0x000068d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0038H, 0x00000730U);
        WR1_PROG(REG_00E0H, 0x81010000U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        r_tsip_func100(0x7894c357U, 0x4f65d104U, 0xa6809250U, 0x35d676f8U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000383U);
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
        r_tsip_func102(0x1bb7a426U, 0xca6142bfU, 0xaad61f42U, 0xb9a8c942U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
