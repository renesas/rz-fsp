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
#include <string.h>

#include "inc/r_usb_typedef.h"
#include "inc/r_usb_extern.h"
#include "../hw/inc/r_usb_bitdefine.h"
#include "../hw/inc/r_usb_reg_access.h"

#if defined(USB_CFG_HCDC_USE)
 #include "r_usb_hcdc_api.h"

#endif                                 /* defined(USB_CFG_HCDC_USE) */

#if defined(USB_CFG_HHID_USE)
 #include "r_usb_hhid_api.h"

#endif                                 /* defined(USB_CFG_HHID_USE) */

#if defined(USB_CFG_HMSC_USE)
 #include "r_usb_hmsc_api.h"

#endif                                 /* defined(USB_CFG_HMSC_USE) */

#if defined(USB_CFG_PCDC_USE)
 #include "r_usb_pcdc_api.h"

#endif                                 /* defined(USB_CFG_PCDC_USE) */

#if defined(USB_CFG_PMSC_USE)
 #include "r_usb_pmsc_api.h"

#endif                                 /* defined(USB_CFG_PMSC_USE) */

#if ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE))
 #include "../hw/inc/r_usb_dmac.h"
#endif                                 /* ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE)) */

#if (BSP_CFG_RTOS == 2)
 #include "inc/r_usb_cstd_rtos.h"
#endif                                 /* #if (BSP_CFG_RTOS == 2) */

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #if USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE
  #define USB_RESPONCE_COUNTER_VALUE    (6000U)
 #endif                                /* USB_HOST_COMPLIANCE_MODE == USB_CFG_ENABLE */

 #if defined(USB_CFG_HVND_USE)
  #define USB_EP_PIPE_NUM               (9)
  #define USB_EP_TBL_WSIZE              ((USB_EPL * USB_EP_PIPE_NUM) + 1)
 #endif                                /* defined(USB_CFG_HVND_USE) */

 #define USB_VALUE_FFH                  (0xFF)
 #define USB_VALUE_3000                 (3000)
 #define USB_VALUE_100U                 (100U)

/******************************************************************************
 * Private global variables and functions
 ******************************************************************************/
static uint16_t  usb_shstd_clr_stall_request[USB_NUM_USBIP][5] USB_BUFFER_PLACE_IN_SECTION;
static usb_utr_t usb_shstd_clr_stall_ctrl[USB_NUM_USBIP] USB_BUFFER_PLACE_IN_SECTION;

 #if defined(USB_CFG_HVND_USE)
static void    usb_hvnd_configured(usb_utr_t * ptr, uint16_t dev_addr, uint16_t data2);
static void    usb_hvnd_detach(usb_utr_t * ptr, uint16_t dev_addr, uint16_t data2);
static void    usb_hvnd_enumeration(usb_clsinfo_t * mess, uint16_t ** table);
static void    usb_hvnd_pipe_info(usb_utr_t * p_utr, uint8_t * table, uint16_t speed, uint16_t length);
static uint8_t usb_hvnd_get_pipe_no(usb_utr_t * p_utr, uint8_t type, uint8_t dir);
static uint8_t usb_hvnd_make_pipe_reg_info(usb_utr_t            * p_utr,
                                           uint16_t               address,
                                           uint16_t               speed,
                                           uint8_t              * descriptor,
                                           usb_pipe_table_reg_t * pipe_table_work);
usb_er_t usb_hvnd_set_pipe_registration(usb_utr_t * ptr, uint16_t dev_addr);

 #endif                                /* defined(USB_CFG_HVND_USE) */
 #if USB_IP_EHCI_OHCI == 0
static void usb_hstd_set_submitutr(usb_utr_t * ptr);
static void usb_hstd_set_retransfer(usb_utr_t * ptr, uint16_t pipe);

 #endif

 #if (BSP_CFG_RTOS == 0)

  #if USB_IP_EHCI_OHCI == 0
static usb_cb_t usb_shstd_clr_stall_call;
static void usb_hstd_clr_stall_result(usb_utr_t * ptr, uint16_t data1, uint16_t data2);

  #endif
 #endif                                /* (BSP_CFG_RTOS == 0) */

/******************************************************************************
 * Exported global variables (to be accessed by other files)
 ******************************************************************************/

/* Device driver (registration) */
usb_hcdreg_t g_usb_hstd_device_drv[USB_NUM_USBIP][USB_MAXDEVADDR + 1U];

/* Root port, status, config num, interface class, speed, */
volatile uint16_t g_usb_hstd_device_info[USB_NUM_USBIP][USB_MAXDEVADDR + 1U][8U];
uint16_t          g_usb_hstd_remort_port[USB_NUM_USBIP];

/* Control transfer stage management */
uint16_t g_usb_hstd_ctsq[USB_NUM_USBIP];

/* Manager mode */
uint16_t g_usb_hstd_mgr_mode[USB_NUM_USBIP];

/* DEVSEL & DCPMAXP (Multiple device) */
uint16_t g_usb_hstd_dcp_register[USB_NUM_USBIP][USB_MAXDEVADDR + 1U];

/* Device address */
uint16_t g_usb_hstd_device_addr[USB_NUM_USBIP];

/* Reset handshake result */
uint16_t g_usb_hstd_device_speed[USB_NUM_USBIP];

/* Device driver number */
uint16_t g_usb_hstd_device_num[USB_NUM_USBIP];

/* Ignore count */
uint16_t g_usb_hstd_ignore_cnt[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1U];

/* USB data transfer */
/* PIPEn Buffer counter */
uint32_t g_usb_hstd_data_cnt[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1U];
uint32_t g_usb_hstd_data_cnt_pipe0[USB_NUM_USBIP];

/* PIPEn Buffer pointer(8bit) */
uint8_t * gp_usb_hstd_data_ptr[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1U];

/* Message pipe */
usb_utr_t * g_p_usb_hstd_pipe[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1U];

/* Hi-speed enable */
uint16_t         g_usb_hstd_hs_enable[USB_NUM_USBIP];
usb_ctrl_trans_t g_usb_ctrl_request[USB_NUM_USBIP][USB_MAXDEVADDR + 1] USB_BUFFER_PLACE_IN_SECTION;

 #if BSP_CFG_RTOS == 0
uint16_t g_usb_hstd_pipe_request[USB_NUM_USBIP][USB_MAX_PIPE_NO + 1U];
 #endif                                /* BSP_CFG_RTOS == 0 */

 #if defined(USB_CFG_HVND_USE)

/* Target Peripheral List */
const uint16_t g_usb_apl_devicetpl[] =
{
    USB_CFG_TPLCNT,                    /* Number of list */
    0,                                 /* Reserved */
    USB_CFG_TPL                        /* Vendor ID, Product ID */
};
 #endif /* defined(USB_CFG_HVND_USE) */

 #if (BSP_CFG_RTOS == 2)
usb_hdl_t g_usb_hstd_sus_res_task_id[USB_NUM_USBIP];
 #endif                                /*  #if (BSP_CFG_RTOS == 2) */

/******************************************************************************
 * Renesas USB Host Driver functions
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_dev_descriptor
 * Description     : Returns buffer header pointer to fetch device descriptor.
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 * Return          : uint8_t *      : Device Descriptor Pointer
 ******************************************************************************/
uint8_t * usb_hstd_dev_descriptor (usb_utr_t * ptr)
{
    return (uint8_t *) &g_usb_hstd_device_descriptor[ptr->ip];
}

