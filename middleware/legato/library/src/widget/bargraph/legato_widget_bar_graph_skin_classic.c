/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/legato/widget/bargraph/legato_widget_bar_graph.h"

#if LE_BAR_GRAPH_WIDGET_ENABLED

#define TICK_LABEL_MARGIN 3

static char strbuff[MAX_TICK_LABEL_DIGITS];

#include <stdio.h>


#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#include "gfx/legato/widget/legato_widget_skin_classic_common.h"

enum
{
    NOT_STARTED = LE_WIDGET_DRAW_STATE_READY,
    DONE = LE_WIDGET_DRAW_STATE_DONE,
    DRAW_BACKGROUND,
    DRAW_BAR_GRAPH,
    DRAW_STRING,
    WAIT_STRING,    
    DRAW_BORDER,
};

static struct
{
    uint32_t alpha;
} paintState;

static void drawBackground(leBarGraphWidget* graph);
static void drawBarGraph(leBarGraphWidget* graph);
static void drawString(leBarGraphWidget* graph);
static void drawBorder(leBarGraphWidget* graph);
//static void waitString(leBarGraphWidget* btn);

static void nextState(leBarGraphWidget* graph)
{
    switch(graph->widget.drawState)
    {
        case NOT_STARTED:
        {
#if LE_ALPHA_BLENDING_ENABLED == 1
            if(graph->fn->getCumulativeAlphaEnabled(graph) == LE_TRUE)
            {
                paintState.alpha = graph->fn->getCumulativeAlphaAmount(graph);
            }
#else
            paintState.alpha = 255;
#endif
            
            if(graph->widget.backgroundType != LE_WIDGET_BACKGROUND_NONE) 
            {
                graph->widget.drawState = DRAW_BACKGROUND;
                graph->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawBackground;

                return;
            }
        }
        case DRAW_BACKGROUND:
        {
            graph->widget.drawState = DRAW_BAR_GRAPH;
            graph->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawBarGraph;
    
            return;
        }
        case DRAW_BAR_GRAPH:
        {            
            graph->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawString;
            graph->widget.drawState = DRAW_STRING;
            
            return;
        }
        case DRAW_STRING:
        {
            if(graph->widget.borderType != LE_WIDGET_BORDER_NONE)
            {
                graph->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawBorder;
                graph->widget.drawState = DRAW_BORDER;
                
                return;
            }
        }
        case DRAW_BORDER:
        {
            graph->widget.drawState = DONE;
            graph->widget.drawFunc = NULL;
        }
    }
}

static void drawBackground(leBarGraphWidget* graph)
{
    leWidget_SkinClassic_DrawStandardBackground((leWidget*)graph);
    
    nextState(graph);
}

static void drawTickLabelWithValue(leBarGraphWidget* graph,
                                   lePoint tickPoint,
                                   leRelativePosition position,
                                   int32_t value,
                                   uint32_t a)
{
    leRect textRect;

    //Protect from overflow
    if (value < MAX_TICK_LABEL_VALUE)
    {
        sprintf(strbuff, "%ld", value);
    }
    else
    {
        sprintf(strbuff, "---");
    }

    // get the string rectangle
    graph->ticksLabelString.fn->setFromCStr(&graph->ticksLabelString, strbuff);
    
    graph->ticksLabelString.fn->getRect(&graph->ticksLabelString, 0, &textRect);

    if (position == LE_RELATIVE_POSITION_LEFTOF)
    {
        textRect.x = tickPoint.x - textRect.width - LABEL_OFFSET_MIN_PIX;
        textRect.y = tickPoint.y - textRect.height / 2;
    }
    else if (position == LE_RELATIVE_POSITION_RIGHTOF)
    {
        textRect.x = tickPoint.x + textRect.width + LABEL_OFFSET_MIN_PIX;
        textRect.y = tickPoint.y - textRect.height / 2;
    }
    else
    {
        textRect.x = tickPoint.x;
        textRect.y = tickPoint.y;
    }
    
    graph->ticksLabelString.fn->_draw(&graph->ticksLabelString,
                                      textRect.x,
                                      textRect.y,
                                      graph->widget.scheme->text,
                                      LE_HALIGN_CENTER,
                                      0,
                                      a);
}

