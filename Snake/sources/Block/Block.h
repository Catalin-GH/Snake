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
    size_t * m_color;
    COORD m_left;
    COORD m_right;
    COORD m_position;
public:
    Block();

    inline void SetFormat(size_t f) { m_format = f; }
    inline void SetValue(size_t v) { m_value = v; }
    inline void SetColor(size_t & c) { m_color = &c; }
    inline void SetLeft(COORD l) { m_left = l; }
    inline void SetRight(COORD r) { m_right = r; }
    inline void SetCoord(COORD l, COORD r) { m_left = l, m_right = r; }
    inline void SetPosition(COORD p) { m_position = p; }
    inline void SetBlock(const Block & b)
    {
        m_format = b.GetFormat();
        m_value = b.GetValue();
        *m_color = b.GetColor();
        m_left = b.GetLeft();
        m_right = b.GetRight();
        m_position = b.GetPosition();
    }

    inline size_t GetFormat() const { return m_format; }
    inline size_t GetValue() const { return m_value; }
    inline size_t GetColor() const { return *m_color; }
    inline COORD GetLeft() const { return m_left; }
    inline COORD GetRight() const { return m_right; }
    inline COORD GetPosition() const { return m_position; }
    inline Block GetBlock() const
    {
        Block block;
        block.SetFormat(this->m_format);
        block.SetValue(this->m_value);
        block.SetColor(*m_color);
        block.SetCoord(this->m_left, this->m_right);
        block.SetPosition(this->m_position);
        return block;
    }

    void ShowFormat(std::ostream&);
    void ShowValue(std::ostream&);
    void ShowColor(std::ostream&);
    void ShowLeft(std::ostream&);
    void ShowRight(std::ostream&);
    void ShowPosition(std::ostream&);

    static void PrintBlock(const Block &, WORD);

    inline COORD operator=(COORD);
    inline bool operator==(const Block &);
    inline friend bool operator==(const COORD &, const COORD &);
    inline friend bool operator!=(const COORD &, const COORD &);
};
