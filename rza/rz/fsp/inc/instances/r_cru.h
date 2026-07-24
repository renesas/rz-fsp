/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef FSP_INC_INSTANCES_R_CRU_H_
 #define FSP_INC_INSTANCES_R_CRU_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "r_cru_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

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
 * @addtogroup RZA_CRU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** CRU color format setting */
typedef enum e_color_input_format
{
    CRU_COLOR_INPUT_FORMAT_YUV420_8BIT  = 0, ///< YUV420 8bit
    CRU_COLOR_INPUT_FORMAT_YUV420_10BIT = 1, ///< YUV420 10bit
    CRU_COLOR_INPUT_FORMAT_YUV422_8BIT  = 2, ///< YUV422 8bit
    CRU_COLOR_INPUT_FORMAT_YUV422_10BIT = 3, ///< YUV422 10bit
    CRU_COLOR_INPUT_FORMAT_RGB565       = 4, ///< RGB565
    CRU_COLOR_INPUT_FORMAT_RGB888       = 5, ///< RGB888
    CRU_COLOR_INPUT_FORMAT_RAW8         = 6, ///< RAW8
    CRU_COLOR_INPUT_FORMAT_RAW10        = 7, ///< RAW10
    CRU_COLOR_INPUT_FORMAT_RAW12        = 8, ///< RAW12
    CRU_COLOR_INPUT_FORMAT_RAW14        = 9, ///< RAW14
} cru_color_input_format_t;

/** Color order setting */
typedef enum e_color_output_format
{
    CRU_COLOR_OUTPUT_FORMAT_YUV420_YUYV  = 0, ///< YUV420 YUYV
    CRU_COLOR_OUTPUT_FORMAT_YUV420_UYVY  = 1, ///< YUV420 UYVY
    CRU_COLOR_OUTPUT_FORMAT_YUV422_YUYV  = 2, ///< YUV422 YUYV
    CRU_COLOR_OUTPUT_FORMAT_YUV422_UYVY  = 3, ///< YUV422 UYVY
    CRU_COLOR_OUTPUT_FORMAT_RGB888_24BIT = 4, ///< RGB888 24BIT
    CRU_COLOR_OUTPUT_FORMAT_RGB888_32BIT = 5, ///< RGB888 32BIT (Upper 8bit is 0x00)
    CRU_COLOR_OUTPUT_FORMAT_ARGB8888     = 6, ///< ARGB8888
    CRU_COLOR_OUTPUT_FORMAT_BGRA8888     = 7, ///< BGRA888
} cru_color_output_format_t;

/* Used datalane */
typedef enum e_cru_datalane
{
    CRU_DATALANE_1 = 1,                ///< use one datalane
    CRU_DATALANE_2 = 2,                ///< use two datalane
    CRU_DATALANE_4 = 4                 ///< use four datalane
} cru_datalane_t;

/** CRU interrupt enable */
typedef enum e_cru_interrupt_enable
{
    CRU_INTERRUPT_ENABLE_FRAME_START = 0x001U,
    CRU_INTERRUPT_ENABLE_FRAME_END   = 0x002U,
    CRU_INTERRUPT_ENABLE_SCAN_LINE   = 0x004U
} cru_interrupt_enable_t;

/** CRU events table for image conv int */
typedef enum e_cru_event_image_conv_int
{
    CRU_EVENT_FRAME_START = 0x0001,    ///< Interrupt for Frame Start
    CRU_EVENT_FRAME_END   = 0x0002,    ///< Interrupt for Frame End
    CRU_EVENT_SCAN_LINE   = 0x0004,    ///< Interrupt for Scan Line
} cru_event_image_conv_int_t;

/** Statistics configuration parameters */
struct st_cru_statsistics_cfg
{
    uint8_t   statistics;              ///< Setting for Statistics processing (0: execute, 1:through)
    uint8_t * pp_buffer[8];            ///< Pointer to array of buffer pointers
    uint8_t   num_buffers;             ///< Number of buffers to use
    uint8_t   stunit;                  ///< Selection of processing units for statistics processing(0-3)
    ///< (0:16x16, 1:32x32, 2:64x64, 3:128x128)
    uint8_t  stsadpos;                 ///< Input data bit position selection for adjacent pixel absolute value summation (0-8)
    uint16_t sthpos;                   ///< horizontal start position for statistics processing (0-376)
};

/** Statistics configuration parameters. Please refer to the struct st_cru_statsistics_cfg. */
typedef struct st_cru_statsistics_cfg statistics_cfg_t;

