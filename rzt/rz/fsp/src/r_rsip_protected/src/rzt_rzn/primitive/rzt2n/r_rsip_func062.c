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

void r_rsip_func062 (void)
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
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800db40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xd2a4e913U), bswap_32big(0xb484f8c2U), bswap_32big(0x0c515ef7U),
                       bswap_32big(0x03b13d5aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            WR1_PROG(REG_1404H, 0x14400000U);
            WR1_PROG(REG_1608H, 0x80010340U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1404H, 0x1a880000U);
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
            r_rsip_func100(bswap_32big(0x1becc578U), bswap_32big(0x947fc79dU), bswap_32big(0x453a9e60U),
                           bswap_32big(0x8947e6edU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x80010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x12380000U);
                r_rsip_subfunc003(0x00c00009U);
                WR1_PROG(REG_1404H, 0x18800000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000448U, 0x00000448U, 0x4141000cU);
                r_rsip_subfunc004(0x00000a90U, 0x00000a90U, 0x4141000cU);
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x81010300U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0x93bc5e12U),
                               bswap_32big(0xdb70f22fU),
                               bswap_32big(0xcf6fda72U),
                               bswap_32big(0xf8899e18U));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0x2914d4b0U));
                OFS_ADR = 676;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000621U));
                r_rsip_func101(bswap_32big(0x404eb08aU),
                               bswap_32big(0x8cfe9067U),
                               bswap_32big(0xc66df324U),
                               bswap_32big(0x60344655U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000448U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0x4c72869dU),
                               bswap_32big(0x0f63c936U),
                               bswap_32big(0xdf938967U),
                               bswap_32big(0x278df98dU));
                r_rsip_func310();
                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000878U, 0x00000448U, 0x4141000cU);
                WR1_PROG(REG_1404H, 0x12380000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0x06c243bbU));
                OFS_ADR = 544;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000622U));
                r_rsip_func101(bswap_32big(0xc3f7c3acU),
                               bswap_32big(0x59cc758bU),
                               bswap_32big(0x8ab2e42bU),
                               bswap_32big(0x75415976U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000a90U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0xe5cf1041U),
                               bswap_32big(0x5a73ac7eU),
                               bswap_32big(0x2414f0c1U),
                               bswap_32big(0x376d39fcU));
                r_rsip_func311();
                WR1_PROG(REG_1404H, 0x16680000U);
                WR1_PROG(REG_1608H, 0x800102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00030005U);
                r_rsip_subfunc003(0x03430005U);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00009U);
                r_rsip_subfunc004(0x00000878U, 0x00000a90U, 0x4141000cU);
                WR1_PROG(REG_1404H, 0x18800000U);
                WR1_PROG(REG_1608H, 0x810102e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x00c90005U);
                r_rsip_func101(bswap_32big(0xf3554428U),
                               bswap_32big(0xa8b05ed8U),
                               bswap_32big(0xca9f10a8U),
                               bswap_32big(0x44d1c60fU));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x5f8b18e8U), bswap_32big(0x678f5b3dU), bswap_32big(0x731df4eeU),
                           bswap_32big(0x42ba44f7U));
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
