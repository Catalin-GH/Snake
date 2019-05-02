#include "Animation.h"
#include "Printer.h"

#include <algorithm>

static const uint8_t LOGO_COLS = 23;

//not used yet
static const uint8_t LOGO_ROWS = 6;

Animation::Animation(const Coordonates2D & position)
    : mPosition(position)
{
    initAnimation();
    draw();
}

Animation::~Animation()
{
    wipe();
}

void Animation::draw() const
{
    for (auto const & sqBlock : mAnimation)
    {
        Printer::printBlock(sqBlock);
    }
}

void Animation::wipe()
{
    for (auto & sqBlock : mAnimation)
    {
        sqBlock.setColor(BLACK_COLOR);
        //Printer::printBlock(sqBlock);
    }
}

void Animation::initAnimation() {
    //template logo
    std::vector<uint8_t> logoMatrix {
        1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
        1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,
        1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,
        1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    mAnimation.reserve(sizeof(SquareBlock) * countOnes(logoMatrix));
    computeBlocks(logoMatrix);
}

const uint8_t Animation::countOnes(const std::vector<uint8_t> & matrix) const
{
    const uint8_t value = 1;
    return static_cast<uint8_t>(std::count(matrix.begin(), matrix.end(), value));
}

void Animation::computeBlocks(const std::vector<uint8_t> & matrix)
{
    const uint8_t search = 1;
    uint8_t offsetX = 0;
    uint8_t offsetY = 0;
    std::for_each(matrix.cbegin(), matrix.cend(), [&](const uint8_t value)
    {
        if (0u == offsetX % LOGO_COLS && 0u != offsetX)
        {
            offsetX = 0;
            ++offsetY;
        }

        if (value == search)
        {
            addElement(Coordonates2D(mPosition.x + offsetX, mPosition.y + offsetY));
        }

        ++offsetX;
    });
}

void Animation::addElement(const Coordonates2D & position)
{
    uint8_t color = randomColor();
    mAnimation.emplace_back(position, Category::LOGO, color);
}

const uint8_t Animation::randomColor() const
{
    const uint8_t maxColor = 15;
    srand(clock());

    return rand() % maxColor + 1;
}
