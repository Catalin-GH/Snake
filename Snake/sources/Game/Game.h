#pragma once

#include <string>
#include <iostream>
#include "Food.h"
#include "Map.h"
#include "Snake.h"
#include "Informations.h"
#include "Functions.h"

#define SPEED 100
#define START_GAME 0
#define SETTINGS 1
#define EXIT 2

class Game
{
private:
    std::string OptionsName[3];
    std::string Options[6];
    Map * _map;
    Snake * _snake;
    Food * _food;
    Infos * _gameInfos;

public:
    Game(void);
    ~Game(void);
    void MainBlock(COORD, size_t, size_t);
    void MainBlockInit(COORD);
    void MainStart(void);
    void Main(COORD);
    void MainOptions();
    void SnakeGame(void);
    void MainExit(void);
    void ConsoleSettings();

    COORD operator=(COORD);
};
