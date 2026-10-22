/*
 * FreeRTOS+TCP V2.2.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 * Copyright (C) 2026 Modified by Renesas Electronics Corporation and/or its affiliates
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

/* Standard libraries includes. */
#include <stdlib.h>

/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"

#include "NetworkInterface.h"
#include "NetworkBufferManagement.h"

/* Renesas includes. */
#include "r_ether_api.h"
#include "hal_data.h"
#include "rm_freertos_plus_tcp.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/* If ipconfigETHERNET_DRIVER_FILTERS_FRAME_TYPES is set to 1, then the Ethernet
 * driver will filter incoming packets and only pass the stack those packets it
 * considers need processing. */
#if (ipconfigETHERNET_DRIVER_FILTERS_FRAME_TYPES == 0)
 #define ipCONSIDER_FRAME_FOR_PROCESSING(pucEthernetBuffer)    eProcessBuffer
#else
 #define ipCONSIDER_FRAME_FOR_PROCESSING(pucEthernetBuffer)    eConsiderFrameForProcessing((pucEthernetBuffer))
#endif

/* Minimum Ethernet frame size (without CRC). */
#define MINIMUM_ETHERNET_FRAME_SIZE               (60U)
#define MAXIMUM_ETHERNET_FRAME_SIZE               (1514U)

#define ETHER_EDMAC_INTERRUPT_FACTOR_RECEPTION    (0x01070000)
#define ETHER_LINK_STATUS_CHECK_INTERVAL          (1000)

#define UNSIGNED_SHORT_RANDOM_NUMBER_MASK         (0xFFFFUL)

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

void vEtherISRCallbackInstance0(ether_callback_args_t * p_args);
void vEtherISRCallbackInstance1(ether_callback_args_t * p_args);

extern void * __freertos_plus_tcp_array_start;
extern void * __freertos_plus_tcp_array_end;
static network_interface_instance_t ** p_network_instance_list;
static uint32_t max_network_instance;
static uint32_t freertos_plus_tcp_initialized = false;
static network_interface_instance_t * p_gether_network_instance_ch[BSP_FEATURE_GETHER_MAX_CHANNELS];

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Prototype declaration of global functions
 **********************************************************************************************************************/
void                 vEtherISRCallback(ether_callback_args_t * p_args);
NetworkInterface_t * pxFSP_Eth_FillInterfaceDescriptor(BaseType_t xEMACIndex, NetworkInterface_t * pxInterface);

/***********************************************************************************************************************
 * Prototype declaration of private functions
 **********************************************************************************************************************/
static BaseType_t                     prvNetworkInterfaceInput(network_interface_instance_t * p_network_interface);
static void                           prvRXHandlerTask(void * pvParameters);
static void                           prvCheckLinkStatusTask(void * pvParameters);
static network_interface_instance_t * prvGetNetworkInterface(NetworkInterface_t * pxInterface);
static void                           prvNetworkInterfaceModuleInitialize(void);

static BaseType_t xFSP_Eth_NetworkInterfaceInitialise(NetworkInterface_t * pxInterface);
static BaseType_t xFSP_Eth_NetworkInterfaceOutput(NetworkInterface_t              * pxInterface,
                                                  NetworkBufferDescriptor_t * const pxNetworkBuffer,
                                                  BaseType_t                        xReleaseAfterSend);
static BaseType_t xFSP_Eth_GetPhyLinkStatus(struct xNetworkInterface * pxInterface);

/***********************************************************************************************************************
 * Interface functions
 **********************************************************************************************************************/
