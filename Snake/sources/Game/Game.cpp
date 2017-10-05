#include "Game.h"

Game::Game(void)
{
    OptionsName[0] = "START";
    OptionsName[1] = "OPTIONS";
    OptionsName[2] = "EXIT";
    COORD OriginPosition = { 5, 5 };
    int length = 20;
    map = new Map(length, OriginPosition);
    food = new Food();
}

void Game::MainBlock(COORD Position, size_t Color, size_t iter)
{
    gotoxy(Position.X, Position.Y + iter * 2);
    SetTextColor((WORD)Color);
    SetConsoleFontSize();
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
    SetConsoleSize(800, 600);
    COORD Position = { GetConsoleSize().X / 3, 10 };
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
    COORD Position = { 10 , GetConsoleSize().X / 2 + 10};
    Block demoBlock[5];
    demoBlock[0].SetColor(COLOR_MAP);
    demoBlock[1].SetColor(COLOR_WALL);
    demoBlock[2].SetColor(COLOR_FOOD);
    demoBlock[3].SetColor(COLOR_SNAKE);
    demoBlock[4].SetColor(COLOR_SNAKE_HEAD);
    for(size_t i = 0; i < 5; i++)
    {
        COORD left = {Position.X + i * 2, Position.Y };
        COORD right = {Position.X + i * 2, Position.Y + 1};
        demoBlock[i].SetCoord(left, right);
        demoBlock[i].SetFormat(FORMAT);
    }

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
