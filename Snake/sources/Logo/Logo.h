#pragma once

#include <iostream>
#include <vector>
#include "Block.h"
#include "Snake.h"
#include "Food.h"
#include <utility>

#define LOGO_COLS 24
#define LOGO_ROWS 6
#define LOGOPART_LENGHT (SNAKE_LENGTH + 2 + 1)    //snake length(5 blocks) + 2 background blocks(2 blocks) + 1 food block(1 block)

extern size_t COLOR_MAP;
extern size_t COLOR_WALL;
extern size_t COLOR_FOOD;
extern size_t COLOR_SNAKE;

class AnimatedLogo
{
private:
    Block _logo[LOGO_ROWS][LOGO_COLS];
    Block _logoPart[LOGOPART_LENGHT];
    std::vector<std::pair<size_t, size_t>> _path;
    bool _condition = FALSE;
public:
    inline void SetCondition(bool Flag) { _condition = Flag; }
    inline bool GetCondition() const { return _condition; }
    AnimatedLogo(void);
    void InitPath(void);
    void InitLogo(COORD);
    void printLogo(void);
    void Animation(void);
};