#include "Game.h"
#include "Logo.h"
#include <thread>

int main(void)
{
    Game *game = new Game();
    game->MainStart();
    delete game;
}