static void determineOriginPoint(leBarGraphWidget* bar)
{
    lePoint drawPoint;
    
    //Determine the origin point
    bar->originPoint.x = bar->graphRect.x;
    
    if (bar->minValue < 0 && bar->maxValue > 0)
    {
        bar->originPoint.y = bar->graphRect.y + (int32_t) ((float) bar->maxValue * bar->pixelsPerUnit);
        bar->originValue = 0;

        drawPoint = bar->originPoint;

        //Draw the origin line
        if(bar->valueAxisTicksVisible)
        {
            switch(bar->valueAxisTicksPosition)
            {
                case BAR_GRAPH_TICK_OUT:
                {
                    drawPoint.x -= bar->tickLength;
                    
                    break;
                }
                case BAR_GRAPH_TICK_CENTER:
                {
                    drawPoint.x -= bar->tickLength / 2;
                    
                    break;
                }
                default:
                {
                    break;
                }
            }
            
            leRenderer_DrawLine(drawPoint.x,
                                drawPoint.y,
                                bar->graphRect.x + bar->graphRect.width,
                                drawPoint.y,
                                bar->widget.scheme->foreground,
                                paintState.alpha);
        }
        else
        {
            leRenderer_DrawLine(drawPoint.x,
                                drawPoint.y,
                                bar->graphRect.x + bar->graphRect.width,
                                drawPoint.y,
                                bar->widget.scheme->foreground,
                                paintState.alpha);
        }

        if(bar->valueAxisLabelsVisible)
        {
            drawTickLabelWithValue(bar,
                                   drawPoint,
                                   LE_RELATIVE_POSITION_LEFTOF,
                                   bar->originValue,
                                   paintState.alpha);
        }
    }
    else if(bar->minValue >= 0)
    {
        bar->originPoint.y = bar->graphRect.y + bar->graphRect.height;
        bar->originValue = bar->minValue;
    }
    else if(bar->maxValue <= 0)
    {
        bar->originPoint.y = bar->graphRect.y;
        bar->originValue = bar->maxValue;
    }
}


static void fillGraphArea(leBarGraphWidget* bar)
{
    // fill the base
    if(bar->fillGraphArea == LE_FALSE)
        return;
        
    leRenderer_RectFill(&bar->graphRect,
                        bar->widget.scheme->base,
                        paintState.alpha);
}

static void drawGraphBorders(leBarGraphWidget* bar)
{
    leRect rect = bar->graphRect;
    
    // draw the graph borders
    leRenderer_DrawLine(rect.x,
                        rect.y,
                        rect.x,
                        rect.y + rect.height,
                        bar->widget.scheme->foreground,
                        paintState.alpha); // left
                        
    leRenderer_DrawLine(rect.x + rect.width,
                        rect.y,
                        rect.x + rect.width,
                        rect.y + rect.height,
                        bar->widget.scheme->foreground,
                        paintState.alpha); // right
}

static void adjustHorizontalBorders(leBarGraphWidget* bar)
{
    leRect rect;
    
    // adjust the horizontal borders if ticks are shown
    if(bar->valueAxisTicksVisible == LE_FALSE)
        return;
    
    rect = bar->graphRect;
    
    switch (bar->valueAxisTicksPosition)
    {
        case BAR_GRAPH_TICK_OUT:
        {
            leRenderer_DrawLine(rect.x - bar->tickLength, 
                                rect.y, 
                                rect.x + rect.width , 
                                rect.y,
                                bar->widget.scheme->foreground,
                                paintState.alpha); // top            
                          
            leRenderer_DrawLine(rect.x - bar->tickLength, 
                                rect.y + rect.height, 
                                rect.x + rect.width, 
                                rect.y + rect.height,
                                bar->widget.scheme->foreground,
                                paintState.alpha); // bottom
                                
            break;
        }
        case BAR_GRAPH_TICK_CENTER:
        {
            leRenderer_DrawLine(rect.x - bar->tickLength / 2, 
                                rect.y, 
                                rect.x + rect.width , 
                                rect.y,
                                bar->widget.scheme->foreground,
                                paintState.alpha); // top    
                                        
            leRenderer_DrawLine(rect.x - bar->tickLength / 2, 
                                rect.y + rect.height, 
                                rect.x + rect.width, 
                                rect.y + rect.height,
                                bar->widget.scheme->foreground,
                                paintState.alpha); // bottom
                                
            break;
        }
        default:
        {
            break;
        }
    }
}

