/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"

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

RSIP_PRV_PRIMITIVE_FUNC

void r_rsip_p47u (const uint32_t InData_Text[], uint32_t OutData_Text[], const uint32_t MAX_CNT)
{
    RSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL;
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0x761c1b1aU), bswap_32big(0xead5aa42U), bswap_32big(0xe58da0b8U),
                       bswap_32big(0x6f4c39e7U));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0a000106U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0x5a8b7cb9U), bswap_32big(0x28026129U), bswap_32big(0x9691bdafU),
                       bswap_32big(0xe9d749b0U));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0a00010eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0xe4144faaU), bswap_32big(0x445b82d6U), bswap_32big(0x611fcf0cU),
                       bswap_32big(0x8f4199abU));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0e000506U);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000003c2U);
        r_rsip_func100(bswap_32big(0x1fe37f6dU), bswap_32big(0x6e7f3ad9U), bswap_32big(0xf623b8deU),
                       bswap_32big(0x5a153e26U));
        WR1_PROG(REG_1444H, 0x00020061U);
        WR1_PROG(REG_1824H, 0x0900090eU);
        WR1_PROG(REG_1408H, 0x000c1000U);
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Text[0]);
    WR1_ADDR(REG_1420H, &InData_Text[1]);
    WR1_ADDR(REG_1420H, &InData_Text[2]);
    WR1_ADDR(REG_1420H, &InData_Text[3]);
    for (iLoop = 4; iLoop < MAX_CNT; iLoop = iLoop + 4)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_Text[iLoop + 3]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 4]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 3]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 2]);
        RD1_ADDR(REG_1420H, &OutData_Text[iLoop - 1]);
    }

    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 4]);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 3]);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 2]);
    RD1_ADDR(REG_1420H, &OutData_Text[MAX_CNT - 1]);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0xd1dde2baU), bswap_32big(0x96d2af32U), bswap_32big(0xc9842572U),
                       bswap_32big(0x5018ce87U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0xc0ef38d3U), bswap_32big(0xa3784ac5U), bswap_32big(0x49d639d7U),
                       bswap_32big(0x74f1e2bfU));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0x41f2146aU), bswap_32big(0xc89b1921U), bswap_32big(0x25eb1fadU),
                       bswap_32big(0x3352c3bcU));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func206();
        r_rsip_func101(bswap_32big(0xc2707ba3U), bswap_32big(0x4363f500U), bswap_32big(0xef5d30d2U),
                       bswap_32big(0x05b66b65U));
    }
}
