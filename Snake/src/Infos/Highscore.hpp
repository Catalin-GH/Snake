#ifndef __HIGHSCORE_HPP__
#define __HIGHSCORE_HPP__

#include "Types.h"

#include <string>

class Highscore
{
public:
    Highscore(const Coordonates2D & position, const std::string & playerName);
    virtual ~Highscore();

    /// Change the player score and print it
    void setPoints();

private:
    /// Print the score of the player in console
    void printScore() const;

    /// print the name of the player in console
    void printPlayer() const;

    /// Clean the score characters from console
    void wipeScore() const;

    /// Clean the name characters of the player from console
    void wipePlayer() const;

    /// Calculate the score position based on the position of the playerName
    const Coordonates2D computeScorePosition() const;

private:
    const std::string mPlayerName;
    const Coordonates2D mPlayerPosition;
    const Coordonates2D mScorePosition;
    uint16_t mScore;
};

#endif //__HIGHSCORE_HPP__
