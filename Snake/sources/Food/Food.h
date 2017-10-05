#pragma once

#include <iostream>
#include "Functions.h"
#include "Console_Functions.h"
#include "Block.h"
#include <vector>

extern int COLOR_FOOD;

class Food
{
private:
    std::vector<Block> _food;
public:
    Food();
    void SetPosition(COORD, COORD, COORD);
    Block GetBlock() const { return _food[0]; }
    std::vector<Block> GetFood() const { return _food; }
};
