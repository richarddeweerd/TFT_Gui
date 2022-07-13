#include "TFT_Gui.h"

GUI_Viewport::GUI_Viewport()
{
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

GUI_Viewport::GUI_Viewport(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

GUI_Base::GUI_Base()
{
}

GUI_Base::GUI_Base(TFT_eSPI *tft, GUI_Viewport viewport)
{
}

GUI_Container::GUI_Container(TFT_eSPI *tft, GUI_Viewport viewport, uint32_t backgroundColor)
{
}
