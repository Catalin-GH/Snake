#include "Food.h"

Food::Food()
{
    Block block;
    block.SetColor(COLOR_FOOD);
    block.SetFormat(FORMAT);
    block.SetValue(IS_FOOD);
    _food.push_back(block);
}

void Food::SetPosition(COORD left, COORD right, COORD Position)
{
    _food[0].SetCoord(left, right);
    _food[0].SetPosition(Position);
}

