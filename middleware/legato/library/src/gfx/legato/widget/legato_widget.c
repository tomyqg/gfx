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

#include "gfx/legato/widget/legato_widget.h"

#include <string.h>

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/widget/legato_widget_skin_classic_common.h"

static leWidgetVTable widgetVTable;

static leWidget_MoveEvent _moveEvent =
{
    {
        LE_WIDGET_EVENT_MOVED,
    },
    0,
    0,
    0,
    0
};

static leWidget_ResizeEvent _resizeEvent =
{
    {
        LE_WIDGET_EVENT_RESIZED,
    },
    0,
    0,
    0,
    0
};

void leWidget_Constructor(leWidget* _this)
{
    uint32_t i;

    LE_ASSERT_THIS();
    
    _this->fn = &widgetVTable;
    
    _this->id = leGetState()->widgetIDs++;

    _this->type = LE_WIDGET_WIDGET;
    
    _this->visible = LE_TRUE;
    _this->enabled = LE_TRUE;
    _this->dirtyState = LE_WIDGET_DIRTY_STATE_DIRTY;
    _this->drawState = LE_WIDGET_DRAW_STATE_READY;

    _this->rect.x = 0;
    _this->rect.y = 0;
    _this->rect.width = 100;
    _this->rect.height = 100;
    _this->cornerRadius = 0;

    _this->borderType = LE_WIDGET_BORDER_NONE;
    _this->backgroundType = LE_WIDGET_BACKGROUND_FILL;
            
#if LE_ALPHA_BLENDING_ENABLED == 1
    _this->alphaEnabled = LE_FALSE;
    _this->alphaAmount = 255;
#endif
            
    _this->halign = LE_HALIGN_CENTER;
    _this->valign = LE_VALIGN_MIDDLE;
            
    _this->margin.left = DEFAULT_BORDER_MARGIN;
    _this->margin.top = DEFAULT_BORDER_MARGIN;
    _this->margin.right = DEFAULT_BORDER_MARGIN;
    _this->margin.bottom = DEFAULT_BORDER_MARGIN;
    
    _this->scheme = leGetDefaultScheme();

    for(i = 0; i < LE_WIDGET_MAX_EVENT_FILTERS; i++)
    {
        _this->eventFilters[i].filterEvent = NULL;
        _this->eventFilters[i].data = NULL;
    }

    _this->root = LE_FALSE;
    _this->parent = NULL;

    leArray_Create(&_this->children);

    _this->optimizationFlags = 0;
    _this->drawCount = 0;
    _this->drawFunc = NULL;
}

void _leWidget_Destructor(leWidget* _this)
{
    leWidget* child;
    uint32_t i;

    LE_ASSERT_THIS();

    if(leGetFocusWidget() == (void*)_this)
    {
        leSetFocusWidget(NULL);
    }

    if(leGetEditWidget() == (void*)_this)
    {
        leSetEditWidget(NULL);
    }
    
    for(i = 0; i < _this->children.size; i++)
    {
        child = _this->children.values[i];
        child->fn->_destructor(child);
        
        LE_FREE(child);
    }

    leArray_Clear(&_this->children);
}

leWidget* leWidget_New()
{
    leWidget* wgt = NULL;

    wgt = LE_MALLOC(sizeof(leWidget));
    
    LE_ASSERT(wgt != NULL);

    if(wgt == NULL)
        return NULL;
    
    leWidget_Constructor(wgt);

    return wgt;
}

void leWidget_Delete(leWidget* wgt)
{
    if(wgt == NULL)
        return;
        
    wgt->fn->_destructor(wgt);
    
    LE_FREE(wgt);
}

static leWidgetType getType(const leWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->type;
}

int32_t _leWidget_GetX(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->rect.x;
}

leResult _leWidget_SetX(leWidget* _this,
                        int32_t x)
{
    leRect area;
    
    LE_ASSERT_THIS();

    if(_this->rect.x == x)
        return LE_SUCCESS;

    // invalidate old area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
        
    _this->rect.x = x;

    // invalidate new area
    area = _this->fn->rectToScreen(_this);

    _this->fn->_damageArea(_this, &area);
        
    return LE_SUCCESS;
}

int32_t _leWidget_GetY(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->rect.y;
}

