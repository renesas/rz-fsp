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
    r_tsip_func100(0xbe28d98aU, 0x8cc42824U, 0xa17d2471U, 0x4efbd76dU);
    r_tsip_func103();
    r_tsip_func100(0xa4b1bc69U, 0x5c4fb67cU, 0x0eec11e0U, 0x90bd3409U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_0000H, 0x00001213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x3ecd429bU, 0x323a0135U, 0xaf6e33bdU, 0xb361c9f1U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00090e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x011d780aU));
    r_tsip_func100(0x775812a7U, 0xc1b4a4aeU, 0x8e6f7703U, 0xdb4afb4dU);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x000a0e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01db1023U));
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
        WR1_PROG(REG_0028H, 0x008f0001U);
        r_tsip_func100(0x2aa9f364U, 0x721a0c2fU, 0x1d69cc53U, 0x676d01c4U);
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
        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 4)
        {
            r_tsip_func100(0x12e6c6f3U, 0xc8b3bb16U, 0x7ff482e5U, 0xf535736dU);
            r_tsip_func103();
            WR1_PROG(REG_0104H, 0x00000052U);
            WR1_PROG(REG_00C4H, 0x01000c84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0000H, 0x00003213U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0x4a4326d3U, 0xf6b24c8cU, 0xc34f2ca8U, 0x76bc3715U);
        }

        r_tsip_func100(0x12e6c6f3U, 0xc8b3bb16U, 0x7ff482e5U, 0xf535736dU);
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
        r_tsip_func100(0x9ea2ecf7U, 0x31b605b2U, 0xdba25b0cU, 0xe7e76823U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xfbdf554dU, 0x953baebfU, 0x99aaf014U, 0xaeb2f909U);
            continue;
        }
        else
        {
            r_tsip_func101(0x045f226fU, 0x5ee744f3U, 0x98c3db56U, 0x9c5c8122U);
        }

        WR1_PROG(REG_00ECH, 0x38008a20U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x944ae9f5U, 0x8104e230U, 0xcc13b6bcU, 0xf936c77fU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x1a4f0545U, 0xd7f8381fU, 0x4dc2e583U, 0xd0549b2cU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001d91U);
                WAIT_STS(REG_0024H, 21U, 0U);
                r_tsip_func101(0xb0e47d6bU, 0xee0fb1eaU, 0x06780fc5U, 0x4ef7fda3U);
            }
            else
            {
                r_tsip_func101(0x5ee0d648U, 0x7a5c208aU, 0xd5500bdcU, 0x4c40ecb3U);
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
            r_tsip_func100(0x59d4591cU, 0xd33bc62eU, 0x1bcf0b20U, 0x2f9c8477U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0xedf23d63U, 0xb5bdee40U, 0x7137fb97U, 0x36f11ed5U);
                continue;
            }
            else
            {
                r_tsip_func101(0x8d31da5cU, 0x37497e59U, 0x99a5e601U, 0x85331660U);
            }
        }
        else
        {
            r_tsip_func101(0x2609566cU, 0x98f721b7U, 0x37a28edeU, 0xb4a4f695U);
        }

        WR1_PROG(REG_00ECH, 0x000008c6U);
        WR1_PROG(REG_00ECH, 0x0000094aU);
        for (iLoop = 0; iLoop < 96; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_00ECH, 0x01003906U);
            WR1_PROG(REG_00ECH, 0x00002cc0U);
            WR1_PROG(REG_00ECH, 0x00002cc0U);
            WR1_PROG(REG_00E0H, 0x81010100U);
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
            r_tsip_func100(0x6f7c535cU, 0xbedef029U, 0x18bb42ddU, 0x2e530e1eU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x0000d140U);
                r_tsip_func101(0x08090545U, 0x1bbed743U, 0xbfe90b87U, 0xee8d5d67U);
                break;
            }
            else
            {
                r_tsip_func101(0x126d976eU, 0xe381e7daU, 0x78d70930U, 0x09cd05d1U);
            }
        }

        WR1_PROG(REG_00ECH, 0x38008940U);
        WR1_PROG(REG_00ECH, 0x00000001U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        r_tsip_func100(0x7787fadcU, 0x02563a97U, 0x2330e31fU, 0x70f35f3bU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xb18319aeU, 0xfd2f9eeeU, 0xc0aa4a71U, 0xa6c85870U);
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
        r_tsip_func100(0xa7a068f4U, 0x33550abdU, 0x8cc6ee06U, 0x3bea9f89U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0x50cd26c2U, 0x58f0fdedU, 0x662cdaacU, 0x7ea72dc6U);
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
            r_tsip_func100(0x94b5471fU, 0xa81ae5cbU, 0xa5d35afcU, 0x512a4dfbU);
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
            r_tsip_func100(0xbfea7027U, 0x43a32678U, 0xe565e5adU, 0xe53eba62U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func101(0x87592441U, 0xefd89a71U, 0xe1f8efabU, 0x9cc32bb5U);
                continue;
            }

            WR1_PROG(REG_0024H, 0x000098d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_00E0H, 0x8090000aU);
            WR1_PROG(REG_0000H, 0x00008343U);
            WR1_PROG(REG_002CH, 0x00000020U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b560U);
            WR1_PROG(REG_00ECH, 0x00000006U);
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
            WR1_PROG(REG_00ECH, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x1e7abb41U, 0x4e362e2fU, 0xa2081346U, 0x550194beU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_007CH, 0x00000021U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0x4a6a9fc5U, 0x43ccefd1U, 0xee0f0ff1U, 0x998e6184U);
            }
            else
            {
                WR1_PROG(REG_007CH, 0x00000041U);
                WR1_PROG(REG_0000H, 0x00005113U);
                WR1_PROG(REG_0074H, 0x00000004U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func101(0xbc80e9d2U, 0x6ee0fa61U, 0x5e805bdeU, 0x1cd5ce0eU);
            }

            r_tsip_func100(0xadf3dafdU, 0x5819edbaU, 0xb5c10331U, 0xfc317d81U);
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
                r_tsip_func101(0x124c553aU, 0xc9090179U, 0x79d72b42U, 0x308b10c6U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_001CH, 0x00602000U);
            r_tsip_func100(0x07a265a6U, 0x498db48bU, 0x32e22f7eU, 0xc90921c2U);
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
                r_tsip_func101(0xff05f6d0U, 0x2cd1e51cU, 0xd2355ba4U, 0xcad10520U);
            }

            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_001CH, 0x00602000U);
            r_tsip_func100(0x5316b217U, 0x3114b8f8U, 0xedecd66cU, 0xd4737109U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000a52U);
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
            WR1_PROG(REG_0004H, 0x00000606U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_002CH, 0x00000010U);
                for (jLoop = 0; jLoop < 16; jLoop = jLoop + 4)
                {
                    r_tsip_func100(0x2a7a8854U, 0x96f27f27U, 0xac60faa5U, 0xbd58e6efU);
                    r_tsip_func103();
                    WR1_PROG(REG_0104H, 0x00000052U);
                    WR1_PROG(REG_00C4H, 0x01000c84U);
                    WAIT_STS(REG_0104H, 31U, 1U);
                    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                    WR1_PROG(REG_0000H, 0x00003213U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    r_tsip_func101(0x877a697bU, 0x87c8db4fU, 0x850af5a7U, 0x2165b564U);
                }

                r_tsip_func100(0xf62a629fU, 0x01d2af50U, 0xe2df8c0bU, 0x4aac6d23U);
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
                r_tsip_func100(0xfad0f17aU, 0xfaaf7e97U, 0xd8918218U, 0xd4d73d78U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 0U))
                {
                    WR1_PROG(REG_00ECH, 0x00002e40U);
                    r_tsip_func101(0xb4a631c3U, 0x70dffad2U, 0x9ed31c2fU, 0xba6c2992U);
                }
                else
                {
                    r_tsip_func100(0xfca733a0U, 0xe8f65ca0U, 0xc33048d3U, 0x928de6faU);
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
                        r_tsip_func100(0x46dad4b0U, 0x7f0649cbU, 0x9d602fd1U, 0x1f04fca4U);
                        WR1_PROG(REG_001CH, 0x00400000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        if (CHCK_STS(REG_001CH, 22U, 0U))
                        {
                            WR1_PROG(REG_00ECH, 0x00002e40U);
                            r_tsip_func101(0x334d1582U, 0xa815548fU, 0xda2c8b50U, 0x5de74002U);
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
                            r_tsip_func101(0xb8b57dddU, 0x986fbb30U, 0x6c6b254aU, 0x6cf9b2f1U);
                        }
                    }

                    WR1_PROG(REG_00ECH, 0x38008a40U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x00000080U);
                    WR1_PROG(REG_001CH, 0x00260000U);
                    r_tsip_func100(0x30c651cfU, 0x20c3b9a5U, 0x9d193862U, 0x09d4d970U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        r_tsip_func101(0x10bc8a8aU, 0x92657debU, 0x881a17b7U, 0xb34976d3U);
                        break;
                    }
                    else
                    {
                        r_tsip_func101(0x65c28c42U, 0x238a097fU, 0x700723aeU, 0xe98e1456U);
                    }
                }
            }

            WR1_PROG(REG_00ECH, 0x38000a4bU);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x18776bb7U, 0xb5cc63b7U, 0xcf12a38eU, 0xa7416e8aU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x00002e20U);
                WR1_PROG(REG_00ECH, 0x38008a20U);
                WR1_PROG(REG_00ECH, 0x00000002U);
                WR1_PROG(REG_00E0H, 0x00000080U);
                WR1_PROG(REG_001CH, 0x00260000U);
                r_tsip_func100(0xb297957fU, 0xbadee085U, 0xa933fbc7U, 0x811b7f07U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func101(0xc1710d96U, 0xa7869548U, 0xc6c31085U, 0xac59df53U);
                    break;
                }
                else
                {
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000e0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    r_tsip_func101(0x6b077df7U, 0x313beac1U, 0x9f3b40f1U, 0xc35a9bfdU);
                }
            }
            else
            {
                r_tsip_func101(0xa89eb0d5U, 0x1d176c08U, 0x6b32bf05U, 0xbd50a794U);
            }
        }
    }

    WR1_PROG(REG_00ECH, 0x38008a20U);
    WR1_PROG(REG_00ECH, 0x00000002U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0xfa9dfd0dU, 0x92fa0c51U, 0xbefd76dbU, 0xd32927f6U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x80c272bfU, 0x798c0552U, 0xad6477a7U, 0x2a32cebbU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }

    r_tsip_func100(0xe2afb0c6U, 0x343806f0U, 0x248a941eU, 0x3a860237U);
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

    r_tsip_func100(0xc8a20deeU, 0x53d4c667U, 0xb32ef976U, 0xb3eca7e9U);
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
        r_tsip_func100(0x31e519d5U, 0x1edd10f2U, 0x6bc9b52fU, 0xa44e235dU);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func101(0xb34b109aU, 0xb13774e1U, 0x76fffc52U, 0x049e91eeU);
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
            r_tsip_func101(0x68b81b0fU, 0x7e73f933U, 0xbcf8597cU, 0xbd1e646dU);
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
    WR1_PROG(REG_00ECH, 0x00010001U);
    WR1_PROG(REG_0024H, 0x000005c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    while (1)
    {
        r_tsip_func100(0x52ea09ecU, 0xbc67002bU, 0xb020ea1aU, 0xa4a942cfU);
        r_tsip_func103();
        r_tsip_func100(0xdfdc9d73U, 0x0f9874a8U, 0x995c9fa1U, 0xc2a5e0e1U);
        WR1_PROG(REG_0104H, 0x00000052U);
        WR1_PROG(REG_00C4H, 0x01080c04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        r_tsip_func100(0xf57ddbbaU, 0x1356d101U, 0x0290dda5U, 0xf0e7a408U);
        WR1_PROG(REG_0104H, 0x00000152U);
        WR1_PROG(REG_00C4H, 0x00440a04U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_00C4H, 0x00090e14U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01689008U));
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_00E0H, 0x80a0000aU);
        WR1_PROG(REG_0000H, 0x00008383U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x282aa3a9U, 0xbd04e58eU, 0xf1e07890U, 0xc9b9602dU);
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

        r_tsip_func100(0x54205b8dU, 0x4916d488U, 0xfcf13cd1U, 0x843fe26bU);
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
        r_tsip_func100(0xec41ae65U, 0xa75f202cU, 0x821fa55eU, 0xad5123feU);
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
            r_tsip_func101(0x2daf80e9U, 0xdfecbb4bU, 0xc0151bb8U, 0x123ce3adU);
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
            WR1_PROG(REG_00E0H, 0x81a0000aU);
            WR1_PROG(REG_0000H, 0x00003883U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func101(0xd5da3f65U, 0xb0e9970bU, 0x3539ef91U, 0x07a7a4d1U);
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
    r_tsip_func100(0x9f501078U, 0xda0d4d10U, 0x0711bbffU, 0xe4d9a738U);
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
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    r_tsip_func100(0x51222374U, 0xc4a5613cU, 0x7357834fU, 0x3daf6a03U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xb63d2953U, 0xde92449aU, 0x86429667U, 0x5dcad666U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x9fa6326bU, 0x72db485bU, 0xc0619d06U, 0x1958f9c7U);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01241e7bU));
    r_tsip_func100(0xb20cba29U, 0x931e6c00U, 0x327656efU, 0x517ffe5cU);
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
    r_tsip_func100(0x0eb009dfU, 0xd60f2a3fU, 0x6675a954U, 0x4909c8ffU);
    WR1_PROG(REG_00C4H, 0x00e00884U);
    WR1_PROG(REG_00E0H, 0x810101c0U);
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
    r_tsip_func100(0x94efcbfcU, 0xfde4f2ebU, 0x79ccf143U, 0x6ac9300cU);
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
    r_tsip_func100(0x85379fe6U, 0x75122466U, 0x6f31afe1U, 0xa571fab0U);
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
    r_tsip_func100(0x64c7dc12U, 0xda4ba560U, 0x595b98e2U, 0xd5a665b6U);
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
    r_tsip_func100(0x433357a0U, 0x2d2b1cb7U, 0x757bd2d3U, 0xe8f23cc7U);
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
    r_tsip_func100(0xeeb5f45eU, 0xfbd4cc5fU, 0x62f97077U, 0xdf972b98U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_00C4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xa053e2e0U, 0xe779b12bU, 0xbc93ddc7U, 0x4d581020U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x74c183f7U, 0x39c679e7U, 0xaf00aa0aU, 0x32307d8cU);
    WR1_PROG(REG_0104H, 0x00000152U);
    WR1_PROG(REG_00C4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00C4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0185ce17U));
    r_tsip_func100(0x78a762cbU, 0x92ce3e23U, 0xaa283a8bU, 0xececff4aU);
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
    r_tsip_func100(0x5b2b8147U, 0xbc198349U, 0xa3ac1400U, 0x781442b3U);
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
    r_tsip_func100(0xca44fa22U, 0x440eb6d2U, 0xab5f6144U, 0x5152fedbU);
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
    r_tsip_func100(0x42cf3cdfU, 0x2b8bcdddU, 0x093e3c31U, 0xd26247a1U);
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
    r_tsip_func100(0x984088ddU, 0xbf19df52U, 0x3bd63e7fU, 0xd2db530aU);
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
    r_tsip_func102(0xb24c9aa9U, 0xc96689dfU, 0xfc5e90d1U, 0x4ca9ed57U);
    WR1_PROG(REG_01BCH, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
