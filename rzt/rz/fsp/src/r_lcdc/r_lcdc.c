/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_lcdc.h"
#include "r_lcdc_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define LCDC_DUMMY_READ_FOR_MODULE_START      (100)

/* Fixed value for LCDC peripheral specification */

/* DU_PBCR.PB_DEP[4:0] must be 0x1F */
#define LCDC_DU_PBCR0                         (0x0000001F)

/* value for enable clock stop function */
#define LCDC_VSPD_CLK_CTRL0                   (0x00000000)
#define LCDC_VSPD_CLK_CTRL1                   (0x00000000)
#define LCDC_VSPD_CLK_DCSWT                   (0x00000808)
#define LCDC_VSPD_CLK_DCSM0                   (0x00000000)
#define LCDC_VSPD_CLK_DCSM1                   (0x00000000)

/* VI6_DL_CTRL.AR_WAIT[15:0] must be 256 */
#define LCDC_VSPD_DL_CTRL                     (0x0100)

/* VI6_LIF0_CTRL.OBTH[11:0] must be 1500 */
#define LCDC_VSPD_LIF_CTRL_OBTH               (0x5DC)

/* VI6_LIF0_LBA.LBA1[11:0] must be 1536 */
#define LCDC_VSPD_LIF_CTRL_LBA1               (0x600)

/* VI6_DPR_WPF0_FPORCH.FP_WPF0[5:0] must be 5 */
#define LCDC_VSPD_DPR_WPF0_FPROCH             (0x05)

/* VI6_DPR_BRS_ROUTE.BRSSEL must be 1 */
#define LCDC_VSPD_DPR_ILV_BRS_ROUTE_BRSSEL    (1)

#define LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF0      (0x27)
#define LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF1      (0x26)
#define LCDC_VSPD_DPR_LUT_ROUTE               (0x3F)
#define LCDC_VSPD_DPR_ILV_BRS_ROUTE_RT        (0x38)

#define LCDC_VSPD_BRSA_CTRL_RBC               (1)
#define LCDC_VSPD_BRSA_CTRL_DSTSEL            (1)
#define LCDC_VSPD_BRSA_CTRL_SRCSEL            (4)
#define LCDC_VSPD_BRSA_BLD_CCMDX              (0)
#define LCDC_VSPD_BRSA_BLD_CCMDY              (1)
#define LCDC_VSPD_BRSA_BLD_ACMDX              (4)
#define LCDC_VSPD_BRSA_BLD_ACMDY              (1)
#define LCDC_VSPD_BRSA_BLD_COEFX              (255)
#define LCDC_VSPD_BRSB_CTRL_SRCSEL            (4)
#define LCDC_VSPD_BRSB_BLD_CCMDX              (3)
#define LCDC_VSPD_BRSB_BLD_CCMDY              (2)
#define LCDC_VSPD_BRSB_BLD_ACMDX              (3)
#define LCDC_VSPD_BRSB_BLD_ACMDY              (4)
#define LCDC_VSPD_BRSB_BLD_COEFY              (255)

/* Value for VI6_WPF0_SRCRPF (RPF0, RPF1 and Virtual RPF status) setting */
#define LAYER_STATUS_INIT                     (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos)
#define LAYER_ENABLE_1                        (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos | \
                                               1U << R_LCDC_VI6_WPF0_SRCRPF_RPF0_ACT_Pos)
#define LAYER_ENABLE_2                        (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos | \
                                               1U << R_LCDC_VI6_WPF0_SRCRPF_RPF1_ACT_Pos)
#define LAYER_ENABLE_ALL                      (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos | \
                                               1U << R_LCDC_VI6_WPF0_SRCRPF_RPF1_ACT_Pos | \
                                               1U << R_LCDC_VI6_WPF0_SRCRPF_RPF0_ACT_Pos)
#define LAYER_DISABLE_1                       (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos | \
                                               1U << R_LCDC_VI6_WPF0_SRCRPF_RPF1_ACT_Pos)
#define LAYER_DISABLE_2                       (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos | \
                                               1U << R_LCDC_VI6_WPF0_SRCRPF_RPF0_ACT_Pos)
#define LAYER_DISABLE_ALL                     (2U << R_LCDC_VI6_WPF0_SRCRPF_VIR_ACT2_Pos)

/* Value for VI6_RPFn_INFMT.CSC(Color Space Conversion Enable) setting */
#define COLOR_FOTMAT_CONVERT                  (1U << R_LCDC_VI6_RPF0_INFMT_CSC_Pos)

/* Value for display signal parameter check. */
#define TIMING_MAX_1920                       (1920)
#define TIMING_MAX_1080                       (1080)
#define LAYER_MAX_HSIZE                       (1920)
#define LAYER_MAX_VSIZE                       (1080)

#define LCDC_DU_DITR1_VSA_MAX                 (4095)
#define LCDC_DU_DITR1_VACTIVE_MIN             (1)
#define LCDC_DU_DITR1_VACTIVE_MAX             (8190)
#define LCDc_DU_DITR2_VBP_MAX                 (8191)
#define LCDC_DU_DITR2_VFP_MAX                 (8191)

#define LCDC_DU_DITR3_HSA_MAX                 (4095)
#define LCDC_DU_DITR3_HACTIVE_MIN             (1)
#define LCDC_DU_DITR3_HACTIVE_MAX             (8190)
#define LCDC_DU_DITR4_HBP_MAX                 (8191)
#define LCDC_DU_DITR4_HFP_MAX                 (8191)

#define CAST_TO_UINT32                        (0xFFFFFFFFU)
#define DL_NUM_CMD                            (25)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Address and data to set display list */
typedef struct st_set_address_data
{
    uint32_t set_address;
    uint32_t set_data;
} set_address_data_t;

/* The structure for display list definition */
typedef struct st_display_list_data_type
{
    set_address_data_t cmd[DL_NUM_CMD];
} display_list_data_type_t;

/* The structure for the layer parameter recalculation */
typedef struct st_lcdc_recalculated_param
{
    uint32_t   hsize;
    uint32_t   vsize;
    uint32_t   coor_x;
    uint32_t   coor_y;
    uint32_t * p_base;
    uint32_t * p_base_cb;
    uint32_t * p_base_cr;
} lcdc_recalculated_param_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_lcdc_du_set(display_cfg_t const * const p_cfg);
static void r_lcdc_clock_set(void);
static void r_lcdc_dl_set(void);
static void r_lcdc_dl_address_set(display_cfg_t const * const p_cfg);
static void r_lcdc_lif_set(void);
static void r_lcdc_layer1_set(lcdc_instance_ctrl_t * p_ctrl, display_cfg_t const * const p_cfg);
static void r_lcdc_layer2_set(lcdc_instance_ctrl_t * p_ctrl, display_cfg_t const * const p_cfg);
static void r_lcdc_layer_cfg_recaluclate(display_input_cfg_t const * const p_input,
                                         lcdc_recalculated_param_t       * p_recalculated);
static void r_lcdc_output_set(display_cfg_t const * const p_cfg);
static void r_lcdc_dpr_set(void);
static void r_lcdc_brs_set(void);
static void r_lcdc_layer_change(lcdc_instance_ctrl_t              * p_ctrl,
                                display_runtime_cfg_t const * const p_rt_cfg,
                                display_frame_layer_t               layer);
static void r_lcdc_ckey_set(display_colorkeying_layer_t ck_cfg, display_frame_layer_t layer);
static void r_lcdc_interrupt_enable(display_cfg_t const * const p_cfg, lcdc_instance_ctrl_t * const p_instance_ctrl);

