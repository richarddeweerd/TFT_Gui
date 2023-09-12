#ifndef _GUI_PAGE_H_
#define _GUI_PAGE_H_

#include "Arduino.h"
#include "TFT_Gui.h"

class GUI_Page : public GUI_Container

{
public:
    GUI_Page();
    GUI_Page(uint32_t background_color);
    void drawSelf();

private:
};

#endif