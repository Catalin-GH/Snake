#include "Game.h"

Game::Game(void)
{
    Show_Cursor(FALSE);
    COORD OriginPosition = { 5, 5 };
    int length = 20;
    map = new Map(length, OriginPosition);
    food = new Food();
}

void Game::TheMain(const COORD & Position)
{
    std::string OptionsName;
    //OptionsName = "START";
    //OptionsName[1] = "OPTIONS";
    // OptionsName[2] = "EXIT";
    SetTextColor(FOREGROUND_RED);
    gotoxy(Position.X, Position.Y);
    std::cout << " " << OptionsName;
    // gotoxy(Position.X, Position.Y + 1);
    //std::cout << OptionsName[1];
    // gotoxy(Position.X, Position.Y + 2);
    // std::cout << " " << OptionsName[2];
}

void Game::GameStart(void)
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
    while(TRUE)
    {
        map->DeleteObject(snake->GetSnake());
        map->GraphicObject(snake->GetSnake());
        snake->UpdatePosition(con.Key_Press(snake->GetSnake()[0].GetPosition()));
        if(map->UpdateObject(snake->GetSnake()) && !snake->HitBodyElement())
        {
            map->GraphicObject(snake->GetSnake());
            if(snake->GetSnake()[0].GetPosition() == food->GetBlock().GetPosition())
            {
                snake->InsertBodyElement(snake->GetBlockTemplate(map->GetBlock(RandPoint.X, RandPoint.Y).GetLeft(), map->GetBlock(RandPoint.X, RandPoint.Y).GetRight(), RandPoint));
                map->DeleteObject(food->GetFood());
                COORD RandPoint = map->RandomPosition();
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
        Sleep(50);
    }
}

COORD Game::operator=(COORD NewPosition)
{
    COORD Position;
    Position.X = NewPosition.X;
    Position.Y = NewPosition.Y;
    return Position;
}
