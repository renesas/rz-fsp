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

void r_rsip_func053 (void)
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
    WR1_PROG(REG_1600H, 0x0000379dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800db40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xf3154134U), bswap_32big(0x5b0ae183U), bswap_32big(0x6bf5c387U),
                       bswap_32big(0xcf2e64ecU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            WR1_PROG(REG_1404H, 0x14200000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x1a380000U);
            WR1_PROG(REG_1608H, 0x80010360U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1600H, 0x0000135bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x3800db40U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x7c2b9592U), bswap_32big(0xc4950fe1U), bswap_32big(0xea30e556U),
                           bswap_32big(0xa0f56d56U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x13980000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x13980000U);
                r_rsip_subfunc003(0x00c00009U);
                WR1_PROG(REG_1404H, 0x19b00000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000428U, 0x00000428U, 0x1111000cU);
                r_rsip_subfunc004(0x00000a40U, 0x00000a40U, 0x1111000cU);
                WR1_PROG(REG_1404H, 0x13980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0xb5d80662U),
                               bswap_32big(0x970f781cU),
                               bswap_32big(0x153f05c2U),
                               bswap_32big(0xce48e29dU));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1f480000U);
                WR1_PROG(REG_1600H, 0x00000b7bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81a0001bU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00011U);
                r_rsip_subfunc003(0x00c90081U);
                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_subfunc003(0x00c00091U);
                r_rsip_subfunc001(0x00000428U, 0x00000838U, 0x00000838U, 0x12120009U);
                r_rsip_subfunc009(bswap_32big(0x0000f053U));
                r_rsip_func101(bswap_32big(0xce897cd0U),
                               bswap_32big(0xf374433cU),
                               bswap_32big(0x338fd4aeU),
                               bswap_32big(0x20338345U));
                r_rsip_func302();
                WR1_PROG(REG_1404H, 0x17a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000838U, 0x00000428U, 0x1111000cU);
                WR1_PROG(REG_1404H, 0x13980000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1f480000U);
                r_rsip_subfunc003(0x00c00091U);
                r_rsip_subfunc007(bswap_32big(0xd9925758U));
                OFS_ADR = 160;
                r_rsip_subfunc008(0x1f580000U, 0x00000020U, bswap_32big(0x0000f053U));
                r_rsip_func101(bswap_32big(0x663e3a3eU),
                               bswap_32big(0x5c63c048U),
                               bswap_32big(0x84f05aecU),
                               bswap_32big(0x9acc2aeeU));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_subfunc003(0x00c00091U);
                r_rsip_subfunc001(0x00000a40U, 0x00000838U, 0x00000838U, 0x12120009U);
                r_rsip_subfunc009(bswap_32big(0x0000f053U));
                r_rsip_func101(bswap_32big(0x1ec9e75fU),
                               bswap_32big(0xfc3ee4f6U),
                               bswap_32big(0x57e35a9cU),
                               bswap_32big(0x63d48212U));
                r_rsip_func303();
                WR1_PROG(REG_1404H, 0x17a80000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x17a80000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000838U, 0x00000a40U, 0x1111000cU);
                WR1_PROG(REG_1404H, 0x19b00000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0xe80ad8d2U),
                               bswap_32big(0x5b820f30U),
                               bswap_32big(0x80ca1218U),
                               bswap_32big(0xc2731b8cU));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0xcd4158eeU), bswap_32big(0x02e5eaa8U), bswap_32big(0x6be28819U),
                           bswap_32big(0xd8cf313bU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x000037bcU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
