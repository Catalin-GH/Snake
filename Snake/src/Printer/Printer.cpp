#include "Console.hpp"
#include "SquareBlock.h"
#include "Printer.h"

/*
For more details about ASCII_VALUE:
https://theasciicode.com.ar/extended-ascii-code/block-graphic-character-ascii-code-219.html
*/
static const uint8_t ASCII_VALUE = 219;

std::mutex Printer::mCout;

void Printer::printString(const Coordonates2D coord, const uint8_t color, const std::string & strVal)
{
    std::lock_guard<std::mutex> lg(mCout);

    gotoxy(coord.x, coord.y);
    SetTextColor(color);
    std::cout << strVal.data();
}

void Printer::printFormat()
{
    std::lock_guard<std::mutex> lg(mCout);

    std::cout << static_cast<char>(ASCII_VALUE);
}

void Printer::printI(const Coordonates2D coord, const uint8_t color, const size_t value)
{
    std::lock_guard<std::mutex> lg(mCout);

    gotoxy(coord.x, coord.y);
    SetTextColor(color);
    std::cout << value;
}

void Printer::endLine()
{
    std::lock_guard<std::mutex> lg(mCout);

    std::cout << std::endl;
}

void Printer::printBlock(const SquareBlock & block)
{
    std::lock_guard<std::mutex> lg(mCout);

    Coordonates2D left = block.getLeft().getPosition();
    gotoxy(left.x, left.y);
    SetTextColor(block.getColor());
    std::cout << ASCII_VALUE;

    Coordonates2D right = block.getRight().getPosition();
    gotoxy(right.x, right.y);
    SetTextColor(block.getColor());
    std::cout << ASCII_VALUE;
}

void Printer::wipeChar(const Coordonates2D position, const uint8_t color)
{
    std::lock_guard<std::mutex> lg(mCout);
    gotoxy(position.x, position.y);
    SetTextColor(color);
    std::cout << ASCII_VALUE;
}
