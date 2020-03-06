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
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_font.h

  Summary:
    Describes font assets

  Description:
    Type definitions.
*******************************************************************************/

// DOM-IGNORE-BEGIN
#ifndef LE_FONT_H
#define LE_FONT_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_color.h"
#include "gfx/legato/core/legato_stream.h"

// *****************************************************************************
/* Enumeration:
    leFontBPP

  Summary:
    Indicates the bits per pixel mode of a font
*/
typedef enum leFontBPP
{
    LE_FONT_BPP_1, // standard
    LE_FONT_BPP_8  // antialiased
} leFontBPP;

// *****************************************************************************
/* Structure:
    struct leFontGlyph

  Summary:
    Describes a font glyph.  A glyph is an individual character of a font.
    Each glyph contains kerning data and options unique to itself.  This
    data is used for proper glyph positioning when rendering text.

    leChar codePoint - the code point of the glyph
    int16_t width - the glyph's overall width
    int16_t height - the glyph's overall height
    int16_t advance - the amount the cursor should advance when preparing to
                      render this glyph
    int16_t bearingX - the X offset from the advance
    int16_t bearingY - the Y offset from the string baseline
    uint16_t flags - general purpose flags
    uint16_t dataRowWidth - the width of one row of glyph data in bytes
    uint32_t dataOffset - the offset of this glyph in the font glyph table
*/
typedef struct leFontGlyph
{
    leChar codePoint;
    int16_t width;
    int16_t height;
    int16_t advance;
    int16_t bearingX;
    int16_t bearingY;
    uint16_t flags;
    uint16_t dataRowWidth;
    uint32_t dataOffset;
} leFontGlyph;

// *****************************************************************************
/* Enumeration:
    enum leFontType

  Summary:
    Defines font types.  Currently only raster fonts are supported but this
    differentiation will allow for future expansion into vector font support.
*/
typedef enum leFontType
{
    LE_RASTER_FONT,
    LE_VECTOR_FONT
} leFontType;

// *****************************************************************************
/* Structure:
    struct leFont

  Summary:
    The base definition of a font object.
    
    leStreamDescriptor header - describes where the font data is located
    leFontType type - indicates the type of font
*/
typedef struct leFont
{
    leStreamDescriptor header;
    leFontType type;
} leFont;

// *****************************************************************************
/* Structure:
    leFontAsset

  Summary:
    Describes a rasterized font object.  A raster font asset is a series of
    raster images that represent linguistic characters.  These characters are
    referenced by an index called a 'code point'.  This code point is 1-2 bytes
    in length.  Code points may be encoded to save space.  Fonts also contain
    general kerning data that describes character positioning data.

    struct leFont base - base font data
    uint16_t height - font height in pixels
    uint16_t baseline - the general font baseline in pixels;
    leFontBPP bpp - the bits per pixel value of this font.
    const uint8_t* glyphTable - pointer to the font's glyph data table
*/
typedef struct leRasterFont
{
    struct leFont base;
    uint16_t height;
    uint16_t baseline;
    leFontBPP bpp;
    const uint8_t* glyphTable;
} leRasterFont;

#if LE_STREAMING_ENABLED == 1
// *****************************************************************************
/* Type:
    leFontStream_DrawCompleteFn

  Summary:
    Defines a callback to indicate that a font stream has finished decoding
    a glyph.
*/
typedef void (*leFontStream_DrawCompleteFn)(uint32_t codepoint);

// *****************************************************************************
/* Structure:
    struct leFontStream

  Summary:
    A specialized stream object that is capable of streaming and rendering
    font glyph data

    leStream stream - base stream data
    leResult open - function that opens this stream
    leResult drawGlyph - function that streams and renders font glyph data

                         Arguments:
                         const leFontGlyph* glyph - the glyph to render
                         int32_t x - screen X location to render the glyph
                         int32_t y - screen Y location to render the glyph
                         leColor clr - the glyph render color
                         uint32_t alpha - a global alpha value to apply
                         leFontStream_DrawCompleteFn cb - callback to be called when the glyph
                                                          finished drawing

    leBool isDone - function that queries if the stream is finished
    void close - function that closes the stream

    leFontStream_DrawCompleteFn cb - callback that indicates when the stream has finished a particular code point
*/
typedef struct leFontStream
{
    leStream stream;

    leResult (*open)();
    leResult (*drawGlyph)(const leFontGlyph* glyph, int32_t x, int32_t y, leColor clr, uint32_t alpha, leFontStream_DrawCompleteFn cb);
    leBool (*isDone)();
    void (*close)();

    leFontStream_DrawCompleteFn cb;
} leFontStream;
#endif

#if LE_INCLUDE_DEFAULT_1BPP_FONT == 1
// *****************************************************************************
/* Type:
    leRasterFont LiberationMono1

  Summary:
    A pre-defined 12 point monospaced 1bpp font that includes the standard
    ASCII range of characters.
*/
LIB_EXPORT extern leRasterFont LiberationMono1;
#endif

#if LE_INCLUDE_DEFAULT_8BPP_FONT == 1
// *****************************************************************************
/* Type:
    lleRasterFont LiberationMono8

  Summary:
    A pre-defined 12 point monospaced 8bpp font that includes the standard
    ASCII range of characters.
*/
LIB_EXPORT extern leRasterFont LiberationMono8;
#endif

