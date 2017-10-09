#pragma once

#include <iostream>
#include "Console_Functions.h"

class Infos
{
private:
    size_t GainedPoints;
public:
    Infos() { GainedPoints = 0; }
    void PrintPointsInConsole(const COORD &);
    void GameOverMessage(const COORD &);
    void IncreasePoints();
    size_t GetGainedPoints() const { return GainedPoints; }

};