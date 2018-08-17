#include "Food.h"

Food::Food()
{
    Block block;
    block.setColor(COLOR_FOOD);
    block.setFormat(FORMAT);
    block.setValue(IS_FOOD);
    m_object.push_back(block);
}

void Food::SetPosition(COORD left, COORD right, COORD Position)
{
    m_object[0].setCoord(left, right);
    m_object[0].setPosition(Position);
}