static BaseType_t xFSP_Eth_NetworkInterfaceInitialise (NetworkInterface_t * pxInterface)
{
    fsp_err_t  err;
    BaseType_t xReturn = pdFAIL;
    network_interface_instance_t * p_network_interface = NULL;

    prvNetworkInterfaceModuleInitialize();

    uint32_t loop;
    for (loop = 0; loop < max_network_instance; loop++)
    {
        if ((p_network_instance_list[loop]->pxFSPInterface == NULL) ||
            (0 == strcmp(p_network_instance_list[loop]->pcName, pxInterface->pcName)))
        {
            p_network_interface = p_network_instance_list[loop];
            break;
        }
    }

    if (NULL == p_network_interface)
    {
        return pdFAIL;
    }

    configASSERT(NULL != p_network_interface->pxEther);

    p_gether_network_instance_ch[p_network_interface->pxEther->p_cfg->channel] = p_network_interface;

    p_network_interface->pxFSPInterface = pxInterface;

    if (ETHER_ZEROCOPY_ENABLE == p_network_interface->pxEther->p_cfg->zerocopy)
    {
        /*NOTE:Currently does not support zero copy mode*/
        while (1)
        {
            ;
        }
    }

    err = p_network_interface->pxEther->p_api->open(p_network_interface->pxEther->p_ctrl,
                                                    p_network_interface->pxEther->p_cfg);

    if ((FSP_SUCCESS != err) && (FSP_ERR_ALREADY_OPEN != err))
    {
        p_network_interface->pxEther->p_api->close(p_network_interface->pxEther->p_ctrl);

        return pdFAIL;
    }

    if (FSP_SUCCESS == err)
    {
        FreeRTOS_FillEndPoint(pxInterface,
                              &p_network_interface->xEndPoint,
                              p_network_interface->ucIpv4,
                              p_network_interface->ucMask,
                              p_network_interface->ucGateway,
                              p_network_interface->ucDns,
                              p_network_interface->pxEther->p_cfg->p_mac_address);
#if (ipconfigUSE_DHCP != 0)
        {
            p_network_interface->xEndPoint.bits.bWantDHCP = pdTRUE;
        }
#endif                                 /* ipconfigUSE_DHCP */
    }

    err = p_network_interface->pxEther->p_api->linkProcess(p_network_interface->pxEther->p_ctrl);

    if (FSP_SUCCESS != err)
    {
        return pdFAIL;
    }

    /* prevent tasks from repeatedly creating when reconnected from the network */
    if (NULL == p_network_interface->xRxHanderTaskHandle)
    {
        xTaskCreate(prvRXHandlerTask,
                    "RXHandlerTask",
                    configMINIMAL_STACK_SIZE,
                    p_network_interface,
                    configMAX_PRIORITIES - 1,
                    &p_network_interface->xRxHanderTaskHandle);
    }

    if (NULL == p_network_interface->xCheckLinkStatusTaskHandle)
    {
        xTaskCreate(prvCheckLinkStatusTask,
                    "CheckLinkStatusTask",
                    configMINIMAL_STACK_SIZE,
                    p_network_interface,
                    configMAX_PRIORITIES - 1,
                    &p_network_interface->xCheckLinkStatusTaskHandle);
    }

    if ((FSP_SUCCESS == err) && (NULL != p_network_interface->xRxHanderTaskHandle) &&
        (NULL != p_network_interface->xCheckLinkStatusTaskHandle))
    {
        xReturn = pdPASS;
    }
    else
    {
        xReturn = pdFAIL;
    }

    return xReturn;
}

static BaseType_t xFSP_Eth_NetworkInterfaceOutput (NetworkInterface_t              * pxInterface,
                                                   NetworkBufferDescriptor_t * const pxNetworkBuffer,
                                                   BaseType_t                        xReleaseAfterSend)
{
    fsp_err_t  err;
    BaseType_t xReturn = pdPASS;

    network_interface_instance_t * p_network_interface = prvGetNetworkInterface(pxInterface);

    configASSERT(NULL != p_network_interface);

    /* Simple network interfaces (as opposed to more efficient zero copy network
     * interfaces) just use Ethernet peripheral driver library functions to copy
     * data from the FreeRTOS+TCP buffer into the peripheral driver's own buffer.*/

    if (MINIMUM_ETHERNET_FRAME_SIZE > pxNetworkBuffer->xDataLength)
    {
        pxNetworkBuffer->xDataLength = MINIMUM_ETHERNET_FRAME_SIZE;
    }

    err = p_network_interface->pxEther->p_api->write(p_network_interface->pxEther->p_ctrl,
                                                     pxNetworkBuffer->pucEthernetBuffer,
                                                     (uint32_t) pxNetworkBuffer->xDataLength);

    if (FSP_SUCCESS == err)
    {
        xReturn = pdPASS;
    }
    else
    {
        xReturn = pdFAIL;
    }

    if (pdFAIL != xReturn)
    {
        /* Call the standard trace macro to log the send event. */
        iptraceNETWORK_INTERFACE_TRANSMIT();
    }

    /* The Ethernet buffer is therefore no longer needed, and must be freed for re-use. */
    if (xReleaseAfterSend == pdTRUE)
    {
        vReleaseNetworkBufferAndDescriptor(pxNetworkBuffer);
    }

    return xReturn;
}

