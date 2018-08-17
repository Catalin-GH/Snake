#pragma once

#include <Windows.h>
#include <cstdint>
#include "Functions.h"
#include <iostream>
#include "Console_Functions.h"

extern HANDLE console;

class Block
{
private:
    size_t m_format;    //ascii value
    size_t m_value;     //clasification
    size_t m_color;
    COORD m_left;
    COORD m_right;
    COORD m_position;

public:
    Block();

    inline void setFormat(size_t f) { m_format = f; }
    inline void setValue(size_t v) { m_value = v; }
    inline void setColor(size_t c) { m_color = c; }
    inline void setLeft(COORD l) { m_left = l; }
    inline void setRight(COORD r) { m_right = r; }
    inline void setCoord(COORD l, COORD r) { m_left = l, m_right = r; }
    inline void setPosition(COORD p) { m_position = p; }
    inline void setBlock(const Block & b) {
        m_format = b.getFormat();
        m_value = b.getValue();
        m_color = b.getColor();
        m_left = b.getLeft();
        m_right = b.getRight();
        m_position = b.getPosition();
    }

    inline size_t getFormat() const { return m_format; }
    inline size_t getValue() const { return m_value; }
    inline size_t getColor() const { return m_color; }
    inline COORD getLeft() const { return m_left; }
    inline COORD getRight() const { return m_right; }
    inline COORD getPosition() const { return m_position; }

    void ShowFormat(std::ostream&);
    void ShowValue(std::ostream&);
    void ShowColor(std::ostream&);
    void ShowLeft(std::ostream&);
    void ShowRight(std::ostream&);
    void ShowPosition(std::ostream&);

    void printBlock();

    inline COORD operator=(COORD);
    inline bool operator==(const Block &);
    inline friend bool operator==(const COORD &, const COORD &);
    inline friend bool operator!=(const COORD &, const COORD &);
};
