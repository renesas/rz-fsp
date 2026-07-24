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

void r_rsip_func056 (void)
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
        r_rsip_func100(bswap_32big(0x26851641U), bswap_32big(0xa2233676U), bswap_32big(0xf6de23b6U),
                       bswap_32big(0x594d5f06U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1818000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1818000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe9ccb2c5U), bswap_32big(0xcb46dbc0U), bswap_32big(0x49ace51aU),
                           bswap_32big(0xac8796a6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xcc60efc0U), bswap_32big(0x87f266f1U), bswap_32big(0x4390b7c3U),
                           bswap_32big(0x2692531fU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19700000U);
    r_rsip_subfunc003(0x00c000d1U);
    r_rsip_subfunc007(bswap_32big(0xd4d8eef8U));
    OFS_ADR = 56;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000561U));
    r_rsip_func101(bswap_32big(0x53a30497U),
                   bswap_32big(0xeeef2afdU),
                   bswap_32big(0x3eb3fda3U),
                   bswap_32big(0xc4f9ac16U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xf4ce7859U));
    OFS_ADR = 112;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
    r_rsip_func101(bswap_32big(0xcc434558U),
                   bswap_32big(0x8431d492U),
                   bswap_32big(0xd219317dU),
                   bswap_32big(0xbdcf03a3U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x15d478ebU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000563U));
    r_rsip_func101(bswap_32big(0xc3e958f7U),
                   bswap_32big(0x58b028b2U),
                   bswap_32big(0xd4a23d39U),
                   bswap_32big(0xfa1ea235U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
    r_rsip_func101(bswap_32big(0x6dfa100bU),
                   bswap_32big(0x55fe572aU),
                   bswap_32big(0xebb4b298U),
                   bswap_32big(0xfa07f7b5U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x1458b7feU));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x00000565U));
    r_rsip_func101(bswap_32big(0xa5d48c1cU),
                   bswap_32big(0xc1b23252U),
                   bswap_32big(0xb37c76ddU),
                   bswap_32big(0x24c91737U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15700000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80b0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x034300c1U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19800000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c000bdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1818000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xa017c71bU), bswap_32big(0x158d72eeU), bswap_32big(0xa41db994U),
                       bswap_32big(0xf1de862cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xbe85b520U), bswap_32big(0xeb428149U), bswap_32big(0x55d08ed6U),
                           bswap_32big(0xd5e3f765U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x15d478ebU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0x73c80a29U), bswap_32big(0xc14bd333U), bswap_32big(0x96d293a7U),
                           bswap_32big(0x76d9f1d3U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd4d8eef8U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x7a4a38d1U), bswap_32big(0x73ab68f2U), bswap_32big(0x3cc3e0a3U),
                           bswap_32big(0x19882420U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000561U));
            r_rsip_func101(bswap_32big(0xbc5ed15eU), bswap_32big(0x126d7ceeU), bswap_32big(0x630f60b0U),
                           bswap_32big(0x772c28d7U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0x15d478ebU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000566U));
            r_rsip_func101(bswap_32big(0xbd510c30U), bswap_32big(0x9f605a3bU), bswap_32big(0xf62047b5U),
                           bswap_32big(0x2e5a1117U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd4d8eef8U));
            OFS_ADR = 56;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000567U));
            r_rsip_func101(bswap_32big(0x031be5a4U), bswap_32big(0xdab07b85U), bswap_32big(0x0fa29a5dU),
                           bswap_32big(0x53f6d286U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf4ce7859U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000563U));
            r_rsip_func101(bswap_32big(0x87741670U), bswap_32big(0xb5e9aba3U), bswap_32big(0xd0df66a4U),
                           bswap_32big(0xf26e99bbU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000564U));
            r_rsip_func101(bswap_32big(0x2adc66daU), bswap_32big(0xd518e556U), bswap_32big(0x344254cdU),
                           bswap_32big(0xfeba46f2U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc009(bswap_32big(0x00000562U));
            r_rsip_func101(bswap_32big(0x05cc0160U), bswap_32big(0xbef99457U), bswap_32big(0x9b6753c6U),
                           bswap_32big(0x114d39b2U));
            r_rsip_func057();
            r_rsip_subfunc007(bswap_32big(0xf4ce7859U));
            OFS_ADR = 112;
            r_rsip_subfunc008(0x13580000U, 0x00000034U, bswap_32big(0x00000568U));
            r_rsip_func101(bswap_32big(0x16ac0950U), bswap_32big(0xaab7081cU), bswap_32big(0x1c92fe20U),
                           bswap_32big(0xd9a6ceeaU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
            OFS_ADR = 168;
            r_rsip_subfunc008(0x19700000U, 0x00000034U, bswap_32big(0x00000569U));
            r_rsip_func101(bswap_32big(0xb2bcb40bU), bswap_32big(0xac43ca74U), bswap_32big(0x12932fb0U),
                           bswap_32big(0xb9cd51beU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f180000U);
            r_rsip_subfunc003(0x00c000c1U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x18180009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x18180009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x18180009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1818000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x64746215U), bswap_32big(0x125b31d1U), bswap_32big(0xb796bc0eU),
                           bswap_32big(0xd48dbaaaU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x18180009U);
                r_rsip_subfunc007(bswap_32big(0x15d478ebU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000565U));
                r_rsip_func101(bswap_32big(0x39e13597U),
                               bswap_32big(0x7647b123U),
                               bswap_32big(0x139bda81U),
                               bswap_32big(0xe2654898U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf4ce7859U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000566U));
                r_rsip_func101(bswap_32big(0x7c73f2b1U),
                               bswap_32big(0x196ca282U),
                               bswap_32big(0x15baead6U),
                               bswap_32big(0x6a6edd2fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000561U));
                r_rsip_func101(bswap_32big(0xc154e059U),
                               bswap_32big(0x8eff09cbU),
                               bswap_32big(0x1c04a725U),
                               bswap_32big(0xc2bc7a6eU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0x15d478ebU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xf1adf561U),
                               bswap_32big(0xa31e5348U),
                               bswap_32big(0xf88150d0U),
                               bswap_32big(0x4a222227U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd4d8eef8U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x00000567U));
                r_rsip_func101(bswap_32big(0xb260980dU),
                               bswap_32big(0xf6da0df7U),
                               bswap_32big(0x38d22938U),
                               bswap_32big(0x94a552d6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x00000568U));
                r_rsip_func101(bswap_32big(0xffe704d5U),
                               bswap_32big(0xd841929aU),
                               bswap_32big(0x32d9c2d2U),
                               bswap_32big(0x424f9f9eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000562U));
                r_rsip_func101(bswap_32big(0xc276ad65U),
                               bswap_32big(0xd09f19c0U),
                               bswap_32big(0xcb1288deU),
                               bswap_32big(0xc528d778U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xd4d8eef8U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0xb644812eU),
                               bswap_32big(0x5faddb08U),
                               bswap_32big(0x2a914ee4U),
                               bswap_32big(0x9f01082cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xbe264726U),
                               bswap_32big(0x8ff9cc52U),
                               bswap_32big(0x526e1dceU),
                               bswap_32big(0x1eec8dafU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1818000aU);
                r_rsip_subfunc007(bswap_32big(0xf4ce7859U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056aU));
                r_rsip_func101(bswap_32big(0xd0f9dddaU),
                               bswap_32big(0x0f4b6ca8U),
                               bswap_32big(0xaab5a785U),
                               bswap_32big(0xb08221b5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x15d478ebU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056bU));
                r_rsip_func101(bswap_32big(0x99fd262bU),
                               bswap_32big(0x4ff8deffU),
                               bswap_32big(0x7f697d7bU),
                               bswap_32big(0x96145302U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000563U));
                r_rsip_func101(bswap_32big(0x065c37d7U),
                               bswap_32big(0x79d37cb5U),
                               bswap_32big(0xed13f324U),
                               bswap_32big(0x13172705U));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xf4ce7859U));
                OFS_ADR = 112;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x4250c0d0U),
                               bswap_32big(0x90563107U),
                               bswap_32big(0x7c1fb52dU),
                               bswap_32big(0xd23a5801U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056cU));
                r_rsip_func101(bswap_32big(0x4c82225aU),
                               bswap_32big(0x0c31fdbaU),
                               bswap_32big(0xc9150c1bU),
                               bswap_32big(0xad6212acU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd4d8eef8U));
                OFS_ADR = 56;
                r_rsip_subfunc008(0x1f080000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0xbe7c3836U),
                               bswap_32big(0x1a95ebe2U),
                               bswap_32big(0x19a82798U),
                               bswap_32big(0xb36e1cfdU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000564U));
                r_rsip_func101(bswap_32big(0xc87502d2U),
                               bswap_32big(0x2826f84dU),
                               bswap_32big(0x6ba0cbd5U),
                               bswap_32big(0x156d95aaU));
                r_rsip_func307();
                r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
                OFS_ADR = 168;
                r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056dU));
                r_rsip_func101(bswap_32big(0xfd19fbf5U),
                               bswap_32big(0x373f54a2U),
                               bswap_32big(0xeb686173U),
                               bswap_32big(0x554ee500U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xe2cff02eU),
                               bswap_32big(0xc7971013U),
                               bswap_32big(0xb1b5eecdU),
                               bswap_32big(0x7f563943U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x1458b7feU));
    OFS_ADR = 224;
    r_rsip_subfunc008(0x11600000U, 0x00000030U, bswap_32big(0x0000056eU));
    r_rsip_func101(bswap_32big(0x0b1cb321U),
                   bswap_32big(0x559becf0U),
                   bswap_32big(0xdf223e42U),
                   bswap_32big(0x469aff48U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19800000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c000bdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xa9eb0874U), bswap_32big(0x5be97413U), bswap_32big(0x7c7ade66U),
                       bswap_32big(0xd9ab39b7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x18180008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x18180008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xb8f52263U), bswap_32big(0x771bb7f3U), bswap_32big(0x2dc4ef3cU),
                           bswap_32big(0xc166fc71U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc649118dU), bswap_32big(0xaa440e93U), bswap_32big(0x83bf429eU),
                           bswap_32big(0x022f09a4U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xc10cbd6eU));
    OFS_ADR = 168;
    r_rsip_subfunc008(0x17680000U, 0x00000034U, bswap_32big(0x0000056fU));
    r_rsip_func101(bswap_32big(0x263cc166U),
                   bswap_32big(0x02c181e1U),
                   bswap_32big(0xd16b28f0U),
                   bswap_32big(0x2bfe4f29U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17680000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x1919000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x02351fd7U), bswap_32big(0x2652f2efU), bswap_32big(0x5242aad9U),
                       bswap_32big(0xeef7f8d9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1919000aU);
            r_rsip_func101(bswap_32big(0x727d6097U), bswap_32big(0x28881269U), bswap_32big(0x95ea0349U),
                           bswap_32big(0xb0ea5221U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x0ee1e67aU), bswap_32big(0xa9f99b8bU), bswap_32big(0xcd47fd50U),
                           bswap_32big(0x0b3883c1U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x0dac7415U),
                   bswap_32big(0x8b3f7b30U),
                   bswap_32big(0x94a046e1U),
                   bswap_32big(0xd7ee8626U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1919000aU);
        r_rsip_func101(bswap_32big(0x8ce38b70U), bswap_32big(0xbf941e0aU), bswap_32big(0x5a9b57c9U),
                       bswap_32big(0x893de192U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x23d3a1d6U), bswap_32big(0x2568a113U), bswap_32big(0xdd12ba6aU),
                       bswap_32big(0x40351f9fU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
