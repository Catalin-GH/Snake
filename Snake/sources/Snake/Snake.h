#pragma once

#include "Console_Functions.h"
#include "Functions.h"
#include "Block.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>

class Snake
{
private:
    std::vector<Block> _snake;
public:
    Snake(const Block &);
    inline std::vector<Block> GetSnake() const {return _snake;}
    inline size_t GetLength() const {return _snake.size();}
    inline Block GetBlockTemplate(COORD left, COORD right, COORD position)
    {
        Block block;
        block.SetValue(FORMAT);
        block.SetColor(COLOR_SNAKE);
        block.SetFormat(IS_SNAKE);
        block.SetLeft(left);
        block.SetRight(right);
        block.SetPosition(position);

        return block;
    }

    bool HitBodyElement(void);
    void InsertBodyElement(const Block &);
    void UpdatePosition(COORD);

    void SeeInfos(void);

    inline COORD operator=(const COORD & New_Pos)
    {
        COORD Actual_Pos;
        Actual_Pos.X = New_Pos.X;
        Actual_Pos.Y = New_Pos.Y;
        return Actual_Pos;
    }
    friend bool operator==(const COORD &, const COORD &);
    friend bool operator!=(const COORD &, const COORD &);
};
