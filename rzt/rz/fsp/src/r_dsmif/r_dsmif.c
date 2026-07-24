/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

#include <r_dsmif_cfg.h>
#include "bsp_api.h"
#include "r_adc_api.h"
#include "r_dsmif.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define DSMIF_CMSH_DEFAULT                          (0x0U)

#if 2U == BSP_FEATURE_DSMIF_UNIT
 #define VECNUM_DSMIF0_CDRUI                        ((IRQn_Type) 343)
 #define VECNUM_DSMIF1_CDRUI                        ((IRQn_Type) 344)
#elif 5U == BSP_FEATURE_DSMIF_UNIT
 #define VECNUM_DSMIF0_CDRUI                        ((IRQn_Type) 533)
 #define VECNUM_DSMIF1_CDRUI                        ((IRQn_Type) 537)
 #define VECNUM_DSMIF2_CDRUI                        ((IRQn_Type) 541)
 #define VECNUM_DSMIF3_CDRUI                        ((IRQn_Type) 545)
 #define VECNUM_DSMIF4_CDRUI                        ((IRQn_Type) 549)
#elif 10U == BSP_FEATURE_DSMIF_UNIT
 #define VECNUM_DSMIF0_CDRUI                        ((IRQn_Type) 658)
 #define VECNUM_DSMIF1_CDRUI                        ((IRQn_Type) 662)
 #define VECNUM_DSMIF2_CDRUI                        ((IRQn_Type) 666)
 #define VECNUM_DSMIF3_CDRUI                        ((IRQn_Type) 670)
 #define VECNUM_DSMIF4_CDRUI                        ((IRQn_Type) 674)
 #define VECNUM_DSMIF5_CDRUI                        ((IRQn_Type) 678)
 #define VECNUM_DSMIF6_CDRUI                        ((IRQn_Type) 682)
 #define VECNUM_DSMIF7_CDRUI                        ((IRQn_Type) 686)
 #define VECNUM_DSMIF8_CDRUI                        ((IRQn_Type) 690)
 #define VECNUM_DSMIF9_CDRUI                        ((IRQn_Type) 694)
#endif

#define DSMIF_OPEN                                  (0x44534D49U)

#define DSMIF_DATA_TYPE_MASK                        (0x0300)
#define DSMIF_DATA_CHANNEL_MASK                     (0x0003)
#define DSMIF_DATA_TYPE_SHIFT                       (0x8)

#if (4U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)

 #define DSMIF_CHANNEL_OVERCURRENT_STATUS_FLAGS     (R_DSMIF0_DSCOCESR_OC0FL0_Msk | R_DSMIF0_DSCOCESR_OC0FL1_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC0FL2_Msk | R_DSMIF0_DSCOCESR_OC0FH0_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC0FH1_Msk | R_DSMIF0_DSCOCESR_OC0FH2_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC1FL0_Msk | R_DSMIF0_DSCOCESR_OC1FL1_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC1FL2_Msk | R_DSMIF0_DSCOCESR_OC1FH0_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC1FH1_Msk | R_DSMIF0_DSCOCESR_OC1FH2_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC2FL0_Msk | R_DSMIF0_DSCOCESR_OC2FL1_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC2FL2_Msk | R_DSMIF0_DSCOCESR_OC2FH0_Msk | \
                                                     R_DSMIF0_DSCOCESR_OC2FH1_Msk | R_DSMIF0_DSCOCESR_OC2FH2_Msk)

 #define DSMIF_OVERCURRENT_NOTIFY_STATUS_FLAGS      (R_DSMIF0_DSCOCNSR_OWD0N0_Msk | R_DSMIF0_DSCOCNSR_OWD0N1_Msk | \
                                                     R_DSMIF0_DSCOCNSR_OWD0N2_Msk | R_DSMIF0_DSCOCNSR_OWD1N0_Msk | \
                                                     R_DSMIF0_DSCOCNSR_OWD1N1_Msk | R_DSMIF0_DSCOCNSR_OWD1N2_Msk | \
                                                     R_DSMIF0_DSCOCNSR_OWD2N0_Msk | R_DSMIF0_DSCOCNSR_OWD2N1_Msk | \
                                                     R_DSMIF0_DSCOCNSR_OWD2N2_Msk | R_DSMIF0_DSCOCNSR_OWD3N0_Msk | \
                                                     R_DSMIF0_DSCOCNSR_OWD3N1_Msk | R_DSMIF0_DSCOCNSR_OWD3N2_Msk)
#else
 #define DSMIF_CHANNEL_OVERCURRENT_STATUS_FLAGS     (R_DSMIF0_DSCESR_OCFL0_Msk | R_DSMIF0_DSCESR_OCFL1_Msk | \
                                                     R_DSMIF0_DSCESR_OCFL2_Msk | R_DSMIF0_DSCESR_OCFH0_Msk | \
                                                     R_DSMIF0_DSCESR_OCFH1_Msk | R_DSMIF0_DSCESR_OCFH2_Msk)
