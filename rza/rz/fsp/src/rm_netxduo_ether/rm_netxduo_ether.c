/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rm_netxduo_ether.h"

#include "nx_arp.h"
#include "nx_rarp.h"

#include "r_gether.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#ifdef __GNUC__
 #pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
 #pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#endif

/* Disable support for RARP by default. */
#ifndef RM_NETXDUO_ETHER_RARP_SUPPORT
 #define RM_NETXDUO_ETHER_RARP_SUPPORT    (0U)
#endif

#define NX_ETHERNET_SIZE                  14
#define NX_READ_BUFFER_SIZE               2000

/* Ethernet Frame IDs. */
#define NX_ETHERNET_IP                    0x0800
#define NX_ETHERNET_ARP                   0x0806
#define NX_ETHERNET_RARP                  0x8035
#define NX_ETHERNET_IPV6                  0x86DD

#define NX_ETHERNET_MIN_TRANSMIT_SIZE     60U

#define NX_ETHERNET_POLLING_INTERVAL      (10U)

/* Transmit Complete. */
#define ETHER_ISR_EE_TC_MASK              (1U << 21U)

/* Frame Receive. */
#define ETHER_ISR_EE_FR_MASK              (1U << 18U)

/* NetX the interfaces attached to this IP instance. */
#define NX_MAX_INTERFACES                 4

/* NetX interface instance management structure. */
typedef struct _nx_network_driver_instance_type
{
    UINT nx_network_driver_in_use;
    UINT nx_driver_channel;

    NX_INTERFACE * nx_driver_interface_ptr;
    NX_IP        * nx_driver_ip_ptr;
} _nx_network_driver_instance_type;

/* Instance of network driver. */
static _nx_network_driver_instance_type _nx_driver_instance[NX_MAX_INTERFACES];

static uint8_t _nx_driver_read_buffer[NX_READ_BUFFER_SIZE];

static int _convert_packet_data(uint8_t * p_buffer_pointer, uint32_t xbytes_received, NX_PACKET ** packet_top);

#define NX_PACKET_SHIFT    2

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

static void rm_netxduo_ether_cleanup(rm_netxduo_ether_instance_t * p_netxduo_ether_instance);
void        rm_netxduo_ether_receive_packet(rm_netxduo_ether_instance_t * p_netxduo_ether_instance);
void        rm_event_timer_callback(ULONG data);

/*******************************************************************************************************************//**
 * Ethernet driver for NetX Duo.
 **********************************************************************************************************************/
