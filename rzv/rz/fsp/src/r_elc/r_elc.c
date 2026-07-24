/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_elc.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "ELC" in ASCII, used to determine if the module is open */
#define ELC_OPEN                        (0x00454C43U)
#define ELC_CLOSED                      (0x00000000U)

#define ELC_SSEL_ALL_DISABLE            (0x3FFFFFFFU)
#define ELC_ELC_SSEL_SEL_SETTING_NUM    (3)
#define ELC_DISABLE_ELC_FUNCTION        (0x3FF)
#define ELC_CHAR_BIT                    (8)
#define ELC_32BIT_SIZE                  (sizeof(uint32_t) * ELC_CHAR_BIT)

static const uint32_t gs_elc_ssel_pos_table[ELC_ELC_SSEL_SEL_SETTING_NUM] =
{
    BSP_ELC_EVENT_SELECT0_POSITION,
    BSP_ELC_EVENT_SELECT1_POSITION,
    BSP_ELC_EVENT_SELECT2_POSITION
};

static const uint32_t gs_elc_ssel_msk_table[ELC_ELC_SSEL_SEL_SETTING_NUM] =
{
    BSP_ELC_EVENT_SELECT0_MASK,
    BSP_ELC_EVENT_SELECT1_MASK,
    BSP_ELC_EVENT_SELECT2_MASK
};

static const uint32_t gs_elc_event_source_msk_table[BSP_ELC_EVENT_MASK_NUM] =
{
    BSP_ELC_PERIPHERAL_0_MASK,
    BSP_ELC_PERIPHERAL_1_MASK,
    BSP_ELC_PERIPHERAL_2_MASK,
    BSP_ELC_PERIPHERAL_3_MASK
};

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