#endif

#define DSMIF_CHANNEL_SHORT_CIRCUIT_STATUS_FLAGS    (R_DSMIF0_DSCESR_SCF0_Msk | \
                                                     R_DSMIF0_DSCESR_SCF1_Msk | R_DSMIF0_DSCESR_SCF2_Msk)
#define DSMIF_OVERCURRENT_SUM_STATUS_FLAGS          (R_DSMIF0_DSCESR_SUMERRL_Msk | R_DSMIF0_DSCESR_SUMERRH_Msk)

#define DSMIF_REGID_MASK                            (0x000000FFU)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

static fsp_err_t r_dsmif_open_param_check(dsmif_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg);

#endif

static void      r_dsmif_start(dsmif_instance_ctrl_t * const p_instance_ctrl);
static fsp_err_t r_dsmif_stop(dsmif_instance_ctrl_t * const p_instance_ctrl);
static void      r_dsmif_open_irq_cfg(dsmif_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg);
static void      r_dsmif_disable_irq(IRQn_Type irq);

void dsmif_cdrui_isr(void);

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** DSMIF Implementation of DSMIF interface. */
const adc_api_t g_adc_on_dsmif =
{
    .open          = R_DSMIF_Open,
    .scanStart     = R_DSMIF_ScanStart,
    .scanStop      = R_DSMIF_ScanStop,
    .scanStatusGet = R_DSMIF_StatusGet,
    .read32        = R_DSMIF_Read,
    .close         = R_DSMIF_Close,
    .callbackSet   = R_DSMIF_CallbackSet
};

static IRQn_Type dsmif_irq_num[BSP_FEATURE_DSMIF_UNIT] =
{
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
#if 5U <= BSP_FEATURE_DSMIF_UNIT
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
#endif
#if 10U == BSP_FEATURE_DSMIF_UNIT
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
    (IRQn_Type) 0U,
#endif
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_DSMIF
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Applies power to the DSMIF and initializes the hardware based on the user configuration.
 * As part of this initialization, set interrupts, set DSMIF error interrupt registers, etc.
 *
 * @note The DSMIF error interrupt is PERI_ERR0, which is an interrupt handler common to other modules,
 *       so IRQ interrupts are not allowed here.
 *
 * @retval  FSP_SUCCESS                 Configuration successful.
 * @retval  FSP_ERR_ASSERTION           An input pointer is NULL or an input parameter is invalid.
 * @retval  FSP_ERR_ALREADY_OPEN        Control block is already open.
 * @retval  FSP_ERR_IRQ_BSP_DISABLED    A required interrupt is disabled
 * @retval  FSP_ERR_IP_UNIT_NOT_PRESENT The Unit requested in the p_cfg parameter is not available on this device.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_Open (adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)
    err = r_dsmif_open_param_check(p_instance_ctrl, p_cfg);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    /* Set all p_instance_ctrl fields prior to using it in any functions. */
    p_instance_ctrl->p_cfg = p_cfg;

    p_instance_ctrl->p_callback = p_cfg->p_callback;
    p_instance_ctrl->p_context  = p_cfg->p_context;
    p_instance_ctrl->mode       = p_cfg->mode;

    /* Configure and enable interrupts. */
    r_dsmif_open_irq_cfg(p_instance_ctrl, p_cfg);

    dsmif_extended_cfg_t const * p_cfg_extend = p_cfg->p_extend;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(p_cfg_extend->p_reg);
#endif

    /* mask_bit DSMIF 0 to 2 bits per unit */
    /* Calculate the register base address. */
    p_instance_ctrl->channel_mask = (uint32_t) (p_cfg_extend->channel_mask >> (p_cfg->unit * 3U));
    p_instance_ctrl->p_reg        = (R_DSMIF0_Type *) p_cfg_extend->p_reg;

    /* Figure "Start flow of DSMIF" */
    /* Release from the module-stop state */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_DSMIF, p_cfg->unit);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Set Overcurrent Sum Error Detection */
    /* DSSELTR : Overcurrent Sum Error Detect Low Threshold Register */
    p_instance_ctrl->p_reg->DSSELTR = (p_cfg_extend->scmptbl & R_DSMIF0_DSSELTR_SCMPTBL_Msk);

    /* DSSEHTR : Overcurrent Sum Error Detect High Threshold Register */
    p_instance_ctrl->p_reg->DSSEHTR = (p_cfg_extend->scmptbh & R_DSMIF0_DSSEHTR_SCMPTBH_Msk);

    /* DSSECSR : Overcurrent Sum Error Detect Channel Setting Register */
    p_instance_ctrl->p_reg->DSSECSR = (p_cfg_extend->sedm << R_DSMIF0_DSSECSR_SEDM_Pos);

    /* DSSEICR : Overcurrent Sum Error Detect Interrupt Control Register */
    p_instance_ctrl->p_reg->DSSEICR =
        (((uint32_t) p_cfg_extend->isel << R_DSMIF0_DSSEICR_ISEL_Pos) |
         ((uint32_t) p_cfg_extend->iseh << R_DSMIF0_DSSEICR_ISEH_Pos));

