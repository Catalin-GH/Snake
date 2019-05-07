#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SquareBlock.h"
#include "Types.h"

//to be deleted
#include <vector>

#include <unordered_map>

class SquareBlock;

struct KeyHasher
{
    std::size_t operator()(const SquareBlock & block) const
    {
        using std::hash;
        uint16_t hashResult = 0;
        const uint8_t bitsShift = 8;
        const Coordonates2D pos = block.getPosition();
        const uint8_t color = block.getColor();

        hashResult = hash<uint8_t>()(pos.x) & hash<uint8_t>()(pos.y) << bitsShift;
        hashResult = hashResult & color;

        return hashResult;
    }
};

class Animation
{
private:
    const Coordonates2D mPosition;
    std::vector<SquareBlock> mAnimation;
    std::unordered_map<SquareBlock, std::vector<SquareBlock>, KeyHasher> mNeighbours;

    const std::vector<Coordonates2D> isNeighbour(const Coordonates2D & neighbour) const;
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

bool isOccupied(const uint8_t);

#endif // !__ANIMATION_H__
