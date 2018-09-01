#include "Game.h"

Game::Game(){
    ConsoleSettings();
}

void Game::MainStart()
{
    COORD position = { 5, 15 };

    Sleep(50);
    m_thread[0] = std::thread(&Animation::startAnimation, &m_animation, std::ref(position));
    Sleep(50);

    /*place options in the center of the console*/
    uint8_t val_y = 4;
    uint8_t val_x = 2;
    uint8_t x = (CONSOLE_LENGTH / val_x) - ((SHORT)m_gameInfo.GetMain(0).size() / val_x);
    uint8_t y = (CONSOLE_LENGTH / val_y) - ((SHORT)m_gameInfo.GetMain(0).size() / val_y);
    Main({ x, y });
}

void Game::Main(COORD Position)
{
    size_t select = 0;
    m_gameInfo.MainBlockInit(Position);
    bool bVal = FALSE;
    while (!bVal)
    {
        Show_Cursor(FALSE);
        size_t previousSelected;
        if (GetAsyncKeyState(VK_DOWN))
        {
            previousSelected = select;
            if (select < 2)
            {
                m_gameInfo.mainElement(Position, COLOR_MAIN, previousSelected);
                ++select;
                m_gameInfo.mainElement(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            previousSelected = select;
            if (select > 0)
            {
                m_gameInfo.mainElement(Position, COLOR_MAIN, previousSelected);
                --select;
                m_gameInfo.mainElement(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            switch (select)
            {
            case START_GAME:
            {
                m_animation.stopAnimation();
                if (m_thread[0].joinable()) {
                    m_thread[0].join();
                }
                cls();

                SnakeGame();
                cls();

                COORD position = { 5, 15 };
                m_thread[0] = std::thread(&Animation::startAnimation, &m_animation, std::ref(position));
                Sleep(50);

                select = 0;
                m_gameInfo.MainBlockInit(Position);
            }break;
            case SETTINGS:
            {
                MainOptions();
                cls();
                m_animation.printBackground();
                select = 0;
                m_gameInfo.MainBlockInit(Position);
            }break;
            case EXIT:
            {
                MainExit();
                select = 0;
                bVal = TRUE;
                cls();
            }break;
            }
        }
        Sleep(200);
    }
}

void Game::MainOptions()
{
    /*place options in the center of the console*/
    COORD Position = { CONSOLE_LENGTH / 2 - (SHORT)m_gameInfo.GetOptions(0).size() / 2, CONSOLE_HEIGHT / 2 - 5 };

    /*print options*/
    m_gameInfo.OptionsBlockInit(Position);
    Sleep(50);

    /*arrow is pressed*/
    size_t select = 0;
    size_t colors[] = { COLOR_MAP, COLOR_WALL, COLOR_FOOD, COLOR_SNAKE };
    bool bVal = FALSE;
    while (!bVal) {
        Show_Cursor(FALSE);
        size_t previousSelected;
        if (GetAsyncKeyState(VK_DOWN)) {
            previousSelected = select;
            if (select < 4) {
                m_gameInfo.optionElement(Position, COLOR_MAIN, previousSelected);
                Sleep(50);
                ++select;
                m_gameInfo.optionElement(Position, COLOR_MAIN_SELECT, select);
                Sleep(50);
            }
            Sleep(200);
        }
        else if (GetAsyncKeyState(VK_UP)) {
            previousSelected = select;
            if (select > 0) {
                m_gameInfo.optionElement(Position, COLOR_MAIN, previousSelected);
                Sleep(50);
                --select;
                m_gameInfo.optionElement(Position, COLOR_MAIN_SELECT, select);
                Sleep(50);
            }
            Sleep(200);
        }
        else if (GetAsyncKeyState(VK_LEFT)) {
            if (colors[select] > 0) {
                size_t color = colors[select];
                do {
                    --color;
                    bool colorNotFound = FALSE;
                    for (size_t i = 0; i < 4; i++) {
                        if (color == colors[i]) {
                            colorNotFound = TRUE;
                        }
                    }
                    if (!colorNotFound) {
                        colors[select] = color;
                        break;
                    }
                } while (color > 0);
                switch (select) {
                case 0: COLOR_MAP = colors[0]; m_animation.setAnimationMapColor(COLOR_MAP);  m_animation.printBackground(); Sleep(100); break;
                case 1: COLOR_WALL =  colors[1]; m_animation.setAnimationWallColor(COLOR_WALL); m_animation.printBackground(); Sleep(100);  break;
                case 2: COLOR_FOOD = colors[2]; m_animation.setAnimationFoodColor(COLOR_FOOD);  break;
                case 3: COLOR_SNAKE = colors[3]; m_animation.setAnimationSnakeColor(COLOR_SNAKE);  break;
                }
            }
            Sleep(50);
        }
        else if (GetAsyncKeyState(VK_RIGHT)) {
            if (colors[select] < 15) {
                size_t color = colors[select];

                do {
                    ++color;
                    bool colorNotFound = FALSE;
                    for (size_t i = 0; i < 4; i++) {
                        if (color == colors[i]) {
                            colorNotFound = TRUE;
                        }
                    }
                    if (!colorNotFound) {
                        colors[select] = color;
                        break;
                    }
                } while (color < 15);

                switch (select) {
                case 0: COLOR_MAP   = colors[0]; m_animation.setAnimationMapColor(COLOR_MAP);     m_animation.printBackground(); Sleep(100); break;
                case 1: COLOR_WALL  = colors[1]; m_animation.setAnimationWallColor(COLOR_WALL);   m_animation.printBackground(); Sleep(100); break;
                case 2: COLOR_FOOD  = colors[2]; m_animation.setAnimationFoodColor(COLOR_FOOD);   break;
                case 3: COLOR_SNAKE = colors[3]; m_animation.setAnimationSnakeColor(COLOR_SNAKE); break;
                }
            }
            Sleep(50);
        }
        else if (GetAsyncKeyState(VK_RETURN) && select == 4) {
            bVal = TRUE;
        }
        Sleep(100);
    }
}

void Game::SnakeGame() {
    COORD OriginPosition = { (SHORT)(CONSOLE_HEIGHT - MAP_LENGTH) / 2 , (SHORT)(CONSOLE_LENGTH - MAP_LENGTH * 2) / 2 };
    m_map.build(OriginPosition);
    m_map.printGraphic();
    COORD Position = { 2, 3 };
    m_gameInfo.printPointsMessage(Position);
    COORD RandPoint = m_map.randomPosition();
    m_food.SetPosition(m_map.getBlock(RandPoint.X, RandPoint.Y).getLeft(), m_map.getBlock(RandPoint.X, RandPoint.Y).getRight(), RandPoint);
    m_snake = Snake(m_map.getCenterBlock());
    m_map.updateObject(m_snake.getSnake());
    m_map.printGraphicObject(m_snake.getSnake());
    m_map.updateObject(m_food.GetFood());
    m_map.printGraphicObject(m_food.GetFood());
    bool bVal = FALSE;
    while (TRUE)
    {
        m_map.deleteGraphicObject(m_snake.getSnake());
        m_map.printGraphicObject(m_snake.getSnake());
        m_snake.updatePosition(m_snake.arrowKeyPress());
        if (m_map.updateObject(m_snake.getSnake()) && !m_snake.hitBodyElement())
        {
            m_map.printGraphicObject(m_snake.getSnake());
            if (m_snake.getSnake()[0].getPosition().X == m_food.GetBlock().getPosition().X && 
                m_snake.getSnake()[0].getPosition().Y == m_food.GetBlock().getPosition().Y )
            {
                COORD Position = { 2, 3 };
                m_gameInfo.IncreasePoints();
                m_gameInfo.printPoints();
                m_snake.insertBodyElement(m_snake.getBlockTemplate(m_map.getBlock(RandPoint.X, RandPoint.Y).getLeft(), m_map.getBlock(RandPoint.X, RandPoint.Y).getRight(), RandPoint));
                COORD RandPoint = m_map.randomPosition();
                m_map.deleteGraphicObject(m_food.GetFood());
                m_food.SetPosition(m_map.getBlock(RandPoint.X, RandPoint.Y).getLeft(), m_map.getBlock(RandPoint.X, RandPoint.Y).getRight(), RandPoint);
                m_map.updateObject(m_food.GetFood());
                m_map.printGraphicObject(m_food.GetFood());
            }
        }
        else
        {
            COORD Position = { CONSOLE_LENGTH / 2 - 8, 3 };
            while (!GetAsyncKeyState(VK_RETURN))
            {
                m_gameInfo.GameOverMessage(Position);
            }
            m_gameInfo.ResetScore();
            break;
        }
        Sleep(SPEED);
    }
}

void Game::ConsoleSettings()
{
    SetConsoleFontSize();
    SetConsoleWindowSize(CONSOLE_LENGTH, CONSOLE_HEIGHT);
    DisableMaximizeButton();
    DisableResize();
    ConsoleTitle();
}

void Game::MainExit()
{
    m_animation.stopAnimation();
    if (m_thread[0].joinable()) {
        m_thread[0].join();
    }
}

COORD Game::operator=(COORD coord)
{
    COORD position;
    position.X = coord.X;
    position.Y = coord.Y;
    return position;
}