#if (1U == BSP_FEATURE_DSMIF_DATA_FORMAT_SEL)

    /* Set data format, Common Interrupt mode */
    p_instance_ctrl->p_reg->DSCMSR = (uint32_t) (p_cfg_extend->dfs << R_DSMIF0_DSCMSR_DFS_Pos);
#endif
#if 1U == BSP_FEATURE_DSMIF_CORE_CLOCK_SELECTABLE

    /* Core Clock Selection */
    p_instance_ctrl->p_reg->DSCCSCR = (uint32_t) (p_cfg_extend->clksel << R_DSMIF0_DSCCSCR_CLKSEL_Pos);
#endif

    /* Register settings for each channel */
    for (uint32_t ch = 0U; ch < DSMIF_MAX_NUM_CHANNELS; ch++)
    {
        p_instance_ctrl->results.results_32[ch] = 0U;

        if (p_cfg_extend->p_channel_cfgs[ch] != NULL)
        {
            /* DSICRCHn : Interrupt Control Register Channel */
#if (3U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_ISR)
            p_instance_ctrl->p_reg->CH[ch].DSICR =
                (uint32_t) ((((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->iue <<
                              R_DSMIF0_CH_DSICR_IUE_Pos) & R_DSMIF0_CH_DSICR_IUE_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ise <<
                              R_DSMIF0_CH_DSICR_ISE_Pos) & R_DSMIF0_CH_DSICR_ISE_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioel[0] << R_DSMIF0_CH_DSICR_IOEL0_Pos) &
                             R_DSMIF0_CH_DSICR_IOEL0_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioel[1] << R_DSMIF0_CH_DSICR_IOEL1_Pos) &
                             R_DSMIF0_CH_DSICR_IOEL1_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioel[2] << R_DSMIF0_CH_DSICR_IOEL2_Pos) &
                             R_DSMIF0_CH_DSICR_IOEL2_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioeh[0] <<
                              R_DSMIF0_CH_DSICR_IOEH0_Pos) & R_DSMIF0_CH_DSICR_IOEH0_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioeh[1] <<
                              R_DSMIF0_CH_DSICR_IOEH1_Pos) & R_DSMIF0_CH_DSICR_IOEH1_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioeh[2] <<
                              R_DSMIF0_CH_DSICR_IOEH2_Pos) & R_DSMIF0_CH_DSICR_IOEH2_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->owne[0] <<
                              R_DSMIF0_CH_DSICR_OWNE0_Pos) & R_DSMIF0_CH_DSICR_OWNE0_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->owne[1] <<
                              R_DSMIF0_CH_DSICR_OWNE1_Pos) & R_DSMIF0_CH_DSICR_OWNE1_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->owne[2] <<
                              R_DSMIF0_CH_DSICR_OWNE2_Pos) & R_DSMIF0_CH_DSICR_OWNE2_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->owne[3] <<
                              R_DSMIF0_CH_DSICR_OWNE3_Pos) & R_DSMIF0_CH_DSICR_OWNE3_Msk));
#else
            p_instance_ctrl->p_reg->CH[ch].DSICR =
                ((((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioel << R_DSMIF0_CH_DSICR_IOEL_Pos) &
                  R_DSMIF0_CH_DSICR_IOEL_Msk) |
                 (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ioeh <<
                    R_DSMIF0_CH_DSICR_IOEH_Pos) & R_DSMIF0_CH_DSICR_IOEH_Msk) |
                 (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ise <<
                    R_DSMIF0_CH_DSICR_ISE_Pos) & R_DSMIF0_CH_DSICR_ISE_Msk) |
                 (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->iue <<
                    R_DSMIF0_CH_DSICR_IUE_Pos) & R_DSMIF0_CH_DSICR_IUE_Msk));
#endif

            /* Set Channel's Error Detection Control */
