#pragma once

#include <Windows.h>
#include <stdexcept>
#include <cstdio>
#include <iostream>
#include<mutex>

#define CONSOLE_LENGTH 80
#define CONSOLE_HEIGHT 40

void gotoxy(size_t, size_t);
void Show_Cursor(bool);
void cls();
void SetConsoleSize(int, int);
void SetTextColor(WORD);
void SetConsoleFontSize();
void SetConsoleWindowSize(SHORT, SHORT);
COORD GetConsoleSize();
void ConsoleTitle(std::string);

void DisableMaximizeButton();
void DisableResize();