void lcdc_vspd_int(void);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
static fsp_err_t r_lcdc_open_param_check(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_sync_signal(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_display_cycle(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_display_timing(display_cfg_t const * const p_cfg);
static fsp_err_t r_lcdc_open_param_check_layer_setting(display_cfg_t const * const p_cfg);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Display list body. */
static display_list_data_type_t g_dl_body BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".noncache_buffer");

/* This table is used for Color Format setting
 * For example, selected RGB565 as input format, 0x00000006 is written to the RDFMT bits in VI6_RPFn_INFMT */
static const uint32_t display_format_table[] =
{
    /* Common input format */
    0x00000013,                        /* ARGB8888,                       32 bits */
    0x00000000,                        /* RGB888,                         32 bits (Not supported) */
    0x00000006,                        /* RGB565,                         16 bits */
    0x00000000,                        /* ARGB1555                        16 bits (Not supported) */
    0x00000000,                        /* ARGB4444                        16 bits (Not supported) */
    0x00000000,                        /* CLUT8 (Not supported) */
    0x00000000,                        /* CLUT4 (Not supported) */
    0x00000000,                        /* CLUT1 (Not supported) */
    /* Extend input format */
    0x00000014,                        /* RGBA8888,                        24 bits */
    0x00000018,                        /* BGR888,                          24 bits */
    0x00000015,                        /* RGB888,                          24 bits */
    0x00000022,                        /* ABGR8888,                        24 bits */
    0x00000146,                        /* YCbCr444 interleaved,            24 bits */
    0x00000147,                        /* YCbCr422 interleaved type0 UYVY, 16 bits */
    0x00008147,                        /* YCbCr422 interleaved type0 YUY2, 16 bits */
    0x0000C147,                        /* YCbCr422 interleaved type0 YVYU, 16 bits */
    0x00000148,                        /* YCbCr420 interleaved type1,      16 bits */
    0x00000149,                        /* YCbCr420 interleaved,            16 bits */
    0x0000014C,                        /* YCbCr420 Planar                  16 bits */
};

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* LCDC function pointers */
const display_api_t g_display_on_lcdc =
{
    .open         = R_LCDC_Open,
    .close        = R_LCDC_Close,
    .start        = R_LCDC_Start,
    .stop         = R_LCDC_Stop,
    .layerChange  = R_LCDC_LayerChange,
    .bufferChange = R_LCDC_BufferChange,
    .clut         = R_LCDC_ClutUpdate,
    .clutEdit     = R_LCDC_ClutEdit,
    .correction   = R_LCDC_ColorCorrection,
    .colorKeySet  = R_LCDC_ColorKeySet,
    .statusGet    = R_LCDC_StatusGet,
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_LCDC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *　Initializes the LCDC modules and enables interrupts
 *
 * @retval FSP_SUCCESS Initializes the LCDC modules.
 * @retval FSP_ERR_ALREADY_OPEN             LCDC module is open already.
 * @retval FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_TIMING_SETTING   Invalid timing parameter.
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Open (display_ctrl_t * const p_api_ctrl, display_cfg_t const * const p_cfg)
{
    fsp_err_t              err    = FSP_SUCCESS;
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;

#if  (LCDC_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters */
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(p_ctrl->state <= DISPLAY_STATE_CLOSED, FSP_ERR_ALREADY_OPEN);
    err = r_lcdc_open_param_check(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    p_ctrl->p_cfg      = p_cfg;
    p_ctrl->p_context  = p_cfg->p_context;
    p_ctrl->p_callback = p_cfg->p_callback;

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_LCDC, 0);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Dummy-read any register of the LCDC module which is being released from the module-stop state at least 100 times
     * (See section "Module-Stop Function" in the RZ microprocessor Hardware Manual for details) */
    for (uint32_t i = 0; i < LCDC_DUMMY_READ_FOR_MODULE_START; i++)
    {
        FSP_REGISTER_READ(R_LCDC->DU_MCR0);
    }

    /* DU Initialization */
    r_lcdc_du_set(p_cfg);

    /* Clock Setting */
    r_lcdc_clock_set();

    /* Enable LCDC Interrupt */
    r_lcdc_interrupt_enable(p_cfg, p_api_ctrl);

    /* Initialize Layer Status */
    p_ctrl->layer_status = LAYER_STATUS_INIT;

    /* Layer 1 Setting (RPF0) */
    r_lcdc_layer1_set(p_ctrl, p_cfg);

    /* Layer 2 Setting (RPF1) */
    r_lcdc_layer2_set(p_ctrl, p_cfg);

    /* Output Setting */
    r_lcdc_output_set(p_cfg);

    /* Display List Initialization */
    r_lcdc_dl_set();

    /* Display List Body Address Set */
    r_lcdc_dl_address_set(p_cfg);

    /* LIF(Display Unit InterFace) Setting */
    r_lcdc_lif_set();

    /* DPR(Data Path Router) Setting */
    r_lcdc_dpr_set();

    /* BRS(Blend ROP Sub Unit) Setting */
    r_lcdc_brs_set();

    /* Start WPF(Write Pixel Formatter)
     * (see Section 'Operation flow of VSPD and DU' in the RZ microprocessor manual */
    R_LCDC->VI6_CMD0_b.STRCMD = 1;

    /* Wait Display start interrupt */
    FSP_HARDWARE_REGISTER_WAIT(R_LCDC->VI6_DISP0_IRQ_STA_b.DST, 1);

    /* Enable display */
    R_LCDC->DU_MCR0_b.DI_EN = 1;

    p_ctrl->state = DISPLAY_STATE_OPENED;

    return err;
}

/*******************************************************************************************************************//**
 * Close the display while the LCDC module is operating
 *
 * @retval FSP_SUCCESS          Close the LCDC module
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_NOT_OPEN     LCDC module is not open
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Close (display_ctrl_t * const p_api_ctrl)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(DISPLAY_STATE_CLOSED != p_ctrl->state, FSP_ERR_NOT_OPEN);
#endif

    /* To close LCDC driver, follow the procedure in hardware manual (see Section
     * 'To stop image process immediately' of 'Operation Control Setting' in the RZ microprocessor manual). */

    /* Display Disable */
    R_LCDC->DU_MCR0_b.DI_EN = 0;

    /* Set the VI6_WPF0_IRQ_ENB.FREE bit to 1 so that frame end interrupt can be issued */
    R_LCDC->VI6_WPF0_IRQ_ENB_b.FREE = 1;

    /* Clear the frame end interrupt status here to confirm the frame end interrupt due to software reset */
    R_LCDC->VI6_WPF0_IRQ_STA_b.FRE = 0;

    /* Set the VI6_SRESET.SRST0 bit to 1. VSPD will invoke termination process immediately */
    R_LCDC->VI6_SRESET_b.SRST0 = 1;

    /* Wait frame end interruption from VSPD or until the VI6_WPF0_IRQ_STA.FRE bit is set to 1 */
    FSP_HARDWARE_REGISTER_WAIT(((R_LCDC->VI6_WPF0_IRQ_STA_b.FRE == 0) && (R_LCDC->VI6_STATUS_b.SYS0_ACT == 1)), 0);

    /* Wait until the DU_MSR0.ST_DI_BSY bit becomes 0.
     * After it occurs, DU has stopped outputting. */
    FSP_HARDWARE_REGISTER_WAIT(R_LCDC->DU_MSR0_b.ST_DI_BSY, 0)

    /* Set the VI6_WPF0_IRQ_STA.FRE and VI6_DISP0_IRQ_STA.DST bits to 0.
     * VSPD will clear interrupts. */
    R_LCDC->VI6_WPF0_IRQ_STA_b.FRE  = 0;
    R_LCDC->VI6_DISP0_IRQ_STA_b.DST = 0;

    /* Set the DU_MCR0.PB_CLR bit to 1 so that PBUF can be cleared */
    R_LCDC->DU_MCR0_b.PB_CLR = 1;

    /* Wait until the DU_MSR0.ST_PB_WINIT and DU_MSR0.ST_PB_RINIT bits become 1 */
    FSP_HARDWARE_REGISTER_WAIT(R_LCDC->DU_MSR0_b.ST_PB_WINIT, 1);
    FSP_HARDWARE_REGISTER_WAIT(R_LCDC->DU_MSR0_b.ST_PB_RINIT, 1);

    /* Set the DU_MCR0.PB_CLR bit to 0 */
    R_LCDC->DU_MCR0_b.PB_CLR = 0;

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_LCDC, 0);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    p_ctrl->last_layer_status = 0x0;

    p_ctrl->state = DISPLAY_STATE_CLOSED;

    return err;
}

/*******************************************************************************************************************//**
 * Start displaying a layer image. It is possible when LCDC state is open
 *
 * @retval FSP_SUCCESS          Start display Normally
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_NOT_OPEN     LCDC module is not open
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Start (display_ctrl_t * const p_api_ctrl)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(DISPLAY_STATE_OPENED == p_ctrl->state, FSP_ERR_NOT_OPEN);
#endif

    if (p_ctrl->last_layer_status != 0x0)
    {
        /* Restores the status stored by R_LCDC_Stop() */
        p_ctrl->layer_status = p_ctrl->last_layer_status;
    }

    /* RPF0(if layer1 is used), RPF1(if layer 2 is used) and Virtual RPF start enable via display list */
    g_dl_body.cmd[0].set_data = p_ctrl->layer_status;

    /* Display List Update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;

    /* Display parallel interface output enable */
    R_LCDC->DU_MCR0_b.DPI_OE = 1;

    p_ctrl->state = DISPLAY_STATE_DISPLAYING;

    return err;
}

/*******************************************************************************************************************//**
 * Start displaying a layer image. It is possible when LCDC state is displaying
 *
 * @retval FSP_SUCCESS              Stop the LCDC module
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     LCDC module status is invalid for R_LCDC_Stop API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_Stop (display_ctrl_t * const p_api_ctrl)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    fsp_err_t              err    = FSP_SUCCESS;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

    /* Store the current state to resume with the R_LCDC_Start() again */
    p_ctrl->last_layer_status = p_ctrl->layer_status;

    /* Disable All Layers */
    p_ctrl->layer_status &= LAYER_DISABLE_ALL;

    /* RPF0(if layer1 is used), RPF1(if layer 2 is used) and Virtual RPF start disable via display list */
    g_dl_body.cmd[0].set_data = p_ctrl->layer_status;

    /* Display List Update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;

    /* Display parallel interface output disable */
    R_LCDC->DU_MCR0_b.DPI_OE = 0;

    p_ctrl->state = DISPLAY_STATE_OPENED;

    return err;
}

/*******************************************************************************************************************//**
 * Change layer configurations. It is possible when LCDC state is displaying
 *
 * @retval FSP_SUCCESS                      The LCDC layer is changed
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 * @retval FSP_ERR_ASSERTION                Pointer to the control block and configuration structure is NULL.
 * @retval FSP_ERR_INVALID_MODE             LCDC module status is invalid for R_LCDC_LayerChange API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_LayerChange (display_ctrl_t const * const        p_api_ctrl,
                              display_runtime_cfg_t const * const p_cfg,
                              display_frame_layer_t               layer)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

    /* Check Layer runtime parameter */
    FSP_ERROR_RETURN((p_cfg->input.hsize <= LAYER_MAX_HSIZE), FSP_ERR_INVALID_LAYER_SETTING);
    FSP_ERROR_RETURN((p_cfg->input.vsize <= LAYER_MAX_VSIZE), FSP_ERR_INVALID_LAYER_SETTING);

    /* Check layer number */
    FSP_ERROR_RETURN((layer == 0 || layer == 1), FSP_ERR_INVALID_LAYER_SETTING);

    /* Change Layer Parameters */
    r_lcdc_layer_change(p_ctrl, p_cfg, layer);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Change Buffer configuration. It is possible when LCDC state is displaying
 *
 * @retval FSP_SUCCESS              The Buffer read by LCDC is changed
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 * @retval FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     LCDC module status is invalid for R_LCDC_BufferChange API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_BufferChange (display_ctrl_t const * const p_api_ctrl,
                               uint8_t * const              framebuffer,
                               display_frame_layer_t        layer)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* Check layer number */
    FSP_ERROR_RETURN((layer == 0 || layer == 1), FSP_ERR_INVALID_LAYER_SETTING);

    /* Display List Setting. Set data to Display List Body. */
    if (layer == DISPLAY_FRAME_LAYER_1)
    {
        if (framebuffer == NULL)
        {
            /* Disable Layer1 (RPF0) */
            p_ctrl->layer_status &= LAYER_DISABLE_1;

            /* Set Layer1's buffer address (NULL) via Display List Body */
            g_dl_body.cmd[1].set_data = (uintptr_t) framebuffer & CAST_TO_UINT32;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            p_ctrl->layer_status |= LAYER_ENABLE_1;

            /* Set Layer1's buffer address via Display List Body */
#if defined(BSP_CFG_CORE_CA55)
            va = (uint64_t) framebuffer & CAST_TO_UINT32;
            R_BSP_MmuVatoPa(va, (void *) &pa);
            g_dl_body.cmd[1].set_data = pa & CAST_TO_UINT32;
#else
            g_dl_body.cmd[1].set_data = (uint32_t) framebuffer & CAST_TO_UINT32;
#endif
        }
    }
    else if (layer == DISPLAY_FRAME_LAYER_2)
    {
        if (framebuffer == NULL)
        {
            /* Disable Layer1 (RPF0) */
            p_ctrl->layer_status &= LAYER_DISABLE_2;

            /* Set layer2's buffer address (NULL) via Display List Body */
            g_dl_body.cmd[11].set_data = (uintptr_t) framebuffer & CAST_TO_UINT32;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            p_ctrl->layer_status |= LAYER_ENABLE_2;

            /* Set Layer2's buffer address via Display List Body */
#if defined(BSP_CFG_CORE_CA55)
            va = (uint64_t) framebuffer & CAST_TO_UINT32;
            R_BSP_MmuVatoPa(va, (void *) &pa);
            g_dl_body.cmd[11].set_data = pa & CAST_TO_UINT32;
#else
            g_dl_body.cmd[11].set_data = (uint32_t) framebuffer & CAST_TO_UINT32;
#endif
        }
    }
    else
    {
        /* Do Nothing */
    }

    /* RPF0(if layer1 is used), RPF1(if layer 2 is used) and Virtual RPF start disable via display list */
    g_dl_body.cmd[0].set_data = p_ctrl->layer_status;

    /* Display List Update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported color correction function. Implements display_api_t::correction.
 *
 * @retval FSP_ERR_UNSUPPORTED      Color correction is not supported.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ColorCorrection (display_ctrl_t const * const       p_api_ctrl,
                                  display_correction_t const * const p_correction)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_correction);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported CLUT update function. Implements display_api_t::clut.
 *
 * @retval FSP_ERR_UNSUPPORTED      CLUT update is not supported.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ClutUpdate (display_ctrl_t const * const     p_api_ctrl,
                             display_clut_cfg_t const * const p_clut_cfg,
                             display_frame_layer_t            layer)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_clut_cfg);
    FSP_PARAMETER_NOT_USED(layer);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Placeholder for unsupported CLUT edit function. Implements display_api_t::clutEdit.
 *
 * @retval FSP_ERR_UNSUPPORTED      CLUT edit is not supported.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ClutEdit (display_ctrl_t const * const p_api_ctrl,
                           display_frame_layer_t        layer,
                           uint8_t                      index,
                           uint32_t                     color)
{
    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(layer);
    FSP_PARAMETER_NOT_USED(index);
    FSP_PARAMETER_NOT_USED(color);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Set the Color Keying Configuration. It is possible when LCDC state is displaying.
 *
 * @retval FSP_SUCCESS                      The source color is changed to destination color
 * @retval FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 * @retval FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE             LCDC module status is invalid for R_LCDC_ColorKeying API
 **********************************************************************************************************************/
