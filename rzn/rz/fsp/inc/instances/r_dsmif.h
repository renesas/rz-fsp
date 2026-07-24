/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_DSMIF_H
 #define R_DSMIF_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_dsmif_cfg.h"
 #include "r_adc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

 #define DSMIF_MAX_NUM_CHANNELS    (3U)

 #define DSMIF_STOP_TIMEOUT        (0x000FFFFFU)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_DSMIF
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Select the channel(s) for overcurrent sum error detection. */
typedef enum e_dsmif_sum_err_detect_channel
{
    DSMIF_SUM_ERR_DETECT_CHANNEL_0_2 = 0, ///< Detects error of sum value of overcurrent data of CH0, CH1, CH2
    DSMIF_SUM_ERR_DETECT_CHANNEL_0_1 = 1, ///< Detects error of sum value of overcurrent data of CH0, CH1
    DSMIF_SUM_ERR_DETECT_CHANNEL_0   = 2, ///< Detects error of overcurrent data of CH0
    DSMIF_SUM_ERR_DETECT_CHANNEL_1   = 3, ///< Detects error of overcurrent data of CH1
    DSMIF_SUM_ERR_DETECT_CHANNEL_2   = 4, ///< Detects error of overcurrent data of CH2
} dsmif_sum_err_detect_channel_t;

/** Select if the DSMIF Measurement Clock Control is an input or output. */
typedef enum e_dsmif_clock_ctrl
{
    DSMIF_CLOCK_CTRL_SLAVE  = 0,       ///< MCLKn pin is input (slave operation)
    DSMIF_CLOCK_CTRL_MASTER = 1,       ///< MCLKn pin is output (master operation)
} dsmif_clock_ctrl_t;

/** Select the clock edge for sampling DSMIF data. */
typedef enum e_dsmif_clock_edge
{
    DSMIF_CLOCK_EDGE_NEGATIVE = 0,     ///< Capture MDATn at the negative edge of MCLKn
    DSMIF_CLOCK_EDGE_POSITIVE = 1,     ///< Capture MDATn at the positive edge of MCLKn
} dsmif_clock_edge_t;

/** Select the DSMIF master clock. */
typedef enum e_dsmif_master_clock
{
 #if 1U == BSP_FEATURE_DSMIF_MCLK_FREQ_TYPE
    DSMIF_MASTER_CLOCK_25MHZ_PCLKH200   = 3,   ///< Master clock 25MHz, PCLKH 200MHz
    DSMIF_MASTER_CLOCK_20MHZ_PCLKH200   = 4,   ///< Master clock 20MHz, PCLKH 200MHz
    DSMIF_MASTER_CLOCK_12_5MHZ_PCLKH200 = 7,   ///< Master clock 12.5MHz, PCLKH 200MHz
    DSMIF_MASTER_CLOCK_10MHZ_PCLKH200   = 9,   ///< Master clock 10MHz, PCLKH 200MHz
    DSMIF_MASTER_CLOCK_6_25MHZ_PCLKH200 = 15,  ///< Master clock 6.25MHz, PCLKH 200MHz
    DSMIF_MASTER_CLOCK_5MHZ_PCLKH200    = 19,  ///< Master clock 5MHz, PCLKH 200MHz

    DSMIF_MASTER_CLOCK_25MHZ_PCLKH150    = 2,  ///< Master clock 25MHz, PCLKH 150MHz
    DSMIF_MASTER_CLOCK_18_75MHZ_PCLKH150 = 3,  ///< Master clock 18.75MHz, PCLKH 150MHz
    DSMIF_MASTER_CLOCK_12_5MHZ_PCLKH150  = 5,  ///< Master clock 12.5MHz, PCLKH 150MHz
    DSMIF_MASTER_CLOCK_9_375MHZ_PCLKH150 = 7,  ///< Master clock 9.375MHz, PCLKH 150MHz
    DSMIF_MASTER_CLOCK_6_25MHZ_PCLKH150  = 11, ///< Master clock 6.25MHz, PCLKH 150MHz
    DSMIF_MASTER_CLOCK_5MHZ_PCLKH150     = 14, ///< Master clock 5MHz, PCLKH 150MHz
 #elif 2U == BSP_FEATURE_DSMIF_MCLK_FREQ_TYPE
    DSMIF_MASTER_CLOCK_25MHZ_CLK400   = 7,     ///< Master clock 25MHz, Core Clock 400MHz
    DSMIF_MASTER_CLOCK_20MHZ_CLK400   = 9,     ///< Master clock 20MHz, Core Clock 400MHz
    DSMIF_MASTER_CLOCK_12_5MHZ_CLK400 = 15,    ///< Master clock 12.5MHz, Core Clock 400MHz
    DSMIF_MASTER_CLOCK_10MHZ_CLK400   = 19,    ///< Master clock 10MHz, Core Clock 400MHz
    DSMIF_MASTER_CLOCK_6_25MHZ_CLK400 = 31,    ///< Master clock 6.25MHz, Core Clock 400MHz
    DSMIF_MASTER_CLOCK_5MHZ_CLK400    = 39,    ///< Master clock 5MHz, Core Clock 400MHz

    DSMIF_MASTER_CLOCK_25MHZ_CLK250   = 4,     ///< Master clock 25MHz, Core Clock 250MHz
    DSMIF_MASTER_CLOCK_20_8MHZ_CLK250 = 5,     ///< Master clock 20.8MHz, Core Clock 250MHz
    DSMIF_MASTER_CLOCK_12_5MHZ_CLK250 = 9,     ///< Master clock 12.5MHz, Core Clock 250MHz
    DSMIF_MASTER_CLOCK_10_4MHZ_CLK250 = 11,    ///< Master clock 10.4MHz, Core Clock 250MHz
    DSMIF_MASTER_CLOCK_6_25MHZ_CLK250 = 19,    ///< Master clock 6.25MHz, Core Clock 250MHz
    DSMIF_MASTER_CLOCK_5MHZ_CLK250    = 24,    ///< Master clock 5MHz, Core Clock 250MHz
 #endif
} dsmif_master_clock_t;

 #if 1U == BSP_FEATURE_DSMIF_CORE_CLOCK_SELECTABLE

