#ifndef __FOOD_H__
#define __FOOD_H__

#include "SquareBlock.h"
#include "Types.h"

class Food
{
private:
    const SquareBlock mFood;

public:
    Food(const Coordonates2D & position, const uint8_t color);
    ~Food();
};

#endif //__FOOD_H__
