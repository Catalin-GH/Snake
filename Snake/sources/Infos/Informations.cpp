#include "Informations.h"

Infos::Infos()
{
    _gainedPoints = 0;

    /*Main*/
    _main[0] = "START  ";
    _main[1] = "OPTIONS";
    _main[2] = "EXIT   ";

    /*Options*/
    _options[0] = "<-    Map     ->";
    _options[1] = "<-    Wall    ->";
    _options[2] = "<-    Food    ->";
    _options[3] = "<-    Snake   ->";
    _options[4] = "<- Head snake ->";
    _options[5] = "      Back      ";
}

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

void Infos::MainElement(COORD Position, size_t Color, size_t iter)
{
    gotoxy(Position.X, Position.Y + iter * 2);
    SetTextColor((WORD)Color);
    std::cout << _main[iter];
}

void Infos::OptionElement(COORD Position, size_t Color, size_t iter)
{
    gotoxy(Position.X, Position.Y + iter * 2);
    SetTextColor((WORD)Color);
    std::cout << _options[iter];
}

void Infos::MainBlockInit(COORD Position)
{
    MainElement(Position, COLOR_MAIN_SELECT, 0);
    MainElement(Position, COLOR_MAIN, 1);
    MainElement(Position, COLOR_MAIN, 2);
}

void Infos::OptionsBlockInit(COORD Position)
{
    OptionElement(Position, COLOR_MAIN_SELECT, 0);
    for (size_t i = 1; i < 6; i++)
    {
        OptionElement(Position, COLOR_MAIN, i);
    }
}

