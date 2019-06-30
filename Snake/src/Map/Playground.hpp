#ifndef __PLAYGROUND_HPP__
#define __PLAYGROUND_HPP__

#include "Types.h"

#include <vector>
#include <deque>

class SquareBlock;

class Playground
{
public:
    Playground(const Coordonates2D & position, const uint8_t color);
    virtual ~Playground();

    const Category getCategory() const;
    const Coordonates2D center() const;
    const uint8_t getColor() const;
    const Coordonates2D randomPoint(const std::deque<SquareBlock> & snake) const;

private:
    void computeBlocks();
    void draw() const;
    void wipe();
    void appendBlocks(const Coordonates2D & position);

private:
    const Coordonates2D mPosition;
    uint8_t mColor;
    Category mCategory;
    std::vector<SquareBlock> mPlayground;
};

#endif //__PLAYGROUND_HPP__
