#include "gfx/legato/generated/screen/le_gen_screen_FPSImages.h"

#include <stdio.h>

#include "sim_time.h"

static uint32_t fpsTickTarget;

#define AVE_FPS_COUNT 10
#define FPS_UPDATE_TIMER_PERIOD_MS 1000
#define MAX_NUM_IMAGES 2

static volatile leBool aveFPSValid = LE_FALSE;
static int aveCounter = 0;
static uint32_t prevDrawCountAve[AVE_FPS_COUNT] = {0};
static uint32_t prevDrawCount;
static uint32_t prevVsyncCount;

uint32_t imgSize;
uint32_t imgType;
uint32_t imgIndex;

static char charBuff[16] = {0};

static leDynamicString fpsBtnText;
static leDynamicString refreshRateText;

static leDynamicString imgSizeText;
static leTableString imageTypeStr;

typedef enum
{
    IMG_40x40,
    IMG_100x100,
    IMG_200x200,
    IMG_480x270,
    IMG_MAX_SIZE,
} IMAGE_SIZE_T;

typedef enum
{
    //IMG_PNG_8888,
    //IMG_JPG_24,
        IMG_RAW_565,
    IMG_RAW_RLE_565,
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)
    IMG_RAW_BLIT,
#endif
    IMG_MAX_TYPE,
} IMAGE_TYPE_T;

typedef struct
{
    leImage * imgAsst[MAX_NUM_IMAGES];
} IMAGE_LIST_T;

char * imageSizeNames[IMG_MAX_SIZE] =
    {
        "40x40",
        "100x100",
        "200x200",
        "480x270",
    };

unsigned int imageTypeNames[IMG_MAX_TYPE] =
    {
        string_Raw565,
        string_RawRLE565,
    };

/*IMAGE_LIST_T imagesPNG[] =
{
    [IMG_40x40] = {
        {&PNG_GFX_mchp_40x40,
        &PNG_GFX_mplab_40x40},
    },
#ifdef PNG_100x100_NOT_SUPPORTED
    [IMG_100x100] = {
        {NULL,
        NULL},
    },
#else
    [IMG_100x100] = {
        {&PNG_GFX_mchp_100x100,
        &PNG_GFX_mplab_100x100},
    },
#endif
    [IMG_200x200] = {
        {NULL,
        NULL},
    },
    [IMG_480x270] = {
        {NULL,
        NULL},
    },
};*/

/*IMAGE_LIST_T imagesJPG[] =
{
    [IMG_40x40] = {
        {&JPG_GFX_mchp_40x40,
        &JPG_GFX_mplab_40x40},
    },
    [IMG_100x100] = {
        {&JPG_GFX_mchp_100x100,
        &JPG_GFX_mplab_100x100},
    },
    [IMG_200x200] = {
        {&JPG_GFX_mchp_200x200,
        &JPG_GFX_mplab_200x200},
    },
    [IMG_480x270] = {
        {&JPG_GFX_mchp_480x270,
        &JPG_GFX_mplab_480x270},
    },
};*/

IMAGE_LIST_T imagesRAW[] =
    {
        { /* IMG_40x40 */
            {
                &RAW_GFX_mchp_40x40,
                &RAW_GFX_mplab_40x40
            },
        },
        { /* IMG_100x100 */
            {
                &RAW_GFX_mchp_100x100,
                &RAW_GFX_mplab_100x100
            },
        },
        { /* IMG_200x200 */
            {
                &RAW_GFX_mchp_200x200,
                &RAW_GFX_mplab_200x200
            },
        },
        { /* IMG_480x270 */
            {
                &RAW_GFX_mchp_480x270,
                &RAW_GFX_mplab_480x270
            },
        },
    };