leResult _leWidget_SetY(leWidget* _this,
                        int32_t y)
{
    leRect area;
    
    LE_ASSERT_THIS();

    if(_this->rect.y == y)
        return LE_SUCCESS;

    // invalidate old area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
        
    _this->rect.y = y;
    
    // invalidate new area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
        
    return LE_SUCCESS;
}

leResult _leWidget_SetPosition(leWidget* _this,
                               int32_t x,
                               int32_t y)
{   
    leRect area;
    
    LE_ASSERT_THIS();
    
    if(_this->rect.x == x && _this->rect.y == y)
        return LE_FAILURE;

    // invalidate old area
    area = _this->fn->rectToScreen(_this);

    _this->fn->_damageArea(_this, &area);

    _moveEvent.oldX = _this->rect.x;
    _moveEvent.oldY = _this->rect.y;

    _this->rect.x = x;
    _this->rect.y = y;
    
    _moveEvent.newX = _this->rect.x;
    _moveEvent.newY = _this->rect.y;

    _this->fn->_handleEvent(_this, (leEvent*)&_moveEvent);

    // invalidate new area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);

    return LE_SUCCESS;
}

leResult _leWidget_Translate(leWidget* _this,
                             int32_t x,
                             int32_t y)
{
    leRect area;
 
    if(x == 0 && y == 0)
        return LE_FAILURE;
        
    LE_ASSERT_THIS();

    // invalidate old area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
    
    _moveEvent.oldX = _this->rect.x;
    _moveEvent.oldY = _this->rect.y;
    
    _this->rect.x += x;
    _this->rect.y += y;
    
    _moveEvent.newX = _this->rect.x;
    _moveEvent.newY = _this->rect.y;

    _this->fn->_handleEvent(_this, (leEvent*)&_moveEvent);

    // invalidate new area 
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
      
    return LE_SUCCESS;
}

uint32_t _leWidget_GetWidth(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->rect.width;
}

leResult _leWidget_SetWidth(leWidget* _this,
                            uint32_t width)
{
    leRect area;

    LE_ASSERT_THIS();
    
    if(_this->rect.width == width)
        return LE_SUCCESS;

    // invalidate old area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
        
    _this->rect.width = width;
    
    // invalidate new area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
       
    return LE_SUCCESS;
}

uint32_t _leWidget_GetHeight(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->rect.height;
}

leResult _leWidget_SetHeight(leWidget* _this,
                             uint32_t height)
{
    leRect area;

    LE_ASSERT_THIS();
    
    if(_this->rect.height == height)
        return LE_SUCCESS;

    // invalidate old area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
        
    _this->rect.height = height;
    
    // invalidate new area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
        
    return LE_SUCCESS;
}

leResult _leWidget_SetSize(leWidget* _this,
                           uint32_t width,
                           uint32_t height)
{
    leRect area;
    
    LE_ASSERT_THIS();
    
    if(_this->rect.width == width && _this->rect.height == height)
        return LE_FAILURE;

    if(width == 0)
    {
        width = 1;
    }
    
    if(height == 0)
    {
        height = 1;
    }
        
    // invalidate old area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
    
    _resizeEvent.oldWidth = _this->rect.width;
    _resizeEvent.oldHeight = _this->rect.height;

    _this->rect.width = width;
    _this->rect.height = height;
    
    _resizeEvent.newWidth = _this->rect.width;
    _resizeEvent.newHeight = _this->rect.height;
    
    _this->fn->_handleEvent(_this, (leEvent*)&_resizeEvent);

    // invalidate new area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
  
    return LE_SUCCESS;
}

leResult _leWidget_Resize(leWidget* _this, 
                          int32_t width,
                          int32_t height)
{
    leRect area;
    
    LE_ASSERT_THIS();
    
    if(width == 0 && height == 0)
        return LE_FAILURE;

    // invalidate old area    
    area = _this->rect;
    leUtils_RectToScreenSpace(_this, &area);
    
    _this->fn->_damageArea(_this, &area);
    
    _resizeEvent.oldWidth = _this->rect.width;
    _resizeEvent.oldHeight = _this->rect.height;
    
    _this->rect.width += width;
    _this->rect.height += height;

    if(_this->rect.width < 1)
    {
        _this->rect.width = 1;
    }
    
    if(_this->rect.height < 1)
    {
        _this->rect.height = 1;
    }
    
    _resizeEvent.newWidth = _this->rect.width;
    _resizeEvent.newHeight = _this->rect.height;
    
    _this->fn->_handleEvent(_this, (leEvent*)&_resizeEvent);
    
    // invalidate new area    
    area = _this->rect;
    leUtils_RectToScreenSpace(_this, &area);
    
    _this->fn->_damageArea(_this, &area);

    return LE_SUCCESS;
}

