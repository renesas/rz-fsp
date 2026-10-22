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
    WR1_PROG(REG_00ECH, 0x00000090U);
    WR1_PROG(REG_00ECH, 0x00003c1eU);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    r_tsip_func101(0xcf0da21aU, 0xa1b7187dU, 0xd9982d3eU, 0x95003459U);
    r_tsip_func311();
    WR1_PROG(REG_00ECH, 0x00000a73U);
    WR1_PROG(REG_00ECH, 0x00000a31U);
    for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x00002e20U);
        WR1_PROG(REG_00ECH, 0x38002673U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x5c6d56dcU, 0xdc1339dfU, 0x588b22cfU, 0xecb1a1c2U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 0U))
        {
            r_tsip_func101(0x53e155bfU, 0xa70b671dU, 0x64a74577U, 0x6a8f2f21U);
        }
        else
        {
            r_tsip_func100(0xfc16b73eU, 0x318ae7f6U, 0xb516e218U, 0x4aeb9793U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x019c85beU));
            r_tsip_func080();
            r_tsip_func100(0x7a360babU, 0x31e8170bU, 0x2dfd6a60U, 0x1c5fe4caU);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000010U);
            r_tsip_func312(204);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x016bcaa1U));
            r_tsip_func080();
            r_tsip_func100(0x7e95d1aaU, 0xa774d54eU, 0xa45544c3U, 0xe5f81f65U);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            r_tsip_func312(136);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01a67f45U));
            r_tsip_func080();
            r_tsip_func100(0xab444e02U, 0xd0282b00U, 0x5abc99d4U, 0xc18c9f57U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(476);
            r_tsip_func100(0x0e7a8a90U, 0x16765a42U, 0xe52258e0U, 0xe50db19aU);
            r_tsip_func314(476 + 64);
            r_tsip_func100(0x0323db97U, 0x37c89faeU, 0x91824b9fU, 0xd9fb0030U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x019fce91U));
            r_tsip_func080();
            r_tsip_func100(0x4059233cU, 0x4a9fdc0cU, 0x535c9741U, 0xb0ea4799U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(612);
            r_tsip_func100(0xfb0676c6U, 0x7e2c6988U, 0x9fb5d402U, 0x0395eb6aU);
            r_tsip_func314(612 + 64);
            r_tsip_func100(0xe61bad0cU, 0x6e398f06U, 0x3ad2ad9bU, 0x9a2920d5U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x011f5dcdU));
            r_tsip_func080();
            r_tsip_func100(0x77dd121cU, 0x2e663f83U, 0xbec4e0e3U, 0x7ac8314dU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(408);
            r_tsip_func100(0x58aba653U, 0xc89d3c09U, 0xabca9eceU, 0x89355d13U);
            r_tsip_func314(408 + 64);
            r_tsip_func100(0xbb26e16eU, 0xe29a0f73U, 0x7d4dca0bU, 0x89b190f8U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01e59c3dU));
            r_tsip_func080();
            r_tsip_func100(0x0fb715ebU, 0x1dc97088U, 0xcd9de5c6U, 0x8af09f58U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(544);
            r_tsip_func100(0xa5ed8d61U, 0x4ee6659bU, 0x2937f10fU, 0x19668e27U);
            r_tsip_func314(544 + 64);
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_00ECH, 0x00000081U);
            r_tsip_func101(0x6ae6c0f9U, 0x67019666U, 0xb059c873U, 0x18be55d3U);
            r_tsip_func309();
            r_tsip_func100(0xa512a684U, 0x1a9ddf24U, 0x238d7b9cU, 0x62d3b263U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x019c85beU));
            r_tsip_func080();
            r_tsip_func100(0xbd1f3939U, 0x8729facdU, 0x80d38fb0U, 0x5a27a43aU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(204);
            r_tsip_func100(0x60551515U, 0xdae1e70fU, 0x95092f72U, 0xc7801298U);
            r_tsip_func314(204 + 64);
            r_tsip_func100(0xaa311502U, 0xa6080d9cU, 0x11349fe9U, 0x87ffd9e6U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x016bcaa1U));
            r_tsip_func080();
            r_tsip_func100(0xb8256a57U, 0x236a6077U, 0x5e792480U, 0xa33a67f8U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(136);
            r_tsip_func100(0x222b6290U, 0x435d0b46U, 0x651a9ff0U, 0x5b9d95f3U);
            r_tsip_func314(136 + 64);
            r_tsip_func101(0xe8f4ffe1U, 0xb05d82ebU, 0x0e3a3c92U, 0xbdcafebbU);
        }

        WR1_PROG(REG_00ECH, 0x3800da9fU);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x1432730aU, 0x39382b71U, 0x4a61d715U, 0x1080079cU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 0U))
        {
            r_tsip_func101(0x962dfd1eU, 0x800a8b12U, 0x8fc19b6dU, 0x4fb2ad19U);
        }
        else
        {
            r_tsip_func100(0xbbdb586fU, 0x6c65a9beU, 0x16501daeU, 0xca992761U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x019c85beU));
            r_tsip_func080();
            r_tsip_func100(0x9fbc04e6U, 0x04f43f13U, 0xfd6dfd31U, 0x02693701U);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000010U);
            r_tsip_func312(204);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x016bcaa1U));
            r_tsip_func080();
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            r_tsip_func312(136);
            r_tsip_func100(0x9902c670U, 0x05149d2cU, 0xdc0805a9U, 0x120a2c1bU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01a67f45U));
            r_tsip_func080();
            r_tsip_func100(0x7726d298U, 0x0e398706U, 0x36609e02U, 0x06b57176U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(476);
            r_tsip_func100(0xf8e20146U, 0xf6d254cbU, 0x84a5d2b0U, 0x593dcbd0U);
            r_tsip_func314(476 + 64);
            r_tsip_func100(0x5a5d374fU, 0x5d1e56b3U, 0x58568a19U, 0x3191f0feU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x011f5dcdU));
            r_tsip_func080();
            r_tsip_func100(0x921104eaU, 0xd6f9a155U, 0xdf24fdddU, 0x613ac43fU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(408);
            r_tsip_func100(0x3848a0c4U, 0x9bfa5e8cU, 0x473e4bceU, 0xf73fa9acU);
            r_tsip_func314(408 + 64);
            r_tsip_func100(0x6cd88c98U, 0xf0fe6b3cU, 0xa9a0ffa4U, 0x3c3c4cc6U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x0132d44bU));
            r_tsip_func080();
            r_tsip_func100(0xa5a667f7U, 0x51d3177aU, 0xc692d9b8U, 0x7d351206U);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000010U);
            r_tsip_func312(68);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01432c7aU));
            r_tsip_func080();
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            r_tsip_func312(0);
            r_tsip_func100(0xc2284488U, 0xbe10aa15U, 0xebc5c6eeU, 0xc6a33ba6U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x019fce91U));
            r_tsip_func080();
            r_tsip_func100(0x4c4b3a06U, 0x3c5a0e0cU, 0xc0d50b1eU, 0x13b98d44U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(612);
            r_tsip_func100(0xc34130e6U, 0x44cba9b5U, 0x2397350cU, 0xdae2d6c9U);
            r_tsip_func314(612 + 64);
            r_tsip_func100(0xa62672dbU, 0x09ea637fU, 0xd25699d3U, 0xc668656bU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x01e59c3dU));
            r_tsip_func080();
            r_tsip_func100(0xfd7bdcf5U, 0xc612c3faU, 0x3f5a48efU, 0x00d71726U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(544);
            r_tsip_func100(0xe2f692f5U, 0x4469a677U, 0x1ec0277aU, 0xfb84d609U);
            r_tsip_func314(544 + 64);
            WR1_PROG(REG_00ECH, 0x0000b400U);
            WR1_PROG(REG_00ECH, 0x00000082U);
            r_tsip_func101(0x9790943bU, 0xaadf216dU, 0x38cf51deU, 0xf7440a31U);
            r_tsip_func309();
            r_tsip_func100(0x4dde5a0bU, 0x78002232U, 0x2cbb372fU, 0x0db6ee0fU);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x019c85beU));
            r_tsip_func080();
            r_tsip_func100(0xc492b860U, 0x647dd183U, 0xeff3048dU, 0xc9b4603cU);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000020U);
            r_tsip_func313(204);
            r_tsip_func100(0xddb843ccU, 0x70d7fce2U, 0x01e0ada7U, 0x2edbbf37U);
            r_tsip_func314(204 + 64);
            r_tsip_func100(0xeda2e797U, 0x8e795de2U, 0x8cd3bcf9U, 0x5a9db061U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x80010020U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x016bcaa1U));
            r_tsip_func080();
            r_tsip_func100(0x4ae99d4cU, 0xec4f6434U, 0x6ef7bf1eU, 0x6307d642U);
            WR1_PROG(REG_0000H, 0x00012303U);
            WR1_PROG(REG_002CH, 0x00000022U);
            r_tsip_func313(136);
            r_tsip_func100(0xe6dfb44dU, 0x50075010U, 0x1f75637eU, 0x22c583e4U);
            r_tsip_func314(136 + 64);
            WR1_PROG(REG_00ECH, 0x0000d260U);
            r_tsip_func101(0x2371e0d5U, 0x716961b5U, 0x6a50c421U, 0x30c3585dU);
        }

        WR1_PROG(REG_00ECH, 0x01816e94U);
        r_tsip_func101(0xcb0b0a91U, 0x4148dc29U, 0xb3b9ba70U, 0xda91256eU);
    }

    WR1_PROG(REG_00ECH, 0x38008a20U);
    WR1_PROG(REG_00ECH, 0x00000020U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    r_tsip_func100(0x393a4a1dU, 0x811f6d58U, 0x84824276U, 0xad357183U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019c85beU));
    r_tsip_func080();
    r_tsip_func100(0x08e49c84U, 0xe8384969U, 0xa31365dbU, 0xe357e7b7U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    r_tsip_func312(204);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016bcaa1U));
    r_tsip_func080();
    r_tsip_func100(0xb52d6c36U, 0x6636a1f3U, 0x4f026e5bU, 0x238cca29U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    r_tsip_func312(136);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a67f45U));
    r_tsip_func080();
    r_tsip_func100(0x3085d573U, 0x4dcd7b51U, 0x85640808U, 0xb77d68acU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(476);
    r_tsip_func100(0xa904f13aU, 0x792fd70aU, 0x44cb4131U, 0x4f75705aU);
    r_tsip_func314(476 + 64);
    r_tsip_func100(0x13d99552U, 0x3f22cdc3U, 0x07ff2d96U, 0x9d326cefU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x011f5dcdU));
    r_tsip_func080();
    r_tsip_func100(0x7ab436cfU, 0x65d447d6U, 0x4bd548e1U, 0x0095eda8U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(408);
    r_tsip_func100(0x88f9a142U, 0x9a08d4a0U, 0xe53a218bU, 0x25633500U);
    r_tsip_func314(408 + 64);
    r_tsip_func100(0x4136e216U, 0xb7d27914U, 0xf36fd845U, 0x0568affaU);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019fce91U));
    r_tsip_func080();
    r_tsip_func100(0x69fd8a15U, 0x53b2b61fU, 0x68b1354aU, 0xa780134eU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(612);
    r_tsip_func100(0x84e958d1U, 0x7a7b0274U, 0x0a948ce1U, 0xe6ee6c2dU);
    r_tsip_func314(612 + 64);
    r_tsip_func100(0x7a11d121U, 0x3ef30246U, 0xe067fe94U, 0xa2f18113U);
    WR1_PROG(REG_0024H, 0x00000581U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01e59c3dU));
    r_tsip_func080();
    r_tsip_func100(0x555fcdfbU, 0x8bf47e8fU, 0xcfddfe2bU, 0xa9f98c44U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(544);
    r_tsip_func100(0x3ead450bU, 0x50b4d49fU, 0xafb8d61fU, 0xa04886a0U);
    r_tsip_func314(544 + 64);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000083U);
    r_tsip_func101(0xe2e70cf5U, 0x66260a77U, 0x8d58402aU, 0x669295b6U);
    r_tsip_func309();
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000090U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_00ECH, 0x00007c00U);
    WR1_PROG(REG_001CH, 0x00602000U);
}
