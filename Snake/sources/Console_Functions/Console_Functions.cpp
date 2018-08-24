#include "Console_Functions.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(size_t x, size_t y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(console, pos);
}

void Show_Cursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(console, &cursorInfo);
}

void cls()
{
    system("cls");
}

//used once
void SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, width, height, TRUE);
}

void SetTextColor(WORD Color)
{
    if (!SetConsoleTextAttribute(console, Color))
    {
        MessageBox(NULL, TEXT("SetConsoleTextAttribute"),
            TEXT("Console Error"), MB_OK);
        return;
    }
}

//set once
void SetConsoleFontSize()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    //cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(console, FALSE, &cfi);

}

//set once
void SetConsoleWindowSize(SHORT x, SHORT y)
{
    HWND csl = GetConsoleWindow();
    RECT r;
    GetWindowRect(csl, &r); //stores the console's current dimensions
    MoveWindow(csl, r.left, r.top, x * 11, y * 5, TRUE);

    if (console == INVALID_HANDLE_VALUE)
        throw std::runtime_error("Unable to get stdout handle.");

    // If either dimension is greater than the largest console window we can have,
    // there is no point in attempting the change.
    {
        COORD largestSize = GetLargestConsoleWindowSize(console);
        if (x > largestSize.X)
            throw std::invalid_argument("The x dimension is too large.");
        if (y > largestSize.Y)
            throw std::invalid_argument("The y dimension is too large.");
    }


    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    if (!GetConsoleScreenBufferInfo(console, &bufferInfo))
        throw std::runtime_error("Unable to retrieve screen buffer info.");

    SMALL_RECT& winInfo = bufferInfo.srWindow;
    COORD windowSize = { winInfo.Right - winInfo.Left + 5, winInfo.Bottom - winInfo.Top + 5 };

    if (windowSize.X > x || windowSize.Y > y)
    {
        // window size needs to be adjusted before the buffer size can be reduced.
        SMALL_RECT info = { 0, 0, x < windowSize.X ? x - 1 : windowSize.X - 1,  y < windowSize.Y ? y - 1 : windowSize.Y - 1 };

        if (!SetConsoleWindowInfo(console, TRUE, &info))
            throw std::runtime_error("Unable to resize window before resizing buffer.");
    }

    COORD size = { x, y };
    if (!SetConsoleScreenBufferSize(console, size))
        throw std::runtime_error("Unable to resize screen buffer.");


    SMALL_RECT info = { 0, 0, x - 1, y - 1 };
    if (!SetConsoleWindowInfo(console, TRUE, &info))
        throw std::runtime_error("Unable to resize window after resizing buffer.");

    /* HWND console = GetConsoleWindow();
     DWORD newStyle = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
     SetWindowLong(console, GWL_STYLE, newStyle);
     SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER);*/

}

//not used
COORD GetConsoleSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(console, &csbiInfo);
    COORD size;
    size.X = csbiInfo.dwSize.X;
    size.Y = csbiInfo.dwSize.Y;
    return size;
}

//used once
void ConsoleTitle()
{
    SetConsoleTitle("Snake Game");
}

//used once
void DisableMaximizeButton()
{
    HWND hwnd = GetConsoleWindow();
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~WS_MAXIMIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}

//used once
void DisableResize()
{
    HWND hwnd = GetConsoleWindow();
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~WS_SIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, style);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}