static void drawMinMaxLabels(leBarGraphWidget* bar)
{
    lePoint drawPoint;
    
    // draw the labels for min/max values
    if(bar->valueAxisLabelsVisible == LE_FALSE)
        return;
    
    drawPoint.x = bar->graphRect.x;
    
    if (bar->valueAxisTicksVisible)
    {
        switch (bar->valueAxisTicksPosition)
        {
            case BAR_GRAPH_TICK_OUT:
            {
                drawPoint.x -= bar->tickLength;
                
                break;
            }
            case BAR_GRAPH_TICK_CENTER:
            {
                drawPoint.x -= bar->tickLength / 2;
                
                break;
            }
            default:
            {
                break;
            }
        }
    }
    
    drawPoint.y = bar->graphRect.y;
    
    drawTickLabelWithValue(bar,
                           drawPoint,
                           LE_RELATIVE_POSITION_LEFTOF,
                           bar->maxValue,
                           paintState.alpha);

    drawPoint.y = bar->graphRect.y + bar->graphRect.height;
    
    drawTickLabelWithValue(bar,
                           drawPoint,
                           LE_RELATIVE_POSITION_LEFTOF,
                           bar->minValue,
                           paintState.alpha);
}

static void drawTicks(leBarGraphWidget* bar)
{
    lePoint drawPoint;
    lePoint drawEndPoint;
    int32_t value;
    
    // draw the ticks
    if(bar->valueAxisTicksVisible == LE_FALSE &&
       bar->valueGridLinesVisible == LE_FALSE)
       return;
       
    if(bar->valueAxisTicksVisible)
    {
        switch(bar->valueAxisTicksPosition)
        {
            case BAR_GRAPH_TICK_OUT:
            {
                drawPoint.x = bar->graphRect.x - bar->tickLength;
                
                break;
            }
            case BAR_GRAPH_TICK_CENTER:
            {
                drawPoint.x = bar->graphRect.x - bar->tickLength / 2;
                
                break;
            }
            case BAR_GRAPH_TICK_IN:
            {
                drawPoint.x = bar->graphRect.x;
                
                break;
            }
            default:
            {
                break;
            }
        }
        
        drawEndPoint.x = drawPoint.x + bar->tickLength;
    }
    else
    {
        drawPoint.x = bar->graphRect.x;
        drawEndPoint = drawPoint;
    }
    
    if (bar->valueGridLinesVisible)
    {
        drawEndPoint.x = bar->graphRect.x + bar->graphRect.width;
    }

    //Start drawing the positive ticks or gridlines
    if(bar->maxValue > 0)
    {
        drawPoint.y = bar->originPoint.y;
        
        for(value = bar->originValue + bar->tickInterval; (value < bar->maxValue); value += bar->tickInterval)
        {
            drawPoint.y = bar->originPoint.y - (int32_t) ((float)(value - bar->originValue) * bar->pixelsPerUnit);
            
            if(drawPoint.y > bar->graphRect.y) 
            {
                leRenderer_DrawLine(drawPoint.x,
                                    drawPoint.y,
                                    drawEndPoint.x,
                                    drawPoint.y,
                                    bar->widget.scheme->foreground,
                                    paintState.alpha);

                if(bar->valueAxisLabelsVisible)
                {
                    drawTickLabelWithValue(bar,
                                           drawPoint,
                                           LE_RELATIVE_POSITION_LEFTOF,
                                           value,
                                           paintState.alpha);
                }
            }
        }
    }
    
    //Start drawing the negative ticks or gridlines
    if (bar->minValue < 0)
    {
        drawPoint.y = bar->originPoint.y;

        for (value = bar->originValue - bar->tickInterval; (value > bar->minValue); value -= bar->tickInterval)
        {
            drawPoint.y = bar->originPoint.y + (int32_t) ((float) (value - bar->originValue) * -bar->pixelsPerUnit);
            
            if (drawPoint.y < (bar->graphRect.y + bar->graphRect.height))
            {
                leRenderer_DrawLine(drawPoint.x,
                                    drawPoint.y,
                                    drawEndPoint.x,
                                    drawPoint.y,
                                    bar->widget.scheme->foreground,
                                    paintState.alpha);
            
                if (bar->valueAxisLabelsVisible)
                {
                   drawTickLabelWithValue(bar,
                                          drawPoint,
                                          LE_RELATIVE_POSITION_LEFTOF,
                                          value,
                                          paintState.alpha);
                }
            }
        }
    }
}

