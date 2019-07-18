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

#include "gfx/legato/widget/keypad/legato_widget_keypad.h"

#if LE_KEYPAD_WIDGET_ENABLED && LE_BUTTON_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/button/legato_widget_button.h"

#define DEFAULT_WIDTH           200
#define DEFAULT_HEIGHT          200

static leKeyPadWidgetVTable keyPadWidgetVTable;

static void resizeCells(leKeyPadWidget* _this,
                        leWidget_ResizeEvent* evt)
{
    uint32_t width, height, wrem, hrem, row, col, wmod, hmod;
    int32_t x, y;
    leButtonWidget* btn;
    
    if(_this->widget.children.size == 0)
        return;
    
    x = 0;
    y = 0;
    width = _this->widget.rect.width / _this->cols;
    height = _this->widget.rect.height / _this->rows;
    
    wrem = _this->widget.rect.width - (width * _this->cols);
    hrem = _this->widget.rect.height - (height * _this->rows);
    
    hmod = 0;
    wmod = 0;
    
    // resize and position all button cells
    for(row = 0; row < _this->rows; row++)
    {
        hmod = row < hrem ? 1 : 0;
           
        for(col = 0; col < _this->cols; col++)
        {
            btn = (leButtonWidget*)_this->fn->getChildAtIndex(_this, (row * _this->cols) + col);
                          
            if(btn == NULL)
                return;
                                                            
            btn->fn->setPosition(btn, x, y);
            
            wmod = col < wrem ? 1 : 0;
            
            btn->fn->setSize(btn, width + wmod, height + hmod);
            
            x += width + wmod;
        }
        
        x = 0;
        
        y += height + hmod;
    }
}

static void buttonClicked(leButtonWidget* btn)
{
    int32_t id, row, col;
    leKeyPadWidget* _this = (leKeyPadWidget*)btn->widget.parent;
    
    LE_ASSERT_THIS();
    
    if ((btn->fn->getPressed(btn) == LE_TRUE && _this->trigger == LE_KEYPAD_TRIGGER_KEYRELEASED) ||
        (btn->fn->getPressed(btn) == LE_FALSE && _this->trigger == LE_KEYPAD_TRIGGER_KEYPRESSED))
        return;
        
    id = _this->fn->getIndexOfChild(_this, (leWidget*)btn);
    
    row = id / _this->cols;
    col = id % _this->cols; 
    
    if(_this->clickEvt != NULL)
    {
        _this->clickEvt(_this, btn, row, col);
    }
    
    //printf("%i, %i\n", row, col);
    
    if(_this->cells[id].action == LE_KEYPAD_CELL_ACTION_APPEND)
    {
        _leEditWidget_Append(_this->cells[id].value);
    }
    else if(_this->cells[id].action == LE_KEYPAD_CELL_ACTION_SET)
    {
        _leEditWidget_Set(_this->cells[id].value);
    }
    else if(_this->cells[id].action == LE_KEYPAD_CELL_ACTION_BACKSPACE)
    {
        _leEditWidget_Backspace();
    }
    else if(_this->cells[id].action == LE_KEYPAD_CELL_ACTION_CLEAR)
    {
        _leEditWidget_Clear();
    }
    else if(_this->cells[id].action == LE_KEYPAD_CELL_ACTION_ACCEPT)
    {
        _leEditWidget_Accept();
    }
}

/*static void languageChanging(leKeyPadWidget* _this)
{
    uint32_t i;
    
    for(i = 0; i < _this->rows * _this->cols; i++)
    {
        if(_this->cells[i].button->text != NULL)
        {
            leWidget_Invalidate((leWidget*)_this);
            
            return;
        }
    }
}*/

void leKeyPadWidget_Constructor(leKeyPadWidget* _this,
                                uint32_t rows,
                                uint32_t cols)
{
    leButtonWidget* button;
    uint32_t i;
    
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&keyPadWidgetVTable;
    _this->fn = &keyPadWidgetVTable;
    
    _this->widget.type = LE_WIDGET_KEYPAD;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_BEVEL;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;
    
    _this->rows = rows;
    _this->cols = cols;
    
    _this->trigger = LE_KEYPAD_TRIGGER_KEYRELEASED;
    
    _this->cells = LE_MALLOC(rows * cols * sizeof(leKeyPadCell));
    
    for(i = 0; i < rows * cols; i++)
    {
        // create button
        button = leButtonWidget_New();
        
        LE_ASSERT_VAR(button != NULL, "%s: Failed to allocate memory for button cell!\n", __FUNCTION__); 
        
        if(button == NULL)
            return;
            
        button->fn->setPressedEventCallback(button, (leButtonWidget_PressedEvent)buttonClicked);
        button->fn->setReleasedEventCallback(button, (leButtonWidget_ReleasedEvent)buttonClicked);        
        
        _this->fn->addChild(_this, (leWidget*)button);
    }
    
    resizeCells(_this, NULL);
}

void _leWidget_Destructor(leWidget* _this);

