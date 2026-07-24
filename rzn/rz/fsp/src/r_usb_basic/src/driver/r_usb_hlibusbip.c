/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/

#include <r_usb_basic.h>
#include <r_usb_basic_api.h>

#include "inc/r_usb_basic_local.h"
#include "inc/r_usb_typedef.h"
#include "inc/r_usb_extern.h"
#include "../hw/inc/r_usb_bitdefine.h"
#include "../hw/inc/r_usb_reg_access.h"

#if ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE))
 #include "../hw/inc/r_usb_dmac.h"
#endif                                 /* ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE)) */

#if defined(USB_CFG_HMSC_USE)
 #include "../../../r_usb_hmsc/src/inc/r_usb_hmsc_driver.h"
#endif                                 /* defined(USB_CFG_HMSC_USE) */

#if defined(USB_CFG_HCDC_USE)
 #include "r_usb_hcdc_cfg.h"
#endif                                 /* defined(USB_CFG_HCDC_USE) */

#if defined(USB_CFG_HHID_USE)
 #include "r_usb_hhid_cfg.h"
#endif                                 /* defined(USB_CFG_HHID_USE) */

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)

/******************************************************************************
 * Renesas Abstracted Host Lib IP functions
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_chk_dev_addr
 * Description     : Get USB speed set in USB register based on the specified USB
 *               : Device address and USB port no.
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 *               : uint16_t addr        : device address
 * Return value    : uint16_t             : USB speed etc
 ******************************************************************************/
uint16_t usb_hstd_chk_dev_addr (usb_utr_t * ptr, uint16_t addr)
{
    return g_usb_hstd_device_info[ptr->ip][addr][4];
}

/******************************************************************************
 * End of function usb_hstd_chk_dev_addr
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_pipe_to_epadr
 * Description     : Get the associated endpoint value of the specified pipe.
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 *              : uint16_t pipe  : Pipe number.
 * Return value    : uint8_t        : OK    : Endpoint nr + direction.
 *              :                : ERROR : Error.
 ******************************************************************************/
uint8_t usb_hstd_pipe_to_epadr (usb_utr_t * ptr, uint16_t pipe)
{
    uint16_t buffer = 0;
    uint16_t direp  = 0;
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(pipe);
    FSP_PARAMETER_NOT_USED(buffer);

    return (uint8_t) (direp);
}

/******************************************************************************
 * End of function usb_hstd_pipe_to_epadr
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_get_devsel
 * Description     : Get device address from pipe number
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 *               : uint16_t pipe  : Pipe number.
 * Return value    : uint16_t DEVSEL-bit status
 ******************************************************************************/
uint16_t usb_hstd_get_devsel (usb_utr_t * ptr, uint16_t pipe)
{
    uint16_t devsel = 0;
    uint16_t buffer = 0;

    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(pipe);
    FSP_PARAMETER_NOT_USED(buffer);

    return devsel;
}

/******************************************************************************
 * End of function usb_hstd_get_devsel
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_get_device_address
 * Description     : Get the device address associated with the specified pipe.
 * Arguments       : usb_utr_t    *ptr    : Pointer to usb_utr_t structure.
 *               : uint16_t     pipe    : Pipe number.
 * Return value    : uint16_t     DEVSEL-bit status
 ******************************************************************************/
uint16_t usb_hstd_get_device_address (usb_utr_t * ptr, uint16_t pipe)
{
    FSP_PARAMETER_NOT_USED(ptr);

    return g_usb_hstd_pipe[pipe].devaddr;
}

/******************************************************************************
 * End of function usb_hstd_get_device_address
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_make_pipe_reg_info
 * Description     : Make value for USB PIPE registers set value.
 * Arguments       : uint16_t ip_no        : USB Module no.(USB_IP0/USB_IP1)
 *              : uint16_t address      : USB Device address
 *              : usb_class_t usb_class : USB Device class(USB_HVND/USB_HCDC/USB_HHID/USB_HMSC/USB_HUB)
 *              : uint16_t speed        : USB speed
 *              : uint8_t *descriptor   : Address for End Point Descriptor
 *              : usb_pipe_table_reg_t *pipe_table_work : Address for Store PIPE reg set value.
 * Return value    : Pipe no (USB_PIPE1->USB_PIPE9:OK, USB_NULL:Error)
 ******************************************************************************/
