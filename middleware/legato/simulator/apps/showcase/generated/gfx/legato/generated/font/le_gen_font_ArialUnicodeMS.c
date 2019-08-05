#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         ArialUnicodeMS
 * Height:       17
 * Baseline:     12
 * Style:        Antialias
 * Glyph Count:  57
 * Range Count:  12
 * Glyph Ranges: 0x20
                 0x28-0x29
                 0x2B-0x39
                 0x3C
                 0x3E-0x3F
                 0x41-0x42
                 0x44-0x45
                 0x48
                 0x4B-0x4C
                 0x53-0x54
                 0x57
                 0x61-0x7A
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
const uint8_t ArialUnicodeMS_glyphs[1144] =
{
    0x39,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x05,0x00,0x0F,0x00,0x05,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x29,0x00,0x05,0x00,
    0x0F,0x00,0x05,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x05,0x00,0x4B,0x00,0x00,0x00,
    0x2B,0x00,0x09,0x00,0x08,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,
    0x96,0x00,0x00,0x00,0x2C,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x02,0x00,
    0x00,0x00,0x04,0x00,0xDE,0x00,0x00,0x00,0x2D,0x00,0x05,0x00,0x03,0x00,0x05,0x00,
    0x00,0x00,0x06,0x00,0x00,0x00,0x05,0x00,0xEE,0x00,0x00,0x00,0x2E,0x00,0x03,0x00,
    0x03,0x00,0x04,0x00,0x01,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0xFD,0x00,0x00,0x00,
    0x2F,0x00,0x06,0x00,0x0C,0x00,0x06,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x06,0x00,
    0x06,0x01,0x00,0x00,0x30,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0x4E,0x01,0x00,0x00,0x31,0x00,0x05,0x00,0x0C,0x00,0x09,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x05,0x00,0xBA,0x01,0x00,0x00,0x32,0x00,0x09,0x00,
    0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0xF6,0x01,0x00,0x00,
    0x33,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,
    0x62,0x02,0x00,0x00,0x34,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0xCE,0x02,0x00,0x00,0x35,0x00,0x08,0x00,0x0C,0x00,0x09,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0x3A,0x03,0x00,0x00,0x36,0x00,0x09,0x00,
    0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0x9A,0x03,0x00,0x00,
    0x37,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,
    0x06,0x04,0x00,0x00,0x38,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0x72,0x04,0x00,0x00,0x39,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0xDE,0x04,0x00,0x00,0x3C,0x00,0x09,0x00,
    0x09,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0x4A,0x05,0x00,0x00,
    0x3E,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,
    0x9B,0x05,0x00,0x00,0x3F,0x00,0x07,0x00,0x0C,0x00,0x07,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x07,0x00,0xEC,0x05,0x00,0x00,0x41,0x00,0x0B,0x00,0x0C,0x00,0x0A,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x0B,0x00,0x40,0x06,0x00,0x00,0x42,0x00,0x09,0x00,
    0x0C,0x00,0x0A,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0xC4,0x06,0x00,0x00,
    0x44,0x00,0x0A,0x00,0x0C,0x00,0x0C,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,
    0x30,0x07,0x00,0x00,0x45,0x00,0x07,0x00,0x0C,0x00,0x09,0x00,0x01,0x00,0x0C,0x00,
    0x00,0x00,0x07,0x00,0xA8,0x07,0x00,0x00,0x48,0x00,0x0A,0x00,0x0C,0x00,0x0C,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,0xFC,0x07,0x00,0x00,0x4B,0x00,0x09,0x00,
    0x0C,0x00,0x0A,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0x74,0x08,0x00,0x00,
    0x4C,0x00,0x07,0x00,0x0C,0x00,0x08,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x07,0x00,
    0xE0,0x08,0x00,0x00,0x53,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0x34,0x09,0x00,0x00,0x54,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0xA0,0x09,0x00,0x00,0x57,0x00,0x0F,0x00,
    0x0C,0x00,0x0F,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0F,0x00,0x0C,0x0A,0x00,0x00,
    0x61,0x00,0x08,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x08,0x00,
    0xC0,0x0A,0x00,0x00,0x62,0x00,0x08,0x00,0x0C,0x00,0x0A,0x00,0x01,0x00,0x0C,0x00,
    0x00,0x00,0x08,0x00,0x08,0x0B,0x00,0x00,0x63,0x00,0x08,0x00,0x09,0x00,0x08,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x08,0x00,0x68,0x0B,0x00,0x00,0x64,0x00,0x09,0x00,
    0x0C,0x00,0x0A,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0xB0,0x0B,0x00,0x00,
    0x65,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,
    0x1C,0x0C,0x00,0x00,0x66,0x00,0x07,0x00,0x0C,0x00,0x06,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x07,0x00,0x6D,0x0C,0x00,0x00,0x67,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0xC1,0x0C,0x00,0x00,0x68,0x00,0x08,0x00,
    0x0C,0x00,0x0A,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0x36,0x0D,0x00,0x00,
    0x69,0x00,0x02,0x00,0x0C,0x00,0x04,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x02,0x00,
    0x96,0x0D,0x00,0x00,0x6A,0x00,0x04,0x00,0x10,0x00,0x04,0x00,0xFF,0xFF,0x0C,0x00,
    0x00,0x00,0x04,0x00,0xAE,0x0D,0x00,0x00,0x6B,0x00,0x08,0x00,0x0C,0x00,0x09,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0xEE,0x0D,0x00,0x00,0x6C,0x00,0x02,0x00,
    0x0C,0x00,0x04,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x02,0x00,0x4E,0x0E,0x00,0x00,
    0x6D,0x00,0x0D,0x00,0x09,0x00,0x0F,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x0D,0x00,
    0x66,0x0E,0x00,0x00,0x6E,0x00,0x08,0x00,0x09,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,
    0x00,0x00,0x08,0x00,0xDB,0x0E,0x00,0x00,0x6F,0x00,0x09,0x00,0x09,0x00,0x0A,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x23,0x0F,0x00,0x00,0x70,0x00,0x08,0x00,
    0x0D,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x08,0x00,0x74,0x0F,0x00,0x00,
    0x71,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,
    0xDC,0x0F,0x00,0x00,0x72,0x00,0x06,0x00,0x09,0x00,0x07,0x00,0x01,0x00,0x09,0x00,
    0x00,0x00,0x06,0x00,0x51,0x10,0x00,0x00,0x73,0x00,0x07,0x00,0x09,0x00,0x08,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x07,0x00,0x87,0x10,0x00,0x00,0x74,0x00,0x06,0x00,
    0x0B,0x00,0x06,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x06,0x00,0xC6,0x10,0x00,0x00,
    0x75,0x00,0x08,0x00,0x09,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x08,0x00,
    0x08,0x11,0x00,0x00,0x76,0x00,0x09,0x00,0x09,0x00,0x08,0x00,0x00,0x00,0x09,0x00,
    0x00,0x00,0x09,0x00,0x50,0x11,0x00,0x00,0x77,0x00,0x0D,0x00,0x09,0x00,0x0D,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x0D,0x00,0xA1,0x11,0x00,0x00,0x78,0x00,0x09,0x00,
    0x09,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x16,0x12,0x00,0x00,
    0x79,0x00,0x09,0x00,0x0D,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,
    0x67,0x12,0x00,0x00,0x7A,0x00,0x07,0x00,0x09,0x00,0x08,0x00,0x00,0x00,0x09,0x00,
    0x00,0x00,0x07,0x00,0xDC,0x12,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t ArialUnicodeMS_data[4891] =
{
    0x00,0x00,0x58,0xEE,0x14,0x00,0x0F,0xEA,0x6E,0x00,0x00,0x6D,0xF2,0x0C,0x00,0x00,
    0xCD,0xA0,0x00,0x00,0x0C,0xFD,0x63,0x00,0x00,0x39,0xFF,0x32,0x00,0x00,0x4E,0xFF,
    0x1E,0x00,0x00,0x57,0xFF,0x15,0x00,0x00,0x47,0xFF,0x26,0x00,0x00,0x2A,0xFF,0x45,
    0x00,0x00,0x01,0xF0,0x7E,0x00,0x00,0x00,0xA8,0xCB,0x00,0x00,0x00,0x3D,0xFF,0x31,
    0x00,0x00,0x00,0xAD,0xB6,0x00,0x00,0x00,0x16,0x7C,0x12,0x39,0xF7,0x2A,0x00,0x00,
    0x00,0xA4,0xC6,0x00,0x00,0x00,0x36,0xFF,0x39,0x00,0x00,0x00,0xD8,0x99,0x00,0x00,
    0x00,0x9A,0xD5,0x00,0x00,0x00,0x68,0xFE,0x06,0x00,0x00,0x53,0xFF,0x19,0x00,0x00,
    0x49,0xFF,0x22,0x00,0x00,0x5C,0xFF,0x12,0x00,0x00,0x7B,0xF3,0x01,0x00,0x00,0xB6,
    0xBD,0x00,0x00,0x0D,0xF4,0x73,0x00,0x00,0x67,0xF7,0x13,0x00,0x0A,0xE1,0x79,0x00,
    0x00,0x2C,0x75,0x03,0x00,0x00,0x00,0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x00,
    0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x00,0x04,0x04,0x07,0xFF,0x27,0x04,0x04,
    0x01,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x50,0x09,0x30,0x30,0x33,0xFF,0x4D,
    0x30,0x30,0x0F,0x00,0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
    0xFF,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x00,0xA0,
    0xF1,0x03,0x00,0xCD,0xA5,0x00,0x08,0xFA,0x4A,0x00,0x3C,0xE3,0x02,0x00,0x01,0x04,
    0x04,0x04,0x02,0x5C,0xFF,0xFF,0xFF,0x84,0x11,0x30,0x30,0x30,0x18,0x04,0x0D,0x00,
    0xBB,0xF3,0x10,0x9D,0xD8,0x0A,0x00,0x00,0x00,0x00,0xC2,0x9D,0x00,0x00,0x00,0x1E,
    0xFE,0x42,0x00,0x00,0x00,0x78,0xE5,0x02,0x00,0x00,0x00,0xD3,0x8C,0x00,0x00,0x00,
    0x2D,0xFF,0x31,0x00,0x00,0x00,0x89,0xD7,0x00,0x00,0x00,0x01,0xE2,0x7B,0x00,0x00,
    0x00,0x3F,0xFF,0x21,0x00,0x00,0x00,0x9A,0xC5,0x00,0x00,0x00,0x06,0xEE,0x6A,0x00,
    0x00,0x00,0x50,0xFB,0x14,0x00,0x00,0x00,0xAB,0xB5,0x00,0x00,0x00,0x00,0x00,0x00,
    0x53,0xD2,0xF6,0xDA,0x64,0x00,0x00,0x00,0x42,0xFD,0x88,0x3C,0x77,0xFC,0x55,0x00,
    0x00,0xBA,0xB4,0x00,0x00,0x00,0x99,0xD5,0x00,0x04,0xF7,0x66,0x00,0x00,0x00,0x48,
    0xFF,0x20,0x22,0xFF,0x41,0x00,0x00,0x00,0x23,0xFF,0x48,0x31,0xFF,0x33,0x00,0x00,
    0x00,0x13,0xFF,0x5A,0x33,0xFF,0x33,0x00,0x00,0x00,0x15,0xFF,0x58,0x22,0xFF,0x42,
    0x00,0x00,0x00,0x23,0xFF,0x49,0x03,0xF5,0x66,0x00,0x00,0x00,0x48,0xFF,0x20,0x00,
    0xB1,0xB3,0x00,0x00,0x00,0x97,0xDC,0x00,0x00,0x37,0xFC,0x86,0x3B,0x75,0xFB,0x5E,
    0x00,0x00,0x00,0x4F,0xD3,0xF8,0xDA,0x66,0x00,0x00,0x00,0x00,0x32,0xE3,0xB0,0x00,
    0x55,0xF5,0xEB,0xB0,0x52,0xFB,0x66,0xAE,0xB0,0x0B,0x41,0x00,0xB3,0xB0,0x00,0x00,
    0x00,0xB4,0xB0,0x00,0x00,0x00,0xB4,0xB0,0x00,0x00,0x00,0xB4,0xB0,0x00,0x00,0x00,
    0xB4,0xB0,0x00,0x00,0x00,0xB4,0xB0,0x00,0x00,0x00,0xB4,0xB0,0x00,0x00,0x00,0xB4,
    0xB0,0x00,0x00,0x00,0xB4,0xB0,0x00,0x0E,0x8D,0xE3,0xF6,0xD4,0x62,0x00,0x00,0x03,
    0xD3,0xCE,0x57,0x3D,0x85,0xFF,0x5C,0x00,0x00,0x2F,0x06,0x00,0x00,0x00,0xBA,0xBB,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9C,0xD2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xD2,0xA4,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xFE,0x35,0x00,0x00,0x00,0x00,0x00,
    0x30,0xF2,0x88,0x00,0x00,0x00,0x00,0x00,0x20,0xE6,0xA7,0x01,0x00,0x00,0x00,0x00,
    0x18,0xDB,0xB7,0x05,0x00,0x00,0x00,0x00,0x12,0xD2,0xC0,0x09,0x00,0x00,0x00,0x00,
    0x0C,0xC9,0xE4,0x40,0x34,0x34,0x34,0x34,0x10,0x3C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x50,0x00,0x3F,0xB0,0xEB,0xF7,0xD9,0x7B,0x04,0x00,0x0C,0xE3,0x9E,0x4B,0x3C,
    0x78,0xFB,0x82,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0xA3,0xD3,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xB2,0xC3,0x00,0x00,0x00,0x02,0x06,0x20,0x80,0xF4,0x42,0x00,0x00,
    0x00,0x88,0xFF,0xFF,0xE5,0x4E,0x00,0x00,0x00,0x00,0x19,0x32,0x47,0x8B,0xF9,0x7E,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0xFC,0x15,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x85,0xFB,0x12,0x44,0xB3,0x62,0x40,
    0x47,0x89,0xFA,0x92,0x00,0x1F,0xA6,0xE5,0xF8,0xF3,0xCD,0x6D,0x03,0x00,0x00,0x00,
    0x00,0x00,0x00,0x9F,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x4A,0xF1,0xFF,0x2C,0x00,
    0x00,0x00,0x00,0x10,0xE5,0x88,0xFF,0x2C,0x00,0x00,0x00,0x00,0xA3,0xBB,0x2F,0xFF,
    0x2C,0x00,0x00,0x00,0x4E,0xF0,0x1D,0x30,0xFF,0x2C,0x00,0x00,0x12,0xE7,0x60,0x00,
    0x30,0xFF,0x2C,0x00,0x00,0xA7,0xB2,0x00,0x00,0x30,0xFF,0x2C,0x00,0x52,0xF1,0x27,
    0x10,0x10,0x3D,0xFF,0x39,0x0D,0xA8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD4,0x27,
    0x3C,0x3C,0x3C,0x3C,0x60,0xFF,0x5D,0x31,0x00,0x00,0x00,0x00,0x00,0x30,0xFF,0x2C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xFF,0x2C,0x00,0x52,0xFF,0xFF,0xFF,0xFF,0xFF,
    0x70,0x00,0x64,0xE7,0x34,0x34,0x34,0x34,0x16,0x00,0x77,0xD1,0x00,0x00,0x00,0x00,
    0x00,0x00,0x8A,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x9C,0xAF,0x00,0x00,0x00,0x00,
    0x00,0x00,0xAF,0xF2,0xF0,0xFB,0xDD,0x84,0x0C,0x00,0x2D,0x63,0x3C,0x40,0x7A,0xF3,
    0xBA,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0xFF,0x22,0x00,0x00,0x00,0x00,0x00,0x40,
    0xFF,0x35,0x00,0x00,0x00,0x00,0x00,0x7C,0xFA,0x10,0xAD,0x64,0x42,0x44,0x88,0xFA,
    0x88,0x00,0x92,0xDD,0xF6,0xED,0xC7,0x5A,0x01,0x00,0x00,0x00,0x00,0x60,0xC7,0xF0,
    0xFB,0x75,0x00,0x00,0x00,0x96,0xF1,0x7F,0x42,0x3C,0x2E,0x00,0x00,0x45,0xFD,0x33,
    0x00,0x00,0x00,0x00,0x00,0x00,0xAC,0xAF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE8,
    0x75,0x95,0xF1,0xEF,0xAA,0x17,0x00,0x03,0xFE,0xE0,0x9B,0x3B,0x55,0xE0,0xC6,0x01,
    0x17,0xFF,0xA2,0x00,0x00,0x00,0x42,0xFF,0x36,0x13,0xFF,0x53,0x00,0x00,0x00,0x08,
    0xFF,0x5B,0x01,0xF3,0x6C,0x00,0x00,0x00,0x11,0xFF,0x4E,0x00,0xAC,0xC9,0x02,0x00,
    0x00,0x52,0xFD,0x21,0x00,0x2A,0xF6,0xA8,0x41,0x61,0xE9,0xA0,0x00,0x00,0x00,0x37,
    0xC0,0xF5,0xEA,0x93,0x09,0x00,0x4C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x60,0x0F,
    0x34,0x34,0x34,0x34,0x34,0x74,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0xB4,0xBF,
    0x00,0x00,0x00,0x00,0x00,0x00,0x25,0xFE,0x53,0x00,0x00,0x00,0x00,0x00,0x00,0x92,
    0xE3,0x03,0x00,0x00,0x00,0x00,0x00,0x0E,0xF2,0x7A,0x00,0x00,0x00,0x00,0x00,0x00,
    0x71,0xF8,0x15,0x00,0x00,0x00,0x00,0x00,0x02,0xDD,0xA2,0x00,0x00,0x00,0x00,0x00,
    0x00,0x4F,0xFF,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0xBE,0xCA,0x00,0x00,0x00,0x00,
    0x00,0x00,0x2D,0xFF,0x5E,0x00,0x00,0x00,0x00,0x00,0x00,0x9C,0xEA,0x07,0x00,0x00,
    0x00,0x00,0x00,0x02,0x7A,0xDC,0xF8,0xDE,0x86,0x08,0x00,0x00,0x7D,0xF9,0x71,0x3C,
    0x66,0xF0,0x99,0x00,0x00,0xCC,0x9E,0x00,0x00,0x00,0x7E,0xE9,0x00,0x00,0xBC,0xA7,
    0x00,0x00,0x00,0x8A,0xDF,0x00,0x00,0x4C,0xFC,0x79,0x05,0x54,0xF4,0x51,0x00,0x00,
    0x00,0x54,0xFB,0xF1,0xFA,0x47,0x00,0x00,0x00,0x1D,0xCD,0xCC,0x7A,0xDF,0xD8,0x29,
    0x00,0x01,0xD0,0xAD,0x04,0x00,0x09,0xAA,0xE3,0x0E,0x2B,0xFF,0x38,0x00,0x00,0x00,
    0x1B,0xFF,0x50,0x1B,0xFF,0x51,0x00,0x00,0x00,0x34,0xFF,0x45,0x00,0xBC,0xE5,0x64,
    0x3C,0x5B,0xDA,0xD7,0x06,0x00,0x12,0x8F,0xDD,0xF7,0xE1,0x97,0x17,0x00,0x00,0x03,
    0x7C,0xDF,0xF7,0xCF,0x52,0x00,0x00,0x00,0x8C,0xF2,0x6F,0x3E,0x7D,0xFB,0x52,0x00,
    0x0B,0xF6,0x72,0x00,0x00,0x00,0x81,0xDB,0x00,0x2B,0xFF,0x3A,0x00,0x00,0x00,0x2B,
    0xFF,0x24,0x18,0xFF,0x51,0x00,0x00,0x00,0x3D,0xFF,0x42,0x00,0xCA,0xD2,0x30,0x0B,
    0x42,0xDA,0xFF,0x47,0x00,0x25,0xCA,0xFF,0xFF,0xDF,0x67,0xFF,0x31,0x00,0x00,0x00,
    0x17,0x24,0x02,0x50,0xFF,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0xA3,0xDD,0x00,0x00,
    0x00,0x00,0x00,0x00,0x2A,0xF7,0x77,0x00,0x00,0x28,0x4C,0x3F,0x76,0xEE,0xC3,0x06,
    0x00,0x00,0x55,0xF8,0xF5,0xD4,0x7C,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x50,0x39,0x00,0x00,0x00,0x00,0x01,0x50,0xCF,0xE3,0x34,0x00,0x00,0x01,0x51,
    0xCF,0xD9,0x63,0x06,0x00,0x01,0x51,0xD0,0xCD,0x55,0x02,0x00,0x00,0x00,0x2D,0xFE,
    0xC7,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x25,0x94,0xF1,0xB5,0x4A,0x02,0x00,0x00,
    0x00,0x00,0x00,0x10,0x74,0xE1,0xDD,0x75,0x0F,0x00,0x00,0x00,0x00,0x00,0x03,0x55,
    0xC6,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x23,0x62,0x04,0x00,0x00,
    0x00,0x00,0x00,0x00,0x1D,0xD7,0xDD,0x62,0x04,0x00,0x00,0x00,0x00,0x00,0x02,0x54,
    0xCD,0xDE,0x63,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xC2,0xDE,0x63,0x04,0x00,
    0x00,0x00,0x00,0x00,0x15,0xB1,0xFF,0x4F,0x00,0x00,0x00,0x3A,0xA4,0xF3,0xA3,0x32,
    0x00,0x07,0x66,0xD0,0xEB,0x84,0x19,0x00,0x00,0x00,0x34,0xD4,0x65,0x08,0x00,0x00,
    0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4E,0xB7,0xE4,0xF6,
    0xD0,0x50,0x00,0x7A,0x9A,0x54,0x3F,0x94,0xFB,0x30,0x00,0x00,0x00,0x00,0x00,0xE2,
    0x76,0x00,0x00,0x00,0x00,0x07,0xEF,0x68,0x00,0x00,0x00,0x01,0x99,0xEC,0x17,0x00,
    0x00,0x00,0x9B,0xEC,0x37,0x00,0x00,0x00,0x62,0xEC,0x28,0x00,0x00,0x00,0x00,0xB3,
    0x7C,0x00,0x00,0x00,0x00,0x00,0x64,0x30,0x00,0x00,0x00,0x00,0x00,0x0D,0x03,0x00,
    0x00,0x00,0x00,0x0E,0xF4,0xB9,0x00,0x00,0x00,0x00,0x09,0xD9,0x9A,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xB8,0xEC,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0xFC,
    0xF4,0x51,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0xD6,0xA6,0xB0,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xD5,0x89,0x52,0xFA,0x14,0x00,0x00,0x00,0x00,0x00,0x35,0xFF,
    0x2D,0x07,0xEF,0x6D,0x00,0x00,0x00,0x00,0x00,0x95,0xD0,0x00,0x00,0x9B,0xCC,0x00,
    0x00,0x00,0x00,0x06,0xED,0x81,0x14,0x14,0x51,0xFF,0x2B,0x00,0x00,0x00,0x53,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0x89,0x00,0x00,0x00,0xB3,0xC1,0x40,0x40,0x40,0x40,0xA3,
    0xE5,0x02,0x00,0x16,0xFB,0x5B,0x00,0x00,0x00,0x00,0x33,0xFF,0x46,0x00,0x71,0xF3,
    0x0B,0x00,0x00,0x00,0x00,0x00,0xD4,0xA5,0x00,0xD0,0xA2,0x00,0x00,0x00,0x00,0x00,
    0x00,0x77,0xF6,0x0E,0x74,0xFF,0xFF,0xFF,0xF7,0xDA,0x93,0x17,0x00,0x74,0xFC,0x34,
    0x34,0x42,0x72,0xF0,0xCF,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x75,0xFF,0x1D,0x74,
    0xFC,0x00,0x00,0x00,0x00,0x6C,0xFE,0x10,0x74,0xFC,0x04,0x04,0x0D,0x3B,0xDB,0x99,
    0x00,0x74,0xFF,0xFF,0xFF,0xFF,0xFF,0x89,0x02,0x00,0x74,0xFC,0x30,0x30,0x3A,0x64,
    0xE1,0xC3,0x07,0x74,0xFC,0x00,0x00,0x00,0x00,0x39,0xFF,0x5E,0x74,0xFC,0x00,0x00,
    0x00,0x00,0x0A,0xFF,0x81,0x74,0xFC,0x00,0x00,0x00,0x00,0x40,0xFF,0x65,0x74,0xFC,
    0x34,0x34,0x3B,0x65,0xE3,0xE4,0x0F,0x74,0xFF,0xFF,0xFF,0xFC,0xDF,0x9B,0x1B,0x00,
    0x74,0xFF,0xFF,0xFF,0xF4,0xD5,0x87,0x16,0x00,0x00,0x74,0xFC,0x34,0x34,0x41,0x74,
    0xE0,0xE7,0x30,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x0F,0xCD,0xDA,0x06,0x74,0xFC,
    0x00,0x00,0x00,0x00,0x00,0x3D,0xFF,0x50,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x02,
    0xF2,0x91,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0xAA,0x74,0xFC,0x00,0x00,
    0x00,0x00,0x00,0x00,0xDA,0xA8,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x04,0xF6,0x8C,
    0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x4B,0xFF,0x4B,0x74,0xFC,0x00,0x00,0x00,0x00,
    0x18,0xDB,0xD3,0x02,0x74,0xFC,0x34,0x35,0x47,0x81,0xEA,0xE0,0x26,0x00,0x74,0xFF,
    0xFF,0xFF,0xF3,0xCC,0x7D,0x10,0x00,0x00,0x74,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x74,
    0xFC,0x34,0x34,0x34,0x34,0x30,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,
    0x00,0x00,0x00,0x00,0x74,0xFC,0x04,0x04,0x04,0x04,0x02,0x74,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xA4,0x74,0xFC,0x30,0x30,0x30,0x30,0x1E,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,
    0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,
    0x34,0x34,0x34,0x34,0x30,0x74,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x74,0xFC,0x00,0x00,
    0x00,0x00,0x00,0x28,0xFF,0x48,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x28,0xFF,0x48,
    0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x28,0xFF,0x48,0x74,0xFC,0x00,0x00,0x00,0x00,
    0x00,0x28,0xFF,0x48,0x74,0xFC,0x04,0x04,0x04,0x04,0x04,0x2B,0xFF,0x48,0x74,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x48,0x74,0xFC,0x30,0x30,0x30,0x30,0x30,0x50,
    0xFF,0x48,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x28,0xFF,0x48,0x74,0xFC,0x00,0x00,
    0x00,0x00,0x00,0x28,0xFF,0x48,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x28,0xFF,0x48,
    0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x28,0xFF,0x48,0x74,0xFC,0x00,0x00,0x00,0x00,
    0x00,0x28,0xFF,0x48,0x74,0xFC,0x00,0x00,0x00,0x00,0x60,0xFD,0x4F,0x74,0xFC,0x00,
    0x00,0x00,0x40,0xFA,0x70,0x00,0x74,0xFC,0x00,0x00,0x26,0xED,0x93,0x00,0x00,0x74,
    0xFC,0x00,0x12,0xDA,0xB3,0x03,0x00,0x00,0x74,0xFC,0x06,0xC1,0xCD,0x0B,0x00,0x00,
    0x00,0x74,0xFC,0xA2,0xFF,0x6C,0x00,0x00,0x00,0x00,0x74,0xFF,0xD3,0xBA,0xF1,0x20,
    0x00,0x00,0x00,0x74,0xFD,0x10,0x15,0xE8,0xC2,0x02,0x00,0x00,0x74,0xFC,0x00,0x00,
    0x49,0xFF,0x77,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x92,0xF9,0x30,0x00,0x74,0xFC,
    0x00,0x00,0x00,0x08,0xD4,0xD4,0x07,0x74,0xFC,0x00,0x00,0x00,0x00,0x2E,0xF8,0x8E,
    0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,
    0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,0x00,
    0x00,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,
    0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFC,0x00,0x00,0x00,0x00,0x00,0x74,
    0xFC,0x00,0x00,0x00,0x00,0x00,0x74,0xFD,0x50,0x50,0x50,0x50,0x4E,0x74,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFC,0x00,0x05,0x80,0xDD,0xF9,0xE8,0xC3,0x5C,0x00,0x00,0x96,0xF1,
    0x6A,0x3D,0x58,0x9C,0x6A,0x00,0x02,0xF7,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
    0xF7,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,0xF5,0x5D,0x02,0x00,0x00,0x00,
    0x00,0x00,0x18,0xC3,0xFF,0xDD,0x73,0x0B,0x00,0x00,0x00,0x00,0x01,0x4B,0xBB,0xFF,
    0xE2,0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xE8,0xCC,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x83,0xFD,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x8F,0xEA,0x00,0x28,0xA2,
    0x61,0x42,0x41,0x81,0xFA,0x78,0x00,0x19,0xB7,0xE5,0xF7,0xEE,0xC6,0x57,0x00,0x00,
    0xD8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB8,0x2B,0x34,0x34,0x6A,0xFF,0x57,0x34,
    0x34,0x25,0x00,0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,
    0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,
    0x44,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0x2C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0x2C,0x00,0x00,0x00,0xB0,0xD2,0x00,0x00,
    0x00,0x00,0x80,0xFF,0x44,0x00,0x00,0x00,0x02,0xF0,0x8A,0x6F,0xFE,0x11,0x00,0x00,
    0x00,0xC7,0xFE,0x8D,0x00,0x00,0x00,0x31,0xFF,0x49,0x2F,0xFF,0x4E,0x00,0x00,0x11,
    0xFC,0xBD,0xD7,0x00,0x00,0x00,0x6F,0xFB,0x0D,0x01,0xEC,0x8B,0x00,0x00,0x55,0xF9,
    0x45,0xFF,0x20,0x00,0x00,0xAD,0xC7,0x00,0x00,0xAD,0xC9,0x00,0x00,0x9C,0xBF,0x04,
    0xF0,0x6A,0x00,0x00,0xE9,0x86,0x00,0x00,0x6D,0xFB,0x0B,0x00,0xE3,0x78,0x00,0xAC,
    0xB3,0x00,0x28,0xFF,0x45,0x00,0x00,0x2C,0xFF,0x44,0x2B,0xFF,0x31,0x00,0x63,0xF5,
    0x07,0x66,0xFA,0x0A,0x00,0x00,0x01,0xEA,0x80,0x6F,0xE9,0x01,0x00,0x1B,0xFF,0x44,
    0xA2,0xC3,0x00,0x00,0x00,0x00,0xAB,0xB9,0xAE,0xA3,0x00,0x00,0x00,0xD2,0x85,0xDC,
    0x82,0x00,0x00,0x00,0x00,0x6A,0xE7,0xDF,0x5C,0x00,0x00,0x00,0x8A,0xC5,0xFE,0x41,
    0x00,0x00,0x00,0x00,0x29,0xFF,0xFD,0x17,0x00,0x00,0x00,0x41,0xFE,0xF8,0x08,0x00,
    0x00,0x00,0x00,0x00,0xE7,0xCF,0x00,0x00,0x00,0x00,0x05,0xF2,0xC0,0x00,0x00,0x00,
    0x00,0x14,0x8E,0xD6,0xF6,0xE1,0x84,0x01,0x00,0x14,0xC4,0x66,0x3F,0x82,0xFF,0x61,
    0x00,0x00,0x00,0x00,0x00,0x00,0xD4,0x9E,0x00,0x00,0x00,0x00,0x01,0x04,0xB7,0xB0,
    0x00,0x29,0xAE,0xEA,0xFE,0xFF,0xFF,0xB0,0x0A,0xE8,0xCE,0x59,0x3A,0x30,0xC6,0xB0,
    0x36,0xFF,0x40,0x00,0x00,0x04,0xE0,0xB0,0x16,0xF9,0xAA,0x3D,0x4D,0xB7,0xDF,0xB0,
    0x00,0x54,0xD8,0xF9,0xDC,0x61,0x70,0xB0,0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,
    0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC3,0x00,0x00,0x00,0x00,0x00,0x00,
    0xA4,0xBC,0x5D,0xDB,0xF9,0xD3,0x4D,0x00,0xA4,0xEB,0xC9,0x52,0x46,0xAC,0xFD,0x3B,
    0xA4,0xFC,0x19,0x00,0x00,0x02,0xDD,0xAD,0xA4,0xD9,0x00,0x00,0x00,0x00,0x99,0xE1,
    0xA4,0xC8,0x00,0x00,0x00,0x00,0x86,0xF0,0xA4,0xDB,0x00,0x00,0x00,0x00,0x9A,0xE0,
    0xA4,0xFD,0x1E,0x00,0x00,0x02,0xDF,0xAC,0xA4,0xEB,0xD0,0x54,0x45,0xAB,0xFD,0x3B,
    0xA4,0x7B,0x66,0xDE,0xF9,0xD3,0x4D,0x00,0x00,0x00,0x49,0xC4,0xF4,0xEE,0xBE,0x09,
    0x00,0x4A,0xFE,0xA2,0x46,0x4F,0x79,0x00,0x00,0xCC,0xC3,0x00,0x00,0x00,0x00,0x00,
    0x08,0xFF,0x74,0x00,0x00,0x00,0x00,0x00,0x1A,0xFF,0x5E,0x00,0x00,0x00,0x00,0x00,
    0x0A,0xFF,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0xD2,0xC0,0x00,0x00,0x00,0x00,0x00,
    0x00,0x53,0xFF,0x9E,0x43,0x48,0x84,0x02,0x00,0x00,0x52,0xCB,0xF6,0xF1,0xBE,0x02,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xEC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0x7C,0x00,0x00,0x68,0xDD,0xF8,
    0xCF,0x39,0xE7,0x7C,0x00,0x62,0xFF,0x97,0x42,0x60,0xDB,0xF3,0x7C,0x00,0xD7,0xC1,
    0x00,0x00,0x00,0x45,0xFF,0x7C,0x0D,0xFF,0x74,0x00,0x00,0x00,0x03,0xFD,0x7C,0x1C,
    0xFF,0x5E,0x00,0x00,0x00,0x00,0xEC,0x7C,0x0F,0xFF,0x70,0x00,0x00,0x00,0x01,0xF9,
    0x7C,0x00,0xDB,0xB8,0x00,0x00,0x00,0x39,0xFF,0x7C,0x00,0x68,0xFF,0x91,0x41,0x5B,
    0xD3,0xF1,0x7C,0x00,0x00,0x6E,0xDF,0xF9,0xD0,0x3A,0xBB,0x7C,0x00,0x00,0x49,0xCB,
    0xF6,0xE0,0x73,0x00,0x00,0x00,0x43,0xFD,0x9B,0x42,0x71,0xF9,0x75,0x00,0x00,0xC5,
    0xC5,0x00,0x00,0x00,0x90,0xEA,0x02,0x08,0xFE,0x7A,0x04,0x04,0x04,0x56,0xFF,0x22,
    0x1A,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x33,0x09,0xFF,0x86,0x30,0x30,0x30,0x30,
    0x30,0x09,0x00,0xCA,0xAF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0xFC,0x9F,0x48,
    0x3D,0x59,0x7B,0x00,0x00,0x00,0x3F,0xBD,0xF2,0xF6,0xDA,0x7F,0x00,0x00,0x00,0x55,
    0xD7,0xF8,0xDF,0x0F,0x00,0x13,0xF8,0xA3,0x3B,0x47,0x00,0x00,0x3A,0xFF,0x2E,0x00,
    0x00,0x00,0x7E,0xEC,0xFF,0xFF,0xFF,0x50,0x00,0x27,0x67,0xFF,0x53,0x34,0x10,0x00,
    0x00,0x40,0xFF,0x28,0x00,0x00,0x00,0x00,0x40,0xFF,0x28,0x00,0x00,0x00,0x00,0x40,
    0xFF,0x28,0x00,0x00,0x00,0x00,0x40,0xFF,0x28,0x00,0x00,0x00,0x00,0x40,0xFF,0x28,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x28,0x00,0x00,0x00,0x00,0x40,0xFF,0x28,0x00,0x00,
    0x00,0x00,0x00,0x66,0xDD,0xF9,0xCF,0x45,0xB6,0x7C,0x00,0x50,0xFF,0x96,0x42,0x62,
    0xDF,0xF0,0x7C,0x00,0xCB,0xBD,0x00,0x00,0x00,0x44,0xFF,0x7C,0x03,0xFB,0x72,0x00,
    0x00,0x00,0x02,0xFB,0x7C,0x18,0xFF,0x5E,0x00,0x00,0x00,0x00,0xE7,0x7C,0x04,0xFC,
    0x71,0x00,0x00,0x00,0x00,0xF6,0x7C,0x00,0xD0,0xB8,0x00,0x00,0x00,0x33,0xFF,0x7C,
    0x00,0x57,0xFF,0x91,0x41,0x5B,0xD3,0xF4,0x7C,0x00,0x00,0x6D,0xDF,0xF9,0xD1,0x45,
    0xE5,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF4,0x6E,0x00,0x00,0x00,0x00,0x00,
    0x00,0x39,0xFF,0x49,0x00,0x62,0x91,0x54,0x3C,0x5D,0xE1,0xD6,0x04,0x00,0x3C,0xBC,
    0xE9,0xFA,0xEE,0xAD,0x22,0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC4,
    0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xBF,
    0x59,0xD6,0xF7,0xD8,0x63,0x00,0xA4,0xE9,0xD2,0x57,0x40,0x9E,0xFF,0x39,0xA4,0xFD,
    0x20,0x00,0x00,0x04,0xEB,0x7E,0xA4,0xDA,0x00,0x00,0x00,0x00,0xCD,0x96,0xA4,0xC6,
    0x00,0x00,0x00,0x00,0xCC,0x98,0xA4,0xC4,0x00,0x00,0x00,0x00,0xCC,0x98,0xA4,0xC4,
    0x00,0x00,0x00,0x00,0xCC,0x98,0xA4,0xC4,0x00,0x00,0x00,0x00,0xCC,0x98,0xA4,0xC4,
    0x00,0x00,0x00,0x00,0xCC,0x98,0x94,0xB6,0x77,0x93,0x00,0x00,0xA4,0xC4,0xA4,0xC4,
    0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0x00,0x00,
    0x94,0xB6,0x00,0x00,0x77,0x93,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,
    0xA4,0xC4,0x00,0x00,0xA4,0xC4,0x00,0x00,0xA4,0xC4,0x00,0x00,0xA4,0xC4,0x00,0x00,
    0xA4,0xC4,0x00,0x00,0xA4,0xC4,0x00,0x00,0xA4,0xC4,0x00,0x00,0xA4,0xC4,0x00,0x00,
    0xA4,0xC4,0x00,0x00,0xAA,0xBC,0x3B,0x49,0xEA,0x8D,0xCD,0xF6,0xBA,0x17,0xA4,0xC0,
    0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC0,
    0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC0,0x00,0x00,0x14,0xDA,0xB1,0x03,0xA4,0xC0,
    0x00,0x0B,0xC9,0xC6,0x09,0x00,0xA4,0xC0,0x04,0xB5,0xD7,0x13,0x00,0x00,0xA4,0xBA,
    0x95,0xE9,0x1F,0x00,0x00,0x00,0xA4,0xED,0xF8,0xF7,0x2C,0x00,0x00,0x00,0xA4,0xE6,
    0x25,0xC6,0xD4,0x09,0x00,0x00,0xA4,0xC0,0x00,0x21,0xF2,0x97,0x00,0x00,0xA4,0xC0,
    0x00,0x00,0x5E,0xFF,0x51,0x00,0xA4,0xC0,0x00,0x00,0x00,0xA7,0xED,0x1D,0xA4,0xC4,
    0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,
    0xA4,0xC4,0xA4,0xC4,0xA4,0xC4,0xA4,0x92,0x63,0xDD,0xF8,0xCC,0x37,0x2C,0xBE,0xF6,
    0xE2,0x80,0x00,0xA4,0xE8,0xC7,0x50,0x49,0xD4,0xE5,0xDC,0x72,0x3F,0x87,0xFF,0x50,
    0xA4,0xFC,0x1A,0x00,0x00,0x50,0xFF,0x7E,0x00,0x00,0x00,0xDB,0x90,0xA4,0xD9,0x00,
    0x00,0x00,0x31,0xFF,0x44,0x00,0x00,0x00,0xBD,0xA7,0xA4,0xC5,0x00,0x00,0x00,0x30,
    0xFF,0x34,0x00,0x00,0x00,0xBC,0xA8,0xA4,0xC4,0x00,0x00,0x00,0x30,0xFF,0x34,0x00,
    0x00,0x00,0xBC,0xA8,0xA4,0xC4,0x00,0x00,0x00,0x30,0xFF,0x34,0x00,0x00,0x00,0xBC,
    0xA8,0xA4,0xC4,0x00,0x00,0x00,0x30,0xFF,0x34,0x00,0x00,0x00,0xBC,0xA8,0xA4,0xC4,
    0x00,0x00,0x00,0x30,0xFF,0x34,0x00,0x00,0x00,0xBC,0xA8,0xA4,0x92,0x5B,0xD6,0xF7,
    0xD8,0x63,0x00,0xA4,0xE8,0xD3,0x57,0x40,0x9E,0xFF,0x39,0xA4,0xFD,0x21,0x00,0x00,
    0x04,0xEB,0x7E,0xA4,0xDB,0x00,0x00,0x00,0x00,0xCD,0x96,0xA4,0xC6,0x00,0x00,0x00,
    0x00,0xCC,0x98,0xA4,0xC4,0x00,0x00,0x00,0x00,0xCC,0x98,0xA4,0xC4,0x00,0x00,0x00,
    0x00,0xCC,0x98,0xA4,0xC4,0x00,0x00,0x00,0x00,0xCC,0x98,0xA4,0xC4,0x00,0x00,0x00,
    0x00,0xCC,0x98,0x00,0x00,0x49,0xC8,0xF7,0xEB,0xA2,0x19,0x00,0x00,0x4C,0xFD,0x9E,
    0x45,0x55,0xD2,0xDF,0x0E,0x00,0xCE,0xBE,0x00,0x00,0x00,0x17,0xF8,0x76,0x0C,0xFE,
    0x72,0x00,0x00,0x00,0x00,0xC0,0xB7,0x1A,0xFF,0x5E,0x00,0x00,0x00,0x00,0xAB,0xCA,
    0x07,0xFE,0x75,0x00,0x00,0x00,0x00,0xC2,0xB8,0x00,0xC2,0xC4,0x00,0x00,0x00,0x19,
    0xFA,0x7A,0x00,0x3D,0xFB,0xA2,0x46,0x54,0xD3,0xE3,0x12,0x00,0x00,0x40,0xC3,0xF5,
    0xEF,0xA9,0x1F,0x00,0xA4,0x94,0x51,0xDB,0xF9,0xD3,0x4E,0x00,0xA4,0xE5,0xC7,0x52,
    0x47,0xB1,0xFD,0x3C,0xA4,0xFB,0x1A,0x00,0x00,0x03,0xE2,0xAD,0xA4,0xD7,0x00,0x00,
    0x00,0x00,0x9A,0xE1,0xA4,0xC7,0x00,0x00,0x00,0x00,0x88,0xF0,0xA4,0xDC,0x00,0x00,
    0x00,0x00,0xA7,0xE0,0xA4,0xFE,0x20,0x00,0x00,0x05,0xE1,0xAA,0xA4,0xEF,0xD1,0x55,
    0x41,0xAE,0xFC,0x38,0xA4,0xB8,0x66,0xDE,0xF9,0xD3,0x4C,0x00,0xA4,0xC3,0x00,0x00,
    0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,
    0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x65,0xDC,
    0xF8,0xCF,0x38,0xB7,0x7C,0x00,0x5F,0xFF,0x95,0x42,0x60,0xD9,0xED,0x7C,0x00,0xD7,
    0xBE,0x00,0x00,0x00,0x47,0xFF,0x7C,0x0D,0xFF,0x73,0x00,0x00,0x00,0x03,0xFD,0x7C,
    0x1C,0xFF,0x5E,0x00,0x00,0x00,0x00,0xEB,0x7C,0x0E,0xFF,0x70,0x00,0x00,0x00,0x01,
    0xFA,0x7C,0x00,0xDA,0xB7,0x00,0x00,0x00,0x3A,0xFF,0x7C,0x00,0x66,0xFF,0x91,0x41,
    0x5B,0xD5,0xF3,0x7C,0x00,0x00,0x6C,0xDF,0xF9,0xCF,0x41,0xE8,0x7C,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xEC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0x7C,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,
    0x7C,0xA4,0x8F,0x39,0xD1,0xF9,0x47,0xA4,0xCB,0xD8,0x61,0x3B,0x10,0xA4,0xFF,0x39,
    0x00,0x00,0x00,0xA4,0xDA,0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0xA4,
    0xC4,0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0xA4,0xC4,0x00,0x00,0x00,
    0x00,0xA4,0xC4,0x00,0x00,0x00,0x00,0x00,0x37,0xBC,0xF0,0xF1,0xCB,0x5E,0x08,0xF0,
    0xA5,0x3F,0x4A,0x87,0x5A,0x25,0xFF,0x43,0x00,0x00,0x00,0x00,0x01,0xC2,0xEA,0x73,
    0x14,0x00,0x00,0x00,0x06,0x6C,0xDC,0xF7,0x95,0x10,0x00,0x00,0x00,0x01,0x4F,0xE5,
    0xB2,0x00,0x00,0x00,0x00,0x00,0x7D,0xE4,0x25,0xA2,0x5B,0x3B,0x55,0xDD,0xA7,0x14,
    0xAF,0xE9,0xF9,0xE3,0x97,0x0F,0x00,0x1B,0xDF,0x00,0x00,0x00,0x00,0x69,0xE0,0x00,
    0x00,0x00,0x87,0xFC,0xFF,0xFF,0xFF,0x5C,0x27,0xA0,0xE6,0x34,0x34,0x12,0x00,0x88,
    0xE0,0x00,0x00,0x00,0x00,0x88,0xE0,0x00,0x00,0x00,0x00,0x88,0xE0,0x00,0x00,0x00,
    0x00,0x88,0xE0,0x00,0x00,0x00,0x00,0x82,0xEA,0x00,0x00,0x00,0x00,0x57,0xFF,0x78,
    0x3A,0x25,0x00,0x03,0x96,0xE8,0xF4,0x57,0xBC,0xB0,0x00,0x00,0x00,0x00,0xE0,0x88,
    0xBC,0xB0,0x00,0x00,0x00,0x00,0xE0,0x88,0xBC,0xB0,0x00,0x00,0x00,0x00,0xE0,0x88,
    0xBC,0xB0,0x00,0x00,0x00,0x00,0xE0,0x88,0xBC,0xB0,0x00,0x00,0x00,0x00,0xE2,0x88,
    0xBB,0xB1,0x00,0x00,0x00,0x00,0xF7,0x88,0xA4,0xD2,0x00,0x00,0x00,0x3C,0xFF,0x88,
    0x5F,0xFF,0x89,0x3E,0x5E,0xDD,0xF0,0x88,0x01,0x80,0xE0,0xF8,0xD2,0x4F,0xB3,0x88,
    0xD2,0xAB,0x00,0x00,0x00,0x00,0x8D,0xEC,0x05,0x76,0xF6,0x0D,0x00,0x00,0x01,0xE3,
    0x94,0x00,0x1B,0xFD,0x5C,0x00,0x00,0x3D,0xFF,0x37,0x00,0x00,0xBD,0xB4,0x00,0x00,
    0x95,0xDA,0x00,0x00,0x00,0x60,0xFA,0x11,0x03,0xE9,0x7D,0x00,0x00,0x00,0x0D,0xF6,
    0x62,0x43,0xFF,0x21,0x00,0x00,0x00,0x00,0xA7,0xB3,0x95,0xC3,0x00,0x00,0x00,0x00,
    0x00,0x4B,0xF4,0xE2,0x66,0x00,0x00,0x00,0x00,0x00,0x04,0xE9,0xF9,0x11,0x00,0x00,
    0x00,0xB3,0xBF,0x00,0x00,0x00,0x9F,0xFF,0x38,0x00,0x00,0x2C,0xFF,0x45,0x6F,0xF7,
    0x07,0x00,0x01,0xE8,0xF0,0x82,0x00,0x00,0x6B,0xF8,0x09,0x2C,0xFF,0x3D,0x00,0x37,
    0xFD,0x8E,0xCC,0x00,0x00,0xAA,0xBD,0x00,0x00,0xE8,0x7C,0x00,0x83,0xC9,0x3B,0xFE,
    0x17,0x00,0xE8,0x79,0x00,0x00,0xA6,0xBB,0x00,0xCF,0x7E,0x04,0xEF,0x60,0x28,0xFF,
    0x35,0x00,0x00,0x63,0xF3,0x1B,0xFF,0x30,0x00,0xA8,0xA6,0x67,0xEE,0x02,0x00,0x00,
    0x20,0xFF,0x85,0xE1,0x00,0x00,0x5C,0xE7,0xA3,0xAD,0x00,0x00,0x00,0x00,0xDD,0xEA,
    0x94,0x00,0x00,0x13,0xFD,0xEC,0x69,0x00,0x00,0x00,0x00,0x9A,0xFF,0x46,0x00,0x00,
    0x00,0xC6,0xFF,0x25,0x00,0x00,0x3C,0xFD,0x5A,0x00,0x00,0x08,0xDA,0xAD,0x00,0x00,
    0x8F,0xEB,0x14,0x00,0x89,0xEB,0x16,0x00,0x00,0x09,0xD9,0xA5,0x32,0xFB,0x56,0x00,
    0x00,0x00,0x00,0x3A,0xFD,0xE4,0xAB,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0xFF,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x5A,0xFB,0xCC,0xC9,0x03,0x00,0x00,0x00,0x19,0xED,0x85,
    0x1D,0xF2,0x7A,0x00,0x00,0x00,0xB3,0xD5,0x07,0x00,0x68,0xF9,0x2E,0x00,0x61,0xFD,
    0x37,0x00,0x00,0x01,0xBE,0xCF,0x05,0xCC,0xB1,0x00,0x00,0x00,0x00,0x88,0xF0,0x08,
    0x6A,0xFA,0x14,0x00,0x00,0x00,0xDE,0x9D,0x00,0x10,0xF7,0x6B,0x00,0x00,0x37,0xFF,
    0x40,0x00,0x00,0xA6,0xC7,0x00,0x00,0x8E,0xE2,0x01,0x00,0x00,0x44,0xFF,0x24,0x01,
    0xE3,0x88,0x00,0x00,0x00,0x01,0xE0,0x7D,0x3A,0xFF,0x2B,0x00,0x00,0x00,0x00,0x80,
    0xCE,0x8A,0xCF,0x00,0x00,0x00,0x00,0x00,0x1F,0xFC,0xE0,0x72,0x00,0x00,0x00,0x00,
    0x00,0x00,0xBC,0xFD,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0xB4,0xBA,0x00,0x00,0x00,
    0x00,0x00,0x00,0x21,0xFB,0x56,0x00,0x00,0x00,0x00,0x30,0x46,0xCE,0xCF,0x03,0x00,
    0x00,0x00,0x00,0xC9,0xF6,0xBB,0x20,0x00,0x00,0x00,0x00,0x00,0x1C,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xC8,0x05,0x34,0x34,0x34,0x45,0xF5,0x8B,0x00,0x00,0x00,0x00,0xA5,0xD6,
    0x08,0x00,0x00,0x00,0x53,0xFB,0x33,0x00,0x00,0x00,0x16,0xEA,0x7F,0x00,0x00,0x00,
    0x00,0xAE,0xCB,0x04,0x00,0x00,0x00,0x5C,0xF7,0x28,0x00,0x00,0x00,0x1A,0xEE,0x9B,
    0x34,0x34,0x34,0x2E,0x60,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,
};

leRasterFont ArialUnicodeMS =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)ArialUnicodeMS_data, // data address pointer
            4891, // data size
        },
        LE_RASTER_FONT,
    },
    17,
    12,
    LE_FONT_BPP_8, // bits per pixel
    ArialUnicodeMS_glyphs, // glyph table
};