/******************************************************************************
 * End of function usb_hstd_dev_descriptor
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_con_descriptor
 * Description     : Returns buffer header pointer that includes the configuration
 *               : descriptor.
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 * Return          : uint8_t *      : Configuration Descriptor Pointer
 ******************************************************************************/
uint8_t * usb_hstd_con_descriptor (usb_utr_t * ptr)
{
    return (uint8_t *) &g_usb_hstd_config_descriptor[ptr->ip];
}

/******************************************************************************
 * End of function usb_hstd_con_descriptor
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_transfer_start_req
 * Description     : Send a request for data transfer to HCD (Host Control Driver)
 *               : using the specified pipe.
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 * Return          : usb_er_t       : USB_OK/USB_QOVR/USB_ERROR
 ******************************************************************************/
usb_er_t usb_hstd_transfer_start_req (usb_utr_t * ptr)
{
    usb_er_t err;
    uint16_t pipenum;
    uint16_t devsel;
 #if (BSP_CFG_RTOS == 0)
    uint16_t connect_inf = 0;
 #else                                 /* (BSP_CFG_RTOS == 0) */
    usb_utr_t * p_tran_data;
 #endif /* BSP_CFG_RTOS == 0 */

    pipenum = ptr->keyword;

    if (USB_PIPE0 == pipenum)
    {
        devsel = (uint16_t) (ptr->p_setup[4] << USB_DEVADDRBIT);
    }
    else
    {
        /* Get device address from pipe number */
        devsel = usb_hstd_get_devsel(ptr, pipenum);
    }

    if ((USB_DEVICE_0 == devsel) && (USB_PIPE0 != pipenum))
    {
        USB_PRINTF1("### usb_hstd_transfer_start_req not configured %x\n", devsel);

        return USB_ERROR;
    }

    ptr->msghead = (usb_mh_t) USB_NULL;
    ptr->msginfo = USB_MSG_HCD_SUBMITUTR;

    if (USB_MAX_PIPE_NO < pipenum)
    {
        return USB_ERROR;
    }

 #if (BSP_CFG_RTOS == 0)
    if (USB_ON == g_usb_hstd_pipe_request[ptr->ip][pipenum])
    {
        return USB_QOVR;
    }

    /* Pipe Transfer Process check */
    if (NULL != g_p_usb_hstd_pipe[ptr->ip][pipenum])
    {
        /* Check PIPE TYPE */
        if (usb_cstd_get_pipe_type(ptr, pipenum) != USB_TYPFIELD_ISO)
        {
            USB_PRINTF1("### usb_hstd_transfer_start_req overlaps %d\n", pipenum);

            return USB_QOVR;
        }
    }

    /* Get device speed from device address */
  #if USB_IP_EHCI_OHCI == 0
    connect_inf = usb_hstd_get_dev_speed(ptr, devsel);
    if (USB_NOCONNECT == connect_inf)
    {
        USB_PRINTF1("### usb_hstd_transfer_start_req not connect %x\n", devsel);

        return USB_ERROR;
    }

  #else
    FSP_PARAMETER_NOT_USED(connect_inf);
  #endif                               /* USB_IP_EHCI_OHCI == 0 */

    /* Send message */
    err = USB_SND_MSG(USB_HCD_MBX, (usb_msg_t *) ptr);
    if (USB_OK == err)
    {
        g_usb_hstd_pipe_request[ptr->ip][pipenum] = USB_ON;
    }
    else
    {
        USB_PRINTF1("### usb_hstd_transfer_start_req snd_msg error (%ld)\n", err);
    }

 #else                                 /* (BSP_CFG_RTOS == 0) */
    p_tran_data = (usb_utr_t *) pvPortMalloc(sizeof(usb_utr_t));
    if (NULL == p_tran_data)
    {
        return USB_ERROR;
    }

    *p_tran_data = *ptr;
    if (0 != ptr->p_setup)
    {
        p_tran_data->setup_data[0] = ptr->p_setup[0];
        p_tran_data->setup_data[1] = ptr->p_setup[1];
        p_tran_data->setup_data[2] = ptr->p_setup[2];
        p_tran_data->setup_data[3] = ptr->p_setup[3];
        p_tran_data->setup_data[4] = ptr->p_setup[4];
        p_tran_data->p_setup       = (uint16_t *) &p_tran_data->setup_data;
    }

    p_tran_data->cur_task_hdl = xTaskGetCurrentTaskHandle();

    /* Send message */
    err = USB_SND_MSG(USB_HCD_MBX, (usb_msg_t *) p_tran_data);
    if (USB_OK != err)
    {
        vPortFree(p_tran_data);
    }
 #endif                                /* (BSP_CFG_RTOS == 0) */

    return err;
}

/******************************************************************************
 * End of function usb_hstd_transfer_start_req
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_device_resume
 * Description     : Send request for RESUME signal output to USB device to MGR task.
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 * Argument        : uint16_t  devaddr    : Device Address
 * Return          : none
 ******************************************************************************/
void usb_hstd_device_resume (usb_utr_t * ptr, uint16_t devaddr)
{
    usb_hstd_mgr_snd_mbx(ptr, (uint16_t) USB_MSG_HCD_RESUME, devaddr, (uint16_t) 0U);
}

/******************************************************************************
 * End of function usb_hstd_device_resume
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_hcd_snd_mbx
 * Description     : Send specified message to HCD (Host Control Driver) task.
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 *               : uint16_t  msginfo : Message info..
 *               : uint16_t  dat     : Pipe no.
 *               : uint16_t  *adr    : Address.
 *               : usb_cb_t  callback: Callback function pointer.
 * Return          : usb_er_t          : USB_OK etc.
 ******************************************************************************/
usb_er_t usb_hstd_hcd_snd_mbx (usb_utr_t * ptr, uint16_t msginfo, uint16_t dat, uint16_t * adr, usb_cb_t callback)
{
    usb_mh_t        p_blf;
    usb_er_t        err;
    usb_er_t        err2;
    usb_hcdinfo_t * hp;

    /* Get memory pool blk */
    err = USB_PGET_BLK(USB_HCD_MPL, &p_blf);
    if (USB_OK == err)
    {
        hp            = (usb_hcdinfo_t *) p_blf;
        hp->msghead   = (usb_mh_t) USB_NULL;
        hp->msginfo   = msginfo;
        hp->keyword   = dat;
        hp->p_tranadr = adr;
        hp->complete  = callback;
        hp->ipp       = ptr->ipp;
        hp->ip        = ptr->ip;
 #if (BSP_CFG_RTOS == 2)
        hp->cur_task_hdl = ptr->cur_task_hdl;
 #endif                                /* #if (BSP_CFG_RTOS == 2) */

        /* Send message */
        err = USB_SND_MSG(USB_HCD_MBX, (usb_msg_t *) hp);
        if (USB_OK != err)
        {
            USB_PRINTF1("### hHcdSndMbx snd_msg error (%ld)\n", err);
            err2 = USB_REL_BLK(USB_HCD_MPL, (usb_mh_t) hp);
            if (USB_OK != err2)
            {
                USB_PRINTF1("### hHcdSndMbx rel_blk error (%ld)\n", err2);
            }
        }
    }
    else
    {
        /* Error */
        /* WAIT_LOOP */
        while (1)
        {
            /* error */
        }
    }

    return err;
}

/******************************************************************************
 * End of function usb_hstd_hcd_snd_mbx
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_mgr_snd_mbx
 * Description     : Send the message to MGR(Manager) task
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 *               : uint16_t msginfo  : Message info.
 *               : uint16_t dat      : Port no.
 *               : uint16_t res      : Result
 * Return          : none
 ******************************************************************************/
