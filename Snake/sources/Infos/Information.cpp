#include "Information.h"

Info::Info()
{
    m_gainedPoints = 0;

    /*Main*/
    m_main[0] = "START  ";
    m_main[1] = "OPTIONS";
    m_main[2] = "EXIT   ";

    /*Options*/
    m_options[0] = "<-    Map     ->";
    m_options[1] = "<-    Wall    ->";
    m_options[2] = "<-    Food    ->";
    m_options[3] = "<-    Snake   ->";
    m_options[4] = "      Back      ";
}

void Info::PrintPointsInConsole(const COORD & StartPointForWriting)
{
    gotoxy(StartPointForWriting.X, StartPointForWriting.Y);
    SetTextColor(COLOR_INFO);
    std::cout << "Points: ";
    SetTextColor(COLOR_INFO_POINT);
    std::cout << std::to_string(m_gainedPoints);
}

void Info::GameOverMessage(const COORD & StartPointForWriting)
{
    gotoxy(StartPointForWriting.X, StartPointForWriting.Y);
    SetTextColor(COLOR_GAME_OVER);
    std::cout << "The game is over!";
}

void Info::IncreasePoints()
{
    ++m_gainedPoints;
}

void Info::MainElement(COORD Position, size_t Color, size_t iter)
{
    gotoxy(Position.X, Position.Y + iter * 2);
    SetTextColor((WORD)Color);
    std::cout << m_main[iter];
    Sleep(20);
}

void Info::OptionElement(COORD Position, size_t Color, size_t iter)
{
    gotoxy(Position.X, Position.Y + iter * 2);
    SetTextColor((WORD)Color);
    std::cout << m_options[iter];
    Sleep(20);
}

void Info::MainBlockInit(COORD Position)
{
    MainElement(Position, COLOR_MAIN_SELECT, 0);
    MainElement(Position, COLOR_MAIN, 1);
    MainElement(Position, COLOR_MAIN, 2);
}

void Info::OptionsBlockInit(COORD Position)
{
    OptionElement(Position, COLOR_MAIN_SELECT, 0);
    for (size_t i = 1; i < 5; i++)
    {
        OptionElement(Position, COLOR_MAIN, i);
    }
}

