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

tsip_ret_t r_tsip_pdcf (const uint32_t InData_Cmd[],
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
    WR1_PROG(REG_0100H, bswap_32big(0xc1059ed8U));
    WR1_PROG(REG_0100H, bswap_32big(0x367cd507U));
    WR1_PROG(REG_0100H, bswap_32big(0x3070dd17U));
    WR1_PROG(REG_0100H, bswap_32big(0xf70e5939U));
    WR1_PROG(REG_0100H, bswap_32big(0xffc00b31U));
    WR1_PROG(REG_0100H, bswap_32big(0x68581511U));
    WR1_PROG(REG_0100H, bswap_32big(0x64f98fa7U));
    WR1_PROG(REG_0100H, bswap_32big(0xbefa4fa4U));
    WR1_PROG(REG_0074H, 0x00000002U);
    r_tsip_func002();
    WR1_PROG(REG_0000H, 0x0000531fU);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x00000307U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000054U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x80000000U));
    WR1_PROG(REG_00F8H, 0x00000040U);
    WR1_PROG(REG_0104H, 0x00000154U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x000002E0U));
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
    r_tsip_func100(0x3ca9f71aU, 0x91ed21d5U, 0xc76d9b7dU, 0x31901935U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func100(0x07c81da8U, 0x7a2c443dU, 0xd2ea5b0eU, 0x492ea46cU);
        WR1_PROG(REG_0074H, 0x00000008U);
        WR1_PROG(REG_0004H, 0x0000051fU);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(REG_0100H, &OutData_MAC[0]);
        RD1_ADDR(REG_0100H, &OutData_MAC[1]);
        RD1_ADDR(REG_0100H, &OutData_MAC[2]);
        RD1_ADDR(REG_0100H, &OutData_MAC[3]);
        RD1_ADDR(REG_0100H, &OutData_MAC[4]);
        RD1_ADDR(REG_0100H, &OutData_MAC[5]);
        RD1_ADDR(REG_0100H, &OutData_MAC[6]);
        WR1_PROG(REG_0000H, 0x00000507U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func102(0xcd6fb640U, 0x70f36ee9U, 0xf00eeab2U, 0x60db8f02U);
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
        WR1_PROG(REG_00ECH, 0x0000001dU);
        WR1_PROG(REG_01D0H, 0x00000000U);
        WR1_PROG(REG_00E0H, 0x00000080U);
        WR1_PROG(REG_001CH, 0x00A60000U);
        r_tsip_func100(0x47b54159U, 0x9ba66ee2U, 0x5f2133c8U, 0xdc1e2860U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            r_tsip_func102(0xb2315e5bU, 0x2bb9c823U, 0x07d29c2aU, 0x8c740071U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x00000bffU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x8087001fU);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_0000H, 0x0000851fU);
            WR1_PROG(REG_0074H, 0x00000008U);
            WAIT_STS(REG_0000H, 25U, 0U);
            WR1_PROG(REG_001CH, 0x00001800U);
            WR1_PROG(REG_0000H, 0x00000507U);
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
            WR1_PROG(REG_0104H, 0x00000661U);
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
            WR1_PROG(REG_0104H, 0x00000051U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func100(0x915689a1U, 0xb839d27fU, 0x800feec6U, 0x7bc50c98U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x9cbbe2c6U, 0x860bfb2fU, 0x2844d2cfU, 0xcd2ed405U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                r_tsip_func102(0x35c9926cU, 0x2aa2aa26U, 0x4442f58dU, 0x5d7b2fc9U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_PASS;
            }
        }
    }
}
