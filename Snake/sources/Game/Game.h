#pragma once

#include <string>
#include "Food.h"
#include "Map.h"
#include "Snake.h"
#include "Informations.h"
#include "Functions.h"
#include "Object.h"
#include "Logo.h"
#include <thread>

#define SPEED 100
#define START_GAME 0
#define SETTINGS 1
#define EXIT 2

class Game
{
private:
    Map * _map;
    Snake * _snake;
    Food * _food;
    Infos * _gameInfos;
    std::thread t1;
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