void usb_hstd_mgr_snd_mbx (usb_utr_t * ptr, uint16_t msginfo, uint16_t dat, uint16_t res)
{
    usb_mh_t        p_blf;
    usb_er_t        err;
    usb_mgrinfo_t * mp;

    /* Get memory pool blk */
    err = USB_PGET_BLK(USB_MGR_MPL, &p_blf);
    if (USB_OK == err)
    {
        mp          = (usb_mgrinfo_t *) p_blf;
        mp->msghead = (usb_mh_t) USB_NULL;
        mp->msginfo = msginfo;
        mp->keyword = dat;
        mp->result  = res;
        mp->ipp     = ptr->ipp;
        mp->ip      = ptr->ip;
 #if (BSP_CFG_RTOS == 2)
        mp->cur_task_hdl = ptr->cur_task_hdl;
 #endif                                /* #if (BSP_CFG_RTOS == 2)*/

        /* Send message */
        err = USB_SND_MSG(USB_MGR_MBX, (usb_msg_t *) mp);
        if (USB_OK != err)
        {
            USB_REL_BLK(USB_MGR_MPL, p_blf);
            USB_PRINTF1("### hMgrSndMbx snd_msg error (%ld)\n", err);
        }
    }
    else
    {
        /* Error */
        /* WAIT_LOOP */
        while (1)
        {
            /* error */
        }
    }
}

/******************************************************************************
 * End of function usb_hstd_mgr_snd_mbx
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_hcd_rel_mpl
 * Description     : Release the secured memory block.
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 *               : uint16_t n        : Error no.
 * Return          : none
 ******************************************************************************/
void usb_hstd_hcd_rel_mpl (usb_utr_t * ptr, uint16_t n)
{
    usb_er_t err;

    (void) n;

    /* Memory Pool Release */
    err = USB_REL_BLK(USB_HCD_MPL, (usb_mh_t) ptr);
    if (USB_OK != err)
    {
        USB_PRINTF1("### USB HCD rel_blk error: %d\n", n);
    }
}

/******************************************************************************
 * End of function usb_hstd_hcd_rel_mpl
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_suspend
 * Description     : Request suspend for USB device.
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 * Return          : none
 ******************************************************************************/
void usb_hstd_suspend (usb_utr_t * ptr)
{
    usb_hcdinfo_t * hp;

    /* Control transfer idle stage ? */
    if (USB_IDLEST == g_usb_hstd_ctsq[ptr->ip])
    {
        /* USB suspend process */
        usb_hstd_suspend_process(ptr);
        usb_hstd_chk_clk(ptr, (uint16_t) USB_SUSPENDED); /* Check clock */
        hp = (usb_hcdinfo_t *) ptr;                      /* Callback */
        (hp->complete)(ptr, USB_NULL, ptr->msginfo);
    }
    else
    {
        /* 1ms wait */
        usb_cpu_delay_xms((uint16_t) 1);

        /* Change device state request */
        usb_hstd_hcd_snd_mbx(ptr, ptr->msginfo, USB_NULL, (uint16_t *) 0, &usb_hstd_status_result);
    }
}

/******************************************************************************
 * End of function usb_hstd_suspend
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_clr_feature
 * Description     : Send ClearFeature command to the connected USB device.
 * Arguments       : usb_utr_t *ptr : Pointer to usb_utr_t structure.
 *               : uint16_t addr     : Device address.
 *               : uint16_t epnum    : Endpoint number.
 *               : usb_cb_t complete : Callback function.
 * Return value    : uint16_t          : Error info.
 ******************************************************************************/
usb_er_t usb_hstd_clr_feature (usb_utr_t * ptr, uint16_t addr, uint16_t epnum, usb_cb_t complete)
{
    usb_er_t ret_code;

    if (USB_VALUE_FFH == epnum)
    {
        /* ClearFeature(Device) */
        usb_shstd_clr_stall_request[ptr->ip][0] = USB_CLEAR_FEATURE | USB_HOST_TO_DEV | USB_STANDARD | USB_DEVICE;
        usb_shstd_clr_stall_request[ptr->ip][1] = USB_DEV_REMOTE_WAKEUP;
        usb_shstd_clr_stall_request[ptr->ip][2] = (uint16_t) 0x0000;
    }
    else
    {
        /* ClearFeature(endpoint) */
        usb_shstd_clr_stall_request[ptr->ip][0] = USB_CLEAR_FEATURE | USB_HOST_TO_DEV | USB_STANDARD | USB_ENDPOINT;
        usb_shstd_clr_stall_request[ptr->ip][1] = USB_ENDPOINT_HALT;
        usb_shstd_clr_stall_request[ptr->ip][2] = epnum;
    }

    usb_shstd_clr_stall_request[ptr->ip][3] = (uint16_t) 0x0000;
    usb_shstd_clr_stall_request[ptr->ip][4] = addr;

    usb_shstd_clr_stall_ctrl[ptr->ip].p_tranadr = USB_NULL;
    usb_shstd_clr_stall_ctrl[ptr->ip].complete  = complete;
    usb_shstd_clr_stall_ctrl[ptr->ip].tranlen   = 0;
    usb_shstd_clr_stall_ctrl[ptr->ip].keyword   = USB_PIPE0;
    usb_shstd_clr_stall_ctrl[ptr->ip].p_setup   = usb_shstd_clr_stall_request[ptr->ip];
    usb_shstd_clr_stall_ctrl[ptr->ip].segment   = USB_TRAN_END;

    usb_shstd_clr_stall_ctrl[ptr->ip].ip  = ptr->ip;
    usb_shstd_clr_stall_ctrl[ptr->ip].ipp = ptr->ipp;

 #if USB_IP_EHCI_OHCI == 0
    ret_code = usb_hstd_transfer_start_req(&usb_shstd_clr_stall_ctrl[ptr->ip]);
 #else
    ret_code = usb_hstd_transfer_start(&usb_shstd_clr_stall_ctrl[ptr->ip]);
 #endif

 #if (BSP_CFG_RTOS == 2)
    if (USB_QOVR == ret_code)
    {
        /** Submit overlap error **/
        /** Retry **/
        /* WAIT_LOOP */
        do
        {
            usb_cpu_delay_xms((uint16_t) 2);
            ret_code = usb_hstd_transfer_start(&usb_shstd_clr_stall_ctrl[ptr->ip]);
        } while (USB_QOVR == ret_code);
    }

    if (USB_OK == ret_code)
    {
        ret_code = class_trans_wait_tmo(ptr, (uint16_t) USB_VALUE_3000);
    }
 #endif                                /* #if (BSP_CFG_RTOS == 2) */
    return ret_code;
}

/******************************************************************************
 * End of function usb_hstd_clr_feature
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_clr_stall
 * Description     : Clear Stall
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 *               : uint16_t pipe        : Pipe number.
 *               : usb_cb_t complete    : Callback function
 * Return value    : uint16_t             : Error info.
 ******************************************************************************/
usb_er_t usb_hstd_clr_stall (usb_utr_t * ptr, uint16_t pipe, usb_cb_t complete)
{
    usb_er_t err;
    uint16_t epnum;
    uint16_t dev_addr;

    epnum    = usb_hstd_get_epnum(pipe);
    epnum   |= usb_hstd_get_pipe_dir(pipe);
    dev_addr = usb_hstd_get_dev_addr(pipe);

    err = usb_hstd_clr_feature(ptr, dev_addr, epnum, complete);

    return err;
}                                      /* End of function usbh1_hstd_clear_stall() */

