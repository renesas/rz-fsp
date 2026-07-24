/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "hal_data.h"
#include "rm_lvgl_port.h"

#include "r_lcdc.h"

#if (BSP_CFG_RTOS == 2)
 #include "FreeRTOS.h"
 #include "semphr.h"
#else
 #include "bsp_api.h"
 #include "r_timer_api.h"
#endif

#include "lvgl.h"
#include "lv_display_private.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define RM_LVGL_PORT_OPEN              (('L' << 24U) | ('V' << 16U) | ('G' << 8U) | ('L' << 0U))
#define RM_LVGL_PORT_PRV_SYSTICK_HZ    (1000U)

/***********************************************************************************************************************
 * External definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

void _rm_lvgl_port_display_callback(display_callback_args_t * p_args);

static void rm_lvgl_port_flush_cb(lv_display_t * p_lv_display, const lv_area_t * p_lv_area, uint8_t * p_px_map);
static void rm_lvgl_port_flush_wait_cb(lv_display_t * p_lv_display);

static void * rotation_buffer = NULL;

#if RM_LVGL_PORT_CFG_PROVIDE_TICK_CALLBACK
#if (BSP_CFG_RTOS == 0)
void _rm_lvgl_port_setup_lvgl_tick( void );
#endif
static uint32_t rm_lvgl_port_tick_get_cb(void);

#endif

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/
#if (BSP_CFG_RTOS == 2)
static SemaphoreHandle_t g_semaphore_vpos;
static StaticSemaphore_t g_semaphore_buffer_vpos;
#else
static volatile uint8_t  g_vpos_flag;
static volatile uint32_t g_systick_ms;
#endif

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZA
{
#endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZA_RM_LVGL_PORT
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 ***********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Open the LVGL port driver module.
 *
 * Example:
 * @snippet rza_rm_lvgl_port_example.c RM_LVGL_PORT_Open
 *
 * @note This function should be called after the LVGL function lv_init() has been called.
 *
 * @retval FSP_SUCCESS LVGL port successfully opened.
 * @retval FSP_ERR_OUT_OF_MEMORY Internal call to lv_display_create() failed to allocate memory for a display.
 *
 * See @ref Common_Error_Codes for other possible return codes. This function calls R_LCDC_Open(), R_LCDC_Start(), and
 * R_LCDC_BufferChange().
 **********************************************************************************************************************/
