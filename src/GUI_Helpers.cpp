#include "GUI_Helpers.h"

int get_abs_pos(int parent_pos, int parent_size, int child_pos)
{
    if (child_pos > parent_size)
        return parent_pos + parent_size;
    return parent_pos + child_pos;
}

int get_abs_size(int parent_size, int child_pos, int child_size)
{
    if (child_size < 0)
        return parent_size - child_pos;

    if (child_size + child_pos > parent_size)
        return parent_size - child_pos;
    return child_size;
}

GUI_Position::GUI_Position()
{
    x = 0;
    y = 0;
}

GUI_Position::GUI_Position(int x, int y)
{
    this->x = 0;
    this->y = 0;
    if (x > 0)
        this->x = x;
    if (y > 0)
        this->y = y;
}

GUI_Size::GUI_Size()
{
    w = -1;
    h = -1;
}

GUI_Size::GUI_Size(int w, int h)
{
    this->w = w;
    this->h = h;
}

GUI_Viewport::GUI_Viewport()
{
    init(0, 0, -1, -1);
}

GUI_Viewport::GUI_Viewport(int x, int y, int w, int h)
{
    init(x, y, w, h);
}

void GUI_Viewport::init(int x, int y, int w, int h)
{
    this->position = GUI_Position(x, y);
    this->size = GUI_Size(w, h);
}

GUI_Viewport GUI_Viewport::getAbsoluteViewport(GUI_Viewport parent_viewport)
{
    GUI_Viewport abs_viewport;
    abs_viewport.position.x = get_abs_pos(parent_viewport.position.x, parent_viewport.size.w, this->position.x);
    abs_viewport.position.y = get_abs_pos(parent_viewport.position.y, parent_viewport.size.h, this->position.y);
    abs_viewport.size.w = get_abs_size(parent_viewport.size.w, this->position.x, this->size.w);
    abs_viewport.size.h = get_abs_size(parent_viewport.size.h, this->position.y, this->size.h);
    return abs_viewport;
}

int get_text_x(GUI_Viewport viewport, int datum)
{
    if ((datum == TC_DATUM) || (datum == CC_DATUM) || (datum == BC_DATUM))
    {
        return viewport.position.x + (viewport.size.w / 2);
    }

    if ((datum == TR_DATUM) || (datum == CR_DATUM) || (datum == BR_DATUM))
    {
        return viewport.position.x + viewport.size.w;
    }
    return viewport.position.x;
}

int get_text_y(GUI_Viewport viewport, int datum)
{
    if ((datum == CL_DATUM) || (datum == CC_DATUM) || (datum == CR_DATUM))
    {
        return viewport.position.y + (viewport.size.h / 2);
    }
    if ((datum == BL_DATUM) || (datum == BC_DATUM) || (datum == BR_DATUM))
    {
        return viewport.position.y + viewport.size.h;
    }
    return viewport.position.y;
}

GUI_Position get_text_pos(GUI_Viewport viewport, int datum)
{
    return GUI_Position(get_text_x(viewport, datum), get_text_y(viewport, datum));
}