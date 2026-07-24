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

rsip_ret_t r_rsip_pf9 (uint32_t const InData_CurveType[],
                       uint32_t const InData_DomainParam[],
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

    WR1_PROG(REG_1B00H, 0x00f90002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10700000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x13400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x17f00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc009(bswap_32big(0x000000f9U));
    r_rsip_func101(bswap_32big(0xa87f345aU),
                   bswap_32big(0x225fc0e7U),
                   bswap_32big(0x18e3d80eU),
                   bswap_32big(0x420b2677U));
    r_rsip_func027(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x498dbdcbU),
                   bswap_32big(0xd123c919U),
                   bswap_32big(0xaaad7e47U),
                   bswap_32big(0xf82be309U));
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x06060010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x06060010U);
    WR1_PROG(REG_1404H, 0x12b80000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x78e85c6bU),
                   bswap_32big(0x330c2735U),
                   bswap_32big(0xeee384abU),
                   bswap_32big(0x51289398U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x18e2317dU),
                   bswap_32big(0x69b293e0U),
                   bswap_32big(0x5ad9322cU),
                   bswap_32big(0xfeca13b5U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x938d165fU),
                   bswap_32big(0x664b36a5U),
                   bswap_32big(0x4aaad617U),
                   bswap_32big(0xfd2ff646U));
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
    WR1_PROG(REG_1404H, 0x10e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0606000aU);
    WR1_PROG(REG_1404H, 0x11280000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc003(0x00c00009U);
    r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000250U, 0x06060007U);
    r_rsip_func100(bswap_32big(0xc587f8feU),
                   bswap_32big(0xbfa9914bU),
                   bswap_32big(0x849653fdU),
                   bswap_32big(0xb6b41df9U));
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000863U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12180000U);
    WR1_PROG(REG_1608H, 0x808e0001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430039U);
    for (iLoop = 0; iLoop < 14; iLoop = iLoop + 1)
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

    WR1_PROG(REG_1404H, 0x14480000U);
    r_rsip_subfunc003(0x00c00039U);
    r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);
    WR1_PROG(REG_1404H, 0x10d80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c00035U);
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
        r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x00000250U, 0x07070007U);
        r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x7eea23c7U), bswap_32big(0xd790c643U), bswap_32big(0xb9180106U),
                       bswap_32big(0x6261a170U));
    }

    WR1_PROG(REG_1600H, 0x00007c03U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10d80000U);
    r_rsip_subfunc003(0x00c00039U);
    r_rsip_func100(bswap_32big(0x1b01f079U),
                   bswap_32big(0x7e6636ceU),
                   bswap_32big(0x34291ffaU),
                   bswap_32big(0x7c0b2c10U));
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
        r_rsip_subfunc001(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0707000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        r_rsip_func100(bswap_32big(0x76a565a4U), bswap_32big(0xd9a7de51U), bswap_32big(0x143cec1eU),
                       bswap_32big(0x56bd0cdaU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x07070009U);
            r_rsip_func101(bswap_32big(0x981f253eU), bswap_32big(0xca635980U), bswap_32big(0x4484a4a5U),
                           bswap_32big(0x7e593fc3U));
        }

        r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0707000cU);
        r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x07070009U);
        WR1_PROG(REG_1600H, 0x00003000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x2d836fd9U), bswap_32big(0x81d34c98U), bswap_32big(0x761361e1U),
                       bswap_32big(0xd5308881U));
    }

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000340U, 0x06060009U);
    WR1_PROG(REG_1404H, 0x11600000U);
    r_rsip_subfunc003(0x00c000f1U);
    r_rsip_subfunc009(bswap_32big(0x000000f9U));
    r_rsip_func101(bswap_32big(0xd5abc57aU),
                   bswap_32big(0xb9fe07d4U),
                   bswap_32big(0x2bbc8b45U),
                   bswap_32big(0xac72ab15U));
    r_rsip_func028(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x000000f9U));
    r_rsip_func101(bswap_32big(0x3d68c293U),
                   bswap_32big(0xebbd4a53U),
                   bswap_32big(0x6ab2d51eU),
                   bswap_32big(0x80dcec88U));
    r_rsip_func089();
    r_rsip_func100(bswap_32big(0x18cf89a8U),
                   bswap_32big(0x3a476881U),
                   bswap_32big(0x9b1a3735U),
                   bswap_32big(0x0db05ce1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x5c5d0227U), bswap_32big(0x49498963U), bswap_32big(0x874d920aU),
                       bswap_32big(0xb96d7397U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x947e12aaU), bswap_32big(0x447729c6U), bswap_32big(0x494031cbU),
                       bswap_32big(0x579b2ec4U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x0000f901U));
        r_rsip_func101(bswap_32big(0xb898311fU), bswap_32big(0xc478eabeU), bswap_32big(0x3b7b426bU),
                       bswap_32big(0xba7e7a9fU));
        r_rsip_func045();
        r_rsip_func076();
        r_rsip_subfunc009(bswap_32big(0x0000f901U));
        r_rsip_func101(bswap_32big(0xb644ffbaU), bswap_32big(0x56073dc0U), bswap_32big(0xc89bf6f0U),
                       bswap_32big(0x678a174fU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xfdba87adU), bswap_32big(0xffd78da9U), bswap_32big(0xe49f63e0U),
                       bswap_32big(0x4244028bU));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x13100000U);
        r_rsip_subfunc003(0x00830031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[4]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[6]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[8]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[10]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[11]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[12]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[13]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[14]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[15]);
        r_rsip_func100(bswap_32big(0xdfb65bc9U), bswap_32big(0x650ae8a3U), bswap_32big(0x3be5c263U),
                       bswap_32big(0xacb2783bU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[16]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[17]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[18]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[19]);
        r_rsip_func100(bswap_32big(0x99bd009fU), bswap_32big(0x578c479cU), bswap_32big(0xf912dea2U),
                       bswap_32big(0x09ff4492U));
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
        r_rsip_func100(bswap_32big(0x686c961fU), bswap_32big(0x76f04e1cU), bswap_32big(0xec1b7d7fU),
                       bswap_32big(0x975c23aaU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x0000f902U));
        r_rsip_func101(bswap_32big(0xfdfbac1aU), bswap_32big(0x47e72a4fU), bswap_32big(0x92118f92U),
                       bswap_32big(0x53f8992bU));
        r_rsip_func045();
        r_rsip_func077();
        r_rsip_subfunc009(bswap_32big(0x0000f902U));
        r_rsip_func101(bswap_32big(0xe566e36cU), bswap_32big(0xedf379f9U), bswap_32big(0x0a007817U),
                       bswap_32big(0xcafa92ffU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xf3806366U), bswap_32big(0xced48e8dU), bswap_32big(0xf2fcc6b8U),
                       bswap_32big(0x3e488c1aU));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12700000U);
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

        r_rsip_func100(bswap_32big(0xf614174cU), bswap_32big(0x300b01e4U), bswap_32big(0xdb607f3cU),
                       bswap_32big(0x1c4667a8U));
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        WR1_PROG(REG_1404H, 0x12c00000U);
        r_rsip_subfunc003(0x00830021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        for (iLoop = 12; iLoop < 20; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        r_rsip_func100(bswap_32big(0x7b4793d9U), bswap_32big(0xbb1d1928U), bswap_32big(0xb534e0c2U),
                       bswap_32big(0xca533463U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[24]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[25]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[26]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[27]);
        r_rsip_func100(bswap_32big(0x908173b8U), bswap_32big(0xec0be571U), bswap_32big(0x00fcf786U),
                       bswap_32big(0xcdcb4621U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[28]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[29]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[30]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[31]);
        r_rsip_func100(bswap_32big(0xd980658cU), bswap_32big(0xfb8d68f6U), bswap_32big(0x011b983eU),
                       bswap_32big(0x05a12cdeU));
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
        r_rsip_func102(bswap_32big(0xc682cad5U), bswap_32big(0xcb673dcaU), bswap_32big(0x076d1dc8U),
                       bswap_32big(0xb310c7c4U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
