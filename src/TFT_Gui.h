#ifndef _TFT_GUI_H_
#define _TFT_GUI_H_

#include "Arduino.h"
#include "TFT_eSPI.h"

class GUI_Viewport
{
public:
    GUI_Viewport();
    GUI_Viewport(int x, int y, int w, int h);
    int x;
    int y;
    int w;
    int h;
};

class GUI_Base
{
public:
    GUI_Base();
    GUI_Base(TFT_eSPI *tft, GUI_Viewport viewport);

    void draw();
    // void setBlock(byte block, byte status);
    void setVisible(bool val);
    bool getVisible() { return _visible; }

    // virtual void init();
    GUI_Base *_parentItem = nullptr;
    GUI_Base *_nextItem = nullptr;
    GUI_Base *_firstItem = nullptr;

    TFT_eSPI *_tft = nullptr;

    // virtual void drawSelf();

private:
    bool _visible = true;
};

class GUI_Container : public GUI_Base
{
public:
    GUI_Container(TFT_eSPI *tft, GUI_Viewport viewport, uint32_t backgroundColor);

    void addChild(GUI_Base *child);
    void setBackgroundColor(uint32_t color);

private:
protected:
    uint32_t _background_col;
};

#include "GUI_Screen.h"
#include "GUI_Form.h"

#endif // _TFT_GUI_H_
