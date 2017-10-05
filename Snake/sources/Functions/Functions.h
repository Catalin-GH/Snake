#pragma once

#include <Windows.h>

//#define COLOR_WALL 7
//#define COLOR_MAP 8
//#define COLOR_FOOD 11
#define COLOR_MAIN 14
#define COLOR_MAIN_SELECT 12
//#define COLOR_SNAKE 9
//#define COLOR_SNAKE_HEAD 10

#define FORMAT 219

#define IS_MAP     0
#define IS_WALL    1
#define IS_SNAKE   2
#define IS_FOOD    3

#define SNAKE_LENGTH 5

bool operator==(const COORD &, const COORD &);
bool operator!=(const COORD &, const COORD &);
void GetDesktopResolution(int &, int &);
