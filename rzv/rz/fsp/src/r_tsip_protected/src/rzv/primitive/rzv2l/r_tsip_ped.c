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

tsip_ret_t r_tsip_ped (uint32_t OutData_PubKeyIndex[], uint32_t OutData_PrivKeyIndex[])
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
    if (0x0U != RD1_MASK(REG_01B8H, 0x1eU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x0000ed02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0x532c4e78U, 0x641c99c7U, 0xffd1eeaaU, 0xd28d3039U);
    WR1_PROG(REG_0028H, 0x008f0001U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000440U);
    WR1_PROG(REG_00E0H, 0x81010000U);
    WR1_PROG(REG_0004H, 0x00000606U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    OFS_ADR = S_RAM[0];
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000edU));
    r_tsip_func101(0x645c214dU, 0x74b96a26U, 0xda8bd169U, 0xb17f041fU);
    r_tsip_func078(OFS_ADR);
    r_tsip_func100(0x083b22b1U, 0xdf84c11bU, 0x78cbcd07U, 0xce40b20cU);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000025U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000040U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x927fbd57U, 0xa08b0674U, 0xc1306fb8U, 0xa9298992U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000011U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x8dcb3094U, 0x60e97f8dU, 0x6d5d356dU, 0x62e87f1eU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0xd314d8adU, 0x22ee02bbU, 0xac2f51b5U, 0x7965b42aU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x000019c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0018H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x0000a206U);
    WAIT_STS(REG_0018H, 10U, 0U);
    WR1_PROG(REG_0018H, 0x00000000U);
    WR1_PROG(REG_0024H, 0x000016c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000682U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000a0c2U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000edU));
    r_tsip_func101(0xe69d1a27U, 0x5b3a4db0U, 0x6fdbc2cfU, 0xe3894cf8U);
    r_tsip_func079(OFS_ADR);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x800088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x8000acd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000dcd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000084d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00021028U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x100019b1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00008cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00001028U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x100019b1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000e0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func100(0x78479075U, 0x664ffdb3U, 0x0126ace0U, 0xe8cf5eddU);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x8190001fU);
    WR1_PROG(REG_0000H, 0x00003843U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x000084d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00021028U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x100019b1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    r_tsip_func103();
    r_tsip_func100(0x5ac2ddeaU, 0x1d3879aaU, 0x8bad7ac4U, 0x83ba6cb6U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WR1_PROG(REG_002CH, 0x00000013U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0x8ae2e9ceU, 0xe49faa67U, 0xd0e9f3d2U, 0x067113daU);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0xfe2eae2bU, 0x898f8ae8U, 0x316e5210U, 0x4dc51709U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func103();
    r_tsip_func100(0xac38907bU, 0x9e4823ceU, 0x48633f36U, 0xce6fa6c4U);
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00003213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x00000c28U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x100019b1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000060c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000015c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000d41U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000a0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00E0H, 0x8190001fU);
    WR1_PROG(REG_0000H, 0x00003843U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x000084d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00021028U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x100019b1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000023U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00E0H, 0x8090001fU);
    WR1_PROG(REG_0000H, 0x00008343U);
    WR1_PROG(REG_002CH, 0x00000021U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_00ECH, 0x00000842U);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x0000b480U);
    WR1_PROG(REG_00ECH, 0x00000200U);
    WR1_PROG(REG_00ECH, 0x0000b7a0U);
    WR1_PROG(REG_00ECH, 0x000000edU);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_0004H, 0x00000607U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < 512; iLoop = iLoop + 1)
    {
        r_tsip_func101(0xce4c125fU, 0x985799d2U, 0x3622073dU, 0x26c25e1aU);
        r_tsip_func300();
        if (S_RAM[0] == 0x00000001U)
        {
            break;
        }

        r_tsip_func101(0x2c7c173fU, 0xba65ed36U, 0xd30dd86eU, 0x1f1431abU);
    }

    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0xdf236ab4U, 0x98fbda3aU, 0x468d9e01U, 0x75b32f20U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x98e7818dU, 0xffc064e1U, 0x4b605e2aU, 0xc72a7318U);
        WR1_PROG(REG_01B8H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_0000H, 0x00003843U);
        WR1_PROG(REG_002CH, 0x00000013U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000028U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x000000c0U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000029U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000025U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x800088d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x8000acd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_00E0H, 0x8190001fU);
        WR1_PROG(REG_0000H, 0x00003843U);
        WR1_PROG(REG_002CH, 0x00000012U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00000828U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000e0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000acd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func100(0x2520f03fU, 0x40e6fe24U, 0xf542550cU, 0xf2adce8fU);
        WR1_PROG(REG_00ECH, 0x00000bffU);
        WR1_PROG(REG_00E0H, 0x8090001fU);
        WR1_PROG(REG_0000H, 0x00008343U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_00ECH, 0x00000842U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_00ECH, 0x0000b480U);
        WR1_PROG(REG_00ECH, 0x00000200U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_00ECH, 0x00000009U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 512; iLoop = iLoop + 1)
        {
            r_tsip_func101(0xcd69f59bU, 0x452f2fa9U, 0xb0518eb6U, 0xdb6234b1U);
            r_tsip_func300();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0xcd160c85U, 0xec9467f2U, 0x24b8f0a8U, 0xb42934cfU);
        }

        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x059f49eaU, 0xb31372fdU, 0xe85e113cU, 0x6b71d874U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x5e8d2a8eU, 0xf2f07806U, 0xeda0207eU, 0x49d2476fU);
            WR1_PROG(REG_01B8H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_0024H, 0x00009cd0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_00E0H, 0x8090001fU);
            WR1_PROG(REG_0000H, 0x00008343U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7c0U);
            WR1_PROG(REG_00ECH, 0x00000010U);
            WR1_PROG(REG_0104H, 0x00000058U);
            WR1_PROG(REG_00E0H, 0x800103a0U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x000000edU));
            r_tsip_func101(0x0b44efb1U, 0x77b29139U, 0x6436e261U, 0xea81d75bU);
            r_tsip_func326();
            r_tsip_func301();
            WR1_PROG(REG_0024H, 0x000019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000d91U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x8000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000040U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x0000001aU);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0034H, 0x0000000aU);
            WR1_PROG(REG_0024H, 0x80000a2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800088d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x0000000aU);
            WR1_PROG(REG_0024H, 0x8000082cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000018U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x000000c0U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000019U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_00E0H, 0x8190001fU);
            WR1_PROG(REG_0000H, 0x00003843U);
            WR1_PROG(REG_002CH, 0x00000015U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            r_tsip_func305();
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x94cf0829U, 0xf6fa7abdU, 0xd43ce3c1U, 0x6fdac8ecU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x1fb11f9eU, 0x851f8b52U, 0x35f202efU, 0x35ccef7bU);
                WR1_PROG(REG_01B8H, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_0024H, 0x00009cd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x00000bffU);
                WR1_PROG(REG_00E0H, 0x8090001fU);
                WR1_PROG(REG_0000H, 0x00008343U);
                WR1_PROG(REG_002CH, 0x00000021U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b7c0U);
                WR1_PROG(REG_00ECH, 0x00000010U);
                WR1_PROG(REG_0104H, 0x00000058U);
                WR1_PROG(REG_00E0H, 0x800103a0U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000019U));
                r_tsip_func101(0x31bd30f1U, 0xbe58ed69U, 0x919ad447U, 0x8bc6db0bU);
                r_tsip_func326();
                r_tsip_func301();
                r_tsip_func100(0xf9345511U, 0xecaca843U, 0xbe10c516U, 0x7aa2e515U);
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
                r_tsip_func100(0x5fd6d8d8U, 0x49158f3fU, 0x1413c96aU, 0x30da90c2U);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_00ECH, 0x000001e0U);
                WR1_PROG(REG_00C4H, 0x00080805U);
                WR1_PROG(REG_00E0H, 0x8184000aU);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x3ae534adU, 0xa3b69178U, 0x40b4761cU, 0x47760115U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e15U);
                WR1_PROG(REG_00E0H, 0x81040000U);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0xdc0b32eaU, 0x3866d715U, 0xe9d451adU, 0x6bb3a691U);
                WR1_PROG(REG_0104H, 0x00000152U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e14U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x01febd0dU));
                r_tsip_func100(0xa9d05fd7U, 0x90d4e1e1U, 0xc7f0c7a0U, 0x74773564U);
                WR1_PROG(REG_00D0H, 0x00000300U);
                WR1_PROG(REG_00C4H, 0x02e087b7U);
                WR1_PROG(REG_00ECH, 0x0000b7e0U);
                WR1_PROG(REG_00ECH, 0x00000140U);
                WR1_PROG(REG_00E0H, 0x8190001fU);
                WR1_PROG(REG_0000H, 0x00002843U);
                WR1_PROG(REG_0004H, 0x00000242U);
                for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
                }

                r_tsip_func100(0x8f1d3763U, 0x1040aec8U, 0x9200101fU, 0xe1bc264bU);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00000c84U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x000009c5U);
                WR1_PROG(REG_0000H, 0x00002213U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0004H, 0x00000212U);
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 4]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 5]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 6]);
                RD1_ADDR(REG_0100H, &OutData_PrivKeyIndex[iLoop + 7]);
                r_tsip_func100(0x4f5f03dfU, 0xcbdd814fU, 0x59c23327U, 0xc606c852U);
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
                r_tsip_func100(0x38192783U, 0x60e52b83U, 0xa5bd1ec7U, 0xb7f2869aU);
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
                r_tsip_func100(0x86e34b35U, 0xc7edc8e9U, 0x56644c89U, 0x34bab7d1U);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_00ECH, 0x000001e0U);
                WR1_PROG(REG_00C4H, 0x00080805U);
                WR1_PROG(REG_00E0H, 0x8184000aU);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x6ec79656U, 0xc0525d24U, 0x2dea53d5U, 0x019103faU);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e15U);
                WR1_PROG(REG_00E0H, 0x81040000U);
                WR1_PROG(REG_0000H, 0x00002813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                r_tsip_func100(0x6e8b2db3U, 0xff91db64U, 0xeb647c68U, 0xb7bba9e2U);
                WR1_PROG(REG_0104H, 0x00000152U);
                WR1_PROG(REG_00C4H, 0x00440a04U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00080e14U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x012368adU));
                r_tsip_func100(0x0e540680U, 0xbb3b9b2aU, 0x36ca9249U, 0x7d2f6a7aU);
                WR1_PROG(REG_00D0H, 0x00000300U);
                WR1_PROG(REG_00C4H, 0x02e08887U);
                WR1_PROG(REG_0000H, 0x00002343U);
                WR1_PROG(REG_002CH, 0x00000022U);
                WR1_PROG(REG_0004H, 0x00000242U);
                for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 7]);
                }

                r_tsip_func100(0xc5c20118U, 0x63e91290U, 0x7ebd1b3dU, 0xde8db41aU);
                WR1_PROG(REG_00D0H, 0x00000200U);
                WR1_PROG(REG_00C4H, 0x00e08887U);
                WR1_PROG(REG_0000H, 0x00002333U);
                WR1_PROG(REG_002CH, 0x00000023U);
                WR1_PROG(REG_0004H, 0x00000232U);
                for ( ; iLoop < 28; iLoop = iLoop + 4)
                {
                    WAIT_STS(REG_0004H, 30U, 1U);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[iLoop + 7]);
                }

                r_tsip_func100(0xb25885deU, 0x244c8523U, 0x698bc740U, 0x8bf3f2d5U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00450944U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_00C4H, 0x00e00885U);
                WR1_PROG(REG_0000H, 0x00002313U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0004H, 0x00000212U);
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[32]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[33]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[34]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[35]);
                r_tsip_func100(0x09a1bebdU, 0x4151ef63U, 0x8b15ae1cU, 0x3b1ece76U);
                WR1_PROG(REG_0104H, 0x00000052U);
                WR1_PROG(REG_00C4H, 0x00000cc4U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
                WR1_PROG(REG_0004H, 0x00000212U);
                WAIT_STS(REG_0004H, 30U, 1U);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[36]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[37]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[38]);
                RD1_ADDR(REG_0100H, &OutData_PubKeyIndex[39]);
                r_tsip_func100(0x5ea7bd42U, 0x6b079569U, 0xf2da9310U, 0xe4e84a26U);
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
                r_tsip_func102(0x53cee227U, 0xde36295bU, 0xf3edb5c3U, 0x94a3a882U);
                WR1_PROG(REG_01B8H, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_PASS;
            }
        }
    }
}
