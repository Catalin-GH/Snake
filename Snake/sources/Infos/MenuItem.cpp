//#include "Information.h"
//#include "Types.h"
//
//Info::Info() :
//    m_points(0),
//    m_points_message { "Points:" },
//    m_game_over_message { "The game is over!" },
//    m_main { "START  ", "OPTIONS", "EXIT   " },
//    m_options { "<-    Map     ->", "<-    Wall    ->",
//                "<-    Food    ->", "<-    Snake   ->", 
//                "      Back      " }
//{}
//
//void Info::printPointsMessage(COORD position) {
//    uint8_t offset = 1;
//    m_points_coord = position;
//    m_points_coord.X += static_cast<uint8_t>(m_points_message.length()) + offset;
//    Printer::printC(position, Color::info, m_points_message.c_str());
//    printPoints();
//}
//
//void Info::printPoints() {
//    Printer::printI(m_points_coord, Color::info_point, m_points);
//}
//
//void Info::gameOverMessage(COORD position) {
//    Printer::printC(position, Color::game_over, m_game_over_message.c_str());
//}
//
//void Info::mainElement(COORD position, uint8_t color, uint8_t iter) {
//    Printer::printC({ position.X, position.Y + iter * 2 }, color, m_main[iter].c_str());
//}
//
//void Info::optionElement(COORD position, uint8_t color, uint8_t iter) {
//    Printer::printC({ position.X, position.Y + iter * 2 }, color, m_options[iter].c_str());
//}
//
//void Info::printMain(COORD position) {
//    mainElement(position, Color::main_select, 0);
//    mainElement(position, Color::main, 1);
//    mainElement(position, Color::main, 2);
//}
//
//void Info::printOptions(COORD position) {
//    optionElement(position, Color::main_select, 0);
//    optionElement(position, Color::main, 1);
//    optionElement(position, Color::main, 2);
//    optionElement(position, Color::main, 3);
//    optionElement(position, Color::main, 4);
//}

#include "MenuItem.hpp"

static const uint8_t COLOR_ITEM_NOT_SELECTED = 14;
static const uint8_t COLOR_ITEM_SELECTED = 12;

Menu::Menu(const Coordonates2D & position)
    : mPosition(position)
{
}

Menu::~Menu()
{
}