/** Select the DSMIF core clock. */
typedef enum e_dsmif_core_clock_select
{
    DSMIF_CORE_CLOCK_SELECT_250MHZ = 0, ///< Core Clock Selection 250MHz
    DSMIF_CORE_CLOCK_SELECT_400MHZ = 1, ///< Core Clock Selection 400MHz
} dsmif_core_clock_select_t;
 #endif

/** Select the DSMIF filter order. */
typedef enum e_dsmif_filter_order
{
    DSMIF_FILTER_ORDER_3RD = 0,        ///< Overcurrent detection filter order setting 3rd order
    DSMIF_FILTER_ORDER_1ST = 1,        ///< Overcurrent detection filter order setting 1st order
    DSMIF_FILTER_ORDER_2ND = 2,        ///< Overcurrent detection filter order setting 2nd order
} dsmif_filter_order_t;

/** Select the [MSB,LSB] that are copied from the filter output into the data register.  */
typedef enum e_dsmif_data_shift
{
    DSMIF_DATA_SHIFT_23_8 = 0,         ///< Data shift setting for overcurrent detection [23:8]
    DSMIF_DATA_SHIFT_22_7 = 1,         ///< Data shift setting for overcurrent detection [22:7]
    DSMIF_DATA_SHIFT_21_6 = 2,         ///< Data shift setting for overcurrent detection [21:6]
    DSMIF_DATA_SHIFT_20_5 = 3,         ///< Data shift setting for overcurrent detection [20:5]
    DSMIF_DATA_SHIFT_19_4 = 4,         ///< Data shift setting for overcurrent detection [19:4]
    DSMIF_DATA_SHIFT_18_3 = 5,         ///< Data shift setting for overcurrent detection [18:3]
    DSMIF_DATA_SHIFT_17_2 = 6,         ///< Data shift setting for overcurrent detection [17:2]
    DSMIF_DATA_SHIFT_16_1 = 7,         ///< Data shift setting for overcurrent detection [16:1]
    DSMIF_DATA_SHIFT_15_0 = 8,         ///< Data shift setting for overcurrent detection [15:0]
    DSMIF_DATA_SHIFT_14_0 = 9,         ///< Data shift setting for overcurrent detection [14:0]
    DSMIF_DATA_SHIFT_13_0 = 10,        ///< Data shift setting for overcurrent detection [13:0]
    DSMIF_DATA_SHIFT_12_0 = 11,        ///< Data shift setting for overcurrent detection [12:0]
    DSMIF_DATA_SHIFT_11_0 = 12,        ///< Data shift setting for overcurrent detection [11:0]
    DSMIF_DATA_SHIFT_10_0 = 13,        ///< Data shift setting for overcurrent detection [10:0]
    DSMIF_DATA_SHIFT_9_0  = 14,        ///< Data shift setting for overcurrent detection [9:0]
    DSMIF_DATA_SHIFT_8_0  = 15,        ///< Data shift setting for overcurrent detection [8:0]
    DSMIF_DATA_SHIFT_7_0  = 16,        ///< Data shift setting for overcurrent detection [7:0]
    DSMIF_DATA_SHIFT_6_0  = 17,        ///< Data shift setting for overcurrent detection [6:0]
    DSMIF_DATA_SHIFT_5_0  = 18,        ///< Data shift setting for overcurrent detection [5:0]
    DSMIF_DATA_SHIFT_4_0  = 19,        ///< Data shift setting for overcurrent detection [4:0]
} dsmif_data_shift_t;

