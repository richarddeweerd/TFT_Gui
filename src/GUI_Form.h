#ifndef _GUI_FORM_H_
#define _GUI_FORM_H_

#include "Arduino.h"
#include "TFT_Gui.h"

class GUI_Form : public GUI_Container
{
public:
    GUI_Form();
    GUI_Form(GUI_Viewport viewport, uint32_t background_color);
    GUI_Form(GUI_Viewport viewport, uint32_t background_color, uint32_t border_color);

    void setBorderColor(uint32_t border_color) { _border_color = border_color; };
    void setBorder(bool border) { _show_border = border; };
    void drawSelf();

private:
    uint32_t _border_color;
    bool _show_border = false;
};
#endif