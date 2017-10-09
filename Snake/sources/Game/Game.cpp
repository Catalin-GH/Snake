#include "Game.h"

Game::Game(void)
{
    SetConsoleFontSize();
    SetConsoleWindowSize(CONSOLE_LENGTH, CONSOLE_HEIGHT);
    //DisableMaximizeButton();
    //DisableResize();
    OptionsName[0] = "START";
    OptionsName[1] = "OPTIONS";
    OptionsName[2] = "EXIT";
    int length = 20;
    COORD OriginPosition = { (CONSOLE_HEIGHT - length ) / 2 , (CONSOLE_LENGTH - length * 2) / 2 };
    map = new Map(length, OriginPosition);
    food = new Food();
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

void Game::Start(void)
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
                /*
                anything else to write
                */
                cls();
                select = 0;
                MainBlockInit(Position);
            }break;
            case SETTINGS:
            {
                cls();
                Options();
                cls();
                select = 0;
                MainBlockInit(Position);
            }break;
            case EXIT: 
            {
                cls();
                Exit();
                select = 0;
                bVal = TRUE;
            }break;
            }
        }
        Sleep(200);
    }
}

void Game::Options()
{
    size_t ColorValues[5];
    /*Name the options*/
    std::string Options[6];
    Options[0] = "<-    Map    ->";
    Options[1] = "<-    Wall    ->";
    Options[2] = "<-    Food    ->";
    Options[3] = "<-    Snake   ->";
    Options[4] = "<- Head snake ->";
    Options[5] = "      Back      ";

    COORD PositionBlock = { CONSOLE_HEIGHT / 2 - 5, CONSOLE_LENGTH / 2 + 15 };
    /* set-up block elements */
    Block demoBlock[5];
    demoBlock[0].SetColor(COLOR_MAP);
    demoBlock[1].SetColor(COLOR_WALL);
    demoBlock[2].SetColor(COLOR_FOOD);
    demoBlock[3].SetColor(COLOR_SNAKE);
    demoBlock[4].SetColor(COLOR_SNAKE_HEAD);
    for(size_t i = 0; i < 5; i++)
    {
        COORD left = {PositionBlock.X + i * 2, PositionBlock.Y };
        COORD right = {PositionBlock.X + i * 2, PositionBlock.Y + 1};
        demoBlock[i].SetCoord(left, right);
        demoBlock[i].SetFormat(FORMAT);

        ColorValues[i] = demoBlock[i].GetColor();
    }

    /* print blocks in console*/
    for(size_t i = 0; i < 5; i++)
    {
        size_t lx = demoBlock[i].GetLeft().X;
        size_t ly = demoBlock[i].GetLeft().Y;
        size_t rx = demoBlock[i].GetRight().X;
        size_t ry = demoBlock[i].GetRight().Y;
        gotoxy(ly, lx);             //(col, row)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)demoBlock[i].GetColor());
        std::cout << (uint8_t)demoBlock[i].GetFormat();
        gotoxy(ry, rx);             //(col, row)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)demoBlock[i].GetColor());
        std::cout << (uint8_t)demoBlock[i].GetFormat();
    }

    COORD Position = {CONSOLE_LENGTH / 2 - 10, CONSOLE_HEIGHT / 2 - 5};
    /*print opstions in console*/
    gotoxy(Position.X, Position.Y);
    SetTextColor(COLOR_MAIN_SELECT);
    std::cout << Options[0];
    for(size_t i = 1; i < 6; i++)
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
        else if(GetAsyncKeyState(VK_LEFT))
        {
            if(Color > 0)
            {
                --Color;
                size_t lx = demoBlock[select].GetLeft().X;
                size_t ly = demoBlock[select].GetLeft().Y;
                size_t rx = demoBlock[select].GetRight().X;
                size_t ry = demoBlock[select].GetRight().Y;
                gotoxy(ly, lx);             //(col, row)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)Color);
                std::cout << (uint8_t)demoBlock[select].GetFormat();
                gotoxy(ry, rx);             //(col, row)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)Color);
                std::cout << (uint8_t)demoBlock[select].GetFormat();
            }
            Sleep(100);
        }
        else if(GetAsyncKeyState(VK_RIGHT))
        {
            if(Color < 15)
            {
                ++Color;
                size_t lx = demoBlock[select].GetLeft().X;
                size_t ly = demoBlock[select].GetLeft().Y;
                size_t rx = demoBlock[select].GetRight().X;
                size_t ry = demoBlock[select].GetRight().Y;
                gotoxy(ly, lx);             //(col, row)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)Color);
                std::cout << (uint8_t)demoBlock[select].GetFormat();
                gotoxy(ry, rx);             //(col, row)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)Color);
                std::cout << (uint8_t)demoBlock[select].GetFormat();
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
    map->Build();
    map->Graphic();
    COORD RandPoint = map->RandomPosition();
    food->SetPosition(map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint);
    snake = new Snake(map->GetCenterBlock());
    map->UpdateObject(snake->GetSnake());
    map->GraphicObject(snake->GetSnake());
    map->UpdateObject(food->GetFood());
    map->GraphicObject(food->GetFood());
    while (TRUE)
    {
        map->DeleteObject(snake->GetSnake());
        map->GraphicObject(snake->GetSnake());
        snake->UpdatePosition(snake->ArrowKeyPress());
        if (map->UpdateObject(snake->GetSnake()) && !snake->HitBodyElement())
        {
            map->GraphicObject(snake->GetSnake());
            if (snake->GetSnake()[0].GetPosition() == food->GetBlock().GetPosition())
            {
                snake->InsertBodyElement(snake->GetBlockTemplate(map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint));
                COORD RandPoint = map->RandomPosition();
                map->DeleteObject(food->GetFood());
                food->SetPosition(map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint);
                map->UpdateObject(food->GetFood());
                map->GraphicObject(food->GetFood());
            }
        }
        else
        {
            /*gotoxy(0, 0);
            std::cout << "Game over!";
            system("pause");*/
            break;
        }
        Sleep(SPEED);
    }
}

void Game::Exit(void)
{

}

COORD Game::operator=(COORD NewPosition)
{
    COORD Position;
    Position.X = NewPosition.X;
    Position.Y = NewPosition.Y;
    return Position;
}
