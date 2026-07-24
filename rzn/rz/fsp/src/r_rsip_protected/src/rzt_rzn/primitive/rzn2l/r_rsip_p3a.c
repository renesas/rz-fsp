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

rsip_ret_t r_rsip_p3a (uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x003a0002U);
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
        WR1_PROG(REG_1600H, 0x000000c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80b00006U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x034300c1U);
        WR1_PROG(REG_1404H, 0x10180000U);
        r_rsip_subfunc003(0x00c00209U);
        r_rsip_func100(bswap_32big(0xad70679cU), bswap_32big(0xc6844b09U), bswap_32big(0x524f41b8U),
                       bswap_32big(0x816f1fe4U));
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
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c90011U);
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000028U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000008e7U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 40; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x1e840e04U), bswap_32big(0xb7ead05bU), bswap_32big(0xdafaecf3U),
                           bswap_32big(0x2dc1b6c2U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x3e8ccc57U), bswap_32big(0x834505cdU), bswap_32big(0xadde792dU),
                           bswap_32big(0x379b44d5U));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x856c2533U), bswap_32big(0xf2cc783aU), bswap_32big(0xf7da9f89U),
                       bswap_32big(0x70378371U));
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
        WR1_PROG(REG_1444H, 0x00002fb0U);
        WR1_PROG(REG_0980H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0984H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0988H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_098CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0990H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0994H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0998H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_099CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09A0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09A4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09A8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09ACH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09B0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09B4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09B8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09BCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09C0H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C4H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09C8H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09CCH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09D0H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09D8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09DCH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09E0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09E8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09ECH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09F0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09F8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09FCH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A00H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A04H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A08H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A0CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A10H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A14H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A18H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A1CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A20H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A24H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A28H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A2CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A30H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A34H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A38H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A3CH, bswap_32big(0x51EB851EU));
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1818000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x03ce04caU), bswap_32big(0x49f5f337U), bswap_32big(0xaa583c05U),
                       bswap_32big(0x92335f74U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x0c2cbbfdU), bswap_32big(0xf05f7d81U), bswap_32big(0x98ccc147U),
                           bswap_32big(0x9c6be9deU));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0x7dea65c1U), bswap_32big(0xa0c63167U), bswap_32big(0x03faca23U),
                           bswap_32big(0xd111efd1U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xcb0bf95eU), bswap_32big(0xc7f2699aU), bswap_32big(0xd6ecb4aeU),
                       bswap_32big(0x3e407c87U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x02382b7bU), bswap_32big(0x183dcb7dU), bswap_32big(0xf8f9078cU),
                           bswap_32big(0x19fff8d8U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x1818000aU);
                r_rsip_func101(bswap_32big(0x17693afcU),
                               bswap_32big(0xcf83309bU),
                               bswap_32big(0x0f9c1664U),
                               bswap_32big(0x840b9a2bU));
            }
            else
            {
                r_rsip_func101(bswap_32big(0xdf9dbb28U),
                               bswap_32big(0x08861f86U),
                               bswap_32big(0xad47dc3cU),
                               bswap_32big(0xc8464ad2U));
            }

            WR1_PROG(REG_1404H, 0x19800000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x10000000U));
            r_rsip_subfunc003(0x00c20011U);
            r_rsip_subfunc003(0x00c000b1U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x52345c56U), bswap_32big(0xa4eb089aU), bswap_32big(0x4ee08e1aU),
                           bswap_32big(0x091366d5U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x29642c0dU),
                               bswap_32big(0x80444d9eU),
                               bswap_32big(0xc6f49350U),
                               bswap_32big(0x68a4273dU));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xc1177c6aU),
                               bswap_32big(0x19ca8683U),
                               bswap_32big(0xb6137c97U),
                               bswap_32big(0x32df73e3U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x221d519fU), bswap_32big(0x13e18875U), bswap_32big(0x329e1c8bU),
                           bswap_32big(0x51e9de07U));
        }

        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000000c0U);
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
            WR1_PROG(REG_1404H, 0x14280000U);
            r_rsip_subfunc003(0x00c00209U);
            WR1_PROG(REG_1404H, 0x15700000U);
            r_rsip_subfunc003(0x00c000bdU);
            r_rsip_subfunc003(0x00c90005U);
            r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x18180010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);
            WR1_PROG(REG_1004H, 0x18180004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x19800000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c000bdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x7b939361U), bswap_32big(0x85cdf837U), bswap_32big(0x0c91109bU),
                           bswap_32big(0x5baaa249U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xe39a0bc1U),
                               bswap_32big(0x4f745395U),
                               bswap_32big(0x0a1a5c8aU),
                               bswap_32big(0xc924794dU));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x03ab17fcU),
                               bswap_32big(0xbae3fd08U),
                               bswap_32big(0x8407cebaU),
                               bswap_32big(0xe6970a1aU));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xacdc5667U), bswap_32big(0x541788f2U), bswap_32big(0x6f6c0af1U),
                       bswap_32big(0x8bc16dddU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xc3597a1eU), bswap_32big(0x313c386fU), bswap_32big(0x4f73dd92U),
                           bswap_32big(0x496ea541U));
            continue;
        }

        WR1_PROG(REG_1404H, 0x18780000U);
        r_rsip_subfunc003(0x00c000c1U);
        r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000428U, 0x18180009U);
        r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);
        WR1_PROG(REG_1404H, 0x14280000U);
        r_rsip_subfunc003(0x00c00209U);
        WR1_PROG(REG_1404H, 0x15700000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
        r_rsip_subfunc003(0x00c000bdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x18180010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        WR1_PROG(REG_1020H, 0x00000838U);
        WR1_PROG(REG_1004H, 0x18180004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19800000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c000bdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x1818000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x82247543U), bswap_32big(0x76dc0879U), bswap_32big(0x91ce1f7bU),
                       bswap_32big(0x6389ff29U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xe99c1a60U), bswap_32big(0xbcdcb0aeU), bswap_32big(0xccefeb44U),
                           bswap_32big(0x05aeed3eU));
        }
        else
        {
            WR1_PROG(REG_1404H, 0x16300000U);
            r_rsip_subfunc003(0x00c00209U);
            r_rsip_func100(bswap_32big(0x3aca0f48U), bswap_32big(0x9ca072c8U), bswap_32big(0x3b6ac3ccU),
                           bswap_32big(0xb74bc96aU));
            WR1_PROG(REG_1404H, 0x17780000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c000bdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x18180010U);
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);
            WR1_PROG(REG_1004H, 0x18180000U);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xb48355caU), bswap_32big(0x7f7baef4U), bswap_32big(0x42dd1d1eU),
                           bswap_32big(0x207b151fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x615ca396U),
                               bswap_32big(0xbc86269fU),
                               bswap_32big(0xdade6280U),
                               bswap_32big(0x91bae00eU));
                continue;
            }

            r_rsip_func100(bswap_32big(0x3470f601U), bswap_32big(0x0c576922U), bswap_32big(0x5ba9f5bcU),
                           bswap_32big(0x6cf2c10dU));
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000002U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80b0000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x11600000U);
            r_rsip_subfunc003(0x034300c1U);
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000000bcU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 48; iLoop = iLoop + 1)
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
            WR1_PROG(REG_1404H, 0x15700000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81b0000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c900c1U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                r_rsip_subfunc004(0x00000630U, 0x00000838U, 0x1818000cU);
                r_rsip_subfunc001(0x00000838U, 0x00000938U, 0x00000630U, 0x18180009U);
                WR1_PROG(REG_1600H, 0x000033e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xdb97147eU),
                               bswap_32big(0x7e9ad3adU),
                               bswap_32big(0xf33759ddU),
                               bswap_32big(0x8236fdc6U));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x64a75e6eU), bswap_32big(0x6f64fb12U), bswap_32big(0xa025b20dU),
                           bswap_32big(0xb7b9a465U));
            WR1_PROG(REG_1600H, 0x00000a52U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010160U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_1404H, 0x10180000U);
                r_rsip_subfunc003(0x00c00209U);
                WR1_PROG(REG_1600H, 0x00000884U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b4c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000030U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x11600000U);
                for (jLoop = 0; jLoop < 48; jLoop = jLoop + 4)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c07U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xf2c6fe78U),
                                   bswap_32big(0x9ba365f3U),
                                   bswap_32big(0xed173820U),
                                   bswap_32big(0xf042c208U));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x8d1c14c8U),
                                   bswap_32big(0x16f8d0f3U),
                                   bswap_32big(0x2f2de95cU),
                                   bswap_32big(0x446595adU));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0xfd78e400U),
                               bswap_32big(0xc5c9e55bU),
                               bswap_32big(0x2c0ee7b3U),
                               bswap_32big(0x1572dd8bU));
                WR1_PROG(REG_1404H, 0x19800000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000004U));
                r_rsip_subfunc003(0x00c000bdU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x1818000aU);
                r_rsip_subfunc006(0x00000018U, 0x00000838U, 0x18180010U);
                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000a40U);
                WR1_PROG(REG_1004H, 0x18180004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x17780000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c000bdU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x18180010U);
                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_1018H, 0x00000630U);
                WR1_PROG(REG_101CH, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);
                WR1_PROG(REG_1004H, 0x18180000U);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1404H, 0x19800000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c000bdU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x1818000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x1818000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x6ffb50d9U),
                               bswap_32big(0x0b618606U),
                               bswap_32big(0x1e9b9d67U),
                               bswap_32big(0xb35937c9U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x886c7c3eU),
                                   bswap_32big(0x3c7772b7U),
                                   bswap_32big(0xdab0cd23U),
                                   bswap_32big(0x2295d06fU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xd9d2d22aU),
                                   bswap_32big(0x8ff15622U),
                                   bswap_32big(0xc50afc48U),
                                   bswap_32big(0x69f6f43fU));
                    WR1_PROG(REG_1608H, 0x81010120U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < S_RAM[0 + 1]; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_1404H, 0x19800000U);
                        WR1_PROG(REG_1608H, 0x81b0000aU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00c900c1U);
                        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x1818000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x1818000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x25c7676cU),
                                       bswap_32big(0xa1ceed4bU),
                                       bswap_32big(0xc07fd5c1U),
                                       bswap_32big(0x597b8500U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0xcd618a42U),
                                           bswap_32big(0x64c45b2aU),
                                           bswap_32big(0x5d4fb736U),
                                           bswap_32big(0x8e988aa9U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18380000U);
                            r_rsip_subfunc003(0x00c00209U);
                            r_rsip_func100(bswap_32big(0x7614fd87U),
                                           bswap_32big(0x161befa5U),
                                           bswap_32big(0x3e6c4339U),
                                           bswap_32big(0xfafda97cU));
                            WR1_PROG(REG_1404H, 0x19800000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                            r_rsip_subfunc003(0x00c000bdU);
                            r_rsip_subfunc003(0x00c20005U);
                            r_rsip_subfunc003(0x0002000dU);
                            WR1_PROG(REG_1014H, 0x00000838U);
                            WR1_PROG(REG_1018H, 0x00000a40U);
                            WR1_PROG(REG_101CH, 0x00000428U);
                            WR1_PROG(REG_1020H, 0x00000220U);
                            WR1_PROG(REG_1004H, 0x18180000U);
                            WR1_PROG(REG_1408H, 0x00020000U);
                            WR1_PROG(REG_1000H, 0x00010201U);
                            WAIT_STS(REG_1000H, 0U, 0U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000838U, 0x18180009U);
                            r_rsip_func101(bswap_32big(0xff2c06b3U),
                                           bswap_32big(0x263b3e16U),
                                           bswap_32big(0x232c547aU),
                                           bswap_32big(0x9658384cU));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x568b05f7U),
                                   bswap_32big(0x7f590d21U),
                                   bswap_32big(0x9c3ec166U),
                                   bswap_32big(0xc2446765U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0x3e3e6cb2U),
                                       bswap_32big(0x95aa02d2U),
                                       bswap_32big(0x76dd08f3U),
                                       bswap_32big(0x16f74bf6U));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x97f3fc76U),
                                       bswap_32big(0xc5c8ba47U),
                                       bswap_32big(0xd1044249U),
                                       bswap_32big(0xa2a4069dU));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x9c37a5ffU), bswap_32big(0x885ee706U), bswap_32big(0xdd271096U),
                           bswap_32big(0xea3534f3U));
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
                r_rsip_func100(bswap_32big(0x51aa0130U),
                               bswap_32big(0x8261be98U),
                               bswap_32big(0xad38db4dU),
                               bswap_32big(0x61296741U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0xe43387d3U),
                                   bswap_32big(0x627b48d0U),
                                   bswap_32big(0x91aec9b4U),
                                   bswap_32big(0xa7ed565fU));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x18180009U);
                    r_rsip_func101(bswap_32big(0xe32010eeU),
                                   bswap_32big(0xc9fb251fU),
                                   bswap_32big(0xb48838b4U),
                                   bswap_32big(0x396fb524U));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0x997b3d6aU),
                               bswap_32big(0x0b3ceae2U),
                               bswap_32big(0x936bbd50U),
                               bswap_32big(0x633adb67U));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xf87f4521U),
                   bswap_32big(0xa59f6384U),
                   bswap_32big(0xfe819a27U),
                   bswap_32big(0xd5c4b35fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x6a790be8U), bswap_32big(0xa2ebbdd5U), bswap_32big(0x29b694e8U),
                       bswap_32big(0xb7b4bd2bU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_subfunc003(0x00c000c1U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x18180009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000778U, 0x18180009U);
    r_rsip_func100(bswap_32big(0xd6661009U),
                   bswap_32big(0x9c50885aU),
                   bswap_32big(0x9d863e59U),
                   bswap_32big(0xde2c5d89U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xf9b1d68fU),
                   bswap_32big(0xc30751b8U),
                   bswap_32big(0x442b0f96U),
                   bswap_32big(0x1a42f72aU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0x29034363U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x6dd48141U),
                   bswap_32big(0x0732ed75U),
                   bswap_32big(0x7cec26ceU),
                   bswap_32big(0x2da5b8f5U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000220U, 0x1818000aU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000630U, 0x1818000aU);
    r_rsip_subfunc009(bswap_32big(0x0000003aU));
    r_rsip_func101(bswap_32big(0xf7351944U),
                   bswap_32big(0x005d3f98U),
                   bswap_32big(0x7fe26131U),
                   bswap_32big(0x2443cf0dU));
    r_rsip_func056();
    WR1_PROG(REG_1404H, 0x14a00000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0x29034363U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0xdb58a295U),
                   bswap_32big(0xa31dc8bbU),
                   bswap_32big(0xc5694559U),
                   bswap_32big(0x8c92795eU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000778U, 0x00000838U, 0x00000220U, 0x18180007U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x3919f6baU),
                   bswap_32big(0xed96d096U),
                   bswap_32big(0xe420b7ffU),
                   bswap_32big(0xa3710a03U));
    r_rsip_func058();
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000428U, 0x3030000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000428U, 0x3030000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x2e10ed3fU),
                   bswap_32big(0x9217c7f8U),
                   bswap_32big(0x4512ff9bU),
                   bswap_32big(0xd15fc69aU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xe572a713U), bswap_32big(0xa25f27dbU), bswap_32big(0xa2834ad6U),
                       bswap_32big(0xe516889eU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0x29034363U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x12a80000U, 0x00000060U, bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x0fab322dU),
                   bswap_32big(0x5864fad0U),
                   bswap_32big(0x8c0cbb6dU),
                   bswap_32big(0x2b82e53fU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000368U, 0x00000428U, 0x00000630U, 0x18180007U);
    r_rsip_subfunc007(bswap_32big(0x29034363U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x14b00000U, 0x00000060U, bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xa5ca39a5U),
                   bswap_32big(0xf6933a35U),
                   bswap_32big(0x0244f2fdU),
                   bswap_32big(0xcef8d358U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x16a80000U);
    r_rsip_subfunc003(0x00c00011U);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);
    r_rsip_subfunc001(0x00000368U, 0x00000a40U, 0x00000160U, 0x1818000aU);
    r_rsip_subfunc001(0x00000160U, 0x00000220U, 0x00000428U, 0x18180007U);
    r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x30300010U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000fe8U);
    r_rsip_subfunc009(bswap_32big(0x0000003aU));
    r_rsip_func101(bswap_32big(0x63e9a38cU),
                   bswap_32big(0x3ef228c0U),
                   bswap_32big(0xbb25f1f2U),
                   bswap_32big(0x36a09e26U));
    r_rsip_func030();
    WR1_PROG(REG_1404H, 0x10a00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000428U, 0x00000220U, 0x00000220U, 0x30300009U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0xffcf675dU),
                   bswap_32big(0xc28b2f35U),
                   bswap_32big(0xb49ece61U),
                   bswap_32big(0x871f75a2U));
    r_rsip_func033();
    WR1_PROG(REG_1404H, 0x12a80000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000838U, 0x00000428U, 0x00000428U, 0x30300009U);
    WR1_PROG(REG_1404H, 0x1ae00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x00c00081U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00109U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x5d754af8U),
                   bswap_32big(0x81138a5fU),
                   bswap_32big(0xad46da51U),
                   bswap_32big(0xb43ee942U));
    r_rsip_func031();
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000008U));
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000948U, 0x00000838U, 0x00000838U, 0x30300008U);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00109U);
    r_rsip_subfunc001(0x00000738U, 0x00000948U, 0x00000b68U, 0x11110009U);
    r_rsip_subfunc001(0x00000838U, 0x00000948U, 0x00000948U, 0x20200009U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x1347f68aU),
                   bswap_32big(0xcfa00fa2U),
                   bswap_32big(0xe3f984e7U),
                   bswap_32big(0x738f94b1U));
    r_rsip_func031();
    for (iLoop = 0; iLoop < 10; iLoop++)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_subfunc003(0x00c00181U);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
        r_rsip_subfunc009(bswap_32big(0x00003a02U));
        r_rsip_func101(bswap_32big(0xb4e0822fU), bswap_32big(0xc7189628U), bswap_32big(0x626c667fU),
                       bswap_32big(0xb6b14ce4U));
        r_rsip_func033();
        r_rsip_func101(bswap_32big(0x3c7f1bffU), bswap_32big(0xd09091e3U), bswap_32big(0xe0ece0b9U),
                       bswap_32big(0xe0af0b84U));
    }

    WR1_PROG(REG_1404H, 0x10a00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000428U, 0x00000220U, 0x00000220U, 0x30300009U);
    r_rsip_subfunc009(bswap_32big(0x00003a03U));
    r_rsip_func101(bswap_32big(0xed2beb09U),
                   bswap_32big(0xfcaf465cU),
                   bswap_32big(0x2a08a64cU),
                   bswap_32big(0x38f9ff54U));
    r_rsip_func033();
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);
    WR1_PROG(REG_1404H, 0x10a00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000220U, 0x30300009U);
    WR1_PROG(REG_1404H, 0x14b00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x2f326e4dU),
                   bswap_32big(0xe8be253cU),
                   bswap_32big(0x154552edU),
                   bswap_32big(0xabb7fe71U));
    r_rsip_func058();
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000428U, 0x3030000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000428U, 0x3030000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0xc450ad20U),
                   bswap_32big(0xdb44e0c0U),
                   bswap_32big(0x13756098U),
                   bswap_32big(0x88975e78U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xcc9e75c8U), bswap_32big(0xf2e06c76U), bswap_32big(0x09b7923bU),
                       bswap_32big(0x3b049f66U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);
    r_rsip_subfunc007(bswap_32big(0x29034363U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x14b00000U, 0x00000060U, bswap_32big(0x00003a0fU));
    r_rsip_func101(bswap_32big(0x303b8807U),
                   bswap_32big(0x58806165U),
                   bswap_32big(0x7a6553c5U),
                   bswap_32big(0x7c52a107U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x86819157U),
                   bswap_32big(0xcb33b1e8U),
                   bswap_32big(0xcd8e0dd6U),
                   bswap_32big(0x384f0cb8U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x08e27c41U),
                   bswap_32big(0x60a7a3a1U),
                   bswap_32big(0xa1ee4819U),
                   bswap_32big(0x2afca8fdU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0173ba21U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0xb9843f39U),
                   bswap_32big(0xb9550d64U),
                   bswap_32big(0x8db3d7a4U),
                   bswap_32big(0x055c83ecU));
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
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0; iLoop < 96; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x12e8713bU), bswap_32big(0xd4c8f74cU), bswap_32big(0x9fb67bb9U),
                       bswap_32big(0x35799be7U));
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
        r_rsip_func101(bswap_32big(0x2ece56aeU), bswap_32big(0x886613b0U), bswap_32big(0x37c4b20cU),
                       bswap_32big(0xea488274U));
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
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12a80000U);
    for (iLoop = 0; iLoop < 96; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x189d7c6dU), bswap_32big(0x02e437dcU), bswap_32big(0x6e4be08eU),
                       bswap_32big(0xf06f9a20U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 100]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 101]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 102]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 103]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x851c812aU), bswap_32big(0xe2ce6c49U), bswap_32big(0x412b1767U),
                       bswap_32big(0x4acd14f9U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x89cbd69bU),
                   bswap_32big(0xb7e9c7f4U),
                   bswap_32big(0x16e1ee7dU),
                   bswap_32big(0x349a9276U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[196]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[197]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[198]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[199]);
    r_rsip_func100(bswap_32big(0x00653c44U),
                   bswap_32big(0x2c6b6bc8U),
                   bswap_32big(0x267973aeU),
                   bswap_32big(0x5cfa4a36U));
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
    r_rsip_func100(bswap_32big(0xcbb82c6fU),
                   bswap_32big(0x65d90689U),
                   bswap_32big(0x87e366d9U),
                   bswap_32big(0xc7bcdbdfU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xd60affd3U),
                   bswap_32big(0x30933526U),
                   bswap_32big(0x08724a9bU),
                   bswap_32big(0x8e0ad9faU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x016eee45U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xc04fab34U),
                   bswap_32big(0x93e5fdc3U),
                   bswap_32big(0x1a7e5198U),
                   bswap_32big(0x230eed2cU));
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
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0; iLoop < 96; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xefa0373aU), bswap_32big(0x8137ea71U), bswap_32big(0xd83d5291U),
                       bswap_32big(0x1732457aU));
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
        r_rsip_func101(bswap_32big(0x8636b3a8U), bswap_32big(0x72f5872eU), bswap_32big(0x846e6adfU),
                       bswap_32big(0x2e9c9aebU));
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
    r_rsip_func100(bswap_32big(0x04a7a39bU),
                   bswap_32big(0x017d6451U),
                   bswap_32big(0x3ffefbcdU),
                   bswap_32big(0x3b83a6beU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008104U);
    WR1_PROG(REG_1608H, 0x81010280U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[100]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[101]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[102]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[103]);
    r_rsip_func100(bswap_32big(0x1ca6fa66U),
                   bswap_32big(0xc7b68138U),
                   bswap_32big(0x6803ade8U),
                   bswap_32big(0xfa46acd8U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c100104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[104]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[105]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[106]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[107]);
    r_rsip_func100(bswap_32big(0x13a42842U),
                   bswap_32big(0x1d4f9b5cU),
                   bswap_32big(0x58ef6e24U),
                   bswap_32big(0x73001725U));
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
    r_rsip_func102(bswap_32big(0xcf0737f1U),
                   bswap_32big(0xce3d5eacU),
                   bswap_32big(0x3d515b46U),
                   bswap_32big(0xe062ec6bU));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
