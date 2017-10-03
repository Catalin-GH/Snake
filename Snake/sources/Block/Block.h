#pragma once

#include <Windows.h>
#include <cstdint>
#include "Functions.h"
#include <iostream>

class Block
{
private:
    size_t _format;      //valoare ascii
    size_t _value;     //clasificare
    size_t _color;
    COORD _left;
    COORD _right;
    COORD _position;
public:
    Block();

    inline void SetFormat(size_t f) { _format = f; }
    inline void SetValue(size_t v) { _value = v; }
    inline void SetColor(size_t c) { _color = c; }
    inline void SetLeft(COORD l) { _left = l; }
    inline void SetRight(COORD r) { _right = r; }
    inline void SetCoord(COORD l, COORD r) { _left = l, _right = r; }
    inline void SetPosition(COORD p) { _position = p; }
    inline void SetBlock(const Block & b)
    {
        _format = b.GetFormat();
        _value = b.GetValue();
        _color = b.GetColor();
        _left = b.GetLeft();
        _right = b.GetRight();
        _position = b.GetPosition();
    }

    inline size_t GetFormat() const { return _format; }
    inline size_t GetValue() const { return _value; }
    inline size_t GetColor() const { return _color; }
    inline COORD GetLeft() const { return _left; }
    inline COORD GetRight() const { return _right; }
    inline COORD GetPosition() const { return _position; }
    inline Block GetBlock() const
    {
        Block block;
        block.SetFormat(this->_format);
        block.SetValue(this->_value);
        block.SetColor(this->_color);
        block.SetCoord(this->_left, this->_right);
        block.SetPosition(this->_position);
        return block;
    }

    void ShowFormat(std::ostream&);
    void ShowValue(std::ostream&);
    void ShowColor(std::ostream&);
    void ShowLeft(std::ostream&);
    void ShowRight(std::ostream&);
    void ShowPosition(std::ostream&);

    inline COORD operator=(COORD);
    inline friend bool operator==(const COORD &, const COORD &);
    inline bool operator==(const Block &);
    inline friend bool operator!=(const COORD &, const COORD &);
};
