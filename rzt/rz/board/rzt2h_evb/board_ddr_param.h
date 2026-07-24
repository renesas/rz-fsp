/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

// RZ/T2H, v3.0.0, L4.R2W32X16D16S32.ADEE-0

#ifndef BSP_DDR_PARAM_H
#define BSP_DDR_PARAM_H

#include <stdint.h>
#include "bsp_api.h"

#if (BSP_FEATURE_DDR_SUPPORTED)
 #if (1 == BSP_CFG_DDR_INIT_ENABLE)

extern const char     ddr_version_str[];
extern const uint32_t param_setup_mc[][2];
extern const uint32_t param_phyinit_c[][2];
extern const uint16_t param_phyinit_1d_dat1[];
extern const uint16_t param_phyinit_2d_dat1[];
extern const uint32_t param_phyinit_i[][2];
extern const uint16_t param_phyinit_1d_dat0[];
extern const uint16_t param_phyinit_2d_dat0[];
extern const uint32_t param_phyinit_swizzle[][2];

extern const uint32_t param_setup_mc_size;
extern const uint32_t param_phyinit_c_size;
extern const uint32_t param_phyinit_1d_dat1_size;
extern const uint32_t param_phyinit_2d_dat1_size;
extern const uint32_t param_phyinit_i_size;
extern const uint32_t param_phyinit_1d_dat0_size;
extern const uint32_t param_phyinit_2d_dat0_size;
extern const uint32_t param_phyinit_swizzle_size;

 #endif
#endif

#endif
