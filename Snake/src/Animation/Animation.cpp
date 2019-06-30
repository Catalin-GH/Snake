#include "Animation.h"
#include "Printer.h"
#include "SquareBlock.h"
#include "Utilities.hpp"

#include <algorithm>

static const uint8_t TEMPLATE_COLS = 23;
static const uint8_t TEMPLATE_ROWS = 6;
static std::thread ANIMATION_THREAD;

Animation::Animation(const Coordonates2D & position)
    : mPosition(position)
    , mElements()
    , mStop(false)
{
    create();
    draw();
}

Animation::~Animation()
{
    wipe();
}

void Animation::draw() const
{
    for (auto const & sqBlock : mElements)
    {
        Printer::printBlock(sqBlock.second);
    }
}

void Animation::wipe()
{
    for (auto & sqBlock : mElements)
    {
        sqBlock.second.setColor(BLACK_COLOR);
        Printer::printBlock(sqBlock.second);
    }
}

void Animation::create() 
{
    //if you modify the matrix, you also need to change TEMPLATE_COLS and TEMPLATE_ROWS
    const std::vector<uint8_t> logoTemplate 
    {
        1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
        1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,
        1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,
        1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    createLogoBlocks(logoTemplate);
}

void Animation::createLogoBlocks(const std::vector<uint8_t> & matrixTemplate)
{
    const uint8_t search = 1;
    uint8_t offsetX = 0;
    uint8_t offsetY = 0;
    uint8_t key = 1;    // key should not be 0

    std::for_each(matrixTemplate.cbegin(), matrixTemplate.cend(), [&](const uint8_t value)
    {
        if (0u == offsetX % TEMPLATE_COLS && 0u != offsetX)
        {
            offsetX = 0;
            ++offsetY;
        }

        if (value == search)
        {
            addElement(key, Coordonates2D(mPosition.x + offsetX, mPosition.y + offsetY));
        }

        ++offsetX;
        ++key;
    });
}

void Animation::addElement(const uint8_t key, const Coordonates2D & position)
{
    auto colorList = getColorList(key);
    const uint8_t color = uniqueColor(colorList);
    mElements.emplace(std::make_pair(key, SquareBlock(position, Category::LOGO, color)));
}

const std::array<uint8_t, MAXIMUM_NEIGHBOURS> Animation::getColorList(const uint8_t centerNeighbour) const
{
    std::array<uint8_t, MAXIMUM_NEIGHBOURS> colors{ 0, 0, 0, 0, 0, 0, 0, 0 };
    const uint8_t offset = 1;

    /*
    * Check for each neighbour according to this picture: 
    * https://www.mathworks.com/matlabcentral/answers/uploaded_files/195423/image.png
    */
    colors.at(0) = getColorOf(centerNeighbour - TEMPLATE_COLS - offset);
    colors.at(1) = getColorOf(centerNeighbour - TEMPLATE_COLS);
    colors.at(2) = getColorOf(centerNeighbour - TEMPLATE_COLS + offset);

    colors.at(3) = getColorOf(centerNeighbour - offset);
    colors.at(4) = getColorOf(centerNeighbour + offset);

    colors.at(5) = getColorOf(centerNeighbour + TEMPLATE_COLS - offset);
    colors.at(6) = getColorOf(centerNeighbour + TEMPLATE_COLS);
    colors.at(7) = getColorOf(centerNeighbour + TEMPLATE_COLS + offset);

    return colors;
}

void Animation::play()
{
    mStop = false;

    ANIMATION_THREAD = std::thread([this]()
    {
        const uint16_t milliSeconds = 10;
        while (false == mStop)
        {
            auto key = randKey();
            auto colorList = getColorList(key);
            auto color = uniqueColor(colorList);
            auto iter = mElements.find(key);

            if (iter != mElements.end())
            {
                iter->second.setColor(color);
                Printer::printBlock(iter->second);
            }

            sleepThread(milliSeconds);
        }
    });
}

void Animation::stop()
{
    //stop the while inside play function
    mStop = true;

    if(true == ANIMATION_THREAD.joinable())
    { 
        ANIMATION_THREAD.join();
    }
}

const uint8_t Animation::getColorOf(const uint8_t neighbour) const
{
    const uint8_t maxNumberNeighbours = TEMPLATE_COLS * TEMPLATE_ROWS;
    uint8_t color = 0; //not found yet

    if (neighbour > 0u && neighbour < maxNumberNeighbours)
    {
        auto search = mElements.find(neighbour);
        if (search != mElements.end())
        {
            color = search->second.getColor();
        }
    }

    return color;
}

const uint8_t Animation::randKey() const
{
    auto iter = mElements.cbegin();
    const uint16_t lowerBound = 0;
    const uint16_t upperBound = static_cast<uint16_t>(mElements.size()) - 1u;

    /*
    * https://en.cppreference.com/w/cpp/iterator/advance
    * Starting with Distance n = 0 the first iterator in the container may be found.
    */
    std::advance(iter, randNumber(lowerBound, upperBound));

    return iter->first;
}

const uint8_t uniqueColor(std::array<uint8_t, MAXIMUM_NEIGHBOURS> colorList)
{
    const uint8_t lowerColor = 1;
    const uint8_t upperColor = 15;
    uint16_t color = 0;
    auto iter = colorList.cbegin();

    do
    {
        color = randNumber(lowerColor, upperColor); //get a random color within a range
        iter = std::find(colorList.cbegin(), colorList.cend(), color);
    } while (iter != colorList.cend());

    return static_cast<uint8_t>(color);
}

const uint8_t animationWidth()
{
    return TEMPLATE_COLS;
}

const uint8_t animationHeight()
{
    return TEMPLATE_ROWS;
}
