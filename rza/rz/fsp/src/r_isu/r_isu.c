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
#include "r_isu.h"
#include "r_isu_cfg.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Register data settings */
#define ENABLE_INTERRUPT                (0x00000003)
#define START_PROSESSING                (0x00010001)
#define DESCRIPTOR_START                (0x00000002)
#define DESCRIPTOR_STOP                 (0x00000000)
#define DESCRIPTOR_NEXT_ADD_L           (0x00000000)
#define DESCRIPTOR_NEXT_ADD_H           (0x00000000)

/* Register offset address for descriptor list*/
#define OFFSET_ADDR_RPF_SRC_SIZE        (0x00000100)
#define OFFSET_ADDR_RPF_SRC_STRD        (0x00000104)
#define OFFSET_ADDR_RPF_SRC_ADDH_PL0    (0x00000108)
#define OFFSET_ADDR_RPF_SRC_ADDL_PL0    (0x0000010C)
#define OFFSET_ADDR_RPF_SRC_ADDH_PL1    (0x00000110)
#define OFFSET_ADDR_RPF_SRC_ADDL_PL1    (0x00000114)
#define OFFSET_ADDR_RPF_FMT             (0x00000118)
#define OFFSET_ADDR_RPF_SRC_DSWAP       (0x00000120)
#define OFFSET_ADDR_RS_HSCALE           (0x00000140)
#define OFFSET_ADDR_RS_VSCALE           (0x00000144)
#define OFFSET_ADDR_RS_OS_CROP          (0x00000150)
#define OFFSET_ADDR_WPF_DST_ADDH_PH0    (0x00000180)
#define OFFSET_ADDR_WPF_DST_ADDL_PL0    (0x00000184)
#define OFFSET_ADDR_WPF_DST_ADDL_PH1    (0x00000188)
#define OFFSET_ADDR_WPF_DST_ADDL_PL1    (0x0000018C)
#define OFFSET_ADDR_WPF_DST_STRD        (0x00000190)
#define OFFSET_ADDR_WPF_FMT             (0x00000194)
#define OFFSET_ADDR_WPF_CCOL            (0x00000198)
#define OFFSET_ADDR_WPF_MUL1            (0x0000019C)
#define OFFSET_ADDR_WPF_MUL2            (0x000001A0)
#define OFFSET_ADDR_WPF_MUL3            (0x000001A4)
#define OFFSET_ADDR_WPF_MUL4            (0x000001A8)
#define OFFSET_ADDR_WPF_MUL5            (0x000001AC)
#define OFFSET_ADDR_WPF_MUL6            (0x000001B0)
#define OFFSET_ADDR_WPF_OSFT1           (0x000001B4)
#define OFFSET_ADDR_WPF_OFST2           (0x000001B8)
#define OFFSET_ADDR_WPF_CLP1            (0x000001BC)
#define OFFSET_ADDR_WPF_CLP2            (0x000001C0)
#define OFFSET_ADDR_WPF_DST_DSWAP       (0x000001C4)

/* Offset address for descriptor list*/
#define ISU_FM_DESCRIPTOR_OFFSET_0      0
#define ISU_FM_DESCRIPTOR_OFFSET_1      1
#define ISU_FM_DESCRIPTOR_OFFSET_2      2
#define ISU_FM_DESCRIPTOR_OFFSET_3      3
#define ISU_FM_DESCRIPTOR_OFFSET_4      4
#define ISU_FM_DESCRIPTOR_OFFSET_5      5
#define ISU_FM_DESCRIPTOR_OFFSET_6      6
#define ISU_FM_DESCRIPTOR_OFFSET_7      7
#define ISU_FM_DESCRIPTOR_OFFSET_8      8
#define ISU_FM_DESCRIPTOR_OFFSET_9      9
#define ISU_FM_DESCRIPTOR_OFFSET_10     10
#define ISU_FM_DESCRIPTOR_OFFSET_11     11
#define ISU_FM_DESCRIPTOR_OFFSET_12     12
#define ISU_FM_DESCRIPTOR_OFFSET_13     13
#define ISU_FM_DESCRIPTOR_OFFSET_14     14
#define ISU_FM_DESCRIPTOR_OFFSET_15     15
#define ISU_FM_DESCRIPTOR_OFFSET_16     16
#define ISU_FM_DESCRIPTOR_OFFSET_17     17
#define ISU_FM_DESCRIPTOR_OFFSET_18     18
#define ISU_FM_DESCRIPTOR_OFFSET_19     19
#define ISU_FM_DESCRIPTOR_OFFSET_20     20
#define ISU_FM_DESCRIPTOR_OFFSET_21     21
#define ISU_FM_DESCRIPTOR_OFFSET_22     22
#define ISU_FM_DESCRIPTOR_OFFSET_23     23
#define ISU_FM_DESCRIPTOR_OFFSET_24     24
#define ISU_FM_DESCRIPTOR_OFFSET_25     25
#define ISU_FM_DESCRIPTOR_OFFSET_26     26
#define ISU_FM_DESCRIPTOR_OFFSET_27     27
#define ISU_FM_DESCRIPTOR_OFFSET_28     28

