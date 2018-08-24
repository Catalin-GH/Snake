#pragma once

#include "Object.h"
#include "Functions.h"

extern size_t COLOR_FOOD;

class Food : public Object
{
public:
    Food();
    void SetPosition(COORD, COORD, COORD);
    Block GetBlock() const { return m_object[0]; }
    std::vector<Block> GetFood() const { return m_object; }
};
