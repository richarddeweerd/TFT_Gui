#include "GUI_Screen.h"
GUI_Screen::GUI_Screen(TFT_eSPI *tft) : GUI_Container()
{
    this->_tft = tft;
    itemType = SCREEN;
}

void GUI_Screen::init()
{
    viewport = GUI_Viewport(0, 0, _tft->width(), _tft->height());
}

void GUI_Screen::setActivePage(int page)
{
    if (page >= getChildCount())
    {
        return;
    }
    _selectedPage = page;
    if (this->_child == nullptr)
    {
        return;
    }
    GUI_Base *current = this->_child;
    while (current != nullptr)
    {
        if (current->getObjectIndex() == _selectedPage)
        {
            current->setVisible(true);
        }
        else
        {
            current->setVisible(false);
        }
        current = current->_sibling;
    }
    draw();
}

void GUI_Screen::drawSelf()
{
}

void GUI_Screen::addPage(GUI_Base *page)
{

    if (page->itemType != GUI_itemType::PAGE)
    {
        return;
    }

    this->addChild(page);
    if (getChildCount() == 1)
    {
        setActivePage(0);
    }
}