static void drawSubTicks(leBarGraphWidget* bar)
{
    lePoint drawPoint;
    int32_t value = 0;
    uint32_t subTickLength = bar->tickLength / 2;
    
    
    // draw the subticks, only if major ticks are also visible
    if(bar->valueAxisSubticksVisible == LE_FALSE ||
       bar->valueAxisTicksVisible == LE_FALSE)
       return;
       
    value = 0;

    drawPoint.x = 0;
    drawPoint.y = bar->originPoint.y;
    
    switch (bar->valueAxisSubticksPosition)
    {
        case BAR_GRAPH_TICK_OUT:
        {
            drawPoint.x = bar->graphRect.x - subTickLength;
            
            break;
        }
        case BAR_GRAPH_TICK_CENTER:
        {
            drawPoint.x = bar->graphRect.x - subTickLength / 2;
            
            break;
        }
        case BAR_GRAPH_TICK_IN:
        {
            drawPoint.x = bar->graphRect.x;
            
            break;
        }
        default:
        {
            break;
        }
    }
    
    // Draw the subticks above the origin point
    for (value = bar->originValue + bar->subtickInterval; (value < bar->maxValue); value += bar->subtickInterval)
    {
        drawPoint.y = bar->originPoint.y - (int32_t) ((float) (value - bar->originValue) * bar->pixelsPerUnit);

        if(drawPoint.y > bar->graphRect.y)
        {
            leRenderer_DrawLine(drawPoint.x,
                                drawPoint.y,
                                drawPoint.x + subTickLength,
                                drawPoint.y,
                                bar->widget.scheme->foreground,
                                paintState.alpha);                
        }
    }

    //Start drawing the negative ticks or gridlines
    drawPoint.y = bar->originPoint.y;
    
    for(value = bar->originValue - bar->subtickInterval; value > bar->minValue; value -= bar->subtickInterval)
    {
        drawPoint.y = bar->originPoint.y + (int32_t) ((float)(bar->originValue - value) * bar->pixelsPerUnit); 
        
        if (drawPoint.y < (bar->graphRect.y + bar->graphRect.height))
        {
            leRenderer_DrawLine(drawPoint.x,
                                drawPoint.y,
                                drawPoint.x + subTickLength,
                                drawPoint.y,
                                bar->widget.scheme->foreground,
                                paintState.alpha);                
        }
    }
}

static void drawCategoryTicks(leBarGraphWidget* bar)
{
    uint32_t categoryIndex = 0;
    lePoint drawPoint = bar->originPoint;
    uint32_t length = bar->tickLength;
    
    if(bar->categAxisTicksVisible == LE_FALSE || bar->categories.size <= 0)
        return;
    
    switch(bar->categAxisTicksPosition)
    {
        case BAR_GRAPH_TICK_OUT:
        {
            drawPoint.y = bar->originPoint.y;
            break;
        }
        case BAR_GRAPH_TICK_CENTER:
        {
            drawPoint.y = bar->originPoint.y - bar->tickLength / 2;
            break;
        }
        case BAR_GRAPH_TICK_IN:
        {
            drawPoint.y = bar->originPoint.y - bar->tickLength;
            break;
        }
        default:
            break;
    }
    
    if (drawPoint.y < bar->graphRect.y)
    {
        length = bar->originPoint.y - bar->graphRect.y;
        drawPoint.y = bar->graphRect.y;
    }
    
    for(categoryIndex = 1;
       ((drawPoint.x < bar->graphRect.x + bar->graphRect.width) && (categoryIndex < bar->categories.size));
       categoryIndex++)
    {
        drawPoint.x = bar->graphRect.x + categoryIndex * bar->graphRect.width / bar->categories.size;
        
        leRenderer_DrawLine(drawPoint.x,
                            drawPoint.y,
                            drawPoint.x,
                            drawPoint.y + length,
                            bar->widget.scheme->foreground,
                            paintState.alpha);
    }
}

