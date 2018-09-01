#include "Printer.h"

void Printer::printC(COORD coord, size_t color, const char * character) {
    std::lock_guard<std::mutex> lg(m_mutex_cout);
    gotoxy(coord.X, coord.Y);
    SetTextColor(color);
    std::cout << character;
}

void Printer::printF(const size_t format) {
    std::lock_guard<std::mutex> lg(m_mutex_cout);
    std::cout << (char)format;
}

void Printer::printI(COORD coord, size_t color, size_t integer) {
    std::lock_guard<std::mutex> lg(m_mutex_cout);
    gotoxy(coord.X, coord.Y);
    SetTextColor(color);
    std::cout << integer;
}

void Printer::endLine() {
    std::lock_guard<std::mutex> lg(m_mutex_cout);
    std::cout << std::endl;
}

void Printer::printBlock(Block block) {
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
