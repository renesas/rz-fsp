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

void r_rsip_func032 (void)
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
    r_rsip_subfunc001(0x00000530U, 0x00000c78U, 0x00000d88U, 0x20200009U);
    r_rsip_subfunc001(0x00000630U, 0x00000c78U, 0x00000e98U, 0x20200009U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x1a600000U);
        WR1_PROG(REG_1608H, 0x80010080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03430005U);
        r_rsip_subfunc003(0x00030005U);
        WR1_PROG(REG_1600H, 0x38000c84U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x5c9d583bU), bswap_32big(0x88501bddU), bswap_32big(0x4c211d8bU),
                       bswap_32big(0x0b21dc7eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x21210009U);
            r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x21210009U);
            r_rsip_func101(bswap_32big(0x69d7dbd2U), bswap_32big(0xbde80c4cU), bswap_32big(0x990fecbdU),
                           bswap_32big(0x7ad064d9U));
        }
        else
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000a58U, 0x2121000aU);
            WR1_PROG(REG_1404H, 0x19500000U);
            WR1_PROG(REG_1608H, 0x800100a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430005U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc001(0x00000d88U, 0x00000b68U, 0x00000a58U, 0x2121000aU);
            WR1_PROG(REG_1404H, 0x19500000U);
            WR1_PROG(REG_1608H, 0x800100c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03430005U);
            r_rsip_subfunc003(0x00030005U);
            WR1_PROG(REG_1600H, 0x38000cc6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0xbf93dc0fU), bswap_32big(0xb94e4626U), bswap_32big(0xc51f463aU),
                           bswap_32big(0xae1cbc31U));
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
                r_rsip_func100(bswap_32big(0xbbb8dd6bU),
                               bswap_32big(0x0ff98733U),
                               bswap_32big(0x2f498220U),
                               bswap_32big(0x95171ea2U));
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
                    WR1_PROG(REG_1404H, 0x19500000U);
                    WR1_PROG(REG_1608H, 0x81010100U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00c00105U);
                    r_rsip_subfunc003(0x00c90005U);
                    r_rsip_subfunc001(0x00000b68U, 0x00000a58U, 0x00000b68U, 0x2121000aU);
                    WR1_PROG(REG_1404H, 0x19500000U);
                    WR1_PROG(REG_1608H, 0x81010100U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00c00005U);
                    r_rsip_subfunc003(0x00c90005U);
                    r_rsip_subfunc003(0x00c00101U);
                    r_rsip_subfunc001(0x00000948U, 0x00000a58U, 0x00000948U, 0x21210009U);
                    r_rsip_func101(bswap_32big(0xdd793beaU),
                                   bswap_32big(0x1dba2ffbU),
                                   bswap_32big(0xc69f716cU),
                                   bswap_32big(0xaa911ff9U));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0x8a1d3f4eU),
                                   bswap_32big(0x7e10eedeU),
                                   bswap_32big(0xfc420201U),
                                   bswap_32big(0x8962cf62U));
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
                        r_rsip_func100(bswap_32big(0x3a1d2ffdU),
                                       bswap_32big(0x4ef25d59U),
                                       bswap_32big(0x134b4eecU),
                                       bswap_32big(0x50d992e8U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0x571edcf0U),
                                           bswap_32big(0xaac85960U),
                                           bswap_32big(0xb0bf4a29U),
                                           bswap_32big(0xa0e65493U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00109U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x2121000aU);
                            r_rsip_subfunc001(0x00000a58U, 0x00000948U, 0x00000948U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0xaeb042a4U),
                                           bswap_32big(0x8e65dbdbU),
                                           bswap_32big(0x3be3704aU),
                                           bswap_32big(0x3d73815fU));
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
                        r_rsip_func100(bswap_32big(0xbfd66c85U),
                                       bswap_32big(0x43c87058U),
                                       bswap_32big(0x6b374116U),
                                       bswap_32big(0x1a0fc5bdU));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0xdfdbf5afU),
                                           bswap_32big(0xe589944bU),
                                           bswap_32big(0x9b898437U),
                                           bswap_32big(0x3133078cU));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00009U);
                            WR1_PROG(REG_1404H, 0x19500000U);
                            WR1_PROG(REG_1608H, 0x81010120U);
                            WR1_PROG(REG_1458H, 0x00000000U);
                            r_rsip_subfunc003(0x00c00105U);
                            r_rsip_subfunc003(0x00c90005U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000a58U, 0x00000b68U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0x3c2a6e14U),
                                           bswap_32big(0xc4d58b10U),
                                           bswap_32big(0xf0086b9fU),
                                           bswap_32big(0xe47e08a1U));
                        }
                    }
                }
            }
            else
            {
                r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x2121000aU);
                r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x2121000aU);
                r_rsip_func101(bswap_32big(0x53a7d68bU),
                               bswap_32big(0x0ed81d44U),
                               bswap_32big(0x618d2c1aU),
                               bswap_32big(0xf5d81812U));
            }
        }
    }

    r_rsip_subfunc001(0x00000948U, 0x00000c78U, 0x00000838U, 0x20200009U);
    r_rsip_subfunc001(0x00000b68U, 0x00000c78U, 0x00000738U, 0x20200009U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