fsp_err_t R_LCDC_ColorKeySet (display_ctrl_t const * const p_api_ctrl,
                              display_colorkeying_layer_t  ck_cfg,
                              display_frame_layer_t        layer)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN((DISPLAY_STATE_DISPLAYING == p_ctrl->state), FSP_ERR_INVALID_MODE);
#endif

    /* Check layer number */
    FSP_ERROR_RETURN((layer == 0 || layer == 1), FSP_ERR_INVALID_LAYER_SETTING);

    /* Color Keying set */
    r_lcdc_ckey_set(ck_cfg, layer);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Get the current status of LCDC module. (close or open or displaying)
 *
 * @retval FSP_SUCCESS      Get status of LCDC module
 * @retval FSP_ERR_ASSERTION    Pointer to the control block and status structure is NULL.
 **********************************************************************************************************************/
fsp_err_t R_LCDC_StatusGet (display_ctrl_t const * const p_api_ctrl, display_status_t * const p_status)
{
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) p_api_ctrl;
    FSP_PARAMETER_NOT_USED(p_ctrl);

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ASSERT(p_status);
#endif

    p_status->state = p_ctrl->state;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup LCDC)
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
 * Display Unit setting function. This function can set signal timing setting.
 *
 * @param[in]       p_cfg       LCDC configuration parameters.
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_du_set (display_cfg_t const * const p_cfg)
{
    /* Set each signal polarity */
    uint32_t demd      = (p_cfg->output.data_enable_polarity == DISPLAY_SIGNAL_POLARITY_LOACTIVE) ? 0U : 3U;
    uint32_t hspol     = (p_cfg->output.htiming.sync_polarity == DISPLAY_SIGNAL_POLARITY_LOACTIVE) ? 0U : 1U;
    uint32_t vspol     = (p_cfg->output.vtiming.sync_polarity == DISPLAY_SIGNAL_POLARITY_LOACTIVE) ? 0U : 1U;
    uint32_t dpi_clkmd = (p_cfg->output.sync_edge == DISPLAY_SIGNAL_SYNC_EDGE_FALLING) ? 1U : 0U;

    /* Set Horizontal signal timings */
    uint32_t h_active = p_cfg->output.htiming.display_cyc;
    uint32_t h_sa     = p_cfg->output.htiming.sync_width;
    uint32_t h_bp     = (uint32_t) (p_cfg->output.htiming.back_porch - p_cfg->output.htiming.sync_width);
    uint32_t h_fp     =
        (uint32_t) (p_cfg->output.htiming.total_cyc - p_cfg->output.htiming.back_porch -
                    p_cfg->output.htiming.display_cyc);

    /* Set Vertical signal timings */
    uint32_t v_active = p_cfg->output.vtiming.display_cyc;
    uint32_t v_sa     = p_cfg->output.vtiming.sync_width;
    uint32_t v_bp     = (uint32_t) (p_cfg->output.vtiming.back_porch - p_cfg->output.vtiming.sync_width);
    uint32_t v_fp     =
        (uint32_t) (p_cfg->output.vtiming.total_cyc - p_cfg->output.vtiming.back_porch -
                    p_cfg->output.vtiming.display_cyc);

    /* Write registers */
    R_LCDC->DU_DITR0 = (hspol << R_LCDC_DU_DITR0_HSPOL_Pos) |
                       (vspol << R_LCDC_DU_DITR0_VSPOL_Pos) |
                       (demd << R_LCDC_DU_DITR0_DEMD_Pos) |
                       (dpi_clkmd << R_LCDC_DU_DITR0_DPI_CLKMD_Pos);

    R_LCDC->DU_DITR3 = (h_active << R_LCDC_DU_DITR3_HACTIVE_Pos) |
                       (h_sa << R_LCDC_DU_DITR3_HSA_Pos);
    R_LCDC->DU_DITR4 = (h_fp << R_LCDC_DU_DITR4_HFP_Pos) |
                       (h_bp << R_LCDC_DU_DITR4_HBP_Pos);

    R_LCDC->DU_DITR1 = (v_active << R_LCDC_DU_DITR1_VACTIVE_Pos) |
                       (v_sa << R_LCDC_DU_DITR1_VSA_Pos);
    R_LCDC->DU_DITR2 = (v_fp << R_LCDC_DU_DITR2_VFP_Pos) |
                       (v_bp << R_LCDC_DU_DITR2_VBP_Pos);

    /* Fixed value */
    R_LCDC->DU_PBCR0 = LCDC_DU_PBCR0;
}

/*******************************************************************************************************************//**
 * Subroutine to configure dot clock setting
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_clock_set (void)
{
    /* Set the registers related to clock settings to enable clock stop function for reducing power consumption.
     * (See Section "VI6_CLK_CTRL0 : Clock Control Register 0" of the RZ microprocessor manual) */
    R_LCDC->VI6_CLK_CTRL0 = LCDC_VSPD_CLK_CTRL0;
    R_LCDC->VI6_CLK_CTRL1 = LCDC_VSPD_CLK_CTRL1;
    R_LCDC->VI6_CLK_DCSWT = LCDC_VSPD_CLK_DCSWT;
    R_LCDC->VI6_CLK_DCSM0 = LCDC_VSPD_CLK_DCSM0;
    R_LCDC->VI6_CLK_DCSM1 = LCDC_VSPD_CLK_DCSM1;
}

/*******************************************************************************************************************//**
 * Display list setting.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_dl_set (void)
{
#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    /* Set display list operation.
     *  - AR_WAIT[15:0] must be fixed value
     *  - The next frame is automatically started
     *  - Don't use Display List Header (Header-less Mode)
     *  - The display list function is enabled */
    R_LCDC->VI6_DL_CTRL = (LCDC_VSPD_DL_CTRL << R_LCDC_VI6_DL_CTRL_AR_WAIT_Pos) |
                          (1U << R_LCDC_VI6_DL_CTRL_CFM0_Pos) |
                          (1U << R_LCDC_VI6_DL_CTRL_NH0_Pos) |
                          (1U << R_LCDC_VI6_DL_CTRL_DLE0_Pos);

    /* Display list body size setting */
    R_LCDC->VI6_DL_BODY_SIZE0_b.BS0 = sizeof(display_list_data_type_t);

    /* Set Extended display list operation.
     *  - No extended display list are used
     *  - DLPRI bit and POLINT[5:0] must be fixed value */
    R_LCDC->VI6_DL_EXT_CTRL0 = (2U << R_LCDC_VI6_DL_EXT_CTRL0_POLINT_Pos) |
                               (1U << R_LCDC_VI6_DL_EXT_CTRL0_DLPRI_Pos) |
                               (0U << R_LCDC_VI6_DL_EXT_CTRL0_EXT_Pos);

    /* Display List Header Address */
#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) (&g_dl_body) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_DL_HDR_ADDR0 = pa & CAST_TO_UINT32;
#else
    R_LCDC->VI6_DL_HDR_ADDR0 = (uint32_t) (&g_dl_body) & CAST_TO_UINT32;
#endif

    /* Data swapping in long word (32-bit) units is enabled.
     * When the CPU sets up a display list on RAM, the CPU writes it to RAM in 32-bit little endian.
     * Therefore, LCDC peripheral needs to access the display list with long word units swap. */
    R_LCDC->VI6_DL_SWAP0_b.LWS = 1;
}

