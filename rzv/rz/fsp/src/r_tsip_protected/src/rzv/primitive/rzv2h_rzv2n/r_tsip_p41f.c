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

tsip_ret_t r_tsip_p41f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Text[],
                        const uint32_t InData_DataT[],
                        const uint32_t InData_DataTLen[],
                        uint32_t       OutData_DataT[])
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
    r_tsip_func100(0x75dd8110U, 0xca07cc82U, 0x22e99ff9U, 0x8834968dU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x8dcf468dU, 0xeafb8aefU, 0xdcf99ac4U, 0xfedb9851U);
        WR1_PROG(REG_01B4H, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
        {
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00A4H, 0x00400a84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func101(0x07b62873U, 0x102a80aeU, 0xaf583804U, 0x787a9b35U);
        }
        else
        {
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00A4H, 0x00500a84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func101(0xb9d28d6aU, 0x39fcd2ceU, 0x08109860U, 0xbc6e93f7U);
        }

        WR1_PROG(REG_00A4H, 0x00040c05U);
        WR1_PROG(REG_0000H, 0x00001113U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
        {
            r_tsip_func100(0x3808e829U, 0xd9a5295cU, 0xb02d913cU, 0x0709f30cU);
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00A4H, 0x00000e95U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_Text[0]);
            WR1_ADDR(REG_0100H, &InData_Text[1]);
            WR1_ADDR(REG_0100H, &InData_Text[2]);
            WR1_ADDR(REG_0100H, &InData_Text[3]);
            WR1_PROG(REG_0004H, 0x00000113U);
            WAIT_STS(REG_0004H, 30U, 1U);
            RD1_ADDR(REG_0100H, &OutData_DataT[0]);
            RD1_ADDR(REG_0100H, &OutData_DataT[1]);
            RD1_ADDR(REG_0100H, &OutData_DataT[2]);
            RD1_ADDR(REG_0100H, &OutData_DataT[3]);
            r_tsip_func102(0x9a9694cbU, 0x2fe8830eU, 0xb25ea08cU, 0xeeb1832eU);
            WR1_PROG(REG_01B4H, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
        else
        {
            WR1_PROG(REG_0104H, 0x00000068U);
            WR1_PROG(REG_00E0H, 0x80010040U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_DataTLen[0]);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x3420a840U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000010U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            WR1_PROG(REG_00ECH, 0x0000b460U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00ECH, 0x34202862U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0xe817e49bU, 0x9bb2bb67U, 0x63ea1eacU, 0x85cd90abU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xe15e4652U, 0x46d9068fU, 0x67677b85U, 0xee78e823U);
                WR1_PROG(REG_01B4H, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_0104H, 0x00000361U);
                WR1_PROG(REG_00A4H, 0x00000e95U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_Text[0]);
                WR1_ADDR(REG_0100H, &InData_Text[1]);
                WR1_ADDR(REG_0100H, &InData_Text[2]);
                WR1_ADDR(REG_0100H, &InData_Text[3]);
                WR1_PROG(REG_00ECH, 0x00000821U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00E0H, 0x80840001U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00008113U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x000034e2U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000568e7U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00026ce7U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00003827U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000b4c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000020U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00003402U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00008c00U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000028c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00008cc0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00004406U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00007421U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00007821U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00003c27U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000034c2U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000a4c0U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x0000001fU);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000568c6U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x000034e6U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00026ce7U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_00ECH, 0x00000821U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_00ECH, 0x3420a8e0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x0000000dU);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x10003c27U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x1000a4e0U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                    WR1_PROG(REG_00ECH, 0x00000004U);
                    WR1_PROG(REG_01D0H, 0x00000000U);
                }

                WR1_PROG(REG_00A4H, 0x00040805U);
                WR1_PROG(REG_00E0H, 0x81840001U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                WR1_PROG(REG_0000H, 0x00001813U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0104H, 0x00000361U);
                WR1_PROG(REG_00A4H, 0x00900c05U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_DataT[0]);
                WR1_ADDR(REG_0100H, &InData_DataT[1]);
                WR1_ADDR(REG_0100H, &InData_DataT[2]);
                WR1_ADDR(REG_0100H, &InData_DataT[3]);
                r_tsip_func100(0xd48bcd3bU, 0x3403fbefU, 0x87d82aadU, 0x98a1e3c2U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x43dbb59fU, 0x071825cbU, 0xddca10a7U, 0x581bf6a8U);
                    WR1_PROG(REG_01B4H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_AUTH_FAIL;
                }
                else
                {
                    r_tsip_func102(0xd18ace93U, 0xd0b20ab8U, 0xbf7f988dU, 0x90a66b2aU);
                    WR1_PROG(REG_01B4H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_PASS;
                }
            }
        }
    }
}
