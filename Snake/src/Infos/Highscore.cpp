#include "Highscore.hpp"
#include "Printer.h"
#include "Utilities.hpp"
#include "SquareBlock.h"

static const uint16_t DEFAULT_SCORE = 0;
static const uint8_t DISTANCE = 2;
static const uint8_t COLOR_HIGHSCORE = 5;
static const uint8_t COLOR_PLAYER = 15;

Highscore::Highscore(const Coordonates2D & position, const std::string & playerName)
    : mPlayerName(playerName)
    , mPlayerPosition(position)
    , mScorePosition(computeScorePosition())
    , mScore(DEFAULT_SCORE)
{
    printPlayer();
    printScore();
}

Highscore::~Highscore()
{
    wipePlayer();
    wipeScore();
}

const Coordonates2D Highscore::computeScorePosition() const
{
    const uint8_t x = mPlayerPosition.x + static_cast<uint8_t>(mPlayerName.length()) + DISTANCE;
    const uint8_t y = mPlayerPosition.y;
    return Coordonates2D(x, y);
}

void Highscore::printScore() const
{
    Printer::printI(mScorePosition, COLOR_HIGHSCORE, mScore);
}

void Highscore::printPlayer() const
{
    Printer::printString(mPlayerPosition, COLOR_PLAYER, mPlayerName);
}

void Highscore::wipePlayer() const
{
    Coordonates2D positionWipe(mPlayerPosition.x, mPlayerPosition.y);

    for (const auto iter : mPlayerName)
    {
        Printer::wipeChar(positionWipe);
        ++positionWipe.x;
    }
}

void Highscore::wipeScore() const
{
    const uint8_t scoreLength = countDigit(mScore);
    Coordonates2D positionWipe(mScorePosition.x, mScorePosition.y);

    for (uint8_t i = 0; i < scoreLength; ++i)
    {
        Printer::wipeChar(positionWipe);
        ++positionWipe.x;
    }
}

void Highscore::setPoints()
{
    wipeScore();
    ++mScore;
    printScore();
}
