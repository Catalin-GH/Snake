//#include "Game.h"
//
//Game::Game(){
//    consoleSettings();
//}
//
//void Game::mainStart()
//{
//    COORD position = { 5, 15 };
//
//    Sleep(50);
//    m_thread[0] = std::thread(&Animation::startAnimation, &m_animation, std::ref(position));
//    Sleep(50);
//
//    /*place options in the center of the console*/
//    uint8_t val_y = 4;
//    uint8_t val_x = 2;
//    uint8_t x = (CONSOLE_LENGTH / val_x) - ((SHORT)m_gameInfo.getMainAt(0).size() / val_x);
//    uint8_t y = (CONSOLE_LENGTH / val_y) - ((SHORT)m_gameInfo.getMainAt(0).size() / val_y);
//    main({ x, y });
//}
//
//void Game::main(COORD position) {
//    uint8_t select = 0;
//    m_gameInfo.printMain(position);
//    bool bVal = FALSE;
//    while (!bVal) {
//        uint8_t previousSelected;
//        if (GetAsyncKeyState(VK_DOWN)) {
//            previousSelected = select;
//            if (select < 2) {
//                m_gameInfo.mainElement(position, Color::main, previousSelected);
//                ++select;
//                m_gameInfo.mainElement(position, Color::main_select, select);
//            }
//            Sleep(100);
//        }
//        else if (GetAsyncKeyState(VK_UP)) {
//            previousSelected = select;
//            if (select > 0) {
//                m_gameInfo.mainElement(position, Color::main, previousSelected);
//                --select;
//                m_gameInfo.mainElement(position, Color::main_select, select);
//            }
//            Sleep(100);
//        }
//        if (GetAsyncKeyState(VK_RETURN)) {
//            switch (select) {
//                case START_GAME: {
//                    m_animation.stopAnimation();
//                    if (m_thread[0].joinable()) {
//                        m_thread[0].join();
//                    }
//                    cls();
//
//                    snakeGame();
//                    cls();
//
//                    COORD position_animation = { 5, 15 };
//                    m_thread[0] = std::thread(&Animation::startAnimation, &m_animation, std::ref(position_animation));
//                    Sleep(50);
//
//                    select = 0;
//                    m_gameInfo.printMain(position);
//                }break;
//                case SETTINGS: {
//                    mainOptions();
//                    cls();
//                    m_animation.printBackground();
//                    select = 0;
//                    m_gameInfo.printMain(position);
//                }break;
//                case EXIT: {
//                    stopAnimation();
//                    select = 0;
//                    bVal = TRUE;
//                    cls();
//                }break;
//            }
//        }
//        Sleep(200);
//    }
//}
//
//void Game::mainOptions() {
//    /*place options in the center of the console*/
//    COORD Position = { CONSOLE_LENGTH / 2 - (SHORT)m_gameInfo.getOptionAt(0).size() / 2, CONSOLE_HEIGHT / 2 - 5 };
//
//    /*print options*/
//    m_gameInfo.printOptions(Position);
//    Sleep(50);
//
//    /*arrow is pressed*/
//    uint8_t select = 0;
//    WORD colors[] = { colorGame.map, colorGame.wall, colorGame.food, colorGame.snake };
//    bool bVal = FALSE;
//    while (!bVal) {
//        Show_Cursor(FALSE);
//        uint8_t previousSelected;
//        if (GetAsyncKeyState(VK_DOWN)) {
//            previousSelected = select;
//            if (select < 4) {
//                m_gameInfo.optionElement(Position, Color::main, previousSelected);
//                Sleep(50);
//                ++select;
//                m_gameInfo.optionElement(Position, Color::main_select, select);
//                Sleep(50);
//            }
//            Sleep(200);
//        }
//        else if (GetAsyncKeyState(VK_UP)) {
//            previousSelected = select;
//            if (select > 0) {
//                m_gameInfo.optionElement(Position, Color::main, previousSelected);
//                Sleep(50);
//                --select;
//                m_gameInfo.optionElement(Position, Color::main_select, select);
//                Sleep(50);
//            }
//            Sleep(200);
//        }
//        else if (GetAsyncKeyState(VK_LEFT)) {
//            if (colors[select] > 0) {
//                WORD color = colors[select];
//                do {
//                    --color;
//                    bool colorNotFound = FALSE;
//                    for (uint8_t i = 0; i < 4; i++) {
//                        if (color == colors[i]) {
//                            colorNotFound = TRUE;
//                        }
//                    }
//                    if (!colorNotFound) {
//                        colors[select] = color;
//                        break;
//                    }
//                } while (color > 0);
//                switch (select) {
//                case 0: colorGame.map = colors[0]; m_animation.setAnimationMapColor(colorGame.map);  m_animation.printBackground(); Sleep(100); break;
//                case 1: colorGame.wall =  colors[1]; m_animation.setAnimationWallColor(colorGame.wall); m_animation.printBackground(); Sleep(100);  break;
//                case 2: colorGame.food = colors[2]; m_animation.setAnimationFoodColor(colorGame.food);  break;
//                case 3: colorGame.snake = colors[3]; m_animation.setAnimationSnakeColor(colorGame.snake);  break;
//                }
//            }
//            Sleep(50);
//        }
//        else if (GetAsyncKeyState(VK_RIGHT)) {
//            if (colors[select] < 15) {
//                WORD color = colors[select];
//
//                do {
//                    ++color;
//                    bool colorNotFound = FALSE;
//                    for (uint8_t i = 0; i < 4; i++) {
//                        if (color == colors[i]) {
//                            colorNotFound = TRUE;
//                        }
//                    }
//                    if (!colorNotFound) {
//                        colors[select] = color;
//                        break;
//                    }
//                } while (color < 15);
//
//                switch (select) {
//                case 0: colorGame.map = colors[0]; m_animation.setAnimationMapColor(colorGame.map);  m_animation.printBackground(); Sleep(100); break;
//                case 1: colorGame.wall = colors[1]; m_animation.setAnimationWallColor(colorGame.wall); m_animation.printBackground(); Sleep(100);  break;
//                case 2: colorGame.food = colors[2]; m_animation.setAnimationFoodColor(colorGame.food);  break;
//                case 3: colorGame.snake = colors[3]; m_animation.setAnimationSnakeColor(colorGame.snake);  break;
//                }
//            }
//            Sleep(50);
//        }
//        else if (GetAsyncKeyState(VK_RETURN) && select == 4) {
//            bVal = TRUE;
//        }
//        Sleep(100);
//    }
//}
//
//void Game::gameSetupContext() {
//
//}
//
//void Game::snakeGame() {
//    COORD originPosition = { 
//        (SHORT)(CONSOLE_HEIGHT - Length::map) / 2,
//        (SHORT)(CONSOLE_LENGTH - Length::map * 2) / 2 };
//    m_map.build(originPosition);
//    m_map.printGraphic();
//    COORD position = { 2, 3 };
//    m_gameInfo.printPointsMessage(position);
//    COORD randomPoint = m_map.randomPosition();
//    m_food.setPosition(m_map.getBlock(randomPoint.X, randomPoint.Y).getLeft(), m_map.getBlock(randomPoint.X, randomPoint.Y).getRight(), randomPoint);
//    m_snake = Snake(m_map.getCenterOfMap());
//    m_map.updateObject(m_snake.getSnake());
//    m_map.printGraphicObject(m_snake.getSnake());
//    m_map.updateObject(m_food.getFood());
//    m_map.printGraphicObject(m_food.getFood());
//    bool bVal = FALSE;
//    while (TRUE) {
//        m_map.deleteGraphicObject(m_snake.getSnake());
//        m_map.printGraphicObject(m_snake.getSnake());
//        m_snake.updatePosition(m_snake.arrowKeyPress());
//        if (m_map.updateObject(m_snake.getSnake()) && !m_snake.hitBodyElement()) {
//            m_map.printGraphicObject(m_snake.getSnake());
//            if (m_snake.getSnake()[0].getPosition().X == m_food.getBlock().getPosition().X && 
//                m_snake.getSnake()[0].getPosition().Y == m_food.getBlock().getPosition().Y ) {
//                COORD position = { 2, 3 };
//                m_gameInfo.increasePoints();
//                m_gameInfo.printPoints();
//                m_snake.insertBodyElement(m_snake.getBlockTemplate(m_map.getBlock(randomPoint.X, randomPoint.Y).getLeft(), m_map.getBlock(randomPoint.X, randomPoint.Y).getRight(), randomPoint));
//                COORD randomPoint = m_map.randomPosition();
//                m_map.deleteGraphicObject(m_food.getFood());
//                m_food.setPosition(m_map.getBlock(randomPoint.X, randomPoint.Y).getLeft(), m_map.getBlock(randomPoint.X, randomPoint.Y).getRight(), randomPoint);
//                m_map.updateObject(m_food.getFood());
//                m_map.printGraphicObject(m_food.getFood());
//            }
//        }
//        else {
//            COORD position = { CONSOLE_LENGTH / 2 - 8, 3 };
//            while (!GetAsyncKeyState(VK_RETURN)) {
//                m_gameInfo.gameOverMessage(position);
//            }
//            m_gameInfo.resetScore();
//            break;
//        }
//        Sleep(SPEED);
//    }
//}
//
//void Game::consoleSettings() {
//    SetConsoleFontSize();
//    SetConsoleWindowSize(CONSOLE_LENGTH, CONSOLE_HEIGHT);
//    DisableMaximizeButton();
//    DisableResize();
//    ConsoleTitle();
//    Show_Cursor(FALSE);
//}
//
//void Game::stopAnimation() {
//    m_animation.stopAnimation();
//    if (m_thread[0].joinable()) {
//        m_thread[0].join();
//    }
//}
//
//COORD Game::operator=(COORD coord) {
//    COORD position;
//    position.X = coord.X;
//    position.Y = coord.Y;
//    return position;
//}
