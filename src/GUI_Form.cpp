#include "GUI_Form.h"

GUI_Form::GUI_Form() : GUI_Container()
{
}

GUI_Form::GUI_Form(GUI_Viewport viewport, uint32_t background_color) : GUI_Container(viewport, background_color)
{
    _border_color = TFT_WHITE;
    _show_border = false;
}

GUI_Form::GUI_Form(GUI_Viewport viewport, uint32_t background_color, uint32_t border_color) : GUI_Container(viewport, background_color)
{
    _border_color = border_color;
    _show_border = true;
}

void GUI_Form::drawSelf()
{
    TFT_eSPI *tft = getTFT();
    GUI_Viewport absolute_viewport = this->getAbsoluteViewport();
    tft->fillRect(absolute_viewport.position.x, absolute_viewport.position.y, absolute_viewport.size.w, absolute_viewport.size.h, _background_color);
    if (_show_border)
    {
        tft->drawRect(absolute_viewport.position.x, absolute_viewport.position.y, absolute_viewport.size.w, absolute_viewport.size.h, _border_color);
    }
}
