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

void r_rsip_func308 (void)
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
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x800102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    WR1_PROG(REG_1404H, 0x1e480000U);
    WR1_PROG(REG_1608H, 0x80010300U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000e40U, 0x3131000aU);
    WR1_PROG(REG_143CH, 0x00a10000U);
    r_rsip_func100(bswap_32big(0x34860e4dU),
                   bswap_32big(0x735305cbU),
                   bswap_32big(0x30ddf6a5U),
                   bswap_32big(0x53c20f33U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x1209b901U), bswap_32big(0x2b85dbabU), bswap_32big(0x3beaf9a7U),
                       bswap_32big(0x0fbd9530U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x31310009U);
            r_rsip_func101(bswap_32big(0x3370fcf1U), bswap_32big(0x6ed29bb2U), bswap_32big(0x2e721df4U),
                           bswap_32big(0x5d010f96U));
        }
        else
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0xea8dc97aU), bswap_32big(0x44e10bd0U), bswap_32big(0x9e0c3c09U),
                           bswap_32big(0x39cd0ae3U));
        }
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38000af8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x233c7580U), bswap_32big(0x8dde45f5U), bswap_32big(0xf2bc4daaU),
                       bswap_32big(0x390bee3fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000838U, 0x31310009U);
            r_rsip_func101(bswap_32big(0x0d7918b4U), bswap_32big(0xf4621241U), bswap_32big(0x0814ec4aU),
                           bswap_32big(0x767b78baU));
        }
        else
        {
            r_rsip_subfunc001(0x00000fd8U, 0x00000838U, 0x00000838U, 0x3131000aU);
            WR1_PROG(REG_1600H, 0x0000dee0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x9c4daf65U), bswap_32big(0xdc39d52cU), bswap_32big(0x9ac44b4fU),
                           bswap_32big(0xa64857a3U));
        }
    }

    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x810102e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c90005U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