/******************************************************************************
 * End of function usb_hstd_clr_stall
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_class_request_complete
 * Description     : Class request transfer complete
 * Arguments       : usb_utr_t *mess  : Pointer to usb_utr_t structure.
 *               : uint16_t  data1  : Not used.
 *               : uint16_t  data2  : Not used.
 * Return          : none
 ******************************************************************************/
void usb_class_request_complete (usb_utr_t * mess, uint16_t data1, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    (void) data1;
    (void) data2;

    if (USB_CTRL_END == mess->status)        /* Check usb receive status */
    {
        ctrl.status = USB_SETUP_STATUS_ACK;
    }
    else if (USB_DATA_STALL == mess->status) /* Check usb receive status */
    {
        ctrl.status = USB_SETUP_STATUS_STALL;
    }
    else
    {
        ctrl.status = USB_ERROR;
    }

    ctrl.type                 = USB_CLASS_REQUEST;
    ctrl.module_number        = mess->ip; /* Module number setting */
    ctrl.setup.request_type   = mess->p_setup[0];
    ctrl.pipe                 = USB_PIPE0;
    ctrl.setup.request_value  = mess->p_setup[1];
    ctrl.setup.request_index  = mess->p_setup[2];
    ctrl.setup.request_length = mess->p_setup[3];
    ctrl.device_address       = (uint8_t) mess->p_setup[4];
    ctrl.data_size            = ctrl.setup.request_length - g_usb_hstd_data_cnt_pipe0[mess->ip];
 #if (BSP_CFG_RTOS == 2)
    ctrl.p_data = (void *) mess->cur_task_hdl;
 #endif                                                /* #if (BSP_CFG_RTOS == 2) */

    usb_set_event(USB_STATUS_REQUEST_COMPLETE, &ctrl); /* Set Event()  */
}

/******************************************************************************
 * End of function usb_class_request_complete
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_driver_registration
 * Description     : The HDCD information registered in the class driver structure
 *               : is registered in HCD.
 * Arguments       : usb_utr_t *ptr           : Pointer to usb_utr_t structure.
 *               : usb_hcdreg_t *callback   : Pointer to usb_hcdreg_t structure
 * Return          : none
 ******************************************************************************/
void usb_hstd_driver_registration (usb_utr_t * ptr, usb_hcdreg_t * callback)
{
    usb_hcdreg_t * driver;

    if (g_usb_hstd_device_num[ptr->ip] <= USB_MAXDEVADDR)
    {
        driver = &g_usb_hstd_device_drv[ptr->ip][g_usb_hstd_device_num[ptr->ip]];

        driver->rootport   = USB_NOPORT;           /* Root port */
        driver->devaddr    = USB_NODEVICE;         /* Device address */
        driver->devstate   = USB_DETACHED;         /* Device state */
        driver->ifclass    = callback->ifclass;    /* Interface Class */
        driver->p_tpl      = callback->p_tpl;      /* Target peripheral list */
        driver->classinit  = callback->classinit;  /* Driver init */
        driver->classcheck = callback->classcheck; /* Driver check */
        driver->devconfig  = callback->devconfig;  /* Device configured */
        driver->devdetach  = callback->devdetach;  /* Device detach */
        driver->devsuspend = callback->devsuspend; /* Device suspend */
        driver->devresume  = callback->devresume;  /* Device resume */
        /* Initialized device driver */
        (*driver->classinit)(ptr, driver->devaddr, (uint16_t) USB_NO_ARG);
        g_usb_hstd_device_num[ptr->ip]++;
        USB_PRINTF1("*** Registration driver 0x%02x\n", driver->ifclass);
    }
}

/******************************************************************************
 * End of function usb_hstd_driver_registration
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_driver_release
 * Description     : Release the Device Class Driver.
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 *               : uint8_t   devclass   : Interface class
 * Return          : none
 ******************************************************************************/
void usb_hstd_driver_release (usb_utr_t * ptr, uint8_t devclass)
{
    usb_hcdreg_t * driver;
    uint16_t       i;
    uint16_t       flg;

    if (USB_IFCLS_NOT == devclass)
    {
        /* Device driver number */
        g_usb_hstd_device_num[ptr->ip] = 0;
    }
    else
    {
        flg = 0U;

        /* WAIT_LOOP */
        for (i = 0U; (i < (USB_MAXDEVADDR + 1U)) && (0U == flg); i++)
        {
            driver = &g_usb_hstd_device_drv[ptr->ip][i];
            if (driver->ifclass == devclass)
            {
                driver->rootport = USB_NOPORT;   /* Root port */
                driver->devaddr  = USB_NODEVICE; /* Device address */
                driver->devstate = USB_DETACHED; /* Device state */

                /* Interface Class : NO class */
                driver->ifclass = (uint16_t) USB_IFCLS_NOT;

                g_usb_hstd_device_num[ptr->ip]--;
                USB_PRINTF1("*** Release class %d driver ***\n", devclass);
                flg = 1U;              /* break; */
            }
        }
    }
}

/******************************************************************************
 * End of function usb_hstd_driver_release
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_set_pipe_info
 * Description     : Copy information of pipe information table from source
 *               :  (2nd argument) to destination (1st argument)
 * Argument        : usb_pipe_table_t *dst_ep_tbl      : DEF_EP table pointer(destination)
 *               : usb_pipe_table_t *src_ep_tbl      : DEF_EP table pointer(source)
 * Return          : none
 ******************************************************************************/
void usb_hstd_set_pipe_info (uint16_t ip_no, uint16_t pipe_no, usb_pipe_table_reg_t * src_ep_tbl)
{
    g_usb_pipe_table[ip_no][pipe_no].use_flag  = USB_TRUE;
    g_usb_pipe_table[ip_no][pipe_no].pipe_cfg  = src_ep_tbl->pipe_cfg;
    g_usb_pipe_table[ip_no][pipe_no].pipe_maxp = src_ep_tbl->pipe_maxp;
    g_usb_pipe_table[ip_no][pipe_no].pipe_peri = src_ep_tbl->pipe_peri;
}

/******************************************************************************
 * End of function usb_hstd_set_pipe_info
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_return_enu_mgr
 * Description     : Continuous enumeration is requested to MGR task (API for nonOS)
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 *               : uint16_t cls_result  : class check result
 * Return          : none
 ******************************************************************************/
void usb_hstd_return_enu_mgr (usb_utr_t * ptr, uint16_t cls_result)
{
    g_usb_hstd_check_enu_result[ptr->ip] = cls_result;
    usb_hstd_mgr_snd_mbx(ptr, USB_MSG_MGR_SUBMITRESULT, USB_PIPE0, USB_CTRL_END);
}

/******************************************************************************
 * End of function usb_hstd_return_enu_mgr
 ******************************************************************************/

 #if (USB_UT_MODE == 0)

/******************************************************************************
 * Function Name   : usb_hstd_change_device_state
 * Description     : Request to change the status of the connected USB Device
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 *               : usb_cb_t complete    : callback function pointer
 *               : uint16_t msginfo     : Message Info
 *               : uint16_t member      : Device address/pipe number
 * Return          : usb_err_t            : USB_OK etc
 ******************************************************************************/
