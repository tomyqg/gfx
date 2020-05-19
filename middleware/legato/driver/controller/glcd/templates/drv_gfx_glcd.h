/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  GFX GLCD Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_glcd_static.h

  Summary:
    GFX GLCD driver interface declarations for the static single instance driver.

  Description:
    The GLCD device driver provides a simple interface to manage the GLCD
    module on Microchip microcontrollers. This file defines the interface
    Declarations for the GLCD driver.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

/** \file drv_gfx_glcd.h
 * @brief GLCD driver functions and definitions.
 *
 * @details The GLCD device driver provides a simple interface to manage the
 * GLCD module on Microchip PIC32MZ DA microcontrollers. This file defines the interface
 * Declarations for the GLCD driver.
 *
 * This driver is configured via MHC and generated specific to the configuration
 * and hardware architecture set in MHC.
 * @see LE GLCD Display Driver component
 */

#ifndef _DRV_GFX_GLCD_H
#define _DRV_GFX_GLCD_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************
/* Note:  A file that maps the interface definitions above to appropriate static
          implementations (depending on build mode) is included at the bottom of
          this file.
*/

#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/gfx_driver.h"

#ifdef __cplusplus
    extern "C" {
#endif
        
// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
/**
 * @brief Initialize driver.
 * @details Initializes the GLCD driver. This routine is typically called
 * by a graphics library or by the application during application initialization.
 * @code
 * gfxResult res = DRV_GLCD_Initialize();
 * @endcode
 * @return GFX_SUCCESS if driver ready to render, otherwise GFX_FAILURE.
 */
void DRV_GLCD_Initialize(void);

/**
 * @brief Get color mode.
 * @details Returns the current color mode.
 * @code
 * gfxDisplayDriver*  drv;
 * gfxColorMode mode = drv->getColorMode();
 * @endcode
 * @return RGB color mode.
 */
gfxColorMode DRV_GLCD_GetColorMode(void);

/**
 * @brief Get buffer count.
 * @details Returns the number of configured buffers. In a single buffer system
 * count will be 1. In a double buffered system, the count would be at least 2.
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t cnt = drv->getBufferCount();
 * @endcode
 * @return number of configured buffers.
 */
uint32_t DRV_GLCD_GetBufferCount(void);

/**
 * @brief Get display width.
 * @details Returns the max number of horizontal pixels. This is the horizonal portion
 * of the screen resolution.
 * @see DRV_LCC_GetDisplayHeight()
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t width = drv->getDisplayWidth();
 * @endcode
 * @return horizontal display width.
 */
uint32_t DRV_GLCD_GetDisplayWidth(void);

/**
 * @brief Get display height.
 * @details Returns the max number vertical pixels. This is the vertical portion
 * of the screen resolution.
 * @see DRV_LCC_GetDisplayWidth()
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t width = drv->getDisplayHeight();
 * @endcode
 * @return vertical display height.
 */
uint32_t DRV_GLCD_GetDisplayHeight(void);

/**
 * @brief Execute update task.
 * @details Performs a driver task update.
 * @code
 * DRV_LCC_Update();
 * @endcode
 * @return void.
 */
void DRV_GLCD_Update(void);

/**
 * @brief Get layer count.
 * @details Returns the number of display layers configured.
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t cnt = drv->getLayerCount();
 * @endcode
 * @return number of display layers.
 */
uint32_t DRV_GLCD_GetLayerCount();

/**
 * @brief Get active layer.
 * @details Returns the index of the active layer.
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t layer = drv->getActiveLayer();
 * @endcode
 * @return layer index.
 */
uint32_t DRV_GLCD_GetActiveLayer();

/**
 * @brief Set active layer.
 * @details Sets active the layer at <span style="color: #820a32"><em>idx</em></span> position.
 * @code
 * gfxDisplayDriver* drv;
 * uint32_t idx;
 * gfxResult res = drv->setActiveLayer(idx);
 * @endcode
 * @return GFX_SUCCESS if layer at idx is active, otherwise GFX_FAILURE.
 */
gfxResult DRV_GLCD_SetActiveLayer(uint32_t idx);

/**
 * @brief Blit buffer.
 * @details Copies <span style="color: #820a32"><em>buf</em></span>
 * to the framebuffer at location <span style="color: #820a32"><em>x</em></span> and
 * <span style="color: #820a32"><em>y</em></span> with
 * <span style="color: #820a32"><em>blend</em></span> composition.
 * @code
 * gfxDisplayDriver* drv;
 * gfxResult res = drv->blitBuffer();
 * @endcode
 * @return GFX_SUCCESS if blit was performed, otherwise GFX_FAILURE.
 */
gfxResult DRV_GLCD_BlitBuffer(int32_t x, int32_t y, gfxPixelBuffer* buf, gfxBlend blend);

/**
 * @brief Swap buffer.
 * @details Swaps the rendering buffer with the display buffer. The display buffer now
 * becomes the rendering buffer. Swapping support double buffering technology.
 * @code
 * gfxDisplayDriver* drv;
 * drv->swap();
 * @endcode
 * @
void DRV_GLCD_Swap(void);

/**
 * @brief Get VSYNC count.
 * @details Returns the vertical pulse count. This can be used
 * as an interrupt to indicate the end of a frame or start of a new frame.
 * This value can also be used to do frame rate calculations.
 * @code
 * gfxDisplayDriver* drv;
 * drv->getVSYNCCount();
 * @endcode
 * @return VSYNC count.
 */
uint32_t DRV_GLCD_GetVSYNCCount(void);

/**
 * @brief Get framebuffer.
 * @details Returns the framebuffer (display buffer) located at
 * <span style="color: #820a32"><em>idx</em></span> position.
 * @code
 * gfxDisplayDriver* drv;
 * int32_t idx;
 * gfxPixelBuffer * buf = drv->getFrameBuffer(idx);
 * @endcode
 * @return void.
 */
gfxPixelBuffer * DRV_GLCD_GetFrameBuffer(int32_t idx);

/**
 * @brief Set use GPU.
 * @details Sets the gpu status to the value of
 * <span style="color: #820a32"><em>onOff</em></span>
 * This routine enables the use of the GPU for blit operations.
 * @code
 * gfxBool onOff;
 * DRV_GLCD_SetUseGPU(onOff);
 * @endcode
 * @return void.
 */
void DRV_GLCD_SetUseGPU(gfxBool onOff);

/**
 * @brief Perform Control config request.
 * @details Performs configuration <span style="color: #820a32"><em>request</em></span>.
 * @code
 * ctlrCfg request;
 * void * arg;
 * gfxDisplayDriver* drv;
 * gfxPixelBuffer * buf = drv->ctrlrConfig(request, arg);
 * @endcode
 * @return GFX_SUCCESS if configuration was performed, otherwise GFX_FAILURE
 */
gfxResult DRV_GLCD_CtrlrConfig(ctlrCfg request, void * arg);

/**
 * @brief Defines the LCC interface functions.
 * @details Establishes the driver abstract interface functions between the driver
 * and client. The client is either a graphics library middleware or application which
 * interfaces with the driver through these functions.
 */
static const gfxDisplayDriver glcdDisplayDriver =
{
    DRV_GLCD_GetColorMode,	/**< implements getColorMode */
    DRV_GLCD_GetBufferCount,	/**< implements getBufferCount */
    DRV_GLCD_GetDisplayWidth,   /**< implements getDisplayWidth */
    DRV_GLCD_GetDisplayHeight,	/**< implements getDisplayHeight */
    DRV_GLCD_Update,            /**< implements update */
    DRV_GLCD_GetLayerCount,	/**< implements layerCount */
    DRV_GLCD_GetActiveLayer,	/**< implements activeLayer */
    DRV_GLCD_SetActiveLayer,	/**< implements setActive */
    DRV_GLCD_BlitBuffer,	/**< implements blitbuffer */
    DRV_GLCD_Swap,		/**< implements swap */
    DRV_GLCD_GetVSYNCCount,	/**< implements getVSYNCCount */
    DRV_GLCD_GetFrameBuffer,	/**< implements getFrameBuffer */
    DRV_GLCD_CtrlrConfig        /**< implements ctrlrConfig */
};

#ifdef __cplusplus
    }
#endif
    
#endif // #ifndef _DRV_GFX_GLCD_H
/*******************************************************************************
 End of File
*/