/* Set data for color format conversion */
#define VAL_WPF_CCOL_ENABLE             (0x00000002)
#define VAL_WPF_MUL1_YUV2RGB            (0x000004A8)
#define VAL_WPF_MUL2_YUV2RGB            (0x00000662)
#define VAL_WPF_MUL3_YUV2RGB            (0x000004A8)
#define VAL_WPF_MUL4_YUV2RGB            (0x3E703CBF)
#define VAL_WPF_MUL5_YUV2RGB            (0x000004A8)
#define VAL_WPF_MUL6_YUV2RGB            (0x08120000)
#define VAL_WPF_OFST1_YUV2RGB           (0x10808000)
#define VAL_WPF_OFST2_YUV2RGB           (0x00000000)
#define VAL_WPF_CLP1_YUV2RGB            (0x0000FF00)
#define VAL_WPF_CLK2_YUV2RGB            (0xFF00FF00)
#define VAL_WPF_MUL1_RGB2YUV            (0x00000107)
#define VAL_WPF_MUL2_RGB2YUV            (0x02040064)
#define VAL_WPF_MUL3_RGB2YUV            (0x00003F68)
#define VAL_WPF_MUL4_RGB2YUV            (0x3ED601C2)
#define VAL_WPF_MUL5_RGB2YUV            (0x000001C2)
#define VAL_WPF_MUL6_RGB2YUV            (0x3E873FB7)
#define VAL_WPF_OFST1_RGB2YUV           (0x00000000)
#define VAL_WPF_OFST2_RGB2YUV           (0x10808000)
#define VAL_WPF_CLP1_RGB2YUV            (0x0000EB10)
#define VAL_WPF_CLP2_RGB2YUV            (0xF010F010)
#define VAL_WPF_MUL1_DISABLE            (0x00000400)
#define VAL_WPF_MUL4_DISABLE            (0x04000000)
#define VAL_WPF_MUL6_DISABLE            (0x00000400)
#define VAL_WPF_REGISTER_NOT_USED       (0x00000000)
#define VAL_FM_DL_STADDH_NOT_USED       (0x00000000)

#define MICRO_WAIT_10                   (10U)
#define CAL_RESIZE_RATE_4096            (4096U)
#define DESCRIPTOR_BODY_SIZE            (29U)
#define DESCRIPTOR_HEADER               (0x000000E8)
#define CLEAR_INTERRUPT_DESEND          (0xFFFFFFFD)
#define CLEAR_INTERRUPT_FREND           (0xFFFFFFFE)

/* The parameter for checking error */
#define SCALING_INPUT_HSIZE_MIN         (1U)
#define SCALING_INPUT_VSIZE_MIN         (1U)
#define SCALING_INPUT_HSIZE_MAX         (2800U)
#define SCALING_INPUT_VSIZE_MAX         (2047U)
#define CHECK_ALIGNMENT_32              (32U)
#define CHECK_ALIGNMENT_64              (64U)
#define CHECK_ALIGNMENT_512             (512U)
#define FORMAT_MIN_INVALID              (0U)
#define FORMAT_MAX_INVALID              (12U)

