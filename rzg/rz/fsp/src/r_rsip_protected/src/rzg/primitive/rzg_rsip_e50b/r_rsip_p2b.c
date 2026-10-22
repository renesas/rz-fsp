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
        r_rsip_func100(bswap_32big(0x3eba9b2aU), bswap_32big(0x2bcbb7c1U), bswap_32big(0x30132631U),
                       bswap_32big(0x72096192U));
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
            r_rsip_func100(bswap_32big(0xfa5ac874U), bswap_32big(0xc8a7a96eU), bswap_32big(0xa4e74163U),
                           bswap_32big(0xba0ad10bU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x62f2b908U), bswap_32big(0x9f178a39U), bswap_32big(0xa9392330U),
                           bswap_32big(0x3b4808e6U));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x2991337eU), bswap_32big(0xa5dfe672U), bswap_32big(0x904ea9e1U),
                       bswap_32big(0x4146748aU));
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
        r_rsip_func100(bswap_32big(0x71721c5fU), bswap_32big(0x4ada4de1U), bswap_32big(0xefaedbecU),
                       bswap_32big(0xdf7c5020U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x216789a6U), bswap_32big(0x036b2ebeU), bswap_32big(0x8563d869U),
                           bswap_32big(0x2feb1756U));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc6298420U), bswap_32big(0xd134a76bU), bswap_32big(0xdeef7518U),
                           bswap_32big(0xf90ee929U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xecd7a198U), bswap_32big(0x1e18c454U), bswap_32big(0x6898d3bbU),
                       bswap_32big(0xd1d96a57U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xbf28bbfdU), bswap_32big(0x577fa040U), bswap_32big(0xc9bd10f0U),
                           bswap_32big(0x97fac3d1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x1010000aU);
                r_rsip_func101(bswap_32big(0x7f6159e6U),
                               bswap_32big(0xbacd833aU),
                               bswap_32big(0x7acf5d63U),
                               bswap_32big(0x12500093U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0x48a4b0b2U),
                               bswap_32big(0x79ae4411U),
                               bswap_32big(0xc157aaedU),
                               bswap_32big(0x78cba9cdU));
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
            r_rsip_func100(bswap_32big(0x56c3fd0cU), bswap_32big(0xfa0192a4U), bswap_32big(0x4f2c8f6cU),
                           bswap_32big(0x35870affU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x9b059dd4U),
                               bswap_32big(0x6ab8ecd0U),
                               bswap_32big(0x7f969543U),
                               bswap_32big(0xd5aac991U));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xb9b36099U),
                               bswap_32big(0xb1913abfU),
                               bswap_32big(0x61cd37f9U),
                               bswap_32big(0xa169e321U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x9f7a4354U), bswap_32big(0x1449bb90U), bswap_32big(0xbb235f51U),
                           bswap_32big(0x9dcf4712U));
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
            r_rsip_func100(bswap_32big(0xb33444ccU), bswap_32big(0x96b2e608U), bswap_32big(0x99d88b8dU),
                           bswap_32big(0xdc0c51c9U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xbcbff466U),
                               bswap_32big(0x8b2dced0U),
                               bswap_32big(0xb810f323U),
                               bswap_32big(0x36602e02U));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x41a04c98U),
                               bswap_32big(0xfaf7be79U),
                               bswap_32big(0x5f0b9eebU),
                               bswap_32big(0x8ef89d75U));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x83e9c04cU), bswap_32big(0x837fe2b5U), bswap_32big(0x137b81eaU),
                       bswap_32big(0x9e44018eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x8e39e51aU), bswap_32big(0x30c20c18U), bswap_32big(0x540dd8dbU),
                           bswap_32big(0x3b03ccf3U));
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
        r_rsip_func100(bswap_32big(0x8fa25219U), bswap_32big(0x60832609U), bswap_32big(0x0f57e85fU),
                       bswap_32big(0x9e9ff01eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x917fbca2U), bswap_32big(0xdb9b083fU), bswap_32big(0xc0fef8ecU),
                           bswap_32big(0xb8621031U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x530b845aU), bswap_32big(0xb3aa7b28U), bswap_32big(0x0a81c6e8U),
                           bswap_32big(0x89943b4fU));
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
            r_rsip_func100(bswap_32big(0x30ea5f8bU), bswap_32big(0xab33e26cU), bswap_32big(0x91da1cfdU),
                           bswap_32big(0x434b4b57U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x5b4275b4U),
                               bswap_32big(0xbb2c112aU),
                               bswap_32big(0x87162026U),
                               bswap_32big(0x230403dcU));
                continue;
            }

            r_rsip_func100(bswap_32big(0x6e39ff89U), bswap_32big(0x9364d7e8U), bswap_32big(0x096a9a22U),
                           bswap_32big(0x4dbf7348U));
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
                r_rsip_func101(bswap_32big(0xe7078feaU),
                               bswap_32big(0x1a7af73aU),
                               bswap_32big(0x8c20510fU),
                               bswap_32big(0x955e0f9fU));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xf4f2530fU), bswap_32big(0x2981fcc8U), bswap_32big(0x38645e40U),
                           bswap_32big(0x800117c6U));
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
                    r_rsip_func100(bswap_32big(0xaef6c725U),
                                   bswap_32big(0x6505a4bcU),
                                   bswap_32big(0xd922f1e1U),
                                   bswap_32big(0x626ac089U));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x28d6be9fU),
                                   bswap_32big(0xbc527ed9U),
                                   bswap_32big(0xe9e8dc48U),
                                   bswap_32big(0x4e58a074U));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0xd1177f0dU),
                               bswap_32big(0xb04ba131U),
                               bswap_32big(0xc81e02d3U),
                               bswap_32big(0xcf8892c7U));
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
                r_rsip_func100(bswap_32big(0x5def90ddU),
                               bswap_32big(0x5ddfd85cU),
                               bswap_32big(0x25dcf3ccU),
                               bswap_32big(0x30b67b23U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x4e9453e9U),
                                   bswap_32big(0xa8c59ddcU),
                                   bswap_32big(0x5d437ef9U),
                                   bswap_32big(0x439e18c2U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xb727c776U),
                                   bswap_32big(0xa773ce9dU),
                                   bswap_32big(0xcd181cc6U),
                                   bswap_32big(0x9f77d8b8U));
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
                        r_rsip_func100(bswap_32big(0x1df5dc2fU),
                                       bswap_32big(0xea76d627U),
                                       bswap_32big(0x774be9b1U),
                                       bswap_32big(0x676d17d5U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x5500dfc3U),
                                           bswap_32big(0x51c2fbdcU),
                                           bswap_32big(0x9fedf9d4U),
                                           bswap_32big(0x065aa392U));
                            break;
                        }
                        else
                        {
                            r_rsip_func100(bswap_32big(0x8ce997aeU),
                                           bswap_32big(0x26adae81U),
                                           bswap_32big(0x280cfe8aU),
                                           bswap_32big(0x899d9d8aU));
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
                            r_rsip_func101(bswap_32big(0x65137e61U),
                                           bswap_32big(0x1fa32a0bU),
                                           bswap_32big(0x6b6e1197U),
                                           bswap_32big(0xa17fd375U));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0xd70e3e2fU),
                                   bswap_32big(0x4e5530d7U),
                                   bswap_32big(0x4516a4deU),
                                   bswap_32big(0x4d7662aeU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0x3e913263U),
                                       bswap_32big(0x70be0135U),
                                       bswap_32big(0xdbe56856U),
                                       bswap_32big(0xca4f8395U));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x51e36ecaU),
                                       bswap_32big(0x311f5f5cU),
                                       bswap_32big(0xb30bb8ffU),
                                       bswap_32big(0x7dd8493cU));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x66db8e3bU), bswap_32big(0xf785666dU), bswap_32big(0x6063726aU),
                           bswap_32big(0xa8c8150fU));
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
                r_rsip_func100(bswap_32big(0x535c928eU),
                               bswap_32big(0xe194c3f1U),
                               bswap_32big(0x6ffe7fcdU),
                               bswap_32big(0x514e6e2cU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0xfd47911fU),
                                   bswap_32big(0xbab39a95U),
                                   bswap_32big(0xc0eede7fU),
                                   bswap_32big(0x524944b2U));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x10100009U);
                    r_rsip_func101(bswap_32big(0x1ac0824eU),
                                   bswap_32big(0xd2b265c4U),
                                   bswap_32big(0x3e024821U),
                                   bswap_32big(0xc72d43fcU));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0xf46be81fU),
                               bswap_32big(0xf0c6a456U),
                               bswap_32big(0xfffe2934U),
                               bswap_32big(0x5fa50b2aU));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xa311a22aU),
                   bswap_32big(0x853ad039U),
                   bswap_32big(0x2729f546U),
                   bswap_32big(0x8460c08aU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xaebc754fU), bswap_32big(0x4582a68dU), bswap_32big(0x5cf482e8U),
                       bswap_32big(0x0045fe9bU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_subfunc003(0x00c00081U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x10100009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x000007b8U, 0x10100009U);
    r_rsip_func100(bswap_32big(0xcd71910aU),
                   bswap_32big(0x3d805d5bU),
                   bswap_32big(0x80aac9abU),
                   bswap_32big(0xa218dafcU));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xd549bc08U),
                   bswap_32big(0xfa87b343U),
                   bswap_32big(0x8963491cU),
                   bswap_32big(0x5a5fe78bU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0x19610cecU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x17380000U, 0x00000040U, bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0x6d763f8bU),
                   bswap_32big(0x7205776cU),
                   bswap_32big(0x8cb8f400U),
                   bswap_32big(0x48d2de07U));
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
    r_rsip_func101(bswap_32big(0xf21a090bU),
                   bswap_32big(0x6d17d1b8U),
                   bswap_32big(0x26b7a54fU),
                   bswap_32big(0xfabb709aU));
    r_rsip_func052();
    WR1_PROG(REG_1404H, 0x15200000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0x19610cecU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x17380000U, 0x00000040U, bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0x771c666dU),
                   bswap_32big(0x7676a249U),
                   bswap_32big(0x71b3b532U),
                   bswap_32big(0x5e64997aU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x000007b8U, 0x00000838U, 0x00000220U, 0x10100007U);
    r_rsip_subfunc009(bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0xd7a70d63U),
                   bswap_32big(0xf35355a9U),
                   bswap_32big(0x325e0391U),
                   bswap_32big(0xfba76994U));
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
    r_rsip_func100(bswap_32big(0x26487c31U),
                   bswap_32big(0x5e014f37U),
                   bswap_32big(0xba18338aU),
                   bswap_32big(0x7f249bafU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xee77a9fdU), bswap_32big(0x131dda3dU), bswap_32big(0xffd989b2U),
                       bswap_32big(0x6db875e2U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0x19610cecU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x13280000U, 0x00000040U, bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0xed1fafedU),
                   bswap_32big(0xb7b6b529U),
                   bswap_32big(0x129421a1U),
                   bswap_32big(0x0c641adbU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x000003a8U, 0x00000428U, 0x00000630U, 0x10100007U);
    r_rsip_subfunc007(bswap_32big(0x19610cecU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x15300000U, 0x00000040U, bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0x35f7fbc3U),
                   bswap_32big(0x58d975cfU),
                   bswap_32big(0xdd21a403U),
                   bswap_32big(0xa08c9984U));
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
    r_rsip_func101(bswap_32big(0x6aa3d7b6U),
                   bswap_32big(0x0f29b12bU),
                   bswap_32big(0x924bf112U),
                   bswap_32big(0x12a6e6efU));
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
    r_rsip_func100(bswap_32big(0xc4b86275U),
                   bswap_32big(0x4cefd6d8U),
                   bswap_32big(0xa0212302U),
                   bswap_32big(0x156a70daU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7b32c1f7U), bswap_32big(0x114a4153U), bswap_32big(0x1332f83dU),
                       bswap_32big(0x06228994U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x20200009U);
    r_rsip_subfunc007(bswap_32big(0x19610cecU));
    OFS_ADR = 356;
    r_rsip_subfunc008(0x15300000U, 0x00000040U, bswap_32big(0x00002b03U));
    r_rsip_func101(bswap_32big(0x57ea4b60U),
                   bswap_32big(0x28bd91f9U),
                   bswap_32big(0x9d12da96U),
                   bswap_32big(0x62a7d993U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x39a417d9U),
                   bswap_32big(0x901371b9U),
                   bswap_32big(0xcb903a73U),
                   bswap_32big(0x3549444cU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0x3503f76dU),
                   bswap_32big(0x923f025cU),
                   bswap_32big(0x49531929U),
                   bswap_32big(0x251af833U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01159628U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00002b01U));
    r_rsip_func101(bswap_32big(0xf7484c2dU),
                   bswap_32big(0xd496c36eU),
                   bswap_32big(0x30139695U),
                   bswap_32big(0xf958289aU));
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
        r_rsip_func100(bswap_32big(0xb4523129U), bswap_32big(0x633d1f1dU), bswap_32big(0x9bcc90edU),
                       bswap_32big(0x4fb68ab2U));
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
        r_rsip_func101(bswap_32big(0x09fef9b6U), bswap_32big(0x47bc0ab8U), bswap_32big(0x24030ad9U),
                       bswap_32big(0x79b86d81U));
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
        r_rsip_func100(bswap_32big(0x27f24569U), bswap_32big(0xd0235a5cU), bswap_32big(0xb908c8eeU),
                       bswap_32big(0xb118f7a9U));
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
        r_rsip_func101(bswap_32big(0x4724246dU), bswap_32big(0xaaa420e0U), bswap_32big(0x2c4241bbU),
                       bswap_32big(0x6496a2f0U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xf3d2c987U),
                   bswap_32big(0x81ad1d07U),
                   bswap_32big(0xaa28e1ecU),
                   bswap_32big(0x7a5d5324U));
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
    r_rsip_func100(bswap_32big(0x4ebda50eU),
                   bswap_32big(0x2fed6bb0U),
                   bswap_32big(0xadc803a6U),
                   bswap_32big(0xc7c809c0U));
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
    r_rsip_func100(bswap_32big(0xbc154951U),
                   bswap_32big(0x62c8fd3fU),
                   bswap_32big(0x629be43eU),
                   bswap_32big(0xda55df52U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0xc560e4ddU),
                   bswap_32big(0x7de7d050U),
                   bswap_32big(0x66e4604bU),
                   bswap_32big(0x8a60dd14U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x011c027cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00002b02U));
    r_rsip_func101(bswap_32big(0xd0fbb784U),
                   bswap_32big(0x1a92459bU),
                   bswap_32big(0xa749baf7U),
                   bswap_32big(0x7f168548U));
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
        r_rsip_func100(bswap_32big(0x86b66465U), bswap_32big(0x7998a390U), bswap_32big(0xfdfdd46aU),
                       bswap_32big(0x2a68ff62U));
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
        r_rsip_func101(bswap_32big(0x80f44e61U), bswap_32big(0x31c9eb69U), bswap_32big(0x7c49be5aU),
                       bswap_32big(0x57158e81U));
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
    r_rsip_func100(bswap_32big(0x815353e0U),
                   bswap_32big(0x858d2768U),
                   bswap_32big(0x5bfc743dU),
                   bswap_32big(0x8f32cdfdU));
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
    r_rsip_func100(bswap_32big(0xcbf00765U),
                   bswap_32big(0xa9ad8415U),
                   bswap_32big(0x69503958U),
                   bswap_32big(0x84aaa1f6U));
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
    r_rsip_func100(bswap_32big(0xb2e7192eU),
                   bswap_32big(0x3e8f9448U),
                   bswap_32big(0x0e492b03U),
                   bswap_32big(0x4a1a6c22U));
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
    r_rsip_func102(bswap_32big(0x3ecc1747U),
                   bswap_32big(0x6c3ad48fU),
                   bswap_32big(0xf5e17dd5U),
                   bswap_32big(0x9f23e8f9U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
