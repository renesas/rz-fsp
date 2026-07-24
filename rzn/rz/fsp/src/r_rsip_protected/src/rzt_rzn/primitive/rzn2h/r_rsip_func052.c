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
        r_rsip_func100(bswap_32big(0xd9620259U), bswap_32big(0xa5baad34U), bswap_32big(0x1686746fU),
                       bswap_32big(0xa83a030cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1010000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x89d59a9fU), bswap_32big(0xb33a738aU), bswap_32big(0xf8664f25U),
                           bswap_32big(0x3152c5fbU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc24de29dU), bswap_32big(0x94c6b570U), bswap_32big(0xd1ca0c5cU),
                           bswap_32big(0xfe86f668U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0xac547b0fU));
    OFS_ADR = 40;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000521U));
    r_rsip_func101(bswap_32big(0xf75e66f2U),
                   bswap_32big(0x918ff10cU),
                   bswap_32big(0x504e2673U),
                   bswap_32big(0x936b9fe9U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc73e07b9U));
    OFS_ADR = 80;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
    r_rsip_func101(bswap_32big(0xa8a9ccfaU),
                   bswap_32big(0x220bb82dU),
                   bswap_32big(0x3f5b28aaU),
                   bswap_32big(0x25d26c27U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x490830c1U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000523U));
    r_rsip_func101(bswap_32big(0x33619768U),
                   bswap_32big(0xe824e390U),
                   bswap_32big(0x9a2e4daeU),
                   bswap_32big(0x2b16c9b7U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
    r_rsip_func101(bswap_32big(0xb35009e2U),
                   bswap_32big(0x0466345fU),
                   bswap_32big(0xfcc42986U),
                   bswap_32big(0x6c26396cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xff0278eaU));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x00000525U));
    r_rsip_func101(bswap_32big(0x2849f342U),
                   bswap_32big(0x078c0b2cU),
                   bswap_32big(0x6e31bb16U),
                   bswap_32big(0xb04369acU));
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
        r_rsip_func100(bswap_32big(0x3fe6c9e6U), bswap_32big(0xdd3900a0U), bswap_32big(0x479c5352U),
                       bswap_32big(0x9f3d1244U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x9114dfeeU), bswap_32big(0xea3ad21cU), bswap_32big(0x734ace2bU),
                           bswap_32big(0x77a7443aU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x490830c1U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0xa724ceb4U), bswap_32big(0xc8d83ef3U), bswap_32big(0xb85481a9U),
                           bswap_32big(0x8bc1a81dU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xac547b0fU));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0x17ed2957U), bswap_32big(0x3f438260U), bswap_32big(0x7f71d929U),
                           bswap_32big(0xc456e4f5U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x4b0315abU), bswap_32big(0xdd671d81U), bswap_32big(0xa051e5e7U),
                           bswap_32big(0x571584d1U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0x490830c1U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000526U));
            r_rsip_func101(bswap_32big(0xe5d54c85U), bswap_32big(0x6c844817U), bswap_32big(0x5610da59U),
                           bswap_32big(0x746b993aU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xac547b0fU));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000527U));
            r_rsip_func101(bswap_32big(0xf7f660b4U), bswap_32big(0x97008a36U), bswap_32big(0x6e359d5cU),
                           bswap_32big(0xc4f80694U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc73e07b9U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000523U));
            r_rsip_func101(bswap_32big(0xa6c2fddbU), bswap_32big(0x09bcad7aU), bswap_32big(0x7e58585dU),
                           bswap_32big(0xfabff24eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
            r_rsip_func101(bswap_32big(0x151bc941U), bswap_32big(0x43aae52fU), bswap_32big(0xc818a320U),
                           bswap_32big(0x7f8424e6U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc009(bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0x184d6cbeU), bswap_32big(0x040de873U), bswap_32big(0xedd466c0U),
                           bswap_32big(0x6f1b3f12U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xc73e07b9U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000528U));
            r_rsip_func101(bswap_32big(0xca92c7b7U), bswap_32big(0xf70f9465U), bswap_32big(0x9bd9e7a9U),
                           bswap_32big(0x25dbc61dU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000529U));
            r_rsip_func101(bswap_32big(0xbc605a7bU), bswap_32big(0x61cde0f0U), bswap_32big(0xde43bc6bU),
                           bswap_32big(0xb862f994U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x99def6fcU), bswap_32big(0x08e32a5bU), bswap_32big(0xd7b6e4edU),
                           bswap_32big(0x74be4e93U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc007(bswap_32big(0x490830c1U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000525U));
                r_rsip_func101(bswap_32big(0xfd4cb414U),
                               bswap_32big(0x3f3e6a87U),
                               bswap_32big(0x6a919e42U),
                               bswap_32big(0xd65a2ab9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc73e07b9U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000526U));
                r_rsip_func101(bswap_32big(0x708f79e4U),
                               bswap_32big(0x3c0614a2U),
                               bswap_32big(0x787c850bU),
                               bswap_32big(0x2141ad54U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000521U));
                r_rsip_func101(bswap_32big(0x162b93a6U),
                               bswap_32big(0x5ee9b26dU),
                               bswap_32big(0xd08ea87dU),
                               bswap_32big(0x54b2bc0fU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x490830c1U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x8b57fdd0U),
                               bswap_32big(0xdaea5610U),
                               bswap_32big(0x662d30ddU),
                               bswap_32big(0x74af6adaU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xac547b0fU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000527U));
                r_rsip_func101(bswap_32big(0xfe9b24c9U),
                               bswap_32big(0x0cf18089U),
                               bswap_32big(0x025facddU),
                               bswap_32big(0x448ae789U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000528U));
                r_rsip_func101(bswap_32big(0x582c4fabU),
                               bswap_32big(0x10915f92U),
                               bswap_32big(0x095d654bU),
                               bswap_32big(0x8791bb91U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000522U));
                r_rsip_func101(bswap_32big(0x238d3ed7U),
                               bswap_32big(0x7384d898U),
                               bswap_32big(0x5a987066U),
                               bswap_32big(0xb8b54badU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xac547b0fU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x1db5ca18U),
                               bswap_32big(0x4e09ee93U),
                               bswap_32big(0x0abc4846U),
                               bswap_32big(0xd3981762U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x81390396U),
                               bswap_32big(0x9b5f8d21U),
                               bswap_32big(0x8b0e0946U),
                               bswap_32big(0xb8d4ea72U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);
                r_rsip_subfunc007(bswap_32big(0xc73e07b9U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0xcadb0c08U),
                               bswap_32big(0xdebf0614U),
                               bswap_32big(0x730978adU),
                               bswap_32big(0xde7905bdU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x490830c1U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0xdf415fc0U),
                               bswap_32big(0xfdcd4e74U),
                               bswap_32big(0x19c7adafU),
                               bswap_32big(0x4864d217U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000523U));
                r_rsip_func101(bswap_32big(0x2f6cf6d8U),
                               bswap_32big(0x4e6ee968U),
                               bswap_32big(0x0cbfbb06U),
                               bswap_32big(0x9325cec5U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xc73e07b9U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x48e9a258U),
                               bswap_32big(0x2e727055U),
                               bswap_32big(0x95d05819U),
                               bswap_32big(0x97cde78dU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0xca68f946U),
                               bswap_32big(0xa261b96dU),
                               bswap_32big(0xa8910a9aU),
                               bswap_32big(0xe33e9153U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xac547b0fU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x3817da3aU),
                               bswap_32big(0xe5b7ab9fU),
                               bswap_32big(0x7760d3f5U),
                               bswap_32big(0x070648e0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000524U));
                r_rsip_func101(bswap_32big(0x40154e7bU),
                               bswap_32big(0xe18b31f5U),
                               bswap_32big(0x3f9590c2U),
                               bswap_32big(0x097d0290U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x14f9508bU),
                               bswap_32big(0x8902d1ceU),
                               bswap_32big(0xf8c7b1e1U),
                               bswap_32big(0xa69e989cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x5309e2c8U),
                               bswap_32big(0x19f726cbU),
                               bswap_32big(0xf32538cdU),
                               bswap_32big(0x1f0db110U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xff0278eaU));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x0000052eU));
    r_rsip_func101(bswap_32big(0x2bec5aa2U),
                   bswap_32big(0x8bc70af0U),
                   bswap_32big(0x62c63283U),
                   bswap_32big(0x2def1144U));
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
        r_rsip_func100(bswap_32big(0x201c8dc8U), bswap_32big(0x55ddf266U), bswap_32big(0xe8f9628fU),
                       bswap_32big(0x7a21e0d8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd5d269cbU), bswap_32big(0xc54f20d4U), bswap_32big(0x5d0af898U),
                           bswap_32big(0x2eca4953U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x65f56285U), bswap_32big(0x15e25c7bU), bswap_32big(0xa6a0e23bU),
                           bswap_32big(0x15bd6725U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x0fcb46ccU));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052fU));
    r_rsip_func101(bswap_32big(0x81de3be3U),
                   bswap_32big(0xb6f5b728U),
                   bswap_32big(0x3b4b0fb8U),
                   bswap_32big(0xd8afa591U));
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
        r_rsip_func100(bswap_32big(0x22fec37cU), bswap_32big(0x597633fcU), bswap_32big(0x3702d0a4U),
                       bswap_32big(0xeab32e7fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0x54c7754bU), bswap_32big(0xe0225a32U), bswap_32big(0xd71e7ad4U),
                           bswap_32big(0xc3700593U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x472ecaf8U), bswap_32big(0xb6a57919U), bswap_32big(0x5847d55bU),
                           bswap_32big(0xb2164c98U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xa6d83ba0U),
                   bswap_32big(0xd8ea6311U),
                   bswap_32big(0x3959fa5eU),
                   bswap_32big(0xddefb098U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);
        r_rsip_func101(bswap_32big(0x4ce2db8fU), bswap_32big(0x5ad8d863U), bswap_32big(0xbe111323U),
                       bswap_32big(0x8c3508e9U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x4ea02a4cU), bswap_32big(0xbb13f458U), bswap_32big(0x1bbc69faU),
                       bswap_32big(0x0fdd3696U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
