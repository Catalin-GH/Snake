#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__

#include <cstdint>

void sleepThread(const uint16_t milliseconds);

const uint16_t randNumber(const uint16_t lowerBound, const uint16_t upperBound);

const uint8_t countDigit(const size_t number);

#endif //__UTILITIES_HPP__