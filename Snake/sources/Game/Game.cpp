#include "Game.h"

Game::Game(void)
{
    Show_Cursor(FALSE);
    COORD OriginPosition = { 5, 5 };
    int length = 20;
    map = new Map(length, OriginPosition);
    food = new Food();
}

void Game::Start(void)
{
    COORD MainPosition = { 10, 10 };
    /*size_t OptionSelected = */Main(MainPosition);
    /*switch (OptionSelected)
    {
    case 0:
        {
        SnakeGame();
        }break;
    case 1:
        {
        Options();
        }break;
    case 2:
        {
        Exit();
        }
    }*/
}

void Game::Main(const COORD & Position)
{
    size_t select = 0;
    std::string OptionsName[3];
    OptionsName[0] = "START";
    OptionsName[1] = "OPTIONS";
    OptionsName[2] = "EXIT";

    gotoxy(Position.X, Position.Y);
    SetTextColor(COLOR_MAIN_SELECT);
    std::cout << " " << OptionsName[0];
    for (size_t i = 1; i < 3; i++)
    {
        gotoxy(Position.X, Position.Y + i * 2);
        SetTextColor(COLOR_MAIN);
        std::cout << " " << OptionsName[i];
    }

    bool bval = FALSE;
    while (!bval)
    {
        size_t previousSelected;
        if (GetAsyncKeyState(VK_DOWN))
        {
            previousSelected = select;
            if (select < 2)
            {
                gotoxy(Position.X, Position.Y + previousSelected * 2);
                SetTextColor(COLOR_MAIN);
                std::cout << " " << OptionsName[previousSelected];
                ++select;
                gotoxy(Position.X, Position.Y + select * 2);
                SetTextColor(COLOR_MAIN_SELECT);
                std::cout << " " << OptionsName[select];
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
                std::cout << " " << OptionsName[previousSelected];
                --select;
                gotoxy(Position.X, Position.Y + select * 2);
                SetTextColor(COLOR_MAIN_SELECT);
                std::cout << " " << OptionsName[select];
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            switch (select)
            {
            case 0: 
            {
                SnakeGame();
                bval = TRUE;
            }break;
            case 1:
            {
                Options();
                bval = TRUE;
            }break;
            case 2: 
            {
                Exit();
                bval = TRUE;
            }break;
            }
        }
        Sleep(300);
    }
}

void Game::Options(void)
{

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
        snake->UpdatePosition(con.Key_Press(snake->GetSnake()[0].GetPosition()));
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
        Sleep(100);
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
