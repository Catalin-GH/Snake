#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "SquareBlock.h"
#include "Types.h"

#include <deque>
#include <vector>

enum class Direction : uint8_t
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
};

class Snake
{
public:
    Snake(const Coordonates2D start, const uint8_t color);
    virtual ~Snake();

    /// Add a new body element.
    void addBody(const Coordonates2D start);

    /// Draw the snake in console.
    void draw() const;

    /// Overwrite the snake color with another one.
    /// \param Pass the color you need to draw.
    void wipe(const uint8_t color) const;

    /// Return the head position
    const Coordonates2D getPosition() const;

    /// Move the snake to next position.
    /// \param direction Just pass the direction you wish the snake to go.
    /// return "true" if the snake can be moved, "false" otherwise.
    bool move(const Direction direction);

    /// Know what is the snake position
    const std::deque<SquareBlock>& getSnake() const;

private:
    /// Verify if the snake bites himself.
    /// return "true" if the new head is valid, "false" otherwise.
    bool isValid(const SquareBlock & newHead) const;

    /// Update the body positions.
    /// return "true" if the update is successful, "false" otherwise.
    bool update(const Coordonates2D newPos);

    /// Create the snake
    void initialize(const Coordonates2D start);

private:
    uint8_t mLength;
    const uint8_t mColor;

    std::deque<SquareBlock> mBody;     //first element is the head
};

#endif // !__SNAKE_H__
