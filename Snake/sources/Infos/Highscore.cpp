#include "Highscore.hpp"
#include "Printer.h"

static const uint16_t DEFAULT_SCORE = 0;
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
}

void Highscore::printScore() const
{
    Printer::printI(mScorePosition, COLOR_HIGHSCORE, mScore);
}

const Coordonates2D Highscore::computeScorePosition() const
{
    const uint8_t offset = 2;
    const uint8_t x = mPlayerPosition.x + static_cast<uint8_t>(mPlayerName.length()) + offset;
    const uint8_t y = mPlayerPosition.y;
    return Coordonates2D(x, y);
}

void Highscore::printPlayer() const
{
    Printer::printString(mPlayerPosition, COLOR_PLAYER, mPlayerName);
}

/*Only for increasing values*/
void Highscore::setPoints(const uint16_t points)
{
    mScore = points;
    printScore();
}
