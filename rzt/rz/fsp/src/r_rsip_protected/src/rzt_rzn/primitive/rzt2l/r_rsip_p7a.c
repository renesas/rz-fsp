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

rsip_ret_t r_rsip_p7a (uint32_t const InData_KeyIndex[], uint32_t const InData_Text[], uint32_t OutData_Text[])
{
    RSIP_PRV_PRIMITIVE_ENTRY;
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x007a0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000fe8U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007aU));
    r_rsip_func101(bswap_32big(0xd22e9309U),
                   bswap_32big(0xde3c9069U),
                   bswap_32big(0x1ff411d4U),
                   bswap_32big(0xdfe9c67cU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01dd5025U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000007aU));
    r_rsip_func101(bswap_32big(0x3df049e3U),
                   bswap_32big(0xc83cd0d0U),
                   bswap_32big(0xdf8a7bd2U),
                   bswap_32big(0x907ec449U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x0000bfc2U);
    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xf7009d07U);
    WR1_PROG(REG_1404H, 0x14b00000U);
    for (iLoop = 0; iLoop < 96; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1A2CH, 0x40001700U);
    WR1_PROG(REG_1A24H, 0xf7008d07U);
    WR1_PROG(REG_1404H, 0x12a80000U);
    for (iLoop = 96; iLoop < 192; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x07008d05U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[196]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[197]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[198]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[199]);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    r_rsip_subfunc003(0x00820011U);
    r_rsip_func100(bswap_32big(0x311d7b2bU),
                   bswap_32big(0xf060d36eU),
                   bswap_32big(0xf7f17ec8U),
                   bswap_32big(0xe5be0c0cU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x85c7b0b7U), bswap_32big(0x7a45f6d3U), bswap_32big(0xe5278427U),
                       bswap_32big(0x994b3fe1U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        WR1_PROG(REG_1444H, 0x00005fd0U);
        for (iLoop = 0; iLoop < 384; iLoop = iLoop + 4)
        {
            WR1_ADDR((&(REG_00A0H))[iLoop / 4], &InData_Text[(iLoop / 4) + 0]);
        }

        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x800103e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x3800dbe0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0017dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000838U, 0x3030000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
        r_rsip_subfunc003(0x00c0017dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x3030000aU);
        r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000a40U, 0x3030000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xb12dcab8U), bswap_32big(0x60384783U), bswap_32big(0x22333315U),
                       bswap_32big(0xaf5e7827U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xed4d9895U), bswap_32big(0x4619d2e8U), bswap_32big(0x2c6187ffU),
                           bswap_32big(0xcf3929ebU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_subfunc009(bswap_32big(0x0000007aU));
            r_rsip_func101(bswap_32big(0xb9db8feeU), bswap_32big(0xbfaa95c7U), bswap_32big(0xa9f73ffbU),
                           bswap_32big(0x19bffc9bU));
            r_rsip_func030();
            WR1_PROG(REG_1404H, 0x1ae00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c00005U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00109U);
            r_rsip_subfunc009(bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0xe1c7101eU), bswap_32big(0xd17363b3U), bswap_32big(0xa2909454U),
                           bswap_32big(0xe6405f00U));
            r_rsip_func031();
            r_rsip_func100(bswap_32big(0x561f69abU), bswap_32big(0x7ab5c75eU), bswap_32big(0x5098856bU),
                           bswap_32big(0x689631c7U));
            r_rsip_func103();
            r_rsip_func100(bswap_32big(0x47f148b8U), bswap_32big(0x134a55a6U), bswap_32big(0x9bc7d5b4U),
                           bswap_32big(0x08610504U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c2000c4U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WAIT_STS(REG_1A28H, 6U, 0U);
            WR1_PROG(REG_143CH, 0x00000900U);
            r_rsip_subfunc007(bswap_32big(0x9d5fee47U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0xf9fb9b23U), bswap_32big(0xabea5542U), bswap_32big(0x3a18dce4U),
                           bswap_32big(0xda119ca0U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000008U));
            r_rsip_subfunc003(0x00c00005U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000948U, 0x00000838U, 0x00000838U, 0x30300008U);
            WR1_PROG(REG_1404H, 0x18400000U);
            r_rsip_subfunc003(0x00c00109U);
            r_rsip_subfunc001(0x00000738U, 0x00000948U, 0x00000b68U, 0x11110009U);
            r_rsip_subfunc001(0x00000838U, 0x00000948U, 0x00000948U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x9bfc0de5U), bswap_32big(0x05e4f9ceU), bswap_32big(0xef85a6fcU),
                           bswap_32big(0x378f261fU));
            r_rsip_func031();
            r_rsip_subfunc007(bswap_32big(0x8e434303U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x42e3314dU), bswap_32big(0xad832ffaU), bswap_32big(0xc4264dc1U),
                           bswap_32big(0x98b3c537U));
            r_rsip_func016(OFS_ADR);
            for (iLoop = 0; iLoop < 10; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x18c00000U);
                r_rsip_subfunc003(0x00c00181U);
                r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc009(bswap_32big(0x00007a01U));
                r_rsip_func101(bswap_32big(0x089aa13fU),
                               bswap_32big(0xb84191d2U),
                               bswap_32big(0xd15a9d01U),
                               bswap_32big(0x2f8706e6U));
                r_rsip_func033();
                r_rsip_func101(bswap_32big(0x2c2f95b3U),
                               bswap_32big(0x3d98d510U),
                               bswap_32big(0xeee15e1dU),
                               bswap_32big(0xbb1d0730U));
            }

            r_rsip_subfunc007(bswap_32big(0x8e434303U));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a01U));
            r_rsip_func101(bswap_32big(0x021faa48U), bswap_32big(0xc5687be0U), bswap_32big(0x293a3b69U),
                           bswap_32big(0xa82c55aeU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0x8442313bU), bswap_32big(0x069be616U), bswap_32big(0x7b24160dU),
                           bswap_32big(0x1a06e4e2U));
            r_rsip_func033();
            r_rsip_subfunc007(bswap_32big(0x4fd7645bU));
            OFS_ADR = 100;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a03U));
            r_rsip_func101(bswap_32big(0xc61978e0U), bswap_32big(0x74fe4fe0U), bswap_32big(0x5ae19cb6U),
                           bswap_32big(0x210e9c0dU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9d5fee47U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x16b80000U, 0x00000060U, bswap_32big(0x00007a02U));
            r_rsip_func101(bswap_32big(0xba6f297dU), bswap_32big(0x6143b309U), bswap_32big(0xbede6167U),
                           bswap_32big(0x15e17117U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1600H, 0x0000094aU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b560U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b5a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 96; iLoop++)
            {
                WR1_PROG(REG_1404H, 0x12a80000U);
                WR1_PROG(REG_1608H, 0x800103e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03430005U);
                r_rsip_subfunc003(0x00030005U);
                WR1_PROG(REG_1600H, 0x0000098cU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 32; jLoop++)
                {
                    WR1_PROG(REG_1404H, 0x18c00000U);
                    r_rsip_subfunc003(0x00c00181U);
                    r_rsip_subfunc001(0x00000838U, 0x00000a40U, 0x00000220U, 0x30300009U);
                    r_rsip_subfunc009(bswap_32big(0x00007a03U));
                    r_rsip_func101(bswap_32big(0xd154b8e2U),
                                   bswap_32big(0x8150ad98U),
                                   bswap_32big(0x44e62e3bU),
                                   bswap_32big(0xbdd11167U));
                    r_rsip_func033();
                    WR1_PROG(REG_1600H, 0x3800dbffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00A60000U);
                    r_rsip_func100(bswap_32big(0x58c121bfU),
                                   bswap_32big(0x3add82aaU),
                                   bswap_32big(0x7b787793U),
                                   bswap_32big(0xe910249dU));
                    WR1_PROG(REG_143CH, 0x00400000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    if (CHCK_STS(REG_143CH, 22U, 1U))
                    {
                        r_rsip_subfunc007(bswap_32big(0x4fd7645bU));
                        OFS_ADR = 100;
                        r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00007a03U));
                        r_rsip_func101(bswap_32big(0x9585c32eU),
                                       bswap_32big(0xe0f6f1c6U),
                                       bswap_32big(0xc619985bU),
                                       bswap_32big(0x9794afa5U));
                        r_rsip_func017(OFS_ADR);
                        r_rsip_subfunc009(bswap_32big(0x00007a04U));
                        r_rsip_func101(bswap_32big(0x33da7a2eU),
                                       bswap_32big(0x7f276f8bU),
                                       bswap_32big(0x26bb0395U),
                                       bswap_32big(0xdf52fe0bU));
                        r_rsip_func033();
                        r_rsip_func101(bswap_32big(0x48a2ef7dU),
                                       bswap_32big(0xf515dea8U),
                                       bswap_32big(0x5a8cd8c6U),
                                       bswap_32big(0x542248e5U));
                    }
                    else
                    {
                        r_rsip_func101(bswap_32big(0x7886c261U),
                                       bswap_32big(0x4fe74969U),
                                       bswap_32big(0x1d517438U),
                                       bswap_32big(0xcb592b8eU));
                    }

                    WR1_PROG(REG_1600H, 0x00016fffU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002d80U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x8b26d4b4U),
                                   bswap_32big(0x6d1b4540U),
                                   bswap_32big(0x736d7961U),
                                   bswap_32big(0xa5edc964U));
                }

                WR1_PROG(REG_1600H, 0x3800098dU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x1a380000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x00c00005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000a40U, 0x00000428U, 0x00000428U, 0x30300008U);
                WR1_PROG(REG_1600H, 0x00002d40U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xae6a19a9U),
                               bswap_32big(0xe14566c4U),
                               bswap_32big(0xec070fd2U),
                               bswap_32big(0xc3c570e5U));
            }

            WR1_PROG(REG_1600H, 0x3800094bU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x10a00000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
            r_rsip_subfunc003(0x00c0017dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc009(bswap_32big(0x00007a05U));
            r_rsip_func101(bswap_32big(0xe0851e4fU), bswap_32big(0x00b2ce14U), bswap_32big(0xb99a79f2U),
                           bswap_32big(0x315542ccU));
            r_rsip_func033();
            WR1_PROG(REG_1600H, 0x00000bffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b400U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x16b80000U);
            for (iLoop = 0; iLoop < 96; iLoop = iLoop + 8)
            {
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x34202be0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d3c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c1eU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00602000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x0ee82152U),
                               bswap_32big(0x710bab9eU),
                               bswap_32big(0x8713bb78U),
                               bswap_32big(0x15037861U));
                WR1_PROG(REG_1A2CH, 0x00000100U);
                WR1_PROG(REG_1A24H, 0x08008107U);
                r_rsip_subfunc003(0x00830021U);
                WR1_PROG(REG_1408H, 0x00002022U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 2]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 3]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 4]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 5]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 6]);
                RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 7]);
                WR1_PROG(REG_1600H, 0x0000a7e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000008U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xd7675d69U),
                               bswap_32big(0x6ba47f6aU),
                               bswap_32big(0xfd81c188U),
                               bswap_32big(0xe00c9f50U));
            }

            WR1_PROG(REG_1600H, 0x38000be0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x9801d79aU), bswap_32big(0x15314490U), bswap_32big(0x1f384d72U),
                           bswap_32big(0xf5f5e2ddU));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func102(bswap_32big(0xb95cf2f7U), bswap_32big(0x4401f9e3U), bswap_32big(0xdade934cU),
                           bswap_32big(0x2667610eU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
