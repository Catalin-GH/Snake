#ifndef __HIGHSCORE_HPP__
#define __HIGHSCORE_HPP__

#include "Types.h"
#include <string>

class Highscore
{
private:
    const std::string mPlayerName;
    const Coordonates2D mPlayerPosition;
    const Coordonates2D mScorePosition;
    uint16_t mScore;

    void printScore() const;
    void printPlayer() const;

    const Coordonates2D computeScorePosition() const;

public:
    Highscore(const Coordonates2D & position, const std::string & playerName);
    ~Highscore();

    void setPoints(const uint16_t points);
};

#endif //__HIGHSCORE_HPP__
