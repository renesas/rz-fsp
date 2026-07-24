/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

#if !(BSP_CFG_RAM_EXECUTION) && (BSP_CFG_USE_LOADER_PARAMETER)
 #if (1 == _RZ_ORDINAL)

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
  #define BSP_LOADER_PARAM_MAX     (19)

  #if BSP_CFG_ESD_BOOT
   #define BSP_LOADER_ALIGNMENT    (512)
  #endif

/* Loader parameter values. */
  #define BSP_LOADER_PARAM_VALUE  \
    BSP_CFG_CACHE_FLG,            \
    BSP_CFG_WRAPCFG_V_DUMMY0,     \
    BSP_CFG_COMCFG_V_DUMMY1,      \
    BSP_CFG_BMCFG_V_DUMMY2,       \
    BSP_CFG_RESTORE_FLG,          \
    BSP_CFG_LDR_ADDR_NML,         \
    BSP_CFG_LDR_SIZE_NML,         \
    BSP_CFG_DEST_ADDR_NML,        \
    BSP_CFG_DUMMY3,               \
    BSP_CFG_DUMMY4,               \
    BSP_CFG_CS0_SIZE_DUMMY5,      \
    BSP_CFG_LIOCFGCS0_V_DUMMY6,   \
    BSP_CFG_PLL0_SSC_CTR_V,       \
    BSP_CFG_BOOTCPU_FLG,          \
    BSP_CFG_DUMMY7,               \
    BSP_CFG_DUMMY8,               \
    BSP_CFG_DUMMY9,               \
    BSP_CFG_ACCESS_SPEED_DUMMY10, \
    BSP_CFG_CHECK_SUM

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* Parameter Information for the Loader. */
  #if BSP_CFG_ESD_BOOT
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param[BSP_LOADER_PARAM_MAX] BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
  #else
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param[BSP_LOADER_PARAM_MAX] BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM) =
  #endif
{
    BSP_LOADER_PARAM_VALUE
};

  #if BSP_CFG_ESD_BOOT
   #define BSP_SECTION_LOADER_PARAM_SPARE_1    ".loader_param_spare1"
   #define BSP_SECTION_LOADER_PARAM_SPARE_2    ".loader_param_spare2"
   #define BSP_SECTION_LOADER_PARAM_SPARE_3    ".loader_param_spare3"
   #define BSP_SECTION_LOADER_PARAM_SPARE_4    ".loader_param_spare4"
   #define BSP_SECTION_LOADER_PARAM_SPARE_5    ".loader_param_spare5"
   #define BSP_SECTION_LOADER_PARAM_SPARE_6    ".loader_param_spare6"

/* Parameter Information for the Loader (Loader program #1 (spare)). */
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param_spare_1[BSP_LOADER_PARAM_MAX]
BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM_SPARE_1)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
{
    BSP_LOADER_PARAM_VALUE
};

/* Parameter Information for the Loader (Loader program #2 (spare)). */
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param_spare_2[BSP_LOADER_PARAM_MAX]
BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM_SPARE_2)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
{
    BSP_LOADER_PARAM_VALUE
};

/* Parameter Information for the Loader (Loader program #3 (spare)). */
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param_spare_3[BSP_LOADER_PARAM_MAX]
BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM_SPARE_3)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
{
    BSP_LOADER_PARAM_VALUE
};

/* Parameter Information for the Loader (Loader program #4 (spare)). */
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param_spare_4[BSP_LOADER_PARAM_MAX]
BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM_SPARE_4)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
{
    BSP_LOADER_PARAM_VALUE
};

/* Parameter Information for the Loader (Loader program #5 (spare)). */
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param_spare_5[BSP_LOADER_PARAM_MAX]
BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM_SPARE_5)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
{
    BSP_LOADER_PARAM_VALUE
};

/* Parameter Information for the Loader (Loader program #6 (spare)). */
BSP_DONT_REMOVE const uint32_t g_bsp_loader_param_spare_6[BSP_LOADER_PARAM_MAX]
BSP_PLACE_IN_SECTION(BSP_SECTION_LOADER_PARAM_SPARE_6)
BSP_ALIGN_VARIABLE(BSP_LOADER_ALIGNMENT) =
{
    BSP_LOADER_PARAM_VALUE
};
  #endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

 #endif
#endif