leBool _leWidget_GetAlphaEnabled(const leWidget* _this)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    LE_ASSERT_THIS();
    
    return _this->alphaEnabled;
#else
    return LE_FALSE;
#endif
}

leBool _leWidget_GetCumulativeAlphaEnabled(const leWidget* _this)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    LE_ASSERT_THIS();
    
    while(_this != NULL)
    {
        if(_this->alphaEnabled == LE_TRUE)
            return LE_TRUE;
        
        _this = _this->parent; 
    }
#endif
    
    return LE_FALSE;
}

leResult _leWidget_SetAlphaEnabled(leWidget* _this,
                                   leBool enable)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    LE_ASSERT_THIS();
    
    if(_this->alphaEnabled == enable)
        return LE_FAILURE;
        
    _this->alphaEnabled = enable;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
#else
    return LE_FAILURE;
#endif
}

uint32_t _leWidget_GetAlphaAmount(const leWidget* _this)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    LE_ASSERT_THIS();
    
    return _this->alphaAmount;
#else
    return 255;
#endif
}

uint32_t _leWidget_GetCumulativeAlphaAmount(const leWidget* _this)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    int32_t amount = 0;
    int32_t localAmount = 0;
    int32_t actualAmount = 0;
   
    LE_ASSERT_THIS();
     
    if(_this->fn->getCumulativeAlphaEnabled(_this) == LE_FALSE)
        return 255;
        
    localAmount = lePercentWholeRounded(_this->alphaAmount, 255);
    actualAmount = localAmount;
        
    _this = _this->parent;
        
    while(_this != NULL && _this->fn->getCumulativeAlphaEnabled(_this) == LE_TRUE)
    {
        amount = lePercentWholeRounded(_this->alphaAmount, 255);
        
        actualAmount = lePercentOf(actualAmount, amount);
        
        _this = _this->parent;
    }
    
    return lePercentOf(255, actualAmount);
#else
    return 255;
#endif
}

leResult _leWidget_SetAlphaAmount(leWidget* _this,
                                  uint32_t alpha)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    LE_ASSERT_THIS();
    
    if(_this->alphaAmount == alpha)
        return LE_FAILURE;
        
    if(alpha > 255)
    {
        alpha = 255;
    }
        
    _this->alphaAmount = alpha;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
#else
    return LE_FAILURE;
#endif
}

leBool _leWidget_IsOpaque(const leWidget* _this)
{
#if LE_ALPHA_BLENDING_ENABLED == 1
    LE_ASSERT_THIS();
    
    if (_this->fn->getCumulativeAlphaEnabled(_this) == LE_TRUE &&
        _this->fn->getCumulativeAlphaAmount(_this) < 255)
    {
         return LE_FALSE;
    }
        
    if(_this->backgroundType == LE_WIDGET_BACKGROUND_NONE /*&&
       (_this->optimizationFlags & LE_WIDGET_OPT_OPAQUE) == 0*/)
    {
       return LE_FALSE;
    }
#endif
       
    return LE_TRUE;
}

leBool _leWidget_GetEnabled(const leWidget* _this)
{
    return _this->enabled;
}