usb_er_t usb_hstd_change_device_state (usb_utr_t * ptr, usb_cb_t complete, uint16_t msginfo, uint16_t member)
{
    usb_mh_t        p_blf;
    usb_er_t        err;
    usb_er_t        err2;
    usb_hcdinfo_t * hp;

    switch (msginfo)
    {
        /* USB_MSG_HCD_CLR_STALL */
        case USB_DO_CLR_STALL:
        {
            err = usb_hstd_hcd_snd_mbx(ptr, USB_MSG_HCD_CLR_STALL, member, (uint16_t *) 0, complete);
            break;
        }

        /* USB_MSG_HCD_SQTGLBIT */
        case USB_DO_SET_SQTGL:
        {
            err = usb_hstd_hcd_snd_mbx(ptr, USB_MSG_HCD_SETSEQBIT, member, (uint16_t *) 0, complete);
            break;
        }

        /* USB_MSG_HCD_CLRSEQBIT */
        case USB_DO_CLR_SQTGL:
        {
            err = usb_hstd_hcd_snd_mbx(ptr, USB_MSG_HCD_CLRSEQBIT, member, (uint16_t *) 0, complete);
            break;
        }

        default:
        {
            /* Get memory pool blk */
            err = USB_PGET_BLK(USB_MGR_MPL, &p_blf);
            if (FSP_SUCCESS == err)
            {
                USB_PRINTF2("*** member%d : msginfo=%d ***\n", member, msginfo);
                hp           = (usb_hcdinfo_t *) p_blf;
                hp->msghead  = (usb_mh_t) USB_NULL;
                hp->msginfo  = msginfo;
                hp->keyword  = member;
                hp->complete = complete;

                hp->ipp = ptr->ipp;
                hp->ip  = ptr->ip;
  #if (BSP_CFG_RTOS == 2)
                hp->cur_task_hdl = xTaskGetCurrentTaskHandle();
  #endif                               /* #if (BSP_CFG_RTOS == 2) */

                /* Send message */
                err = USB_SND_MSG(USB_MGR_MBX, (usb_msg_t *) p_blf);
                if (FSP_SUCCESS != err)
                {
                    USB_PRINTF1("### hMgrChangeDeviceState snd_msg error (%ld)\n", err);
                    err2 = USB_REL_BLK(USB_MGR_MPL, (usb_mh_t) p_blf);
                    if (FSP_SUCCESS != err2)
                    {
                        USB_PRINTF1("### hMgrChangeDeviceState rel_blk error (%ld)\n", err2);
                    }
                }
            }
            else
            {
                /* Error */
                /* WAIT_LOOP */
  #ifdef USB_DEBUG_ON
                while (1)
                {
                    /* error */
                }
  #endif
            }

            break;
        }
    }

    return err;
}

/******************************************************************************
 * End of function usb_hstd_change_device_state
 ******************************************************************************/
 #endif                                /* #if (USB_UT_MODE == 0) */

/***************************************************************************//**
 * @brief Start HCD(Host Control Driver) task
 *
 * @retval FSP_SUCCESS         Success.
 * @retval FSP_ERR_USB_FAILED  Failed in acquiring version information.
 ******************************************************************************/
fsp_err_t usb_hstd_hcd_open (usb_utr_t * ptr)
{
    static uint8_t is_init = USB_NO;
    uint16_t       i;
    uint16_t       j;
    fsp_err_t      err = FSP_SUCCESS;

    if (USB_MAXDEVADDR < USB_DEVICEADDR)
    {
        USB_PRINTF0("Device address error\n");

        /* >yes no process */
        return FSP_ERR_USB_FAILED;
    }

    /* Global Init */
    if (USB_NO == is_init)
    {
        memset((void *) &usb_shstd_clr_stall_ctrl[0], 0, sizeof(usb_utr_t));
        memset((void *) &usb_shstd_clr_stall_request[0], 0, (5 * 2));
 #if (USB_NUM_USBIP == 2)
        memset((void *) &usb_shstd_clr_stall_ctrl[1], 0, sizeof(usb_utr_t));
        memset((void *) &usb_shstd_clr_stall_request[1], 0, (5 * 2));
 #endif
        is_init = USB_YES;
    }

    /* WAIT_LOOP */
    for (i = 0; i < (USB_MAXDEVADDR + 1); i++)
    {
        memset((void *) &g_usb_hstd_device_drv[ptr->ip][i], 0, sizeof(usb_hcdreg_t));
        memset((void *) &g_usb_hstd_device_info[ptr->ip][i], 0, (8 * 2));
        g_usb_hstd_dcp_register[ptr->ip][i] = 0;
        memset((void *) &g_usb_ctrl_request[ptr->ip][i], 0, sizeof(usb_ctrl_trans_t));
    }

    /* WAIT_LOOP */
    for (i = 0; i < (USB_MAX_PIPE_NO + 1); i++)
    {
        g_usb_hstd_data_cnt[ptr->ip][i]   = 0;
        gp_usb_hstd_data_ptr[ptr->ip][i]  = 0;
        g_usb_hstd_ignore_cnt[ptr->ip][i] = 0;
 #if (BSP_CFG_RTOS == 0)
        g_usb_hstd_pipe_request[ptr->ip][i] = 0;
 #endif                                /* (BSP_CFG_RTOS == 0) */
    }

    g_usb_hstd_device_addr[ptr->ip]  = 0;
    g_usb_hstd_device_speed[ptr->ip] = 0;
    g_usb_hstd_device_num[ptr->ip]   = 0;

    /* Control transfer stage management */
    g_usb_hstd_ctsq[ptr->ip] = USB_IDLEST;

    g_usb_hstd_remort_port[ptr->ip] = USB_DEFAULT;

    j = ptr->ip;

    /* WAIT_LOOP */
    for (i = USB_PIPE0; i <= USB_MAX_PIPE_NO; i++)
    {
        g_p_usb_hstd_pipe[j][i] = (usb_utr_t *) USB_NULL;
    }

    USB_PRINTF0("*** Install USB-HCD ***\n");

    usb_cstd_set_task_pri(USB_HCD_TSK, USB_PRI_1);

    return err;
}

/******************************************************************************
 * End of function usb_hstd_hcd_open
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_dummy_function
 * Description     : Dummy function
 * Arguments       : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 *               : uint16_t data1    : Not used.
 *               : uint16_t data2    : Not used.
 * Return value    : none
 ******************************************************************************/
void usb_hstd_dummy_function (usb_utr_t * ptr, uint16_t data1, uint16_t data2)
{
    (void) *ptr;
    (void) data1;
    (void) data2;

    /* None */
}

/******************************************************************************
 * End of function usb_hstd_dummy_function
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_suspend_complete
 * Description     : usb_hstd_change_device_state callback (Suspend)
 * Arguments       : usb_utr_t *ptr   : Pointer to usb_utr_t structure.
 *               : uint16_t data1   : Not used.
 *               : uint16_t data2   : Not used.
 * Return value    : none
 ******************************************************************************/
void usb_hstd_suspend_complete (usb_utr_t * ptr, uint16_t data1, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;
    usb_cfg_t         * p_cfg = NULL;

    (void) data1;
    (void) data2;

 #if (BSP_CFG_RTOS == 0)
    g_usb_change_device_state[ptr->ip] &= (uint16_t) (~(1 << USB_STATUS_SUSPEND));
 #endif                                /* BSP_CFG_RTOS == 0 */

    ctrl.module_number  = ptr->ip;     /* USB Module Number */
    ctrl.device_address = 1;           /* Device Address Number */
 #if (BSP_CFG_RTOS == 2)
    ctrl.p_data = (void *) ptr->cur_task_hdl;
 #endif                                /* #if (BSP_CFG_RTOS == 2) */

    if (ptr->ip)
    {
 #ifdef VECTOR_NUMBER_USB_HI
        p_cfg = (usb_cfg_t *) R_FSP_IsrContextGet((IRQn_Type) VECTOR_NUMBER_USB_HI);
 #endif
    }
    else
    {
 #ifdef VECTOR_NUMBER_USB_HI
        p_cfg = (usb_cfg_t *) R_FSP_IsrContextGet((IRQn_Type) VECTOR_NUMBER_USB_HI);
 #endif
    }

 #if defined(VECTOR_NUMBER_USB_HI)
    ctrl.p_context = p_cfg->p_context;
 #else
    FSP_PARAMETER_NOT_USED(p_cfg);
 #endif

    usb_set_event(USB_STATUS_SUSPEND, &ctrl);
}