#if ELC_CFG_PARAM_CHECKING_ENABLE
static fsp_err_t r_elc_common_parameter_checking(elc_instance_ctrl_t * p_instance_ctrl);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/** ELC API structure.  */
const elc_api_t g_elc_on_elc =
{
    .open                  = R_ELC_Open,
    .close                 = R_ELC_Close,
    .softwareEventGenerate = R_ELC_SoftwareEventGenerate,
    .linkSet               = R_ELC_LinkSet,
    .linkBreak             = R_ELC_LinkBreak,
    .enable                = R_ELC_Enable,
    .disable               = R_ELC_Disable,
};

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZV
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZV_ELC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initialize all the links in the Event Link Controller. Implements @ref elc_api_t::open
 *
 * The configuration structure passed in to this function includes links for every event source included in the ELC
 * and sets them all at once. To set or clear an individual link use R_ELC_LinkSet and R_ELC_LinkBreak respectively.
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       p_ctrl or p_cfg was NULL
 * @retval FSP_ERR_ALREADY_OPEN    The module is currently open
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Open (elc_ctrl_t * const p_ctrl, elc_cfg_t const * const p_cfg)
{
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(NULL != p_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ERROR_RETURN(ELC_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    volatile uint32_t * p_reg   = BSP_ELC_EVENT_SELECT_REG;
    uint32_t            i_shift = 1;

    /* All links and set or clear them in the ELC block.
     * Use 'ELC_DISABLE_ELC_FUNCTION' because "ELC_EVENT_NONE" cannot disable the ELC function.
     * see Event Selection register description chapter of the RZ microprocessor manual for more details.
     *
     * Loop through all Event Selection register. */
    for (uint32_t ssel_register_num = 0; ssel_register_num < BSP_ELC_ELC_SSEL_NUM; ssel_register_num++)
    {
        uint32_t elc_ssel = ELC_SSEL_ALL_DISABLE;

        /* Loop through all bits of Event Selection register.
         * (n indicates the register number and m indicates the bit number).
         */
        for (uint32_t sel_bit_num = 0; sel_bit_num < ELC_ELC_SSEL_SEL_SETTING_NUM; sel_bit_num++)
        {
            /* A bit of Event Selection register and p_cfg->link have the following relation
             *
             * First bit of Event Selection register0 <-> p_cfg->link[0]
             * Second bit of Event Selection register0 <-> p_cfg->link[1]
             * Third bit of Event Selection register0 <-> p_cfg->link[2]
             * First bit of Event Selection register1 <-> p_cfg->link[3]
             * Second bit of Event Selection register1 <-> p_cfg->link[4]
             * ...
             * Mth bit of Event Selection registern <-> p_cfg->link[n * 3 + m]
             *
             * so, use formula
             * link_num = (ssel_register_num * ELC_ELC_SSEL_SEL_SETTING_NUM) + sel_bit_num
             */
            uint32_t link_num = (ssel_register_num * ELC_ELC_SSEL_SEL_SETTING_NUM) + sel_bit_num;

            /* Make sure the bit trying to set is not Reserved. */
            if (gs_elc_event_source_msk_table[link_num / ELC_32BIT_SIZE] & i_shift)
            {
                elc_ssel &= ~gs_elc_ssel_msk_table[sel_bit_num];
                elc_ssel |=
                    (uint32_t) ((p_cfg->link[link_num] == ELC_EVENT_NONE) ?
                                ELC_DISABLE_ELC_FUNCTION :
                                p_cfg->link[link_num]) << gs_elc_ssel_pos_table[sel_bit_num];
            }

            i_shift = (i_shift << 1) | (i_shift >> (ELC_32BIT_SIZE - 1));
        }

        p_reg[ssel_register_num] = elc_ssel;
    }

    /* Set driver status to open */
    p_instance_ctrl->open = ELC_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Globally disable ELC linking. Implements @ref elc_api_t::close
 *
 * @retval FSP_SUCCESS             The ELC was successfully disabled
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Close (elc_ctrl_t * const p_ctrl)
{
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;

#if ELC_CFG_PARAM_CHECKING_ENABLE
    fsp_err_t err = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    volatile uint32_t * p_reg = BSP_ELC_EVENT_SELECT_REG;

    /* Globally disable the operation of the Event Link Controller */
    for (int i = 0; i < BSP_ELC_ELC_SSEL_NUM; i++)
    {
        p_reg[i] = ELC_SSEL_ALL_DISABLE;
    }

    /* Set state to closed */
    p_instance_ctrl->open = ELC_CLOSED;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Generate a software event in the Event Link Controller. Implements @ref elc_api_t::softwareEventGenerate
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       Invalid event number or p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_SoftwareEventGenerate (elc_ctrl_t * const p_ctrl, elc_software_event_t event_number)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#endif

    volatile uint32_t * p_reg = BSP_ELC_SOFTWARE_EVENT_REG;

    FSP_PARAMETER_NOT_USED(p_ctrl);

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    /* Software event output is generated in the ICU by writing 1 and then 0 successively to a bit. */
    *p_reg = (uint32_t) (BSP_ELC_SOFTWARE_EVENT_MASK << event_number);
    *p_reg = 0;

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Create a single event link. Implements @ref elc_api_t::linkSet
 *
 * @retval FSP_SUCCESS             Initialization was successful
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_LinkSet (elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral, elc_event_t signal)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    volatile uint32_t * p_reg = BSP_ELC_EVENT_SELECT_REG;

    /* Set the event link register for the corresponding peripheral to the given signal */
    uint32_t register_num         = (uint32_t) peripheral / ELC_ELC_SSEL_SEL_SETTING_NUM;
    uint32_t ssel_sel_setting_num = (uint32_t) peripheral % ELC_ELC_SSEL_SEL_SETTING_NUM;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    p_reg[register_num] &= ~(gs_elc_ssel_msk_table[ssel_sel_setting_num]);
    p_reg[register_num] |= (uint32_t) signal << gs_elc_ssel_pos_table[ssel_sel_setting_num];

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Break an event link. Implements @ref elc_api_t::linkBreak
 *
 * @retval FSP_SUCCESS             Event link broken
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_LinkBreak (elc_ctrl_t * const p_ctrl, elc_peripheral_t peripheral)
{
#if ELC_CFG_PARAM_CHECKING_ENABLE
    elc_instance_ctrl_t * p_instance_ctrl = (elc_instance_ctrl_t *) p_ctrl;
    fsp_err_t             err             = r_elc_common_parameter_checking(p_instance_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    volatile uint32_t * p_reg = BSP_ELC_EVENT_SELECT_REG;

    /* Clear the corresponding peripheral event link register to break the link */
    uint32_t register_num         = (uint32_t) peripheral / ELC_ELC_SSEL_SEL_SETTING_NUM;
    uint32_t ssel_sel_setting_num = (uint32_t) peripheral % ELC_ELC_SSEL_SEL_SETTING_NUM;

    FSP_CRITICAL_SECTION_DEFINE;
    FSP_CRITICAL_SECTION_ENTER;

    p_reg[register_num] &= ~(gs_elc_ssel_msk_table[ssel_sel_setting_num]);
    p_reg[register_num] |= (uint32_t) ELC_DISABLE_ELC_FUNCTION <<
                           gs_elc_ssel_pos_table[ssel_sel_setting_num];

    FSP_CRITICAL_SECTION_EXIT;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Enable the operation of the Event Link Controller. Implements @ref elc_api_t::enable
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported.
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Enable (elc_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Disable the operation of the Event Link Controller. Implements @ref elc_api_t::disable
 *
 * @retval FSP_ERR_UNSUPPORTED         API not supported.
 *
 **********************************************************************************************************************/
fsp_err_t R_ELC_Disable (elc_ctrl_t * const p_ctrl)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);

    return FSP_ERR_UNSUPPORTED;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @} (end addtogroup ELC)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

#if ELC_CFG_PARAM_CHECKING_ENABLE

/*******************************************************************************************************************//**
 * Verifies the control structure is not NULL and the module is open. This reduces code size when the error logger is
 * used.
 *
 * @param[in]  p_instance_ctrl          Pointer to instance control structure.
 *
 * @retval FSP_SUCCESS                  No error detected.
 * @retval FSP_ERR_ASSERTION            Invalid input argument.
 * @retval FSP_ERR_NOT_OPEN             Module is not open.
 **********************************************************************************************************************/
static fsp_err_t r_elc_common_parameter_checking (elc_instance_ctrl_t * p_instance_ctrl)
{
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(ELC_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);

    return FSP_SUCCESS;
}

#endif
