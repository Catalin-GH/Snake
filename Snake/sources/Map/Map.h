#pragma once

#include "Console_Functions.h"
#include "Snake.h"
#include "Functions.h"
#include <fstream>
#include "Block.h"
#include <cstdlib>
#include <time.h>

extern size_t COLOR_MAP;
extern size_t COLOR_SNAKE;
extern size_t COLOR_SNAKE_HEAD;
extern size_t COLOR_WALL;
extern size_t COLOR_FOOD;

class Map
{
private:
    Block ** _block;
    size_t _rows;
    size_t _cols;
    COORD _originPosition;
public:
    Map(size_t, COORD);
    ~Map();

    size_t GetRows() const {return _rows;}
    size_t GetCols() const {return _cols;}
    Block GetBlock(size_t, size_t) const;
    Block GetCenterBlock() const;

    void Build(void);
    bool UpdateObject(const std::vector<Block> &);
    void PrintGraphicObject(const std::vector<Block> &);
    void DeleteGraphicObject(const std::vector<Block> &);
    void PrintGraphic(void);
    COORD RandomPosition(void);

    void SeeInfos(void);

    inline COORD operator=(COORD NewPosition)
    {
        COORD Position;
        Position.X = NewPosition.X;
        Position.Y = NewPosition.Y;
        return Position;
    }

    friend bool operator==(const COORD &, const COORD &);
};
