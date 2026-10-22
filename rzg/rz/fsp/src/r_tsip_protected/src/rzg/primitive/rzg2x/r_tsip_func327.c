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

void r_tsip_func327 (void)
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
    r_tsip_func100(0xbc52aedaU, 0x7ad206d6U, 0xdf28dea1U, 0x371ec1e7U);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00ECH, 0x0000b420U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x0000345eU);
    WR1_PROG(REG_00ECH, 0x00026c42U);
    WR1_PROG(REG_00E0H, 0x810103c0U);
    WR1_PROG(REG_0004H, 0x00000606U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_00ECH, 0x0000381fU);
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
            WR1_PROG(REG_00E0H, 0x00000080U);
            WR1_PROG(REG_001CH, 0x00A60000U);
            WR1_PROG(REG_00ECH, 0x00016c00U);
            r_tsip_func100(0xf3fc7234U, 0xa585ef08U, 0x0e31e15eU, 0x3cd0d4b0U);
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
                r_tsip_func101(0x295cd607U, 0x77438363U, 0xc6ee03f4U, 0x980ad249U);
            }
            else
            {
                WR1_PROG(REG_0024H, 0x0000082cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x100019b1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000001d1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                r_tsip_func101(0xb2398d15U, 0x5080a1bfU, 0x0a6adbf8U, 0x940a1a1bU);
            }
        }

        WR1_PROG(REG_00ECH, 0x000027e1U);
        r_tsip_func101(0xc53c4eb0U, 0xf172dfe6U, 0x65cf97cbU, 0xc1bb632fU);
    }

    WR1_PROG(REG_00ECH, 0x00000be2U);
    WR1_PROG(REG_00ECH, 0x00007c1fU);
    WR1_PROG(REG_001CH, 0x00602000U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_001CH, 0x00602000U);
}
