/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Private definition to set enumeration values. */
#define BSP_PRV_SYTSEMFEN_MASK        (0x00000001U)
#define BSP_PRV_SYTSEMFEN_ENABLE      (0x00000001U)
#define BSP_PRV_SYTSEMFEN_DISABLE     (0x00000000U)

#define BSP_PRV_SEMRCEN_MASK          (0x00000001U)
#define BSP_PRV_SEMRCEN_ENABLE        (0x00000001U)
#define BSP_PRV_SEMRCEN_DISABLE       (0x00000000U)

#define BSP_PRV_SEMRCENAR_MASK        (0x00000001U)
#define BSP_PRV_SEMRCENAR_ENABLE      (0x00000001U)
#define BSP_PRV_SEMRCENAR_DISABLE     (0x00000000U)

#define BSP_PRV_RESOURCE_NOT_USED     (0x00000001U)
#define BSP_SEMAPHORE_RESOURCE_MAX    (8U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Semaphore initialization.
 **********************************************************************************************************************/
void bsp_semaphore_init (void)
{
#if BSP_FEATURE_BSP_SEMAPHORE_SUPPORTED
 #if BSP_FEATURE_SEM_SUPPORTED

    /* If the semaphore read clear enable register is already set, the initialization will be skipped. */
    if (BSP_PRV_SYTSEMFEN_DISABLE == (R_SEM->SYTSEMFEN & BSP_PRV_SYTSEMFEN_MASK))
    {
        /* Enable read clear function. */
        R_SEM->SYTSEMFEN = BSP_PRV_SYTSEMFEN_ENABLE;

        for (uint32_t sem_num = 0; sem_num < BSP_SEMAPHORE_RESOURCE_MAX; sem_num++)
        {
            /* Set the semaphore state not being used. */
            __DMB();
            R_SEM->SYTSEMF[sem_num] = BSP_PRV_RESOURCE_NOT_USED;
        }
    }
 #endif

 #if BSP_FEATURE_MAILBOX_SEM_SUPPORTED
    for (uint32_t sem_num = 0; sem_num < BSP_SEMAPHORE_RESOURCE_MAX; sem_num++)
    {
        /* If the semaphore read clear enable register is already set, the initialization will be skipped. */

        if (BSP_PRV_SEMRCEN_DISABLE == ((R_MBXSEM->SEMRCEN >> sem_num) & BSP_PRV_SEMRCEN_MASK))
        {
            /* Enable read clear function for External Host and Internal CPUs. */
            R_MBXSEM->SEMRCEN |= (BSP_PRV_SEMRCEN_ENABLE << sem_num);

            /* Set the semaphore state not being used for External Host and Internal CPUs. */
            __DMB();
            R_MBXSEM->SEM[sem_num] = BSP_PRV_RESOURCE_NOT_USED;
        }

  #if BSP_FEATURE_MAILBOX_SEM_INTERNAL_CPU_SEM_SUPPORTED
        if (BSP_PRV_SEMRCENAR_DISABLE == ((R_MBXSEM->SEMRCENAR >> sem_num) & BSP_PRV_SEMRCENAR_MASK))
        {
            /* Enable read clear function for Internal CPUs. */
            R_MBXSEM->SEMRCENAR |= (BSP_PRV_SEMRCENAR_ENABLE << sem_num);

            /* Set the semaphore state not being used for Internal CPUs. */
            __DMB();
            R_MBXSEM->SEMAR[sem_num] = BSP_PRV_RESOURCE_NOT_USED;
        }
  #endif
    }
 #endif
#endif
}
