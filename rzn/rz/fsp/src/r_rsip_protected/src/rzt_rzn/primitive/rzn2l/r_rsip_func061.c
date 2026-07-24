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
        r_rsip_func100(bswap_32big(0x475148f8U), bswap_32big(0x13bc6f9bU), bswap_32big(0x3d7b3cbcU),
                       bswap_32big(0x95a01652U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000230U, 0x00000230U, 0x4040000cU);
            r_rsip_subfunc004(0x00000660U, 0x00000660U, 0x4040000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x7605621bU), bswap_32big(0xc049d794U), bswap_32big(0x34a28461U),
                           bswap_32big(0x73e460a5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x7b0b8c3aU), bswap_32big(0x2871c2ffU), bswap_32big(0x94c50256U),
                           bswap_32big(0xa102dfa3U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18800000U);
    r_rsip_subfunc003(0x00c00211U);
    r_rsip_subfunc007(bswap_32big(0xd74b83dcU));
    OFS_ADR = 136;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000611U));
    r_rsip_func101(bswap_32big(0xce1b6fc3U),
                   bswap_32big(0x0cf0f4e7U),
                   bswap_32big(0xa82aba28U),
                   bswap_32big(0x295166f1U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x78d245b6U));
    OFS_ADR = 272;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
    r_rsip_func101(bswap_32big(0xf9ce5e92U),
                   bswap_32big(0x9d9a3460U),
                   bswap_32big(0x0c9012a8U),
                   bswap_32big(0xd833418bU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c001fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x861f84dbU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000613U));
    r_rsip_func101(bswap_32big(0xd2524277U),
                   bswap_32big(0xc2577780U),
                   bswap_32big(0x893db044U),
                   bswap_32big(0x0b3ed86bU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0988781dU));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
    r_rsip_func101(bswap_32big(0xc56e88dfU),
                   bswap_32big(0x5c8c4edbU),
                   bswap_32big(0x8db5de0fU),
                   bswap_32big(0xa9401682U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x1a2186a2U));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x00000615U));
    r_rsip_func101(bswap_32big(0x7c460ce1U),
                   bswap_32big(0x052d688eU),
                   bswap_32big(0x96ac5901U),
                   bswap_32big(0x60f368f7U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe66a71eeU));
    OFS_ADR = 676;
    r_rsip_subfunc008(0x14600000U, 0x00000080U, bswap_32big(0x00000616U));
    r_rsip_func101(bswap_32big(0x46a11270U),
                   bswap_32big(0xa2f77b1fU),
                   bswap_32big(0x880fafd9U),
                   bswap_32big(0x5a4fb5f8U));
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
        r_rsip_func100(bswap_32big(0x2b5b4a4eU), bswap_32big(0x4d0a9f70U), bswap_32big(0xf570dc29U),
                       bswap_32big(0x19090f5fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xc45569bbU), bswap_32big(0x7071028dU), bswap_32big(0xdc395f1cU),
                           bswap_32big(0xf6781a3eU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x861f84dbU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0x4ac6ec5bU), bswap_32big(0x50ae56e6U), bswap_32big(0x74f5077cU),
                           bswap_32big(0x69c83673U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd74b83dcU));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x8bd7e2b2U), bswap_32big(0xee1db9caU), bswap_32big(0xfb4ce34aU),
                           bswap_32big(0xdbed3eaaU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000611U));
            r_rsip_func101(bswap_32big(0xed642cb5U), bswap_32big(0x23dabc95U), bswap_32big(0x4e97aa47U),
                           bswap_32big(0x9827b20bU));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x861f84dbU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000617U));
            r_rsip_func101(bswap_32big(0xd14e1dddU), bswap_32big(0x42e63cccU), bswap_32big(0x19c215a1U),
                           bswap_32big(0x620d6f78U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd74b83dcU));
            OFS_ADR = 136;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000618U));
            r_rsip_func101(bswap_32big(0x183ca6a9U), bswap_32big(0x4b7b7c5bU), bswap_32big(0x444d34f3U),
                           bswap_32big(0xb3df85e2U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x78d245b6U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000613U));
            r_rsip_func101(bswap_32big(0xf695b217U), bswap_32big(0x6f227af2U), bswap_32big(0xbcb495d0U),
                           bswap_32big(0x08527e97U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0988781dU));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x00000614U));
            r_rsip_func101(bswap_32big(0x1ba47237U), bswap_32big(0xf3bb6b7bU), bswap_32big(0xc0ee8b34U),
                           bswap_32big(0xea88ad80U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc009(bswap_32big(0x00000612U));
            r_rsip_func101(bswap_32big(0x2c48abdfU), bswap_32big(0x4673f433U), bswap_32big(0x84437b52U),
                           bswap_32big(0x26995a86U));
            r_rsip_func062();
            r_rsip_subfunc007(bswap_32big(0x78d245b6U));
            OFS_ADR = 272;
            r_rsip_subfunc008(0x12380000U, 0x00000084U, bswap_32big(0x00000619U));
            r_rsip_func101(bswap_32big(0xfa32407bU), bswap_32big(0x93d62ea3U), bswap_32big(0xc6564159U),
                           bswap_32big(0x53eff2a6U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0988781dU));
            OFS_ADR = 408;
            r_rsip_subfunc008(0x18800000U, 0x00000084U, bswap_32big(0x0000061aU));
            r_rsip_func101(bswap_32big(0x9b211c9dU), bswap_32big(0xfa45b3f6U), bswap_32big(0xd205a307U),
                           bswap_32big(0x0bc6e1d8U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1dd80000U);
            r_rsip_subfunc003(0x00c00201U);
            r_rsip_subfunc001(0x00000230U, 0x00000fd8U, 0x00000878U, 0x40400009U);
            r_rsip_subfunc001(0x00000660U, 0x00000fd8U, 0x00000230U, 0x40400009U);
            r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000660U, 0x40400009U);
            r_rsip_subfunc001(0x00000230U, 0x00000660U, 0x00000878U, 0x4040000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x60a9ce21U), bswap_32big(0xc1a3a2f6U), bswap_32big(0xe756ac83U),
                           bswap_32big(0xdaef804dU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000878U, 0x00000fd8U, 0x00000230U, 0x40400009U);
                r_rsip_subfunc007(bswap_32big(0x861f84dbU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000615U));
                r_rsip_func101(bswap_32big(0x6ef96134U),
                               bswap_32big(0x5999ab72U),
                               bswap_32big(0xde9c9bcdU),
                               bswap_32big(0xfdaf62ffU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x78d245b6U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000616U));
                r_rsip_func101(bswap_32big(0x904fd35eU),
                               bswap_32big(0xb09b5e25U),
                               bswap_32big(0xd58c66e2U),
                               bswap_32big(0x528bd73fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000611U));
                r_rsip_func101(bswap_32big(0xbd087e96U),
                               bswap_32big(0x03cd64d8U),
                               bswap_32big(0x6eebcc4eU),
                               bswap_32big(0xcd115fbaU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x861f84dbU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0x40059303U),
                               bswap_32big(0x06468badU),
                               bswap_32big(0x8ab7a016U),
                               bswap_32big(0x5801ff3aU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd74b83dcU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x00000617U));
                r_rsip_func101(bswap_32big(0x972248e1U),
                               bswap_32big(0x43e30757U),
                               bswap_32big(0x86a96865U),
                               bswap_32big(0x5c447cd5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0988781dU));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x00000618U));
                r_rsip_func101(bswap_32big(0x24f9de69U),
                               bswap_32big(0xd5243512U),
                               bswap_32big(0x8d5eb921U),
                               bswap_32big(0x92bbfc7dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000612U));
                r_rsip_func101(bswap_32big(0x2a0161ffU),
                               bswap_32big(0x067d101fU),
                               bswap_32big(0x579bc6eeU),
                               bswap_32big(0xbe027b38U));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0xd74b83dcU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x545651c1U),
                               bswap_32big(0x570c47a0U),
                               bswap_32big(0x53a45e08U),
                               bswap_32big(0x37f3dfe3U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x37e61298U),
                               bswap_32big(0xea37eb17U),
                               bswap_32big(0x7bb0b600U),
                               bswap_32big(0x36d18467U));
            }
            else
            {
                r_rsip_subfunc001(0x00000660U, 0x00000230U, 0x00000660U, 0x4040000aU);
                r_rsip_subfunc007(bswap_32big(0x78d245b6U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061aU));
                r_rsip_func101(bswap_32big(0x8beec055U),
                               bswap_32big(0xb22eb7ddU),
                               bswap_32big(0xae6594d3U),
                               bswap_32big(0xa2d6115cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x861f84dbU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061bU));
                r_rsip_func101(bswap_32big(0xaf14a246U),
                               bswap_32big(0x5f5d1214U),
                               bswap_32big(0xc72a61f1U),
                               bswap_32big(0xd99d8a33U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000613U));
                r_rsip_func101(bswap_32big(0xe753035eU),
                               bswap_32big(0xd218c0b6U),
                               bswap_32big(0xa9ba9b21U),
                               bswap_32big(0x9daf50cbU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x78d245b6U));
                OFS_ADR = 272;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x5f667ba6U),
                               bswap_32big(0x615b6fd1U),
                               bswap_32big(0xe5e9cb1dU),
                               bswap_32big(0xb24fec8bU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0988781dU));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061cU));
                r_rsip_func101(bswap_32big(0x4c0cf1afU),
                               bswap_32big(0xcb5b8733U),
                               bswap_32big(0x16f5bb70U),
                               bswap_32big(0x28cc64f7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd74b83dcU));
                OFS_ADR = 136;
                r_rsip_subfunc008(0x1dc80000U, 0x00000084U, bswap_32big(0x0000061dU));
                r_rsip_func101(bswap_32big(0x53f8e70bU),
                               bswap_32big(0xa09f4dc6U),
                               bswap_32big(0x1ac89d3dU),
                               bswap_32big(0x9d75aacfU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000614U));
                r_rsip_func101(bswap_32big(0x9608965eU),
                               bswap_32big(0x22fdf037U),
                               bswap_32big(0xcb04703cU),
                               bswap_32big(0x3a3e01fdU));
                r_rsip_func311();
                r_rsip_subfunc007(bswap_32big(0x0988781dU));
                OFS_ADR = 408;
                r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061eU));
                r_rsip_func101(bswap_32big(0x23fc4111U),
                               bswap_32big(0xc5fc8fd9U),
                               bswap_32big(0x40763cd3U),
                               bswap_32big(0x3a185240U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xa02ab235U),
                               bswap_32big(0xe56265bdU),
                               bswap_32big(0x16b88285U),
                               bswap_32big(0x668a0cdcU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x1a2186a2U));
    OFS_ADR = 544;
    r_rsip_subfunc008(0x10300000U, 0x00000080U, bswap_32big(0x0000061eU));
    r_rsip_func101(bswap_32big(0x34b0d0dbU),
                   bswap_32big(0x965e1965U),
                   bswap_32big(0x44c73405U),
                   bswap_32big(0x6bc6bc58U));
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
        r_rsip_func100(bswap_32big(0xff0cb15fU), bswap_32big(0x0f6dbdabU), bswap_32big(0x8fdb27fdU),
                       bswap_32big(0x03068e55U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a90U, 0x00000660U, 0x00000660U, 0x40400008U);
            r_rsip_subfunc001(0x00000a90U, 0x00000230U, 0x00000230U, 0x40400008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x87a91941U), bswap_32big(0x38c7e1e6U), bswap_32big(0xcf6a169fU),
                           bswap_32big(0x5819c2a5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x6d634cb8U), bswap_32big(0x4f9a1e70U), bswap_32big(0x46382c7bU),
                           bswap_32big(0xb7a7a686U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x0988781dU));
    OFS_ADR = 408;
    r_rsip_subfunc008(0x16680000U, 0x00000084U, bswap_32big(0x0000061fU));
    r_rsip_func101(bswap_32big(0x0a601bd1U),
                   bswap_32big(0xec472915U),
                   bswap_32big(0x8b5b9f63U),
                   bswap_32big(0x5518cc4bU));
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
        r_rsip_func100(bswap_32big(0xa37fcdacU), bswap_32big(0x51325f61U), bswap_32big(0x7af83bacU),
                       bswap_32big(0xba8405f8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000878U, 0x00000230U, 0x00000878U, 0x4141000aU);
            r_rsip_func101(bswap_32big(0xf5f9d2f7U), bswap_32big(0x0f650540U), bswap_32big(0xa31120f3U),
                           bswap_32big(0x3a0685c0U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x550d0f7fU), bswap_32big(0xfb39e140U), bswap_32big(0xc93e5aebU),
                           bswap_32big(0x8cf23e8cU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x0580b4abU),
                   bswap_32big(0xbace839bU),
                   bswap_32big(0x076a35b5U),
                   bswap_32big(0x8ea49d70U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000230U, 0x00000878U, 0x00000878U, 0x4141000aU);
        r_rsip_func101(bswap_32big(0xccf9533cU), bswap_32big(0x52e87f63U), bswap_32big(0x2c4ca1aaU),
                       bswap_32big(0x61216736U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x52b0fc53U), bswap_32big(0xb678cfd4U), bswap_32big(0xdcbb8defU),
                       bswap_32big(0xda777660U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
