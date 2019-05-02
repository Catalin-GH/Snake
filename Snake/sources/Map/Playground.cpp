#include "Playground.hpp"
#include "SquareBlock.h"
#include "Printer.h"

Playground::Playground(const Coordonates2D & position, const uint8_t color)
    : mPosition(position)
    , mColor(color)
    , mCategory(Category::PLAYGROUND)
{
    mPlayground.reserve((SQUARE_PLAYGROUND * SQUARE_PLAYGROUND) * sizeof(SquareBlock));
    computeBlocks();

    draw();
}

Playground::~Playground()
{
    wipe();
}

void Playground::draw() const
{
    for (auto const & sqBlock : mPlayground)
    {
        Printer::printBlock(sqBlock);
    }
}

void Playground::wipe()
{
    for (auto & sqBlock : mPlayground)
    {
        sqBlock.setColor(BLACK_COLOR);
        //Printer::printBlock(sqBlock);
    }
}

void Playground::computeBlocks()
{
    const auto numberBlocks = SQUARE_PLAYGROUND * SQUARE_PLAYGROUND;

    uint8_t valuePosX = 0;
    uint8_t valuePosY = 0;
    for (uint16_t i = 0; i < numberBlocks; ++i)
    {
        appendBlocks(Coordonates2D(mPosition.x + valuePosX, mPosition.y + valuePosY));
        if (0 == (i + 1) % SQUARE_PLAYGROUND && i != 0)
        {
            ++valuePosY;
            valuePosX = 0;
        }
        else
        {
            ++valuePosX;
        }
    }
}

void Playground::appendBlocks(const Coordonates2D & position)
{
    mPlayground.emplace_back(position, mCategory, mColor);
}

const Category Playground::getCategory() const
{
    return mCategory;
}
