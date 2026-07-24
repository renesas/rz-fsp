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

rsip_ret_t r_rsip_p3b (uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x003b0002U);
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
        r_rsip_func100(bswap_32big(0x13da6185U), bswap_32big(0x3313e195U), bswap_32big(0x98216d98U),
                       bswap_32big(0x6b2aea26U));
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
        WR1_PROG(REG_1404H, 0x11200000U);
        r_rsip_subfunc003(0x00c90011U);
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000038U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000008e7U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 56; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x12c7b2a1U), bswap_32big(0xa836ce88U), bswap_32big(0x073107a6U),
                           bswap_32big(0x5b50f2eeU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe4b61828U), bswap_32big(0xba606e8dU), bswap_32big(0x90bd1a24U),
                           bswap_32big(0x675531ebU));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x3bb36261U), bswap_32big(0x36549ebfU), bswap_32big(0x686f3d2aU),
                       bswap_32big(0xf7a92a30U));
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
        WR1_PROG(REG_1444H, 0x00003fb0U);
        WR1_PROG(REG_0940H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0944H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0948H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_094CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0950H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0954H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0958H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_095CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0960H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0964H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0968H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_096CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0970H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0974H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0978H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_097CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0980H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0984H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0988H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_098CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0990H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0994H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0998H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_099CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09A0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09A4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09A8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09ACH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09B0H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09B4H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09B8H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09BCH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09C0H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09C4H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09C8H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09CCH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09D0H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09D4H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09D8H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09DCH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09E0H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09E4H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09E8H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_09ECH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_09F0H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_09F4H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_09F8H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_09FCH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A00H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A04H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A08H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A0CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A10H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A14H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A18H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A1CH, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A20H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A24H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A28H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A2CH, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A30H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A34H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A38H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A3CH, bswap_32big(0xB851EB85U));
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x2020000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x82331301U), bswap_32big(0xb633ab2eU), bswap_32big(0xb79fedffU),
                       bswap_32big(0x5152fc98U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x8951212eU), bswap_32big(0xdf36f16aU), bswap_32big(0x14b78769U),
                           bswap_32big(0x088792afU));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0x2c589123U), bswap_32big(0x75fe5bd2U), bswap_32big(0xa5e0de68U),
                           bswap_32big(0x4b2943b4U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x32165d1aU), bswap_32big(0x6ff1d7ddU), bswap_32big(0x273ba5a8U),
                       bswap_32big(0xe342f681U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x30de537cU), bswap_32big(0x00bf8bb1U), bswap_32big(0x42ee3602U),
                           bswap_32big(0xbea5bb8eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x2020000aU);
                r_rsip_func101(bswap_32big(0x3c12714fU),
                               bswap_32big(0xe5d8eb3cU),
                               bswap_32big(0xb212fda2U),
                               bswap_32big(0xdc4a8057U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0x28a58cf7U),
                               bswap_32big(0xae28866fU),
                               bswap_32big(0x606b3668U),
                               bswap_32big(0xd1f2f008U));
            }

            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x10000000U));
            r_rsip_subfunc003(0x00c20011U);
            r_rsip_subfunc003(0x00c000f1U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x5c230d8cU), bswap_32big(0xc8bad32bU), bswap_32big(0x1705fd1cU),
                           bswap_32big(0x56ede685U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x16407a1cU),
                               bswap_32big(0x056c9110U),
                               bswap_32big(0xfeb0da14U),
                               bswap_32big(0x389842a2U));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x6bb3947aU),
                               bswap_32big(0xf4eac7eeU),
                               bswap_32big(0x05830412U),
                               bswap_32big(0xfad84654U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x9f73e10cU), bswap_32big(0x1ffc3897U), bswap_32big(0x943c584eU),
                           bswap_32big(0xe7f8cdb0U));
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
            WR1_PROG(REG_1404H, 0x15300000U);
            r_rsip_subfunc003(0x00c000fdU);
            r_rsip_subfunc003(0x00c90005U);
            r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x20200010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000630U);
            WR1_PROG(REG_1020H, 0x00000838U);
            WR1_PROG(REG_1004H, 0x20200004U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c000fdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x5496d49aU), bswap_32big(0x9b4d69b5U), bswap_32big(0xcfdb3e1aU),
                           bswap_32big(0x14c45592U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xa6089c99U),
                               bswap_32big(0xae3662f8U),
                               bswap_32big(0xca3c1899U),
                               bswap_32big(0xc357bd98U));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x99832eb2U),
                               bswap_32big(0xbc879744U),
                               bswap_32big(0x50065c29U),
                               bswap_32big(0x84d7aa70U));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x9591b3d5U), bswap_32big(0x1ced7402U), bswap_32big(0x6275a050U),
                       bswap_32big(0xd1de8c3cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x380e4e7eU), bswap_32big(0xb5ef2200U), bswap_32big(0xd92b8577U),
                           bswap_32big(0x4cf60f79U));
            continue;
        }

        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_subfunc003(0x00c00101U);
        r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000428U, 0x20200009U);
        r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x2020000aU);
        WR1_PROG(REG_1404H, 0x14280000U);
        r_rsip_subfunc003(0x00c00209U);
        WR1_PROG(REG_1404H, 0x15300000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
        r_rsip_subfunc003(0x00c000fdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x20200010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        WR1_PROG(REG_101CH, 0x00000630U);
        WR1_PROG(REG_1020H, 0x00000838U);
        WR1_PROG(REG_1004H, 0x20200004U);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19400000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c000fdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x2020000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xa96345a8U), bswap_32big(0x0ea2df63U), bswap_32big(0x19ed71d6U),
                       bswap_32big(0xc7c1ad9fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xe9722c52U), bswap_32big(0xd524a9efU), bswap_32big(0x5e91f148U),
                           bswap_32big(0x9d5fc116U));
        }
        else
        {
            WR1_PROG(REG_1404H, 0x16300000U);
            r_rsip_subfunc003(0x00c00209U);
            r_rsip_func100(bswap_32big(0xc7bd9451U), bswap_32big(0xcb9dc9b7U), bswap_32big(0x5cdb0e06U),
                           bswap_32big(0x8e81864eU));
            WR1_PROG(REG_1404H, 0x17380000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c000fdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x20200010U);
            WR1_PROG(REG_1014H, 0x00000838U);
            WR1_PROG(REG_1018H, 0x00000220U);
            WR1_PROG(REG_101CH, 0x00000428U);
            WR1_PROG(REG_1020H, 0x00000630U);
            WR1_PROG(REG_1004H, 0x20200000U);
            WR1_PROG(REG_1408H, 0x00020000U);
            WR1_PROG(REG_1000H, 0x00010201U);
            WAIT_STS(REG_1000H, 0U, 0U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xdd3aea1cU), bswap_32big(0xb82c0907U), bswap_32big(0x0f291be3U),
                           bswap_32big(0xff401b49U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x803d90a0U),
                               bswap_32big(0x1ab7b5f4U),
                               bswap_32big(0x7c1c17e0U),
                               bswap_32big(0x2d8efe38U));
                continue;
            }

            r_rsip_func100(bswap_32big(0x5a3255c6U), bswap_32big(0xfc858dfdU), bswap_32big(0x4ded3df1U),
                           bswap_32big(0x404eaadeU));
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000001U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x80c0000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x11200000U);
            r_rsip_subfunc003(0x03430101U);
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000000fcU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 64; iLoop = iLoop + 1)
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
            WR1_PROG(REG_1404H, 0x15300000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81c0000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90101U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                r_rsip_subfunc004(0x00000630U, 0x00000838U, 0x2020000cU);
                r_rsip_subfunc001(0x00000838U, 0x00000938U, 0x00000630U, 0x20200009U);
                WR1_PROG(REG_1600H, 0x000033e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x2196fc36U),
                               bswap_32big(0x15c10881U),
                               bswap_32big(0xeb345468U),
                               bswap_32big(0x1cbfd173U));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xb857b1e3U), bswap_32big(0x19fa2af4U), bswap_32big(0x2f861b6bU),
                           bswap_32big(0x1a56bb26U));
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
                WR1_PROG(REG_1600H, 0x00000040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x11200000U);
                for (jLoop = 0; jLoop < 64; jLoop = jLoop + 4)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c07U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0x3bb8610cU),
                                   bswap_32big(0xcfd827baU),
                                   bswap_32big(0x276d166cU),
                                   bswap_32big(0x37123728U));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xa3111ee2U),
                                   bswap_32big(0x03db0802U),
                                   bswap_32big(0x7ea6d7a8U),
                                   bswap_32big(0x56c3f94fU));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x954e430eU),
                               bswap_32big(0x91454fe7U),
                               bswap_32big(0xa63ca78fU),
                               bswap_32big(0x013bf7f5U));
                WR1_PROG(REG_1404H, 0x19400000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000004U));
                r_rsip_subfunc003(0x00c000fdU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x2020000aU);
                r_rsip_subfunc006(0x00000018U, 0x00000838U, 0x20200010U);
                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_101CH, 0x00000838U);
                WR1_PROG(REG_1020H, 0x00000a40U);
                WR1_PROG(REG_1004H, 0x20200004U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_1404H, 0x17380000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c000fdU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x20200010U);
                WR1_PROG(REG_1014H, 0x00000220U);
                WR1_PROG(REG_1018H, 0x00000630U);
                WR1_PROG(REG_101CH, 0x00000428U);
                WR1_PROG(REG_1020H, 0x00000838U);
                WR1_PROG(REG_1004H, 0x20200000U);
                WR1_PROG(REG_1408H, 0x00020000U);
                WR1_PROG(REG_1000H, 0x00010201U);
                WAIT_STS(REG_1000H, 0U, 0U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1404H, 0x19400000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c000fdU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x2020000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x2020000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x9ac7f22dU),
                               bswap_32big(0xb1985e19U),
                               bswap_32big(0x3760277fU),
                               bswap_32big(0xc5af8e1cU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x3da16c83U),
                                   bswap_32big(0xe31d0704U),
                                   bswap_32big(0xf880d2a7U),
                                   bswap_32big(0xad3c31dfU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0x2370f689U),
                                   bswap_32big(0xbcf19216U),
                                   bswap_32big(0xc9875601U),
                                   bswap_32big(0x1f6a5fedU));
                    WR1_PROG(REG_1608H, 0x81010120U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < S_RAM[0 + 1]; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_1404H, 0x19400000U);
                        WR1_PROG(REG_1608H, 0x81c0000aU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00c90101U);
                        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x2020000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x2020000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x3dee63e3U),
                                       bswap_32big(0x9bd79177U),
                                       bswap_32big(0x0da892c7U),
                                       bswap_32big(0xc2b4e55bU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x0fc6712aU),
                                           bswap_32big(0x462bd5cbU),
                                           bswap_32big(0xb2e39b46U),
                                           bswap_32big(0x597fb482U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18380000U);
                            r_rsip_subfunc003(0x00c00209U);
                            r_rsip_func100(bswap_32big(0x5bb7e0f0U),
                                           bswap_32big(0xeb017a24U),
                                           bswap_32big(0x2b27d93eU),
                                           bswap_32big(0xf316ff03U));
                            WR1_PROG(REG_1404H, 0x19400000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                            r_rsip_subfunc003(0x00c000fdU);
                            r_rsip_subfunc003(0x00c20005U);
                            r_rsip_subfunc003(0x0002000dU);
                            WR1_PROG(REG_1014H, 0x00000838U);
                            WR1_PROG(REG_1018H, 0x00000a40U);
                            WR1_PROG(REG_101CH, 0x00000428U);
                            WR1_PROG(REG_1020H, 0x00000220U);
                            WR1_PROG(REG_1004H, 0x20200000U);
                            WR1_PROG(REG_1408H, 0x00020000U);
                            WR1_PROG(REG_1000H, 0x00010201U);
                            WAIT_STS(REG_1000H, 0U, 0U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000838U, 0x20200009U);
                            r_rsip_func101(bswap_32big(0x04521a9bU),
                                           bswap_32big(0xc7036bc7U),
                                           bswap_32big(0x6e564581U),
                                           bswap_32big(0x8fde7a3fU));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x1109cbb4U),
                                   bswap_32big(0x84242940U),
                                   bswap_32big(0x99349089U),
                                   bswap_32big(0xf96aea3bU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0x90c54182U),
                                       bswap_32big(0xe4598bb3U),
                                       bswap_32big(0x701b0eceU),
                                       bswap_32big(0x1d6c31c7U));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xcce0790bU),
                                       bswap_32big(0x90a653fbU),
                                       bswap_32big(0x2524c000U),
                                       bswap_32big(0x521e236aU));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0xb7c5339dU), bswap_32big(0x097c899fU), bswap_32big(0x3f49b568U),
                           bswap_32big(0x356cbce9U));
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
                r_rsip_func100(bswap_32big(0x09ae72b4U),
                               bswap_32big(0x6374c400U),
                               bswap_32big(0x9eba5e6cU),
                               bswap_32big(0xd3dd58fcU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0xc841115bU),
                                   bswap_32big(0x24d95dc9U),
                                   bswap_32big(0x91a090ecU),
                                   bswap_32big(0x9e0d4b87U));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x20200009U);
                    r_rsip_func101(bswap_32big(0x0cdcafd0U),
                                   bswap_32big(0x901d6614U),
                                   bswap_32big(0xb21dddbdU),
                                   bswap_32big(0x666532f8U));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0x79d37454U),
                               bswap_32big(0xa7cbee61U),
                               bswap_32big(0xb379f677U),
                               bswap_32big(0xa32575fcU));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x337af301U),
                   bswap_32big(0x191b172aU),
                   bswap_32big(0x20112c33U),
                   bswap_32big(0xdb98bbb5U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xade46a9eU), bswap_32big(0xdd45c038U), bswap_32big(0x90761eadU),
                       bswap_32big(0x0f35f1fbU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x20200009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000738U, 0x20200009U);
    r_rsip_func100(bswap_32big(0x04840864U),
                   bswap_32big(0xb0e03cebU),
                   bswap_32big(0x8a863da4U),
                   bswap_32big(0xb3a2f700U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xd2882dfbU),
                   bswap_32big(0x01953205U),
                   bswap_32big(0xcd883141U),
                   bswap_32big(0x5aff6756U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0xbbbcf5b1U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xd0179a20U),
                   bswap_32big(0x554eb582U),
                   bswap_32big(0xdf44fe4dU),
                   bswap_32big(0x8230ac32U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000220U, 0x2020000aU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000630U, 0x2020000aU);
    r_rsip_subfunc009(bswap_32big(0x0000003bU));
    r_rsip_func101(bswap_32big(0x5c6037c0U),
                   bswap_32big(0x1762b06fU),
                   bswap_32big(0xa0a5edf8U),
                   bswap_32big(0xad9f29b1U));
    r_rsip_func054();
    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000660U, 0x20200009U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000dc0U);
    WR1_PROG(REG_1404H, 0x14500000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0xbbbcf5b1U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x16780000U, 0x00000080U, bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xcc12255eU),
                   bswap_32big(0x3062ffd1U),
                   bswap_32big(0xf93c51a2U),
                   bswap_32big(0x3a7ec33eU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000778U, 0x00000878U, 0x00000230U, 0x20200007U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xb61d60d2U),
                   bswap_32big(0xdb3b04eaU),
                   bswap_32big(0x01114f4aU),
                   bswap_32big(0xa8809a1bU));
    r_rsip_func061();
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000660U, 0x00000a90U, 0x00000448U, 0x4040000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000448U, 0x4040000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x772350fbU),
                   bswap_32big(0xf99ddf86U),
                   bswap_32big(0xe3b34914U),
                   bswap_32big(0x529902e9U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x8ffede0dU), bswap_32big(0x62e6c6d6U), bswap_32big(0x0f957f59U),
                       bswap_32big(0x67b3fa16U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0xbbbcf5b1U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x12480000U, 0x00000080U, bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x0ece2de9U),
                   bswap_32big(0xc7ddc1a2U),
                   bswap_32big(0x1da0030dU),
                   bswap_32big(0x75690debU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000348U, 0x00000448U, 0x00000660U, 0x20200007U);
    r_rsip_subfunc007(bswap_32big(0xbbbcf5b1U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0xc03a7552U),
                   bswap_32big(0x57045fedU),
                   bswap_32big(0x1d02afa6U),
                   bswap_32big(0xc41bf06fU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000448U, 0x00000a90U, 0x00000230U, 0x2020000aU);
    r_rsip_subfunc001(0x00000348U, 0x00000a90U, 0x00000130U, 0x2020000aU);
    r_rsip_subfunc001(0x00000130U, 0x00000230U, 0x00000448U, 0x20200007U);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000448U, 0x00000a90U, 0x00000428U, 0x40400009U);
    r_rsip_subfunc001(0x00000660U, 0x00000a90U, 0x00000630U, 0x40400009U);
    r_rsip_subfunc001(0x00000878U, 0x00000a90U, 0x00000838U, 0x40400009U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000fe8U);
    r_rsip_subfunc009(bswap_32big(0x0000003bU));
    r_rsip_func101(bswap_32big(0x619eada8U),
                   bswap_32big(0x7f210214U),
                   bswap_32big(0x6f9a52abU),
                   bswap_32big(0x00bf4786U));
    r_rsip_func030();
    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000428U, 0x00000220U, 0x00000220U, 0x40400009U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0x12984d75U),
                   bswap_32big(0x42587c48U),
                   bswap_32big(0xbf2647b4U),
                   bswap_32big(0x8b1d11eeU));
    r_rsip_func034();
    WR1_PROG(REG_1404H, 0x12280000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000838U, 0x00000428U, 0x00000428U, 0x40400009U);
    WR1_PROG(REG_1404H, 0x1a600000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00109U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xdb481628U),
                   bswap_32big(0xf2a1716eU),
                   bswap_32big(0x0771b4d8U),
                   bswap_32big(0x480d085aU));
    r_rsip_func032();
    WR1_PROG(REG_1404H, 0x1a600000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00109U);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x89197d0cU),
                   bswap_32big(0x0524f41dU),
                   bswap_32big(0x729247c4U),
                   bswap_32big(0x1d9a7557U));
    r_rsip_func032();
    for (iLoop = 0; iLoop < 12; iLoop++)
    {
        WR1_PROG(REG_1404H, 0x18400000U);
        r_rsip_subfunc003(0x00c00201U);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x40400009U);
        r_rsip_subfunc009(bswap_32big(0x00003b02U));
        r_rsip_func101(bswap_32big(0xe4509f58U), bswap_32big(0xaa8100c7U), bswap_32big(0xb5dd4d2dU),
                       bswap_32big(0x8ccf6891U));
        r_rsip_func034();
        r_rsip_func101(bswap_32big(0xd25d51c1U), bswap_32big(0x9901e009U), bswap_32big(0x115e1949U),
                       bswap_32big(0xc88d925cU));
    }

    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000428U, 0x00000220U, 0x00000220U, 0x40400009U);
    r_rsip_subfunc009(bswap_32big(0x00003b03U));
    r_rsip_func101(bswap_32big(0x75fecb1bU),
                   bswap_32big(0x81874ad7U),
                   bswap_32big(0x606aca7aU),
                   bswap_32big(0x0ea4e5aaU));
    r_rsip_func034();
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000dc0U);
    WR1_PROG(REG_1404H, 0x10300000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000838U, 0x00000230U, 0x00000230U, 0x40400009U);
    WR1_PROG(REG_1404H, 0x14600000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x56ced87dU),
                   bswap_32big(0x25843486U),
                   bswap_32big(0x2644a979U),
                   bswap_32big(0xb61ee5a8U));
    r_rsip_func061();
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000660U, 0x00000a90U, 0x00000448U, 0x4040000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000448U, 0x4040000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x20f798a5U),
                   bswap_32big(0xd4a38ff3U),
                   bswap_32big(0x101e2762U),
                   bswap_32big(0x84f6292bU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7afb3174U), bswap_32big(0xfcc13fe0U), bswap_32big(0xdff88adbU),
                       bswap_32big(0xa172ad61U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000878U, 0x00000a90U, 0x00000448U, 0x40400009U);
    r_rsip_subfunc007(bswap_32big(0xbbbcf5b1U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00003b03U));
    r_rsip_func101(bswap_32big(0xd9dd9716U),
                   bswap_32big(0xc7c59989U),
                   bswap_32big(0x43843989U),
                   bswap_32big(0x83b4ef64U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x967dbdb4U),
                   bswap_32big(0x78dafa17U),
                   bswap_32big(0x325f249aU),
                   bswap_32big(0x2dd3ae47U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xf9926626U),
                   bswap_32big(0xc909765eU),
                   bswap_32big(0x283f09f4U),
                   bswap_32big(0xa6c45eceU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01490ab7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xee345443U),
                   bswap_32big(0x03dce08fU),
                   bswap_32big(0xe65a8b6eU),
                   bswap_32big(0x8bb90bceU));
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
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x14600000U);
    for (iLoop = 0; iLoop < 128; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xd1dd4a62U), bswap_32big(0xf47fd358U), bswap_32big(0x6d469099U),
                       bswap_32big(0xae6f574eU));
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
        r_rsip_func101(bswap_32big(0xf50e7f5fU), bswap_32big(0xf2d15818U), bswap_32big(0x35518ceeU),
                       bswap_32big(0xa6cf04d5U));
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
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12480000U);
    for (iLoop = 0; iLoop < 128; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x3c8989d7U), bswap_32big(0x46f5c548U), bswap_32big(0xa0bdeda3U),
                       bswap_32big(0xcc77d372U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 132]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 133]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 134]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 135]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xbfbaec79U), bswap_32big(0x93e6ff91U), bswap_32big(0x75c46208U),
                       bswap_32big(0x1d112607U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x82129126U),
                   bswap_32big(0x88e342f8U),
                   bswap_32big(0x1157616cU),
                   bswap_32big(0x0c5770a3U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[260]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[261]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[262]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[263]);
    r_rsip_func100(bswap_32big(0x01ed0431U),
                   bswap_32big(0x7843f3c6U),
                   bswap_32big(0x9e804edfU),
                   bswap_32big(0x4a653170U));
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
    r_rsip_func100(bswap_32big(0xf958bf09U),
                   bswap_32big(0x2940d6acU),
                   bswap_32big(0xd7476f27U),
                   bswap_32big(0x5a67755aU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x312933b7U),
                   bswap_32big(0x56728eaeU),
                   bswap_32big(0x1237d56aU),
                   bswap_32big(0x1b4acc13U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0106cf89U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x8fffa798U),
                   bswap_32big(0x20e53cafU),
                   bswap_32big(0xbdce3fb5U),
                   bswap_32big(0xfe2b381cU));
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
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x14600000U);
    for (iLoop = 0; iLoop < 128; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x55ba8decU), bswap_32big(0x91733833U), bswap_32big(0x154004d0U),
                       bswap_32big(0xf5c81df3U));
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
        r_rsip_func101(bswap_32big(0xb006df65U), bswap_32big(0x39f326d8U), bswap_32big(0x559ebebdU),
                       bswap_32big(0xce3d57bfU));
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
    r_rsip_func100(bswap_32big(0xb187e57fU),
                   bswap_32big(0x27f199daU),
                   bswap_32big(0xfa987375U),
                   bswap_32big(0x51cd7d5aU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008104U);
    WR1_PROG(REG_1608H, 0x81010280U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[132]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[133]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[134]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[135]);
    r_rsip_func100(bswap_32big(0xed2efbe8U),
                   bswap_32big(0x1b057985U),
                   bswap_32big(0x3d3d1e79U),
                   bswap_32big(0x6f83eda9U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c100104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[136]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[137]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[138]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[139]);
    r_rsip_func100(bswap_32big(0xf440ed87U),
                   bswap_32big(0x82d0f8e5U),
                   bswap_32big(0x156dfc3aU),
                   bswap_32big(0x6701b779U));
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
    r_rsip_func102(bswap_32big(0x6ca5ee69U),
                   bswap_32big(0x3868a42fU),
                   bswap_32big(0x3e7af31dU),
                   bswap_32big(0x2fd30f88U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