/** LenearMatrix configuration parameters */
struct st_cru_linearmatrix_cfg
{
    uint8_t linearmatrix;              ///< Setting for Linear matrix processing (0: execute, 1:through)
    int8_t  rof;                       ///< R offset value -128(8'h80)～127(8'h7F)
    int8_t  gof;                       ///< G offset value -128(8'h80)～127(8'h7F)
    int8_t  bof;                       ///< B offset value -128(8'h80)～127(8'h7F)
    int16_t rr;                        ///< Coefficient R of R data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t rg;                        ///< Coefficient G of R data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t rb;                        ///< Coefficient B of R data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t gr;                        ///< Coefficient R of G data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t gg;                        ///< Coefficient G of G data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t gb;                        ///< Coefficient B of G data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t br;                        ///< Coefficient R of B data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t bg;                        ///< Coefficient G of B data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
    int16_t bb;                        ///< Coefficient B of B data for Linear Matrix calculation (-4096(13'h1000)～4095(13'h0FFF))
};

/** LenearMatrix configuration parameters. Please refer to the struct st_cru_linearmatrix_cfg. */
typedef struct st_cru_linearmatrix_cfg linearmatrix_cfg_t;

/** CRU hardware specific configuration */
struct st_cru_extended_cfg
{
    cru_datalane_t            num_datalane;     ///< select number of datalane
    cru_color_input_format_t  color_input;      ///< input color format
    cru_color_output_format_t color_output;     ///< output color format
    cru_interrupt_enable_t    interrupt_enable; ///< Interrupt enable table
    uint16_t  scan_line_num;                    ///< Line specification for generating a scan line interrupt
    uint8_t   image_conv_int_ipl;               ///< Image conversion interrupt priority
    IRQn_Type image_conv_int_irq;               ///< Image conversion IRQ number

    statistics_cfg_t   statistics_cfg;          ///< Statistics Configuration
    linearmatrix_cfg_t linearmatrix_cfg;        ///< LinearMatrix Configuration
    uint8_t            rgb_bit_extension;       ///< Settings when RGB bit is extended (8bit/10bit -> 12bit)
    ///< 0: Lower 4bits/2bits are expanded repeatedly from the highest 4bits/2bits
    ///< 1: Lower 4bits/2bits are filled with zeros
    uint8_t rawstarttype;                       ///< Specify the type of the 1st pixel of the 1st line of RAW data
    ///< 0: R (RGRG...), 1: Gr (GRGR...), 2: Gb (GBGB...), 3: B (BGBG...)
    uint32_t t_init;                            /// timing parameter, register of CSIDPHYTIM0
    uint32_t tclk_miss;                         /// timing parameter, register of CSIDPHYTIM0
    uint32_t tclk_settle;                       /// timing parameter, register of CSIDPHYTIM1
    uint32_t ths_settle;                        /// timing parameter, register of CSIDPHYTIM1
    uint32_t tclk_prepare;                      /// timing parameter, register of CSIDPHYTIM1
    uint32_t ths_prepare;                       /// timing parameter, register of CSIDPHYTIM1
};

/** CRU hardware specific configuration. Please refer to the struct st_cru_extended_cfg. */
typedef struct st_cru_extended_cfg cru_extended_cfg_t;

/** CRU instance control block. */
struct st_cru_instance_ctrl
{
    camera_state_t    state;                                           /// Status of LCDC module
    cru_cfg_t const * p_cfg;                                           ///< Pointer to the configuration structure
    uint8_t           capture_num;                                     ///< The buffer number currently used by CRU
    void            * p_context;                                       ///< Placeholder for user data.  Passed to the user callback.
    void              (* p_callback)(camera_callback_args_t * p_args); ///< Callback provided when a image conversion ISR occurs.
};

/** CRU instance control block. Please refer to the struct st_cru_instance_ctrl. */
typedef struct st_cru_instance_ctrl cru_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern const cru_api_t g_cru_on_cru;

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_CRU_Open(cru_ctrl_t * const p_api_ctrl, cru_cfg_t const * const p_cfg);
fsp_err_t R_CRU_Close(cru_ctrl_t * const p_api_ctrl);
fsp_err_t R_CRU_CaptureStart(cru_ctrl_t * const p_api_ctrl);
fsp_err_t R_CRU_CaptureStop(cru_ctrl_t * const p_api_ctrl);
fsp_err_t R_CRU_StatusGet(cru_ctrl_t * const p_api_ctrl, camera_status_t * p_status);

/*******************************************************************************************************************//**
 * @} (end defgroup CRU)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */

FSP_FOOTER
#endif                                 /* FSP_INC_INSTANCES_R_CRU_H_ */
