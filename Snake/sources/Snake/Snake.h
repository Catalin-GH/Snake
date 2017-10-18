#pragma once

#include "Object.h"

extern size_t COLOR_SNAKE;
extern size_t COLOR_SNAKE_HEAD;

class Snake : public Object
{
public:
    Snake() {}
    Snake(const Block &);
    inline std::vector<Block> GetSnake() const {return _object;}
    inline size_t GetLength() const {return _object.size();}
    void Build(const Block &);
    Block GetBlockTemplate(COORD, COORD, COORD);
    bool HitBodyElement(void);
    void InsertBodyElement(const Block &);
    void UpdatePosition(COORD);
    COORD ArrowKeyPress();

    COORD operator=(const COORD &);
    friend bool operator==(const COORD &, const COORD &);
    friend bool operator!=(const COORD &, const COORD &);
};
