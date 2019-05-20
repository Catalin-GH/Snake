#include "Log.hpp"

#include <iostream>

std::ofstream Log::logFile;

Log::Log()
{
    logFile.open("SnakeLogs.txt");
}

Log::~Log()
{
    logFile.close();
}

void Log::message(const char * message)
{
    if (logFile.is_open())
    {
        logFile << message;
    }
    else
    {
        std::cout << "file not oened!";
    }
}

void Log::value(const int value)
{
    if (logFile.is_open())
    {
        logFile << value;
    }
    else
    {
        std::cout << "file not oened!";
    }
}

void Log::endLine()
{
    if (logFile.is_open())
    {
        logFile << std::endl;
    }
}

