#ifndef __PLAYGROUND_HPP__
#define __PLAYGROUND_HPP__

#include <vector>
#include "Types.h"

class SquareBlock;

class Playground
{
private:
    const Coordonates2D mPosition;
    uint8_t mColor;
    Category mCategory;
    std::vector<SquareBlock> mPlayground;

    void computeBlocks();
    void draw() const;
    void wipe();
    void appendBlocks(const Coordonates2D & position);

public:
    const Category getCategory() const;

    Playground(const Coordonates2D & position, const uint8_t color);
    ~Playground();
};

#endif //__PLAYGROUND_HPP__
