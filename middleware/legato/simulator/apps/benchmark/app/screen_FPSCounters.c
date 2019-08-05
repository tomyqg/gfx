#include "gfx/legato/generated/screen/le_gen_screen_FPSCounters.h"

#include <stdio.h>
#include <string.h>

#include "sim_time.h"

static uint32_t fpsTickTarget;


#define AVE_FPS_COUNT 10
#define FPS_UPDATE_TIMER_PERIOD_MS 1000
#define MAX_COUNTDOWN 9999
#define MIN_COUNTDOWN 0
#define MIN_COUNTER_SIZE 1
#define MAX_COUNTER_SIZE 5


static volatile leBool aveFPSValid = LE_FALSE;
static int aveCounter = 0;
static uint32_t prevDrawCountAve[AVE_FPS_COUNT] = {0};
static uint32_t prevDrawCount;
static uint32_t prevVsyncCount;
static int32_t tickDecCount;

static uint32_t counterStringSize;

static leDynamicString fpsBtnText;
static leDynamicString refreshRateText;
static leDynamicString decStr;
static leDynamicString counterSizeStringText;

static char charBuff[16] = {0};

unsigned int counterSizeStrings[MAX_COUNTER_SIZE + 1] =
    {
        0x00,
        string_NumsTiny,
        string_NumsLittle,
        string_NumsSmall,
        string_NumsMed,
        string_NumsLarge,
    };

static enum
{
    SCREEN_DO_NOTHING = 0,
    SCREEN_COUNTER_SIZE_UP,
    SCREEN_COUNTER_SIZE_DOWN,
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
    FPSCounterValue->fn->setString(FPSCounterValue, (leString*)&fpsBtnText);

    prevDrawCount = 0;
    prevVsyncCount = 0;
}

static void fpsUpdateTimer_Callback()
{
    unsigned int rate;
    unsigned int i;

    if(FPSCounterValue == NULL)
        return;

    //Update the 10-pt rolling average
    prevDrawCountAve[aveCounter] = (leGetRenderState()->drawCount - prevDrawCount);

    //If not pressed, show current FPS
    if(FPSUpdateValue->fn->getPressed(FPSUpdateValue) == LE_FALSE)
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
    FPSUpdateValue->fn->setString(FPSUpdateValue, (leString*)&fpsBtnText);


    //Update Refresh Rate
    uint32_t vsyncCount = leGetRenderState()->dispDriver->getVSYNCCount();
    rate =  (vsyncCount - prevVsyncCount) / (FPS_UPDATE_TIMER_PERIOD_MS/1000);

    //If vsyncCount does not increase, assume fixed refresh rate using vsyncCount
    //value
    if (rate == 0)
        rate = vsyncCount;

    sprintf(charBuff, "%u", rate);

    refreshRateText.fn->setFromCStr(&refreshRateText, charBuff);
    FPSRefreshValue->fn->setString(FPSRefreshValue,
                                   (leString*)&refreshRateText);


    prevDrawCount = leGetRenderState()->drawCount;
    prevVsyncCount = vsyncCount;

//    APP_DecrementCount(FPSCounterValue);
}

static void increaseCounterSize()
{
    if(counterStringSize < MAX_COUNTER_SIZE)
    {
        counterStringSize += 1;
    }
    else
    {
        return;
    }

    FPSCounterValue->fn->invalidate(FPSCounterValue);

    sprintf(charBuff, "%u", (unsigned int)counterStringSize);

    counterSizeStringText.fn->setFromCStr(&counterSizeStringText, charBuff);
    FPSStringSize->fn->setString(FPSStringSize, (leString*)&counterSizeStringText);

    resetFPS();
}

static void decreaseCounterSize()
{
    if(counterStringSize > 1)
    {
        counterStringSize -= 1;
    }
    else
    {
        return;
    }

    FPSCounterValue->fn->invalidate(FPSCounterValue);

    sprintf(charBuff, "%u", (unsigned int)counterStringSize);

    counterSizeStringText.fn->setFromCStr(&counterSizeStringText, charBuff);
    FPSStringSize->fn->setString(FPSStringSize, (leString*)&counterSizeStringText);

    resetFPS();
}

static void decrementCount()
{
    tickDecCount--;

    if (tickDecCount <= MIN_COUNTDOWN)
        tickDecCount = MAX_COUNTDOWN;

    sprintf(charBuff, "%04u", (unsigned int)tickDecCount);

    decStr.fn->setFont(&decStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                            counterSizeStrings[counterStringSize],
                                                            0));

    decStr.fn->setFromCStr(&decStr, charBuff);
    FPSCounterValue->fn->setString(FPSCounterValue, (leString*)&decStr);
}

void FPSCounters_OnShow()
{
    leFont* font = NULL;

    tickDecCount = MAX_COUNTDOWN;

    font = leStringTable_GetStringFont(&stringTable, string_NumsLittle, 0);

    leDynamicString_Constructor(&fpsBtnText);
    fpsBtnText.fn->setFont(&fpsBtnText, font);

    leDynamicString_Constructor(&refreshRateText);
    refreshRateText.fn->setFont(&refreshRateText, font);

    leDynamicString_Constructor(&counterSizeStringText);
    counterSizeStringText.fn->setFont(&counterSizeStringText, font);

    leDynamicString_Constructor(&decStr);
    decStr.fn->setFont(&decStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                            counterSizeStrings[counterStringSize],
                                                            0));

    counterStringSize = 5;

    resetFPS();

    memset(prevDrawCountAve, 0, sizeof(prevDrawCountAve));

    sprintf(charBuff, "%u", (unsigned int)counterStringSize);

    counterSizeStringText.fn->setFromCStr(&counterSizeStringText, charBuff);
    FPSStringSize->fn->setString(FPSStringSize, (leString*)&counterSizeStringText);

    screenState = SCREEN_DO_NOTHING;

    fpsTickTarget = sim_TimeTotal() + FPS_UPDATE_TIMER_PERIOD_MS;
}

void FPSCounters_OnHide()
{
    fpsBtnText.fn->destructor(&fpsBtnText);
    refreshRateText.fn->destructor(&refreshRateText);
    counterSizeStringText.fn->destructor(&counterSizeStringText);
    decStr.fn->destructor(&decStr);
}

void FPSCounters_OnUpdate()
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
            decrementCount();

            break;
        }
        case SCREEN_COUNTER_SIZE_UP:
        {
            increaseCounterSize();

            screenState = SCREEN_DO_NOTHING;

            break;
        }
        case SCREEN_COUNTER_SIZE_DOWN:
        {
            decreaseCounterSize();

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

            legato_showScreen(screenID_FPSMotion);

            break;
        }
        case SCREEN_DONE:
        default:
            break;
    }


}

// event handlers
void FPSCounterSizeDown_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_COUNTER_SIZE_DOWN;
    }
}

void FPSCounterSizeUp_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_COUNTER_SIZE_UP;
    }
}

void FPSNextButton_OnPressed(leButtonWidget* btn)
{
    if(screenState == SCREEN_DO_NOTHING)
    {
        screenState = SCREEN_WAIT_FOR_NEXT;
    }
}