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

rsip_ret_t r_rsip_p70f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
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
    r_rsip_func100(bswap_32big(0x0f38b593U),
                   bswap_32big(0x0639ccebU),
                   bswap_32big(0x15773f2cU),
                   bswap_32big(0x53b3ebedU));
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x7ffbdc34U), bswap_32big(0x43d85d6bU), bswap_32big(0xf258bfeaU),
                       bswap_32big(0x29cdda1cU));
        WR1_PROG(REG_1408H, 0x00004016U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        r_rsip_func102(bswap_32big(0xda3ac589U), bswap_32big(0x5c5d756eU), bswap_32big(0x58f91221U),
                       bswap_32big(0x7f032a8aU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xc7740bc2U), bswap_32big(0x75145911U), bswap_32big(0x801e6a15U),
                       bswap_32big(0x112c2727U));
        WR1_PROG(REG_1408H, 0x0000401eU);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        r_rsip_func102(bswap_32big(0x1828ed05U), bswap_32big(0x5da93313U), bswap_32big(0x6fa96dc8U),
                       bswap_32big(0x09be82d5U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x6ac047d0U), bswap_32big(0x443b7bd4U), bswap_32big(0x72877b3fU),
                       bswap_32big(0x9b87b0deU));
        WR1_PROG(REG_1408H, 0x00004022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        r_rsip_func102(bswap_32big(0x048838f8U), bswap_32big(0xf300ef6bU), bswap_32big(0x7ce73efdU),
                       bswap_32big(0xfd0663f8U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xdbf045cdU), bswap_32big(0xc7a26c7aU), bswap_32big(0xa4f46159U),
                       bswap_32big(0xc91c69dcU));
        WR1_PROG(REG_1408H, 0x00004032U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[8]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[9]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[10]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[11]);
        r_rsip_func102(bswap_32big(0xcaa48381U), bswap_32big(0x5c134357U), bswap_32big(0x0261cd35U),
                       bswap_32big(0xaae7e733U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xf4cc4703U), bswap_32big(0x2167ae1eU), bswap_32big(0x2132cbe3U),
                       bswap_32big(0x0032d91fU));
        WR1_PROG(REG_1408H, 0x00004042U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[8]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[9]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[10]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[11]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[12]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[13]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[14]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[15]);
        r_rsip_func102(bswap_32big(0xe833f0abU), bswap_32big(0xad2e1d7dU), bswap_32big(0xc4fde310U),
                       bswap_32big(0x2596afc8U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }

    return RSIP_RET_PASS;
}
