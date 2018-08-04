#include "Food.h"

Food::Food()
{
    Block block;
    block.SetColor(COLOR_FOOD);
    block.SetFormat(FORMAT);
    block.SetValue(IS_FOOD);
    m_object.push_back(block);
}

void Food::SetPosition(COORD left, COORD right, COORD Position)
{
    m_object[0].SetCoord(left, right);
    m_object[0].SetPosition(Position);
}