#define CAST_TO_UINT32                  (0xFFFFFFFF)
#define BIT_SHIFT_16                    (16U)
#define BIT_SHIFT_32                    (32U)
#define DESCRIPTION_ALINMENT_32         (32U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef struct
{
    uint32_t set_address;
    uint32_t set_data;
} addr_and_data_t;

typedef struct
{
    uint32_t        header;
    addr_and_data_t cmd[DESCRIPTOR_BODY_SIZE];
    uint32_t        next_address_l;
    uint32_t        next_address_h;
    uint32_t        dexsriptor_ctrl;
} descriptor_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_isu_start_process();
static void r_isu_fm_set_addr();
static void r_isu_fm_set_data(isu_runtime_cfg_t const * const p_cfg);
static void r_isu_irqcfg_enable(isu_instance_ctrl_t * const p_instance_ctrl);
void        isu_int_fre_isr(IRQn_Type const irq);

#if (ISU_CFG_PARAM_CHECKING_ENABLE)
static fsp_err_t r_isu_open_param_check(isu_runtime_cfg_t * const p_cfg);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

static const uint32_t scaling_format_table[] =
{
    /* This table is used for the color format of the input image to use for scaling
     * If you selected RGB565 as input format, 0x00000001 is written to the RDFMT register in ISU_RPF_FMT */

    0x00000001,                        /* RGB565 */
    0x00000003,                        /* RGB888 */
    0x00000004,                        /* BGR888 */
    0x00000005,                        /* ARGB8888 */
    0x00000006,                        /* RGBA8888 */
    0x00000007,                        /* ABGR8888 */
    0x00000020,                        /* YCbCr422, UYVY */
    0x00000021,                        /* YCbCr422, YUY2 */
    0x00000022,                        /* YCbCr422, NV16 */
    0x00000023,                        /* YCbCr420, NV12 */
    0x00000030,                        /* RAW8 */
    0x00000031,                        /* RAW10 */
    0x00000032,                        /* RAW12 */
};

static descriptor_t descriptor_cfg __attribute__((section("UNCACHED_BSS"),
                                                  __aligned__(DESCRIPTION_ALINMENT_32)));
