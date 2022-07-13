#ifndef _GUI_SCREEN_H_
#define _GUI_SCREEN_H_

#include "Arduino.h"
#include "TFT_Gui.h"

class GUI_Screen : public GUI_Container
{
public:
    GUI_Screen(TFT_eSPI *tft);
    GUI_Screen(TFT_eSPI *tft, uint32_t backgroundColor);

    

    void drawSelf();

private:
};
#endif // _GUI_SCREEN_H_