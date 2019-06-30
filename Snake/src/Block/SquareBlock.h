#ifndef __SQUARE_BLOCK_HPP__
#define __SQUARE_BLOCK_HPP__

#include "Block.hpp"

#include <cstdint>

/// Custom define of two close characters in console.
/// A square is formed by adding two rectangles side by side.
/// A square represents two adjacent characters in console.
class SquareBlock
{
public:
    SquareBlock(const Coordonates2D & position, const Category category, const uint8_t color);
    virtual ~SquareBlock();

    void setColor(const uint8_t color);

    const uint8_t getColor() const;
    const Category getCategory() const;
    const Block getLeft() const;
    const Block getRight() const;
    const Coordonates2D getPosition() const;

    bool operator==(const SquareBlock & squareBlock) const;
    SquareBlock & operator=(const SquareBlock & squareBlock);

private:
    /// Set the positions of the left and right blocks so that they form a square
    void setBlocksPosition();

private:
    /// Position of the square.
    Coordonates2D mPosition;

    /// Color of the square.
    uint8_t mColor;

    /// Left and right side blocks that form the square.
    Block mLeft;
    Block mRight;

    /// The category it belongs to.
    Category mCategory;
};

#endif //__SQUARE_BLOCK_HPP__