#if (3U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_CONTROL)
            p_instance_ctrl->p_reg->CH[ch].TR[0].DSOCL =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbl[0] << R_DSMIF0_CH_TR_DSOCL_OCMPTBL0_Pos) &
                R_DSMIF0_CH_TR_DSOCL_OCMPTBL0_Msk;
            p_instance_ctrl->p_reg->CH[ch].TR[1].DSOCL =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbl[1] << R_DSMIF0_CH_TR_DSOCL_OCMPTBL0_Pos) &
                R_DSMIF0_CH_TR_DSOCL_OCMPTBL0_Msk;
            p_instance_ctrl->p_reg->CH[ch].TR[2].DSOCL =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbl[2] << R_DSMIF0_CH_TR_DSOCL_OCMPTBL0_Pos) &
                R_DSMIF0_CH_TR_DSOCL_OCMPTBL0_Msk;

            p_instance_ctrl->p_reg->CH[ch].TR[0].DSOCH =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbh[0] << R_DSMIF0_CH_TR_DSOCH_OCMPTBH0_Pos) &
                R_DSMIF0_CH_TR_DSOCH_OCMPTBH0_Msk;
            p_instance_ctrl->p_reg->CH[ch].TR[1].DSOCH =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbh[1] << R_DSMIF0_CH_TR_DSOCH_OCMPTBH0_Pos) &
                R_DSMIF0_CH_TR_DSOCH_OCMPTBH0_Msk;
            p_instance_ctrl->p_reg->CH[ch].TR[2].DSOCH =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbh[2] << R_DSMIF0_CH_TR_DSOCH_OCMPTBH0_Pos) &
                R_DSMIF0_CH_TR_DSOCH_OCMPTBH0_Msk;
#endif
#if (4U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)

            /* Set each channel's Overcurrent Detect Window Control setting */
            p_instance_ctrl->p_reg->CH[ch].DSODWCR =
                (uint32_t) (((uint32_t) (p_cfg_extend->p_channel_cfgs[ch]->ownm0_2[0] <<
                                         R_DSMIF0_CH_DSODWCR_OWNM0_Pos) &
                             R_DSMIF0_CH_DSODWCR_OWNM0_Msk) |
                            ((uint32_t) (p_cfg_extend->p_channel_cfgs[ch]->ownm0_2[1] <<
                                         R_DSMIF0_CH_DSODWCR_OWNM1_Pos) &
                             R_DSMIF0_CH_DSODWCR_OWNM1_Msk) |
                            ((uint32_t) (p_cfg_extend->p_channel_cfgs[ch]->ownm0_2[2] <<
                                         R_DSMIF0_CH_DSODWCR_OWNM2_Pos) &
                             R_DSMIF0_CH_DSODWCR_OWNM2_Msk) |
                            ((uint32_t) (p_cfg_extend->p_channel_cfgs[ch]->ownm3 << R_DSMIF0_CH_DSODWCR_OWNM3_Pos) &
                             R_DSMIF0_CH_DSODWCR_OWNM3_Msk));
#endif
#if (1U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_CONTROL)
            p_instance_ctrl->p_reg->CH[ch].DSOCLTR =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbl << R_DSMIF0_CH_DSOCLTR_OCMPTBL_Pos) &
                R_DSMIF0_CH_DSOCLTR_OCMPTBL_Msk;
            p_instance_ctrl->p_reg->CH[ch].DSOCHTR =
                (p_cfg_extend->p_channel_cfgs[ch]->ocmptbh << R_DSMIF0_CH_DSOCHTR_OCMPTBH_Pos) &
                R_DSMIF0_CH_DSOCHTR_OCMPTBH_Msk;
