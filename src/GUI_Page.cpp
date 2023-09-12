#include "GUI_Page.h"

GUI_Page::GUI_Page() : GUI_Container()
{
    itemType = PAGE;
}

GUI_Page::GUI_Page(uint32_t background_color) : GUI_Container(background_color)
{
    itemType = PAGE;
}

void GUI_Page::drawSelf()
{
    TFT_eSPI *tft = getTFT();
    GUI_Viewport absolute_viewport = this->getAbsoluteViewport();
    tft->fillRect(absolute_viewport.position.x, absolute_viewport.position.y, absolute_viewport.size.w, absolute_viewport.size.h, _background_color);
    // _tft->fillScreen(TFT_PURPLE);
}