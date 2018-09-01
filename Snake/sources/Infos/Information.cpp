#include "Information.h"

Info::Info() : 
    m_points(0),
    m_points_message { "Points:" },
    m_game_over_message { "The game is over!" },
    m_main { "START  ", "OPTIONS", "EXIT   " },
    m_options { "<-    Map     ->", "<-    Wall    ->",
                "<-    Food    ->", "<-    Snake   ->", 
                "      Back      " }
{}

void Info::printPointsMessage(COORD position) {
    uint8_t offset = 1;
    m_points_coord = position;
    m_points_coord.X += static_cast<uint8_t>(m_points_message.length()) + offset;
    printer.printC(position, COLOR_INFO, m_points_message.c_str());
    printPoints();
}

void Info::printPoints() {
    printer.printI(m_points_coord, COLOR_INFO_POINT, m_points);
}

void Info::GameOverMessage(COORD position)
{
    printer.printC(position, COLOR_GAME_OVER, m_game_over_message.c_str());
}

void Info::IncreasePoints()
{
    ++m_points;
}

void Info::mainElement(COORD position, size_t color, size_t iter)
{
    printer.printC( {position.X, position.Y + (SHORT)iter * 2}
        ,color
        ,m_main[iter].c_str());
}

void Info::optionElement(COORD position, size_t color, size_t iter)
{
    printer.printC({ position.X, position.Y + (SHORT)iter * 2 }
        ,color
        ,m_options[iter].c_str());
}

void Info::MainBlockInit(COORD position)
{
    mainElement(position, COLOR_MAIN_SELECT, 0);
    mainElement(position, COLOR_MAIN, 1);
    mainElement(position, COLOR_MAIN, 2);
}

void Info::OptionsBlockInit(COORD Position)
{
    optionElement(Position, COLOR_MAIN_SELECT, 0);
    for (size_t i = 1; i < 5; i++)
    {
        optionElement(Position, COLOR_MAIN, i);
    }
}

