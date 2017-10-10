#include "Functions.h"

size_t COLOR_WALL = 7;
size_t COLOR_MAP = 8;
size_t COLOR_FOOD = 11;
size_t COLOR_SNAKE = 9;
size_t COLOR_SNAKE_HEAD = 3;

bool operator==(const COORD & left, const COORD & right)
{
    bool bValue = FALSE;
    if ((left.X == right.X) && (left.Y == right.Y))
    {
        bValue = TRUE;
    }
    return bValue;
}

bool operator!=(const COORD & c1, const COORD & c2)
{
    bool bval = FALSE;
    if (c1.X != c2.X || c1.Y != c2.Y)
        bval = TRUE;
    return bval;
}

void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    horizontal = desktop.right;
    vertical = desktop.bottom;
}
