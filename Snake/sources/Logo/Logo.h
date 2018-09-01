#pragma once

#include <iostream>
#include <atomic>
#include <vector>
#include "Block.h"
#include "Snake.h"
#include "Food.h"
#include "Functions.h"

#define LOGO_COLS 24
#define LOGO_ROWS 6
#define LOGOPART_LENGHT (SNAKE_LENGTH + 2 + 1)    //snake length(5 blocks) + 2 background blocks(2 blocks) + 1 food block(1 block)

extern size_t COLOR_MAP;
extern size_t COLOR_WALL;
extern size_t COLOR_FOOD;
extern size_t COLOR_SNAKE;
extern Printer printer;

class Animation
{
private:
    Block m_logo[LOGO_ROWS][LOGO_COLS];             //entire logo
    Block  m_logo_part[LOGOPART_LENGHT];            //just snake and food properties
    uint8_t m_logo_path[LOGO_ROWS][LOGO_COLS];     //used for path, letters and the line in the footer of the logo
    std::pair<uint8_t, uint8_t> m_path[52];
    volatile bool m_stop_animation;

public:
    Animation();

    void startAnimation(COORD&);
    void stopAnimation();
 
    void setAnimationFoodColor(WORD);
    void setAnimationMapColor(WORD);
    void setAnimationWallColor(WORD);
    void setAnimationSnakeColor(WORD);

    void initLogoMatrix();
    void initPath();
    void initLogo(COORD);

    void printBackground();
};
