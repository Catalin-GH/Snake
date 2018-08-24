#include "Snake.h"

Snake::Snake(const Block & StartPosition) {
    build(StartPosition);
}

void Snake::build(const Block & StartPosition) {
    for (size_t i = 0; i < SNAKE_LENGTH; i++) {
        Block block;
        COORD left = { StartPosition.getLeft().X, StartPosition.getLeft().Y - (SHORT)i * 2 };
        COORD right = { StartPosition.getRight().X, StartPosition.getRight().Y - (SHORT)i * 2 };
        COORD position = { StartPosition.getPosition().X, StartPosition.getPosition().Y - (SHORT)i };
        block.setValue(FORMAT);
        block.setFormat(IS_SNAKE);
        block.setLeft(left);
        block.setRight(right);
        block.setPosition(position);
        block.setColor(COLOR_SNAKE);
        m_object.push_back(block);
    }
}

Block Snake::getBlockTemplate(COORD left, COORD right, COORD position) {
    Block block;

    block.setValue(FORMAT);
    block.setColor(COLOR_SNAKE);
    block.setFormat(IS_SNAKE);
    block.setLeft(left);
    block.setRight(right);
    block.setPosition(position);

    return block;
}

bool Snake::hitBodyElement(void) {
    bool bVal = FALSE;

    for (size_t i = 1; i < m_object.size(); i++) {
        if (m_object[0].getPosition().X == m_object[i].getPosition().X && 
            m_object[0].getPosition().Y == m_object[i].getPosition().Y) {
            bVal = TRUE;
            break;
        }
    }

    return bVal;
}

void Snake::insertBodyElement(const Block & NewBlock) {
    m_object.push_back(NewBlock);
}

void Snake::updatePosition(COORD HeadPosition) {
    COORD Position = HeadPosition;
    if (Position.X == m_object[0].getPosition().X &&
        Position.Y == m_object[0].getPosition().Y) {
        COORD head = m_object[0].getPosition();
        COORD body1 = m_object[1].getPosition();
        if (head.Y == body1.Y) {
            Position.Y = head.Y;
            if (head.X < body1.X) {
                Position.X = head.X - 1;
            }
            else if (head.X > body1.X) {
                Position.X = head.X + 1;
            }
        }
        else if (head.X == body1.X) {
            Position.X = head.X;
            if (head.Y < body1.Y) {
                Position.Y = head.Y - 1;
            }
            else if (head.Y > body1.Y) {
                Position.Y = head.Y + 1;
            }
        }
        for (size_t it = m_object.size() - 1; it > 0; it--) {
            m_object[it].setPosition(m_object[it - 1].getPosition());
        }
        m_object[0].setPosition(Position);
    }
    else if (Position.X == m_object[1].getPosition().X &&
             Position.Y == m_object[1].getPosition().Y) {

    }
    else {
        for (size_t it = m_object.size() - 1; it > 0; it--) {
            m_object[it].setPosition(m_object[it - 1].getPosition());
        }
        m_object[0].setPosition(HeadPosition);
    }
}

COORD Snake::arrowKeyPress() {
    COORD newPosition = m_object[0].getPosition();

    if (GetAsyncKeyState(VK_LEFT)) {
        newPosition.Y -= 1;
        return newPosition;
    }
    if (GetAsyncKeyState(VK_UP)) {
        newPosition.X -= 1;
        return newPosition;
    }
    if (GetAsyncKeyState(VK_RIGHT)) {
        newPosition.Y += 1;
        return newPosition;
    }
    if (GetAsyncKeyState(VK_DOWN)) {
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

COORD Snake::operator=(const COORD & New_Pos) {
    COORD Actual_Pos;
    Actual_Pos.X = New_Pos.X;
    Actual_Pos.Y = New_Pos.Y;
    return Actual_Pos;
}
