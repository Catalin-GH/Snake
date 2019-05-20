#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "Types.h"

#include <atomic>
#include <array>
#include <map>
#include <vector>

static const uint8_t MAXIMUM_NEIGHBOURS = 8;

class SquareBlock;

class Animation
{
public:
    explicit Animation(const Coordonates2D & position);
    ~Animation();

    void play();
    static void stop();

private:
    void create();

    /* Calculate the parameters to initialize the SquareBlocks */
    void createLogoBlocks(const std::vector<uint8_t> & matrix);

    /* Add new element (SquareBlock) to logo */
    void addElement(const uint8_t key, const Coordonates2D & position);

    /* Get a list of colors of the neighbours.s */
    const std::array<uint8_t, MAXIMUM_NEIGHBOURS> getNeighbourColors(const uint8_t centerElement) const;

    /* Retrive the color of the neighbour */
    const uint8_t getColorOf(const uint8_t neighbour) const;
    const uint8_t randKey() const;
    void draw() const;
    void wipe();

private:
    static std::atomic_bool mStop;
    const Coordonates2D mPosition;
    std::map<uint8_t, SquareBlock> mElements;
};

const uint8_t uniqueColor(std::array<uint8_t, MAXIMUM_NEIGHBOURS> colorList);

#endif // !__ANIMATION_H__
