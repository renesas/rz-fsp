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

tsip_ret_t r_tsip_p2a (uint32_t MAX_CNT, uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
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

    WR1_PROG(REG_0084H, 0x00002a02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0xfce3f3a1U, 0x5c60c655U, 0x41924bdcU, 0x6a9cc5abU);
    r_tsip_func103();
    r_tsip_func100(0x693b3237U, 0xef03d3eeU, 0x74086f54U, 0xbfc22172U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_0000H, 0x00001213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x8608dab6U, 0xc8463c84U, 0xc83696c7U, 0xf56ac11dU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a4ae54U));
    r_tsip_func100(0x06d82218U, 0x63d8847eU, 0x9d237a98U, 0x063a0a6eU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a0e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x012d90cfU));
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
        WR1_PROG(REG_0028H, 0x008f0001U);
        r_tsip_func100(0xd1593d28U, 0x11aa18cdU, 0xcaea7389U, 0x0651d254U);
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
        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
        {
            r_tsip_func100(0x88bcf887U, 0x795c6781U, 0xbae01053U, 0x6694f7d2U);
            r_tsip_func103();
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x01000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x0cf13f0fU, 0x11cfedc5U, 0xb1330affU, 0xd749d247U);
        }

        r_tsip_func100(0x88bcf887U, 0x795c6781U, 0xbae01053U, 0x6694f7d2U);
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
        WR1_PROG(REG_0104H, 0x00000f57U);
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
        WR1_PROG(REG_0100H, bswap_32big(0x851EB80EU));
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xf79a77e0U, 0xf885b3a0U, 0x9583ea4cU, 0x7389b603U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x100e23f8U, 0x4ab8c9cfU, 0xe20f560cU, 0x4a2b7e32U);
            continue;
        }
        else
        {
            r_tsip_func101(0xee259200U, 0x5e5cc53dU, 0xdb73c062U, 0x0e7e8a4cU);
        }

        WR1_PROG(REG_00ECH, 0x38008a20U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0xeacdf81dU, 0x60c7d1c5U, 0x5dd46957U, 0x4588b21dU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xae4dcdbfU, 0xfc260edfU, 0xb060daabU, 0xfc705cb0U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001d91U);
                WAIT_STS(REG_0024H, 21U, 0U);
                r_tsip_func101(0x4f3279daU, 0xbb9ca101U, 0xd819d49cU, 0x74537aaeU);
            }
            else
            {
                r_tsip_func101(0xaa4437f0U, 0xcaec503cU, 0xfa6c8b5aU, 0xa36bd457U);
            }

            WR1_PROG(REG_002CH, 0x00000011U);
            WR1_PROG(REG_0104H, 0x00000357U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0100H, bswap_32big(0x10000000U));
            WR1_PROG(REG_0000H, 0x00003033U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x00001591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xe877faeaU, 0x9dd883dcU, 0x2f7441c7U, 0xc244053eU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0x74636161U, 0x1d7b0405U, 0xc67eda4dU, 0x00ef0b6eU);
                continue;
            }
            else
            {
                r_tsip_func101(0xbdf2057fU, 0x8c35b3dfU, 0x729ba61dU, 0xe19623cdU);
            }
        }
        else
        {
            r_tsip_func101(0xbeed45d7U, 0x432ec679U, 0xd7207cbfU, 0xfcf689fdU);
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
            WR1_PROG(REG_0000H, 0x0000303fU);
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
            r_tsip_func100(0x0cb65f7dU, 0x2bac6185U, 0x17b44ea9U, 0xdb5114f0U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x0000d140U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0x3f731e9aU, 0x70eff530U, 0xe1c0f2e6U, 0x1834d815U);
                break;
            }
            else
            {
                r_tsip_func101(0x469ddd5cU, 0x903912e2U, 0x1adffae7U, 0xa1d95c55U);
            }
        }

        WR1_PROG(REG_00ECH, 0x38008940U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0xc284365fU, 0xb4a400deU, 0xded5bf71U, 0xdcc48bfbU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x3a2792dbU, 0xb94f6924U, 0x3c732944U, 0xf2d4db45U);
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
        WR1_PROG(REG_0000H, 0x0000303fU);
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
        r_tsip_func100(0xbcba51edU, 0x0d716703U, 0xe7fcd64fU, 0xe1873e04U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xd14a7dd6U, 0x999d1881U, 0x4ffe01bbU, 0xe8aaa5ddU);
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
            WR1_PROG(REG_0024H, 0x000084d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x8002d008U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000005c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000189U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func100(0xfa49168aU, 0x4860b360U, 0x0732bb23U, 0x0a71bc86U);
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
            r_tsip_func100(0x2e3851eaU, 0xea958f15U, 0xa2111ccdU, 0x614e8445U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0xa195c61aU, 0xb3f30959U, 0x12282c63U, 0x9de94367U);
                continue;
            }

            WR1_PROG(REG_0024H, 0x000098d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8090000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008343U);
            WR1_PROG(REG_002CH, 0x00000020U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b560U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000006U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00B0H, 0x00000300U);
            WR1_PROG(REG_00A4H, 0x02e09737U);
            WR1_PROG(REG_0000H, 0x00001343U);
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
            r_tsip_func100(0x2767d1c8U, 0x2867457eU, 0x25e857e9U, 0xe4693093U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_007CH, 0x00000021U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0x4d50b658U, 0xa547b45bU, 0x3008e125U, 0x5d409993U);
            }
            else
            {
                WR1_PROG(REG_007CH, 0x00000041U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0xa901eddeU, 0x2d1fd2abU, 0x06ec8916U, 0xb4178dffU);
            }

            r_tsip_func100(0x36739929U, 0xe311c6c1U, 0x8fbf0f6dU, 0x120d009aU);
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
                r_tsip_func101(0xd6b87e31U, 0x58c20647U, 0x4ca836a2U, 0x11000fadU);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_001CH, 0x00602000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func100(0x0dff2485U, 0xdb063d29U, 0x2ff3386aU, 0xf3eab20bU);
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
                r_tsip_func101(0x500be15fU, 0xf87e3c64U, 0x6159f7e7U, 0x616c7e57U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_001CH, 0x00602000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func100(0xb4511269U, 0x02bad31fU, 0x631b98cfU, 0xb0c95211U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000a52U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0024H, 0x000084d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00029008U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x8000c0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
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
                for (jLoop = 0; jLoop < 16; jLoop = jLoop + 4)
                {
                    r_tsip_func100(0x425825a0U, 0xd88fdb3aU, 0xa7f1ad92U, 0x874b6be5U);
                    r_tsip_func103();
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x01000c84U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_0000H, 0x00003213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func101(0xe57e9510U, 0x14014dd8U, 0x1ee06b72U, 0x50c484d0U);
                }

                r_tsip_func100(0x4cf78884U, 0x23ad3612U, 0x3ddd522eU, 0xbe44ea86U);
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
                WR1_PROG(REG_0024H, 0x000050d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000084d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00029008U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x8000c0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000088d0U);
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
                WR1_PROG(REG_0024H, 0x000050d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000084d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00029008U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x8000c0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000088d0U);
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
                r_tsip_func100(0x7e98da59U, 0xd10b4a08U, 0x507d795aU, 0x1e398ec1U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 0U))
                {
                    WR1_PROG(REG_00ECH, 0x00002e40U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func101(0x6375e254U, 0x4e190f47U, 0x19c984a3U, 0x35658990U);
                }
                else
                {
                    r_tsip_func100(0x32464c37U, 0x9a687207U, 0x81e2491eU, 0xb4e3880fU);
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
                        r_tsip_func100(0x7763c430U, 0xd3d7d815U, 0xb9d742aaU, 0x0bc28d2eU);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 0U))
                        {
                            WR1_PROG(REG_00ECH, 0x00002e40U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            r_tsip_func101(0x1fabab7eU, 0xc40247faU, 0x0b8018acU, 0x88443b07U);
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
                            r_tsip_func101(0x278c6930U, 0x237f68b7U, 0x29c70f77U, 0xb32a567cU);
                        }
                    }

                    WR1_PROG(REG_00ECH, 0x38008a40U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x00000080U);
                    WR1_PROG(REG_001CH, 0x00260000U);
                    r_tsip_func100(0xeb294a80U, 0xe2c659a2U, 0xccf562e0U, 0xb9b7db74U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func101(0xe596620bU, 0x82d9c95cU, 0x87f14806U, 0xb57e2ba7U);
                        break;
                    }
                    else
                    {
                        r_tsip_func101(0xbb30ece7U, 0x7ec05253U, 0xbfc96171U, 0x982cdbebU);
                    }
                }
            }

            WR1_PROG(REG_00ECH, 0x38000a4bU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0xdf7f6fe4U, 0x42429271U, 0x9ace1a55U, 0xf2b23c50U);
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
                r_tsip_func100(0x20c7b39cU, 0xdab606cfU, 0xc6386a20U, 0x12ce835bU);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func101(0x57431974U, 0x0130a5a9U, 0x53f68608U, 0x8e041f6cU);
                    break;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000e0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    r_tsip_func101(0x7945f984U, 0x82eb8b52U, 0xf996d152U, 0x4ff6c528U);
                }
            }
            else
            {
                r_tsip_func101(0xb812b0cdU, 0x03247cfbU, 0xaf765adcU, 0xdd6854caU);
            }
        }
    }

    WR1_PROG(REG_00ECH, 0x38008a20U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x3ba24badU, 0x7e8c5e5eU, 0x605e3f9eU, 0xe833bff3U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x19cace8cU, 0xe97db68eU, 0xaa30db0fU, 0xccaacc30U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }

    r_tsip_func100(0x0d639ee3U, 0x6e57e2c9U, 0x3fca0edbU, 0x7ec384beU);
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
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000020U);
    WR1_PROG(REG_0024H, 0x800019c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_00B0H, 0x00000700U);
    WR1_PROG(REG_00A4H, 0x02e0a7b7U);
    WR1_PROG(REG_0000H, 0x00001383U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_0004H, 0x00000182U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
    }

    r_tsip_func100(0x9aabb32eU, 0x70a613d7U, 0xacd51a9cU, 0xe9c0402bU);
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
    WR1_PROG(REG_0028H, 0x008f0001U);
    WR1_PROG(REG_0024H, 0x0000b0d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000e8d0U);
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
        r_tsip_func100(0xfba800d8U, 0xd533b2b3U, 0x467a5a26U, 0x914b105bU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xc1e30009U, 0xd40016d1U, 0xa166a987U, 0x18b9943bU);
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
            r_tsip_func101(0x23a6f3bfU, 0xa9111eaeU, 0x3d52c284U, 0x3fac460aU);
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
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000980aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_0000H, 0x0000307fU);
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
    WR1_PROG(REG_0028H, 0x009f0001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000991U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000e0c1U);
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
        r_tsip_func100(0xba889af9U, 0xe49871f6U, 0x4b32bebbU, 0x947f2793U);
        r_tsip_func103();
        r_tsip_func100(0x94352c00U, 0x1c547620U, 0x81c968ebU, 0x53f01785U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0xd4f8ad44U, 0x24fca575U, 0x82a622d9U, 0x290d9535U);
        WR1_PROG(REG_0104H, 0x00000152U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00090e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x016a3bc9U));
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x80a0000aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008383U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0xdf8774cfU, 0x5443fc00U, 0xa8699036U, 0xb9f43a0eU);
        WR1_PROG(REG_00D0H, 0x00000700U);
        WR1_PROG(REG_00C4H, 0x02e097b7U);
        WR1_PROG(REG_0000H, 0x00002383U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WR1_PROG(REG_0004H, 0x00000282U);
        for (iLoop = 36; iLoop < 68; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
        }

        r_tsip_func100(0x3162bf42U, 0x91925319U, 0xaf706b3cU, 0x5f4e91e6U);
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
        WR1_PROG(REG_0028H, 0x008f0001U);
        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x800080c1U);
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
        r_tsip_func100(0x20b05149U, 0x93d6f66dU, 0xc64f5b27U, 0xcd3c6e56U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0028H, 0x008f0001U);
            WR1_PROG(REG_0104H, 0x00001f61U);
            WR1_PROG(REG_00B0H, 0x00000700U);
            WR1_PROG(REG_00A4H, 0x02f0a7b7U);
            WR1_PROG(REG_0000H, 0x00003143U);
            WR1_PROG(REG_002CH, 0x00000015U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
            }

            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0000H, 0x00003143U);
            WR1_PROG(REG_002CH, 0x00000014U);
            for (iLoop = 16; iLoop < 32; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_0100H, &S_HEAP[iLoop + 3]);
            }

            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x9c419d61U, 0x6a33912aU, 0x64a795fbU, 0x3bf8d253U);
            break;
        }
        else
        {
            WR1_PROG(REG_0028H, 0x008f0001U);
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x800011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000e0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0000H, 0x00003043U);
            WR1_PROG(REG_002CH, 0x00000018U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0028H, 0x009f0001U);
            WR1_PROG(REG_0024H, 0x0000890eU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0104H, 0x00001f62U);
            WR1_PROG(REG_00D0H, 0x00000700U);
            WR1_PROG(REG_00C4H, 0x02f097b7U);
            WR1_PROG(REG_0000H, 0x00003283U);
            WR1_PROG(REG_002CH, 0x00000012U);
            for (iLoop = 36; iLoop < 68; iLoop = iLoop + 4)
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
            WR1_PROG(REG_0024H, 0x00001de1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000094aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x81a0000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003883U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0xd09aadfdU, 0xa4b0d681U, 0xfd55c5dbU, 0xdbbb9b0aU);
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
    r_tsip_func100(0x30a8ef73U, 0x4f51f760U, 0x2fee920dU, 0x6677bdfbU);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x800088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000b8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000002U);
    WR1_PROG(REG_0024H, 0x00007b0aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000ccd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x009f0001U);
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
    r_tsip_func100(0x552dae12U, 0xf1f67888U, 0x2c065b02U, 0x07e83f82U);
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
    r_tsip_func100(0xae8be563U, 0x6148a6afU, 0xacf94e09U, 0xc8d3e9a3U);
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
    r_tsip_func100(0x2e88a830U, 0x03d5bb92U, 0x56887798U, 0xd97eec9aU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01f5b8a7U));
    r_tsip_func100(0x80376a93U, 0xaf608a84U, 0x6ed1da4bU, 0xd610d337U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00040804U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00002383U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x02e08887U);
    WR1_PROG(REG_0004H, 0x00000282U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xa7e3f653U, 0x01320a45U, 0xbe888f4eU, 0x8a069f90U);
    WR1_PROG(REG_00C4H, 0x00e00884U);
    WR1_PROG(REG_00E0H, 0x810101c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002807U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[36]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[37]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[38]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[39]);
    WAIT_STS(REG_00C8H, 6U, 0U);
    r_tsip_func100(0xebd84ac3U, 0x2f89b2acU, 0x1094b63eU, 0xd7b3ef04U);
    WR1_PROG(REG_0018H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x00004404U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0024H, 0x00004804U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0018H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002383U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000282U);
    for (iLoop = 36; iLoop < 68; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x08b86c2dU, 0x6caf3348U, 0x855f76e3U, 0x4ba9e7b9U);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000009c5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000008U));
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[72]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[73]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[74]);
    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[75]);
    r_tsip_func100(0xe9290965U, 0xf9f6b739U, 0x1661182fU, 0xc331e47bU);
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
    r_tsip_func100(0x0cca55f6U, 0xc6516246U, 0x7a4f3325U, 0x95d36635U);
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
    r_tsip_func100(0x77ebde7fU, 0x1e7a6691U, 0x80669946U, 0x68714397U);
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
    r_tsip_func100(0x57b77951U, 0xfa3f14faU, 0x00a835adU, 0x13ffebffU);
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
    r_tsip_func100(0x82d57f43U, 0xd1a82e70U, 0xa64a8835U, 0x3877c007U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x019184b5U));
    r_tsip_func100(0x4a1b323eU, 0x4d6171b9U, 0xdc61d3ffU, 0x7e10cb39U);
    WR1_PROG(REG_0000H, 0x00002383U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x02e087b7U);
    WR1_PROG(REG_0004H, 0x00000282U);
    for (iLoop = 0; iLoop < 32; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x86ae29e8U, 0xe6273e8bU, 0x996d7361U, 0xa09c8c48U);
    WR1_PROG(REG_0000H, 0x00002383U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000282U);
    for (iLoop = 32; iLoop < 64; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xcfc087e5U, 0x6dcf1506U, 0x2a3023beU, 0x51a1a388U);
    WR1_PROG(REG_0000H, 0x00002383U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WR1_PROG(REG_00D0H, 0x00000700U);
    WR1_PROG(REG_00C4H, 0x00e087b7U);
    WR1_PROG(REG_0004H, 0x00000282U);
    for (iLoop = 64; iLoop < 96; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
    }

    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x1e499303U, 0x0483b063U, 0x8c1e2f88U, 0x70540b5fU);
    WR1_PROG(REG_0104H, 0x00000352U);
    WR1_PROG(REG_00C4H, 0x000009c5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000018U));
    WR1_PROG(REG_0004H, 0x00000212U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[100]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[101]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[102]);
    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[103]);
    r_tsip_func100(0x570d6c56U, 0x7a3e6ce4U, 0xdcd38bd8U, 0xf4df5f90U);
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
    r_tsip_func102(0x606ef760U, 0xcb8ed401U, 0xf2192161U, 0xd4173710U);
    WR1_PROG(REG_01BCH, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
