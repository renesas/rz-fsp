/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef FSP_INC_INSTANCES_R_ISU_H_
 #define FSP_INC_INSTANCES_R_ISU_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

 #include "r_isu_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZA
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_ISU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Image scaling control block.  DO NOT INITIALIZE. */
/** ISU hardware specific configuration */
struct st_isu_extended_cfg
{
    uint8_t   isu_frame_end_ipl;       ///< Image conversion interrupt priority
    IRQn_Type isu_frame_end_irq;       ///< Image conversion IRQ number
};

/** ISU hardware specific configuration. Please refer to the struct st_isu_extended_cfg. */
typedef struct st_isu_extended_cfg isu_extended_cfg_t;

/** ISU instance  */
struct st_isu_instance_ctrl
{
    isu_state_t state;                                              // Status of ISU module

    /* Parameters to Event processing for scaling devices */
    void              (* p_callback)(isu_callback_args_t * p_args); // Pointer to callback function
    void            * p_context;                                    // Pointer to the higher level device context
    const isu_cfg_t * p_cfg;                                        // Pointer to initial configurations
};

/** ISU instance. Please refer to the struct st_isu_instance_ctrl. */
typedef struct st_isu_instance_ctrl isu_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern const isu_api_t g_isu_on_isu;

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_ISU_Open(isu_ctrl_t * const p_api_ctrl, isu_cfg_t const * const p_cfg);
fsp_err_t R_ISU_Close(isu_ctrl_t * const p_api_ctrl);
fsp_err_t R_ISU_Start(isu_ctrl_t * const p_api_ctrl);
fsp_err_t R_ISU_ChangeCfg(isu_ctrl_t * const p_api_ctrl, isu_runtime_cfg_t * const p_runtime_cfg);

/*******************************************************************************************************************//**
 * @} (end defgroup ISU)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER
#endif                                 /* FSP_INC_INSTANCES_R_ISU_H_ */
