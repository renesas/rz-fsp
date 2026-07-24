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
        r_rsip_func100(bswap_32big(0xc80c5a24U), bswap_32big(0x69fdc6a4U), bswap_32big(0x83636774U),
                       bswap_32big(0x08d42f45U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x21210009U);
            r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x21210009U);
            r_rsip_func101(bswap_32big(0xc4d1b430U), bswap_32big(0x27feec5fU), bswap_32big(0xffcb480cU),
                           bswap_32big(0x7d5f093aU));
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
            r_rsip_func100(bswap_32big(0xd01d8420U), bswap_32big(0x4d3fc7e9U), bswap_32big(0x88d65437U),
                           bswap_32big(0x779f262eU));
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
                r_rsip_func100(bswap_32big(0xaf19907aU),
                               bswap_32big(0xe1701fb9U),
                               bswap_32big(0xbad84ab6U),
                               bswap_32big(0x8c032996U));
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
                    r_rsip_func101(bswap_32big(0x6d8b4fecU),
                                   bswap_32big(0xca26b4a2U),
                                   bswap_32big(0x6841be3bU),
                                   bswap_32big(0xe39659beU));
                }
                else
                {
                    WR1_PROG(REG_1600H, 0x38000ca5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    r_rsip_func100(bswap_32big(0xd545cda6U),
                                   bswap_32big(0xe7c75f8fU),
                                   bswap_32big(0xd499a3f0U),
                                   bswap_32big(0xa1b8b6f4U));
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
                        r_rsip_func100(bswap_32big(0x1f87dcdaU),
                                       bswap_32big(0x6e083610U),
                                       bswap_32big(0x96b5888aU),
                                       bswap_32big(0x67cca733U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0x739ee9e2U),
                                           bswap_32big(0xa783650aU),
                                           bswap_32big(0xf831b247U),
                                           bswap_32big(0x61520681U));
                            break;
                        }
                        else
                        {
                            WR1_PROG(REG_1404H, 0x18400000U);
                            r_rsip_subfunc003(0x00c00109U);
                            r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x2121000aU);
                            r_rsip_subfunc001(0x00000a58U, 0x00000948U, 0x00000948U, 0x21210009U);
                            r_rsip_func101(bswap_32big(0x39dff0caU),
                                           bswap_32big(0x0f80a849U),
                                           bswap_32big(0x95b1d3ceU),
                                           bswap_32big(0x73b5bb27U));
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
                        r_rsip_func100(bswap_32big(0x075e53bbU),
                                       bswap_32big(0x5641be50U),
                                       bswap_32big(0xdbfa3abbU),
                                       bswap_32big(0x687a02f3U));
                        WR1_PROG(REG_143CH, 0x00400000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        if (CHCK_STS(REG_143CH, 22U, 1U))
                        {
                            r_rsip_func101(bswap_32big(0x1fcd7fd5U),
                                           bswap_32big(0x3f8c6ee4U),
                                           bswap_32big(0x7cdbd08eU),
                                           bswap_32big(0x4800cc4eU));
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
                            r_rsip_func101(bswap_32big(0x5788f8beU),
                                           bswap_32big(0x91e5e411U),
                                           bswap_32big(0xe9a569d6U),
                                           bswap_32big(0x90b89534U));
                        }
                    }
                }
            }
            else
            {
                r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x2121000aU);
                r_rsip_subfunc001(0x00000948U, 0x00000e98U, 0x00000948U, 0x2121000aU);
                r_rsip_func101(bswap_32big(0x832ad336U),
                               bswap_32big(0x2dc7b8ccU),
                               bswap_32big(0xf98ed68fU),
                               bswap_32big(0x71ca2f29U));
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