#endif

            p_instance_ctrl->p_reg->CH[ch].DSSCTSR =
                (uint32_t) (((p_cfg_extend->p_channel_cfgs[ch]->scntl << R_DSMIF0_CH_DSSCTSR_SCNTL_Pos) &
                             R_DSMIF0_CH_DSSCTSR_SCNTL_Msk) |
                            ((p_cfg_extend->p_channel_cfgs[ch]->scnth <<
                              R_DSMIF0_CH_DSSCTSR_SCNTH_Pos) & R_DSMIF0_CH_DSSCTSR_SCNTH_Msk));
            p_instance_ctrl->p_reg->CH[ch].DSEDCR =
                ((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->sde << R_DSMIF0_CH_DSEDCR_SDE_Pos) &
                R_DSMIF0_CH_DSEDCR_SDE_Msk;

            /* Set Channel's Current Measurement Control */
            uint32_t dscmctcrch;
            dscmctcrch =
                (((uint32_t) p_cfg_extend->cap_trig_a << R_DSMIF0_CH_DSCMCTCR_CTSELA_Pos) |
                 ((uint32_t) p_cfg_extend->cap_trig_b << R_DSMIF0_CH_DSCMCTCR_CTSELB_Pos) | \
                 ((uint32_t) p_cfg_extend->cnt_init_trig << R_DSMIF0_CH_DSCMCTCR_DITSEL_Pos) |
                 ((uint32_t) p_cfg_extend->edge << R_DSMIF0_CH_DSCMCTCR_DEDGE_Pos));
            p_instance_ctrl->p_reg->CH[ch].DSCMCTCR = dscmctcrch;

            /* Set Current Measurement Clock Control Register */
            /* For Slave, set DSCMCCRCHn.CKDIV to 0 (default) */
            uint32_t ckdiv;
            if (DSMIF_CLOCK_CTRL_SLAVE == p_cfg_extend->p_channel_cfgs[ch]->ckdir)
            {
                ckdiv = 0U;
            }
            else
            {
                ckdiv = p_cfg_extend->p_channel_cfgs[ch]->ckdiv;
            }

            p_instance_ctrl->p_reg->CH[ch].DSCMCCR =
                (uint32_t) ((((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ckdir << R_DSMIF0_CH_DSCMCCR_CKDIR_Pos) &
                             R_DSMIF0_CH_DSCMCCR_CKDIR_Msk) |
                            (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->sedge <<
                              R_DSMIF0_CH_DSCMCCR_SEDGE_Pos) & R_DSMIF0_CH_DSCMCCR_SEDGE_Msk) |
                            ((ckdiv << R_DSMIF0_CH_DSCMCCR_CKDIV_Pos) & R_DSMIF0_CH_DSCMCCR_CKDIV_Msk));

            /* Set Current Measurement Filter Control Register */
            p_instance_ctrl->p_reg->CH[ch].DSCMFCR =
                (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->cmsinc << R_DSMIF0_CH_DSCMFCR_CMSINC_Pos) |
                 (p_cfg_extend->p_channel_cfgs[ch]->cmdec <<
                    R_DSMIF0_CH_DSCMFCR_CMDEC_Pos) |
                 ((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->cmsh <<
                    R_DSMIF0_CH_DSCMFCR_CMSH_Pos));

            /* Set Overcurrent Detect Filter Control Register */
            p_instance_ctrl->p_reg->CH[ch].DSOCFCR =
                (((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ocsinc << R_DSMIF0_CH_DSOCFCR_OCSINC_Pos) |
                 (p_cfg_extend->p_channel_cfgs[ch]->ocdec <<
                    R_DSMIF0_CH_DSOCFCR_OCDEC_Pos) |
                 ((uint32_t) p_cfg_extend->p_channel_cfgs[ch]->ocsh <<
                    R_DSMIF0_CH_DSOCFCR_OCSH_Pos));
        }
    }

    /* Mark driver as open by initializing it to "DSMI" - its ASCII equivalent. */
    p_instance_ctrl->opened = DSMIF_OPEN;

    return err;
}

/*******************************************************************************************************************//**
 * Starts either synchronous control mode or individual control mode .
 *
 * @note After executing R_DSMIF_ScanStart, it is necessary to wait until the filter result is output stably.
 *       (Reference section "Settling Time of Channel Activation")
 *
 * @retval  FSP_SUCCESS                Scan started or hardware triggers enabled successfully.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_ScanStart (adc_ctrl_t * p_ctrl)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;
    fsp_err_t               err             = FSP_SUCCESS;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    r_dsmif_start(p_instance_ctrl);

    /* Return the error code */
    return err;
}

/*******************************************************************************************************************//**
 * Stops any in-progress scan started by software.
 *
 * @retval  FSP_SUCCESS                Scan stopped or hardware triggers disabled successfully.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 * @retval  FSP_ERR_TIMEOUT            Timeout error.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_ScanStop (adc_ctrl_t * p_ctrl)
{
    fsp_err_t               err;
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    err = r_dsmif_stop(p_instance_ctrl);

    /* Return the error code */
    return err;
}

/*******************************************************************************************************************//**
 * Configuration settings.(Overcurrent detection and Sum error detection).
 *
 * @retval  FSP_SUCCESS                Configuration setting successfully.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_CfgSet (adc_ctrl_t * p_ctrl, adc_cfg_t const * const p_cfg)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    dsmif_extended_cfg_t const * p_cfg_extend = (dsmif_extended_cfg_t *) p_cfg->p_extend;

    /* Set overcurrent detection */
    for (uint32_t ch = 0U; ch < DSMIF_MAX_NUM_CHANNELS; ch++)
    {
        /* Set overcurrent detection valid */
#if (3U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_CONTROL)
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEL0 = p_cfg_extend->p_channel_cfgs[ch]->odel[0];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEL1 = p_cfg_extend->p_channel_cfgs[ch]->odel[1];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEL2 = p_cfg_extend->p_channel_cfgs[ch]->odel[2];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEH0 = p_cfg_extend->p_channel_cfgs[ch]->odeh[0];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEH1 = p_cfg_extend->p_channel_cfgs[ch]->odeh[1];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEH2 = p_cfg_extend->p_channel_cfgs[ch]->odeh[2];
#endif
#if (4U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.OWFE0 = p_cfg_extend->p_channel_cfgs[ch]->owfe[0];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.OWFE1 = p_cfg_extend->p_channel_cfgs[ch]->owfe[1];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.OWFE2 = p_cfg_extend->p_channel_cfgs[ch]->owfe[2];
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.OWFE3 = p_cfg_extend->p_channel_cfgs[ch]->owfe[3];
#endif
#if (1U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_CONTROL)
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEL = p_cfg_extend->p_channel_cfgs[ch]->odel;
        p_instance_ctrl->p_reg->CH[ch].DSODCR_b.ODEH = p_cfg_extend->p_channel_cfgs[ch]->odeh;
#endif
    }

    /* Set sum error detection */
    /* DSSECR : Overcurrent Sum Error Detect Control Register */
    p_instance_ctrl->p_reg->DSSECR = (uint32_t) ((p_cfg_extend->seel << R_DSMIF0_DSSECR_SEEL_Pos) |
                                                 (p_cfg_extend->seeh << R_DSMIF0_DSSECR_SEEH_Pos));

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Returns the status of a scan started by software.
 *
 * @retval  FSP_SUCCESS                No software scan is in progress.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_StatusGet (adc_ctrl_t * p_ctrl, adc_status_t * p_status)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_status);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Channel synchronization control mode */

    if (0U == (p_instance_ctrl->p_reg->DSCSSR & (R_DSMIF0_DSCSSR_CHSTATE0_Msk | \
                                                 R_DSMIF0_DSCSSR_CHSTATE1_Msk | R_DSMIF0_DSCSSR_CHSTATE2_Msk)))
    {
        p_status->state = ADC_STATE_IDLE;
    }
    else
    {
        p_status->state = ADC_STATE_SCAN_IN_PROGRESS;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Returns the error status of a scan started by software.
 *
 * @retval  FSP_SUCCESS                No software scan is in progress.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_ErrorStatusGet (adc_ctrl_t * p_ctrl, dsmif_error_status_t * p_error_status)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_error_status);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

