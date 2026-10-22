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
        r_rsip_func100(bswap_32big(0x50855ba7U), bswap_32big(0x1da399c2U), bswap_32big(0x7737753fU),
                       bswap_32big(0x80ab7dedU));
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
            r_rsip_func100(bswap_32big(0x91764883U), bswap_32big(0x3ab06c14U), bswap_32big(0x0c426f21U),
                           bswap_32big(0xb5d2a89cU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd0be0f22U), bswap_32big(0xa8a6a7e8U), bswap_32big(0x4221ac41U),
                           bswap_32big(0xdd8b558dU));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x687c685cU), bswap_32big(0xbeac019eU), bswap_32big(0xaa4c80f4U),
                       bswap_32big(0x2ac94dbcU));
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
        r_rsip_func100(bswap_32big(0xd527ce42U), bswap_32big(0x58817bfeU), bswap_32big(0x916c3551U),
                       bswap_32big(0xa5084beeU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xf6162898U), bswap_32big(0xc3596b47U), bswap_32big(0x96592d3bU),
                           bswap_32big(0x43057762U));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0x35d6618cU), bswap_32big(0x1f030c86U), bswap_32big(0x5429a267U),
                           bswap_32big(0x3d9aae25U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x82bccbc0U), bswap_32big(0x8e1cba23U), bswap_32big(0xd5477425U),
                       bswap_32big(0xa54d3a7fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xd96ac7e3U), bswap_32big(0x378e8700U), bswap_32big(0x68e30917U),
                           bswap_32big(0x5b9cd465U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x1818000aU);
                r_rsip_func101(bswap_32big(0x55f2100fU),
                               bswap_32big(0x8a0a9fabU),
                               bswap_32big(0x5108291dU),
                               bswap_32big(0x208b77e6U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0xb67b0db7U),
                               bswap_32big(0x2377ad0eU),
                               bswap_32big(0x130f3025U),
                               bswap_32big(0x3bf1fbccU));
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
            r_rsip_func100(bswap_32big(0xdd3f1c0fU), bswap_32big(0x96112e10U), bswap_32big(0x281914bbU),
                           bswap_32big(0xc4ab22feU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0xe0b954ddU),
                               bswap_32big(0xec93d55aU),
                               bswap_32big(0xb5663a2cU),
                               bswap_32big(0x922f3087U));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x3578465dU),
                               bswap_32big(0x86e65587U),
                               bswap_32big(0x93fb2a37U),
                               bswap_32big(0x4647529bU));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x8c4cdaf9U), bswap_32big(0x681068e5U), bswap_32big(0x1479a940U),
                           bswap_32big(0x4ef1174fU));
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
            WR1_PROG(REG_1404H, 0x15700000U);
            r_rsip_subfunc003(0x00c000bdU);
            r_rsip_subfunc003(0x00c90005U);
            r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x18180010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x18180004U);
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
            r_rsip_func100(bswap_32big(0x74e32003U), bswap_32big(0x0120478cU), bswap_32big(0x72b012b3U),
                           bswap_32big(0x7720a282U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xd5dba954U),
                               bswap_32big(0xb7e16ac8U),
                               bswap_32big(0xe39184c8U),
                               bswap_32big(0xd4862fa4U));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0xeb02be07U),
                               bswap_32big(0x5f77fd73U),
                               bswap_32big(0x0739f61eU),
                               bswap_32big(0xfc7ae52aU));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x2b34b17cU), bswap_32big(0x5118d370U), bswap_32big(0x2f959a21U),
                       bswap_32big(0xf0c5a240U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x90e41347U), bswap_32big(0x78807970U), bswap_32big(0xca950a91U),
                           bswap_32big(0x4d23f1f8U));
            continue;
        }

        WR1_PROG(REG_1404H, 0x18780000U);
        r_rsip_subfunc003(0x00c000c1U);
        r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000428U, 0x18180009U);
        r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x1818000aU);
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
        r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x18180004U);
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
        r_rsip_func100(bswap_32big(0x08e27811U), bswap_32big(0x6f6b5562U), bswap_32big(0xb6a7247fU),
                       bswap_32big(0xf16252ceU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x4b737701U), bswap_32big(0x016385bbU), bswap_32big(0xaa6872c4U),
                           bswap_32big(0x7317968dU));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xb373910aU), bswap_32big(0xc82ea3b1U), bswap_32big(0x2a63d572U),
                           bswap_32big(0x6c7e302fU));
            WR1_PROG(REG_1404H, 0x17780000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c000bdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x18180010U);
            r_rsip_subfunc005(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x18180000U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x3f14b830U), bswap_32big(0x470a45c7U), bswap_32big(0x25f39f4fU),
                           bswap_32big(0x5bdc7ba2U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x0429c052U),
                               bswap_32big(0x7807b5f1U),
                               bswap_32big(0xfeab7c17U),
                               bswap_32big(0x83a28fcdU));
                continue;
            }

            r_rsip_func100(bswap_32big(0x1b284231U), bswap_32big(0xed33deadU), bswap_32big(0xe30acfa6U),
                           bswap_32big(0x83318294U));
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
                r_rsip_func101(bswap_32big(0xf359a1aaU),
                               bswap_32big(0x6aaaaa50U),
                               bswap_32big(0xd6853feaU),
                               bswap_32big(0x8871468cU));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x456fb059U), bswap_32big(0xe79a4c64U), bswap_32big(0x070eea6eU),
                           bswap_32big(0x7f02a980U));
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
                    r_rsip_func100(bswap_32big(0x8ca5b93bU),
                                   bswap_32big(0xafeefaf2U),
                                   bswap_32big(0xd150bb76U),
                                   bswap_32big(0xf6b7f8b9U));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xa9bac8e3U),
                                   bswap_32big(0x928374a6U),
                                   bswap_32big(0x9cae9255U),
                                   bswap_32big(0x143abb37U));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x4c28af0bU),
                               bswap_32big(0x0c3e873aU),
                               bswap_32big(0xd05c8d0bU),
                               bswap_32big(0x5fcc565dU));
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
                r_rsip_subfunc002(0x00000838U, 0x00000a40U, 0x18180004U);
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
                r_rsip_subfunc005(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x18180000U, 0x00020000U);
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
                r_rsip_func100(bswap_32big(0x7e8cc5c7U),
                               bswap_32big(0xe512428fU),
                               bswap_32big(0x5b61661dU),
                               bswap_32big(0x4848a528U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xaa1fa463U),
                                   bswap_32big(0x1ca1c857U),
                                   bswap_32big(0x8cb24714U),
                                   bswap_32big(0x7be2b954U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0x1abadf0aU),
                                   bswap_32big(0xf10405bdU),
                                   bswap_32big(0xa2b7b9aaU),
                                   bswap_32big(0x0c985f5dU));
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
                        r_rsip_func100(bswap_32big(0x1727c05cU),
                                       bswap_32big(0xe4770d79U),
                                       bswap_32big(0xe27e2ac8U),
                                       bswap_32big(0xab907bc6U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0xd008df21U),
                                           bswap_32big(0xd4375428U),
                                           bswap_32big(0x1c2e71acU),
                                           bswap_32big(0x6d6b0953U));
                            break;
                        }
                        else
                        {
                            r_rsip_func100(bswap_32big(0xe7927bb8U),
                                           bswap_32big(0x17ca10bdU),
                                           bswap_32big(0xd950501dU),
                                           bswap_32big(0x1ae177d0U));
                            WR1_PROG(REG_1404H, 0x19800000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                            r_rsip_subfunc003(0x00c000bdU);
                            r_rsip_subfunc003(0x00c20005U);
                            r_rsip_subfunc003(0x0002000dU);
                            r_rsip_subfunc005(0x00000838U,
                                              0x00000a40U,
                                              0x00000428U,
                                              0x00000220U,
                                              0x18180000U,
                                              0x00020000U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000838U, 0x18180009U);
                            r_rsip_func101(bswap_32big(0xe3315c1bU),
                                           bswap_32big(0xcd55a83aU),
                                           bswap_32big(0x6bb400fbU),
                                           bswap_32big(0xd321490bU));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x7898da2aU),
                                   bswap_32big(0x30cae1cbU),
                                   bswap_32big(0x55cf4ccfU),
                                   bswap_32big(0x120066c1U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0xf8304752U),
                                       bswap_32big(0x04659fc0U),
                                       bswap_32big(0x8a6d62a3U),
                                       bswap_32big(0xcaa098ffU));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x175091bfU),
                                       bswap_32big(0xbfb24d6cU),
                                       bswap_32big(0x9fea4c83U),
                                       bswap_32big(0x1e41df85U));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x62d74bcbU), bswap_32big(0xdbd0d5f0U), bswap_32big(0x2ffc23b5U),
                           bswap_32big(0x26df8dd8U));
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
                r_rsip_func100(bswap_32big(0xc241e0c8U),
                               bswap_32big(0x82aa2535U),
                               bswap_32big(0xfc57716cU),
                               bswap_32big(0x45c42e09U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0xdab6b1e2U),
                                   bswap_32big(0x15a27b1bU),
                                   bswap_32big(0x6cd71995U),
                                   bswap_32big(0x322efe3fU));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x18180009U);
                    r_rsip_func101(bswap_32big(0xa682ffb0U),
                                   bswap_32big(0x928f8b08U),
                                   bswap_32big(0xab741d1bU),
                                   bswap_32big(0xadbc9adaU));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0x420e8428U),
                               bswap_32big(0x0b2f762fU),
                               bswap_32big(0x1d5ce4b0U),
                               bswap_32big(0xb78e42e4U));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xeb044e05U),
                   bswap_32big(0xd9ae6872U),
                   bswap_32big(0x65a5c0cbU),
                   bswap_32big(0x3be665d4U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x91b59029U), bswap_32big(0xf856e362U), bswap_32big(0x8645c26fU),
                       bswap_32big(0x3610c164U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19800000U);
    r_rsip_subfunc003(0x00c000c1U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x18180009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000778U, 0x18180009U);
    r_rsip_func100(bswap_32big(0xc1fd888aU),
                   bswap_32big(0x99c2605dU),
                   bswap_32big(0x2f9e4b44U),
                   bswap_32big(0x352c8751U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x08e885b4U),
                   bswap_32big(0x26d8ed03U),
                   bswap_32big(0x13d8049aU),
                   bswap_32big(0x911a93c3U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0xaca5877cU));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x058093e5U),
                   bswap_32big(0xaf56323cU),
                   bswap_32big(0x3f619f31U),
                   bswap_32big(0x3e4be963U));
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
    r_rsip_func101(bswap_32big(0x723aac73U),
                   bswap_32big(0x2383c740U),
                   bswap_32big(0x8201b7b4U),
                   bswap_32big(0x44a4b520U));
    r_rsip_func056();
    WR1_PROG(REG_1404H, 0x14a00000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0xaca5877cU));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0xdf23299fU),
                   bswap_32big(0xa4a82aa7U),
                   bswap_32big(0x681cb7dcU),
                   bswap_32big(0x493b1fe0U));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000778U, 0x00000838U, 0x00000220U, 0x18180007U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x334b9ceeU),
                   bswap_32big(0x1e7fd368U),
                   bswap_32big(0xa23c61a8U),
                   bswap_32big(0x1db1cf53U));
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
    r_rsip_func100(bswap_32big(0x2466b588U),
                   bswap_32big(0x2a15e12eU),
                   bswap_32big(0x0ebfea09U),
                   bswap_32big(0xab89d8faU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xfb80150fU), bswap_32big(0x4e0d44ffU), bswap_32big(0xf1ab2dd2U),
                       bswap_32big(0xf24935f4U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0xaca5877cU));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x12a80000U, 0x00000060U, bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xbe551a61U),
                   bswap_32big(0xf46517c0U),
                   bswap_32big(0xcc35605bU),
                   bswap_32big(0xf292c8d2U));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000368U, 0x00000428U, 0x00000630U, 0x18180007U);
    r_rsip_subfunc007(bswap_32big(0xaca5877cU));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x14b00000U, 0x00000060U, bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x0781a7baU),
                   bswap_32big(0x6a4d7894U),
                   bswap_32big(0x94cd6faeU),
                   bswap_32big(0x2cec05b7U));
    r_rsip_func016(OFS_ADR);
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
    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000838U);
    r_rsip_subfunc002(0x00000630U, 0x00000428U, 0x30300002U);
    r_rsip_subfunc002(0x00000630U, 0x00000220U, 0x30300003U);
    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000220U);
    r_rsip_subfunc002(0x00000630U, 0x00000220U, 0x30300002U);
    WR1_PROG(REG_1404H, 0x14b00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x3df8f173U),
                   bswap_32big(0x23e547b0U),
                   bswap_32big(0x739a55abU),
                   bswap_32big(0x1f1ebc51U));
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
    r_rsip_func100(bswap_32big(0xa72c0586U),
                   bswap_32big(0x299b11b6U),
                   bswap_32big(0x1cac6efcU),
                   bswap_32big(0x58b9ba80U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x6bae1ab4U), bswap_32big(0xa3fd9eedU), bswap_32big(0x7b87d5ebU),
                       bswap_32big(0x95dabd58U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_subfunc003(0x00c00181U);
    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x30300009U);
    r_rsip_subfunc007(bswap_32big(0xaca5877cU));
    OFS_ADR = 516;
    r_rsip_subfunc008(0x14b00000U, 0x00000060U, bswap_32big(0x00003a0fU));
    r_rsip_func101(bswap_32big(0xca8f4350U),
                   bswap_32big(0x22723c38U),
                   bswap_32big(0xfda3ca66U),
                   bswap_32big(0xcc86d735U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x900d1936U),
                   bswap_32big(0x9084b704U),
                   bswap_32big(0x73e0ba7fU),
                   bswap_32big(0x605cecc3U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x8f7ee087U),
                   bswap_32big(0x2ca60ca8U),
                   bswap_32big(0x95c3546dU),
                   bswap_32big(0x41cc9855U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0198fae4U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003a01U));
    r_rsip_func101(bswap_32big(0x8550f630U),
                   bswap_32big(0x69b04d07U),
                   bswap_32big(0x859cf550U),
                   bswap_32big(0x1c91d873U));
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
        r_rsip_func100(bswap_32big(0xdfce4e17U), bswap_32big(0xfe6cf37bU), bswap_32big(0x61e2d144U),
                       bswap_32big(0x04ed21aaU));
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
        r_rsip_func101(bswap_32big(0x5f173126U), bswap_32big(0xcef05881U), bswap_32big(0x00bf2dcfU),
                       bswap_32big(0x9c9ac242U));
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
        r_rsip_func100(bswap_32big(0xc2c53367U), bswap_32big(0x3aadfd1aU), bswap_32big(0xf2274d25U),
                       bswap_32big(0x1a72fcc9U));
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
        r_rsip_func101(bswap_32big(0xb19faf78U), bswap_32big(0x9cafd84cU), bswap_32big(0x33887eabU),
                       bswap_32big(0x2995b7dbU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xa4530594U),
                   bswap_32big(0x9f1a8f97U),
                   bswap_32big(0xfdd412c3U),
                   bswap_32big(0xe6a3770aU));
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
    r_rsip_func100(bswap_32big(0x2d37d773U),
                   bswap_32big(0x62b628dbU),
                   bswap_32big(0x7871da0cU),
                   bswap_32big(0xaeacfe0eU));
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
    r_rsip_func100(bswap_32big(0x8682921cU),
                   bswap_32big(0xe21d4ba9U),
                   bswap_32big(0x37719bf8U),
                   bswap_32big(0x53985d3eU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0xccfca7d2U),
                   bswap_32big(0xe125a57bU),
                   bswap_32big(0x3260d27cU),
                   bswap_32big(0xc1f6f3fcU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x011ba0baU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003a02U));
    r_rsip_func101(bswap_32big(0x3a6f36ffU),
                   bswap_32big(0x37446eedU),
                   bswap_32big(0xa53bc4fcU),
                   bswap_32big(0xa7fd3067U));
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
        r_rsip_func100(bswap_32big(0x3646e957U), bswap_32big(0x4a160265U), bswap_32big(0xc56d8b66U),
                       bswap_32big(0x193f65a1U));
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
        r_rsip_func101(bswap_32big(0x5fad7288U), bswap_32big(0x3832c542U), bswap_32big(0xb82aac25U),
                       bswap_32big(0xf2439b7dU));
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
    r_rsip_func100(bswap_32big(0xbd3649c4U),
                   bswap_32big(0xf917a221U),
                   bswap_32big(0xaa300705U),
                   bswap_32big(0x9c36d272U));
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
    r_rsip_func100(bswap_32big(0x9223e033U),
                   bswap_32big(0x2b4ea6b3U),
                   bswap_32big(0x09f6fed0U),
                   bswap_32big(0x2b63d354U));
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
    r_rsip_func100(bswap_32big(0x6f68593fU),
                   bswap_32big(0x31440864U),
                   bswap_32big(0x35b9f0f8U),
                   bswap_32big(0x4cd15b5dU));
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
    r_rsip_func102(bswap_32big(0xcf6523b2U),
                   bswap_32big(0xe4a9ab4fU),
                   bswap_32big(0xb2af0043U),
                   bswap_32big(0x5fccd171U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
