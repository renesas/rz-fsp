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

rsip_ret_t r_rsip_p7f (uint32_t const InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x007f0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    r_rsip_subfunc009(bswap_32big(0x0000007fU));
    r_rsip_func101(bswap_32big(0x425028bfU),
                   bswap_32big(0x768954a1U),
                   bswap_32big(0xce5a86a3U),
                   bswap_32big(0x47e4b288U));
    r_rsip_func078(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x84b6d201U),
                   bswap_32big(0x10194474U),
                   bswap_32big(0xbf84641fU),
                   bswap_32big(0x95074a9cU));
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x08080010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x08080010U);
    WR1_PROG(REG_1404H, 0x12a80000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x316cc462U),
                   bswap_32big(0x80fd6ec6U),
                   bswap_32big(0x7b56db29U),
                   bswap_32big(0x9579efdfU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xd19b8d13U),
                   bswap_32big(0x61d8b828U),
                   bswap_32big(0x43d743e1U),
                   bswap_32big(0x8db1b370U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa1827098U),
                   bswap_32big(0x600aabeeU),
                   bswap_32big(0x20adf9ecU),
                   bswap_32big(0x3264dadfU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xbc639862U),
                   bswap_32big(0x2982fbecU),
                   bswap_32big(0x52cdaa89U),
                   bswap_32big(0x8b1831d4U));
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
    WR1_PROG(REG_1404H, 0x10d00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0808000aU);
    WR1_PROG(REG_1404H, 0x11180000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc003(0x00c00009U);
    r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000250U, 0x08080007U);
    r_rsip_func100(bswap_32big(0x03678433U),
                   bswap_32big(0xc74f1273U),
                   bswap_32big(0x7e94ae35U),
                   bswap_32big(0xc1a47d9eU));
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000863U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12080000U);
    WR1_PROG(REG_1608H, 0x80920001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430049U);
    for (iLoop = 0; iLoop < 18; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1600H, 0x38000c63U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x20000842U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x10003841U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b7c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
        {
            WR1_PROG(REG_1600H, 0x3800585eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x20003460U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x20002c60U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x10002c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x100033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1600H, 0x0000a420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1404H, 0x14380000U);
    r_rsip_subfunc003(0x00c00049U);
    r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x09090009U);
    WR1_PROG(REG_1404H, 0x10c80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1600H, 0x00003403U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x00000250U, 0x09090007U);
        r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x09090009U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7878493dU), bswap_32big(0x55fafec9U), bswap_32big(0x31e4ea62U),
                       bswap_32big(0x5cfaa0d8U));
    }

    WR1_PROG(REG_1600H, 0x00007c03U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_subfunc003(0x00c00049U);
    r_rsip_func100(bswap_32big(0x51d85a45U),
                   bswap_32big(0xb77b2f1eU),
                   bswap_32big(0x6b171419U),
                   bswap_32big(0xd8ec0aa4U));
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        r_rsip_subfunc001(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        r_rsip_func100(bswap_32big(0xbb555694U), bswap_32big(0xf0a8ff13U), bswap_32big(0x2debb652U),
                       bswap_32big(0xe7c5e7f2U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x09090009U);
            r_rsip_func101(bswap_32big(0x0db5ac68U), bswap_32big(0x8e2275deU), bswap_32big(0xcd1661abU),
                           bswap_32big(0xd8790b52U));
        }

        r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0909000cU);
        r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x09090009U);
        WR1_PROG(REG_1600H, 0x00003000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xfc545840U), bswap_32big(0x8603040fU), bswap_32big(0x69e8b928U),
                       bswap_32big(0x03a11555U));
    }

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10d00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000340U, 0x08080009U);
    r_rsip_subfunc009(bswap_32big(0x0000007fU));
    r_rsip_func101(bswap_32big(0x1176d29bU),
                   bswap_32big(0x0359c7aaU),
                   bswap_32big(0x07a24e28U),
                   bswap_32big(0x8b8cb43aU));
    r_rsip_func079(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000007fU));
    r_rsip_func101(bswap_32big(0x020722cbU),
                   bswap_32big(0xe10f240cU),
                   bswap_32big(0xa8a6e9b1U),
                   bswap_32big(0xf2dcca64U));
    r_rsip_func071();
    r_rsip_func100(bswap_32big(0x55af3b5dU),
                   bswap_32big(0xa6fecdb0U),
                   bswap_32big(0xef5d8a67U),
                   bswap_32big(0x5c5f65f9U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xef5b556aU), bswap_32big(0x417a15a8U), bswap_32big(0x52fdd62aU),
                       bswap_32big(0x715ac6b9U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x0c8580c2U), bswap_32big(0x1e86fc96U), bswap_32big(0x00228855U),
                       bswap_32big(0xcab34beeU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00007f01U));
        r_rsip_func101(bswap_32big(0xd07db37aU), bswap_32big(0x44581019U), bswap_32big(0x6539245eU),
                       bswap_32big(0xd5b205a0U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01cc489dU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00007f01U));
        r_rsip_func101(bswap_32big(0x4a382ecbU), bswap_32big(0xe4d7045dU), bswap_32big(0x9beb66a6U),
                       bswap_32big(0x5f6d9c1aU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x734cb877U), bswap_32big(0xf9b586d8U), bswap_32big(0x46eba364U),
                       bswap_32big(0xe7195ea5U));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x13000000U);
        r_rsip_subfunc003(0x00830031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0x44017383U), bswap_32big(0x595ab442U), bswap_32big(0xb6d67aefU),
                       bswap_32big(0x997fde51U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 7]);
        r_rsip_func100(bswap_32big(0xae0deef2U), bswap_32big(0x2445c5c5U), bswap_32big(0xa6c8a0f7U),
                       bswap_32big(0x21125febU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 8]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 9]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 10]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 11]);
        r_rsip_func100(bswap_32big(0xbc59316fU), bswap_32big(0x56a0e096U), bswap_32big(0x862cb381U),
                       bswap_32big(0x18234ccdU));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[3]);
        r_rsip_func100(bswap_32big(0x46f83b16U), bswap_32big(0x9a8def5fU), bswap_32big(0xb570fdb4U),
                       bswap_32big(0x9438c932U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00007f02U));
        r_rsip_func101(bswap_32big(0xe0e2e89aU), bswap_32big(0x1eb84108U), bswap_32big(0x4978924fU),
                       bswap_32big(0xa028344eU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01366895U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00007f02U));
        r_rsip_func101(bswap_32big(0xf1ed8b53U), bswap_32big(0xe3344ed5U), bswap_32big(0x2cdc509fU),
                       bswap_32big(0x6e8851a1U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xcbf638e9U), bswap_32big(0xdd93133eU), bswap_32big(0xad37740bU),
                       bswap_32big(0xbbc53c72U));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12600000U);
        r_rsip_subfunc003(0x00830031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0xcad866cbU), bswap_32big(0x828e553dU), bswap_32big(0x0eed1e28U),
                       bswap_32big(0xb1f91528U));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1404H, 0x12b00000U);
        r_rsip_subfunc003(0x00830021U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 12; iLoop < 24; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0xd0265bd2U), bswap_32big(0x6f736ca7U), bswap_32big(0x99fb1b38U),
                       bswap_32big(0x1a62931dU));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[28]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[29]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[30]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[31]);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        r_rsip_func100(bswap_32big(0x950b990fU), bswap_32big(0xc59afd7bU), bswap_32big(0x7c373572U),
                       bswap_32big(0x2800e1f5U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[32]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[33]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[34]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[35]);
        r_rsip_func100(bswap_32big(0x49c21908U), bswap_32big(0x934f32bfU), bswap_32big(0x0cd351ebU),
                       bswap_32big(0x988e545cU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[36]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[37]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[38]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[39]);
        r_rsip_func100(bswap_32big(0x7f60f2fbU), bswap_32big(0xf62679c7U), bswap_32big(0xe63736aeU),
                       bswap_32big(0x03de7c37U));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[3]);
        r_rsip_func102(bswap_32big(0x49111844U), bswap_32big(0x6adc0158U), bswap_32big(0xe9fcdf6dU),
                       bswap_32big(0x3e648cb9U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
