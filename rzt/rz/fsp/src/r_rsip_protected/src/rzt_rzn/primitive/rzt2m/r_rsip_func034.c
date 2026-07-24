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

void r_rsip_func034 (void)
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
    WR1_PROG(REG_1600H, 0x00000842U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b460U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x18380000U);
    r_rsip_subfunc003(0x00c00661U);
    WR1_PROG(REG_1600H, 0x0000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a00004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03400081U);
    for (oLoop = 0; oLoop < 4; oLoop++)
    {
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_func100(bswap_32big(0x94495aa3U), bswap_32big(0xca965200U), bswap_32big(0x0212c460U),
                       bswap_32big(0x557def8eU));
        WR1_PROG(REG_1600H, 0x00007c02U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x00000220U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0x779ebf05U), bswap_32big(0xe0d7da57U), bswap_32big(0xa006b63aU),
                           bswap_32big(0x9c47599aU));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x000001a0U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0x1b7cbfb7U), bswap_32big(0x28e76b05U), bswap_32big(0x8ee01da8U),
                           bswap_32big(0x1b452b92U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x00000120U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0x4d8b6ce6U), bswap_32big(0xc50d180aU), bswap_32big(0xb3d7b956U),
                           bswap_32big(0x166fdea0U));
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x000000a0U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0x637455aeU), bswap_32big(0xec74b91fU), bswap_32big(0x0f0a7c46U),
                           bswap_32big(0xb0a9debeU));
        }

        r_rsip_subfunc001(0x00000838U, 0x000008c0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e98U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000948U);
        WR1_PROG(REG_1020H, 0x00000948U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1d080000U);
        r_rsip_subfunc003(0x00c00081U);
        r_rsip_subfunc001(0x000008c8U, 0x00000d88U, 0x00000ae8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_subfunc003(0x00c00091U);
        WR1_PROG(REG_1404H, 0x1d080000U);
        WR1_PROG(REG_1600H, 0x00000884U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81a00004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90081U);
        r_rsip_subfunc001(0x00000948U, 0x00000d88U, 0x00000d88U, 0x10100007U);
        r_rsip_subfunc001(0x00000d88U, 0x000008c0U, 0x00000e10U, 0x10100009U);
        r_rsip_subfunc001(0x00000630U, 0x000008c0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e10U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000948U);
        WR1_PROG(REG_1020H, 0x00000948U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x19480000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x000007b8U, 0x000009d0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e98U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000a58U);
        WR1_PROG(REG_1020H, 0x00000a58U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_subfunc003(0x00c00111U);
        r_rsip_subfunc001(0x00000ae8U, 0x00000d88U, 0x00000d88U, 0x10100009U);
        r_rsip_subfunc001(0x00000a58U, 0x00000d88U, 0x00000a58U, 0x20200009U);
        r_rsip_subfunc001(0x000009d8U, 0x00000d00U, 0x00000bf8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x19480000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x000005b0U, 0x000009d0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e10U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000a58U);
        WR1_PROG(REG_1020H, 0x00000d88U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x000008c8U, 0x000009d0U, 0x00000948U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x00000d88U, 0x00000948U, 0x00000948U, 0x20200009U);
        r_rsip_subfunc001(0x000008c8U, 0x000009d0U, 0x000009d8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1a580000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x00000738U, 0x00000ae0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e98U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000b68U);
        WR1_PROG(REG_1020H, 0x00000b68U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_subfunc003(0x00c00111U);
        r_rsip_subfunc001(0x00000bf8U, 0x00000d88U, 0x00000d88U, 0x10100009U);
        r_rsip_subfunc001(0x00000b68U, 0x00000d88U, 0x00000b68U, 0x20200009U);
        r_rsip_subfunc001(0x00000ae8U, 0x00000d00U, 0x000008c8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1a580000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x00000530U, 0x00000ae0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e10U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000b68U);
        WR1_PROG(REG_1020H, 0x00000d88U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x000009d8U, 0x00000ae0U, 0x00000a58U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x19480000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x00000d88U, 0x00000a58U, 0x00000a58U, 0x20200009U);
        r_rsip_subfunc001(0x000009d8U, 0x00000ae0U, 0x00000ae8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1b680000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x000006b8U, 0x00000bf0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e98U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000c78U);
        WR1_PROG(REG_1020H, 0x00000c78U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_subfunc003(0x00c00111U);
        r_rsip_subfunc001(0x000008c8U, 0x00000d88U, 0x00000d88U, 0x10100009U);
        r_rsip_subfunc001(0x00000c78U, 0x00000d88U, 0x00000c78U, 0x20200009U);
        r_rsip_subfunc001(0x00000bf8U, 0x00000d00U, 0x000009d8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1b680000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x000004b0U, 0x00000bf0U, 0x00000d88U, 0x10100009U);
        WR1_PROG(REG_1014H, 0x00000e10U);
        WR1_PROG(REG_1018H, 0x00000d88U);
        WR1_PROG(REG_101CH, 0x00000c78U);
        WR1_PROG(REG_1020H, 0x00000d88U);
        WR1_PROG(REG_1004H, 0x1010000dU);
        WR1_PROG(REG_1000H, 0x00010201U);
        WAIT_STS(REG_1000H, 0U, 0U);
        r_rsip_subfunc001(0x00000ae8U, 0x00000bf0U, 0x00000b68U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1a580000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x00000d88U, 0x00000b68U, 0x00000b68U, 0x20200009U);
        r_rsip_subfunc001(0x00000ae8U, 0x00000bf0U, 0x00000bf8U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_subfunc003(0x00c00111U);
        r_rsip_subfunc001(0x000009d8U, 0x00000d00U, 0x00000d88U, 0x10100009U);
        r_rsip_subfunc001(0x00000bf8U, 0x00000d00U, 0x00000c78U, 0x10100009U);
        WR1_PROG(REG_1404H, 0x1b680000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_subfunc001(0x00000d88U, 0x00000c78U, 0x00000e98U, 0x20200009U);
        WR1_PROG(REG_1404H, 0x1d080000U);
        WR1_PROG(REG_1600H, 0x0000b480U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x81a00004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00c90081U);
        r_rsip_subfunc001(0x00000d88U, 0x00000e98U, 0x00000c78U, 0x20200009U);
        WR1_PROG(REG_1600H, 0x0000b480U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80a00004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x1b780000U);
        r_rsip_subfunc003(0x03430081U);
        WR1_PROG(REG_1600H, 0x00002c40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xb765e98cU), bswap_32big(0x82a1d717U), bswap_32big(0xec6d7c10U),
                       bswap_32big(0x442ed8f4U));
    }

    WR1_PROG(REG_1600H, 0x38000843U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc001(0x00000c78U, 0x00000d00U, 0x00000ae8U, 0x11110009U);
    r_rsip_subfunc001(0x00000a58U, 0x00000d00U, 0x000008c8U, 0x10100009U);
    r_rsip_subfunc009(bswap_32big(0x0000f034U));
    r_rsip_func101(bswap_32big(0xa959f86aU),
                   bswap_32big(0x392260e5U),
                   bswap_32big(0x659bc1a5U),
                   bswap_32big(0x7365e426U));
    r_rsip_func032();
    WR1_PROG(REG_1600H, 0x000037bcU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
