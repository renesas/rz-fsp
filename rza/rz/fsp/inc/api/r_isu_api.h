/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup RENESAS_GRAPHICS_INTERFACES
 * @defgroup IMAGE_SCALING_API Image Scaling Interface
 * @brief Interface for image scaling.
 *
 * @section IMAGE_SCALING_API_SUMMARY Summary
 * The Image Scaling interface provides a general API for configuring and controlling image scaling.
 *
 *
 * @{
 **********************************************************************************************************************/

#ifndef FSP_INC_API_R_ISU_API_H_
#define FSP_INC_API_R_ISU_API_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Includes board and MCU related header files. */
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Image Scaling module state */
typedef enum e_isu_state
{
    ISU_STATE_IDLE  = 0,               ///< Image Scaling is idle
    ISU_IN_PROGRESS = 1,               ///< Image Scaling in progress
    ISU_STATE_BUSY  = 2,               ///< Image Scaling reset in progress
} isu_state_t;

/** Color format setting */
typedef enum e_isu_color_format
{
    ISU_COLOR_FORMAT_RGB565        = 0,  ///< RGB565
    ISU_COLOR_FORMAT_RGB888        = 1,  ///< RGB888
    ISU_COLOR_FORMAT_BGR888        = 2,  ///< BGR888
    ISU_COLOR_FORMAT_ARGB8888      = 3,  ///< ARGB8888
    ISU_COLOR_FORMAT_RGBA8888      = 4,  ///< RGBA8888
    ISU_COLOR_FORMAT_ABGR8888      = 5,  ///< ABGR888
    ISU_COLOR_FORMAT_YCBCR422_UYVY = 6,  ///< YCbCr422 UYVY
    ISU_COLOR_FORMAT_YCBCR422_YUY2 = 7,  ///< YCbCr422 YUY2
    ISU_COLOR_FORMAT_YCBCR422_NV16 = 8,  ///< YCbCr422 NV16
    ISU_COLOR_FORMAT_YCBCR420_NV12 = 9,  ///< YCbCR420 NV12
    ISU_COLOR_FORMAT_RAW8          = 10, ///< RAW8
    ISU_COLOR_FORMAT_RAW10         = 11, ///< RAW10
    ISU_COLOR_FORMAT_RAW12         = 12, ///< RAW12
} isu_color_format_t;

/** Data swap setting */
typedef enum e_isu_data_swap
{
    ISU_DATA_SWAP_8BIT  = 1,           ///< 8 bit data swap setting
    ISU_DATA_SWAP_16BIT = 2,           ///< 16bit data swap setting
    ISU_DATA_SWAP_32BIT = 4,           ///< 32bit data swap setting
} isu_data_swap_t;

/** Image Scaling status */
typedef struct e_isu_status
{
    isu_state_t state;                 ///< status of scaling module
} isu_status_t;

/** Scaling callback function parameter data */
typedef struct st_isu_callback_args
{
    void * p_context;                  ///< Placeholder for user data.
} isu_callback_args_t;

/** Image Scaling configuration */
typedef struct st_isu_buffer_cfg
{
    uint32_t           hsize;          ///< Horizontal size
    uint32_t           vsize;          ///< Vertical size
    uint32_t           hstride;        ///< memory stride
    isu_color_format_t format;         ///< color format
    isu_data_swap_t    data_swap;      ///< data swap setting
    uint32_t         * p_base;         ///< base address for plane0
    uint32_t         * p_base_cbcr;    ///< base address for plane1(for Cb and Cr component)
} isu_buffer_cfg_t;

/** ISU configuration parameters */
typedef struct st_isu_cfg
{
    isu_buffer_cfg_t input;                            ///< input configuration
    isu_buffer_cfg_t output;                           ///< output configuration
    void (* p_callback)(isu_callback_args_t * p_args); ///< Callback provided when a image conversion ISR occurs.
    void       * p_context;
    void const * p_extend;                             ///< Placeholder for user data.
} isu_cfg_t;

/** ISU runtime configuration parameters */
typedef struct st_isu_runtime_cfg
{
    isu_buffer_cfg_t input;            ///< input configuration
    isu_buffer_cfg_t output;           ///< output configuration
} isu_runtime_cfg_t;

/** Image Scaling control block */
typedef void isu_ctrl_t;

/** Shared Interface definition for image scaling peripheral */
typedef struct st_isu_api
{
    /** Open scaling device.
     * @param[in,out]  p_ctrl        Pointer to scaling interface control block.
     * @param[in]      p_cfg         Pointer to scaling configuration structure.
     */
    fsp_err_t (* open)(isu_ctrl_t * const p_ctrl, isu_cfg_t const * const p_cfg);

    /** Close scaling device.
     * @param[in]     p_ctrl   Pointer to scaling interface control block.
     */
    fsp_err_t (* close)(isu_ctrl_t * const p_ctrl);

    /** Start image scaling.
     * @param[in]     p_ctrl   Pointer to scaling interface control block.
     */
    fsp_err_t (* start)(isu_ctrl_t * const p_ctrl);

    /** Change image scaling configuration.
     * @param[in]     p_ctrl   Pointer to scaling interface control block.
     */
    fsp_err_t (* changeCfg)(isu_ctrl_t * const p_ctrl, isu_runtime_cfg_t * const p_runtime_cfg);
} isu_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_isu_instance
{
    isu_ctrl_t      * p_ctrl;          ///< Pointer to the control structure for this instance
    isu_cfg_t const * p_cfg;           ///< Pointer to the configuration structure for this instance
    isu_api_t const * p_api;           ///< Pointer to the API structure for this instance
} isu_instance_t;

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /* FSP_INC_API_R_ISU_API_H_ */

/*******************************************************************************************************************//**
 * @} (end defgroup ISU_API)
 **********************************************************************************************************************/