#if (4U == BSP_FEATURE_DSMIF_OVERCURRENT_DETECT_NOTIFY)
    p_error_status->channel_overcurrent_window_status =
        (dsmif_channel_overcurrent_window_status_t) (p_instance_ctrl->p_reg->DSCOCNSR &
                                                     DSMIF_OVERCURRENT_NOTIFY_STATUS_FLAGS);
    p_error_status->channel_overcurrent_status =
        (dsmif_channel_overcurrent_status_t) (p_instance_ctrl->p_reg->DSCOCESR &
                                              DSMIF_CHANNEL_OVERCURRENT_STATUS_FLAGS);
    p_error_status->channel_short_circuit_status =
        (dsmif_channel_short_circuit_status_t) (p_instance_ctrl->p_reg->DSCESR &
                                                DSMIF_CHANNEL_SHORT_CIRCUIT_STATUS_FLAGS);
    p_error_status->overcurrent_sum_status =
        (dsmif_overcurrent_sum_status_t) ((p_instance_ctrl->p_reg->DSCESR &
                                           DSMIF_OVERCURRENT_SUM_STATUS_FLAGS) >> 16U);
#else
    p_error_status->channel_overcurrent_status =
        (dsmif_channel_overcurrent_status_t) (p_instance_ctrl->p_reg->DSCESR &
                                              DSMIF_CHANNEL_OVERCURRENT_STATUS_FLAGS);
    p_error_status->channel_short_circuit_status =
        (dsmif_channel_short_circuit_status_t) ((p_instance_ctrl->p_reg->DSCESR &
                                                 DSMIF_CHANNEL_SHORT_CIRCUIT_STATUS_FLAGS) >> 8U);
    p_error_status->overcurrent_sum_status =
        (dsmif_overcurrent_sum_status_t) ((p_instance_ctrl->p_reg->DSCESR &
                                           DSMIF_OVERCURRENT_SUM_STATUS_FLAGS) >> 16U);
#endif

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the most recent result from a channel.
 *
 * @retval  FSP_SUCCESS                Result in p_data.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL or an input parameter was invalid.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_Read (adc_ctrl_t * p_ctrl, adc_channel_t const reg_id, uint32_t * const p_data)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_data);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(0U != ((1U << ((uint32_t) reg_id & DSMIF_REGID_MASK)) & p_instance_ctrl->channel_mask));
#endif

    adc_channel_t        channel         = (adc_channel_t) (reg_id & DSMIF_DATA_CHANNEL_MASK);
    dsmif_current_data_t dsmif_data_type =
        (dsmif_current_data_t) ((reg_id & DSMIF_DATA_TYPE_MASK) >> DSMIF_DATA_TYPE_SHIFT);
    if (DSMIF_CURRENT_DATA == dsmif_data_type)
    {
        p_instance_ctrl->results.results_32[channel] = p_instance_ctrl->p_reg->CH[channel].DSCDR;
    }
    else if (DSMIF_CURRENT_DATA_CAPTURE_A == dsmif_data_type)
    {
        p_instance_ctrl->results.results_32[channel] = p_instance_ctrl->p_reg->CH[channel].DSCCDRA;
    }
    else
    {
        p_instance_ctrl->results.results_32[channel] = p_instance_ctrl->p_reg->CH[channel].DSCCDRB;
    }

    *p_data = p_instance_ctrl->results.results_32[channel];

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Stops any scan in progress, disables interrupts, and powers down the DSMIF peripheral.
 *
 * @note This function is delayed at least until the outage is complete, as required by the DSMIF outage procedure.
 *
 * @retval  FSP_SUCCESS                Instance control block closed successfully.
 * @retval  FSP_ERR_ASSERTION          An input pointer was NULL.
 * @retval  FSP_ERR_NOT_OPEN           Instance control block is not open.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_Close (adc_ctrl_t * p_ctrl)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

    /* Perform parameter checking*/
