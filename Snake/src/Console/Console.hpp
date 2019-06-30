#pragma once

#include <Windows.h>
#include <stdexcept>
#include <cstdio>
#include <iostream>

const uint8_t CONSOLE_WIDTH = 80;
const uint8_t CONSOLE_HEIGHT = 40;

void gotoxy(uint8_t, uint8_t);
void showCursor(bool);
void cls();
void SetConsoleSize(int, int);
void SetTextColor(WORD);
void setConsoleFontSize();
void setConsoleWindowSize(SHORT, SHORT);
COORD GetConsoleSize();
void consoleTitle(const char * name);

void disableMaximizeButton();
void disableResize();