void rm_netxduo_ether (NX_IP_DRIVER * driver_req_ptr, rm_netxduo_ether_instance_t * p_netxduo_ether_instance)
{
    ether_instance_t const * p_ether_instance = p_netxduo_ether_instance->p_cfg->p_ether_instance;
    NX_INTERFACE           * interface_ptr    = driver_req_ptr->nx_ip_driver_interface;
    UINT i = 0;
    UINT interface_index;

    p_netxduo_ether_instance->p_ctrl->p_interface = interface_ptr;

    p_netxduo_ether_instance->p_ctrl->p_ip = driver_req_ptr->nx_ip_driver_ptr;

    driver_req_ptr->nx_ip_driver_status = NX_SUCCESS;

    /* Obtain the index number of the network interface. */
    interface_index = interface_ptr->nx_interface_index;

    /* Find out the driver interface if the driver command is not ATTACH. */
    if (driver_req_ptr->nx_ip_driver_command != NX_LINK_INTERFACE_ATTACH)
    {
        for (i = 0; i < NX_MAX_INTERFACES; i++)
        {
            if (_nx_driver_instance[i].nx_network_driver_in_use == 0)
            {
                continue;
            }

            if (_nx_driver_instance[i].nx_driver_ip_ptr != driver_req_ptr->nx_ip_driver_ptr)
            {
                continue;
            }

            if (_nx_driver_instance[i].nx_driver_interface_ptr == driver_req_ptr->nx_ip_driver_interface)
            {
                break;
            }
        }

        if (i == NX_MAX_INTERFACES)
        {
            driver_req_ptr->nx_ip_driver_status = NX_INVALID_INTERFACE;

            return;
        }
    }

    switch (driver_req_ptr->nx_ip_driver_command)
    {
        case NX_LINK_INTERFACE_ATTACH:
        {
            /* Find an available driver instance to attach the interface. */
            for (i = 0; i < NX_MAX_INTERFACES; i++)
            {
                if (_nx_driver_instance[i].nx_network_driver_in_use == 0)
                {
                    break;
                }
            }

            /* An available entry is found. */
            if (i < NX_MAX_INTERFACES)
            {
                /* Set the IN USE flag.*/
                _nx_driver_instance[i].nx_network_driver_in_use = 1;

                _nx_driver_instance[i].nx_driver_channel = p_ether_instance->p_cfg->channel;

                /* Record the interface attached to the IP instance. */
                _nx_driver_instance[i].nx_driver_interface_ptr = driver_req_ptr->nx_ip_driver_interface;

                /* Record the IP instance. */
                _nx_driver_instance[i].nx_driver_ip_ptr = driver_req_ptr->nx_ip_driver_ptr;
            }
            else
            {
                driver_req_ptr->nx_ip_driver_status = NX_INVALID_INTERFACE;
            }

            break;
        }

        case NX_LINK_INTERFACE_DETACH:
        {
            /* Zero out the driver instance. */
            memset(&(_nx_driver_instance[i]), 0, sizeof(_nx_network_driver_instance_type));

            break;
        }

        case NX_LINK_INITIALIZE:
        {
            /* The nx_interface_ip_mtu_size should be the MTU for the IP payload.
             * For regular Ethernet, the IP MTU is 1500. */
            nx_ip_interface_mtu_set(driver_req_ptr->nx_ip_driver_ptr,
                                    interface_index,
                                    p_netxduo_ether_instance->p_cfg->mtu);

            /* Set the physical address (MAC address) of this IP instance.  */
            uint8_t * p_mac_address = p_ether_instance->p_cfg->p_mac_address;
            nx_ip_interface_physical_address_set(driver_req_ptr->nx_ip_driver_ptr,
                                                 interface_index,
                                                 (ULONG) ((p_mac_address[0] << 8) | (p_mac_address[1] << 0)),
                                                 (ULONG) ((p_mac_address[2] << 24) | (p_mac_address[3] << 16) |
                                                          (p_mac_address[4] << 8) |
                                                          (p_mac_address[5] << 0)),
                                                 NX_FALSE);

            /* Indicate to the IP software that IP to physical mapping is required.  */
            nx_ip_interface_address_mapping_configure(driver_req_ptr->nx_ip_driver_ptr, interface_index, NX_TRUE);
            break;
        }

        case NX_LINK_UNINITIALIZE:
        {
            /* Zero out the driver instance. */
            memset(&(_nx_driver_instance[i]), 0, sizeof(_nx_network_driver_instance_type));

            break;
        }

        case NX_LINK_ENABLE:
        {
            /* Initialize ether driver state. */
            p_netxduo_ether_instance->p_ctrl->tx_packet_index             = 0;
            p_netxduo_ether_instance->p_ctrl->tx_packet_transmitted_index = 0;
            p_netxduo_ether_instance->p_ctrl->rx_packet_index             = 0;

            /* Clear the multicast MAC address list. */
            memset(p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses, 0,
                   sizeof(p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses));

            /* Set the return status to be invalid if the link is not enabled. */
            driver_req_ptr->nx_ip_driver_status = NX_INVALID_INTERFACE;

            /* Open the r_ether driver. */
            if (FSP_SUCCESS != p_ether_instance->p_api->open(p_ether_instance->p_ctrl, p_ether_instance->p_cfg))
            {
                rm_netxduo_ether_cleanup(p_netxduo_ether_instance);
            }
            /* Create a timer to poll for completion of auto negotiation. */
            else if (TX_SUCCESS !=
                     tx_timer_create(&p_netxduo_ether_instance->p_ctrl->event_timer, (CHAR *) "nx ether driver timer",
                                     rm_event_timer_callback, (ULONG) p_netxduo_ether_instance,
                                     NX_ETHERNET_POLLING_INTERVAL,
                                     NX_ETHERNET_POLLING_INTERVAL, TX_AUTO_ACTIVATE))
            {
                rm_netxduo_ether_cleanup(p_netxduo_ether_instance);
            }
            else
            {
                /* Wait for the link to be enabled. */
                while (FSP_SUCCESS != p_ether_instance->p_api->linkProcess(p_ether_instance->p_ctrl))
                {
                }

                driver_req_ptr->nx_ip_driver_status = NX_SUCCESS;
            }

            break;
        }

        case NX_LINK_DISABLE:
        {
            /* Delete RTOS objects. */
            rm_netxduo_ether_cleanup(p_netxduo_ether_instance);

            break;
        }

        case NX_LINK_PACKET_SEND:
        case NX_LINK_PACKET_BROADCAST:
        case NX_LINK_ARP_SEND:
        case NX_LINK_ARP_RESPONSE_SEND:
        case NX_LINK_RARP_SEND:
        {
            NX_PACKET * packet_ptr = driver_req_ptr->nx_ip_driver_packet;

            if (NX_TRUE != interface_ptr->nx_interface_link_up)
            {
                /* THe link has not been established yet. */
                driver_req_ptr->nx_ip_driver_status = NX_INVALID_INTERFACE;

                FSP_LOG_PRINT("Cannot transmit Ethernet packets because the link is down.");

                /* Release the NetX packet because it cannot be sent. */
                if (NX_SUCCESS != nx_packet_transmit_release(driver_req_ptr->nx_ip_driver_packet))
                {
                    FSP_LOG_PRINT("Failed to release transmit packet.");
                }

                return;
            }

            /* Adjust prepend pointer to make room for Ethernet header. */
            UCHAR * p_packet_prepend = packet_ptr->nx_packet_prepend_ptr - NX_ETHERNET_SIZE;
            UINT    packet_length    = packet_ptr->nx_packet_length + NX_ETHERNET_SIZE;

            /* Setup the Ethernet frame pointer to build the Ethernet frame.  Backup another 2
             * bytes to get 32-bit word alignment.  */
            ULONG * ethernet_frame_ptr = (ULONG *) (p_packet_prepend - 2);

            /* Build the Ethernet frame.  */
            *ethernet_frame_ptr       = driver_req_ptr->nx_ip_driver_physical_address_msw;
            *(ethernet_frame_ptr + 1) = driver_req_ptr->nx_ip_driver_physical_address_lsw;
            *(ethernet_frame_ptr + 2) = (interface_ptr->nx_interface_physical_address_msw << 16) |
                                        (interface_ptr->nx_interface_physical_address_lsw >> 16);
            *(ethernet_frame_ptr + 3) = (interface_ptr->nx_interface_physical_address_lsw << 16);

            if (driver_req_ptr->nx_ip_driver_command == NX_LINK_ARP_SEND)
            {
                *(ethernet_frame_ptr + 3) |= NX_ETHERNET_ARP;
            }
            else if (driver_req_ptr->nx_ip_driver_command == NX_LINK_ARP_RESPONSE_SEND)
            {
                *(ethernet_frame_ptr + 3) |= NX_ETHERNET_ARP;
            }

#if RM_NETXDUO_ETHER_RARP_SUPPORT
            else if (driver_req_ptr->nx_ip_driver_command == NX_LINK_RARP_SEND)
            {
                *(ethernet_frame_ptr + 3) |= NX_ETHERNET_RARP;
            }
#endif
            else if (packet_ptr->nx_packet_ip_version == 4)
            {
                *(ethernet_frame_ptr + 3) |= NX_ETHERNET_IP;
            }
            else
            {
                *(ethernet_frame_ptr + 3) |= NX_ETHERNET_IPV6;
            }

            /* Endian swapping if NX_LITTLE_ENDIAN is defined.  */
            NX_CHANGE_ULONG_ENDIAN(*(ethernet_frame_ptr));
            NX_CHANGE_ULONG_ENDIAN(*(ethernet_frame_ptr + 1));
            NX_CHANGE_ULONG_ENDIAN(*(ethernet_frame_ptr + 2));
            NX_CHANGE_ULONG_ENDIAN(*(ethernet_frame_ptr + 3));

            /* Zero-pad if the packet is smaller than the minimum packet size. */
            if (packet_length < NX_ETHERNET_MIN_TRANSMIT_SIZE)
            {
                memset(p_packet_prepend + packet_length, 0, NX_ETHERNET_MIN_TRANSMIT_SIZE - packet_length);
                packet_length = NX_ETHERNET_MIN_TRANSMIT_SIZE;
            }

            /* Transmit the Ethernet packet. */
            fsp_err_t err = p_ether_instance->p_api->write(p_ether_instance->p_ctrl, p_packet_prepend, packet_length);

            if (FSP_SUCCESS != err)
            {
                /* Set driver status to indicate that the packet was not transmitted. */
                driver_req_ptr->nx_ip_driver_status = NX_TX_QUEUE_DEPTH;

                FSP_LOG_PRINT("Failed to transmit the Ethernet packet.");

                /* Release the NetX packet because it cannot be sent. */
                if (NX_SUCCESS != nx_packet_transmit_release(packet_ptr))
                {
                    FSP_LOG_PRINT("Failed to release transmit packet.");
                }

                return;
            }

            /* Release the NetX packet because it cannot be sent. */
            if (NX_SUCCESS != nx_packet_transmit_release(packet_ptr))
            {
                FSP_LOG_PRINT("Failed to release transmit packet.");
            }

            break;
        }

        case NX_LINK_MULTICAST_JOIN:
        {
            /* Store the multicast MAC address in list at the next available location. */
            for (i = 0; i < NX_MAX_MULTICAST_GROUPS; i++)
            {
                if ((p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_msw == 0U) &&
                    (p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_lsw == 0U))
                {
                    p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_msw =
                        driver_req_ptr->nx_ip_driver_physical_address_msw;
                    p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_lsw =
                        driver_req_ptr->nx_ip_driver_physical_address_lsw;
                    break;
                }
            }

            if (NX_MAX_MULTICAST_GROUPS == i)
            {
                driver_req_ptr->nx_ip_driver_status = NX_NO_MORE_ENTRIES;
            }

            break;
        }

        case NX_LINK_MULTICAST_LEAVE:
        {
            /* Remove the multicast MAC address from the list. */
            for (i = 0; i < NX_MAX_MULTICAST_GROUPS; i++)
            {
                if ((p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_msw ==
                     driver_req_ptr->nx_ip_driver_physical_address_msw) &&
                    (p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_lsw ==
                     driver_req_ptr->nx_ip_driver_physical_address_lsw))
                {
                    p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_msw = 0U;
                    p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_lsw = 0U;
                    break;
                }
            }

            if (NX_MAX_MULTICAST_GROUPS == i)
            {
                driver_req_ptr->nx_ip_driver_status = NX_ENTRY_NOT_FOUND;
            }

            break;
        }

        case NX_LINK_DEFERRED_PROCESSING:
        {
            /* linkProcess will call the Ethernet callback from the ip task when the link changes. */
            p_ether_instance->p_api->linkProcess(p_ether_instance->p_ctrl);
            break;
        }

        case NX_LINK_GET_STATUS:
        {
            /* Return the link status in the supplied return pointer.  */
            *(driver_req_ptr->nx_ip_driver_return_ptr) = interface_ptr->nx_interface_link_up;
            break;
        }

        default:
        {
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Delete all unused rtos objects.
 **********************************************************************************************************************/
static void rm_netxduo_ether_cleanup (rm_netxduo_ether_instance_t * p_netxduo_ether_instance)
{
    /* Set interface link status to down. */
    p_netxduo_ether_instance->p_ctrl->p_interface->nx_interface_link_up = NX_FALSE;

    ether_instance_t const * p_ether_instance = p_netxduo_ether_instance->p_cfg->p_ether_instance;

    /* Close the ether driver. */
    p_ether_instance->p_api->close(p_ether_instance->p_ctrl);

    /* Delete RTOS Objects. */
    tx_semaphore_delete(&p_netxduo_ether_instance->p_ctrl->ether_tx_semaphore);
    tx_timer_deactivate(&p_netxduo_ether_instance->p_ctrl->event_timer);
    tx_timer_delete(&p_netxduo_ether_instance->p_ctrl->event_timer);

    /* Release all transmit packets. */
    for (uint32_t i = 0; i < p_ether_instance->p_cfg->num_tx_descriptors; i++)
    {
        if (NULL != p_netxduo_ether_instance->p_cfg->p_tx_packets[i])
        {
            nx_packet_release(p_netxduo_ether_instance->p_cfg->p_tx_packets[i]);
            p_netxduo_ether_instance->p_cfg->p_tx_packets[i] = NULL;
        }
    }

    /* Release all receive packets. */
    for (uint32_t i = 0; i < p_ether_instance->p_cfg->num_rx_descriptors; i++)
    {
        nx_packet_release(p_netxduo_ether_instance->p_cfg->p_rx_packets[i]);
    }
}

/*******************************************************************************************************************//**
 * Process all Ethernet packets that have been received.
 **********************************************************************************************************************/
void rm_netxduo_ether_receive_packet (rm_netxduo_ether_instance_t * p_netxduo_ether_instance)
{
    ether_instance_t const * p_ether_instance = p_netxduo_ether_instance->p_cfg->p_ether_instance;
    uint8_t                * p_mac_address    = p_ether_instance->p_cfg->p_mac_address;
    ULONG mac_msw = (ULONG) ((p_mac_address[0] << 8) | (p_mac_address[1] << 0));
    ULONG mac_lsw =
        (ULONG) ((p_mac_address[2] << 24) | (p_mac_address[3] << 16) | (p_mac_address[4] << 8) |
                 (p_mac_address[5] << 0));
    fsp_err_t   err;
    NX_PACKET * p_nx_packet = NULL;
    UINT        i;
    uint32_t    length;

    do
    {
        /* Get a pointer to the packet received. */
        length = sizeof(_nx_driver_read_buffer);
        err    = p_ether_instance->p_api->read(p_ether_instance->p_ctrl, _nx_driver_read_buffer, &length);
        if (FSP_SUCCESS != err)
        {
            break;
        }

        /* Allocate NetX packet and copy data into. */
        int interface_instance_id;
        interface_instance_id = _convert_packet_data(_nx_driver_read_buffer, length, &p_nx_packet);

        if (0 <= interface_instance_id)
        {
            /* Pick up the destination MAC address from the packet.  */
            ULONG destination_address_msw = (ULONG) *(p_nx_packet->nx_packet_prepend_ptr);
            destination_address_msw = (destination_address_msw << 8) |
                                      (ULONG) *(p_nx_packet->nx_packet_prepend_ptr + 1);
            ULONG destination_address_lsw = (ULONG) *(p_nx_packet->nx_packet_prepend_ptr + 2);
            destination_address_lsw = (destination_address_lsw << 8) |
                                      (ULONG) *(p_nx_packet->nx_packet_prepend_ptr + 3);
            destination_address_lsw = (destination_address_lsw << 8) |
                                      (ULONG) *(p_nx_packet->nx_packet_prepend_ptr + 4);
            destination_address_lsw = (destination_address_lsw << 8) |
                                      (ULONG) *(p_nx_packet->nx_packet_prepend_ptr + 5);

            bool multicast_group = false;

            /* Check if the packet is an IPv4 Multicast packet. */
            if ((destination_address_msw == 0x00000100U) && ((destination_address_lsw >> 24U) == 0x5EU)) // NOLINT(readability-magic-numbers)
            {
                /* Check if the IP instance is a member of the group. */
                for (i = 0; i < NX_MAX_MULTICAST_GROUPS; i++)
                {
                    /* IPv4 multicast MAC addreses always begin with 0x0100 so only destination_address_lsw needs to be checked. */
                    if (destination_address_lsw ==
                        p_netxduo_ether_instance->p_ctrl->multicast_mac_addresses[i].mac_address_lsw)
                    {
                        multicast_group = true;
                        break;
                    }
                }
            }

            /* Only process packets that are meant for this mac address (dest=Broadcast/mac_address). */
            if (((destination_address_msw == ((ULONG) 0x0000FFFF)) &&  // NOLINT(readability-magic-numbers)
                 (destination_address_lsw == ((ULONG) 0xFFFFFFFF))) || // NOLINT(readability-magic-numbers)
                ((destination_address_msw == mac_msw) &&               // NOLINT(readability-magic-numbers)
                 (destination_address_lsw == mac_lsw)) ||              // NOLINT(readability-magic-numbers)
                (destination_address_msw == ((ULONG) 0x00003333)) ||   // NOLINT(readability-magic-numbers)
                ((destination_address_msw == 0) && (destination_address_lsw == 0)) ||
                multicast_group)
            {
                /* Get the Ethernet packet id. */
                UINT packet_type = (((UINT) (*(p_nx_packet->nx_packet_prepend_ptr + 12))) << 8) |
                                   ((UINT) (*(p_nx_packet->nx_packet_prepend_ptr + 13)));

                if ((packet_type == NX_ETHERNET_IP) ||
#ifndef NX_DISABLE_IPV6
                    (packet_type == NX_ETHERNET_IPV6) ||
#endif
                    (packet_type == NX_ETHERNET_ARP)
#if RM_NETXDUO_ETHER_RARP_SUPPORT
                    || (packet_type == NX_ETHERNET_RARP)
#endif
                    )
                {
                    switch (packet_type)
                    {
                        case NX_ETHERNET_IP:
#ifndef NX_DISABLE_IPV6
                        case NX_ETHERNET_IPV6:
#endif
                            {
                                /* Clean off the Ethernet header.  */
                                p_nx_packet->nx_packet_prepend_ptr = p_nx_packet->nx_packet_prepend_ptr +
                                                                     NX_ETHERNET_SIZE;

                                /* Adjust the packet length.  */
                                p_nx_packet->nx_packet_length = p_nx_packet->nx_packet_length - NX_ETHERNET_SIZE;

                                /* Process the IP packet. */
                                _nx_ip_packet_deferred_receive(
                                    _nx_driver_instance[interface_instance_id].nx_driver_ip_ptr,
                                    p_nx_packet);
                                break;
                            }

                        case NX_ETHERNET_ARP:
                        {
                            /* Clean off the Ethernet header.  */
                            p_nx_packet->nx_packet_prepend_ptr = p_nx_packet->nx_packet_prepend_ptr + NX_ETHERNET_SIZE;

                            /* Adjust the packet length.  */
                            p_nx_packet->nx_packet_length = p_nx_packet->nx_packet_length - NX_ETHERNET_SIZE;

                            /* Process the ARP packet. */
                            _nx_arp_packet_deferred_receive(_nx_driver_instance[interface_instance_id].nx_driver_ip_ptr,
                                                            p_nx_packet);
                            break;
                        }

#if RM_NETXDUO_ETHER_RARP_SUPPORT
                        case NX_ETHERNET_RARP:
                        {
                            /* Clean off the Ethernet header.  */
                            p_nx_packet->nx_packet_prepend_ptr = p_nx_packet->nx_packet_prepend_ptr + NX_ETHERNET_SIZE;

                            /* Adjust the packet length.  */
                            p_nx_packet->nx_packet_length = p_nx_packet->nx_packet_length - NX_ETHERNET_SIZE;

                            /* Process the RARP packet. */
                            _nx_rarp_packet_deferred_receive(
                                _nx_driver_instance[interface_instance_id].nx_driver_ip_ptr,
                                p_nx_packet);
                            break;
                        }
#endif

                        default:
                        {
                            if (NX_SUCCESS != nx_packet_release(p_nx_packet))
                            {
                                FSP_LOG_PRINT("Failed to release NetX Packet.");
                            }

                            break;
                        }
                    }
                }
                else
                {
                    if (NX_SUCCESS != nx_packet_release(p_nx_packet))
                    {
                        FSP_LOG_PRINT("Failed to release NetX Packet.");
                    }
                }
            }
            else
            {
                if (NX_SUCCESS != nx_packet_release(p_nx_packet))
                {
                    FSP_LOG_PRINT("Failed to release NetX Packet.");
                }
            }
        }
    } while (FSP_SUCCESS == err);
}

/**********************************************************************************************************************
 * Function Name: _convert_packet_data ()
 * Description  : Convert received packet data to NX_PACKET data
 * Arguments    : uint8_t *p_buffer_pointer
 *                int32_t xbytes_received
 *                NX_PACKET**packet_top
 * Return Value : interface instance id
 *********************************************************************************************************************/
static int _convert_packet_data (uint8_t * p_buffer_pointer, uint32_t xbytes_received, NX_PACKET ** packet_top)
{
    int         interface_instance_id;
    NX_PACKET * packet_ptr;

    for (interface_instance_id = 0; interface_instance_id < NX_MAX_INTERFACES; interface_instance_id++)
    {
        /* Skip the instance that has not been initialized. */
        if (_nx_driver_instance[interface_instance_id].nx_network_driver_in_use == 0)
        {
            continue;
        }

        /* Set the IP instance.  */
        NX_IP * ip_ptr;
        ip_ptr = _nx_driver_instance[interface_instance_id].nx_driver_ip_ptr;

        if (nx_packet_allocate(ip_ptr->nx_ip_default_packet_pool, &packet_ptr, NX_RECEIVE_PACKET,
                               NX_NO_WAIT) == NX_SUCCESS)
        {
            /* Adjust the address to the 32-bit boundary. */
            packet_ptr->nx_packet_prepend_ptr = packet_ptr->nx_packet_prepend_ptr + NX_PACKET_SHIFT;
            packet_ptr->nx_packet_append_ptr  = packet_ptr->nx_packet_prepend_ptr;

            if (nx_packet_data_append(packet_ptr, p_buffer_pointer, xbytes_received, ip_ptr->nx_ip_default_packet_pool,
                                      NX_NO_WAIT) == NX_SUCCESS)
            {
                /* Setup interface pointer.  */
                packet_ptr->nx_packet_address.nx_packet_interface_ptr =
                    _nx_driver_instance[interface_instance_id].nx_driver_interface_ptr;

                *packet_top = packet_ptr;
                break;
            }

            // else //The following code will not be executed even if there is no else.
            {
                nx_packet_release(packet_ptr);
                packet_ptr            = NULL;
                interface_instance_id = -1;
            }

            break;
        }
    }

    if (NX_MAX_INTERFACES <= interface_instance_id)
    {
        interface_instance_id = -1;
    }

    return interface_instance_id;
}

/*******************************************************************************************************************//**
 * Timer callback for notifying the driver to poll the Ethernet link status.
 **********************************************************************************************************************/
void rm_event_timer_callback (ULONG data)
{
    rm_netxduo_ether_instance_t * p_netxduo_ether_instance = (rm_netxduo_ether_instance_t *) data;

    /* Check the received remaining packets. */
    rm_netxduo_ether_receive_packet(p_netxduo_ether_instance);

    /* Call NetX to register a deferred event.  */
    _nx_ip_driver_deferred_processing(p_netxduo_ether_instance->p_ctrl->p_ip);
}

/*******************************************************************************************************************//**
 * Callback from r_ether ISR.
 *
 * Notifies ether_thread when a packet is received using a semaphore.
 * Processes Link Up and Link Down events.
 **********************************************************************************************************************/
void rm_netxduo_ether_callback (ether_callback_args_t * p_args)
{
    /* Get the ether interface from a global pointer because r_ether does not set p_contect in p_args. */
    rm_netxduo_ether_instance_t * p_netxduo_ether_instance = (rm_netxduo_ether_instance_t *) p_args->p_context;

// ether_instance_t const      * p_ether_instance         = p_netxduo_ether_instance->p_cfg->p_ether_instance;

    /* Either the callback was called from an ISR or it was called from the linkProcess. */
    switch (p_args->event)
    {
        case ETHER_EVENT_INTERRUPT:
        {
            /* Packet received. */
            if (ETHER_ISR_EE_FR_MASK == (p_args->status_eesr & ETHER_ISR_EE_FR_MASK))
            {
                rm_netxduo_ether_receive_packet(p_netxduo_ether_instance);
            }

            break;
        }

        case ETHER_EVENT_LINK_ON:
        {
            /* Notify NetX that the link is up. */
            p_netxduo_ether_instance->p_ctrl->p_interface->nx_interface_link_up = NX_TRUE;
            _nx_ip_driver_link_status_event(p_netxduo_ether_instance->p_ctrl->p_ip,
                                            p_netxduo_ether_instance->p_ctrl->p_interface->nx_interface_index);
            break;
        }

        case ETHER_EVENT_LINK_OFF:
        {
            /* Notify NetX that the link is down. */
            p_netxduo_ether_instance->p_ctrl->p_interface->nx_interface_link_up = NX_FALSE;
            _nx_ip_driver_link_status_event(p_netxduo_ether_instance->p_ctrl->p_ip,
                                            p_netxduo_ether_instance->p_ctrl->p_interface->nx_interface_index);
            break;
        }

        default:
        {
            break;
        }
    }
}