uint8_t usb_hstd_make_pipe_reg_info (uint16_t               ip_no,
                                     uint16_t               address,
                                     uint16_t               usb_class,
                                     uint16_t               speed,
                                     uint8_t              * descriptor,
                                     usb_pipe_table_reg_t * pipe_table_work)
{
    uint8_t  pipe_no;
    uint16_t pipe_cfg;
    uint16_t pipe_maxp;
    uint16_t pipe_peri = USB_NULL;

    /* Check Endpoint descriptor */
    if (USB_DT_ENDPOINT != descriptor[USB_DEV_B_DESCRIPTOR_TYPE])
    {
        return USB_NULL;               /* Error */
    }

    /* set pipe configuration value */
    switch ((uint16_t) (descriptor[USB_EP_B_ATTRIBUTES] & USB_EP_TRNSMASK))
    {
        /* Bulk Endpoint */
        case USB_EP_BULK:
        {
            /* Set pipe configuration table */
            if (USB_EP_IN == (descriptor[USB_EP_B_ENDPOINTADDRESS] & USB_EP_DIRMASK))
            {
                /* IN(receive) */
                pipe_cfg = (uint16_t) (USB_TYPFIELD_BULK | USB_CFG_DBLB | USB_SHTNAKFIELD | USB_DIR_H_IN);
                pipe_no  = usb_hstd_get_pipe_no(ip_no, address, usb_class, USB_EP_BULK, USB_PIPE_DIR_IN);
            }
            else
            {
                /* OUT(send) */
                pipe_cfg = (uint16_t) (USB_TYPFIELD_BULK | USB_CFG_DBLB | USB_DIR_H_OUT);
                pipe_no  = usb_hstd_get_pipe_no(ip_no, address, usb_class, USB_EP_BULK, USB_PIPE_DIR_OUT);
            }

            break;
        }

        /* Interrupt Endpoint */
        case USB_EP_INT:
        {
            /* Set pipe configuration table */
            if (USB_EP_IN == (descriptor[USB_EP_B_ENDPOINTADDRESS] & USB_EP_DIRMASK))
            {
                /* IN(receive) */
                pipe_cfg = (uint16_t) (USB_TYPFIELD_INT | USB_DIR_H_IN);
                pipe_no  = usb_hstd_get_pipe_no(ip_no, address, usb_class, USB_EP_INT, USB_PIPE_DIR_IN);
            }
            else
            {
                /* OUT(send) */
                pipe_cfg = (uint16_t) (USB_TYPFIELD_INT | USB_DIR_H_OUT);
                pipe_no  = usb_hstd_get_pipe_no(ip_no, address, usb_class, USB_EP_INT, USB_PIPE_DIR_OUT);
            }

            /* Get value for Interval Error Detection Interval  */
            pipe_peri = usb_hstd_get_pipe_peri_value(speed, descriptor[USB_EP_B_INTERVAL]);

            break;
        }

        default:
        {
            return USB_NULL;           /* Error */
            break;
        }
    }

    /* Check Pipe no. */
    if (USB_NULL != pipe_no)
    {
        /* Endpoint number set */
        pipe_cfg = (uint16_t) (pipe_cfg | (descriptor[USB_EP_B_ENDPOINTADDRESS] & USB_EP_NUMMASK));

        /* set max packet size */
        pipe_maxp = (uint16_t) ((uint16_t) descriptor[USB_EP_B_MAXPACKETSIZE_L] | (address << USB_DEVADDRBIT));
        pipe_maxp = (uint16_t) (pipe_maxp | ((uint16_t) descriptor[USB_EP_B_MAXPACKETSIZE_H] << 8));

        /* Store PIPE reg set value. */
        pipe_table_work->pipe_cfg  = pipe_cfg;
        pipe_table_work->pipe_maxp = pipe_maxp;
        pipe_table_work->pipe_peri = pipe_peri;
    }

    return pipe_no;
}                                      /* eof usb_hstd_make_pipe_reg_info() */

/******************************************************************************
 * Function Name   : usb_hstd_clr_pipe_table
 * Description     : Clear pipe table.
 * Arguments       : uint16_t ip_no          : USB Module no.(USB_IP0/USB_IP1)
 *              : uint16_t device_address : USB Device address
 * Return value    : none
 ******************************************************************************/
void usb_hstd_clr_pipe_table (uint16_t ip_no, uint16_t device_address)
{
    uint8_t pipe_no;

    /* Search use pipe block */
    /* WAIT_LOOP */
    for (pipe_no = USB_MIN_PIPE_NO; pipe_no < (USB_MAX_PIPE_NO + 1); pipe_no++)
    {
        /* Check use block */
        if (USB_TRUE == g_usb_pipe_table[ip_no][pipe_no].use_flag)
        {
            /* Check USB Device address */
            if ((device_address << USB_DEVADDRBIT) ==
                (uint16_t) (g_usb_pipe_table[ip_no][pipe_no].pipe_maxp & USB_DEVSEL))
            {
                /* Clear use block */
                g_usb_pipe_table[ip_no][pipe_no].use_flag  = USB_FALSE;
                g_usb_pipe_table[ip_no][pipe_no].pipe_cfg  = USB_NULL;
                g_usb_pipe_table[ip_no][pipe_no].pipe_maxp = USB_NULL;
                g_usb_pipe_table[ip_no][pipe_no].pipe_peri = USB_NULL;
            }
        }
    }
}                                      /* eof usb_hstd_clr_pipe_table() */

