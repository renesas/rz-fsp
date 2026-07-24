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

void r_rsip_func052 (void)
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
    WR1_PROG(REG_1600H, 0x0000373dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1404H, 0x16280000U);
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
        r_rsip_func100(bswap_32big(0x199ad735U), bswap_32big(0x9b7f9c4bU), bswap_32big(0xcfb50681U),
                       bswap_32big(0x95be9123U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1010000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x1ead9ea4U), bswap_32big(0xe1e6571cU), bswap_32big(0x11f11918U),
                           bswap_32big(0x09295855U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x26835cd0U), bswap_32big(0xc7bc070cU), bswap_32big(0xaf0b5b3cU),
                           bswap_32big(0x821f3a44U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0x9ad25631U));
    OFS_ADR = 40;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000521U));
    r_rsip_func101(bswap_32big(0x010a624fU),
                   bswap_32big(0x715f1c58U),
                   bswap_32big(0x523bae8dU),
                   bswap_32big(0x87b35c06U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xea867876U));
    OFS_ADR = 80;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
    r_rsip_func101(bswap_32big(0xe8449facU),
                   bswap_32big(0x8a45216eU),
                   bswap_32big(0x918d3488U),
                   bswap_32big(0xf62c99f7U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xbf142b14U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000523U));
    r_rsip_func101(bswap_32big(0x8f4cf323U),
                   bswap_32big(0xc59fc1afU),
                   bswap_32big(0xc3e31df7U),
                   bswap_32big(0x27104e1dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
    r_rsip_func101(bswap_32big(0x78f707e8U),
                   bswap_32big(0x4bc06c78U),
                   bswap_32big(0x54ac5666U),
                   bswap_32big(0x3ab127b1U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xd9925758U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x00000525U));
    r_rsip_func101(bswap_32big(0x68316d23U),
                   bswap_32big(0xe4f0f4ecU),
                   bswap_32big(0xc92b7616U),
                   bswap_32big(0x2895240dU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430081U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xb4320bbeU), bswap_32big(0x01454775U), bswap_32big(0x48bf4c2eU),
                       bswap_32big(0x97f023dfU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xbeb8a412U), bswap_32big(0xc6877ef3U), bswap_32big(0x07c3fbbbU),
                           bswap_32big(0x941f8cc8U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xbf142b14U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x54b74eedU), bswap_32big(0x7ca3ea62U), bswap_32big(0x88063802U),
                           bswap_32big(0x2d3eeb20U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9ad25631U));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0xb3d0a13eU), bswap_32big(0xe067fbf8U), bswap_32big(0xe6ab0503U),
                           bswap_32big(0x41a259cfU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x72090f5cU), bswap_32big(0x6bf219a7U), bswap_32big(0x44a39697U),
                           bswap_32big(0x4b0e8ad7U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xbf142b14U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000526U));
            r_rsip_func101(bswap_32big(0x4c9b5b46U), bswap_32big(0xd5ee055aU), bswap_32big(0xef216d67U),
                           bswap_32big(0xbc623d71U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9ad25631U));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000527U));
            r_rsip_func101(bswap_32big(0x2c28baa0U), bswap_32big(0x5bab2659U), bswap_32big(0xb69e41b6U),
                           bswap_32big(0x9288f98dU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xea867876U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000523U));
            r_rsip_func101(bswap_32big(0x3f4a55bbU), bswap_32big(0xd5b8157bU), bswap_32big(0xdda9875bU),
                           bswap_32big(0x7b8ff80eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
            r_rsip_func101(bswap_32big(0x532865fcU), bswap_32big(0x51081fc4U), bswap_32big(0x625d30fdU),
                           bswap_32big(0x77a2d1e0U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc009(bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0xfcde9e5bU), bswap_32big(0xc98a9a02U), bswap_32big(0x7f30399bU),
                           bswap_32big(0x7fd1fa8eU));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xea867876U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000528U));
            r_rsip_func101(bswap_32big(0x0f366fb8U), bswap_32big(0xcfe21c63U), bswap_32big(0xfebdba31U),
                           bswap_32big(0x3f7c5e14U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000529U));
            r_rsip_func101(bswap_32big(0x14ab0ed1U), bswap_32big(0xbd95241eU), bswap_32big(0xed7accfbU),
                           bswap_32big(0xde971ee4U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x8290bb35U), bswap_32big(0x26963557U), bswap_32big(0x63bf13c1U),
                           bswap_32big(0xa7634ff2U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc007(bswap_32big(0xbf142b14U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000525U));
                r_rsip_func101(bswap_32big(0x5db8d831U),
                               bswap_32big(0x132fda10U),
                               bswap_32big(0x52b96d96U),
                               bswap_32big(0x88dab9b9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xea867876U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000526U));
                r_rsip_func101(bswap_32big(0xb60748caU),
                               bswap_32big(0x24266747U),
                               bswap_32big(0x163a66f3U),
                               bswap_32big(0xe415b522U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000521U));
                r_rsip_func101(bswap_32big(0x19013016U),
                               bswap_32big(0x6967b86fU),
                               bswap_32big(0x25c26a1fU),
                               bswap_32big(0x3137a4a1U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xbf142b14U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x17c1b22bU),
                               bswap_32big(0x3b034588U),
                               bswap_32big(0x8a197e6cU),
                               bswap_32big(0x70228de4U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9ad25631U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000527U));
                r_rsip_func101(bswap_32big(0x11b5dd85U),
                               bswap_32big(0x8fbe0477U),
                               bswap_32big(0x53cfcfc8U),
                               bswap_32big(0x0d81cc46U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000528U));
                r_rsip_func101(bswap_32big(0x98a05ffaU),
                               bswap_32big(0x17eb96d1U),
                               bswap_32big(0x052d682fU),
                               bswap_32big(0x03c5296bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000522U));
                r_rsip_func101(bswap_32big(0xd681a956U),
                               bswap_32big(0x47fd339cU),
                               bswap_32big(0x7c4fa2e5U),
                               bswap_32big(0xbdb8653dU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x9ad25631U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x3d883d73U),
                               bswap_32big(0x242b1988U),
                               bswap_32big(0x3e12a0e6U),
                               bswap_32big(0x2e3a9bf0U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x9564eba7U),
                               bswap_32big(0xfa89d196U),
                               bswap_32big(0x26a535f2U),
                               bswap_32big(0x71069885U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);
                r_rsip_subfunc007(bswap_32big(0xea867876U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x6515adbeU),
                               bswap_32big(0x20126e58U),
                               bswap_32big(0x92f2ef40U),
                               bswap_32big(0x20d3917dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbf142b14U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x2e52ec5aU),
                               bswap_32big(0xa0dadf3eU),
                               bswap_32big(0xb86cad66U),
                               bswap_32big(0xdff4cc57U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000523U));
                r_rsip_func101(bswap_32big(0x2e7dd776U),
                               bswap_32big(0x1ab7d87dU),
                               bswap_32big(0x54143641U),
                               bswap_32big(0x0eb103daU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xea867876U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x424a4e46U),
                               bswap_32big(0xb7ffc1d9U),
                               bswap_32big(0x435f569eU),
                               bswap_32big(0xfc7e5e8aU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0xd31ee48dU),
                               bswap_32big(0x8021f7e9U),
                               bswap_32big(0xcc3469d8U),
                               bswap_32big(0x56faff8eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9ad25631U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0xe12e0a62U),
                               bswap_32big(0xaaed9b00U),
                               bswap_32big(0x6e142530U),
                               bswap_32big(0x255307e7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000524U));
                r_rsip_func101(bswap_32big(0xea9d9c73U),
                               bswap_32big(0x6be447f7U),
                               bswap_32big(0x301dc158U),
                               bswap_32big(0x60aafb9eU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x973b15b1U),
                               bswap_32big(0x55e99a5dU),
                               bswap_32big(0x879f1504U),
                               bswap_32big(0xe609d1c8U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x194715e4U),
                               bswap_32big(0x457897abU),
                               bswap_32big(0x428f22baU),
                               bswap_32big(0x399164b4U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xd9925758U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x0000052eU));
    r_rsip_func101(bswap_32big(0x7b778a9aU),
                   bswap_32big(0x59f0b26eU),
                   bswap_32big(0x1adaaa7dU),
                   bswap_32big(0x8fc6e142U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x4d7ea94bU), bswap_32big(0x219612ffU), bswap_32big(0x778f692bU),
                       bswap_32big(0x5a928d1fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x59608edbU), bswap_32big(0x127d5be4U), bswap_32big(0x7406011dU),
                           bswap_32big(0xa7d59771U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x03114fe5U), bswap_32big(0x581783a0U), bswap_32big(0xd116d019U),
                           bswap_32big(0xbd730717U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xdc0a4280U));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052fU));
    r_rsip_func101(bswap_32big(0x544617b3U),
                   bswap_32big(0xed3d3e11U),
                   bswap_32big(0x9fea785aU),
                   bswap_32big(0xf8ca79beU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x1111000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x4bf4519eU), bswap_32big(0x0ab76e4aU), bswap_32big(0x5b091281U),
                       bswap_32big(0xd79b4cabU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0xd5e4469fU), bswap_32big(0x188a13e6U), bswap_32big(0x5737e1f4U),
                           bswap_32big(0xae63550eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x5824e5f0U), bswap_32big(0xc6cbccebU), bswap_32big(0x4ed0c8d2U),
                           bswap_32big(0x8755829fU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xf6e2a31cU),
                   bswap_32big(0xbcf9cf63U),
                   bswap_32big(0x9a638014U),
                   bswap_32big(0x604f125dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);
        r_rsip_func101(bswap_32big(0x64545785U), bswap_32big(0x19faeebbU), bswap_32big(0x859b5f76U),
                       bswap_32big(0x3c132535U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x6aa56298U), bswap_32big(0x9674cc66U), bswap_32big(0x401c9d64U),
                       bswap_32big(0x96244a57U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