// *****************************************************************************
/* Function:
    leResult leFont_GetGlyphInfo(const leFont* fnt,
                                 uint32_t codepoint,
                                 leFontGlyph* glyph)

   Summary:
    Given a font asset and a codepoint, retrieves the glyph kerning data from
    the font glyph data table.

   Parameters:
    const leFont* fnt - the font to query
    uint32_t codepoint - the codepoint to lookup
    leFontGlyph* glyph - the glyph data that was retrieved

  Returns:

  Remarks:
*/
leResult leFont_GetGlyphInfo(const leFont* fnt,
                             uint32_t codepoint,
                             leFontGlyph* glyph);

// *****************************************************************************
/* Function:
    leResult leFont_GetGlyphRect(const leFontGlyph* glyph,
                                 leRect* rect)

   Summary:
    Given a font asset and a codepoint, retrieves the glyph rectangle in pixels.

   Parameters:
    const leFontGlyph* glyph - the glyph kerning information
    leRect* rect - the glyph rectangle in pixels

  Returns:

  Remarks:
*/
leResult leFont_GetGlyphRect(const leFontGlyph* glyph,
                             leRect* rect);

// *****************************************************************************
/* Function:
    void leFont_DrawUnknownGlyph(int32_t x,
                                 int32_t y,
                                 const leFontGlyph* glyph,
                                 leColor clr,
                                 uint32_t a)

   Summary:
    Draws the 'unknown glyph' symbol

   Parameters:
    int32_t x - the screen x location to draw
    int32_t y - the screen y location to draw
    const leFontGlyph* glyph - the glyph kerning information
    leColor clr - the glyph render color
    uint32_t alpha - a global alpha value to apply

  Returns:

  Remarks:
*/
void leFont_DrawUnknownGlyph(int32_t x,
                             int32_t y,
                             const leFontGlyph* glyph,
                             leColor clr,
                             uint32_t a);

// *****************************************************************************
/* Function:
    leResult leFont_DrawGlyph(const leFont* fnt,
                              const leFontGlyph* glyph,
                              int32_t x,
                              int32_t y,
                              leColor clr,
                              uint32_t a)

   Summary:
    Draws a glyph

   Parameters:
    const leFont* fnt - the font object to draw
    const leFontGlyph* glyph - the glyph kerning information
    int32_t x - the screen x location to draw
    int32_t y - the screen y location to draw
    leColor clr - the glyph render color
    uint32_t alpha - a global alpha value to apply

  Returns:

  Remarks:
*/
leResult leFont_DrawGlyph(const leFont* fnt,
                          const leFontGlyph* glyph,
                          int32_t x,
                          int32_t y,
                          leColor clr,
                          uint32_t a);

// *****************************************************************************
/* Function:
    leResult leFont_DrawGlyphData(const leFont* fnt,
                                  const leFontGlyph* glyph,
                                  const uint8_t* data,
                                  int32_t x,
                                  int32_t y,
                                  leColor clr,
                                  uint32_t a)

   Summary:
    Draws a glyph from a raw data buffer

   Parameters:
    const leFont* fnt - the font object to draw
    const leFontGlyph* glyph - the glyph kerning information
    const uint8_t* data - the data buffer to reference
    int32_t x - the screen x location to draw
    int32_t y - the screen y location to draw
    leColor clr - the glyph render color
    uint32_t alpha - a global alpha value to apply

  Returns:

  Remarks:
*/
leResult leFont_DrawGlyphData(const leFont* fnt,
                              const leFontGlyph* glyph,
                              const uint8_t* data,
                              int32_t x,
                              int32_t y,
                              leColor clr,
                              uint32_t a);

// *****************************************************************************
/* Function:
    void leFont_DrawGlyphRow(leFontBPP bpp,
                             const uint8_t* data,
                             int32_t x,
                             int32_t y,
                             int32_t colStart,
                             int32_t colEnd,
                             leColor clr,
                             uint32_t a)

   Summary:
    Draws a glyph from a raw data buffer

   Parameters:
    leFontBPP bpp - the data format of the row data
    const uint8_t* data - the data to reference
    int32_t x - the screen x location to draw
    int32_t y - the screen y location to draw
    int32_t colStart - index of the start of the data
    int32_t colEnd - index of the end of the data
    leColor clr - the glyph render color
    uint32_t alpha - a global alpha value to apply

  Returns:

  Remarks:
*/
void leFont_DrawGlyphRow(leFontBPP bpp,
                         const uint8_t* data,
                         int32_t x,
                         int32_t y,
                         int32_t colStart,
                         int32_t colEnd,
                         leColor clr,
                         uint32_t a);

#if LE_STREAMING_ENABLED == 1
// *****************************************************************************
/* Function:
    leFontStream* leFont_GetStream(const leFont* fnt)

   Summary:
    Creates a font stream for a given font

   Parameters:
    const leFont* fnt - the font to stream

  Returns:

  Remarks:
*/
leFontStream* leFont_GetStream(const leFont* fnt);
#endif

#endif /* LE_FONT_H */