/** Select the current data capture trigger. */
typedef enum e_dsmif_capture_trigger
{
    DSMIF_CAPTURE_TRIGGER_NOT = 0,     ///< Do not capture
    DSMIF_CAPTURE_TRIGGER_0   = 1,     ///< Select current data capture trigger 0
    DSMIF_CAPTURE_TRIGGER_1   = 2,     ///< Select current data capture trigger 1
    DSMIF_CAPTURE_TRIGGER_2   = 3,     ///< Select current data capture trigger 2
    DSMIF_CAPTURE_TRIGGER_3   = 4,     ///< Select current data capture trigger 3
    DSMIF_CAPTURE_TRIGGER_4   = 5,     ///< Select current data capture trigger 4
    DSMIF_CAPTURE_TRIGGER_5   = 6,     ///< Select current data capture trigger 5
} dsmif_capture_trigger_t;

/** Select the counter initialization trigger. */
typedef enum e_dsmif_counter_init_trigger
{
    DSMIF_COUNTER_INIT_TRIGGER_NOT = 0, ///< Do not initialize
    DSMIF_COUNTER_INIT_TRIGGER_0   = 1, ///< Select decimation dividing counter initialization trigger 0
    DSMIF_COUNTER_INIT_TRIGGER_1   = 2, ///< Select decimation dividing counter initialization trigger 1
    DSMIF_COUNTER_INIT_TRIGGER_2   = 3, ///< Select decimation dividing counter initialization trigger 2
} dsmif_counter_init_trigger_t;

/** DSMIF data register */
typedef enum e_dsmif_current_data
{
    DSMIF_CURRENT_DATA           = 0,  ///< DSCDRCHn   : Current Data Register
    DSMIF_CURRENT_DATA_CAPTURE_A = 1,  ///< DSCCDRACHn : Capture Current Data Register A
    DSMIF_CURRENT_DATA_CAPTURE_B = 2,  ///< DSCCDRBCHn : Capture Current Data Register B
} dsmif_current_data_t;

/** For DSMIF Scan configuration e_dsmif_ch_mask::channel_mask.
 *  Use bitwise OR to combine these masks for desired channels and sensors.    */