static isu_instance_ctrl_t r_isu_blk;

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* ISU Implementation of ISU Driver */
const isu_api_t g_isu_on_isu =
{
    .open      = R_ISU_Open,
    .close     = R_ISU_Close,
    .start     = R_ISU_Start,
    .changeCfg = R_ISU_ChangeCfg,
};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZA
{
#endif
#endif

/*******************************************************************************************************************//**
 *
 * @addtogroup RZA_ISU
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 *　Initializes the ISU modules and set interrupt configuration
 *
 * @retval FSP_SUCCESS              Initializes the ISU modules.
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_ALREADY_OPEN     IRU module is already open
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument error
 * @retval FSP_ERR_INVALID_ALIGNMENT       Input buffer alignment
 **********************************************************************************************************************/
fsp_err_t R_ISU_Open (isu_ctrl_t * const p_api_ctrl, isu_cfg_t const * const p_cfg)
{
    fsp_err_t             err           = FSP_SUCCESS;
    isu_instance_ctrl_t * p_ctrl        = (isu_instance_ctrl_t *) p_api_ctrl;
    isu_runtime_cfg_t   * p_cfg_runtime = (isu_runtime_cfg_t *) p_cfg;

#if  (ISU_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters */
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(ISU_STATE_IDLE == p_ctrl->state, FSP_ERR_ALREADY_OPEN);
    err = r_isu_open_param_check(p_cfg_runtime);
    if (FSP_SUCCESS != err)
    {
        return err;
    }
#endif

    p_ctrl->p_cfg       = p_cfg;
    p_ctrl->p_context   = p_cfg->p_context;
    p_ctrl->p_callback  = p_cfg->p_callback;
    r_isu_blk.p_context = p_ctrl;

    /* ISU clock start */
    R_BSP_MODULE_START(FSP_IP_ISU, 0);

    /* Flow Management configuration */
    r_isu_fm_set_addr();
    r_isu_fm_set_data(p_cfg_runtime);

    /* Configuration interrupt */
    r_isu_irqcfg_enable(p_api_ctrl);

    p_ctrl->state = ISU_IN_PROGRESS;

    return err;
}

/*******************************************************************************************************************//**
 *　Close the ISU modules
 *
 * @retval FSP_SUCCESS          Close the ISU module
 * @retval FSP_ERR_ASSERTION    Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     ISU module is not ISU_IN_PROGRESS or ISU_STATE_BUSY
 **********************************************************************************************************************/
fsp_err_t R_ISU_Close (isu_ctrl_t * const p_api_ctrl)
{
    fsp_err_t             err    = FSP_SUCCESS;
    isu_instance_ctrl_t * p_ctrl = (isu_instance_ctrl_t *) p_api_ctrl;

#if  (ISU_CFG_PARAM_CHECKING_ENABLE)

    /* Check parameters */
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(ISU_STATE_IDLE != p_ctrl->state, FSP_ERR_INVALID_MODE);
#endif

    /* Disable frame end interrupt by description */
    descriptor_cfg.dexsriptor_ctrl = DESCRIPTOR_STOP;

    R_BSP_MODULE_STOP(FSP_IP_ISU, 0);

    p_ctrl->state = ISU_STATE_IDLE;

    return err;
}

/*******************************************************************************************************************//**
 *　Start scaling the input image
 *
 * @retval FSP_SUCCESS              start a capture.
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     ISU module is not ready.
 **********************************************************************************************************************/
fsp_err_t R_ISU_Start (isu_ctrl_t * const p_api_ctrl)
{
    fsp_err_t             err    = FSP_SUCCESS;
    isu_instance_ctrl_t * p_ctrl = (isu_instance_ctrl_t *) p_api_ctrl;
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#endif
#if  (ISU_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(ISU_IN_PROGRESS == p_ctrl->state, FSP_ERR_INVALID_MODE);
#endif

    /* set descriptor address */
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (&descriptor_cfg);
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    R_ISU->ISU_FM_DL_STADDH = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT32;
    R_ISU->ISU_FM_DL_STADDL = (uint32_t) (pa) & CAST_TO_UINT32;
#else
    R_ISU->ISU_FM_DL_STADDH = VAL_FM_DL_STADDH_NOT_USED;
    R_ISU->ISU_FM_DL_STADDL = (uint64_t) &descriptor_cfg & CAST_TO_UINT32;
#endif

    /* set footer data of description */
    descriptor_cfg.next_address_h  = DESCRIPTOR_NEXT_ADD_H;
    descriptor_cfg.next_address_l  = DESCRIPTOR_NEXT_ADD_L;
    descriptor_cfg.dexsriptor_ctrl = DESCRIPTOR_START;

    /* Enable frame end interruption */
    R_ISU->ISU_FM_INT_EN = ENABLE_INTERRUPT;

    /* Wait 10 microsecond */
    R_BSP_SoftwareDelay(MICRO_WAIT_10, BSP_DELAY_UNITS_MICROSECONDS);

    r_isu_start_process();

    p_ctrl->state = ISU_STATE_BUSY;

    return err;
}

/*******************************************************************************************************************//**
 *　Change scaling configuration
 *
 * @retval FSP_SUCCESS              Change scaling configuration.
 * @retval FSP_ERR_ASSERTION        Pointer to the control block is NULL.
 * @retval FSP_ERR_INVALID_MODE     ISU module is not ready.
 * @retval FSP_ERR_INVALID_ARGUMENT Invalid argument error
 * @retval FSP_ERR_INVALID_ALIGNMENT Invalid alignment error
 **********************************************************************************************************************/
fsp_err_t R_ISU_ChangeCfg (isu_ctrl_t * const p_api_ctrl, isu_runtime_cfg_t * const p_runtime_cfg)
{
    fsp_err_t             err    = FSP_SUCCESS;
    isu_instance_ctrl_t * p_ctrl = (isu_instance_ctrl_t *) p_api_ctrl;

#if  (ISU_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_ctrl);
    FSP_ERROR_RETURN(ISU_STATE_BUSY == p_ctrl->state, FSP_ERR_INVALID_MODE);
    err = r_isu_open_param_check(p_runtime_cfg);
    if (FSP_SUCCESS != err)
    {
        return err;
    }
#endif

    /* Flow Management configuration */
    r_isu_fm_set_data(p_runtime_cfg);

    /* Wait 10 microsecond */
    R_BSP_SoftwareDelay(MICRO_WAIT_10, BSP_DELAY_UNITS_MICROSECONDS);

    r_isu_start_process();

    p_ctrl->state = ISU_STATE_BUSY;

    return err;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup IOPORT)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/***********************************************************************************************************************
 * Private Functions
 *
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Set the address offset for frame management
 *
 * @retval        none
 **********************************************************************************************************************/
static void r_isu_fm_set_addr (void)
{
    /* set footer data of descriptor */
    descriptor_cfg.header = DESCRIPTOR_HEADER;

    /* set descriptor for register address */
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_0].set_address  = OFFSET_ADDR_RPF_SRC_SIZE;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_1].set_address  = OFFSET_ADDR_RPF_SRC_STRD;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_2].set_address  = OFFSET_ADDR_RPF_SRC_ADDH_PL0;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_3].set_address  = OFFSET_ADDR_RPF_SRC_ADDL_PL0;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_4].set_address  = OFFSET_ADDR_RPF_SRC_ADDH_PL1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_5].set_address  = OFFSET_ADDR_RPF_SRC_ADDL_PL1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_6].set_address  = OFFSET_ADDR_RPF_FMT;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_7].set_address  = OFFSET_ADDR_RPF_SRC_DSWAP;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_8].set_address  = OFFSET_ADDR_RS_HSCALE;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_9].set_address  = OFFSET_ADDR_RS_VSCALE;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_10].set_address = OFFSET_ADDR_RS_OS_CROP;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_11].set_address = OFFSET_ADDR_WPF_DST_ADDH_PH0;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_12].set_address = OFFSET_ADDR_WPF_DST_ADDL_PL0;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_13].set_address = OFFSET_ADDR_WPF_DST_ADDL_PH1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_14].set_address = OFFSET_ADDR_WPF_DST_ADDL_PL1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_15].set_address = OFFSET_ADDR_WPF_DST_STRD;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_16].set_address = OFFSET_ADDR_WPF_FMT;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_17].set_address = OFFSET_ADDR_WPF_CCOL;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_18].set_address = OFFSET_ADDR_WPF_MUL1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_19].set_address = OFFSET_ADDR_WPF_MUL2;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_20].set_address = OFFSET_ADDR_WPF_MUL3;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_21].set_address = OFFSET_ADDR_WPF_MUL4;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_22].set_address = OFFSET_ADDR_WPF_MUL5;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_23].set_address = OFFSET_ADDR_WPF_MUL6;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_24].set_address = OFFSET_ADDR_WPF_OSFT1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_25].set_address = OFFSET_ADDR_WPF_OFST2;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_26].set_address = OFFSET_ADDR_WPF_CLP1;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_27].set_address = OFFSET_ADDR_WPF_CLP2;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_28].set_address = OFFSET_ADDR_WPF_DST_DSWAP;
}

