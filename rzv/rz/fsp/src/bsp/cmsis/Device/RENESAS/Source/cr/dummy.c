/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Dummy variable to avoid the following linker warning in GCC V12.
 *   "ld.exe: warning: <projectname>.elf has a LOAD segment with RWX permissions"
 * This variable will be referenced in the linker script.
 */
#if defined(__GNUC__)
BSP_DONT_REMOVE static const void * g_bsp_loader_dummy_itcm BSP_PLACE_IN_SECTION(".loader_dummy_itcm");
BSP_DONT_REMOVE static const void * g_bsp_loader_dummy_sram BSP_PLACE_IN_SECTION(".loader_dummy_sram");

#endif
