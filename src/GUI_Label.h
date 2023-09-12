#ifndef _GUI_LABEL_H_
#define _GUI_LABEL_H_

#include "Arduino.h"
#include "TFT_Gui.h"

class GUI_Label : public GUI_Base
{

public:
    GUI_Label();

    GUI_Label(GUI_Viewport viewport, uint32_t text_color, const GFXfont *font, int datum, String text);

    void drawSelf();

private:
    uint32_t _background_color;
    uint32_t _text_color;
    const GFXfont *_font;
    String _text;
    int _datum = 0;
};

#endif // _GUI_LABEL_H_