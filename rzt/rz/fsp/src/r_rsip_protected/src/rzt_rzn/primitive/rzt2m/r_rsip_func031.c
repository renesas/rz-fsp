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
        r_rsip_func100(bswap_32big(0x383757c8U), bswap_32big(0x543aa2edU), bswap_32big(0xc574ea12U),
                       bswap_32big(0x7f3eec2dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x11110009U);
            r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x21210009U);
            r_rsip_func101(bswap_32big(0x82976238U), bswap_32big(0x81c27baeU), bswap_32big(0x7b84411cU),
                           bswap_32big(0x3f1dab6cU));
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
            r_rsip_func100(bswap_32big(0x97a8f110U), bswap_32big(0xb0aeef94U), bswap_32big(0xf55200b8U),
                           bswap_32big(0xe715211dU));
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
                r_rsip_func100(bswap_32big(0x9123c455U),
                               bswap_32big(0x72e09cdcU),
                               bswap_32big(0x5ed64119U),
                               bswap_32big(0x721a52d9U));
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
                    r_rsip_func101(bswap_32big(0x3156f80aU),
                                   bswap_32big(0xd0464161U),
                                   bswap_32big(0x8be0d24cU),
                                   bswap_32big(0x81d308a3U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x619542efU),
                                   bswap_32big(0x8473b956U),
                                   bswap_32big(0x78967125U),
                                   bswap_32big(0x1b91a192U));
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
                        r_rsip_func100(bswap_32big(0x9487669cU),
                                       bswap_32big(0xfc7c419fU),
                                       bswap_32big(0x140b1ef7U),
                                       bswap_32big(0x95d725f5U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0x646e5ef9U),
                                           bswap_32big(0xfdab8e3fU),
                                           bswap_32big(0x9019fb4aU),
                                           bswap_32big(0xc12c133aU));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00109U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x1111000aU);
                            r_rsip_subfunc001(0x00000a58U, 0x00000948U, 0x00000948U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0xe8011c67U),
                                           bswap_32big(0x781c5f41U),
                                           bswap_32big(0x2b74da49U),
                                           bswap_32big(0x22778c10U));
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
                        r_rsip_func100(bswap_32big(0x22c77858U),
                                       bswap_32big(0xca5ca3c0U),
                                       bswap_32big(0x8e5cfb46U),
                                       bswap_32big(0x02906150U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0xba48ceaeU),
                                           bswap_32big(0xb9f2e659U),
                                           bswap_32big(0x153b9936U),
                                           bswap_32big(0x853043abU));
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
                            r_rsip_func101(bswap_32big(0x9d4a7529U),
                                           bswap_32big(0x5765e1bdU),
                                           bswap_32big(0x1906f035U),
                                           bswap_32big(0xcce64dddU));
                        }
                    }
                }
            }
            else
            {
                r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x1111000aU);
                r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x2121000aU);
                r_rsip_func101(bswap_32big(0x8e077deaU),
                               bswap_32big(0xbe814dc0U),
                               bswap_32big(0xcd56c94aU),
                               bswap_32big(0x80e6eb9cU));
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
