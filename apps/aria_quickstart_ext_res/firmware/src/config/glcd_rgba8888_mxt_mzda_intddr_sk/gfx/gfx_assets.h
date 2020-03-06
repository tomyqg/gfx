// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

/*******************************************************************************
  MPLAB Harmony Graphics Asset Header File

  File Name:
    gfx_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/


#ifndef GFX_ASSETS_H
#define GFX_ASSETS_H

#include "gfx/utils/gfx_utils.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END 

/*** Generated Asset Descriptors ***/
/*****************************************************************************
 * MPLAB Harmony Graphics Asset Location IDs
 *****************************************************************************/
#define GFXU_ASSET_LOCATION_ID_INTERNAL    0
#define GFXU_ASSET_LOCATION_ID_SQI    1
 
/*****************************************************************************
 * MPLAB Harmony Graphics Image Assets
 *****************************************************************************/
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_jpeg
 * Size:   141x132 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_jpeg;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_png
 * Size:   141x132 pixels
 * Mode:   RGB_888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_png;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_raw
 * Size:   141x132 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_raw;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_rle
 * Size:   141x132 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_rle;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_raw_direct_blit
 * Size:   141x132 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_raw_direct_blit;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS
 * Height:       19
 * Style:        Plain
 * Glyph Count:  40
 * Range Count:  15
 * Glyph Ranges: 0x20
			     0x2B
			     0x41-0x42
			     0x44-0x45
			     0x47
			     0x49-0x4A
			     0x4C
			     0x4E
			     0x50-0x53
			     0x55
			     0x57
			     0x5C
			     0x61-0x69
			     0x6C-0x70
			     0x72-0x79
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Large
 * Height:       24
 * Style:        Plain
 * Glyph Count:  21011
 * Range Count:  18
 * Glyph Ranges: 0x20
			     0x2B
			     0x41-0x42
			     0x44-0x45
			     0x47
			     0x4A
			     0x4C
			     0x4E
			     0x50
			     0x52
			     0x57
			     0x63
			     0x65
			     0x69
			     0x6C
			     0x72
			     0x74
			     0x4E00-0x9FFF
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Large;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     UTF16
 * Languages:    English, Chinese
 * String Count: 11
 ***********************************/
// language IDs
#define language_English    0
#define language_Chinese    1

// string IDs
#define string_DrawDirectBlit    0
#define string_DrawJpeg    1
#define string_DrawPNG    2
#define string_DrawRLE    3
#define string_DrawRaw    4
#define string_ImageIsDirectBlit    5
#define string_ImageIsJPEG    6
#define string_ImageIsPNG    7
#define string_ImageIsRLE    8
#define string_ImageIsRaw    9
#define string_TitleString    10
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

