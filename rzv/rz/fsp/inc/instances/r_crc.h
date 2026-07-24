/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_CRC_H
 #define R_CRC_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_crc_cfg.h"
 #include "r_crc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZV
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_CRC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Driver extend config structure. */
struct st_crc_extended_cfg
{
    crc_snoop_direction_t snoop_direction; // CRC snoop mode direction
};

/** Driver extend config structure. Please refer to the struct st_crc_extended_cfg. */
typedef struct st_crc_extended_cfg crc_extended_cfg_t;

/** Driver instance control structure. */
struct st_crc_instance_ctrl
{
    uint32_t          open;
    const crc_cfg_t * p_cfg;           // Pointer to initial configurations
};

/** Driver instance control structure. Please refer to the struct st_crc_instance_ctrl. */
typedef struct st_crc_instance_ctrl crc_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const crc_api_t g_crc_on_crc;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_CRC_Open(crc_ctrl_t * const p_ctrl, crc_cfg_t const * const p_cfg);
fsp_err_t R_CRC_Close(crc_ctrl_t * const p_ctrl);
fsp_err_t R_CRC_Calculate(crc_ctrl_t * const p_ctrl, crc_input_t * const p_crc_input, uint32_t * calculatedValue);
fsp_err_t R_CRC_CalculatedValueGet(crc_ctrl_t * const p_ctrl, uint32_t * calculatedValue);
fsp_err_t R_CRC_SnoopEnable(crc_ctrl_t * const p_ctrl, uint32_t crc_seed);
fsp_err_t R_CRC_SnoopDisable(crc_ctrl_t * const p_ctrl);

/*******************************************************************************************************************//**
 * @} (end defgroup CRC)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
