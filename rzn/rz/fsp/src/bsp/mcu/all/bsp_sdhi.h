/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_SDHI_H
#define BSP_SDHI_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
void bsp_sdhi_copy_multibyte(uint32_t             channel,
                             volatile uintptr_t * src,
                             volatile uintptr_t * dst,
                             volatile uintptr_t   bytesize);
void bsp_sdhi_copy_multibyte_8byte(uint32_t             channel,
                                   volatile uintptr_t * src,
                                   volatile uintptr_t * dst,
                                   volatile uintptr_t   bytesize);
void bsp_sdhi_emmc_media_init(void);
void bsp_sdhi_store_sdhi_register(void);
void bsp_sdhi_restore_sdhi_register(void);
void bsp_sdhi_init_uninitialized_vars(void);

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