typedef enum e_dsmif_channel_mask
{
    DSMIF_CHANNEL_MASK_OFF = (0U),       ///< No channels selected
    DSMIF_CHANNEL_MASK_0   = (1U << 0U), ///< Channel 0 mask
    DSMIF_CHANNEL_MASK_1   = (1U << 1U), ///< Channel 1 mask
    DSMIF_CHANNEL_MASK_2   = (1U << 2U), ///< Channel 2 mask
    DSMIF_CHANNEL_MASK_3   = (1U << 3U), ///< Channel 3 mask
    DSMIF_CHANNEL_MASK_4   = (1U << 4U), ///< Channel 4 mask
    DSMIF_CHANNEL_MASK_5   = (1U << 5U), ///< Channel 5 mask
 #if 10U == BSP_FEATURE_DSMIF_UNIT
    DSMIF_CHANNEL_MASK_6  = (1U << 6U),  ///< Channel 6 mask
    DSMIF_CHANNEL_MASK_7  = (1U << 7U),  ///< Channel 7 mask
    DSMIF_CHANNEL_MASK_8  = (1U << 8U),  ///< Channel 8 mask
    DSMIF_CHANNEL_MASK_9  = (1U << 9U),  ///< Channel 9 mask
    DSMIF_CHANNEL_MASK_10 = (1U << 10U), ///< Channel 10 mask
    DSMIF_CHANNEL_MASK_11 = (1U << 11U), ///< Channel 11 mask
    DSMIF_CHANNEL_MASK_12 = (1U << 12U), ///< Channel 12 mask
    DSMIF_CHANNEL_MASK_13 = (1U << 13U), ///< Channel 13 mask
    DSMIF_CHANNEL_MASK_14 = (1U << 14U), ///< Channel 14 mask
    DSMIF_CHANNEL_MASK_15 = (1U << 15U), ///< Channel 15 mask
    DSMIF_CHANNEL_MASK_16 = (1U << 16U), ///< Channel 16 mask
    DSMIF_CHANNEL_MASK_17 = (1U << 17U), ///< Channel 17 mask
    DSMIF_CHANNEL_MASK_21 = (1U << 21U), ///< Channel 21 mask
    DSMIF_CHANNEL_MASK_22 = (1U << 22U), ///< Channel 22 mask
    DSMIF_CHANNEL_MASK_23 = (1U << 23U), ///< Channel 23 mask
    DSMIF_CHANNEL_MASK_24 = (1U << 24U), ///< Channel 24 mask
    DSMIF_CHANNEL_MASK_25 = (1U << 25U), ///< Channel 25 mask
 #endif
} dsmif_channel_mask_t;

 #if (1 == BSP_FEATURE_DSMIF_DATA_FORMAT_SEL)

/** DSMIF Data Format Select */
typedef enum e_dsmif_format
{
    DSMIF_FORMAT_LEFT  = 0,            ///< Left justified
    DSMIF_FORMAT_RIGHT = 1             ///< Right justified
} dsmif_format_t;
 #endif

 #if (4 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)

/** DSMIF overcurrent detection window notification 3 mode select register */
typedef enum e_dsmif_owwm3_mode
{
    DSMIF_OWNM3_MODE_0             = 0x0, ///< Overcurrent detection window notification 0
    DSMIF_OWNM3_MODE_1             = 0x1, ///< Overcurrent detection window notification 1
    DSMIF_OWNM3_MODE_2             = 0x2, ///< Overcurrent detection window notification 2
    DSMIF_OWNM3_MODE_0_OR_1        = 0x3, ///< Overcurrent detection window notification 0 OR 1
    DSMIF_OWNM3_MODE_0_AND_1       = 0x4, ///< Overcurrent detection window notification 0 AND 1
    DSMIF_OWNM3_MODE_0_OR_2        = 0x5, ///< Overcurrent detection window notification 0 OR 2
    DSMIF_OWNM3_MODE_0_AND_2       = 0x6, ///< Overcurrent detection window notification 0 AND 2
    DSMIF_OWNM3_MODE_1_OR_2        = 0x7, ///< Overcurrent detection window notification 1 OR 2
    DSMIF_OWNM3_MODE_1_AND_2       = 0x8, ///< Overcurrent detection window notification 1 AND 2
    DSMIF_OWNM3_MODE_0_OR_1_OR_2   = 0x9, ///< Overcurrent detection window notification 0 OR 1 OR 2
    DSMIF_OWNM3_MODE_0_AND_1_AND_2 = 0xA, ///< Overcurrent detection window notification 0 AND 1 AND 2
} dsmif_owwm3_mode_t;
 #endif

