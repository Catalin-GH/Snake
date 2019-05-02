//#pragma once
//
//#include <algorithm>
//#include <string> 
//#include <thread>
//
//#include "Animation.h"
//#include "Console_Functions.h"
//#include "Food.h"
//#include "Information.h"
//#include "Map.h"
//#include "Snake.h"
//#include "Types.h"
//
//const uint8_t SPEED = 100;
//const uint8_t START_GAME = 0;
//const uint8_t SETTINGS = 1;
//const uint8_t EXIT = 2;
//const uint8_t NTHREAD = 1;
//
//extern ColorGame colorGame;
//
//class Game
//{
//private:
//    Map m_map;
//    Snake m_snake;
//    Food m_food;
//    Info m_gameInfo;
//    Animation m_animation;
//    std::thread m_thread[NTHREAD];
//
//public:
//    Game();
//
//    void mainStart();
//    void main(COORD);
//    void mainOptions();
//    void snakeGame();
//    void stopAnimation();
//    void consoleSettings();
//    void menuSetupContext();
//    void gameSetupContext();
//
//    COORD operator=(COORD);
//};