static void drawUnstackedBars(leBarGraphWidget* bar)
{
    uint32_t barWidthPixels;
    uint32_t categoryIndex = 0;
    uint32_t seriesIndex = 0;
    leBarGraphDataSeries* series;
    int32_t* valuePtr;
    int32_t value;
    leRect valueRect;
    int32_t height;
    
    if(bar->categories.size <= 0 || bar->dataSeriesArray.size <= 0)
        return;
        
    //determine the width of each category + L & R margins
    barWidthPixels = (bar->graphRect.width / (bar->categories.size * (bar->dataSeriesArray.size + 2)));

    for (seriesIndex = 0; seriesIndex < bar->dataSeriesArray.size; seriesIndex++)
    {
        series = leArray_Get(&bar->dataSeriesArray, seriesIndex);
        
        if(series == NULL)
            continue;
        
        for(categoryIndex = 0;
            (categoryIndex < bar->categories.size && categoryIndex < series->data.size); 
            categoryIndex++)
        {
            valuePtr = leArray_Get(&series->data, categoryIndex);
            
            if (valuePtr == NULL)
                continue;
            
            value = *valuePtr;
            
            valueRect.x = bar->originPoint.x + 
                          (categoryIndex * bar->graphRect.width / bar->categories.size) + 
                          seriesIndex * barWidthPixels + barWidthPixels;
            
            // draw the bars above the origin value
            if (value > bar->originValue && bar->maxValue > bar->originValue)
            {
                valueRect.y = bar->originPoint.y - (int32_t) ((float)(value - bar->originValue) * bar->pixelsPerUnit);

                if (valueRect.y <= bar->graphRect.y)
                {
                    valueRect.y = bar->graphRect.y;
                }
                
                valueRect.width = barWidthPixels;
                valueRect.height = bar->originPoint.y - valueRect.y;
                
                leRenderer_RectFill(&valueRect,
                                    series->scheme->foreground,
                                    paintState.alpha);
            }
            //draw the bars below the origin value
            else if(value < bar->originValue && bar->minValue < bar->originValue)
            {
                valueRect.y = bar->originPoint.y + 1;
                
                height = (int32_t) ((float)(bar->originValue - value) * bar->pixelsPerUnit);
                
                if (height >= (bar->graphRect.y + bar->graphRect.height - bar->originPoint.y))
                {
                    height = bar->graphRect.y + bar->graphRect.height - bar->originPoint.y;
                }
                
                valueRect.width = barWidthPixels;
                valueRect.height = height;
                
                leRenderer_RectFill(&valueRect,
                                    series->scheme->foreground,
                                    paintState.alpha);
            }
        }
    }
}

