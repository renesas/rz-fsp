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
    r_tsip_func100(0x8a8ea4d4U, 0x09be8803U, 0x82e57699U, 0x0fdd4e9bU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x0000002cU);
    WR1_PROG(REG_00ECH, 0x00003c1eU);
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
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b9d3a9U));
    r_tsip_func080();
    r_tsip_func100(0x70b5e656U, 0x75df5630U, 0x78c5bc1bU, 0x3fdeb3e9U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(680);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x012dc3c7U));
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
        r_tsip_func100(0x4108718cU, 0x1dece81eU, 0xcad1f1c9U, 0x04f0ae70U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x0fde97f1U, 0xdb534434U, 0xad9aa141U, 0x56dd06d4U);
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
            r_tsip_func101(0x1aa50941U, 0xc4f0d3b3U, 0x5b20719dU, 0xba9abf57U);
        }
    }

    r_tsip_func100(0x770a9f86U, 0xc1d80a74U, 0x60dcb9cdU, 0xc0976b2eU);
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
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016bcaa1U));
    r_tsip_func080();
    r_tsip_func100(0x49ee5752U, 0x825a247aU, 0xc9c40079U, 0x75df9730U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(136);
    r_tsip_func100(0x0ca6a448U, 0x8a1208b8U, 0xd9ebca34U, 0x20f0d145U);
    r_tsip_func314(136 + 64);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func100(0xcac54980U, 0xf1b40628U, 0x553889c3U, 0x8a70c829U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019c85beU));
    r_tsip_func080();
    r_tsip_func100(0xcca4126dU, 0x9d9520d8U, 0xa97845d7U, 0xd390e390U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(204);
    r_tsip_func100(0xcdbed2d8U, 0xcad59720U, 0xc8373e3cU, 0x17269102U);
    r_tsip_func314(204 + 64);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x00000a52U);
    for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
    {
        r_tsip_func100(0x5fa47742U, 0x73072bfbU, 0x043a0f75U, 0x8afa45a7U);
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
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01b9d3a9U));
        r_tsip_func080();
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000014U);
        r_tsip_func312(680);
        WR1_PROG(REG_00ECH, 0x00002e40U);
        r_tsip_func101(0xf4d7e25dU, 0xdf9c223aU, 0x462825ebU, 0xccc8edebU);
    }

    r_tsip_func100(0x3984b249U, 0xbbc898aaU, 0x22298b0aU, 0x45168d80U);
    WR1_PROG(REG_00ECH, 0x38008a40U);
    WR1_PROG(REG_00ECH, 0x00000100U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
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
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b9d3a9U));
    r_tsip_func080();
    r_tsip_func100(0xd69aec09U, 0x4109c4beU, 0x26f523b3U, 0xed584dc8U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(680);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x011f5dcdU));
    r_tsip_func080();
    r_tsip_func100(0x26acc2ebU, 0x331d6c52U, 0xef6261f6U, 0x2a7dc793U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(408);
    r_tsip_func100(0x9acd66c8U, 0x8e7c16f0U, 0x544fc8dbU, 0x4bf05e68U);
    r_tsip_func314(408 + 64);
    r_tsip_func100(0xffc9ce2cU, 0xe79402d8U, 0xb08655dcU, 0x7cab738fU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01e59c3dU));
    r_tsip_func080();
    r_tsip_func100(0xbca1600bU, 0x4b342140U, 0x12aa3f08U, 0x0f31ac94U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(544);
    r_tsip_func100(0x764c7f81U, 0xbf0f7dd7U, 0xcecc4994U, 0xb4bae568U);
    r_tsip_func314(544 + 64);
    WR1_PROG(REG_0024H, 0x000049c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func100(0x2807d723U, 0x2f429c33U, 0x41837f53U, 0x7105afb9U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a67f45U));
    r_tsip_func080();
    r_tsip_func100(0x85bd28aaU, 0x4723229dU, 0x8e81e7f0U, 0xfb6f2abfU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(476);
    r_tsip_func100(0x90b6d038U, 0x796eb08cU, 0x3224731bU, 0xbc49d1dfU);
    r_tsip_func314(476 + 64);
    r_tsip_func100(0xf20b3fe3U, 0x08089a4fU, 0x16cb7418U, 0x7aec9b82U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019fce91U));
    r_tsip_func080();
    r_tsip_func100(0x8790f38cU, 0x918d2b38U, 0xfaeadf6dU, 0xe6317263U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(612);
    r_tsip_func100(0xfdc02ee1U, 0xede696c3U, 0x72c55e6dU, 0x934c52f8U);
    r_tsip_func314(612 + 64);
    WR1_PROG(REG_00ECH, 0x00000a52U);
    for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x0000b400U);
        WR1_PROG(REG_00ECH, 0x00000085U);
        r_tsip_func101(0x1ee3b0ceU, 0x4f0e5e76U, 0xd664e5b0U, 0x809ea130U);
        r_tsip_func309();
        r_tsip_func100(0x6533b674U, 0x6dcf347aU, 0xa0d66d57U, 0xcaec2d3fU);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01a67f45U));
        r_tsip_func080();
        r_tsip_func100(0xfe1d7d3aU, 0xd2c4c26dU, 0xe8dde380U, 0xcccfa05eU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(476);
        r_tsip_func100(0xde43895dU, 0xd66d07b4U, 0x263e90acU, 0x9eccc6a0U);
        r_tsip_func314(476 + 64);
        r_tsip_func100(0xd720a2dbU, 0xc52ca8acU, 0x3a8bd25eU, 0x4ed9cf6aU);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x019fce91U));
        r_tsip_func080();
        r_tsip_func100(0x5fe959acU, 0x80637df3U, 0x585036c5U, 0x7c4ed57dU);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        r_tsip_func313(612);
        r_tsip_func100(0xc1a6c1cfU, 0x5022529fU, 0x9dcf49eeU, 0xb055500aU);
        r_tsip_func314(612 + 64);
        r_tsip_func100(0x08f224deU, 0xc62ce953U, 0x9173b77cU, 0x05b98f1aU);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x011f5dcdU));
        r_tsip_func080();
        r_tsip_func100(0x0c9d580aU, 0x47bdab48U, 0x88c8e42dU, 0x1b39cc22U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        r_tsip_func313(408);
        r_tsip_func100(0x2d651752U, 0x70c8e55bU, 0xfa169774U, 0x685d8563U);
        r_tsip_func314(408 + 64);
        r_tsip_func100(0xcafe1073U, 0xa142b70cU, 0x82adf4e2U, 0x0f7abad2U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01e59c3dU));
        r_tsip_func080();
        r_tsip_func100(0x040cecb3U, 0x7340db4cU, 0xfa93eea4U, 0x85f688d4U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        r_tsip_func313(544);
        r_tsip_func100(0x4418406dU, 0x9c502897U, 0x241c9966U, 0x9fb82c02U);
        r_tsip_func314(544 + 64);
        WR1_PROG(REG_00ECH, 0x00002e40U);
        r_tsip_func101(0xadbb8c24U, 0xd6218afeU, 0x0c52c599U, 0xd57ae05aU);
    }

    WR1_PROG(REG_00ECH, 0x38008a40U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    r_tsip_func100(0x65d765e7U, 0x5332dcbaU, 0x2f864256U, 0xf2a4179eU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a67f45U));
    r_tsip_func080();
    r_tsip_func100(0x97171fa0U, 0x5e3019eeU, 0x15186ad5U, 0xa91deb1dU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(476);
    r_tsip_func100(0x39bb5350U, 0x63cde5acU, 0xe88cbf22U, 0x9458ff69U);
    r_tsip_func314(476 + 64);
    r_tsip_func100(0xae2b0544U, 0x01f50a5aU, 0xc0a74648U, 0xacfaeb46U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x011f5dcdU));
    r_tsip_func080();
    r_tsip_func100(0x553f4802U, 0x32ca9ed2U, 0x551ed2bdU, 0x937b8b0bU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(408);
    r_tsip_func100(0xf3f7c86bU, 0x192c46d2U, 0x9400107fU, 0x0e8180b2U);
    r_tsip_func314(408 + 64);
    r_tsip_func100(0xad517463U, 0xc9e2b306U, 0x53555d75U, 0x6020f15cU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0132d44bU));
    r_tsip_func080();
    r_tsip_func100(0x428910bdU, 0xfa7f3a51U, 0xe5aa8816U, 0x04d95799U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    r_tsip_func312(68);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01432c7aU));
    r_tsip_func080();
    r_tsip_func100(0xab57fc37U, 0x15d37edaU, 0x88fddc36U, 0x81920804U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    r_tsip_func312(0);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019fce91U));
    r_tsip_func080();
    r_tsip_func100(0xd73b27aaU, 0x4fabdbaaU, 0x12c37a18U, 0x12502f03U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(612);
    r_tsip_func100(0xfe1609d0U, 0x0b5863a1U, 0xe41cb7abU, 0xd9f00ae3U);
    r_tsip_func314(612 + 64);
    r_tsip_func100(0xa4fe9687U, 0xf507214eU, 0x215b2d3bU, 0xf07c1cbcU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01e59c3dU));
    r_tsip_func080();
    r_tsip_func100(0xc2ca16dbU, 0x356efa83U, 0x6fb256faU, 0xebcc07fcU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(544);
    r_tsip_func100(0x21f409a8U, 0xe3b95d11U, 0x709100abU, 0x576fcb34U);
    r_tsip_func314(544 + 64);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000086U);
    r_tsip_func101(0xf23c8d74U, 0x09ba295cU, 0x6998a23bU, 0x850b9f24U);
    r_tsip_func309();
    r_tsip_func100(0xa6c6fa68U, 0xb9174a03U, 0x622730f1U, 0xb45b846eU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0132d44bU));
    r_tsip_func080();
    r_tsip_func100(0x4a1788afU, 0x1e9ce0d1U, 0x1ff3a832U, 0xce05bf01U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(68);
    r_tsip_func100(0xcbf73173U, 0x64fbe318U, 0xd0a5c6d6U, 0x9efe5bb3U);
    r_tsip_func314(68 + 64);
    r_tsip_func100(0x04010114U, 0xfbdcf5e7U, 0xc02c2c41U, 0xd1ff1f2fU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01432c7aU));
    r_tsip_func080();
    r_tsip_func100(0xe4434ac5U, 0xc7d2a678U, 0x1419490fU, 0xa3b07775U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(0);
    r_tsip_func100(0xbba2ff74U, 0x5d08cbcaU, 0x8d386296U, 0xc28ebd75U);
    r_tsip_func314(0 + 64);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x0000002cU);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_00ECH, 0x00007c00U);
    WR1_PROG(REG_001CH, 0x00602000U);
}
