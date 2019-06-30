#include "Utilities.hpp"

#include <chrono>
#include <stdlib.h>
#include <thread>

const uint16_t randNumber(const uint16_t lowerBound, const uint16_t upperBound)
{
    return rand() % upperBound + lowerBound;
}

void sleepThread(const uint16_t milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

const uint8_t countDigit(size_t number)
{
    if (number < 9)
    {
        return 1;
    }

    uint8_t digits = 0;
    while (0 != number)
    {
        number /= 10;
        ++digits;
    }

    return digits;
}