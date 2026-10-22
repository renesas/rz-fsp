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
    r_tsip_func100(0x62a32a06U, 0x6558966bU, 0xc5c9cc4bU, 0x620ed04fU);
    r_tsip_func103();
    r_tsip_func100(0x703da5efU, 0x032dd2c7U, 0x4574d4a3U, 0x1f256d28U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_0000H, 0x00001213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xa403df02U, 0x08c85d80U, 0xf4cd47e8U, 0x7ae7eecdU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x018c6f5dU));
    r_tsip_func100(0x2e1db90cU, 0x7a1855d0U, 0x648492a0U, 0x8538f4beU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a0e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01caae52U));
    WR1_PROG(REG_00ECH, 0x00000a31U);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00000343U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x80b00006U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x000083c3U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0028H, 0x009f0001U);
        r_tsip_func100(0x4c1a13eeU, 0xc3128c8fU, 0x5d04cfc4U, 0x4f3b9a50U);
        r_tsip_func103();
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00E0H, 0x80040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000d01fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003813U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        for (iLoop = 0; iLoop < 24; iLoop = iLoop + 4)
        {
            r_tsip_func100(0xcda8cadcU, 0xa51b818eU, 0x86578319U, 0x3f588ab4U);
            r_tsip_func103();
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x01000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x793716deU, 0xa8c83788U, 0x6c3337f4U, 0xeac9ca7eU);
        }

        r_tsip_func100(0xcda8cadcU, 0xa51b818eU, 0x86578319U, 0x3f588ab4U);
        r_tsip_func103();
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01000c84U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00E0H, 0x80040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008213U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000d060U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x81040000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
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
        r_tsip_func100(0xfd6b6facU, 0xb79fa4a6U, 0x46c71580U, 0xf55d3af0U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x63bb1f32U, 0x72e5b86dU, 0xb1361af4U, 0x4dd0b0bdU);
            continue;
        }
        else
        {
            r_tsip_func101(0x1340ae41U, 0x10489822U, 0x85304544U, 0xe7237cddU);
        }

        WR1_PROG(REG_00ECH, 0x38008a20U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x46419c21U, 0x85caab68U, 0x315b7237U, 0xb3100369U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xe1df3bbaU, 0x7d20730aU, 0x950595f0U, 0x7e27fca9U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001d91U);
                WAIT_STS(REG_0024H, 21U, 0U);
                r_tsip_func101(0xced5d5dbU, 0xf192cfc9U, 0xcf3ec3c1U, 0xe0a6c3d9U);
            }
            else
            {
                r_tsip_func101(0x7695d605U, 0x035a3bc3U, 0x6d3418e6U, 0x369ad557U);
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
            r_tsip_func100(0x331b4513U, 0xfaa16febU, 0xd54d14caU, 0x7f28f317U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0x86c997f2U, 0x842c5550U, 0xaef5f670U, 0x1c612e1aU);
                continue;
            }
            else
            {
                r_tsip_func101(0xbacc70e7U, 0xf2a199a7U, 0x67c93456U, 0x2bea5ac0U);
            }
        }
        else
        {
            r_tsip_func101(0xa8f14329U, 0x82af4bc8U, 0x032b1307U, 0xf0738bb6U);
        }

        WR1_PROG(REG_00ECH, 0x000008c6U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        for (iLoop = 0; iLoop < 96; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_00ECH, 0x01003906U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00002cc0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00002cc0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81010100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            r_tsip_func100(0x74c1c264U, 0xc90d1aa4U, 0x60a9ceb2U, 0x6c6fd1f7U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x0000d140U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0xd63f4bfaU, 0x3584c3c4U, 0xb1bde398U, 0xc1b4ce95U);
                break;
            }
            else
            {
                r_tsip_func101(0x903e8d79U, 0x6960fd95U, 0xe992a823U, 0x3630439eU);
            }
        }

        WR1_PROG(REG_00ECH, 0x38008940U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x345bd052U, 0x6743614cU, 0x83cac386U, 0x1aa1a55dU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x96bd0908U, 0x16359454U, 0x8ce226e6U, 0x4935b23dU);
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
        r_tsip_func100(0x68c78f70U, 0x2e446b4bU, 0x27b11b9aU, 0xc548c9f3U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xd6dfdf3fU, 0x225eaf90U, 0xce42d51cU, 0x946abe21U);
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
            r_tsip_func100(0x62350e1bU, 0x9e09560cU, 0xdcbebf08U, 0x3087dbc8U);
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
            r_tsip_func100(0x632bdc5aU, 0xf2974772U, 0x2798c9a0U, 0x06308c00U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0xa9797566U, 0xe9564735U, 0x7b2cef48U, 0x4bcc9169U);
                continue;
            }

            WR1_PROG(REG_0024H, 0x000098d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x80a0000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008383U);
            WR1_PROG(REG_002CH, 0x00000020U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b560U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000003U);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x65095398U, 0xd60c126dU, 0xb25dd725U, 0xb50c5b8bU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_007CH, 0x00000021U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0xc5a195e2U, 0x08427923U, 0x2ae046e3U, 0x8460d5f9U);
            }
            else
            {
                WR1_PROG(REG_007CH, 0x00000041U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0x352c281bU, 0xfd0d768fU, 0x16c557daU, 0x5e123ad1U);
            }

            r_tsip_func100(0x23545c3eU, 0x43037495U, 0x4063f29cU, 0x3b03735fU);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000c0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000929U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000b4c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000fcU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00003906U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00008d00U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0xfffffffeU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00003d06U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000908U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x000038e6U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000a8c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000004U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_00ECH, 0x38008900U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x11816907U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x38008900U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x10002d20U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x000168e7U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                }
            }

            WR1_PROG(REG_00ECH, 0x00003549U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000a540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000003U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0002694aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81010140U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            WR1_PROG(REG_00ECH, 0x000037eaU);
            WR1_PROG(REG_01D0H, 0x00000000U);
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
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0x328fd633U, 0xd8ac13c0U, 0x83b895e6U, 0x82f7b6d9U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_001CH, 0x00602000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func100(0x2767500dU, 0xfe636292U, 0x036324fcU, 0x2912f755U);
            WR1_PROG(REG_00ECH, 0x00026d4aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00002949U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81010140U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            WR1_PROG(REG_00ECH, 0x000037eaU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_0024H, 0x2000018dU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x000033e0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0x24e73b45U, 0x44bb841dU, 0xe711cbacU, 0xf834caa2U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_001CH, 0x00602000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func100(0x3b0c074eU, 0x587f2e50U, 0x2014ee3fU, 0x867e0beeU);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000a52U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0024H, 0x00006404U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00006c04U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00E0H, 0x81010160U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_002CH, 0x00000010U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 4)
                {
                    r_tsip_func100(0x33126ad1U, 0x434644ceU, 0xf1277cc7U, 0x7eecccaaU);
                    r_tsip_func103();
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x01000c84U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_0000H, 0x00003213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func101(0x981d9e1dU, 0x10fbb7c8U, 0xaa71882dU, 0xb7e7c588U);
                }

                r_tsip_func100(0x939df4e2U, 0xeecf5db0U, 0xc88e8422U, 0x2ca5840fU);
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
                r_tsip_func100(0x76f06bb6U, 0xed90a957U, 0x9cd161e4U, 0xb0410977U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 0U))
                {
                    WR1_PROG(REG_00ECH, 0x00002e40U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func101(0x444e555cU, 0x097a9c8fU, 0xe6d07b6cU, 0x5453522fU);
                }
                else
                {
                    r_tsip_func100(0xa924e405U, 0x11adb379U, 0xc9d796adU, 0x4832613dU);
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
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0004H, 0x00000606U);
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[1]);
                    WR1_PROG(REG_00ECH, 0x000037e9U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
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
                        r_tsip_func100(0x16fccd2cU, 0xb90b8094U, 0x1178cecaU, 0x3ef16240U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 0U))
                        {
                            WR1_PROG(REG_00ECH, 0x00002e40U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            r_tsip_func101(0xf62f0c44U, 0xa295c721U, 0x0b146614U, 0xf80a0f2bU);
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
                            r_tsip_func101(0xbc52fb8bU, 0xb9b79c63U, 0x1e85df8bU, 0x44027cf3U);
                        }
                    }

                    WR1_PROG(REG_00ECH, 0x38008a40U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x00000080U);
                    WR1_PROG(REG_001CH, 0x00260000U);
                    r_tsip_func100(0x391520cdU, 0x95539a83U, 0x6c20d3daU, 0x4b670f43U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func101(0xccd344e2U, 0x66acde2bU, 0x8ee78314U, 0x7ae0cde0U);
                        break;
                    }
                    else
                    {
                        r_tsip_func101(0xa9a9ffabU, 0x31feaceeU, 0xadea244cU, 0x64110918U);
                    }
                }
            }

            WR1_PROG(REG_00ECH, 0x38000a4bU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x6e08c96fU, 0xe6baaeffU, 0xb3a7afd0U, 0x10a52ea2U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x00002e20U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x38008a20U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000002U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x00000080U);
                WR1_PROG(REG_001CH, 0x00260000U);
                r_tsip_func100(0xd067cdecU, 0xe903a25bU, 0x1cebb972U, 0x86528555U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func101(0xe07bf6c6U, 0x20756c98U, 0x1ee90bf6U, 0x7592c9edU);
                    break;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000e0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    r_tsip_func101(0xaab0e95aU, 0xf43a1e7aU, 0x3bf79971U, 0x14708b35U);
                }
            }
            else
            {
                r_tsip_func101(0xeccc2c0eU, 0x7f0c403cU, 0xc3ae347bU, 0x858cec00U);
            }
        }
    }

    WR1_PROG(REG_00ECH, 0x38008a20U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x2899dfd1U, 0x32cb090cU, 0x91c7b8ceU, 0xf53937f3U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xf4081abdU, 0x04f795acU, 0x3d79b10bU, 0xdc76cfd4U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }

    r_tsip_func100(0xe9baae9dU, 0x3791eb41U, 0x587edf10U, 0x6c613de9U);
    WR1_PROG(REG_00ECH, 0x0000b5c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00010001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
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

    r_tsip_func100(0x0edf2a9eU, 0x679c5bccU, 0x0a3eaa00U, 0x8e65c54fU);
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
        r_tsip_func100(0xf42b8f89U, 0xb0e26ca4U, 0xda41467bU, 0x57935d75U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x8d381ed5U, 0xf40ba474U, 0x76a781c2U, 0x14e499cdU);
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
            r_tsip_func101(0x62c5241cU, 0xe9ec8a34U, 0xcdd37fbdU, 0x7d420ad9U);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00010001U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0024H, 0x000005c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    while (1)
    {
        r_tsip_func100(0x232b47f9U, 0x02070e1dU, 0x70a05faaU, 0x4269e2f3U);
        r_tsip_func103();
        r_tsip_func100(0xfea2032eU, 0x017d06e0U, 0x41d43605U, 0x9a705d74U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0xc7e63bf8U, 0xbf5c03e7U, 0x2fda56d8U, 0x4795318eU);
        WR1_PROG(REG_0104H, 0x00000152U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00090e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x017ed8baU));
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80c0000aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00018303U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x7640c133U, 0x71c0ffb4U, 0x45b51c5fU, 0x9e82d0b3U);
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

        r_tsip_func100(0x3209e7e5U, 0x11c91099U, 0xafd90763U, 0xb501818dU);
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
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0000H, 0x0000301fU);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00E0H, 0x81010100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000000U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000c002U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x00003506U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x800100c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x0000031fU);
        WR1_PROG(REG_002CH, 0x0000002cU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0000H, 0x00008307U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x380088c0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0xc58ffe5dU, 0x6cf97c51U, 0x395bd939U, 0x8e45a012U);
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
            r_tsip_func101(0x0ac8f811U, 0xba2f95e8U, 0xa11038beU, 0x4479908eU);
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
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81c0000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00013803U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x2b855b68U, 0x6f67f09aU, 0x513b22c4U, 0x688ca5ebU);
        }
    }

    WR1_PROG(REG_00ECH, 0x00007c06U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0x5cfb9ebcU, 0xee34e127U, 0xad75894fU, 0xbd9ef110U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    r_tsip_func103();
    r_tsip_func100(0x0a672fd2U, 0x77f3e0f8U, 0x1a62b4a2U, 0xefb35f4eU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_0000H, 0x00001213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xb52a5000U, 0x13ee65faU, 0x83cab1b9U, 0x45e0548bU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01d63bf6U));
    r_tsip_func100(0x55574150U, 0x9b360e5fU, 0xad9c1afcU, 0x5dd8ccbeU);
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

    r_tsip_func100(0x21bc3bbaU, 0x3e865b46U, 0x31f05febU, 0xe0aff42aU);
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
    r_tsip_func100(0xd4f1dc33U, 0x27cf20ffU, 0x852afbb8U, 0xd5378600U);
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
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0x29732909U, 0x3510f44bU, 0x922d3b8fU, 0x0f7da082U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xe8c910eeU, 0xac92e85cU, 0xfd800bc0U, 0x0b409ef1U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x002e812fU, 0x1d092efdU, 0x35b84e61U, 0x42739e97U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01cae143U));
    r_tsip_func100(0xd05d7c99U, 0x84acc937U, 0x6f51bbe7U, 0x1973ccf5U);
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
    r_tsip_func100(0x369ac45cU, 0xf8447192U, 0x03f082ddU, 0x0449f84fU);
    WR1_PROG(REG_00C4H, 0x00e00884U);
    WR1_PROG(REG_00E0H, 0x810101c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
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
    r_tsip_func100(0xccc895cbU, 0x5b1b3029U, 0x9d6382eaU, 0x28b5476aU);
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
    r_tsip_func100(0xfc12ad9fU, 0x80f66544U, 0x4e700c51U, 0xdce761d3U);
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
    r_tsip_func100(0x1e0da217U, 0x2af67c33U, 0x18a15ab8U, 0x2fd34e24U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000612U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[0]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[1]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[2]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[3]);
    r_tsip_func100(0x16bff7a1U, 0x38b0d889U, 0x681be7a0U, 0xaa8ac59bU);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0xd10eff96U, 0xa8e345f7U, 0xb78ae83cU, 0xa0869ae8U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x4de075ebU, 0x93352752U, 0x5c6b51b8U, 0x9f026390U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x272d3454U, 0x16042a9aU, 0xbd3465f8U, 0x98b3b67fU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013a2341U));
    r_tsip_func100(0xcb813640U, 0x1e8fd12bU, 0x097a30d9U, 0x50800602U);
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
    r_tsip_func100(0x9e99ca5aU, 0x8796b524U, 0xfede2e22U, 0xf6c46bb3U);
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
    r_tsip_func100(0xd14c5467U, 0x12ac3af0U, 0xc5354e57U, 0xae156e5dU);
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
    r_tsip_func100(0x447fc736U, 0xc5f3d13fU, 0xdc275fb9U, 0x19ef9993U);
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
    r_tsip_func100(0x5299a908U, 0x6a647f6aU, 0xf66767e6U, 0x21010be8U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000612U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[0]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[1]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[2]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[3]);
    r_tsip_func102(0x10ecac59U, 0x47cf5812U, 0x2842da3eU, 0x802ec335U);
    WR1_PROG(REG_01BCH, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