static void drawStackedBars(leBarGraphWidget* bar)
{   
    uint32_t barWidthPixels;
    uint32_t categoryIndex = 0;
    uint32_t seriesIndex = 0;
    leBarGraphDataSeries* series;
    int32_t* valuePtr;
    int32_t value;
    leRect valueRect;
    int32_t bottomValue;
    int32_t topValue;
    lePoint topPoint;
    lePoint bottomPoint;
        
    // draw the bars
    if(bar->categories.size <= 0 || bar->dataSeriesArray.size <= 0)
        return;
        
    //determine the width each category
    barWidthPixels = (bar->graphRect.width / bar->categories.size) / 3;
    
    for (categoryIndex = 0; 
         (categoryIndex < bar->categories.size); 
         categoryIndex++)
    {
        bottomValue = 0;
        topValue = 0;
        topPoint = bar->originPoint;
        bottomPoint = bar->originPoint;

        for (seriesIndex = 0; seriesIndex < bar->dataSeriesArray.size; seriesIndex++)
        {
            series = leArray_Get(&bar->dataSeriesArray, seriesIndex);
            
            if(categoryIndex >= series->data.size)
                continue;

            valuePtr = leArray_Get(&series->data, categoryIndex);
        
            if(valuePtr == NULL)
                continue;
            
            value = *valuePtr;

            valueRect.x = bar->originPoint.x + 
                          ((categoryIndex * bar->graphRect.width) / bar->categories.size) + 
                          (bar->graphRect.width / (bar->categories.size * 2)) - 
                          (barWidthPixels/2);
            
            // draw the bars above the origin value
            if(value > 0 && topValue < bar->maxValue)
            {
                topValue += value;

                if (topValue < bar->originValue)
                    continue;

                if (topValue > bar->maxValue)
                {
                    topValue = bar->maxValue;
                }
                
                valueRect.y = bar->originPoint.y - (int32_t) ((float) (topValue - bar->originValue) * bar->pixelsPerUnit);
              
                if (valueRect.y <= bar->graphRect.y)
                {
                    valueRect.y = bar->graphRect.y;
                }
                
                valueRect.width = barWidthPixels;
                valueRect.height = topPoint.y - valueRect.y;
                
                leRenderer_RectFill(&valueRect,
                                    series->scheme->foreground,
                                    paintState.alpha);
                
                topPoint.y = valueRect.y;
                
            }
            //draw the bars below if the origin value
            else if(value < 0 && bottomValue > bar->minValue)
            {
                bottomValue += value;
                bottomPoint.y += 1;

                if(bottomValue > bar->originValue)
                    continue;

                valueRect.y = bar->originPoint.y + (int32_t) ((float) (bar->originValue - bottomValue) * bar->pixelsPerUnit);
                
                if (valueRect.y >= bar->graphRect.y + bar->graphRect.height)
                {
                    valueRect.y = bar->graphRect.y + bar->graphRect.height;
                }
                
                valueRect.width = barWidthPixels;
                valueRect.height = valueRect.y - bottomPoint.y + 1;
                
                leRenderer_RectFill(&valueRect,
                                    series->scheme->foreground,
                                    paintState.alpha);
                
                bottomPoint.y = valueRect.y;
            }
        }
    }
}

static void drawHorizontalBorders(leBarGraphWidget* bar)
{
    // draw the horizontal borders
    leRenderer_DrawLine(bar->graphRect.x,
                        bar->graphRect.y,
                        bar->graphRect.x + bar->graphRect.width,
                        bar->graphRect.y,
                        bar->widget.scheme->foreground,
                        paintState.alpha); // top
                                    
    leRenderer_DrawLine(bar->graphRect.x,
                        bar->graphRect.y + bar->graphRect.height,
                        bar->graphRect.x + bar->graphRect.width,
                        bar->graphRect.y + bar->graphRect.height,
                        bar->widget.scheme->foreground,
                        paintState.alpha); // bottom
}

void _leBarGraphWidget_GetGraphRect(const leBarGraphWidget* _this,
                                    leRect* graphRect);

static void drawBarGraph(leBarGraphWidget* graph)
{
    leRect widgetRect;
    
    widgetRect = graph->fn->localRect(graph);
    leUtils_RectToScreenSpace((leWidget*)graph, &widgetRect);
    
        
    _leBarGraphWidget_GetGraphRect(graph, &graph->graphRect);
    
    graph->pixelsPerUnit = (float) graph->graphRect.height / ((float) graph->maxValue - (float) graph->minValue);
    
    fillGraphArea(graph);
    drawGraphBorders(graph);
    adjustHorizontalBorders(graph);
    drawMinMaxLabels(graph);
    determineOriginPoint(graph);
    drawTicks(graph);
    drawSubTicks(graph);
    drawCategoryTicks(graph);
    
    if(graph->stacked == LE_TRUE)
    {
        drawStackedBars(graph);
    }
    else
    {
        drawUnstackedBars(graph);
    }
    
    drawHorizontalBorders(graph);
    
    nextState(graph);
}