/*******************************************************************************************************************//**
 * Set the register data for frame management
 *
 * @param[in]     p_cfg       ISU configuration parameters
 * @retval        none
 **********************************************************************************************************************/
static void r_isu_fm_set_data (isu_runtime_cfg_t const * const p_cfg)
{
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    uint64_t pa;                       /* Physical Address */
    uint64_t va;                       /* Virtual Address */
#else
    uint64_t buffer_address;           /* Used to store address of buffer*/
#endif

    uint32_t resize_hrate_int;
    uint32_t resize_hrate_dec;
    uint32_t resize_vrate_int;
    uint32_t resize_vrate_dec;
    float    hrate_cal;
    float    vrate_cal;
    uint32_t int_cast_val;

    /* calculate parameters set in registers */
    /* Calculation for horizontal resize rate */
    resize_hrate_int = p_cfg->input.hsize / p_cfg->output.hsize;
    hrate_cal        = (float) p_cfg->input.hsize / (float) p_cfg->output.hsize;
    int_cast_val     = (uint32_t) (hrate_cal * CAL_RESIZE_RATE_4096);
    resize_hrate_dec = (uint32_t) (int_cast_val - resize_hrate_int * CAL_RESIZE_RATE_4096);

    /* Calculation for vertical resize rate */
    resize_vrate_int = p_cfg->input.vsize / p_cfg->output.vsize;
    vrate_cal        = (float) p_cfg->input.vsize / (float) p_cfg->output.vsize;
    int_cast_val     = (uint32_t) (vrate_cal * CAL_RESIZE_RATE_4096);
    resize_vrate_dec = (uint32_t) (int_cast_val - resize_vrate_int * CAL_RESIZE_RATE_4096);

    /* set descriptor for register data */
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_0].set_data = (p_cfg->input.hsize << BIT_SHIFT_16) |
                                                              (p_cfg->input.vsize);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_1].set_data = p_cfg->input.hstride << BIT_SHIFT_16;

