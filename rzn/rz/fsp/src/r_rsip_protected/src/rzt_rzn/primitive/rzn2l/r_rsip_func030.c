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

void r_rsip_func030 (void)
{
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
    WR1_PROG(REG_1404H, 0x18c00000U);
    r_rsip_subfunc003(0x00c00089U);
    WR1_PROG(REG_1404H, 0x19d00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00085U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000630U, 0x00000948U, 0x00000b68U, 0x10100009U);
    WR1_PROG(REG_1404H, 0x1bf00000U);
    r_rsip_subfunc003(0x00c00089U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (oLoop = 0; oLoop < 1024; oLoop++)
    {
        WR1_PROG(REG_1404H, 0x19400000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800dbe0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x88221692U), bswap_32big(0x332c79b6U), bswap_32big(0xb59571b4U),
                       bswap_32big(0xd820325dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000948U, 0x00000b68U, 0x00000948U, 0x11110009U);
            r_rsip_subfunc001(0x00000c78U, 0x00000a58U, 0x00000c78U, 0x11110009U);
            r_rsip_func101(bswap_32big(0x1259dc32U), bswap_32big(0xf194f26dU), bswap_32big(0x872b75b7U),
                           bswap_32big(0x6ee213e2U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x418a13d9U), bswap_32big(0x547a801eU), bswap_32big(0x934b5befU),
                           bswap_32big(0xd2487233U));
        }

        r_rsip_subfunc004(0x00000948U, 0x00000948U, 0x1111000cU);
        r_rsip_subfunc001(0x00000a58U, 0x00000a58U, 0x00000a58U, 0x11110009U);
        WR1_PROG(REG_1600H, 0x00002c00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x6fc74a5cU), bswap_32big(0xaa8681dbU), bswap_32big(0xd6dfbd6bU),
                       bswap_32big(0xd808cd73U));
    }

    WR1_PROG(REG_1600H, 0x38000801U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a00000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x1bf80000U);
    r_rsip_subfunc003(0x03430081U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
