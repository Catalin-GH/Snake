#include "Game.h"

Game::Game(void)
{
    ConsoleSettings();
    int length = 20;
    COORD OriginPosition = { (SHORT)(CONSOLE_HEIGHT - length) / 2 , (SHORT)(CONSOLE_LENGTH - length * 2) / 2 };
    _map = new Map(length, OriginPosition);
    _food = new Food();
    _gameInfos = new Infos();
    Logo.InitialSetup();
}

Game::~Game(void)
{
    Logo.ReleaseMemoryLogoMatrix();
    delete _map;
    delete _snake;
    delete _food;
    delete _gameInfos;
}

void Game::MainStart(void)
{
    COORD Position = { 5, 15 };

    Logo.AllocateMemory();
    Sleep(50);
    Logo.InitLogo(Position);
    Logo.printLogo();
    thread[0] = std::thread(&AnimatedLogo::Animation, Logo);

    /*place options in the center of the console*/
    Position = { CONSOLE_LENGTH / 2 - (SHORT)_gameInfos->GetMain(0).size() / 2, CONSOLE_HEIGHT / 2 - (SHORT)_gameInfos->GetMain(0).size() / 2 };
    Main(Position);
}

void Game::Main(COORD Position)
{
    size_t select = 0;
    _gameInfos->MainBlockInit(Position);
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
                _gameInfos->MainElement(Position, COLOR_MAIN, previousSelected);
                ++select;
                _gameInfos->MainElement(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            previousSelected = select;
            if (select > 0)
            {
                _gameInfos->MainElement(Position, COLOR_MAIN, previousSelected);
                --select;
                _gameInfos->MainElement(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            switch (select)
            {
            case START_GAME:
            {
                Logo.SetStopAnimation(TRUE);
                while (Logo.VerifyAnimation()) {}
                thread[0].detach();
                Logo.ReleaseMemory();
                Sleep(50);
                cls();

                SnakeGame();
                cls();
                Logo.SetStopAnimation(FALSE);

                COORD PositionLogo = { 5, 15 };
                Logo.AllocateMemory();
                Sleep(50);
                Logo.InitLogo(PositionLogo);
                Logo.printLogo();
                thread[0] = std::thread(&AnimatedLogo::Animation, Logo);

                select = 0;
                _gameInfos->MainBlockInit(Position);
            }break;
            case SETTINGS:
            {
                MainOptions();
                cls();
                Logo.printLogo();
                select = 0;
                _gameInfos->MainBlockInit(Position);
            }break;
            case EXIT:
            {
                cls();
                MainExit();
                select = 0;
                bVal = TRUE;
            }break;
            }
        }
        Sleep(200);
    }
}

void Game::MainOptions(void)
{
    /*place options in the center of the console*/
    COORD Position = { CONSOLE_LENGTH / 2 - (SHORT)_gameInfos->GetOptions(0).size() / 2, CONSOLE_HEIGHT / 2 - 5 };

    /*print options*/
    _gameInfos->OptionsBlockInit(Position);

    /*arrow is pressed*/
    size_t select = 0;
    std::vector<size_t> Colors = { COLOR_MAP, COLOR_WALL, COLOR_FOOD, COLOR_SNAKE };
    bool bVal = FALSE;
    while (!bVal)
    {
        Show_Cursor(FALSE);
        size_t previousSelected;
        if (GetAsyncKeyState(VK_DOWN))
        {
            previousSelected = select;
            if (select < 4)
            {
                _gameInfos->OptionElement(Position, COLOR_MAIN, previousSelected);
                ++select;
                _gameInfos->OptionElement(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            previousSelected = select;
            if (select > 0)
            {
                _gameInfos->OptionElement(Position, COLOR_MAIN, previousSelected);
                --select;
                _gameInfos->OptionElement(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (Colors[select] > 0)
            {
                size_t Color = Colors[select];
                do
                {
                    --Color;
                    bool bVal = FALSE;
                    for (size_t i = 0; i < 4; i++)
                    {
                        if (Color == Colors[i])
                        {
                            bVal = TRUE;
                        }
                    }
                    if (!bVal)
                    {
                        Colors[select] = Color;
                        break;
                    }
                } while (Color > 0);
                switch (select)
                {
                case 0: COLOR_MAP = Colors[0]; Logo.printLogo(); break;
                case 1: COLOR_WALL = Colors[1]; Logo.printLogo(); break;
                case 2: COLOR_FOOD = Colors[2]; break;
                case 3: COLOR_SNAKE = Colors[3]; break;
                }
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (Colors[select] < 15)
            {
                size_t Color = Colors[select];
                do
                {
                    ++Color;
                    bool bVal = FALSE;
                    for (size_t i = 0; i < 4; i++)
                    {
                        if (Color == Colors[i])
                        {
                            bVal = TRUE;
                        }
                    }
                    if (!bVal)
                    {
                        Colors[select] = Color;
                        break;
                    }
                } while (Color < 15);
                switch (select)
                {
                case 0: COLOR_MAP = Colors[0]; Logo.printLogo(); break;
                case 1: COLOR_WALL = Colors[1]; Logo.printLogo(); break;
                case 2: COLOR_FOOD = Colors[2]; break;
                case 3: COLOR_SNAKE = Colors[3]; break;
                }
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_RETURN) && select == 4)
        {
            bVal = TRUE;
        }
        Sleep(100);
    }
}

void Game::SnakeGame(void)
{
    _map->Build();
    _map->PrintGraphic();
    COORD Position = { 2, 3 };
    _gameInfos->PrintPointsInConsole(Position);
    COORD RandPoint = _map->RandomPosition();
    _food->SetPosition(_map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), _map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint);
    _snake = new Snake(_map->GetCenterBlock());
    _map->UpdateObject(_snake->GetSnake());
    _map->PrintGraphicObject(_snake->GetSnake());
    _map->UpdateObject(_food->GetFood());
    _map->PrintGraphicObject(_food->GetFood());
    bool bVal = FALSE;
    while (TRUE)
    {
        _map->DeleteGraphicObject(_snake->GetSnake());
        _map->PrintGraphicObject(_snake->GetSnake());
        _snake->UpdatePosition(_snake->ArrowKeyPress());
        if (_map->UpdateObject(_snake->GetSnake()) && !_snake->HitBodyElement())
        {
            _map->PrintGraphicObject(_snake->GetSnake());
            if (_snake->GetSnake()[0].GetPosition() == _food->GetBlock().GetPosition())
            {
                COORD Position = { 2, 3 };
                _gameInfos->IncreasePoints();
                _gameInfos->PrintPointsInConsole(Position);

                _snake->InsertBodyElement(_snake->GetBlockTemplate(_map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), _map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint));
                COORD RandPoint = _map->RandomPosition();
                _map->DeleteGraphicObject(_food->GetFood());
                _food->SetPosition(_map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), _map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint);
                _map->UpdateObject(_food->GetFood());
                _map->PrintGraphicObject(_food->GetFood());
            }
        }
        else
        {
            COORD Position = { CONSOLE_LENGTH / 2 - 8, 3 };
            while (!GetAsyncKeyState(VK_RETURN))
            {
                _gameInfos->GameOverMessage(Position);
            }
            _gameInfos->ResetScore();
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
    ConsoleTitle("Snake Game");
}

void Game::MainExit()
{
    Logo.SetStopAnimation(TRUE);
    while (Logo.VerifyAnimation()) {}
    thread[0].detach();
    Logo.ReleaseMemory();
}

COORD Game::operator=(COORD NewPosition)
{
    COORD Position;
    Position.X = NewPosition.X;
    Position.Y = NewPosition.Y;
    return Position;
}