/******************************************************************************
 * End of function usb_hstd_suspend_complete
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_resume_complete
 * Description     : usb_hstd_change_device_state callback (Resume)
 * Arguments       : usb_utr_t *ptr   : Pointer to usb_utr_t structure.
 *               : uint16_t data1   : Not used.
 *               : uint16_t data2   : Not used.
 * Return value    : none
 ******************************************************************************/
void usb_hstd_resume_complete (usb_utr_t * ptr, uint16_t data1, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;
    usb_cfg_t         * p_cfg = NULL;

    (void) data1;
    (void) data2;

 #if (BSP_CFG_RTOS == 0)
    g_usb_change_device_state[ptr->ip] &= (uint16_t) (~(1 << USB_STATUS_RESUME));
 #endif                                /* BSP_CFG_RTOS == 0 */

    ctrl.module_number  = ptr->ip;
    ctrl.device_address = 1;
 #if (BSP_CFG_RTOS == 2)
    ctrl.p_data = (void *) ptr->cur_task_hdl;
 #endif                                /* #if (BSP_CFG_RTOS == 2) */

    if (ptr->ip)
    {
 #ifdef VECTOR_NUMBER_USB_HI
        p_cfg = (usb_cfg_t *) R_FSP_IsrContextGet((IRQn_Type) VECTOR_NUMBER_USB_HI);
 #endif
    }
    else
    {
 #ifdef VECTOR_NUMBER_USB_HI
        p_cfg = (usb_cfg_t *) R_FSP_IsrContextGet((IRQn_Type) VECTOR_NUMBER_USB_HI);
 #endif
    }

 #if defined(VECTOR_NUMBER_USB_HI)
    ctrl.p_context = p_cfg->p_context;
 #else
    FSP_PARAMETER_NOT_USED(p_cfg);
 #endif

    usb_set_event(USB_STATUS_RESUME, &ctrl);
}                                      /* End of function usb_hstd_resume_complete */

/******************************************************************************
 * Function Name  : usb_hstd_device_information
 * Description    : Get the status of the connected USB Device
 * Arguments      : usb_utr_t *ptr    : Pointer to usb_utr_t structure.
 *              : uint16_t devaddr  : Device address
 *              : uint16_t *tbl     : Table Pointer
 * Return         : None
 ******************************************************************************/
void usb_hstd_device_information (usb_utr_t * ptr, uint16_t devaddr, uint16_t * tbl)
{
    uint16_t   i;
    uint16_t   port;
    uint16_t * p;

    if (0 == devaddr)
    {
        p = tbl;
        for (i = 0; i < 8; ++i)
        {
            *p++ = USB_NOPORT;
        }

        port   = g_usb_hstd_device_info[ptr->ip][devaddr][0];
        tbl[0] = port;
        tbl[1] = g_usb_hstd_mgr_mode[ptr->ip];
        tbl[4] = g_usb_hstd_device_info[ptr->ip][devaddr][4];
    }
    else
    {
        for (i = 0; i < 8; ++i)
        {
            tbl[i] = g_usb_hstd_device_info[ptr->ip][devaddr][i];
        }
    }

    tbl[8] = g_usb_hstd_mgr_mode[ptr->ip];
}

/******************************************************************************
 * End of function usb_hstd_device_information
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_host_registration
 * Description     : sample registration.
 * Argument        : usb_utr_t    *ptr   : Pointer to usb_utr_t structure.
 * Return          : none
 ******************************************************************************/
void usb_host_registration (usb_utr_t * ptr)
{
    (void) *ptr;

 #if defined(USB_CFG_HCDC_USE)
    usb_hcdc_registration(ptr);
 #endif                                /* defined(USB_CFG_HCDC_USE) */

 #if defined(USB_CFG_HHID_USE)
    usb_hhid_registration(ptr);
 #endif                                /* defined(USB_CFG_HHID_USE) */

 #if defined(USB_CFG_HMSC_USE)
    usb_hmsc_registration(ptr);
 #endif                                /* defined(USB_CFG_HMSC_USE) */

 #if defined(USB_CFG_HVND_USE)
    usb_hvnd_registration(ptr);
 #endif                                /* defined(USB_CFG_HVND_USE) */
}

/******************************************************************************
 * End of function usb_host_registration
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_connect_err_event_set
 * Description     : Set event for "USB_STS_NOT_SUPPORT"
 * Arguments       : uint16_t ip_no  : IP no.(USB_IP0/USB_IP1)
 * Return          : none
 ******************************************************************************/
void usb_hstd_connect_err_event_set (uint16_t ip_no)
{
    usb_instance_ctrl_t ctrl;

    ctrl.device_address = (uint8_t) g_usb_hstd_device_addr[ip_no]; /* usb device address */
    ctrl.module_number  = (uint8_t) ip_no;                         /* module number setting */
    usb_set_event(USB_STATUS_NOT_SUPPORT, &ctrl);                  /* set event()  */
}

/******************************************************************************
 * End of function usb_hstd_connect_err_event_set
 ******************************************************************************/

 #if defined(USB_CFG_HVND_USE)

/******************************************************************************
 * Function Name   : usb_hvnd_set_pipe_registration
 * Description     : Host CDC pipe registration.
 * Arguments       : usb_utr_t *ptr       : Pointer to usb_utr_t structure.
 *               : uint16_t  devadr     : Device address
 * Return          : usb_er_t             : Error info
 ******************************************************************************/
usb_er_t usb_hvnd_set_pipe_registration (usb_utr_t * ptr, uint16_t dev_addr)
{
    usb_er_t err;                      /* Error code */
    uint8_t  pipe_no;

    err = USB_ERROR;

    /* Device address check */
    if (0 != dev_addr)
    {
        /* Search use pipe block */
        /* WAIT_LOOP */
        for (pipe_no = USB_MIN_PIPE_NO; pipe_no < (USB_MAX_PIPE_NO + 1); pipe_no++)
        {
            /* Check use block */
            if (USB_TRUE == g_usb_pipe_table[ptr->ip][pipe_no].use_flag)
            {
                /* Check USB Device address */
                if ((dev_addr << USB_DEVADDRBIT) ==
                    (uint16_t) (g_usb_pipe_table[ptr->ip][pipe_no].pipe_maxp & USB_DEVSEL))
                {
                    usb_hstd_set_pipe_reg(ptr, pipe_no);
                    err = USB_OK;
                }
            }
        }
    }
    else
    {
        /* Error */
        USB_PRINTF1("SmplOpen adr error %x\n", dev_addr);
    }

    return err;
}

/******************************************************************************
 * End of function usb_hvnd_set_pipe_registration()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_configured
 * Description     : Host vendor application initialization.
 * Argument        : usb_utr_t *ptr    : IP info (mode, IP no, reg. address).
 * : uint16_t dev_addr : Device address.
 * : uint16_t data2    : Not used.
 * Return          : none
 ******************************************************************************/
