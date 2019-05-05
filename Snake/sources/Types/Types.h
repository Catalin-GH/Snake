#pragma once

#include <cstdint>

static const uint8_t BLACK_COLOR = 0;
static const uint8_t SNAKE = 5;
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

enum class Category : uint8_t
{
    PLAYGROUND = 0,
    WALL,
    FOOD,
    SNAKE,
    LOGO
};

struct ColorGame
{
    uint8_t wall;
    uint8_t playground;
    uint8_t food;
    uint8_t snake;
};
