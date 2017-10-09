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
    Map * map;
    Snake * snake;
    Food * food;
    Infos GameInfos;
public:
    Game(void);
    void MainBlock(COORD, size_t, size_t);
    void MainBlockInit(COORD);
    void Start(void);
    void Main(COORD);
    void Options();
    void SnakeGame(void);
    void Exit(void);

    COORD operator=(COORD);
};
