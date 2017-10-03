#include "Controls.h"

COORD Controls::Key_Press(const COORD & HeadPosition)
{
    _newPosition = HeadPosition;
    bool bVal = FALSE;

    if(GetAsyncKeyState(VK_LEFT) && (bVal == FALSE))
    {
        _newPosition.Y -= 1;
        bVal = TRUE;
    }
    if(GetAsyncKeyState(VK_UP) && (bVal == FALSE))
    {
        _newPosition.X -= 1;
        bVal = TRUE;
    }
    if(GetAsyncKeyState(VK_RIGHT) && (bVal == FALSE))
    {
        _newPosition.Y += 1;
        bVal = TRUE;
    }
    if(GetAsyncKeyState(VK_DOWN) && (bVal == FALSE))
    {
        _newPosition.X += 1;
        bVal = TRUE;
    }

    return _newPosition;
}
