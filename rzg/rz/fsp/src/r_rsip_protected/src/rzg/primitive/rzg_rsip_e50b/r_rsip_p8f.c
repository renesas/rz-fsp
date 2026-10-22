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

rsip_ret_t r_rsip_p8f (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_WrappedKeyIndex[],
                       uint32_t       OutData_Text[],
                       uint32_t       KEY_INDEX_SIZE,
                       uint32_t       WRAPPED_KEY_SIZE)
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
    if (0x0U != RD1_MASK(REG_14B4H, 0x1dU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x008f0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000001c7U);
    WR1_PROG(REG_1608H, 0x80020100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_WrappedKeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003409U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a900U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x059b5192U),
                   bswap_32big(0xc40f9fc5U),
                   bswap_32big(0x4912efdaU),
                   bswap_32big(0x348d6f50U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xb587e0e1U), bswap_32big(0x859a0b1aU), bswap_32big(0x82c542a7U),
                       bswap_32big(0x526441c8U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
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
        r_rsip_subfunc009(bswap_32big(0x00008f01U));
        r_rsip_func101(bswap_32big(0x6bde2c2cU), bswap_32big(0x7afb4b1aU), bswap_32big(0xbe7b9f64U),
                       bswap_32big(0xafe7fa4cU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x38000d08U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x3d50ddfcU), bswap_32big(0xf522af71U), bswap_32big(0x0ce4d49bU),
                       bswap_32big(0x31c732b3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01379ba9U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00008f01U));
            r_rsip_func101(bswap_32big(0xf46b4f3cU), bswap_32big(0x9438ee33U), bswap_32big(0x376e7defU),
                           bswap_32big(0x963df603U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x20c60f42U), bswap_32big(0x06e58354U), bswap_32big(0xd8897ca0U),
                           bswap_32big(0xb0a89e15U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7009d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_subfunc003(0x00420011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
            WR1_PROG(REG_182CH, 0x00000000U);
            r_rsip_func101(bswap_32big(0x3ee92fcdU), bswap_32big(0xcea390f5U), bswap_32big(0x11b3da5fU),
                           bswap_32big(0x0ebcdf9fU));
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x014e8006U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00008f02U));
            r_rsip_func101(bswap_32big(0x91fc5aa6U), bswap_32big(0xa5ec0da9U), bswap_32big(0x76df442bU),
                           bswap_32big(0xbd792878U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xabd5edd2U), bswap_32big(0xb4b31724U), bswap_32big(0x66ec5a63U),
                           bswap_32big(0xc4a75460U));
            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_subfunc003(0x00420011U);
            r_rsip_func100(bswap_32big(0x317f2912U), bswap_32big(0xbc354ee3U), bswap_32big(0x657092b3U),
                           bswap_32big(0x57eab1d7U));
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_subfunc003(0x00420011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[12]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[13]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[14]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[15]);
            WR1_PROG(REG_182CH, 0x40000000U);
            r_rsip_func101(bswap_32big(0x360a29a2U), bswap_32big(0x4e407294U), bswap_32big(0x761837a6U),
                           bswap_32big(0xb4611249U));
        }

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0xa8e4e097U), bswap_32big(0xf0c582dbU), bswap_32big(0x371cbe16U),
                       bswap_32big(0x2ee31afdU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xe4ac1e40U), bswap_32big(0x59b81303U), bswap_32big(0xa6a8a191U),
                           bswap_32big(0x0b2e5392U));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00003409U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func030();
            WR1_PROG(REG_1600H, 0x000035c7U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00008f02U));
            r_rsip_func101(bswap_32big(0x499a4583U), bswap_32big(0xe0882c6eU), bswap_32big(0xf81ad957U),
                           bswap_32big(0x710a60d0U));
            r_rsip_func045();
            WR1_PROG(REG_1600H, 0x000034e6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00008f03U));
            r_rsip_func101(bswap_32big(0x27db32e2U), bswap_32big(0x1cf74cf5U), bswap_32big(0xc4f139b3U),
                           bswap_32big(0x1331f43bU));
            r_rsip_func046();
            WR1_PROG(REG_1600H, 0x000034eeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1600H, 0x0000b7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b780U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b760U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a8e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < KEY_INDEX_SIZE - 8; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xf7008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 7]);
                WR1_PROG(REG_1608H, 0x8084001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                WR1_PROG(REG_1600H, 0x000027fcU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000027dbU);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x7ec9e0a7U),
                               bswap_32big(0x32336649U),
                               bswap_32big(0xac04565bU),
                               bswap_32big(0xd52d61ceU));
            }

            WR1_PROG(REG_1600H, 0x38000bc7U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_WrappedKeyIndex[iLoop + 7]);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_subfunc003(0x00820011U);
            r_rsip_func100(bswap_32big(0xaa7a58eaU), bswap_32big(0x148c99f4U), bswap_32big(0xfa8cb507U),
                           bswap_32big(0x664587d9U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xa136a609U),
                               bswap_32big(0x21ccbf7eU),
                               bswap_32big(0x2491949dU),
                               bswap_32big(0x2f0de2e6U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0xa6a6a6a6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003420U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b760U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000008U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b780U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b480U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000001U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop <= 5; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x000037fbU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000bbdU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    for (iLoop = 1; iLoop <= (WRAPPED_KEY_SIZE - 2) / 2; iLoop = iLoop + 1)
                    {
                        WR1_PROG(REG_1824H, 0x0a008105U);
                        WR1_PROG(REG_1608H, 0x81020000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00490009U);
                        WR1_PROG(REG_1608H, 0x8182001fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x00490009U);
                        WR1_PROG(REG_1608H, 0x80040000U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_subfunc003(0x03410011U);
                        WR1_PROG(REG_1600H, 0x00000824U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00003c5fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x000027fcU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00003c7fU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x000027fcU);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002c80U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        WR1_PROG(REG_1600H, 0x00002fa0U);
                        WR1_PROG(REG_1458H, 0x00000000U);
                        r_rsip_func101(bswap_32big(0x7ba7dbc2U),
                                       bswap_32big(0x2d8fb704U),
                                       bswap_32big(0x35f45bf6U),
                                       bswap_32big(0xfee64a06U));
                    }

                    WR1_PROG(REG_1600H, 0x38000ba5U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1608H, 0x00000080U);
                    WR1_PROG(REG_143CH, 0x00260000U);
                    WR1_PROG(REG_143CH, 0x00402000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002fc0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x9a73c021U),
                                   bswap_32big(0x7bfc6298U),
                                   bswap_32big(0xdd14193eU),
                                   bswap_32big(0x529e6d8bU));
                }

                WR1_PROG(REG_1600H, 0x38008bc0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000006U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000bffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c1fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000027fcU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003c3fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000bffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000037a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002fa0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b780U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000008U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < WRAPPED_KEY_SIZE; iLoop = iLoop + 2)
                {
                    WR1_PROG(REG_1600H, 0x000008c6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x34202bddU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d0c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c06U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0x5a02526eU),
                                   bswap_32big(0x3e8c3f4aU),
                                   bswap_32big(0x1f34ce8fU),
                                   bswap_32big(0x41e8ef97U));
                    WR1_PROG(REG_1608H, 0x8182001fU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1408H, 0x0000500aU);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Text[iLoop]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Text[iLoop + 1]);
                    WR1_PROG(REG_1600H, 0x000027fcU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002fc0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xdcff70d8U),
                                   bswap_32big(0xc772b8e2U),
                                   bswap_32big(0x0bb99b5cU),
                                   bswap_32big(0x3c3de9b1U));
                }

                WR1_PROG(REG_1600H, 0x38000bddU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func102(bswap_32big(0x79a13c50U),
                               bswap_32big(0x431253c1U),
                               bswap_32big(0x1bbf615aU),
                               bswap_32big(0x030ae4f3U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