void usb_hvnd_configured (usb_utr_t * ptr, uint16_t dev_addr, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    FSP_PARAMETER_NOT_USED(data2);

    ctrl.module_number  = ptr->ip;     /* Module number setting */
    ctrl.device_address = (uint8_t) dev_addr;
    if (0 != dev_addr)
    {
        /* Registration */
        usb_hvnd_set_pipe_registration(ptr, dev_addr); /* Host CDC Pipe registration */
    }

    usb_set_event(USB_STATUS_CONFIGURED, &ctrl);
}

/******************************************************************************
 * End of function usb_hvnd_configured
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_detach
 * Description     : Close host vendor application.
 * Argument        : usb_utr_t *ptr    : IP info (mode, IP no, reg. address).
 * : uint16_t data1            : Not Use
 * : uint16_t data2            : Not Use
 * Return          : none
 ******************************************************************************/
void usb_hvnd_detach (usb_utr_t * ptr, uint16_t dev_addr, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    FSP_PARAMETER_NOT_USED(data2);

    usb_hstd_clr_pipe_table(ptr->ip, dev_addr);

    ctrl.module_number  = ptr->ip;     /* Module number setting */
    ctrl.device_address = (uint8_t) dev_addr;
    usb_set_event(USB_STATUS_DETACH, &ctrl);
}

/******************************************************************************
 * End of function usb_hvnd_detach
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_enumeration
 * Description     : Vendor class example enumeration execution by host.
 * Argument        : usb_clsinfo_t *mess   : Class info data pointer.
 * Return          : none
 ******************************************************************************/
void usb_hvnd_enumeration (usb_clsinfo_t * mess, uint16_t ** table)
{
    uint8_t * pdesc;
    uint16_t  total_len;
    uint16_t  speed;

    *table[3] = USB_OK;

    /* Pipe Information table set */
    speed = *table[6];
    pdesc = (uint8_t *) g_usb_hstd_config_descriptor[mess->ip];

    total_len = ((uint16_t) *(pdesc + 3)) << 8;
    total_len = (uint16_t) *(pdesc + 2);

    R_USB_HstdSetPipe(table);

    /* Pipe Information table set */
    usb_hvnd_pipe_info(mess, pdesc, speed, total_len);

    usb_hstd_return_enu_mgr(mess, USB_OK); /* Return to MGR */
}

/******************************************************************************
 * End of function usb_hvnd_enumeration
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_pipe_info
 * Description     : Host pipe information check. Set EP table.
 * Arguments       : uint8_t *table        : Descriptor start address.
 * : uint16_t speed        : Device connected speed
 * : uint16_t length       : Configuration Descriptor Length
 * Return value    : none
 ******************************************************************************/
void usb_hvnd_pipe_info (usb_utr_t * p_utr, uint8_t * table, uint16_t speed, uint16_t length)
{
    uint16_t             ofdsc;
    uint16_t             pipe_no;
    usb_pipe_table_reg_t ep_tbl;

    /* Check Endpoint Descriptor */
    ofdsc = table[0];

    /* WAIT_LOOP */
    while (ofdsc < length)
    {
        /* Search within Interface */
        if (USB_DT_ENDPOINT == table[ofdsc + 1])
        {
            pipe_no = (uint16_t) (usb_hvnd_make_pipe_reg_info(p_utr, USB_ADDRESS1, speed, &table[ofdsc], &ep_tbl));
            if (USB_NULL == pipe_no)
            {
                return;
            }
            else
            {
                usb_hstd_set_pipe_info(USB_IP0, pipe_no, &ep_tbl);
            }

            ofdsc += table[ofdsc];
        }
        else
        {
            ofdsc += table[ofdsc];
        }
    }
}

/******************************************************************************
 * End of function usb_hvnd_pipe_info
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_read_complete
 * Description     : Notify application task of data reception completion.
 * : (Callback function at completion of INT data reception.)
 * Arguments       :
 * Return value    : none
 ******************************************************************************/
void usb_hvnd_read_complete (usb_utr_t * ptr, uint16_t data1, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    FSP_PARAMETER_NOT_USED(data1);
    FSP_PARAMETER_NOT_USED(data2);

    ctrl.module_number = ptr->ip;                               /* Module number setting */
    ctrl.pipe          = (uint8_t) ptr->keyword;                /* Pipe number setting */
    ctrl.type          = (usb_class_t) USB_CLASS_INTERNAL_HVND; /* Vendor class  */

    ctrl.data_size      = ptr->read_req_len - ptr->tranlen;
    ctrl.device_address = (uint8_t) usb_hstd_get_device_address(ptr, ctrl.pipe);
  #if (BSP_CFG_RTOS == 2)
    ctrl.p_data = (void *) ptr->cur_task_hdl;
  #endif                               /* #if (BSP_CFG_RTOS == 2) */

    switch (ptr->status)
    {
        case USB_DATA_OK:
        {
            ctrl.status = FSP_SUCCESS;
            break;
        }

        case USB_DATA_SHT:
        {
            ctrl.status = FSP_ERR_USB_SIZE_SHORT;
            break;
        }

        case USB_DATA_OVR:
        {
            ctrl.status = FSP_ERR_USB_SIZE_OVER;
            break;
        }

        case USB_DATA_ERR:
        default:
        {
            ctrl.status = FSP_ERR_USB_FAILED;
            break;
        }
    }

    usb_set_event(USB_STATUS_READ_COMPLETE, &ctrl); /* Set Event()  */
}

/******************************************************************************
 * End of function usb_hvnd_read_complete()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_write_complete
 * Description     : Notify application task of data transmission completion.
 * : (Callback function at completion of INT data reception.)
 * Arguments       :
 * Return value    : none
 ******************************************************************************/
void usb_hvnd_write_complete (usb_utr_t * ptr, uint16_t data1, uint16_t data2)
{
    usb_instance_ctrl_t ctrl;

    FSP_PARAMETER_NOT_USED(data1);
    FSP_PARAMETER_NOT_USED(data2);

    ctrl.module_number  = ptr->ip;                               /* Module number setting */
    ctrl.pipe           = (uint8_t) ptr->keyword;                /* Pipe number setting */
    ctrl.type           = (usb_class_t) USB_CLASS_INTERNAL_HVND; /* Vendor class  */
    ctrl.device_address = (uint8_t) usb_hstd_get_device_address(ptr, ctrl.pipe);
  #if (BSP_CFG_RTOS == 2)
    ctrl.p_data = (void *) ptr->cur_task_hdl;
  #endif /* #if (BSP_CFG_RTOS == 2) */

    if (USB_DATA_NONE == ptr->status)
    {
        ctrl.status = FSP_SUCCESS;
    }
    else
    {
        ctrl.status = FSP_ERR_USB_FAILED;
    }

    usb_set_event(USB_STATUS_WRITE_COMPLETE, &ctrl); /* Set Event()  */
}

/******************************************************************************
 * End of function usb_hvnd_write_complete()
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_registration
 * Description     : Host vendor class registration.
 * Argument        : usb_utr_t *ptr    : IP info (mode, IP no, reg. address).
 * Return          : none
 ******************************************************************************/
