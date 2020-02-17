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

#include "gfx/legato/image/raw/legato_imagedecoder_raw.h"

#if LE_STREAMING_ENABLED == 1

#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/image/legato_image_utils.h"

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
#define cache leRawImageDecoderScratchBuffer
#endif

void _leRawImageDecoder_InjectStage(leRawDecodeState* state,
                                    leRawDecodeStage* stage);

enum StageState
{
    SS_READY,
    SS_STALLED,
    SS_DONE
};

static struct StreamReadStage
{
    leRawDecodeStage base;

    enum StageState state;

    leStream stream;
} streamReadStage;

static leResult advanceStage()
{
    streamReadStage.base.state->readIndex += 1;

    if(streamReadStage.base.state->readIndex < streamReadStage.base.state->readCount)
    {
        return LE_FAILURE;
    }
    else
    {
        // reset for next iteration
        streamReadStage.base.state->readIndex = 0;

        streamReadStage.state = SS_DONE;

        return LE_SUCCESS;
    }
}

static void colorDataReady(leStream* strm)
{
    streamReadStage.state = SS_READY;

    advanceStage();
}

static leResult exec_nonblocking(struct StreamReadStage* stage)
{
    uint32_t addr;
    leRawSourceReadOperation* op;

    // no need to do anything if a data read is still pending
    if(streamReadStage.state == SS_STALLED)
        return LE_FAILURE;

    if(streamReadStage.state == SS_DONE)
    {
        streamReadStage.state = SS_READY;

        return LE_SUCCESS;
    }

    op = &streamReadStage.base.state->readOperation[streamReadStage.base.state->readIndex];

    // get the address of the desired pixel
    addr = (uint32_t)streamReadStage.base.state->source->header.address +
                     op->bufferIndex *
                     leColorInfoTable[streamReadStage.base.state->source->buffer.mode].size;

    // read the pixel
    leStream_Read(&streamReadStage.stream,
                  addr,
                  leColorInfoTable[streamReadStage.base.state->source->buffer.mode].size,
                  (uint8_t*)&op->data,
                  colorDataReady);

    // only stall out of the read is still pending
    if(leStream_IsDataReady(&streamReadStage.stream) == LE_FALSE)
    {
        streamReadStage.state = SS_STALLED;

        return LE_FAILURE;
    }

    advanceStage();

    if(streamReadStage.state == SS_DONE)
    {
        streamReadStage.state = SS_READY;

        return LE_SUCCESS;
    }

    return LE_FAILURE;
}

leResult exec_blocking(struct StreamReadStage* stage)
{
    uint32_t addr;
    leRawSourceReadOperation* op;

    stage->base.state->readIndex = 0;

    for(stage->base.state->readIndex = 0;
        stage->base.state->readIndex < stage->base.state->readCount;
        stage->base.state->readIndex++)
    {
        op = &streamReadStage.base.state->readOperation[streamReadStage.base.state->readIndex];

        // get the address of the desired pixel
        addr = (uint32_t)streamReadStage.base.state->source->header.address +
                         op->bufferIndex *
                         leColorInfoTable[streamReadStage.base.state->source->buffer.mode].size;

        // read the pixel
        leStream_Read(&streamReadStage.stream,
                      addr,
                      leColorInfoTable[streamReadStage.base.state->source->buffer.mode].size,
                      (uint8_t*)&op->data,
                      NULL);

        streamReadStage.base.state->readIndex += 1;
    }

    return LE_SUCCESS;
}

static void cleanup(struct StreamReadStage* stage)
{
    leStream_Close(&streamReadStage.stream);
}

leResult _leRawImageDecoder_ReadStage_StreamColor(leRawDecodeState* state)
{
    memset(&streamReadStage, 0, sizeof(streamReadStage));

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 0
    leStream_Init(&streamReadStage.stream,
                  (leStreamDescriptor*)state->source,
                  0,
                  NULL,
                  NULL);
#else
    leStream_Init(&streamReadStage.stream,
                  (struct leStreamDescriptor*)state->source,
                  LE_ASSET_DECODER_CACHE_SIZE,
                  leRawImageDecoderScratchBuffer,
                  NULL);
#endif

    if(leStream_Open(&streamReadStage.stream) == LE_FAILURE)
    {
        return LE_FAILURE;
    }

    streamReadStage.base.state = state;
    streamReadStage.base.cleanup = (void*)cleanup;

    if(leStream_IsBlocking(&streamReadStage.stream) == LE_TRUE)
    {
        streamReadStage.base.exec = exec_blocking;
    }
    else
    {
        streamReadStage.base.exec = exec_nonblocking;
    }

    _leRawImageDecoder_InjectStage(state, (void*)&streamReadStage);

    return LE_SUCCESS;
}

#endif