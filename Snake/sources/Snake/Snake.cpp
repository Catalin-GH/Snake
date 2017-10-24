#include "Snake.h"

Snake::Snake(const Block & StartPosition)
{
    Build(StartPosition);
}

void Snake::Build(const Block & StartPosition)
{
    for (size_t i = 0; i < SNAKE_LENGTH; i++)
    {
        Block block;
        COORD left = { StartPosition.GetLeft().X, StartPosition.GetLeft().Y - (SHORT)i * 2 };
        COORD right = { StartPosition.GetRight().X, StartPosition.GetRight().Y - (SHORT)i * 2 };
        COORD position = { StartPosition.GetPosition().X, StartPosition.GetPosition().Y - (SHORT)i };
        block.SetValue(FORMAT);
        block.SetFormat(IS_SNAKE);
        block.SetLeft(left);
        block.SetRight(right);
        block.SetPosition(position);
        block.SetColor(COLOR_SNAKE);
        _object.push_back(block);
    }
}

Block Snake::GetBlockTemplate(COORD left, COORD right, COORD position)
{
    Block block;
    block.SetValue(FORMAT);
    block.SetColor(COLOR_SNAKE);
    block.SetFormat(IS_SNAKE);
    block.SetLeft(left);
    block.SetRight(right);
    block.SetPosition(position);

    return block;
}

bool Snake::HitBodyElement(void)
{
    bool bVal = FALSE;
    for (size_t i = 1; i < _object.size(); i++)
    {
        if (_object[0].GetPosition() == _object[i].GetPosition())
        {
            bVal = TRUE;
            break;
        }
    }
    return bVal;
}

void Snake::InsertBodyElement(const Block & NewBlock)
{
    _object.push_back(NewBlock);
}

void Snake::UpdatePosition(COORD HeadPosition)
{
    COORD Position = HeadPosition;
    if (Position == _object[0].GetPosition())
    {
        COORD head = _object[0].GetPosition();
        COORD body1 = _object[1].GetPosition();
        if (head.Y == body1.Y)
        {
            Position.Y = head.Y;
            if (head.X < body1.X)
            {
                Position.X = head.X - 1;
            }
            else if (head.X > body1.X)
            {
                Position.X = head.X + 1;
            }
        }
        else if (head.X == body1.X)
        {
            Position.X = head.X;
            if (head.Y < body1.Y)
            {
                Position.Y = head.Y - 1;
            }
            else if (head.Y > body1.Y)
            {
                Position.Y = head.Y + 1;
            }
        }
        for (size_t it = _object.size() - 1; it > 0; it--)
        {
            _object[it].SetPosition(_object[it - 1].GetPosition());
        }
        _object[0].SetPosition(Position);
    }
    else if (Position == _object[1].GetPosition())
    {

    }
    else
    {
        for (size_t it = _object.size() - 1; it > 0; it--)
        {
            _object[it].SetPosition(_object[it - 1].GetPosition());
        }
        _object[0].SetPosition(HeadPosition);
    }
}

COORD Snake::ArrowKeyPress()
{
    COORD newPosition = _object[0].GetPosition();

    if (GetAsyncKeyState(VK_LEFT))
    {
        newPosition.Y -= 1;
        return newPosition;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        newPosition.X -= 1;
        return newPosition;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        newPosition.Y += 1;
        return newPosition;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        newPosition.X += 1;
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

    return newPosition;
}

COORD Snake::operator=(const COORD & New_Pos)
{
    COORD Actual_Pos;
    Actual_Pos.X = New_Pos.X;
    Actual_Pos.Y = New_Pos.Y;
    return Actual_Pos;
}
