#ifndef __BLOCK_HPP__
#define __BLOCK_HPP__

#include "Types.h"

/// Memorize the position of a character in the console.
class Block
{
public:
    explicit Block(const Coordonates2D & position);
    virtual ~Block();

    Block & operator=(const Block & block);

    void setPosition(const Coordonates2D & position);
    const Coordonates2D getPosition() const;

private:
    Coordonates2D mPosition;
};

#endif //__BLOCK_HPP__
