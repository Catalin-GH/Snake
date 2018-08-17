#include "Block.h"

Block::Block() : 
    m_format { FORMAT },
    m_value { 0 },
    m_color { 0 },
    m_left { 0, 0 },
    m_right { 0, 0 } {
}

void Block::ShowFormat(std::ostream& stream) {
    stream << (int)m_format << " ";
    return;
}

void Block::ShowValue(std::ostream& stream) {
    stream << (int)m_value << " ";
    return;
}

void Block::ShowColor(std::ostream& stream) {
    stream << (int)m_color << " ";
    return;
}

void Block::ShowLeft(std::ostream& stream) {
    stream << m_left.X << "," << m_left.Y << " ";
    return;
}

void Block::ShowRight(std::ostream& stream) {
    stream << m_right.X << "," << m_right.Y << "  ";
    return;
}

void Block::ShowPosition(std::ostream& stream) {
    stream << m_position.X << "," << m_position.Y << " ";
    return;
}

void Block::printBlock() {
    gotoxy(this->m_left.Y, this->m_left.X);             //(col, row)
    SetConsoleTextAttribute(console, this->m_color);
    std::cout << ((char)this->m_format);
    gotoxy(this->m_right.Y, this->m_right.X);             //(col, row)
    SetConsoleTextAttribute(console, this->m_color);
    std::cout << ((char)this->m_format);
}

bool Block::operator==(const Block & b1) {
    bool bVal = FALSE;
    if (b1.getValue() != m_value
        && b1.getColor() != m_color
        && b1.getPosition() != m_position
        && b1.getLeft() != m_left
        && b1.getRight() != m_right) {
        bVal = TRUE;
    }

    return bVal;
}

COORD Block::operator=(COORD NewPosition) {
    COORD Position;
    Position.X = NewPosition.X;
    Position.Y = NewPosition.Y;
    return Position;
}