static BaseType_t xFSP_Eth_GetPhyLinkStatus (struct xNetworkInterface * pxInterface)
{
    BaseType_t xReturn = pdPASS;
    network_interface_instance_t * p_network_interface = prvGetNetworkInterface(pxInterface);

    configASSERT(NULL != p_network_interface);

    if (FSP_SUCCESS == p_network_interface->pxEther->p_api->linkProcess(p_network_interface->pxEther->p_ctrl))
    {
        xReturn = pdPASS;
    }
    else
    {
        xReturn = pdFAIL;
    }

    return xReturn;
}

/***********************************************************************************************************************
 * global functions
 **********************************************************************************************************************/
void vEtherISRCallback (ether_callback_args_t * p_args) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* If EDMAC FR (Frame Receive Event) or FDE (Receive Descriptor Empty Event)
     * interrupt occurs, wake up xRxHanderTask. */
    network_interface_instance_t * p_network_interface = p_gether_network_instance_ch[p_args->channel];
    if (p_args->status_eesr & ETHER_EDMAC_INTERRUPT_FACTOR_RECEPTION)
    {
        if (p_network_interface->xRxHanderTaskHandle != NULL)
        {
            vTaskNotifyGiveFromISR(p_network_interface->xRxHanderTaskHandle, &xHigherPriorityTaskWoken);
        }

        /* If xHigherPriorityTaskWoken is now set to pdTRUE then a context switch
         * should be performed to ensure the interrupt returns directly to the highest
         * priority task.  The macro used for this purpose is dependent on the port in
         * use and may be called portEND_SWITCHING_ISR(). */
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

size_t uxNetworkInterfaceAllocateRAMToBuffers (
    NetworkBufferDescriptor_t pxNetworkBuffers[ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS])
{
    /* Remove compiler warning about unused parameter. */
    FSP_PARAMETER_NOT_USED(pxNetworkBuffers);

    return 0;
}

NetworkInterface_t * pxFSP_Eth_FillInterfaceDescriptor (BaseType_t xEMACIndex, NetworkInterface_t * pxInterface)
{
    char * pcName = NULL;
    network_interface_instance_t * p_network_interface = NULL;

    prvNetworkInterfaceModuleInitialize();

    /* This function pxFSP_Eth_FillInterfaceDescriptor() adds a network-interface. */
    uint32_t loop;
    for (loop = 0; loop < max_network_instance; loop++)
    {
        if (p_network_instance_list[loop]->pcName[0] == '\0')
        {
            p_network_interface = p_network_instance_list[loop];

            break;
        }
    }

    if (NULL != p_network_interface)
    {
        pcName = p_network_interface->pcName;

        if (NULL != pcName)
        {
            snprintf(pcName, sizeof(p_network_interface->pcName), "eth%u", (unsigned) xEMACIndex);

            memset(pxInterface, '\0', sizeof(*pxInterface));
            pxInterface->pcName             = pcName;              /* Just for logging, debugging. */
            pxInterface->pvArgument         = (void *) xEMACIndex; /* Has only meaning for the driver functions. */
            pxInterface->pfInitialise       = xFSP_Eth_NetworkInterfaceInitialise;
            pxInterface->pfOutput           = xFSP_Eth_NetworkInterfaceOutput;
            pxInterface->pfGetPhyLinkStatus = xFSP_Eth_GetPhyLinkStatus;

            FreeRTOS_AddNetworkInterface(pxInterface);
        }
    }

    return pxInterface;
}

/*-----------------------------------------------------------*/

#if defined(ipconfigIPv4_BACKWARD_COMPATIBLE) && (ipconfigIPv4_BACKWARD_COMPATIBLE == 1)

/* Do not call the following function directly. It is there for downward compatibility.
 * The function FreeRTOS_IPInit() will call it to initialice the interface and end-point
 * objects.  See the description in FreeRTOS_Routing.h. */
NetworkInterface_t * pxFillInterfaceDescriptor (BaseType_t xEMACIndex, NetworkInterface_t * pxInterface)
{
    return pxFSP_Eth_FillInterfaceDescriptor(xEMACIndex, pxInterface);
}

#endif

/*-----------------------------------------------------------*/

/***********************************************************************************************************************
 * private functions
 **********************************************************************************************************************/
static BaseType_t prvNetworkInterfaceInput (network_interface_instance_t * p_network_interface) {
    BaseType_t xResult = pdFAIL;
    fsp_err_t  err;

    /* Used to indicate that xSendEventStructToIPTask() is being called because
     * of an Ethernet receive event. */
    IPStackEvent_t              xRxEvent;
    NetworkBufferDescriptor_t * pxBufferDescriptor;
    uint32_t xBytesReceived = 0;

    pxBufferDescriptor = pxGetNetworkBufferWithDescriptor((size_t) MAXIMUM_ETHERNET_FRAME_SIZE, 0);

    if (NULL != pxBufferDescriptor)
    {
        /* Set the maximum buffer size when reading. */
        xBytesReceived = p_network_interface->pxEther->p_cfg->ether_buffer_size;

        err = p_network_interface->pxEther->p_api->read(p_network_interface->pxEther->p_ctrl,
                                                        (void *) pxBufferDescriptor->pucEthernetBuffer,
                                                        &xBytesReceived);
        if (FSP_SUCCESS != err)
        {
            xBytesReceived = 0;
        }

        pxBufferDescriptor->xDataLength = (size_t) xBytesReceived;
        pxBufferDescriptor->pxInterface = p_network_interface->pxFSPInterface;
        pxBufferDescriptor->pxEndPoint  =
            FreeRTOS_MatchingEndpoint(p_network_interface->pxFSPInterface, pxBufferDescriptor->pucEthernetBuffer);

        /* When driver received any data. */
        if ((FSP_SUCCESS == err) || (FSP_ERR_ETHER_ERROR_NO_DATA == err))
        {
            if ((pxBufferDescriptor->pxEndPoint != NULL) &&
                (eConsiderFrameForProcessing(pxBufferDescriptor->pucEthernetBuffer) == eProcessBuffer))
            {
                /* The event about to be sent to the TCP/IP is an Rx event. */
                xRxEvent.eEventType = eNetworkRxEvent;

                /* pvData is used to point to the network buffer descriptor that
                 * now references the received data. */
                xRxEvent.pvData = (void *) pxBufferDescriptor;

                /* Send the data to the TCP/IP stack. */
                if (pdPASS == xSendEventStructToIPTask(&xRxEvent, 0))
                {
                    /* The message was successfully sent to the TCP/IP stack.
                     * Call the standard trace macro to log the occurrence. */
                    iptraceNETWORK_INTERFACE_RECEIVE();
                    xResult = pdPASS;
                }
            }
        }

        if (pdPASS != xResult)
        {
            /* The buffer could not be sent to the IP task so the buffer must be released. */
            vReleaseNetworkBufferAndDescriptor(pxBufferDescriptor);
            iptraceETHERNET_RX_EVENT_LOST();
        }
    }

    return xResult;
}

static void prvNetworkInterfaceModuleInitialize (void)
{
    if (false == freertos_plus_tcp_initialized)
    {
        p_network_instance_list = (network_interface_instance_t **) &__freertos_plus_tcp_array_start;
        max_network_instance    =
            (uint32_t) ((uintptr_t) &__freertos_plus_tcp_array_end - (uintptr_t) &__freertos_plus_tcp_array_start) /
            sizeof(uintptr_t);
        freertos_plus_tcp_initialized = true;
    }
}

static network_interface_instance_t * prvGetNetworkInterface (NetworkInterface_t * pxInterface)
{
    uint32_t loop;
    for (loop = 0; loop < max_network_instance; loop++)
    {
        if (p_network_instance_list[loop]->pxFSPInterface == pxInterface)
        {
            return p_network_instance_list[loop];
        }
    }

    return NULL;
}

static void prvRXHandlerTask (void * pvParameters) {
    BaseType_t xResult = pdFALSE;

    /* Avoid compiler warning about unreferenced parameter. */

    for ( ; ; )
    {
        /* Wait for the Ethernet MAC interrupt to indicate that another packet
         * has been received.  */
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY);

        do
        {
            xResult = prvNetworkInterfaceInput(pvParameters);
        } while (pdFAIL != xResult);
    }
}

