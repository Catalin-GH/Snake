#pragma once

#include <iostream>
#include <mutex>

#include "Console_Functions.h"
#include "Block.h"

extern HANDLE console;

class Printer {
private:
    std::mutex m_mutex_cout;

public:
    void printC(COORD, size_t, const char *);
    void printF(size_t);
    void printI(COORD, size_t, size_t);
    void endLine();
    void printBlock(Block);
};
