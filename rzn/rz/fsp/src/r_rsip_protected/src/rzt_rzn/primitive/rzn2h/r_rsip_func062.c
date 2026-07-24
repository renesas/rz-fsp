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
        r_rsip_func100(bswap_32big(0xa430ab0eU), bswap_32big(0x25b47195U), bswap_32big(0x87c79830U),
                       bswap_32big(0xef52f6c5U));
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
            r_rsip_func100(bswap_32big(0x6a8cc354U), bswap_32big(0xe053bf67U), bswap_32big(0x9ec8bf0fU),
                           bswap_32big(0x87a9ac56U));
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
                r_rsip_func101(bswap_32big(0x0952aaf1U),
                               bswap_32big(0x823fb49aU),
                               bswap_32big(0xb0de441dU),
                               bswap_32big(0x10254a81U));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0xbe84871eU));
                OFS_ADR = 676;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000621U));
                r_rsip_func101(bswap_32big(0xf5750caaU),
                               bswap_32big(0x4fceb14dU),
                               bswap_32big(0x3ba1ee0dU),
                               bswap_32big(0x73d68939U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000448U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0xeb98ec47U),
                               bswap_32big(0x26ec99b6U),
                               bswap_32big(0x54b244baU),
                               bswap_32big(0x1a4503aeU));
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
                r_rsip_subfunc007(bswap_32big(0x4ea3f35fU));
                OFS_ADR = 544;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000622U));
                r_rsip_func101(bswap_32big(0xbdc2c281U),
                               bswap_32big(0x1ae5d9efU),
                               bswap_32big(0x6c8bc070U),
                               bswap_32big(0xae654f28U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000a90U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0x74e44248U),
                               bswap_32big(0x3cabbbb7U),
                               bswap_32big(0x8fafd2b8U),
                               bswap_32big(0xd4b76896U));
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
                r_rsip_func101(bswap_32big(0xe76406c0U),
                               bswap_32big(0xbe949e85U),
                               bswap_32big(0x0995bfa3U),
                               bswap_32big(0x11c39b2bU));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0x29b9e2f1U), bswap_32big(0x2eacdb97U), bswap_32big(0xbffc14aaU),
                           bswap_32big(0xfe4e6884U));
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
