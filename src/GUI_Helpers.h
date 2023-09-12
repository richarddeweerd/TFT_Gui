#ifndef _GUI_HELPERS_H_
#define _GUI_HELPERS_H_

#include "Arduino.h"
#include "TFT_eSPI.h"

int get_abs_pos(int parent_pos, int parent_size, int child_pos);
int get_abs_size(int parent_size, int child_pos, int child_size);

enum GUI_itemType
{
    BASE,
    CONTAINER,
    FORM,
    PAGE,
    SCREEN
};

class GUI_Position
{
public:
    GUI_Position();
    GUI_Position(int x, int y);
    int x;
    int y;
};

class GUI_Size
{
public:
    GUI_Size();
    GUI_Size(int w, int h);
    int w;
    int h;
};

class GUI_Viewport
{
public:
    GUI_Viewport();
    GUI_Viewport(int x, int y, int w, int h);
    void init(int x, int y, int w, int h);
    GUI_Viewport getAbsoluteViewport(GUI_Viewport parent_viewport);

    GUI_Position position;
    GUI_Size size;
};

int get_text_x(GUI_Viewport viewport, int datum);
int get_text_y(GUI_Viewport viewport, int datum);
GUI_Position get_text_pos(GUI_Viewport viewport, int datum);

#endif // _GUI_HELPERS_H_