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
    r_tsip_func100(0xe77f7897U, 0xf1c4f6d8U, 0x365206b3U, 0xcc59fcaaU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x000d4d39U, 0xf85c63fbU, 0x6e2de979U, 0x21f26f0dU);
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
    r_tsip_func100(0x7db86efdU, 0x644f7273U, 0x6ee4d349U, 0xc8f10e40U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x010ed47dU));
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
    r_tsip_func100(0xdf2536e5U, 0xcecacbc9U, 0x8bcbf18cU, 0x32ee6ab4U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x6fda9b5dU, 0xce499c0bU, 0xf82955f6U, 0x4c6a332dU);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_KEY_FAIL;
    }
    else
    {
        r_tsip_func100(0xfffeebb7U, 0x81bdc475U, 0xee5dccb5U, 0xa6c1b41eU);
        r_tsip_func103();
        r_tsip_func100(0x31f8d97cU, 0xdab88addU, 0x385acdf8U, 0x1a91f598U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0x182c3db2U, 0x9a2313cdU, 0x16ae1915U, 0x5f6c8e23U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x012dc3c7U));
        r_tsip_func080();
        r_tsip_func100(0xb116ce54U, 0xe1280cb7U, 0x60b49abbU, 0x04305fa6U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(748);
        r_tsip_func100(0xb6c21dd3U, 0x2329bc5cU, 0xfcd71949U, 0xebef2e16U);
        r_tsip_func314(748 + 64);
        r_tsip_func100(0xace355f8U, 0x02fb9f66U, 0x8b1b13aaU, 0x7e3c1e37U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01b9d3a9U));
        r_tsip_func080();
        r_tsip_func100(0x9e73d08eU, 0x70f5b3d9U, 0xebd98ce0U, 0xc22d5423U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        r_tsip_func313(680);
        r_tsip_func100(0x7a178048U, 0x9cd0156dU, 0xf29c930fU, 0x3bb89614U);
        r_tsip_func314(680 + 64);
        WR1_PROG(REG_0000H, 0x000003ffU);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x800103e0U);
        WR1_PROG(REG_0000H, 0x00008307U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x3800dbe0U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x4531fd3aU, 0xbc0fca22U, 0xb5cd8e26U, 0x1002c141U);
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
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0132d44bU));
        r_tsip_func080();
        r_tsip_func100(0xd6f9bd6dU, 0x66b51dc2U, 0x10f325edU, 0x15855c99U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(68);
        r_tsip_func100(0xa178ca7fU, 0x23fd3f25U, 0xa00fb8e7U, 0x72e0f34cU);
        r_tsip_func314(68 + 64);
        r_tsip_func100(0xc73f7000U, 0x6f7f598bU, 0x6df459f2U, 0xb8f3148eU);
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
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01432c7aU));
        r_tsip_func080();
        r_tsip_func100(0x4e6ab066U, 0xd1a989a8U, 0x14a062f4U, 0x4c407835U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000024U);
        r_tsip_func313(0);
        r_tsip_func100(0x535ce6d5U, 0x85fcf766U, 0x16f4a805U, 0xfae082a1U);
        r_tsip_func314(0 + 64);
        r_tsip_func100(0xcee5eb7bU, 0x66211e48U, 0x677140a2U, 0xb8764229U);
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
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01b9d3a9U));
        r_tsip_func080();
        r_tsip_func100(0x82fe0ac9U, 0xf10cfc1aU, 0x9fbe1e82U, 0x6fbb023fU);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        r_tsip_func312(680);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x012dc3c7U));
        r_tsip_func080();
        r_tsip_func100(0xf14684f2U, 0x86158964U, 0x0ca21e30U, 0xb143e133U);
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
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01432c7aU));
        r_tsip_func080();
        r_tsip_func100(0x20376bccU, 0xf956ad03U, 0xb3a33f34U, 0x71cb2e55U);
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000014U);
        r_tsip_func312(0);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0132d44bU));
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
        r_tsip_func100(0x1729f4abU, 0x39c3ef5aU, 0xcf34ef3fU, 0x33058210U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x407230d3U, 0x3fbb664aU, 0x359ea4b9U, 0xda8e363eU);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_00ECH, 0x0000007cU);
            r_tsip_func101(0x2510c09aU, 0x2d6d595dU, 0x68a43392U, 0xd0e48351U);
            r_tsip_func307();
            r_tsip_func100(0x3f5b5645U, 0xf082e097U, 0x6f73dc8aU, 0x4cf3f507U);
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
            r_tsip_func100(0x194c833aU, 0x40961e0fU, 0xf7f5d7c6U, 0x7f83bc84U);
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
            r_tsip_func102(0x604da801U, 0xa1f41292U, 0x71470f3bU, 0x37872193U);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
    }
}
