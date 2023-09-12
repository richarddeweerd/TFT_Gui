#ifndef _GUI_SCREEN_H_
#define _GUI_SCREEN_H_

#include "Arduino.h"
#include "TFT_Gui.h"
#include "GUI_Form.h"

class GUI_Screen : public GUI_Container
{
public:
    GUI_Screen(TFT_eSPI *tft);
    void init();

    void addPage(GUI_Base *page);

    int getActivePage() { return _selectedPage; }
    void setActivePage(int page);

    void drawSelf();

private:
protected:
    int _selectedPage = -1;
};

#endif