IMAGE_LIST_T imagesRAWRLE[] =
    {
        { /* IMG_40x40 */
            {
                &RAWRLE_GFX_mchp_40x40,
                &RAWRLE_GFX_mplab_40x40
            },
        },
        { /* IMG_100x100 */
            {
                &RAWRLE_GFX_mchp_100x100,
                &RAWRLE_GFX_mplab_100x100
            },
        },
        { /* IMG_200x200 */
            {
                &RAWRLE_GFX_mchp_200x200,
                &RAWRLE_GFX_mplab_200x200
            },
        },
        { /* IMG_480x270 */
            {
                &RAWRLE_GFX_mchp_480x270,
                &RAWRLE_GFX_mplab_480x270
            },
        },
    };

#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)
IMAGE_LIST_T imagesRAWBLIT[] =
{
    [IMG_40x40] = {
        {&BLIT_GFX_mchp_40x40,
        &BLIT_GFX_mplab_40x40},
    },
    [IMG_100x100] = {
        {&BLIT_GFX_mchp_100x100,
        &BLIT_GFX_mplab_100x100},
    },
    [IMG_200x200] = {
        {&BLIT_GFX_mchp_200x200,
        &BLIT_GFX_mplab_200x200},
    },
    [IMG_480x270] = {
        {&BLIT_GFX_mchp_480x270,
        &BLIT_GFX_mplab_480x270},
    },
};
#endif

static enum
{
    SCREEN_DO_NOTHING = 0,
    SCREEN_IMAGE_SIZE_UP,
    SCREEN_IMAGE_SIZE_DOWN,
    SCREEN_IMAGE_MODE_NEXT,
    SCREEN_IMAGE_MODE_PREV,
    SCREEN_NEXT,
    SCREEN_WAIT_FOR_NEXT,
    SCREEN_MOVE_TO_NEXT,
    SCREEN_DONE
} screenState;

static void resetFPS(void)
{
    aveFPSValid = LE_FALSE;
    aveCounter = 0;

    sprintf(charBuff, "---");

    fpsBtnText.fn->setFromCStr(&fpsBtnText, charBuff);
    ImageUpdateValue->fn->setString(ImageUpdateValue, (leString*)&fpsBtnText);

    prevDrawCount = 0;
    prevVsyncCount = 0;
}

static void fpsUpdateTimer_Callback()
{

    unsigned int rate;
    unsigned int i;

    if(ImageUpdateValue == NULL)
        return;

    //Update the 10-pt rolling average
    prevDrawCountAve[aveCounter] = (leGetRenderState()->drawCount - prevDrawCount);

    //If not pressed, show current FPS
    if(ImageUpdateValue->fn->getPressed(ImageUpdateValue) == LE_FALSE)
    {
        //Update FPS
        rate = (leGetRenderState()->drawCount - prevDrawCount)/
            (FPS_UPDATE_TIMER_PERIOD_MS/1000);

        sprintf(charBuff, "%u curr", rate);
    }
        //If pressed, show average FPS
    else
    {
        for (i = 0, rate = 0; i < AVE_FPS_COUNT; i++)
        {
            rate += prevDrawCountAve[i];
        }

        if (aveFPSValid)
        {
            sprintf(charBuff, "%u avg",
                    (rate / ((AVE_FPS_COUNT)*(FPS_UPDATE_TIMER_PERIOD_MS / 1000))));
        }
        else
        {
            sprintf(charBuff, "---");
        }
    }

    if (aveCounter < (AVE_FPS_COUNT - 1))
    {
        aveCounter++;
    }
    else
    {
        aveCounter = 0;
        aveFPSValid = LE_TRUE;
    }

    fpsBtnText.fn->setFromCStr(&fpsBtnText, charBuff);
    ImageUpdateValue->fn->setString(ImageUpdateValue, (leString*)&fpsBtnText);


    //Update Refresh Rate
    uint32_t vsyncCount = leGetRenderState()->dispDriver->getVSYNCCount();
    rate =  (vsyncCount - prevVsyncCount) / (FPS_UPDATE_TIMER_PERIOD_MS/1000);

    //If vsyncCount does not increase, assume fixed refresh rate using vsyncCount
    //value
    if (rate == 0)
        rate = vsyncCount;

    sprintf(charBuff, "%u", rate);

    refreshRateText.fn->setFromCStr(&refreshRateText, charBuff);
    ImageRefreshValue->fn->setString(ImageRefreshValue,
                                     (leString*)&refreshRateText);


    prevDrawCount = leGetRenderState()->drawCount;
    prevVsyncCount = vsyncCount;

//    DecrementCount(Counter1LabelWidget);
}

