#include "Controls.h"

COORD Controls::Key_Press(const COORD & HeadPosition)
{
    _newPosition = HeadPosition;

    if(GetAsyncKeyState(VK_LEFT))
    {
        _newPosition.Y -= 1;
        return _newPosition;
    }
    if(GetAsyncKeyState(VK_UP))
    {
        _newPosition.X -= 1;
        return _newPosition;
    }
    if(GetAsyncKeyState(VK_RIGHT))
    {
        _newPosition.Y += 1;
        return _newPosition;
    }
    if(GetAsyncKeyState(VK_DOWN))
    {
        _newPosition.X += 1;
    }

    //DWORD count;  /* ignored */
    //INPUT_RECORD event;
    ///* Get the input event */
    //ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &event, 1, &count);

    ///* Only respond to key release events */
    //if ((event.EventType == KEY_EVENT) && !event.Event.KeyEvent.bKeyDown)
    //    switch (event.Event.KeyEvent.wVirtualKeyCode)
    //    {
    //    case VK_LEFT:   _newPosition.Y -= 1; break;
    //    case VK_RIGHT:  _newPosition.Y += 1; break;
    //    case VK_UP:     _newPosition.X -= 1; break;
    //    case VK_DOWN:   _newPosition.X += 1; break;
    //    }

    return _newPosition;
}
