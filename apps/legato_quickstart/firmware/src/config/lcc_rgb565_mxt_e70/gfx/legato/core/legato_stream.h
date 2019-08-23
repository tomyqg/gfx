#ifndef LE_STREAM_H
#define LE_STREAM_H

#include "gfx/legato/common/legato_common.h"

// *****************************************************************************
/* Structure:
    leStreamDescriptor

  Summary:
    Defines a common header for all stream operations.

  Description:
    dataLocation - indicates the location of the data.  0 is always
                   internal flash.  any other number must be understood
                   by the application

    dataAddress  - the address at which the data resides.  may be a local pointer
                   or a location in some external storage location not in the
                   local memory map.

    dataSize     - the size of the data in bytes
*/
typedef struct leStreamDescriptor
{
    uint32_t location;
    void* address;
    uint32_t size;
} leStreamDescriptor;

#define LE_STREAM_LOCATION_ID_INTERNAL 0

#if LE_STREAMING_ENABLED == 1

// *****************************************************************************
/* enum:
    leStreamState

  Summary:
    Enumerates stream state machine states.

    LE_STREAM_CLOSED    - stream isn't currently open
    LE_STREAM_READY     - stream is ready to fetch data
    LE_STREAM_WAITING   - stream is waiting for a memory operation to complete
    LE_STREAM_DATAREADY - stream has data ready for use
    LE_STREAM_ERROR     - stream encountered an unrecoverable error
*/
typedef enum leStreamState
{
    LE_STREAM_CLOSED     = 1 << 0,
    LE_STREAM_READY      = 1 << 1,
    LE_STREAM_WAITING    = 1 << 2,
    LE_STREAM_DATAREADY  = 1 << 3,
    LE_STREAM_ERROR      = 1 << 4,
} leStreamState;

struct leStream;

typedef void (*leStream_DataReadyCallback)(struct leStream* strm);

// *****************************************************************************
/* Structure:
    struct leStream

  Summary:
    Defines the base description of an stream reader.  Specific reader
    implementations will build on this foundation for each decoder type.

  Description:
    data - the data being streamed

    status - the overall status of the stream state machine

    dataReady - signals that the requested data is ready.  if NULL then the stream
                is a blocking-type stream and cannot preempt itself

    userData - any kind of user or application data attached to this reader

*/
typedef struct leStream
{
    leStreamDescriptor* desc;

    enum leStreamState state;

    int32_t result;

    struct
    {
        uint32_t size;
        uint8_t* buf;
        leStream_DataReadyCallback dataReadyCB;
    } readRequest;

    struct
    {
        uint32_t physicalSize;
        uint32_t baseAddress;
        uint32_t logicalSize;
        uint8_t* ptr;
    } cache;

    void* userData;
} leStream;

// *****************************************************************************
/* Function:
    void leStream_Init(leStream* stream,
                       leStreamDescriptor* desc,
                       uint32_t cacheSize,
                       uint8_t* cacheBuf,
                       void* userData)

  Summary:
    Initialize a stream object

  Description:
    A stream object is a construct that is capable of making external data
    read requests to the application.  It is responsible for opening, reading
    from, and closing an external device to the standard application data
    streaming interface.

    It can also be configured to manage a local data cache for faster
    data streaming speed.

  Parameters:
    leStream* stream - the stream struct to initialize
    leStreamDescriptor* desc - the stream descriptor to read from
    uint32_t cacheSize - the size of the cache being passed in
    uint8_t* cacheBuf - a buffer to use as a local cache
    void* userData - a user data pointer for general purpose use

  Returns:


  Remarks:

*/
void leStream_Init(leStream* stream,
                   leStreamDescriptor* desc,
                   uint32_t cacheSize,
                   uint8_t* cacheBuf,
                   void* userData);

// *****************************************************************************
/* Function:
    void leStream_Open(leStream* stream)

  Summary:
    Opens a stream object

  Description:
    Instructs the stream object to attempt to open the data source through the
    leApplication_MediaOpenRequest API.

  Parameters:
    leStream* stream - the stream to open

  Returns:


  Remarks:

*/
leResult leStream_Open(leStream* stream);