static void destructor(leKeyPadWidget* _this)
{
    LE_FREE(_this->cells);
    
    _leWidget_Destructor((leWidget*)_this);
}

leKeyPadWidget* leKeyPadWidget_New(uint32_t rows, uint32_t cols)
{
    leKeyPadWidget* pad = NULL;

    pad = LE_MALLOC(sizeof(leKeyPadWidget));
    
    leKeyPadWidget_Constructor(pad, rows, cols);

    return pad;
}

static leKeyPadActionTrigger getKeyPadActionTrigger(const leKeyPadWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->trigger;
}

static leResult setKeyPadActionTrigger(leKeyPadWidget* _this,
                                       leKeyPadActionTrigger trigger)
{
    LE_ASSERT_THIS();

    _this->trigger = trigger;
    
    return LE_SUCCESS;
}

static leKeyPadWidget_KeyClickEvent getKeyClickEventCallback(const leKeyPadWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->clickEvt;
}

static leResult setKeyClickEventCallback(leKeyPadWidget* _this,
                                         leKeyPadWidget_KeyClickEvent cb)
{
    LE_ASSERT_THIS();
    
    _this->clickEvt = cb;
    
    return LE_SUCCESS;
}

static leResult setKeyEnabled(leKeyPadWidget* _this,
                              uint32_t row,
                              uint32_t col,
                              leBool enabled)
{
    leButtonWidget* btn;
    
    LE_ASSERT_THIS();
    
    if(row * _this->cols + col > _this->rows * _this->cols)
        return LE_FAILURE;
        
    btn = _this->fn->getCellButton(_this, row, col);
        
    return btn->fn->setVisible(btn, enabled);
}

static leKeyPadCellAction getKeyAction(const leKeyPadWidget* _this,
                                       uint32_t row,
                                       uint32_t col)
{
    LE_ASSERT_THIS();
    
    if(row * _this->cols + col > _this->rows * _this->cols)
        return 0;
    
    return _this->cells[row * _this->cols + col].action;
}
                                               
static leResult setKeyAction(leKeyPadWidget* _this,
                             uint32_t row,
                             uint32_t col,
                             leKeyPadCellAction action)
{
    LE_ASSERT_THIS();
    
    if(row * _this->cols + col > _this->rows * _this->cols)
        return LE_FAILURE;
        
    _this->cells[row * _this->cols + col].action = action;
        
    return LE_SUCCESS;
}

static leString* getKeyValue(const leKeyPadWidget* _this,
                             uint32_t row,
                             uint32_t col)
{
    if(row * _this->cols + col > _this->rows * _this->cols)
        return NULL;
    
    return (leString*)_this->cells[row * _this->cols + col].value;
}

static leResult setKeyValue(leKeyPadWidget* _this,
                            uint32_t row,
                            uint32_t col,
                            const leString* val)
{
    if(row * _this->cols + col > _this->rows * _this->cols)
        return LE_FAILURE;

    _this->cells[row * _this->cols + col].value = val;

    return LE_SUCCESS;
}
                                               
static leButtonWidget* getCellButton(const leKeyPadWidget* _this,
                                     uint32_t row,
                                     uint32_t col)
{
    leButtonWidget* btn;
    
    LE_ASSERT_THIS();
    
    if(row >= _this->rows || col >= _this->cols)
        return NULL;
       
    btn = (leButtonWidget*)_this->fn->getChildAtIndex(_this, (row * _this->cols) + col);
    
    return btn;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leKeyPadWidget_Paint(leKeyPadWidget* _this);

void _leKeyPadWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&keyPadWidgetVTable);
    
    /* overrides from base class */
    keyPadWidgetVTable._destructor = destructor;
    keyPadWidgetVTable.resizeEvent = resizeCells;
    keyPadWidgetVTable._paint = _leKeyPadWidget_Paint;
    
    /* member functions */
    keyPadWidgetVTable.getKeyPadActionTrigger = getKeyPadActionTrigger;
    keyPadWidgetVTable.setKeyPadActionTrigger = setKeyPadActionTrigger;
    keyPadWidgetVTable.getKeyClickEventCallback = getKeyClickEventCallback;
    keyPadWidgetVTable.setKeyClickEventCallback = setKeyClickEventCallback;
    keyPadWidgetVTable.setKeyEnabled = setKeyEnabled;
    keyPadWidgetVTable.getKeyAction = getKeyAction;
    keyPadWidgetVTable.setKeyAction = setKeyAction;
    keyPadWidgetVTable.getKeyValue = getKeyValue;
    keyPadWidgetVTable.setKeyValue = setKeyValue;
    keyPadWidgetVTable.getCellButton = getCellButton;
}

void _leKeyPadWidget_FillVTable(leKeyPadWidgetVTable* tbl)
{
    *tbl = keyPadWidgetVTable;
}
                                                    
#endif // LE_WIDGET_KEYPAD_ENABLED && LE_WIDGET_BUTTON_ENABLED