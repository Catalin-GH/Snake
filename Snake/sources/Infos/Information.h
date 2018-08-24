#pragma once

#include <iostream>
#include <string>
#include "Functions.h"
#include "Console_Functions.h"
#include "Functions.h"

extern Printer printer;

class Info
{
private:
    std::string m_main[3];
    std::string m_options[5];
    std::string m_points_message;
    std::string m_game_over_message;
    size_t m_points;
    COORD m_points_coord;
public:
    Info();
    inline std::string GetOptions(size_t iter) const { return m_options[iter]; }
    inline std::string GetMain(size_t iter) const { return m_main[iter]; }
    inline size_t GetGainedPoints() const { return m_points; }
    inline void ResetScore(void) { m_points = 0; }
    void printPointsMessage(COORD);
    void printPoints();
    void GameOverMessage(COORD);
    void IncreasePoints();
    void mainElement(COORD, size_t, size_t);
    void optionElement(COORD, size_t, size_t);
    void MainBlockInit(COORD);
    void OptionsBlockInit(COORD);
};
