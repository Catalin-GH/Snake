#ifndef __WALL_HPP__
#define __WALL_HPP__

#include "Types.h"

#include <vector>

class SquareBlock;

class Wall
{
public:
    Wall(const Coordonates2D & position, const uint8_t color);
    virtual ~Wall();

    const Category getCategory() const;

    const std::vector<Coordonates2D> getOppositeCornesrs() const;

private:
    void computeBlocks();
    void draw() const;
    void wipe();
    void appendBlocks(const Coordonates2D & position);

private:
    const Coordonates2D mPosition;
    uint8_t mColor;
    Category mCategory;
    std::vector<SquareBlock> mWall;
};

#endif //__WALL_HPP__
