/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "hal_data.h"
#include "r_cru.h"
#include "r_cru_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define CSI2_DPHYTIM0                  (0x040137B9)
#define CSI2_DPHYTIM1                  (0x0A0A0C12)
#define CSI2_DPHYSKW0                  (0x00001111)
#define CSI2_MCT2                      (0x0016000B)
#define CPG_CLKON_CRU_VCLK_DISABLE     (0x00020000)
#define CPG_CLKON_CRU_VCLK_ENABLE      (0x00020002)
#define CPG_RST_CRU_UNIT0_ENABLE       (0x00010001)
#define ICNMC_CL                       (0x3)

#define YUV422_10BIT_FORMAT_ENALBE     (1U)
#define YUV422_8BIT_FORMAT_ENALBE      (1U)
#define YUV420_10BIT_FORMAT_ENALBE     (1U)
#define YUV420_8BIT_FORMAT_ENALBE      (1U)
#define GENERIC_LONG_PACKET_ENALBE     (1U)
#define GENERIC_SHORT_PACKET_ENALBE    (1U)
#define USER_DEFINED_DATA_ENALBE       (1U)
#define RAW20_FORMAT_ENALBE            (1U)
#define RAW16_FORMAT_ENABLE            (1U)
#define RAW14_FORMAT_ENABLE            (1U)
#define RAW12_FORMAT_ENABLE            (1U)
#define RAW10_FORMAT_ENABLE            (1U)
#define RAW8_FORMAT_ENABLE             (1U)
#define RAW7_FORMAT_ENABLE             (1U)
#define RAW6_FORMAT_ENABLE             (1U)
#define RGB888_FORMAT_ENALBE           (1U)
#define RGB666_FORMAT_ENALBE           (1U)
#define RGB565_FORMAT_ENALBE           (1U)
#define RGB555_FORMAT_ENALBE           (1U)
#define RGB444_FORMAT_ENALBE           (1U)

#define CAST_TO_UINT32                 (0xFFFFFFFFU)
#define CAST_TO_UINT13                 (0x1FFFU)
#define CAST_TO_UINT12                 (0xFFFU)
#define CAST_TO_UINT9                  (0x1FFU)
#define CAST_TO_UINT6                  (0x3FU)
#define CAST_TO_UINT4                  (0xFU)
#define CAST_TO_UINT3                  (0x7U)
#define CAST_TO_UINT2                  (0x3U)
#define CAST_TO_UINT1                  (0x1U)

#define CSI2_DTEL                      (YUV422_10BIT_FORMAT_ENALBE) << 31 | (YUV422_8BIT_FORMAT_ENALBE) << 30 | \
    (YUV420_10BIT_FORMAT_ENALBE) << 29 | (YUV420_8BIT_FORMAT_ENALBE) << 28 |                                    \
    (YUV420_8BIT_FORMAT_ENALBE) << 26 | (YUV420_10BIT_FORMAT_ENALBE) << 25 |                                    \
    (YUV420_8BIT_FORMAT_ENALBE) << 24 | (GENERIC_LONG_PACKET_ENALBE) << 22 |                                    \
    (GENERIC_LONG_PACKET_ENALBE) << 21 | (GENERIC_LONG_PACKET_ENALBE) << 20 |                                   \
    (GENERIC_LONG_PACKET_ENALBE) << 19 | (GENERIC_SHORT_PACKET_ENALBE) << 15 |                                  \
    (GENERIC_SHORT_PACKET_ENALBE) << 14 | (GENERIC_SHORT_PACKET_ENALBE) << 13 |                                 \
    (GENERIC_SHORT_PACKET_ENALBE) << 12 | (GENERIC_SHORT_PACKET_ENALBE) << 11 |                                 \
    (GENERIC_SHORT_PACKET_ENALBE) << 10 | (GENERIC_SHORT_PACKET_ENALBE) << 9 |                                  \
    (GENERIC_SHORT_PACKET_ENALBE) << 8

#define CSI2_DTEH                      (USER_DEFINED_DATA_ENALBE) << 23 | (USER_DEFINED_DATA_ENALBE) << 22 | \
    (USER_DEFINED_DATA_ENALBE) << 21 | (USER_DEFINED_DATA_ENALBE) << 20 |                                    \
    (USER_DEFINED_DATA_ENALBE) << 19 | (USER_DEFINED_DATA_ENALBE) << 18 |                                    \
    (USER_DEFINED_DATA_ENALBE) << 17 | (USER_DEFINED_DATA_ENALBE) << 16 |                                    \
    (RAW20_FORMAT_ENALBE) << 15 | (RAW16_FORMAT_ENABLE) << 14 |                                              \
    (RAW14_FORMAT_ENABLE) << 13 | (RAW12_FORMAT_ENABLE) << 12 |                                              \
    (RAW10_FORMAT_ENABLE) << 11 | (RAW8_FORMAT_ENABLE) << 10 |                                               \
    (RAW7_FORMAT_ENABLE) << 9 | (RAW6_FORMAT_ENABLE) << 8 |                                                  \
    (RGB888_FORMAT_ENALBE) << 4 | (RGB666_FORMAT_ENALBE) << 3 |                                              \
    (RGB565_FORMAT_ENALBE) << 2 | (RGB555_FORMAT_ENALBE) << 1 |                                              \
    (RGB444_FORMAT_ENALBE)

#define MICROSEC_WAIT_20               (20U)
#define MICROSEC_WAIT_10               (10U)
#define MILISEC_WAIT_1                 (1U)
#define BIT_SHIFT_32                   (32)
#define BIT_SHIFT_24                   (24)
#define BIT_SHIFT_16                   (16)
#define BIT_SHIFT_8                    (8)

