#include "Wall.hpp"
#include "SquareBlock.h"
#include "Printer.h"

Wall::Wall(const Coordonates2D & position, const uint8_t color)
    : mPosition(position)
    , mColor(color)
    , mCategory(Category::WALL)
{
    const uint8_t numberWalls = 4;
    const uint8_t corners = 4;
    mWall.reserve((WALL * numberWalls) + corners);
    computeBlocks();

    draw();
}

Wall::~Wall()
{
    wipe();
}

void Wall::draw() const
{
    for (auto const & sqBlock : mWall)
    {
        Printer::printBlock(sqBlock);
    }
}

void Wall::wipe()
{
    for (auto & sqBlock : mWall)
    {
        sqBlock.setColor(BLACK_COLOR);
        Printer::printBlock(sqBlock);
    }
}

//calculate the square blocks position
void Wall::computeBlocks()
{
    const uint8_t wallEdge = 2;
    const uint8_t value = WALL + wallEdge - 1;
    for (uint8_t i = 0; i < WALL + wallEdge; ++i)
    {
        //up wall
        appendBlocks(Coordonates2D(mPosition.x + i, mPosition.y));
        //down wall
        appendBlocks(Coordonates2D(mPosition.x + i, mPosition.y + value));

        if (i > 0 && i < value)
        {
            //left wall
            appendBlocks(Coordonates2D(mPosition.x , mPosition.y + i));
            //right wall
            appendBlocks(Coordonates2D(mPosition.x + value, mPosition.y + i));
        }
    }
}

void Wall::appendBlocks(const Coordonates2D & position)
{
    mWall.emplace_back(position, mCategory, mColor);
}

const Category Wall::getCategory() const
{
    return mCategory;
}

const std::vector<Coordonates2D> Wall::getOppositeCornesrs() const
{
    return { mWall.at(0).getPosition(), mWall.at(mWall.size() - 1).getPosition() };
}
