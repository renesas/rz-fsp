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
    r_rsip_func100(bswap_32big(0x7b933982U),
                   bswap_32big(0x8fe7d7deU),
                   bswap_32big(0xfa35d152U),
                   bswap_32big(0xd170b689U));
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xa804b40eU), bswap_32big(0xf4bd09f6U), bswap_32big(0x764745ffU),
                       bswap_32big(0x0e2375f1U));
        WR1_PROG(REG_1408H, 0x0000601eU);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        r_rsip_func102(bswap_32big(0xe2b11d8dU), bswap_32big(0x0ac1e88fU), bswap_32big(0xefeef263U),
                       bswap_32big(0xf5d9bd67U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x7b22f698U), bswap_32big(0x0674a48bU), bswap_32big(0x3b60efd4U),
                       bswap_32big(0x621491ddU));
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
        r_rsip_func102(bswap_32big(0x60f6457eU), bswap_32big(0x22b43a8dU), bswap_32big(0x46fc788cU),
                       bswap_32big(0xd729393bU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xde64e695U), bswap_32big(0xd2eeb3a6U), bswap_32big(0xea8d8494U),
                       bswap_32big(0x3a807451U));
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
        r_rsip_func102(bswap_32big(0x38a16eb8U), bswap_32big(0x7b3dcad1U), bswap_32big(0xe6d85513U),
                       bswap_32big(0x61922837U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x6bc66f5dU), bswap_32big(0xbf13786cU), bswap_32big(0x5c8d1d9cU),
                       bswap_32big(0x0ceed3feU));
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
        r_rsip_func102(bswap_32big(0x958f29faU), bswap_32big(0xbc6fcffeU), bswap_32big(0xe25b3ee4U),
                       bswap_32big(0xa69cfe0fU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }

    return RSIP_RET_PASS;
}
