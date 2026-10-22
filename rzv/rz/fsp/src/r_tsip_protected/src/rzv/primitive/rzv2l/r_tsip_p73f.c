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

tsip_ret_t r_tsip_p73f (const uint32_t InData_Cmd[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       OutData_MAC[])
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
    WR1_PROG(REG_0074H, 0x00000000U);
    WR1_PROG(REG_0028H, 0x00840001U);
    WR1_PROG(REG_0000H, 0x00003517U);
    WR1_PROG(REG_0074H, 0x00000008U);
    WR1_PROG(REG_002CH, 0x00000010U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_007CH, 0x00000001U);
    WR1_PROG(REG_0104H, 0x00000454U);
    WR1_PROG(REG_0074H, 0x00000004U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x67452301U));
    WR1_PROG(REG_0100H, bswap_32big(0xefcdab89U));
    WR1_PROG(REG_0100H, bswap_32big(0x98badcfeU));
    WR1_PROG(REG_0100H, bswap_32big(0x10325476U));
    WR1_PROG(REG_0100H, bswap_32big(0xc3d2e1f0U));
    WR1_PROG(REG_0074H, 0x00000002U);
    r_tsip_func002();
    WR1_PROG(REG_0000H, 0x00005317U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000054U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x80000000U));
    WR1_PROG(REG_00F8H, 0x00000040U);
    WR1_PROG(REG_0104H, 0x00000154U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x000002a0U));
    WAIT_STS(REG_0074H, 18U, 0U);
    WR1_PROG(REG_0074H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00001600U);
    WR1_PROG(REG_00E0H, 0x80010000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x38000c00U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    r_tsip_func100(0xff45e1e3U, 0xf4070a9cU, 0x693e6d22U, 0x8e777c03U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func100(0x532ac1ebU, 0x39d601d1U, 0x7d411f43U, 0x7c58747aU);
        WR1_PROG(REG_0074H, 0x00000008U);
        WR1_PROG(REG_0004H, 0x00000517U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_MAC[0]);
        RD1_ADDR(REG_0100H, &OutData_MAC[1]);
        RD1_ADDR(REG_0100H, &OutData_MAC[2]);
        RD1_ADDR(REG_0100H, &OutData_MAC[3]);
        RD1_ADDR(REG_0100H, &OutData_MAC[4]);
        r_tsip_func102(0xb3900414U, 0xa92a4c25U, 0xa31d17bcU, 0x4f4ea432U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
    else
    {
        WR1_PROG(REG_0104H, 0x00000068U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_length[0]);
        WR1_PROG(REG_00ECH, 0x3420a820U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        WR1_PROG(REG_00ECH, 0x3420a820U);
        WR1_PROG(REG_00ECH, 0x00000015U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0xf1563577U, 0xf72f67cdU, 0x6776271cU, 0x749f7be5U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x1be53a06U, 0xea820e1eU, 0x031b6ab5U, 0x4625daa3U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_00E0H, 0x8085001fU);
            WR1_PROG(REG_0000H, 0x00008517U);
            WR1_PROG(REG_0074H, 0x00000008U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000800U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x3c002be1U);
                WR1_PROG(REG_00ECH, 0x12003c1fU);
                WR1_PROG(REG_00ECH, 0x00002fe0U);
            }

            WR1_PROG(REG_00A4H, 0x00040805U);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_0000H, 0x00001813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00A4H, 0x00050805U);
            WR1_PROG(REG_0000H, 0x00001813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0104H, 0x00000461U);
            WR1_PROG(REG_00A4H, 0x00900c05U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_MAC[0]);
            WR1_ADDR(REG_0100H, &InData_MAC[1]);
            WR1_ADDR(REG_0100H, &InData_MAC[2]);
            WR1_ADDR(REG_0100H, &InData_MAC[3]);
            WR1_PROG(REG_00A4H, 0x00900c44U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_MAC[4]);
            r_tsip_func100(0xcd4df504U, 0xc5926175U, 0xdd2db818U, 0x5352f802U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xbc0963dfU, 0x48dd5e45U, 0x0f079e6eU, 0x16d5d359U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                r_tsip_func102(0x46738438U, 0xb1290a8fU, 0x82e9c7e3U, 0x1deaa7b6U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_PASS;
            }
        }
    }
}
