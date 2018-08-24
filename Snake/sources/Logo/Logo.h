#pragma once

#include <iostream>
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

class AnimatedLogo
{
private:
    Block m_logo[LOGO_ROWS][LOGO_COLS];                 //entire logo
    Block  m_logo_part[LOGOPART_LENGHT];            //just snake and food properties
    size_t m_logo_matrix[LOGO_ROWS][LOGO_COLS];         //used for path, letters and the line in the footer of the logo
    std::pair<size_t, size_t> m_path[52];
    static bool m_stop_animation;
    static bool m_animation_stopped;

public:
    inline void SetStopAnimation(bool value) { m_stop_animation = value; }
    inline bool StopAnimation() { return m_stop_animation; }
    inline bool VerifyAnimation() { return m_animation_stopped; }
    
    void setMapColor(size_t color) {
        for (uint8_t i = 0; i < LOGO_ROWS - 1; i++) {
            for (uint8_t j = 0; j < LOGO_COLS; j++) {
                if (m_logo_matrix[i][j] > 0) {
                    m_logo[i][j].setColor(color);
                }
            }
        }
    }
    void setWallColor(size_t color) {
        for (uint8_t i = LOGO_ROWS - 1; i < LOGO_ROWS; i++) {
            for (uint8_t j = 0; j < LOGO_COLS; j++) {
                m_logo[i][j].setColor(color);
            }
        }
    }
    void setSnakeColor(size_t color) {
        for(uint8_t i = 0; i < SNAKE_LENGTH; i++) {
            m_logo_part[i].setColor(color);
        }
    };
    void setFoodColor(size_t color) { m_logo_part[LOGOPART_LENGHT - 1].setColor(color); }
    void InitialSetup(void);
    void InitLogoMatrix(void);
    void InitPath(void);
    void InitLogo(COORD);
    void printLogo(void);
    void Animation(void);
};