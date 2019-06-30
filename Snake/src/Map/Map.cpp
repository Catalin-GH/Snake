#include "Map.h"

Map::Map(const Coordonates2D & position, const uint8_t wallColor, const uint8_t playgroundColor)
    : mPosition(position)
    , mWall(position, wallColor)
    , mPlayground(Coordonates2D(position.x + 1, position.y + 1), playgroundColor)
{
}

Map::~Map()
{
}

const Coordonates2D Map::center() const
{
    return mPlayground.center();
}

uint8_t Map::getColor() const
{
    return mPlayground.getColor();
}

const std::vector<Coordonates2D> Map::getOppositeCornesrs() const
{
    return mWall.getOppositeCornesrs();
}

const Coordonates2D Map::getRandomPoint(const std::deque<SquareBlock>& snake) const
{
    return mPlayground.randomPoint(snake);
}
