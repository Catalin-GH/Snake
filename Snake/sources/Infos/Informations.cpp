#include "Informations.h"

void Infos::PrintPointsInConsole(const COORD & StartPointForWriting)
{
    gotoxy(StartPointForWriting.X, StartPointForWriting.Y);
    SetTextColor(COLOR_INFO);
    std::cout << "Points: ";
    SetTextColor(COLOR_INFO_POINT);
    std::cout << GetGainedPoints();
}

void Infos::GameOverMessage(const COORD & StartPointForWriting)
{
    gotoxy(StartPointForWriting.X, StartPointForWriting.Y);
    SetTextColor(COLOR_GAME_OVER);
    std::cout << "The game is over!";
}

void Infos::IncreasePoints()
{
    ++_gainedPoints;
}