static void prvCheckLinkStatusTask (void * pvParameters) {
    /* Remove compiler warning about unused parameter. */
    network_interface_instance_t * p_network_interface = pvParameters;

    fsp_err_t      current_link_status  = FSP_ERR_ETHER_ERROR_LINK;
    fsp_err_t      previous_link_status = FSP_ERR_ETHER_ERROR_LINK;
    IPStackEvent_t xNetworkDownEvent    = {eNetworkDownEvent, p_network_interface->pxFSPInterface};

    for ( ; ; )
    {
        vTaskDelay(ETHER_LINK_STATUS_CHECK_INTERVAL);
        current_link_status = p_network_interface->pxEther->p_api->linkProcess(p_network_interface->pxEther->p_ctrl);

        /* Link status is changed. */
        if (previous_link_status != current_link_status)
        {
            if (FSP_SUCCESS == current_link_status)
            {
                /* Link status changed to up. */
                previous_link_status = current_link_status;

                vIPNetworkUpCalls(p_network_interface->pxFSPInterface->pxEndPoint);
            }
            else if ((FSP_ERR_ETHER_ERROR_LINK == current_link_status) ||
                     (FSP_ERR_ETHER_PHY_ERROR_LINK == current_link_status))
            {
                /* Link status changed to down. Send the data to the TCP/IP stack. */
                if (pdPASS == xSendEventStructToIPTask(&xNetworkDownEvent, 0))
                {
                    previous_link_status = current_link_status;
                }
            }
            else
            {
                /* Correct Link status could not be retrieved. */
                ;
            }
        }
    }
}

