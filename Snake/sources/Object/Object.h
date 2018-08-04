#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Console_Functions.h"
#include "Block.h"

class Object
{
protected:
    std::vector<Block> m_object;

public:
    Object() {}
    void SeeInfos(uint8_t);
    virtual ~Object() {}
};