/******************************************************************************
 * Function Name   : usb_hstd_set_pipe_reg
 * Description     : Set up USB registers to use specified pipe (Pipe unit).
 * Arguments       : usb_utr_t *ptr          : Pointer to usb_utr_t structure.
 *              : uint16_t pipe_no        : USB Pipe No.
 * Return value    : none
 ******************************************************************************/
void usb_hstd_set_pipe_reg (usb_utr_t * ptr, uint16_t pipe_no)
{
    uint16_t buf = 0;
    FSP_PARAMETER_NOT_USED(buf);
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(pipe_no);
}                                      /* eof usb_hstd_set_pipe_reg() */

/******************************************************************************
 * Function Name   : usb_hstd_get_pipe_no
 * Description     : Get PIPE No.
 * Arguments       : uint16_t ip_no     : USB Module no.(USB_IP0/USB_IP1)
 *              : uint16_t address   : USB Device address
 *              : uint16_t class     : USB Device class(USB_HVND/USB_HCDC/USB_HHID/USB_HMSC/USB_HUB)
 *              : uint8_t  type      : Transfer Type.(USB_EP_BULK/USB_EP_INT)
 *              : uint8_t  dir       : (USB_PIPE_DIR_IN/USB_PIPE_DIR_OUT)
 * Return value    : Pipe no (USB_PIPE1->USB_PIPE9:OK, USB_NULL:Error)
 ******************************************************************************/