#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->input.p_base) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_2].set_data = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_3].set_data = (uint32_t) (pa) & CAST_TO_UINT32;
#else
    buffer_address = p_cfg->input.p_base;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_2].set_data = (uint32_t) (buffer_address >> BIT_SHIFT_32) &
                                                              CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_3].set_data = (uint32_t) buffer_address & CAST_TO_UINT32;
#endif
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->input.p_base_cbcr) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_4].set_data = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_5].set_data = (uint32_t) (pa) & CAST_TO_UINT32;
#else
    buffer_address = p_cfg->input.p_base_cbcr;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_4].set_data = (uint32_t) (buffer_address >> BIT_SHIFT_32) &
                                                              CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_5].set_data = (uint32_t) buffer_address & CAST_TO_UINT32;
#endif
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_6].set_data  = scaling_format_table[p_cfg->input.format];
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_7].set_data  = p_cfg->input.data_swap;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_8].set_data  = (resize_hrate_int << BIT_SHIFT_16) | (resize_hrate_dec);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_9].set_data  = (resize_vrate_int << BIT_SHIFT_16) | (resize_vrate_dec);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_10].set_data = (p_cfg->output.hsize << BIT_SHIFT_16) |
                                                               (p_cfg->output.vsize);
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->output.p_base) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_11].set_data = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_12].set_data = (uint32_t) (pa) & CAST_TO_UINT32;
#else
    buffer_address = p_cfg->output.p_base;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_11].set_data = (uint32_t) (buffer_address >> BIT_SHIFT_32) &
                                                               CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_12].set_data = (uint32_t) buffer_address & CAST_TO_UINT32;
#endif
#if (BSP_FEATURE_BSP_HAS_MMU_SUPPORT)
    va = (uint64_t) (p_cfg->output.p_base_cbcr) & CAST_TO_UINT32;
    R_MMU_VAtoPA(&g_mmu_ctrl, va, (void *) &pa);
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_13].set_data = (uint32_t) (pa >> BIT_SHIFT_32) & CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_14].set_data = (uint32_t) (pa) & CAST_TO_UINT32;
#else
    buffer_address = p_cfg->output.p_base_cbcr;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_13].set_data = (uint32_t) (buffer_address >> BIT_SHIFT_32) &
                                                               CAST_TO_UINT32;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_14].set_data = (uint32_t) buffer_address & CAST_TO_UINT32;