/** DSMIF channel configuration */
struct st_dsmif_channel_cfg
{
 #if (3 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_ISR)
    bool ioel[3];                      ///< Overcurrent lower limit detection interrupt enable
    bool ioeh[3];                      ///< Overcurrent upper limit exceeded output interrupt enable
 #else
    bool ioel;                         ///< Overcurrent lower limit detection interrupt enable
    bool ioeh;                         ///< Overcurrent upper limit exceeded output interrupt enable
 #endif
    bool                 ise;          ///< Short circuit detection error interrupt enable bit
    bool                 iue;          ///< Current data register update interrupt enable
    dsmif_clock_ctrl_t   ckdir;        ///< A/D conversion clock master/slave switching
    dsmif_clock_edge_t   sedge;        ///< Sampling edge selection
    dsmif_master_clock_t ckdiv;        ///< A/D conversion clock division ratio
    dsmif_filter_order_t cmsinc;       ///< Current measurement filter order setting
    uint32_t             cmdec;        ///< Decimation ratio selection for current measurement
    dsmif_data_shift_t   cmsh;         ///< Data shift setting for current measurement
    bool                 sde;          ///< Short circuit detection enable bit
    dsmif_filter_order_t ocsinc;       ///< Overcurrent detection filter order setting
    uint32_t             ocdec;        ///< Decimation ratio selection for overcurrent detection
    dsmif_data_shift_t   ocsh;         ///< Data shift setting for overcurrent detection
 #if (3 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_CONTROL)
    uint32_t ocmptbl[3];               ///< Overcurrent detection lower limit
    uint32_t ocmptbh[3];               ///< Overcurrent detection upper limit
 #else
    uint32_t ocmptbl;                  ///< Overcurrent detection lower limit
    uint32_t ocmptbh;                  ///< Overcurrent detection upper limit
 #endif
    uint32_t scntl;                    ///< Short circuit detection low continuous detection count
    uint32_t scnth;                    ///< Short circuit detection high continuous detection count
 #if (4 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)
    bool               odel[3];        ///< Overcurrent lower limit detection enable bit
    bool               odeh[3];        ///< Overcurrent upper limit exceeded detection enable bit
    bool               owne[4];        ///< Overcurrent detection window notification output enable
    bool               owfe[4];        ///< Overcurrent detection window function enable
    bool               ownm0_2[3];     ///< Channel n overcurrent detection window notification mode select
    dsmif_owwm3_mode_t ownm3;          ///< Channel n overcurrent detection window notification 3 mode select
 #else
    bool odel;                         ///< Overcurrent lower limit detection enable bit
    bool odeh;                         ///< Overcurrent upper limit exceeded detection enable bit
 #endif
};

/** DSMIF channel configuration. Please refer to the struct st_dsmif_channel_cfg. */
typedef struct st_dsmif_channel_cfg dsmif_channel_cfg_t;

/** DSMIF configuration extension. This extension is required and must be provided in dsmif_cfg_t::p_extend. */
struct st_dsmif_extended_cfg
{
    bool isel;                                                    ///< Overcurrent sum error lower limit detection interrupt enable bit
    bool iseh;                                                    ///< Overcurrent sum error upper limit detection interrupt enable bit
    dsmif_sum_err_detect_channel_t sedm;                          ///< Overcurrent sum error detect mode setting bit
    uint32_t                     scmptbl;                         ///< DSSELTR : Overcurrent Sum Error Detect Low Threshold Register
    uint32_t                     scmptbh;                         ///< DSSEHTR : Overcurrent Sum Error Detect High Threshold Register
    bool                         seel;                            ///< DSSECR : Overcurrent Sum Error lower limit detection enable
    bool                         seeh;                            ///< DSSECR : Overcurrent Sum Error upper limit detection enable
    dsmif_capture_trigger_t      cap_trig_a;                      ///< DSCMCTCRCHn.CTSELA[2:0] : Current capture trigger A selection bit
    dsmif_capture_trigger_t      cap_trig_b;                      ///< DSCMCTCRCHn.CTSELB[2:0] : Current capture trigger B selection bit
    dsmif_counter_init_trigger_t cnt_init_trig;                   ///< DSCMCTCRCHn.DITSEL[2:0] : Current measurement filter initialization trigger division counter for decimation.
    dsmif_clock_edge_t           edge;                            ///< DSCMCTCRCHn.DEDGE[2:0]  : Current measurement filter initialization trigger for division counter for decimation edge.
 #if (1 == BSP_FEATURE_DSMIF_DATA_FORMAT_SEL)
    dsmif_format_t dfs;                                           ///< Data Format Select
 #endif
 #if 1U == BSP_FEATURE_DSMIF_CORE_CLOCK_SELECTABLE
    dsmif_core_clock_select_t clksel;                             ///< Core Clock Selection
 #endif
    dsmif_channel_cfg_t * p_channel_cfgs[DSMIF_MAX_NUM_CHANNELS]; ///< Configuration for each channel, set to NULL if unused
    dsmif_channel_mask_t  channel_mask;                           ///< Channel bitmask
    void                * p_reg;                                  ///< Register base address
};

