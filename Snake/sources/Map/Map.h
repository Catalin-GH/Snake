#pragma once

#include <cstdlib>
#include <fstream>
#include <time.h>

#include "Block.h"
#include "Console_Functions.h"
#include "Functions.h"
#include "Snake.h"

extern size_t COLOR_MAP;
extern size_t COLOR_SNAKE;
extern size_t COLOR_WALL;
extern size_t COLOR_FOOD;

class Map {
private:
    Block m_block[MAP_LENGTH][MAP_LENGTH];
    COORD m_originPosition;
public:
    Map() {}
    ~Map() {}

    Block getBlock(size_t, size_t) const;
    Block getCenterBlock() const;

    void build(COORD);
    bool updateObject(const std::vector<Block> &);
    void printGraphicObject(const std::vector<Block> &);
    void deleteGraphicObject(const std::vector<Block> &);
    void printGraphic(void);
    COORD randomPosition(void);

    void seeInfos(void);

    inline COORD operator=(COORD NewPosition) {
        COORD Position;
        Position.X = NewPosition.X;
        Position.Y = NewPosition.Y;
        return Position;
    }

    friend bool operator==(const COORD &, const COORD &);
};
