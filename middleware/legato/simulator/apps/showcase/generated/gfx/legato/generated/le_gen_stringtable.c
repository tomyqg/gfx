#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 2
 * String Count:   92
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index
 * unsigned byte - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned (index size) - a value of length 'index size' that contains
 *                           the offset of the string codepoint data in
 *                           the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 * unsigned short : length of the string in bytes:
 * 'length' number of codepoints - the string data (encoding dependent
 ****************************************************************************/

const uint8_t stringTable_data[1837] =
{
    0x5C,0x00,0x02,0x02,0x06,0x2C,0x02,0x03,0x30,0x02,0x02,0x34,0x02,0x02,0x49,0x02,
    0x01,0x34,0x02,0x01,0x49,0x02,0x01,0x54,0x02,0x01,0x54,0x02,0x00,0x57,0x02,0x00,
    0x57,0x02,0x04,0x5A,0x02,0x02,0x69,0x02,0x01,0x73,0x02,0x01,0x30,0x02,0x01,0x79,
    0x02,0x01,0x98,0x02,0x02,0xA3,0x02,0x02,0xB7,0x02,0x01,0xA3,0x02,0x01,0xB7,0x02,
    0x01,0xC0,0x02,0x01,0x54,0x02,0x01,0xC3,0x02,0x01,0x54,0x02,0x01,0xC6,0x02,0x01,
    0x54,0x02,0x01,0xC9,0x02,0x01,0x54,0x02,0x01,0xCC,0x02,0x01,0x54,0x02,0x01,0xCF,
    0x02,0x01,0x54,0x02,0x01,0xD2,0x02,0x01,0x54,0x02,0x01,0xD5,0x02,0x01,0x54,0x02,
    0x01,0xD8,0x02,0x01,0x54,0x02,0x01,0xDB,0x02,0x01,0x54,0x02,0x01,0xDE,0x02,0x01,
    0xDE,0x02,0x01,0xE1,0x02,0x01,0xE1,0x02,0x01,0xE4,0x02,0x01,0xE4,0x02,0x01,0xE7,
    0x02,0x01,0xE7,0x02,0x01,0xEA,0x02,0x01,0xEA,0x02,0x01,0xED,0x02,0x01,0xED,0x02,
    0x01,0xF0,0x02,0x01,0xF0,0x02,0x01,0xF3,0x02,0x01,0xF3,0x02,0x01,0xF6,0x02,0x01,
    0xF6,0x02,0x01,0xF9,0x02,0x01,0xF9,0x02,0x01,0xFC,0x02,0x01,0xFC,0x02,0x01,0xFF,
    0x02,0x01,0xFF,0x02,0x01,0x02,0x03,0x01,0x02,0x03,0x01,0x05,0x03,0x01,0x05,0x03,
    0x01,0x08,0x03,0x01,0x08,0x03,0x01,0x0B,0x03,0x01,0x0B,0x03,0x01,0x0E,0x03,0x01,
    0x0E,0x03,0x01,0x11,0x03,0x01,0x11,0x03,0x01,0x14,0x03,0x01,0x14,0x03,0x01,0x17,
    0x03,0x01,0x17,0x03,0x01,0x1A,0x03,0x01,0x1A,0x03,0x01,0x1D,0x03,0x01,0x1D,0x03,
    0x01,0x20,0x03,0x01,0x20,0x03,0x01,0x23,0x03,0x01,0x23,0x03,0x01,0x26,0x03,0x01,
    0x26,0x03,0x01,0x29,0x03,0x01,0x29,0x03,0x02,0x2C,0x03,0x02,0x44,0x03,0x01,0x4E,
    0x03,0x01,0x81,0x03,0x01,0x2C,0x03,0x01,0x44,0x03,0x01,0x8E,0x03,0x01,0xB0,0x03,
    0x01,0xBA,0x03,0x01,0xE3,0x03,0x01,0xEF,0x03,0x01,0x1E,0x04,0x06,0x2E,0x04,0x03,
    0x30,0x02,0x01,0x32,0x04,0x01,0x6F,0x04,0x01,0x30,0x02,0x01,0x30,0x02,0x01,0x88,
    0x04,0x01,0x88,0x04,0x01,0x91,0x04,0x01,0x30,0x02,0x01,0x9B,0x04,0x01,0xA5,0x04,
    0x02,0xAB,0x04,0x02,0xBC,0x04,0x01,0xC3,0x04,0x01,0xBC,0x04,0x01,0xD3,0x04,0x01,
    0xFE,0x04,0x01,0x0D,0x05,0x01,0x48,0x05,0x05,0x5E,0x05,0x02,0xA5,0x04,0x01,0x71,
    0x05,0x01,0xA7,0x05,0x01,0xBA,0x05,0x01,0xD2,0x05,0x01,0xDA,0x05,0x01,0x09,0x06,
    0x01,0x18,0x06,0x01,0x36,0x06,0x01,0x44,0x06,0x01,0x74,0x06,0x02,0x82,0x06,0x02,
    0x9A,0x06,0x01,0x82,0x06,0x01,0x9A,0x06,0x01,0xA5,0x06,0x01,0xCF,0x06,0x00,0xDE,
    0x06,0x00,0xDE,0x06,0x01,0xE1,0x06,0x01,0x30,0x02,0x00,0xE8,0x06,0x00,0xE8,0x06,
    0x01,0xEB,0x06,0x01,0xEB,0x06,0x06,0xC0,0x02,0x03,0xC0,0x02,0x06,0xC3,0x02,0x03,
    0xC3,0x02,0x06,0xF2,0x06,0x03,0xF2,0x06,0x06,0xF6,0x06,0x03,0xF6,0x06,0x06,0xFA,
    0x06,0x03,0xFA,0x06,0x06,0xC6,0x02,0x03,0xC6,0x02,0x06,0xC9,0x02,0x03,0xC9,0x02,
    0x06,0xCC,0x02,0x03,0xCC,0x02,0x06,0xCF,0x02,0x03,0xCF,0x02,0x06,0xD2,0x02,0x03,
    0xD2,0x02,0x06,0xD5,0x02,0x03,0xD5,0x02,0x06,0xD8,0x02,0x03,0xD8,0x02,0x06,0xDB,
    0x02,0x03,0xDB,0x02,0x01,0xFE,0x06,0x01,0xFE,0x06,0x01,0x03,0x07,0x01,0x03,0x07,
    0x01,0x06,0x07,0x01,0x0D,0x07,0x01,0x12,0x07,0x01,0xE3,0x03,0x02,0x00,0x41,0x4D,
    0x02,0x00,0x3F,0x3F,0x13,0x00,0x41,0x6C,0x70,0x68,0x61,0x20,0x42,0x6C,0x65,0x6E,
    0x64,0x69,0x6E,0x67,0x20,0x44,0x65,0x6D,0x6F,0x09,0x00,0x41,0x6C,0x70,0x68,0x61,
    0x3F,0x3F,0x3F,0x3F,0x01,0x00,0x3F,0x01,0x00,0x2D,0x0D,0x00,0x4D,0x50,0x4C,0x41,
    0x42,0x20,0x48,0x61,0x72,0x6D,0x6F,0x6E,0x79,0x08,0x00,0x4D,0x50,0x4C,0x41,0x42,
    0x20,0x3F,0x3F,0x04,0x00,0x48,0x65,0x6C,0x70,0x1D,0x00,0x54,0x6F,0x75,0x63,0x68,
    0x20,0x74,0x6F,0x20,0x72,0x65,0x74,0x75,0x72,0x6E,0x20,0x74,0x6F,0x20,0x6D,0x61,
    0x69,0x6E,0x20,0x6D,0x65,0x6E,0x75,0x2E,0x09,0x00,0x3F,0x3F,0x20,0x3F,0x3F,0x3F,
    0x3F,0x3F,0x3F,0x12,0x00,0x4B,0x65,0x79,0x70,0x61,0x64,0x20,0x57,0x69,0x64,0x67,
    0x65,0x74,0x20,0x44,0x65,0x6D,0x6F,0x07,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,
    0x01,0x00,0x30,0x01,0x00,0x31,0x01,0x00,0x32,0x01,0x00,0x33,0x01,0x00,0x34,0x01,
    0x00,0x35,0x01,0x00,0x36,0x01,0x00,0x37,0x01,0x00,0x38,0x01,0x00,0x39,0x01,0x00,
    0x61,0x01,0x00,0x62,0x01,0x00,0x63,0x01,0x00,0x64,0x01,0x00,0x65,0x01,0x00,0x66,
    0x01,0x00,0x67,0x01,0x00,0x68,0x01,0x00,0x69,0x01,0x00,0x6A,0x01,0x00,0x6B,0x01,
    0x00,0x6C,0x01,0x00,0x6D,0x01,0x00,0x6E,0x01,0x00,0x6F,0x01,0x00,0x70,0x01,0x00,
    0x71,0x01,0x00,0x72,0x01,0x00,0x73,0x01,0x00,0x74,0x01,0x00,0x75,0x01,0x00,0x76,
    0x01,0x00,0x77,0x01,0x00,0x78,0x01,0x00,0x79,0x01,0x00,0x7A,0x16,0x00,0x4C,0x69,
    0x73,0x74,0x20,0x57,0x68,0x65,0x65,0x6C,0x20,0x57,0x69,0x64,0x67,0x65,0x74,0x20,
    0x44,0x65,0x6D,0x6F,0x08,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x31,0x00,
    0x54,0x6F,0x75,0x63,0x68,0x20,0x61,0x6E,0x64,0x20,0x64,0x72,0x61,0x67,0x20,0x74,
    0x68,0x65,0x20,0x6C,0x69,0x73,0x74,0x77,0x68,0x65,0x65,0x6C,0x20,0x74,0x6F,0x20,
    0x63,0x68,0x61,0x6E,0x67,0x65,0x20,0x74,0x68,0x65,0x20,0x76,0x61,0x6C,0x75,0x65,
    0x2E,0x0B,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x20,0x00,
    0x54,0x6F,0x75,0x63,0x68,0x20,0x74,0x6F,0x20,0x61,0x63,0x63,0x65,0x73,0x73,0x20,
    0x68,0x65,0x6C,0x70,0x20,0x69,0x6E,0x66,0x6F,0x72,0x6D,0x61,0x74,0x69,0x6F,0x6E,
    0x08,0x00,0x3F,0x3F,0x20,0x3F,0x3F,0x3F,0x3F,0x3F,0x27,0x00,0x54,0x6F,0x75,0x63,
    0x68,0x20,0x74,0x68,0x65,0x20,0x6D,0x65,0x6E,0x75,0x20,0x69,0x63,0x6F,0x6E,0x73,
    0x20,0x74,0x6F,0x20,0x73,0x74,0x61,0x72,0x74,0x20,0x74,0x68,0x65,0x20,0x64,0x65,
    0x6D,0x6F,0x2E,0x0A,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x2D,
    0x00,0x54,0x6F,0x75,0x63,0x68,0x20,0x74,0x6F,0x20,0x63,0x68,0x61,0x6E,0x67,0x65,
    0x20,0x74,0x68,0x65,0x20,0x73,0x65,0x74,0x74,0x69,0x6E,0x67,0x73,0x20,0x28,0x65,
    0x2E,0x67,0x2E,0x2C,0x20,0x6C,0x61,0x6E,0x67,0x75,0x61,0x67,0x65,0x29,0x0E,0x00,
    0x3F,0x3F,0x20,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x02,0x00,
    0x50,0x4D,0x3B,0x00,0x2B,0x2F,0x2D,0x20,0x20,0x20,0x20,0x20,0x54,0x6F,0x75,0x63,
    0x68,0x20,0x74,0x6F,0x20,0x69,0x6E,0x63,0x72,0x65,0x6D,0x65,0x6E,0x74,0x61,0x6C,
    0x6C,0x79,0x20,0x61,0x64,0x6A,0x75,0x73,0x74,0x20,0x74,0x68,0x65,0x20,0x61,0x6C,
    0x70,0x68,0x61,0x20,0x70,0x65,0x72,0x63,0x65,0x6E,0x74,0x61,0x67,0x65,0x2E,0x17,
    0x00,0x2B,0x2F,0x2D,0x20,0x20,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,
    0x41,0x6C,0x70,0x68,0x61,0x3F,0x3F,0x3F,0x07,0x00,0x45,0x6E,0x67,0x6C,0x69,0x73,
    0x68,0x08,0x00,0x4C,0x61,0x6E,0x67,0x75,0x61,0x67,0x65,0x08,0x00,0x53,0x65,0x74,
    0x20,0x54,0x69,0x6D,0x65,0x04,0x00,0x3F,0x3F,0x3F,0x3F,0x0F,0x00,0x53,0x6C,0x69,
    0x64,0x65,0x20,0x53,0x68,0x6F,0x77,0x20,0x44,0x65,0x6D,0x6F,0x05,0x00,0x3F,0x3F,
    0x3F,0x3F,0x3F,0x0E,0x00,0x53,0x6C,0x69,0x64,0x65,0x53,0x68,0x6F,0x77,0x20,0x44,
    0x65,0x6D,0x6F,0x29,0x00,0x3C,0x2F,0x3E,0x20,0x20,0x20,0x54,0x6F,0x75,0x63,0x68,
    0x20,0x74,0x6F,0x20,0x73,0x63,0x72,0x6F,0x6C,0x6C,0x20,0x74,0x68,0x72,0x6F,0x75,
    0x67,0x68,0x20,0x74,0x68,0x65,0x20,0x69,0x6D,0x61,0x67,0x65,0x73,0x2E,0x0D,0x00,
    0x3C,0x2F,0x3E,0x20,0x20,0x20,0x20,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x39,0x00,0x44,
    0x72,0x61,0x67,0x20,0x74,0x68,0x65,0x20,0x73,0x6C,0x69,0x64,0x65,0x72,0x20,0x72,
    0x69,0x67,0x68,0x74,0x2F,0x6C,0x65,0x66,0x74,0x20,0x74,0x6F,0x20,0x63,0x68,0x61,
    0x6E,0x67,0x65,0x20,0x74,0x68,0x65,0x20,0x61,0x6C,0x70,0x68,0x61,0x20,0x70,0x65,
    0x72,0x63,0x65,0x6E,0x74,0x61,0x67,0x65,0x14,0x00,0x3F,0x3F,0x2F,0x3F,0x3F,0x3F,
    0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x41,0x6C,0x70,0x68,0x61,0x3F,0x3F,0x3F,0x11,0x00,
    0x47,0x72,0x61,0x70,0x68,0x69,0x63,0x73,0x20,0x53,0x68,0x6F,0x77,0x63,0x61,0x73,
    0x65,0x34,0x00,0x54,0x6F,0x75,0x63,0x68,0x20,0x74,0x6F,0x20,0x72,0x75,0x6E,0x20,
    0x73,0x6C,0x69,0x64,0x65,0x73,0x68,0x6F,0x77,0x20,0x69,0x6E,0x20,0x35,0x30,0x30,
    0x2D,0x6D,0x69,0x6C,0x6C,0x69,0x73,0x65,0x63,0x6F,0x6E,0x64,0x20,0x69,0x6E,0x74,
    0x65,0x72,0x76,0x61,0x6C,0x73,0x2E,0x11,0x00,0x3F,0x3F,0x20,0x3F,0x35,0x30,0x30,
    0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x16,0x00,0x54,0x6F,0x75,0x63,
    0x68,0x20,0x74,0x68,0x65,0x20,0x77,0x68,0x69,0x74,0x65,0x20,0x73,0x63,0x72,0x65,
    0x65,0x6E,0x06,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x2D,0x00,0x54,0x6F,0x75,0x63,
    0x68,0x20,0x74,0x6F,0x20,0x72,0x75,0x6E,0x20,0x73,0x6C,0x69,0x64,0x65,0x73,0x68,
    0x6F,0x77,0x20,0x69,0x6E,0x20,0x32,0x2D,0x73,0x65,0x63,0x6F,0x6E,0x64,0x20,0x69,
    0x6E,0x74,0x65,0x72,0x76,0x61,0x6C,0x73,0x2E,0x0D,0x00,0x3F,0x3F,0x20,0x3F,0x32,
    0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x1C,0x00,0x54,0x6F,0x75,0x63,0x68,0x20,
    0x74,0x6F,0x20,0x73,0x74,0x6F,0x70,0x20,0x74,0x68,0x65,0x20,0x73,0x6C,0x69,0x64,
    0x65,0x73,0x68,0x6F,0x77,0x2E,0x0C,0x00,0x3F,0x3F,0x20,0x3F,0x3F,0x3F,0x3F,0x3F,
    0x3F,0x3F,0x3F,0x3F,0x2E,0x00,0x54,0x6F,0x75,0x63,0x68,0x20,0x74,0x68,0x65,0x20,
    0x77,0x68,0x69,0x74,0x65,0x20,0x73,0x63,0x72,0x65,0x65,0x6E,0x20,0x74,0x6F,0x20,
    0x73,0x65,0x65,0x20,0x74,0x68,0x65,0x20,0x74,0x6F,0x75,0x63,0x68,0x20,0x70,0x6F,
    0x69,0x6E,0x74,0x73,0x0C,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,
    0x3F,0x3F,0x16,0x00,0x54,0x6F,0x75,0x63,0x68,0x20,0x54,0x65,0x73,0x74,0x20,0x57,
    0x69,0x64,0x67,0x65,0x74,0x20,0x44,0x65,0x6D,0x6F,0x09,0x00,0x3F,0x3F,0x3F,0x3F,
    0x3F,0x3F,0x3F,0x3F,0x3F,0x28,0x00,0x54,0x6F,0x75,0x63,0x68,0x20,0x74,0x68,0x65,
    0x20,0x74,0x65,0x78,0x74,0x20,0x66,0x69,0x65,0x6C,0x64,0x20,0x74,0x6F,0x20,0x73,
    0x74,0x61,0x72,0x74,0x20,0x74,0x65,0x78,0x74,0x20,0x65,0x6E,0x74,0x72,0x79,0x0D,
    0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x01,0x00,
    0x2B,0x05,0x00,0x63,0x6C,0x65,0x61,0x72,0x01,0x00,0x3A,0x05,0x00,0x35,0x30,0x30,
    0x6D,0x73,0x02,0x00,0x31,0x30,0x02,0x00,0x31,0x31,0x02,0x00,0x31,0x32,0x03,0x00,
    0x32,0x20,0x73,0x01,0x00,0x20,0x05,0x00,0x73,0x70,0x61,0x63,0x65,0x03,0x00,0x3F,
    0x3F,0x3F,0x19,0x00,0x54,0x6F,0x75,0x63,0x68,0x20,0x74,0x6F,0x20,0x62,0x65,0x67,
    0x69,0x6E,0x20,0x74,0x65,0x78,0x74,0x20,0x65,0x6E,0x74,0x72,0x79,
};

/* font asset pointer list */
leFont* fontList[7] =
{
    (leFont*)&Calibri,
    (leFont*)&ArialUnicodeMS,
    (leFont*)&ArialUnicodeMS_Large,
    (leFont*)&ArialUnicodeMS_XL,
    (leFont*)&NotoSans_Bold16,
    (leFont*)&NotoSans_Bold18,
    (leFont*)&NotoSans_Bold24,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        1837, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};
