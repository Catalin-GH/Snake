#pragma once

#include <iostream>
#include "Console_Functions.h"

class Infos
{
private:
    int GainedPoints;
public:
    Infos() { GainedPoints = 0; }
    void PrintPointsInConsole(const COORD &);
    void GameOverMessage(const COORD &);
    void IncreasePoints();
    int GetGainedPoints() const { return GainedPoints; }

};