/** DSMIF configuration extension. This extension is required and must be provided in dsmif_cfg_t::p_extend. Please refer to the struct st_dsmif_extended_cfg. */
typedef struct st_dsmif_extended_cfg dsmif_extended_cfg_t;

/** DSMIF instance control block. DO NOT INITIALIZE. */
struct st_dsmif_instance_ctrl
{
    R_DSMIF0_Type   * p_reg;           // Base register for this unit
    adc_cfg_t const * p_cfg;
    uint32_t          opened;          // Boolean to verify that the Unit has been initialized
    uint32_t          channel_mask;    // Channel bitmask
    adc_mode_t        mode;            // DSMIF operation mode
    union
    {
        uint16_t results_16[DSMIF_MAX_NUM_CHANNELS];
        uint32_t results_32[DSMIF_MAX_NUM_CHANNELS];
    }    results;
    void (* p_callback)(adc_callback_args_t *); // Pointer to callback that is called when an dsmif_event_t occurs.
    adc_callback_args_t * p_callback_memory;    // Pointer to non-secure memory that can be used to pass arguments to a callback in non-secure memory.

    /* Pointer to context to be passed into callback function */
    void * p_context;
};

/** DSMIF instance control block. DO NOT INITIALIZE. Please refer to the struct st_dsmif_instance_ctrl. */
typedef struct st_dsmif_instance_ctrl dsmif_instance_ctrl_t;

/** DSMIF Channel Overcurrent detect status. */
typedef enum e_dsmif_channel_overcurrent_status
{
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH0_LOWER_LIMIT_0 = 1 << 0U,  ///< Channel 0 overcurrent lower limit detection 0  flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH1_LOWER_LIMIT_0 = 1 << 1U,  ///< Channel 1 overcurrent lower limit detection 0 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH2_LOWER_LIMIT_0 = 1 << 2U,  ///< Channel 2 overcurrent lower limit detection 0 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH0_UPPER_LIMIT_0 = 1 << 3U,  ///< Channel 0 overcurrent upper limit exceeded 0 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH1_UPPER_LIMIT_0 = 1 << 4U,  ///< Channel 1 overcurrent upper limit exceeded 0 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH2_UPPER_LIMIT_0 = 1 << 5U,  ///< Channel 2 overcurrent upper limit exceeded 0 flag

 #if (4 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH0_LOWER_LIMIT_1 = 1 << 6U,  ///< Channel 0 overcurrent lower limit detection 1 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH1_LOWER_LIMIT_1 = 1 << 7U,  ///< Channel 1 overcurrent lower limit detection 1 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH2_LOWER_LIMIT_1 = 1 << 8U,  ///< Channel 2 overcurrent lower limit detection 1 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH0_UPPER_LIMIT_1 = 1 << 9U,  ///< Channel 0 overcurrent upper limit exceeded 1 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH1_UPPER_LIMIT_1 = 1 << 10U, ///< Channel 1 overcurrent upper limit exceeded 1 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH2_UPPER_LIMIT_1 = 1 << 11U, ///< Channel 2 overcurrent upper limit exceeded 1 flag

    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH0_LOWER_LIMIT_2 = 1 << 12U, ///< Channel 0 overcurrent lower limit detection 2 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH1_LOWER_LIMIT_2 = 1 << 13U, ///< Channel 1 overcurrent lower limit detection 2 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH2_LOWER_LIMIT_2 = 1 << 14U, ///< Channel 2 overcurrent lower limit detection 2 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH0_UPPER_LIMIT_2 = 1 << 15U, ///< Channel 0 overcurrent upper limit exceeded 2 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH1_UPPER_LIMIT_2 = 1 << 16U, ///< Channel 1 overcurrent upper limit exceeded 2 flag
    DSMIF_CHANNEL_OVERCURRENT_STATUS_CH2_UPPER_LIMIT_2 = 1 << 17U, ///< Channel 2 overcurrent upper limit exceeded 2 flag
 #endif
} dsmif_channel_overcurrent_status_t;