__attribute__((weak)) BaseType_t xApplicationGetRandomNumber (uint32_t * pulNumber)
{
    /* example of a 32-bit random number generator.
     * rand() in returns a 16-bit number. so create 32 bit Random number using 16 bit rand().
     * In this case just a pseudo random number is used so THIS IS NOT RECOMMENDED FOR PRODUCTION SYSTEMS.
     */
    uint32_t ulRandomValue = 0;

    ulRandomValue = (uint32_t) (((((uint32_t) rand()) & UNSIGNED_SHORT_RANDOM_NUMBER_MASK)) |       // NOLINT (rand() has limited randomness. But c99 does not support random)
                                ((((uint32_t) rand()) & UNSIGNED_SHORT_RANDOM_NUMBER_MASK) << 16)); // NOLINT (rand() has limited randomness. But c99 does not support random)

    *(pulNumber) = ulRandomValue;

    return pdTRUE;
}

BSP_WEAK_REFERENCE uint32_t ulApplicationGetNextSequenceNumber (uint32_t ulSourceAddress,
                                                                uint16_t usSourcePort,
                                                                uint32_t ulDestinationAddress,
                                                                uint16_t usDestinationPort)
{
    /*
     * Callback that provides the inputs necessary to generate a randomized TCP
     * Initial Sequence Number per RFC 6528.  In this case just a pseudo random
     * number is used so THIS IS NOT RECOMMENDED FOR PRODUCTION SYSTEMS.
     */
    FSP_PARAMETER_NOT_USED(ulSourceAddress);
    FSP_PARAMETER_NOT_USED(ulDestinationAddress);
    FSP_PARAMETER_NOT_USED(usSourcePort);
    FSP_PARAMETER_NOT_USED(usDestinationPort);

    uint32_t ulResult = 0;
    while (0 == ulResult)
    {
        xApplicationGetRandomNumber(&ulResult);
    }

    return ulResult;
}