#define CAPTURE_HSIZE_MAX              (2800)
#define CAPTURE_VSIZE_MAX              (4095)
#define CAPTURE_HSIZE_MIN              (320)
#define CAPTURE_VSIZE_MIN              (240)
#define BUFFER_ALIGNMENT_512           (512)
#define BUFFER_NUM_MIN                 (1)
#define BUFFER_NUM_MAX                 (8)
#define INPUT_FORMAT_MIN_INVLID        (0)
#define INPUT_FORMAT_MAX_INVLID        (9)
#define OUTPUT_FORMAT_MIN_INVLID       (0)
#define OUTPUT_FORMAT_MAX_INVLID       (7)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_cru_mipi_dphy_set(cru_cfg_t const * const p_cfg);
static void r_cru_mipi_link_set(cru_cfg_t const * const p_cfg);
static void r_cru_axi_set(cru_cfg_t const * const p_cfg);
static void r_cru_image_processing_set(cru_cfg_t const * const p_cfg);
static void r_cru_stop_linkpacket();
static void r_cru_stop_dphy();
static void r_cru_stop_imageprocessing();
static void r_cru_interrupt_enable(cru_instance_ctrl_t * const p_instance_ctrl);
void        cru_image_conv_int(IRQn_Type const irq);

#if (CRU_CFG_PARAM_CHECKING_ENABLE)
static fsp_err_t r_cru_open_param_check(cru_cfg_t const * const p_cfg);
static fsp_err_t r_cru_open_param_check_size_setting(cru_cfg_t const * const p_cfg);
static fsp_err_t r_cru_open_param_check_buffer_setting(cru_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* This table values are written to CRU register */
static const uint8_t capture_input_format[] =
{
    0x18,                              /* YUV420 8bit  */
    0x19,                              /* YUV420 10bit */
    0x1E,                              /* YUV422 8bit  */
    0x1F,                              /* YUV422 10bit */
    0x22,                              /* RGB565       */
    0x24,                              /* RGB888       */
    0x2A,                              /* RAW8         */
    0x2B,                              /* RAW10        */
    0x2C,                              /* RAW12        */
    0x2D,                              /* RAW14        */
};

/* This table values are written to CRU register */
static const uint8_t capture_output_format[] =
{
    0x4,                               /* YUYV (YUV420) */
    0x5,                               /* UYVY (YUV420) */
    0x0,                               /* YUYV (YUV422) */
    0x1,                               /* UYVY (YUV422) */
    0x0,                               /* RGB888 24bit  */
    0x1, /* RGB888 32bit  */           ///< Upper 8bit : 0x00
    0x3, /* RGB888 32bit  */           ///< A-R-G-B
    0x2, /* RGB888 32bit  */           ///< B-G-R-A
};

static volatile uint32_t * const AMnMBnADDRL[8] =
{
    &(R_CRU->AMnMB1ADDRL),
    &(R_CRU->AMnMB2ADDRL),
    &(R_CRU->AMnMB3ADDRL),
    &(R_CRU->AMnMB4ADDRL),
    &(R_CRU->AMnMB5ADDRL),
    &(R_CRU->AMnMB6ADDRL),
    &(R_CRU->AMnMB7ADDRL),
    &(R_CRU->AMnMB8ADDRL),
};

static volatile uint32_t * const AMnMBnADDRH[8] =
{
    &(R_CRU->AMnMB1ADDRH),
    &(R_CRU->AMnMB2ADDRH),
    &(R_CRU->AMnMB3ADDRH),
    &(R_CRU->AMnMB4ADDRH),
    &(R_CRU->AMnMB5ADDRH),
    &(R_CRU->AMnMB6ADDRH),
    &(R_CRU->AMnMB7ADDRH),
    &(R_CRU->AMnMB8ADDRH),
};

static volatile uint32_t * const AMnSDMBnADDRL[8] =
{
    &(R_CRU->AMnSDMB1ADDRL),
    &(R_CRU->AMnSDMB2ADDRL),
    &(R_CRU->AMnSDMB3ADDRL),
    &(R_CRU->AMnSDMB4ADDRL),
    &(R_CRU->AMnSDMB5ADDRL),
    &(R_CRU->AMnSDMB6ADDRL),
    &(R_CRU->AMnSDMB7ADDRL),
    &(R_CRU->AMnSDMB8ADDRL),
};

static volatile uint32_t * const AMnSDMBnADDRH[8] =
{
    &(R_CRU->AMnSDMB1ADDRH),
    &(R_CRU->AMnSDMB2ADDRH),
    &(R_CRU->AMnSDMB3ADDRH),
    &(R_CRU->AMnSDMB4ADDRH),
    &(R_CRU->AMnSDMB5ADDRH),
    &(R_CRU->AMnSDMB6ADDRH),
    &(R_CRU->AMnSDMB7ADDRH),
    &(R_CRU->AMnSDMB8ADDRH),
};
static cru_instance_ctrl_t r_cru_blk;

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* CRU API */
const cru_api_t g_cru_on_cru =
{
    .open         = R_CRU_Open,
    .close        = R_CRU_Close,
    .captureStart = R_CRU_CaptureStart,
    .captureStop  = R_CRU_CaptureStop,
    .statusGet    = R_CRU_StatusGet,
};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZA
{
#endif
#endif

/*******************************************************************************************************************//**
 *
 * @addtogroup RZA_CRU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *　Initializes the CRU modules and enables interrupts
 *
 * @retval FSP_SUCCESS              Initializes the CRU modules.
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_ALREADY_OPEN     CRU module is already open
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument error
 * @retval FSP_ERR_INVALID_ALIGNMENT       Input buffer alignment
 **********************************************************************************************************************/
fsp_err_t R_CRU_Open (cru_ctrl_t * const p_api_ctrl, cru_cfg_t const * const p_cfg)
{
    fsp_err_t             err    = FSP_SUCCESS;
    cru_instance_ctrl_t * p_ctrl = (cru_instance_ctrl_t *) p_api_ctrl;

#if  (CRU_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters */
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->state <= CAMERA_STATE_IDLE, FSP_ERR_ALREADY_OPEN);
    err = r_cru_open_param_check(p_cfg);
    if (FSP_SUCCESS != err)
    {
        return err;
    }
#endif

    p_ctrl->p_cfg       = p_cfg;
    p_ctrl->p_context   = p_cfg->p_context;
    p_ctrl->p_callback  = p_cfg->p_callback;
    r_cru_blk.p_context = p_ctrl;

    R_BSP_MODULE_START(FSP_IP_CRU, 0);

    /* D-PHY setting */
    r_cru_mipi_dphy_set(p_cfg);

    /* select MIPI I/F -> select MIPI*/
    R_CRU->CRUnCTRL_b.VINSEL = 0;

    /* release the Image Processing Module form the reset state */
    R_CRU->CRUnRST_b.VRESETN = 1;

    /* interrupt setting */
    R_CRU->CRUnIE   = 0x00000000;
    R_CRU->CRUnINTS = 0x00000000;

    /* AXI-MASTER setting */
    r_cru_axi_set(p_cfg);

    /* Image Processing module setting */
    r_cru_image_processing_set(p_cfg);

    /* Enable CRU interrupts */
    r_cru_interrupt_enable(p_api_ctrl);

    /* LINK setting */
    r_cru_mipi_link_set(p_cfg);

    /* Change Capture Status */
    p_ctrl->state = CAMERA_STATE_IN_PROGRESS;

    return err;
}

/*******************************************************************************************************************//**
 * Close the capture while the CRU module is operating
 *
 * @retval FSP_SUCCESS          Close the CRU module
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_NOT_OPEN     CRU module is not open
 **********************************************************************************************************************/
fsp_err_t R_CRU_Close (cru_ctrl_t * const p_api_ctrl)
{
    fsp_err_t             err    = FSP_SUCCESS;
    cru_instance_ctrl_t * p_ctrl = (cru_instance_ctrl_t *) p_api_ctrl;

#if  (CRU_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(CAMERA_STATE_IDLE != p_ctrl->state, FSP_ERR_NOT_OPEN);
#endif

    /* Disable interrupts */
    R_CRU->CRUnIE_b.SFE    = false;
    R_CRU->CRUnIE_b.EFE    = false;
    R_CRU->CRUnIE_b.SIE    = false;
    R_CRU->CRUnIE_b.WIE    = false;
    R_CRU->CRUnIE_b.FEOVWE = false;
    R_CRU->CRUnIE_b.DECEE  = false;
    R_CRU->CRUnIE_b.SLVEE  = false;
    R_CRU->CRUnIE_b.FOE    = false;

    /* stop Link packet */
    r_cru_stop_linkpacket();

    /* stop D-PHY */
    r_cru_stop_dphy();

    /* LINK stop reception */
    R_CRU->CSI2nMCT3_b.RXEN = 0;

    /* software reset */
    R_CRU->CSI2nRTCT_b.VSRST = 1;
    while (1 == R_CRU->CSI2nRTST_b.VSRSTS)
    {
        /*
         * No operation
         */
    }

    /* stop image processing module */
    r_cru_stop_imageprocessing();

    /* Change Capture Status */
    p_ctrl->state = CAMERA_STATE_IDLE;

    return err;
}

/*******************************************************************************************************************//**
 * Start a capture. It is only possible when CRU is open.
 *
 * @retval FSP_SUCCESS              start a capture.
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     CRU module is not CAMERA_STATE_IN_PROGRESS
 **********************************************************************************************************************/
fsp_err_t R_CRU_CaptureStart (cru_ctrl_t * const p_api_ctrl)
{
    fsp_err_t             err    = FSP_SUCCESS;
    cru_instance_ctrl_t * p_ctrl = (cru_instance_ctrl_t *) p_api_ctrl;

#if  (CRU_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(CAMERA_STATE_IN_PROGRESS == p_ctrl->state, FSP_ERR_INVALID_MODE);
#endif

    /* Start the operation of Image processing */
    R_CRU->ICnEN_b.ICEN = 1;

    R_BSP_MODULE_RSTOFF(FSP_IP_CRU, 0);
    R_BSP_SoftwareDelay(MILISEC_WAIT_1, BSP_DELAY_UNITS_MILLISECONDS);

    /* Change Capture Status */
    p_ctrl->state = CAMERA_STATE_BUSY;

    return err;
}

/*******************************************************************************************************************//**
 * Stop a capture. It is only possible when CRU is running.
 *
 * @retval FSP_SUCCESS              stop a capture.
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     CRU module is not CAMERA_STATE_BUSY
 **********************************************************************************************************************/
fsp_err_t R_CRU_CaptureStop (cru_ctrl_t * const p_api_ctrl)
{
    fsp_err_t             err    = FSP_SUCCESS;
    cru_instance_ctrl_t * p_ctrl = (cru_instance_ctrl_t *) p_api_ctrl;

#if  (CRU_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(CAMERA_STATE_BUSY == p_ctrl->state, FSP_ERR_INVALID_MODE);
#endif

    /* Start the operation of Image processing */
    R_CRU->ICnEN_b.ICEN = 0;

    /* Change Capture Status */
    p_ctrl->state = CAMERA_STATE_IN_PROGRESS;

    return err;
}

/*******************************************************************************************************************//**
 * Get the camera status, CAMERA module status and buffer address.
 * It is only possible when CRU is running.
 *
 * @retval FSP_SUCCESS              stop a capture.
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     CRU module is not CAMERA_STATE_BUSY
 **********************************************************************************************************************/
fsp_err_t R_CRU_StatusGet (cru_ctrl_t * const p_api_ctrl, camera_status_t * p_status)
{
    fsp_err_t             err    = FSP_SUCCESS;
    cru_instance_ctrl_t * p_ctrl = (cru_instance_ctrl_t *) p_api_ctrl;
    uint32_t              buffer_id;

#if  (CRU_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(CAMERA_STATE_BUSY == p_ctrl->state, FSP_ERR_INVALID_MODE);
#endif

    buffer_id          = R_CRU->AMnMBS_b.MBSTS;
    p_status->p_buffer = (uint32_t *) ((uint64_t) p_ctrl->p_cfg->buffer_cfg.pp_buffer[buffer_id] & CAST_TO_UINT32);

    p_status->state = p_ctrl->state;

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RZA_CRU)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Set the MIPI D-PHY configurations
 *
 * @retval        none
 **********************************************************************************************************************/
static void r_cru_mipi_dphy_set (cru_cfg_t const * const p_cfg)
{
    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_cfg->p_extend;

    /* D-PHY timing setting */
    R_CRU->CSIDPHYTIM0 = (pextend->tclk_miss << BIT_SHIFT_24) | (pextend->t_init);
    R_CRU->CSIDPHYTIM1 = (pextend->ths_prepare << BIT_SHIFT_24) | (pextend->tclk_prepare << BIT_SHIFT_16) |
                         (pextend->ths_settle << BIT_SHIFT_8) | (pextend->tclk_settle);

    /* skew adjustment setting */
    R_CRU->CSIDPHYSKW0 = CSI2_DPHYSKW0;

    R_CRU->CSIDPHYCTRL0_b.EN_BGR = 1;
    R_BSP_SoftwareDelay(MICROSEC_WAIT_20, BSP_DELAY_UNITS_MICROSECONDS);

    R_CRU->CSIDPHYCTRL0_b.EN_LDO1200 = 1;
    R_BSP_SoftwareDelay(MICROSEC_WAIT_10, BSP_DELAY_UNITS_MICROSECONDS);

    R_BSP_MODULE_CLKON(FSP_IP_CRU, 0);
}

/*******************************************************************************************************************//**
 * Set the MIPI LINK configurations
 *
 * @param[in]       p_cfg       CRU configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_cru_mipi_link_set (cru_cfg_t const * const p_cfg)
{
    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_cfg->p_extend;

    /* disable de-scrambling */
    R_CRU->CSI2nMCT0_b.LFSREN = 0;

    /* ECC  0:26bit 1:24bit*/
    R_CRU->CSI2nMCT0_b.ECCV13 = 0;

    /* number of used data lanes */
    R_CRU->CSI2nMCT0_b.VDLN = pextend->num_datalane;

    /* internal setting parameter */
    R_CRU->CSI2nMCT2 = CSI2_MCT2;

    /*input data type setting, all format enable */
    R_CRU->CSI2nDTEL = CSI2_DTEL;
    R_CRU->CSI2nDTEH = CSI2_DTEH;

    R_CPG->CPG_CLKON_CRU = CPG_CLKON_CRU_VCLK_DISABLE;
    while (1 == R_CPG->CPG_CLKMON_CRU_b.CLK1_MON)
    {
        /* Do Nothing */
    }

    /* enable LINK receive */
    R_CRU->CSI2nMCT3_b.RXEN = 1;

    R_CPG->CPG_CLKON_CRU = CPG_CLKON_CRU_VCLK_ENABLE;
    while (0 == R_CPG->CPG_CLKMON_CRU_b.CLK1_MON)
    {
        /* Do Nothing */
    }

    /* Release the CRU from the reset state for the third time (D-PHY)) */
    R_CPG->CPG_RST_CRU = CPG_RST_CRU_UNIT0_ENABLE;
}

