#pragma once

#include "Console_Functions.h"
#include "Block.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Controls
{
private:
    COORD _newPosition;
public:
    Controls()
    {
        _newPosition.X = 0;
        _newPosition.Y = 0;
    }
    COORD Key_Press(const COORD &);
    inline COORD operator=(const COORD & New_Pos)
    {
        COORD Next_Pos;
        Next_Pos.X = New_Pos.X;
        Next_Pos.Y = New_Pos.Y;
        return Next_Pos;
    }
};

