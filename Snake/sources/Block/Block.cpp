#include "Block.hpp"

Block::Block(const Coordonates2D & position)
    : mPosition(position)
{
}

Block::~Block()
{
}

const Coordonates2D Block::getPosition() const
{
    return mPosition;
}

void Block::setPosition(const Coordonates2D & position)
{
    mPosition = position;
}
