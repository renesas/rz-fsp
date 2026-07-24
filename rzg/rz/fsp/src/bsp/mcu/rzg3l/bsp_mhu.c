/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_mhu.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define MHU_PRV_MAX_CM33_IRQ                      3
#define MHU_PRV_MAX_CHANNELS                      19
#define MHU_NS_PRV_INTC_IM33_MISR4_BIT0_Msk       0x01
#define MHU_NS_PRV_INTC_IM33_MISR4_BIT1_Msk       0x02
#define MHU_NS_PRV_INTC_IM33_MISR4_BIT2_Msk       0x04
#define MHU_NS_PRV_INTC_IM33_MISR4_BIT3_Msk       0x08
#define MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT0_Msk    0x01
#define MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT1_Msk    0x02
#define MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT2_Msk    0x04
#define MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT3_Msk    0x08

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZG
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZG_BSP_MPU_RZG3L
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
void * gp_mhu_context[MHU_PRV_MAX_CM33_IRQ][MHU_PRV_MAX_CHANNELS];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Sets the MHU context associated with the requested IRQ and channel.
 *
 * @param[in]  irq            IRQ number
 * @param[in]  ch             channel number
 * @param[in]  p_context      MHU context for IRQ and channel.
 **********************************************************************************************************************/
void R_BSP_MHU_ContextSet (IRQn_Type const irq, uint32_t ch, void * p_context)
{
    /* This provides access to the MHU context array defined in bsp_mhu.c. */
    uint8_t mhu_irq_num = 0;
    switch (irq)
    {
        case MHU_MSG_NS_IRQn:
        case MHU_RSP_NS_IRQn:
        {
            mhu_irq_num = 0;
            break;
        }

        case MHU_MSG_S_IRQn:
        case MHU_RSP_S_IRQn:
        {
            mhu_irq_num = 1;
            break;
        }

        case MHU_SW_INT_IRQn:
        {
            mhu_irq_num = 2;
            break;
        }

        default:
        {
            break;
        }
    }

    gp_mhu_context[mhu_irq_num][ch] = p_context;
}

/*******************************************************************************************************************//**
 * @brief      Finds the MHU context associated with the requested IRQ and channel.
 *
 * @param[in]  irq            IRQ number
 * @param[in]  ch             channel number
 * @return  MHU context for IRQ and channel.
 **********************************************************************************************************************/
void * R_BSP_MHU_ContextGet (IRQn_Type const irq, uint32_t ch)
{
    /* This provides access to the MHU context array defined in bsp_mhu.c. */
    uint8_t mhu_irq_num = 0;
    switch (irq)
    {
        case MHU_MSG_NS_IRQn:
        case MHU_RSP_NS_IRQn:
        {
            mhu_irq_num = 0;
            break;
        }

        case MHU_MSG_S_IRQn:
        case MHU_RSP_S_IRQn:
        {
            mhu_irq_num = 1;
            break;
        }

        case MHU_SW_INT_IRQn:
        {
            mhu_irq_num = 2;
            break;
        }

        default:
        {
            break;
        }
    }

    return gp_mhu_context[mhu_irq_num][ch];
}

/*******************************************************************************************************************//**
 * @brief      Finds the MHU channel associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ number
 * @return  MHU channel.
 **********************************************************************************************************************/
uint32_t R_BSP_MHU_CurrentChannelGet (IRQn_Type const irq)
{
    uint32_t ch       = 0;
    uint32_t irq_flag = R_BSP_IntStatusControlGet(FSP_IP_MHU, (uint8_t) ch, irq);
    switch (irq)
    {
        case MHU_MSG_NS_IRQn:
        case MHU_MSG_S_IRQn:
        {
            if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT0_Msk)
            {
                ch = 3;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT1_Msk)
            {
                ch = 7;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT2_Msk)
            {
                ch = 11;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT3_Msk)
            {
                ch = 15;

                return ch;
            }
            else
            {
                return ch;
            }

            break;
        }

        case MHU_RSP_NS_IRQn:
        case MHU_RSP_S_IRQn:
        {
            if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT0_Msk)
            {
                ch = 16;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT1_Msk)
            {
                ch = 17;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT2_Msk)
            {
                ch = 18;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_MISR4_BIT3_Msk)
            {
                ch = 19;

                return ch;
            }
            else
            {
                return ch;
            }

            break;
        }

        case MHU_SW_INT_IRQn:
        {
            if (irq_flag & MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT0_Msk)
            {
                ch = 0;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT1_Msk)
            {
                ch = 1;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT2_Msk)
            {
                ch = 2;

                return ch;
            }
            else if (irq_flag & MHU_NS_PRV_INTC_IM33_SWISR_SWSTAT3_Msk)
            {
                ch = 3;

                return ch;
            }
            else
            {
                ch = 4;

                return ch;
            }

            break;
        }

        default:
        {
            return ch;
            break;
        }
    }
}

/** @} (end addtogroup RZG_BSP_MPU_RZG3L) */

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif
