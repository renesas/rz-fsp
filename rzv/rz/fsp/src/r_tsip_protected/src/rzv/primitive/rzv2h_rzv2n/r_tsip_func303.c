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

void r_tsip_func303 (const uint32_t ARG1[])
{
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
    WR1_PROG(REG_0028H, 0x00870001U);
    OFS_ADR = 128;
    r_tsip_func100(0xe4334a1eU, 0x246b52d3U, 0x052d5e38U, 0x2c42777aU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00C4H, 0x00090805U);
    WR1_PROG(REG_00E0H, 0x8184001eU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xe473e88dU, 0x051047f9U, 0x0b7ce96fU, 0xd7b98080U);
    r_tsip_func004(OFS_ADR);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000bcd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000015U);
    WR1_PROG(REG_0104H, 0x00000767U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &ARG1[0]);
    WR1_ADDR(REG_0100H, &ARG1[1]);
    WR1_ADDR(REG_0100H, &ARG1[2]);
    WR1_ADDR(REG_0100H, &ARG1[3]);
    WR1_ADDR(REG_0100H, &ARG1[4]);
    WR1_ADDR(REG_0100H, &ARG1[5]);
    WR1_ADDR(REG_0100H, &ARG1[6]);
    WR1_ADDR(REG_0100H, &ARG1[7]);
    WR1_PROG(REG_002CH, 0x00000010U);
    WR1_PROG(REG_0104H, 0x00000767U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &ARG1[8]);
    WR1_ADDR(REG_0100H, &ARG1[9]);
    WR1_ADDR(REG_0100H, &ARG1[10]);
    WR1_ADDR(REG_0100H, &ARG1[11]);
    WR1_ADDR(REG_0100H, &ARG1[12]);
    WR1_ADDR(REG_0100H, &ARG1[13]);
    WR1_ADDR(REG_0100H, &ARG1[14]);
    WR1_ADDR(REG_0100H, &ARG1[15]);
    WR1_PROG(REG_00ECH, 0x0000b7e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00000140U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x8088001fU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x00000024U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x000070d0U);
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
    WR1_PROG(REG_0024H, 0x00001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000060c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000d91U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    WR1_PROG(REG_0024H, 0x00000dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    WR1_PROG(REG_0024H, 0x000019c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00001191U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00000591U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_001CH, 0x00001f00U);
    WR1_PROG(REG_001CH, 0x00210000U);
    r_tsip_func100(0xaf3e09d7U, 0x9065f747U, 0x23fcf2d7U, 0x934c828eU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_00ECH, 0x00000800U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func101(0x787cb5a5U, 0xaec790d1U, 0xe1f8cb17U, 0x518dac16U);
    }
    else
    {
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00005004U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00008404U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
        {
            WR1_PROG(REG_00ECH, 0x0000381fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
            {
                WR1_PROG(REG_0024H, 0x0000102cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x3800d81fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x00000080U);
                WR1_PROG(REG_001CH, 0x00A60000U);
                WR1_PROG(REG_00ECH, 0x00016c00U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func100(0x0bb589f0U, 0xbf875a59U, 0x0a498d76U, 0x04990441U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    WR1_PROG(REG_0024H, 0x0000082cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    r_tsip_func101(0x96b477cbU, 0x5200042cU, 0x51e6994fU, 0xdf1ef7d7U);
                }
                else
                {
                    r_tsip_func101(0x5221bdfbU, 0x45d78d2eU, 0x5f88b41eU, 0xc0b253b9U);
                }
            }

            WR1_PROG(REG_00ECH, 0x000027e1U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0x06bbec4eU, 0x392225c5U, 0x19c423afU, 0x61af1986U);
        }

        WR1_PROG(REG_00ECH, 0x00008be0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000120U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00007c1fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_001CH, 0x00602000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func100(0x07e93c93U, 0x9131b2cdU, 0xc408d34aU, 0x721995e8U);
        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000060c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0000H, 0x00003523U);
        WR1_PROG(REG_0074H, 0x00000008U);
        WR1_PROG(REG_002CH, 0x00000011U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000094aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088000aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000023U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00000c2cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000060c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000094d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000c2cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000009c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000e0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000008U);
        WR1_PROG(REG_0024H, 0x8000d4d0U);
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
        WR1_PROG(REG_0034H, 0x00000003U);
        WR1_PROG(REG_0024H, 0x800048d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func005(OFS_ADR);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x800088d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000802U);
        WR1_PROG(REG_0024H, 0x8000acd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b540U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088000aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000025U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000009c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001028U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x100019b1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019a1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000e0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8088001fU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000021U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000842U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b420U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b480U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000100U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x0000b7a0U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x000000e4U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        r_tsip_func100(0x82d6b07bU, 0xc4e05715U, 0x52ed7647U, 0xaae67041U);
        WR1_PROG(REG_00E0H, 0x81010380U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
        {
            r_tsip_func101(0xb2dd2a30U, 0x1ba29b46U, 0xaab5bef9U, 0x997b1113U);
            r_tsip_func302();
            if (S_RAM[0] == 0x00000001U)
            {
                break;
            }

            r_tsip_func101(0xfb7c0e77U, 0xca76c3bdU, 0x20b0d2faU, 0x479c244eU);
        }

        WR1_PROG(REG_00ECH, 0x0000b540U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000040U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x8188000aU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_0000H, 0x00003823U);
        WR1_PROG(REG_002CH, 0x0000001aU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x00001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0xa2cbc117U, 0x52f472b8U, 0x246eb68eU, 0x643a0789U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_00ECH, 0x00000800U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func101(0x642f1722U, 0xace9aa82U, 0x60b4417eU, 0x757daf9aU);
        }
        else
        {
            WR1_PROG(REG_0034H, 0x00000003U);
            WR1_PROG(REG_0024H, 0x800048d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800068d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00005004U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00008404U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b420U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000004U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x0000381fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_0024H, 0x0000102cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x3800d81fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x00000080U);
                    WR1_PROG(REG_001CH, 0x00A60000U);
                    WR1_PROG(REG_00ECH, 0x00016c00U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func100(0xc09b56e2U, 0x15345c2aU, 0x14fc82b2U, 0x0d72bda2U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        WR1_PROG(REG_0024H, 0x0000082cU);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x100019b1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x000019a1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        WR1_PROG(REG_0024H, 0x000080c1U);
                        WAIT_STS(REG_0024H, 21U, 0U);
                        r_tsip_func101(0xf33cbecaU, 0xc740bf98U, 0x02a9a907U, 0xee6eb3c5U);
                    }
                    else
                    {
                        r_tsip_func101(0xefc3d7c4U, 0xce111e78U, 0x585f81a3U, 0xf6a6dd1aU);
                    }
                }

                WR1_PROG(REG_00ECH, 0x000027e1U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0xf9e1ae1aU, 0x63770d92U, 0xb4e6f023U, 0x4ec22c20U);
            }

            WR1_PROG(REG_00ECH, 0x00008be0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000120U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00007c1fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_001CH, 0x00602000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0034H, 0x00000002U);
            WR1_PROG(REG_0024H, 0x80000dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x800011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000a2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000082cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000082cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000a2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x800015c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000e2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000c2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000c2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000c2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000e2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000e2cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000015c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00001028U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000e0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000002U);
            WR1_PROG(REG_0024H, 0x800009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000060U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8188000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8188000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00003823U);
            WR1_PROG(REG_002CH, 0x0000001bU);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0024H, 0x0000082cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000002U);
            WR1_PROG(REG_0024H, 0x80008cd0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x0000082cU);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x100019b1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000019a1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800060c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x800011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000002U);
            WR1_PROG(REG_0024H, 0x800009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000002U);
            WR1_PROG(REG_0024H, 0x80000dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x8000a0c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000022U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b540U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000C0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088000aU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000023U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x0000b7e0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008323U);
            WR1_PROG(REG_002CH, 0x00000021U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000bdeU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000842U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000b420U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000004U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000b480U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000100U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x0000b7a0U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x000000e5U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000b9cU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            r_tsip_func100(0x6e8ea96fU, 0x7e96941aU, 0x1419aa61U, 0xc78c3b6aU);
            WR1_PROG(REG_00E0H, 0x81010380U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0004H, 0x00000607U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
            for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
            {
                r_tsip_func101(0x9d2b38e8U, 0x1e1f7dd3U, 0x99c5e0c8U, 0x50c29c1eU);
                r_tsip_func302();
                if (S_RAM[0] == 0x00000001U)
                {
                    break;
                }

                r_tsip_func101(0xa658c315U, 0xf2054060U, 0xddf37e19U, 0xe92b1259U);
            }

            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x15c7184fU, 0x3e789db8U, 0x41ef6c9dU, 0x720728f6U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x00000800U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                r_tsip_func101(0x2e33c706U, 0xea0633ccU, 0xcc91c431U, 0x3dadbe1dU);
            }
            else
            {
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000080U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x8188000aU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x0000001aU);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x0000b540U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000000C0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x8188000aU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x0000001bU);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0024H, 0x00009cd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000102cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000070d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000002U);
                WR1_PROG(REG_0024H, 0x800048d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000200U);
                WR1_PROG(REG_0024H, 0x80000a41U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000200U);
                WR1_PROG(REG_0024H, 0x80000951U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000002U);
                WR1_PROG(REG_0024H, 0x80004cd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000280U);
                WR1_PROG(REG_0024H, 0x800019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000080U);
                WR1_PROG(REG_0024H, 0x800080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000e0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000102cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000200U);
                WR1_PROG(REG_0024H, 0x900019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000280U);
                WR1_PROG(REG_0024H, 0x800019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800015c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000941U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800015c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000951U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000080U);
                WR1_PROG(REG_0024H, 0x800040c2U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000200U);
                WR1_PROG(REG_0024H, 0x800012c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00008cd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00008cd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000102cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000951U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x800080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000149U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000d51U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000080U);
                WR1_PROG(REG_0024H, 0x800080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000080U);
                WR1_PROG(REG_0024H, 0x800060c2U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000c2cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000060c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000d51U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000145U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x8000a0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001dc0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00001f00U);
                WR1_PROG(REG_001CH, 0x00210000U);
                r_tsip_func100(0x3c9c3a7fU, 0x5fcd3f82U, 0xc4665c54U, 0x16909803U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    WR1_PROG(REG_00ECH, 0x00000800U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    r_tsip_func101(0x28252bd1U, 0x6f59f9d9U, 0x7859eebdU, 0xfd6b99a7U);
                }
                else
                {
                    WR1_PROG(REG_0034H, 0x00000003U);
                    WR1_PROG(REG_0024H, 0x800048d0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000800U);
                    WR1_PROG(REG_0024H, 0x800068d0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00001dc0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000080c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000591U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000591U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000a0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00005004U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00008404U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x0000b420U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000004U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x0000b7e0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000100U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x8088001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00008323U);
                    WR1_PROG(REG_002CH, 0x00000021U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    for (iLoop = 0; iLoop < 8; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_00ECH, 0x0000381fU);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
                        {
                            WR1_PROG(REG_0024H, 0x0000102cU);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x100019b1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000019a1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_0024H, 0x000080c1U);
                            WAIT_STS(REG_0024H, 21U, 0U);
                            WR1_PROG(REG_00ECH, 0x3800d81fU);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            WR1_PROG(REG_00E0H, 0x00000080U);
                            WR1_PROG(REG_001CH, 0x00A60000U);
                            WR1_PROG(REG_00ECH, 0x00016c00U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            r_tsip_func100(0x7db95cb0U, 0xdfd35b46U, 0x3fef9ed5U, 0x3f9ee94fU);
                            WR1_PROG(REG_001CH, 0x00400000U);
                            WR1_PROG(REG_01D0H, 0x00000000U);
                            if (CHCK_STS(REG_001CH, 22U, 1U))
                            {
                                WR1_PROG(REG_0024H, 0x0000082cU);
                                WAIT_STS(REG_0024H, 21U, 0U);
                                WR1_PROG(REG_0024H, 0x100019b1U);
                                WAIT_STS(REG_0024H, 21U, 0U);
                                WR1_PROG(REG_0024H, 0x000019a1U);
                                WAIT_STS(REG_0024H, 21U, 0U);
                                WR1_PROG(REG_0024H, 0x000080c1U);
                                WAIT_STS(REG_0024H, 21U, 0U);
                                r_tsip_func101(0x7bece701U, 0x1e87fe72U, 0x7f38d902U, 0x557f50ceU);
                            }
                            else
                            {
                                r_tsip_func101(0x2cacd566U, 0xdb1bf1c3U, 0xb8103efcU, 0xa707d6a9U);
                            }
                        }

                        WR1_PROG(REG_00ECH, 0x000027e1U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        r_tsip_func101(0xe89cbd60U, 0x36a0f572U, 0x5595872eU, 0x49290062U);
                    }

                    WR1_PROG(REG_00ECH, 0x00008be0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000120U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00007c1fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_001CH, 0x00602000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0034H, 0x00000002U);
                    WR1_PROG(REG_0024H, 0x80000dc0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000009c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000a0c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0034H, 0x00000008U);
                    WR1_PROG(REG_0024H, 0x800011c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000a2cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000082cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x0000082cU);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x0000b7e0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000140U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x8188001fU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00003823U);
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
                    WR1_PROG(REG_0024H, 0x000088d0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00009004U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00001028U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x100019b1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000019a1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x000040c1U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_00ECH, 0x0000b540U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00E0H, 0x8188000aU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_0000H, 0x00003823U);
                    WR1_PROG(REG_002CH, 0x00000014U);
                    WAIT_STS(REG_0000H, 25U, 0U);
                    WR1_PROG(REG_001CH, 0x00001800U);
                    WR1_PROG(REG_0024H, 0x000009c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00001991U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_001CH, 0x00001f00U);
                    WR1_PROG(REG_001CH, 0x00210000U);
                    WR1_PROG(REG_0024H, 0x000019c0U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_0024H, 0x00000991U);
                    WAIT_STS(REG_0024H, 21U, 0U);
                    WR1_PROG(REG_001CH, 0x00001f00U);
                    WR1_PROG(REG_001CH, 0x00210000U);
                    r_tsip_func100(0xdf6fd38eU, 0x9ff9a12dU, 0x530d7bc4U, 0x1659a4f0U);
                    WR1_PROG(REG_001CH, 0x00400000U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    if (CHCK_STS(REG_001CH, 22U, 1U))
                    {
                        WR1_PROG(REG_00ECH, 0x00000800U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        r_tsip_func101(0x6c3e97d4U, 0x0fc2b0caU, 0xbbe5157aU, 0x692c84ddU);
                    }
                    else
                    {
                        WR1_PROG(REG_00ECH, 0x00000800U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        WR1_PROG(REG_00ECH, 0x0000d000U);
                        WR1_PROG(REG_01D0H, 0x00000000U);
                        r_tsip_func101(0x662608f8U, 0x4139cab8U, 0xfa46886bU, 0xc3024748U);
                    }
                }
            }
        }
    }

    WR1_PROG(REG_00ECH, 0x38000c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_00ECH, 0x00007c1bU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
}
