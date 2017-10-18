#include "Game.h"
#include "Logo.h"
#include <thread>

int main(void)
{
    COORD pos = { 5, 5 };
    AnimatedLogo Logo;
    Logo.InitLogo(pos);
    Logo.printLogo();
    Game *game = new Game();

    std::thread t1(&AnimatedLogo::Animation, &Logo);
    std::thread t2(&Game::MainStart, game);

    t1.join();
    t2.join();
}