/*******************************************************************************************************************//**
 * Set the AXI configurations
 *
 * @param[in]       p_cfg       CRU configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_cru_axi_set (cru_cfg_t const * const p_cfg)
{
    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_cfg->p_extend;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* MB setting */
    uint16_t wait;
    uint8_t  MB_valid   = 1;
    uint8_t  SDMB_valid = 1;
    uint8_t  i          = 0;

    for (wait = 0; wait < p_cfg->buffer_cfg.num_buffers; wait++)
    {
        MB_valid *= 2;
    }

    MB_valid--;
    R_CRU->AMnMBVALID_b.MBVALID = MB_valid;

    for (i = 0; i < p_cfg->buffer_cfg.num_buffers; i++)
    {
        /* Set physical address of read buffer to an I/O register */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
        va = (uint64_t) (p_cfg->buffer_cfg.pp_buffer[i]) & CAST_TO_UINT32;
        R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
        *AMnMBnADDRL[i] = (uint32_t) (pa) & CAST_TO_UINT32;
        *AMnMBnADDRH[i] = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT2;
#else
        *AMnMBnADDRL[i] = (uint32_t) ((uint64_t) p_cfg->buffer_cfg.pp_buffer[i]) & CAST_TO_UINT32;
        *AMnMBnADDRH[i] = (uint32_t) ((uint64_t) p_cfg->buffer_cfg.pp_buffer[i] >> BIT_SHIFT_32) & CAST_TO_UINT2;
#endif
    }

    /* AXI bus master attribute setting for image data */
    R_CRU->AMnAXIATTR_b.AXILEN = 0;

    /* FIFO control setting for image data */
    R_CRU->AMnFIFO_b.FIFOOVFREC = 1;

    /* AXI Master transfer stop setting */
    R_CRU->AMnAXISTP_b.AXI_STOP = 0;

    if (0 == pextend->statistics_cfg.statistics)
    {
        /* Memory Bank settings for statistics data */
        for (wait = 0; wait < pextend->statistics_cfg.num_buffers; wait++)
        {
            SDMB_valid *= 2;
        }

        SDMB_valid--;
        R_CRU->AMnSDMBVALID_b.SDMBVALID = SDMB_valid;

        for (i = 0; i < p_cfg->buffer_cfg.num_buffers; i++)
        {
            /* Buffer address setting  */
            /* Set physical address of read buffer to an I/O register */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
            va = (uint64_t) (pextend->statistics_cfg.pp_buffer[i]) & CAST_TO_UINT32;
            R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
            *AMnSDMBnADDRL[i] = (uint32_t) (pa) & CAST_TO_UINT32;
            *AMnSDMBnADDRH[i] = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT2;
#else
            *AMnSDMBnADDRL[i] = (uint32_t) ((uint64_t) pextend->statistics_cfg.pp_buffer[i]) & CAST_TO_UINT32;
            *AMnSDMBnADDRH[i] = (uint32_t) ((uint64_t) pextend->statistics_cfg.pp_buffer[i] >> BIT_SHIFT_32) &
                                CAST_TO_UINT2;
#endif
        }

        /* Maximum Statistics Burst Length setting */
        R_CRU->AMnSDAXIATTR_b.SDAXILEN = 0x0;

        /* Statistics FIFO overflow */
        R_CRU->AMnSDFIFO_b.SDFIFOOVFREC = 1;

        /* Statistics AXI Resume Transfer Control */
        R_CRU->AMnSDFIFOTRST_b.SDAXI_TRANS_START = 0;

        /* Statistics AXI Stop transfer */
        R_CRU->AMnSDAXISTP_b.SDAXISTOP = 0;
    }
    else
    {
        /* Do Nothing */
    }
}

