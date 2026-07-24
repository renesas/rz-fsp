/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

// RZ/T2N, v01.00, L4.R1W16X16D16S16.BDEE-0

#ifndef BSP_DDR_PARAM_H
#define BSP_DDR_PARAM_H

#include <stdint.h>
#include "bsp_api.h"

#if (BSP_FEATURE_DDR_SUPPORTED)
 #if (1 == BSP_CFG_DDR_INIT_ENABLE)

extern const char     ddr_version_str[];
extern const uint32_t param_setup_mc[][2];
extern const uint32_t param_dram_boot_clk_period;
extern const uint32_t param_dram_clk_period;
extern const uint8_t  param_phyinit_00;
extern const uint8_t  param_phyinit_01;
extern const uint8_t  param_phyinit_02;
extern const uint8_t  param_phyinit_03;
extern const uint8_t  param_phyinit_10;
extern const uint32_t param_phyinit_11;
extern const uint32_t param_phyinit_12;
extern const uint32_t param_phyinit_13;
extern const uint8_t  param_ddr_swizzle_ca[];
extern const uint8_t  param_ddr_swizzle_cs[];
extern const uint8_t  param_ddr_swizzle_bit[];
extern const uint8_t  param_ddr_swizzle_byte[];

extern const uint32_t param_setup_mc_size;

 #endif
#endif

#endif
