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
        r_rsip_func100(bswap_32big(0xc0a63f94U), bswap_32big(0x4b27aef9U), bswap_32big(0x20131da4U),
                       bswap_32big(0xe3acee4bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            r_rsip_subfunc004(0x00000660U, 0x00000660U, 0x4040000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc9359327U), bswap_32big(0x5ec08f50U), bswap_32big(0xf1599455U),
                           bswap_32big(0x04a3035aU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xa579e07dU), bswap_32big(0x504f4593U), bswap_32big(0x7306ed30U),
                           bswap_32big(0xc47393c2U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_subfunc003(0x00c00211U);
    r_rsip_subfunc007(bswap_32big(0xfa53965bU));
    OFS_ADR = 136;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000611U));
    r_rsip_func101(bswap_32big(0x6a3071ceU),
                   bswap_32big(0x2b089415U),
                   bswap_32big(0x5d9cbb4eU),
                   bswap_32big(0xf3f141c5U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x40ecbc25U));
    OFS_ADR = 272;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
    r_rsip_func101(bswap_32big(0x7fd20314U),
                   bswap_32big(0x38a89f31U),
                   bswap_32big(0x7a218e72U),
                   bswap_32big(0x593eed8fU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xdd677e57U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000613U));
    r_rsip_func101(bswap_32big(0x6df18e64U),
                   bswap_32big(0x082117b6U),
                   bswap_32big(0xd9aeb9e6U),
                   bswap_32big(0xd952ab4cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
    r_rsip_func101(bswap_32big(0x5b86baadU),
                   bswap_32big(0xeb2301cbU),
                   bswap_32big(0xba0d7ab9U),
                   bswap_32big(0x9e29d32eU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x06c243bbU));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x00000615U));
    r_rsip_func101(bswap_32big(0x86472bd7U),
                   bswap_32big(0x62a83821U),
                   bswap_32big(0x4d24df33U),
                   bswap_32big(0x37a956feU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x2914d4b0U));
    OFS_ADR = 676;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00000616U));
    r_rsip_func101(bswap_32big(0xeab3cdafU),
                   bswap_32big(0xe6c1a765U),
                   bswap_32big(0x6a8bcae3U),
                   bswap_32big(0x1ca635ddU));
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
        r_rsip_func100(bswap_32big(0xe6c60bb1U), bswap_32big(0xb745ad86U), bswap_32big(0x21a358e5U),
                       bswap_32big(0xd59ce80cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x99ebc17eU), bswap_32big(0xb18b6f2bU), bswap_32big(0xd51d88e4U),
                           bswap_32big(0x7b2c6198U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xdd677e57U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x66c0420eU), bswap_32big(0x3965d197U), bswap_32big(0xbe1b7518U),
                           bswap_32big(0x23716021U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xfa53965bU));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0xf4510385U), bswap_32big(0xbeeae3f7U), bswap_32big(0x552f0a3dU),
                           bswap_32big(0x249fd763U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x5662c796U), bswap_32big(0x42bd0f3fU), bswap_32big(0xfeb7ae8aU),
                           bswap_32big(0xde5408a6U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0xdd677e57U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000617U));
            r_rsip_func101(bswap_32big(0xded2360fU), bswap_32big(0xae609220U), bswap_32big(0x2210dee4U),
                           bswap_32big(0x8d48c760U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xfa53965bU));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000618U));
            r_rsip_func101(bswap_32big(0xb2a49d10U), bswap_32big(0xbb271f22U), bswap_32big(0x6a7e69a7U),
                           bswap_32big(0xffa30829U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x40ecbc25U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000613U));
            r_rsip_func101(bswap_32big(0x985b360bU), bswap_32big(0xcdf7c785U), bswap_32big(0xf91eac4cU),
                           bswap_32big(0x459a7172U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
            r_rsip_func101(bswap_32big(0x50edb5a0U), bswap_32big(0x19ddd2a8U), bswap_32big(0x0e162240U),
                           bswap_32big(0x30161ddfU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc009(bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0xe23eb0d3U), bswap_32big(0x0848772eU), bswap_32big(0x2a00bca1U),
                           bswap_32big(0x826fc861U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x40ecbc25U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000619U));
            r_rsip_func101(bswap_32big(0x5cafa571U), bswap_32big(0x5b9d5563U), bswap_32big(0x193346e3U),
                           bswap_32big(0xf93db5cfU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x0000061aU));
            r_rsip_func101(bswap_32big(0x338038d1U), bswap_32big(0x5e8b5474U), bswap_32big(0x10405788U),
                           bswap_32big(0xee235582U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc001(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x206b2d25U), bswap_32big(0xaaba5cc5U), bswap_32big(0x54a8bbbbU),
                           bswap_32big(0x63ef5e59U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);
                r_rsip_subfunc007(bswap_32big(0xdd677e57U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000615U));
                r_rsip_func101(bswap_32big(0x66e03962U),
                               bswap_32big(0xd4e37346U),
                               bswap_32big(0x6c724cecU),
                               bswap_32big(0xb1fce91aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x40ecbc25U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000616U));
                r_rsip_func101(bswap_32big(0x8acbe56dU),
                               bswap_32big(0x96bd30ceU),
                               bswap_32big(0x806c9043U),
                               bswap_32big(0xdc619317U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000611U));
                r_rsip_func101(bswap_32big(0x3b2e9dc0U),
                               bswap_32big(0xf3394d21U),
                               bswap_32big(0x347fd4efU),
                               bswap_32big(0x69ab5889U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xdd677e57U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0xb0c66a83U),
                               bswap_32big(0x7fb2c110U),
                               bswap_32big(0xdc76c578U),
                               bswap_32big(0x5f0bdf29U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xfa53965bU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000617U));
                r_rsip_func101(bswap_32big(0x6a792553U),
                               bswap_32big(0xebcc9057U),
                               bswap_32big(0x6ecf1d2cU),
                               bswap_32big(0x0f6febadU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000618U));
                r_rsip_func101(bswap_32big(0xec296449U),
                               bswap_32big(0xee99cd39U),
                               bswap_32big(0xd65ae7b8U),
                               bswap_32big(0x48a84cd5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000612U));
                r_rsip_func101(bswap_32big(0x4ccd1825U),
                               bswap_32big(0x8c87bfb6U),
                               bswap_32big(0x18b69edfU),
                               bswap_32big(0x67001d00U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xfa53965bU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0xcf77322aU),
                               bswap_32big(0x32d71f46U),
                               bswap_32big(0xbe5ec1c7U),
                               bswap_32big(0xc6d0421fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x6bae71c5U),
                               bswap_32big(0x50c06755U),
                               bswap_32big(0x305ce6f3U),
                               bswap_32big(0x27cc55daU));
            }
            else
            {
                r_rsip_subfunc001(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);
                r_rsip_subfunc007(bswap_32big(0x40ecbc25U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061aU));
                r_rsip_func101(bswap_32big(0x12f0acfdU),
                               bswap_32big(0x68a5c5e1U),
                               bswap_32big(0xb64121e8U),
                               bswap_32big(0x3808c369U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xdd677e57U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0xd932eecbU),
                               bswap_32big(0xa063b93aU),
                               bswap_32big(0x8b9ad30dU),
                               bswap_32big(0xcebf2927U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000613U));
                r_rsip_func101(bswap_32big(0x4b9a5a02U),
                               bswap_32big(0x68ba7b82U),
                               bswap_32big(0x5b0e1ccdU),
                               bswap_32big(0xa5257470U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x40ecbc25U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0xe17a73e4U),
                               bswap_32big(0x504bc8b4U),
                               bswap_32big(0x8f22dd6eU),
                               bswap_32big(0xb88df354U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x2fbbbbd8U),
                               bswap_32big(0x2cfdbd84U),
                               bswap_32big(0x50795eeeU),
                               bswap_32big(0x91859bf0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xfa53965bU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0xad19485cU),
                               bswap_32big(0x2da387d7U),
                               bswap_32big(0xddce0349U),
                               bswap_32big(0xaebcf5b7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000614U));
                r_rsip_func101(bswap_32big(0x28f82f55U),
                               bswap_32big(0x45803627U),
                               bswap_32big(0x5eaf9269U),
                               bswap_32big(0x3bf73717U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061eU));
                r_rsip_func101(bswap_32big(0x77f30774U),
                               bswap_32big(0x92b46bd3U),
                               bswap_32big(0x822dae3eU),
                               bswap_32big(0x4a4b3d47U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xb27c8d97U),
                               bswap_32big(0xd3cb1d5cU),
                               bswap_32big(0x121387caU),
                               bswap_32big(0x6d20902bU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x06c243bbU));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x0000061eU));
    r_rsip_func101(bswap_32big(0xf393a2cdU),
                   bswap_32big(0xe6a90aa9U),
                   bswap_32big(0x0664cc10U),
                   bswap_32big(0x31ac1c8cU));
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
        r_rsip_func100(bswap_32big(0xa10381b9U), bswap_32big(0xd0297182U), bswap_32big(0xf7b6d30dU),
                       bswap_32big(0x5e3ef14dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);
            r_rsip_subfunc001(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xcece6b4dU), bswap_32big(0x74b8150dU), bswap_32big(0x72fa7cffU),
                           bswap_32big(0xb478a252U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x770f0264U), bswap_32big(0x81a1217fU), bswap_32big(0x273db19dU),
                           bswap_32big(0x5fb53e3aU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x2760e6c9U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061fU));
    r_rsip_func101(bswap_32big(0xaa2bd2daU),
                   bswap_32big(0x9f8deaebU),
                   bswap_32big(0x5f1c2dd3U),
                   bswap_32big(0xf8f26260U));
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
        r_rsip_func100(bswap_32big(0x987268d2U), bswap_32big(0x9d3c6263U), bswap_32big(0xeeed3f75U),
                       bswap_32big(0x585648ddU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xb3b78e50U), bswap_32big(0x353f2fc1U), bswap_32big(0xc10965fbU),
                           bswap_32big(0xd16573d5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xda2fa51bU), bswap_32big(0xe19cb4f2U), bswap_32big(0xa28e2bbdU),
                           bswap_32big(0xca498a5bU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x2c47a996U),
                   bswap_32big(0xd69bc884U),
                   bswap_32big(0x59af3ed4U),
                   bswap_32big(0x1ab39e04U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);
        r_rsip_func101(bswap_32big(0xc43cfa69U), bswap_32big(0x8b3e2c3aU), bswap_32big(0x73cdaf1fU),
                       bswap_32big(0x50edfb5cU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xc173d4d9U), bswap_32big(0x73463044U), bswap_32big(0x814e924dU),
                       bswap_32big(0x1b5a7830U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
