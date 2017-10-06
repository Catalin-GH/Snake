#include "Console_Functions.h"

void gotoxy(size_t x, size_t y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Show_Cursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void FullScreen_Console(bool FullScreenFlag)
{
    if(FullScreenFlag == TRUE)
    {
        SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
    }
}

void cls()
{
    system("cls");
}

void SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, width, height, TRUE);
}

void SetConsolePosition(int width, int height)
{
    HWND console = GetConsoleWindow();
    SetWindowPos(console, HWND_TOP, width, height, 0, 0, SWP_NOSIZE);
}

void SetTextColor(WORD Color)
{
    if (!SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color))
    {
        MessageBox(NULL, TEXT("SetConsoleTextAttribute"), 
            TEXT("Console Error"), MB_OK);
        return;
    }
}

void SetConsoleFontSize()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    //cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

COORD GetConsoleSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
    COORD size;
    size.X = csbiInfo.dwSize.X;
    size.Y = csbiInfo.dwSize.Y;
    return size;
}
