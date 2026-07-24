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
        r_rsip_func100(bswap_32big(0x284148c4U), bswap_32big(0x7331a62dU), bswap_32big(0xe02adfbcU),
                       bswap_32big(0x75a7d864U));
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
            r_rsip_func100(bswap_32big(0x14102de7U), bswap_32big(0xfc040e78U), bswap_32big(0x2ee7fe60U),
                           bswap_32big(0xaeec5c66U));
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
                r_rsip_func101(bswap_32big(0xec0e6b00U),
                               bswap_32big(0x183f0762U),
                               bswap_32big(0x2a6b6d12U),
                               bswap_32big(0x3b194cfeU));
            }
            else
            {
                WR1_PROG(REG_1404H, 0x1dc80000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc007(bswap_32big(0x8162b38bU));
                OFS_ADR = 676;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000621U));
                r_rsip_func101(bswap_32big(0x3838f4ffU),
                               bswap_32big(0x67ca7e7eU),
                               bswap_32big(0x8ce7418aU),
                               bswap_32big(0x6c2cc8eeU));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000448U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0xeb2a5975U),
                               bswap_32big(0x467e071aU),
                               bswap_32big(0x1b64e324U),
                               bswap_32big(0x2b0bed97U));
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
                r_rsip_subfunc007(bswap_32big(0x7edfb1abU));
                OFS_ADR = 544;
                r_rsip_subfunc008(0x1dd80000U, 0x00000080U, bswap_32big(0x00000622U));
                r_rsip_func101(bswap_32big(0x05b85948U),
                               bswap_32big(0x80216771U),
                               bswap_32big(0x2ba2bc31U),
                               bswap_32big(0x55b8dc68U));
                r_rsip_func017(OFS_ADR);
                WR1_PROG(REG_1404H, 0x16680000U);
                r_rsip_subfunc003(0x00c00211U);
                r_rsip_subfunc001(0x00000a90U, 0x00000878U, 0x00000878U, 0x42420009U);
                r_rsip_subfunc009(bswap_32big(0x0000f062U));
                r_rsip_func101(bswap_32big(0x0fc00600U),
                               bswap_32big(0x854b8288U),
                               bswap_32big(0x1eb39524U),
                               bswap_32big(0xaccf3ab8U));
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
                r_rsip_func101(bswap_32big(0xc91a39a9U),
                               bswap_32big(0x6769ecc0U),
                               bswap_32big(0x03a39c43U),
                               bswap_32big(0x019fa402U));
            }
        }
        else
        {
            r_rsip_func101(bswap_32big(0xa85c9b0bU), bswap_32big(0x786fce22U), bswap_32big(0x5bb65966U),
                           bswap_32big(0xca50420bU));
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
