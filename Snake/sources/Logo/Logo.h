#pragma once

#include <iostream>
#include <vector>
#include "Block.h"
#include "Snake.h"
#include "Food.h"
#include <utility>

#define LOGO_COLS 24
#define  LOGO_ROWS 6

class AnimatedLogo
{
private:
    Block _logo[LOGO_ROWS][LOGO_COLS];
public:
    AnimatedLogo(void);
    void InitLogo(COORD);
    void printLogo(void);
    void Animation(void);
};