/*******************************************************************************************************************//**
 * Display List address setting.
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_dl_address_set (display_cfg_t const * const p_cfg)
{
    lcdc_extended_cfg_t * p_extend = (lcdc_extended_cfg_t *) p_cfg->p_extend;

#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    g_dl_body.cmd[0].set_address  = (uintptr_t) (&(R_LCDC->VI6_WPF0_SRCRPF)) & CAST_TO_UINT32;
    g_dl_body.cmd[1].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_SRCM_ADDR_Y)) & CAST_TO_UINT32;
    g_dl_body.cmd[2].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_INFMT)) & CAST_TO_UINT32;
    g_dl_body.cmd[3].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_SRC_BSIZE)) & CAST_TO_UINT32;
    g_dl_body.cmd[4].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_SRC_ESIZE)) & CAST_TO_UINT32;
    g_dl_body.cmd[5].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_SRCM_PSTRIDE)) & CAST_TO_UINT32;
    g_dl_body.cmd[6].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_LOC)) & CAST_TO_UINT32;
    g_dl_body.cmd[7].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_DSWAP)) & CAST_TO_UINT32;
    g_dl_body.cmd[8].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_CKEY_CTRL)) & CAST_TO_UINT32;
    g_dl_body.cmd[9].set_address  = (uintptr_t) (&(R_LCDC->VI6_RPF0_CKEY_SET0)) & CAST_TO_UINT32;
    g_dl_body.cmd[10].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF0_CKEY_SET1)) & CAST_TO_UINT32;
    g_dl_body.cmd[11].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_SRCM_ADDR_Y)) & CAST_TO_UINT32;
    g_dl_body.cmd[12].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_INFMT)) & CAST_TO_UINT32;
    g_dl_body.cmd[13].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_SRC_BSIZE)) & CAST_TO_UINT32;
    g_dl_body.cmd[14].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_SRC_ESIZE)) & CAST_TO_UINT32;
    g_dl_body.cmd[15].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_SRCM_PSTRIDE)) & CAST_TO_UINT32;
    g_dl_body.cmd[16].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_LOC)) & CAST_TO_UINT32;
    g_dl_body.cmd[17].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_DSWAP)) & CAST_TO_UINT32;
    g_dl_body.cmd[18].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_CKEY_CTRL)) & CAST_TO_UINT32;
    g_dl_body.cmd[19].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_CKEY_SET0)) & CAST_TO_UINT32;
    g_dl_body.cmd[20].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_CKEY_SET1)) & CAST_TO_UINT32;
    g_dl_body.cmd[21].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF0_SRCM_ADDR_C0)) & CAST_TO_UINT32;
    g_dl_body.cmd[22].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF0_SRCM_ADDR_C1)) & CAST_TO_UINT32;
    g_dl_body.cmd[23].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_SRCM_ADDR_C0)) & CAST_TO_UINT32;
    g_dl_body.cmd[24].set_address = (uintptr_t) (&(R_LCDC->VI6_RPF1_SRCM_ADDR_C1)) & CAST_TO_UINT32;

    /* Set Display List Configuration for Layer 1 */
    lcdc_recalculated_param_t recalculated_layer1;
    r_lcdc_layer_cfg_recaluclate(&p_cfg->input[0], &recalculated_layer1);

    /* Only Virtual RPF start enable via display list */
    g_dl_body.cmd[0].set_data = LAYER_STATUS_INIT;

    /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) (recalculated_layer1.p_base) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    g_dl_body.cmd[1].set_data = pa & CAST_TO_UINT32;
#else
    g_dl_body.cmd[1].set_data = (uint32_t) (recalculated_layer1.p_base) & CAST_TO_UINT32;
#endif

    /* Input Format Setting */
    g_dl_body.cmd[2].set_data = display_format_table[p_cfg->input[0].format];

    if (p_cfg->input[0].format >= 12)
    {
        /* In LCDC HAL driver, the display output format is fixed to RGB888.
         * If the input format is YCbCr, YCbCr->RGB color space conversion must be performed.
         * Color conversion is done as BT.601 YCbCr [16,235/240] -> RGB [0,255] (RDTM[2:0] is fixed to 0). */
        g_dl_body.cmd[2].set_data |= COLOR_FOTMAT_CONVERT;
    }
    else
    {
        /* Do Nothing */
    }

    /* Size Setting */
    g_dl_body.cmd[3].set_data = (recalculated_layer1.hsize << R_LCDC_VI6_RPF0_SRC_BSIZE_BHSIZE_Pos) |
                                (recalculated_layer1.vsize << R_LCDC_VI6_RPF0_SRC_BSIZE_BVSIZE_Pos);
    g_dl_body.cmd[4].set_data = (recalculated_layer1.hsize << R_LCDC_VI6_RPF0_SRC_ESIZE_EHSIZE_Pos) |
                                (recalculated_layer1.vsize << R_LCDC_VI6_RPF0_SRC_ESIZE_EVSIZE_Pos);

    /* Stride Setting */
    g_dl_body.cmd[5].set_data = ((uint32_t) p_cfg->input[0].hstride << R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_Y_Pos) |
                                ((uint32_t) p_cfg->input[0].hstride_cbcr <<
                                 R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_C_Pos);

    /* Location Setting */
    g_dl_body.cmd[6].set_data = (recalculated_layer1.coor_x << R_LCDC_VI6_RPF0_LOC_HCOORD_Pos) |
                                (recalculated_layer1.coor_y << R_LCDC_VI6_RPF0_LOC_VCOORD_Pos);

    /* Input buffer data swap setting */
    g_dl_body.cmd[7].set_data = (uint32_t) (p_cfg->input[0].data_swap);

    /* Color keying setting */
    if (p_extend->p_ckey_cfg == NULL)
    {
        g_dl_body.cmd[8].set_data  = 0;
        g_dl_body.cmd[9].set_data  = 0;
        g_dl_body.cmd[10].set_data = 0;
    }
    else
    {
        g_dl_body.cmd[8].set_data =
            (uint32_t) (p_extend->p_ckey_cfg->layer[0].enable_ckey << R_LCDC_VI6_RPF0_CKEY_CTRL_CV_Pos);
        g_dl_body.cmd[9].set_data  = p_extend->p_ckey_cfg->layer[0].src_color.argb;
        g_dl_body.cmd[10].set_data = p_extend->p_ckey_cfg->layer[0].dst_color.argb;
    }

    /* Set Display List Configuration for Layer 2 */
    lcdc_recalculated_param_t recalculated_layer2;
    r_lcdc_layer_cfg_recaluclate(&p_cfg->input[1], &recalculated_layer2);

    /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) (recalculated_layer2.p_base) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    g_dl_body.cmd[11].set_data = pa & CAST_TO_UINT32;
#else
    g_dl_body.cmd[11].set_data = (uint32_t) (recalculated_layer2.p_base) & CAST_TO_UINT32; // (p_cfg->input[1].p_base) & CAST_TO_UINT32;
#endif

    /* Input Format Setting */
    g_dl_body.cmd[12].set_data = display_format_table[p_cfg->input[1].format];

    if (p_cfg->input[1].format >= 12)
    {
        /* In LCDC HAL driver, the display output format is fixed to RGB888.
         * If the input format is YCbCr, YCbCr->RGB color space conversion must be performed.
         * Color conversion is done as BT.601 YCbCr [16,235/240] -> RGB [0,255] (RDTM[2:0] is fixed to 0). */
        g_dl_body.cmd[12].set_data |= COLOR_FOTMAT_CONVERT;
    }
    else
    {
        /* Do Nothing */
    }

    /* Size Setting */
    g_dl_body.cmd[13].set_data = (recalculated_layer2.hsize << R_LCDC_VI6_RPF1_SRC_BSIZE_BHSIZE_Pos) |
                                 (recalculated_layer2.vsize << R_LCDC_VI6_RPF1_SRC_BSIZE_BVSIZE_Pos);
    g_dl_body.cmd[14].set_data = (recalculated_layer2.hsize << R_LCDC_VI6_RPF1_SRC_ESIZE_EHSIZE_Pos) |
                                 (recalculated_layer2.vsize << R_LCDC_VI6_RPF1_SRC_ESIZE_EVSIZE_Pos);

    /* Stride Setting */
    g_dl_body.cmd[15].set_data = ((uint32_t) p_cfg->input[1].hstride << R_LCDC_VI6_RPF1_SRCM_PSTRIDE_PICT_STRD_Y_Pos) |
                                 ((uint32_t) p_cfg->input[1].hstride_cbcr <<
                                  R_LCDC_VI6_RPF1_SRCM_PSTRIDE_PICT_STRD_C_Pos);

    /* Location Setting */
    g_dl_body.cmd[16].set_data = (recalculated_layer2.coor_x << R_LCDC_VI6_RPF1_LOC_HCOORD_Pos) |
                                 (recalculated_layer2.coor_y << R_LCDC_VI6_RPF1_LOC_VCOORD_Pos);

    /* Input buffer data swap setting */
    g_dl_body.cmd[17].set_data = (uint32_t) (p_cfg->input[1].data_swap);

    /* Color keying setting */
    if (p_extend->p_ckey_cfg == NULL)
    {
        g_dl_body.cmd[18].set_data = 0;
        g_dl_body.cmd[19].set_data = 0;
        g_dl_body.cmd[20].set_data = 0;
    }
    else
    {
        g_dl_body.cmd[18].set_data =
            (uint32_t) (p_extend->p_ckey_cfg->layer[1].enable_ckey << R_LCDC_VI6_RPF1_CKEY_CTRL_CV_Pos);
        g_dl_body.cmd[19].set_data = p_extend->p_ckey_cfg->layer[1].src_color.argb;
        g_dl_body.cmd[20].set_data = p_extend->p_ckey_cfg->layer[1].dst_color.argb;
    }

    /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) (recalculated_layer1.p_base_cb) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    g_dl_body.cmd[21].set_data = pa & CAST_TO_UINT32;

    va = (uint64_t) (recalculated_layer1.p_base_cr) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    g_dl_body.cmd[22].set_data = pa & CAST_TO_UINT32;
#else
    g_dl_body.cmd[21].set_data = (uint32_t) (recalculated_layer1.p_base_cb) & CAST_TO_UINT32;
    g_dl_body.cmd[22].set_data = (uint32_t) (recalculated_layer1.p_base_cr) & CAST_TO_UINT32;
#endif

#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) (recalculated_layer2.p_base_cb) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    g_dl_body.cmd[23].set_data = pa & CAST_TO_UINT32;

    va = (uint64_t) (recalculated_layer2.p_base_cr) & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    g_dl_body.cmd[24].set_data = pa & CAST_TO_UINT32;
#else
    g_dl_body.cmd[23].set_data = (uint32_t) (recalculated_layer2.p_base_cb) & CAST_TO_UINT32;
    g_dl_body.cmd[24].set_data = (uint32_t) (recalculated_layer2.p_base_cr) & CAST_TO_UINT32;
#endif
}

/*******************************************************************************************************************//**
 * Display Unit InterFace (LIF) settings. Select using modules.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_lif_set (void)
{
    /* Set LIF operation.
     *  - Buffer Threshold for Start Ready Notification to Display Module is fixed value
     *  - Disable of padding with dummy lines to output-image to the DU
     *  - CFMT bit must be because output format is RGB
     *  - DU is selected as the destination external display module
     *  - Data output to the external display module is enabled */
    R_LCDC->VI6_LIF0_CTRL = (LCDC_VSPD_LIF_CTRL_OBTH << R_LCDC_VI6_LIF0_CTRL_OBTH_Pos) |
                            (1U << R_LCDC_VI6_LIF0_CTRL_REQSEL_Pos) |
                            (1U << R_LCDC_VI6_LIF0_CTRL_LIF_EN_Pos);

    /* LIF Buffer Attribute Register 0/1 must be fixed value */
    R_LCDC->VI6_LIF0_LBA = (1U << R_LCDC_VI6_LIF0_LBA_LBA0_Pos) |
                           (LCDC_VSPD_LIF_CTRL_LBA1 << R_LCDC_VI6_LIF0_LBA_LBA1_Pos);
}

