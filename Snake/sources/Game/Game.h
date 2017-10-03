#pragma once

#include <string>
#include <iostream>
#include "Food.h"
#include "Map.h"
#include "Snake.h"
#include "Controls.h"
#include "Informations.h"

#define MAP_SIDE_LENGTH 25
#define MAP_ORIGIN_POSITION 10
#define SPEED 100
#define START_GAME 0
#define SETTINGS 1
#define EXIT 2

class Game
{
private:
    Map * map;
    Snake * snake;
    Food * food;
    Infos GameInfos;
    Controls con;
public:
    Game(void);
    void TheMain(const COORD &);
    void Options(void);
    void GameStart(void);
    void GameSetup(void);

    COORD operator=(COORD);
};
