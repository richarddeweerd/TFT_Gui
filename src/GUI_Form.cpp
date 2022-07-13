#include "GUI_Form.h"

GUI_Form::GUI_Form(TFT_eSPI *tft, uint32_t color) : GUI_Container(tft, GUI_Viewport(), color)
{
}

GUI_Form::GUI_Form(TFT_eSPI *tft, GUI_Viewport viewport, uint32_t color) : GUI_Container(tft, viewport, color)
{
}

void GUI_Form::drawSelf()
{
    // _tft->fillRect(frame.getPosAbs().x, frame.getPosAbs().y, frame.getSizeAbs().w, frame.getSizeAbs().h, _background_col);
}
