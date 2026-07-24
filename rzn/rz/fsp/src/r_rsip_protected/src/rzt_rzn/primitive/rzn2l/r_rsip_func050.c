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
        r_rsip_func100(bswap_32big(0x59a999e1U), bswap_32big(0x08e151e2U), bswap_32big(0x6f9eede0U),
                       bswap_32big(0xf84056c0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x0808000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd49c642cU), bswap_32big(0x475f5ad2U), bswap_32big(0x8f806dd8U),
                           bswap_32big(0x2d1812bcU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xbba6d795U), bswap_32big(0x7b98bd9fU), bswap_32big(0xeafc740fU),
                           bswap_32big(0x9d0197abU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19f00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0xd5144e9fU));
    OFS_ADR = 24;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000501U));
    r_rsip_func101(bswap_32big(0x14815367U),
                   bswap_32big(0xf9ec9656U),
                   bswap_32big(0xf319c440U),
                   bswap_32big(0x0fcc9cdfU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x5f9e39c3U));
    OFS_ADR = 48;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
    r_rsip_func101(bswap_32big(0x15d0be3eU),
                   bswap_32big(0x731be1f0U),
                   bswap_32big(0x5ec1ebfcU),
                   bswap_32big(0x2eb2c83cU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xce891104U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000503U));
    r_rsip_func101(bswap_32big(0xa4f95516U),
                   bswap_32big(0xac5265deU),
                   bswap_32big(0xd0e560adU),
                   bswap_32big(0x022c8fcaU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
    r_rsip_func101(bswap_32big(0xb1823b87U),
                   bswap_32big(0x130e5060U),
                   bswap_32big(0x3d66b56bU),
                   bswap_32big(0x058cdc8cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xeb60936eU));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x00000505U));
    r_rsip_func101(bswap_32big(0x51292428U),
                   bswap_32big(0x92f4a41cU),
                   bswap_32big(0x1ba3a914U),
                   bswap_32big(0x8681414fU));
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
        r_rsip_func100(bswap_32big(0x151c7aaeU), bswap_32big(0x9afd4340U), bswap_32big(0x38d2e830U),
                       bswap_32big(0xe34e5ec2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x18d85d3dU), bswap_32big(0x2772e2a4U), bswap_32big(0xb2abce97U),
                           bswap_32big(0xdcb44cd1U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xce891104U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x77dfe427U), bswap_32big(0x43a9b433U), bswap_32big(0xffbb1ab4U),
                           bswap_32big(0xb2914a19U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd5144e9fU));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x47803a2eU), bswap_32big(0x6cfc40d2U), bswap_32big(0xcddff3dbU),
                           bswap_32big(0xf7ad8604U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x2a33835cU), bswap_32big(0x98422dabU), bswap_32big(0x94a19ab3U),
                           bswap_32big(0x1c03ce36U));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0xce891104U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000506U));
            r_rsip_func101(bswap_32big(0x65629722U), bswap_32big(0x53818c53U), bswap_32big(0x0f93f1c5U),
                           bswap_32big(0x7f41a13cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd5144e9fU));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000507U));
            r_rsip_func101(bswap_32big(0x671c9e92U), bswap_32big(0x6f37cc52U), bswap_32big(0x317dac71U),
                           bswap_32big(0x6233636aU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5f9e39c3U));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000503U));
            r_rsip_func101(bswap_32big(0x2011dbdfU), bswap_32big(0x614f996aU), bswap_32big(0x98b56f60U),
                           bswap_32big(0xb4187b72U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
            r_rsip_func101(bswap_32big(0x9b84c002U), bswap_32big(0x46dd0a99U), bswap_32big(0x01b80c3bU),
                           bswap_32big(0xe9ecf711U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x60c15d91U), bswap_32big(0x5b8752ebU), bswap_32big(0x9fdbdb34U),
                           bswap_32big(0x5e26fb31U));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x5f9e39c3U));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000508U));
            r_rsip_func101(bswap_32big(0xf46035c5U), bswap_32big(0x0db7c09aU), bswap_32big(0xfec47ae8U),
                           bswap_32big(0xa6cd73e0U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000509U));
            r_rsip_func101(bswap_32big(0x043f6372U), bswap_32big(0xaec7564cU), bswap_32big(0x4ad22b47U),
                           bswap_32big(0xcf823043U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x5db2c5a1U), bswap_32big(0x99725829U), bswap_32big(0xc213381bU),
                           bswap_32big(0x43735847U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc007(bswap_32big(0xce891104U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000505U));
                r_rsip_func101(bswap_32big(0xe26ec84bU),
                               bswap_32big(0x8673f32fU),
                               bswap_32big(0x8468d048U),
                               bswap_32big(0x9aeb53b6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5f9e39c3U));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000506U));
                r_rsip_func101(bswap_32big(0x931144a0U),
                               bswap_32big(0x998bf705U),
                               bswap_32big(0x52058cfeU),
                               bswap_32big(0x0440a9c9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000501U));
                r_rsip_func101(bswap_32big(0x43632dd3U),
                               bswap_32big(0x85b99df8U),
                               bswap_32big(0x3ca3eee6U),
                               bswap_32big(0x500daaa4U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xce891104U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0xee078e7dU),
                               bswap_32big(0xe5443ceeU),
                               bswap_32big(0xcafb7816U),
                               bswap_32big(0x8cfb6953U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd5144e9fU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000507U));
                r_rsip_func101(bswap_32big(0xc8b4c6eeU),
                               bswap_32big(0x9b0cb984U),
                               bswap_32big(0x49b51d98U),
                               bswap_32big(0xac539f56U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000508U));
                r_rsip_func101(bswap_32big(0x3b9bd85fU),
                               bswap_32big(0x3744f7f8U),
                               bswap_32big(0xd89090beU),
                               bswap_32big(0x6fb0de6dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000502U));
                r_rsip_func101(bswap_32big(0x70ac5e53U),
                               bswap_32big(0xde11adebU),
                               bswap_32big(0xe2935670U),
                               bswap_32big(0xb396fa00U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xd5144e9fU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0x5fba8f1eU),
                               bswap_32big(0xab118e99U),
                               bswap_32big(0x3d725d77U),
                               bswap_32big(0x2e104468U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x9b715dafU),
                               bswap_32big(0xab142af7U),
                               bswap_32big(0xd4a8d7b5U),
                               bswap_32big(0xfcbdd52eU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x0808000aU);
                r_rsip_subfunc007(bswap_32big(0x5f9e39c3U));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x5339e771U),
                               bswap_32big(0x0b46f89eU),
                               bswap_32big(0x43662d80U),
                               bswap_32big(0x48307095U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xce891104U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xd1d06ce9U),
                               bswap_32big(0x3e6908e5U),
                               bswap_32big(0xbdbb6482U),
                               bswap_32big(0x27b99320U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000503U));
                r_rsip_func101(bswap_32big(0x8901611eU),
                               bswap_32big(0x284d4758U),
                               bswap_32big(0xd353c4d1U),
                               bswap_32big(0x872359dbU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x5f9e39c3U));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x33ea39f3U),
                               bswap_32big(0x97cac815U),
                               bswap_32big(0x4fb71297U),
                               bswap_32big(0x01d6e61cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0xca83eb77U),
                               bswap_32big(0x47d2ad76U),
                               bswap_32big(0x421ad922U),
                               bswap_32big(0xed8c4b96U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd5144e9fU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x8fd8b889U),
                               bswap_32big(0xe7068650U),
                               bswap_32big(0xdd6dfa87U),
                               bswap_32big(0xe1eed6a4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000504U));
                r_rsip_func101(bswap_32big(0xcef58ea9U),
                               bswap_32big(0xd78cd217U),
                               bswap_32big(0x5c5d812fU),
                               bswap_32big(0x7835a3cbU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x056d73d5U),
                               bswap_32big(0x8fd41eb3U),
                               bswap_32big(0x2155c390U),
                               bswap_32big(0x7dd7f768U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x7aef07aaU),
                               bswap_32big(0x50d37aebU),
                               bswap_32big(0xfd32731fU),
                               bswap_32big(0xead54139U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xeb60936eU));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x0000050eU));
    r_rsip_func101(bswap_32big(0x0ff36896U),
                   bswap_32big(0x4e0b0f6bU),
                   bswap_32big(0xf38f523cU),
                   bswap_32big(0x3bbf134eU));
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
        r_rsip_func100(bswap_32big(0xf3827bdfU), bswap_32big(0xcab6d5d4U), bswap_32big(0xc9c845e1U),
                       bswap_32big(0x89425a86U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x08080008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x08080008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x749b41c6U), bswap_32big(0xd9da260cU), bswap_32big(0xd7746441U),
                           bswap_32big(0x167cbf05U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x50dbd99bU), bswap_32big(0xd14b3cb6U), bswap_32big(0x0f30e71fU),
                           bswap_32big(0x964ed5a2U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x3b3f8130U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050fU));
    r_rsip_func101(bswap_32big(0xee4352abU),
                   bswap_32big(0xa4fd5848U),
                   bswap_32big(0xf6800182U),
                   bswap_32big(0x304185c1U));
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
        r_rsip_func100(bswap_32big(0xde506cc0U), bswap_32big(0xbf863584U), bswap_32big(0xc3eb1029U),
                       bswap_32big(0x0d22e991U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0xf9134751U), bswap_32big(0xb38d43b7U), bswap_32big(0x398d15f5U),
                           bswap_32big(0xb81311bfU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x71ecc3a1U), bswap_32big(0xe42a08adU), bswap_32big(0xf69254b7U),
                           bswap_32big(0x7ef6d0aaU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xe9d6c2fbU),
                   bswap_32big(0x9616eb2eU),
                   bswap_32big(0x91d8d002U),
                   bswap_32big(0x69a9d320U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x0909000aU);
        r_rsip_func101(bswap_32big(0xd0cc4bc0U), bswap_32big(0xb6db8827U), bswap_32big(0x49e552acU),
                       bswap_32big(0xd51871c4U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xaebe62ccU), bswap_32big(0x7aed266cU), bswap_32big(0x0eadf128U),
                       bswap_32big(0x70b4ded0U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