/*******************************************************************************************************************//**
 * Check if the input format is RAW
 *
 * @param[in]       inf        input format
 * @retval          true       input format is RAW8/10/12/14
 * @retval          false      input format is not RAW
 **********************************************************************************************************************/
static _Bool r_cru_isinput_raw (const cru_color_input_format_t inf)
{
    if ((inf == CRU_COLOR_INPUT_FORMAT_RAW8) ||
        (inf == CRU_COLOR_INPUT_FORMAT_RAW10) ||
        (inf == CRU_COLOR_INPUT_FORMAT_RAW12) ||
        (inf == CRU_COLOR_INPUT_FORMAT_RAW14))
    {
        return true;
    }

    return false;
}

/*******************************************************************************************************************//**
 * Check if the input format is YUV
 *
 * @param[in]       inf        input format
 * @retval          true       input format is YUV422/420
 * @retval          false      input format is not YUV
 **********************************************************************************************************************/
static _Bool r_cru_isinput_yuv (const cru_color_input_format_t inf)
{
    if ((inf == CRU_COLOR_INPUT_FORMAT_YUV420_8BIT) ||
        (inf == CRU_COLOR_INPUT_FORMAT_YUV420_10BIT) ||
        (inf == CRU_COLOR_INPUT_FORMAT_YUV422_8BIT) ||
        (inf == CRU_COLOR_INPUT_FORMAT_YUV422_10BIT))
    {
        return true;
    }

    return false;
}