// *****************************************************************************
/* Function:
    leResult leStream_Read(leStream* stream,
                           uint32_t addr,
                           uint32_t size,
                           uint8_t* buf,
                           leStream_DataReadyCallback cb)

  Summary:
    Read from a stream object.

  Description:
    Instructs a stream object to attempt to read from its data source using the
    leApplication_MediaReadRequest API.

  Parameters:
    leStream* stream - the stream to read from
    uint32_t addr - the address to read from
    uint32_t size - the size to read
    uint8_t* buf - the destination buffer to read to
    leStream_DataReadyCallback cb - a callback to indicate that the data is ready


  Returns:


  Remarks:

*/
leResult leStream_Read(leStream* stream,
                       uint32_t addr,
                       uint32_t size,
                       uint8_t* buf,
                       leStream_DataReadyCallback cb);

// *****************************************************************************
/* Function:
    leBool leStream_IsDataReady(leStream* stream)

  Summary:
    Polls the state of the stream to see if the data request is read.  Used
    if a data ready callback was not provided.

  Description:
    Polls the state of the stream to see if the data request is read.  Used
    if a data ready callback was not provided.

  Parameters:
    leStream* stream - the stream to poll

  Returns:
    leBool - LE_TRUE if the stream data is ready

  Remarks:

*/
leBool leStream_IsDataReady(leStream* stream);

// *****************************************************************************
/* Function:
    leResult leStream_DataReady(leStream* stream)

  Summary:
    Notifies a stream that its data is ready.

  Description:
    Notifies a stream that its data is ready.  Call after filling the stream's
    destination buffer to the requested size.

  Parameters:
    leStream* stream - the stream to notify

  Returns:

  Remarks:

*/
leResult leStream_DataReady(leStream* stream);

// *****************************************************************************
/* Function:
    leResult leStream_Close(leStream* stream)

  Summary:
    Closes a stream.

  Description:
    Closes a stream.  The stream will call the leApplication_MediaCloseRequest
    API to close any open data sources.  If multiple streams use the same data
    source then it is up to the application to determine when all streams are
    finished with source.  The use of a reference counter is advised.

  Parameters:
    leStream* stream - the stream to close

  Returns:

  Remarks:

*/
leResult leStream_Close(leStream* stream);

// *****************************************************************************
/* Structure:
    struct leStreamManager

  Summary:
    A common interface for a manager object that is capable of managing a stream
    object.

  Description:
    A manager object that is capable of managing a stream object.  Stream
    managers will typically manage the streaming and decoding of some kind
    of file format

    exec - function that runs the stream manager
    isDone - function that queries if the stream manager is finished
    abort - function that aborts the stream manager

    onDone - a callback that is called when the stream manager is finished
    void* userData - general purpose data storage

*/
typedef struct leStreamManager
{
    leResult (*exec)(struct leStreamManager* mgr);
    leBool (*isDone)(struct leStreamManager* mgr);
    void (*abort)(struct leStreamManager* mgr);

    void (*onDone)(struct leStreamManager* mgr);
    void* userData;
} leStreamManager;

// *****************************************************************************
/* typedef:
    leApplication_MediaOpenRequest

  Summary:
    A callback that indicates that a stream wishes to read from an external
    source and that the application should prepare that source.

    If the result is false then the stream will abort.

    stream - the reader that is requesting to stream data
*/
leResult leApplication_MediaOpenRequest(leStream* stream);

// *****************************************************************************
/* typedef:
    leMemoryReadRequest_FnPtr

  Summary:
    A memory read request function is a request that is issued by anything that
    needs external support to access data that is stored in some external
    location.  For instance, an image may be stored in an SPI memory chip.
    A JPEG decoder has no knowledge of what SPI is.  This read request is issued
    to the application so that the application can then assume responsibility for
    communication with the peripherial to retrieve the data.

    From the reader the handler can determine which asset is being decoded and
    which media it resides in.

    stream - the stream requesting the media data
    address - the requested source address
    size - the requested data size
    buf - the destination data address

    The application servicing the request should call leStream_DataReady
    when it has finished streaming from the peripheral.
*/
leResult leApplication_MediaReadRequest(leStream* stream, // stream reader
                                        uint32_t address,  // address
                                        uint32_t size,  // dest size
                                        uint8_t* buf);  // dest buffer);

// *****************************************************************************
/* typedef:
    leMediaCloseRequest_FnPtr

  Summary:
    A callback that indicates that a stream is finished with a given
    media location and that the application can close if it.

    reader - the reader that was streaming data.
*/
void leApplication_MediaCloseRequest(leStream* stream);


#endif /* LE_STREAMING_ENABLED */

#endif /* LE_STREAM_H */