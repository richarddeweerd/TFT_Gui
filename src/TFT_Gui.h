#ifndef _TFT_GUI_H_
#define _TFT_GUI_H_

#include "Arduino.h"

#include "TFT_eSPI.h"
#include "Free_Fonts.h"

#include "GUI_Helpers.h"

class GUI_Base
{
public:
    GUI_Base();
    GUI_Base(GUI_Viewport viewport);

    GUI_itemType itemType = BASE;

    GUI_Viewport viewport;
    GUI_Base *_parent = nullptr;
    GUI_Base *_sibling = nullptr;
    GUI_Base *_child = nullptr;
    TFT_eSPI *_tft = nullptr;

    TFT_eSPI *getTFT();

    void addSibling(GUI_Base *sibling);

    int getObjectIndex() { return this->_objectIndex; }
    void setObjectIndex(int index) { this->_objectIndex = index; }

    void draw();
    virtual void drawSelf();

    GUI_Viewport getAbsoluteViewport();

    void setVisible(bool val) { this->_visible = val; }
    bool getVisible() { return _visible; }

private:
    bool _visible = true;
    int _objectIndex = -1;
};

class GUI_Container : public GUI_Base
{
public:
    GUI_Container();
    GUI_Container(uint32_t background_color);
    GUI_Container(GUI_Viewport viewport, uint32_t background_color);

    // GUI_Container(TFT_eSPI *tft, GUI_Viewport viewport);
    // GUI_Container(TFT_eSPI *tft, GUI_Viewport viewport, uint32_t backgroundColor);

    void addChild(GUI_Base *child);

    void setBackgroundColor(uint32_t color) { _background_color = color; };
    uint32_t getBackgroundColor() { return _background_color; }

    uint32_t _background_color;
    void drawSelf();
    int getChildCount() { return _child_count; }

private:
    int _child_count = 0;
};

#include "GUI_Form.h"
#include "GUI_Screen.h"
#include "GUI_Page.h"

#include "GUI_Label.h"
#include "GUI_Value.h"

#endif // _TFT_GUI_H_
