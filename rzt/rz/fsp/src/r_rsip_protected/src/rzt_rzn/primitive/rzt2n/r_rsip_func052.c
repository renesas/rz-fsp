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
        r_rsip_func100(bswap_32big(0xe50ebfe6U), bswap_32big(0x787c3d00U), bswap_32big(0xfbcff1d1U),
                       bswap_32big(0xde8c664aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1010000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2e3fecf6U), bswap_32big(0xf0c1113fU), bswap_32big(0xb9f3fd13U),
                           bswap_32big(0x0bbbe9a5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x03040443U), bswap_32big(0xfc965355U), bswap_32big(0x32c34006U),
                           bswap_32big(0xc68abe67U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0xb21297b4U));
    OFS_ADR = 40;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000521U));
    r_rsip_func101(bswap_32big(0xf9f9f461U),
                   bswap_32big(0x297a0869U),
                   bswap_32big(0x4b623357U),
                   bswap_32big(0xdcf27681U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x9b0dc6a0U));
    OFS_ADR = 80;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
    r_rsip_func101(bswap_32big(0xb6a3df3aU),
                   bswap_32big(0x9e9fb8e5U),
                   bswap_32big(0xc00a95c6U),
                   bswap_32big(0x533f2ac9U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xf7802804U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000523U));
    r_rsip_func101(bswap_32big(0xebd85f6dU),
                   bswap_32big(0xa6ee8db6U),
                   bswap_32big(0x6cb349f4U),
                   bswap_32big(0xdb485e48U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xefce6423U));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
    r_rsip_func101(bswap_32big(0x052acec9U),
                   bswap_32big(0xb1f27c49U),
                   bswap_32big(0x3b8d164dU),
                   bswap_32big(0x3c5acb12U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe1b59982U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x00000525U));
    r_rsip_func101(bswap_32big(0x230f066fU),
                   bswap_32big(0x0f512f1bU),
                   bswap_32big(0x1b5daac4U),
                   bswap_32big(0xe35fb0cfU));
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
        r_rsip_func100(bswap_32big(0x141e1e62U), bswap_32big(0xda2d2286U), bswap_32big(0xfe4fb5c7U),
                       bswap_32big(0x4a8c763eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xedf5bc80U), bswap_32big(0x180e56d1U), bswap_32big(0x62bfc4dfU),
                           bswap_32big(0x836d2474U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xf7802804U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x4ed34759U), bswap_32big(0x350c6debU), bswap_32big(0xe0f28393U),
                           bswap_32big(0x11fe17c2U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb21297b4U));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0x7a49b7f7U), bswap_32big(0x87a5845cU), bswap_32big(0x05ac2060U),
                           bswap_32big(0xa64a76e4U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0xb0eb312cU), bswap_32big(0xfa9b4ae1U), bswap_32big(0x66abffb9U),
                           bswap_32big(0xc61e33a0U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xf7802804U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000526U));
            r_rsip_func101(bswap_32big(0x4b432139U), bswap_32big(0xce1fd6f2U), bswap_32big(0xf1da3e97U),
                           bswap_32big(0xfb852eb6U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb21297b4U));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000527U));
            r_rsip_func101(bswap_32big(0xb1ecf48cU), bswap_32big(0xd6ca32c2U), bswap_32big(0x859943beU),
                           bswap_32big(0x09a2d020U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9b0dc6a0U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000523U));
            r_rsip_func101(bswap_32big(0x3a36715bU), bswap_32big(0x216156a5U), bswap_32big(0x12373ca2U),
                           bswap_32big(0x8d0c1618U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xefce6423U));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
            r_rsip_func101(bswap_32big(0x2ec0fbf6U), bswap_32big(0xb736a50eU), bswap_32big(0xf5317887U),
                           bswap_32big(0xe8dc2c51U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc009(bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0xfb288bf8U), bswap_32big(0xc598b177U), bswap_32big(0x6871b79aU),
                           bswap_32big(0x23915fcbU));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0x9b0dc6a0U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000528U));
            r_rsip_func101(bswap_32big(0x9e6f624dU), bswap_32big(0xa84c1401U), bswap_32big(0xaa03f09eU),
                           bswap_32big(0x2719cdaeU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xefce6423U));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000529U));
            r_rsip_func101(bswap_32big(0x7e81676bU), bswap_32big(0xe551cf6bU), bswap_32big(0xf42c9661U),
                           bswap_32big(0xe5d4063bU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xcabb8069U), bswap_32big(0x57f01d9fU), bswap_32big(0xbcf349d7U),
                           bswap_32big(0x7a6d7265U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc007(bswap_32big(0xf7802804U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000525U));
                r_rsip_func101(bswap_32big(0x54917b28U),
                               bswap_32big(0x873f3859U),
                               bswap_32big(0x7f758d3eU),
                               bswap_32big(0xb0313265U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9b0dc6a0U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000526U));
                r_rsip_func101(bswap_32big(0x8e15bbc7U),
                               bswap_32big(0xcd04c8dbU),
                               bswap_32big(0x2e4bfaa9U),
                               bswap_32big(0xc4cb4c20U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000521U));
                r_rsip_func101(bswap_32big(0xfb2e354dU),
                               bswap_32big(0xdc7bf4e2U),
                               bswap_32big(0x43fc271eU),
                               bswap_32big(0x6bc57aebU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xf7802804U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0xc9017f50U),
                               bswap_32big(0x5aef0bcfU),
                               bswap_32big(0xe830061cU),
                               bswap_32big(0xd186778cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb21297b4U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000527U));
                r_rsip_func101(bswap_32big(0x2e31021bU),
                               bswap_32big(0x632b8e33U),
                               bswap_32big(0x93f18faeU),
                               bswap_32big(0xb946c529U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xefce6423U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000528U));
                r_rsip_func101(bswap_32big(0xb2c391cfU),
                               bswap_32big(0xd8fbcf30U),
                               bswap_32big(0xb1368913U),
                               bswap_32big(0x0342ff1dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000522U));
                r_rsip_func101(bswap_32big(0x28655bb9U),
                               bswap_32big(0x125b908eU),
                               bswap_32big(0xc3b5a06aU),
                               bswap_32big(0x24963e72U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xb21297b4U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x0df501b3U),
                               bswap_32big(0x3615e9acU),
                               bswap_32big(0xa031b215U),
                               bswap_32big(0xfd7d3cabU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x3ac1361bU),
                               bswap_32big(0x05e02badU),
                               bswap_32big(0x97c015caU),
                               bswap_32big(0x0a3b88c1U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);
                r_rsip_subfunc007(bswap_32big(0x9b0dc6a0U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x9676371fU),
                               bswap_32big(0x5b1e932bU),
                               bswap_32big(0xa88278a5U),
                               bswap_32big(0x8853e34aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf7802804U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x5ef57122U),
                               bswap_32big(0xac53cd37U),
                               bswap_32big(0xfafd6913U),
                               bswap_32big(0xbfc31de0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000523U));
                r_rsip_func101(bswap_32big(0xa8496aa9U),
                               bswap_32big(0x27e21787U),
                               bswap_32big(0x558c01eeU),
                               bswap_32big(0x946f32d2U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x9b0dc6a0U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x0e93ad78U),
                               bswap_32big(0x8a15f485U),
                               bswap_32big(0x80e4bdfdU),
                               bswap_32big(0xabe05327U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xefce6423U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0xdc8a4704U),
                               bswap_32big(0x32f99fa1U),
                               bswap_32big(0x21476a7cU),
                               bswap_32big(0x9ef6cde4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb21297b4U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x2e701fb3U),
                               bswap_32big(0xa5daa8eeU),
                               bswap_32big(0xf22a3d82U),
                               bswap_32big(0x1092369aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000524U));
                r_rsip_func101(bswap_32big(0x6f87e6a8U),
                               bswap_32big(0x0314209aU),
                               bswap_32big(0x30cc8932U),
                               bswap_32big(0x32600f51U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xefce6423U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0xbaf836ceU),
                               bswap_32big(0x3fbc9494U),
                               bswap_32big(0x78bc39a0U),
                               bswap_32big(0x22114fcdU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x52f12453U),
                               bswap_32big(0xd24f8a3fU),
                               bswap_32big(0x1b3d9d34U),
                               bswap_32big(0x32ba1040U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xe1b59982U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x0000052eU));
    r_rsip_func101(bswap_32big(0xf96f7b36U),
                   bswap_32big(0x0ef2da94U),
                   bswap_32big(0x150e20ffU),
                   bswap_32big(0x81451993U));
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
        r_rsip_func100(bswap_32big(0x35e935c5U), bswap_32big(0xfe3ab7a8U), bswap_32big(0x569ae592U),
                       bswap_32big(0xb6fb9b8cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc0b882daU), bswap_32big(0x6b79b506U), bswap_32big(0x878192ebU),
                           bswap_32big(0xe83d2f96U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x26ea9794U), bswap_32big(0x3e23be27U), bswap_32big(0x9d9f6173U),
                           bswap_32big(0x97ddeee1U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xefce6423U));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052fU));
    r_rsip_func101(bswap_32big(0x646d9975U),
                   bswap_32big(0x99d0676aU),
                   bswap_32big(0xaa2c9accU),
                   bswap_32big(0x717f5470U));
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
        r_rsip_func100(bswap_32big(0x6146d37aU), bswap_32big(0xac03dea2U), bswap_32big(0xfa7225d0U),
                       bswap_32big(0xd6198c07U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0x558a3e6dU), bswap_32big(0x62301c75U), bswap_32big(0xe4e40691U),
                           bswap_32big(0xd90f9d57U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x4a30d047U), bswap_32big(0x80da0f26U), bswap_32big(0xf38f56f1U),
                           bswap_32big(0x4665dea3U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x63ee215dU),
                   bswap_32big(0xd597a3f3U),
                   bswap_32big(0x66bcc046U),
                   bswap_32big(0xc13d4fceU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);
        r_rsip_func101(bswap_32big(0xab771d04U), bswap_32big(0x07dd6904U), bswap_32big(0xcf0b7663U),
                       bswap_32big(0xb9bcddfaU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x9e690a55U), bswap_32big(0x024cdd30U), bswap_32big(0xe6ee06a9U),
                       bswap_32big(0x4423bd23U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