/*******************************************************************************************************************//**
 * Display for Layer1 settings.
 *
 * @param[in]       p_ctrl      Instance pointer of LCDC control
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_layer1_set (lcdc_instance_ctrl_t * p_ctrl, display_cfg_t const * const p_cfg)
{
#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    lcdc_recalculated_param_t recalculated_layer;
    r_lcdc_layer_cfg_recaluclate(&p_cfg->input[0], &recalculated_layer);

    /* Input Format Setting */
    R_LCDC->VI6_RPF0_INFMT = display_format_table[p_cfg->input[0].format];

    /* Size Setting */
    uint32_t hsize = recalculated_layer.hsize;
    uint32_t vsize = recalculated_layer.vsize;
    R_LCDC->VI6_RPF0_SRC_BSIZE = (hsize << R_LCDC_VI6_RPF0_SRC_BSIZE_BHSIZE_Pos) |
                                 (vsize << R_LCDC_VI6_RPF0_SRC_BSIZE_BVSIZE_Pos);
    R_LCDC->VI6_RPF0_SRC_ESIZE = (hsize << R_LCDC_VI6_RPF0_SRC_ESIZE_EHSIZE_Pos) |
                                 (vsize << R_LCDC_VI6_RPF0_SRC_ESIZE_EVSIZE_Pos);

    /* Stride Setting */
    uint32_t hstride      = p_cfg->input[0].hstride;
    uint32_t hstride_cbcr = p_cfg->input[0].hstride_cbcr;
    R_LCDC->VI6_RPF0_SRCM_PSTRIDE = (hstride_cbcr << R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_Y_Pos) |
                                    (hstride << R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_C_Pos);

    /* Location Setting */
    uint32_t coor_x = recalculated_layer.coor_x;
    uint32_t coor_y = recalculated_layer.coor_y;
    R_LCDC->VI6_RPF0_LOC = (coor_x << R_LCDC_VI6_RPF0_LOC_HCOORD_Pos) |
                           (coor_y << R_LCDC_VI6_RPF0_LOC_VCOORD_Pos);

    /* Buffer address Setting
     * Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) recalculated_layer.p_base & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_RPF0_SRCM_ADDR_Y = pa & CAST_TO_UINT32;

    va = (uint64_t) recalculated_layer.p_base_cb & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_RPF0_SRCM_ADDR_C0 = pa & CAST_TO_UINT32;

    va = (uint64_t) recalculated_layer.p_base_cr & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_RPF0_SRCM_ADDR_C1 = pa & CAST_TO_UINT32;
#else
    R_LCDC->VI6_RPF0_SRCM_ADDR_Y  = (uint32_t) recalculated_layer.p_base;
    R_LCDC->VI6_RPF0_SRCM_ADDR_C0 = (uint32_t) recalculated_layer.p_base_cb;
    R_LCDC->VI6_RPF0_SRCM_ADDR_C1 = (uint32_t) recalculated_layer.p_base_cr;
#endif

    /* Alpha Setting (RPF0 Alpha data is 0x00) */
    R_LCDC->VI6_RPF0_ALPH_SEL_b.ASEL = 0;

    /* Swap Setting */
    R_LCDC->VI6_RPF0_DSWAP = (uint32_t) (p_cfg->input[0].data_swap);

    if (p_cfg->input[0].p_base == NULL)
    {
        /* Disable Layer1 (RPF0) */
        p_ctrl->layer_status &= LAYER_DISABLE_1;
    }
    else
    {
        /* Enable Layer1 (RPF0) */
        p_ctrl->layer_status |= LAYER_ENABLE_1;
    }
}

/*******************************************************************************************************************//**
 * Display for Layer2 settings.
 *
 * @param[in]       p_ctrl      Instance pointer of LCDC control
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_layer2_set (lcdc_instance_ctrl_t * p_ctrl, display_cfg_t const * const p_cfg)
{
#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    lcdc_recalculated_param_t recalculated_layer;
    r_lcdc_layer_cfg_recaluclate(&p_cfg->input[1], &recalculated_layer);

    /* Format Setting */
    R_LCDC->VI6_RPF1_INFMT = display_format_table[p_cfg->input[1].format];

    /* Size Setting */
    uint32_t hsize = recalculated_layer.hsize;
    uint32_t vsize = recalculated_layer.vsize;
    R_LCDC->VI6_RPF1_SRC_BSIZE = (hsize << R_LCDC_VI6_RPF1_SRC_BSIZE_BHSIZE_Pos) |
                                 (vsize << R_LCDC_VI6_RPF1_SRC_BSIZE_BVSIZE_Pos);
    R_LCDC->VI6_RPF1_SRC_ESIZE = (hsize << R_LCDC_VI6_RPF1_SRC_ESIZE_EHSIZE_Pos) |
                                 (vsize << R_LCDC_VI6_RPF1_SRC_ESIZE_EVSIZE_Pos);

    /* Stride Setting */
    uint32_t hstride      = p_cfg->input[1].hstride;
    uint32_t hstride_cbcr = p_cfg->input[1].hstride_cbcr;
    R_LCDC->VI6_RPF1_SRCM_PSTRIDE = (hstride_cbcr << R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_Y_Pos) |
                                    (hstride << R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_C_Pos);

    /* Location Setting */
    uint32_t coor_x = recalculated_layer.coor_x;
    uint32_t coor_y = recalculated_layer.coor_y;
    R_LCDC->VI6_RPF1_LOC = (coor_x << R_LCDC_VI6_RPF1_LOC_HCOORD_Pos) | coor_y;

    /* Buffer address Setting */
    /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
    va = (uint64_t) recalculated_layer.p_base & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_RPF1_SRCM_ADDR_Y = pa & CAST_TO_UINT32;

    va = (uint64_t) recalculated_layer.p_base_cb & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_RPF1_SRCM_ADDR_C0 = pa & CAST_TO_UINT32;

    va = (uint64_t) recalculated_layer.p_base_cr & CAST_TO_UINT32;
    R_BSP_MmuVatoPa(va, (void *) &pa);
    R_LCDC->VI6_RPF1_SRCM_ADDR_C1 = pa & CAST_TO_UINT32;
#else
    R_LCDC->VI6_RPF1_SRCM_ADDR_Y  = (uint32_t) recalculated_layer.p_base & CAST_TO_UINT32;
    R_LCDC->VI6_RPF1_SRCM_ADDR_C0 = (uint32_t) recalculated_layer.p_base_cb & CAST_TO_UINT32;
    R_LCDC->VI6_RPF1_SRCM_ADDR_C1 = (uint32_t) recalculated_layer.p_base_cr & CAST_TO_UINT32;
#endif

    /* Alpha Setting */
    R_LCDC->VI6_RPF1_ALPH_SEL_b.ASEL = 0;

    /* Swap Setting */
    R_LCDC->VI6_RPF1_DSWAP = (uint32_t) (p_cfg->input[1].data_swap);

    if (p_cfg->input[1].p_base == NULL)
    {
        /* Disable Layer1 (RPF1) */
        p_ctrl->layer_status &= LAYER_DISABLE_2;
    }
    else
    {
        /* Enable Layer1 (RPF1) */
        p_ctrl->layer_status |= LAYER_ENABLE_2;
    }
}

/*******************************************************************************************************************//**
 * Subroutine to recalculate the configuration for the graphics planes. This routine recalculates the layer
 *           configuration if the layer is beyond the left/right/top/bottom end of the active video region.
 * @param[in]     p_input         The input frame buffer configuration
 * @param[in,out] p_recalculated  Pointer to store recalculated parameter
 * @retval        void
 **********************************************************************************************************************/
