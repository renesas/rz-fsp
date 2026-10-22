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

void r_tsip_func307 (void)
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
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000090U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00003c1eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0xa3f008b9U, 0x21a083dfU, 0x40a8054dU, 0x2afe88d2U);
    r_tsip_func311();
    WR1_PROG(REG_00ECH, 0x00000a73U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000a31U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x00002e20U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x38002673U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x3dd44c2dU, 0x39316a40U, 0x00ba815eU, 0xc599adb1U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 0U))
        {
            r_tsip_func101(0x1e8758b5U, 0xf1373ee7U, 0xcd7ce46dU, 0x419f0b07U);
        }
        else
        {
            r_tsip_func100(0x17913040U, 0xbf1de61cU, 0x2d574419U, 0x8dc88d93U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01f8596cU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x0b64d56fU, 0xf7c8495dU, 0x44737fdfU, 0xc3db5e38U);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000010U);
            r_tsip_func312(204);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x010b2feaU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xc9799eecU, 0x12ecaf00U, 0x08ccd94eU, 0x5c464fb7U);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            r_tsip_func312(136);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01b3ca8cU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x0e232272U, 0x433ef833U, 0xd6c79022U, 0x9fa0469aU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(476);
            r_tsip_func100(0x238270c4U, 0x26c4465eU, 0x6fc6976bU, 0xd4a81613U);
            r_tsip_func314(476 + 64);
            r_tsip_func100(0x4fddbd0bU, 0x1747c425U, 0x50ea29ebU, 0x01f427e1U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01381a90U));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xa4933150U, 0xf595fe3aU, 0x8610350fU, 0x1a3ca1bbU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(612);
            r_tsip_func100(0xc341dd05U, 0x63a6b869U, 0xd157b876U, 0xd6cf295cU);
            r_tsip_func314(612 + 64);
            r_tsip_func100(0x6f06b758U, 0x1e24d2f8U, 0x01fbcafcU, 0x6eb1247cU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x0186fa0eU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xadc2ca1aU, 0x7dded3b5U, 0xb3d6dfdeU, 0x14960dd7U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(408);
            r_tsip_func100(0xb8531c98U, 0x688b5c34U, 0x6457ca35U, 0x1d74e27aU);
            r_tsip_func314(408 + 64);
            r_tsip_func100(0x07176be1U, 0x528ef186U, 0x40665b80U, 0x30dcc699U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01feea12U));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xdc07b3ceU, 0x226c7919U, 0x23304258U, 0xd9fbdc39U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(544);
            r_tsip_func100(0xed49da1dU, 0x5fce2082U, 0x2c9f6c90U, 0x36d60a34U);
            r_tsip_func314(544 + 64);
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000081U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0x5eee9853U, 0x769e2e26U, 0x26a8345bU, 0x691b6bfaU);
            r_tsip_func309();
            r_tsip_func100(0xb4677269U, 0xb7085512U, 0x58486b14U, 0xf9cd1e6aU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01f8596cU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x8ae6b15bU, 0xfdc6afdbU, 0xda0f0cf9U, 0xfaa381c2U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(204);
            r_tsip_func100(0xb9921380U, 0x5ed0e9a7U, 0xd4fdcd75U, 0x04760e50U);
            r_tsip_func314(204 + 64);
            r_tsip_func100(0xd291e693U, 0x9795b5feU, 0x9acedad5U, 0x95ca71b8U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x010b2feaU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xaee4ddd6U, 0x96f278feU, 0x1a4ddf94U, 0x0cc40474U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(136);
            r_tsip_func100(0xfc3af1bdU, 0x5a070e31U, 0xb39a9875U, 0x1d990d72U);
            r_tsip_func314(136 + 64);
            r_tsip_func101(0x3ae928ceU, 0x10cb9510U, 0x130b3df4U, 0xf7bd639aU);
        }

        WR1_PROG(REG_00ECH, 0x3800da9fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0xa9a23867U, 0xf7433138U, 0x7196f2bdU, 0xba84bb87U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 0U))
        {
            r_tsip_func101(0x3c145ed5U, 0xdc068ec2U, 0x89ad3de4U, 0x72d6953eU);
        }
        else
        {
            r_tsip_func100(0x1f50d252U, 0xf5676a3cU, 0x40778720U, 0x1f76400dU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01f8596cU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xc5f59604U, 0xb70d7f56U, 0x54e57793U, 0xd4f1502cU);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000010U);
            r_tsip_func312(204);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x010b2feaU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            r_tsip_func312(136);
            r_tsip_func100(0x84329246U, 0x94c76a16U, 0xe418aabdU, 0xc0569e6aU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01b3ca8cU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0xbc3bcceeU, 0xeb95d5e0U, 0x55059c5dU, 0x423ad741U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(476);
            r_tsip_func100(0xd0de1bc6U, 0x648de1d8U, 0x9170ebc5U, 0x582bfcc5U);
            r_tsip_func314(476 + 64);
            r_tsip_func100(0xcabfd0e1U, 0x1dafc65bU, 0xd3643be6U, 0x2fc5e923U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x0186fa0eU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x58258278U, 0x6e95c16dU, 0x792a2a3fU, 0x1e7bb1aaU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(408);
            r_tsip_func100(0x2017e5daU, 0x87998c75U, 0x95cb5a95U, 0xd42e6e5bU);
            r_tsip_func314(408 + 64);
            r_tsip_func100(0x84232cf4U, 0x9f68081bU, 0xbbaed83fU, 0x252cff7eU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01db9aafU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x8a70d9f2U, 0x59f0db87U, 0x45846f0cU, 0xa7a4cec9U);
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
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            r_tsip_func312(0);
            r_tsip_func100(0xb39a5d92U, 0x07fb5647U, 0x468ba5f0U, 0x7bb98934U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01381a90U));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x0f836473U, 0x2e33513dU, 0xb1f2e5e7U, 0xa9f74051U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(612);
            r_tsip_func100(0x70d876b9U, 0x91025e29U, 0xe2c43842U, 0xe66e591eU);
            r_tsip_func314(612 + 64);
            r_tsip_func100(0x0393e32aU, 0xd8f9269cU, 0x309e11a4U, 0xaf7f4ec3U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01feea12U));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x5370dc54U, 0x376d456eU, 0x935db5feU, 0x242903edU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(544);
            r_tsip_func100(0x8f97cf9eU, 0x703a110cU, 0xa0e79abcU, 0xc1c12c26U);
            r_tsip_func314(544 + 64);
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000082U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0x1d2d4a46U, 0x5d5ce6d3U, 0xb072feb5U, 0x5f45058eU);
            r_tsip_func309();
            r_tsip_func100(0xc22315efU, 0x9a101493U, 0xd2bd20e3U, 0x2f50a94eU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01f8596cU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x01b473caU, 0x9b7617b5U, 0xd73d5b92U, 0xc0de976fU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(204);
            r_tsip_func100(0x4917eb92U, 0xebdf4695U, 0x5d04e496U, 0x2403dad8U);
            r_tsip_func314(204 + 64);
            r_tsip_func100(0x1bdd07e2U, 0x2fb72dd1U, 0xc8809af6U, 0xffd419f9U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x010b2feaU));
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func080();
            r_tsip_func100(0x4bb548c5U, 0x287cef4dU, 0x0a187704U, 0x9876f3b4U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(136);
            r_tsip_func100(0x2d6de302U, 0xe32b776fU, 0x6ca492f9U, 0xe891449bU);
            r_tsip_func314(136 + 64);
            WR1_PROG(REG_00ECH, 0x0000d260U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0x513cb7b5U, 0x711df67eU, 0x40db7348U, 0x0ce41104U);
        }

        WR1_PROG(REG_00ECH, 0x01816e94U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0xbf39817aU, 0xd0c53173U, 0x77950bc1U, 0x361a1093U);
    }

    WR1_PROG(REG_00ECH, 0x38008a20U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0x1d04ec35U, 0xf51fdd65U, 0x82e5c9f8U, 0x8e955835U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01f8596cU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x314ce00bU, 0xdf92346aU, 0x972a5980U, 0x17bba591U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    r_tsip_func312(204);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x010b2feaU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x06a2b3faU, 0x1af65b32U, 0x052baaacU, 0x7147f72aU);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    r_tsip_func312(136);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b3ca8cU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xdd7b0639U, 0x430e63dbU, 0xca8d0931U, 0xc8a4ca0eU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(476);
    r_tsip_func100(0xfbea2b98U, 0xc9593c72U, 0x60130559U, 0x8ad6c8b0U);
    r_tsip_func314(476 + 64);
    r_tsip_func100(0x7268a7f8U, 0x73b87b0dU, 0x81a53154U, 0x8147e532U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0186fa0eU));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xa51a6645U, 0xe839384eU, 0x6dadc473U, 0x694545dbU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(408);
    r_tsip_func100(0x60966bbeU, 0xd7fbdfe3U, 0x4757bfc0U, 0x54544390U);
    r_tsip_func314(408 + 64);
    r_tsip_func100(0xd33086ddU, 0x07459446U, 0x3d0dac65U, 0xa084af3cU);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01381a90U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0xd744a9a7U, 0xca3a207cU, 0xa4c3ebf4U, 0x8c7699e3U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(612);
    r_tsip_func100(0x2328734fU, 0xc66ce4f8U, 0x92ba330aU, 0xbc25e378U);
    r_tsip_func314(612 + 64);
    r_tsip_func100(0x61218cb5U, 0xf60b7755U, 0x7017886fU, 0x3ecd8c8bU);
    WR1_PROG(REG_0024H, 0x00000581U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01feea12U));
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func080();
    r_tsip_func100(0x354e626eU, 0xeb751a71U, 0x220cf046U, 0x304c7a83U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(544);
    r_tsip_func100(0x5200cf91U, 0x2815876eU, 0x210b1ba8U, 0x340fd8a6U);
    r_tsip_func314(544 + 64);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000083U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func101(0x682e26f2U, 0xb0b93c05U, 0x018cbe18U, 0x09723f65U);
    r_tsip_func309();
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000090U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00007c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
}
