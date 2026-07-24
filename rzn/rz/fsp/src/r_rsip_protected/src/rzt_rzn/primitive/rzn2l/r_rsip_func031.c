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

void r_rsip_func031 (void)
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
    WR1_PROG(REG_1404H, 0x1b680000U);
    r_rsip_subfunc003(0x00c00331U);
    r_rsip_subfunc001(0x00000530U, 0x00000c78U, 0x00000d88U, 0x10100009U);
    r_rsip_subfunc001(0x00000630U, 0x00000c78U, 0x00000e98U, 0x20200009U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x1ae00000U);
        WR1_PROG(REG_1608H, 0x80010080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03430005U);
        r_rsip_subfunc003(0x00030005U);
        WR1_PROG(REG_1600H, 0x38000c84U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x936b7ec6U), bswap_32big(0x7557c929U), bswap_32big(0x6581390eU),
                       bswap_32big(0x3d246ac4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x11110009U);
            r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x21210009U);
            r_rsip_func101(bswap_32big(0x8dd64769U), bswap_32big(0x64714bdeU), bswap_32big(0x6fd2e5daU),
                           bswap_32big(0xca15ca3cU));
        }
        else
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000a58U, 0x1111000aU);
            WR1_PROG(REG_1404H, 0x19d00000U);
            WR1_PROG(REG_1608H, 0x800100a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430005U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc001(0x00000d88U, 0x00000b68U, 0x00000a58U, 0x1111000aU);
            WR1_PROG(REG_1404H, 0x19d00000U);
            WR1_PROG(REG_1608H, 0x800100c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430005U);
            r_rsip_subfunc003(0x00030005U);
            WR1_PROG(REG_1600H, 0x38000cc6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x6b4d3b9cU), bswap_32big(0x6a8d9361U), bswap_32big(0xd3dd328dU),
                           bswap_32big(0x34ae70b0U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1404H, 0x18400000U);
                WR1_PROG(REG_1608H, 0x800100e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430005U);
                r_rsip_subfunc003(0x00030005U);
                WR1_PROG(REG_1600H, 0x38000ce7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00A60000U);
                r_rsip_func100(bswap_32big(0x792e3829U),
                               bswap_32big(0x54991115U),
                               bswap_32big(0x488dc8f3U),
                               bswap_32big(0x90737824U));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_subfunc001(0x00000c78U, 0x00000948U, 0x00000a58U, 0x2121000aU);
                    WR1_PROG(REG_1404H, 0x19500000U);
                    WR1_PROG(REG_1608H, 0x80010100U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00030005U);
                    r_rsip_subfunc003(0x03430005U);
                    WR1_PROG(REG_1600H, 0x00002d00U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1404H, 0x19d00000U);
                    WR1_PROG(REG_1608H, 0x81010100U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00c00085U);
                    r_rsip_subfunc003(0x00c90005U);
                    r_rsip_subfunc001(0x00000b68U, 0x00000a58U, 0x00000b68U, 0x1111000aU);
                    WR1_PROG(REG_1404H, 0x19500000U);
                    WR1_PROG(REG_1608H, 0x81010100U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00c00005U);
                    r_rsip_subfunc003(0x00c90005U);
                    r_rsip_subfunc003(0x00c00101U);
                    r_rsip_subfunc001(0x00000948U, 0x00000a58U, 0x00000948U, 0x21210009U);
                    r_rsip_func101(bswap_32big(0x0e7cca14U),
                                   bswap_32big(0xe6a43fcaU),
                                   bswap_32big(0x083f2b85U),
                                   bswap_32big(0x88566b76U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0xb9b24018U),
                                   bswap_32big(0x457edf91U),
                                   bswap_32big(0x9f447a28U),
                                   bswap_32big(0x420b84e5U));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000a58U, 0x2121000aU);
                        WR1_PROG(REG_1404H, 0x19500000U);
                        WR1_PROG(REG_1608H, 0x80010100U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x03430005U);
                        r_rsip_subfunc003(0x00030005U);
                        WR1_PROG(REG_1600H, 0x38000d08U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00A60000U);
                        r_rsip_func100(bswap_32big(0x989c6522U),
                                       bswap_32big(0x1c494a66U),
                                       bswap_32big(0xff4dbb98U),
                                       bswap_32big(0x2a34395bU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0xb103aa5fU),
                                           bswap_32big(0xdaf02bcaU),
                                           bswap_32big(0x9802b922U),
                                           bswap_32big(0xdfa0acb1U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00109U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x1111000aU);
                            r_rsip_subfunc001(0x00000a58U, 0x00000948U, 0x00000948U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0x9c3fbf9cU),
                                           bswap_32big(0xdcd06c87U),
                                           bswap_32big(0x1d1986f6U),
                                           bswap_32big(0x44750527U));
                        }
                    }
                    else
                    {
                        WR1_PROG(REG_1404H, 0x18400000U);
                        WR1_PROG(REG_1608H, 0x80010120U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00030005U);
                        r_rsip_subfunc003(0x03430005U);
                        WR1_PROG(REG_1600H, 0x38000d29U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1608H, 0x00000080U);
                        WR1_PROG(REG_143CH, 0x00260000U);
                        r_rsip_func100(bswap_32big(0x323baca8U),
                                       bswap_32big(0x0e88d1bcU),
                                       bswap_32big(0x6640d07dU),
                                       bswap_32big(0xa1e3491cU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0xc97f49a0U),
                                           bswap_32big(0xec92de52U),
                                           bswap_32big(0x69acfb72U),
                                           bswap_32big(0x1f61b00dU));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00009U);
                            WR1_PROG(REG_1404H, 0x19d00000U);
                            WR1_PROG(REG_1608H, 0x81010120U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x00c00085U);
                            r_rsip_subfunc003(0x00c90005U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000a58U, 0x00000b68U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0xec31e8e0U),
                                           bswap_32big(0x13080588U),
                                           bswap_32big(0xbc16f46eU),
                                           bswap_32big(0xe701c12dU));
                        }
                    }
                }
            }
            else
            {
                r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x1111000aU);
                r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x2121000aU);
                r_rsip_func101(bswap_32big(0x18665bf3U),
                               bswap_32big(0xf07d3631U),
                               bswap_32big(0xc8869939U),
                               bswap_32big(0x3879a0d5U));
            }
        }
    }

    r_rsip_subfunc001(0x00000948U, 0x00000c78U, 0x00000838U, 0x20200009U);
    r_rsip_subfunc001(0x00000b68U, 0x00000c78U, 0x00000738U, 0x10100009U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
