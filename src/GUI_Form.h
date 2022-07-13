#ifndef _GUI_FORM_H_
#define _GUI_FORM_H_

#include "Arduino.h"
#include "TFT_Gui.h"

class GUI_Form : public GUI_Container
{
public:
    GUI_Form(TFT_eSPI *tft, uint32_t color);
    GUI_Form(TFT_eSPI *tft, GUI_Viewport viewport, uint32_t color);
    void drawSelf();

private:
};
#endif