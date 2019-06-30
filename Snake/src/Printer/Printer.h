#ifndef __PRINTER_H__
#define __PRINTER_H__

#include "Types.h"

#include <mutex>

class SquareBlock;

class Printer
{
private:
    static std::mutex mCout;

public:
    Printer() = delete;
    Printer(const Printer &) = delete;
    Printer(Printer &&) = delete;
    Printer& operator=(const Printer &) = delete;

    static void printString(const Coordonates2D, const uint8_t, const std::string &);
    static void printFormat();
    static void printI(const Coordonates2D, const uint8_t, const size_t);
    static void endLine();
    static void printBlock(const SquareBlock &);
    static void wipeChar(const Coordonates2D, const uint8_t color = BLACK_COLOR);
};

#endif // !__PRINTER_H__
