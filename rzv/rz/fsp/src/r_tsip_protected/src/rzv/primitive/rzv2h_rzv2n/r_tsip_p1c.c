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

tsip_ret_t r_tsip_p1c (const uint32_t InData_IV[], const uint32_t InData_InstData[], uint32_t OutData_KeyIndex[])
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
    if (0x0U != RD1_MASK(REG_01B4H, 0x1dU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00001c02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0xa8b14efcU, 0x0cc7c21bU, 0xfe6063a8U, 0xbeab4442U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00A4H, 0x000a0805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x3d66e1d9U, 0xf51972c1U, 0xd6e9525fU, 0x5a884539U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000a2e15U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[0]);
    WR1_ADDR(REG_0100H, &S_INST2[1]);
    WR1_ADDR(REG_0100H, &S_INST2[2]);
    WR1_ADDR(REG_0100H, &S_INST2[3]);
    r_tsip_func100(0x55280ab5U, 0xb8f751f8U, 0x61538af1U, 0x077b25e9U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00442a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a2e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01ef1cb9U));
    r_tsip_func100(0x461b9b93U, 0x21336fb2U, 0x4e8475e2U, 0x3a89ce0eU);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x02f82735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[4]);
    WR1_ADDR(REG_0100H, &S_INST2[5]);
    WR1_ADDR(REG_0100H, &S_INST2[6]);
    WR1_ADDR(REG_0100H, &S_INST2[7]);
    r_tsip_func100(0x790124fdU, 0x66e84559U, 0x57f25d9eU, 0xf954eb10U);
    WR1_PROG(REG_0104H, 0x00000761U);
    WR1_PROG(REG_00A4H, 0x00f92735U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[8]);
    WR1_ADDR(REG_0100H, &S_INST2[9]);
    WR1_ADDR(REG_0100H, &S_INST2[10]);
    WR1_ADDR(REG_0100H, &S_INST2[11]);
    WR1_PROG(REG_00A4H, 0x000027b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_INST2[12]);
    WR1_ADDR(REG_0100H, &S_INST2[13]);
    WR1_ADDR(REG_0100H, &S_INST2[14]);
    WR1_ADDR(REG_0100H, &S_INST2[15]);
    WR1_PROG(REG_00A4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x154e7976U, 0x18eabe69U, 0xa7ce6e5dU, 0x21fe211aU);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00040805U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_IV[0]);
    WR1_ADDR(REG_0100H, &InData_IV[1]);
    WR1_ADDR(REG_0100H, &InData_IV[2]);
    WR1_ADDR(REG_0100H, &InData_IV[3]);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00050804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    r_tsip_func103();
    r_tsip_func100(0xa405bae5U, 0x42ba7065U, 0x39dc127dU, 0x695d69e7U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0xf6b73642U, 0x308525c2U, 0x7f5bc010U, 0x22480263U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x5c136cc8U, 0xd214afe9U, 0x16d9a203U, 0xd9f477d9U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0144186bU));
    r_tsip_func100(0x5de28041U, 0xb0fab6ddU, 0xb965f93fU, 0xd9f85c7aU);
    WR1_PROG(REG_0000H, 0x00002113U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00d049a5U);
    WR1_PROG(REG_00C4H, 0x02e007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[0]);
    WR1_ADDR(REG_0100H, &InData_InstData[1]);
    WR1_ADDR(REG_0100H, &InData_InstData[2]);
    WR1_ADDR(REG_0100H, &InData_InstData[3]);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[4]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[5]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[6]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[7]);
    r_tsip_func100(0xbeba86c5U, 0x1d2a5636U, 0x23112355U, 0x49b07a77U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00451944U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00002113U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00d049a5U);
    WR1_PROG(REG_00C4H, 0x00e007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[4]);
    WR1_ADDR(REG_0100H, &InData_InstData[5]);
    WR1_ADDR(REG_0100H, &InData_InstData[6]);
    WR1_ADDR(REG_0100H, &InData_InstData[7]);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[8]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[9]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[10]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[11]);
    r_tsip_func100(0xbd8a670aU, 0x35ebd0deU, 0x4ca51880U, 0x5a9c96dbU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x000009c5U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000213U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[12]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[13]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[14]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[15]);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x00900c45U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_InstData[8]);
    WR1_ADDR(REG_0100H, &InData_InstData[9]);
    WR1_ADDR(REG_0100H, &InData_InstData[10]);
    WR1_ADDR(REG_0100H, &InData_InstData[11]);
    r_tsip_func100(0xbf4a2671U, 0x0e2f5347U, 0xc5427a08U, 0x8db8df09U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x378b88cbU, 0xddafe849U, 0xf77e73a4U, 0x2a61bf12U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        r_tsip_func100(0x011c9496U, 0xdcf6a609U, 0x2769962bU, 0x5208b98dU);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0004H, 0x00000613U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[0]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[1]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[2]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_KeyIndex[3]);
        r_tsip_func102(0x876ed941U, 0xef150d25U, 0x6b8258daU, 0xaa9fe621U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
}
