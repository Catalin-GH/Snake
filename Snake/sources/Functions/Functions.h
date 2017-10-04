#pragma once

#include <Windows.h>

#define FORMAT 219
#define COLOR_WALL 7
#define COLOR_MAP  8
#define IS_WALL    1
#define IS_MAP     0
#define SNAKE_LENGTH 5
#define COLOR_SNAKE 9
#define IS_SNAKE 2
#define IS_FOOD 3
#define COLOR_FOOD 11
#define COLOR_MAIN 14
#define COLOR_MAIN_SELECT 12

bool operator==(const COORD &, const COORD &);
bool operator!=(const COORD &, const COORD &);
void GetDesktopResolution(int &, int &);

