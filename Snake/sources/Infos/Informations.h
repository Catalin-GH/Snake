#pragma once

#include <iostream>
#include <string>
#include "Functions.h"
#include "Console_Functions.h"
#include "Functions.h"

class Infos
{
private:
    std::string _main[3];
    std::string _options[5];
    size_t _gainedPoints;
public:
    Infos();
    inline std::string GetOptions(size_t iter) const { return _options[iter]; }
    inline std::string GetMain(size_t iter) const { return _main[iter]; }
    inline size_t GetGainedPoints() const { return _gainedPoints; }
    inline void ResetScore(void) { _gainedPoints = 0; }
    void PrintPointsInConsole(const COORD &);
    void GameOverMessage(const COORD &);
    void IncreasePoints();
    void MainElement(COORD, size_t, size_t);
    void OptionElement(COORD, size_t, size_t);
    void MainBlockInit(COORD);
    void OptionsBlockInit(COORD);
};
