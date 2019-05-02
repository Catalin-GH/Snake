//#pragma once
//
//#include <array>
//#include "Printer.h"
//
//class Info
//{
//private:
//    std::array<std::string, 3> m_main;
//    std::array<std::string, 5> m_options;
//    std::string m_points_message;
//
//public:
//    Info();
//
//    std::string getOptionAt(uint8_t) const;
//    std::string getMainAt(uint8_t) const;
//    uint8_t getPoints() const;
//    void resetScore();
//    void increasePoints();
//    void printPointsMessage(COORD);
//    void printPoints();
//    void gameOverMessage(COORD);
//    void mainElement(COORD, uint8_t, uint8_t);
//    void optionElement(COORD, uint8_t, uint8_t);
//    void printMain(COORD);
//    void printOptions(COORD);
//};
//
//inline 
//std::string Info::getOptionAt(uint8_t iter) const 
//{ 
//    return m_options[iter];
//}
//
//inline 
//std::string Info::getMainAt(uint8_t iter) const 
//{ 
//    return m_main[iter]; 
//}
//
//inline 
//uint8_t Info::getPoints() const 
//{ 
//    return m_points; 
//}
//
//inline 
//void Info::resetScore() 
//{ 
//    m_points = 0;
//}
//
//inline 
//void Info::increasePoints()
//{ 
//    ++m_points; 
//};

#ifndef __MENU_ITEM_HPP__
#define __MENU_ITEM_HPP__

#include <array>
#include "Types.h"

static const uint8_t LABELS = 3;

class Menu
{
private:
    const Coordonates2D mPosition;
    const std::array<std::string, LABELS> mItems;

public:
    Menu(const Coordonates2D & position);
    ~Menu();
};

#endif // __MENU_ITEM_HPP__
