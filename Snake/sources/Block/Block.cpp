#include "Block.h"

Block::Block() {
    m_format = 0;
    m_value = 0;
    m_color = nullptr;
    m_left.X = m_left.Y = 0;
    m_right.X = m_right.Y = 0;
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
    stream << (int)*m_color << " ";
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

void Block::PrintBlock(const Block & Block, WORD Color) {
    size_t lx = Block.GetLeft().X;
    size_t ly = Block.GetLeft().Y;
    size_t rx = Block.GetRight().X;
    size_t ry = Block.GetRight().Y;
    gotoxy(ly, lx);             //(col, row)
    SetConsoleTextAttribute(console, Color);
    std::cout << ((char)Block.GetFormat());
    std::cout.clear();
    gotoxy(ry, rx);             //(col, row)
    SetConsoleTextAttribute(console, Color);
    std::cout << ((char)Block.GetFormat());
    std::cout.clear();
}

bool Block::operator==(const Block & b1) {
    bool bVal = FALSE;
    if (b1.GetValue() != m_value
        && b1.GetColor() != *m_color
        && b1.GetPosition() != m_position
        && b1.GetLeft() != m_left
        && b1.GetRight() != m_right) {
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

