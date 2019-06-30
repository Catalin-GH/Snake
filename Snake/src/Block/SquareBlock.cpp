#include "SquareBlock.h"

#include <utility>

SquareBlock::SquareBlock(const Coordonates2D & position, const Category category, const uint8_t color)
    : mPosition(position)
    , mColor(color)
    , mLeft(position)
    , mRight(position)
    , mCategory(category)
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
    const uint8_t offset = 1;
    const uint8_t overlap = 2; //do not overlap the blocks
    mLeft.setPosition(Coordonates2D((mPosition.x * overlap), mPosition.y));
    mRight.setPosition(Coordonates2D(((mPosition.x  * overlap) + offset), mPosition.y));
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

bool SquareBlock::operator==(const SquareBlock & squareBlock) const
{
    bool result = false;
    if (this != &squareBlock)
    {
        result = (squareBlock.getCategory() == mCategory) && 
            (squareBlock.getColor() == mColor) && 
            (squareBlock.getPosition() == mPosition);
    }
    return result;
}

SquareBlock & SquareBlock::operator=(const SquareBlock & squareBlock)
{
    if(this != &squareBlock)
    {
        mPosition = squareBlock.getPosition();
        mColor = squareBlock.getColor();
        mLeft = squareBlock.getLeft();
        mRight = squareBlock.getRight();
        mCategory = squareBlock.getCategory();
    }

    return *this;
}
