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
    WR1_PROG(REG_0104H, 0x00000068U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_ADDR(REG_0100H, &InData_Cmd[0]);
    WR1_PROG(REG_00ECH, 0x38000c00U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    r_tsip_func100(0x919ff3a6U, 0x86c7ee4dU, 0x5cda8541U, 0x0fa082c4U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func100(0xb7bd2003U, 0xc6fc6d65U, 0x5f91a39fU, 0x550b2df5U);
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
        r_tsip_func102(0x5264f668U, 0xce36da06U, 0x8cd5f7ffU, 0x9c5d3b37U);
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
        WR1_PROG(REG_00ECH, 0x00000021U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x46930c5eU, 0xf0921468U, 0xf84877faU, 0x4b2b7983U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xc702931aU, 0x843d229cU, 0xe8678ee1U, 0xa9570563U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_00E0H, 0x8088001fU);
            WR1_PROG(REG_0000H, 0x00008523U);
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
            r_tsip_func100(0x09142e02U, 0xfb64fd1eU, 0xf795c5a3U, 0xb7fffe25U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x76ab612aU, 0xeecb6e17U, 0x6d7154acU, 0x09b22444U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                r_tsip_func102(0xbaee2197U, 0x721981eaU, 0x1b604d4dU, 0x4874b51bU);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_PASS;
            }
        }
    }
}
