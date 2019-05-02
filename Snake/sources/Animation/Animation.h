#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SquareBlock.h"
#include "Types.h"

#include <vector>

class SquareBlock;

//TODO: use kempe's algorithm for animation 

class Animation
{
private:
    const Coordonates2D mPosition;
    std::vector<SquareBlock> mAnimation;

    void initAnimation();
    const uint8_t countOnes(const std::vector<uint8_t> & matrix) const;
    void computeBlocks(const std::vector<uint8_t> & matrix);
    const uint8_t randomColor() const;
    void addElement(const Coordonates2D & position);

    void draw() const;
    void wipe();

public:
    explicit Animation(const Coordonates2D & position);
    ~Animation();
};

#endif // !__ANIMATION_H__
