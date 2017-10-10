#include "Game.h"

Game::Game(void)
{
    ConsoleSettings();
    OptionsName[0] = "START";
    OptionsName[1] = "OPTIONS";
    OptionsName[2] = "EXIT";
    int length = 20;
    COORD OriginPosition = { (CONSOLE_HEIGHT - length) / 2 , (CONSOLE_LENGTH - length * 2) / 2 };
    _map = new Map(length, OriginPosition);
    _food = new Food();
    _gameInfos = new Infos();
}

Game::~Game(void)
{
    delete _map;
    delete _snake;
    delete _food;
    delete _gameInfos;
}

void Game::MainBlock(COORD Position, size_t Color, size_t iter)
{
    gotoxy(Position.X, Position.Y + iter * 2);
    SetTextColor((WORD)Color);
    std::cout << OptionsName[iter];
}

void Game::MainBlockInit(COORD Position)
{
    MainBlock(Position, COLOR_MAIN_SELECT, 0);
    MainBlock(Position, COLOR_MAIN, 1);
    MainBlock(Position, COLOR_MAIN, 2);
}

void Game::MainStart(void)
{
    COORD Position = { CONSOLE_LENGTH / 2 - OptionsName[0].size() , 15 };
    Main(Position);
}

void Game::Main(COORD Position)
{
    size_t select = 0;
    MainBlockInit(Position);
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
                MainBlock(Position, COLOR_MAIN, previousSelected);
                ++select;
                MainBlock(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            previousSelected = select;
            if (select > 0)
            {
                MainBlock(Position, COLOR_MAIN, previousSelected);
                --select;
                MainBlock(Position, COLOR_MAIN_SELECT, select);
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            switch (select)
            {
            case START_GAME:
            {
                cls();
                SnakeGame();
                cls();
                select = 0;
                MainBlockInit(Position);
            }break;
            case SETTINGS:
            {
                cls();
                MainOptions();
                cls();
                select = 0;
                MainBlockInit(Position);
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

void Game::MainOptions()
{
    /*Name the options*/
    Options[0] = "<-    Map    ->";
    Options[1] = "<-    Wall    ->";
    Options[2] = "<-    Food    ->";
    Options[3] = "<-    Snake   ->";
    Options[4] = "<- Head snake ->";
    Options[5] = "      Back      ";

    COORD PositionBlock = { CONSOLE_HEIGHT / 2 - 5, CONSOLE_LENGTH / 2 + 15 };

    /* set-up block elements */
    size_t ColorValues[5];
    Block demoBlock[5];
    demoBlock[0].SetColor(COLOR_MAP);
    demoBlock[1].SetColor(COLOR_WALL);
    demoBlock[2].SetColor(COLOR_FOOD);
    demoBlock[3].SetColor(COLOR_SNAKE);
    demoBlock[4].SetColor(COLOR_SNAKE_HEAD);
    for (size_t i = 0; i < 5; i++)
    {
        COORD left = { PositionBlock.X + i * 2, PositionBlock.Y };
        COORD right = { PositionBlock.X + i * 2, PositionBlock.Y + 1 };
        demoBlock[i].SetCoord(left, right);
        demoBlock[i].SetFormat(FORMAT);

        ColorValues[i] = demoBlock[i].GetColor();
    }

    /* print blocks in console*/
    for (size_t i = 0; i < 5; i++)
    {
        Block::PrintBlock(demoBlock[i], (WORD)demoBlock[i].GetColor());
    }

    COORD Position = { CONSOLE_LENGTH / 2 - 10, CONSOLE_HEIGHT / 2 - 5 };

    /*print opstions in console*/
    gotoxy(Position.X, Position.Y);
    SetTextColor(COLOR_MAIN_SELECT);
    std::cout << Options[0];
    for (size_t i = 1; i < 6; i++)
    {
        gotoxy(Position.X, Position.Y + i * 2);
        SetTextColor(COLOR_MAIN);
        std::cout << Options[i];
    }

    size_t select = 0;
    size_t Color = demoBlock[select].GetColor();
    bool bVal = FALSE;
    while (!bVal)
    {
        Show_Cursor(FALSE);
        size_t previousSelected;
        if (GetAsyncKeyState(VK_DOWN))
        {
            previousSelected = select;
            if (select < 5)
            {
                gotoxy(Position.X, Position.Y + previousSelected * 2);
                SetTextColor(COLOR_MAIN);
                std::cout << Options[previousSelected];
                ++select;
                gotoxy(Position.X, Position.Y + select * 2);
                SetTextColor(COLOR_MAIN_SELECT);
                std::cout << Options[select];

                Color = demoBlock[select].GetColor();
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            previousSelected = select;
            if (select > 0)
            {
                gotoxy(Position.X, Position.Y + previousSelected * 2);
                SetTextColor(COLOR_MAIN);
                std::cout << Options[previousSelected];
                --select;
                gotoxy(Position.X, Position.Y + select * 2);
                SetTextColor(COLOR_MAIN_SELECT);
                std::cout << Options[select];

                Color = demoBlock[select].GetColor();
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (Color > 0)
            {
                --Color;
                Block::PrintBlock(demoBlock[select], (WORD)Color);
            }
            Sleep(100);
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (Color < 15)
            {
                ++Color;
                Block::PrintBlock(demoBlock[select], (WORD)Color);
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_RETURN) && select == 5)
        {
            bVal = TRUE;
        }
        switch (select)
        {
        case 0: COLOR_WALL = Color; break;
        case 1: COLOR_MAP = Color; break;
        case 2: COLOR_FOOD = Color; break;
        case 3: COLOR_SNAKE = Color; break;
        case 4: COLOR_SNAKE_HEAD = Color; break;
        }
        Sleep(200);
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
    SetConsoleTitle("Snake Game");
}

void Game::MainExit()
{

}

COORD Game::operator=(COORD NewPosition)
{
    COORD Position;
    Position.X = NewPosition.X;
    Position.Y = NewPosition.Y;
    return Position;
}
