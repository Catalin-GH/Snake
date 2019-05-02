#include "SquareBlock.h"

SquareBlock::SquareBlock(const Coordonates2D & position, const Category category,
        const uint8_t color)
    : mPosition(position)
    , mCategory(category)
    , mColor(color)
    , mLeft(position)
    , mRight(position)
{
    setBlocksPosition();
    //print the block to console here?
}

SquareBlock::~SquareBlock()
{
    //clean the block from console here?
}

void SquareBlock::setBlocksPosition()
{
    const uint8_t offset = 1u;
    const uint8_t overlap = 2u; //do not overlap the blocks
    mLeft.setPosition(Coordonates2D(mPosition.x * overlap, mPosition.y));
    mRight.setPosition(Coordonates2D(mPosition.x  * overlap + offset, mPosition.y));
}

void SquareBlock::setPosition(const Coordonates2D & position)
{
    mPosition = position;
    setBlocksPosition();
}

void SquareBlock::setColor(const uint8_t color)
{
    mColor = color;
}

const uint8_t SquareBlock::getColor() const
{
    return mColor;
}

const Category SquareBlock::getCategory() const
{
    return mCategory;
}

const Block SquareBlock::getLeft() const
{
    return mLeft;
}

const Block SquareBlock::getRight() const
{
    return mRight;
}

const Coordonates2D SquareBlock::getPosition() const
{
    return mPosition;
}

const bool SquareBlock::operator==(const SquareBlock & squareBlock) const
{
    return (squareBlock.getCategory() != mCategory
        && squareBlock.getColor() != mColor
        && squareBlock.getPosition() != mPosition);
}
