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

rsip_ret_t r_rsip_p78f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
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
    WAIT_STS(REG_2440H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020065U);
    for (iLoop = 0; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop = iLoop + S_RAM[0])
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        for (jLoop = 0; jLoop < S_RAM[0]; jLoop = jLoop + 2)
        {
            WR1_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop + 0]);
            WR1_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop + 1]);
        }
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001400U);
    WAIT_STS(REG_2440H, 4U, 1U);
    r_rsip_func100(bswap_32big(0x4b8127c6U),
                   bswap_32big(0x2ba455b0U),
                   bswap_32big(0xb3f399f1U),
                   bswap_32big(0xcb21904bU));
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xbef9d30aU), bswap_32big(0xbe6ac922U), bswap_32big(0x918c7881U),
                       bswap_32big(0x4a385722U));
        WR1_PROG(REG_1408H, 0x0000601eU);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        r_rsip_func102(bswap_32big(0x6bb21b1cU), bswap_32big(0x74254329U), bswap_32big(0x5c4f62eaU),
                       bswap_32big(0xedde42f2U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xc83acb91U), bswap_32big(0xb33ebfbeU), bswap_32big(0x5ef7d51bU),
                       bswap_32big(0x95b78767U));
        WR1_PROG(REG_1408H, 0x00006022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        r_rsip_func102(bswap_32big(0x9d93c6c0U), bswap_32big(0xab51ad05U), bswap_32big(0x01eb8befU),
                       bswap_32big(0x81c2376dU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xc2e99c70U), bswap_32big(0x5609555aU), bswap_32big(0xcdf2dcfbU),
                       bswap_32big(0x9b4fa4f3U));
        WR1_PROG(REG_1408H, 0x00006032U);
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
        r_rsip_func102(bswap_32big(0xb0ee34f9U), bswap_32big(0xbbdcb4c1U), bswap_32big(0x4c31c661U),
                       bswap_32big(0xfc95f1a3U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x6e25d906U), bswap_32big(0xc98feb37U), bswap_32big(0x156632e3U),
                       bswap_32big(0x395c4206U));
        WR1_PROG(REG_1408H, 0x00006042U);
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
        r_rsip_func102(bswap_32big(0x8a7443f2U), bswap_32big(0xe0d95d72U), bswap_32big(0x5a73ec6cU),
                       bswap_32big(0xcca53586U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }

    return RSIP_RET_PASS;
}
