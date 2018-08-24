#include <Windows.h>

#include "Printer.h"

#define COLOR_MAIN 14
#define COLOR_MAIN_SELECT 12
#define COLOR_INFO_POINT 5
#define COLOR_INFO 15
#define COLOR_GAME_OVER 15
#define COLOR_LOGO 8

#define FORMAT 219

#define IS_MAP     0
#define IS_WALL    1
#define IS_FOOD    2
#define IS_SNAKE   3
#define IS_LOGO    4

#define SNAKE_LENGTH 5

#define MAP_LENGTH 20

bool operator==(const COORD &, const COORD &);
bool operator!=(const COORD &, const COORD &);
