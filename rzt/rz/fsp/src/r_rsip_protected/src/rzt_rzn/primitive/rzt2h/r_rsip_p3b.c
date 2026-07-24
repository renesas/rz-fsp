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
        r_rsip_func100(bswap_32big(0x1f12d850U), bswap_32big(0x3e11cb35U), bswap_32big(0x2cb2a6b1U),
                       bswap_32big(0xc6960794U));
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
            r_rsip_func100(bswap_32big(0xe5b6c30eU), bswap_32big(0x059eb819U), bswap_32big(0xe35636c0U),
                           bswap_32big(0x55a186a9U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x34163443U), bswap_32big(0x05eb42caU), bswap_32big(0x35ead0abU),
                           bswap_32big(0x926193feU));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x11ea36e5U), bswap_32big(0xd404c1c4U), bswap_32big(0x5b9a9a41U),
                       bswap_32big(0x0e97a497U));
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
        r_rsip_func100(bswap_32big(0xb02f48d1U), bswap_32big(0x5402e186U), bswap_32big(0xf5711203U),
                       bswap_32big(0x86ab500dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xd8e57d4cU), bswap_32big(0x50386bc4U), bswap_32big(0xb770f3deU),
                           bswap_32big(0x5b1682bfU));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0x14b06872U), bswap_32big(0xdcf0fdacU), bswap_32big(0x98b4cb25U),
                           bswap_32big(0x8111ad0aU));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xed3d51cdU), bswap_32big(0x7a150ae6U), bswap_32big(0x64f78535U),
                       bswap_32big(0x9e8350afU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x95a22a74U), bswap_32big(0xf36410e4U), bswap_32big(0x5688ccf6U),
                           bswap_32big(0x9af83c6fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x2020000aU);
                r_rsip_func101(bswap_32big(0xa0139aacU),
                               bswap_32big(0x7e50618eU),
                               bswap_32big(0xae6d3aefU),
                               bswap_32big(0x4df0663dU));
            }
            else
            {
                r_rsip_func101(bswap_32big(0x0df3eee7U),
                               bswap_32big(0xc9a7d7bfU),
                               bswap_32big(0xadf8bd18U),
                               bswap_32big(0xff90d815U));
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
            r_rsip_func100(bswap_32big(0xfabe3c6eU), bswap_32big(0x97bf2870U), bswap_32big(0xf85762e6U),
                           bswap_32big(0x440182ceU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0xf9f898a1U),
                               bswap_32big(0x1cf1e418U),
                               bswap_32big(0xf00b8ba4U),
                               bswap_32big(0x71749210U));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x2d28f482U),
                               bswap_32big(0x0a77de5bU),
                               bswap_32big(0x0afed810U),
                               bswap_32big(0x4306d403U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x06858ad8U), bswap_32big(0x19b43082U), bswap_32big(0xe1e15d5cU),
                           bswap_32big(0x952ea5a4U));
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
            WR1_PROG(REG_1404H, 0x15300000U);
            r_rsip_subfunc003(0x00c000fdU);
            r_rsip_subfunc003(0x00c90005U);
            r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x20200010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x20200004U);
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
            r_rsip_func100(bswap_32big(0x8b3abf86U), bswap_32big(0xda9b1ebbU), bswap_32big(0xf7330bd4U),
                           bswap_32big(0xa9b4f618U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x1d528340U),
                               bswap_32big(0xb77b907fU),
                               bswap_32big(0x17ca289eU),
                               bswap_32big(0x8c7ea8deU));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x89e3ce48U),
                               bswap_32big(0xa2833b6fU),
                               bswap_32big(0x023710e1U),
                               bswap_32big(0xe7c6a361U));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x1f6f73f3U), bswap_32big(0xb9d1d06eU), bswap_32big(0x82346882U),
                       bswap_32big(0x64f96ceeU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xf57ac91dU), bswap_32big(0xf92b03b6U), bswap_32big(0xcc96ddd3U),
                           bswap_32big(0x651878eaU));
            continue;
        }

        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_subfunc003(0x00c00101U);
        r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000428U, 0x20200009U);
        r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x2020000aU);
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
        r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x20200004U);
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
        r_rsip_func100(bswap_32big(0x0e6c0ebcU), bswap_32big(0xee02ff31U), bswap_32big(0xc4a8b226U),
                       bswap_32big(0x7bbcaf16U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xac4460ecU), bswap_32big(0xa66a8466U), bswap_32big(0xdf7068acU),
                           bswap_32big(0x82569699U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0xe1a560a3U), bswap_32big(0x82e1dbcfU), bswap_32big(0x04c97981U),
                           bswap_32big(0x8a3b82e2U));
            WR1_PROG(REG_1404H, 0x17380000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c000fdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x20200010U);
            r_rsip_subfunc005(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x20200000U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xca991528U), bswap_32big(0x797befdaU), bswap_32big(0x5288290dU),
                           bswap_32big(0x6f6c6de5U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0xe95b224bU),
                               bswap_32big(0x5616f1ddU),
                               bswap_32big(0x8651c693U),
                               bswap_32big(0x245c2321U));
                continue;
            }

            r_rsip_func100(bswap_32big(0xedc9b13cU), bswap_32big(0x57d0948bU), bswap_32big(0x2dbaa021U),
                           bswap_32big(0x37e0af10U));
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
                r_rsip_func101(bswap_32big(0xecc43319U),
                               bswap_32big(0x26ba7752U),
                               bswap_32big(0x3e10a679U),
                               bswap_32big(0xbd08ac26U));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x1f2fb95fU), bswap_32big(0x19f45973U), bswap_32big(0x334e57b5U),
                           bswap_32big(0xcff512f1U));
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
                    r_rsip_func100(bswap_32big(0x4bf74592U),
                                   bswap_32big(0xd197a0edU),
                                   bswap_32big(0x20b7d4d0U),
                                   bswap_32big(0xe6fbfa2fU));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x5e85bf0fU),
                                   bswap_32big(0x8891ac46U),
                                   bswap_32big(0x97f3d479U),
                                   bswap_32big(0x4154e3f2U));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x5e3f3901U),
                               bswap_32big(0xf2c19c75U),
                               bswap_32big(0xd0cc2a2cU),
                               bswap_32big(0x6c50c3daU));
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
                r_rsip_subfunc002(0x00000838U, 0x00000a40U, 0x20200004U);
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
                r_rsip_subfunc005(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x20200000U, 0x00020000U);
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
                r_rsip_func100(bswap_32big(0xeb8827b9U),
                               bswap_32big(0x1ca6f2e9U),
                               bswap_32big(0xda284858U),
                               bswap_32big(0x06030e61U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xc0708accU),
                                   bswap_32big(0x309960dcU),
                                   bswap_32big(0xf6ae2b2bU),
                                   bswap_32big(0xe0ba5ebdU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xb3829e64U),
                                   bswap_32big(0x3b619e20U),
                                   bswap_32big(0xfdca0261U),
                                   bswap_32big(0x37ebc331U));
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
                        r_rsip_func100(bswap_32big(0x8602e3eeU),
                                       bswap_32big(0xe7237687U),
                                       bswap_32big(0xa1a93f89U),
                                       bswap_32big(0xbf8d47f9U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0xd0db0c48U),
                                           bswap_32big(0xde7ed138U),
                                           bswap_32big(0x57498ee1U),
                                           bswap_32big(0x766da20aU));
                            break;
                        }
                        else
                        {
                            r_rsip_func100(bswap_32big(0x9815f182U),
                                           bswap_32big(0xd4a1d2faU),
                                           bswap_32big(0xcb1fc887U),
                                           bswap_32big(0xc9c159cfU));
                            WR1_PROG(REG_1404H, 0x19400000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                            r_rsip_subfunc003(0x00c000fdU);
                            r_rsip_subfunc003(0x00c20005U);
                            r_rsip_subfunc003(0x0002000dU);
                            r_rsip_subfunc005(0x00000838U,
                                              0x00000a40U,
                                              0x00000428U,
                                              0x00000220U,
                                              0x20200000U,
                                              0x00020000U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000838U, 0x20200009U);
                            r_rsip_func101(bswap_32big(0x761e109cU),
                                           bswap_32big(0xb8e9782bU),
                                           bswap_32big(0x275a7df1U),
                                           bswap_32big(0xee73d648U));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x9aee6ffdU),
                                   bswap_32big(0xa7c4fb41U),
                                   bswap_32big(0xaf379df1U),
                                   bswap_32big(0x1244a1c0U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0x01fe60e2U),
                                       bswap_32big(0x09809a17U),
                                       bswap_32big(0x09083f30U),
                                       bswap_32big(0xa557f4d0U));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0xb13c43adU),
                                       bswap_32big(0xf7e9fe95U),
                                       bswap_32big(0xf73c93baU),
                                       bswap_32big(0x0c798709U));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0xf45c1feaU), bswap_32big(0x31d39ca9U), bswap_32big(0x2d06ae07U),
                           bswap_32big(0xe231d287U));
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
                r_rsip_func100(bswap_32big(0x858d7b1cU),
                               bswap_32big(0x6f88bc68U),
                               bswap_32big(0xfc7303c6U),
                               bswap_32big(0xaf8d1b08U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x39fbbf08U),
                                   bswap_32big(0xd5a878d6U),
                                   bswap_32big(0xccf35544U),
                                   bswap_32big(0x63132b80U));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x20200009U);
                    r_rsip_func101(bswap_32big(0xced2d700U),
                                   bswap_32big(0x0f42ade9U),
                                   bswap_32big(0xb7e452deU),
                                   bswap_32big(0x401b1c9aU));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0xff5701b4U),
                               bswap_32big(0x8371f054U),
                               bswap_32big(0x3c485eb3U),
                               bswap_32big(0x897b519eU));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x1dfcf1b5U),
                   bswap_32big(0x7664d26eU),
                   bswap_32big(0x63916097U),
                   bswap_32big(0x4029296dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x57d62eddU), bswap_32big(0x659b5b84U), bswap_32big(0xccbdf342U),
                       bswap_32big(0x4cb3c717U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x20200009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000738U, 0x20200009U);
    r_rsip_func100(bswap_32big(0x0a585d99U),
                   bswap_32big(0x71079fb9U),
                   bswap_32big(0x4a96fec8U),
                   bswap_32big(0xb628ed2aU));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x2ace5a86U),
                   bswap_32big(0x66851ef1U),
                   bswap_32big(0x6960913eU),
                   bswap_32big(0x9182c487U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0x273c3408U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x16380000U, 0x00000080U, bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0x45cb7cf1U),
                   bswap_32big(0xb6dd2ca1U),
                   bswap_32big(0x50808c39U),
                   bswap_32big(0x84a9a49bU));
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
    r_rsip_func101(bswap_32big(0xc6339204U),
                   bswap_32big(0x02214dbbU),
                   bswap_32big(0x28f60127U),
                   bswap_32big(0xdaa14246U));
    r_rsip_func054();
    WR1_PROG(REG_1404H, 0x19400000U);
    r_rsip_subfunc003(0x00c00101U);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000660U, 0x20200009U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000dc0U);
    WR1_PROG(REG_1404H, 0x14500000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0x273c3408U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x16780000U, 0x00000080U, bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xba137e4fU),
                   bswap_32big(0x4b4d5ceaU),
                   bswap_32big(0xe08d3f66U),
                   bswap_32big(0xaa8accd1U));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000778U, 0x00000878U, 0x00000230U, 0x20200007U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0x01327ea3U),
                   bswap_32big(0x745c283bU),
                   bswap_32big(0xf33714d7U),
                   bswap_32big(0x7e468c66U));
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
    r_rsip_func100(bswap_32big(0x640f76aeU),
                   bswap_32big(0x85a3207eU),
                   bswap_32big(0xc5e507f5U),
                   bswap_32big(0xddcc8f78U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x7a27dbc1U), bswap_32big(0x6d8ae810U), bswap_32big(0x792ae58aU),
                       bswap_32big(0xd87955aaU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0x273c3408U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x12480000U, 0x00000080U, bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x57d8659fU),
                   bswap_32big(0xa2d5b625U),
                   bswap_32big(0xd7b73399U),
                   bswap_32big(0xff8fffbcU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x00000348U, 0x00000448U, 0x00000660U, 0x20200007U);
    r_rsip_subfunc007(bswap_32big(0x273c3408U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x9116ce5dU),
                   bswap_32big(0x7d38ed19U),
                   bswap_32big(0xf6775ce1U),
                   bswap_32big(0x129e8414U));
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
    r_rsip_subfunc006(0x00000018U, 0x00000660U, 0x40400010U);
    WR1_PROG(REG_1014H, 0x00000448U);
    WR1_PROG(REG_1018H, 0x00000878U);
    r_rsip_subfunc002(0x00000660U, 0x00000448U, 0x40400002U);
    r_rsip_subfunc002(0x00000660U, 0x00000230U, 0x40400003U);
    WR1_PROG(REG_1014H, 0x00000448U);
    WR1_PROG(REG_1018H, 0x00000230U);
    r_rsip_subfunc002(0x00000660U, 0x00000230U, 0x40400002U);
    WR1_PROG(REG_1404H, 0x14600000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x42413234U),
                   bswap_32big(0xf6016a18U),
                   bswap_32big(0x1d053da2U),
                   bswap_32big(0x7bc1eb0cU));
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
    r_rsip_func100(bswap_32big(0xac232390U),
                   bswap_32big(0x47a88573U),
                   bswap_32big(0x02bb91e6U),
                   bswap_32big(0xbe1ce8eeU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x9f84acf9U), bswap_32big(0xc7ec3fa1U), bswap_32big(0xc53ac5f0U),
                       bswap_32big(0x58a63f14U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00201U);
    r_rsip_subfunc001(0x00000878U, 0x00000a90U, 0x00000448U, 0x40400009U);
    r_rsip_subfunc007(bswap_32big(0x273c3408U));
    OFS_ADR = 808;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00003b03U));
    r_rsip_func101(bswap_32big(0x16a454f7U),
                   bswap_32big(0x206e29fdU),
                   bswap_32big(0xbbc3b71dU),
                   bswap_32big(0xbe0218c2U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xfa86bf3cU),
                   bswap_32big(0xc00287e8U),
                   bswap_32big(0x0bddb1edU),
                   bswap_32big(0xba9b543dU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xa628a1a0U),
                   bswap_32big(0xa683561eU),
                   bswap_32big(0x830553caU),
                   bswap_32big(0x3aba5957U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01b9c56bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003b01U));
    r_rsip_func101(bswap_32big(0xff53a2e0U),
                   bswap_32big(0x3869d3b2U),
                   bswap_32big(0xbebc8ccbU),
                   bswap_32big(0x9cdc1a84U));
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
        r_rsip_func100(bswap_32big(0x12046a22U), bswap_32big(0x6a34ac69U), bswap_32big(0x4c253867U),
                       bswap_32big(0x65cca0b5U));
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
        r_rsip_func101(bswap_32big(0x61fc5cacU), bswap_32big(0xf46c7017U), bswap_32big(0x83c12bb8U),
                       bswap_32big(0xb04d603bU));
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
        r_rsip_func100(bswap_32big(0x845da2e1U), bswap_32big(0x255bf831U), bswap_32big(0x02a5586aU),
                       bswap_32big(0x80feaa5cU));
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
        r_rsip_func101(bswap_32big(0x3a2df544U), bswap_32big(0x947ebc6eU), bswap_32big(0xe963107cU),
                       bswap_32big(0x073145b4U));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x15888952U),
                   bswap_32big(0x27af3395U),
                   bswap_32big(0x3122c03bU),
                   bswap_32big(0x74d2ab47U));
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
    r_rsip_func100(bswap_32big(0xe9311761U),
                   bswap_32big(0x0a86db97U),
                   bswap_32big(0xe5ea2d5eU),
                   bswap_32big(0x38f9e075U));
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
    r_rsip_func100(bswap_32big(0x6b729658U),
                   bswap_32big(0xe88b6147U),
                   bswap_32big(0xf7aa5303U),
                   bswap_32big(0xbc8fc0a7U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0x6bb4deeeU),
                   bswap_32big(0xbf6e4b8aU),
                   bswap_32big(0xdb333acaU),
                   bswap_32big(0x7820004fU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01c88721U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00003b02U));
    r_rsip_func101(bswap_32big(0xc0b304a3U),
                   bswap_32big(0x648abc78U),
                   bswap_32big(0xed79b809U),
                   bswap_32big(0x4d00d3adU));
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
        r_rsip_func100(bswap_32big(0x6b844af4U), bswap_32big(0xf6219dfeU), bswap_32big(0xcef7220fU),
                       bswap_32big(0x6a09c538U));
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
        r_rsip_func101(bswap_32big(0x40308dccU), bswap_32big(0x7db20e5bU), bswap_32big(0x26e55979U),
                       bswap_32big(0x5e8ab671U));
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
    r_rsip_func100(bswap_32big(0xbd3bd7afU),
                   bswap_32big(0x9ae1dba1U),
                   bswap_32big(0x86bbde92U),
                   bswap_32big(0x0e1d327dU));
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
    r_rsip_func100(bswap_32big(0x82487885U),
                   bswap_32big(0xab54b8fdU),
                   bswap_32big(0xf1faf86dU),
                   bswap_32big(0xeaa63544U));
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
    r_rsip_func100(bswap_32big(0x1d2e8ea1U),
                   bswap_32big(0x86ec5632U),
                   bswap_32big(0xbff5664eU),
                   bswap_32big(0xd652b985U));
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
    r_rsip_func102(bswap_32big(0x6b83b6afU),
                   bswap_32big(0xfda4c3c2U),
                   bswap_32big(0xd6623be1U),
                   bswap_32big(0xcb037be0U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
