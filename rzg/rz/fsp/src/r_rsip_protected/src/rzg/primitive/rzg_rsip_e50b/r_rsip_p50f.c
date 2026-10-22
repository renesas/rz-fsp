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

rsip_ret_t r_rsip_p50f (void)
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
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0xe3e27afeU), bswap_32big(0x5bfc39c9U), bswap_32big(0xdac9979fU),
                       bswap_32big(0xf4cc67ccU));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0xac6e854eU), bswap_32big(0xc2e6d91bU), bswap_32big(0x53df52d4U),
                       bswap_32big(0x11193e26U));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0xeda47ea8U), bswap_32big(0x2f250046U), bswap_32big(0x7a23f002U),
                       bswap_32big(0xca1cfa6cU));
    }
    else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0xd15bcfbbU), bswap_32big(0x818172e3U), bswap_32big(0x89fdc7c4U),
                       bswap_32big(0x069158bdU));
    }
    else if (0x00000004U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func101(bswap_32big(0x762583f0U), bswap_32big(0xba590f46U), bswap_32big(0xd0e3f7d0U),
                       bswap_32big(0x48ec8a0eU));
    }

    r_rsip_func102(bswap_32big(0x51d13b11U),
                   bswap_32big(0x61891a7dU),
                   bswap_32big(0xcdf46b82U),
                   bswap_32big(0x3d0576c7U));
    WR1_PROG(REG_14BCH, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
