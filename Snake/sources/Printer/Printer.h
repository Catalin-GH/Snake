#ifndef __PRINTER_H__
#define __PRINTER_H__

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

    static void printString(Coordonates2D, uint8_t, const std::string&);
    static void printFormat();
    static void printI(Coordonates2D, uint8_t, size_t);
    static void endLine();
    static void printBlock(const SquareBlock &);
};

#endif // !__PRINTER_H__
