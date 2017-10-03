#include "Block.h"

Block::Block()
{
    _format = _color = _format = 0;
    _left.X = _left.Y = 0;
    _right.X = _right.Y = 0;
}

void Block::ShowFormat(std::ostream& stream)
{
    stream << (int)_format << " ";
    return;
}

void Block::ShowValue(std::ostream& stream)
{
    stream << (int)_value << " ";
    return;
}

void Block::ShowColor(std::ostream& stream)
{
    stream << (int)_color << " ";
    return;
}

void Block::ShowLeft(std::ostream& stream)
{
    stream << _left.X << "," << _left.Y << " ";
    return;
}

void Block::ShowRight(std::ostream& stream)
{
    stream << _right.X << "," << _right.Y << "  ";
    return;
}

void Block::ShowPosition(std::ostream& stream)
{
    stream << _position.X << "," << _position.Y << " ";
    return;
}

bool Block::operator==(const Block & b1)
{
    bool bVal = FALSE;
    if (b1.GetValue() != _value && b1.GetColor() != _color && b1.GetPosition() != _position && b1.GetLeft() != _left && b1.GetRight() != _right)
        bVal = TRUE;
    return bVal;
}

COORD Block::operator=(COORD NewPosition)
{
    COORD Position;
    Position.X = NewPosition.X;
    Position.Y = NewPosition.Y;
    return Position;
}