/*******************************************************************************************************************//**
 * Check if the input format is RGB
 *
 * @param[in]       inf        input format
 * @retval          true       input format is RGB565/888
 * @retval          false      input format is not RGB
 **********************************************************************************************************************/
static _Bool r_cru_isinput_rgb (const cru_color_input_format_t inf)
{
    if ((inf == CRU_COLOR_INPUT_FORMAT_RGB565) ||
        (inf == CRU_COLOR_INPUT_FORMAT_RGB888))
    {
        return true;
    }

    return false;
}

/*******************************************************************************************************************//**
 * Check if the output format is YUV
 *
 * @param[in]       outf       output format
 * @retval          true       output format is YUV422/420
 * @retval          false      output format is not YUV422/420
 **********************************************************************************************************************/
static _Bool r_cru_isoutput_yuv (const cru_color_output_format_t outf)
{
    if ((outf == CRU_COLOR_OUTPUT_FORMAT_YUV420_YUYV) ||
        (outf == CRU_COLOR_OUTPUT_FORMAT_YUV420_UYVY) ||
        (outf == CRU_COLOR_OUTPUT_FORMAT_YUV422_YUYV) ||
        (outf == CRU_COLOR_OUTPUT_FORMAT_YUV422_UYVY))
    {
        return true;
    }

    return false;
}

/*******************************************************************************************************************//**
 * Check if the output format is RGB
 *
 * @param[in]       outf       output format
 * @retval          true       output format is RGB888
 * @retval          false      output format is not RGB888
 **********************************************************************************************************************/
static _Bool r_cru_isoutput_rgb (const cru_color_output_format_t outf)
{
    if ((outf == CRU_COLOR_OUTPUT_FORMAT_RGB888_24BIT) ||
        (outf == CRU_COLOR_OUTPUT_FORMAT_RGB888_32BIT))
    {
        return true;
    }

    return false;
}