leResult _leWidget_SetEnabled(leWidget* _this, leBool enable)
{
    LE_ASSERT_THIS();
    
    if(_this->enabled == enable)
        return LE_FAILURE;
        
    _this->enabled = enable;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

leBool _leWidget_GetVisible(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->visible;
}

leResult _leWidget_SetVisible(leWidget* _this, leBool visible)
{
    LE_ASSERT_THIS();
    
    if(_this->visible == visible)
        return LE_FAILURE;
        
    _this->visible = visible;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

leRect _leWidget_LocalRect(const leWidget* _this)
{
    leRect res;
    
    LE_ASSERT_THIS();
    
    res = _this->rect;
    
    res.x = 0;
    res.y = 0;
    
    return res;
}

leRect _leWidget_RectToParentSpace(const leWidget* _this)
{
    leRect rect = {0};
    
    LE_ASSERT_THIS();
    
    if(_this != NULL && _this->parent != NULL)
    {
        rect = _this->rect;
        
        rect.x += _this->parent->rect.x;
        rect.y += _this->parent->rect.y;
    }
    
    return rect;
}

leRect _leWidget_RectToScreenSpace(const leWidget* _this)
{
    leRect rect = {0};
 
    LE_ASSERT_THIS();
    
    if(_this == NULL)
        return rect;
        
    rect = _this->rect;
    
    if(_this != NULL && _this->parent != NULL)
    {
        leUtils_RectToScreenSpace(_this->parent, &rect);
    }
    
    return rect;
}

static leBool isAncestorOf(const leWidget* sub, const leWidget* obj)
{  
    if(sub == NULL || obj == NULL)
        return LE_FALSE;
        
    if(obj->parent == NULL)
        return LE_FALSE;
        
    if(sub == obj->parent)
        return LE_TRUE;
        
    return isAncestorOf(sub, obj->parent);
}

leResult _leWidget_AddChild(leWidget* _this,
                            leWidget* child)
{
    LE_ASSERT_THIS();
    
    if(child == NULL ||
       child->root == LE_TRUE ||
       isAncestorOf(child, _this) == LE_TRUE)
    {
        return LE_FAILURE;
    }
        
    if(child->parent != NULL)
    {
        child->parent->fn->removeChild(child->parent, child);
    }
    
    leArray_PushBack(&_this->children, child);
    child->parent = _this;

    child->fn->invalidate(child);

    return LE_SUCCESS;
}

leResult _leWidget_RemoveChild(leWidget* _this,
                               leWidget* child)
{
    LE_ASSERT_THIS();
    
    if(child == NULL || child->parent != _this)
    {
        return LE_FAILURE;
    }
        
    leArray_Remove(&_this->children, child);
    child->parent = NULL;
        
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

void _leWidget_RemoveAllChildren(leWidget* _this)
{
    leWidget* child;
    uint32_t i;
    
    LE_ASSERT_THIS();
    
    for(i = 0; i < _this->children.size; i++)
    {
        child = _this->children.values[i];
        
        if (child != NULL && child->children.size > 0)
        {
            child->fn->removeAllChildren(child);
        }
    }
    
    leArray_Clear(&_this->children);
}

leWidget* _leWidget_GetRootWidget(const leWidget* _this)
{
    leWidget* parent;
    
    LE_ASSERT_THIS();
    
    if(_this->parent == NULL)
        return NULL;
    
    parent = _this->parent;
    
    while(parent->parent != NULL)
    {
        parent = parent->parent;
    }
    
    return parent;
}

leResult _leWidget_SetParent(leWidget* _this,
                             leWidget* parent)
{
    LE_ASSERT_THIS();
    
    if(parent == NULL)
        return LE_FAILURE;
        
    if(_this->parent != NULL)
    {
        _this->parent->fn->removeChild(_this->parent, _this);
    }
    
    if(parent == NULL)
        return LE_SUCCESS;
        
    return parent->fn->addChild(parent, _this);
}

uint32_t _leWidget_GetChildCount(const leWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->children.size;
}

leWidget* _leWidget_GetChildAtIndex(const leWidget* _this,
                                    uint32_t idx)
{
    LE_ASSERT_THIS();
    
    if(_this == NULL || idx >= _this->children.size)
        return NULL;
        
    return _this->children.values[idx];
}

uint32_t _leWidget_GetIndexOfChild(const leWidget* _this,
                                   const leWidget* child)
{
    LE_ASSERT_THIS();
    
    if(_this == NULL || child == NULL)
        return -1;
        
    return leArray_Find((void*)&_this->children, (void*)child);
}

leBool _leWidget_ContainsDescendent(const leWidget* _this,
                                    const leWidget* wgt)
{
    uint32_t idx;
    leWidget* child;
    
    LE_ASSERT_THIS();
    
    for(idx = 0; idx < _this->children.size; idx++)
    {
        child = _this->children.values[idx];
        
        if(child == wgt)
        {
            return LE_TRUE;
        }
        else
        {
            if(child->fn->containsDescendent(child, wgt) == LE_TRUE)
            {
                return LE_TRUE;
            }
        }    
    }
    
    return LE_FALSE;
}

leScheme* _leWidget_GetScheme(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leScheme*)_this->scheme;
}

leResult _leWidget_SetScheme(leWidget* _this,
                             leScheme* scheme)
{
    LE_ASSERT_THIS();
    
    if(_this->scheme == scheme)
        return LE_SUCCESS;

    if(scheme == NULL)
    {
        _this->scheme = leGetDefaultScheme();
    }
    else
    {
        _this->scheme = scheme;
    }
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

leBorderType _leWidget_GetBorderType(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->borderType;
}

leResult _leWidget_SetBorderType(leWidget* _this,
                                 leBorderType type)
{
    LE_ASSERT_THIS();
    
    if(_this->borderType == type)
        return LE_SUCCESS;
        
    _this->borderType = type;
    
	_this->fn->_invalidateBorderAreas(_this);
    
    return LE_SUCCESS;
}

leBackgroundType _leWidget_GetBackgroundType(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->backgroundType;
}

leResult _leWidget_SetBackgroundType(leWidget* _this,
                                     leBackgroundType type)
{
    LE_ASSERT_THIS();
    if(_this->backgroundType == type)
        return LE_SUCCESS;
        
    _this->backgroundType = type;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

uint32_t _leWidget_GetOptimizationFlags(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->optimizationFlags;
}

leResult _leWidget_SetOptimizationFlags(leWidget* _this,
                                        uint32_t val)
{
    LE_ASSERT_THIS();
    
    _this->optimizationFlags = val;
    
    return LE_SUCCESS;
}

leHAlignment _leWidget_GetHAlignment(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->halign;
}

leResult _leWidget_SetHAlignment(leWidget* _this,
                                 leHAlignment align)
{
    LE_ASSERT_THIS();
    
    if(_this->halign == align)
        return LE_SUCCESS;

    _this->fn->invalidateContents(_this);

    _this->halign = align;

    _this->fn->invalidateContents(_this);
    
    return LE_SUCCESS;
}

leVAlignment _leWidget_GetVAlignment(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->valign;
}

leResult _leWidget_SetVAlignment(leWidget* _this,
                                 leVAlignment align)
{
    LE_ASSERT_THIS();
    
    if(_this->valign == align)
        return LE_SUCCESS;

    _this->fn->invalidateContents(_this);

    _this->valign = align;

    _this->fn->invalidateContents(_this);
    
    return LE_SUCCESS;
}

leMargin _leWidget_GetMargins(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->margin;
}

leResult _leWidget_SetMargins(leWidget* _this,
                              uint32_t l,
                              uint32_t t,
                              uint32_t r,
                              uint32_t b)
{   
    LE_ASSERT_THIS();
         
    if(_this->margin.left == l &&
       _this->margin.top == t &&
       _this->margin.right == r &&
       _this->margin.bottom == b)
    {
       return LE_FAILURE;
    }
        
    _this->margin.left = l;
    _this->margin.top = t;
    _this->margin.right = r;
    _this->margin.bottom = b;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

uint32_t _leWidget_GetCornerRadius(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->cornerRadius;
}

leResult _leWidget_SetCornerRadius(leWidget* _this,
                                   uint32_t radius)
{
    LE_ASSERT_THIS();
    
    if (_this->borderType != LE_WIDGET_BORDER_NONE &&
        _this->borderType != LE_WIDGET_BORDER_LINE)
        return LE_FAILURE;
        
    if(_this->cornerRadius == radius)
       return LE_FAILURE;
        
    _this->cornerRadius = radius;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

leBool _leWidget_HasFocus(const leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return leGetState()->focus == _this;
}

leResult _leWidget_SetFocus(leWidget* _this)
{
    LE_ASSERT_THIS();
    
    return leSetFocusWidget(_this);
}

/*leResult leWidget_SetExternalInputHandler(leWidget* _this, leWidgetInputHandler* hndlr)
{
    LE_ASSERT_THIS();
    
    if(hndlr == NULL)
    {
        _this->externalHandler.touchDown = NULL;
        _this->externalHandler.touchUp = NULL;
        _this->externalHandler.touchMoved = NULL;
    }
    else
    {
        _this->externalHandler = *hndlr;
    }
        
    return LE_SUCCESS;
}*/

void _leWidget_Invalidate(const leWidget* _this)
{
    leRect area;
    
    LE_ASSERT_THIS();
    
    // invalidate entire area
    area = _this->fn->rectToScreen(_this);
    
    _this->fn->_damageArea(_this, &area);
}

#if 0
void _leWidget_InvalidateRect(const leWidget* _this,
                              const leRect* rect)
{
    uint32_t i;
    leRect widgetRect;
    leWidget* parent;
    leWidget* child;

    // if widget is completely outside of parent's bounds
    // then nothing needs to be done
    if(leUtils_ChildIntersectsParent(_this->parent, _this) == LE_FALSE)
    {
        // mark this widget and all children as clean
        //_leWidget_ValidateChildren(_this);
        
        return;
    }
    
    widgetRect = _this->fn->rectToScreen(_this);
    
    if(leRectIntersects(&widgetRect, rect) == LE_FALSE)
        return;
        
    if(leUtils_WidgetIsOccluded(_this, rect) == LE_FALSE)
    {
        _this->fn->_increaseDirtyState(_this, LE_WIDGET_DIRTY_STATE_DIRTY);
        
        parent = _this->parent;
        
        if(parent != NULL)
        {
            if(parent->dirtyState != LE_WIDGET_DIRTY_STATE_CHILD)
            {
                parent = _this->parent;
                
                while(parent != NULL)
                {
                    parent->fn->_increaseDirtyState(parent, LE_WIDGET_DIRTY_STATE_CHILD);
                    
                    parent = parent->parent;
                }
            }
        }
    }
    
    // attempt to invalidate children
    for(i = 0; i < _this->children.size; i++)
    {
        child = _this->children.values[i];
        
        child->fn->invalidateRect(child, rect);
    }
}
#endif

void _leWidget_InvalidateContents(const leWidget* _this)
{ }

static leResult _leWidget_InstallEventFilter(leWidget* _this,
                                             leWidgetEventFilter fltr)
{
    uint32_t i;
    
    LE_ASSERT_THIS();

    if(fltr.filterEvent == NULL)
        return LE_FAILURE;

    for(i = 0; i < LE_WIDGET_MAX_EVENT_FILTERS; i++)
    {
        if(_this->eventFilters[i].filterEvent == NULL)
        {
            _this->eventFilters[i] = fltr;
            
            return LE_SUCCESS;
        }
    }
    
    return LE_FAILURE;
}

static leResult _leWidget_RemoveEventFilter(leWidget* _this,
                                            leWidgetEventFilter fltr)
{
    uint32_t i;
    
    LE_ASSERT_THIS();

    if(fltr.filterEvent == NULL)
        return LE_FAILURE;

    for(i = 0; i < LE_WIDGET_MAX_EVENT_FILTERS; i++)
    {
        if(_this->eventFilters[i].filterEvent == fltr.filterEvent)
        {
            _this->eventFilters[i].filterEvent = NULL;
            _this->eventFilters[i].data = NULL;
            
            return LE_SUCCESS;
        }
    }
    
    return LE_FAILURE;
}

void _leWidget_TouchDownEvent(leWidget* _this,
                              leWidgetEvent_TouchDown* evt)
{ }

void _leWidget_TouchUpEvent(leWidget* _this,
                            leWidgetEvent_TouchUp* evt)
{ }

void _leWidget_TouchMoveEvent(leWidget* _this,
                              leWidgetEvent_TouchMove* evt)
{ }

void _leWidget_MoveEvent(leWidget* _this,
                         leWidget_MoveEvent* evt)
{ }

void _leWidget_ResizeEvent(leWidget* _this,
                           leWidget_ResizeEvent* evt)
{ }

void _leWidget_FocusLostEvent(leWidget* _this)
{ }

void _leWidget_FocusGainedEvent(leWidget* _this)
{ }

void _leWidget_LanguageChangeEvent(leWidget* _this)
{ }

static leBool filterEvent(leWidget* _this,
                          leWidgetEvent* evt)
{
    uint32_t i;

    for(i = 0; i < LE_WIDGET_MAX_EVENT_FILTERS; i++)
    {
        if(_this->eventFilters[i].filterEvent != NULL &&
            _this->eventFilters[i].filterEvent(_this, evt, _this->eventFilters[i].data) == LE_TRUE)
        {
            return LE_TRUE;
        }
    }

    return LE_FALSE;
}

void _leWidget_HandleEvent(leWidget* _this,
                           leEvent* evt)
{
    LE_ASSERT_THIS();
    
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->touchDownEvent(_this, (leWidgetEvent_TouchDown*)evt);

            break;
        }
        case LE_EVENT_TOUCH_UP:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->touchUpEvent(_this, (leWidgetEvent_TouchUp*)evt);
        
            break;
        }
        case LE_EVENT_TOUCH_MOVE:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->touchMoveEvent(_this, (leWidgetEvent_TouchMove*)evt);
        
            break;
        }
        case LE_WIDGET_EVENT_PAINT:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->_paint(_this);
            
            break;
        }
        case LE_WIDGET_EVENT_MOVED:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->moveEvent(_this, (leWidget_MoveEvent*)evt);
            
            break;
        }
        case LE_WIDGET_EVENT_RESIZED:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->resizeEvent(_this, (leWidget_ResizeEvent*)evt);
            
            break;
        }
        case LE_WIDGET_EVENT_FOCUS_GAINED:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->focusGainedEvent(_this);
            
            break;
        }
        case LE_WIDGET_EVENT_FOCUS_LOST:
        {
            if(filterEvent(_this, (leWidgetEvent*)evt) == LE_TRUE)
                return;

            _this->fn->focusLostEvent(_this);
            
            break;
        }
        default:
        {
            break;
        }
    }   
}

