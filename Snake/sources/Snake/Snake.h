#pragma once

#include "Object.h"

extern size_t COLOR_SNAKE;

class Snake : public Object
{
public:
    Snake() {}
    Snake(const Block &);

    inline std::vector<Block> getSnake() const {return m_object;}
    inline size_t getLength() const {return m_object.size();}
    void build(const Block &);
    Block getBlockTemplate(COORD, COORD, COORD);
    bool hitBodyElement(void);
    void insertBodyElement(const Block &);
    void updatePosition(COORD);
    COORD arrowKeyPress();

    COORD operator=(const COORD &);
    friend bool operator==(const COORD &, const COORD &);
    friend bool operator!=(const COORD &, const COORD &);
};
