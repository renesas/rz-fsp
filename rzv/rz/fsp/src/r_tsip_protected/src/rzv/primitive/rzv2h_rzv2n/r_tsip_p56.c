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

tsip_ret_t r_tsip_p56 (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_0084H, 0x00005602U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x08cd8567U, 0xb21acce4U, 0x16911172U, 0xc6142e50U);
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
    r_tsip_func100(0xbe2ed43cU, 0x902280eeU, 0x4dc377a7U, 0x15839901U);
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
    r_tsip_func100(0xd603c506U, 0xc6a80d9fU, 0x03e84215U, 0xcfbc14faU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01cae143U));
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0000H, 0x00013103U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WR1_PROG(REG_0104H, 0x00008361U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x02f08887U);
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
    WR1_PROG(REG_00A4H, 0x00f00885U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[68]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[69]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[70]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[71]);
    WR1_PROG(REG_00E0H, 0x80010000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008107U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x0000010fU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00013103U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x00f087b7U);
    for (iLoop = 72; iLoop < 136; iLoop = iLoop + 4)
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
    WR1_ADDR(REG_0100H, &InData_KeyIndex[136]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[137]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[138]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[139]);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x5a37c567U, 0xeea18a37U, 0xf2a94dd8U, 0xe2c06e2eU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x4f58104aU, 0x5a1722e2U, 0xd628cd4fU, 0x58c70a6eU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0xb8f94a70U, 0x1b7283d8U, 0x88e12589U, 0xe5d2540dU);
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
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0038H, 0x00000338U);
        WR1_PROG(REG_00E0H, 0x81010000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        r_tsip_func100(0xc6123553U, 0x31eaebbdU, 0x75ad9122U, 0xc80ebc72U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000303U);
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
        r_tsip_func102(0x27bf8ba4U, 0x6153aba1U, 0x60093cefU, 0x6840e080U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