static void _leBarGraphWidget_GetCategoryTextRect(leBarGraphWidget* graph,
                                                  uint32_t categoryIndex,
                                                  const leRect* graphRect,
                                                  leRect* textRect,
                                                  leRect* drawRect)
{
    leString* category;
    leRect bounds;
    
    *textRect = leRect_Zero;
    *drawRect = leRect_Zero;
    
    if(categoryIndex >= graph->categories.size)
        return;
    
    category = leArray_Get(&graph->categories, categoryIndex);
    
    if(category == NULL)
        return;
        
    category->fn->getRect(category, 0, textRect);
    
    bounds.x = 0;
    bounds.y = 0;
    bounds.width = graphRect->width;
    bounds.height = textRect->height;
    
    leRectClip(textRect, &bounds, drawRect);

    //get center of category, arrange text below it
    switch(graph->categAxisTicksPosition)
    {
        case BAR_GRAPH_TICK_OUT:
        {
            textRect->y = graphRect->y + graphRect->height + graph->tickLength + LABEL_OFFSET_MIN_PIX;
            
            break;
        }
        case BAR_GRAPH_TICK_CENTER:
        {
            textRect->y = graphRect->y + graphRect->height + graph->tickLength / 2 + LABEL_OFFSET_MIN_PIX;
            
            break;
        }
        case BAR_GRAPH_TICK_IN:
        {
            textRect->y = graphRect->y + graphRect->height + LABEL_OFFSET_MIN_PIX;
            
            break;
        }
        default:
        {
            break;
        }
    }
                
    textRect->x = graphRect->x + 
                 (categoryIndex * graphRect->width / graph->categories.size) + 
                 (graphRect->width / (graph->categories.size * 2)) - (textRect->width / 2);

    drawRect->x = textRect->x;
    drawRect->y = textRect->y;
}

static void drawString(leBarGraphWidget* graph)
{
    leRect textRect, drawRect, graphRect;
    leString* category;
    uint32_t categoryIndex = 0;
    uint32_t a = 255;

    if (graph->categAxisLabelsVisible)
    {
        _leBarGraphWidget_GetGraphRect(graph, &graphRect);
        
        for (categoryIndex = 0; 
             (categoryIndex < graph->categories.size); 
             categoryIndex++)
        {
            category = leArray_Get(&graph->categories, categoryIndex);
            
            if (category == NULL)
                return;
                
            _leBarGraphWidget_GetCategoryTextRect(graph,
                                                  categoryIndex,
                                                  &graphRect,
                                                  &textRect,
                                                  &drawRect);
                 
            category->fn->_draw(category,
                                textRect.x,
                                textRect.y,
                                graph->widget.scheme->text,
                                graph->alpha,
                                LE_HALIGN_LEFT,
                                a);
         
#if LE_EXTERNAL_STREAMING_ENABLED == 1
            if(graph->reader != NULL)
            {
                graph->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&waitString;
                graph->widget.drawState = WAIT_STRING;

                return;
            }
#endif
        }
    }

    nextState(graph);
}

#if LE_EXTERNAL_STREAMING_ENABLED == 1
static void waitString(leBarGraphWidget* graph)
{
    if(graph->reader->status != leREADER_STATUS_FINISHED)
    {
        graph->reader->run(graph->reader);
        
        return;
    }
    
    // free the reader
    graph->reader->memIntf->heap.free(graph->reader);
    graph->reader = NULL;
    
    graph->widget.drawState = DRAW_STRING;
    
    nextState(graph);
}
#endif

static void drawBorder(leBarGraphWidget* graph)
{    
    if(graph->widget.borderType == LE_WIDGET_BORDER_LINE)
    {
        leWidget_SkinClassic_DrawStandardLineBorder((leWidget*)graph);
    }
    else if(graph->widget.borderType == LE_WIDGET_BORDER_BEVEL)
    {
        leWidget_SkinClassic_DrawStandardRaisedBorder((leWidget*)graph);
    }
    
    nextState(graph);
}

void _leBarGraphWidget_Paint(leBarGraphWidget* graph)
{
    if(graph->widget.scheme == NULL)
    {
        graph->widget.drawState = DONE;
        
        return;
    }
    
    if(graph->widget.drawState == NOT_STARTED)
        nextState(graph);
    
    while(graph->widget.drawState != DONE)
    {
        graph->widget.drawFunc((leWidget*)graph);
        
#if LE_PREEMPTION_LEVEL == 2
        break;
#endif
    }
}

#endif // LE_BAR_GRAPH_WIDGET_ENABLED