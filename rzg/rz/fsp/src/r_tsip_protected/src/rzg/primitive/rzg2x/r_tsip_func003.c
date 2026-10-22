/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"
#include "r_tsip_reg.h"
#include "r_tsip_util.h"

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

TSIP_PRV_PRIMITIVE_FUNC

void r_tsip_func003 (uint32_t * ARG1)
{
    uint32_t iLoop;
    uint32_t iLoop2;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t oLoop2;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) iLoop2;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) oLoop2;
    (void) OFS_ADR;
    WR1_PROG(REG_0028H, 0x00870001U);
    OFS_ADR = 128;
    r_tsip_func100(0xe93840abU, 0xf3b650f4U, 0xa2389ce2U, 0xb656695cU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x000001f0U);
    WR1_PROG(REG_00C4H, 0x00090805U);
    WR1_PROG(REG_00E0H, 0x8184001eU);
    WR1_PROG(REG_0000H, 0x00002813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x013affabU, 0xe813df5cU, 0x3d1bde91U, 0xc7c270baU);
    r_tsip_func004(OFS_ADR);
    WR1_PROG(REG_0024H, 0x0000dcd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000403U);
    WR1_PROG(REG_0024H, 0x8000e8d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000084d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00029008U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x8000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000010U);
    WR1_PROG(REG_0024H, 0x80005cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000003U);
    WR1_PROG(REG_0024H, 0x80008cd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000880cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x800050d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x800088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x800094d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000880cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000800U);
    WR1_PROG(REG_0024H, 0x800070d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000802U);
    WR1_PROG(REG_0024H, 0x8000acd0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010360U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x000000f0U));
    r_tsip_func101(0xb5203e4aU, 0x5aef5dc4U, 0xc1a82be8U, 0x9e07dfa2U);
    r_tsip_func006();
    r_tsip_func100(0x9875fa82U, 0xa23a52ffU, 0x038dd12eU, 0x2c4d3e6dU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_00ECH, 0x00000800U);
        r_tsip_func101(0x76bcf09dU, 0x416fbd40U, 0x6e6dcd69U, 0x78848a57U);
    }
    else
    {
        r_tsip_func100(0xd534a9e6U, 0x551c9003U, 0x2caf9648U, 0x4a3a2adeU);
        WR1_PROG(REG_0024H, 0x00009cd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0018H, 0x00000004U);
        WR1_PROG(REG_0038H, 0x000000b0U);
        WAIT_STS(REG_0018H, 10U, 0U);
        WR1_PROG(REG_0018H, 0x00000000U);
        WR1_PROG(REG_0034H, 0x00000010U);
        WR1_PROG(REG_0024H, 0x80005cd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000880cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a8d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000008U);
        WR1_PROG(REG_0024H, 0x800050d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00004a0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000480cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000480cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00004a0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000008U);
        WR1_PROG(REG_0024H, 0x800074d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00006e0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00006c0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00006c0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00006c0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00006e0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00006e0cU);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_00ECH, 0x0000b7e0U);
        WR1_PROG(REG_00ECH, 0x00000020U);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x000000aaU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000027dfU);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x000000abU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000027dfU);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x000000a8U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000027dfU);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x000000a9U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000027dfU);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x0000002aU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000027dfU);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x0000002bU);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x000027dfU);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000022U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_00ECH, 0x0000a7c0U);
        WR1_PROG(REG_00ECH, 0x00000020U);
        WR1_PROG(REG_00E0H, 0x8088001eU);
        WR1_PROG(REG_0000H, 0x00008323U);
        WR1_PROG(REG_002CH, 0x00000023U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        r_tsip_func100(0x093e2320U, 0xd73079ebU, 0xc902c098U, 0x862c25f4U);
        r_tsip_func004(OFS_ADR);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000dcd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000e0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000403U);
        WR1_PROG(REG_0024H, 0x8000e8d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000002U);
        WR1_PROG(REG_0024H, 0x800048d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000c00U);
        WR1_PROG(REG_0024H, 0x800058d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000c20U);
        WR1_PROG(REG_0024H, 0x8000bcd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0000H, 0x00003523U);
        WR1_PROG(REG_0074H, 0x00000008U);
        WR1_PROG(REG_002CH, 0x00000094U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x0000001dU);
        WR1_PROG(REG_0104H, 0x00000767U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &ARG1[0]);
        WR1_ADDR(REG_0100H, &ARG1[1]);
        WR1_ADDR(REG_0100H, &ARG1[2]);
        WR1_ADDR(REG_0100H, &ARG1[3]);
        WR1_ADDR(REG_0100H, &ARG1[4]);
        WR1_ADDR(REG_0100H, &ARG1[5]);
        WR1_ADDR(REG_0100H, &ARG1[6]);
        WR1_ADDR(REG_0100H, &ARG1[7]);
        WR1_PROG(REG_002CH, 0x00000010U);
        WR1_PROG(REG_0104H, 0x00000767U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_ADDR(REG_0100H, &ARG1[8]);
        WR1_ADDR(REG_0100H, &ARG1[9]);
        WR1_ADDR(REG_0100H, &ARG1[10]);
        WR1_ADDR(REG_0100H, &ARG1[11]);
        WR1_ADDR(REG_0100H, &ARG1[12]);
        WR1_ADDR(REG_0100H, &ARG1[13]);
        WR1_ADDR(REG_0100H, &ARG1[14]);
        WR1_ADDR(REG_0100H, &ARG1[15]);
        WR1_PROG(REG_0024H, 0x0000dcd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000a4d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0002b208U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000800U);
        WR1_PROG(REG_0024H, 0x8000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000020U);
        WR1_PROG(REG_0024H, 0x80007cd0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000d91U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        WR1_PROG(REG_0034H, 0x00000020U);
        WR1_PROG(REG_0024H, 0x80001dc0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000591U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00001f00U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x483c5310U, 0x2e78ee7bU, 0xd674b998U, 0xfe370712U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_00ECH, 0x00000800U);
            r_tsip_func101(0x4445161dU, 0xf812a1faU, 0xf3883587U, 0xe82ac47bU);
        }
        else
        {
            WR1_PROG(REG_0034H, 0x00000c20U);
            WR1_PROG(REG_0024H, 0x8000fcd0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000800U);
            WR1_PROG(REG_0024H, 0x800048d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func100(0x4137985eU, 0x17f6d37dU, 0x25ff2a48U, 0x3114acbeU);
            r_tsip_func009();
            r_tsip_func100(0x6bbacabaU, 0x4e5bf69bU, 0xf947ece1U, 0x2a33de0eU);
            WR1_PROG(REG_0034H, 0x00000410U);
            WR1_PROG(REG_0024H, 0x800098d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func005(OFS_ADR);
            r_tsip_func100(0x67efc283U, 0x5edc5727U, 0x07872500U, 0x0af94e92U);
            WR1_PROG(REG_0034H, 0x00000110U);
            WR1_PROG(REG_0024H, 0x800019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000110U);
            WR1_PROG(REG_0024H, 0x80001ec0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000330U);
            WR1_PROG(REG_0024H, 0x800019c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000330U);
            WR1_PROG(REG_0024H, 0x80001ec0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            r_tsip_func007();
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x8000f0d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000008U);
            WR1_PROG(REG_0024H, 0x800050d0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0018H, 0x00000004U);
            WR1_PROG(REG_0038H, 0x00231030U);
            WAIT_STS(REG_0018H, 10U, 0U);
            WR1_PROG(REG_0018H, 0x00000000U);
            WR1_PROG(REG_0024H, 0x00001dc0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x00000591U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_001CH, 0x00001f00U);
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xdfae157fU, 0x9dfec9bfU, 0x559511bfU, 0x9ec35aa2U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_00ECH, 0x00000800U);
                r_tsip_func101(0x599fe8eeU, 0x8ab259e7U, 0x452ed267U, 0x50643dcbU);
            }
            else
            {
                WR1_PROG(REG_0024H, 0x0000bcd0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000b20cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000054d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x00000908U);
                WR1_PROG(REG_00ECH, 0x0000b500U);
                WR1_PROG(REG_00ECH, 0x00000060U);
                WR1_PROG(REG_00E0H, 0x81880008U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000010U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_00ECH, 0x00000908U);
                WR1_PROG(REG_00E0H, 0x81880008U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000013U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0024H, 0x00008c0cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0000880cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000008U);
                WR1_PROG(REG_0024H, 0x800011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00001191U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000019a1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00009008U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x0000b500U);
                WR1_PROG(REG_00ECH, 0x00000020U);
                WR1_PROG(REG_00E0H, 0x81880008U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000014U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0024H, 0x0000a4d0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x0002b208U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000800U);
                WR1_PROG(REG_0024H, 0x8000c0c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_00ECH, 0x0000b500U);
                WR1_PROG(REG_00ECH, 0x00000040U);
                WR1_PROG(REG_00E0H, 0x81880008U);
                WR1_PROG(REG_0000H, 0x00003823U);
                WR1_PROG(REG_002CH, 0x00000012U);
                WAIT_STS(REG_0000H, 25U, 0U);
                WR1_PROG(REG_001CH, 0x00001800U);
                WR1_PROG(REG_0024H, 0x0000880cU);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x00000591U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_001CH, 0x00001f00U);
                WR1_PROG(REG_001CH, 0x00a10000U);
                r_tsip_func100(0xddc854c4U, 0xd5238369U, 0xf6c3f1c3U, 0x2f34c6c2U);
                WR1_PROG(REG_001CH, 0x00400000U);
                WR1_PROG(REG_01D0H, 0x00000000U);
                if (CHCK_STS(REG_001CH, 22U, 1U))
                {
                    WR1_PROG(REG_00ECH, 0x00000800U);
                    r_tsip_func101(0xaff4c775U, 0xbab529fdU, 0x2d1112cdU, 0x9bbd3945U);
                }
                else
                {
                    WR1_PROG(REG_00ECH, 0x0000d000U);
                    r_tsip_func101(0xa3dcbe82U, 0x86c9e693U, 0xac725334U, 0x3c045e23U);
                }
            }
        }
    }

    WR1_PROG(REG_00ECH, 0x38000c00U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_00ECH, 0x00007c1dU);
    WR1_PROG(REG_001CH, 0x00602000U);
}