static void increaseImageSize()
{
    if(imgSize < IMG_MAX_SIZE - 1)
    {
        imgSize += 1;
    }
    else
    {
        return;
    }

    // Special handling, PNG sizes are limited to 100x100 due
    // to memory limitations
    /*if ((imgType == IMG_PNG_8888) &&
        (imgSize > IMG_100x100))
    {
        imgSize = IMG_100x100;
    }*/

    //Update image size label
    sprintf(charBuff, "%s", imageSizeNames[imgSize]);

    imgSizeText.fn->setFromCStr(&imgSizeText, charBuff);
    ImageSizeValue->fn->setString(ImageSizeValue, (leString*)&imgSizeText);

    resetFPS();
}

static void decreaseImageSize()
{
    if(imgSize > 0)
    {
        imgSize -= 1;
    }
    else
    {
        return;
    }

    //Update image size label
    sprintf(charBuff, "%s", imageSizeNames[imgSize]);

    imgSizeText.fn->setFromCStr(&imgSizeText, charBuff);
    ImageSizeValue->fn->setString(ImageSizeValue, (leString*)&imgSizeText);

    resetFPS();
}

static void nextImageType()
{
    if(imgType < IMG_MAX_TYPE - 1)
    {
        imgType += 1;
    }
    else
    {
        return;
    }

    //Update image type label
    imageTypeStr.fn->setID(&imageTypeStr, imageTypeNames[imgType]);
    ImageTypeValue->fn->setString(ImageTypeValue, (leString*)&imageTypeStr);

    resetFPS();
}

static void prevImageType()
{
    if(imgType > 0)
    {
        imgType -= 1;
    }
    else
    {
        return;
    }

    //Update image type label
    imageTypeStr.fn->setID(&imageTypeStr, imageTypeNames[imgType]);
    ImageTypeValue->fn->setString(ImageTypeValue, (leString*)&imageTypeStr);

    resetFPS();
}

static void nextImage()
{
    if(imgIndex < MAX_NUM_IMAGES - 1)
    {
        imgIndex += 1;
    }
    else
    {
        imgIndex = 0;
    }

//    if (imgType == IMG_PNG_8888)
//    {
//        if (imagesPNG[imgSize].imgAsst[imgIndex] != NULL)
//        {
//            laImageWidget_SetImage(imgWidget,
//                                   imagesPNG[imgSize].imgAsst[imgIndex]);
//        }
//        else
//        {
//
//        }
//    }
//    else if (imgType == IMG_JPG_24)
//    {
//        if (imagesJPG[imgSize].imgAsst[imgIndex] != NULL)
//        {
//            laImageWidget_SetImage(imgWidget,
//                                   imagesJPG[imgSize].imgAsst[imgIndex]);
//        }
//    }
    if (imgType == IMG_RAW_565)
    {
        if (imagesRAW[imgSize].imgAsst[imgIndex] != NULL)
        {
            ImageRenderArea->fn->setImage(ImageRenderArea,
                                          imagesRAW[imgSize].imgAsst[imgIndex]);
        }
    }
    else if (imgType == IMG_RAW_RLE_565)
    {
        if (imagesRAWRLE[imgSize].imgAsst[imgIndex] != NULL)
        {
            ImageRenderArea->fn->setImage(ImageRenderArea,
                                          imagesRAWRLE[imgSize].imgAsst[imgIndex]);
        }
    }
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)
    //    else if (imgType == IMG_RAW_BLIT)
//    {
//        if (imagesRAWBLIT[imgSize].imgAsst[imgIndex] != NULL)
//        {
//            laImageWidget_SetImage(imgWidget,
//                                   imagesRAWBLIT[imgSize].imgAsst[imgIndex]);
//        }
//    }
#endif
}

