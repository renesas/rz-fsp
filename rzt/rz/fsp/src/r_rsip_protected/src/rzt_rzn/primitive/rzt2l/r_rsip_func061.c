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
        r_rsip_func100(bswap_32big(0x2c1f8580U), bswap_32big(0xbf6bb2d8U), bswap_32big(0xb7d6d8d0U),
                       bswap_32big(0x540e9da3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            r_rsip_subfunc004(0x00000660U, 0x00000660U, 0x4040000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x33fd664bU), bswap_32big(0x33a8e2deU), bswap_32big(0x2e89a907U),
                           bswap_32big(0x74f51bf4U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x7dfefd58U), bswap_32big(0xba9a866bU), bswap_32big(0x892e9a64U),
                           bswap_32big(0xe7b0a827U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_subfunc003(0x00c00211U);
    r_rsip_subfunc007(bswap_32big(0xdeea3ad9U));
    OFS_ADR = 136;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000611U));
    r_rsip_func101(bswap_32big(0x99546dc8U),
                   bswap_32big(0x12a4b2edU),
                   bswap_32big(0xd12dba48U),
                   bswap_32big(0x636bf0faU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xada22b4bU));
    OFS_ADR = 272;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
    r_rsip_func101(bswap_32big(0xe6ec2a1bU),
                   bswap_32big(0xc2ddc2c3U),
                   bswap_32big(0x9697d08fU),
                   bswap_32big(0xb2cf001cU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x5bdd8d00U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000613U));
    r_rsip_func101(bswap_32big(0xc9f86d2eU),
                   bswap_32big(0x79cf9fd5U),
                   bswap_32big(0x77b74861U),
                   bswap_32big(0xf84f7483U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc75d1704U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
    r_rsip_func101(bswap_32big(0x705a2b8fU),
                   bswap_32big(0x84202b89U),
                   bswap_32big(0xe8f7febaU),
                   bswap_32big(0x4b285f65U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x2a8c92d0U));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x00000615U));
    r_rsip_func101(bswap_32big(0xc6061726U),
                   bswap_32big(0x8a663902U),
                   bswap_32big(0x390f26f7U),
                   bswap_32big(0x9903a85dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe7a909b7U));
    OFS_ADR = 676;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00000616U));
    r_rsip_func101(bswap_32big(0x2a6f1e3eU),
                   bswap_32big(0xe6ee8c07U),
                   bswap_32big(0x4b46e0e5U),
                   bswap_32big(0x5fc5ce6aU));
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
        r_rsip_func100(bswap_32big(0xa621719bU), bswap_32big(0x00bf4deeU), bswap_32big(0x8d4f9b8fU),
                       bswap_32big(0xfe376290U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x2ff49131U), bswap_32big(0x262bd7faU), bswap_32big(0x1c3126b1U),
                           bswap_32big(0x63333f7cU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x5bdd8d00U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x6532b105U), bswap_32big(0xf4e49ac6U), bswap_32big(0x7c070450U),
                           bswap_32big(0x15989e79U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xdeea3ad9U));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0xd5f20e10U), bswap_32big(0x02dd68ffU), bswap_32big(0x20b28f25U),
                           bswap_32big(0x3dd37465U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x629ca24aU), bswap_32big(0x76ab7265U), bswap_32big(0x7014ba92U),
                           bswap_32big(0xf363b0d5U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x5bdd8d00U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000617U));
            r_rsip_func101(bswap_32big(0xe3d26ffbU), bswap_32big(0x8e0d7f59U), bswap_32big(0x6993c382U),
                           bswap_32big(0xcd9f9f7eU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xdeea3ad9U));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000618U));
            r_rsip_func101(bswap_32big(0xcfe5ce44U), bswap_32big(0x5d704e23U), bswap_32big(0xe289bff2U),
                           bswap_32big(0x43ab4224U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xada22b4bU));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000613U));
            r_rsip_func101(bswap_32big(0x4096cccaU), bswap_32big(0x7d18e69dU), bswap_32big(0x1a79c92bU),
                           bswap_32big(0xa9517b92U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc75d1704U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
            r_rsip_func101(bswap_32big(0x9c25b491U), bswap_32big(0x73b01024U), bswap_32big(0x26bb88f4U),
                           bswap_32big(0x73ef1e41U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc009(bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x193313a9U), bswap_32big(0xe57d959eU), bswap_32big(0x21da370aU),
                           bswap_32big(0x9b7b76cdU));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0xada22b4bU));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000619U));
            r_rsip_func101(bswap_32big(0x7db085b6U), bswap_32big(0xea34edaaU), bswap_32big(0x72a12742U),
                           bswap_32big(0xa5f12d13U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc75d1704U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x0000061aU));
            r_rsip_func101(bswap_32big(0x9563fd4dU), bswap_32big(0x3795fa70U), bswap_32big(0x9c8be692U),
                           bswap_32big(0x56a89f9aU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc001(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x19a34002U), bswap_32big(0x1d560965U), bswap_32big(0x892d526bU),
                           bswap_32big(0xfbeeefd5U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);
                r_rsip_subfunc007(bswap_32big(0x5bdd8d00U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000615U));
                r_rsip_func101(bswap_32big(0x0f7ae54fU),
                               bswap_32big(0x95588888U),
                               bswap_32big(0x191b6835U),
                               bswap_32big(0xe09ce6bcU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xada22b4bU));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000616U));
                r_rsip_func101(bswap_32big(0x0968ae14U),
                               bswap_32big(0x1ab7ac12U),
                               bswap_32big(0xf192a9d0U),
                               bswap_32big(0xcffc69edU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000611U));
                r_rsip_func101(bswap_32big(0x18f55589U),
                               bswap_32big(0x5c71c55fU),
                               bswap_32big(0xcea007faU),
                               bswap_32big(0x7480009fU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x5bdd8d00U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x8dca25c0U),
                               bswap_32big(0x6867d30bU),
                               bswap_32big(0x00663bc7U),
                               bswap_32big(0x72d8ca15U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xdeea3ad9U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000617U));
                r_rsip_func101(bswap_32big(0x29359c59U),
                               bswap_32big(0x7687e8b7U),
                               bswap_32big(0x87dca0d1U),
                               bswap_32big(0xd7b78877U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc75d1704U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000618U));
                r_rsip_func101(bswap_32big(0xb5cfd926U),
                               bswap_32big(0x87ac082fU),
                               bswap_32big(0xe185f438U),
                               bswap_32big(0xfde3ffceU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000612U));
                r_rsip_func101(bswap_32big(0xd4809cd9U),
                               bswap_32big(0x418229d6U),
                               bswap_32big(0x9aebbaabU),
                               bswap_32big(0x1bd4637dU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xdeea3ad9U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x9401a049U),
                               bswap_32big(0x9adb2b51U),
                               bswap_32big(0xca343486U),
                               bswap_32big(0xcd196c03U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x546ae3eaU),
                               bswap_32big(0xe6cfbe95U),
                               bswap_32big(0x7e1ceec6U),
                               bswap_32big(0x60671a91U));
            }
            else
            {
                r_rsip_subfunc001(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);
                r_rsip_subfunc007(bswap_32big(0xada22b4bU));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061aU));
                r_rsip_func101(bswap_32big(0xb0a6ed32U),
                               bswap_32big(0x229ce0baU),
                               bswap_32big(0xbf06c37cU),
                               bswap_32big(0x22a9eb35U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5bdd8d00U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x5413d2e9U),
                               bswap_32big(0x951df0d4U),
                               bswap_32big(0xaab1ed5bU),
                               bswap_32big(0xfa7f3266U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000613U));
                r_rsip_func101(bswap_32big(0x7dd52385U),
                               bswap_32big(0x91abfc25U),
                               bswap_32big(0xf1f18fc6U),
                               bswap_32big(0x62fe17adU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xada22b4bU));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x74cb8ffdU),
                               bswap_32big(0x937a41edU),
                               bswap_32big(0x05f2ca89U),
                               bswap_32big(0x986be701U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc75d1704U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x4ad0f210U),
                               bswap_32big(0xfa08c541U),
                               bswap_32big(0x2c87d6e1U),
                               bswap_32big(0xc66a61c7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xdeea3ad9U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x74fc236bU),
                               bswap_32big(0xb3bda833U),
                               bswap_32big(0x721cc90aU),
                               bswap_32big(0x568eaea0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000614U));
                r_rsip_func101(bswap_32big(0xc3b30b44U),
                               bswap_32big(0x7e84747cU),
                               bswap_32big(0xee7ecfb8U),
                               bswap_32big(0xf1848369U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xc75d1704U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061eU));
                r_rsip_func101(bswap_32big(0xe88e7e4fU),
                               bswap_32big(0xc88bde13U),
                               bswap_32big(0xb4aa95c8U),
                               bswap_32big(0xc86dc6f2U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x49c77e43U),
                               bswap_32big(0x578fd2e5U),
                               bswap_32big(0x3791bc36U),
                               bswap_32big(0x72b58cabU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x2a8c92d0U));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x0000061eU));
    r_rsip_func101(bswap_32big(0x75f395d5U),
                   bswap_32big(0x94a4c0c7U),
                   bswap_32big(0xf4a71fe1U),
                   bswap_32big(0x77843963U));
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
        r_rsip_func100(bswap_32big(0x78a33886U), bswap_32big(0xece659a6U), bswap_32big(0x3ba9c690U),
                       bswap_32big(0x795259daU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);
            r_rsip_subfunc001(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xeb7e3507U), bswap_32big(0x07e3a76bU), bswap_32big(0x08002e6dU),
                           bswap_32big(0xdef57da0U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x1bf1ab57U), bswap_32big(0xb39d9f95U), bswap_32big(0x4c5386a8U),
                           bswap_32big(0xa433976aU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xc75d1704U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061fU));
    r_rsip_func101(bswap_32big(0x6f768d60U),
                   bswap_32big(0xdd094befU),
                   bswap_32big(0x2f23b63dU),
                   bswap_32big(0xcf52deb7U));
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
        r_rsip_func100(bswap_32big(0x454763dfU), bswap_32big(0x0b68021bU), bswap_32big(0x62802ae0U),
                       bswap_32big(0xef308ba4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xeee49069U), bswap_32big(0xb6bf2c96U), bswap_32big(0x9bb55286U),
                           bswap_32big(0x07c5e1d3U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xcb529ccaU), bswap_32big(0x741b55aaU), bswap_32big(0xb0b42fbcU),
                           bswap_32big(0x09a023a9U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xf666d099U),
                   bswap_32big(0x6fdec58cU),
                   bswap_32big(0xa78153a1U),
                   bswap_32big(0xd36cb01cU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);
        r_rsip_func101(bswap_32big(0x8b7bb91bU), bswap_32big(0xab9dbbc2U), bswap_32big(0xb87e8784U),
                       bswap_32big(0xe82d6ecdU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xdaef6732U), bswap_32big(0x6514bba2U), bswap_32big(0x2f74ce56U),
                       bswap_32big(0x79fe8ea8U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