/*******************************************************************************************************************//**
 * Set the Image Processing Module configurations
 *
 * @param[in]       p_cfg       CRU configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_cru_image_processing_set (cru_cfg_t const * const p_cfg)
{
    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_cfg->p_extend;

    /* MIPI input format setting */
    R_CRU->ICnMC_b.INF = capture_input_format[pextend->color_input] & CAST_TO_UINT6;

    /* select RAW type */
    R_CRU->ICnMC_b.RAWSTTYP = pextend->rawstarttype & CAST_TO_UINT2;

    /* virtual channel setting */
    R_CRU->ICnMC_b.VCSEL = 0x0;

    /* disable sub-sampling */
    R_CRU->ICnMC_b.DECTHR = 1;

    /* enable clipping */
    R_CRU->ICnMC_b.CLPTHR = 0;

    /* setting demosaic */
    if (r_cru_isinput_raw(pextend->color_input))
    {
        R_CRU->ICnMC_b.DEMTHR = 0;
    }
    else
    {
        R_CRU->ICnMC_b.DEMTHR = 1;
    }

    /* setting Linear Matrix */
    R_CRU->ICnMC_b.LMXTHR = pextend->linearmatrix_cfg.linearmatrix & CAST_TO_UINT1;

    /* setting color space conversion */
    if ((r_cru_isinput_raw(pextend->color_input) && r_cru_isoutput_yuv(pextend->color_output)) ||
        (r_cru_isinput_yuv(pextend->color_input) && r_cru_isoutput_rgb(pextend->color_output)) ||
        (r_cru_isinput_rgb(pextend->color_input) && r_cru_isoutput_yuv(pextend->color_output)))
    {
        R_CRU->ICnMC_b.CSCTHR = 0;
    }
    else
    {
        R_CRU->ICnMC_b.CSCTHR = 1;
    }

    /* setting Statistics */
    R_CRU->ICnMC_b.STITHR = pextend->statistics_cfg.statistics & CAST_TO_UINT1;

    /* disable LUT (10bit to 8bit) */
    R_CRU->ICnMC_b.LUTTHR = 1;

    /* select offset binary of U and V */
    R_CRU->ICnMC_b.IBINSEL = 0;

    /** Linear Matrix processing settings */
    if ((0 == R_CRU->ICnMC_b.DEMTHR) && (0 == R_CRU->ICnMC_b.LMXTHR))
    {
        /* linear matrix offset setting */
        R_CRU->ICnLMXOF_b.ROF = (uint8_t) pextend->linearmatrix_cfg.rof;
        R_CRU->ICnLMXOF_b.GOF = (uint8_t) pextend->linearmatrix_cfg.gof;
        R_CRU->ICnLMXOF_b.BOF = (uint8_t) pextend->linearmatrix_cfg.bof;

        /* linear matrix R register setting */
        R_CRU->ICnLMXRC1_b.RR = pextend->linearmatrix_cfg.rr & CAST_TO_UINT13;
        R_CRU->ICnLMXRC2_b.RG = pextend->linearmatrix_cfg.rg & CAST_TO_UINT13;
        R_CRU->ICnLMXRC2_b.RB = pextend->linearmatrix_cfg.rb & CAST_TO_UINT13;

        /* linear matrix G register setting */
        R_CRU->ICnLMXGC1_b.GR = pextend->linearmatrix_cfg.gr & CAST_TO_UINT13;
        R_CRU->ICnLMXGC2_b.GG = pextend->linearmatrix_cfg.gg & CAST_TO_UINT13;
        R_CRU->ICnLMXGC2_b.GB = pextend->linearmatrix_cfg.gb & CAST_TO_UINT13;

        /* linear matrix B register setting */
        R_CRU->ICnLMXBC1_b.BR = pextend->linearmatrix_cfg.br & CAST_TO_UINT13;
        R_CRU->ICnLMXBC2_b.BG = pextend->linearmatrix_cfg.bg & CAST_TO_UINT13;
        R_CRU->ICnLMXBC2_b.BB = pextend->linearmatrix_cfg.bb & CAST_TO_UINT13;
    }

    /** Statistics processing settings */
    if (0 == R_CRU->ICnMC_b.STITHR)
    {
        /* unit of operation selection */
        R_CRU->ICnSTIC1_b.STUNIT = pextend->statistics_cfg.stunit & CAST_TO_UINT2;

        /* sum of adjacent pixels */
        R_CRU->ICnSTIC1_b.STSADPOS = pextend->statistics_cfg.stsadpos & CAST_TO_UINT4;

        /* horizontal start position */
        R_CRU->ICnSTIC2_b.STHPOS = pextend->statistics_cfg.sthpos & CAST_TO_UINT9;
    }

    /** Color space conversion processing settings */
    if (0 == R_CRU->ICnMC_b.CSCTHR)
    {
        R_CRU->ICnYCCR3_b.YCLCEN   = 1;
        R_CRU->ICnCBCCR3_b.CBCLCEN = 1;
        R_CRU->ICnCRCCR3_b.CRCLCEN = 1;
    }

    /* Alpha value setting in ARGB format */
    R_CRU->ICnDMR_b.A8BIT = 0x00;

    /* YUV data order setting */
    if (r_cru_isoutput_yuv(pextend->color_output))
    {
        R_CRU->ICnDMR_b.YCMODE = capture_output_format[pextend->color_output] & CAST_TO_UINT3;
    }

    /* RGB data order setting */
    if (r_cru_isoutput_rgb(pextend->color_output))
    {
        R_CRU->ICnDMR_b.RGBMODE = capture_output_format[pextend->color_output] & CAST_TO_UINT2;
    }

    /* YUV output binary setting */
    R_CRU->ICnDMR_b.OBINSEL = 0;

    /* data clipping setting for YUV format */
    R_CRU->ICnMC_b.CLP = ICNMC_CL;

    /* Image Clipping */
    R_CRU->ICnSLPrC_b.SLPrC = p_cfg->y_capture_start_pixel & CAST_TO_UINT12;
    R_CRU->ICnELPrC_b.ELPrC = (p_cfg->y_capture_start_pixel + p_cfg->y_capture_pixels) & CAST_TO_UINT12;
    R_CRU->ICnSPPrC_b.SPPrC = p_cfg->x_capture_start_pixel & CAST_TO_UINT12;
    R_CRU->ICnEPPrC_b.EPPrC = (p_cfg->x_capture_start_pixel + p_cfg->x_capture_pixels) & CAST_TO_UINT12;
}

