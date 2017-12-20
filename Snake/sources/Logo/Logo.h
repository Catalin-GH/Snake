#pragma once

#include <iostream>
#include <vector>
#include "Block.h"
#include "Snake.h"
#include "Food.h"

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
    Block ** _logo;                 //entire logo properties
    Block  * _logo_part;             //just snake and food properties
    size_t ** _logo_matrix;         //used for path, letters and the line in the footer of the logo
    std::pair<size_t, size_t> _path[52];
    static bool _stop_animation;
    static bool _animation_stopped;
public:
    inline void SetStopAnimation(bool value) { _stop_animation = value; }
    inline bool StopAnimation() { return _stop_animation; }
    inline bool VerifyAnimation() { return _animation_stopped; }
    void InitialSetup(void);
    void InitLogoMatrix(void);
    void AllocateMemoryLogoMatrix(void);
    void ReleaseMemoryLogoMatrix(void);
    void AllocateMemory(void);
    void ReleaseMemory(void);
    void InitPath(void);
    void InitLogo(COORD);
    void printLogo(void);
    void Animation(void);
};