#include "Food.h"

Food::Food()
{
    Block block;
    block.SetColor(COLOR_FOOD);
    block.SetFormat(FORMAT);
    block.SetValue(IS_FOOD);
    _object.push_back(block);
}

void Food::SetPosition(COORD left, COORD right, COORD Position)
{
    _object[0].SetCoord(left, right);
    _object[0].SetPosition(Position);
}
