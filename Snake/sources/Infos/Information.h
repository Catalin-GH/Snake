#pragma once

#include <iostream>
#include <string>
#include "Functions.h"
#include "Console_Functions.h"
#include "Functions.h"

class Info
{
private:
    std::string m_main[3];
    std::string m_options[5];
    size_t m_gainedPoints;
public:
    Info();
    inline std::string GetOptions(size_t iter) const { return m_options[iter]; }
    inline std::string GetMain(size_t iter) const { return m_main[iter]; }
    inline size_t GetGainedPoints() const { return m_gainedPoints; }
    inline void ResetScore(void) { m_gainedPoints = 0; }
    void PrintPointsInConsole(const COORD &);
    void GameOverMessage(const COORD &);
    void IncreasePoints();
    void MainElement(COORD, size_t, size_t);
    void OptionElement(COORD, size_t, size_t);
    void MainBlockInit(COORD);
    void OptionsBlockInit(COORD);
};
