#include "Block.h"

Block::Block() : 
    m_format { 0 },
    m_value { 0 },
    m_color { 0 },
    m_left { 0, 0 },
    m_right { 0, 0 } {
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

