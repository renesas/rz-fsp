/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"

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

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_p5e (const uint32_t InData_PubKeyType[],
                       const uint32_t InData_PubKey[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_EncSecret[])
{
    RSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x005e0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10700000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x13400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x17f00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc009(bswap_32big(0x0000005eU));
    r_rsip_func101(bswap_32big(0x49a6ac55U),
                   bswap_32big(0x4a228937U),
                   bswap_32big(0x557ed07fU),
                   bswap_32big(0x945df071U));
    r_rsip_func078(InData_DomainParam);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x08080010U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005e01U));
    r_rsip_func101(bswap_32big(0xd5f9be27U),
                   bswap_32big(0xbcf1e708U),
                   bswap_32big(0x3129d7daU),
                   bswap_32big(0xfa3e0a51U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x012b75aeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005e01U));
    r_rsip_func101(bswap_32big(0x85ab5aedU),
                   bswap_32big(0x3ffef498U),
                   bswap_32big(0xf2a8812cU),
                   bswap_32big(0xb5d214c6U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x00000fc2U);
    WR1_PROG(REG_1A2CH, 0x40000300U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WR1_PROG(REG_1404H, 0x13000000U);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        r_rsip_subfunc003(0x00c20011U);
    }

    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0xa1c7009bU),
                   bswap_32big(0x6e5bfc8cU),
                   bswap_32big(0x49a928b0U),
                   bswap_32big(0x33591c50U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x0fcfa437U), bswap_32big(0xb571c669U), bswap_32big(0xf0ed2f6aU),
                       bswap_32big(0x0fc157f1U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1404H, 0x10c00000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1404H, 0x11100000U);
        r_rsip_subfunc003(0x00c00051U);
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_PubKeyType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000f7bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x5a30c74cU), bswap_32big(0x7cf1f5aeU), bswap_32big(0xc8ac2492U),
                       bswap_32big(0x15964ee5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1444H, 0x00000fd0U);
            for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_00D0H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 0]);
            }

            WR1_PROG(REG_1444H, 0x00000fd0U);
            for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
            {
                WR1_ADDR((&(REG_0120H))[iLoop / 4], &InData_PubKey[(iLoop / 4) + 16]);
            }

            r_rsip_func101(bswap_32big(0x25a817aaU), bswap_32big(0x2171aa13U), bswap_32big(0x17f585c3U),
                           bswap_32big(0x15888868U));
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00005e02U));
            r_rsip_func101(bswap_32big(0xe478e1e3U), bswap_32big(0x4f68ffb9U), bswap_32big(0xbd60d9fbU),
                           bswap_32big(0xc6eb5becU));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0160f11aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00005e02U));
            r_rsip_func101(bswap_32big(0xd164cebbU), bswap_32big(0xc0df2c9bU), bswap_32big(0x47d5501aU),
                           bswap_32big(0x35a4ca94U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x00001bc2U);
            WR1_PROG(REG_1A2CH, 0x40000600U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            WR1_PROG(REG_1404H, 0x10d00000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
                r_rsip_subfunc003(0x00c20011U);
            }

            for (iLoop = 16; iLoop < 28; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
            }

            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_subfunc003(0x00c20031U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 7]);
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 8]);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 9]);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 10]);
            WR1_ADDR(REG_1420H, &InData_PubKey[iLoop + 11]);
            r_rsip_func100(bswap_32big(0xab24b06fU), bswap_32big(0x5ea7213bU), bswap_32big(0x60bd41b1U),
                           bswap_32big(0xdec0c2f3U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x2d0ae69aU),
                               bswap_32big(0x2a484a98U),
                               bswap_32big(0x50f64a82U),
                               bswap_32big(0xdaab0ef0U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x6e389ebfU),
                               bswap_32big(0x0fb6743eU),
                               bswap_32big(0x256539f6U),
                               bswap_32big(0x4ce6a8c6U));
            }
        }

        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x000001b0U);
        WR1_PROG(REG_1004H, 0x08080002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000200U);
        WR1_PROG(REG_1004H, 0x08080002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1004H, 0x08080001U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000890U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x08080005U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1004H, 0x08080002U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x000008e0U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x08080005U);
        WR1_PROG(REG_1014H, 0x00000200U);
        WR1_PROG(REG_101CH, 0x00000070U);
        WR1_PROG(REG_1020H, 0x00000110U);
        WR1_PROG(REG_1004H, 0x08080001U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x00000250U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000110U, 0x00000250U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xeede2570U), bswap_32big(0x5ca1a3aeU), bswap_32big(0xde7aac12U),
                       bswap_32big(0xfaf6e82dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x95148b3dU), bswap_32big(0x4a7bc3c2U), bswap_32big(0x0f3daef9U),
                           bswap_32big(0xd932ecd3U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10d00000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x000002a0U, 0x08080009U);
            r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x000002f0U, 0x08080009U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x00c000f1U);
            r_rsip_subfunc001(0x000002a0U, 0x00000110U, 0x000001c0U, 0x08080009U);
            r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000208U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x0000005eU));
            r_rsip_func101(bswap_32big(0x42120b73U), bswap_32big(0x80f3830dU), bswap_32big(0xa05279eeU),
                           bswap_32big(0xaef65171U));
            r_rsip_func071();
            r_rsip_func100(bswap_32big(0x33bc42baU), bswap_32big(0xeda855d7U), bswap_32big(0xb003ad23U),
                           bswap_32big(0x29e8b8fdU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xe399b87fU),
                               bswap_32big(0xb7cc1186U),
                               bswap_32big(0xab493d34U),
                               bswap_32big(0x36c35908U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0x8ce0daa5U),
                               bswap_32big(0x1cf703baU),
                               bswap_32big(0x00bf3945U),
                               bswap_32big(0xf2f17623U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00005e03U));
                r_rsip_func101(bswap_32big(0x845122e0U),
                               bswap_32big(0x6c7cd355U),
                               bswap_32big(0xc51d203bU),
                               bswap_32big(0x22f45097U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x01d0b7b0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00005e03U));
                r_rsip_func101(bswap_32big(0x066a8ddaU),
                               bswap_32big(0x7a8282fcU),
                               bswap_32big(0x5e5792b6U),
                               bswap_32big(0xa28ee96eU));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0x1f9150d0U),
                               bswap_32big(0x06d26b97U),
                               bswap_32big(0x95420814U),
                               bswap_32big(0xb0edb294U));
                WR1_PROG(REG_1A2CH, 0x40000200U);
                WR1_PROG(REG_1A24H, 0xe7009d07U);
                WR1_PROG(REG_1404H, 0x12600000U);
                r_rsip_subfunc003(0x00830031U);
                WR1_PROG(REG_1408H, 0x00002032U);
                for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 7]);
                }

                r_rsip_func100(bswap_32big(0x5a410318U),
                               bswap_32big(0xe8b7ef00U),
                               bswap_32big(0x515149c1U),
                               bswap_32big(0x4f78f739U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe7008d05U);
                r_rsip_subfunc003(0x00830011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 4]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 6]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 7]);
                r_rsip_func100(bswap_32big(0x7dfa2619U),
                               bswap_32big(0x9825309bU),
                               bswap_32big(0xcb74729bU),
                               bswap_32big(0xfc58e37eU));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_subfunc003(0x00820011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 8]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 9]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 10]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 11]);
                r_rsip_func100(bswap_32big(0xc8a4ecbcU),
                               bswap_32big(0x0fda5e3bU),
                               bswap_32big(0x79cf3c15U),
                               bswap_32big(0xd0b72bbfU));
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[1]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[3]);
                r_rsip_func102(bswap_32big(0xfdcfbb23U),
                               bswap_32big(0xd8a28f32U),
                               bswap_32big(0xa69aa973U),
                               bswap_32big(0xcc4211ffU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
