#pragma once

#include <Windows.h>
#include <cstdio>

struct ConsoleSize;
struct OriginalConsoleSize;

void gotoxy(size_t, size_t);
void Show_Cursor(bool);
void FullScreen_Console(bool);
void cls();
void SetConsoleSize(int, int);
void SetConsolePosition(int, int);
void SetTextColor(WORD);
void SetConsoleFontSize();
COORD GetConsoleSize();
