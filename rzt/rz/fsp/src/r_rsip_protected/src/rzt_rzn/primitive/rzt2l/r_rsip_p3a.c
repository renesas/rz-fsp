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
        r_rsip_func100(bswap_32big(0x7894d37fU), bswap_32big(0x817e9ff5U), bswap_32big(0x873ddf2bU),
                       bswap_32big(0x9133d6b1U));
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
            r_rsip_func100(bswap_32big(0x4632f1caU), bswap_32big(0xea658b67U), bswap_32big(0xedc435b8U),
                           bswap_32big(0x4a3e74bfU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xcddd6fbbU), bswap_32big(0x807ac56cU), bswap_32big(0xb09bc055U),
                           bswap_32big(0xa9ff82fbU));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xd0ec7c6bU), bswap_32big(0xea126a4fU), bswap_32big(0xbf91d7deU),
                       bswap_32big(0xf29465b4U));
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
        r_rsip_func100(bswap_32big(0xb92447c9U), bswap_32big(0xd4edfa84U), bswap_32big(0xe0240f78U),
                       bswap_32big(0xe13b08f2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xfa096093U), bswap_32big(0x55b2af79U), bswap_32big(0x85142af7U),
                           bswap_32big(0x79a55377U));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0xe7b82ed0U), bswap_32big(0xd42b8b40U), bswap_32big(0x47981257U),
                           bswap_32big(0x375b33f9U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xd3145774U), bswap_32big(0x798297daU), bswap_32big(0x7cbd75e9U),
                       bswap_32big(0x7bc34f48U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xbcefd07fU), bswap_32big(0xdc137f97U), bswap_32big(0x4cff1e6cU),
                           bswap_32big(0xf4f1472aU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x1818000aU);
                r_rsip_func101(bswap_32big(0x65fc186eU),
                               bswap_32big(0x78fe878fU),
                               bswap_32big(0x2b9d555fU),
                               bswap_32big(0x72ebf916U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0x80e52ce5U),
                               bswap_32big(0x2509fb84U),
                               bswap_32big(0x196edd83U),
                               bswap_32big(0x3375e426U));
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
            r_rsip_func100(bswap_32big(0xd02cfa21U), bswap_32big(0x9203804eU), bswap_32big(0xb45d64f8U),
                           bswap_32big(0x65e1f096U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x7a6a5448U),
                               bswap_32big(0xaf4332f5U),
                               bswap_32big(0x5667ad5bU),
                               bswap_32big(0x71110fdbU));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x03abf5e6U),
                               bswap_32big(0xbcc276c2U),
                               bswap_32big(0x430be0b1U),
                               bswap_32big(0x4d05e092U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb125fe9cU), bswap_32big(0x82ebd745U), bswap_32big(0xb833103aU),
                           bswap_32big(0xff894c9bU));
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
            r_rsip_func100(bswap_32big(0x97b4f34aU), bswap_32big(0x087b3a26U), bswap_32big(0x7da7f0a0U),
                           bswap_32big(0xd0aadc31U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xaca459c7U),
                               bswap_32big(0x2512db4eU),
                               bswap_32big(0x3bfbcc7aU),
                               bswap_32big(0x9b87bc6dU));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x186c93c8U),
                               bswap_32big(0xa61b4e54U),
                               bswap_32big(0x0c331a3fU),
                               bswap_32big(0x9ce33ac7U));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xbabaef86U), bswap_32big(0x46c4c5a4U), bswap_32big(0x1f3b14e5U),
                       bswap_32big(0x8f5e192dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x20e7348aU), bswap_32big(0xf06a540aU), bswap_32big(0x44444f0dU),
                           bswap_32big(0x81190c69U));
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
        r_rsip_func100(bswap_32big(0xf4cd2be2U), bswap_32big(0xbf10a6c2U), bswap_32big(0x8e9c40a0U),
                       bswap_32big(0x190e015eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x1b8e9836U), bswap_32big(0x7d57deaeU), bswap_32big(0xbf5c6365U),
                           bswap_32big(0xb576ed55U));
        }
        else
        {
            WR1_PROG(REG_1404H, 0x16300000U);
            r_rsip_subfunc003(0x00c00209U);
            r_rsip_func100(bswap_32big(0xb72dcce4U), bswap_32big(0x081a065cU), bswap_32big(0xfb4b4060U),
                           bswap_32big(0xd01c67c6U));
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
            r_rsip_func100(bswap_32big(0xe93e6a66U), bswap_32big(0x952c8775U), bswap_32big(0x0933996eU),
                           bswap_32big(0xe7afc56fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0xd1e64264U),
                               bswap_32big(0xcae0dc1eU),
                               bswap_32big(0x0dba9c9dU),
                               bswap_32big(0x38f4ef09U));
                continue;
            }

            r_rsip_func100(bswap_32big(0x38ab2df7U), bswap_32big(0x2a8d243bU), bswap_32big(0xb73509c4U),
                           bswap_32big(0xa111d654U));
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
                r_rsip_func101(bswap_32big(0x6e209f1bU),
                               bswap_32big(0xa4899559U),
                               bswap_32big(0xf430f245U),
                               bswap_32big(0x3168f031U));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x95eaa59eU), bswap_32big(0x86f68279U), bswap_32big(0x8f1b2a34U),
                           bswap_32big(0x5ad964b4U));
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
                    r_rsip_func100(bswap_32big(0x79e0d269U),
                                   bswap_32big(0xf3ed5dbfU),
                                   bswap_32big(0x831f91d1U),
                                   bswap_32big(0x4bf42145U));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xf1bc4fb0U),
                                   bswap_32big(0xf16a8b4dU),
                                   bswap_32big(0x640a3cbbU),
                                   bswap_32big(0x9db758a4U));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0xe15183bdU),
                               bswap_32big(0xb82624dbU),
                               bswap_32big(0xf31fba46U),
                               bswap_32big(0x1ca27b56U));
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
                r_rsip_func100(bswap_32big(0x0b504d4cU),
                               bswap_32big(0x8693e9c5U),
                               bswap_32big(0x396c9441U),
                               bswap_32big(0x89d2c7b0U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x5cc0d9bdU),
                                   bswap_32big(0xac8b635fU),
                                   bswap_32big(0x2d700949U),
                                   bswap_32big(0x6f144d16U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xf91574b0U),
                                   bswap_32big(0xa16fccd5U),
                                   bswap_32big(0x83b23f49U),
                                   bswap_32big(0x07c65d7bU));
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
                        r_rsip_func100(bswap_32big(0x24dca678U),
                                       bswap_32big(0x62e2d5f8U),
                                       bswap_32big(0x5e056223U),
                                       bswap_32big(0x0f6a4ce5U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x2573c71aU),
                                           bswap_32big(0x1f501bb1U),
                                           bswap_32big(0x60e8e15dU),
                                           bswap_32big(0x3671f892U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18380000U);
                            r_rsip_subfunc003(0x00c00209U);
                            r_rsip_func100(bswap_32big(0xbe51efd5U),
                                           bswap_32big(0xd88d2a88U),
                                           bswap_32big(0x2afcb248U),
                                           bswap_32big(0x10928c5fU));
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
                            r_rsip_func101(bswap_32big(0xa4909f04U),
                                           bswap_32big(0x74189eb6U),
                                           bswap_32big(0x9b921ed5U),
                                           bswap_32big(0x46d13fe8U));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x011832e4U),
                                   bswap_32big(0x9d4bf29eU),
                                   bswap_32big(0x82efc4f9U),
                                   bswap_32big(0xd0f0bde0U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0xa2c6459aU),
                                       bswap_32big(0xb6aae3c5U),
                                       bswap_32big(0x520e89a7U),
                                       bswap_32big(0x9ae9ce5aU));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x76324b5bU),
                                       bswap_32big(0xd5255b45U),
                                       bswap_32big(0xaed82e5fU),
                                       bswap_32big(0x860fd9efU));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x307704ffU), bswap_32big(0xbc7f208fU), bswap_32big(0x84240eafU),
                           bswap_32big(0x8030c6e7U));
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
                r_rsip_func100(bswap_32big(0x91d3519aU),
                               bswap_32big(0x898aff29U),
                               bswap_32big(0x2eb05e54U),
                               bswap_32big(0xba02b1b8U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x6ecc903dU),
                                   bswap_32big(0xc0eccdd2U),
                                   bswap_32big(0x24cba18dU),
                                   bswap_32big(0xdb8746ceU));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x18180009U);
                    r_rsip_func101(bswap_32big(0xbc658215U),
                                   bswap_32big(0x5f9dd268U),
                                   bswap_32big(0x838e636eU),
                                   bswap_32big(0x3e985ab5U));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0x24657fe1U),
                               bswap_32big(0xc45706d6U),
                               bswap_32big(0x3d8d0e04U),
                               bswap_32big(0x5f06f839U));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x45431007U),
                   bswap_32big(0xbea38ac5U),
                   bswap_32big(0x8615bd6eU),
                   bswap_32big(0x0cafa6e0U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xbe2d0df7U), bswap_32big(0xa066b73bU), bswap_32big(0x1d3758adU),
                       bswap_32big(0x18e6b919U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_subfunc003(0x00c000c1U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x18180009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000778U, 0x18180009U);
    r_rsip_func100(bswap_32big(0xa3646cd6U),
                   bswap_32big(0x2e521d2bU),
                   bswap_32big(0x53f8f4a0U),
                   bswap_32big(0x40aa1244U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x2fc1fe9fU),
                   bswap_32big(0xf46e3f5fU),
                   bswap_32big(0x87ec921fU),
                   bswap_32big(0xa5d0b938U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0xfc88fbf0U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0xb6bb2130U),
                   bswap_32big(0x0a19f8d5U),
                   bswap_32big(0x12a4637bU),
                   bswap_32big(0x77ef025bU));
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
    r_rsip_func101(bswap_32big(0x3af21256U),
                   bswap_32big(0x06c69b65U),
                   bswap_32big(0x8a1cc021U),
                   bswap_32big(0x57488b33U));
    r_rsip_func056();
    WR1_PROG(REG_1404H, 0x14a00000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0xfc88fbf0U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x711a89daU),
                   bswap_32big(0xe3b29cd7U),
                   bswap_32big(0xd0984384U),
                   bswap_32big(0x080e0dd5U));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000778U, 0x00000838U, 0x00000220U, 0x18180007U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x0d1f7d2fU),
                   bswap_32big(0x4a978ed4U),
                   bswap_32big(0xe4a80f25U),
                   bswap_32big(0x0eb7e843U));
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
    r_rsip_func100(bswap_32big(0x867f17a8U),
                   bswap_32big(0x3fb17f24U),
                   bswap_32big(0x9983f7d4U),
                   bswap_32big(0x4ee107b9U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xc0087789U), bswap_32big(0x9955919fU), bswap_32big(0x1e3a9db4U),
                       bswap_32big(0x04298190U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0xfc88fbf0U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x12a80000U, 0x00000060U, bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xa62f7beeU),
                   bswap_32big(0x5ba9baccU),
                   bswap_32big(0x03812fa3U),
                   bswap_32big(0x99403323U));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000368U, 0x00000428U, 0x00000630U, 0x18180007U);
    r_rsip_subfunc007(bswap_32big(0xfc88fbf0U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x14b00000U, 0x00000060U, bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x7d439237U),
                   bswap_32big(0x48d16de8U),
                   bswap_32big(0x8af9572bU),
                   bswap_32big(0x88fb3dc2U));
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
    r_rsip_func101(bswap_32big(0x17394936U),
                   bswap_32big(0x9d88a0d2U),
                   bswap_32big(0xcf316fdeU),
                   bswap_32big(0x5e1a3d8cU));
    r_rsip_func030();
    WR1_PROG(REG_1404H, 0x10a00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000428U, 0x00000220U, 0x00000220U, 0x30300009U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0xf9eef0acU),
                   bswap_32big(0x81854a38U),
                   bswap_32big(0x5d54591eU),
                   bswap_32big(0xd28e38a2U));
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
    r_rsip_func101(bswap_32big(0xa2485376U),
                   bswap_32big(0xbc7e2099U),
                   bswap_32big(0x9f96bfdaU),
                   bswap_32big(0x093e3479U));
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
    r_rsip_func101(bswap_32big(0x60550574U),
                   bswap_32big(0x3e9f7448U),
                   bswap_32big(0x3552fe55U),
                   bswap_32big(0xdd920a04U));
    r_rsip_func031();
    for (iLoop = 0; iLoop < 10; iLoop++)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        r_rsip_subfunc003(0x00c00181U);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
        r_rsip_subfunc009(bswap_32big(0x00003a02U));
        r_rsip_func101(bswap_32big(0x2c0fcb49U), bswap_32big(0x25ad6a7cU), bswap_32big(0x2436fc11U),
                       bswap_32big(0x87bc09acU));
        r_rsip_func033();
        r_rsip_func101(bswap_32big(0xa12b6efaU), bswap_32big(0x5f7794a2U), bswap_32big(0xb6886f6dU),
                       bswap_32big(0x78d08b7bU));
    }

    WR1_PROG(REG_1404H, 0x10a00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000428U, 0x00000220U, 0x00000220U, 0x30300009U);
    r_rsip_subfunc009(bswap_32big(0x00003a03U));
    r_rsip_func101(bswap_32big(0x61a98d1fU),
                   bswap_32big(0x5bbb8385U),
                   bswap_32big(0x53bfcc6eU),
                   bswap_32big(0xedc37018U));
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
    r_rsip_func101(bswap_32big(0xa1f1a543U),
                   bswap_32big(0x407c8ed4U),
                   bswap_32big(0xc63c15fdU),
                   bswap_32big(0x172bd178U));
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
    r_rsip_func100(bswap_32big(0xa9226b51U),
                   bswap_32big(0x8508e6daU),
                   bswap_32big(0x73508ef5U),
                   bswap_32big(0x76d6d9f6U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x46b6bd52U), bswap_32big(0xe4b6371dU), bswap_32big(0x63e8b34eU),
                       bswap_32big(0x01a417e8U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);
    r_rsip_subfunc007(bswap_32big(0xfc88fbf0U));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x14b00000U, 0x00000060U, bswap_32big(0x00003a0fU));
    r_rsip_func101(bswap_32big(0x58b63838U),
                   bswap_32big(0xf80cd518U),
                   bswap_32big(0x46efba60U),
                   bswap_32big(0x26d3db9eU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x1c1a43a8U),
                   bswap_32big(0x6e977c72U),
                   bswap_32big(0xf9beac54U),
                   bswap_32big(0x048cb7aaU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x1e647af5U),
                   bswap_32big(0x62627138U),
                   bswap_32big(0x7a8fc815U),
                   bswap_32big(0xfe0769f0U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01dd5025U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x137b2f96U),
                   bswap_32big(0x5e5988efU),
                   bswap_32big(0x3a1463c0U),
                   bswap_32big(0x695c555fU));
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
        r_rsip_func100(bswap_32big(0x95e9348aU), bswap_32big(0x58de71c0U), bswap_32big(0x149ba8daU),
                       bswap_32big(0xfe8132a7U));
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
        r_rsip_func101(bswap_32big(0xe8476797U), bswap_32big(0x8bb8e2faU), bswap_32big(0xedecbfb3U),
                       bswap_32big(0x8217abddU));
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
        r_rsip_func100(bswap_32big(0xee111c1bU), bswap_32big(0xba482b77U), bswap_32big(0x44ae7469U),
                       bswap_32big(0x9ad23ec4U));
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
        r_rsip_func101(bswap_32big(0x30351f1eU), bswap_32big(0xfdaf3481U), bswap_32big(0x3eebc548U),
                       bswap_32big(0x3817a57eU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x62638251U),
                   bswap_32big(0x3749a1f3U),
                   bswap_32big(0xa5a576d8U),
                   bswap_32big(0xd8b42194U));
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
    r_rsip_func100(bswap_32big(0xdbdb1151U),
                   bswap_32big(0x77f2e9c8U),
                   bswap_32big(0x8457f66aU),
                   bswap_32big(0x30f015beU));
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
    r_rsip_func100(bswap_32big(0xee6dd52fU),
                   bswap_32big(0xb01c39feU),
                   bswap_32big(0xf093c72aU),
                   bswap_32big(0x1d702966U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x5d56d6c3U),
                   bswap_32big(0x9b21c83eU),
                   bswap_32big(0xaf6d6f51U),
                   bswap_32big(0xa1898a93U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01d1a79cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xac1cce90U),
                   bswap_32big(0x1496c44eU),
                   bswap_32big(0x025963c6U),
                   bswap_32big(0x544bf6aeU));
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
        r_rsip_func100(bswap_32big(0x10d26218U), bswap_32big(0x4dbee922U), bswap_32big(0x9796571dU),
                       bswap_32big(0x1ddab7caU));
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
        r_rsip_func101(bswap_32big(0xec341d7bU), bswap_32big(0x3ccad76fU), bswap_32big(0x32ba9636U),
                       bswap_32big(0x12beda07U));
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
    r_rsip_func100(bswap_32big(0xf673a291U),
                   bswap_32big(0x8c55cc91U),
                   bswap_32big(0x584fa0b7U),
                   bswap_32big(0x3ff5098aU));
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
    r_rsip_func100(bswap_32big(0x082400e5U),
                   bswap_32big(0xe0675e45U),
                   bswap_32big(0xa2e780ceU),
                   bswap_32big(0x3a9d69cbU));
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
    r_rsip_func100(bswap_32big(0x0f6ffd21U),
                   bswap_32big(0x25e0f2e4U),
                   bswap_32big(0xca4c5b86U),
                   bswap_32big(0x7365aeaeU));
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
    r_rsip_func102(bswap_32big(0xe42f90c2U),
                   bswap_32big(0x15aafa75U),
                   bswap_32big(0x2cc9d633U),
                   bswap_32big(0x031d1fd1U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
