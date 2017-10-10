#pragma once

#include <iostream>
#include "Functions.h"
#include "Console_Functions.h"

class Infos
{
private:
    size_t _gainedPoints;
public:
    Infos() { _gainedPoints = 0; }
    void PrintPointsInConsole(const COORD &);
    void GameOverMessage(const COORD &);
    void IncreasePoints();
    size_t GetGainedPoints() const { return _gainedPoints; }

};