#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

    /* Verify the pointers are not NULL and ensure the DSMIF unit is already open. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Mark driver as closed   */
    p_instance_ctrl->opened = 0U;

    /* Disable interrupts. */
    r_dsmif_disable_irq(p_instance_ctrl->p_cfg->scan_end_irq);

    for (uint32_t ch = 0U; ch < DSMIF_MAX_NUM_CHANNELS; ch++)
    {
        p_instance_ctrl->results.results_32[ch] = 0U;
        p_instance_ctrl->p_reg->CH[ch].DSICR    = 0x00000000U;
    }

    /* Stop processing(No error is returned because it is forcibly terminated.) */
    (void) r_dsmif_stop(p_instance_ctrl);

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_STOP(FSP_IP_DSMIF, p_instance_ctrl->p_cfg->unit);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    /* Return the error code */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Updates the user callback with the option to provide memory for the callback argument structure.
 *
 * @retval  FSP_SUCCESS                  Callback updated successfully.
 * @retval  FSP_ERR_ASSERTION            A required pointer is NULL.
 * @retval  FSP_ERR_NOT_OPEN             The control block has not been opened.
 **********************************************************************************************************************/
fsp_err_t R_DSMIF_CallbackSet (adc_ctrl_t * const          p_ctrl,
                               void (                    * p_callback)(adc_callback_args_t *),
                               void * const                p_context,
                               adc_callback_args_t * const p_callback_memory)
{
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) p_ctrl;

#if DSMIF_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_callback);
    FSP_ERROR_RETURN(DSMIF_OPEN == p_instance_ctrl->opened, FSP_ERR_NOT_OPEN);
#endif

    /* Store callback and context */
    p_instance_ctrl->p_callback        = p_callback;
    p_instance_ctrl->p_context         = p_context;
    p_instance_ctrl->p_callback_memory = p_callback_memory;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup DSMIF)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
#if (1 == DSMIF_CFG_PARAM_CHECKING_ENABLE)

/*******************************************************************************************************************//**
 * Validates the input parameters to open().
 *
 * @param[in]  p_instance_ctrl  Pointer to instance control block
 * @param[in]  p_cfg   Pointer to configuration structure
 *
 * @retval  FSP_SUCCESS                 No invalid configurations identified.
 * @retval  FSP_ERR_ALREADY_OPEN        Control block is already open.
 * @retval  FSP_ERR_ASSERTION           An input pointer is NULL or an input parameter is invalid.
 * @retval  FSP_ERR_IRQ_BSP_DISABLED    A callback is provided, but the interrupt is not enabled.
 * @retval  FSP_ERR_IP_UNIT_NOT_PRESENT The Unit requested in the p_cfg parameter is not available on this device.
 **********************************************************************************************************************/
static fsp_err_t r_dsmif_open_param_check (dsmif_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg)
{
    /* Verify the pointers are not NULL. */
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_extend);

    /* Verify the control block has not already been initialized. */
    FSP_ERROR_RETURN(DSMIF_OPEN != p_instance_ctrl->opened, FSP_ERR_ALREADY_OPEN);

    /* Verify the unit exists on the MPU. */
    FSP_ERROR_RETURN(((1U << p_cfg->unit) & BSP_FEATURE_DSMIF_VALID_UNIT_MASK), FSP_ERR_IP_UNIT_NOT_PRESENT);

    /* If a callback is used, then make sure the scan end interrupt is enabled */
    if (NULL != p_cfg->p_callback)
    {
        FSP_ERROR_RETURN(p_cfg->scan_end_irq >= 0, FSP_ERR_IRQ_BSP_DISABLED);
    }

    return FSP_SUCCESS;
}

#endif

/*******************************************************************************************************************//**
 * Start processing of channel synchronization control mode and individual control mode
 *
 * @param[in]  p_instance_ctrl     Pointer to instance control block
 *
 **********************************************************************************************************************/
static void r_dsmif_start (dsmif_instance_ctrl_t * const p_instance_ctrl)
{
    /* DSCSTRTR : Channel Software Start Trigger Register (Channel synchronization control mode)*/
    /* Write 1 to Channel's start trigger */
    p_instance_ctrl->p_reg->DSCSTRTR = p_instance_ctrl->channel_mask;
}

/*******************************************************************************************************************//**
 * Stop processing of channel synchronization control mode and individual control mode
 *
 * @param[in]  p_instance_ctrl     Pointer to instance control block
 *
 * @retval  FSP_SUCCESS            Stop processing succeeded.
 * @retval  FSP_ERR_TIMEOUT        Timeout error.
 **********************************************************************************************************************/
