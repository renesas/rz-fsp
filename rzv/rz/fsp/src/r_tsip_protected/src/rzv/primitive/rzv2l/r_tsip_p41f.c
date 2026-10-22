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
    r_tsip_func100(0x2a1f9c9eU, 0xcd0a0820U, 0x19bf44f1U, 0x210c97d2U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xa11c5b88U, 0x27480ed9U, 0x2ea5e331U, 0xb68cbc1dU);
        WR1_PROG(REG_01BCH, 0x00000040U);
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
            r_tsip_func101(0xacd15549U, 0xfe76b3e2U, 0x7f7c771fU, 0xc21f092aU);
        }
        else
        {
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00A4H, 0x00500a84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func101(0x8448da81U, 0xf9444cfdU, 0x60634d08U, 0x5753991cU);
        }

        WR1_PROG(REG_00A4H, 0x00040c05U);
        WR1_PROG(REG_0000H, 0x00001113U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
        {
            r_tsip_func100(0xcd11f325U, 0x85e47397U, 0x231ef94aU, 0x0abb8d3bU);
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
            r_tsip_func102(0x03836ce0U, 0x7ed44c82U, 0x1877ad54U, 0xc77f8cc9U);
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
            r_tsip_func100(0x34fc5c9bU, 0xe59d444fU, 0xd177e24dU, 0x7e44243bU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0xcb9690aeU, 0x873609faU, 0xa3014360U, 0xa5088fa9U);
                WR1_PROG(REG_01BCH, 0x00000040U);
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
                r_tsip_func100(0xc04555c5U, 0x8b7d7085U, 0xe1ccb7a1U, 0x9f54d68dU);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0xadcab333U, 0xee476b33U, 0x87991f7bU, 0x52401dd9U);
                    WR1_PROG(REG_01BCH, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_AUTH_FAIL;
                }
                else
                {
                    r_tsip_func102(0x4afbfbadU, 0xaa1e80e8U, 0xbdce7b32U, 0x47a5729cU);
                    WR1_PROG(REG_01BCH, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_PASS;
                }
            }
        }
    }
}
