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

rsip_ret_t r_rsip_p2b (uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
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
    if (0x0U != RD1_MASK(REG_14BCH, 0x1fU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x002b0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);
    WR1_PROG(REG_1600H, 0x00000a31U);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (kLoop = 0; kLoop < MAX_CNT; kLoop = kLoop + 1)
    {
        WR1_PROG(REG_1444H, 0x00002fb0U);
        WR1_PROG(REG_0160H, bswap_32big(0x00030005U));
        WR1_PROG(REG_0164H, bswap_32big(0x0007000bU));
        WR1_PROG(REG_0168H, bswap_32big(0x000d0011U));
        WR1_PROG(REG_016CH, bswap_32big(0x00130017U));
        WR1_PROG(REG_0170H, bswap_32big(0x001d001fU));
        WR1_PROG(REG_0174H, bswap_32big(0x00250029U));
        WR1_PROG(REG_0178H, bswap_32big(0x002b002fU));
        WR1_PROG(REG_017CH, bswap_32big(0x003b003dU));
        WR1_PROG(REG_0180H, bswap_32big(0x00430047U));
        WR1_PROG(REG_0184H, bswap_32big(0x0049004fU));
        WR1_PROG(REG_0188H, bswap_32big(0x00530059U));
        WR1_PROG(REG_018CH, bswap_32big(0x00610065U));
        WR1_PROG(REG_0190H, bswap_32big(0x0067006bU));
        WR1_PROG(REG_0194H, bswap_32big(0x006d0071U));
        WR1_PROG(REG_0198H, bswap_32big(0x007f0083U));
        WR1_PROG(REG_019CH, bswap_32big(0x0089008bU));
        WR1_PROG(REG_01A0H, bswap_32big(0x00950097U));
        WR1_PROG(REG_01A4H, bswap_32big(0x009d00a3U));
        WR1_PROG(REG_01A8H, bswap_32big(0x00a700adU));
        WR1_PROG(REG_01ACH, bswap_32big(0x00b300b5U));
        WR1_PROG(REG_01B0H, bswap_32big(0x00bf00c1U));
        WR1_PROG(REG_01B4H, bswap_32big(0x00c500c7U));
        WR1_PROG(REG_01B8H, bswap_32big(0x00d300dfU));
        WR1_PROG(REG_01BCH, bswap_32big(0x00e300e5U));
        WR1_PROG(REG_01C0H, bswap_32big(0x00e900efU));
        WR1_PROG(REG_01C4H, bswap_32big(0x00f100fbU));
        WR1_PROG(REG_01C8H, bswap_32big(0x01010107U));
        WR1_PROG(REG_01CCH, bswap_32big(0x010d010fU));
        WR1_PROG(REG_01D0H, bswap_32big(0x01150119U));
        WR1_PROG(REG_01D4H, bswap_32big(0x011b0125U));
        WR1_PROG(REG_01D8H, bswap_32big(0x01330137U));
        WR1_PROG(REG_01DCH, bswap_32big(0x0139013dU));
        WR1_PROG(REG_01E0H, bswap_32big(0x014b0151U));
        WR1_PROG(REG_01E4H, bswap_32big(0x015b015dU));
        WR1_PROG(REG_01E8H, bswap_32big(0x01610167U));
        WR1_PROG(REG_01ECH, bswap_32big(0x016f0175U));
        WR1_PROG(REG_01F0H, bswap_32big(0x017b017fU));
        WR1_PROG(REG_01F4H, bswap_32big(0x0185018dU));
        WR1_PROG(REG_01F8H, bswap_32big(0x01910199U));
        WR1_PROG(REG_01FCH, bswap_32big(0x01a301a5U));
        WR1_PROG(REG_0200H, bswap_32big(0x01af01b1U));
        WR1_PROG(REG_0204H, bswap_32big(0x01b701bbU));
        WR1_PROG(REG_0208H, bswap_32big(0x01c101c9U));
        WR1_PROG(REG_020CH, bswap_32big(0x01cd01cfU));
        WR1_PROG(REG_0210H, bswap_32big(0x01d301dfU));
        WR1_PROG(REG_0214H, bswap_32big(0x01e701ebU));
        WR1_PROG(REG_0218H, bswap_32big(0x01f301f7U));
        WR1_PROG(REG_021CH, bswap_32big(0x01fd0000U));
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80b00006U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x034300c1U);
        r_rsip_func100(bswap_32big(0xae4e425dU), bswap_32big(0x3e0097a7U), bswap_32big(0xb91ddd88U),
                       bswap_32big(0xc88bd55cU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d01fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x11a00000U);
        r_rsip_subfunc003(0x00c90011U);
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000018U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000008e7U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 24; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xc78602a5U), bswap_32big(0x6597d314U), bswap_32big(0xd0157c98U),
                           bswap_32big(0x7ee12726U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xae09aeadU), bswap_32big(0xfe8085cdU), bswap_32big(0x690443a1U),
                           bswap_32big(0x20347421U));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x88bc386cU), bswap_32big(0x7880629fU), bswap_32big(0xbfdf87e3U),
                       bswap_32big(0xdbecf803U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        WR1_PROG(REG_1600H, 0x0000d060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90011U);
        WR1_PROG(REG_1444H, 0x00001fb0U);
        WR1_PROG(REG_09C0H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_09C4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09CCH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09D0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09D4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09DCH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09E0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09E4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09ECH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09F0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09F4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09FCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A00H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A04H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A08H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A0CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A10H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A14H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A18H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A1CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A20H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A24H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A28H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A2CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A30H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A34H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A38H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A3CH, bswap_32big(0xEB851B5CU));
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x9b3b808bU), bswap_32big(0xca16d633U), bswap_32big(0x346e7c19U),
                       bswap_32big(0xda4cbfc1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xe2c6a05dU), bswap_32big(0x34cf225dU), bswap_32big(0xaa425125U),
                           bswap_32big(0x846252aeU));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb1b397f0U), bswap_32big(0x5bbadd9bU), bswap_32big(0x695bc4f6U),
                           bswap_32big(0xb065d182U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xb3e8a023U), bswap_32big(0x1dc2d951U), bswap_32big(0x3a58e797U),
                       bswap_32big(0xd8377620U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x7e8d7b10U), bswap_32big(0x24862854U), bswap_32big(0x8b7325caU),
                           bswap_32big(0x7c5433f1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x1010000aU);
                r_rsip_func101(bswap_32big(0x927ae2a9U),
                               bswap_32big(0xbafbea70U),
                               bswap_32big(0x18b46cccU),
                               bswap_32big(0x1c8ef8d6U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0xffa233e4U),
                               bswap_32big(0xf6417960U),
                               bswap_32big(0x05eac12aU),
                               bswap_32big(0x3a4df9daU));
            }

            WR1_PROG(REG_1404H, 0x19c00000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x10000000U));
            r_rsip_subfunc003(0x00c20011U);
            r_rsip_subfunc003(0x00c00071U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x672a3ddcU), bswap_32big(0x6a2a98a0U), bswap_32big(0x1f300306U),
                           bswap_32big(0x6e2d090dU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0xb479f30aU),
                               bswap_32big(0x47d4be87U),
                               bswap_32big(0xc9ef927bU),
                               bswap_32big(0xbd5a7a5cU));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x7e2ba759U),
                               bswap_32big(0x08b04fbdU),
                               bswap_32big(0x68090fd7U),
                               bswap_32big(0x6bc0ac98U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x6b3cce82U), bswap_32big(0x19578393U), bswap_32big(0x001fe28cU),
                           bswap_32big(0x4d6d3839U));
        }

        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000094aU);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 95; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_1600H, 0x01003906U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002cc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002cc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010100U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x15b00000U);
            r_rsip_subfunc003(0x00c0007dU);
            r_rsip_subfunc003(0x00c90005U);
            r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x10100010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x10100004U);
            WR1_PROG(REG_1404H, 0x19c00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0007dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x429053eeU), bswap_32big(0x370b3291U), bswap_32big(0xe6f9d5c8U),
                           bswap_32big(0x52e44ac1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xb0efa59bU),
                               bswap_32big(0xa679721bU),
                               bswap_32big(0xe5426654U),
                               bswap_32big(0x884d9407U));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xd2967e47U),
                               bswap_32big(0xe3af923dU),
                               bswap_32big(0xadf98b6bU),
                               bswap_32big(0x082f5adbU));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x75a679f9U), bswap_32big(0xea1e53bfU), bswap_32big(0x99d0a6a3U),
                       bswap_32big(0xc4fa4bd5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x92db10d8U), bswap_32big(0x42be225fU), bswap_32big(0x7ebf1577U),
                           bswap_32big(0xaff4c207U));
            continue;
        }

        WR1_PROG(REG_1404H, 0x18b80000U);
        r_rsip_subfunc003(0x00c00081U);
        r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000428U, 0x10100009U);
        r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x1010000aU);
        WR1_PROG(REG_1404H, 0x15b00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x10100010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x10100004U);
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xcff050b9U), bswap_32big(0x83809729U), bswap_32big(0x1717cd38U),
                       bswap_32big(0x063e635cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xf64a91beU), bswap_32big(0xca50afe4U), bswap_32big(0x0e9e34a6U),
                           bswap_32big(0x735e0facU));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x5966b03bU), bswap_32big(0xcc83506fU), bswap_32big(0x98d3b766U),
                           bswap_32big(0x3c1be5cdU));
            WR1_PROG(REG_1404H, 0x17b80000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0007dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x10100010U);
            r_rsip_subfunc005(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x10100000U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x90e40399U), bswap_32big(0xa3e4cf33U), bswap_32big(0x1a96a100U),
                           bswap_32big(0x8de9533cU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0xf0320c97U),
                               bswap_32big(0xba0a18eaU),
                               bswap_32big(0xf9fa503fU),
                               bswap_32big(0x95c04638U));
                continue;
            }

            r_rsip_func100(bswap_32big(0x19f31ac0U), bswap_32big(0x4c83a040U), bswap_32big(0xc7857235U),
                           bswap_32big(0xbe9de770U));
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000003U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80a0000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x11a00000U);
            r_rsip_subfunc003(0x03430081U);
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000007cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x000038e6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a8c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x38008900U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x11816907U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x38008900U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x10002d20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000168e7U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }
            }

            WR1_PROG(REG_1608H, 0x81010120U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            WR1_PROG(REG_1600H, 0x000037e9U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x15b00000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81a0000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90081U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                r_rsip_subfunc004(0x00000630U, 0x00000838U, 0x1010000cU);
                r_rsip_subfunc001(0x00000838U, 0x00000938U, 0x00000630U, 0x10100009U);
                WR1_PROG(REG_1600H, 0x000033e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x9a823ae1U),
                               bswap_32big(0xb66bd134U),
                               bswap_32big(0x97a9c66aU),
                               bswap_32big(0x0ecd3a47U));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x1acda947U), bswap_32big(0xba5a5668U), bswap_32big(0xeccfbd89U),
                           bswap_32big(0x0ec75358U));
            WR1_PROG(REG_1600H, 0x00000a52U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010160U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1600H, 0x00000884U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000020U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x11a00000U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 4)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c07U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xa8eed774U),
                                   bswap_32big(0xa7914b36U),
                                   bswap_32big(0xf6991427U),
                                   bswap_32big(0xe42e1fccU));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x30774214U),
                                   bswap_32big(0x4f1bc7a4U),
                                   bswap_32big(0x4f2ea491U),
                                   bswap_32big(0x8e9d1a0dU));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x4e947d92U),
                               bswap_32big(0x067667a8U),
                               bswap_32big(0x1fb75b3aU),
                               bswap_32big(0x0a7d2182U));
                WR1_PROG(REG_1404H, 0x19c00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000004U));
                r_rsip_subfunc003(0x00c0007dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x1010000aU);
                r_rsip_subfunc006(0x00000018U, 0x00000838U, 0x10100010U);
                WR1_PROG(REG_1014H, 0x00000220U);
                r_rsip_subfunc002(0x00000838U, 0x00000a40U, 0x10100004U);
                WR1_PROG(REG_1404H, 0x17b80000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0007dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x10100010U);
                r_rsip_subfunc005(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x10100000U, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1404H, 0x19c00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0007dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x1010000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x1010000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x5c6eb690U),
                               bswap_32big(0xc1d02830U),
                               bswap_32big(0x41d86571U),
                               bswap_32big(0x842b6db1U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x6c596a65U),
                                   bswap_32big(0x248d135dU),
                                   bswap_32big(0x44d2b955U),
                                   bswap_32big(0xce97c8d6U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xb149900bU),
                                   bswap_32big(0x68565024U),
                                   bswap_32big(0x6dde7256U),
                                   bswap_32big(0x7812ce42U));
                    WR1_PROG(REG_1608H, 0x81010120U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < S_RAM[0 + 1]; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_1404H, 0x19c00000U);
                        WR1_PROG(REG_1608H, 0x81a0000aU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00c90081U);
                        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x1010000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x1010000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x155e1dabU),
                                       bswap_32big(0x68734021U),
                                       bswap_32big(0xd96cb14aU),
                                       bswap_32big(0x34c7c80cU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x7ab1629fU),
                                           bswap_32big(0x61e40285U),
                                           bswap_32big(0x0a25404fU),
                                           bswap_32big(0xdd0ea935U));
                            break;
                        }
                        else
                        {
                            r_rsip_func100(bswap_32big(0xd48bfb4fU),
                                           bswap_32big(0x3c675fa7U),
                                           bswap_32big(0xad8de3feU),
                                           bswap_32big(0xa62a957eU));
                            WR1_PROG(REG_1404H, 0x19c00000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                            r_rsip_subfunc003(0x00c0007dU);
                            r_rsip_subfunc003(0x00c20005U);
                            r_rsip_subfunc003(0x0002000dU);
                            r_rsip_subfunc005(0x00000838U,
                                              0x00000a40U,
                                              0x00000428U,
                                              0x00000220U,
                                              0x10100000U,
                                              0x00020000U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000838U, 0x10100009U);
                            r_rsip_func101(bswap_32big(0x541ffba4U),
                                           bswap_32big(0x6870d55cU),
                                           bswap_32big(0x09949423U),
                                           bswap_32big(0x4846c8d8U));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0xd9d27740U),
                                   bswap_32big(0xf3225878U),
                                   bswap_32big(0x9ef4d8fbU),
                                   bswap_32big(0xc87ccfb0U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0x03f01cceU),
                                       bswap_32big(0x78d3c2cbU),
                                       bswap_32big(0x8d9671c2U),
                                       bswap_32big(0x416d8e23U));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x2d863b02U),
                                       bswap_32big(0xf37e0797U),
                                       bswap_32big(0xbd9d41ebU),
                                       bswap_32big(0x03e41273U));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0xc2a00a0dU), bswap_32big(0xcdd629beU), bswap_32big(0x6da9d7b4U),
                           bswap_32big(0xc33ccac4U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00002e20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38008a20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                r_rsip_func100(bswap_32big(0x9ba32f28U),
                               bswap_32big(0x21bbf010U),
                               bswap_32big(0x048979bbU),
                               bswap_32big(0x5a05acd4U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x6acc3a37U),
                                   bswap_32big(0xbf33425dU),
                                   bswap_32big(0x7a204997U),
                                   bswap_32big(0xf1454bcfU));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x10100009U);
                    r_rsip_func101(bswap_32big(0x4c5a45a0U),
                                   bswap_32big(0x14183b01U),
                                   bswap_32big(0x6ea5888dU),
                                   bswap_32big(0xa9e408bdU));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0x30c22c92U),
                               bswap_32big(0x1659c7cbU),
                               bswap_32big(0x76228bf1U),
                               bswap_32big(0x2af169b0U));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xaa4ef707U),
                   bswap_32big(0x4799bc7cU),
                   bswap_32big(0x93ff1814U),
                   bswap_32big(0xba66f2c0U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x69d18be8U), bswap_32big(0x993fe1ecU), bswap_32big(0xc61d5af9U),
                       bswap_32big(0x881fa494U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_subfunc003(0x00c00081U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x10100009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x000007b8U, 0x10100009U);
    r_rsip_func100(bswap_32big(0xdd59731cU),
                   bswap_32big(0x37288c00U),
                   bswap_32big(0x81a0f3a6U),
                   bswap_32big(0xef036114U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xdd68d0f5U),
                   bswap_32big(0x95af5520U),
                   bswap_32big(0x29ec8201U),
                   bswap_32big(0x60aa493aU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0xccd604baU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x17380000U, 0x00000040U, bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0x98168208U),
                   bswap_32big(0xfde05f47U),
                   bswap_32big(0xaf74d215U),
                   bswap_32big(0x3fe8af60U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000220U, 0x1010000aU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000630U, 0x1010000aU);
    r_rsip_subfunc009(bswap_32big(0x0000002bU));
    r_rsip_func101(bswap_32big(0xfaf39547U),
                   bswap_32big(0xb6db5ae7U),
                   bswap_32big(0xd886facbU),
                   bswap_32big(0xaef5fec9U));
    r_rsip_func052();
    WR1_PROG(REG_1404H, 0x15200000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0xccd604baU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x17380000U, 0x00000040U, bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0x0fc3631fU),
                   bswap_32big(0x0aa6f519U),
                   bswap_32big(0x008b25a3U),
                   bswap_32big(0x3a6aa4ceU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x000007b8U, 0x00000838U, 0x00000220U, 0x10100007U);
    r_rsip_subfunc009(bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0xf11600c2U),
                   bswap_32big(0x748c6e81U),
                   bswap_32big(0x887b4989U),
                   bswap_32big(0xef290f2fU));
    r_rsip_func054();
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000428U, 0x2020000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000428U, 0x2020000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x947caa80U),
                   bswap_32big(0xa9d09aaaU),
                   bswap_32big(0x79c94654U),
                   bswap_32big(0x8cb9642dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xcad99732U), bswap_32big(0xe4bdd5f4U), bswap_32big(0x45d082a0U),
                       bswap_32big(0x05eabebaU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0xccd604baU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x13280000U, 0x00000040U, bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0x672381d5U),
                   bswap_32big(0x50d90f57U),
                   bswap_32big(0xd36d69ecU),
                   bswap_32big(0x883aa88dU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x000003a8U, 0x00000428U, 0x00000630U, 0x10100007U);
    r_rsip_subfunc007(bswap_32big(0xccd604baU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x15300000U, 0x00000040U, bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0x24f7d4e7U),
                   bswap_32big(0xe22982e3U),
                   bswap_32big(0x3d749ee7U),
                   bswap_32big(0x18ed7182U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x1010000aU);
    r_rsip_subfunc001(0x000003a8U, 0x00000a40U, 0x000001a0U, 0x1010000aU);
    r_rsip_subfunc001(0x000001a0U, 0x00000220U, 0x00000428U, 0x10100007U);
    r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x20200010U);
    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000838U);
    r_rsip_subfunc002(0x00000630U, 0x00000428U, 0x20200002U);
    r_rsip_subfunc002(0x00000630U, 0x00000220U, 0x20200003U);
    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000220U);
    r_rsip_subfunc002(0x00000630U, 0x00000220U, 0x20200002U);
    WR1_PROG(REG_1404H, 0x15300000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc009(bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0xc362758bU),
                   bswap_32big(0x603e712eU),
                   bswap_32big(0x98879274U),
                   bswap_32big(0x2c8048f8U));
    r_rsip_func054();
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000428U, 0x2020000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000428U, 0x2020000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0xd5b6e72aU),
                   bswap_32big(0x3d2d6c0aU),
                   bswap_32big(0x97abeceaU),
                   bswap_32big(0x65162d0eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x9942733aU), bswap_32big(0x4287a7d8U), bswap_32big(0xd2eff867U),
                       bswap_32big(0x15d8e4eeU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x20200009U);
    r_rsip_subfunc007(bswap_32big(0xccd604baU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x15300000U, 0x00000040U, bswap_32big(0x00002b03U));
    r_rsip_func101(bswap_32big(0xcbf4234fU),
                   bswap_32big(0x2952bbb0U),
                   bswap_32big(0xffe337faU),
                   bswap_32big(0xbaf5d8aaU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x65b1eed7U),
                   bswap_32big(0x3f3f918cU),
                   bswap_32big(0x22d87616U),
                   bswap_32big(0x8b0a1b14U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0x3fb359f0U),
                   bswap_32big(0xb0b51a0bU),
                   bswap_32big(0xdad1a4d4U),
                   bswap_32big(0x941a193cU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01e48f0cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0xf7bd2816U),
                   bswap_32big(0xfa5dfd5aU),
                   bswap_32big(0x5f92623aU),
                   bswap_32big(0x672a6c7cU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x0e947662U), bswap_32big(0x498dfa37U), bswap_32big(0x70e82e84U),
                       bswap_32big(0xc7e79a86U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x1585f8c3U), bswap_32big(0x6a757a50U), bswap_32big(0xbc0eb6e7U),
                       bswap_32big(0x286cc35dU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x13280000U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xabc731f4U), bswap_32big(0x5a05a1b8U), bswap_32big(0x67ffa46aU),
                       bswap_32big(0xb3ee16d9U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 68]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 69]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 70]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 71]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xb4117b7aU), bswap_32big(0xd5e62b30U), bswap_32big(0xd1ca510fU),
                       bswap_32big(0x0f27123bU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x4f11bd74U),
                   bswap_32big(0x08d51227U),
                   bswap_32big(0x3c6a2d18U),
                   bswap_32big(0xe5f394f2U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[132]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[133]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[134]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[135]);
    r_rsip_func100(bswap_32big(0xf51d0d1fU),
                   bswap_32big(0xc8985994U),
                   bswap_32big(0x35eac82eU),
                   bswap_32big(0xf9bcdeabU));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[3]);
    r_rsip_func100(bswap_32big(0x20c127cdU),
                   bswap_32big(0x98dfd44fU),
                   bswap_32big(0xa0a36f4dU),
                   bswap_32big(0x13b23aa2U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0x0580f83aU),
                   bswap_32big(0xef4238a6U),
                   bswap_32big(0xac2a6f3dU),
                   bswap_32big(0xfa73d590U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01e09ffdU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0xda23f42cU),
                   bswap_32big(0x058a3babU),
                   bswap_32big(0x12b8d364U),
                   bswap_32big(0x98a54973U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x00000884U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4a0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b4c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x0602854bU), bswap_32big(0x9d389625U), bswap_32big(0x72be074aU),
                       bswap_32big(0x3971f41dU));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x12838f72U), bswap_32big(0x41528203U), bswap_32big(0x432ddca2U),
                       bswap_32big(0x02546941U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_func100(bswap_32big(0x790bc2a0U),
                   bswap_32big(0xb1cb92a1U),
                   bswap_32big(0x5fa4f652U),
                   bswap_32big(0xf90214dcU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008104U);
    WR1_PROG(REG_1608H, 0x81010280U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[68]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[69]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[70]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[71]);
    r_rsip_func100(bswap_32big(0xceb9e5b4U),
                   bswap_32big(0x064e892aU),
                   bswap_32big(0xaaed18bcU),
                   bswap_32big(0xffab9feeU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c100104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[72]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[73]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[74]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[75]);
    r_rsip_func100(bswap_32big(0xca5b5ba8U),
                   bswap_32big(0x5c9fce7dU),
                   bswap_32big(0x8b07d0d0U),
                   bswap_32big(0x42ac4fd4U));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[3]);
    r_rsip_func102(bswap_32big(0x3ac88921U),
                   bswap_32big(0xbb92f219U),
                   bswap_32big(0xaf477d1bU),
                   bswap_32big(0x42dc34d5U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
