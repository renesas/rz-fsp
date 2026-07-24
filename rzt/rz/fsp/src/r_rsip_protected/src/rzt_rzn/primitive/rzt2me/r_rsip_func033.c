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

void r_rsip_func033 (void)
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
    WR1_PROG(REG_1600H, 0x00000003U);
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
    for (oLoop = 0; oLoop < 3; oLoop++)
    {
        WR1_PROG(REG_1404H, 0x18380000U);
        r_rsip_subfunc003(0x00c00091U);
        r_rsip_func100(bswap_32big(0xef61fd36U), bswap_32big(0x9042e3ecU), bswap_32big(0xb102ca47U),
                       bswap_32big(0x9cee9645U));
        WR1_PROG(REG_1600H, 0x00007c02U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x00000220U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0xd835f030U), bswap_32big(0x27efd6beU), bswap_32big(0xb791b146U),
                           bswap_32big(0x52504463U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x000001a0U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0xe07f750dU), bswap_32big(0x13cf99c9U), bswap_32big(0x6daa0f45U),
                           bswap_32big(0x96875ab2U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc001(0x00000120U, 0x000008c0U, 0x00000e98U, 0x10100009U);
            r_rsip_func101(bswap_32big(0x15eb07d9U), bswap_32big(0x56e5279dU), bswap_32big(0x25951727U),
                           bswap_32big(0x03639386U));
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
        WR1_PROG(REG_1404H, 0x1c780000U);
        r_rsip_subfunc003(0x00c00111U);
        r_rsip_subfunc001(0x000008c8U, 0x00000d00U, 0x00000d88U, 0x10100009U);
        r_rsip_subfunc001(0x00000ae8U, 0x00000d00U, 0x00000c78U, 0x10100009U);
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
        r_rsip_subfunc001(0x00000d88U, 0x00000e98U, 0x00000b68U, 0x20200009U);
        WR1_PROG(REG_1600H, 0x0000b480U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000080U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x80a00004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x1a680000U);
        r_rsip_subfunc003(0x03430081U);
        WR1_PROG(REG_1600H, 0x00002c40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7a9908c6U), bswap_32big(0x78742f27U), bswap_32big(0xd3436585U),
                       bswap_32big(0x320ba320U));
    }

    WR1_PROG(REG_1600H, 0x38000843U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc001(0x00000a58U, 0x00000d00U, 0x000008c8U, 0x10100009U);
    r_rsip_subfunc009(bswap_32big(0x0000f033U));
    r_rsip_func101(bswap_32big(0x79a09d43U),
                   bswap_32big(0xdeca72b3U),
                   bswap_32big(0x6c1e4a75U),
                   bswap_32big(0xb719e716U));
    r_rsip_func031();
    WR1_PROG(REG_1600H, 0x000037bcU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
