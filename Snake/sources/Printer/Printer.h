#pragma once

#include <iostream>
#include <mutex>

#include "Console_Functions.h"
#include "Block.h"

extern HANDLE console;

class Printer {
public:
    std::mutex m_mutex_cout;

    void printC(COORD coord, size_t color, const char * character) {
        std::lock_guard<std::mutex> lg(m_mutex_cout);
        gotoxy(coord.X, coord.Y);
        SetTextColor(color);
        std::cout << character;
    }

    void printF(const size_t format) {
        std::lock_guard<std::mutex> lg(m_mutex_cout);
        std::cout << (char) format;
    }

    void printI(COORD coord, size_t color, const size_t integer) {
        std::lock_guard<std::mutex> lg(m_mutex_cout);
        gotoxy(coord.X, coord.Y);
        SetTextColor(color);
        std::cout << integer;
    }

    void endLine() {
        std::lock_guard<std::mutex> lg(m_mutex_cout);
        std::cout << std::endl;
    }

    void printBlock(Block block) {
        std::lock_guard<std::mutex> lg(m_mutex_cout);
        COORD left = block.getLeft();
        COORD right = block.getRight();
        gotoxy(left.Y, left.X);             //(col, row)
        SetConsoleTextAttribute(console, (WORD)block.getColor());
        std::cout << (char)block.getFormat();
        gotoxy(right.Y, right.X);             //(col, row)
        SetConsoleTextAttribute(console, (WORD)block.getColor());
        std::cout << (char)block.getFormat();
    }
};