static void r_lcdc_layer_cfg_recaluclate (display_input_cfg_t const * const p_input,
                                          lcdc_recalculated_param_t       * p_recalculated)
{
    uint16_t hsize        = p_input->hsize;
    uint16_t vsize        = p_input->vsize;
    uint16_t hstride      = p_input->hstride;
    uint16_t hstride_cbcr = p_input->hstride_cbcr;

    int16_t coor_x = p_input->coordinate_x;
    int16_t coor_y = p_input->coordinate_y;

    uint32_t * p_base    = p_input->p_base;
    uint32_t * p_base_cb = p_input->p_base_cb;
    uint32_t * p_base_cr = p_input->p_base_cr;

    uint16_t vdispsize = R_LCDC->DU_DITR1_b.VACTIVE;

    /* If the offset of the graphics layer is less than the right edge end of display window (coor_x < 0)
     * but some part of the layer may still be visible, calculate actual pixel size to display. */
    if (coor_x < 0)
    {
        /* Actual horizontal layer size to be output to screen */
        p_recalculated->hsize = (uint32_t) (hsize + coor_x);

        /* If the horizontal start position is negative, the graphic layer is actually at the right edge of the display. */
        p_recalculated->coor_x = 0;

        /* Calculate offset base address.
         *   (hstride / hsize) means byte per pixel.
         *
         *   If coor_x < 0, the image is read with an offset of coor_x pixel in the buffer and is displayed
         *   from the right edge of the display.
         *   Since hstride is not changed, LCDC gets exactly the the actual horizontal size of the image.
         *   Therefore, columns '0' to 'coor_x - 1' pixel of the image buffer are no longer displayed,
         *   and columns 'coor_x' to 'vsize' are displayed on the screen.
         *
         *   As an example, when displaying a 1920x1080 image with coor_x = -2,
         *   the image is displayed from the right edge of the screen starting at the 2nd pixel.
         *   In this case, 0, 1, 1920, 1921th, ... pixel is off the screen at the right edge.
         *
         *   When stride = 1920 and vsize = 1918, LCDC considers 2 to 1921 th, 1922 to 3841 th, ... pixel to be one line due to stride,
         *   while 2 to 1919 th, 1922 to 3839 th, ... pixel is actually displayed due to vsize. */
        p_base = (uint32_t *) ((uintptr_t) p_base + (uint32_t) ((-1) * coor_x) * hstride / hsize);

        /* p_base_cb is only used in some YCbCr formats */
        if (p_base_cb != NULL)
        {
            p_base_cb = (uint32_t *) ((uintptr_t) p_base_cb + (uint32_t) ((-1) * coor_x) * hstride_cbcr / hsize);
        }

        /* p_base_cr is only used in some YCbCr formats */
        if (p_base_cr != NULL)
        {
            p_base_cr = (uint32_t *) ((uintptr_t) p_base_cr + (uint32_t) ((-1) * coor_x) * hstride_cbcr / hsize);
        }
    }
    else
    {
        /* Actual pixel size to display is the same as input image size */
        p_recalculated->hsize  = hsize;
        p_recalculated->coor_x = (uint32_t) coor_x;
    }

    /* If the offset of the graphics layer is less than the top end of display window (coor_y < 0)
     * but some part of the layer may still be visible, calculate actual pixel size to display. */
    if (coor_y < 0)
    {
        /* Actual vertical layer size to be output to screen */
        p_recalculated->vsize = (uint32_t) (vsize + coor_y);

        /* If the vertical start position is negative, the graphic layer is actually at the top of the display. */
        p_recalculated->coor_y = 0;

        if (p_input->format != DISPLAY_IN_FORMAT_16BITS_YCBCR420_INTERLEAVED)
        {
            /* If coor_y < 0, the image is read with an offset of 1 line byte(=hstride) * coor_y pixel in the buffer and
             * is displayed from the top of the display, 0 to coor_y lines are off-screen and do not actually need to be read. */
            p_base = (uint32_t *) ((uintptr_t) p_base + (uint32_t) ((-1) * coor_y) * hstride);
        }
        else
        {
            /* When the input format is YCbCr420 Interleaved, the p_base vertical size is 1/2 by its input format. */
            p_base = (uint32_t *) ((uintptr_t) p_base + (uint32_t) ((-1) * coor_y + (coor_y % 2)) * hstride / 2);
        }

        /* p_base_cb is only used in some YCbCr formats */
        if (p_base_cb != NULL)
        {
            if (p_input->format != DISPLAY_IN_FORMAT_16BITS_YCBCR420_PLANAR)
            {
                p_base_cb =
                    (uint32_t *) ((uintptr_t) p_base_cb + (uint32_t) ((-1) * coor_y + (coor_y % 2)) * hstride_cbcr);
            }
            else
            {
                /* When the input format is YCbCr420 Planar, the p_base_cb vertical size is 1/2 by its input format. */
                p_base_cb =
                    (uint32_t *) ((uintptr_t) p_base_cb + (uint32_t) ((-1) * coor_y + (coor_y % 2)) * hstride_cbcr / 2);
            }
        }

        /* p_base_cr is only used in some YCbCr formats */
        if (p_base_cr != NULL)
        {
            if (p_input->format != DISPLAY_IN_FORMAT_16BITS_YCBCR420_PLANAR)
            {
                p_base_cr =
                    (uint32_t *) ((uintptr_t) p_base_cr + (uint32_t) ((-1) * coor_y + (coor_y % 2)) * hstride_cbcr);
            }
            else
            {
                /* When the input format is YCbCr420 Planar, the p_base_cr vertical size is 1/2 by its input format. */
                p_base_cr =
                    (uint32_t *) ((uintptr_t) p_base_cr + (uint32_t) ((-1) * coor_y + (coor_y % 2)) * hstride_cbcr / 2);
            }
        }
    }
    /* In the vertical direction, when 'coor_y >= 0' and the input image extends beyond the screen
     * due to the size and start offset of the input image. */
    else if ((vsize + coor_y > vdispsize))
    {
        /* Actual pixel size to display is less than input image size */
        p_recalculated->vsize  = (uint32_t) (vdispsize - coor_y);
        p_recalculated->coor_y = (uint32_t) coor_y;
    }
    else
    {
        /* Actual pixel size to display is the same as input image size */
        p_recalculated->vsize  = (uint32_t) vsize;
        p_recalculated->coor_y = (uint32_t) coor_y;
    }

    /* If all image pixels are off-screen due to input image and start offset,
     * nothing is shown on the display. */
    if ((p_recalculated->hsize <= 0) || (p_recalculated->vsize <= 0))
    {
        p_recalculated->hsize = 2;
        p_recalculated->vsize = 2;

        p_base    = NULL;
        p_base_cb = NULL;
        p_base_cr = NULL;
    }

    p_recalculated->p_base    = p_base;
    p_recalculated->p_base_cb = p_base_cb;
    p_recalculated->p_base_cr = p_base_cr;
}

/*******************************************************************************************************************//**
 * LCDC output settings
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_output_set (display_cfg_t const * const p_cfg)
{
    /* Background layer Setting */
    R_LCDC->VI6_WPF0_SRCRPF = LAYER_DISABLE_ALL;

    /* Background Layer (Virtual RPF) size setting */
    uint32_t hsize = p_cfg->output.htiming.display_cyc;
    uint32_t vsize = p_cfg->output.vtiming.display_cyc;
    R_LCDC->VI6_BRS_VIRRPF_SIZE = (hsize << R_LCDC_VI6_BRS_VIRRPF_SIZE_VIR_HSIZE_Pos) |
                                  (vsize << R_LCDC_VI6_BRS_VIRRPF_SIZE_VIR_VSIZE_Pos);

    /* Background Layer (Virtual RPF) location setting.
     * The vertical/horizontal coordinate of where to locate the top/left-edge pixel of the virtual RPF's layer is set to 0.
     * With this setting, the background layer is drawn from the top left edge of the display. */
    R_LCDC->VI6_BRS_VIRRPF_LOC = 0x00000000;

    /* Background Layer (Virtual RPF) color setting */
    R_LCDC->VI6_BRS_VIRRPF_COL = p_cfg->output.bg_color.argb;

    /* Write Back setting */
    R_LCDC->VI6_WPF0_WRBCK_CTRL_b.WBMD = 0;
}

/*******************************************************************************************************************//**
 * Data Path Router settings. Select using modules.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_dpr_set (void)
{
    /* The target node for RPF0 is BRSin1 (RPF0 -> BRSin1) */
    R_LCDC->VI6_DPR_RPF0_ROUTE_b.RT_RPF0 = LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF0;

    /* The target node for RPF1 is BRSin0 (RPF1 -> BRSin0) */
    R_LCDC->VI6_DPR_RPF1_ROUTE_b.RT_RPF1 = LCDC_VSPD_DPR_RPF0_ROUTE_RT_RPF1;

    /* WPF0 Internal Operation Timing Setting (FP_WPF0[5:0]) must be fixed value. */
    R_LCDC->VI6_DPR_WPF0_FPORCH_b.FP_WPF0 = LCDC_VSPD_DPR_WPF0_FPROCH;

    /* LCDC HAL driver does not use LUT */
    R_LCDC->VI6_DPR_LUT_ROUTE_b.RT = LCDC_VSPD_DPR_LUT_ROUTE;

    /* The target not for BRS is WPF0 (BRS -> WPF0)
     * BRSSEL bit must be fixed value */
    R_LCDC->VI6_DPR_BRS_ROUTE = (LCDC_VSPD_DPR_ILV_BRS_ROUTE_BRSSEL << R_LCDC_VI6_DPR_BRS_ROUTE_BRSSEL_Pos) |
                                (LCDC_VSPD_DPR_ILV_BRS_ROUTE_RT << R_LCDC_VI6_DPR_BRS_ROUTE_RT_Pos);
}

/*******************************************************************************************************************//**
 * Blend ROP Sub unit settings. Select ROP or alpha blending.
 *
 * @retval      none
 **********************************************************************************************************************/
static void r_lcdc_brs_set (void)
{
    /* Set Blend/ROP unit A operation.
     *  - Blending Operation
     *  - BRS input 1 (BRSin1) is input to DST
     *  - Virtual RPF is input to SRC */
    R_LCDC->VI6_BRSA_CTRL = (1U << R_LCDC_VI6_BRSA_CTRL_RBC_Pos) |
                            (LCDC_VSPD_BRSA_CTRL_DSTSEL << R_LCDC_VI6_BRSA_CTRL_DSTSEL_Pos) |
                            (LCDC_VSPD_BRSA_CTRL_SRCSEL << R_LCDC_VI6_BRSA_CTRL_SRCSEL_Pos) |
                            (0U << R_LCDC_VI6_BRSA_CTRL_CROP_Pos) |
                            (0U << R_LCDC_VI6_BRSA_CTRL_AROP_Pos);

    /* Blend/ROP unit A operation expression.
     *  - Blending Expression
     *      = (DST alpha data) * (DST color data) + (255 - DST alpha data) * (SRC color data)
     *
     *  -  Blending alpha Creation Expression
     *      = (DST alpha data) +  (255 - DST alpha data) * (SRC alpha data) */
    R_LCDC->VI6_BRSA_BLD = (0U << R_LCDC_VI6_BRSA_BLD_CBES_Pos) |
                           (LCDC_VSPD_BRSA_BLD_CCMDX << R_LCDC_VI6_BRSA_BLD_CCMDX_Pos) |
                           (LCDC_VSPD_BRSA_BLD_CCMDY << R_LCDC_VI6_BRSA_BLD_CCMDY_Pos) |
                           (0U << R_LCDC_VI6_BRSA_BLD_ABES_Pos) |
                           (LCDC_VSPD_BRSA_BLD_ACMDX << R_LCDC_VI6_BRSA_BLD_ACMDX_Pos) |
                           (LCDC_VSPD_BRSA_BLD_ACMDY << R_LCDC_VI6_BRSA_BLD_ACMDY_Pos) |
                           (LCDC_VSPD_BRSA_BLD_COEFX << R_LCDC_VI6_BRSA_BLD_COEFX_Pos);

    /* Set Blend/ROP unit B operation.
     *  - Operation Type : Blending operation */
    R_LCDC->VI6_BRSB_CTRL = (1U << R_LCDC_VI6_BRSB_CTRL_RBC_Pos);

    /* Blend/ROP unit B operation expression.
     *  - Blending Expression
     *      = (SRC alpha data) * (SRC color data) + (255 - SRC alpha data) * (DST color data)
     *
     *  -  Blending alpha Creation Expression
     *      = (SRC alpha data) + (255 - SRC alpha data) * (DST alpha data) */
    R_LCDC->VI6_BRSB_BLD = (0U << R_LCDC_VI6_BRSB_BLD_CBES_Pos) |
                           (LCDC_VSPD_BRSB_BLD_CCMDX << R_LCDC_VI6_BRSB_BLD_CCMDX_Pos) |
                           (LCDC_VSPD_BRSB_BLD_CCMDY << R_LCDC_VI6_BRSB_BLD_CCMDY_Pos) |
                           (0U << R_LCDC_VI6_BRSB_BLD_ABES_Pos) |
                           (LCDC_VSPD_BRSB_BLD_ACMDX << R_LCDC_VI6_BRSB_BLD_ACMDX_Pos) |
                           (LCDC_VSPD_BRSB_BLD_ACMDY << R_LCDC_VI6_BRSB_BLD_ACMDY_Pos) |
                           (LCDC_VSPD_BRSB_BLD_COEFY << R_LCDC_VI6_BRSB_BLD_COEFY_Pos);
}

