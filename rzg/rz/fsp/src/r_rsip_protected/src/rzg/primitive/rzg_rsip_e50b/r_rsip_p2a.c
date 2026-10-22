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

rsip_ret_t r_rsip_p2a (uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x002a0002U);
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
        r_rsip_func100(bswap_32big(0xddcc65d7U), bswap_32big(0x78933ae3U), bswap_32big(0xb8050213U),
                       bswap_32big(0xd660fe39U));
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
        WR1_PROG(REG_1404H, 0x11e00000U);
        r_rsip_subfunc003(0x00c90011U);
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x000008e7U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1600H, 0x34202886U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x2000d0e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c07U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x3d1512fcU), bswap_32big(0x25a52208U), bswap_32big(0xe66db66aU),
                           bswap_32big(0x1b47bbc2U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20011U);
            WR1_PROG(REG_1600H, 0x00002485U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x4c79d844U), bswap_32big(0xf2d69a38U), bswap_32big(0x83415d4dU),
                           bswap_32big(0x44e41cd4U));
        }

        WR1_PROG(REG_1600H, 0x38000886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xff564c85U), bswap_32big(0xc0197327U), bswap_32big(0xc13c8598U),
                       bswap_32big(0xca0f5cf3U));
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
        WR1_PROG(REG_1444H, 0x00000fb0U);
        WR1_PROG(REG_0A00H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0A04H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A08H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A0CH, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A10H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A14H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A18H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A1CH, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A20H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A24H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A28H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0A2CH, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0A30H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0A34H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0A38H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0A3CH, bswap_32big(0x851EB80EU));
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xb95d69e3U), bswap_32big(0x6c8476a6U), bswap_32big(0x98626899U),
                       bswap_32big(0x4263a473U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x54664258U), bswap_32big(0xd19f8754U), bswap_32big(0x446c5061U),
                           bswap_32big(0x1b149ebeU));
            continue;
        }
        else
        {
            r_rsip_func101(bswap_32big(0x2220dd38U), bswap_32big(0x1913c930U), bswap_32big(0x9b8795b9U),
                           bswap_32big(0xe60c39f5U));
        }

        WR1_PROG(REG_1600H, 0x38008a20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x574f66e8U), bswap_32big(0x8444dd23U), bswap_32big(0x6a8716c3U),
                       bswap_32big(0x7404a70eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000320U, 0x00000220U, 0x00000630U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0x0f290183U), bswap_32big(0xb0762326U), bswap_32big(0x34ccd43fU),
                           bswap_32big(0xbf5e9110U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000220U, 0x00000320U, 0x00000630U, 0x0808000aU);
                r_rsip_func101(bswap_32big(0x73fa9fa2U),
                               bswap_32big(0xa3bc01acU),
                               bswap_32big(0x8ad98d2aU),
                               bswap_32big(0x1f908ae0U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0x072b2decU),
                               bswap_32big(0x5b8aa6dbU),
                               bswap_32big(0xcdec9406U),
                               bswap_32big(0xfdf4e336U));
            }

            WR1_PROG(REG_1404H, 0x1a000000U);
            WR1_PROG(REG_1444H, 0x000003a2U);
            WR1_PROG(REG_1A24H, 0x08000105U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1420H, bswap_32big(0x10000000U));
            r_rsip_subfunc003(0x00c20011U);
            r_rsip_subfunc003(0x00c00031U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xc2775bfdU), bswap_32big(0x95c10be0U), bswap_32big(0x7ce42e0fU),
                           bswap_32big(0x1964db03U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x6d1b339cU),
                               bswap_32big(0x495a1446U),
                               bswap_32big(0xdf63cc76U),
                               bswap_32big(0x54f493e1U));
                continue;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x70de1275U),
                               bswap_32big(0x786bb6faU),
                               bswap_32big(0x7b795fe3U),
                               bswap_32big(0x257f662dU));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x86910df6U), bswap_32big(0xc7c8dd03U), bswap_32big(0x8bfc2f24U),
                           bswap_32big(0xdd01bca3U));
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
            WR1_PROG(REG_1404H, 0x15f00000U);
            r_rsip_subfunc003(0x00c0003dU);
            r_rsip_subfunc003(0x00c90005U);
            r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x08080010U);
            WR1_PROG(REG_1014H, 0x00000220U);
            r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x08080004U);
            WR1_PROG(REG_1404H, 0x1a000000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0003dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xab2e4408U), bswap_32big(0x6261b3ddU), bswap_32big(0x4a8e5277U),
                           bswap_32big(0x2d4579cdU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x0000d140U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x38d7a459U),
                               bswap_32big(0xfae835b7U),
                               bswap_32big(0xbcf67c0aU),
                               bswap_32big(0x4b4cdcc4U));
                break;
            }
            else
            {
                r_rsip_func101(bswap_32big(0x7956ccefU),
                               bswap_32big(0xcb88293eU),
                               bswap_32big(0x111daa4aU),
                               bswap_32big(0x21b13b06U));
            }
        }

        WR1_PROG(REG_1600H, 0x38008940U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x45b9a471U), bswap_32big(0xe6640f5cU), bswap_32big(0xbcf458d9U),
                       bswap_32big(0x5d393b70U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x9811ee9aU), bswap_32big(0x33884548U), bswap_32big(0xb2fda213U),
                           bswap_32big(0xdb53f304U));
            continue;
        }

        WR1_PROG(REG_1404H, 0x18f80000U);
        r_rsip_subfunc003(0x00c00041U);
        r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000428U, 0x08080009U);
        r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x0808000aU);
        WR1_PROG(REG_1404H, 0x15f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x08080010U);
        WR1_PROG(REG_1014H, 0x00000220U);
        r_rsip_subfunc002(0x00000630U, 0x00000838U, 0x08080004U);
        WR1_PROG(REG_1404H, 0x1a000000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000630U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x195ab346U), bswap_32big(0xdee0ac74U), bswap_32big(0x3f7db51dU),
                       bswap_32big(0x393e3fe9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x0b76a855U), bswap_32big(0xe3f83daaU), bswap_32big(0x09ed29d7U),
                           bswap_32big(0x301f5be4U));
        }
        else
        {
            r_rsip_func100(bswap_32big(0x60bc7695U), bswap_32big(0x82165dc8U), bswap_32big(0xb99e3c07U),
                           bswap_32big(0x49581953U));
            WR1_PROG(REG_1404H, 0x17f80000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0003dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x08080010U);
            r_rsip_subfunc005(0x00000838U, 0x00000220U, 0x00000428U, 0x00000630U, 0x08080000U, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xe76b1864U), bswap_32big(0x1744392bU), bswap_32big(0xe6dcd5f4U),
                           bswap_32big(0x6cfd9408U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func101(bswap_32big(0x70872f48U),
                               bswap_32big(0x8b4ed3c4U),
                               bswap_32big(0x2aec7580U),
                               bswap_32big(0xb8b6e373U));
                continue;
            }

            r_rsip_func100(bswap_32big(0x378a6ad7U), bswap_32big(0x4bfb3be7U), bswap_32big(0x051b6be8U),
                           bswap_32big(0xe61a9db3U));
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000006U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8090000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x11e00000U);
            r_rsip_subfunc003(0x03430041U);
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000908U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000003cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
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
            WR1_PROG(REG_1404H, 0x15f00000U);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x8190000aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90041U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                r_rsip_subfunc004(0x00000630U, 0x00000838U, 0x0808000cU);
                r_rsip_subfunc001(0x00000838U, 0x00000938U, 0x00000630U, 0x08080009U);
                WR1_PROG(REG_1600H, 0x000033e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x2b88ff75U),
                               bswap_32big(0xe07ce039U),
                               bswap_32big(0x6fb90951U),
                               bswap_32big(0x84395759U));
            }

            WR1_PROG(REG_1600H, 0x00007c1fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xd873c2f6U), bswap_32big(0x300326c6U), bswap_32big(0x7d5c844aU),
                           bswap_32big(0x405b3bbdU));
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
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x11e00000U);
                for (jLoop = 0; jLoop < 16; jLoop = jLoop + 4)
                {
                    WR1_PROG(REG_1600H, 0x34202886U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d0e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c07U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xff006ef4U),
                                   bswap_32big(0x75178786U),
                                   bswap_32big(0xc4412e56U),
                                   bswap_32big(0x5cbc4f9eU));
                    r_rsip_func103();
                    WR1_PROG(REG_1444H, 0x000000a2U);
                    WR1_PROG(REG_1A24H, 0x0c200104U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_subfunc003(0x00c20011U);
                    WR1_PROG(REG_1600H, 0x00002485U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x57bae2e5U),
                                   bswap_32big(0x2d0a821cU),
                                   bswap_32big(0x1a221e73U),
                                   bswap_32big(0x28cc65ddU));
                }

                WR1_PROG(REG_1600H, 0x38000886U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x9055a84bU),
                               bswap_32big(0x9d0c2bd5U),
                               bswap_32big(0x25db4297U),
                               bswap_32big(0x99c41714U));
                WR1_PROG(REG_1404H, 0x1a000000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000004U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x0808000aU);
                r_rsip_subfunc006(0x00000018U, 0x00000838U, 0x08080010U);
                WR1_PROG(REG_1014H, 0x00000220U);
                r_rsip_subfunc002(0x00000838U, 0x00000a40U, 0x08080004U);
                WR1_PROG(REG_1404H, 0x17f80000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc006(0x00000018U, 0x00000428U, 0x08080010U);
                r_rsip_subfunc005(0x00000220U, 0x00000630U, 0x00000428U, 0x00000838U, 0x08080000U, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1404H, 0x1a000000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0003dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x0808000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0xab473e3bU),
                               bswap_32big(0x9b1672faU),
                               bswap_32big(0x745cfb84U),
                               bswap_32big(0xf91ee329U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 0U))
                {
                    WR1_PROG(REG_1600H, 0x00002e40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xda182eb4U),
                                   bswap_32big(0x59e0b180U),
                                   bswap_32big(0xb794b310U),
                                   bswap_32big(0x2a8efdfcU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x0000094aU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xad9ba580U),
                                   bswap_32big(0x50e4e8e2U),
                                   bswap_32big(0xfc157936U),
                                   bswap_32big(0xef168b81U));
                    WR1_PROG(REG_1608H, 0x81010120U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x00005006U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[1]);
                    WR1_PROG(REG_1600H, 0x000037e9U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (jLoop = 0; jLoop < S_RAM[0 + 1]; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_1404H, 0x1a000000U);
                        WR1_PROG(REG_1608H, 0x8190000aU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00c90041U);
                        r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000220U, 0x0808000aU);
                        WR1_PROG(REG_143CH, 0x00210000U);
                        r_rsip_func100(bswap_32big(0x06dff42fU),
                                       bswap_32big(0xe286a4ecU),
                                       bswap_32big(0x068b4bb3U),
                                       bswap_32big(0x4a2de11eU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 0U))
                        {
                            WR1_PROG(REG_1600H, 0x00002e40U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_func101(bswap_32big(0x85f92da9U),
                                           bswap_32big(0x8c3594a5U),
                                           bswap_32big(0x34a27526U),
                                           bswap_32big(0xbb7f8a0eU));
                            break;
                        }
                        else
                        {
                            r_rsip_func100(bswap_32big(0x05681f14U),
                                           bswap_32big(0x99ab5ca1U),
                                           bswap_32big(0xb1312905U),
                                           bswap_32big(0xbf51897bU));
                            WR1_PROG(REG_1404H, 0x1a000000U);
                            WR1_PROG(REG_1444H, 0x000000a2U);
                            WR1_PROG(REG_1A24H, 0x08000104U);
                            WAIT_STS(REG_1444H, 31U, 1U);
                            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
                            r_rsip_subfunc003(0x00c0003dU);
                            r_rsip_subfunc003(0x00c20005U);
                            r_rsip_subfunc003(0x0002000dU);
                            r_rsip_subfunc005(0x00000838U,
                                              0x00000a40U,
                                              0x00000428U,
                                              0x00000220U,
                                              0x08080000U,
                                              0x00020000U);
                            WR1_PROG(REG_143CH, 0x00000d00U);
                            r_rsip_subfunc001(0x00000220U, 0x00000938U, 0x00000838U, 0x08080009U);
                            r_rsip_func101(bswap_32big(0xdea344dcU),
                                           bswap_32big(0xfda1a51eU),
                                           bswap_32big(0xbd866c26U),
                                           bswap_32big(0x51042883U));
                        }
                    }

                    WR1_PROG(REG_1600H, 0x38008a40U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0xeb21724cU),
                                   bswap_32big(0xef4c6733U),
                                   bswap_32big(0xbd25c93bU),
                                   bswap_32big(0x00efbd8cU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_func101(bswap_32big(0x1e21e4e0U),
                                       bswap_32big(0xec6ca9a9U),
                                       bswap_32big(0x9470581dU),
                                       bswap_32big(0xfd8f133bU));
                        break;
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x8cb6e8b5U),
                                       bswap_32big(0x9e035d57U),
                                       bswap_32big(0xa6d12518U),
                                       bswap_32big(0xffdd31aeU));
                    }
                }
            }

            WR1_PROG(REG_1600H, 0x38000a4bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0xedde3841U), bswap_32big(0x6d6f25bdU), bswap_32big(0xb5fc5c54U),
                           bswap_32big(0x4a7cf565U));
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
                r_rsip_func100(bswap_32big(0xd5220972U),
                               bswap_32big(0x80c461aeU),
                               bswap_32big(0x9ae3be86U),
                               bswap_32big(0x0a636c35U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func101(bswap_32big(0x7275f015U),
                                   bswap_32big(0xcac355e9U),
                                   bswap_32big(0x58258a6cU),
                                   bswap_32big(0x992fbc12U));
                    break;
                }
                else
                {
                    r_rsip_subfunc001(0x00000428U, 0x00000938U, 0x00000320U, 0x08080009U);
                    r_rsip_func101(bswap_32big(0xbf89c70bU),
                                   bswap_32big(0xc9da7898U),
                                   bswap_32big(0x68ab04c7U),
                                   bswap_32big(0x39a2fa6aU));
                }
            }
            else
            {
                r_rsip_func101(bswap_32big(0xc2437d69U),
                               bswap_32big(0x0e8511d9U),
                               bswap_32big(0x211ce68fU),
                               bswap_32big(0x15313cdeU));
            }
        }
    }

    WR1_PROG(REG_1600H, 0x38008a20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x0443a17cU),
                   bswap_32big(0x5213df24U),
                   bswap_32big(0xdefc98c1U),
                   bswap_32big(0x182b5292U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x34ca139bU), bswap_32big(0x630ffa9aU), bswap_32big(0x88efb8f9U),
                       bswap_32big(0x90b7be98U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x1a000000U);
    r_rsip_subfunc003(0x00c00041U);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000838U, 0x08080009U);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x000007f8U, 0x08080009U);
    r_rsip_func100(bswap_32big(0x56a2dd7aU),
                   bswap_32big(0x83643f5eU),
                   bswap_32big(0xe9216c7aU),
                   bswap_32big(0xfd9447a3U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x62a92e4dU),
                   bswap_32big(0x2b889d8dU),
                   bswap_32big(0x3dedd90bU),
                   bswap_32big(0x8a7a3b04U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c2000c4U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WAIT_STS(REG_1A28H, 6U, 0U);
    WR1_PROG(REG_143CH, 0x00000900U);
    r_rsip_subfunc007(bswap_32big(0xac1cd394U));
    OFS_ADR = 196;
    r_rsip_subfunc008(0x17b80000U, 0x00000020U, bswap_32big(0x00002a01U));
    r_rsip_func101(bswap_32big(0x817a3bb4U),
                   bswap_32big(0x6acb54ecU),
                   bswap_32big(0xa92c852aU),
                   bswap_32big(0x305ca0acU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000320U, 0x00000a40U, 0x00000220U, 0x0808000aU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000630U, 0x0808000aU);
    r_rsip_subfunc009(bswap_32big(0x0000002aU));
    r_rsip_func101(bswap_32big(0xd8c60f1bU),
                   bswap_32big(0x1d1a1773U),
                   bswap_32big(0x1ca5d0ecU),
                   bswap_32big(0x62633ba7U));
    r_rsip_func050();
    WR1_PROG(REG_1404H, 0x15a00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0xac1cd394U));
    OFS_ADR = 196;
    r_rsip_subfunc008(0x17b80000U, 0x00000020U, bswap_32big(0x00002a01U));
    r_rsip_func101(bswap_32big(0xd0f44050U),
                   bswap_32big(0x33523a1eU),
                   bswap_32big(0x7e295998U),
                   bswap_32big(0xc8709a62U));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x000007f8U, 0x00000838U, 0x00000220U, 0x08080007U);
    r_rsip_subfunc009(bswap_32big(0x00002a01U));
    r_rsip_func101(bswap_32big(0x0a2ce8fbU),
                   bswap_32big(0x68133d35U),
                   bswap_32big(0x81b1f10bU),
                   bswap_32big(0xe35ab918U));
    r_rsip_func052();
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000428U, 0x1010000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000428U, 0x1010000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0x9e522c1fU),
                   bswap_32big(0xff288dbeU),
                   bswap_32big(0x0189b699U),
                   bswap_32big(0x6162b6dfU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x74af5ad3U), bswap_32big(0x48a62de0U), bswap_32big(0xb14b7f73U),
                       bswap_32big(0x0c150db9U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    r_rsip_subfunc007(bswap_32big(0xac1cd394U));
    OFS_ADR = 196;
    r_rsip_subfunc008(0x13a80000U, 0x00000020U, bswap_32big(0x00002a02U));
    r_rsip_func101(bswap_32big(0x4935e000U),
                   bswap_32big(0xe9db7463U),
                   bswap_32big(0x1cd8b016U),
                   bswap_32big(0x5502bf4dU));
    r_rsip_func017(OFS_ADR);
    r_rsip_subfunc001(0x000003e8U, 0x00000428U, 0x00000630U, 0x08080007U);
    r_rsip_subfunc007(bswap_32big(0xac1cd394U));
    OFS_ADR = 196;
    r_rsip_subfunc008(0x15b00000U, 0x00000020U, bswap_32big(0x00002a02U));
    r_rsip_func101(bswap_32big(0xaae98787U),
                   bswap_32big(0x372b4dd7U),
                   bswap_32big(0x39b5e131U),
                   bswap_32big(0x9b095a4cU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000428U, 0x00000a40U, 0x00000220U, 0x0808000aU);
    r_rsip_subfunc001(0x000003e8U, 0x00000a40U, 0x000001e0U, 0x0808000aU);
    r_rsip_subfunc001(0x000001e0U, 0x00000220U, 0x00000428U, 0x08080007U);
    r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x10100010U);
    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000838U);
    r_rsip_subfunc002(0x00000630U, 0x00000428U, 0x10100002U);
    r_rsip_subfunc002(0x00000630U, 0x00000220U, 0x10100003U);
    WR1_PROG(REG_1014H, 0x00000428U);
    WR1_PROG(REG_1018H, 0x00000220U);
    r_rsip_subfunc002(0x00000630U, 0x00000220U, 0x10100002U);
    WR1_PROG(REG_1404H, 0x15b00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00010001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc009(bswap_32big(0x00002a02U));
    r_rsip_func101(bswap_32big(0x7e6f57b6U),
                   bswap_32big(0x8a6278bbU),
                   bswap_32big(0x54077fc0U),
                   bswap_32big(0xcaf06207U));
    r_rsip_func052();
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000428U, 0x1010000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000428U, 0x1010000aU);
    WR1_PROG(REG_143CH, 0x00210000U);
    r_rsip_func100(bswap_32big(0xea4a0001U),
                   bswap_32big(0xf39733f8U),
                   bswap_32big(0xdb2c91c9U),
                   bswap_32big(0x4efcd944U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1ef9f5f6U), bswap_32big(0x4fc7d15aU), bswap_32big(0x151e7608U),
                       bswap_32big(0xbd09ec71U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }

    WR1_PROG(REG_1404H, 0x19c00000U);
    r_rsip_subfunc003(0x00c00081U);
    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000428U, 0x10100009U);
    r_rsip_subfunc007(bswap_32big(0xac1cd394U));
    OFS_ADR = 196;
    r_rsip_subfunc008(0x15b00000U, 0x00000020U, bswap_32big(0x00002a03U));
    r_rsip_func101(bswap_32big(0xd6831dd0U),
                   bswap_32big(0xb56f02beU),
                   bswap_32big(0x2bc76372U),
                   bswap_32big(0xb23c1141U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1600H, 0x0000b680U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00010001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x1eab7ad8U),
                   bswap_32big(0xabe25452U),
                   bswap_32big(0x041a1469U),
                   bswap_32big(0x29f918baU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00002a01U));
    r_rsip_func101(bswap_32big(0x2f302e0fU),
                   bswap_32big(0x51ddb3f4U),
                   bswap_32big(0x5d92cd99U),
                   bswap_32big(0x2b00e0e2U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01abe599U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00002a01U));
    r_rsip_func101(bswap_32big(0x76a4ec05U),
                   bswap_32big(0xc91b70b1U),
                   bswap_32big(0x930e28a0U),
                   bswap_32big(0x9230eac8U));
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
    WR1_PROG(REG_1600H, 0x00000020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x15b00000U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xdd61338eU), bswap_32big(0xca42519cU), bswap_32big(0x091cceedU),
                       bswap_32big(0xf69b823aU));
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
        r_rsip_func101(bswap_32big(0xfb73ee45U), bswap_32big(0x8f9717bbU), bswap_32big(0x444a4d07U),
                       bswap_32big(0x442d21a0U));
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
    WR1_PROG(REG_1600H, 0x00000020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x13a80000U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x8dd2058aU), bswap_32big(0x9060a037U), bswap_32big(0x4e504db6U),
                       bswap_32big(0x0fd5503dU));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 36]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 37]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 38]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 39]);
        WR1_PROG(REG_1600H, 0x00002485U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xfea16d9bU), bswap_32big(0xdbf12384U), bswap_32big(0xb3fb0f1cU),
                       bswap_32big(0x4f37727aU));
    }

    WR1_PROG(REG_1600H, 0x38000886U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xce35872fU),
                   bswap_32big(0x54b15c0fU),
                   bswap_32big(0x22ca9171U),
                   bswap_32big(0xdfee49acU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[68]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[69]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[70]);
    RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[71]);
    r_rsip_func100(bswap_32big(0x90add6b1U),
                   bswap_32big(0x5df6ad41U),
                   bswap_32big(0xf5a0828cU),
                   bswap_32big(0xadd646f8U));
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
    r_rsip_func100(bswap_32big(0x345f7f72U),
                   bswap_32big(0x09a237daU),
                   bswap_32big(0xdfe488a1U),
                   bswap_32big(0x478c75b4U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00002a02U));
    r_rsip_func101(bswap_32big(0x964cb104U),
                   bswap_32big(0xdc1ce311U),
                   bswap_32big(0x79132738U),
                   bswap_32big(0x5533a15eU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0195358eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00002a02U));
    r_rsip_func101(bswap_32big(0x456db8d3U),
                   bswap_32big(0x3ec23324U),
                   bswap_32big(0xdb8f42acU),
                   bswap_32big(0x776f7e32U));
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
    WR1_PROG(REG_1600H, 0x00000020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x15b00000U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WR1_PROG(REG_1600H, 0x34202886U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000d0e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c07U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xa60b5bbeU), bswap_32big(0xc91171c1U), bswap_32big(0x60cc3dc7U),
                       bswap_32big(0x01071352U));
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
        r_rsip_func101(bswap_32big(0x72126aeeU), bswap_32big(0xeee2e2a5U), bswap_32big(0x22c82059U),
                       bswap_32big(0xcfba0c39U));
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
    r_rsip_func100(bswap_32big(0xbcb2fe8fU),
                   bswap_32big(0x5606e429U),
                   bswap_32big(0xbecddea1U),
                   bswap_32big(0x027995c2U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008104U);
    WR1_PROG(REG_1608H, 0x81010280U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890005U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[36]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[37]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[38]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[39]);
    r_rsip_func100(bswap_32big(0xf645d408U),
                   bswap_32big(0x81015b17U),
                   bswap_32big(0xe44a16f6U),
                   bswap_32big(0xb295ea70U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c100104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[40]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[41]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[42]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[43]);
    r_rsip_func100(bswap_32big(0x2f83dc3cU),
                   bswap_32big(0x636b9985U),
                   bswap_32big(0xc3529ca3U),
                   bswap_32big(0x678b37a9U));
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
    r_rsip_func102(bswap_32big(0x52e8543cU),
                   bswap_32big(0x9baf5094U),
                   bswap_32big(0x6336d319U),
                   bswap_32big(0x0a38d381U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
