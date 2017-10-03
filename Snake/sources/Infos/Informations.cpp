#include "Informations.h"

void Infos::PrintPointsInConsole(const COORD & StartPointForWriting)
{
    gotoxy(StartPointForWriting.X, StartPointForWriting.Y);
    std::cout << "Points: " << GetGainedPoints();
}

void Infos::GameOverMessage(const COORD & StartPointForWriting)
{
    gotoxy(StartPointForWriting.X, StartPointForWriting.Y);
    std::cout << "The game is over!";
}

void Infos::IncreasePoints()
{
    ++GainedPoints;
}

