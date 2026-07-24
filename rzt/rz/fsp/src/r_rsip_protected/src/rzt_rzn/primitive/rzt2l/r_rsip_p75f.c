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

rsip_ret_t r_rsip_p75f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Msg[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       MAX_CNT,
                        uint32_t       OutData_MAC[])
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
    WAIT_STS(REG_2030H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020064U);
    for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 3]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 7]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 11]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 12]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 13]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 14]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 15]);
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001600U);
    WAIT_STS(REG_2030H, 4U, 1U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0x9f03bb50U),
                   bswap_32big(0x629715ebU),
                   bswap_32big(0x0dcd379bU),
                   bswap_32big(0x89b7667eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func100(bswap_32big(0xbe27f98aU), bswap_32big(0x0e21beb8U), bswap_32big(0x3e880809U),
                       bswap_32big(0xe382d274U));
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x8feb7b64U), bswap_32big(0x9bea577cU), bswap_32big(0x028d3024U),
                           bswap_32big(0x3251503cU));
            WR1_PROG(REG_1408H, 0x00004016U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            r_rsip_func102(bswap_32big(0xdd00bc8cU), bswap_32big(0x8fbe5f10U), bswap_32big(0xaec6d532U),
                           bswap_32big(0x1679ee39U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xfd51a526U), bswap_32big(0xd281082fU), bswap_32big(0x638b65f0U),
                           bswap_32big(0xfab1f490U));
            WR1_PROG(REG_1408H, 0x0000401eU);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            r_rsip_func102(bswap_32big(0xcaf4084aU), bswap_32big(0xbfc309abU), bswap_32big(0x863ea50eU),
                           bswap_32big(0x9c161a6fU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x5cfbdd59U), bswap_32big(0xa18239e2U), bswap_32big(0x596eeedaU),
                           bswap_32big(0x4f485cc0U));
            WR1_PROG(REG_1408H, 0x00004022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            r_rsip_func102(bswap_32big(0x7395b1f3U), bswap_32big(0xc36e5f9aU), bswap_32big(0x5befe413U),
                           bswap_32big(0x1acd0c5bU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x27d49a1eU), bswap_32big(0x165e9d2eU), bswap_32big(0x6b33e520U),
                           bswap_32big(0xc79c43acU));
            WR1_PROG(REG_1408H, 0x00004032U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            RD1_ADDR(REG_1420H, &OutData_MAC[8]);
            RD1_ADDR(REG_1420H, &OutData_MAC[9]);
            RD1_ADDR(REG_1420H, &OutData_MAC[10]);
            RD1_ADDR(REG_1420H, &OutData_MAC[11]);
            r_rsip_func102(bswap_32big(0x9ce61412U), bswap_32big(0xb35e16b2U), bswap_32big(0xb2c679b4U),
                           bswap_32big(0x5e058f0bU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xbdaaea08U), bswap_32big(0x7762d557U), bswap_32big(0x9f30a742U),
                           bswap_32big(0xe9af736fU));
            WR1_PROG(REG_1408H, 0x00004042U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            RD1_ADDR(REG_1420H, &OutData_MAC[8]);
            RD1_ADDR(REG_1420H, &OutData_MAC[9]);
            RD1_ADDR(REG_1420H, &OutData_MAC[10]);
            RD1_ADDR(REG_1420H, &OutData_MAC[11]);
            RD1_ADDR(REG_1420H, &OutData_MAC[12]);
            RD1_ADDR(REG_1420H, &OutData_MAC[13]);
            RD1_ADDR(REG_1420H, &OutData_MAC[14]);
            RD1_ADDR(REG_1420H, &OutData_MAC[15]);
            r_rsip_func102(bswap_32big(0xaa9cc53aU), bswap_32big(0x3dedc214U), bswap_32big(0xa28056acU),
                           bswap_32big(0x1b52e7f0U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x1b0dc855U), bswap_32big(0x59bcd130U), bswap_32big(0x2683b9beU),
                       bswap_32big(0x1259bfc2U));
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000014U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xa3907fc8U), bswap_32big(0xf2ebf527U), bswap_32big(0x8829ee94U),
                           bswap_32big(0x87207962U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000001cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x5dd9f0d6U), bswap_32big(0xbb515a74U), bswap_32big(0xeb6842afU),
                           bswap_32big(0xb90a7198U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x69854f7dU), bswap_32big(0xbdf6d5e4U), bswap_32big(0xcbaea77aU),
                           bswap_32big(0x16b97fafU));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd1a345a3U), bswap_32big(0x309f4b88U), bswap_32big(0x84484735U),
                           bswap_32big(0x70eed43dU));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x0d5cc606U), bswap_32big(0xb9b143a1U), bswap_32big(0xc7992e31U),
                           bswap_32big(0x3948621cU));
        }

        WR1_PROG(REG_1600H, 0x3420a820U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1600H, 0x34202841U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x6744fe87U), bswap_32big(0xa4d54aadU), bswap_32big(0xf520c3f7U),
                       bswap_32big(0x8a568c27U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x97012026U), bswap_32big(0x582322c7U), bswap_32big(0x33996ce9U),
                           bswap_32big(0xf1b81f1eU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xc8aea82fU), bswap_32big(0xe2962a57U), bswap_32big(0x06cbec07U),
                           bswap_32big(0x716ef0daU));
            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000008a5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026c42U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
            {
                r_rsip_func100(bswap_32big(0x0ed1865aU),
                               bswap_32big(0x38aa785fU),
                               bswap_32big(0x403d454aU),
                               bswap_32big(0x13559c0fU));
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003464U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3420a880U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x380088c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c03U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80810007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03450005U);
                    WR1_PROG(REG_1444H, 0x000000c1U);
                    WR1_PROG(REG_1824H, 0x08000044U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    r_rsip_func101(bswap_32big(0x6c7a88daU),
                                   bswap_32big(0x000afb59U),
                                   bswap_32big(0xace9dbfaU),
                                   bswap_32big(0x5076ec7bU));
                }
                else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x0345000dU);
                    WR1_PROG(REG_1444H, 0x000002c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 2]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_func101(bswap_32big(0xa86cc826U),
                                   bswap_32big(0x599f147bU),
                                   bswap_32big(0x3ed5a62eU),
                                   bswap_32big(0x08538747U));
                }
                else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03450011U);
                    WR1_PROG(REG_1444H, 0x000003c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 3]);
                    r_rsip_func101(bswap_32big(0x08d7e46cU),
                                   bswap_32big(0xe331574bU),
                                   bswap_32big(0xe23e20a7U),
                                   bswap_32big(0x816ce41aU));
                }

                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 16; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x3c0028a1U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x12003c07U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ce0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ca0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81840007U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00490011U);
                WR1_PROG(REG_1600H, 0x0000a4c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x4333ef1eU),
                               bswap_32big(0xb0dd59c2U),
                               bswap_32big(0xc3fd59a7U),
                               bswap_32big(0xe98d3267U));
            }

            WR1_PROG(REG_1600H, 0x000008c2U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c06U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x1bc87992U), bswap_32big(0x6339b447U), bswap_32big(0xdbd1e44cU),
                           bswap_32big(0xcfbd4e90U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x4ba7602bU),
                               bswap_32big(0x1ac3d776U),
                               bswap_32big(0xd2a6512cU),
                               bswap_32big(0xbd4cc831U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func102(bswap_32big(0x9d5b9dacU),
                               bswap_32big(0x091bd0e2U),
                               bswap_32big(0x68b3d43fU),
                               bswap_32big(0x7916031dU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