void usb_hvnd_registration (usb_utr_t * ptr)
{
    usb_hcdreg_t driver;

    /* Driver registration */

    /* Interface Class */
    driver.ifclass = (uint16_t) USB_IFCLS_VEN;

    /* Target peripheral list */
    driver.p_tpl = (uint16_t *) &g_usb_apl_devicetpl;

    /* Driver init */
    driver.classinit = &usb_hstd_dummy_function;

    /* Driver check */
    driver.classcheck = &usb_hvnd_enumeration;

    /* Device configured */
    driver.devconfig = &usb_hvnd_configured;

    /* Device detach */
    driver.devdetach = &usb_hvnd_detach;

    /* Device suspend */
    driver.devsuspend = &usb_hstd_dummy_function;

    /* Device resume */
    driver.devresume = &usb_hstd_dummy_function;

    usb_hstd_driver_registration(ptr, &driver);

  #if USB_CFG_HUB == USB_CFG_ENABLE
   #if (BSP_CFG_RTOS == 0)
    usb_cstd_set_task_pri(USB_HUB_TSK, USB_PRI_3);
   #endif                              /* BSP_CFG_RTOS == 0 */
    usb_hhub_registration(ptr, USB_NULL);
  #endif                               /* USB_CFG_HUB == USB_CFG_ENABLE */
}

/******************************************************************************
 * End of function usb_hvnd_registration
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hvnd_make_pipe_reg_info
 * Description     : Make value for USB PIPE registers set value.
 * Arguments    : usb_utr_t *p_utr   : Pointer to usb_utr_t structure
 *              : uint16_t address      : USB Device address
 *              : usb_class_t usb_class : USB Device class(USB_HVND/USB_HCDC/USB_HHID/USB_HMSC/USB_HUB)
 *              : uint16_t speed        : USB speed
 *              : uint8_t *descriptor   : Address for End Point Descriptor
 *              : usb_pipe_table_reg_t *pipe_table_work : Address for Store PIPE reg set value.
 * Return value    : Pipe no (USB_PIPE1->USB_PIPE9:OK, USB_NULL:Error)
 ******************************************************************************/
static uint8_t usb_hvnd_make_pipe_reg_info (usb_utr_t            * p_utr,
                                            uint16_t               address,
                                            uint16_t               speed,
                                            uint8_t              * descriptor,
                                            usb_pipe_table_reg_t * pipe_table_work)
{
    uint8_t  pipe_no;
    uint16_t pipe_cfg;
    uint16_t pipe_maxp;
    uint16_t pipe_peri = USB_NULL;
  #if defined(USB_HIGH_SPEED_MODULE)
    uint16_t pipe_buf;
  #endif                               /* defined (USB_HIGH_SPEED_MODULE) */

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
                pipe_no  = usb_hvnd_get_pipe_no(p_utr, USB_EP_BULK, USB_PIPE_DIR_IN);
            }
            else
            {
                /* OUT(send) */
                pipe_cfg = (uint16_t) (USB_TYPFIELD_BULK | USB_CFG_DBLB | USB_DIR_H_OUT);
                pipe_no  = usb_hvnd_get_pipe_no(p_utr, USB_EP_BULK, USB_PIPE_DIR_OUT);
            }

  #if defined(USB_HIGH_SPEED_MODULE)
            if (USB_IP1 == p_utr->ip)
            {
                pipe_cfg |= (uint16_t) (USB_CFG_CNTMD);
            }
  #endif                               /* defined (USB_HIGH_SPEED_MODULE) */
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
                pipe_no  = usb_hvnd_get_pipe_no(p_utr, USB_EP_INT, USB_PIPE_DIR_IN);
            }
            else
            {
                /* OUT(send) */
                pipe_cfg = (uint16_t) (USB_TYPFIELD_INT | USB_DIR_H_OUT);
                pipe_no  = usb_hvnd_get_pipe_no(p_utr, USB_EP_INT, USB_PIPE_DIR_OUT);
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
  #if defined(USB_HIGH_SPEED_MODULE)
        if (USB_IP1 == p_utr->ip)
        {
            /* PIPEBUF is USBA module only */
            pipe_buf = usb_hstd_get_pipe_buf_value(pipe_no);
            pipe_table_work->pipe_buf = pipe_buf;
        }
  #endif                               /* #if defined (USB_HIGH_SPEED_MODULE) */
    }

    return pipe_no;
}

/******************************************************************************
 * End of function usb_hvnd_make_pipe_reg_info
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_hstd_get_pipe_no
 * Description     : Get PIPE No.
 * Arguments    : usb_utr_t *p_utr   : Pointer to usb_utr_t structure
 *              : uint16_t address   : USB Device address
 *              : uint16_t class     : USB Device class(USB_HVND/USB_HCDC/USB_HHID/USB_HMSC/USB_HUB)
 *              : uint8_t  type      : Transfer Type.(USB_EP_BULK/USB_EP_INT)
 *              : uint8_t  dir       : (USB_PIPE_DIR_IN/USB_PIPE_DIR_OUT)
 * Return value    : Pipe no (USB_PIPE1->USB_PIPE9:OK, USB_NULL:Error)
 ******************************************************************************/
static uint8_t usb_hvnd_get_pipe_no (usb_utr_t * p_utr, uint8_t type, uint8_t dir)
{
  #if (USB_CFG_DMA == USB_CFG_DISABLE)
    (void) dir;
  #endif                               /* (USB_CFG_DMA == USB_CFG_ENABLE) */
    uint8_t pipe_no = USB_NULL;
    uint8_t pipe;

    if (USB_EP_BULK == type)
    {
        /* BULK PIPE Loop */
        /* WAIT_LOOP */
        for (pipe = USB_BULK_PIPE_START; pipe < (USB_BULK_PIPE_END + 1); pipe++)
        {
  #if (USB_CFG_DMA == USB_CFG_ENABLE)
            if ((USB_PIPE1 == pipe) || (USB_PIPE2 == pipe))
            {
                if ((USB_PIPE_DIR_IN == dir) && (0 != p_utr->p_transfer_rx))
                {
                    /* For IN transfer */

                    /* Check Free pipe */
                    if (USB_FALSE == g_usb_pipe_table[p_utr->ip][pipe].use_flag)
                    {
                        pipe_no = pipe; /* Set Free pipe */
                        break;
                    }
                }
                else if ((USB_PIPE_DIR_IN != dir) && (0 != p_utr->p_transfer_tx))
                {
                    /* For OUT Transfer */

                    /* Check Free pipe */
                    if (USB_FALSE == g_usb_pipe_table[p_utr->ip][pipe].use_flag)
                    {
                        pipe_no = pipe; /* Set Free pipe */
                        break;
                    }
                }
                else
                {
                    /* Nothing */
                }
            }
            else
            {
                /* Check Free pipe */
                if (USB_FALSE == g_usb_pipe_table[p_utr->ip][pipe].use_flag)
                {
                    pipe_no = pipe;    /* Set Free pipe */
                    break;
                }
            }

  #else
            if (USB_FALSE == g_usb_pipe_table[p_utr->ip][pipe].use_flag)
            {
                /* Check Free pipe */
                pipe_no = pipe;        /* Set Free pipe */
                break;
            }
  #endif
        }
    }

    if (USB_EP_INT == type)
    {
        /* Interrupt PIPE Loop */
        /* WAIT_LOOP */
        for (pipe = USB_INT_PIPE_START; pipe < (USB_INT_PIPE_END + 1); pipe++)
        {
            if (USB_FALSE == g_usb_pipe_table[p_utr->ip][pipe].use_flag)
            {
                /* Check Free pipe */
                pipe_no = pipe;        /* Set Free pipe */
                break;
            }
        }
    }

    return pipe_no;
}

/******************************************************************************
 * End of function usb_hvnd_get_pipe_no
 ******************************************************************************/
 #endif                                /* defined(USB_CFG_HVND_USE) */

#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

/******************************************************************************
 * End  Of File
 ******************************************************************************/
