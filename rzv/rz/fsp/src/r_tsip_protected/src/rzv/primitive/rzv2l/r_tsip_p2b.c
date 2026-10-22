/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"
#include "r_tsip_reg.h"
#include "r_tsip_util.h"

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

TSIP_PRV_PRIMITIVE_FUNC

tsip_ret_t r_tsip_p2b (uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
{
    TSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t iLoop2;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t oLoop2;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) iLoop2;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) oLoop2;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_01BCH, 0x1fU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00002b02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0xa528dfaaU, 0x5203df34U, 0xc7f1f74eU, 0xf4504db7U);
    r_tsip_func103();
    r_tsip_func100(0x83afe376U, 0xf072a7a4U, 0xacd131b2U, 0xe5f124feU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_0000H, 0x00001213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x896cb4daU, 0xa86e2656U, 0x9621380aU, 0x8cd746b7U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0124ee4dU));
    r_tsip_func100(0x3e3b7af0U, 0xeb4ce527U, 0x2d99196fU, 0x29e10c22U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a0e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01288ad7U));
    WR1_PROG(REG_00ECH, 0x00000a31U);
    for (kLoop = 0; kLoop < MAX_CNT; kLoop = kLoop + 1)
    {
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0000H, 0x00003043U);
        WR1_PROG(REG_002CH, 0x00000012U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0104H, 0x00002f57U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00030005U));
        WR1_PROG(REG_0100H, bswap_32big(0x0007000bU));
        WR1_PROG(REG_0100H, bswap_32big(0x000d0011U));
        WR1_PROG(REG_0100H, bswap_32big(0x00130017U));
        WR1_PROG(REG_0100H, bswap_32big(0x001d001fU));
        WR1_PROG(REG_0100H, bswap_32big(0x00250029U));
        WR1_PROG(REG_0100H, bswap_32big(0x002b002fU));
        WR1_PROG(REG_0100H, bswap_32big(0x003b003dU));
        WR1_PROG(REG_0100H, bswap_32big(0x00430047U));
        WR1_PROG(REG_0100H, bswap_32big(0x0049004fU));
        WR1_PROG(REG_0100H, bswap_32big(0x00530059U));
        WR1_PROG(REG_0100H, bswap_32big(0x00610065U));
        WR1_PROG(REG_0100H, bswap_32big(0x0067006bU));
        WR1_PROG(REG_0100H, bswap_32big(0x006d0071U));
        WR1_PROG(REG_0100H, bswap_32big(0x007f0083U));
        WR1_PROG(REG_0100H, bswap_32big(0x0089008bU));
        WR1_PROG(REG_0100H, bswap_32big(0x00950097U));
        WR1_PROG(REG_0100H, bswap_32big(0x009d00a3U));
        WR1_PROG(REG_0100H, bswap_32big(0x00a700adU));
        WR1_PROG(REG_0100H, bswap_32big(0x00b300b5U));
        WR1_PROG(REG_0100H, bswap_32big(0x00bf00c1U));
        WR1_PROG(REG_0100H, bswap_32big(0x00c500c7U));
        WR1_PROG(REG_0100H, bswap_32big(0x00d300dfU));
        WR1_PROG(REG_0100H, bswap_32big(0x00e300e5U));
        WR1_PROG(REG_0100H, bswap_32big(0x00e900efU));
        WR1_PROG(REG_0100H, bswap_32big(0x00f100fbU));
        WR1_PROG(REG_0100H, bswap_32big(0x01010107U));
        WR1_PROG(REG_0100H, bswap_32big(0x010d010fU));
        WR1_PROG(REG_0100H, bswap_32big(0x01150119U));
        WR1_PROG(REG_0100H, bswap_32big(0x011b0125U));
        WR1_PROG(REG_0100H, bswap_32big(0x01330137U));
        WR1_PROG(REG_0100H, bswap_32big(0x0139013dU));
        WR1_PROG(REG_0100H, bswap_32big(0x014b0151U));
        WR1_PROG(REG_0100H, bswap_32big(0x015b015dU));
        WR1_PROG(REG_0100H, bswap_32big(0x01610167U));
        WR1_PROG(REG_0100H, bswap_32big(0x016f0175U));
        WR1_PROG(REG_0100H, bswap_32big(0x017b017fU));
        WR1_PROG(REG_0100H, bswap_32big(0x0185018dU));
        WR1_PROG(REG_0100H, bswap_32big(0x01910199U));
        WR1_PROG(REG_0100H, bswap_32big(0x01a301a5U));
        WR1_PROG(REG_0100H, bswap_32big(0x01af01b1U));
        WR1_PROG(REG_0100H, bswap_32big(0x01b701bbU));
        WR1_PROG(REG_0100H, bswap_32big(0x01c101c9U));
        WR1_PROG(REG_0100H, bswap_32big(0x01cd01cfU));
        WR1_PROG(REG_0100H, bswap_32big(0x01d301dfU));
        WR1_PROG(REG_0100H, bswap_32big(0x01e701ebU));
        WR1_PROG(REG_0100H, bswap_32big(0x01f301f7U));
        WR1_PROG(REG_0100H, bswap_32big(0x01fd0000U));
        WR1_PROG(REG_00ECH, 0x000008c6U);
        WR1_PROG(REG_0000H, 0x00000343U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x80b00006U);
        WR1_PROG(REG_0000H, 0x000083c3U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0028H, 0x009f0001U);
        r_tsip_func100(0xc4cccdd5U, 0x8b782b05U, 0x91302779U, 0x6f4ce4c4U);
        r_tsip_func103();
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00E0H, 0x80040000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000d01fU);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_0000H, 0x00003813U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        for (iLoop = 0; iLoop < 24; iLoop = iLoop + 4)
        {
            r_tsip_func100(0x71c7c07fU, 0x5a441404U, 0x4fbbec39U, 0x95dd9ec9U);
            r_tsip_func103();
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x01000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0xf4f6cb3dU, 0x6bfa205dU, 0x76fc278dU, 0xaff3f896U);
        }

        r_tsip_func100(0x71c7c07fU, 0x5a441404U, 0x4fbbec39U, 0x95dd9ec9U);
        r_tsip_func103();
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00E0H, 0x80040000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000d060U);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_0000H, 0x00003813U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000011U);
        WR1_PROG(REG_0104H, 0x00001f57U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xB51EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0100H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0100H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0100H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0100H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0100H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0100H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0100H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0100H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0100H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0100H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0100H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0100H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0100H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0100H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0100H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0100H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0100H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0100H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0100H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0100H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851EB8U));
        WR1_PROG(REG_0100H, bswap_32big(0x51EB851EU));
        WR1_PROG(REG_0100H, bswap_32big(0xB851EB85U));
        WR1_PROG(REG_0100H, bswap_32big(0x1EB851EBU));
        WR1_PROG(REG_0100H, bswap_32big(0x851EB851U));
        WR1_PROG(REG_0100H, bswap_32big(0xEB851B5CU));
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xdbb6640dU, 0x26ba93b7U, 0xa75d9031U, 0x566f9268U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xb24590daU, 0x67e26ef1U, 0x5a545ef1U, 0x5a5ddb5aU);
            continue;
        }
        else
        {
            r_tsip_func101(0xb9a1457fU, 0xcbae16edU, 0xbc8ef47fU, 0x6ddd34dcU);
        }

        WR1_PROG(REG_00ECH, 0x38008a20U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x128f68ceU, 0x2a99fcb5U, 0x9fe554f8U, 0xb5e6c6ffU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x2431d876U, 0xc0909944U, 0x42367ec6U, 0x0ba1ffd9U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001d91U);
                WAIT_STS(REG_0024H, 21U, 0U);
                r_tsip_func101(0xb651ae76U, 0x26706319U, 0xc8af2adbU, 0xcbf38c28U);
            }
            else
            {
                r_tsip_func101(0x6b39aadfU, 0x8234eff8U, 0x5016e1cdU, 0xdef2084fU);
            }

            WR1_PROG(REG_002CH, 0x00000011U);
            WR1_PROG(REG_0104H, 0x00000357U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0100H, bswap_32big(0x10000000U));
            WR1_PROG(REG_0000H, 0x00003073U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00001591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x7a9adbdeU, 0xf1c4fde3U, 0x9f2df94dU, 0xb214e66fU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0x19f8d31fU, 0xd288aed4U, 0x737ee60dU, 0x6400aeceU);
                continue;
            }
            else
            {
                r_tsip_func101(0x7148c935U, 0xa856388aU, 0x232872cfU, 0xe4261340U);
            }
        }
        else
        {
            r_tsip_func101(0x3edb338dU, 0xd5318118U, 0x4d56be4eU, 0xfd46e0f6U);
        }

        WR1_PROG(REG_00ECH, 0x000008c6U);
        WR1_PROG(REG_00ECH, 0x0000094aU);
        for (iLoop = 0; iLoop < 96; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_00ECH, 0x01003906U);
            WR1_PROG(REG_00ECH, 0x00002cc0U);
            WR1_PROG(REG_00ECH, 0x00002cc0U);
            WR1_PROG(REG_00E0H, 0x81010100U);
            WR1_PROG(REG_0000H, 0x0000307fU);
            WR1_PROG(REG_002CH, 0x00000014U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0000H, 0x00003807U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00004006U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xfe21c2efU, 0xd2dcf653U, 0xf6910eddU, 0x3371a403U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x0000d140U);
                r_tsip_func101(0x9d4b83c6U, 0x3007c6abU, 0x7fbcdaa1U, 0x61b04a8bU);
                break;
            }
            else
            {
                r_tsip_func101(0xb207afe7U, 0x5945be31U, 0xcf6b1254U, 0xa858c4c1U);
            }
        }

        WR1_PROG(REG_00ECH, 0x38008940U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x53837a8bU, 0xe98da1b9U, 0x53a52834U, 0x58a58d5aU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x0b2f9506U, 0xe21c89c7U, 0x19ec7ce2U, 0x41d41880U);
            continue;
        }

        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000060c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0000H, 0x0000307fU);
        WR1_PROG(REG_002CH, 0x00000014U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0104H, 0x00000057U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00010001U));
        WR1_PROG(REG_0024H, 0x00004006U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000009c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x8cf2036eU, 0x7882388aU, 0xb230a3ebU, 0x5ea929f7U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xe9f91d5aU, 0x32514d47U, 0x656f6bb9U, 0x3c86d785U);
        }
        else
        {
            WR1_PROG(REG_0024H, 0x0000d0d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000005c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000189U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func100(0xff39087eU, 0x8348fdefU, 0x42c8f5a7U, 0x6c6b44e7U);
            WR1_PROG(REG_0018H, 0x00000004U);
            WR1_PROG(REG_0038H, 0x00004080U);
            WAIT_STS(REG_0018H, 10U, 0U);
            WR1_PROG(REG_0018H, 0x00000000U);
            WR1_PROG(REG_0024H, 0x000005c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            WR1_PROG(REG_0024H, 0x000044d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000991U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xefc73c6bU, 0xdfbfe319U, 0xe1e8a7fdU, 0x358cce7eU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0x79e81448U, 0x258b1637U, 0xa529ca46U, 0xe9ca5887U);
                continue;
            }

            WR1_PROG(REG_0024H, 0x000098d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_00E0H, 0x80a0000aU);
            WR1_PROG(REG_0000H, 0x00008383U);
            WR1_PROG(REG_002CH, 0x00000020U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b560U);
            WR1_PROG(REG_00ECH, 0x00000003U);
            WR1_PROG(REG_00B0H, 0x00000700U);
            WR1_PROG(REG_00A4H, 0x02e09737U);
            WR1_PROG(REG_0000H, 0x00001383U);
            WR1_PROG(REG_002CH, 0x00000020U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00A4H, 0x00000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_00A4H, 0x000019c5U);
            WR1_PROG(REG_0000H, 0x00001113U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x38008a20U);
            WR1_PROG(REG_00ECH, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x101b1e0aU, 0x3613d681U, 0x0b8d6aebU, 0x2cfb2817U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_007CH, 0x00000021U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0x0a8d8252U, 0x04fee4dbU, 0x5785a968U, 0x21aa1af9U);
            }
            else
            {
                WR1_PROG(REG_007CH, 0x00000041U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0x6b90d8deU, 0xe04fa559U, 0x8c5e1c26U, 0x71a1250eU);
            }

            r_tsip_func100(0x8fb809bcU, 0x0f9f96edU, 0xa53476b2U, 0x2d0763aeU);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000c0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000929U);
            WR1_PROG(REG_00ECH, 0x0000b4c0U);
            WR1_PROG(REG_00ECH, 0x000000fcU);
            WR1_PROG(REG_00ECH, 0x00003906U);
            WR1_PROG(REG_00ECH, 0x00008d00U);
            WR1_PROG(REG_00ECH, 0xfffffffeU);
            WR1_PROG(REG_00ECH, 0x00003d06U);
            WR1_PROG(REG_00ECH, 0x00000908U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x000038e6U);
                WR1_PROG(REG_00ECH, 0x0000a8c0U);
                WR1_PROG(REG_00ECH, 0x00000004U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_00ECH, 0x38008900U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x11816907U);
                    WR1_PROG(REG_00ECH, 0x38008900U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x10002d20U);
                    WR1_PROG(REG_00ECH, 0x000168e7U);
                }
            }

            WR1_PROG(REG_00ECH, 0x00003549U);
            WR1_PROG(REG_00ECH, 0x0000a540U);
            WR1_PROG(REG_00ECH, 0x00000003U);
            WR1_PROG(REG_00ECH, 0x0002694aU);
            WR1_PROG(REG_00E0H, 0x81010140U);
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            WR1_PROG(REG_00ECH, 0x000037eaU);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_0024H, 0x00000185U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000185U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000185U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000185U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x000033e0U);
                r_tsip_func101(0xec5ddee9U, 0xd1116440U, 0x80edb792U, 0x4a2300a7U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_001CH, 0x00602000U);
            r_tsip_func100(0xffa63dfdU, 0xea599244U, 0x86103004U, 0x05de3e98U);
            WR1_PROG(REG_00ECH, 0x00026d4aU);
            WR1_PROG(REG_00ECH, 0x00002949U);
            WR1_PROG(REG_00E0H, 0x81010140U);
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            WR1_PROG(REG_00ECH, 0x000037eaU);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_0024H, 0x2000018dU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x000033e0U);
                r_tsip_func101(0xb6fe6f67U, 0x982c4349U, 0x11e45eb6U, 0x8f02b330U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_001CH, 0x00602000U);
            r_tsip_func100(0x8fa17313U, 0x829881b5U, 0x9f070ffeU, 0xe25eb391U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000a52U);
            WR1_PROG(REG_0024H, 0x00006404U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00006c04U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00E0H, 0x81010160U);
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_002CH, 0x00000010U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 4)
                {
                    r_tsip_func100(0xa10f88b7U, 0x5e5d60d8U, 0x463fea83U, 0xfa091dcfU);
                    r_tsip_func103();
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x01000c84U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_0000H, 0x00003213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func101(0x72aef184U, 0x066dc69eU, 0x9b834a4cU, 0x37dc984fU);
                }

                r_tsip_func100(0x182498fdU, 0x654b6949U, 0x4b120689U, 0xeb743ef9U);
                WR1_PROG(REG_0024H, 0x000019c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000c0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00009008U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000581U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000581U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000581U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000581U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000581U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000581U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000c0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000dc0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0018H, 0x00000004U);
                WR1_PROG(REG_0038H, 0x00000c40U);
                WAIT_STS(REG_0018H, 10U, 0U);
                WR1_PROG(REG_0018H, 0x00000000U);
                WR1_PROG(REG_0024H, 0x000005c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001191U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00210000U);
                WR1_PROG(REG_0024H, 0x000005c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000991U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00210000U);
                r_tsip_func100(0x8842e0f0U, 0xa58dac77U, 0x6435e9e0U, 0x2c32e98aU);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 0U))
                {
                    WR1_PROG(REG_00ECH, 0x00002e40U);
                    r_tsip_func101(0x337f74f9U, 0x52d2f77dU, 0xd7f339b5U, 0x16a2adb8U);
                }
                else
                {
                    r_tsip_func100(0x1a743fa5U, 0x8a7174beU, 0xba150ebeU, 0xcab801e1U);
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000591U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00006404U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00006c04U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00E0H, 0x81010120U);
                    WR1_PROG(REG_0004H, 0x00000606U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[1]);
                    WR1_PROG(REG_00ECH, 0x000037e9U);
                    for (jLoop = 0; jLoop < S_RAM[0 + 1]; jLoop = jLoop + 1)
                    {
                        WR1_PROG(REG_0024H, 0x000009c0U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x00001191U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_001CH, 0x00210000U);
                        WR1_PROG(REG_0024H, 0x000011c0U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x00000991U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_001CH, 0x00210000U);
                        r_tsip_func100(0xa330bf14U, 0x6a3b1089U, 0x3bd48342U, 0x38f74946U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 0U))
                        {
                            WR1_PROG(REG_00ECH, 0x00002e40U);
                            r_tsip_func101(0xf378986eU, 0xf59250c5U, 0x9cee7dabU, 0x56b5c821U);
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_0024H, 0x00004c0cU);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x0000880cU);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019c0U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x00000591U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000040c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            r_tsip_func101(0x21a2f3d5U, 0xaf6655d5U, 0x98731cb4U, 0x289348e1U);
                        }
                    }

                    WR1_PROG(REG_00ECH, 0x38008a40U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x00000080U);
                    WR1_PROG(REG_001CH, 0x00260000U);
                    r_tsip_func100(0x2167adeaU, 0xd2ab2be5U, 0xa5b98c7bU, 0x4b211984U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func101(0x5bea39bdU, 0x88d2fbacU, 0x0ef79100U, 0xcfa3c3d0U);
                        break;
                    }
                    else
                    {
                        r_tsip_func101(0xe1fd07f0U, 0x6cea3f43U, 0x3f4b7e50U, 0x84c4bdc3U);
                    }
                }
            }

            WR1_PROG(REG_00ECH, 0x38000a4bU);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x0d207b2eU, 0x54444ee0U, 0x70bebe38U, 0xd709eecbU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x00002e20U);
                WR1_PROG(REG_00ECH, 0x38008a20U);
                WR1_PROG(REG_00ECH, 0x00000002U);
                WR1_PROG(REG_00E0H, 0x00000080U);
                WR1_PROG(REG_001CH, 0x00260000U);
                r_tsip_func100(0xeebe32c9U, 0x5c10a165U, 0xf03e0b4bU, 0xef07032aU);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func101(0xe2c102b8U, 0x2d541d16U, 0xd597dca1U, 0xb008745bU);
                    break;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000e0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    r_tsip_func101(0x36bae20cU, 0x40f60f46U, 0xbf8cfd76U, 0xb2d21f1fU);
                }
            }
            else
            {
                r_tsip_func101(0x381b2052U, 0x34c90f1aU, 0x14cc4e69U, 0x7efeb2d8U);
            }
        }
    }

    WR1_PROG(REG_00ECH, 0x38008a20U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0xdd5dc748U, 0x1f13cc68U, 0x93c4a23aU, 0xd31aa6a3U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xb297ec63U, 0xa9d712b5U, 0x2f788670U, 0x33a26cabU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }

    r_tsip_func100(0x599baefbU, 0x9becf10fU, 0x28692af2U, 0x0f8db22aU);
    WR1_PROG(REG_00ECH, 0x0000b5c0U);
    WR1_PROG(REG_00ECH, 0x00010001U);
    WR1_PROG(REG_0024H, 0x000019c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x02e0a7b7U);
    WR1_PROG(REG_0000H, 0x00011303U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_0004H, 0x00000102U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    }

    r_tsip_func100(0x9616008bU, 0xf49907ecU, 0xdb21895dU, 0xb69c5951U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000029c5U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000112U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000a0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000e0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    while (1)
    {
        WR1_PROG(REG_0024H, 0x00008006U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xc0ecb7a6U, 0x984d236aU, 0xbb10a11eU, 0xe037d95aU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x77df4491U, 0x29531dc2U, 0xc0939bfcU, 0x403459d0U);
            break;
        }
        else
        {
            WR1_PROG(REG_0024H, 0x000019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000d0d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func101(0xb6ca99eeU, 0x771e008dU, 0x1b2033fbU, 0x510f7198U);
        }
    }

    WR1_PROG(REG_0024H, 0x000094d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000c002U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000dcd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000b80aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0000H, 0x000030ffU);
    WR1_PROG(REG_002CH, 0x00000014U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000057U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00010001U));
    WR1_PROG(REG_002CH, 0x00000002U);
    WR1_PROG(REG_0024H, 0x0000c002U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_00E0H, 0x800100c0U);
    WR1_PROG(REG_0000H, 0x0000031fU);
    WR1_PROG(REG_002CH, 0x00000024U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000991U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b500U);
    WR1_PROG(REG_00ECH, 0x00010001U);
    WR1_PROG(REG_0024H, 0x000005c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    while (1)
    {
        r_tsip_func100(0x1d2aef6dU, 0x8b4dec92U, 0x5175cf5eU, 0x81f81c89U);
        r_tsip_func103();
        r_tsip_func100(0xa84483b6U, 0x3a413e38U, 0xf3d55833U, 0x3930b9ffU);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0xeefc624cU, 0x31e5e47fU, 0x8cb0f87aU, 0x405f0138U);
        WR1_PROG(REG_0104H, 0x00000152U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00090e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x013094c2U));
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_00E0H, 0x80c0000aU);
        WR1_PROG(REG_0000H, 0x00018303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x642c388fU, 0x8ff4f072U, 0xa104db98U, 0x102cb4aeU);
        WR1_PROG(REG_00D0H, 0x00000f00U);
        WR1_PROG(REG_00C4H, 0x02e097b7U);
        WR1_PROG(REG_0000H, 0x00012303U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000202U);
        for (iLoop = 68; iLoop < 132; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        r_tsip_func100(0x6d3547fbU, 0x5639a008U, 0xc99e0429U, 0xcad0b2b9U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x00000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x000019c5U);
        WR1_PROG(REG_0000H, 0x00002213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0004H, 0x00000212U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_0028H, 0x009f0001U);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00870001U);
        WR1_PROG(REG_0000H, 0x0000301fU);
        WR1_PROG(REG_002CH, 0x00000014U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x810100c0U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0000H, 0x0000301fU);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x81010100U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000000U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000c002U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00003506U);
        WR1_PROG(REG_00E0H, 0x800100c0U);
        WR1_PROG(REG_0000H, 0x0000031fU);
        WR1_PROG(REG_002CH, 0x0000002cU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0000H, 0x00008307U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x380088c0U);
        WR1_PROG(REG_00ECH, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0xf82d1999U, 0x4af27a68U, 0x67e02695U, 0xaead37e3U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0028H, 0x00bf0001U);
            WR1_PROG(REG_0104H, 0x00003f61U);
            WR1_PROG(REG_00B0H, 0x00000f00U);
            WR1_PROG(REG_00A4H, 0x02f0a7b7U);
            WR1_PROG(REG_0000H, 0x00013103U);
            WR1_PROG(REG_002CH, 0x00000014U);
            for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
            }

            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x2f41d223U, 0xd90253e6U, 0x3f9cdf80U, 0x178eb18eU);
            break;
        }
        else
        {
            WR1_PROG(REG_0028H, 0x009f0001U);
            WR1_PROG(REG_0024H, 0x000015c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000c0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0000H, 0x00003083U);
            WR1_PROG(REG_002CH, 0x00000011U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0028H, 0x00bf0001U);
            WR1_PROG(REG_0024H, 0x0000880eU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0104H, 0x00003f62U);
            WR1_PROG(REG_00D0H, 0x00000f00U);
            WR1_PROG(REG_00C4H, 0x02f097b7U);
            WR1_PROG(REG_0000H, 0x00013203U);
            WR1_PROG(REG_002CH, 0x00000012U);
            for (iLoop = 68; iLoop < 132; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
            }

            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0104H, 0x00000362U);
            WR1_PROG(REG_00C4H, 0x000017b5U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
            WR1_PROG(REG_00C4H, 0x00800c45U);
            WR1_PROG(REG_0000H, 0x00002213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000094aU);
            WR1_PROG(REG_00E0H, 0x81c0000aU);
            WR1_PROG(REG_0000H, 0x00013803U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x1288302bU, 0xbaf5ff0fU, 0x25578247U, 0x82fea1c8U);
        }
    }

    WR1_PROG(REG_00ECH, 0x00007c06U);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000027b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
    WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    WR1_PROG(REG_00A4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xd901a8caU, 0x8695e26cU, 0x35e7f215U, 0xbe3dda82U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    r_tsip_func103();
    r_tsip_func100(0xc5bcf71dU, 0xad06d89fU, 0x2a1e7520U, 0x1f5b7ea0U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_0000H, 0x00001213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x2ee1195eU, 0x3b49e0b4U, 0xebd50633U, 0x4e309d04U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01b10d2eU));
    r_tsip_func100(0xd4b26309U, 0xddaef54eU, 0xd4c2ccb7U, 0x531d4fe5U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x02e097b7U);
    WR1_PROG(REG_0000H, 0x00011303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WR1_PROG(REG_0004H, 0x00000102U);
    for (iLoop = 68; iLoop < 132; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    }

    r_tsip_func100(0xbaca7b7fU, 0x506361b2U, 0x5051d985U, 0x886ad575U);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000019c5U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000112U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
    RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    r_tsip_func100(0x24d21fa9U, 0xef6fbbeaU, 0x277d3020U, 0xe93b121bU);
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_0024H, 0x0000b8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000002U);
    WR1_PROG(REG_0024H, 0x00007b0aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0xfcbf0001U);
    WR1_PROG(REG_0024H, 0x0000c8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    r_tsip_func100(0xc177748cU, 0x6f74e287U, 0x4d9eb4c3U, 0xbaa59975U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x884e99c0U, 0x7bf03b2cU, 0x2b14b3d2U, 0x80a7f1c9U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xc90eb5e4U, 0x7b503e3cU, 0xdce12ca1U, 0x8351b520U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x011c43cbU));
    r_tsip_func100(0x561e34dfU, 0x0472af1aU, 0x478cf9b1U, 0xcfaeb832U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x02e08887U);
    WR1_PROG(REG_0004H, 0x00000202U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x8b0818e2U, 0xb3c490faU, 0x38fb805bU, 0x70a8885aU);
    WR1_PROG(REG_00C4H, 0x00e00884U);
    WR1_PROG(REG_00E0H, 0x810101c0U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[68]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[69]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[70]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[71]);
    WAIT_STS(REG_00C8H, 6U, 0U);
    r_tsip_func100(0x58724fc2U, 0xe4827c8dU, 0x55670b8fU, 0x4fd7c557U);
    WR1_PROG(REG_0018H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x00004404U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0024H, 0x00004804U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0018H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000202U);
    for (iLoop = 68; iLoop < 132; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x9abc7638U, 0xe6a2be16U, 0xf3625872U, 0xe5f24596U);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000009c5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000010U));
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[136]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[137]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[138]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[139]);
    r_tsip_func100(0x67d70102U, 0xc442655eU, 0x7e8a2372U, 0xe1581ccdU);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0004H, 0x00000612U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[0]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[1]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[2]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[3]);
    r_tsip_func100(0x021d47f8U, 0xf4868b7bU, 0x381448acU, 0x0006bffeU);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    r_tsip_func100(0x2f7d4896U, 0xb61ddde5U, 0xf0ffe525U, 0xe46b8d9bU);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x3d5636c9U, 0x2cdfa8efU, 0xa22f9378U, 0x1d0f8f75U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x95e26a7aU, 0xd8fb4f50U, 0x4bbf476fU, 0x7c86422fU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0170f901U));
    r_tsip_func100(0xc991a315U, 0x727297d2U, 0x40d7ace0U, 0x61347423U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x02e087b7U);
    WR1_PROG(REG_0004H, 0x00000202U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x8b779f69U, 0xe059c895U, 0xd2d872e8U, 0x5d5fc0f7U);
    WR1_PROG(REG_0000H, 0x00012103U);
    WR1_PROG(REG_0104H, 0x00000031U);
    WR1_PROG(REG_00B0H, 0x00000f00U);
    WR1_PROG(REG_00A4H, 0x02f097b7U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000202U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_HEAP[68]);
    WR1_ADDR(REG_0100H, &S_HEAP[69]);
    WR1_ADDR(REG_0100H, &S_HEAP[70]);
    WR1_ADDR(REG_0100H, &S_HEAP[71]);
    for (iLoop = 68; iLoop < 128; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 4]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 5]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 6]);
        WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 7]);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 1]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 2]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 3]);
    }

    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 1]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 2]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 3]);
    WR1_PROG(REG_0104H, 0x00000000U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WAIT_STS(REG_00C8H, 6U, 0U);
    WR1_PROG(REG_0104H, 0x00000361U);
    WR1_PROG(REG_00A4H, 0x000017b5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &S_HEAP[132]);
    WR1_ADDR(REG_0100H, &S_HEAP[133]);
    WR1_ADDR(REG_0100H, &S_HEAP[134]);
    WR1_ADDR(REG_0100H, &S_HEAP[135]);
    WR1_PROG(REG_00A4H, 0x00800c45U);
    WR1_PROG(REG_0000H, 0x00001113U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xc2dd1b48U, 0xc36733e1U, 0x8d6c0372U, 0x7e14ceb8U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WR1_PROG(REG_00D0H, 0x00000f00U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000202U);
    for (iLoop = 128; iLoop < 192; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x666df72cU, 0x74771743U, 0x1aa59532U, 0xb3d55adcU);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000009c5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000030U));
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[196]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[197]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[198]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[199]);
    r_tsip_func100(0x30d9df4cU, 0x514306caU, 0x32ffe8d5U, 0x821b95b0U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0004H, 0x00000612U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[0]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[1]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[2]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[3]);
    r_tsip_func102(0xccee5dd5U, 0x5669949eU, 0x13804881U, 0x3771ee24U);
    WR1_PROG(REG_01BCH, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
