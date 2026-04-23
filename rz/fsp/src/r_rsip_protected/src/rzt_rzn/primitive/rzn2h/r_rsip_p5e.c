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
    r_rsip_subfunc009(bswap_32big(0x0000005eU));
    r_rsip_func101(bswap_32big(0x01696547U),
                   bswap_32big(0x0de7a9b8U),
                   bswap_32big(0x0d7fdf36U),
                   bswap_32big(0x73c0f2c0U));
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
    r_rsip_func101(bswap_32big(0x102cb0f9U),
                   bswap_32big(0x1fafb8f4U),
                   bswap_32big(0x559723c7U),
                   bswap_32big(0xeb0e43d8U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01d2c619U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00005e01U));
    r_rsip_func101(bswap_32big(0xe743beaeU),
                   bswap_32big(0x3bc2ce21U),
                   bswap_32big(0x882a5f42U),
                   bswap_32big(0x9ccc8f9bU));
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
    r_rsip_func100(bswap_32big(0x424ed01fU),
                   bswap_32big(0x474e5812U),
                   bswap_32big(0x0344d80dU),
                   bswap_32big(0x6d33b8efU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4a10f3d0U), bswap_32big(0x41bf65b6U), bswap_32big(0xfeab10ceU),
                       bswap_32big(0x1e427babU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
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
        r_rsip_func100(bswap_32big(0x51a0e926U), bswap_32big(0x70ab338cU), bswap_32big(0x631a2d65U),
                       bswap_32big(0x5a90eab8U));
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

            r_rsip_func101(bswap_32big(0x3bbb409dU), bswap_32big(0x2bf52aedU), bswap_32big(0x23338f67U),
                           bswap_32big(0x0ca6e2abU));
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
            r_rsip_func101(bswap_32big(0x3ab48f71U), bswap_32big(0xbbdfac13U), bswap_32big(0xf270b1c8U),
                           bswap_32big(0xc7fad0f5U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x014a2920U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00005e02U));
            r_rsip_func101(bswap_32big(0x3d49f57bU), bswap_32big(0xa0b352a3U), bswap_32big(0x8482d856U),
                           bswap_32big(0x5617ad35U));
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
            r_rsip_func100(bswap_32big(0xc8318661U), bswap_32big(0x312cce6bU), bswap_32big(0xa60509f6U),
                           bswap_32big(0xb99d4c0fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x0dc7b0edU),
                               bswap_32big(0x45ee2843U),
                               bswap_32big(0x00db5930U),
                               bswap_32big(0x45b6841fU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x5e9028b2U),
                               bswap_32big(0xb29c3fd1U),
                               bswap_32big(0x1aab02c1U),
                               bswap_32big(0xd4d6b0c8U));
            }
        }

        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x000001b0U, 0x08080002U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x00000390U);
        r_rsip_subfunc002(0x00000070U, 0x00000200U, 0x08080002U);
        WR1_PROG(REG_1014H, 0x000001b0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x08080001U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x00000890U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x08080005U);
        WR1_PROG(REG_1014H, 0x00000160U);
        WR1_PROG(REG_1018H, 0x000001b0U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x08080002U);
        WR1_PROG(REG_1014H, 0x00000110U);
        WR1_PROG(REG_1018H, 0x000008e0U);
        r_rsip_subfunc002(0x00000070U, 0x00000160U, 0x08080005U);
        WR1_PROG(REG_1014H, 0x00000200U);
        r_rsip_subfunc002(0x00000070U, 0x00000110U, 0x08080001U);
        r_rsip_subfunc001(0x00000110U, 0x00000160U, 0x00000250U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_subfunc001(0x00000160U, 0x00000110U, 0x00000250U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xf5367f59U), bswap_32big(0x5c8e391fU), bswap_32big(0xb5c4b2dcU),
                       bswap_32big(0xb0b0e5abU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xc420149fU), bswap_32big(0x301148bfU), bswap_32big(0x817cde1dU),
                           bswap_32big(0x089d1d18U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1404H, 0x10d00000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000208U, 0x08080009U);
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x000001c0U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x0000005eU));
            r_rsip_func101(bswap_32big(0x5e896210U), bswap_32big(0x9f665f24U), bswap_32big(0x4f251d22U),
                           bswap_32big(0xa6a4a215U));
            r_rsip_func071();
            r_rsip_func100(bswap_32big(0x1aa30bffU), bswap_32big(0x4e697a96U), bswap_32big(0xb0e46caeU),
                           bswap_32big(0x057e7078U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xfcdf0c86U),
                               bswap_32big(0xff0af2e8U),
                               bswap_32big(0x7fb4759eU),
                               bswap_32big(0xd9713931U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xa2a0a0bfU),
                               bswap_32big(0x4a2d4aadU),
                               bswap_32big(0x7216299fU),
                               bswap_32big(0x55d4dfeaU));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00005e03U));
                r_rsip_func101(bswap_32big(0xd66b5dd9U),
                               bswap_32big(0xf5fbf18eU),
                               bswap_32big(0xcc963915U),
                               bswap_32big(0xa9800b36U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x0000b4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0149ea5eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00005e03U));
                r_rsip_func101(bswap_32big(0x8c065303U),
                               bswap_32big(0x6deace9fU),
                               bswap_32big(0x8a1088ccU),
                               bswap_32big(0x19b919fbU));
                r_rsip_func046();
                r_rsip_func100(bswap_32big(0x01f4f28fU),
                               bswap_32big(0x64e39326U),
                               bswap_32big(0x3c910ed4U),
                               bswap_32big(0x803703daU));
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

                r_rsip_func100(bswap_32big(0xe0a4779cU),
                               bswap_32big(0xb72b55d7U),
                               bswap_32big(0x4939e645U),
                               bswap_32big(0x0e3286d8U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xe7008d05U);
                r_rsip_subfunc003(0x00830011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 4]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 5]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 6]);
                RD1_ADDR(REG_1420H, &OutData_EncSecret[iLoop + 7]);
                r_rsip_func100(bswap_32big(0x3c1a63fdU),
                               bswap_32big(0xaf209c0aU),
                               bswap_32big(0x4ce8f1bdU),
                               bswap_32big(0x8ad14777U));
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
                r_rsip_func100(bswap_32big(0xda055e50U),
                               bswap_32big(0x93362791U),
                               bswap_32big(0xe2f57e7dU),
                               bswap_32big(0xdb92ee0fU));
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
                r_rsip_func102(bswap_32big(0xcdecf1eaU),
                               bswap_32big(0x29826c7dU),
                               bswap_32big(0x87932ee7U),
                               bswap_32big(0xe535c11aU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
