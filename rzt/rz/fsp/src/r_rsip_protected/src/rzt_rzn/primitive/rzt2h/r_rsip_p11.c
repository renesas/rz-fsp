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

rsip_ret_t r_rsip_p11 (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
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

    WR1_PROG(REG_1B00H, 0x00110002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    r_rsip_subfunc009(bswap_32big(0x00000011U));
    r_rsip_func101(bswap_32big(0xe2ed7d2eU),
                   bswap_32big(0xe80dea82U),
                   bswap_32big(0xe7522f5aU),
                   bswap_32big(0xc17c003eU));
    r_rsip_func074(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x1ca1f8e3U),
                   bswap_32big(0x6dd953b0U),
                   bswap_32big(0x871a6682U),
                   bswap_32big(0x06b0ae7aU));
    WR1_PROG(REG_1404H, 0x11180000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x000003e0U, 0x0808000aU);
    r_rsip_subfunc006(0x00000020U, 0x000003e0U, 0x09090010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x09090010U);
    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x7b55d2b6U),
                   bswap_32big(0xf2ec3b6dU),
                   bswap_32big(0x81c5039fU),
                   bswap_32big(0x59ac2fb1U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xf82cf965U),
                   bswap_32big(0x42038ed0U),
                   bswap_32big(0x9f7fce69U),
                   bswap_32big(0xd46bd4e5U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x4654b147U),
                   bswap_32big(0x346f3f4dU),
                   bswap_32big(0x7b646b52U),
                   bswap_32big(0xc65de666U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x105354b6U),
                   bswap_32big(0x17cf4a02U),
                   bswap_32big(0xe2c19129U),
                   bswap_32big(0xb46ceef2U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20009U);
    r_rsip_subfunc003(0x00020009U);
    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x000003e0U);
    WR1_PROG(REG_1020H, 0x00000160U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x09090004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x13e80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000160U, 0x00000430U, 0x00000340U, 0x09090009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x09090010U);
    r_rsip_subfunc009(bswap_32big(0x00000011U));
    r_rsip_func101(bswap_32big(0x41de94ddU),
                   bswap_32big(0xaecd8693U),
                   bswap_32big(0x03b0167bU),
                   bswap_32big(0xb4de82adU));
    r_rsip_func075(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x00000011U));
    r_rsip_func101(bswap_32big(0x9d484a43U),
                   bswap_32big(0x795c8128U),
                   bswap_32big(0xa9e0c138U),
                   bswap_32big(0x406dd4d2U));
    r_rsip_func072();
    r_rsip_func100(bswap_32big(0x4180baafU),
                   bswap_32big(0x51131b9dU),
                   bswap_32big(0x432550e3U),
                   bswap_32big(0xe0b014d1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xf2928d9fU), bswap_32big(0x0abd34a6U), bswap_32big(0x93baf751U),
                       bswap_32big(0x2826dffeU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000840U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x000002f0U);
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_1004H, 0x09090002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000002f0U);
        r_rsip_subfunc002(0x000000c0U, 0x000002a0U, 0x09090004U);
        WR1_PROG(REG_1404H, 0x10c80000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c00045U);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000002a0U, 0x00000110U, 0x00000160U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x60988b6fU), bswap_32big(0x704130eeU), bswap_32big(0x56758eaaU),
                       bswap_32big(0xd9a512c9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x2d3b8be8U), bswap_32big(0xe9276323U), bswap_32big(0xc32a5297U),
                           bswap_32big(0xc6261190U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x3bb4da19U), bswap_32big(0xb0a0fc08U), bswap_32big(0x917106dfU),
                           bswap_32big(0x7627a3ecU));
            WR1_PROG(REG_1404H, 0x11180000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c00045U);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000110U, 0x0909000aU);
            r_rsip_subfunc005(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0909000fU, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000160U);
            WR1_PROG(REG_1018H, 0x00000840U);
            r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x09090002U);
            WR1_PROG(REG_1404H, 0x11100000U);
            r_rsip_subfunc003(0x00c00011U);
            WR1_PROG(REG_1444H, 0x00000fc2U);
            WR1_PROG(REG_1A2CH, 0x00000300U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1404H, 0x11200000U);
            for (iLoop = 0; iLoop < 16; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 3]);
                r_rsip_subfunc003(0x00c20011U);
            }

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
            r_rsip_subfunc009(bswap_32big(0x00000011U));
            r_rsip_func101(bswap_32big(0x8091c91cU), bswap_32big(0xc3ce5cb3U), bswap_32big(0xa4079f67U),
                           bswap_32big(0xce8f7f78U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01640a92U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00000011U));
            r_rsip_func101(bswap_32big(0xb354550dU), bswap_32big(0x1cf7fec6U), bswap_32big(0x6f4e3e8dU),
                           bswap_32big(0xa0b3737aU));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x000013c2U);
            WR1_PROG(REG_1A2CH, 0x40000400U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);
            WR1_PROG(REG_1404H, 0x11b00000U);
            for (iLoop = 0; iLoop < 20; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
                r_rsip_subfunc003(0x00c20011U);
            }

            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_subfunc003(0x00820011U);
            r_rsip_func100(bswap_32big(0xdede1395U), bswap_32big(0x50fba793U), bswap_32big(0x10a42ec8U),
                           bswap_32big(0x24acce9fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x0aaaac1fU),
                               bswap_32big(0x593c5778U),
                               bswap_32big(0x979f5350U),
                               bswap_32big(0x9226123fU));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000200U);
                WR1_PROG(REG_1018H, 0x00000840U);
                r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x09090002U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x000002a0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x09090002U);
                WR1_PROG(REG_1014H, 0x00000160U);
                WR1_PROG(REG_1018H, 0x00000200U);
                r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x09090005U);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x000001b0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x09090002U);
                WR1_PROG(REG_1404H, 0x10c80000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c00045U);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000160U, 0x0909000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x46b8a173U),
                               bswap_32big(0x0e9a7292U),
                               bswap_32big(0x3393f667U),
                               bswap_32big(0x3554562dU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x79d57084U),
                                   bswap_32big(0x9a7173edU),
                                   bswap_32big(0x63f2aca1U),
                                   bswap_32big(0x11667030U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0x360588fbU),
                                   bswap_32big(0x9d524033U),
                                   bswap_32big(0xe2b62b57U),
                                   bswap_32big(0x5118a27aU));
                    WR1_PROG(REG_1404H, 0x12500000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830031U);
                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[0]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[1]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[2]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[3]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[4]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[5]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[6]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[7]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[8]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[9]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[10]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[11]);
                    r_rsip_func100(bswap_32big(0x5c5e95baU),
                                   bswap_32big(0x050ccc2aU),
                                   bswap_32big(0x94a633deU),
                                   bswap_32big(0x8636d255U));
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830021U);
                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[12]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[13]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[14]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[15]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[16]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[17]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[18]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[19]);
                    r_rsip_func100(bswap_32big(0xfe83892cU),
                                   bswap_32big(0xf75464d3U),
                                   bswap_32big(0xf86c9717U),
                                   bswap_32big(0xf86618eaU));
                    WR1_PROG(REG_1404H, 0x11b00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830031U);
                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[20]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[21]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[22]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[23]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[24]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[25]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[26]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[27]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[28]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[29]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[30]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[31]);
                    r_rsip_func100(bswap_32big(0xb3e06282U),
                                   bswap_32big(0x27d1962fU),
                                   bswap_32big(0x7be34e7eU),
                                   bswap_32big(0x73926644U));
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830021U);
                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[32]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[33]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[34]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[35]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[36]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[37]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[38]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[39]);
                    r_rsip_func102(bswap_32big(0x99df796cU),
                                   bswap_32big(0xf8892184U),
                                   bswap_32big(0x3b36b2c0U),
                                   bswap_32big(0xf09bc05eU));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
