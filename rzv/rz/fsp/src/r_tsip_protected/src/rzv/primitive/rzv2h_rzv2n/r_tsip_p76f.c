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

tsip_ret_t r_tsip_p76f (const uint32_t InData_Cmd[],
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
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_0000H, 0x00003523U);
    WR1_PROG(REG_0074H, 0x00000008U);
    WR1_PROG(REG_002CH, 0x00000010U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_007CH, 0x00000011U);
    WR1_PROG(REG_0104H, 0x00000754U);
    WR1_PROG(REG_0074H, 0x00000004U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x6a09e667U));
    WR1_PROG(REG_0100H, bswap_32big(0xbb67ae85U));
    WR1_PROG(REG_0100H, bswap_32big(0x3c6ef372U));
    WR1_PROG(REG_0100H, bswap_32big(0xa54ff53aU));
    WR1_PROG(REG_0100H, bswap_32big(0x510e527fU));
    WR1_PROG(REG_0100H, bswap_32big(0x9b05688cU));
    WR1_PROG(REG_0100H, bswap_32big(0x1f83d9abU));
    WR1_PROG(REG_0100H, bswap_32big(0x5be0cd19U));
    WR1_PROG(REG_0074H, 0x00000002U);
    r_tsip_func002();
    WR1_PROG(REG_0000H, 0x00005323U);
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
    WR1_PROG(REG_0100H, bswap_32big(0x00000300U));
    WAIT_STS(REG_0074H, 18U, 0U);
    WR1_PROG(REG_0074H, 0x00000000U);
    WR1_PROG(REG_001CH, 0x00001600U);
    WR1_PROG(REG_00E0H, 0x80010000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0104H, 0x00000068U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x38000c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    r_tsip_func100(0xb78d0cfbU, 0x440b0b75U, 0xe5ab133dU, 0x1ebc3aceU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func100(0xab91880aU, 0x09266399U, 0xdfa6806dU, 0x09ff472cU);
        WR1_PROG(REG_0074H, 0x00000008U);
        WR1_PROG(REG_0004H, 0x00000523U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_MAC[0]);
        RD1_ADDR(REG_0100H, &OutData_MAC[1]);
        RD1_ADDR(REG_0100H, &OutData_MAC[2]);
        RD1_ADDR(REG_0100H, &OutData_MAC[3]);
        RD1_ADDR(REG_0100H, &OutData_MAC[4]);
        RD1_ADDR(REG_0100H, &OutData_MAC[5]);
        RD1_ADDR(REG_0100H, &OutData_MAC[6]);
        RD1_ADDR(REG_0100H, &OutData_MAC[7]);
        r_tsip_func102(0x02606b5bU, 0xf7987f24U, 0xd553ae2aU, 0xf95e5603U);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_PASS;
    }
    else
    {
        WR1_PROG(REG_0104H, 0x00000068U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &InData_length[0]);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x3420a820U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000004U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00260000U);
        WR1_PROG(REG_00ECH, 0x3420a820U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00000021U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x4f2f39c5U, 0xb0685a89U, 0xf4fefa3fU, 0x7f74db56U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0x2f297c32U, 0xc24872c2U, 0x3bf2eec0U, 0x82bc0723U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00008523U);
            WR1_PROG(REG_0074H, 0x00000008U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00ECH, 0x00000800U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            for (iLoop = 0; iLoop < 32; iLoop = iLoop + 1)
            {
                WR1_PROG(REG_00ECH, 0x3c002be1U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x12003c1fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00002fe0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
            }

            WR1_PROG(REG_00A4H, 0x00040805U);
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8188001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x00001813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_00A4H, 0x00050805U);
            WR1_PROG(REG_0000H, 0x00001813U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0104H, 0x00000761U);
            WR1_PROG(REG_00A4H, 0x00900c05U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_MAC[0]);
            WR1_ADDR(REG_0100H, &InData_MAC[1]);
            WR1_ADDR(REG_0100H, &InData_MAC[2]);
            WR1_ADDR(REG_0100H, &InData_MAC[3]);
            WR1_PROG(REG_00A4H, 0x00900c45U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_MAC[4]);
            WR1_ADDR(REG_0100H, &InData_MAC[5]);
            WR1_ADDR(REG_0100H, &InData_MAC[6]);
            WR1_ADDR(REG_0100H, &InData_MAC[7]);
            r_tsip_func100(0xe1708749U, 0xefe3149aU, 0x8bfe6ba7U, 0x09ee5411U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x6a718fd4U, 0xfe9f16e5U, 0x58134690U, 0x6e53ba13U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                r_tsip_func102(0xa15f0d77U, 0x78be29f8U, 0x70f34bbdU, 0xe08688a5U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_PASS;
            }
        }
    }
}
