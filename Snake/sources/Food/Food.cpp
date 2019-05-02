#include "Food.h"

Food::Food(const Coordonates2D & position, const uint8_t color)
    : mFood(position, Category::FOOD, color)
{
}

Food::~Food()
{
}
