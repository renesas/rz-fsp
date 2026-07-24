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

rsip_ret_t r_rsip_pe5f (const uint32_t InData_Msg[],
                        const uint32_t InData_EncMsg[],
                        uint32_t       OutData_KDFInfo[],
                        const uint32_t MAX_CNT,
                        const uint32_t MAX_CNT2)
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
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    uint32_t max_cnt2 = bswap_32big(MAX_CNT2);
    WR1_ADDR(REG_1420H, &max_cnt2);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000d08U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x91c38990U),
                   bswap_32big(0xb549d9c4U),
                   bswap_32big(0x297cc9c4U),
                   bswap_32big(0x7e40e8f6U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e504U));
        r_rsip_func101(bswap_32big(0xea09cb41U), bswap_32big(0x117c6d3dU), bswap_32big(0xa97a0eb5U),
                       bswap_32big(0x6a06019aU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x013f271aU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e504U));
        r_rsip_func101(bswap_32big(0x0c0d40a6U), bswap_32big(0x31788d90U), bswap_32big(0xd60e93eeU),
                       bswap_32big(0xc7d85233U));
        r_rsip_func046();
        WAIT_STS(REG_2030H, 0U, 1U);
        r_rsip_func100(bswap_32big(0x12ff169aU), bswap_32big(0x8a3990eaU), bswap_32big(0x5496d257U),
                       bswap_32big(0xc7c4fd98U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x81010100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        OFS_ADR = S_RAM[0];
        WR1_PROG(REG_1600H, 0x0000a900U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00026908U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3800a900U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0xebff568cU), bswap_32big(0x030f9e4fU), bswap_32big(0xad302e45U),
                       bswap_32big(0xe2d2fe5dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0] - 12; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xf7008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
                r_rsip_subfunc003(0x01420011U);
                WR1_PROG(REG_1600H, 0x00002d20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x10192836U),
                               bswap_32big(0x80b45229U),
                               bswap_32big(0xeff83facU),
                               bswap_32big(0x46ee2452U));
            }

            WR1_PROG(REG_1600H, 0x000037e8U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000033e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38000be9U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
            r_rsip_subfunc003(0x01420005U);
            r_rsip_subfunc003(0x0002000dU);
            iLoop = iLoop + 4;
            r_rsip_func101(bswap_32big(0xc639f6e1U), bswap_32big(0x17903bf9U), bswap_32big(0x7e6a6019U),
                           bswap_32big(0x1a40859eU));
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00000929U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < S_RAM[0] - 8; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1444H, 0x000003c2U);
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0xf7008d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
                r_rsip_subfunc003(0x01420011U);
                WR1_PROG(REG_1600H, 0x00002d20U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xc97865d0U),
                               bswap_32big(0x0e44dc60U),
                               bswap_32big(0x5c44f46aU),
                               bswap_32big(0xc766afe8U));
            }

            WR1_PROG(REG_1600H, 0x38000909U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x5f296607U), bswap_32big(0x24d874e9U), bswap_32big(0xc94de350U),
                           bswap_32big(0x5fb358e8U));
        }

        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 3]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 2]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 1]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x83cba1b2U), bswap_32big(0xc961f8b3U), bswap_32big(0x054e5ef4U),
                       bswap_32big(0xb931fc38U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xbc069380U), bswap_32big(0xed346126U), bswap_32big(0xd63e224eU),
                           bswap_32big(0x3f2e1204U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func101(bswap_32big(0xcd4d743eU), bswap_32big(0x7c138befU), bswap_32big(0x78293f86U),
                           bswap_32big(0x03d49e0bU));
        }
    }
    else
    {
        r_rsip_func101(bswap_32big(0xc3787ca6U), bswap_32big(0x699a7397U), bswap_32big(0xc26cfb90U),
                       bswap_32big(0x2e7d8722U));
    }

    WAIT_STS(REG_2030H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020064U);
    for (iLoop = 0; iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001600U);
    WAIT_STS(REG_2030H, 4U, 1U);
    r_rsip_func100(bswap_32big(0xd568e563U),
                   bswap_32big(0xbf7565d2U),
                   bswap_32big(0x87b44264U),
                   bswap_32big(0x4272bf1cU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x0000e505U));
    r_rsip_func101(bswap_32big(0xcc2728a5U),
                   bswap_32big(0x0f831e02U),
                   bswap_32big(0xbdfea3a5U),
                   bswap_32big(0x3d7139c6U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x013f271aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000e505U));
    r_rsip_func101(bswap_32big(0xe3ed260eU),
                   bswap_32big(0x1ad667cdU),
                   bswap_32big(0xdcd42408U),
                   bswap_32big(0xfdf3d4adU));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x000008e7U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xed2ea210U),
                   bswap_32big(0xbadbd94eU),
                   bswap_32big(0x6e66af3dU),
                   bswap_32big(0x42de284eU));
    WR1_PROG(REG_1608H, 0x810101e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
    {
        r_rsip_func100(bswap_32big(0x4106f52cU), bswap_32big(0xb8a74111U), bswap_32big(0xacc15ca8U),
                       bswap_32big(0xf60f6592U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00850011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 7]);
        WR1_PROG(REG_1600H, 0x0000a4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xd4388852U), bswap_32big(0xe96bbd13U), bswap_32big(0x9c7262d8U),
                       bswap_32big(0x1eb884a1U));
    }

    WR1_PROG(REG_1600H, 0x380008efU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x44ff73f4U),
                   bswap_32big(0x4dcc688cU),
                   bswap_32big(0x40eb432fU),
                   bswap_32big(0x0dd5a805U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x09108105U);
    r_rsip_subfunc003(0x00820011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 4]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 5]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 6]);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[iLoop + 7]);
    r_rsip_func100(bswap_32big(0x86bc2e23U),
                   bswap_32big(0x14c9f679U),
                   bswap_32big(0x2e19f51cU),
                   bswap_32big(0x94b3db67U));
    WR1_PROG(REG_1608H, 0x81040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[0]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[1]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[2]);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_KDFInfo[3]);
    r_rsip_func102(bswap_32big(0xb29bea8fU),
                   bswap_32big(0x3228dcbcU),
                   bswap_32big(0xdb17cb76U),
                   bswap_32big(0x736fff75U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
