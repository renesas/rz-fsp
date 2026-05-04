/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RM_FREERTOS_PLUS_TCP_H
#define RM_FREERTOS_PLUS_TCP_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Standard libraries includes. */
#include <stdlib.h>

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

#include "NetworkInterface.h"
#include "NetworkBufferManagement.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/
#define RM_FREERTOS_PLUS_TCP_SIZE_OF_IPV4              (4)
#define RM_FREERTOS_PLUS_TCP_SIZE_OF_INTERFACE_NAME    (17)

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZA
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_RM_FREERTOS_PLUS_TCP
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
struct st_network_interface_instance
{
    TaskHandle_t             xRxHanderTaskHandle;
    TaskHandle_t             xCheckLinkStatusTaskHandle;
    NetworkInterface_t     * pxFSPInterface;
    const ether_instance_t * pxEther;
    NetworkEndPoint_t        xEndPoint;
    uint8_t ucIpv4[RM_FREERTOS_PLUS_TCP_SIZE_OF_IPV4];
    uint8_t ucMask[RM_FREERTOS_PLUS_TCP_SIZE_OF_IPV4];
    uint8_t ucGateway[RM_FREERTOS_PLUS_TCP_SIZE_OF_IPV4];
    uint8_t ucDns[RM_FREERTOS_PLUS_TCP_SIZE_OF_IPV4];
    char    pcName[RM_FREERTOS_PLUS_TCP_SIZE_OF_INTERFACE_NAME];
};

/* Typedef definitions Please refer to the struct st_network_interface_instance. */
typedef struct st_network_interface_instance network_interface_instance_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_FREERTOS_PLUS_TCP)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* RM_FREERTOS_PLUS_TCP_H */
