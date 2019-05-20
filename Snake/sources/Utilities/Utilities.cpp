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