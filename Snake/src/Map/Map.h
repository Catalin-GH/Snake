#ifndef __MAP_H__
#define __MAP_H__

#include "Playground.hpp"
#include "Types.h"
#include "Wall.hpp"

class Snake;

class Map
{
public:
    Map(const Coordonates2D & position, const uint8_t wallColor, const uint8_t playgroundColor);
    virtual ~Map();

    /// Get the position of center of the map
    const Coordonates2D center() const;

    uint8_t getColor() const;

    const std::vector<Coordonates2D> getOppositeCornesrs() const;

    const Coordonates2D getRandomPoint(const std::deque<SquareBlock> & snake) const;

private:
    const Coordonates2D mPosition;
    const Wall mWall;
    const Playground mPlayground;
};

#endif //__MAP_H__ 
