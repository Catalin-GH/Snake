#pragma once

#include <algorithm>
#include <string> 
#include <thread>

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