#endif
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_15].set_data = p_cfg->output.hstride << BIT_SHIFT_16;
    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_16].set_data = scaling_format_table[p_cfg->output.format];

    /* Color Correction settings */
    /* input format is YCbCr */
    if ((ISU_COLOR_FORMAT_YCBCR422_UYVY <= p_cfg->input.format) &&
        (p_cfg->input.format <= ISU_COLOR_FORMAT_YCBCR420_NV12))
    {
        /* output format is RGB and enable color conversion (BT.601SDTV) */
        if ((ISU_COLOR_FORMAT_RGB565 <= p_cfg->output.format) && (p_cfg->output.format <= ISU_COLOR_FORMAT_ABGR8888))
        {
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_17].set_data = VAL_WPF_CCOL_ENABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_18].set_data = VAL_WPF_MUL1_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_19].set_data = VAL_WPF_MUL2_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_20].set_data = VAL_WPF_MUL3_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_21].set_data = VAL_WPF_MUL4_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_22].set_data = VAL_WPF_MUL5_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_23].set_data = VAL_WPF_MUL6_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_24].set_data = VAL_WPF_OFST1_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_25].set_data = VAL_WPF_OFST2_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_26].set_data = VAL_WPF_CLP1_YUV2RGB;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_27].set_data = VAL_WPF_CLK2_YUV2RGB;
        }
        /* output format is YCbCr and disable color conversion */
        else if ((ISU_COLOR_FORMAT_YCBCR422_UYVY <= p_cfg->output.format) &&
                 (p_cfg->output.format <= ISU_COLOR_FORMAT_YCBCR420_NV12))
        {
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_17].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_18].set_data = VAL_WPF_MUL1_DISABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_19].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_20].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_21].set_data = VAL_WPF_MUL4_DISABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_22].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_23].set_data = VAL_WPF_MUL6_DISABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_24].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_25].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_26].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_27].set_data = VAL_WPF_REGISTER_NOT_USED;
        }
        else
        {
            /* No Operation*/
        }
    }
    /* input format is RGB */
    else if ((ISU_COLOR_FORMAT_RGB565 <= p_cfg->input.format) && (p_cfg->input.format <= ISU_COLOR_FORMAT_ABGR8888))
    {
        /* output format is YCbCr and enable color conversion (BT.601SDTV) */
        if ((ISU_COLOR_FORMAT_YCBCR422_UYVY <= p_cfg->output.format) &&
            (p_cfg->output.format <= ISU_COLOR_FORMAT_YCBCR420_NV12))
        {
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_17].set_data = VAL_WPF_CCOL_ENABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_18].set_data = VAL_WPF_MUL1_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_19].set_data = VAL_WPF_MUL2_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_20].set_data = VAL_WPF_MUL3_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_21].set_data = VAL_WPF_MUL4_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_22].set_data = VAL_WPF_MUL5_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_23].set_data = VAL_WPF_MUL6_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_24].set_data = VAL_WPF_OFST1_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_25].set_data = VAL_WPF_OFST2_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_26].set_data = VAL_WPF_CLP1_RGB2YUV;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_27].set_data = VAL_WPF_CLP2_RGB2YUV;
        }
        /* output format is RGB and disable color conversion */
        else if ((ISU_COLOR_FORMAT_RGB565 <= p_cfg->output.format) &&
                 (p_cfg->output.format <= ISU_COLOR_FORMAT_ABGR8888))
        {
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_17].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_18].set_data = VAL_WPF_MUL1_DISABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_19].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_20].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_21].set_data = VAL_WPF_MUL4_DISABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_22].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_23].set_data = VAL_WPF_MUL6_DISABLE;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_24].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_25].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_26].set_data = VAL_WPF_REGISTER_NOT_USED;
            descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_27].set_data = VAL_WPF_REGISTER_NOT_USED;
        }
        else
        {
            /* No Operation*/
        }
    }
    else
    {
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_17].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_18].set_data = VAL_WPF_MUL1_DISABLE;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_19].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_20].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_21].set_data = VAL_WPF_MUL4_DISABLE;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_22].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_23].set_data = VAL_WPF_MUL6_DISABLE;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_24].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_25].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_26].set_data = VAL_WPF_REGISTER_NOT_USED;
        descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_27].set_data = VAL_WPF_REGISTER_NOT_USED;
    }

    descriptor_cfg.cmd[ISU_FM_DESCRIPTOR_OFFSET_28].set_data = p_cfg->output.data_swap;

    R_BSP_CACHE_CleanInvalidateAll();
}

/*******************************************************************************************************************//**
 * Start scaling processing
 *
 * @retval        none
 **********************************************************************************************************************/