/*******************************************************************************************************************//**
 * Change selected layer configuration
 *
 * @param[in]       p_ctrl      Instance pointer of LCDC control
 * @param[in]       p_rt_cfg    LCDC runtime configuration parameters
 * @param[in]       layer       selected layer number
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_layer_change (lcdc_instance_ctrl_t              * p_ctrl,
                                 display_runtime_cfg_t const * const p_rt_cfg,
                                 display_frame_layer_t               layer)
{
#if defined(BSP_CFG_CORE_CA55)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif

    lcdc_recalculated_param_t recalculated;
    r_lcdc_layer_cfg_recaluclate(&p_rt_cfg->input, &recalculated);

    /* Change Layer Setting */
    if (layer == DISPLAY_FRAME_LAYER_1)
    {
        if (p_rt_cfg->input.p_base == NULL)
        {
            /* Disable Layer1 (RPF0) */
            p_ctrl->layer_status &= LAYER_DISABLE_1;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            p_ctrl->layer_status |= LAYER_ENABLE_1;
        }

        /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
        va = (uint64_t) (recalculated.p_base) & CAST_TO_UINT32;
        R_BSP_MmuVatoPa(va, (void *) &pa);
        g_dl_body.cmd[1].set_data = pa & CAST_TO_UINT32;
#else
        g_dl_body.cmd[1].set_data = (uint32_t) (recalculated.p_base) & CAST_TO_UINT32;
#endif

        /* Input Format Setting */
        g_dl_body.cmd[2].set_data = display_format_table[p_rt_cfg->input.format];

        if (p_rt_cfg->input.format >= 12)
        {
            /* In LCDC HAL driver, the display output format is fixed to RGB888.
             * If the input format is YCbCr, YCbCr->RGB color space conversion must be performed.
             * Color conversion is done as BT.601 YCbCr [16,235/240] -> RGB [0,255] (RDTM[2:0] is fixed to 0). */
            g_dl_body.cmd[2].set_data |= COLOR_FOTMAT_CONVERT;
        }
        else
        {
            /* Do Nothing */
        }

        /* Size Setting */
        g_dl_body.cmd[3].set_data = (recalculated.hsize << R_LCDC_VI6_RPF0_SRC_BSIZE_BHSIZE_Pos) |
                                    (recalculated.vsize << R_LCDC_VI6_RPF0_SRC_BSIZE_BVSIZE_Pos);
        g_dl_body.cmd[4].set_data = (recalculated.hsize << R_LCDC_VI6_RPF0_SRC_ESIZE_EHSIZE_Pos) |
                                    (recalculated.vsize << R_LCDC_VI6_RPF0_SRC_ESIZE_EVSIZE_Pos);

        /* Stride Setting */
        g_dl_body.cmd[5].set_data =
            ((uint32_t) p_rt_cfg->input.hstride << R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_Y_Pos) |
            ((uint32_t) p_rt_cfg->input.hstride_cbcr <<
                R_LCDC_VI6_RPF0_SRCM_PSTRIDE_PICT_STRD_C_Pos);

        /* Location Setting */
        g_dl_body.cmd[6].set_data = (recalculated.coor_x << R_LCDC_VI6_RPF0_LOC_HCOORD_Pos) |
                                    (recalculated.coor_y << R_LCDC_VI6_RPF0_LOC_VCOORD_Pos);

        /* Input buffer data swap setting */
        g_dl_body.cmd[7].set_data = (uint32_t) (p_rt_cfg->input.data_swap);

#if defined(BSP_CFG_CORE_CA55)
        va = (uint64_t) (recalculated.p_base_cb) & CAST_TO_UINT32;
        R_BSP_MmuVatoPa(va, (void *) &pa);
        g_dl_body.cmd[21].set_data = pa & CAST_TO_UINT32;

        va = (uint64_t) (recalculated.p_base_cr) & CAST_TO_UINT32;
        R_BSP_MmuVatoPa(va, (void *) &pa);
        g_dl_body.cmd[22].set_data = pa & CAST_TO_UINT32;
#else
        g_dl_body.cmd[21].set_data = (uint32_t) (recalculated.p_base_cb) & CAST_TO_UINT32;
        g_dl_body.cmd[22].set_data = (uint32_t) (recalculated.p_base_cr) & CAST_TO_UINT32;
#endif
    }
    else if (layer == DISPLAY_FRAME_LAYER_2)
    {
        if (p_rt_cfg->input.p_base == NULL)
        {
            /* Disable Layer1 (RPF0) */
            p_ctrl->layer_status &= LAYER_DISABLE_2;
        }
        else
        {
            /* Enable Layer1 (RPF0) */
            p_ctrl->layer_status |= LAYER_ENABLE_2;
        }

        /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
        va = (uint64_t) (recalculated.p_base) & CAST_TO_UINT32;
        R_BSP_MmuVatoPa(va, (void *) &pa);
        g_dl_body.cmd[11].set_data = pa & CAST_TO_UINT32;
#else
        g_dl_body.cmd[11].set_data = (uint32_t) (recalculated.p_base) & CAST_TO_UINT32;
#endif

        /* Input Format Setting */
        g_dl_body.cmd[12].set_data = display_format_table[p_rt_cfg->input.format];

        if (p_rt_cfg->input.format >= 12)
        {
            /* In LCDC HAL driver, the display output format is fixed to RGB888.
             * If the input format is YCbCr, YCbCr->RGB color space conversion must be performed.
             * Color conversion is done as BT.601 YCbCr [16,235/240] -> RGB [0,255] (RDTM[2:0] is fixed to 0). */
            g_dl_body.cmd[12].set_data |= COLOR_FOTMAT_CONVERT;
        }
        else
        {
            /* Do Nothing */
        }

        /* Size Setting */
        g_dl_body.cmd[13].set_data = (recalculated.hsize << R_LCDC_VI6_RPF1_SRC_BSIZE_BHSIZE_Pos) |
                                     (recalculated.vsize << R_LCDC_VI6_RPF1_SRC_BSIZE_BVSIZE_Pos);
        g_dl_body.cmd[14].set_data = (recalculated.hsize << R_LCDC_VI6_RPF1_SRC_ESIZE_EHSIZE_Pos) |
                                     (recalculated.vsize << R_LCDC_VI6_RPF1_SRC_ESIZE_EVSIZE_Pos);

        /* Stride Setting */
        g_dl_body.cmd[15].set_data =
            ((uint32_t) p_rt_cfg->input.hstride << R_LCDC_VI6_RPF1_SRCM_PSTRIDE_PICT_STRD_Y_Pos) |
            ((uint32_t) p_rt_cfg->input.hstride_cbcr <<
                R_LCDC_VI6_RPF1_SRCM_PSTRIDE_PICT_STRD_C_Pos);

        /* Location Setting */
        g_dl_body.cmd[16].set_data = (recalculated.coor_x << R_LCDC_VI6_RPF1_LOC_HCOORD_Pos) |
                                     (recalculated.coor_y << R_LCDC_VI6_RPF1_LOC_VCOORD_Pos);

        /* Input buffer data swap setting */
        g_dl_body.cmd[17].set_data = (uint32_t) (p_rt_cfg->input.data_swap);

        /* Set physical address of buffer to descriptor */
#if defined(BSP_CFG_CORE_CA55)
        va = (uint64_t) (recalculated.p_base_cb) & CAST_TO_UINT32;
        R_BSP_MmuVatoPa(va, (void *) &pa);
        g_dl_body.cmd[23].set_data = pa & CAST_TO_UINT32;

        va = (uint64_t) (recalculated.p_base_cr) & CAST_TO_UINT32;
        R_BSP_MmuVatoPa(va, (void *) &pa);
        g_dl_body.cmd[24].set_data = pa & CAST_TO_UINT32;
#else
        g_dl_body.cmd[23].set_data = (uint32_t) (recalculated.p_base_cb) & CAST_TO_UINT32;
        g_dl_body.cmd[24].set_data = (uint32_t) (recalculated.p_base_cr) & CAST_TO_UINT32;
#endif
    }
    else
    {
        /* Do Nothing */
    }

    /* RPF0(if layer1 is used), RPF1(if layer 2 is used) and Virtual RPF start enable via display list */
    g_dl_body.cmd[0].set_data = p_ctrl->layer_status;

    /* Display List update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;
}

/*******************************************************************************************************************//**
 * Color Keying setting for selected layer
 *
 * @param[in]       ck_cfg      LCDC configuration parameters for color keying
 * @param[in]       layer       selected layer number
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_ckey_set (display_colorkeying_layer_t ck_cfg, display_frame_layer_t layer)
{
    /* Change color keying setting via display list */
    if (layer == DISPLAY_FRAME_LAYER_1)
    {
        g_dl_body.cmd[8].set_data  = (uint32_t) (ck_cfg.layer[layer].enable_ckey << R_LCDC_VI6_RPF0_CKEY_CTRL_CV_Pos);
        g_dl_body.cmd[9].set_data  = ck_cfg.layer[layer].src_color.argb;
        g_dl_body.cmd[10].set_data = ck_cfg.layer[layer].dst_color.argb;
    }
    else
    {
        /* Do Nothing */
    }

    if (layer == DISPLAY_FRAME_LAYER_2)
    {
        g_dl_body.cmd[18].set_data = (uint32_t) (ck_cfg.layer[layer].enable_ckey << R_LCDC_VI6_RPF1_CKEY_CTRL_CV_Pos);
        g_dl_body.cmd[19].set_data = ck_cfg.layer[layer].src_color.argb;
        g_dl_body.cmd[20].set_data = ck_cfg.layer[layer].dst_color.argb;
    }
    else
    {
        /* Do Nothing */
    }

    /* Display List update */
    R_LCDC->VI6_DL_BODY_SIZE0_b.UPD0 = 1;
}

/*******************************************************************************************************************//**
 *  Set the interrupt setting for LCDC module
 *
 * @param[in]       p_cfg       LCDC configuration parameters
 * @param[in]       p_instance_ctrl     Instance pointer of LCDC control
 * @retval          none
 **********************************************************************************************************************/
static void r_lcdc_interrupt_enable (display_cfg_t const * const p_cfg, lcdc_instance_ctrl_t * const p_instance_ctrl)
{
    lcdc_extended_cfg_t * pextend = (lcdc_extended_cfg_t *) p_cfg->p_extend;

    /* Display IRQ Status clear.
     * Interrupt status clear for 'Display Start' and 'Display Read Data End' */
    R_LCDC->VI6_DISP0_IRQ_STA &= ~(1U << R_LCDC_VI6_DISP0_IRQ_STA_MAE_Pos | 1U << R_LCDC_VI6_DISP0_IRQ_STA_DST_Pos);

    /* LCDC Interrupt Setting.
     * Interrupt Enable for 'Frame End' and 'DU Connection UnderRun Error' */
    R_LCDC->VI6_WPF0_IRQ_ENB |= (1U << R_LCDC_VI6_WPF0_IRQ_ENB_FREE_Pos) |
                                (1U << R_LCDC_VI6_WPF0_IRQ_ENB_UNDE_Pos);

    if (pextend->frame_end_irq >= 0)
    {
        R_BSP_IrqCfgEnable(pextend->frame_end_irq, pextend->frame_end_ipl, p_instance_ctrl);
    }
}