static void _leWidget_ValidateChildren(leWidget* _this)
{
    uint32_t i;
    leWidget* child;
    
    LE_ASSERT_THIS();

    _this->fn->_clearDirtyState(_this);
    
    _this->drawState = LE_WIDGET_DRAW_STATE_READY;

    for(i = 0; i < _this->children.size; i++)
    {
        child = _this->children.values[i];

        child->fn->_validateChildren(child);
    }
}

static void _leWidget_IncreaseDirtyState(leWidget* _this, uint32_t state)
{
    LE_ASSERT_THIS();
    
    if(state > _this->dirtyState)
    {
        _this->dirtyState = state;
    }
}

static void _leWidget_SetDirtyState(leWidget* _this, uint32_t state)
{
    LE_ASSERT_THIS();
    
    _this->dirtyState = state;
}

static void _leWidget_ClearDirtyState(leWidget* _this)
{
    LE_ASSERT_THIS();
    
    _this->dirtyState = LE_WIDGET_DIRTY_STATE_CLEAN;
}


void _leWidget_InvalidateBorderAreas(const leWidget* _this)
{ }

static void _leWidget_DamageArea(const leWidget* _this, leRect* rect)
{
    LE_ASSERT_THIS();
    
    if(leWidgetIsInScene(_this) == LE_TRUE)
    {
        leRenderer_DamageArea(rect);
    }
}