fsp_err_t RM_LVGL_PORT_Open (rm_lvgl_port_instance_ctrl_t * const p_instance_ctrl,
                             rm_lvgl_port_cfg_t const * const     p_cfg)
{
#if RM_LVGL_PORT_CFG_PARAM_CHECKING_ENABLE
    FSP_ASSERT(p_instance_ctrl);
    FSP_ASSERT(p_cfg);
    FSP_ERROR_RETURN(RM_LVGL_PORT_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#endif

    fsp_err_t error;

#if (BSP_CFG_RTOS == 2)
    g_semaphore_vpos = xSemaphoreCreateBinaryStatic(&g_semaphore_buffer_vpos);
#endif

    p_instance_ctrl->p_display_instance          = p_cfg->p_display_instance;
    p_instance_ctrl->inherit_frame_layer         = p_cfg->inherit_frame_layer;
    p_instance_ctrl->p_framebuffer_0             = p_cfg->p_framebuffer_0;
    p_instance_ctrl->p_framebuffer_1             = p_cfg->p_framebuffer_1;
    p_instance_ctrl->p_partial_framebuffer_0     = p_cfg->p_partial_framebuffer_0;
    p_instance_ctrl->p_partial_framebuffer_1     = p_cfg->p_partial_framebuffer_1;
    p_instance_ctrl->render_mode                 = p_cfg->render_mode;
    p_instance_ctrl->rotation                    = p_cfg->rotation;
    p_instance_ctrl->p_callback                  = p_cfg->p_callback;

    if (NULL != p_instance_ctrl->p_framebuffer_0)
    {
        memset(p_instance_ctrl->p_framebuffer_0, 0,
               (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT));
    }

    if (NULL != p_instance_ctrl->p_framebuffer_1)
    {
        memset(p_instance_ctrl->p_framebuffer_1, 0,
               (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT));
    }

    error = R_LCDC_Open(p_instance_ctrl->p_display_instance->p_ctrl, p_instance_ctrl->p_display_instance->p_cfg);
    FSP_ERROR_RETURN(error == FSP_SUCCESS, error);

    error = R_LCDC_Start(p_instance_ctrl->p_display_instance->p_ctrl);
    if (error != FSP_SUCCESS)
    {
        R_LCDC_Close(p_instance_ctrl->p_display_instance->p_ctrl);
        return error;
    }

    /* Display the inactive buffer if double-buffering is used. */
    if (NULL != p_instance_ctrl->p_framebuffer_1)
    {
        do
        {
            error = R_LCDC_BufferChange(p_instance_ctrl->p_display_instance->p_ctrl,
                                         p_instance_ctrl->p_framebuffer_1,
                                         p_instance_ctrl->inherit_frame_layer);
        } while (FSP_ERR_INVALID_UPDATE_TIMING == error);

        if (error != FSP_SUCCESS)
        {
            R_LCDC_Close(p_instance_ctrl->p_display_instance->p_ctrl);
            return error;
        }
    }

    p_instance_ctrl->p_lv_display = lv_display_create(LVGL_DISPLAY_HSIZE_INPUT, LVGL_DISPLAY_VSIZE_INPUT);

    if (NULL == p_instance_ctrl->p_lv_display)
    {
        R_LCDC_Close(p_instance_ctrl->p_display_instance->p_ctrl);

        return FSP_ERR_OUT_OF_MEMORY;
    }

    lv_display_set_rotation(p_instance_ctrl->p_lv_display, p_instance_ctrl->rotation);
    lv_display_set_flush_cb(p_instance_ctrl->p_lv_display, rm_lvgl_port_flush_cb);
    lv_display_set_flush_wait_cb(p_instance_ctrl->p_lv_display, rm_lvgl_port_flush_wait_cb);
    if (LV_DISPLAY_RENDER_MODE_PARTIAL == p_instance_ctrl->render_mode) {
        lv_display_set_buffers(p_instance_ctrl->p_lv_display,
                               p_instance_ctrl->p_partial_framebuffer_0,
                               p_instance_ctrl->p_partial_framebuffer_1,
                               (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT / LVGL_DISPLAY_BUFFER_SIZE_DIVISOR),
                               p_instance_ctrl->render_mode);
    } else {
        lv_display_set_buffers(p_instance_ctrl->p_lv_display,
                               p_instance_ctrl->p_framebuffer_0,
                               p_instance_ctrl->p_framebuffer_1,
                               (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT),
                               p_instance_ctrl->render_mode);
    }

#if RM_LVGL_PORT_CFG_PROVIDE_TICK_CALLBACK
 #if (BSP_CFG_RTOS == 0)
    _rm_lvgl_port_setup_lvgl_tick();
 #endif

    lv_tick_set_cb(rm_lvgl_port_tick_get_cb);
#endif

    p_instance_ctrl->open = RM_LVGL_PORT_OPEN;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_LVGL_PORT)
 **********************************************************************************************************************/

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/*******************************************************************************************************************//**
 * @brief  Callback function for LVGL Port. This function is called back from a Display HAL driver module.
 * If DISPLAY_EVENT_FRAME_END is returned from Display HAL driver module, it sets the semaphore for rendering and
 * displaying synchronization. This function invokes a user callback function if registered through RM_LVGL_PORT_Open()
 * function.
 * @param[in]    p_args   Pointer to the Display interface callback argument.
 **********************************************************************************************************************/
void _rm_lvgl_port_display_callback (display_callback_args_t * p_args)
{
    rm_lvgl_port_callback_args_t cb_arg;

    if (DISPLAY_EVENT_FRAME_END == p_args->event)
    {
#if (BSP_CFG_RTOS == 2)
        BaseType_t context_switch;

        xSemaphoreGiveFromISR(g_semaphore_vpos, &context_switch);
        portYIELD_FROM_ISR(context_switch);
#else
        g_vpos_flag = 1;
#endif
        cb_arg.event = RM_LVGL_PORT_EVENT_DISPLAY_VPOS;
    }
    else if ((DISPLAY_EVENT_GR1_UNDERFLOW == p_args->event) || (DISPLAY_EVENT_GR2_UNDERFLOW == p_args->event))
    {
        cb_arg.event = RM_LVGL_PORT_EVENT_UNDERFLOW;
    }
    else
    {
    }

    if (g_lvgl_port_ctrl.p_callback)
    {
        cb_arg.device = RM_LVGL_PORT_DEVICE_DISPLAY;
        cb_arg.error  = FSP_SUCCESS;
        g_lvgl_port_ctrl.p_callback(&cb_arg);
    }
}

static void _rm_lvgl_port_flush_partial_cb (lv_display_t * p_lv_display, const lv_area_t * p_lv_area, uint8_t * p_px_map)
{
    lv_color_format_t cf = lv_display_get_color_format(p_lv_display);
    uint32_t px_size = lv_color_format_get_size(cf);

    /*Calculate the position of the rotated area*/
    lv_area_t rotated_area = *p_lv_area;
    lv_display_rotate_area(p_lv_display, &rotated_area);

    /*Calculate the properties of the source buffer*/
    int32_t src_w = lv_area_get_width(p_lv_area);
    int32_t src_h = lv_area_get_height(p_lv_area);
    uint32_t src_stride = lv_draw_buf_width_to_stride((uint32_t)src_w, cf);

    /*Calculate the properties of the frame buffer*/
    uint32_t fb_stride = lv_draw_buf_width_to_stride((uint32_t)p_lv_display->hor_res, cf);

    static uint8_t * p_active_fb = NULL;
    static uint8_t * p_inactive_fb = NULL;

    static uint8_t initial = 1;
    if (initial) {
        p_active_fb = g_lvgl_port_ctrl.p_framebuffer_0;
        if (NULL != g_lvgl_port_ctrl.p_framebuffer_1) {
            p_inactive_fb = g_lvgl_port_ctrl.p_framebuffer_1;
        }
        initial = 0;
    }

    uint8_t * fb_start = p_active_fb;
    fb_start += (uint32_t) rotated_area.y1 * fb_stride + (uint32_t) rotated_area.x1 * px_size;

    lv_display_rotation_t rotation = lv_display_get_rotation(p_lv_display);
    if (rotation == LV_DISPLAY_ROTATION_0) {
        for (int32_t y = p_lv_area->y1; y <= p_lv_area->y2; y++) {
            lv_memcpy(fb_start, p_px_map, src_stride);
            p_px_map += src_stride;
            fb_start += fb_stride;
        }
    }
    else {
        lv_draw_sw_rotate(p_px_map, fb_start, src_w, src_h, (int32_t) src_stride, (int32_t) fb_stride, rotation, cf);
    }

    if (lv_display_flush_is_last(p_lv_display)) {
        R_BSP_CACHE_CleanRange((uint64_t) p_active_fb,  LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT);
        R_LCDC_BufferChange(g_lvgl_port_ctrl.p_display_instance->p_ctrl,
                            p_active_fb,
                            g_lvgl_port_ctrl.inherit_frame_layer);

        if (NULL != g_lvgl_port_ctrl.p_framebuffer_1) {
#if (BSP_CFG_RTOS == 2)

            /* Try to take the semaphore once without waiting to clear it if already set, then take it again. */
            xSemaphoreTake(g_semaphore_vpos, 0);
            xSemaphoreTake(g_semaphore_vpos, portMAX_DELAY);
#else
            g_vpos_flag = 0;
            while (0 == g_vpos_flag)
            {
            }
#endif
            lv_memcpy(p_inactive_fb, p_active_fb, LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT);

            /* Swap buffers */
            uint8_t * p_temp = p_inactive_fb;
            p_inactive_fb = p_active_fb;
            p_active_fb = p_temp;
        }
    }
}

static void _rm_lvgl_port_flush_direct_cb (lv_display_t * p_lv_display, const lv_area_t * p_lv_area, uint8_t * p_px_map) {
    FSP_PARAMETER_NOT_USED(p_lv_area);

    if (lv_display_flush_is_last(p_lv_display))
    {
        lv_display_rotation_t rotation = lv_display_get_rotation(p_lv_display);

        if (rotation != LV_DISPLAY_ROTATION_0) {
            lv_color_format_t cf = lv_display_get_color_format(p_lv_display);

            int32_t w = p_lv_display->ver_res;
            int32_t h = p_lv_display->hor_res;
            uint32_t w_stride = lv_draw_buf_width_to_stride((uint32_t)w, cf);
            uint32_t h_stride = lv_draw_buf_width_to_stride((uint32_t)h, cf);

            /* only allocate if rotation is actually being used */
            if (!rotation_buffer) {
                rotation_buffer = lv_malloc(2 * LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT);
                LV_ASSERT_MALLOC(rotation_buffer);
            }

            static uint8_t buffer_id = 0;
            uint8_t * fb = (uint8_t *)(rotation_buffer) + buffer_id * (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT);

            if(rotation == LV_DISPLAY_ROTATION_180) {
                lv_draw_sw_rotate(p_px_map, fb, w, h, (int32_t) w_stride, (int32_t) w_stride, rotation, cf);
            }
            else /* 90 or 270 */
            {
                lv_draw_sw_rotate(p_px_map, fb, w, h, (int32_t) w_stride, (int32_t) h_stride, rotation, cf);
            }

            R_BSP_CACHE_CleanRange((uint64_t) fb, (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT));
            R_LCDC_BufferChange(g_lvgl_port_ctrl.p_display_instance->p_ctrl,
                                fb,
                                g_lvgl_port_ctrl.inherit_frame_layer);

            buffer_id = !buffer_id;
        } else {
            R_BSP_CACHE_CleanRange((uint64_t) p_px_map, (LVGL_DISPLAY_BUFFER_STRIDE_BYTES_INPUT * LVGL_DISPLAY_VSIZE_INPUT));
            R_LCDC_BufferChange(g_lvgl_port_ctrl.p_display_instance->p_ctrl,
                                p_px_map,
                                g_lvgl_port_ctrl.inherit_frame_layer);
        }
    }
    else
    {
    }
}

/*******************************************************************************************************************//**
 * @brief Display flush callback required for LVGL.
 * @param[in] p_lv_display Pointer to the lv_display_t which is being flushed.
 * @param[in] p_lv_area Pointer to an lv_area_t which is the destination region in the frame buffer to copy the render
 * buffer data to, given in pixel coordinates.
 * @param[in] p_px_map Pointer to the render buffer from which pixel data should be copied.
 **********************************************************************************************************************/
static void rm_lvgl_port_flush_cb (lv_display_t * p_lv_display, const lv_area_t * p_lv_area, uint8_t * p_px_map)
{
    if (LV_DISPLAY_RENDER_MODE_PARTIAL == p_lv_display->render_mode) {
        _rm_lvgl_port_flush_partial_cb(p_lv_display, p_lv_area, p_px_map);
    } else {
        _rm_lvgl_port_flush_direct_cb(p_lv_display, p_lv_area, p_px_map);
    }
}

/*******************************************************************************************************************//**
 * @brief Display flush wait callback required for LVGL.
 * @param[in] p_lv_display Pointer to the lv_display_t which is being waited upon.
 **********************************************************************************************************************/
static void rm_lvgl_port_flush_wait_cb (lv_display_t * p_lv_display)
{
    if (lv_display_flush_is_last(p_lv_display) && (LV_DISPLAY_RENDER_MODE_PARTIAL != p_lv_display->render_mode))
    {
#if (BSP_CFG_RTOS == 2)

        /* Try to take the semaphore once without waiting to clear it if already set, then take it again. */
        xSemaphoreTake(g_semaphore_vpos, 0);
        xSemaphoreTake(g_semaphore_vpos, portMAX_DELAY);
#else
        g_vpos_flag = 0;
        while (0 == g_vpos_flag)
        {
        }
#endif
    }
    else
    {
    }
}

#if RM_LVGL_PORT_CFG_PROVIDE_TICK_CALLBACK

/*******************************************************************************************************************//**
 * @brief Millisecond tick get callback required for LVGL.
 **********************************************************************************************************************/
static uint32_t rm_lvgl_port_tick_get_cb (void)
{
 #if (BSP_CFG_RTOS == 2)

   return (uint32_t) (pdTICKS_TO_MS(xTaskGetTickCount()));
 #else

    return g_systick_ms;
 #endif
}

 #if (BSP_CFG_RTOS == 0)
void SysTick_Handler(timer_callback_args_t * args);

void SysTick_Handler (timer_callback_args_t * args)
{
    FSP_PARAMETER_NOT_USED(args);
    g_systick_ms++;
}

 #endif

#endif
