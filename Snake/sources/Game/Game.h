#pragma once

#include <algorithm>
#include <string> 
#include <thread>

#include "Console_Functions.h"
#include "Food.h"
#include "Functions.h"
#include "Information.h"
#include "Map.h"
#include "Logo.h"
#include "Object.h"
#include "Snake.h"

#define SPEED 100
#define START_GAME 0
#define SETTINGS 1
#define EXIT 2
#define NTHREAD 1

extern size_t COLOR_MAP;
extern size_t COLOR_SNAKE;
extern size_t COLOR_WALL;
extern size_t COLOR_FOOD;

class Game
{
private:
    Map m_map;
    Snake m_snake;
    Food m_food;
    Info m_gameInfo;
    AnimatedLogo m_logo;
    std::thread m_thread[NTHREAD];

public:
    Game(void);
    ~Game(void);
    void MainStart(void);
    void Main(COORD);
    void MainOptions();
    void SnakeGame(void);
    void MainExit(void);
    void ConsoleSettings();

    COORD operator=(COORD);
};
