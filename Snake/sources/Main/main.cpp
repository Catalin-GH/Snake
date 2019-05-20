#include "Map.h"
#include "Animation.h"
#include "Highscore.hpp"
#include "Utilities.hpp"
#include <chrono>
#include <thread>

int main()
{
    srand(time_t()); //used for randomness 

    //Game game;
    //game.mainStart();

    //Coordonates2D position{ 1, 0 };
    //Food food(position, 4);

    //Coordonates2D position1{ 1, 1 };
    //Food food1(position1, 15);

    //Map wall({ 2, 3 });

    Animation animation({ 0, 0 });
    animation.play();

    sleepThread(5000);
    Animation::stop();

    sleepThread(3000);

    //Highscore hightscore({ 3, 0 }, "George");

    //hightscore.setPoints(10);

    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //hightscore.setPoints(200);
}
