#ifndef __FOOD_H__
#define __FOOD_H__

#include "SquareBlock.h"
#include "Types.h"

class Food
{
public:
    Food(const Coordonates2D & position, const uint8_t color);
    virtual ~Food();

    Food & operator=(const Food & food);
    const Coordonates2D getPosition() const;
    void wipe(const uint8_t color);
    void draw() const;

private:
    SquareBlock mFood;
};

#endif //__FOOD_H__