void FPSImages_OnShow()
{
    leFont* font = NULL;

    font = leStringTable_FontIndexLookup(&stringTable, string_NumsLittle, 0);

    leDynamicString_Constructor(&fpsBtnText);
    fpsBtnText.fn->setFont(&fpsBtnText, font);

    leDynamicString_Constructor(&refreshRateText);
    refreshRateText.fn->setFont(&refreshRateText, font);

    font = leStringTable_FontIndexLookup(leGetState()->stringTable, string_NumsTiny, 0);

    leDynamicString_Constructor(&imgSizeText);
    imgSizeText.fn->setFont(&imgSizeText, font);

    leTableString_Constructor(&imageTypeStr, string_Raw565);

    imgSize = IMG_40x40;
    imgType = IMG_RAW_565;
    imgIndex = 0;

    // initialize image size label
    sprintf(charBuff, "%s", imageSizeNames[imgSize]);

    imgSizeText.fn->setFromCStr(&imgSizeText, charBuff);
    ImageSizeValue->fn->setString(ImageSizeValue, (leString*)&imgSizeText);

    // initialize image type label
    imageTypeStr.fn->setID(&imageTypeStr, imageTypeNames[imgType]);
    ImageTypeValue->fn->setString(ImageTypeValue, (leString*)&imageTypeStr);

    resetFPS();

    memset(prevDrawCountAve, 0, sizeof(prevDrawCountAve));

    screenState = SCREEN_DO_NOTHING;

    fpsTickTarget = sim_TimeTotal() + FPS_UPDATE_TIMER_PERIOD_MS;
}

void FPSImages_OnHide()
{
    fpsBtnText.fn->destructor(&fpsBtnText);
    refreshRateText.fn->destructor(&refreshRateText);
    imgSizeText.fn->destructor(&imgSizeText);
    imageTypeStr.fn->destructor(&imageTypeStr);
}

void FPSImages_OnUpdate()
{
    if(sim_TimeTotal() >= fpsTickTarget)
    {
        fpsUpdateTimer_Callback();

        fpsTickTarget = sim_TimeTotal() + FPS_UPDATE_TIMER_PERIOD_MS;
    }

    switch (screenState)
    {
        case SCREEN_DO_NOTHING:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
                leEvent_GetCount() == 0)
            {
                nextImage();
            }

            break;
        }
        case SCREEN_IMAGE_SIZE_UP:
        {
            increaseImageSize();

            screenState = SCREEN_DO_NOTHING;

            break;
        }
        case SCREEN_IMAGE_SIZE_DOWN:
        {
            decreaseImageSize();

            screenState = SCREEN_DO_NOTHING;

            break;
        }
        case SCREEN_IMAGE_MODE_NEXT:
        {
            nextImageType();

            screenState = SCREEN_DO_NOTHING;

            break;
        }
        case SCREEN_IMAGE_MODE_PREV:
        {
            prevImageType();

            screenState = SCREEN_DO_NOTHING;

            break;
        }
        case SCREEN_NEXT:
        {
            screenState = SCREEN_WAIT_FOR_NEXT;

            aveFPSValid = LE_FALSE;

            break;
        }
        case SCREEN_WAIT_FOR_NEXT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
                leEvent_GetCount() == 0)
            {
                screenState = SCREEN_MOVE_TO_NEXT;
            }

            break;
        }
        case SCREEN_MOVE_TO_NEXT:
        {
            screenState = SCREEN_DONE;

            legato_showScreen(screenID_FPSCounters);

            break;
        }
        case SCREEN_DONE:
        default:
            break;
    }


}

// event handlers
void ImageSizeDownButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_SIZE_DOWN;
    }
}

void ImageSizeUpButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_SIZE_UP;
    }
}

void ImageTypePrevButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_MODE_PREV;
    }
}

void ImageTypeNextButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_IMAGE_MODE_NEXT;
    }
}

void ImageNextButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_NEXT;
    }
}