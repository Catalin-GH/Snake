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
    Block m_logo[LOGO_ROWS][LOGO_COLS];                 //entire logo properties
    Block  m_logo_part[LOGOPART_LENGHT];            //just snake and food properties
    size_t m_logo_matrix[LOGO_ROWS][LOGO_COLS];         //used for path, letters and the line in the footer of the logo
    std::pair<size_t, size_t> m_path[52];
    static bool m_stop_animation;
    static bool m_animation_stopped;

public:
    inline void SetStopAnimation(bool value) { m_stop_animation = value; }
    inline bool StopAnimation() { return m_stop_animation; }
    inline bool VerifyAnimation() { return m_animation_stopped; }
    
    void InitialSetup(void);
    void InitLogoMatrix(void);
    void InitPath(void);
    void InitLogo(COORD);
    void printLogo(void);
    void Animation(void);
};