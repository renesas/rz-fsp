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
        r_rsip_func100(bswap_32big(0x55228aedU), bswap_32big(0x5c7d92beU), bswap_32big(0xa856814dU),
                       bswap_32big(0x8fff8ec1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            r_rsip_subfunc004(0x00000660U, 0x00000660U, 0x4040000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x0b9bdd64U), bswap_32big(0xd54c9202U), bswap_32big(0x6239bbe9U),
                           bswap_32big(0x659bda6cU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xee525abdU), bswap_32big(0xeb70a7fdU), bswap_32big(0x20208291U),
                           bswap_32big(0x9deebd71U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_subfunc003(0x00c00211U);
    r_rsip_subfunc007(bswap_32big(0xf9bf3112U));
    OFS_ADR = 136;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000611U));
    r_rsip_func101(bswap_32big(0xd931276cU),
                   bswap_32big(0xb5ffa2d4U),
                   bswap_32big(0x5f59ce9fU),
                   bswap_32big(0x39f5b91dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x5bfa91b0U));
    OFS_ADR = 272;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
    r_rsip_func101(bswap_32big(0x232c397cU),
                   bswap_32big(0x825f1432U),
                   bswap_32big(0xaffe54bdU),
                   bswap_32big(0x093a0465U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x9fd531f0U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000613U));
    r_rsip_func101(bswap_32big(0x7728db40U),
                   bswap_32big(0x8c2fb486U),
                   bswap_32big(0xd48ebffcU),
                   bswap_32big(0x704ac698U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
    r_rsip_func101(bswap_32big(0xc1a86bcfU),
                   bswap_32big(0xf95d1bc7U),
                   bswap_32big(0xc7f1c114U),
                   bswap_32big(0x5ee89681U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x7edfb1abU));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x00000615U));
    r_rsip_func101(bswap_32big(0x9d2649d1U),
                   bswap_32big(0x02ae831fU),
                   bswap_32big(0xb00421c4U),
                   bswap_32big(0x3db376a2U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x8162b38bU));
    OFS_ADR = 676;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00000616U));
    r_rsip_func101(bswap_32big(0x94e39018U),
                   bswap_32big(0x28078b57U),
                   bswap_32big(0x9798eff9U),
                   bswap_32big(0x7655ef5fU));
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
        r_rsip_func100(bswap_32big(0xeadea5ffU), bswap_32big(0xa45f8ac5U), bswap_32big(0x2e21a355U),
                       bswap_32big(0xeacdfd08U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x39221f4cU), bswap_32big(0x7993dfa9U), bswap_32big(0x44afd7e5U),
                           bswap_32big(0x3ab99b80U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x9fd531f0U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0xe9471416U), bswap_32big(0xc9b2da76U), bswap_32big(0x01cd942aU),
                           bswap_32big(0x9674f8a8U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf9bf3112U));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x1936b14eU), bswap_32big(0x7eb5f317U), bswap_32big(0x4d8cde27U),
                           bswap_32big(0xcf3535efU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x9f710b3aU), bswap_32big(0x921d6adaU), bswap_32big(0xc3d1ac49U),
                           bswap_32big(0x6bf30e00U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x9fd531f0U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000617U));
            r_rsip_func101(bswap_32big(0x5a694668U), bswap_32big(0x2e87ac6cU), bswap_32big(0x2c3d9644U),
                           bswap_32big(0xcaecf954U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf9bf3112U));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000618U));
            r_rsip_func101(bswap_32big(0xad187f81U), bswap_32big(0x62813e75U), bswap_32big(0x96476abbU),
                           bswap_32big(0xae505c3cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5bfa91b0U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000613U));
            r_rsip_func101(bswap_32big(0xa959f43fU), bswap_32big(0xf538162fU), bswap_32big(0x6f8bd5cbU),
                           bswap_32big(0x98210114U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
            r_rsip_func101(bswap_32big(0x0b074593U), bswap_32big(0x715537ebU), bswap_32big(0x37d7242cU),
                           bswap_32big(0x45345fd9U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc009(bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x092eb88eU), bswap_32big(0x991a834cU), bswap_32big(0x61e84deaU),
                           bswap_32big(0xb1b52983U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x5bfa91b0U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000619U));
            r_rsip_func101(bswap_32big(0xc58464beU), bswap_32big(0x5d92ce5bU), bswap_32big(0x53189be3U),
                           bswap_32big(0x5a584bdfU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x0000061aU));
            r_rsip_func101(bswap_32big(0xcff03632U), bswap_32big(0x7aa53254U), bswap_32big(0xc553990aU),
                           bswap_32big(0x10c4bb48U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc001(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x1976fb02U), bswap_32big(0xf0553e69U), bswap_32big(0x29a4824cU),
                           bswap_32big(0x8eebe3e1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);
                r_rsip_subfunc007(bswap_32big(0x9fd531f0U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000615U));
                r_rsip_func101(bswap_32big(0x4303108aU),
                               bswap_32big(0x9bc22579U),
                               bswap_32big(0xf15899f9U),
                               bswap_32big(0x18d4b0a3U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5bfa91b0U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000616U));
                r_rsip_func101(bswap_32big(0x79dfb92cU),
                               bswap_32big(0xb2f54126U),
                               bswap_32big(0xa5180272U),
                               bswap_32big(0x332fefd9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000611U));
                r_rsip_func101(bswap_32big(0xa01fe0d0U),
                               bswap_32big(0x425957aaU),
                               bswap_32big(0x80769576U),
                               bswap_32big(0xe48b77d1U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x9fd531f0U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x8cf4bb7bU),
                               bswap_32big(0xd469af2cU),
                               bswap_32big(0xb101542cU),
                               bswap_32big(0x6a9e2f53U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf9bf3112U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000617U));
                r_rsip_func101(bswap_32big(0xbf6d9c60U),
                               bswap_32big(0xc60ad2aeU),
                               bswap_32big(0x5b18b3b2U),
                               bswap_32big(0xb8dea73aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000618U));
                r_rsip_func101(bswap_32big(0x3dbfd214U),
                               bswap_32big(0x4263fff9U),
                               bswap_32big(0x8695c218U),
                               bswap_32big(0x1dfd9a51U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000612U));
                r_rsip_func101(bswap_32big(0x44e45d4fU),
                               bswap_32big(0x3c4c5e25U),
                               bswap_32big(0xeebf9c64U),
                               bswap_32big(0x17adf2b9U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xf9bf3112U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0xf9bee976U),
                               bswap_32big(0x7bc87811U),
                               bswap_32big(0x76ae2963U),
                               bswap_32big(0x97c5738cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xab8b652fU),
                               bswap_32big(0x6e6e37e5U),
                               bswap_32big(0xf9afc0b7U),
                               bswap_32big(0xb55dc035U));
            }
            else
            {
                r_rsip_subfunc001(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);
                r_rsip_subfunc007(bswap_32big(0x5bfa91b0U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061aU));
                r_rsip_func101(bswap_32big(0x73bad636U),
                               bswap_32big(0x0c428e8bU),
                               bswap_32big(0xb47df412U),
                               bswap_32big(0x46469747U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9fd531f0U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0xc0db1047U),
                               bswap_32big(0x78751c7dU),
                               bswap_32big(0x14267251U),
                               bswap_32big(0x24cf21d0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000613U));
                r_rsip_func101(bswap_32big(0x80bed5ecU),
                               bswap_32big(0x84e26cdaU),
                               bswap_32big(0xdc2e7fbbU),
                               bswap_32big(0x2731469aU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x5bfa91b0U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0xe04b3e29U),
                               bswap_32big(0x3f9884a7U),
                               bswap_32big(0xe2fc5587U),
                               bswap_32big(0xcb2ee6e2U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x58757066U),
                               bswap_32big(0xe3baea07U),
                               bswap_32big(0x251661a7U),
                               bswap_32big(0x9470bdebU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf9bf3112U));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0xa1f5d73fU),
                               bswap_32big(0x07654696U),
                               bswap_32big(0xfb3f3ec2U),
                               bswap_32big(0x751148f1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000614U));
                r_rsip_func101(bswap_32big(0x5bbfa3abU),
                               bswap_32big(0xcedce571U),
                               bswap_32big(0xee05d61fU),
                               bswap_32big(0x03603a60U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061eU));
                r_rsip_func101(bswap_32big(0xf822e6cdU),
                               bswap_32big(0xaeb8e03bU),
                               bswap_32big(0x21e37595U),
                               bswap_32big(0x2c0c04d5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xb1a87e5dU),
                               bswap_32big(0x2e79008aU),
                               bswap_32big(0x5cab92b6U),
                               bswap_32big(0x33b31425U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x7edfb1abU));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x0000061eU));
    r_rsip_func101(bswap_32big(0xeb7452e3U),
                   bswap_32big(0xcf797655U),
                   bswap_32big(0xab92499aU),
                   bswap_32big(0xd1066d6eU));
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
        r_rsip_func100(bswap_32big(0x22c67d18U), bswap_32big(0x033b6e61U), bswap_32big(0x94f0325dU),
                       bswap_32big(0x5293aa9aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);
            r_rsip_subfunc001(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x4b5ee54dU), bswap_32big(0x83dc914fU), bswap_32big(0x5175c78eU),
                           bswap_32big(0x971176b5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x73e6e316U), bswap_32big(0x63dbdc72U), bswap_32big(0x7901b10eU),
                           bswap_32big(0xf4039798U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x0c0ab7c4U));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061fU));
    r_rsip_func101(bswap_32big(0x6738e1eeU),
                   bswap_32big(0xe423711aU),
                   bswap_32big(0x80ca1f44U),
                   bswap_32big(0x196862e0U));
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
        r_rsip_func100(bswap_32big(0x57b1ad75U), bswap_32big(0x79dbfb60U), bswap_32big(0x36208e2bU),
                       bswap_32big(0x9c4a0916U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xdf3a9ca2U), bswap_32big(0xfe43ad16U), bswap_32big(0x88a65f51U),
                           bswap_32big(0x33792146U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x7bfea140U), bswap_32big(0xb46901d2U), bswap_32big(0x65cb0064U),
                           bswap_32big(0x202b4aa3U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xaf0ad40fU),
                   bswap_32big(0x0b4549b8U),
                   bswap_32big(0xcce7b8c6U),
                   bswap_32big(0xf8e66921U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);
        r_rsip_func101(bswap_32big(0x23f2a21eU), bswap_32big(0x08d86473U), bswap_32big(0x3452f529U),
                       bswap_32big(0x2744b548U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x04cdc55eU), bswap_32big(0x89f6bc08U), bswap_32big(0x3f8e02bcU),
                       bswap_32big(0xdd2d7ac3U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
