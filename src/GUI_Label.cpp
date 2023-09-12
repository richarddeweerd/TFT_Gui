#include "GUI_Label.h"

GUI_Label::GUI_Label()
{
}

GUI_Label::GUI_Label(GUI_Viewport viewport, uint32_t text_color, const GFXfont *font, int datum, String text) : GUI_Base(viewport)
{
    _text_color = text_color;
    _font = font;
    _text = text;
    _datum = datum;
}

void GUI_Label::drawSelf()
{
    TFT_eSPI *tft = getTFT();
    GUI_Viewport absolute_viewport = this->getAbsoluteViewport();
    int text_x = absolute_viewport.position.x;
    tft->fillRect(absolute_viewport.position.x, absolute_viewport.position.y, absolute_viewport.size.w, absolute_viewport.size.h, TFT_LIGHTGREY);
    tft->setTextDatum(_datum);

    // tft->setTextColor(_text_color, _background_color);
    tft->setTextColor(_text_color);
    tft->setFreeFont(_font);

    tft->drawString(_text, get_text_x(absolute_viewport, _datum), get_text_y(absolute_viewport, _datum), GFXFF);
}