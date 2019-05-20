#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <fstream>

class Log
{
private:
    static std::ofstream logFile;

public:
    Log();
    ~Log();

    void message(const char * message);
    void value(const int value);
    void endLine();
};

#endif //__LOG_HPP__