void _leWidget_Paint(leWidget* _this);

void _leWidget_Update(leWidget* _this, uint32_t dt)
{
}

void _leWidget_GenerateVTable()
{
    widgetVTable.getType = getType;
    widgetVTable.getX = _leWidget_GetX;
    widgetVTable.setX = _leWidget_SetX;
    widgetVTable.getY = _leWidget_GetY;
    widgetVTable.setY = _leWidget_SetY;
    widgetVTable.setPosition = _leWidget_SetPosition;
    widgetVTable.translate = _leWidget_Translate;
    widgetVTable.getWidth = _leWidget_GetWidth;
    widgetVTable.setWidth = _leWidget_SetWidth;
    widgetVTable.getHeight = _leWidget_GetHeight;
    widgetVTable.setHeight = _leWidget_SetHeight;
    widgetVTable.setSize = _leWidget_SetSize;
    widgetVTable.resize = _leWidget_Resize;
    widgetVTable.getAlphaEnabled = _leWidget_GetAlphaEnabled;
    widgetVTable.getCumulativeAlphaEnabled = _leWidget_GetCumulativeAlphaEnabled;
    widgetVTable.setAlphaEnabled = _leWidget_SetAlphaEnabled;
    widgetVTable.getAlphaAmount = _leWidget_GetAlphaAmount;
    widgetVTable.getCumulativeAlphaAmount = _leWidget_GetCumulativeAlphaAmount;
    widgetVTable.setAlphaAmount = _leWidget_SetAlphaAmount;
    widgetVTable.isOpaque = _leWidget_IsOpaque;
    widgetVTable.getEnabled = _leWidget_GetEnabled;
    widgetVTable.setEnabled = _leWidget_SetEnabled;
    widgetVTable.getVisible = _leWidget_GetVisible;
    widgetVTable.setVisible = _leWidget_SetVisible;
    widgetVTable.localRect = _leWidget_LocalRect;
    widgetVTable.rectToParent = _leWidget_RectToParentSpace;
    widgetVTable.rectToScreen = _leWidget_RectToScreenSpace;
    widgetVTable.addChild = _leWidget_AddChild;
    widgetVTable.removeChild = _leWidget_RemoveChild;
    widgetVTable.removeAllChildren = _leWidget_RemoveAllChildren;
    widgetVTable.getRootWidget = _leWidget_GetRootWidget;
    widgetVTable.setParent = _leWidget_SetParent;
    widgetVTable.getChildCount = _leWidget_GetChildCount;
    widgetVTable.getChildAtIndex = _leWidget_GetChildAtIndex;
    widgetVTable.getIndexOfChild = _leWidget_GetIndexOfChild;
    widgetVTable.containsDescendent = _leWidget_ContainsDescendent;
    widgetVTable.getScheme = _leWidget_GetScheme;
    widgetVTable.setScheme = _leWidget_SetScheme;
    widgetVTable.getBorderType = _leWidget_GetBorderType;
    widgetVTable.setBorderType = _leWidget_SetBorderType;
    widgetVTable.getBackgroundType = _leWidget_GetBackgroundType;
    widgetVTable.setBackgroundType = _leWidget_SetBackgroundType;
    /*widgetVTable.getOptimizationFlags = _leWidget_GetOptimizationFlags;
    widgetVTable.setOptimizationFlags = _leWidget_SetOptimizationFlags;*/
    widgetVTable.getHAlignment = _leWidget_GetHAlignment;
    widgetVTable.setHAlignment = _leWidget_SetHAlignment;
    widgetVTable.getVAlignment = _leWidget_GetVAlignment;
    widgetVTable.setVAlignment = _leWidget_SetVAlignment;
    widgetVTable.getMargins = _leWidget_GetMargins;
    widgetVTable.setMargins = _leWidget_SetMargins;
    widgetVTable.getCornerRadius = _leWidget_GetCornerRadius;
    widgetVTable.setCornerRadius = _leWidget_SetCornerRadius;
    widgetVTable.hasFocus = _leWidget_HasFocus;
    widgetVTable.setFocus = _leWidget_SetFocus;
    widgetVTable.invalidate = _leWidget_Invalidate;
    widgetVTable.invalidateContents = _leWidget_InvalidateContents;
    widgetVTable.installEventFilter = _leWidget_InstallEventFilter;
    widgetVTable.removeEventFilter = _leWidget_RemoveEventFilter;
    
    widgetVTable.update = _leWidget_Update;
    
    widgetVTable.touchDownEvent = _leWidget_TouchDownEvent;
    widgetVTable.touchUpEvent = _leWidget_TouchUpEvent;
    widgetVTable.touchMoveEvent = _leWidget_TouchMoveEvent;
    widgetVTable.moveEvent = _leWidget_MoveEvent;
    widgetVTable.resizeEvent = _leWidget_ResizeEvent;
    widgetVTable.focusLostEvent = _leWidget_FocusLostEvent;
    widgetVTable.focusGainedEvent = _leWidget_FocusGainedEvent;
    widgetVTable.languageChangeEvent = _leWidget_LanguageChangeEvent;
    
    widgetVTable._destructor = _leWidget_Destructor;
    widgetVTable._handleEvent = _leWidget_HandleEvent;
    widgetVTable._validateChildren = _leWidget_ValidateChildren;
    widgetVTable._increaseDirtyState = _leWidget_IncreaseDirtyState;
    widgetVTable._setDirtyState = _leWidget_SetDirtyState;
    widgetVTable._clearDirtyState = _leWidget_ClearDirtyState;
    widgetVTable._invalidateBorderAreas = _leWidget_InvalidateBorderAreas;
    widgetVTable._damageArea = _leWidget_DamageArea;
    
    widgetVTable._paint = _leWidget_Paint;
}

void _leWidget_FillVTable(leWidgetVTable* tbl)
{
    *tbl = widgetVTable;
}