static void r_isu_start_process (void)
{
    uint32_t flag_interrupt;

    /* Start frame processing */
    R_ISU->ISU_FM_FRCON = START_PROSESSING;

    /* Wait for read completion interruption */
    while (1)
    {
        flag_interrupt = R_ISU->ISU_FM_INT_STA_b.DESEND;
        if (true == (flag_interrupt))
        {
            break;
        }
    }

    R_ISU->ISU_FM_INT_STA = CLEAR_INTERRUPT_DESEND;

    /* Wait for frame end interruption */
    while (1)
    {
        flag_interrupt = R_ISU->ISU_FM_INT_STA_b.FREND;
        if (true == (flag_interrupt))
        {
            break;
        }
    }

    R_ISU->ISU_FM_INT_STA = CLEAR_INTERRUPT_FREND;
}

/*******************************************************************************************************************//**
 * Set the interrupt settings for ISU module
 *
 * @param[in]       p_instance_ctrl         ISU instance control block
 * @retval          none
 **********************************************************************************************************************/
static void r_isu_irqcfg_enable (isu_instance_ctrl_t * const p_instance_ctrl)
{
    isu_extended_cfg_t * pextend = (isu_extended_cfg_t *) p_instance_ctrl->p_cfg->p_extend;

    R_BSP_IrqCfgEnable(pextend->isu_frame_end_irq, pextend->isu_frame_end_ipl, p_instance_ctrl);
}

/*******************************************************************************************************************//**
 * Interrupt function for ISU frame end Interrupt
 *
 * @param[in]       irq     FSP error type
 * @retval          none
 **********************************************************************************************************************/
void isu_int_fre_isr (IRQn_Type const irq)
{
    FSP_CONTEXT_SAVE FSP_PARAMETER_NOT_USED(irq);

    isu_callback_args_t args;

    isu_instance_ctrl_t * p_ctrl = (isu_instance_ctrl_t *) r_isu_blk.p_context;

    /* Call back callback function if it is registered */
    if (NULL != p_ctrl->p_callback)
    {
        args.p_context = p_ctrl->p_context;
        p_ctrl->p_callback(&args);
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE
}

#if (ISU_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * Parameter Checking for R_ISU_Open.
 *
 * @param[in]       p_cfg       ISU configuration parameters
 * @retval          FSP_SUCCESS                       No parameter error found
 * @retval          FSP_ERR_ASSERTION                 Pointer to the control block is NULL.
 * @retval          FSP_ERR_INVALID_ARGUMENT          Invalid argument error
 * @retval          FSP_ERR_INVALID_ALIGNMENT         Input buffer alignment
 **********************************************************************************************************************/
static fsp_err_t r_isu_open_param_check (isu_runtime_cfg_t * const p_cfg)
{
    FSP_ASSERT(p_cfg);

    /* check parameter for capture size */
    FSP_ERROR_RETURN(p_cfg->input.hsize >= SCALING_INPUT_HSIZE_MIN, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->input.hsize <= SCALING_INPUT_HSIZE_MAX, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->input.vsize >= SCALING_INPUT_VSIZE_MIN, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(p_cfg->input.vsize <= SCALING_INPUT_VSIZE_MAX, FSP_ERR_INVALID_ARGUMENT);

    /* check parameter for buffer address alignment */
    FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->input.p_base) & CAST_TO_UINT32) % CHECK_ALIGNMENT_64),
                     FSP_ERR_INVALID_ALIGNMENT);
    FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->input.hstride) & CAST_TO_UINT32) % CHECK_ALIGNMENT_32),
                     FSP_ERR_INVALID_ALIGNMENT);
    FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->output.p_base) & CAST_TO_UINT32) % CHECK_ALIGNMENT_512),
                     FSP_ERR_INVALID_ALIGNMENT);
    FSP_ERROR_RETURN(0U == (((uint64_t) (p_cfg->output.hstride) & CAST_TO_UINT32) % CHECK_ALIGNMENT_32),
                     FSP_ERR_INVALID_ALIGNMENT);

    /* check parameter for color format */
    FSP_ERROR_RETURN((p_cfg->input.format >= FORMAT_MIN_INVALID), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_cfg->input.format <= FORMAT_MAX_INVALID), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_cfg->output.format >= FORMAT_MIN_INVALID), FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN((p_cfg->output.format <= FORMAT_MAX_INVALID), FSP_ERR_INVALID_ARGUMENT);

    return FSP_SUCCESS;
}

#endif
