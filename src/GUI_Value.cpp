#include "GUI_Value.h"

GUI_Value::GUI_Value()
{
}

GUI_Value::GUI_Value(GUI_Viewport viewport, uint32_t text_color, const GFXfont *font, int datum, int decimals, int value) : GUI_Base(viewport)
{
    _text_color = text_color;
    _font = font;
    _datum = datum;
    _decimals = decimals;
    _value = value;
}

void GUI_Value::updateValue(int value)
{
    _value = value;
}

void GUI_Value::updateValue(float value)
{
    float value_float = value * pow(10, _decimals);
    updateValue(int(value_float));
}

void GUI_Value::updateValue(float value, int decimals)
{
    _decimals = decimals;
    updateValue(value);
}

String GUI_Value::getPrintValue()
{
    if (_decimals == 0)
    {
        return String(_value);
    }
    else
    {
        float value_float = _value / pow(10, _decimals);
        return String(value_float, _decimals);
    }
}

void GUI_Value::drawSelf()
{
    TFT_eSPI *tft = getTFT();
    GUI_Viewport absolute_viewport = this->getAbsoluteViewport();
    int text_x = absolute_viewport.position.x;
    tft->fillRect(absolute_viewport.position.x, absolute_viewport.position.y, absolute_viewport.size.w, absolute_viewport.size.h, TFT_LIGHTGREY);
    tft->setTextDatum(_datum);

    // tft->setTextColor(_text_color, _background_color);
    tft->setTextColor(_text_color);
    tft->setFreeFont(_font);

    tft->drawString("", get_text_x(absolute_viewport, _datum), get_text_y(absolute_viewport, _datum), GFXFF);
}