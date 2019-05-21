#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "Types.h"

#include <atomic>
#include <array>
#include <map>
#include <vector>

static const uint8_t MAXIMUM_NEIGHBOURS = 8;

class SquareBlock;

/*!
 * 
 * 
 */
class Animation
{
public:
    explicit Animation(const Coordonates2D & position);

    ~Animation();

    /*!
     * Start playing the animation effect. A thread is initialized and detached.
     * 
     */
    void play();

    /*!
     * In order to stop the animation, the following method must be called.
     * 
     */
    static void stop();

private:
    /*!
     * Set the template logo
     * 
     */
    void create();

    /*!
     * Calculate the parameters needed to initialize a SquareBlock and added it to the container
     * 
     * \param matrix - an array of 0 and 1 that form the base of the logo
     */
    void createLogoBlocks(const std::vector<uint8_t> & matrix);

    /*!
     * Add a new element (SquareBlock) to mElements container
     * 
     * \param key - store the key
     * \param position - position of the SquareBlock
     */
    void addElement(const uint8_t key, const Coordonates2D & position);

    /*!
     * Get a list of colors of the neighbours
     * 
     * \param centerElement need to know the element in order to find its neighbours
     * \return an array of colors from each neighbours
     */
    const std::array<uint8_t, MAXIMUM_NEIGHBOURS> getNeighbourColors(const uint8_t centerElement) const;

    /*!
     * Retrive the color of the neighbour and return it
     * 
     * \param neighbour 
     * \return 
     */
    const uint8_t getColorOf(const uint8_t neighbour) const;

    /*!
     * Generate a random key for container
     * 
     * \return key
     */
    const uint8_t randKey() const;

    /*!
     * Draw the logo in console
     * 
     */
    void draw() const;

    /*!
     * Delete the logo from console
     * 
     */
    void wipe();

private:
    static std::atomic_bool mStop;
    const Coordonates2D mPosition;
    std::map<uint8_t, SquareBlock> mElements;
};

/* Generate a unique color that can't be found in the colorList */
const uint8_t uniqueColor(std::array<uint8_t, MAXIMUM_NEIGHBOURS> colorList);

#endif // !__ANIMATION_H__
