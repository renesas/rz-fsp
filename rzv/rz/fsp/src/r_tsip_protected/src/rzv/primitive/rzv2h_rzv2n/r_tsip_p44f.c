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
    r_tsip_func100(0x7ecbc49eU, 0xaf2ecef8U, 0xdd7310c6U, 0x1c2c3a4cU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func102(0xcbeb8871U, 0x5c150043U, 0xa58b214cU, 0x54580cbdU);
        WR1_PROG(REG_01B4H, 0x00000040U);
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
            r_tsip_func101(0x97ad64ffU, 0xc17d1787U, 0x552bb789U, 0x9f132328U);
        }
        else
        {
            WR1_PROG(REG_0104H, 0x00000051U);
            WR1_PROG(REG_00B0H, 0x40000000U);
            WR1_PROG(REG_00A4H, 0x00508a84U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            r_tsip_func101(0x91912391U, 0x186a06c3U, 0xd8ad153aU, 0x4de5cc35U);
        }

        WR1_PROG(REG_00A4H, 0x00040c05U);
        WR1_PROG(REG_0000H, 0x00001113U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        if ((InData_Cmd[0] == 0x00000000U) || (InData_Cmd[0] == 0x00000001U))
        {
            r_tsip_func100(0xd59becd6U, 0x13fed483U, 0x910fff05U, 0x67632381U);
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
            r_tsip_func102(0x63b2f46aU, 0x809de039U, 0xd424cfb5U, 0xeb185437U);
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
            r_tsip_func100(0xba1413c5U, 0x6d8cac85U, 0xf11d4c8eU, 0x21e9eac0U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                r_tsip_func102(0x9d1a7024U, 0xa2523522U, 0x39da6aa8U, 0x9a2e0230U);
                WR1_PROG(REG_01B4H, 0x00000040U);
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
                r_tsip_func100(0x092a05d1U, 0x8d3e930bU, 0xf639e061U, 0x7a2eeb30U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    r_tsip_func102(0xf7bc47f7U, 0xc1ebfaf9U, 0xb4cfe0c9U, 0x1f97cad6U);
                    WR1_PROG(REG_01B4H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_AUTH_FAIL;
                }
                else
                {
                    r_tsip_func102(0x309e7f60U, 0x3d861fe4U, 0x3d7fa785U, 0x9dbb75f9U);
                    WR1_PROG(REG_01B4H, 0x00000040U);
                    WAIT_STS(REG_0018H, 12U, 0U);

                    return TSIP_RET_PASS;
                }
            }
        }
    }
}
