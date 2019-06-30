#ifndef __MENU_ITEM_HPP__
#define __MENU_ITEM_HPP__

#include "Printer.h"
#include "Types.h"

#include <unordered_map>

enum class Status : int8_t
{
    GAME = 0,
    OPTIONS,
    EXIT
};

class Item
{
public:
    Item(const Coordonates2D position, const std::string & name)
        : mPosition(position)
        , mName(name)
    {}

    const Coordonates2D & getPosition() const
    {
        return mPosition;
    }

    const std::string & getName() const
    {
        return mName;
    }

    void printItem(const uint8_t color) const
    {
        Printer::printString(mPosition, color, mName);
    }

    void wipeItem() const
    {
        Coordonates2D position = mPosition;
        for (const auto iter : mName)
        {
            Printer::wipeChar(position);
            ++position.x;
        }
    }

private:
    const Coordonates2D mPosition;
    const std::string mName;
};

class Menu
{
public:
    Menu(const Coordonates2D position);
    virtual ~Menu();

    Status selectState(const uint16_t waitingTimeMS);

private:
    void selectItem(const Status selectedItem);

    void insertItems(const Coordonates2D position);

    void showAllItems() const;

    void wipe() const;

private:
    int8_t currentState;

    std::unordered_map<Status, Item> mItems;
};

#endif // __MENU_ITEM_HPP__
