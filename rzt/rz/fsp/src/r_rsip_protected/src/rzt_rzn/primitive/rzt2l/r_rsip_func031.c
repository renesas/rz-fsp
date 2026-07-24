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
        r_rsip_func100(bswap_32big(0x37c10a3cU), bswap_32big(0xf10a1c70U), bswap_32big(0x1679c0ebU),
                       bswap_32big(0x7b272bfeU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x11110009U);
            r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x21210009U);
            r_rsip_func101(bswap_32big(0xdeaa2371U), bswap_32big(0xbfad20b7U), bswap_32big(0xd2c5e692U),
                           bswap_32big(0x17e7b6d3U));
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
            r_rsip_func100(bswap_32big(0x0256c7baU), bswap_32big(0x85204833U), bswap_32big(0x677549cdU),
                           bswap_32big(0x51820dafU));
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
                r_rsip_func100(bswap_32big(0x69c4923aU),
                               bswap_32big(0xaf08d95cU),
                               bswap_32big(0x53e0fd6bU),
                               bswap_32big(0x44504560U));
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
                    r_rsip_func101(bswap_32big(0xc23026dbU),
                                   bswap_32big(0xbf665963U),
                                   bswap_32big(0x10691d6dU),
                                   bswap_32big(0x6d169b5cU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0xce2e859dU),
                                   bswap_32big(0x4a0a577aU),
                                   bswap_32big(0xe23f37d0U),
                                   bswap_32big(0x36c2da9bU));
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
                        r_rsip_func100(bswap_32big(0x9006fedbU),
                                       bswap_32big(0x5426551bU),
                                       bswap_32big(0x087d29bbU),
                                       bswap_32big(0x69b66c01U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0x4e08eeb3U),
                                           bswap_32big(0x5fcc285bU),
                                           bswap_32big(0x1d4376f7U),
                                           bswap_32big(0x6dce0e94U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00109U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x1111000aU);
                            r_rsip_subfunc001(0x00000a58U, 0x00000948U, 0x00000948U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0xc84134a9U),
                                           bswap_32big(0x6c0c282dU),
                                           bswap_32big(0x72282c7cU),
                                           bswap_32big(0xe356659cU));
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
                        r_rsip_func100(bswap_32big(0x34e2a4b5U),
                                       bswap_32big(0x7a31842bU),
                                       bswap_32big(0xc78dd157U),
                                       bswap_32big(0xffe66431U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0x9fab5659U),
                                           bswap_32big(0xc5f29e08U),
                                           bswap_32big(0x1a01bdecU),
                                           bswap_32big(0xd10709e0U));
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
                            r_rsip_func101(bswap_32big(0x414f832bU),
                                           bswap_32big(0x5a54a72bU),
                                           bswap_32big(0x6741cbdcU),
                                           bswap_32big(0x4b5f84d9U));
                        }
                    }
                }
            }
            else
            {
                r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x1111000aU);
                r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x2121000aU);
                r_rsip_func101(bswap_32big(0x880496fbU),
                               bswap_32big(0x3498dd42U),
                               bswap_32big(0xd15de5a9U),
                               bswap_32big(0x74b2ec3dU));
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