/*******************************************************************************************************************//**
 * Stop LINK packet
 *
 * @retval        none
 **********************************************************************************************************************/
static void r_cru_stop_linkpacket (void)
{
    /* wait for a frame to be received for a period of one frame */
    while (1 == R_CRU->CSI2nRXST_b.RACTDET)
    {
        /* clear CSI2nRXST.RACTDET */
        R_CRU->CSI2nRXSC_b.RACTDETC = 1;
    }
}

/*******************************************************************************************************************//**
 * Stop the D-PHY
 *
 * @retval        none
 **********************************************************************************************************************/
static void r_cru_stop_dphy (void)
{
    /* Reset the CRU (D-PHY) */
    R_CPG->CPG_RST_CRU_b.UNIT0_RSTB = 0;

    /* Stop the D-PHY clock */
    R_CPG->CPG_CLKON_CRU_b.CLK0_ON = 0;

    /* Cancel the EN_LDO1200 register settings */
    R_CRU->CSIDPHYCTRL0_b.EN_LDO1200 = 0;

    /* Cancel the EN_BGR register settings */
    R_CRU->CSIDPHYCTRL0_b.EN_BGR = 0;
}

/*******************************************************************************************************************//**
 * Stop the image processing
 *
 * @retval        none
 **********************************************************************************************************************/
static void r_cru_stop_imageprocessing (void)
{
    /* Stop the operation of Image Processing*/
    R_CRU->ICnEN_b.ICEN = 0;

    /* Image data has not been received yet */
    while (1 == R_CRU->ICnMS_b.IA)
    {
        /*
         * No operation
         */
    }

    /* wait until the FIFO becomes empty */
    while (R_CRU->AMnFIFOPNTR_b.FIFORPNTR_Y != R_CRU->AMnFIFOPNTR_b.FIFOWPNTR)
    {
        /*
         * No operation
         */
    }

    /* Request the AXI bus to stop */
    R_CRU->AMnAXISTP_b.AXI_STOP = 1;

    /* Check AXi bus stopped */
    while (0 == R_CRU->AMnAXISTPACK_b.AXI_STOP_ACK)
    {
        /*
         * No operation
         */
    }

    /* Cancel the AXI bus stop request */
    R_CRU->AMnAXISTP_b.AXI_STOP = 0;

    /* Stop processing Statistics data */
    if (0 == R_CRU->AMnSDAXISTPACK_b.SDAXISTOPACK)
    {
        while (R_CRU->AMnSDFIFOPNTR_b.SDFIFORPNTR != R_CRU->AMnSDFIFOPNTR_b.SDFIFOWPNTR)
        {
            /*
             * No operation
             */
        }

        /* Request the AXI bus to stop */
        R_CRU->AMnSDAXISTP_b.SDAXISTOP = 1;

        /* Check AXi bus stopped */
        while (0 == R_CRU->AMnSDAXISTPACK_b.SDAXISTOPACK)
        {
            /*
             * No operation
             */
        }

        /* Cancel the AXI bus stop request */
        R_CRU->AMnSDAXISTP_b.SDAXISTOP = 0;
    }

    /* Reset the CRU */
    R_CPG->CPG_RST_CRU_b.UNIT2_RSTB = 0;

    /* Reset the CRU */
    R_CRU->CRUnRST_b.VRESETN = 0;
}

/*******************************************************************************************************************//**
 * Set the interrupt settings for CRU module
 *
 * @param[in]       p_instance_ctrl         CRU instance control block
 * @retval          none
 **********************************************************************************************************************/
static void r_cru_interrupt_enable (cru_instance_ctrl_t * const p_instance_ctrl)
{
    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    /* Enable interrupt register for image conv int */
    R_CRU->CRUnIE_b.SFE = (pextend->interrupt_enable) & CAST_TO_UINT1;
    R_CRU->CRUnIE_b.EFE = (pextend->interrupt_enable >> 1) & CAST_TO_UINT1;
    R_CRU->CRUnIE_b.SIE = (pextend->interrupt_enable >> 2) & CAST_TO_UINT1;
    R_CRU->ICnSI_b.SI   = (pextend->scan_line_num) & CAST_TO_UINT12;

    if (pextend->image_conv_int_irq >= 0)
    {
        R_BSP_IrqCfgEnable(pextend->image_conv_int_irq, pextend->image_conv_int_ipl, p_instance_ctrl);
    }
    else
    {
        /* Do Nothing */
    }
}

/*******************************************************************************************************************//**
 * Interrupt function for CRU Image Conv Interrupt
 *
 * @param[in]       irq     FSP error type
 * @retval          none
 **********************************************************************************************************************/