/** DSMIF Channel Short circuit detect status. */
typedef enum e_dsmif_channel_short_circuit_status
{
    DSMIF_CHANNEL_SHORT_CIRCUIT_STATUS_CH0 = 1 << 0U, ///< Channel 0 short circuit detection flag
    DSMIF_CHANNEL_SHORT_CIRCUIT_STATUS_CH1 = 1 << 1U, ///< Channel 1 short circuit detection flag
    DSMIF_CHANNEL_SHORT_CIRCUIT_STATUS_CH2 = 1 << 2U, ///< Channel 2 short circuit detection flag
} dsmif_channel_short_circuit_status_t;

/** DSMIF Overcurrent Sum detect status. */
typedef enum e_dsmif_overcurrent_sum_status
{
    DSMIF_OVERCURRENT_SUM_STATUS_LOWER_LIMIT = 1 << 0U, ///< Overcurrent sum error lower limit detection flag
    DSMIF_OVERCURRENT_SUM_STATUS_UPPER_LIMIT = 1 << 1U, ///< Overcurrent sum error upper limit detection flag
} dsmif_overcurrent_sum_status_t;

 #if (4 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)

/** DSMIF Overcurrent Window detect status. */
typedef enum e_dsmif_channel_overcurrent_window_status
{
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH0_0 = 1 << 0U,  ///< Channel 0 overcurrent detection window notification 0 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH1_0 = 1 << 1U,  ///< Channel 1 overcurrent detection window notification 0 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH2_0 = 1 << 2U,  ///< Channel 2 overcurrent detection window notification 0 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH0_1 = 1 << 3U,  ///< Channel 0 overcurrent detection window notification 1 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH1_1 = 1 << 4U,  ///< Channel 1 overcurrent detection window notification 1 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH2_1 = 1 << 5U,  ///< Channel 2 overcurrent detection window notification 1 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH0_2 = 1 << 6U,  ///< Channel 0 overcurrent detection window notification 2 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH1_2 = 1 << 7U,  ///< Channel 1 overcurrent detection window notification 2 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH2_2 = 1 << 8U,  ///< Channel 2 overcurrent detection window notification 2 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH0_3 = 1 << 9U,  ///< Channel 0 overcurrent detection window notification 3 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH1_3 = 1 << 10U, ///< Channel 1 overcurrent detection window notification 3 flag
    DSMIF_OVERCURRENT_WINDOW_STATUS_CH2_3 = 1 << 11U, ///< Channel 2 overcurrent detection window notification 3 flag
} dsmif_channel_overcurrent_window_status_t;
 #endif

/** DSMIF Error status. */
struct st_dsmif_error_status
{
    dsmif_channel_overcurrent_status_t   channel_overcurrent_status;             ///< Channel Overcurrent state
    dsmif_channel_short_circuit_status_t channel_short_circuit_status;           ///< Channel Short circuit state
    dsmif_overcurrent_sum_status_t       overcurrent_sum_status;                 ///< Overcurrent Sum state

 #if (4 == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)
    dsmif_channel_overcurrent_window_status_t channel_overcurrent_window_status; ///< Channel Overcurrent Window State
 #endif
};

/** DSMIF Error status. Please refer to the struct st_dsmif_error_status. */
typedef struct st_dsmif_error_status dsmif_error_status_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Interface Structure for user access */
extern const adc_api_t g_adc_on_dsmif;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_Open(adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg);
fsp_err_t R_DSMIF_ScanStart(adc_ctrl_t * p_ctrl);
fsp_err_t R_DSMIF_ScanStop(adc_ctrl_t * p_ctrl);
fsp_err_t R_DSMIF_CfgSet(adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg);
fsp_err_t R_DSMIF_StatusGet(adc_ctrl_t * p_ctrl, adc_status_t * p_status);
fsp_err_t R_DSMIF_ErrorStatusGet(adc_ctrl_t * p_ctrl, dsmif_error_status_t * p_error_status);
fsp_err_t R_DSMIF_Read(adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data);
fsp_err_t R_DSMIF_Close(adc_ctrl_t * p_ctrl);
fsp_err_t R_DSMIF_CallbackSet(adc_ctrl_t * const          p_ctrl,
                              void (                    * p_callback)(adc_callback_args_t *),
                              void * const                p_context,
                              adc_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup DSMIF)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
