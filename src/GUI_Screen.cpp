#include "GUI_Screen.h"

GUI_Screen::GUI_Screen(TFT_eSPI *tft) : GUI_Container(tft, GUI_Viewport(), 0) {}

GUI_Screen::GUI_Screen(TFT_eSPI *tft, uint32_t backgroundColor) : GUI_Container(tft, GUI_Viewport(), backgroundColor) {}

void GUI_Screen::drawSelf()
{
    _tft->fillScreen(_background_col);
}
