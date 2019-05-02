#pragma once

#include <Windows.h>
#include <stdexcept>
#include <cstdio>
#include <iostream>

const uint8_t CONSOLE_LENGTH = 80;
const uint8_t CONSOLE_HEIGHT = 40;

void gotoxy(uint8_t, uint8_t);
void Show_Cursor(bool);
void cls();
void SetConsoleSize(int, int);
void SetTextColor(WORD);
void SetConsoleFontSize();
void SetConsoleWindowSize(SHORT, SHORT);
COORD GetConsoleSize();
void ConsoleTitle();

void DisableMaximizeButton();
void DisableResize();
