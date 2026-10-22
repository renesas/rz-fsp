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
        r_rsip_func100(bswap_32big(0xa409bd4fU), bswap_32big(0x19345479U), bswap_32big(0xdf525545U),
                       bswap_32big(0xc9e7d56eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            r_rsip_subfunc004(0x00000660U, 0x00000660U, 0x4040000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd4eca91aU), bswap_32big(0xca968847U), bswap_32big(0xa45970a2U),
                           bswap_32big(0x4081704fU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x410afb72U), bswap_32big(0x269e2314U), bswap_32big(0x20c383baU),
                           bswap_32big(0xec255956U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_subfunc003(0x00c00211U);
    r_rsip_subfunc007(bswap_32big(0x7192a079U));
    OFS_ADR = 136;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000611U));
    r_rsip_func101(bswap_32big(0xc24b2c11U),
                   bswap_32big(0x54f4145fU),
                   bswap_32big(0x97277632U),
                   bswap_32big(0xe509c339U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x3d1f6e52U));
    OFS_ADR = 272;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
    r_rsip_func101(bswap_32big(0x28cbc2e2U),
                   bswap_32big(0x1c7d2664U),
                   bswap_32big(0x6037e3f9U),
                   bswap_32big(0x67e12e05U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xf4900f00U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000613U));
    r_rsip_func101(bswap_32big(0xf9081881U),
                   bswap_32big(0xb4976830U),
                   bswap_32big(0x7736e4a2U),
                   bswap_32big(0xda1c781bU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xa6dec343U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
    r_rsip_func101(bswap_32big(0x5aed3bd5U),
                   bswap_32big(0xb1c4e381U),
                   bswap_32big(0x287b0046U),
                   bswap_32big(0x9528c73bU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x53a951d5U));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x00000615U));
    r_rsip_func101(bswap_32big(0x915806abU),
                   bswap_32big(0xe2a64516U),
                   bswap_32big(0x3f9ae113U),
                   bswap_32big(0x47299249U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x42352bf5U));
    OFS_ADR = 676;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00000616U));
    r_rsip_func101(bswap_32big(0x0c5da01bU),
                   bswap_32big(0x6a157af9U),
                   bswap_32big(0xd78ae211U),
                   bswap_32big(0x9c1a32fdU));
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
        r_rsip_func100(bswap_32big(0x5d06c960U), bswap_32big(0x54004f7fU), bswap_32big(0x511fc93fU),
                       bswap_32big(0x37ce54f7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xa6c62e2bU), bswap_32big(0x5a1166e8U), bswap_32big(0xf704994dU),
                           bswap_32big(0x829382d4U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xf4900f00U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0xdc9b3d61U), bswap_32big(0x859dcb4bU), bswap_32big(0x3d2884a0U),
                           bswap_32big(0xce23ad52U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x7192a079U));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x136a681dU), bswap_32big(0x338cabbdU), bswap_32big(0x13f4aa10U),
                           bswap_32big(0xab7fccc8U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x6803a610U), bswap_32big(0x23fae0b1U), bswap_32big(0x64a825dfU),
                           bswap_32big(0xa093849aU));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0xf4900f00U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000617U));
            r_rsip_func101(bswap_32big(0x04160c18U), bswap_32big(0x0d3bd58bU), bswap_32big(0x077f5ad0U),
                           bswap_32big(0x70785469U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x7192a079U));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000618U));
            r_rsip_func101(bswap_32big(0x8cc93db4U), bswap_32big(0xa97b94faU), bswap_32big(0x670ab593U),
                           bswap_32big(0xfa75bb10U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x3d1f6e52U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000613U));
            r_rsip_func101(bswap_32big(0xa9d0c118U), bswap_32big(0xe7686804U), bswap_32big(0x659dbe77U),
                           bswap_32big(0x02a0b605U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa6dec343U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
            r_rsip_func101(bswap_32big(0xf370d2a4U), bswap_32big(0xdfd415e0U), bswap_32big(0x6195afc3U),
                           bswap_32big(0xf870856aU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc009(bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0xbef807d4U), bswap_32big(0x483e12bdU), bswap_32big(0x941e55ffU),
                           bswap_32big(0x002b444dU));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x3d1f6e52U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000619U));
            r_rsip_func101(bswap_32big(0x3bd36b75U), bswap_32big(0xe4566f5fU), bswap_32big(0x36c05e58U),
                           bswap_32big(0xa05ac938U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa6dec343U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x0000061aU));
            r_rsip_func101(bswap_32big(0x6e5c9e4bU), bswap_32big(0xbd2d5aedU), bswap_32big(0x17eaf1bbU),
                           bswap_32big(0xcea3b9baU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc001(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x07757c0aU), bswap_32big(0x3d50390bU), bswap_32big(0xa7cb85f6U),
                           bswap_32big(0x0abb7313U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);
                r_rsip_subfunc007(bswap_32big(0xf4900f00U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000615U));
                r_rsip_func101(bswap_32big(0x44e3dba1U),
                               bswap_32big(0x428a9ab2U),
                               bswap_32big(0x80efe83dU),
                               bswap_32big(0xbb94c2abU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x3d1f6e52U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000616U));
                r_rsip_func101(bswap_32big(0xd2d09d6fU),
                               bswap_32big(0x27055b2cU),
                               bswap_32big(0xee428ea1U),
                               bswap_32big(0xe3b19b1fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000611U));
                r_rsip_func101(bswap_32big(0xf52e21b2U),
                               bswap_32big(0xc85b1928U),
                               bswap_32big(0x7ca993c2U),
                               bswap_32big(0x8d83eddbU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xf4900f00U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x2dea9a16U),
                               bswap_32big(0x8c61660aU),
                               bswap_32big(0x93c50e1bU),
                               bswap_32big(0x31eb8806U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x7192a079U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000617U));
                r_rsip_func101(bswap_32big(0x54190b9bU),
                               bswap_32big(0xff79c7caU),
                               bswap_32big(0x6e20eabdU),
                               bswap_32big(0x8bca9140U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa6dec343U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000618U));
                r_rsip_func101(bswap_32big(0x9f7aac49U),
                               bswap_32big(0xe716c935U),
                               bswap_32big(0x843006c2U),
                               bswap_32big(0xa9783abbU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000612U));
                r_rsip_func101(bswap_32big(0xb7af3003U),
                               bswap_32big(0xa5971663U),
                               bswap_32big(0x305899e7U),
                               bswap_32big(0x18521a3dU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x7192a079U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x62e28d6fU),
                               bswap_32big(0x5d1762c6U),
                               bswap_32big(0xfcb8bc08U),
                               bswap_32big(0xfc501432U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x3fc02f26U),
                               bswap_32big(0x3f810ed6U),
                               bswap_32big(0xab9e2b89U),
                               bswap_32big(0xc88030f0U));
            }
            else
            {
                r_rsip_subfunc001(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);
                r_rsip_subfunc007(bswap_32big(0x3d1f6e52U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061aU));
                r_rsip_func101(bswap_32big(0x7738d070U),
                               bswap_32big(0x53bbf05aU),
                               bswap_32big(0x5285398eU),
                               bswap_32big(0xddec275fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf4900f00U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0xa8f1a055U),
                               bswap_32big(0xb4fd83c2U),
                               bswap_32big(0x2971b8ceU),
                               bswap_32big(0x86fa6062U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000613U));
                r_rsip_func101(bswap_32big(0xc7578f4eU),
                               bswap_32big(0x23c2d7cdU),
                               bswap_32big(0xf83435bbU),
                               bswap_32big(0x22db7111U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x3d1f6e52U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x5f14bbb3U),
                               bswap_32big(0x85655bdfU),
                               bswap_32big(0xbf3eca7bU),
                               bswap_32big(0xcb8c51b5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa6dec343U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x30dfc6f6U),
                               bswap_32big(0x2c77a4bfU),
                               bswap_32big(0xd50d6e76U),
                               bswap_32big(0xc519148fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x7192a079U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x2abc5c36U),
                               bswap_32big(0x53e723cfU),
                               bswap_32big(0x0272d079U),
                               bswap_32big(0xcb0f8364U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000614U));
                r_rsip_func101(bswap_32big(0x53f93ff1U),
                               bswap_32big(0xf58fee1fU),
                               bswap_32big(0x21c73f3cU),
                               bswap_32big(0xbdeba7dbU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xa6dec343U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061eU));
                r_rsip_func101(bswap_32big(0xaf51514cU),
                               bswap_32big(0xd68af533U),
                               bswap_32big(0x7d0914cdU),
                               bswap_32big(0x36a613ceU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xc5984b19U),
                               bswap_32big(0x322c836cU),
                               bswap_32big(0x76a34e6eU),
                               bswap_32big(0x016c545eU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x53a951d5U));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x0000061eU));
    r_rsip_func101(bswap_32big(0x709b64b3U),
                   bswap_32big(0xec9f15c7U),
                   bswap_32big(0x99716407U),
                   bswap_32big(0x30a9466eU));
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
        r_rsip_func100(bswap_32big(0x5eafeaeeU), bswap_32big(0x2a2207a3U), bswap_32big(0xab476decU),
                       bswap_32big(0x4e1e8f54U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);
            r_rsip_subfunc001(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc4764209U), bswap_32big(0x04cf9ac4U), bswap_32big(0x52497839U),
                           bswap_32big(0xb9068b73U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x73e5451aU), bswap_32big(0x94b7faf7U), bswap_32big(0x18f47e6cU),
                           bswap_32big(0xa69a3552U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xa6dec343U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061fU));
    r_rsip_func101(bswap_32big(0xdac2bd9dU),
                   bswap_32big(0xd9d34f87U),
                   bswap_32big(0x2c736e96U),
                   bswap_32big(0x7f10a486U));
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
        r_rsip_func100(bswap_32big(0x4ed6b8b4U), bswap_32big(0xc0179685U), bswap_32big(0x7a16a9adU),
                       bswap_32big(0xa35b0662U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xd85a77cfU), bswap_32big(0x46fa5716U), bswap_32big(0x40c1db6bU),
                           bswap_32big(0xcd470b51U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x54e41d29U), bswap_32big(0x2c054769U), bswap_32big(0x04b933f4U),
                           bswap_32big(0x528e30a6U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xcee7d138U),
                   bswap_32big(0xd227a51eU),
                   bswap_32big(0x36fb92c0U),
                   bswap_32big(0xccca75b2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);
        r_rsip_func101(bswap_32big(0x1b2ddc0dU), bswap_32big(0x142aa33eU), bswap_32big(0x8b2e76ddU),
                       bswap_32big(0x398e60e1U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x964ac959U), bswap_32big(0xef072b32U), bswap_32big(0xeb96a003U),
                       bswap_32big(0x14157ab4U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
