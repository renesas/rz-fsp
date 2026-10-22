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
    r_rsip_subfunc009(bswap_32big(0x0000007fU));
    r_rsip_func101(bswap_32big(0x6769f4d9U),
                   bswap_32big(0x5d4de99dU),
                   bswap_32big(0xac6d61f4U),
                   bswap_32big(0xd089d15aU));
    r_rsip_func078(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x6276c35eU),
                   bswap_32big(0x94821ddeU),
                   bswap_32big(0xa27a582aU),
                   bswap_32big(0xaefec087U));
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x08080010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x08080010U);
    WR1_PROG(REG_1404H, 0x12a80000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa1afc716U),
                   bswap_32big(0x6991e5a4U),
                   bswap_32big(0xd00e479cU),
                   bswap_32big(0x252e77c1U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xf2a6afa5U),
                   bswap_32big(0x02c7230eU),
                   bswap_32big(0xa5456099U),
                   bswap_32big(0x06c82972U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xf58812baU),
                   bswap_32big(0xf9cd7b7fU),
                   bswap_32big(0x3e1f52d5U),
                   bswap_32big(0xa3153a5cU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x1601783cU),
                   bswap_32big(0x708483f5U),
                   bswap_32big(0x4f094e14U),
                   bswap_32big(0x295f6e31U));
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
    r_rsip_func100(bswap_32big(0x9dc2f74bU),
                   bswap_32big(0x5cb1222aU),
                   bswap_32big(0x05d199e4U),
                   bswap_32big(0x3e016d86U));
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
        r_rsip_func101(bswap_32big(0x00dc605fU), bswap_32big(0x627153c8U), bswap_32big(0x5b65731dU),
                       bswap_32big(0x24041e09U));
    }

    WR1_PROG(REG_1600H, 0x00007c03U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10c80000U);
    r_rsip_subfunc003(0x00c00049U);
    r_rsip_func100(bswap_32big(0x80b9218aU),
                   bswap_32big(0x1860bfa2U),
                   bswap_32big(0x146ece9fU),
                   bswap_32big(0x7dd514ecU));
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
        r_rsip_func100(bswap_32big(0xcd1a2c7fU), bswap_32big(0xf1316dd3U), bswap_32big(0xbba26c73U),
                       bswap_32big(0xde027519U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x09090009U);
            r_rsip_func101(bswap_32big(0xc94b03d8U), bswap_32big(0x097f67eaU), bswap_32big(0x7c7efbcaU),
                           bswap_32big(0xe4f35eb5U));
        }

        r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0909000cU);
        r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x09090009U);
        WR1_PROG(REG_1600H, 0x00003000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xb6994e9eU), bswap_32big(0x4d8b9846U), bswap_32big(0xd9f0cd03U),
                       bswap_32big(0xc2ef6f6cU));
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
    WR1_PROG(REG_1404H, 0x11600000U);
    r_rsip_subfunc003(0x00c000f1U);
    r_rsip_subfunc009(bswap_32big(0x0000007fU));
    r_rsip_func101(bswap_32big(0xa8d4047aU),
                   bswap_32big(0x02d8f3b0U),
                   bswap_32big(0x869a66adU),
                   bswap_32big(0xe3d16907U));
    r_rsip_func079(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000007fU));
    r_rsip_func101(bswap_32big(0xbcb6a304U),
                   bswap_32big(0xb98236f6U),
                   bswap_32big(0x0dd3c3ffU),
                   bswap_32big(0xb8ad6133U));
    r_rsip_func071();
    r_rsip_func100(bswap_32big(0x45f4086fU),
                   bswap_32big(0xd0b5bde6U),
                   bswap_32big(0xafecbeb5U),
                   bswap_32big(0xaa486590U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1be27940U), bswap_32big(0xe6428520U), bswap_32big(0xeb30a1f1U),
                       bswap_32big(0xa54f0212U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xdde92180U), bswap_32big(0x62fc0487U), bswap_32big(0x7e5a66a7U),
                       bswap_32big(0x42f6e111U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00007f01U));
        r_rsip_func101(bswap_32big(0xacb9c7deU), bswap_32big(0x2913ae76U), bswap_32big(0x37923118U),
                       bswap_32big(0x43a20ebaU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0130c80eU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00007f01U));
        r_rsip_func101(bswap_32big(0x62deab0eU), bswap_32big(0xeda26ff7U), bswap_32big(0x2e7bae79U),
                       bswap_32big(0x0a975f13U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xf706b39dU), bswap_32big(0x5afa9158U), bswap_32big(0xb1e004fbU),
                       bswap_32big(0x48021491U));
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

        r_rsip_func100(bswap_32big(0x33e8ea9eU), bswap_32big(0x1941fddcU), bswap_32big(0x924ee3edU),
                       bswap_32big(0x1cd3f3ddU));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe7008d05U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 7]);
        r_rsip_func100(bswap_32big(0x39a1fd1bU), bswap_32big(0x3c0b0511U), bswap_32big(0xadc9d09bU),
                       bswap_32big(0x4585d56cU));
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
        r_rsip_func100(bswap_32big(0xa2b7e31fU), bswap_32big(0x024fab86U), bswap_32big(0xf2b1d594U),
                       bswap_32big(0x1df1105eU));
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
        r_rsip_func100(bswap_32big(0x10161bb5U), bswap_32big(0xee710296U), bswap_32big(0x16c813beU),
                       bswap_32big(0x6975a0a5U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00007f02U));
        r_rsip_func101(bswap_32big(0x02a076bfU), bswap_32big(0x7ad28303U), bswap_32big(0xae2bf118U),
                       bswap_32big(0xaecf1a60U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x013986d4U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00007f02U));
        r_rsip_func101(bswap_32big(0x12b11bcbU), bswap_32big(0xbe02ad71U), bswap_32big(0x63ff2013U),
                       bswap_32big(0x7d3d3978U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x6d464c08U), bswap_32big(0x7f1a4cd7U), bswap_32big(0x273cabe1U),
                       bswap_32big(0xb1c780beU));
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

        r_rsip_func100(bswap_32big(0x1f9702ceU), bswap_32big(0xf9b18a98U), bswap_32big(0x4d0e5720U),
                       bswap_32big(0x7833c060U));
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

        r_rsip_func100(bswap_32big(0x00e96d02U), bswap_32big(0x878e01c6U), bswap_32big(0x6c26e08cU),
                       bswap_32big(0x53a7ff96U));
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
        r_rsip_func100(bswap_32big(0x5041aae0U), bswap_32big(0x82e02722U), bswap_32big(0xa6c46f99U),
                       bswap_32big(0xe385e5bcU));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[32]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[33]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[34]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[35]);
        r_rsip_func100(bswap_32big(0xb2ed376cU), bswap_32big(0x04a0340bU), bswap_32big(0x75671b15U),
                       bswap_32big(0xc00983e9U));
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
        r_rsip_func100(bswap_32big(0x08a45444U), bswap_32big(0xad8b1b4cU), bswap_32big(0x2e2cce83U),
                       bswap_32big(0x253aa583U));
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
        r_rsip_func102(bswap_32big(0x71e7931aU), bswap_32big(0xc47b89b2U), bswap_32big(0x44c46d82U),
                       bswap_32big(0x76c6775bU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
