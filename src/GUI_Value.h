#ifndef _GUI_VALUE_H_
#define _GUI_VALUE_H_

#include "Arduino.h"
#include "TFT_Gui.h"

class GUI_Value : public GUI_Base
{

public:
    GUI_Value();

    GUI_Value(GUI_Viewport viewport, uint32_t text_color, const GFXfont *font, int datum, int decimals, int value);

    void updateValue(int value);
    void updateValue(float value);
    void updateValue(float value, int decimals);
    String getPrintValue();

    int getValue() { return _value; }

    void drawSelf();

private:
    uint32_t _background_color;
    uint32_t _text_color;
    const GFXfont *_font;
    int _datum = 0;
    int _value = 0;
    int _decimals = 0;
};

#endif // _GUI_VALUE_H_