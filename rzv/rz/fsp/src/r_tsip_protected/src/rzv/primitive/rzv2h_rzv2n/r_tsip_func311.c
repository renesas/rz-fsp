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

void r_tsip_func311 (void)
{
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
    r_tsip_func100(0x4b5ff74cU, 0x075c0c51U, 0x298fb3e2U, 0x9879d581U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000002cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00003c1eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x800080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x04000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_0034H, 0x00000008U);
    WR1_PROG(REG_0024H, 0x800011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000008U);
    WR1_PROG(REG_0024H, 0x82001191U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0178be44U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x1bb31594U, 0x0c9388b4U, 0xdbb96be5U, 0xd7bc7b10U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(680);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x018e0c6eU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    r_tsip_func312(748);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x04001991U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x060049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x02001191U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000581U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00210000U);
    oLoop1 = 1;
    while (oLoop1 == 1)
    {
        r_tsip_func100(0x733a0991U, 0x5b082b45U, 0x4ee74fafU, 0x0f35fadbU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x2bba7942U, 0xd4967a52U, 0x13728045U, 0x850ebc02U);
            oLoop1 = 0;
        }
        else
        {
            WR1_PROG(REG_0024H, 0x000049c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x04001991U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x060049c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x02001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func101(0x6507cb7eU, 0x88adf1e9U, 0x402b1f37U, 0xa3f56b2fU);
        }
    }

    r_tsip_func100(0x83ba68eeU, 0x906c938dU, 0x6a710ac7U, 0xa488b9f9U);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x04001981U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x060049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x02001181U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x010b2feaU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xf9dcc025U, 0xb752442dU, 0xcb1cdb17U, 0x1f26452aU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(136);
    r_tsip_func100(0xab061419U, 0xfd877f50U, 0xc352e90eU, 0x0742d0bcU);
    r_tsip_func314(136 + 64);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func100(0xf58743cfU, 0xd112481cU, 0x2559b6e2U, 0xe5d89b94U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01f8596cU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x28577c5dU, 0x57304f38U, 0x1bbc5a0cU, 0xb43eaf5cU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(204);
    r_tsip_func100(0x5ad82867U, 0xa2050d2aU, 0x707aca53U, 0xaf939bb7U);
    r_tsip_func314(204 + 64);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x00000a52U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
    {
        r_tsip_func100(0x1f4c85f8U, 0xba4fd626U, 0x92c59a9eU, 0xa90668d1U);
        WR1_PROG(REG_0024H, 0x040049c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04000149U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x060049c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0400d0d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x02000149U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0178be44U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000014U);
        r_tsip_func312(680);
        WR1_PROG(REG_00ECH, 0x00002e40U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x254d8f4dU, 0x83bb838fU, 0x4e80a651U, 0xda8dcdd7U);
    }

    r_tsip_func100(0x95dde29aU, 0xdc155525U, 0xc6866998U, 0xb32abffdU);
    WR1_PROG(REG_00ECH, 0x38008a40U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000100U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0024H, 0x040049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x040019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x060049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0400d0d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x020019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0178be44U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x0f625c76U, 0x6bd2a45cU, 0x2a9eb794U, 0xa3c4943fU);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(680);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0186fa0eU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xf0370476U, 0x3a23bb41U, 0x719754d7U, 0xe5f59914U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(408);
    r_tsip_func100(0x342f5476U, 0x698f936fU, 0x666d1f01U, 0x47d46d3bU);
    r_tsip_func314(408 + 64);
    r_tsip_func100(0xe26ce0e4U, 0x0ef22562U, 0x84ae6f4aU, 0xab4bc15aU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01feea12U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x6811c0f1U, 0x95d72912U, 0x12c4353dU, 0x23937078U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(544);
    r_tsip_func100(0x4b5df89aU, 0x137ff1e1U, 0xc62a4e80U, 0x3b0a33acU);
    r_tsip_func314(544 + 64);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func100(0x23cff6ecU, 0xb1b9ae5cU, 0x85c66e1dU, 0xc2e0644dU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b3ca8cU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xd8b0406eU, 0xa6dd989fU, 0x4778260bU, 0x54539b39U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(476);
    r_tsip_func100(0xcf16294cU, 0x8930c493U, 0x726439ecU, 0xe1b752c3U);
    r_tsip_func314(476 + 64);
    r_tsip_func100(0xcb5414e2U, 0xc3f45648U, 0x7a080fe6U, 0x6075f0b8U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01381a90U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x42dedce8U, 0x87eb53ddU, 0x7ed5063cU, 0x52b90050U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(612);
    r_tsip_func100(0xd55f92ddU, 0x9b3cc8e5U, 0x433eeeccU, 0x12ca2d61U);
    r_tsip_func314(612 + 64);
    WR1_PROG(REG_00ECH, 0x00000a52U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000085U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x0dfef9e2U, 0x53826172U, 0x0c9998c2U, 0xefb95b50U);
        r_tsip_func309();
        r_tsip_func100(0x7516ba78U, 0x1101faafU, 0x026e5f19U, 0x3aa0dd3dU);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01b3ca8cU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0xe2e37d4eU, 0x6d2446ecU, 0xb7450677U, 0x7f3a135fU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(476);
        r_tsip_func100(0x03672719U, 0xa4b4283dU, 0x320d5b7dU, 0x9c26c5caU);
        r_tsip_func314(476 + 64);
        r_tsip_func100(0xa850cc02U, 0x52064c7bU, 0x9f20fd3dU, 0x799c6900U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01381a90U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0xb7122e62U, 0x818f427bU, 0x260dde03U, 0x51f58147U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(612);
        r_tsip_func100(0x201d7b0aU, 0xdce1ac2bU, 0x0c077392U, 0xa61f6238U);
        r_tsip_func314(612 + 64);
        r_tsip_func100(0x9639ac44U, 0xd9fbd26dU, 0xd107581dU, 0x1421bcd2U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x0186fa0eU));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x20618504U, 0x20eee41aU, 0x0b8b7f4fU, 0x33917fc9U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        r_tsip_func313(408);
        r_tsip_func100(0x3b24fff0U, 0xc7be2770U, 0xc0f44521U, 0x6341a01bU);
        r_tsip_func314(408 + 64);
        r_tsip_func100(0x02a222f3U, 0xcf6e7734U, 0xccf32b3fU, 0x7f63de94U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01feea12U));
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func080();
        r_tsip_func100(0x15bf2322U, 0x57637bf7U, 0x0a0d0dd8U, 0xea2b342cU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        r_tsip_func313(544);
        r_tsip_func100(0x4d39ad1eU, 0x3a49fcf9U, 0xac428178U, 0x858665d4U);
        r_tsip_func314(544 + 64);
        WR1_PROG(REG_00ECH, 0x00002e40U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x438e494bU, 0x07075f39U, 0x6949c530U, 0x55a5ab1cU);
    }

    WR1_PROG(REG_00ECH, 0x38008a40U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0x7c210635U, 0x685b2089U, 0xd4f708daU, 0xf312367cU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b3ca8cU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x3bb9dde2U, 0x7861b1b2U, 0x82716ac6U, 0x5c83f75cU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(476);
    r_tsip_func100(0x3161a5e4U, 0xfd2ec19bU, 0x61457c36U, 0xd2fbd688U);
    r_tsip_func314(476 + 64);
    r_tsip_func100(0x1c0a2293U, 0x0e4b3740U, 0x51dd52b6U, 0x7c46e8dcU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0186fa0eU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x4e5f8651U, 0x8b3bbaccU, 0x88231951U, 0x13ef5ae2U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(408);
    r_tsip_func100(0x0e96af91U, 0x16665222U, 0x295aa95aU, 0x501c57b0U);
    r_tsip_func314(408 + 64);
    r_tsip_func100(0x9ef94746U, 0xc0658de0U, 0x5b5090dcU, 0x6176b1aeU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01db9aafU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xfe497d0aU, 0xd39f0b30U, 0xcbbba572U, 0x1299c4a4U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    r_tsip_func312(68);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019175a3U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x7981ac08U, 0x42b53c96U, 0x622b69fcU, 0xa6fc993aU);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    r_tsip_func312(0);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01381a90U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x9ae1614eU, 0x000cda02U, 0x084a0741U, 0x93d57f14U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(612);
    r_tsip_func100(0x960f158dU, 0xdebdcf94U, 0x329d43e5U, 0x3fc02057U);
    r_tsip_func314(612 + 64);
    r_tsip_func100(0x8556e36aU, 0xe0d2b128U, 0x07e93f57U, 0x74891402U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01feea12U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x77d5ed11U, 0x8e8ddd1fU, 0x47204b39U, 0x547e6dd2U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(544);
    r_tsip_func100(0x0a465fcfU, 0xc2446fc5U, 0xfdf38ab1U, 0x845fc48fU);
    r_tsip_func314(544 + 64);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000086U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0xb5567399U, 0x2d6b91f9U, 0x7e32a968U, 0xdd9f6b3cU);
    r_tsip_func309();
    r_tsip_func100(0x859f00d6U, 0x9c5067b8U, 0x2874990aU, 0xac169ba5U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01db9aafU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x9f7a0c3dU, 0x01ccb214U, 0xeff90799U, 0xda9f0bd9U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(68);
    r_tsip_func100(0xca7583feU, 0x73cc3f96U, 0x7ee88323U, 0x67dd3da3U);
    r_tsip_func314(68 + 64);
    r_tsip_func100(0xe6f26b0cU, 0xfbcef142U, 0x90edd460U, 0x5ae7aa5cU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019175a3U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x91c4337aU, 0x20460303U, 0x62e03b1eU, 0x905f4b69U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(0);
    r_tsip_func100(0xdbd5eaa3U, 0x9d0ba4c8U, 0x3331d746U, 0xa98aab01U);
    r_tsip_func314(0 + 64);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000002cU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00007c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
}
