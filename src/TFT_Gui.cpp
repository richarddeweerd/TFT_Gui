#include "TFT_Gui.h"

GUI_Base::GUI_Base()
{
    this->viewport = GUI_Viewport();
}

GUI_Base::GUI_Base(GUI_Viewport viewport)
{
    this->viewport = viewport;
}

GUI_Viewport GUI_Base::getAbsoluteViewport()
{
    if (this->_parent == nullptr)
    {
        return viewport;
    }
    return this->viewport.getAbsoluteViewport(this->_parent->getAbsoluteViewport());
}

void GUI_Base::addSibling(GUI_Base *sibling)
{
    GUI_Base *current = this;
    while (current->_sibling != nullptr)
    {
        current = current->_sibling;
    }
    current->_sibling = sibling;
}

TFT_eSPI *GUI_Base::getTFT()
{
    if (_parent == nullptr)
    {
        return _tft;
    }
    return _parent->getTFT();
}

void GUI_Base::draw()
{
    if (_visible)
    {
        // only draw the object and its childs if it is visible
        drawSelf();
        if (this->_child != nullptr)
        {
            // Object has child object(s) draw them first
            _child->draw();
        }
    }
    if (this->_sibling != nullptr)
    {
        // Object has sibbeling object(s) draw them now
        _sibling->draw();
    }
}

void GUI_Base::drawSelf()
{
}

GUI_Container::GUI_Container() : GUI_Base()

{
    _background_color = TFT_BLACK;
    itemType = CONTAINER;
}

GUI_Container::GUI_Container(uint32_t background_color) : GUI_Base()
{
    _background_color = background_color;
    itemType = CONTAINER;
}

GUI_Container::GUI_Container(GUI_Viewport viewport, uint32_t background_color) : GUI_Base(viewport)
{
    _background_color = background_color;
    itemType = CONTAINER;
}

void GUI_Container::addChild(GUI_Base *child)
{
    if (child->_parent != nullptr)
    {
        // child is already a child of another object
        return;
    }
    child->_parent = this;
    child->setObjectIndex(_child_count);
    _child_count++;

    if (this->_child == nullptr)
    {
        // first child
        this->_child = child;
        return;
    }
    _child->addSibling(child);
}

void GUI_Container::drawSelf()
{
}