void cru_image_conv_int (IRQn_Type const irq)
{
    FSP_CONTEXT_SAVE FSP_PARAMETER_NOT_USED(irq);

    camera_callback_args_t args;
    uint32_t               event_flag;
    uint32_t               scan_line_flag;
    uint32_t               frame_end_flag;
    uint32_t               frame_start_flag;
    uint32_t               reg_val;
    cru_instance_ctrl_t  * p_ctrl = (cru_instance_ctrl_t *) r_cru_blk.p_context;

    /* clear event flag */
    event_flag = 0;

    /* get register value of  interrupt status (CRUnINIS) */
    reg_val          = R_CRU->CRUnINTS;
    scan_line_flag   = (reg_val >> 18) & CAST_TO_UINT1;
    frame_end_flag   = (reg_val >> 17) & CAST_TO_UINT1;
    frame_start_flag = (reg_val >> 16) & CAST_TO_UINT1;

    /* Check which interrupt is generated */
    if (1 == frame_start_flag)
    {
        event_flag |= CRU_EVENT_FRAME_START;
    }
    else
    {
        /* Do Nothing */
    }

    if (1 == frame_end_flag)
    {
        event_flag |= CRU_EVENT_FRAME_END;
    }
    else
    {
        /* Do Nothing */
    }

    if (1 == scan_line_flag)
    {
        event_flag |= CRU_EVENT_SCAN_LINE;
    }
    else
    {
        /* Do Nothing */
    }

    /* Call back callback function if it is registered */
    if (NULL != p_ctrl->p_callback)
    {
        args.event     = event_flag;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear interrupt flag */
    if (1 == scan_line_flag)
    {
        R_CRU->CRUnINTS_b.SIS = 1;
    }
    else
    {
        /* Do Nothing */
    }

    if (1 == frame_end_flag)
    {
        R_CRU->CRUnINTS_b.EFS = 1;
    }
    else
    {
        /* Do Nothing */
    }

    if (1 == frame_start_flag)
    {
        R_CRU->CRUnINTS_b.SFS = 1;
    }
    else
    {
        /* Do Nothing */
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

#if (CRU_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * Parameter Checking for R_CRU_Open.
 *
 * @param[in]       p_cfg       CRU configuration parameters
 * @retval          FSP_SUCCESS                       No parameter error found
 * @retval          FSP_ERR_ASSERTION                 Pointer to the control block is NULL.
 * @retval          FSP_ERR_INVALID_ARGUMENT          Invalid argument error
 * @retval          FSP_ERR_INVALID_ALIGNMENT         Input buffer alignment
 **********************************************************************************************************************/
static fsp_err_t r_cru_open_param_check (cru_cfg_t const * const p_cfg)
{
    fsp_err_t error;

    FSP_ASSERT(p_cfg);

    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_cfg->p_extend;

    /* check parameter for capture size */
    error = r_cru_open_param_check_size_setting(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == error, error);

    /* check parameter for buffer address alignment */
    error = r_cru_open_param_check_buffer_setting(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == error, error);

    /* check parameter for color format */
    FSP_ERROR_RETURN((pextend->color_input >= INPUT_FORMAT_MIN_INVLID), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((pextend->color_input <= INPUT_FORMAT_MAX_INVLID), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((pextend->color_output >= OUTPUT_FORMAT_MIN_INVLID), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((pextend->color_output <= OUTPUT_FORMAT_MAX_INVLID), FSP_ERR_INVALID_ARGUMENT);

    /* check parameter for number datalane */
    FSP_ERROR_RETURN((pextend->num_datalane ==
                      CRU_DATALANE_1) |
                     (pextend->num_datalane == CRU_DATALANE_2) | (pextend->num_datalane == CRU_DATALANE_4),
                     FSP_ERR_INVALID_ARGUMENT);

    /* check parameter for number of buffers */
    FSP_ERROR_RETURN(p_cfg->buffer_cfg.num_buffers >= BUFFER_NUM_MIN, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->buffer_cfg.num_buffers <= BUFFER_NUM_MAX, FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Cheking parameters of capture size setting.
 *
 * @param[in]       p_cfg                                   CRU configuration parameters
 * @retval          FSP_SUCCESS                             No parameter error found
 * @retval          FSP_ERR_INVALID_ARGUMENT                Invalid argument error
 **********************************************************************************************************************/
static fsp_err_t r_cru_open_param_check_size_setting (cru_cfg_t const * const p_cfg)
{
    FSP_ERROR_RETURN(p_cfg->x_capture_start_pixel + p_cfg->x_capture_pixels >= CAPTURE_HSIZE_MIN,
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->y_capture_start_pixel + p_cfg->y_capture_pixels >= CAPTURE_VSIZE_MIN,
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->x_capture_start_pixel + p_cfg->x_capture_pixels <= CAPTURE_HSIZE_MAX,
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->y_capture_start_pixel + p_cfg->y_capture_pixels <= CAPTURE_VSIZE_MAX,
                     FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->x_capture_start_pixel <= CAPTURE_HSIZE_MAX, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->y_capture_start_pixel <= CAPTURE_VSIZE_MAX, FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Cheking parameters of buffer address alignment setting.
 *
 * @param[in]       p_cfg                           CRU configuration parameters
 * @retval          FSP_SUCCESS                     No parameter error found
 * @retval          FSP_ERR_INVALID_ALIGNMENT       Input buffer alignment
 * @retval          FSP_ERR_INVALID_ARGUMENT        input buffer address is NULL
 **********************************************************************************************************************/
static fsp_err_t r_cru_open_param_check_buffer_setting (cru_cfg_t const * const p_cfg)
{
    uint32_t i;

    if (p_cfg->buffer_cfg.pp_buffer[0])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[0]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[1])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[1]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[2])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[2]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[3])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[3]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[4])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[4]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[5])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[5]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[6])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[6]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    if (p_cfg->buffer_cfg.pp_buffer[7])
    {
        FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->buffer_cfg.pp_buffer[7]) & CAST_TO_UINT32) % BUFFER_ALIGNMENT_512),
                         FSP_ERR_INVALID_ALIGNMENT);
    }
    else
    {
        /* Do Nothing */
    }

    for (i = 0; i < p_cfg->buffer_cfg.num_buffers; i++)
    {
        if (p_cfg->buffer_cfg.pp_buffer[i] == NULL)
        {
            return FSP_ERR_INVALID_ARGUMENT;
        }
    }

 #if STATISTICS_ENABLE
    cru_extended_cfg_t * pextend = (cru_extended_cfg_t *) p_cfg->p_extend;

    for (i = 0; i < pextend->statistics_cfg.num_buffers; i++)
    {
        if (pextend->statistics_cfg.pp_buffer[i] == NULL)
        {
            return FSP_ERR_INVALID_ARGUMENT;
        }
    }
 #endif

    return FSP_SUCCESS;
}

#endif
