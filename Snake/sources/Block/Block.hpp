#ifndef __BLOCK_HPP__
#define __BLOCK_HPP__

#include "Types.h"

class Block
{
private:
    Coordonates2D mPosition;

public:
    explicit Block(const Coordonates2D & position);
    ~Block();

    void setPosition(const Coordonates2D & position);
    const Coordonates2D getPosition() const;
};

#endif //__BLOCK_HPP__
