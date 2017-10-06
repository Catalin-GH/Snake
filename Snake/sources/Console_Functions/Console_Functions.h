#pragma once

#include <Windows.h>
#include <cstdio>

#define CONSOLE_LENGTH 80
#define CONSOLE_HEIGHT 40

void gotoxy(size_t, size_t);
void Show_Cursor(bool);
void FullScreen_Console(bool);
void cls();
void SetConsoleSize(int, int);
void SetConsolePosition(int, int);
void SetTextColor(WORD);
void SetConsoleFontSize();
COORD GetConsoleSize();
