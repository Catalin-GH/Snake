#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "Types.h"

#include <array>
#include <map>
#include <vector>

static const uint8_t MAXIMUM_NEIGHBOURS = 8;

class SquareBlock;

/// The constructor needs 2d coordonates to build each elements. 
/// Remember that the coordonates are of the top left corner. 
/// An internal thread is used to create the efect.
class Animation
{
public:
    explicit Animation(const Coordonates2D & position);

    Animation(const Animation &) = delete;
    Animation(Animation &&) = delete;
    Animation & operator=(const Animation &) = delete;
    Animation & operator=(Animation &&) = delete;

    virtual ~Animation();

    /// Start playing the animation effect. 
    /// A thread is initialized and detached.
    void play();

    /// In order to stop the animation, the following method must be called.
    void stop();

private:
    /// Set the template logo.
    void create();

    /// Calculate the parameters to initialize a SquareBlock.
    /// Add multiple SquareBlocks to the container.
    /// \param matrix - an array of 0 and 1 that form the base of the logo
    void createLogoBlocks(const std::vector<uint8_t> & matrix);

    /// Add a new SquareBlock to mElements container.
    /// \param key - store the key
    /// \param position - position of the SquareBlock
    void addElement(const uint8_t key, const Coordonates2D & position);

    /// Get a list of colors of the neighbours.
    /// \param centerElement need to know the element in order to find its neighbours.
    /// \return an array of colors from each neighbours.
    const std::array<uint8_t, MAXIMUM_NEIGHBOURS> getColorList(const uint8_t centerElement) const;

    /// Retrive the color of the neighbour and return it.
    const uint8_t getColorOf(const uint8_t neighbour) const;

    /// Generate a random key for container and returns it.
    const uint8_t randKey() const;

    /// Draw the logo in console.
    void draw() const;

    /// Delete the logo from console.
    void wipe();

private:
    /// Used to stop the animation.
    bool mStop;

    /// Remember the top left corner coordonates.
    /// Used to calculate each position of the SquareBlock.
    const Coordonates2D mPosition;

    /// Save the elements that form the animation
    std::map<uint8_t, SquareBlock> mElements;
};

/// Generate an unique color that can't be found in the colorList and returns it
const uint8_t uniqueColor(std::array<uint8_t, MAXIMUM_NEIGHBOURS> colorList);

const uint8_t animationWidth();

const uint8_t animationHeight();

#endif // !__ANIMATION_H__
