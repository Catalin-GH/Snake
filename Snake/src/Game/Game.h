#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "MenuItem.hpp"
#include "Snake.h"

typedef struct Colors
{
    uint8_t wall = 5;
    uint8_t playground = 8;
    uint8_t food = 4;
    uint8_t snake = 9;
};

class Animation;
class Map;

class Game
{
public:
    Game();
    virtual ~Game();

    void startup();

private:
    void actionGame();
    void actionOptions();
    void actionExit();
    void consoleSettings();
    void select(const Status status, std::unique_ptr<Animation> & animation);

private:
    Colors colors;
};

/// Return the direction from keyboard using arrow keys.
/// If no arrow is pressed, the function will return last direction.
Direction keyPressed(const Direction lastDirection);

/// Return true in case that snake's head hit the wall, false otherwise.
bool isWallHit(const Coordonates2D headPos, const Map & map);

#endif // !__GAME_HPP__
