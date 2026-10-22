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

void r_rsip_func050 (void)
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
        r_rsip_func100(bswap_32big(0xb9ea5f1dU), bswap_32big(0x96b62dd8U), bswap_32big(0x06789bebU),
                       bswap_32big(0x52f42d8cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x0808000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x59092bcaU), bswap_32big(0x9462e9b3U), bswap_32big(0xba404301U),
                           bswap_32big(0x283fa41fU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xfbe65d9eU), bswap_32big(0x86b66c6dU), bswap_32big(0xd4574de1U),
                           bswap_32big(0x807ee12eU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19f00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0x845b545eU));
    OFS_ADR = 24;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000501U));
    r_rsip_func101(bswap_32big(0xa3ce4678U),
                   bswap_32big(0x9e64a366U),
                   bswap_32big(0xfb3a5b4cU),
                   bswap_32big(0x893c4fcaU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc7a2d32aU));
    OFS_ADR = 48;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
    r_rsip_func101(bswap_32big(0x671597e2U),
                   bswap_32big(0x059b2064U),
                   bswap_32big(0xcc70d6a6U),
                   bswap_32big(0xb5dae871U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xeb62928bU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000503U));
    r_rsip_func101(bswap_32big(0x85126ca4U),
                   bswap_32big(0xb199025bU),
                   bswap_32big(0xa58bd97fU),
                   bswap_32big(0x873370eaU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
    r_rsip_func101(bswap_32big(0x770420beU),
                   bswap_32big(0x82bf452bU),
                   bswap_32big(0xde6f2c3aU),
                   bswap_32big(0xfd0d938cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x23cdc410U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x00000505U));
    r_rsip_func101(bswap_32big(0x34c3ae88U),
                   bswap_32big(0x7f9bd957U),
                   bswap_32big(0x86a14c56U),
                   bswap_32big(0x118cd357U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15f00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x8090001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430041U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x1a000000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x05bdf1f0U), bswap_32big(0x53d5ecd8U), bswap_32big(0x4f315081U),
                       bswap_32big(0xba62009bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x1711bb59U), bswap_32big(0x55f75043U), bswap_32big(0x117ba49dU),
                           bswap_32big(0x05d9450dU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xeb62928bU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0xe0736c74U), bswap_32big(0x2169722cU), bswap_32big(0xea18fccaU),
                           bswap_32big(0x556c19d0U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x845b545eU));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0xbae9ceb2U), bswap_32big(0x2de98bb8U), bswap_32big(0x6789e566U),
                           bswap_32big(0xab29a401U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x0c3dfd65U), bswap_32big(0x5a7b93a9U), bswap_32big(0xd0b636eeU),
                           bswap_32big(0x7929066bU));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0xeb62928bU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000506U));
            r_rsip_func101(bswap_32big(0x5005a825U), bswap_32big(0x53418374U), bswap_32big(0x48f84105U),
                           bswap_32big(0x04832c46U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x845b545eU));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000507U));
            r_rsip_func101(bswap_32big(0x20012898U), bswap_32big(0xb151238eU), bswap_32big(0x7e48d3eaU),
                           bswap_32big(0xaf2dc1ebU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc7a2d32aU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000503U));
            r_rsip_func101(bswap_32big(0x5c79deddU), bswap_32big(0xca78f212U), bswap_32big(0x9e92ccadU),
                           bswap_32big(0x3ea38f03U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
            r_rsip_func101(bswap_32big(0x43a16455U), bswap_32big(0xcbf922dbU), bswap_32big(0x45808cceU),
                           bswap_32big(0x87df707dU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0xd12fa194U), bswap_32big(0x77e2cf42U), bswap_32big(0x5c7391c7U),
                           bswap_32big(0x0ca05fc9U));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0xc7a2d32aU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000508U));
            r_rsip_func101(bswap_32big(0x7fba1fb3U), bswap_32big(0xd1dfb069U), bswap_32big(0xbc1ac31cU),
                           bswap_32big(0xcd23e3a6U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000509U));
            r_rsip_func101(bswap_32big(0xe1b7270cU), bswap_32big(0x8a9bdc7cU), bswap_32big(0xa5319becU),
                           bswap_32big(0x6cbdae6eU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xaab2837cU), bswap_32big(0xe00ac38fU), bswap_32big(0x52572c8bU),
                           bswap_32big(0x5dc40186U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc007(bswap_32big(0xeb62928bU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000505U));
                r_rsip_func101(bswap_32big(0xf603e76eU),
                               bswap_32big(0xa694756fU),
                               bswap_32big(0xffad618eU),
                               bswap_32big(0x64d364ddU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc7a2d32aU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000506U));
                r_rsip_func101(bswap_32big(0xad0e849cU),
                               bswap_32big(0xc17fe787U),
                               bswap_32big(0x11151356U),
                               bswap_32big(0x22663cedU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000501U));
                r_rsip_func101(bswap_32big(0x879ad12dU),
                               bswap_32big(0x64cbe1f1U),
                               bswap_32big(0xf378534eU),
                               bswap_32big(0xce9edff2U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xeb62928bU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x1f5988c0U),
                               bswap_32big(0x7d65630eU),
                               bswap_32big(0x549b722dU),
                               bswap_32big(0x871f42b5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x845b545eU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000507U));
                r_rsip_func101(bswap_32big(0x6e48bfbdU),
                               bswap_32big(0x6e432a47U),
                               bswap_32big(0xa67b58bdU),
                               bswap_32big(0x747f26f2U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000508U));
                r_rsip_func101(bswap_32big(0xf29f156fU),
                               bswap_32big(0xec0991daU),
                               bswap_32big(0xa7c2d3dbU),
                               bswap_32big(0xde798da0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000502U));
                r_rsip_func101(bswap_32big(0x3a5674c9U),
                               bswap_32big(0xa78eb186U),
                               bswap_32big(0xedb65423U),
                               bswap_32big(0xbb93cf7cU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x845b545eU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xee420458U),
                               bswap_32big(0x8525cf42U),
                               bswap_32big(0x647cb8bfU),
                               bswap_32big(0xebf1aa26U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x984a8575U),
                               bswap_32big(0xd6ac371eU),
                               bswap_32big(0xea28f863U),
                               bswap_32big(0xd24f00e3U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x0808000aU);
                r_rsip_subfunc007(bswap_32big(0xc7a2d32aU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x4e81e6ceU),
                               bswap_32big(0x6d81e79dU),
                               bswap_32big(0xf73cea69U),
                               bswap_32big(0x92ef81f0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xeb62928bU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0x537203dfU),
                               bswap_32big(0x041c7a35U),
                               bswap_32big(0xa93b002bU),
                               bswap_32big(0x7c22e8edU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000503U));
                r_rsip_func101(bswap_32big(0xb6c1fedfU),
                               bswap_32big(0x71610a66U),
                               bswap_32big(0xea6f5fcbU),
                               bswap_32big(0xf2cb7758U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xc7a2d32aU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x9c4d9445U),
                               bswap_32big(0xbca75c88U),
                               bswap_32big(0x0753b01eU),
                               bswap_32big(0x8d6271c9U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x79b473fdU),
                               bswap_32big(0x2ad591a9U),
                               bswap_32big(0xcffad28eU),
                               bswap_32big(0xc94e92e1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x845b545eU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x6cb416b8U),
                               bswap_32big(0x8fdb8f8aU),
                               bswap_32big(0xacc08491U),
                               bswap_32big(0x786e3efdU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000504U));
                r_rsip_func101(bswap_32big(0xc2e1d55fU),
                               bswap_32big(0x6fac9cefU),
                               bswap_32big(0xce58c729U),
                               bswap_32big(0x18c0b731U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x215067deU),
                               bswap_32big(0x690f1173U),
                               bswap_32big(0xf1f3573cU),
                               bswap_32big(0xf7641a69U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x2fecc254U),
                               bswap_32big(0x27893b2cU),
                               bswap_32big(0xdafcf1b3U),
                               bswap_32big(0xce32d603U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x23cdc410U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x0000050eU));
    r_rsip_func101(bswap_32big(0xaacaab08U),
                   bswap_32big(0x3acb085cU),
                   bswap_32big(0x94d70efeU),
                   bswap_32big(0x0d0bfbacU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x33a8d40cU), bswap_32big(0xe851330fU), bswap_32big(0x0dbaa050U),
                       bswap_32big(0x93cb796dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x08080008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x08080008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x9ff0ce72U), bswap_32big(0x400ff93dU), bswap_32big(0x0e94a174U),
                           bswap_32big(0x4163d1d6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x8b01d2a3U), bswap_32big(0x3867f163U), bswap_32big(0xb70f6884U),
                           bswap_32big(0x2bf52871U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x0a9e1b47U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050fU));
    r_rsip_func101(bswap_32big(0xd7e65158U),
                   bswap_32big(0x35f1c052U),
                   bswap_32big(0x8191d730U),
                   bswap_32big(0x3d667f7eU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17e80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x2fefe939U), bswap_32big(0x77d00a52U), bswap_32big(0xfccd31bbU),
                       bswap_32big(0x4fc13a56U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0x385fc089U), bswap_32big(0x0d4e8860U), bswap_32big(0x0b18bca8U),
                           bswap_32big(0x5655cb07U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x5341da48U), bswap_32big(0x6e505d4eU), bswap_32big(0xfa029d2fU),
                           bswap_32big(0xe5cc1f6bU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xd64c9e7cU),
                   bswap_32big(0x4e12a842U),
                   bswap_32big(0x6ce616a5U),
                   bswap_32big(0x3f9027d1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x0909000aU);
        r_rsip_func101(bswap_32big(0x8c50c7a5U), bswap_32big(0x4df4f68dU), bswap_32big(0x85b4ca90U),
                       bswap_32big(0xaf3f687aU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x3c1f93cbU), bswap_32big(0xe23ea1a6U), bswap_32big(0xa5b79a0bU),
                       bswap_32big(0x81baa7c4U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
