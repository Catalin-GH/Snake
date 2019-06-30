#include "Playground.hpp"
#include "Printer.h"
#include "Snake.h"
#include "Utilities.hpp"

#include <algorithm>

Playground::Playground(const Coordonates2D & position, const uint8_t color)
    : mPosition(position)
    , mColor(color)
    , mCategory(Category::PLAYGROUND)
{
    mPlayground.reserve(SQUARE_PLAYGROUND * SQUARE_PLAYGROUND);
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
        Printer::printBlock(sqBlock);
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

const Coordonates2D Playground::center() const
{
    return mPlayground.at((mPlayground.size() / 2) - SQUARE_PLAYGROUND + (SQUARE_PLAYGROUND / 2)).getPosition();
}

const uint8_t Playground::getColor() const
{
    return mColor;
}

const Coordonates2D Playground::randomPoint(const std::deque<SquareBlock> & snake) const
{
    Coordonates2D point(0, 0);

    do
    {
        auto number = randNumber(0, mPlayground.size());
        point = mPlayground.at(number).getPosition();

    } while (std::any_of(snake.cbegin(), snake.cend(), [&point](const SquareBlock & block) {return point == block.getPosition(); }));

    return point;
}
