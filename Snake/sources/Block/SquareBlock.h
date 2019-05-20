#ifndef __SQUARE_BLOCK_HPP__
#define __SQUARE_BLOCK_HPP__

#include "Block.hpp"

#include <cstdint>

class SquareBlock
{
public:
    SquareBlock(const Coordonates2D & position, const Category category,
        const uint8_t color);
    ~SquareBlock();

    void setColor(const uint8_t color);
    void setPosition(const Coordonates2D & position);

    const uint8_t getColor() const;
    const Category getCategory() const;
    const Block getLeft() const;
    const Block getRight() const;
    const Coordonates2D getPosition() const;

    const bool operator==(const SquareBlock & squareBlock) const;

private:
    Coordonates2D mPosition;
    uint8_t mColor;
    Block mLeft;
    Block mRight;
    const Category mCategory;

    void setBlocksPosition();
};

#endif //__SQUARE_BLOCK_HPP__
