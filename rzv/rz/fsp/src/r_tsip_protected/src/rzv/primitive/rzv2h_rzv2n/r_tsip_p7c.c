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

tsip_ret_t r_tsip_p7c (const uint32_t InData_KeyIndex[], const uint32_t InData_Text[], uint32_t OutData_Text[])
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

    WR1_PROG(REG_0084H, 0x00007c02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x6a3cc5d2U, 0x3a7b05f7U, 0x7e27fb88U, 0x24e48767U);
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
    r_tsip_func100(0x7bfd1b5eU, 0x482476c5U, 0x4e1ed7aaU, 0xf7827267U);
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
    r_tsip_func100(0xe5eee02fU, 0x817c14a5U, 0x08ba63f2U, 0x909acf6fU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x018d1828U));
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0104H, 0x00007f62U);
    WR1_PROG(REG_00D0H, 0x00001f00U);
    WR1_PROG(REG_00C4H, 0x02e08887U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    for (iLoop = 64; iLoop < 128; iLoop = iLoop + 4)
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
    WR1_PROG(REG_00C4H, 0x00e00885U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 4]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 5]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 6]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 7]);
    WR1_PROG(REG_00E0H, 0x80010280U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008207U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x0000020fU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000362U);
    WR1_PROG(REG_00C4H, 0x000007b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 8]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 9]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 10]);
    WR1_ADDR(REG_0100H, &InData_KeyIndex[iLoop + 11]);
    WR1_PROG(REG_00C4H, 0x00900c45U);
    WR1_PROG(REG_0000H, 0x00002213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x9435dab9U, 0xf48221aeU, 0xb7ca6b89U, 0x7e63d56bU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x8c4c8e76U, 0xcac2e57aU, 0x061c5ecbU, 0x2489fb80U);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0xe5ab69ecU, 0x9f611cc7U, 0xb4b18071U, 0x64b4d108U);
        r_tsip_func103();
        r_tsip_func100(0xddf89e32U, 0x518a5ebbU, 0x92c0f349U, 0xf4b4f76bU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0xd0288521U, 0x3d5f7670U, 0xab0a08a9U, 0x31e5a865U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x018e0c6eU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x787377f9U, 0x7db24d2aU, 0x9e9fa2cbU, 0x9d069bf7U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(748);
        r_tsip_func100(0x046ea738U, 0xef776e7bU, 0x4759270dU, 0x43919131U);
        r_tsip_func314(748 + 64);
        r_tsip_func100(0x3b79a1f1U, 0xc3486b59U, 0x5dfd2c61U, 0x5e28836bU);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0178be44U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x452cdf25U, 0x2e358a27U, 0x771c41edU, 0x2804f80fU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        r_tsip_func313(680);
        r_tsip_func100(0x85c88c89U, 0x13901ad3U, 0x31a1da8bU, 0xdbdbd015U);
        r_tsip_func314(680 + 64);
        WR1_PROG(REG_0000H, 0x000003ffU);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x800103e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008307U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x3800dbe0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x2b3027e2U, 0xf4e5c177U, 0xae4f6aeaU, 0x22d2cbd3U);
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
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01db9aafU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x103783cfU, 0x00a23cc0U, 0x8534ee7bU, 0x9cc26f35U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(68);
        r_tsip_func100(0x936b826eU, 0xfb31990aU, 0xae8f0537U, 0x2c5a33aaU);
        r_tsip_func314(68 + 64);
        r_tsip_func100(0x124e0f70U, 0x3b79511cU, 0x41e7bf5bU, 0x07873eb0U);
        WR1_PROG(REG_002CH, 0x00000014U);
        WR1_PROG(REG_0104H, 0x00003f67U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_Text[64]);
        WR1_ADDR(REG_0100H, &InData_Text[65]);
        WR1_ADDR(REG_0100H, &InData_Text[66]);
        WR1_ADDR(REG_0100H, &InData_Text[67]);
        WR1_ADDR(REG_0100H, &InData_Text[68]);
        WR1_ADDR(REG_0100H, &InData_Text[69]);
        WR1_ADDR(REG_0100H, &InData_Text[70]);
        WR1_ADDR(REG_0100H, &InData_Text[71]);
        WR1_ADDR(REG_0100H, &InData_Text[72]);
        WR1_ADDR(REG_0100H, &InData_Text[73]);
        WR1_ADDR(REG_0100H, &InData_Text[74]);
        WR1_ADDR(REG_0100H, &InData_Text[75]);
        WR1_ADDR(REG_0100H, &InData_Text[76]);
        WR1_ADDR(REG_0100H, &InData_Text[77]);
        WR1_ADDR(REG_0100H, &InData_Text[78]);
        WR1_ADDR(REG_0100H, &InData_Text[79]);
        WR1_ADDR(REG_0100H, &InData_Text[80]);
        WR1_ADDR(REG_0100H, &InData_Text[81]);
        WR1_ADDR(REG_0100H, &InData_Text[82]);
        WR1_ADDR(REG_0100H, &InData_Text[83]);
        WR1_ADDR(REG_0100H, &InData_Text[84]);
        WR1_ADDR(REG_0100H, &InData_Text[85]);
        WR1_ADDR(REG_0100H, &InData_Text[86]);
        WR1_ADDR(REG_0100H, &InData_Text[87]);
        WR1_ADDR(REG_0100H, &InData_Text[88]);
        WR1_ADDR(REG_0100H, &InData_Text[89]);
        WR1_ADDR(REG_0100H, &InData_Text[90]);
        WR1_ADDR(REG_0100H, &InData_Text[91]);
        WR1_ADDR(REG_0100H, &InData_Text[92]);
        WR1_ADDR(REG_0100H, &InData_Text[93]);
        WR1_ADDR(REG_0100H, &InData_Text[94]);
        WR1_ADDR(REG_0100H, &InData_Text[95]);
        WR1_ADDR(REG_0100H, &InData_Text[96]);
        WR1_ADDR(REG_0100H, &InData_Text[97]);
        WR1_ADDR(REG_0100H, &InData_Text[98]);
        WR1_ADDR(REG_0100H, &InData_Text[99]);
        WR1_ADDR(REG_0100H, &InData_Text[100]);
        WR1_ADDR(REG_0100H, &InData_Text[101]);
        WR1_ADDR(REG_0100H, &InData_Text[102]);
        WR1_ADDR(REG_0100H, &InData_Text[103]);
        WR1_ADDR(REG_0100H, &InData_Text[104]);
        WR1_ADDR(REG_0100H, &InData_Text[105]);
        WR1_ADDR(REG_0100H, &InData_Text[106]);
        WR1_ADDR(REG_0100H, &InData_Text[107]);
        WR1_ADDR(REG_0100H, &InData_Text[108]);
        WR1_ADDR(REG_0100H, &InData_Text[109]);
        WR1_ADDR(REG_0100H, &InData_Text[110]);
        WR1_ADDR(REG_0100H, &InData_Text[111]);
        WR1_ADDR(REG_0100H, &InData_Text[112]);
        WR1_ADDR(REG_0100H, &InData_Text[113]);
        WR1_ADDR(REG_0100H, &InData_Text[114]);
        WR1_ADDR(REG_0100H, &InData_Text[115]);
        WR1_ADDR(REG_0100H, &InData_Text[116]);
        WR1_ADDR(REG_0100H, &InData_Text[117]);
        WR1_ADDR(REG_0100H, &InData_Text[118]);
        WR1_ADDR(REG_0100H, &InData_Text[119]);
        WR1_ADDR(REG_0100H, &InData_Text[120]);
        WR1_ADDR(REG_0100H, &InData_Text[121]);
        WR1_ADDR(REG_0100H, &InData_Text[122]);
        WR1_ADDR(REG_0100H, &InData_Text[123]);
        WR1_ADDR(REG_0100H, &InData_Text[124]);
        WR1_ADDR(REG_0100H, &InData_Text[125]);
        WR1_ADDR(REG_0100H, &InData_Text[126]);
        WR1_ADDR(REG_0100H, &InData_Text[127]);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x019175a3U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0xe2f964b3U, 0x7797e13cU, 0x2d468e52U, 0x4dacb52fU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000024U);
        r_tsip_func313(0);
        r_tsip_func100(0x188e4592U, 0xcdd7a1f6U, 0x8857448cU, 0xe86d6167U);
        r_tsip_func314(0 + 64);
        r_tsip_func100(0x72a0ec2dU, 0x59359bc9U, 0xce6a4972U, 0xd2a6368bU);
        WR1_PROG(REG_0024H, 0x000040d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000005c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x060049c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x02001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00a10000U);
        WR1_PROG(REG_0024H, 0x000005c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000581U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0178be44U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x3c29d7ffU, 0xbbfb5580U, 0x359f6a71U, 0x1a95856bU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        r_tsip_func312(680);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x018e0c6eU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x28c8903aU, 0x744155b6U, 0xec36bab2U, 0xbea2aadcU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000012U);
        r_tsip_func312(748);
        WR1_PROG(REG_0024H, 0x000080d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x060049c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x02001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000049c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x019175a3U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0xb425cb48U, 0x16d55f27U, 0x7e99bba2U, 0x1761b809U);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000014U);
        r_tsip_func312(0);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01db9aafU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        r_tsip_func312(68);
        WR1_PROG(REG_0024H, 0x04001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x060049c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x02001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x611fe255U, 0x35754949U, 0xd56a7308U, 0x68fce9afU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x6cdc22f9U, 0xe6db6602U, 0x57e8b66dU, 0xf4f2e178U);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000007cU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0x6fe17cb5U, 0xefdbc613U, 0x9567739fU, 0x873e0d46U);
            r_tsip_func307();
            r_tsip_func100(0xb03f1199U, 0x87e2a27fU, 0x3b33f937U, 0xc9ee58f3U);
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
            r_tsip_func100(0x886e4825U, 0x18fa1025U, 0xfc69c0f1U, 0x9e945a82U);
            WR1_PROG(REG_002CH, 0x00000022U);
            WR1_PROG(REG_0004H, 0x00000302U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &OutData_Text[64]);
            RD1_ADDR(REG_0100H, &OutData_Text[65]);
            RD1_ADDR(REG_0100H, &OutData_Text[66]);
            RD1_ADDR(REG_0100H, &OutData_Text[67]);
            RD1_ADDR(REG_0100H, &OutData_Text[68]);
            RD1_ADDR(REG_0100H, &OutData_Text[69]);
            RD1_ADDR(REG_0100H, &OutData_Text[70]);
            RD1_ADDR(REG_0100H, &OutData_Text[71]);
            RD1_ADDR(REG_0100H, &OutData_Text[72]);
            RD1_ADDR(REG_0100H, &OutData_Text[73]);
            RD1_ADDR(REG_0100H, &OutData_Text[74]);
            RD1_ADDR(REG_0100H, &OutData_Text[75]);
            RD1_ADDR(REG_0100H, &OutData_Text[76]);
            RD1_ADDR(REG_0100H, &OutData_Text[77]);
            RD1_ADDR(REG_0100H, &OutData_Text[78]);
            RD1_ADDR(REG_0100H, &OutData_Text[79]);
            RD1_ADDR(REG_0100H, &OutData_Text[80]);
            RD1_ADDR(REG_0100H, &OutData_Text[81]);
            RD1_ADDR(REG_0100H, &OutData_Text[82]);
            RD1_ADDR(REG_0100H, &OutData_Text[83]);
            RD1_ADDR(REG_0100H, &OutData_Text[84]);
            RD1_ADDR(REG_0100H, &OutData_Text[85]);
            RD1_ADDR(REG_0100H, &OutData_Text[86]);
            RD1_ADDR(REG_0100H, &OutData_Text[87]);
            RD1_ADDR(REG_0100H, &OutData_Text[88]);
            RD1_ADDR(REG_0100H, &OutData_Text[89]);
            RD1_ADDR(REG_0100H, &OutData_Text[90]);
            RD1_ADDR(REG_0100H, &OutData_Text[91]);
            RD1_ADDR(REG_0100H, &OutData_Text[92]);
            RD1_ADDR(REG_0100H, &OutData_Text[93]);
            RD1_ADDR(REG_0100H, &OutData_Text[94]);
            RD1_ADDR(REG_0100H, &OutData_Text[95]);
            RD1_ADDR(REG_0100H, &OutData_Text[96]);
            RD1_ADDR(REG_0100H, &OutData_Text[97]);
            RD1_ADDR(REG_0100H, &OutData_Text[98]);
            RD1_ADDR(REG_0100H, &OutData_Text[99]);
            RD1_ADDR(REG_0100H, &OutData_Text[100]);
            RD1_ADDR(REG_0100H, &OutData_Text[101]);
            RD1_ADDR(REG_0100H, &OutData_Text[102]);
            RD1_ADDR(REG_0100H, &OutData_Text[103]);
            RD1_ADDR(REG_0100H, &OutData_Text[104]);
            RD1_ADDR(REG_0100H, &OutData_Text[105]);
            RD1_ADDR(REG_0100H, &OutData_Text[106]);
            RD1_ADDR(REG_0100H, &OutData_Text[107]);
            RD1_ADDR(REG_0100H, &OutData_Text[108]);
            RD1_ADDR(REG_0100H, &OutData_Text[109]);
            RD1_ADDR(REG_0100H, &OutData_Text[110]);
            RD1_ADDR(REG_0100H, &OutData_Text[111]);
            RD1_ADDR(REG_0100H, &OutData_Text[112]);
            RD1_ADDR(REG_0100H, &OutData_Text[113]);
            RD1_ADDR(REG_0100H, &OutData_Text[114]);
            RD1_ADDR(REG_0100H, &OutData_Text[115]);
            RD1_ADDR(REG_0100H, &OutData_Text[116]);
            RD1_ADDR(REG_0100H, &OutData_Text[117]);
            RD1_ADDR(REG_0100H, &OutData_Text[118]);
            RD1_ADDR(REG_0100H, &OutData_Text[119]);
            RD1_ADDR(REG_0100H, &OutData_Text[120]);
            RD1_ADDR(REG_0100H, &OutData_Text[121]);
            RD1_ADDR(REG_0100H, &OutData_Text[122]);
            RD1_ADDR(REG_0100H, &OutData_Text[123]);
            RD1_ADDR(REG_0100H, &OutData_Text[124]);
            RD1_ADDR(REG_0100H, &OutData_Text[125]);
            RD1_ADDR(REG_0100H, &OutData_Text[126]);
            RD1_ADDR(REG_0100H, &OutData_Text[127]);
            r_tsip_func102(0xc5fc8a50U, 0xd769192fU, 0xef2363e4U, 0x73d3b5beU);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