uint8_t usb_hstd_get_pipe_no (uint16_t ip_no, uint16_t address, uint16_t usb_class, uint8_t type, uint8_t dir)
{
    uint8_t pipe_no = USB_NULL;
 #if defined(USB_CFG_HVND_USE)
    uint16_t pipe;
 #endif                                /* defined(USB_CFG_HVND_USE) */
 #if defined(USB_CFG_HMSC_USE)
    uint16_t side;
 #endif                                /* defined(USB_CFG_HMSC_USE) */
    switch (usb_class)
    {
        case USB_CLASS_INTERNAL_HVND:
        {
 #if defined(USB_CFG_HVND_USE)
            if (USB_EP_BULK == type)
            {
                /* BULK PIPE Loop */
                /* WAIT_LOOP */
                for (pipe = USB_BULK_PIPE_START; pipe < (USB_BULK_PIPE_END + 1); pipe++)
                {
                    if (USB_FALSE == g_usb_pipe_table[ip_no][pipe].use_flag)
                    {
                        /* Check Free pipe */
                        pipe_no = (uint8_t) pipe; /* Set Free pipe */
                        break;
                    }
                }
            }

            if (USB_EP_INT == type)
            {
                /* Interrupt PIPE Loop */
                /* WAIT_LOOP */
                for (pipe = USB_INT_PIPE_START; pipe < (USB_INT_PIPE_END + 1); pipe++)
                {
                    if (USB_FALSE == g_usb_pipe_table[ip_no][pipe].use_flag)
                    {
                        /* Check Free pipe */
                        pipe_no = (uint8_t) pipe; /* Set Free pipe */
                        break;
                    }
                }
            }
 #endif                                /* defined(USB_CFG_HVND_USE) */
            break;
        }

        case USB_CLASS_INTERNAL_HCDC:
        {
 #if defined(USB_CFG_HCDC_USE)
            if (USB_EP_BULK == type)
            {
                if (USB_PIPE_DIR_IN == dir)
                {
                    switch (address)
                    {
                        case 1:        /* Root port device1 */
                        case 2:        /* Hub downport device1 */
                        {
                            pipe_no = USB_CFG_HCDC_BULK_IN;
                            break;
                        }

                        case 3:        /* Hub downport device2 */
                        {
                            pipe_no = USB_CFG_HCDC_BULK_IN2;
                            break;
                        }

                        default:
                        {
                            break;
                        }
                    }
                }
                else
                {
                    switch (address)
                    {
                        case 1:        /* Root port device1 */
                        case 2:        /* Hub downport device1 */
                        {
                            pipe_no = USB_CFG_HCDC_BULK_OUT;
                            break;
                        }

                        case 3:        /* Hub downport device2 */
                        {
                            pipe_no = USB_CFG_HCDC_BULK_OUT2;
                            break;
                        }

                        default:
                        {
                            break;
                        }
                    }
                }
            }

            if (USB_EP_INT == type)
            {
                if (USB_PIPE_DIR_IN == dir)
                {
                    switch (address)
                    {
                        case 1:        /* Root port device1 */
                        case 2:        /* Hub downport device1 */
                        {
                            pipe_no = USB_CFG_HCDC_INT_IN;
                            break;
                        }

                        case 3:        /* Hub downport device2 */
                        {
                            pipe_no = USB_CFG_HCDC_INT_IN2;
                            break;
                        }

                        default:
                        {
                            break;
                        }
                    }
                }
            }
 #endif                                /* defined(USB_CFG_HCDC_USE) */
            break;
        }

        case USB_CLASS_INTERNAL_HHID:
        {
 #if defined(USB_CFG_HHID_USE)
            if (USB_EP_INT == type)
            {
                if (USB_PIPE_DIR_IN == dir)
                {
                    switch (address)
                    {
                        case 1:        /* Root port device1 */
                        case 2:        /* Hub downport device1 */
                        {
                            pipe_no = USB_CFG_HHID_INT_IN;
                            break;
                        }

                        case 3:        /* Hub downport device2 */
                        {
                            pipe_no = USB_CFG_HHID_INT_IN2;
                            break;
                        }

                        case 4:        /* Hub downport device3 */
                        {
                            pipe_no = USB_CFG_HHID_INT_IN3;
                            break;
                        }

                        default:
                        {
                            break;
                        }
                    }
                }
                else
                {
                    /* Check root port device1 or Hub downport device1 */
                    if ((1 == address) || (2 == address))
                    {
                        pipe_no = USB_CFG_HHID_INT_OUT;
                    }
                }
            }
 #endif                                /* defined(USB_CFG_HHID_USE) */
            break;
        }

        case USB_CLASS_INTERNAL_HMSC:
        {
 #if defined(USB_CFG_HMSC_USE)
            if (USB_EP_BULK == type)
            {
                /* Add USB IP no. for USB Device address */
                if (USB_IP1 == ip_no)
                {
                    address |= USBA_ADDRESS_OFFSET;
                }

                /* Get Strage drive no. */
                side = usb_hmsc_ref_drvno(address);

                /* Check Strage drive no. */
                if (side < USB_MAXSTRAGE)
                {
                    /* Calculate the pipe number corresponding to the drive number */
                    pipe_no = (uint8_t) (USB_PIPE1 + side);
                }
            }
 #endif                                /* defined(USB_CFG_HMSC_USE) */
            break;
        }

        case USB_HUB:
        {
            pipe_no = USB_HUB_PIPE;
            break;
        }

        default:
        {
            (void) ip_no;
            (void) address;
            (void) type;
            (void) dir;

            return USB_NULL;
            break;
        }
    }

    return pipe_no;
}                                      /* eof usb_hstd_get_pipe_no() */

/******************************************************************************
 * Function Name   : usb_hstd_get_pipe_peri_value
 * Description     : Get value to be set in PIPEPERI
 * Arguments       : uint16_t  speed     : USB speed
 *              : uint8_t   binterval : bInterval for ENDPOINT Descriptor.
 * Return value    : Value for set PIPEPERI
 ******************************************************************************/
uint16_t usb_hstd_get_pipe_peri_value (uint16_t speed, uint8_t binterval)
{
    uint16_t pipe_peri = USB_NULL;
    uint16_t work1;
    uint16_t work2;

    /* set interval counter */
    if (0 != binterval)
    {
        /* FS/LS interrupt */
        if (USB_HSCONNECT != speed)
        {
            /* The time of the FS/LS interrupt forwarding of the interval is specified by the unit of ms. */
            /* It is necessary to calculate to specify USB-IP by the n-th power of two. */
            /* The NAK rate of the control and the bulk transfer doesn't correspond. */
            work1 = binterval;
            work2 = 0;
            for ( ; work1 != 0; work2++)
            {
                work1 = (uint16_t) (work1 >> 1);
            }

            if (0 != work2)
            {
                /* Interval time */
                pipe_peri |= (uint16_t) (work2 - 1);
            }
        }
        else
        {
            /* Hi-Speed */
            if (8 >= binterval)
            {
                /* Interval time */
                pipe_peri = (uint16_t) (binterval - 1U);
            }
            else
            {
                /* Max Interval time */
                pipe_peri = (uint16_t) (USB_IITVFIELD);
            }
        }
    }

    return pipe_peri;
}                                      /* eof usb_hstd_get_pipe_peri_value() */

#endif  /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

/******************************************************************************
 * End  Of File
 ******************************************************************************/
