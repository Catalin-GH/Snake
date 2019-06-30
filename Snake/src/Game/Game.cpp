#include "Game.h"

#include "Animation.h"
#include "Console.hpp"
#include "Food.h"
#include "Highscore.hpp"
#include "Map.h"
#include "Utilities.hpp"

#include <memory>

static const uint8_t SPEED = 100;

static const Coordonates2D ANIMATION_POS(((CONSOLE_WIDTH / 2) - animationWidth()) / 2, 3);
static const Coordonates2D MENU_POS((CONSOLE_WIDTH / 2) - 3, (CONSOLE_HEIGHT / 2) - 2);
static const Coordonates2D MAP_POS(((CONSOLE_WIDTH / 2) - SQUARE_PLAYGROUND - 2) / 2, (CONSOLE_HEIGHT - SQUARE_PLAYGROUND) / 2);
static const Coordonates2D SCORE_POS(2, 2);

Game::Game()
{
    consoleSettings();
}

Game::~Game()
{
}

void Game::startup()
{
    srand(time(NULL)); //used for randomness
    const uint8_t waitingThreadTimeMS = 200;
    Status selectedItem = Status::GAME;
    std::unique_ptr<Menu> menu(nullptr);
    std::unique_ptr<Animation> animation(new Animation(ANIMATION_POS)); //initialize animation when application starts for the first time
    
    animation->play();

    while(Status::EXIT != selectedItem) //return to main menu
    {
        menu.reset(new Menu(MENU_POS)); // create menu
        selectedItem = menu->selectState(waitingThreadTimeMS); //select the menu item (START, OPTIONS or EXIT)
        menu.reset(nullptr); //delete the menu, no matter what is the selected item
        select(selectedItem, animation); //do the action for the selected item and manage the animation instance
    }
}

void Game::select(const Status status, std::unique_ptr<Animation> & animation)
{
    switch (status)
    {
        case Status::GAME:
        {
            //stop the animation and remove it from console, because the game will start
            animation->stop();
            animation.reset(nullptr);

            actionGame();

            //run the animation after the game will be finished
            animation.reset(new Animation(ANIMATION_POS));
            animation->play();
        } break;

        case Status::OPTIONS:
        {
            actionOptions();
        } break;

        case Status::EXIT:
        {
            animation->stop();
            animation.reset(nullptr);

            actionExit();
        } break;
    }
}

void Game::actionGame()
{
    Map map(MAP_POS, colors.wall, colors.playground);
    const uint8_t mapColor = map.getColor();

    Snake snake(map.center(), colors.snake);
    snake.draw();

    Food food(map.getRandomPoint(snake.getSnake()), colors.food);
    food.draw();

    Highscore score(SCORE_POS, "Kevin");

    Direction direction = Direction::RIGHT;

    while (true)
    {
        direction = keyPressed(direction);  // get a direction using arrow keys
        snake.wipe(mapColor);

        //game over verification
        if (false == snake.move(direction) || true == isWallHit(snake.getPosition(), map))
        {
            snake.draw();
            sleepThread(3000);
            break; // game over
        }

        //snake eat the food
        if (snake.getPosition() == food.getPosition())
        {
            score.setPoints();
            snake.addBody(snake.getSnake().at(snake.getSnake().size() - 1).getPosition());
            food.wipe(colors.playground);
            food = Food(map.getRandomPoint(snake.getSnake()), colors.food);
            food.draw();
        }
        snake.draw();

        sleepThread(SPEED); // how fast snake moves
    }
}

bool isWallHit(const Coordonates2D headPos, const Map & map)
{
    const Coordonates2D upperLeftCorner(map.getOppositeCornesrs().at(0));
    const Coordonates2D lowerRightCorner(map.getOppositeCornesrs().at(1));

    return ((headPos.x == upperLeftCorner.x) || //verify the left wall
            (headPos.y == upperLeftCorner.y) || // verify the upper wall
            (headPos.x == lowerRightCorner.x) || // verify the right wall
            (headPos.y == lowerRightCorner.y)); // verify the lower wall
}

Direction keyPressed(const Direction lastDirection)
{
    if (GetAsyncKeyState(VK_UP) && lastDirection != Direction::DOWN)
    {
        return Direction::UP;
    }

    if (GetAsyncKeyState(VK_DOWN) && lastDirection != Direction::UP)
    {
        return Direction::DOWN;
    }

    if (GetAsyncKeyState(VK_LEFT) && lastDirection != Direction::RIGHT)
    {
        return Direction::LEFT;
    }

    if (GetAsyncKeyState(VK_RIGHT) && lastDirection != Direction::LEFT)
    {
        return Direction::RIGHT;
    }

    return lastDirection;
}

void Game::actionOptions()
{
}

void Game::actionExit()
{

}

void Game::consoleSettings()
{
    setConsoleFontSize();
    setConsoleWindowSize(CONSOLE_WIDTH, CONSOLE_HEIGHT);
    disableMaximizeButton();
    disableResize();
    consoleTitle("snake");
    showCursor(false);
}
