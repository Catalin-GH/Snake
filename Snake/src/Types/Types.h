#pragma once

#include <cstdint>

static const uint8_t BLACK_COLOR = 0;
static const uint8_t SQUARE_PLAYGROUND = 20;
static const uint8_t WALL = SQUARE_PLAYGROUND;

enum class Color : uint8_t
{

    gameOver = 15
};

struct Coordonates2D
{
    uint8_t x;
    uint8_t y;

    Coordonates2D(uint8_t x, uint8_t y) : x(x), y(y) {}

    const Coordonates2D& operator=(const Coordonates2D & position)
    {
        this->x = position.x;
        this->y = position.y;
        return *this;
    }

    const bool operator!=(const Coordonates2D & position) const
    {
        return (this->x != position.x && this->y != position.y);
    }

    const bool operator==(const Coordonates2D & position) const
    {
        return (this->x == position.x && this->y == position.y);
    }
};

enum class Category : int8_t
{
    INVALID = -1,
    PLAYGROUND,
    WALL,
    FOOD,
    SNAKE,
    LOGO
};
