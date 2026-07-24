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

void r_rsip_func061 (void)
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
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1404H, 0x16580000U);
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
        r_rsip_func100(bswap_32big(0xaf0f6641U), bswap_32big(0x652e7cd5U), bswap_32big(0xe6af185dU),
                       bswap_32big(0xb2526508U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            r_rsip_subfunc004(0x00000660U, 0x00000660U, 0x4040000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x4c25ef04U), bswap_32big(0x6cacad46U), bswap_32big(0x36ad35dbU),
                           bswap_32big(0x73fa6bd5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x49e35572U), bswap_32big(0xa151e628U), bswap_32big(0x261f83c3U),
                           bswap_32big(0xc02b5844U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_subfunc003(0x00c00211U);
    r_rsip_subfunc007(bswap_32big(0x54b06b8cU));
    OFS_ADR = 136;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000611U));
    r_rsip_func101(bswap_32big(0xf0532aebU),
                   bswap_32big(0x9c8f4de0U),
                   bswap_32big(0x732aa0a5U),
                   bswap_32big(0x1d7e9c54U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x1ec17773U));
    OFS_ADR = 272;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
    r_rsip_func101(bswap_32big(0x57f8005eU),
                   bswap_32big(0x35cd380fU),
                   bswap_32big(0xf4b62055U),
                   bswap_32big(0x0c4315b2U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x1d5b6923U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000613U));
    r_rsip_func101(bswap_32big(0xa2c54801U),
                   bswap_32big(0xb1c0b8d0U),
                   bswap_32big(0xa4b719daU),
                   bswap_32big(0x8feebc4eU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
    r_rsip_func101(bswap_32big(0xfa2fe268U),
                   bswap_32big(0x5a1807b4U),
                   bswap_32big(0x559c44c2U),
                   bswap_32big(0xe428c543U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x4ea3f35fU));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x00000615U));
    r_rsip_func101(bswap_32big(0xf9473e10U),
                   bswap_32big(0x47c00126U),
                   bswap_32big(0xe074e901U),
                   bswap_32big(0x7d226d27U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xbe84871eU));
    OFS_ADR = 676;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00000616U));
    r_rsip_func101(bswap_32big(0xb36885a9U),
                   bswap_32big(0x823be4b1U),
                   bswap_32big(0x3ce0b9eeU),
                   bswap_32big(0x506f3260U));
    r_rsip_func016(OFS_ADR);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x18900000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c001fdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000230U, 0x00000a90U, 0x00000878U, 0x4040000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xbc3a956aU), bswap_32big(0xcbbd6541U), bswap_32big(0x43e28234U),
                       bswap_32big(0x6656d376U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xc62fbeafU), bswap_32big(0xcb8ef4c9U), bswap_32big(0xf11b9514U),
                           bswap_32big(0x2473995eU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x1d5b6923U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x54444896U), bswap_32big(0xa64145efU), bswap_32big(0x93c1538bU),
                           bswap_32big(0xdcdf157eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x54b06b8cU));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0xead782ffU), bswap_32big(0xe08a95f4U), bswap_32big(0xc3c96596U),
                           bswap_32big(0x991d68beU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0xf16bc744U), bswap_32big(0x93b85f2aU), bswap_32big(0x79ee4da3U),
                           bswap_32big(0x55189f34U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x1d5b6923U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000617U));
            r_rsip_func101(bswap_32big(0xd08bba87U), bswap_32big(0x08317fa0U), bswap_32big(0x88a08f26U),
                           bswap_32big(0x2ac1d616U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x54b06b8cU));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000618U));
            r_rsip_func101(bswap_32big(0xe69c18d9U), bswap_32big(0x5d8595e8U), bswap_32big(0x75146a07U),
                           bswap_32big(0x733746ebU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x1ec17773U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000613U));
            r_rsip_func101(bswap_32big(0xaf5c11caU), bswap_32big(0x4b2b4238U), bswap_32big(0x8d8b64ffU),
                           bswap_32big(0x85b67394U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
            r_rsip_func101(bswap_32big(0xf78296c8U), bswap_32big(0x134421c0U), bswap_32big(0xc838d853U),
                           bswap_32big(0xd1c3430dU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc009(bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x5847336fU), bswap_32big(0xdd37f608U), bswap_32big(0x94dc2bd2U),
                           bswap_32big(0x319f0194U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x1ec17773U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000619U));
            r_rsip_func101(bswap_32big(0xb692572cU), bswap_32big(0x7eafa449U), bswap_32big(0xe62c63dbU),
                           bswap_32big(0x8860fb4cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x0000061aU));
            r_rsip_func101(bswap_32big(0xe32481c5U), bswap_32big(0x56531146U), bswap_32big(0x89a4f6dbU),
                           bswap_32big(0x1c59b30cU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc001(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x5e120ea8U), bswap_32big(0x25c93bd6U), bswap_32big(0x880ed1adU),
                           bswap_32big(0x21f847a2U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);
                r_rsip_subfunc007(bswap_32big(0x1d5b6923U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000615U));
                r_rsip_func101(bswap_32big(0x58308e1bU),
                               bswap_32big(0xb6d59d22U),
                               bswap_32big(0x5a1b34b6U),
                               bswap_32big(0x61a63494U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x1ec17773U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000616U));
                r_rsip_func101(bswap_32big(0x16c9147cU),
                               bswap_32big(0xaabbfa3fU),
                               bswap_32big(0x9fe773e4U),
                               bswap_32big(0x91e3ec91U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000611U));
                r_rsip_func101(bswap_32big(0xc74a0fc7U),
                               bswap_32big(0xc2f5ecb9U),
                               bswap_32big(0x6717a43eU),
                               bswap_32big(0x9a3333daU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x1d5b6923U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x57219779U),
                               bswap_32big(0xf2cfacf5U),
                               bswap_32big(0x84d8d590U),
                               bswap_32big(0xbf614b00U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x54b06b8cU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000617U));
                r_rsip_func101(bswap_32big(0x7207777dU),
                               bswap_32big(0x260e451bU),
                               bswap_32big(0xa1c76620U),
                               bswap_32big(0x4c176015U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000618U));
                r_rsip_func101(bswap_32big(0x9df7922fU),
                               bswap_32big(0x36b46f0bU),
                               bswap_32big(0xdb271117U),
                               bswap_32big(0x494c00fcU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000612U));
                r_rsip_func101(bswap_32big(0x8ce204c1U),
                               bswap_32big(0xb8e5304aU),
                               bswap_32big(0x183b2ee4U),
                               bswap_32big(0x0e5b2c1eU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x54b06b8cU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x5580a90aU),
                               bswap_32big(0x844b088cU),
                               bswap_32big(0x46c2e9edU),
                               bswap_32big(0xe9c0518dU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xfbb71980U),
                               bswap_32big(0x54c4c76cU),
                               bswap_32big(0x648bf404U),
                               bswap_32big(0x9989c76aU));
            }
            else
            {
                r_rsip_subfunc001(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);
                r_rsip_subfunc007(bswap_32big(0x1ec17773U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061aU));
                r_rsip_func101(bswap_32big(0x92f6ff84U),
                               bswap_32big(0xb30fd3bfU),
                               bswap_32big(0x4d27a032U),
                               bswap_32big(0x3c736e9dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x1d5b6923U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x29f5fa3cU),
                               bswap_32big(0x9b584805U),
                               bswap_32big(0x6e85a25bU),
                               bswap_32big(0x9e428ceaU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000613U));
                r_rsip_func101(bswap_32big(0x22540edeU),
                               bswap_32big(0x0e7f3f9bU),
                               bswap_32big(0xe6607c3eU),
                               bswap_32big(0x6c915400U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x1ec17773U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x9fc273b3U),
                               bswap_32big(0xe6273a79U),
                               bswap_32big(0xfbdb8a3eU),
                               bswap_32big(0xb32e7e2aU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x1f03ff19U),
                               bswap_32big(0xb02b03eeU),
                               bswap_32big(0x9842b879U),
                               bswap_32big(0xebf18c9eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x54b06b8cU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x11448d88U),
                               bswap_32big(0xb225930cU),
                               bswap_32big(0x6c37daaaU),
                               bswap_32big(0xc6f1e84eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000614U));
                r_rsip_func101(bswap_32big(0x38ebfdfeU),
                               bswap_32big(0x8838a687U),
                               bswap_32big(0x20995dbdU),
                               bswap_32big(0x40189175U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061eU));
                r_rsip_func101(bswap_32big(0x1d5a2292U),
                               bswap_32big(0xff73e042U),
                               bswap_32big(0x63d3df28U),
                               bswap_32big(0x78c3d033U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xc40e746bU),
                               bswap_32big(0x6057b1cfU),
                               bswap_32big(0x4f9246c6U),
                               bswap_32big(0xf10ff3c9U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x4ea3f35fU));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x0000061eU));
    r_rsip_func101(bswap_32big(0x41fc1653U),
                   bswap_32big(0x1081d771U),
                   bswap_32big(0xe47c9cf8U),
                   bswap_32big(0x115b236cU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xddfb0b82U), bswap_32big(0xd35124ceU), bswap_32big(0x8fe6cbceU),
                       bswap_32big(0x314795a3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);
            r_rsip_subfunc001(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc175306cU), bswap_32big(0x6980be73U), bswap_32big(0xa72521ffU),
                           bswap_32big(0x6fdbd558U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xec666727U), bswap_32big(0x8f4847ecU), bswap_32big(0x398a8c5dU),
                           bswap_32big(0x0a444e7eU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xd4a2584aU));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061fU));
    r_rsip_func101(bswap_32big(0xa4bb88bcU),
                   bswap_32big(0xd1e8fc44U),
                   bswap_32big(0x8290c934U),
                   bswap_32big(0x59a9d9f4U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x16680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000a90U, 0x4141000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x31063888U), bswap_32big(0xa60ef839U), bswap_32big(0xa9538f4aU),
                       bswap_32big(0x6e1b4a2dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xd245313eU), bswap_32big(0x3e77a769U), bswap_32big(0xe7f845f2U),
                           bswap_32big(0x70d6875eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x313608baU), bswap_32big(0x6144de02U), bswap_32big(0xe86d44c3U),
                           bswap_32big(0x2e41bb80U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x781bff14U),
                   bswap_32big(0x74fffd4dU),
                   bswap_32big(0x38105ed2U),
                   bswap_32big(0x41e6ae88U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);
        r_rsip_func101(bswap_32big(0xd6aa4f00U), bswap_32big(0x5b4a7e3bU), bswap_32big(0xa76ed3b8U),
                       bswap_32big(0x8cf45b79U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xe49e400cU), bswap_32big(0xed1b8506U), bswap_32big(0x0f1f66bfU),
                       bswap_32big(0xb2ad793aU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