static fsp_err_t r_dsmif_stop (dsmif_instance_ctrl_t * const p_instance_ctrl)
{
    fsp_err_t err     = FSP_SUCCESS;
    uint32_t  timeout = DSMIF_STOP_TIMEOUT;

    /* DSCSTPTR : Channel Software Stop Trigger Register (Channel synchronization control mode) */
    /* Write 1 to Channel's stop trigger */
    p_instance_ctrl->p_reg->DSCSTPTR = p_instance_ctrl->channel_mask;

    /* Check that all channels are down */
    while (0 != (p_instance_ctrl->p_reg->DSCSSR & (R_DSMIF0_DSCSSR_CHSTATE0_Msk | \
                                                   R_DSMIF0_DSCSSR_CHSTATE1_Msk | R_DSMIF0_DSCSSR_CHSTATE2_Msk)))
    {
        /* Exit processing when time out. */
        if (0U == timeout)
        {
            err = FSP_ERR_TIMEOUT;
            break;
        }

        timeout--;
    }

    /* Disable overcurrent detection of all target channels */
    for (uint32_t ch = 0U; ch < DSMIF_MAX_NUM_CHANNELS; ch++)
    {
        p_instance_ctrl->p_reg->CH[ch].DSODCR = 0x00000000U;
    }

    /* Disable sum error detection  */
    /* DSSECR : Overcurrent Sum Error Detect Control Register */
    p_instance_ctrl->p_reg->DSSECR = 0x00000000U;

    return err;
}

/*******************************************************************************************************************//**
 * Configures interrupts and ensures required interrupts are enabled.
 *
 * @param[in]  p_instance_ctrl     Pointer to instance control block
 * @param[in]  p_cfg      Pointer to configuration structure
 *
 **********************************************************************************************************************/
static void r_dsmif_open_irq_cfg (dsmif_instance_ctrl_t * const p_instance_ctrl, adc_cfg_t const * const p_cfg)
{
    /* Set the interrupt priorities. */
    if (p_cfg->scan_end_irq >= 0)
    {
        R_BSP_IrqCfgEnable(p_cfg->scan_end_irq, p_cfg->scan_end_ipl, p_instance_ctrl);
        dsmif_irq_num[p_cfg->unit] = p_cfg->scan_end_irq;
    }
}

/*******************************************************************************************************************//**
 * Disables an interrupt.
 *
 * @param[in]  irq     Interrupt to disable
 **********************************************************************************************************************/
static void r_dsmif_disable_irq (IRQn_Type irq)
{
    if (irq >= 0)
    {
        R_BSP_IrqDisable(irq);
        R_FSP_IsrContextSet(irq, NULL);
    }
}

/*******************************************************************************************************************//**
 * DSMIFx current data register update interrupt.
 **********************************************************************************************************************/
void dsmif_cdrui_isr (void)
{
    DSMIF_CFG_MULTIPLEX_INTERRUPT_ENABLE;

    /* Save context if RTOS is used */
    FSP_CONTEXT_SAVE;

    IRQn_Type               irq             = R_FSP_CurrentIrqGet();
    dsmif_instance_ctrl_t * p_instance_ctrl = (dsmif_instance_ctrl_t *) R_FSP_IsrContextGet(irq);
    adc_callback_args_t     args;

    /* Store callback arguments in memory provided by user if available.  This allows callback arguments to be
     * stored in non-secure memory so they can be accessed by a non-secure callback function. */
    adc_callback_args_t * p_args = p_instance_ctrl->p_callback_memory;
    if (NULL == p_args)
    {
        /* Store on stack */
        p_args = &args;
    }
    else
    {
        /* Save current arguments on the stack in case this is a nested interrupt. */
        args = *p_args;
    }

    /* If a callback was provided, call it with the argument */
    if (NULL != p_instance_ctrl->p_callback)
    {
        /* Store the event into the callback argument */
        /* Check interrupts that have occurred */
        uint8_t dsmif_unit_no;
        for (dsmif_unit_no = 0U; dsmif_unit_no < BSP_FEATURE_DSMIF_UNIT; dsmif_unit_no++)
        {
            if (dsmif_irq_num[dsmif_unit_no] == irq)
            {
                break;
            }
        }

        p_args->unit      = dsmif_unit_no;
        p_args->event     = ADC_EVENT_SCAN_COMPLETE;
        p_args->p_context = p_instance_ctrl->p_context;
        p_instance_ctrl->p_callback(p_args);
    }

    if (NULL != p_instance_ctrl->p_callback_memory)
    {
        /* Restore callback memory in case this is a nested interrupt. */
        *p_instance_ctrl->p_callback_memory = args;
    }

    /* Restore context if RTOS is used */
    FSP_CONTEXT_RESTORE;

    DSMIF_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}
