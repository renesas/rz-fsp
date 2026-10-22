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

tsip_ret_t r_tsip_p44f (const uint32_t InData_Cmd[],
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
    r_tsip_func100(0x320222f8U, 0xe4cb5d3aU, 0x12037ecdU, 0x782bcc8dU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0x4afb00fcU, 0x8ce2d564U, 0x814eba12U, 0x2a7d6c9bU);
        WR1_PROG(REG_01BCH, 0x00000040U);
        WAIT_STS(REG_0018H, 12U, 0U);

        return TSIP_RET_FAIL;
    }
    else
    {
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000002U))
        {
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00B0H, 0x40000000U);
            WR1_PROG(REG_00A4H, 0x00408a84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func101(0x0de3b776U, 0x3d6e2e07U, 0xd9f3aea8U, 0xed61f9c5U);
        }
        else
        {
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00B0H, 0x40000000U);
            WR1_PROG(REG_00A4H, 0x00508a84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func101(0x169425beU, 0x9a182dfcU, 0x26774df1U, 0x5a151c1cU);
        }

        WR1_PROG(REG_00A4H, 0x00040c05U);
        WR1_PROG(REG_0000H, 0x00001113U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
        {
            r_tsip_func100(0x7f107445U, 0xee68bd21U, 0x59290895U, 0x89334e6aU);
            WR1_PROG(REG_0104H, 0x00000361U);
            WR1_PROG(REG_00B0H, 0x40000000U);
            WR1_PROG(REG_00A4H, 0x00008e95U);
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
            r_tsip_func102(0xf6e0e0caU, 0x724160b3U, 0xef072b0dU, 0x751bb5f8U);
            WR1_PROG(REG_01BCH, 0x00000040U);
            WAIT_STS(REG_0018H, 12U, 0U);

            return TSIP_RET_PASS;
        }
        else
        {
            WR1_PROG(REG_0104H, 0x00000068U);
            WR1_PROG(REG_00E0H, 0x80010040U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_ADDR(REG_0100H, &InData_DataTLen[0]);
            WR1_PROG(REG_00ECH, 0x3420a840U);
            WR1_PROG(REG_00ECH, 0x00000010U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            WR1_PROG(REG_00ECH, 0x0000b460U);
            WR1_PROG(REG_00ECH, 0x00000080U);
            WR1_PROG(REG_00ECH, 0x34202862U);
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00260000U);
            r_tsip_func100(0x7f96cdb0U, 0x9eaeb21eU, 0x92b781eeU, 0x8074cabeU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xf5bf4c5eU, 0xf5c532b4U, 0x2f4cae06U, 0x83b51b95U);
                WR1_PROG(REG_01BCH, 0x00000040U);
                WAIT_STS(REG_0018H, 12U, 0U);

                return TSIP_RET_FAIL;
            }
            else
            {
                WR1_PROG(REG_0104H, 0x00000361U);
                WR1_PROG(REG_00B0H, 0x40000000U);
                WR1_PROG(REG_00A4H, 0x00008e95U);
                WAIT_STS(REG_0104H, 31U, 1U);
                WR1_ADDR(REG_0100H, &InData_Text[0]);
                WR1_ADDR(REG_0100H, &InData_Text[1]);
                WR1_ADDR(REG_0100H, &InData_Text[2]);
                WR1_ADDR(REG_0100H, &InData_Text[3]);
                WR1_PROG(REG_00ECH, 0x00000821U);
                WR1_PROG(REG_00E0H, 0x80840001U);
                WR1_PROG(REG_0000H, 0x00008113U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x000034e2U);
                WR1_PROG(REG_00ECH, 0x000568e7U);
                WR1_PROG(REG_00ECH, 0x00026ce7U);
                WR1_PROG(REG_00ECH, 0x00003827U);
                WR1_PROG(REG_00ECH, 0x0000b4c0U);
                WR1_PROG(REG_00ECH, 0x00000020U);
                WR1_PROG(REG_00ECH, 0x00003402U);
                WR1_PROG(REG_00ECH, 0x00008c00U);
                WR1_PROG(REG_00ECH, 0x0000001fU);
                WR1_PROG(REG_00ECH, 0x000028c0U);
                WR1_PROG(REG_00ECH, 0x00008cc0U);
                WR1_PROG(REG_00ECH, 0x0000001fU);
                WR1_PROG(REG_00ECH, 0x00004406U);
                WR1_PROG(REG_00ECH, 0x00007421U);
                WR1_PROG(REG_00ECH, 0x00007821U);
                WR1_PROG(REG_00ECH, 0x00003c27U);
                WR1_PROG(REG_00ECH, 0x000034c2U);
                WR1_PROG(REG_00ECH, 0x0000a4c0U);
                WR1_PROG(REG_00ECH, 0x0000001fU);
                WR1_PROG(REG_00ECH, 0x000568c6U);
                WR1_PROG(REG_00ECH, 0x000034e6U);
                WR1_PROG(REG_00ECH, 0x00026ce7U);
                WR1_PROG(REG_00ECH, 0x00000821U);
                for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1)
                {
                    WR1_PROG(REG_00ECH, 0x3420a8e0U);
                    WR1_PROG(REG_00ECH, 0x0000000dU);
                    WR1_PROG(REG_00ECH, 0x10003c27U);
                    WR1_PROG(REG_00ECH, 0x1000a4e0U);
                    WR1_PROG(REG_00ECH, 0x00000004U);
                }

                WR1_PROG(REG_00A4H, 0x00040805U);
                WR1_PROG(REG_00E0H, 0x81840001U);
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
                r_tsip_func100(0x7d336553U, 0x92324f79U, 0x67c8d234U, 0x656400a0U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0x0e5c8cceU, 0x9ad77787U, 0x1a64711fU, 0x05df9127U);
                    WR1_PROG(REG_01BCH, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_AUTH_FAIL;
                }
                else
                {
                    r_tsip_func102(0x36577c36U, 0x041c7a1bU, 0x08113d2eU, 0x36a27ac7U);
                    WR1_PROG(REG_01BCH, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_PASS;
                }
            }
        }
    }
}
