#include "Snake.h"
#include "Printer.h"

#include <algorithm>
#include <iterator>

Snake::Snake(const Coordonates2D start, const uint8_t color)
    : mColor(color)
    , mLength(5)
    , mBody{}
{
    initialize(start);
}

Snake::~Snake()
{
}

void Snake::initialize(const Coordonates2D start)
{
    for (uint8_t i = 0; i < mLength; ++i)
    {
        addBody(Coordonates2D(start.x - i, start.y));
    }
}

void Snake::addBody(const Coordonates2D pos)
{
    mBody.emplace_back(Coordonates2D(pos.x, pos.y), Category::SNAKE, mColor);
}

bool Snake::isValid(const SquareBlock & newHead) const
{
    bool result = true;

    // Check whether the new head position is actually a body element
    // In case of true the snake bites himself, false otherwise
    result = any_of(mBody.cbegin(), mBody.cend(), [&newHead](const SquareBlock & body)
    { 
        return (body == newHead);
    });

    return !result;
}

bool Snake::update(const Coordonates2D newPos)
{
    int8_t counter = static_cast<uint8_t>(mBody.size()) - 1u;
    const SquareBlock head(newPos, Category::SNAKE, mColor);

    // Check whether the new head has a valid position or not
    if (false == isValid(head))
    {
        return false;   //inform that snake cannot be updated
    }
    else
    {
        // Update the snake based on the new received position
        for_each(mBody.rbegin(), mBody.rend(), [this, &counter, &head](SquareBlock & body) mutable
        {
            if ((--counter) >= 0)
            {
                body = mBody.at(counter);
            }
            else
            {
                body = head;
            }
        });
    }

    return true;
}

void Snake::draw() const
{
    for_each(mBody.cbegin(), mBody.cend(), [](const SquareBlock & body)
    {
        Printer::printBlock(body);
    });
}

void Snake::wipe(const uint8_t color) const
{
    for_each(mBody.cbegin(), mBody.cend(), [&color](const SquareBlock & body)
    {
        Printer::wipeChar(body.getLeft().getPosition(), color);
        Printer::wipeChar(body.getRight().getPosition(), color);
    });
}

const Coordonates2D Snake::getPosition() const
{
    return mBody.at(0).getPosition();
}

bool Snake::move(const Direction direction)
{
    Coordonates2D newHeadPos = mBody.at(0).getPosition();
    bool updated = false;

    switch (direction)
    {
        case Direction::UP:
        {
            --newHeadPos.y;
            updated = update(newHeadPos);
        } break;
        case Direction::RIGHT:
        {
            ++newHeadPos.x;
            updated = update(newHeadPos);
        } break;
        case Direction::DOWN:
        {
            ++newHeadPos.y;
            updated = update(newHeadPos);
        } break;
        case Direction::LEFT:
        {
            --newHeadPos.x;
            updated = update(newHeadPos);
        } break;
        default:
        // if this point has been reached the snake does not update the position
            ;
    }

    return updated;
}

const std::deque<SquareBlock>& Snake::getSnake() const
{
    return mBody;
}
