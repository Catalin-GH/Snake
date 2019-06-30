#include "Food.h"
#include "Printer.h"

#include <utility>

Food::Food(const Coordonates2D & position, const uint8_t color)
    : mFood(position, Category::FOOD, color)
{
}

Food::~Food()
{
}

Food & Food::operator=(const Food & food)
{
    if (this != &food)
    {
        this->mFood = food.mFood;
    }

    return *this;
}

const Coordonates2D Food::getPosition() const
{
    return mFood.getPosition();
}

void Food::draw() const
{
    Printer::printBlock(mFood);
}

void Food::wipe(const uint8_t color)
{
    mFood.setColor(color);
    Printer::printBlock(mFood);
}
