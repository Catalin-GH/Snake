#ifndef __WALL_HPP__
#define __WALL_HPP__

#include <vector>
#include "Types.h"

class SquareBlock;

class Wall
{
private:
    const Coordonates2D mPosition;
    uint8_t mColor;
    Category mCategory;
    std::vector<SquareBlock> mWall;

    void computeBlocks();
    void draw() const;
    void wipe();
    void appendBlocks(const Coordonates2D & position);

public:
    const Category getCategory() const;

    Wall(const Coordonates2D & position, const uint8_t color);
    ~Wall();
};

#endif //__WALL_HPP__