/*******************************************************************************************************************//**
 *  Interrupt function for LCDC VSPD interrupt
 **********************************************************************************************************************/
void lcdc_vspd_int (void)
{
    LCDC_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    FSP_CONTEXT_SAVE;

    IRQn_Type irq = R_FSP_CurrentIrqGet();

    /* Recover ISR context saved in open */
    lcdc_instance_ctrl_t * p_ctrl = (lcdc_instance_ctrl_t *) R_FSP_IsrContextGet(irq);

    display_callback_args_t args;
    display_event_t         event = (display_event_t) 0;

    /* Check which interrupt is generated */
    if (1 == R_LCDC->VI6_WPF0_IRQ_STA_b.FRE)
    {
        event = DISPLAY_EVENT_FRAME_END;
    }
    else
    {
        /* Do Nothing */
    }

    if (1 == R_LCDC->VI6_WPF0_IRQ_STA_b.UND)
    {
        event = DISPLAY_EVENT_GR1_UNDERFLOW;
    }
    else
    {
        /* Do Nothing */
    }

    /* Call back callback function if it is registered */
    if (NULL != p_ctrl->p_callback)
    {
        args.event     = event;
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear interrupt flag */
    R_LCDC->VI6_WPF0_IRQ_STA &= ~((1U << R_LCDC_VI6_WPF0_IRQ_STA_FRE_Pos) | (1U << R_LCDC_VI6_WPF0_IRQ_STA_UND_Pos));

    /* Dummy read to ensure that interrupt event is cleared. */
    FSP_REGISTER_READ(R_LCDC->VI6_WPF0_IRQ_STA);

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    LCDC_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#if (LCDC_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * The parameter checking subroutine for R_LCDC_Open API.
 *
 * @param[in] p_cfg   Pointer to the configuration structure for display interface
 * @retval  FSP_SUCCESS                      No parameter error found
 * @retval  FSP_ERR_ASSERTION                Pointer to the control block is NULL.
 * @retval  FSP_ERR_INVALID_TIMING_SETTING   Invalid timing parameter.
 * @retval  FSP_ERR_INVALID_LAYER_SETTING    Invalid layer parameter
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check (display_cfg_t const * const p_cfg)
{
    FSP_ASSERT(p_cfg);
    FSP_ASSERT(p_cfg->p_extend);

    /* Sync signal parameter check */
    fsp_err_t err = r_lcdc_open_param_check_sync_signal(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = r_lcdc_open_param_check_layer_setting(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking subroutine for R_LCDC_Open API.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_TIMING_SETTING      Invalid timing parameter.
 * @retval      FSP_ERR_INVALID_LAYER_SETTING       Invalid layer parameter
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_sync_signal (display_cfg_t const * const p_cfg)
{
    fsp_err_t err = r_lcdc_open_param_check_display_cycle(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = r_lcdc_open_param_check_display_timing(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = r_lcdc_open_param_check_layer_setting(p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking for display cycle.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_TIMING_SETTING      Invalid timing parameter.
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_display_cycle (display_cfg_t const * const p_cfg)
{
    uint32_t h_active = p_cfg->output.htiming.display_cyc;
    uint32_t v_active = p_cfg->output.vtiming.display_cyc;

    FSP_ERROR_RETURN((h_active <= TIMING_MAX_1920), FSP_ERR_INVALID_TIMING_SETTING);
    FSP_ERROR_RETURN((v_active <= TIMING_MAX_1080), FSP_ERR_INVALID_TIMING_SETTING);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking for display timing.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_TIMING_SETTING      Invalid timing parameter.
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_display_timing (display_cfg_t const * const p_cfg)
{
    /* Vertical signal timing setting restrictions are as follows
     * (See section "DU_DITR1 : DU Display I/F Timing Register 1" and
     *  "DU_DITR2 : DU Display I/F Timing Register 2" in the RZ microprocessor Hardware Manual for details):
     *   - VSA available value     : DU_DITR1.VSA[11:0] -> max.4095
     *   - VACTIVE available value : DU_DITR1.VACTIVE[28:16] -> min.1, max.8190
     *   - VBP available value     : DU_DITR2.VBP[12:0] -> max.8191
     *   - VFP available value     : DU_DITR2.VFP[12:0] -> max.8191
     *
     * p_cfg->output.vtiming.display_cyc sets the value of VACTIVE,
     * so p_cfg->output.vtining.display_cyc value is greater than 0. */
    FSP_ERROR_RETURN((p_cfg->output.vtiming.display_cyc >= LCDC_DU_DITR1_VACTIVE_MIN), FSP_ERR_INVALID_TIMING_SETTING);

    /* p_cfg->output.vtiming.sync_width sets the value of VSA,
     * so p_cfg->output.vtiming.sync_width available max value is 4095. */
    uint32_t v_sa = p_cfg->output.vtiming.sync_width;
    FSP_ERROR_RETURN(LCDC_DU_DITR1_VSA_MAX >= v_sa, FSP_ERR_INVALID_TIMING_SETTING);

    /* p_cfg->output.vtiming.back_porch - p_cfg->output.vtiming.sync_width set the value of VBP,
     * so p_cfg->output.vtiming.back_porch - p_cfg->output.vtiming.sync_width value is less than or equal to 8191. */
    uint32_t v_bp = (uint32_t) (p_cfg->output.vtiming.back_porch - p_cfg->output.vtiming.sync_width);
    FSP_ERROR_RETURN(LCDc_DU_DITR2_VBP_MAX >= v_bp, FSP_ERR_INVALID_TIMING_SETTING);

    /* DU_DITR1.VSA (Vsync period) + DU_DITR2.VBP (Vback period) should be set more than 0. */
    FSP_ERROR_RETURN((v_sa + v_bp) > 0, FSP_ERR_INVALID_TIMING_SETTING);

    /* p_cfg->output.vtiming.total_cyc set the value of VSA + VBP + VACTIVE + VFP,
     * so p_cfg->output.vtiming.total_cyc available max value is 4095 + 8191 + 8190 + 8191. */
    FSP_ERROR_RETURN(p_cfg->output.vtiming.total_cyc <=
                     LCDC_DU_DITR1_VSA_MAX + LCDc_DU_DITR2_VBP_MAX + LCDC_DU_DITR1_VACTIVE_MAX + LCDC_DU_DITR2_VFP_MAX,
                     FSP_ERR_INVALID_TIMING_SETTING);

    /* Horizontal signal timing setting restrictions are as follows
     * (See section "DU_DITR3 : DU Display I/F Timing Register 3" and
     *  "DU_DITR4 : DU Display I/F Timing Register 4" in the RZ microprocessor Hardware Manual for details):
     *   - HSA available value     : DU_DITR3.HSA[11:0] -> max.4095
     *   - HACTIVE available value : DU_DITR3.HACTIVE[12:0] -> min.1, max.8190
     *   - HBP available value     : DU_DITR4.HBP[12:0] -> max.8191
     *   - HFP available value     : DU_DITR4.HFP[12:0] -> max.8191
     *
     * p_cfg->output.htiming.display_cyc sets the value of HACTIVE,
     * so p_cfg->output.htining.display_cyc value is greater than 0. */
    FSP_ERROR_RETURN((p_cfg->output.htiming.display_cyc >= LCDC_DU_DITR3_HACTIVE_MIN), FSP_ERR_INVALID_TIMING_SETTING);

    /* p_cfg->output.htiming.sync_width sets the value of HSA,
     * so p_cfg->output.htiming.sync_width available max value is 4095. */
    uint32_t h_sa = p_cfg->output.htiming.sync_width;
    FSP_ERROR_RETURN(LCDC_DU_DITR3_HSA_MAX >= h_sa, FSP_ERR_INVALID_TIMING_SETTING);

    /* p_cfg->output.htiming.back_porch - p_cfg->output.htiming.sync_width set the value of HBP,
     * so p_cfg->output.htiming.back_porch - p_cfg->output.htiming.sync_width value is less than or equal to 8191. */
    uint32_t h_bp = (uint32_t) (p_cfg->output.htiming.back_porch - p_cfg->output.htiming.sync_width);
    FSP_ERROR_RETURN(LCDC_DU_DITR4_HBP_MAX >= h_bp, FSP_ERR_INVALID_TIMING_SETTING);

    /* DU_DITR3.HSA (Hsync period) + DU_DITR4.HBP (Hback period) + DU_DITR4.HFP (Hfront) should be set 3 or more. */
    uint32_t h_fp =
        (uint32_t) (p_cfg->output.htiming.total_cyc - p_cfg->output.htiming.back_porch -
                    p_cfg->output.htiming.display_cyc);
    FSP_ERROR_RETURN((h_sa + h_bp + h_fp) >= 3, FSP_ERR_INVALID_TIMING_SETTING);

    /* p_cfg->output.htiming.total_cyc set the value of HSA + HBP + HACTIVE + HFP,
     * so p_cfg->output.htiming.total_cyc available max value is 4095 + 8191 + 8191 + 8191. */
    FSP_ERROR_RETURN(p_cfg->output.htiming.total_cyc <=
                     LCDC_DU_DITR3_HSA_MAX + LCDC_DU_DITR4_HBP_MAX + LCDC_DU_DITR3_HACTIVE_MAX + LCDC_DU_DITR4_HFP_MAX,
                     FSP_ERR_INVALID_TIMING_SETTING);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * The parameter checking for layer setting.
 *
 * @param[in]   p_cfg   Pointer to the configuration structure for display interface
 * @retval      FSP_SUCCESS                         No parameter error found
 * @retval      FSP_ERR_INVALID_LAYER_SETTING       Invalid layer parameter
 **********************************************************************************************************************/
static fsp_err_t r_lcdc_open_param_check_layer_setting (display_cfg_t const * const p_cfg)
{
    for (uint32_t layer_num = 0; layer_num <= DISPLAY_FRAME_LAYER_2; layer_num++)
    {
        if (p_cfg->input[layer_num].p_base)
        {
            FSP_ERROR_RETURN((p_cfg->input[layer_num].hsize <= LAYER_MAX_HSIZE), FSP_ERR_INVALID_LAYER_SETTING);
            FSP_ERROR_RETURN((p_cfg->input[layer_num].vsize <= LAYER_MAX_VSIZE), FSP_ERR_INVALID_LAYER_SETTING);
        }
        else
        {
            /* Do Nothing */
        }
    }

    return FSP_SUCCESS;
}

#endif
