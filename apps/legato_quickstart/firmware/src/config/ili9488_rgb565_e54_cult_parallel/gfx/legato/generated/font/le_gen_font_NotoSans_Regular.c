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

#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       17
 * Baseline:     12
 * Style:        Plain
 * Glyph Count:  16
 * Range Count:  12
 * Glyph Ranges: 0x20
                 0x2E
                 0x47
                 0x4D
                 0x52
                 0x61
                 0x64-0x66
                 0x69
                 0x6E-0x6F
                 0x72
                 0x74-0x75
                 0x79
 *********************************/
/*********************************
 * font glyph kerning table description
 *
 * unsigned int - number of glyphs
 * for each glyph:
 *     unsigned short - codepoint         * the glyph's codepoint
 *     short          - width             * the glyph's width in pixels
 *     short          - height            * the glyph's height in pixels
 *     short          - advance           * the glyph's advance value in pixels
 *     short          - bearingX          * the glyph's bearing value in pixels on the X axis
 *     short          - bearingY          * the glyph's bearing value in pixels on the Y axis
 *     unsigned short - flags             * status flags for this glyph
 *     unsigned short - data row width    * the size of a row of glyph data in bytes
 *     unsigned int   - data table offset * the offset into the corresponding font data table
 ********************************/
const uint8_t NotoSans_Regular_glyphs[324] =
{
    0x10,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2E,0x00,0x03,0x00,0x03,0x00,0x04,0x00,
    0x01,0x00,0x03,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x47,0x00,0x0B,0x00,
    0x0C,0x00,0x0C,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x02,0x00,0x03,0x00,0x00,0x00,
    0x4D,0x00,0x0C,0x00,0x0C,0x00,0x0F,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x02,0x00,
    0x1B,0x00,0x00,0x00,0x52,0x00,0x09,0x00,0x0C,0x00,0x0A,0x00,0x01,0x00,0x0C,0x00,
    0x00,0x00,0x02,0x00,0x33,0x00,0x00,0x00,0x61,0x00,0x08,0x00,0x09,0x00,0x09,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x01,0x00,0x4B,0x00,0x00,0x00,0x64,0x00,0x09,0x00,
    0x0C,0x00,0x0A,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x02,0x00,0x54,0x00,0x00,0x00,
    0x65,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x02,0x00,
    0x6C,0x00,0x00,0x00,0x66,0x00,0x07,0x00,0x0C,0x00,0x06,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x01,0x00,0x7E,0x00,0x00,0x00,0x69,0x00,0x02,0x00,0x0C,0x00,0x04,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x01,0x00,0x8A,0x00,0x00,0x00,0x6E,0x00,0x08,0x00,
    0x09,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x01,0x00,0x96,0x00,0x00,0x00,
    0x6F,0x00,0x09,0x00,0x09,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x02,0x00,
    0x9F,0x00,0x00,0x00,0x72,0x00,0x06,0x00,0x09,0x00,0x07,0x00,0x01,0x00,0x09,0x00,
    0x00,0x00,0x01,0x00,0xB1,0x00,0x00,0x00,0x74,0x00,0x06,0x00,0x0B,0x00,0x06,0x00,
    0x00,0x00,0x0B,0x00,0x00,0x00,0x01,0x00,0xBA,0x00,0x00,0x00,0x75,0x00,0x08,0x00,
    0x09,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x01,0x00,0xC5,0x00,0x00,0x00,
    0x79,0x00,0x09,0x00,0x0D,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x02,0x00,
    0xCE,0x00,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Regular_data[232] =
{
    0x00,0xC0,0xC0,0x0F,0xC0,0x18,0xC0,0x30,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x61,
    0xC0,0x60,0x40,0x60,0x40,0x30,0x40,0x18,0x40,0x0F,0xC0,0x60,0x30,0x60,0x70,0x70,
    0x70,0x50,0x50,0x50,0xD0,0x58,0x90,0x49,0x90,0x49,0x10,0x4D,0x10,0x47,0x10,0x46,
    0x10,0x46,0x10,0x7C,0x00,0x46,0x00,0x43,0x00,0x43,0x00,0x43,0x00,0x46,0x00,0x7C,
    0x00,0x4C,0x00,0x46,0x00,0x42,0x00,0x43,0x00,0x41,0x00,0x3E,0x26,0x03,0x03,0x3F,
    0x63,0x43,0x67,0x39,0x01,0x00,0x01,0x00,0x01,0x00,0x1D,0x00,0x33,0x00,0x61,0x00,
    0x41,0x00,0x41,0x00,0x41,0x00,0x61,0x00,0x33,0x00,0x1D,0x00,0x1C,0x00,0x32,0x00,
    0x63,0x00,0x41,0x00,0x7F,0x00,0x60,0x00,0x60,0x00,0x30,0x00,0x1F,0x00,0x1C,0x30,
    0x20,0x78,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x40,0x00,0xC0,0xC0,0xC0,
    0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xDC,0xE6,0xC2,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0x1E,
    0x00,0x33,0x00,0x61,0x00,0x41,0x80,0x41,0x80,0x41,0x80,0x61,0x00,0x33,0x00,0x1E,
    0x00,0xD8,0xE0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x20,0x20,0xF8,0x60,0x60,0x60,
    0x60,0x60,0x60,0x20,0x38,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0x67,0x7B,0xC3,0x00,
    0x43,0x00,0x42,0x00,0x66,0x00,0x26,0x00,0x24,0x00,0x3C,0x00,0x18,0x00,0x18,0x00,
    0x18,0x00,0x10,0x00,0x30,0x00,0xE0,0x00,
};

leFont NotoSans_Regular =
{
    {
        LE_ASSET_TYPE_FONT, // asset type
        LE_ASSET_LOCATION_ID_INTERNAL, // data location id
        (void*)NotoSans_Regular_data, // data address pointer
        232, // data size
    },
    9,
    12,
    LE_FONT_BPP_1, // bits per pixel
    NotoSans_Regular_glyphs, // glyph table
    NotoSans_Regular_data, // font data
};
