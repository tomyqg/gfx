#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Image Asset
 * Name:   GFX_Play_Green_20x20
 * Size:   20x20 pixels
 * Mode:   RGBA_5551
 * Format: RLE
 ***********************************/

const uint8_t GFX_Play_Green_20x20_data[113] =
{
    0x01,0x02,0x1C,0x00,0x00,0x01,0xC1,0x07,0x13,0x00,0x00,0x02,0xC1,0x07,0x12,0x00,
    0x00,0x03,0xC1,0x07,0x11,0x00,0x00,0x04,0xC1,0x07,0x10,0x00,0x00,0x05,0xC1,0x07,
    0x0F,0x00,0x00,0x06,0xC1,0x07,0x0E,0x00,0x00,0x07,0xC1,0x07,0x0D,0x00,0x00,0x08,
    0xC1,0x07,0x0C,0x00,0x00,0x09,0xC1,0x07,0x0B,0x00,0x00,0x08,0xC1,0x07,0x0C,0x00,
    0x00,0x07,0xC1,0x07,0x0D,0x00,0x00,0x06,0xC1,0x07,0x0E,0x00,0x00,0x05,0xC1,0x07,
    0x0F,0x00,0x00,0x04,0xC1,0x07,0x10,0x00,0x00,0x04,0xC1,0x07,0x10,0x00,0x00,0x03,
    0xC1,0x07,0x11,0x00,0x00,0x02,0xC1,0x07,0x12,0x00,0x00,0x01,0xC1,0x07,0x1F,0x00,
    0x00,
};

leImage GFX_Play_Green_20x20 =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)GFX_Play_Green_20x20_data, // data address pointer
        113, // data size
    },
    LE_IMAGE_FORMAT_RLE,
    {
        LE_COLOR_MODE_RGBA_5551,
        {
            20,
            20
        },
        400,
        113,
        (void*)GFX_Play_Green_20x20_data
    },
    0, // image flags
    {
        0x1, // color mask
    },
    NULL, // alpha mask
    NULL, // palette
};